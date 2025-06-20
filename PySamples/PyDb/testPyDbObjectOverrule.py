from pyrx import Db


def OnPyInitApp():
    print("\ncommand = pydbooverrule")
    print("\ncommand = pystopdbooverrule")


def OnPyUnloadApp():
    # please exit cleanly
    PyRxCmd_pystopdbooverrule()


class MyDboOverrule(Db.DbObjectOverrule):
    def __init__(self):
        Db.DbObjectOverrule.__init__(self)

    # must override
    def isApplicable(self, subject):
        return True

    # optional override
    def open(self, subject: Db.DbObject, mode: Db.OpenMode) -> Db.ErrorStatus:
        try:
            return self.baseOpen(subject, mode)
        except Exception as err:
            print(err)

    def close(self, subject: Db.DbObject) -> Db.ErrorStatus:
        try:
            return self.baseClose(subject)
        except Exception as err:
            print(err)

    def cancel(self, subject: Db.DbObject) -> Db.ErrorStatus:
        try:
            return self.baseCancel(subject)
        except Exception as err:
            print(err)

    def erase(self, subject: Db.DbObject, erasing: bool) -> Db.ErrorStatus:
        try:
            return self.baseErase(subject, erasing)
        except Exception as err:
            print(err)

    def deepClone(self, subject, pOwnerObject, idMap, isPrimary) -> Db.DbObject:
        try:
            clonedObject = self.baseDeepClone(subject, pOwnerObject, idMap, isPrimary)
            # line = Db.Line.cast(clonedObject)
            # line.setColorIndex(2)
            return clonedObject
        except Exception as err:
            print(err)

    def wblockClone(self, subject, pOwnerObject, idMap, isPrimary) -> Db.DbObject:
        try:
            clonedObject = self.baseWblockClone(subject, pOwnerObject, idMap, isPrimary)
            line = Db.Line.cast(clonedObject)
            line.setColorIndex(1)
            return clonedObject
        except Exception as err:
            print(err)


overrule = None


def PyRxCmd_pydbooverrule():
    try:
        global overrule
        if overrule is None:
            return
        overrule = MyDboOverrule()
        overrule.addOverrule(Db.Line.desc(), overrule)
        overrule.setIsOverruling(True)
    except Exception as err:
        print(err)


def PyRxCmd_pystopdbooverrule():
    try:
        global overrule
        if overrule is None:
            return
        if overrule.removeOverrule(Db.Line.desc(), overrule) == Db.ErrorStatus.eOk:
            overrule.setIsOverruling(False)
        del overrule
    except Exception as err:
        print(err)
