# import
import PyGe as Ge
import win32com.client
import pythoncom
import AcadApp24

def getApp() -> AcadApp24.IAcadApplication:
    id = AcadApp24.AcadApplication.CLSID
    app: AcadApp24.IAcadApplication = win32com.client.Dispatch(id)
    return app

def comPnt2d(val: Ge.Point2d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def comVec2d(val: Ge.Vector2d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def comMatrix2d(val: Ge.Matrix2d):
    return win32com.client.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def comPnt3d(val: Ge.Point3d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def comVec3d(val: Ge.Vector3d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def comMatrix3d(val: Ge.Matrix3d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())