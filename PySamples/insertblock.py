import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyGs as Gs

def OnPyInitApp():
    print("\nOnPyInitApp")
    print("Added command pyinsert")
	
def OnPyUnloadApp():
    print("\nOnPyUnloadApp")
        
def OnPyLoadDwg():
    print("\nOnPyLoadDwg")
	
def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")
         
def PyRxCmd_pyinsert():
    try: 
        db = Db.HostApplicationServices().workingDatabase()
        block = Db.Database(False, True)
        block.readDwgFile("./dwg/18X36RP.dwg")
        blockId = Db.ObjectId()
        db.insert(blockId,"WOOHOO", block, True)
        
        blockRef = Db.BlockReference(Ge.Point3d(100,100,0),blockId)
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(blockRef)

    except Exception as err:
        print(err)
