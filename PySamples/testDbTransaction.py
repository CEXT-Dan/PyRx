import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("added command = doittr")

def do_something(tr):
    for obj in tr.getAllObjects():
        ent = Db.Entity.cast(obj)
        ent.upgradeOpen()
        ent.setColorIndex(1)
        
def make_objects(db,tmr):
    model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
    for ind in range(0,1):
        pnt = Db.Point(Ge.Point3d(ind,ind,0))
        model.appendAcDbEntity(pnt)
        tmr.addNewlyCreatedDBRObject(pnt)
    
def PyRxCmd_doittr():
    try:
        db = Db.HostApplicationServices().workingDatabase()
        tmr = Db.TransactionManager()
        tr = tmr.startTransaction()
        
        make_objects(db,tmr)
            
        do_something(tr)
        tmr.abortTransaction()
        #tmr.endTransaction()
        
    except Exception as err:
        print(err)
