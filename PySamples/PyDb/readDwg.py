from pyrx_imp import Db

print("added command pyreaddwg")

# debug
def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()

# Python disposes object in order of creation
# so we'll define new a new function as a scope 
# to make sure modelspace is closed before the database

def iterateDatabase(db: Db.Database, entities):
    model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForRead)
    for id in model.objectIds():
        classname = id.objectClass().name()
        if classname in entities:
            entities[classname] = entities[classname]+1
        else:
            entities[classname] = 1
    
def PyRxCmd_pyreaddwg():
    try:
        db = Db.Database(False, True)
        db.readDwgFile("..\\dwg\\Floor Plan Sample.dwg")
        db.closeInput(True)
        entities = {}
        
        #scope
        iterateDatabase(db, entities)
       
        print(entities)
    except Exception as err:
        print(err)
