from __future__ import annotations
import pytest
from tests import HOST
from pyrx import Ap, Ge, Ax


class TestAxBlock:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_add3DFace(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        face = axSpace.add3DFace(pnts[0], pnts[1], pnts[2], pnts[3])
        assert face.objectName() == "Acad3DFace"

    def test_add3DMesh(self):
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
        mesh = axSpace.add3DMesh(4,4,pnts)
        assert mesh.objectName() == "AcadPolygonMesh"


