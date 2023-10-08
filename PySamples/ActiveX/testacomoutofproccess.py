
import pythoncom
import win32com.client
from timeit import default_timer as timer

import AcadApp24

def comMatrix3d(mat):
        return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, mat)
    
def getApp() -> AcadApp24.IAcadApplication:
    id = AcadApp24.AcadApplication.CLSID
    app: AcadApp24.IAcadApplication = win32com.client.Dispatch(id)
    return app

def getDbx() -> AcadApp24.IAxDbDocument:
    id = AcadApp24.AxDbDocument.CLSID
    dbx: AcadApp24.IAxDbDocument = win32com.client.Dispatch(id)
    return dbx
    
start = timer()
comMat = comMatrix3d(
    [[1.0, 0.0, 0.0, 100.0],
     [0.0, 1.0, 0.0, 100.0], 
     [0.0, 0.0, 1.0, 0.0], 
     [0.0, 0.0, 0.0, 1.0]])

acad = getApp()
model = acad.ActiveDocument.ModelSpace

for ent in model:
    if ent.ObjectName == "AcDbPoint":
        ent.TransformBy(comMat)
        
end = timer()
print(end - start)

