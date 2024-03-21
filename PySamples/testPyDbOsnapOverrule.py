from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs


def OnPyInitApp():
    print("\ncommand = pyosnapoverrule")
    print("\ncommand = pystoppyosnapoverrule")


def OnPyUnloadApp():
    # please exit cleanly
    PyRxCmd_pystoppyosnapoverrule()


class MyOsnapOverrule(Db.OsnapOverrule):
    def __init__(self):
        Db.OsnapOverrule.__init__(self)

    # must override
    def isApplicable(self, subject):
        return True

    # optional override
    def isContentSnappable(self, subject: Db.Entity) -> bool:
        try:
            if subject.isA().isDerivedFrom(Db.Line.desc()):
                return False
            return self.baseIsContentSnappable(subject)
        except Exception as err:
            print(err)


overrule = None


def PyRxCmd_pyosnapoverrule():
    try:
        global overrule
        if overrule != None:
            return
        overrule = MyOsnapOverrule()
        overrule.addOverrule(Db.Line.desc(), overrule)
        overrule.setIsOverruling(True)
    except Exception as err:
        print(err)


def PyRxCmd_pystoppyosnapoverrule():
    try:
        global overrule
        if overrule == None:
            return
        if overrule.removeOverrule(Db.Line.desc(), overrule) == Db.ErrorStatus.eOk:
            overrule.setIsOverruling(False)
        del overrule
    except Exception as err:
        print(err)
