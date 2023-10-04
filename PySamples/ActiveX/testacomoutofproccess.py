
import pythoncom
import win32com.client
from timeit import default_timer as timer

def comMatrix3d(mat):
        return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, mat)
    
start = timer()
comMat = comMatrix3d(
    [[1.0, 0.0, 0.0, 100.0],
     [0.0, 1.0, 0.0, 100.0], 
     [0.0, 0.0, 1.0, 0.0], 
     [0.0, 0.0, 0.0, 1.0]])

#166.88979500000278 without cache
#acad = win32com.client.Dispatch("AutoCAD.Application")

#40.01999249999972 with cache
acad = win32com.client.gencache.EnsureDispatch("AutoCAD.Application")
model = acad.ActiveDocument.ModelSpace

for ent in model:
    if ent.ObjectName == "AcDbPoint":
        ent.TransformBy(comMat)
        
end = timer()
print(end - start)

