from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


def is_before(objs: list[Ax.AcadEntity], left: Ax.AcadEntity, right: Ax.AcadEntity):
    for obj in objs:
        if obj == right:
            return False
        elif obj == left:
            return True


class TestAcadSortentsTable:
    @pytest.mark.known_failure_GRX
    def test_getinstance(self):
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axModel = axDoc.modelSpace()

        axEnt1 = axModel.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        axEnt2 = axModel.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))

        ex = axModel.extensionDictionary()
        if "AcDbSortentsTable" not in [i.objectName() for i in ex.items()]:
            ex.addObject("ACAD_SORTENTS", "AcDbSortentsTable")

        axSortEnts = Ax.AcadSortentsTable.cast(ex.object("ACAD_SORTENTS"))
        axSortEnts.moveToTop([axEnt1])
        axSortEnts.moveToBottom([axEnt2])

        do = axSortEnts.fullDrawOrder(True)
        assert is_before(do,axEnt1,axEnt2) == False

        axSortEnts.swapOrder(axEnt1, axEnt2)
        do = axSortEnts.fullDrawOrder(True)
        assert is_before(do,axEnt1,axEnt2) == True

        axSortEnts.moveToTop([axEnt1])
        axSortEnts.moveToBottom([axEnt2])
        do = axSortEnts.fullDrawOrder(True)
        assert is_before(do,axEnt1,axEnt2) == False

        axSortEnts.moveToTop([axEnt2])
        axSortEnts.moveToBottom([axEnt1])
        do = axSortEnts.fullDrawOrder(True)
        assert is_before(do,axEnt1,axEnt2) == True
