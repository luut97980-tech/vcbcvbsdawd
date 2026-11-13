"""Inspect unencrypted ARM64 Mach-O files against supplied dump RVA profiles.
This is static binary inspection, not an iOS execution test.
"""
import argparse,hashlib,json,re,struct
from pathlib import Path

class MachO:
 def __init__(self,path):
  self.data=Path(path).read_bytes();b=self.data
  magic,cpu,sub,kind,count,size,flags,res=struct.unpack_from('<8I',b)
  assert magic==0xfeedfacf and cpu==0x100000c and kind==6
  self.uuid=None;self.segments=[];self.symbols={};self.encrypted=False;table=None;o=32
  for _ in range(count):
   cmd,n=struct.unpack_from('<II',b,o);assert n>=8 and o+n<=32+size
   if cmd==0x19:
    name=b[o+8:o+24].rstrip(b'\0').decode();va,vs,fo,fs=struct.unpack_from('<QQQQ',b,o+24)
    self.segments.append((name,va,vs,fo,fs))
   elif cmd==0x1b:self.uuid=b[o+8:o+24].hex()
   elif cmd==0x2c:self.encrypted=bool(struct.unpack_from('<I',b,o+16)[0])
   elif cmd==2:table=struct.unpack_from('<4I',b,o+8)
   o+=n
  assert o==32+size and self.uuid and not self.encrypted
  if table:
   symoff,nsyms,stroff,strsize=table
   for i in range(nsyms):
    st,typ,sect,desc,value=struct.unpack_from('<IBBHQ',b,symoff+16*i)
    if st and st<strsize and typ&1 and (typ&0xe)!=0:
     end=b.index(b'\0',stroff+st,stroff+strsize)
     name=b[stroff+st:end].decode(errors='replace');self.symbols[name]=value
  self.sha256=hashlib.sha256(b).hexdigest()
 def read(self,rva,size):
  for name,va,vs,fo,fs in self.segments:
   if name=='__TEXT' and va<=rva and rva+size<=va+fs:
    return self.data[fo+rva-va:fo+rva-va+size]
  raise ValueError(f'No text bytes at {rva:#x}')

def inspect(files,root):
 rows=json.loads((root/'analysis/method_rva_profiles.json').read_text())
 source=(root/'src/game_backend.cpp').read_text()
 req=set(re.findall(r'\bLOAD\((\w+)\)',source))-{'n'}
 optional=set(re.findall(r'\bOPT\((\w+)\)',source))-{'n'}
 out={}
 for path in files:
  m=MachO(path);matched=[]
  for client in ['vng','global']:
   anchors=[r for r in rows if r['client']==client and r['class']=='ActorSystem']
   expected=[bytes.fromhex('002c40f9c0035fd6'),bytes.fromhex('003840f9c0035fd6')]
   if all(m.read(int(r['rva'],16),8)==e for r,e in zip(anchors,expected)):matched.append(client)
  assert len(matched)==1,(str(path),matched)
  client=matched[0];assert client not in out
  methods=[]
  for r in rows:
   if r['client']!=client:continue
   rva=int(r['rva'],16);prefix=m.read(rva,16)
   assert prefix!=bytes(16) and rva%4==0
   methods.append(dict(r,native_prefix_hex=prefix.hex(),evidence='dump RVA mapped to __TEXT bytes; identity anchored by ActorSystem getters'))
  dynamic=[]
  for target in json.loads((root/'analysis/dynamic_target_audit.json').read_text()):
   for method in target[client]:
    rva=method['rva'];prefix=m.read(rva,16)
    assert rva%4==0 and prefix!=bytes(16)
    dynamic.append({'namespace':target['namespace'],'class':target['class'],'signature':method['signature'],'rva':hex(rva),'native_prefix_hex':prefix.hex()})
  exports={name:('_il2cpp_'+name in m.symbols) for name in sorted(req)}
  assert all(exports.values()),(client,[k for k,v in exports.items() if not v])
  out[client]={'input_file':Path(path).name,'framework_uuid':m.uuid,'framework_sha256':m.sha256,'framework_size':len(m.data),'encrypted':m.encrypted,'required_exports':exports,'optional_exports':{name:'_il2cpp_'+name in m.symbols for name in sorted(optional)},'methods':methods,'dynamic_target_spans':dynamic,'decoded_getters':{'ActorSystem.myActorCharacter':'LDR X0,[X0,#0x58]; RET','ActorSystem.otherActorCharacter':'LDR X0,[X0,#0x70]; RET'},'device_tested':False}
 assert set(out)=={'vng','global'}
 return out

if __name__=='__main__':
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('frameworks',nargs=2,type=Path);p.add_argument('--output',type=Path)
 args=p.parse_args();result=inspect(args.frameworks,Path(__file__).resolve().parents[1])
 if args.output:args.output.write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps({k:{'file':v['input_file'],'uuid':v['framework_uuid'],'required_exports':len(v['required_exports']),'method_spans':len(v['methods']),'dynamic_target_spans':len(v['dynamic_target_spans'])} for k,v in result.items()},indent=2))
