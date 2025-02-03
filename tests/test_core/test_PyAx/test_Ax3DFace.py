from __future__ import annotations
import pytest
from tests import HOST
from pyrx import Ap, Ge, Ax


class TestAx3dFace:

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
        face = axSpace.add3DFace(pnts[0], pnts[1], pnts[2], pnts[3])
        assert face.coordinates() == pnts
