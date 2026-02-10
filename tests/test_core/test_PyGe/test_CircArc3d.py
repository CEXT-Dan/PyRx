from __future__ import annotations

from pyrx import Ge


class TestCircArc3d:
    """Unit tests for the CircArc3d class."""

    def test_initialization_1(self):
        start = Ge.Point3d(0.0, 0.0, 0.0)
        mid = Ge.Point3d(5.0, 5.0, 0.0)
        end = Ge.Point3d(10.0, 0.0, 0.0)
        
        arc = Ge.CircArc3d(start, mid, end)
        
        # Get the angles
        s_ang = arc.startAng()
        e_ang = arc.endAng()
        
        # Correct for arcs that cross the 0-radian line
        if e_ang < s_ang:
            e_ang += (2 * 3.141592653589793)
            
        mid_ang = (s_ang + e_ang) / 2.0
        computed_mid = arc.evalPoint(mid_ang)
        
        # Assertions
        assert arc.getStartPoint() == start
        assert arc.endPoint() == end
        # Use isEqualTo for float comparisons in Ge points
        assert computed_mid.isEqualTo(mid) 


    def test_initialization_2_center_radius(self):
        """Test creating a CircArc3d using center and radius."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        radius = 5.0
        
        arc = Ge.CircArc3d(center, Ge.Vector3d.kZAxis, radius)
        
        assert arc.center() == center
        assert arc.radius() == radius

    def test_initialization_3_center_normal_radius(self):
        """Test creating a CircArc3d using center, normal, and radius."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        normal = Ge.Vector3d(0.0, 0.0, 1.0)
        radius = 5.0
        
        arc = Ge.CircArc3d(center, normal, radius)
        
        assert arc.center() == center
        assert arc.normal() == normal
        assert arc.radius() == radius
        
        # Verify the plane is correctly defined
        plane = arc.getPlane()
        assert plane.normal() == normal

    def test_initialization_4_full_circle(self):
        """Test creating a full circle using start, mid, and end points."""
        start = Ge.Point3d(1.0, 0.0, 0.0)
        mid = Ge.Point3d(0.0, 1.0, 0.0)
        end = Ge.Point3d(-1.0, 0.0, 0.0)
        
        arc = Ge.CircArc3d(start, mid, end)

        # Verify it is a full circle (start and end points are opposite)
        assert arc.startPoint() == start
        assert arc.endPoint() == end

    def test_is_inside(self):
        """Test the isInside method."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        normal = Ge.Vector3d(0.0, 0.0, 1.0)
        radius = 5.0
        
        arc = Ge.CircArc3d(center, normal, radius)
        
        # Point inside the circle
        point_inside = Ge.Point3d(0.0, 0.0, 0.0)
        assert arc.isInside(point_inside) == True
        
        # Point outside the circle
        point_outside = Ge.Point3d(0.0, 0.0, 10.0)
        assert arc.isInside(point_outside) == False

    def test_get_plane(self):
        """Test retrieving the plane of the arc."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        normal = Ge.Vector3d(0.0, 0.0, 1.0)
        radius = 5.0
        
        arc = Ge.CircArc3d(center, normal, radius)
        
        plane = arc.getPlane()
        
        assert plane.normal() == normal
