import traceback

from pyrx import Db, Ge, Gi


def OnPyInitApp() -> None:
    print("\ncommand = pycreateoverrule")
    print("\ncommand = pydrawoverrule")
    print("\ncommand = pystopoverrule")


def OnPyUnloadApp() -> None:
    # please exit cleanly
    PyRxCmd_pystopoverrule()


class OrDrawOverrule(Gi.DrawableOverrule):
    def __init__(self) -> None:
        Gi.DrawableOverrule.__init__(self)

    # override
    def isApplicable(self, subject) -> bool:
        return True

    # override
    def worldDraw(self, subject, wd) -> bool:
        try:
            # draw the subject first
            flag = self.baseWorldDraw(subject, wd)

            # cast subject to a line
            ore = Db.OverrulableEntity.cast(subject)

            # Transparency
            traits = wd.subEntityTraits()
            trans = Db.Transparency(0.3)
            traits.setTransparency(trans)

            geo: Gi.Geometry = wd.geometry()

            for p, r in zip(ore.points(), ore.doubles()):
                geo.circle(p, r, Ge.Vector3d.kZAxis)

            for p, s in zip(ore.points(), ore.strings()):
                geo.text(p, ore.normal(), ore.direction(), 1, 1, 0, s)

        except Exception as err:
            traceback.print_exception(err)
        finally:
            return flag


overrulableEntityDraw = None


def PyRxCmd_pycreateoverrule():
    try:
        db = Db.curDb()
        ore = Db.OverrulableEntity()
        ore.setStrings(["Welcome", "To", "The", "Swamp"])
        ore.setDoubles([1.5, 1.0, 1.0, 1.0])

        pos = ore.position()
        ore.setPoints(
            [
                pos,
                pos + (Ge.Vector3d.kYAxis * 3),
                pos + (Ge.Vector3d.kYAxis * 5),
                pos + (Ge.Vector3d.kYAxis * 7),
            ]
        )
        db.addToModelspace(ore)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pydrawoverrule():
    try:
        global overrulableEntityDraw
        if overrulableEntityDraw is not None:
            return
        overrulableEntityDraw = OrDrawOverrule()
        overrulableEntityDraw.addOverrule(Db.OverrulableEntity.desc(), overrulableEntityDraw)
        overrulableEntityDraw.setIsOverruling(True)
        print("overruling is on, please regen: ")
    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pystopoverrule():
    try:
        global overrulableEntityDraw
        if overrulableEntityDraw is None:
            return
        if (
            overrulableEntityDraw.removeOverrule(
                Db.OverrulableEntity.desc(), overrulableEntityDraw
            )
            == Db.ErrorStatus.eOk
        ):
            overrulableEntityDraw.setIsOverruling(False)
        overrulableEntityDraw = None
        print("overruling is off, please regen: ")
    except Exception as err:
        traceback.print_exception(err)
