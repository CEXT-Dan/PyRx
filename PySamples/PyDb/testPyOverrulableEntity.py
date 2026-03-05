import traceback

from pyrx import Ap, Db, Ge, Gi


def OnPyInitApp() -> None:
    print("\ncommand = pycreateoverrule")
    print("\ncommand = pystartoverrule")
    print("\ncommand = pystopoverrule")


def OnPyUnloadApp() -> None:
    # please exit cleanly
    pystopoverrule()


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

            # cast subject
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


class GrpOverrule(Db.GripOverrule):
    def __init__(self) -> None:
        Db.GripOverrule.__init__(self)

    # override
    def isApplicable(self, subject) -> bool:
        return True

    # override
    def getGripPoints(self, subject, gripPoints : list[Ge.Point3dArray], osnapModes, geomIds) -> bool:
        try:
            ore = Db.OverrulableEntity.cast(subject)
            gripPoints.extend(ore.points())
            stat = Db.ErrorStatus.eOk
        except Exception as err:
            traceback.print_exception(err)
            stat = Db.ErrorStatus.eInvalidInput
        finally:
            return stat

    def moveGripPointsAt(self, subject, indices, offset) -> bool:
        try:
            print(indices, offset)
            stat = Db.ErrorStatus.eOk
        except Exception as err:
            traceback.print_exception(err)
            stat = Db.ErrorStatus.eInvalidInput
        finally:
            return stat


overrulableEntityDraw = None
overrulableEntityGrip = None


def OnDblClk(ent: Db.OverrulableEntity, pnt: Ge.Point3d):
    print(ent.isA().name(), pnt)

@Ap.Command()
def pycreateoverrule():
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


@Ap.Command()
def pystartoverrule():
    try:
        global overrulableEntityDraw
        if overrulableEntityDraw is not None:
            return
        overrulableEntityDraw = OrDrawOverrule()
        overrulableEntityDraw.addOverrule(
            Db.OverrulableEntity.desc(), overrulableEntityDraw
        )
        overrulableEntityDraw.setIsOverruling(True)

        global overrulableEntityGrip
        if overrulableEntityGrip is not None:
            return

        overrulableEntityGrip = GrpOverrule()
        overrulableEntityGrip.addOverrule(
            Db.OverrulableEntity.desc(), overrulableEntityGrip
        )
        overrulableEntityGrip.setIsOverruling(True)

        print("overruling is on, please regen: ")

        Db.OverrulableEntity.registerOnDoubleClick(OnDblClk)
    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def pystopoverrule():
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

        global overrulableEntityGrip
        if overrulableEntityGrip is None:
            return
        if (
            overrulableEntityGrip.removeOverrule(
                Db.OverrulableEntity.desc(), overrulableEntityGrip
            )
            == Db.ErrorStatus.eOk
        ):
            overrulableEntityGrip.setIsOverruling(False)
        overrulableEntityGrip = None

        print("overruling is off, please regen: ")

        Db.OverrulableEntity.removeOnDoubleClick(OnDblClk)
    except Exception as err:
        traceback.print_exception(err)
