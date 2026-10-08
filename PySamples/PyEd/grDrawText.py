import math
import traceback

from pyrx import Ap, Db, Ed, Ge


@Ap.Command()
def doit1():
    try:
        val = "This is some text"
        mat = Ge.Matrix3d.translation(Ge.Point3d(10, 10, 0).asVector())
        Ed.Core.grDrawText(val, mat, 1)
    except Exception:
        traceback.print_exc()


@Ap.Command()
def doit2():
    try:
        db = Db.curDb()
        val = "This is some text"
        
        # explicit font
        font = "simplex.shx"
        
        # Translation)
        mat = Ge.Matrix3d.translation(Ge.Vector3d(7.5, 7.5, 0))
        
        # Append Rotation
        mat *= Ge.Matrix3d.rotation(math.radians(45), Ge.Vector3d.kZAxis, Ge.Point3d.kOrigin)
        
        # Append Scale
        mat *= Ge.Matrix3d.scaling(db.textsize(), Ge.Point3d.kOrigin)
        
        # Translation * Rotation * Scale
        Ed.Core.grDrawText(val, font, mat, 2)
        
    except Exception:
        traceback.print_exc()
