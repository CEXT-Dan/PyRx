from __future__ import annotations
import math
from pyrx import Db, Ge


class TestDbArc:

    def test_create_three_points(self):
        """Test constructor with three points"""
        arc = Db.Arc(Ge.Point3d(10, 0, 0), Ge.Point3d(0, 10, 0), Ge.Point3d(-10, 0, 0))
        assert arc.center() == Ge.Point3d.kOrigin
        assert arc.radius() == 10
        assert arc.startAngle() == 0
        assert arc.endAngle() == math.radians(180)

    def test_create_center_radius_angles(self):
        """Test constructor with center, radius, startAngle, endAngle"""
        center = Ge.Point3d(50, 50, 0)
        radius = 25.0
        start_angle = 0.0
        end_angle = 1.5708  # 90 degrees
        arc = Db.Arc(center, radius, start_angle, end_angle)
        assert arc.center() == center
        assert arc.radius() == radius
        assert arc.startAngle() == start_angle
        assert arc.endAngle() == end_angle

    def test_create_center_normal_radius_angles(self):
        """Test constructor with center, normal, radius, startAngle, endAngle"""
        center = Ge.Point3d(0, 0, 0)
        normal = Ge.Vector3d(0, 0, 1)
        radius = 10.0
        start_angle = 0.0
        end_angle = 3.14159  # 180 degrees
        arc = Db.Arc(center, normal, radius, start_angle, end_angle)
        assert arc.center() == center
        assert arc.normal() == normal
        assert arc.radius() == radius
        assert arc.startAngle() == start_angle
        assert arc.endAngle() == end_angle

    def test_center_property(self):
        # Test getting center (we'll use a simple case for this)
        arc2 = Db.Arc(Ge.Point3d(50, 50, 0), 25.0, 0.0, 1.5708)
        assert arc2.center() == Ge.Point3d(50, 50, 0)

    def test_radius_property(self):
        """Test radius property getter and setter"""
        radius = 15.0
        arc = Db.Arc(Ge.Point3d(0, 0, 0), radius, 0.0, 1.5708)
        assert arc.radius() == radius

    def test_normal_property(self):
        """Test normal property getter"""
        normal = Ge.Vector3d(0, 0, 1)
        arc = Db.Arc(Ge.Point3d(0, 0, 0), normal, 10.0, 0.0, 3.14159)
        assert arc.normal() == normal

    def test_angles_properties(self):
        """Test startAngle and endAngle properties"""
        start_angle = 0.0
        end_angle = 1.5708  # 90 degrees
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 10.0, start_angle, end_angle)
        assert arc.startAngle() == start_angle
        assert arc.endAngle() == end_angle

    def test_length_property(self):
        """Test length property"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 10.0, 0.0, 1.5708)  # Quarter circle
        length = arc.length()
        # Length of quarter circle with radius 10 should be (π * r) / 2 ≈ 15.708
        expected_length = (3.14159 * 10.0) / 2
        assert abs(length - expected_length) < 0.001

    def test_thickness_property(self):
        """Test thickness property"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 10.0, 0.0, 1.5708)
        thickness = arc.thickness()
        assert thickness == 0.0

    def test_total_angle_property(self):
        """Test totalAngle property"""
        start_angle = 0.0
        end_angle = 1.5708  # 90 degrees
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 10.0, start_angle, end_angle)
        total_angle = arc.totalAngle()
        assert abs(total_angle - (end_angle - start_angle)) < 0.001

    def test_set_center(self):
        """Test setCenter method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 10.0, 0.0, 1.5708)
        new_center = Ge.Point3d(25, 25, 0)
        arc.setCenter(new_center)
        assert arc.center() == new_center

    def test_set_radius(self):
        """Test setRadius method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 10.0, 0.0, 1.5708)
        arc.setRadius(20.0)
        assert arc.radius() == 20.0

    def test_set_start_angle(self):
        """Test setStartAngle method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 10.0, 0.0, 1.5708)
        arc.setStartAngle(1.5708)
        assert arc.startAngle() == 1.5708

    def test_set_end_angle(self):
        """Test setEndAngle method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 10.0, 0.0, 1.5708)
        arc.setEndAngle(3.14159)  # 180 degrees
        assert arc.endAngle() == 3.14159

    def test_set_normal(self):
        """Test setNormal method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 10.0, 0.0, 1.5708)
        normal = Ge.Vector3d.kYAxis
        arc.setNormal(normal)
        assert arc.normal() == normal

    def test_arc_creation_variants(self):
        """Test various Arc creation patterns"""
        # Test 1: Three points construction
        p1 = Ge.Point3d(0, 0, 0)
        p2 = Ge.Point3d(50, -50, 0)
        p3 = Ge.Point3d(100, 0, 0)

        arc1 = Db.Arc(p1, p2, p3)
        assert isinstance(arc1, Db.Arc)

        # Test 2: Center/radius/angles construction
        center = Ge.Point3d(50, 50, 0)
        arc2 = Db.Arc(center, 25.0, 0.0, 1.5708)  # Quarter circle
        assert isinstance(arc2, Db.Arc)

        # Test 3: Center/normal/radius/angles construction
        normal = Ge.Vector3d(0, 0, 1)
        arc3 = Db.Arc(center, normal, 25.0, 0.0, 1.5708)
        assert isinstance(arc3, Db.Arc)

    def test_arc_properties_basic(self):
        """Test basic property access"""
        center = Ge.Point3d(10, 20, 30)
        radius = 15.0
        start_angle = 0.0
        end_angle = 3.14159  # Pi radians
        arc = Db.Arc(center, radius, start_angle, end_angle)

        # Test that we can access basic properties without error
        center_result = arc.center()
        radius_result = arc.radius()
        start_angle_result = arc.startAngle()
        end_angle_result = arc.endAngle()
        assert isinstance(center_result, Ge.Point3d)
        assert isinstance(radius_result, float)
        assert isinstance(start_angle_result, float)
        assert isinstance(end_angle_result, float)

    def test_arc_geometry_properties(self):
        """Test geometric property calculations"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 10.0, 0.0, 3.14159)  # Half circle
        length = arc.length()
        total_angle = arc.totalAngle()
        # Length of semicircle with radius 10 should be π * r ≈ 31.416
        expected_length = 3.14159 * 10.0
        assert abs(length - expected_length) < 0.01
        # Total angle for half circle should be π radians (180 degrees)
        assert abs(total_angle - 3.14159) < 0.01
