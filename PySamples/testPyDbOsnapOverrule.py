from pyrx import Db, Ge


def OnPyInitApp() -> None:
    print("\ncommand = pyosnapoverrule")
    print("\ncommand = pystoppyosnapoverrule")


def OnPyUnloadApp() -> None:
    PyRxCmd_pystoppyosnapoverrule()


class MyOsnapOverrule(Db.OsnapOverrule):
    def __init__(self) -> None:
        Db.OsnapOverrule.__init__(self)

    # must override
    def isApplicable(self, subject) -> bool:
        return True

    # optional override
    def isContentSnappable(self, subject: Db.Entity) -> bool:
        try:
            print(subject.isA().name())
            return self.baseIsContentSnappable(subject)
        except Exception as err:
            print(err)

    # return type (Db.ErrorStatus,[])
    def getOsnapPoints(
        self, subject, osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform
    ) -> tuple[Db.ErrorStatus, list[Ge.Point3d]]:

        try:
            # return (Db.ErrorStatus.eInvalidInput,[])

            # pass through
            res = self.baseGetOsnapPoints(
                subject, osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform
            )

            # print(res)

            return res

        except Exception as err:
            print(err)

    # return type (Db.ErrorStatus,[])
    def getOsnapPointsX(
        self, subject, osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, insertionMat
    ) -> tuple[Db.ErrorStatus, list[Ge.Point3d]]:

        try:
            # return (Db.ErrorStatus.eInvalidInput,[])

            # pass through
            res = self.baseGetOsnapPointsX(
                subject, osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, insertionMat
            )

            # print('X', res)
            return res

        except Exception as err:
            print(err)


overrule = None


# start/stop the overrule
def PyRxCmd_pyosnapoverrule() -> None:
    try:
        global overrule
        if overrule is None:
            return
        overrule = MyOsnapOverrule()
        overrule.addOverrule(Db.Entity.desc(), overrule)
        overrule.setIsOverruling(True)
    except Exception as err:
        print(err)


def PyRxCmd_pystoppyosnapoverrule():
    try:
        global overrule
        if overrule is None:
            return
        if overrule.removeOverrule(Db.Entity.desc(), overrule) == Db.ErrorStatus.eOk:
            overrule.setIsOverruling(False)
        del overrule
    except Exception as err:
        print(err)
