from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


# a 2D solid (AcDbSolid) is created from four corner points
class TestAxSolid:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    @staticmethod
    def _corner_pnts() -> list[Ge.Point3d]:
        return [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]

    def test_create(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addSolid(*self._corner_pnts())
        assert ent.objectName() == "AcDbSolid"
        assert ent.entityType() == Ax.AcEntityName.acSolid

    def test_cast(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addSolid(*self._corner_pnts())
        solid = Ax.AcadSolid.cast(ent)
        assert solid is not None
        assert isinstance(solid, Ax.AcadSolid)

    def test_className(self):
        assert Ax.AcadSolid.className() == "AcadSolid"

    def test_coordinates(self):
        pnts = self._corner_pnts()
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addSolid(*pnts)
        coords = ent.coordinates()
        # all four input corners must be present in the returned coordinates
        assert len(coords) >= 4
        assert set(pnts) <= set(coords)

    def test_setCoordinates(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addSolid(*self._corner_pnts())
        new_pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(50, 0, 0),
            Ge.Point3d(50, 50, 0),
            Ge.Point3d(0, 50, 0),
        ]
        ent.setCoordinates(new_pnts)
        assert set(new_pnts) <= set(ent.coordinates())

    def test_normal(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addSolid(*self._corner_pnts())
        # a solid lying in the XY plane has its normal parallel to the Z axis
        assert ent.normal().isParallelTo(Ge.Vector3d.kZAxis)

    def test_setNormal(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addSolid(*self._corner_pnts())
        ent.setNormal(Ge.Vector3d.kZAxis)
        assert ent.normal().isParallelTo(Ge.Vector3d.kZAxis)

    def test_thickness(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addSolid(*self._corner_pnts())
        # a freshly created flat 2D solid has zero thickness
        assert ent.thickness() == 0

    def test_setThickness(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addSolid(*self._corner_pnts())
        ent.setThickness(10)
        assert ent.thickness() == 10
