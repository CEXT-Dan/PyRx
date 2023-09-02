import pyautocad as PYCAD
from timeit import default_timer as timer

acad = PYCAD.Autocad(create_if_not_exists=True)
        
start = timer()
        
mspace = acad.ActiveDocument.ModelSpace
for i in range(0, mspace.Count):
    obj = mspace[i]
    if obj.ObjectName != "AcDbPoint":
        continue
    obj.Layer = "Tin"
            
end = timer()
        
print(end - start)