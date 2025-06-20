from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxEntity:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_trueColore(self):
        axSpace = self.axDoc.modelSpace()
        axColor = Ax.AcadAcCmColor(100, 100, 100)
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        ent.setTrueColor(axColor)
        axColor2 = ent.trueColor()
        assert axColor.red() == axColor2.red()
        assert axColor.green() == axColor2.green()
        assert axColor.blue() == axColor2.blue()

    def test_intersectWith(self):
        axSpace = self.axDoc.modelSpace()
        axLine1 = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        axLine2 = axSpace.addLine(Ge.Point3d(100, 0, 0), Ge.Point3d(0, 100, 0))
        axCircle = axSpace.addCircle(Ge.Point3d(50, 50, 0), 50)
        inters1 = axLine1.intersectWith(axLine2, Ax.AcExtendOption.acExtendNone)
        inters2 = axLine1.intersectWith(axCircle, Ax.AcExtendOption.acExtendNone)
        inters3 = axLine2.intersectWith(axCircle, Ax.AcExtendOption.acExtendNone)
        assert len(inters1) == 1
        assert inters1[0] == Ge.Point3d(50, 50, 0)
        assert len(inters2) == 2
        assert len(inters3) == 2
        assert inters2[0].distanceTo(inters2[1]) == 100.0
        assert inters3[0].distanceTo(inters3[1]) == 100.0
        
    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_GRX
    def test_arrayPolar(self):
        axSpace = self.axDoc.modelSpace()
        axEnt = axSpace.addCircle(Ge.Point3d(2,2,0),1)
        axEnts: list[Ax.AcadEntity]
        axEnts = axEnt.arrayPolar(4,3.14,Ge.Point3d(3,3,0))
        assert len(axEnts) == 3
