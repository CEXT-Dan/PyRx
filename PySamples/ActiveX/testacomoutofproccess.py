
import pythoncom
import win32com.client
from timeit import default_timer as timer

#166.88979500000278 seconds
def comMatrix3d(mat):
        return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, mat)
    
start = timer()
comMat = comMatrix3d(
    [[1.0, 0.0, 0.0, 100.0],
     [0.0, 1.0, 0.0, 100.0], 
     [0.0, 0.0, 1.0, 0.0], 
     [0.0, 0.0, 0.0, 1.0]])

acad = win32com.client.Dispatch("AutoCAD.Application")
model = acad.ActiveDocument.ModelSpace

for ent in model:
    if ent.ObjectName == "AcDbPoint":
        ent.TransformBy(comMat)
        
end = timer()
print(end - start)

