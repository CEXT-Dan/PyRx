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

    # override
    def isApplicable(self, subject):
        return True

    # override
    def close(self, subject : PyDb.DbObject):
        try:
            # if(subject.isWriteEnabled()):
            #     ent = PyDb.Entity.cast(subject)
            #     ent.setColorIndex(1)
            return self.baseClose(subject)
        except Exception as err:
            print(err)
            
    def deepClone(self, subject, pOwnerObject,pClonedObject,idMap,isPrimary):
        try:
            # if(pClonedObject.isWriteEnabled()):
            #     ent = PyDb.Entity.cast(pClonedObject)
            #     ent.setColorIndex(2)
            return PyDb.ErrorStatus.eOk
        except Exception as err:
            print(err)
            return PyDb.ErrorStatus.eInvalidInput
            
    def wblockClone(self, subject, pOwnerObject,pClonedObject,idMap,isPrimary):
        try:
            # if(pClonedObject.isWriteEnabled()):
            #     ent = PyDb.Entity.cast(pClonedObject)
            #     ent.setColorIndex(3)
            return PyDb.ErrorStatus.eOk
        except Exception as err:
            print(err)
            return PyDb.ErrorStatus.eInvalidInput

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
        del (overrule)
    except Exception as err:
        print(err)
