"""Verify the packaged bindings against BOTH supplied dumps; never executes game code."""
import argparse,hashlib,json,re
from pathlib import Path
from dump_index import parse

def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--vng',required=True);p.add_argument('--global-dump',required=True);a=p.parse_args()
 root=Path(__file__).resolve().parents[1];profiles=json.loads((root/'analysis/ios_build.json').read_text())['clients']
 indexes={}
 for client,path in [('vng',a.vng),('global',a.global_dump)]:
  assert hashlib.sha256(Path(path).read_bytes()).hexdigest()==profiles[client]['dump_sha256'],client+' dump hash mismatch'
  indexes[client]=parse(path)
 fields=json.loads((root/'analysis/field_bindings.json').read_text())
 header=(root/'src/ios_field_offsets.hpp').read_text()
 constants={name:int(value,16) for name,value in re.findall(r'std::size_t (\w+) = (0x[0-9a-f]+);',header)}
 for row in fields:
  for client,idx in indexes.items():
   actual=idx[(row['namespace'],row['owner'])]['fields'][row['field']]
   assert actual==row[client],(client,row,actual)
   assert constants[row['constant']]==actual['offset'],row
 methods=json.loads((root/'analysis/method_rva_profiles.json').read_text())
 for row in methods:
  candidates=indexes[row['client']][(row['namespace'],row['class'])]['methods']
  found=[m for m in candidates if m['signature']==row['signature']]
  assert len(found)==1 and found[0]['rva']==int(row['rva'],16),row
 targets=re.findall(r'\{"([^"]*)", "([^"]+)", "([^"]+)", Ret::(\w+)\}',(root/'src/stealth.hpp').read_text())
 for ns,cls,name,ret in targets:
  for client,idx in indexes.items():
   found=[m for m in idx[(ns,cls)]['methods'] if m['name']==name]
   assert found,(client,cls,name)
   for m in found:assert m['signature'].split(name+'(')[0].split()[-1].lower()==ret.lower(),m
 statics=[('GPresto.Protector.Engine','GPrestoEngine','detected_types','HashSet<int>'),('CodeStage.AntiCheat.Time','SpeedHackProofTime','speedHackDetected','bool'),('CodeStage.AntiCheat.Time','SpeedHackProofTime','warningShot','bool'),('GPresto.Protector','SpeedHack','currentFalsePositives','byte')]
 for ns,cls,field,typ in statics:
  for idx in indexes.values():assert idx[(ns,cls)]['fields'][field]['type']==typ,(cls,field)
 # Generic definitions report zero layout in these dumps: resolve their
 # closed runtime instances through metadata, never treat zero as a field offset.
 for idx in indexes.values():
  for field in ['_items','_size','_version']:
   assert field in idx[('System.Collections.Generic','List<T>')]['fields']
 source=(root/'src/game_backend.cpp').read_text()
 assert not re.search(r'safeReadAt\((?:ak|cur|kmgUnitKlass|gpEng|shptKlass|gpSh),0xB8',source)
 assert 'safeReadAt(curMap,layout::IMap_cinemachineBrain,brain)' in source
 assert constants['IMap_cinemachineBrain']==0x48
 assert not re.search(r'safeReadAt\(listObj,0x',source)
 print(json.dumps({'ok':True,'unique_fields':len(constants),'source_bindings':len(fields),'method_rva_entries':len(methods),'dynamic_targets_per_client':len(targets),'static_fields':len(statics),'clients':list(indexes),'native_binary_verified':False},indent=2))

if __name__=='__main__':main()
