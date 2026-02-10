from __future__ import annotations

import math

from pyrx import Ge


class TestLineSeg3d:
    """Unit tests for the LineSeg3d class."""

    def test_initialization(self):
        """Test creating a LineSeg3d with start and end points."""
        start = Ge.Point3d(0.0, 0.0, 0.0)
        end = Ge.Point3d(10.0, 0.0, 0.0)
        
        # Assuming standard constructor signature
        line = Ge.LineSeg3d(start, end)
        
        assert line.startPoint() == start
        assert line.endPoint() == end

    def test_is_on_point_on_line(self):
        """Test isOn method returning True for a point on the line segment."""
        start = Ge.Point3d(0.0, 0.0, 0.0)
        end = Ge.Point3d(10.0, 0.0, 0.0)
        line = Ge.LineSeg3d(start, end)
        
        # Point exactly at the start
        pt1 = Ge.Point3d(0.0, 0.0, 0.0)
        flag , pt = line.isOn(pt1)
        assert flag == True

        # Point exactly at the end
        pt2 = Ge.Point3d(10.0, 0.0, 0.0)
        flag , pt = line.isOn(pt2)
        assert flag == True

        # Point in the middle
        pt3 = Ge.Point3d(5.0, 0.0, 0.0)
        flag , pt = line.isOn(pt3)
        assert flag == True


    def test_is_on_point_off_line(self):
        """Test isOn method returning False for a point off the line segment."""
        start = Ge.Point3d(0.0, 0.0, 0.0)
        end = Ge.Point3d(10.0, 0.0, 0.0)
        line = Ge.LineSeg3d(start, end)
        
        # Point far away
        pt = Ge.Point3d(0.0, 10.0, 0.0)
        flag , pt = line.isOn(pt)
        assert flag == False

    def test_transform_by_matrix(self):
        """Test transformBy method using a Matrix3d."""
        start = Ge.Point3d(0.0, 0.0, 0.0)
        end = Ge.Point3d(1.0, 0.0, 0.0)
        line = Ge.LineSeg3d(start, end)
        
        # Create a translation matrix
        vec = Ge.Vector3d(1.0, 1.0, 1.0)
        mat = Ge.Matrix3d.translation(vec)
        
        line.transformBy(mat)
        
        # Verify start point moved
        expected_start = Ge.Point3d(1.0, 1.0, 1.0)
        assert line.startPoint() == expected_start
        
        # Verify end point moved
        expected_end = Ge.Point3d(2.0, 1.0, 1.0)
        assert line.endPoint() == expected_end

    def test_rotate_by(self):
        """Test rotateBy method."""
        start = Ge.Point3d(0.0, 0.0, 0.0)
        end = Ge.Point3d(1.0, 0.0, 0.0)
        line = Ge.LineSeg3d(start, end)
        
        # Rotate 90 degrees around Z axis
        angle = 90.0
        vec = Ge.Vector3d.kZAxis
        pt = Ge.Point3d(0.0, 1.0, 0.0) # Origin
        
        line.rotateBy(math.radians(angle), vec, pt)
        
        # End point should now be at (1.0, 2.0, 0.0)
        expected_end = Ge.Point3d(1.0, 2.0, 0.0)
        assert line.endPoint() == expected_end

    def test_scale_by(self):
        """Test scaleBy method."""
        start = Ge.Point3d(0.0, 0.0, 0.0)
        end = Ge.Point3d(1.0, 0.0, 0.0)
        line = Ge.LineSeg3d(start, end)
        
        # Scale by 2 about the origin
        line.scaleBy(2.0,Ge.Point3d.kOrigin)
        
        # End point should now be at (2.0, 0.0, 0.0)
        expected_end = Ge.Point3d(2.0, 0.0, 0.0)
        assert line.endPoint() == expected_end

    def test_translate_by(self):
        """Test translateBy method."""
        start = Ge.Point3d(0.0, 0.0, 0.0)
        end = Ge.Point3d(1.0, 0.0, 0.0)
        line = Ge.LineSeg3d(start, end)
        
        # Translate by (1, 1, 1)
        line.translateBy(Ge.Vector3d(1.0, 1.0, 1.0))
        
        # End point should now be at (2.0, 1.0, 1.0)
        expected_end = Ge.Point3d(2.0, 1.0, 1.0)
        assert line.endPoint() == expected_end

    def test_mirror(self):
        """Test mirror method."""
        start = Ge.Point3d(0.0, 0.0, 0.0)
        end = Ge.Point3d(2.0, 2.0, 0.0)
        line = Ge.LineSeg3d(start, end)
        
        # Mirror across XY plane (z=0)
        
        plane = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kXAxis)
        
        line.mirror(plane)
        
        # End point should now be at (1.0, -1.0, 0.0)
        assert line.endPoint() == Ge.Point3d(-2.0,2.0,0.0)
