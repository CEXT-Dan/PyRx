import traceback

from pyrx import Db, Ge, Gi


def OnPyInitApp() -> None:
    print("\ncommand = pydrawoverrule")
    print("\ncommand = pystopoverrule")


def OnPyUnloadApp() -> None:
    # please exit cleanly
    PyRxCmd_pystopoverrule()


class LineDrawOverrule(Gi.DrawableOverrule):
    def __init__(self) -> None:
        Gi.DrawableOverrule.__init__(self)
        self.seg = Ge.LineSeg3d()

    # override
    def isApplicable(self, subject) -> bool:
        dbo = Db.Entity.cast(subject)
        return dbo.ownerId() == Db.workingDb().modelSpaceId()

    # override
    def worldDraw(self, subject, wd) -> bool:
        try:
            # draw the subject first
            flag = self.baseWorldDraw(subject, wd)

            # cast subject to a line
            line = Db.Line.cast(subject)

            # Transparency
            traits = wd.subEntityTraits()
            trans = Db.Transparency(0.3)
            traits.setTransparency(trans)

            # circle info
            self.seg.set(line.startPoint(), line.endPoint())
            cen = self.seg.midPoint()
            rad = self.seg.length() * 0.3

            # draw circle
            traits.setColor(1)
            geo = wd.geometry()
            geo.circle(cen, rad, Ge.Vector3d.kZAxis)

        except Exception as err:
            traceback.print_exception(err)
        finally:
            return flag


linedraw = None


def PyRxCmd_pydrawoverrule():
    try:
        global linedraw
        if linedraw is None:
            return
        linedraw = LineDrawOverrule()
        linedraw.addOverrule(Db.Line.desc(), linedraw)
        linedraw.setIsOverruling(True)
        print("overruling is on, please regen: ")
    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pystopoverrule():
    try:
        global linedraw
        if linedraw is None:
            return
        if linedraw.removeOverrule(Db.Line.desc(), linedraw) == Db.ErrorStatus.eOk:
            linedraw.setIsOverruling(False)
        linedraw = None
        print("overruling is off, please regen: ")
    except Exception as err:
        traceback.print_exception(err)
