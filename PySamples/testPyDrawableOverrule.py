from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs


def OnPyInitApp():
    print("\ncommand = pydrawoverrule")
    print("\ncommand = pystopoverrule")


def OnPyUnloadApp():
    # please exit cleanly
    PyRxCmd_pystopoverrule()


class MyDrawableOverrule(Gi.DrawableOverrule):
    def __init__(self):
        Gi.DrawableOverrule.__init__(self)

    # override
    def isApplicable(self, subject):
        return True

    # override
    def worldDraw(self, subject, wd):
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
            seg = Ge.LineSeg3d(line.endPoint(), line.startPoint())
            cen = seg.midPoint()
            rad = seg.length() * 0.3

            # draw circle
            traits.setColor(1)
            geo = wd.geometry()
            geo.circle(cen, rad, Ge.Vector3d.kZAxis)

            # draw text
            traits.setColor(2)
            testpos = cen + (seg.direction().perpVector().normalize() * 3)
            geo.text(testpos, Ge.Vector3d.kZAxis,
                     seg.direction(), 10, 1.0, 0, "SUP Bruh")

            # returing false here will go to viewport
            return flag
        except Exception as err:
            print(err)

overrule = None

def PyRxCmd_pydrawoverrule():
    try:
        global overrule
        if overrule != None:
            return 
        overrule = MyDrawableOverrule()
        overrule.addOverrule(Db.Line.desc(), overrule)
        overrule.setIsOverruling(True)
    except Exception as err:
        print(err)


def PyRxCmd_pystopoverrule():
    try:
        global overrule
        if overrule == None:
            return
        if overrule.removeOverrule(Db.Line.desc(), overrule) == Db.ErrorStatus.eOk:
            overrule.setIsOverruling(False)
        del (overrule)
    except Exception as err:
        print(err)
