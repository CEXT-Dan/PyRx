import traceback
from pyrx_imp import Rx, Ge, Gi, Db, Ap, Ed


class MyReactor(Db.DbObjectReactor):
    def __init__(self):
        Db.DbObjectReactor.__init__(self)

    def cancelled(self, Obj: Db.DbObject) -> None:
        print("cancelled", Obj.isA().dxfName())

    def copied(self, Obj: Db.DbObject, newObj: Db.DbObject) -> None:
        print("copied", Obj.isA().dxfName(), newObj.isA().dxfName())

    def erased(self, Obj: Db.DbObject, flag: bool) -> None:
        print("erased", Obj.isA().dxfName(), flag)

    def goodbye(self, Obj: Db.DbObject) -> None:
        print("goodbye", Obj.isA().dxfName())

    def openedForModify(self, Obj: Db.DbObject) -> None:
        print("openedForModify", Obj.isA().dxfName())

    def modified(self, Obj: Db.DbObject) -> None:
        print("modified", Obj.isA().dxfName())

    def subObjModified(self, Obj: Db.DbObject, subObj: Db.DbObject):
        print("subObjModified", Obj.isA().dxfName(), subObj.isA().dxfName())

    def modifyUndone(self, Obj: Db.DbObject) -> None:
        print("modifyUndone", Obj.isA().dxfName())
        
    def modifiedXData(self, Obj: Db.DbObject) -> None:
        print("modifiedXData", Obj.isA().dxfName())
        
    def unappended(self, Obj: Db.DbObject) -> None:
        print("unappended", Obj.isA().dxfName())
        
    def reappended(self, Obj: Db.DbObject) -> None:
        print("reappended", Obj.isA().dxfName())

    def objectClosed(self, id: Db.ObjectId) -> None:
        print("objectClosed", id.objectClass().dxfName())


myReactor = MyReactor()


def PyRxCmd_doit():
    try:
        db = Db.curDb()
        entRes = Ed.Editor.entSel("\nSelect Ent: ")
        if (entRes[0] != Ed.PromptStatus.eNormal):
            return
        ent = Db.Entity(entRes[1])
        ent.addReactor(myReactor)
    except Exception as err:
        print(err)
