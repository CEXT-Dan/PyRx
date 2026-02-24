from __future__ import annotations
import math
import pytest
from pyrx import Ap, Ax, Ge


class TestAxLine:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def teardown_class(self):
        # Optional: Close document or application if needed
        pass

    def test_create(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        assert ent.objectName() == "AcDbLine"

    def test_cast(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        line_ent = Ax.AcadLine.cast(ent)
        assert line_ent is not None
        assert line_ent.length() == 100

    def test_className(self):
        assert Ax.AcadLine.className() == "AcadLine"

    def test_angle(self):
        # Line from (0,0) to (100, 0) has an angle of 0 radians
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))

        # Verify angle is 0
        assert ent.angle() == 0.0

        # Verify angle is 0 for a horizontal line
        assert math.isclose(ent.angle(), 0.0, abs_tol=1e-6)

    def test_delta(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))

        # Delta should be the vector from start to end
        delta = ent.delta()
        assert delta.isParallelTo(Ge.Vector3d.kXAxis)
        assert delta.length() == 100

    def test_normal(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))

        # Default normal for a line in XY plane is usually (0, 0, 1)
        assert ent.normal() == Ge.Vector3d.kZAxis

    def test_thickness(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))

        # Default thickness is usually 0
        assert ent.thickness() == 0.0

        # Set thickness
        ent.setThickness(5.0)
        assert ent.thickness() == 5.0

    def test_offset(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))

        # Offset creates parallel lines
        # Note: In a real test environment, you might want to check if entities
        # were actually added to the database or just check the return type
        offset_lines = ent.offset(10.0)

        # The method returns a list of entities
        assert isinstance(offset_lines, list)
        # Depending on implementation, it might return 1 or 2 lines (one on each side)
        assert len(offset_lines) > 0

    def test_set_start_point(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        new_start = Ge.Point3d(50, 0, 0)
        ent.setStartPoint(new_start)

        # Verify start point changed
        assert ent.startPoint() == new_start

    def test_set_end_point(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))

        new_end = Ge.Point3d(150, 0, 0)
        ent.setEndPoint(new_end)

        # Verify end point changed
        assert ent.endPoint() == new_end
