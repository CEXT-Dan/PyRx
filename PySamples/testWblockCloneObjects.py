from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs
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
