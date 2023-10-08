
import pythoncom
import win32com.client
from timeit import default_timer as timer

import AxApp24

def comMatrix3d(mat):
        return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, mat)
    
def getApp() -> AxApp24.IAcadApplication:
    id = AxApp24.AcadApplication.CLSID
    app: AxApp24.IAcadApplication = win32com.client.Dispatch(id)
    return app

def getDbx() -> AxApp24.IAxDbDocument:
    id = AxApp24.AxDbDocument.CLSID
    dbx: AxApp24.IAxDbDocument = win32com.client.Dispatch(id)
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

