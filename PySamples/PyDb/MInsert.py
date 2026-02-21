import traceback
from pyrx import Ap, Db, Ed, Ge

"""
The AcDbMInsertBlock class represents a special form of the INSERT entity in which an array
of duplicate images of the entities within the referenced AcDbBlockTableRecord is
displayed. Creating an AcDbMInsertBlock with a definition of rows = 1 and columns = 1 will
create a AcDbBlockReference instead.
"""


@Ap.Command()
def doit0():
    try:
        db = Db.curDb()
        blks = db.getBlocks()
        mi = Db.MInsertBlock(Ge.Point3d.kOrigin, blks["n"], 5, 5, 100, 100)
        db.addToModelspace(mi)
    except Exception:
        traceback.print_exc()
