from pyrx import Db

print("added command - addDbreactor")
print("added command - remDbreactor")


class MyReactor(Db.DatabaseReactor):
    def __init__(self):
        Db.DatabaseReactor.__init__(self)

    def objectAppended(self, db: Db.Database, Obj: Db.DbObject) -> None:
        print("objectAppended", db.getFilename(), Obj.isA().dxfName())

    def objectUnAppended(self, db: Db.Database, Obj: Db.DbObject) -> None:
        print("objectUnAppended", db.getFilename(), Obj.isA().dxfName())

    def objectReAppended(self, db: Db.Database, Obj: Db.DbObject) -> None:
        print("objectReAppended", db.getFilename(), Obj.isA().dxfName())

    def objectOpenedForModify(self, db: Db.Database, Obj: Db.DbObject) -> None:
        print("objectOpenedForModify", db.getFilename(), Obj.isA().dxfName())

    def objectModified(self, db: Db.Database, Obj: Db.DbObject) -> None:
        print("objectModified", db.getFilename(), Obj.isA().dxfName())

    def objectErased(self, db: Db.Database, Obj: Db.DbObject, erased) -> None:
        print("objectErased", db.getFilename(), Obj.isA().dxfName(), erased)

    def headerSysVarWillChange(self, db: Db.Database, name) -> None:
        print("headerSysVarWillChange", db.getFilename(), name)

    def headerSysVarChanged(self, db: Db.Database, name, bSuccess) -> None:
        print("headerSysVarChanged", db.getFilename(), name, bSuccess)

    def proxyResurrectionCompleted(self, db: Db.Database, name, objects) -> None:
        print("proxyResurrectionCompleted", db.getFilename(), name, objects)

    def goodbye(self, db: Db.Database) -> None:
        print("goodbye", db.getFilename())


myReactor = MyReactor()


def PyRxCmd_addDbreactor():
    try:
        db = Db.curDb()
        db.addReactor(myReactor)

    except Exception as err:
        print(err)


def PyRxCmd_remDbreactor():
    try:
        db = Db.curDb()
        db.removeReactor(myReactor)
    except Exception as err:
        print(err)
