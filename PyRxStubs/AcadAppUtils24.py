# import
import PyGe as Ge
import win32com.client
import pythoncom
import AcadApp24

def getApp() -> AcadApp24.IAcadApplication:
    id = AcadApp24.AcadApplication.CLSID
    app: AcadApp24.IAcadApplication = win32com.client.Dispatch(id)
    return app

def getDbx() -> AcadApp24.IAxDbDocument:
    id = AcadApp24.AxDbDocument.CLSID
    dbx: AcadApp24.IAxDbDocument = win32com.client.Dispatch(id)
    return dbx

def pnt2d(val: Ge.Point2d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def vec2d(val: Ge.Vector2d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def matrix2d(val: Ge.Matrix2d):
    return win32com.client.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def pnt3d(val: Ge.Point3d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def vec3d(val: Ge.Vector3d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def matrix3d(val: Ge.Matrix3d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def entlist(ents : [AcadApp24.IAcadEntity]):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_DISPATCH, ents)

def dbolist(objs : [AcadApp24.IAcadObject]):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_DISPATCH, objs)

def ssfilterType(ints):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_I2, ints)

def ssfilterData(strings):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_VARIANT, strings)