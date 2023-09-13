import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import traceback

def importDimStyleFromDb(destDb : Db.Database, srcDb : Db.Database):
    
    idmap = Db.IdMapping()
    srcdims = Db.DimStyleTable(srcDb.dimStyleTableId())
    
    destDb.wblockCloneObjects(
        srcdims.recordIds(), 
        destDb.dimStyleTableId(),
        idmap, 
        Db.DuplicateRecordCloning.kDrcIgnore)
    
def PyRxCmd_doit():
    try:
        lock = Ap.AutoDocLock()
        destDb = Db.curDb()
        sourceDb = Db.Database(False,True)
        sourceDb.readDwgFile("E://06457Submittal.dwg")
        sourceDb.closeInput(True)
        
        #scope
        importDimStyleFromDb(destDb , sourceDb)

    except Exception as err:
        traceback.print_exception(err)
