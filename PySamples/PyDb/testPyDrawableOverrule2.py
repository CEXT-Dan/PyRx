import traceback

import wx

from pyrx import Ap, Db, Ed, Ge, Gi

vpids = []
markers = []
pointdraw = None


def OnPyInitApp() -> None:
    pydrawoverrule()


def OnPyUnloadApp() -> None:
    # please exit cleanly
    pystopoverrule()
    clear()


class PointDrawOverrule(Gi.DrawableOverrule):
    def __init__(self) -> None:
        Gi.DrawableOverrule.__init__(self)

        # load the file
        self.img = wx.Image()
        self.img.LoadFile("E:\\temp\\map.png")

        # create a cache
        self.buffer = Gi.PixelBGRA32Array.createFromWxImage(self.img, 125)

    # override
    def isApplicable(self, subject) -> bool:
        return True

    # override
    def worldDraw(self, subject, wd) -> bool:
        try:
            flag = self.baseWorldDraw(subject, wd)
            point = Db.Point.cast(subject)
            pos = point.position()
            up = Ge.Point3d(pos.x + self.img.Width, pos.y, pos.z)
            vp = Ge.Point3d(pos.x, pos.y + self.img.Height, pos.z)
            geo: Gi.Geometry = wd.geometry()
            geo.image(self.buffer, self.img.Width, self.img.Height, pos, up - pos, vp - pos)
        except Exception as err:
            traceback.print_exception(err)
        finally:
            return flag

@Ap.Command()
def pydrawoverrule():
    try:
        global pointdraw
        if pointdraw is not None:
            return
        pointdraw = PointDrawOverrule()
        pointdraw.addOverrule(Db.Point.desc(), pointdraw)
        pointdraw.setIsOverruling(True)
    except Exception as err:
        traceback.print_exception(err)

@Ap.Command()
def pystopoverrule():
    try:
        global pointdraw
        if pointdraw is None:
            return
        if pointdraw.removeOverrule(Db.Point.desc(), pointdraw) == Db.ErrorStatus.eOk:
            pointdraw.setIsOverruling(False)
        pointdraw = None
    except Exception as err:
        traceback.print_exception(err)


def clear():
    tm = Gi.TransientManager.current()
    for marker in markers:
        tm.eraseTransient(marker, vpids)
    vpids.clear()
    markers.clear()


@Ap.Command()
def doit():
    try:
        clear()
        vpids.append(Ed.Core.getVar("CVPORT"))

        # Z
        dbl = Db.Point(Ge.Point3d(0, 0, -1))
        dbl.setDatabaseDefaults()
        markers.append(dbl)
        tm = Gi.TransientManager.current()

        # kAcGiMain
        tm.addTransient(dbl, Gi.TransientDrawingMode.kAcGiMain, 0, vpids)
        Ed.Core.vportTableRecords2Vports()
    except Exception as err:
        traceback.print_exception(err)
