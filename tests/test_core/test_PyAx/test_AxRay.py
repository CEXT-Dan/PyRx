from __future__ import annotations

import math

import pytest

from pyrx import Ap, Ax, Ge


class TestAxRay:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_create(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addRay(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        assert ent.objectName() == "AcDbRay"
        assert ent.entityType() == Ax.AcEntityName.acRay

    def test_cast(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addRay(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        ray = Ax.AcadRay.cast(ent)
        assert ray is not None
        assert isinstance(ray, Ax.AcadRay)

    def test_className(self):
        assert Ax.AcadRay.className() == "AcadRay"

    def test_basePoint(self):
        axSpace = self.axDoc.modelSpace()
        base = Ge.Point3d(5, 3, 0)
        ent = axSpace.addRay(base, Ge.Point3d(5, 5, 0))
        assert ent.basePoint() == base

    def test_secondPoint(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addRay(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        # the second point lies on the ray, in the same direction as the direction vector
        assert (ent.secondPoint() - ent.basePoint()).isParallelTo(ent.directionVector())

    def test_directionVector(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addRay(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        # direction from base to second point is +Y
        assert ent.directionVector().isParallelTo(Ge.Vector3d.kYAxis)
        # the ray stores its direction as a unit vector
        assert math.isclose(ent.directionVector().length(), 1.0, abs_tol=1e-6)

    def test_setBasePoint(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addRay(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        new_base = Ge.Point3d(10, 20, 0)
        ent.setBasePoint(new_base)
        assert ent.basePoint() == new_base

    def test_setSecondPoint(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addRay(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        # redirect the ray along +X by setting the second point
        ent.setSecondPoint(Ge.Point3d(9, 3, 0))
        assert ent.directionVector().isParallelTo(Ge.Vector3d.kXAxis)

    @pytest.mark.known_failure_ARX
    def test_setDirectionVector(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addRay(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        # Expected: setDirectionVector(v) sets the ray direction to normalize(v),
        # i.e. setDirectionVector(kXAxis) should make the direction +X.
        ent.setDirectionVector(Ge.Vector3d.kXAxis)
        assert ent.directionVector().isParallelTo(Ge.Vector3d.kXAxis)
        # OBSERVED BUG: setDirectionVector treats its input as a POINT relative to
        # the base point, not as a direction vector. With base (5,3,0) and input
        # (1,0,0) it returned direction (-0.8,-0.6,0) == normalize((1,0,0)-(5,3,0)).
        # This is a C++/COM-layer issue (PyAcadRay::setDirectionVector ->
        # IAcadRay::SetDirectionVector), not fixable from the test side.
