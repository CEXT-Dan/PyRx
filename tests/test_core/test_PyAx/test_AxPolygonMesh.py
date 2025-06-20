from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxPolygonMesh :

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_getcoordinates(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(2, 0, 1),
            Ge.Point3d(4, 0, 0),
            Ge.Point3d(6, 0, 1),
            Ge.Point3d(0, 2, 0),
            Ge.Point3d(2, 2, 1),
            Ge.Point3d(4, 2, 0),
            Ge.Point3d(6, 2, 1),
            Ge.Point3d(0, 4, 0),
            Ge.Point3d(2, 4, 1),
            Ge.Point3d(4, 4, 0),
            Ge.Point3d(6, 4, 1),
            Ge.Point3d(0, 6, 0),
            Ge.Point3d(2, 6, 1),
            Ge.Point3d(4, 6, 0),
            Ge.Point3d(6, 6, 1),
        ]
        axSpace = self.axDoc.modelSpace()
        mesh = axSpace.add3DMesh(4, 4, pnts)
        assert mesh.objectName() == "AcDbPolygonMesh"
        assert mesh.coordinates() == pnts

    @pytest.mark.known_failure_GRX
    def test_setcoordinates(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(2, 0, 1),
            Ge.Point3d(4, 0, 0),
            Ge.Point3d(6, 0, 1),
            Ge.Point3d(0, 2, 0),
            Ge.Point3d(2, 2, 1),
            Ge.Point3d(4, 2, 0),
            Ge.Point3d(6, 2, 1),
            Ge.Point3d(0, 4, 0),
            Ge.Point3d(2, 4, 1),
            Ge.Point3d(4, 4, 0),
            Ge.Point3d(6, 4, 1),
            Ge.Point3d(0, 6, 0),
            Ge.Point3d(2, 6, 1),
            Ge.Point3d(4, 6, 0),
            Ge.Point3d(6, 6, 1),
        ]
        axSpace = self.axDoc.modelSpace()
        mesh = axSpace.add3DMesh(4, 4, pnts)
        mesh.setCoordinates(pnts)
        
    def test_getcoordinate(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(2, 0, 1),
            Ge.Point3d(4, 0, 0),
            Ge.Point3d(6, 0, 1),
            Ge.Point3d(0, 2, 0),
            Ge.Point3d(2, 2, 1),
            Ge.Point3d(4, 2, 0),
            Ge.Point3d(6, 2, 1),
            Ge.Point3d(0, 4, 0),
            Ge.Point3d(2, 4, 1),
            Ge.Point3d(4, 4, 0),
            Ge.Point3d(6, 4, 1),
            Ge.Point3d(0, 6, 0),
            Ge.Point3d(2, 6, 1),
            Ge.Point3d(4, 6, 0),
            Ge.Point3d(6, 6, 1),
        ]
        axSpace = self.axDoc.modelSpace()
        mesh = axSpace.add3DMesh(4, 4, pnts)
        assert mesh.coordinate(1) == pnts[1]

    @pytest.mark.known_failure_GRX
    def test_setcoordinate(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(2, 0, 1),
            Ge.Point3d(4, 0, 0),
            Ge.Point3d(6, 0, 1),
            Ge.Point3d(0, 2, 0),
            Ge.Point3d(2, 2, 1),
            Ge.Point3d(4, 2, 0),
            Ge.Point3d(6, 2, 1),
            Ge.Point3d(0, 4, 0),
            Ge.Point3d(2, 4, 1),
            Ge.Point3d(4, 4, 0),
            Ge.Point3d(6, 4, 1),
            Ge.Point3d(0, 6, 0),
            Ge.Point3d(2, 6, 1),
            Ge.Point3d(4, 6, 0),
            Ge.Point3d(6, 6, 1),
        ]
        axSpace = self.axDoc.modelSpace()
        mesh = axSpace.add3DMesh(4, 4, pnts)
        mesh.setCoordinate(1,Ge.Point3d(2, 1, 1))
        assert mesh.coordinate(1) == Ge.Point3d(2, 1, 1)
        
    def test_explode(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(2, 0, 1),
            Ge.Point3d(4, 0, 0),
            Ge.Point3d(6, 0, 1),
            Ge.Point3d(0, 2, 0),
            Ge.Point3d(2, 2, 1),
            Ge.Point3d(4, 2, 0),
            Ge.Point3d(6, 2, 1),
            Ge.Point3d(0, 4, 0),
            Ge.Point3d(2, 4, 1),
            Ge.Point3d(4, 4, 0),
            Ge.Point3d(6, 4, 1),
            Ge.Point3d(0, 6, 0),
            Ge.Point3d(2, 6, 1),
            Ge.Point3d(4, 6, 0),
            Ge.Point3d(6, 6, 1),
        ]
        axSpace = self.axDoc.modelSpace()
        mesh = axSpace.add3DMesh(4, 4, pnts)
        
        entinfo = set()
        ent: Ax.AcadEntity
        i = 0
        for ent in mesh.explode():
            i += 1
            entinfo.add(ent.objectName())
            
        assert 'AcDbFace' in entinfo
        assert i == 9



