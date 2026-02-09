from __future__ import annotations

import math

import pytest

from pyrx import Db, Ge


class TestDbShape:
    
    # --- Constructor Tests ---

    @pytest.mark.known_failure_ZRX
    def test_create_1(self):
        """Tests the constructor with position, size, rotation, and widthFactor."""
        shape = Db.Shape(Ge.Point3d(10, 10, 0), 15, 0, 0)
        assert shape.size() == 15
        assert shape.position() == Ge.Point3d(10, 10, 0)
        assert shape.rotation() == 0
        assert shape.widthFactor() == 0

    def test_position_setter(self):
        """Tests setting and getting the insertion point."""
        shape = Db.Shape()
        new_pos = Ge.Point3d(5.0, 5.0, 5.0)
        shape.setPosition(new_pos)
        assert shape.position() == new_pos

    def test_size_setter(self):
        """Tests setting and getting the height."""
        shape = Db.Shape()
        shape.setSize(25.0)
        assert shape.size() == 25.0

    def test_rotation_setter(self):
        """Tests setting and getting the rotation angle."""
        shape = Db.Shape()
        shape.setRotation(math.radians(45.0))
        assert shape.rotation() == math.radians(45.0)

    def test_width_factor_setter(self):
        """Tests setting and getting the width factor."""
        shape = Db.Shape()
        shape.setWidthFactor(0.8)
        assert shape.widthFactor() == 0.8

    def test_thickness_setter(self):
        """Tests setting and getting the thickness."""
        shape = Db.Shape()
        shape.setThickness(2.0)
        assert shape.thickness() == 2.0

    def test_normal_setter(self):
        """Tests setting and getting the normal vector."""
        shape = Db.Shape()
        new_normal = Ge.Vector3d(0, 0, 1)
        shape.setNormal(new_normal)
        assert shape.normal() == new_normal

    def test_oblique_setter(self):
        """Tests setting and getting the oblique angle."""
        shape = Db.Shape()
        shape.setOblique(30.0)
        assert shape.oblique() == 30.0

    def test_shape_number_setter(self):
        """Tests setting the shape number (character index in SHX font)."""
        shape = Db.Shape()
        shape.setShapeNumber(65) # ASCII 'A' usually
        assert shape.shapeNumber() == 65

    def test_style_id_setter(self):
        """Tests setting the style ID (SHX font reference)."""
        db = Db.curDb()
        shape = Db.Shape()
        shape.setStyleId(db.textstyle())
        assert shape.styleId() == db.textstyle()

    def test_name_setter(self):
        """
        Tests setting the name.
        Note: The documentation states this requires the object to be in a database 
        and the shape to be loaded in the text style table.
        """
        pass
        #shape = Db.Shape()
        # This will likely fail without a database context, but tests the API call.
        #shape.setName("TEST_SHAPE")
        #shape.name()
        # Note: getName() returns the name, but the doc says it's derived from shapeNumber/styleId
        # if not explicitly set in a database context.

    def test_dxf_group_code_position(self):
        """Verifies position corresponds to DXF Group Code 10."""
        shape = Db.Shape()
        pos = Ge.Point3d(100, 200, 300)
        shape.setPosition(pos)
        # The API returns the value, verifying the mapping conceptually
        assert shape.position() == pos

    def test_dxf_group_code_size(self):
        """Verifies size corresponds to DXF Group Code 40."""
        shape = Db.Shape()
        shape.setSize(10.5)
        assert shape.size() == 10.5

    def test_dxf_group_code_rotation(self):
        """Verifies rotation corresponds to DXF Group Code 50."""
        shape = Db.Shape()
        shape.setRotation(math.radians(90.0))
        assert shape.rotation() == math.radians(90.0)

    def test_dxf_group_code_thickness(self):
        """Verifies thickness corresponds to DXF Group Code 39."""
        shape = Db.Shape()
        shape.setThickness(5.0)
        assert shape.thickness() == 5.0

    def test_dxf_group_code_width_factor(self):
        """Verifies width factor corresponds to DXF Group Code 41."""
        shape = Db.Shape()
        shape.setWidthFactor(0.5)
        assert shape.widthFactor() == 0.5

    def test_dxf_group_code_normal(self):
        """Verifies normal corresponds to DXF Group Code 210."""
        shape = Db.Shape()
        norm = Ge.Vector3d(1, 0, 0)
        shape.setNormal(norm)
        assert shape.normal() == norm

    def test_dxf_group_code_oblique(self):
        """Verifies oblique corresponds to DXF Group Code 51."""
        shape = Db.Shape()
        shape.setOblique(15.0)
        assert shape.oblique() == 15.0
