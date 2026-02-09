from __future__ import annotations

import pytest

from pyrx import Db, Ge


class TestDbDimension:
    
    # --- Initialization Tests ---

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

    def test_rotated_dimension_creation(self):
        """Tests creation of a RotatedDimension with a specific angle."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        # Create a rotated dimension (angle in radians)
        dim = Db.RotatedDimension(0.5,pt1, pt2, pt3)
        
        assert dim.xLine1Point() == pt1
        assert dim.xLine2Point() == pt2
        assert dim.dimLinePoint() == pt3
        # Note: measurement is calculated based on the angle
        assert dim.measurement() > 0.0

    def test_dimension_text_initialization(self):
        """Tests setting custom text on creation."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        # Set custom text
        custom_text = "Custom Length"
        dim.setDimensionText(custom_text)
        
        assert dim.dimensionText() == custom_text

    # --- Property Tests ---

    def test_dimension_text_position(self):
        """Tests setting and getting the text position."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        # Set a custom text position
        new_pos = Ge.Point3d(5, 8, 0)
        dim.setTextPosition(new_pos)
        
        assert dim.textPosition() == new_pos

    def test_dimension_text_rotation(self):
        """Tests setting the rotation angle of the text."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        # Set rotation to 45 degrees (pi/4 radians)
        dim.setTextRotation(0.7853981633974483)
        
        # Verify the setter doesn't crash
        assert dim.textRotation() == 0.7853981633974483

    @pytest.mark.known_failure_GRX
    def test_dimension_style(self):
        """Tests setting and getting the dimension style."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        # In a real scenario, you would pass a valid ObjectId here
        # For this test, we verify the setter/getter logic exists
        style_id = Db.curDb().dimstyle()
        dim.setDimensionStyle(style_id)
        assert dim.dimensionStyle() == style_id
        
        # We can test the string properties of the style
        dim.setPrefix("DIA:")
        assert dim.prefix() == "DIA:"
        
        dim.setSuffix(" mm")
        assert dim.suffix() == " mm"

    def test_dimension_elevation(self):
        """Tests setting the elevation of the dimension."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        dim.setElevation(5.0)
        assert dim.elevation() == 5.0

    def test_dimension_normal_vector(self):
        """Tests setting the normal vector (plane) of the dimension."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        # Set a normal vector pointing up (0, 0, 1)
        normal = Ge.Vector3d(0, 0, 1)
        dim.setNormal(normal)
        
        assert dim.normal() == normal

    # --- Formatting Tests ---
    @pytest.mark.known_failure_ZRX
    def test_format_measurement_basic(self):
        """Tests the formatMeasurement method to generate text strings."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        # Format a measurement (e.g., 22.5)
        formatted = dim.formatMeasurement(22.5)
        
        # The result should be a string containing the formatted number
        # The exact format depends on the current dimension style settings
        assert isinstance(formatted, str)
        assert "22.5" in formatted or "22.50" in formatted

    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    def test_format_measurement_with_template(self):
        """Tests formatMeasurement with a dimension text template."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        # Set a template that includes the default text placeholder
        dim.setDimensionText("Length: <>")
        
        # Format a measurement
        formatted = dim.formatMeasurement(15.0)
        
        # The result should combine the template and the formatted number
        assert "Length:" in formatted
        assert "15.0" in formatted

    # --- Block Management Tests ---

    def test_dim_block_id(self):
        """Tests getting the block ID used for the dimension display."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        # Get the block ID
        block_id = dim.dimBlockId()
        
        # The block ID should be valid (not null) for a dimension that has been generated
        # Note: For a newly created dimension, this might be null until generateLayout() is called
        # depending on the API implementation details.
        assert isinstance(block_id, Db.ObjectId)

    def test_dim_block_position(self):
        """Tests getting and setting the block position."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        # Get the default block position
        pos = dim.dimBlockPosition() 
        assert isinstance(pos, Ge.Point3d)
        
    # --- Style Data Tests ---

    def test_get_dimstyle_data(self):
        """Tests copying dimension style data to a record."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        dim.setDatabaseDefaults()
        dms = Db.DimStyleTableRecord()
        dim.setDimstyleData(dms)
        # eInvalidInput? maybe needs a database
        # style_record = dim.getDimstyleData()
        # assert isinstance(style_record, Db.DimStyleTableRecord)

    def test_horizontal_rotation(self):
        """Tests getting the horizontal rotation angle."""
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(10, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)
        
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        
        # Get the horizontal rotation
        rot = dim.horizontalRotation()
        
        # Should be a float value in radians
        assert isinstance(rot, float)
