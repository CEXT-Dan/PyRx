from pyrx import Ap, Ax, Db, Ed, Ge, Rx
import traceback

def far(db: Db.Database, trm: Db.TransactionManager):
    # Sub-transaction 2
    tr = trm.startTransaction()
    model = Db.BlockTableRecord.cast(tr.getObject(db.modelSpaceId(), Db.OpenMode.kForWrite))
    circle = Db.Circle(Ge.Point3d(50, 50, 0), Ge.Vector3d.kZAxis, 25)
    model.appendAcDbEntity(circle)
    trm.addNewlyCreatedDBRObject(circle)
    trm.endTransaction() # Closes Sub-transaction 2

def foo(db: Db.Database, trm: Db.TransactionManager):
    # Sub-transaction 1
    tr = trm.startTransaction()
    model = Db.BlockTableRecord.cast(tr.getObject(db.modelSpaceId(), Db.OpenMode.kForWrite))
    line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
    model.appendAcDbEntity(line)
    trm.addNewlyCreatedDBRObject(line)
    trm.endTransaction() # Closes Sub-transaction 1

@Ap.Command()
def doit():
    try:
        db = Db.curDb()
        trm = db.transactionManager()
        master_tr = trm.startTransaction()
        foo(db, trm)
        far(db, trm)
        trm.endTransaction() 
        print("\nOperation committed successfully.")
    except Exception as e:
        trm.abortTransaction()
        traceback.print_exc()
