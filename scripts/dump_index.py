import re
from pathlib import Path

def parse(path):
 result={}
 text=Path(path).read_text()
 for block in re.split(r'(?m)^// Namespace: ',text)[1:]:
  ns,_,body=block.partition('\n')
  head=re.search(r'^(?:.*?)(?:class|struct|enum|interface) (.*?) // TypeDefIndex:',body,re.M)
  if not head:continue
  declaration=head[1];name=declaration.split(' : ')[0]
  fields={m[2]:{'type':m[1].strip(),'offset':int(m[3],16)} for m in re.finditer(r'^\s*(?:public|private|protected|internal)(?:\s+(?:static|readonly|volatile|protected|internal))*\s+(.+?)\s+([^\s;]+); // (0x[\da-fA-F]+)',body,re.M)}
  methods=[]
  for m in re.finditer(r'// RVA: (0x[\da-fA-F]+)[^\n]*\n\s*([^\n]+) \{ \}',body):
   sig=m[2];mm=re.search(r'([^\s(]+)\((.*)\)',sig)
   if mm:methods.append({'name':mm[1],'signature':sig,'rva':int(m[1],16),'params':mm[2]})
  result[(ns.strip(),name)]={'namespace':ns.strip(),'name':name,'declaration':declaration,'fields':fields,'methods':methods}
 return result
