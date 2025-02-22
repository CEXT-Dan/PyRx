from __future__ import annotations
import pytest
from tests import HOST
from pyrx import Ap, Ge, Ax


class TestAx3DPolyline:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_getcoordinates(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.add3DPoly(pnts)
        assert ent.objectName() == "AcDb3dPolyline"
        assert ent.coordinates() == pnts

    def test_setcoordinates(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.add3DPoly(pnts)
        assert ent.coordinates() == pnts
        pnts.reverse()
        ent.setCoordinates(pnts)
        assert ent.coordinates() == pnts

    def test_getcoordinate(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.add3DPoly(pnts)
        assert ent.coordinate(3) == pnts[3]

    def test_setcoordinate(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.add3DPoly(pnts)
        ent.setCoordinate(0, Ge.Point3d(0, 1, 0))
        assert ent.coordinate(0) == Ge.Point3d(0, 1, 0)

    def test_closed(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.add3DPoly(pnts)
        assert ent.isClosed() == False
        ent.setClosed(True)
        assert ent.isClosed() == True

    def test_length(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.add3DPoly(pnts)
        assert ent.length() == 300.0
        ent.setClosed(True)
        assert ent.length() == 400.0

    def test_explode(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.add3DPoly(pnts)

        entinfo = set()
        ent: Ax.AcadEntity
        i = 0
        for ent in ent.explode():
            i += 1
            entinfo.add(ent.objectName())

        assert "AcDbLine" in entinfo
        assert i == 3
