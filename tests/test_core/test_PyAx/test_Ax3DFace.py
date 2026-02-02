from __future__ import annotations

from pyrx import Ap, Ge


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

    def test_setcoordinates(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        face = axSpace.add3DFace(pnts[0], pnts[1], pnts[2], pnts[3])
        assert face.coordinates() == pnts
        face.setCoordinates(pnts[3], pnts[2], pnts[1], pnts[0])
        pnts.reverse()
        assert face.coordinates() == pnts

    def test_getcoordinate(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        face = axSpace.add3DFace(pnts[0], pnts[1], pnts[2], pnts[3])
        assert face.coordinate(0) == pnts[0]

    def test_setcoordinate(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        face = axSpace.add3DFace(pnts[0], pnts[1], pnts[2], pnts[3])

        pnts[0] = Ge.Point3d(1, 1, 1)
        pnts[1] = Ge.Point3d(101, 1, 1)
        pnts[2] = Ge.Point3d(101, 101, 0)
        pnts[3] = Ge.Point3d(1, 101, 1)

        face.setCoordinate(0, pnts[0])
        face.setCoordinate(1, pnts[1])
        face.setCoordinate(2, pnts[2])
        face.setCoordinate(3, pnts[3])

        assert face.coordinate(0) == pnts[0]
        assert face.coordinate(1) == pnts[1]
        assert face.coordinate(2) == pnts[2]
        assert face.coordinate(3) == pnts[3]
        assert face.coordinates() == pnts

