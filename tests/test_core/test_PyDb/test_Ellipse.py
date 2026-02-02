from __future__ import annotations

import math

from pyrx import Db, Ge


class TestDbEllipse:

    # --- Initialization Tests ---

    def test_create_1(self):
        """Test creating an ellipse with center, normal, major axis, and ratio."""
        cen = Ge.Point3d(10, 10, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.5

        ellipse = Db.Ellipse(cen, unit_normal, major_axis, radius_ratio)

        assert ellipse.center() == cen
        assert ellipse.normal() == unit_normal
        assert ellipse.majorAxis() == major_axis
        assert ellipse.radiusRatio() == radius_ratio

    def test_create_2(self):
        """Test creating an ellipse with start and end angles."""
        cen = Ge.Point3d(0, 0, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.5
        start_angle = 0.0
        end_angle = 3.14159  # 180 degrees

        ellipse = Db.Ellipse(
            cen, unit_normal, major_axis, radius_ratio, start_angle, end_angle
        )

        assert ellipse.center() == cen
        assert abs(ellipse.startAngle() - start_angle) < 1e-6
        assert abs(ellipse.endAngle() - end_angle) < 1e-6

    # --- Geometry Property Tests ---

    def test_major_minor_axes(self):
        """Test that minor axis is perpendicular to major axis and normal."""
        cen = Ge.Point3d(0, 0, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.5

        ellipse = Db.Ellipse(cen, unit_normal, major_axis, radius_ratio)

        # Verify axes are perpendicular
        dot_prod = ellipse.majorAxis().dotProduct(ellipse.minorAxis())
        assert abs(dot_prod) < 1e-6

        # Verify normal is perpendicular to both
        dot_prod_normal_major = ellipse.normal().dotProduct(ellipse.majorAxis())
        assert abs(dot_prod_normal_major) < 1e-6

        dot_prod_normal_minor = ellipse.normal().dotProduct(ellipse.minorAxis())
        assert abs(dot_prod_normal_minor) < 1e-6

    def test_radii_calculation(self):
        """Test that radii are calculated correctly based on ratio."""
        cen = Ge.Point3d(0, 0, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.5

        ellipse = Db.Ellipse(cen, unit_normal, major_axis, radius_ratio)

        # Major radius is magnitude of majorAxis vector
        expected_major = ellipse.majorAxis().length()

        # Minor radius = Major radius * ratio
        expected_minor = expected_major * radius_ratio

        assert abs(ellipse.majorRadius() - expected_major) < 1e-6
        assert abs(ellipse.minorRadius() - expected_minor) < 1e-6

    # --- Angle Tests ---

    def test_angle_at_param(self):
        """Test conversion between parametric value and angle."""
        cen = Ge.Point3d(0, 0, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.5

        ellipse = Db.Ellipse(cen, unit_normal, major_axis, radius_ratio)

        angle_0 = ellipse.angleAtParam(ellipse.getStartParam())
        assert abs(angle_0) < 1e-6

        angle_pi = ellipse.angleAtParam(ellipse.getEndParam())
        assert abs(angle_pi - math.tau < 1e-6)

    def test_param_at_angle(self):
        """Test conversion between angle and parametric value."""
        cen = Ge.Point3d(0, 0, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.5

        ellipse = Db.Ellipse(cen, unit_normal, major_axis, radius_ratio)

        angle_0 = 0.0
        param_0 = ellipse.paramAtAngle(angle_0)
        assert abs(param_0) < 1e-6

        # Angle pi should correspond to param pi
        angle_pi = math.tau
        param_pi = ellipse.paramAtAngle(angle_pi)
        assert abs(param_pi - math.tau) < 1e-6

    # --- Modification Tests ---

    def test_set_center(self):
        """Test setting the center point."""
        cen = Ge.Point3d(10, 10, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.5

        ellipse = Db.Ellipse(cen, unit_normal, major_axis, radius_ratio)

        new_cen = Ge.Point3d(20, 20, 0)
        ellipse.setCenter(new_cen)

        assert ellipse.center() == new_cen

    def test_set_radii(self):
        """Test setting major and minor radii."""
        cen = Ge.Point3d(0, 0, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.5

        ellipse = Db.Ellipse(cen, unit_normal, major_axis, radius_ratio)

        new_major = 15.0
        new_minor = 7.5  # Matches ratio 0.5

        ellipse.setMajorRadius(new_major)
        ellipse.setMinorRadius(new_minor)

        assert abs(ellipse.majorRadius() - new_major) < 1e-6
        assert abs(ellipse.minorRadius() - new_minor) < 1e-6

    def test_set_radius_ratio(self):
        """Test setting the radius ratio."""
        cen = Ge.Point3d(0, 0, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.5

        ellipse = Db.Ellipse(cen, unit_normal, major_axis, radius_ratio)

        new_ratio = 0.75
        ellipse.setRadiusRatio(new_ratio)

        assert abs(ellipse.radiusRatio() - new_ratio) < 1e-6

    def test_set_angles(self):
        """Test setting start and end angles."""
        cen = Ge.Point3d(0, 0, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.5

        ellipse = Db.Ellipse(cen, unit_normal, major_axis, radius_ratio)

        start = 1.0
        end = 4.0

        ellipse.setStartAngle(start)
        ellipse.setEndAngle(end)

        assert abs(ellipse.startAngle() - start) < 1e-6
        assert abs(ellipse.endAngle() - end) < 1e-6

    def test_set_full_properties(self):
        """Test the set() method with all parameters."""
        cen = Ge.Point3d(0, 0, 0)
        unit_normal = Ge.Vector3d.kZAxis
        major_axis = Ge.Vector3d.kXAxis
        radius_ratio = 0.8
        start_angle = 0.0
        end_angle = 2.0

        ellipse = Db.Ellipse(cen, unit_normal, major_axis, radius_ratio)

        ellipse.set(cen, unit_normal, major_axis, radius_ratio, start_angle, end_angle)

        assert ellipse.center() == cen
        assert ellipse.radiusRatio() == radius_ratio
        assert abs(ellipse.startAngle() - start_angle) < 1e-6
        assert abs(ellipse.endAngle() - end_angle) < 1e-6
