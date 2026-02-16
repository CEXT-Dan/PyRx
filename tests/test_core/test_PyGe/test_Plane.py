from __future__ import annotations

import pytest

from pyrx import Ge


class TestPlane:
    def test_plane_init_default(self):
        """Test default initialization of Plane."""
        plane = Ge.Plane()
        # Default plane should pass through origin (0,0,0)
        flag, pnt = plane.intersectWith(
            Ge.LineSeg3d(Ge.Point3d(0, 0, -100), Ge.Point3d(0, 0, 100))
        )
        assert flag == True
        assert pnt == Ge.Point3d(0, 0, 0)

    def test_plane_init_from_equation(self):
        """Test initialization using the implicit equation coefficients (a, b, c, d)."""
        # Plane equation: x + y + z + 1 = 0
        # Normal vector is (1, 1, 1)
        # Point (0, 0, -1) satisfies the equation
        a, b, c, d = 1.0, 1.0, 1.0, 1.0
        plane = Ge.Plane(a, b, c, d)

        # Verify the plane passes through (0, 0, -1)
        test_point = Ge.Point3d(0, 0, -1)
        flag, pnt = plane.intersectWith(
            Ge.LineSeg3d(test_point, test_point + Ge.Vector3d(1, 0, 0))
        )

        assert flag == True
        assert pnt == test_point

    def test_plane_init_origin_normal(self):
        """Test initialization using an origin point and a normal vector."""
        origin = Ge.Point3d(10.0, 20.0, 30.0)
        normal = Ge.Vector3d.kXAxis # Plane is parallel to YZ plane
        
        plane = Ge.Plane(origin, normal)

        # Define a line segment crossing the plane along the X-axis
        # The plane is at X=10, so the segment from X=9 to X=11 should intersect at X=10
        flag, pnt = plane.intersectWith(
            Ge.LineSeg3d(origin - Ge.Vector3d.kXAxis, origin + Ge.Vector3d.kXAxis)
        )
        
        assert flag == True
        assert pnt.isEqualTo(origin)
        

    def test_plane_init_three_points(self):
        """Test initialization using three points (pntU, origin, pntV)."""
        # Define a plane passing through these 3 points
        pnt_u = Ge.Point3d(100, 0, 0)
        origin = Ge.Point3d(0, 0, 0)
        pnt_v = Ge.Point3d(0, 100, 0)

        plane = Ge.Plane(pnt_u, origin, pnt_v)

        # Verify the plane passes through the origin point
        flag, pnt = plane.intersectWith(
            Ge.LineSeg3d(origin - Ge.Vector3d.kZAxis, origin + Ge.Vector3d.kZAxis)
        )

        assert flag == True
        assert pnt == origin

    def test_plane_set_from_equation(self):
        """Test setting Plane coefficients using set(a, b, c, d)."""
        # Plane equation: 2x + 3y - z - 4 = 0
        # Point (1, 1, 1) satisfies: 2(1) + 3(1) - 1 - 4 = 0
        a, b, c, d = 2.0, 3.0, -1.0, -4.0
        plane = Ge.Plane()

        plane.set(a, b, c, d)

        test_point = Ge.Point3d(1, 1, 1)
        flag, pnt = plane.intersectWith(
            Ge.LineSeg3d(test_point, test_point + Ge.Vector3d(1, 0, 0))
        )

        assert flag == True
        assert pnt == test_point

    def test_plane_set_origin_normal(self):
        """Test setting Plane using set(origin, normal)."""
        
        origin = Ge.Point3d(10.0, 20.0, 30.0)
        normal = Ge.Vector3d.kXAxis # Plane is parallel to YZ plane
        
        plane = Ge.Plane()
        plane.set(origin, normal)

        # Define a line segment crossing the plane along the X-axis
        # The plane is at X=10, so the segment from X=9 to X=11 should intersect at X=10
        flag, pnt = plane.intersectWith(
            Ge.LineSeg3d(origin - Ge.Vector3d.kXAxis, origin + Ge.Vector3d.kXAxis)
        )
        
        assert flag == True
        assert pnt.isEqualTo(origin)

    def test_plane_set_three_points(self):
        """Test setting Plane using set(pntU, origin, pntV)."""
        # Define a plane passing through these 3 points
        pnt_u = Ge.Point3d(100, 0, 0)
        origin = Ge.Point3d(0, 0, 0)
        pnt_v = Ge.Point3d(0, 100, 0)

        plane = Ge.Plane()
        plane.set(pnt_u, origin, pnt_v)

        # Verify the plane passes through the origin point
        flag, pnt = plane.intersectWith(
            Ge.LineSeg3d(origin - Ge.Vector3d.kZAxis, origin + Ge.Vector3d.kZAxis)
        )

        assert flag == True
        assert pnt == origin
       
