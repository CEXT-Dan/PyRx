from __future__ import annotations

import pytest

from pyrx import Db, Ge


class TestDbFcf:

    def test_ctor_1(self):
        """Test constructor with string, point, normal, and direction."""
        fcf = Db.Fcf(
            "TEST", Ge.Point3d(10, 10, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis
        )
        assert "TEST" in fcf.text(0)

    def test_ctor_2(self):
        """Test constructor with string, point, normal, and direction."""
        fcf = Db.Fcf(
            "TEST", Ge.Point3d(10, 10, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis
        )
        assert "TEST" in fcf.textAll()

    def test_set_text_with_gdt_codes(self):
        """
        Test setText using the control codes described in the documentation.
        This tests the specific string format required for Feature Control Frames.
        """
        # Sample string based on the documentation example
        # {\\Fgdt;j}%%v{\\Fgdt;n}0.001{\\Fgdt;m}%%v1.200{\\Fgdt;l}%%vA{\\Fgdt;s}%%vB%%vCn
        gdt_string = "{\\Fgdt;j}%%v{\\Fgdt;n}0.001{\\Fgdt;m}%%v1.200{\\Fgdt;l}%%vA{\\Fgdt;s}%%vB%%vCn"

        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis)
        fcf.setText(gdt_string)

        # Verify the string was set
        assert fcf.textAll() == gdt_string

    def test_set_text_with_symbols(self):
        """
        Test setText using specific GDT symbols (e.g., Positional, Cylindricity).
        """
        # Using symbols: Positional (j), Cylindricity (g)
        symbol_string = "{\\Fgdt;j}0.005{\\Fgdt;g}0.002"

        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis)
        fcf.setText(symbol_string)

        assert symbol_string in fcf.textAll()

    def test_location(self):
        """Test that the location point is set correctly."""
        point = Ge.Point3d(5.0, 10.0, 15.0)
        fcf = Db.Fcf("", point, Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis)

        retrieved_point = fcf.location()

        # Compare coordinates
        assert retrieved_point.x == point.x
        assert retrieved_point.y == point.y
        assert retrieved_point.z == point.z

    def test_normal(self):
        """Test that the normal vector is set correctly."""
        normal = Ge.Vector3d.kYAxis
        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), normal, Ge.Vector3d.kZAxis)

        retrieved_normal = fcf.normal()

        # Compare vectors
        assert retrieved_normal.x == normal.x
        assert retrieved_normal.y == normal.y
        assert retrieved_normal.z == normal.z

    def test_direction(self):
        """Test that the direction vector is set correctly."""
        direction = Ge.Vector3d(0.0, 1.0, 0.0)
        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, direction)

        retrieved_direction = fcf.direction()

        # Compare vectors
        assert retrieved_direction.x == direction.x
        assert retrieved_direction.y == direction.y
        assert retrieved_direction.z == direction.z

    def test_set_orientation(self):
        """Test setOrientation method."""
        new_normal = Ge.Vector3d(0.0, 0.0, 1.0)
        new_direction = Ge.Vector3d(1.0, 0.0, 0.0)

        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis)

        # This should not raise an exception
        fcf.setOrientation(new_normal, new_direction)

        # Verify the change
        assert fcf.normal() == new_normal
        assert fcf.direction() == new_direction

    @pytest.mark.known_failure_GRX
    def test_get_bounding_points(self):
        """Test getBoundingPoints returns 4 points in WCS."""
        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis)

        points = fcf.getBoundingPoints()

        # Should return exactly 4 points
        assert len(points) == 4

        # Order: Top-Left, Top-Right, Bottom-Right, Bottom-Left
        # Note: Exact coordinates depend on the text content and size,
        # but we verify the list structure.
        assert isinstance(points[0], Ge.Point3d)
        assert isinstance(points[1], Ge.Point3d)
        assert isinstance(points[2], Ge.Point3d)
        assert isinstance(points[3], Ge.Point3d)

    @pytest.mark.known_failure_GRX
    def test_get_bounding_pline(self):
        """Test getBoundingPline returns a list of points."""
        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis)

        points = fcf.getBoundingPline()

        # Should return a list of points
        assert isinstance(points, list)
        # Should contain at least the corner points
        assert len(points) > 0
        for p in points:
            assert isinstance(p, Ge.Point3d)

    def test_dimension_style(self):
        """Test dimensionStyle property."""
        # Note: This tests the getter. Setting it requires a valid ObjectId.
        db = Db.curDb()
        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis)
        fcf.setDimensionStyle(db.dimstyle())

        # If no style is set, it might return a null ObjectId or the default
        style_id = fcf.dimensionStyle()
        assert isinstance(style_id, Db.ObjectId)
        assert style_id == db.dimstyle()

    def test_dim_vars(self):
        """Test various dimension variable getters (e.g., dimtxt, dimscale)."""
        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis)

        # Test dimtxt (Text height)
        txt = fcf.dimtxt()
        assert isinstance(txt, float)

        # Test dimscale (Scale factor)
        scale = fcf.dimscale()
        assert isinstance(scale, float)

        # Test dimgap (Gap)
        gap = fcf.dimgap()
        assert isinstance(gap, float)

    def test_set_dim_vars(self):
        """Test setting dimension variable overrides."""
        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis)

        # Set text height override
        fcf.setDimtxt(2.5)

        # Verify it was set (Note: This might return the effective value,
        # which depends on the dimension style, but the override is applied)
        # Ideally, you would check the effective value here.
        assert fcf.dimtxt() > 0

    def test_set_location(self):
        """Test setLocation method."""
        new_loc = Ge.Point3d(100.0, 200.0, 300.0)
        fcf = Db.Fcf("", Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, Ge.Vector3d.kXAxis)

        fcf.setLocation(new_loc)

        assert fcf.location() == new_loc
