from __future__ import annotations

import math
import pytest
from pyrx import Ap, Ge, Ax


class TestAxArc:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def teardown_method(self):
        # Clean up created entities
        pass

    def test_setCenter(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        assert ent.objectName() == "AcDbArc"
        ent.setCenter(Ge.Point3d(1, 1, 1))
        assert ent.center() == Ge.Point3d(1, 1, 1)

    def test_setRadius(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        assert ent.objectName() == "AcDbArc"
        ent.setRadius(6)
        assert ent.radius() == 6

    def test_setStartAngle(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        ent.setStartAngle(0)
        assert ent.startAngle() == 0

    def test_setEndAngle(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        ent.setEndAngle(math.pi * 3 / 4)
        assert ent.endAngle() == math.pi * 3 / 4

    def test_setNormal(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        new_normal = Ge.Vector3d.kYAxis
        ent.setNormal(new_normal)
        
        assert ent.normal() == new_normal

    def test_setThickness(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        ent.setThickness(2.5)
        assert ent.thickness() == 2.5

    def test_arcLength(self):
        axSpace = self.axDoc.modelSpace()
        # Radius 5, Total Angle 90 degrees (PI/2)
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        # Length = r * theta
        expected_length = 5 * (math.pi / 2)
        assert abs(ent.arcLength() - expected_length) < 0.001

    def test_area(self):
        axSpace = self.axDoc.modelSpace()
        # Area = (r^2 * theta) / 2
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        assert ent.area() == pytest.approx(7.134954084936207)

    def test_totalAngle(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        assert ent.totalAngle() == math.pi / 2

    def test_endPoint(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        # Start at 0, radius 5 -> End point is (5, 0, 0)
        expected = Ge.Point3d(0, 5, 0)
        assert ent.endPoint() == expected

    def test_startPoint(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        # Start at 0, radius 5 -> Start point is (5, 0, 0)
        expected = Ge.Point3d(5, 0, 0)
        assert ent.startPoint() == expected

    def test_offset(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        offset_dist = 1.0
        new_entities = ent.offset(offset_dist)
        assert len(new_entities) > 0
        assert isinstance(new_entities[0], Ax.AcadEntity)

    def test_cast(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        
        arc_ent = Ax.AcadArc.cast(ent)
        
        assert arc_ent is not None
        assert arc_ent.radius() == 5

    def test_className(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 0, math.pi / 2)
        
        assert Ax.AcadArc.className() == "AcadArc"
