from __future__ import annotations

from pyrx import Db, Ge


class TestDbAlignedDimension:
    
    def test_aligned_dimension_creation(self):
        """Tests creation of an AlignedDimension."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(15, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        assert dim.xLine1Point() == pt1
        assert dim.xLine2Point() == pt2
        assert dim.dimLinePoint() == pt3
        assert dim.measurement() == 15.0

    def test_aligned_dimension_with_text(self):
        """Tests creation of AlignedDimension with custom text."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 3, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3, "10.0")
        
        assert dim.xLine1Point() == pt1
        assert dim.xLine2Point() == pt2
        assert dim.dimLinePoint() == pt3

    def test_set_xline_points(self):
        """Tests setting extension line points."""
        dim = Db.AlignedDimension()
        pt1 = Ge.Point3d(1, 1, 0)
        pt2 = Ge.Point3d(11, 1, 0)
        
        dim.setXLine1Point(pt1)
        dim.setXLine2Point(pt2)
        
        assert dim.xLine1Point() == pt1
        assert dim.xLine2Point() == pt2

    def test_set_dim_line_point(self):
        """Tests setting dimension line point."""
        dim = Db.AlignedDimension()
        pt = Ge.Point3d(6, 4, 0)
        
        dim.setDimLinePoint(pt)
        
        assert dim.dimLinePoint() == pt

    def test_oblique_angle(self):
        """Tests setting and getting oblique angle."""
        dim = Db.AlignedDimension()
        angle = 0.785398  # ~45 degrees in radians
        
        dim.setOblique(angle)
        
        assert dim.oblique() == angle

    def test_jog_symbol(self):
        """Tests jog symbol on/off functionality."""
        dim = Db.AlignedDimension()
        
        dim.setJogSymbolOn(True)
        assert dim.jogSymbolOn() is True
        
        dim.setJogSymbolOn(False)
        assert dim.jogSymbolOn() is False

    def test_jog_symbol_position(self):
        """Tests setting jog symbol position."""
        dim = Db.AlignedDimension()
        jog_pt = Ge.Point3d(7.5, 2.5, 0)
        
        dim.setJogSymbolPosition(jog_pt)
        
        assert dim.jogSymbolPosition() == jog_pt

    def test_measurement_vertical_dimension(self):
        """Tests measurement calculation for vertical dimension."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(0, 20, 0)
        pt3 = Ge.Point3d(5, 10, 0)
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        assert abs(dim.measurement() - 20.0) < 1e-9

    def test_aligned_dimension_creation_with_points(self):
        """Tests creation of an AlignedDimension using three points."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(15, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        assert dim.xLine1Point() == pt1
        assert dim.xLine2Point() == pt2
        assert dim.dimLinePoint() == pt3
        assert dim.measurement() == 15.0

    def test_aligned_dimension_creation_with_text(self):
        """Tests creation of an AlignedDimension with custom text."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        custom_text = "Custom Dim"
        
        dim = Db.AlignedDimension(pt1, pt2, pt3, custom_text)
        
        assert dim.xLine1Point() == pt1
        assert dim.xLine2Point() == pt2
        assert dim.dimLinePoint() == pt3
        # Note: Depending on the implementation, text might be stored or displayed differently
        # but the constructor accepts it.
        

    def test_set_x_line_points(self):
        """Tests setting the extension line start points."""
        dim = Db.AlignedDimension()
        
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(15, 0, 0)
        
        dim.setXLine1Point(pt1)
        dim.setXLine2Point(pt2)
        
        assert dim.xLine1Point() == pt1
        assert dim.xLine2Point() == pt2

    def test_set_dim_line_point_2(self):
        """Tests setting the dimension line definition point."""
        dim = Db.AlignedDimension()
        
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(15, 0, 0)
        new_dim_pt = Ge.Point3d(5, 10, 0)
        
        dim.setXLine1Point(pt1)
        dim.setXLine2Point(pt2)
        dim.setDimLinePoint(new_dim_pt)
        
        assert dim.dimLinePoint() == new_dim_pt

    def test_oblique_angle_2(self):
        """
        Tests the oblique angle functionality.
        The angle is relative to the line containing xLine1Point and xLine2Point.
        """
        dim = Db.AlignedDimension()
        
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        
        dim.setXLine1Point(pt1)
        dim.setXLine2Point(pt2)
        
        # Set an oblique angle (e.g., 45 degrees in radians)
        oblique_rad = 45 * (3.141592653589793 / 180.0)
        dim.setOblique(oblique_rad)
        
        # Verify the angle was set
        retrieved_angle = dim.oblique()
        # Allow for floating point comparison tolerance
        assert abs(retrieved_angle - oblique_rad) < 0.0001

    def test_jog_symbol_2(self):
        """Tests the jog symbol status and position."""
        dim = Db.AlignedDimension()
        
        # Test setting jog symbol to on
        dim.setJogSymbolOn(True)
        assert dim.jogSymbolOn() is True
        
        # Test setting jog symbol to off
        dim.setJogSymbolOn(False)
        assert dim.jogSymbolOn() is False
        
        # Test setting jog symbol position
        jog_pos = Ge.Point3d(5, 5, 0)
        dim.setJogSymbolPosition(jog_pos)
        
        # Verify position
        retrieved_pos = dim.jogSymbolPosition()
        assert retrieved_pos == jog_pos
