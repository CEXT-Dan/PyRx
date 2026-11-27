from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxPolyfaceMesh:

    PNTS = [
        Ge.Point3d(4, 7, 0),
        Ge.Point3d(5, 7, 0),
        Ge.Point3d(6, 7, 0),
        Ge.Point3d(4, 6, 0),
        Ge.Point3d(5, 6, 0),
        Ge.Point3d(6, 6, 1),
    ]
    FACES = [1, 2, 5, 4, 2, 3, 6, 5]

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _make_pmesh(self):
        axSpace = self.axDoc.modelSpace()
        return axSpace.addPolyfaceMesh(self.PNTS, self.FACES)

    def test_create(self):
        ent = self._make_pmesh()
        assert ent.objectName() == "AcDbPolyFaceMesh"
        assert ent.entityType() == Ax.AcEntityName.acPolyfaceMesh

    def test_cast(self):
        ent = self._make_pmesh()
        casted = Ax.AcadPolyfaceMesh.cast(ent)
        assert casted is not None
        assert casted.objectName() == "AcDbPolyFaceMesh"

    def test_className(self):
        assert Ax.AcadPolyfaceMesh.className() == "AcadPolyfaceMesh"

    def test_coordinates(self):
        ent = self._make_pmesh()
        assert ent.coordinates() == self.PNTS

    def test_setCoordinates(self):
        ent = self._make_pmesh()
        new_pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(1, 0, 0),
            Ge.Point3d(1, 1, 0),
            Ge.Point3d(0, 1, 0),
            Ge.Point3d(0, 0, 1),
            Ge.Point3d(1, 1, 1),
        ]
        ent.setCoordinates(new_pnts)
        assert ent.coordinates() == new_pnts

    def test_coordinate(self):
        ent = self._make_pmesh()
        assert ent.coordinate(0) == self.PNTS[0]

    def test_setCoordinate(self):
        ent = self._make_pmesh()
        new_pnt = Ge.Point3d(2, 1, 1)
        ent.setCoordinate(0, new_pnt)
        assert ent.coordinate(0) == new_pnt

    def test_numberOfVertices(self):
        ent = self._make_pmesh()
        assert ent.numberOfVertices() == len(self.PNTS)

    def test_numberOfFaces(self):
        ent = self._make_pmesh()
        assert ent.numberOfFaces() == len(self.FACES) // 4

    @pytest.mark.known_failure_ARX
    def test_setFaces(self):
        ent = self._make_pmesh()
        ent.setFaces(self.FACES)
        assert ent.numberOfFaces() == 2
