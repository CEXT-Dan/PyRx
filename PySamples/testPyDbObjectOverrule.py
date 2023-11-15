import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor


def OnPyInitApp():
    print("\ncommand = pydbooverrule")
    print("\ncommand = pystopdbooverrule")


def OnPyUnloadApp():
    # please exit cleanly
    PyRxCmd_pystopdbooverrule()


class MyDboOverrule(PyDb.DbObjectOverrule):
    def __init__(self):
        PyDb.DbObjectOverrule.__init__(self)

    # must override
    def isApplicable(self, subject):
        return True

    # optional override
    def open(self, subject: PyDb.DbObject, mode: PyDb.OpenMode) -> PyDb.ErrorStatus:
        try:
            return self.baseOpen(subject, mode)
        except Exception as err:
            print(err)

    def close(self, subject: PyDb.DbObject) -> PyDb.ErrorStatus:
        try:
            return self.baseClose(subject)
        except Exception as err:
            print(err)

    def cancel(self, subject: PyDb.DbObject) -> PyDb.ErrorStatus:
        try:
            return self.baseCancel(subject)
        except Exception as err:
            print(err)

    def erase(self, subject: PyDb.DbObject, erasing: bool) -> PyDb.ErrorStatus:
        try:
            return self.baseErase(subject, erasing)
        except Exception as err:
            print(err)

    def deepClone(self, subject, pOwnerObject, idMap, isPrimary) -> PyDb.DbObject:
        try:
            clonedObject = self.baseDeepClone(subject, pOwnerObject, idMap, isPrimary)
            # line = PyDb.Line.cast(clonedObject)
            # line.setColorIndex(2)
            return clonedObject
        except Exception as err:
            print(err)

    def wblockClone(self, subject, pOwnerObject, idMap, isPrimary) -> PyDb.DbObject:
        try:
            clonedObject = self.baseWblockClone(subject, pOwnerObject, idMap, isPrimary)
            line = PyDb.Line.cast(clonedObject)
            line.setColorIndex(1)
            return clonedObject
        except Exception as err:
            print(err)


overrule = None


def PyRxCmd_pydbooverrule():
    try:
        global overrule
        if overrule != None:
            return
        overrule = MyDboOverrule()
        overrule.addOverrule(PyDb.Line.desc(), overrule)
        overrule.setIsOverruling(True)
    except Exception as err:
        print(err)


def PyRxCmd_pystopdbooverrule():
    try:
        global overrule
        if overrule == None:
            return
        if overrule.removeOverrule(PyDb.Line.desc(), overrule) == PyDb.ErrorStatus.eOk:
            overrule.setIsOverruling(False)
        del overrule
    except Exception as err:
        print(err)
