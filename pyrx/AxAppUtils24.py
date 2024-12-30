# import
import PyGe as Ge
import win32com.client
import pythoncom


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

# not sure if this is correct


def nestedXformToMatrix3d(xmat: list[tuple[float]]) -> Ge.Matrix3d:
    mat = Ge.Matrix3d()
    o = Ge.Point3d(xmat[3][0], xmat[3][1], xmat[3][2])
    x = Ge.Vector3d(xmat[0][0], xmat[0][1], xmat[0][2])
    y = Ge.Vector3d(xmat[1][0], xmat[1][1], xmat[1][2])
    z = Ge.Vector3d(xmat[2][0], xmat[2][1], xmat[2][2])
    mat.setCoordSystem(o, x, y, z)
    return mat
