import os
from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

print("added command pyreaddwg")

print(os.getcwd())


def PyRxCmd_pyreaddwg():
    try:
        db = Db.Database(False, True)
        es = db.readDwgFile("..\\dwg\\Floor Plan Sample.dwg")
        if es != Db.ErrorStatus.eOk:
            print("readDwgFile failed:", es)
            return

        db.closeInput(True)
        entities = {}
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForRead)

        for id in model.objectIds():
            classname = id.objectClass().name()
            if classname in entities:
                entities[classname] = entities[classname]+1
            else:
                entities[classname] = 1
        print(entities)
    except Exception as err:
        print(err)
