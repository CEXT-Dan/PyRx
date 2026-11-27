from __future__ import annotations

import math

import pytest

from pyrx import Ap, Ax, Ge


# An infinite construction line (AcDbXline) is defined by a base point and a
# direction vector; unlike a ray it extends in both directions.
class TestAxXline:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _make_xline(self, base: Ge.Point3d | None = None,
                    second: Ge.Point3d | None = None) -> Ax.AcadXline:
        base = base or Ge.Point3d(5, 3, 0)
        second = second or Ge.Point3d(5, 5, 0)
        return self.axDoc.modelSpace().addXline(base, second)

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadXline.className() == "AcadXline"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadXline()

    def test_cast(self):
        ent = self._make_xline()
        xline = Ax.AcadXline.cast(ent)
        assert xline is not None
        assert isinstance(xline, Ax.AcadXline)

    # --- creation / identity ---

    def test_create(self):
        ent = self._make_xline()
        assert ent.objectName() == "AcDbXline"
        assert ent.entityType() == Ax.AcEntityName.acXline

    def test_objectId(self):
        ent = self._make_xline()
        assert ent.objectId().isNull() is False

    def test_isNull(self):
        ent = self._make_xline()
        assert ent.isNull() is False

    # --- geometry ---

    def test_basePoint(self):
        base = Ge.Point3d(5, 3, 0)
        ent = self._make_xline(base=base)
        assert ent.basePoint() == base

    def test_secondPoint(self):
        ent = self._make_xline()
        # the second point lies on the line, in the same direction as the direction vector
        assert (ent.secondPoint() - ent.basePoint()).isParallelTo(ent.directionVector())

    def test_directionVector(self):
        ent = self._make_xline(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        # direction from base to second point is +Y
        assert ent.directionVector().isParallelTo(Ge.Vector3d.kYAxis)
        # the xline stores its direction as a unit vector
        assert math.isclose(ent.directionVector().length(), 1.0, abs_tol=1e-6)

    def test_setBasePoint(self):
        ent = self._make_xline()
        new_base = Ge.Point3d(10, 20, 0)
        ent.setBasePoint(new_base)
        assert ent.basePoint() == new_base

    def test_setSecondPoint(self):
        ent = self._make_xline(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        # redirect the line along +X by setting the second point
        ent.setSecondPoint(Ge.Point3d(9, 3, 0))
        assert ent.directionVector().isParallelTo(Ge.Vector3d.kXAxis)

    @pytest.mark.known_failure_ARX
    def test_setDirectionVector(self):
        ent = self._make_xline(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        # Expected: setDirectionVector(v) sets the line direction to normalize(v),
        # i.e. setDirectionVector(kXAxis) should make the direction +X.
        ent.setDirectionVector(Ge.Vector3d.kXAxis)
        assert ent.directionVector().isParallelTo(Ge.Vector3d.kXAxis)
        # OBSERVED BUG: setDirectionVector treats its input as a POINT relative to
        # the base point, not as a direction vector. With base (5,3,0) and input
        # (1,0,0) it returned direction (-0.8,-0.6,0) == normalize((1,0,0)-(5,3,0)).
        # Same C++/COM-layer issue as AcadRay (see test_AxRay.py), not fixable from
        # the test side.

    # --- offset ---

    def test_offset(self):
        ent = self._make_xline()
        offset_lines = ent.offset(10.0)
        # the method returns a list of entities
        assert isinstance(offset_lines, list)
        assert len(offset_lines) > 0
        # an offset of an infinite line is a parallel infinite line
        off = Ax.AcadXline.cast(offset_lines[0])
        assert off is not None
        assert off.directionVector().isParallelTo(ent.directionVector())
