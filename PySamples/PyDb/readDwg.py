import os
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

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
