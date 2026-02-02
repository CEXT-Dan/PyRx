from __future__ import annotations

from pyrx import Db, Ge


class TestDbAcValue:
    
    def create_with_string(self):
        test_val = "hello"
        acv = Db.AcValue(test_val)
        assert acv.getString() == test_val

    def create_with_int(self):
        test_val = 42
        acv = Db.AcValue(test_val)
        assert acv.getInt32() == test_val

    def create_with_float(self):
        test_val = 3.14
        acv = Db.AcValue(test_val)
        assert acv.getDouble() == test_val

    def create_with_object_id(self):
        test_id = Db.ObjectId()
        acv = Db.AcValue(test_id)
        assert acv.getObjectId() == test_id

    def create_with_point2d(self):
        test_pt = Ge.Point2d(1.0, 2.0)
        acv = Db.AcValue(test_pt)
        assert acv.getPoint2d() == test_pt

    def create_with_point3d(self):
        test_pt = Ge.Point3d(1.0, 2.0, 3.0)
        acv = Db.AcValue(test_pt)
        assert acv.getPoint3d() == test_pt

    def test_is_valid_after_creation(self):
        acv = Db.AcValue("test")
        assert acv.isValid() is True

    def test_reset_value(self):
        acv = Db.AcValue(100)
        assert acv.isValid() is True
        
        # Resetting the value should invalidate the object
        result = acv.resetValue()
        assert result is True
        assert acv.isValid() is False

    def test_reset_with_data_type(self):
        acv = Db.AcValue("test")
        assert acv.isValid() is True
        
        # Resetting with a specific data type
        result = acv.reset(Db.ValueDataType.kString)
        assert result is True
        assert acv.isValid() is False

    def test_format_method(self):
        acv = Db.AcValue(123.456)
        # Default format option
        formatted = acv.format()
        assert isinstance(formatted, str)
        # Verify the string contains the number
        assert "123.456" in formatted

    def test_setter_methods(self):
        acv = Db.AcValue(0) # Initialize with int
        
        # Set as string
        acv.setString("new_string")
        assert acv.getString() == "new_string"
        
        # Set as int
        acv.setInt32(999)
        assert acv.getInt32() == 999
        
        # Set as double
        acv.setDouble(1.5)
        assert acv.getDouble() == 1.5

    def test_data_type_property(self):
        acv = Db.AcValue("test")
        # Check if the data type matches the input type
        # Note: The return type is ValueDataType enum
        assert acv.dataType() == Db.ValueDataType.kString
