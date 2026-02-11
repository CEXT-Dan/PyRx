from __future__ import annotations

from pyrx import Db


class TestDatabaseSummaryInfo:
    
    def test_initialization_with_database(self, db_06457: Db.Database):
        """Test that DatabaseSummaryInfo can be initialized with a database object."""
        info = Db.DatabaseSummaryInfo(db_06457)
        assert info is not None
        assert isinstance(info, Db.DatabaseSummaryInfo)

    def test_initialization_empty(self):
        """Test that DatabaseSummaryInfo can be initialized without arguments."""
        info = Db.DatabaseSummaryInfo()
        assert info is not None

    def test_standard_properties_getters(self):
        """Test getting standard metadata properties."""
        info = Db.DatabaseSummaryInfo()
        
        # Set some values
        info.setTitle("Test Title")
        info.setAuthor("Test Author")
        info.setComments("Test Comments")
        
        # Verify getters
        assert info.getTitle() == "Test Title"
        assert info.getAuthor() == "Test Author"
        assert info.getComments() == "Test Comments"

    def test_custom_properties_add_and_get(self):
        """Test adding and retrieving custom summary info."""
        info = Db.DatabaseSummaryInfo()
        info.removeAllCustomSummaryInfo()
        
        # Add custom info
        info.addCustomSummaryInfo("CustomKey1", "CustomValue1")
        info.addCustomSummaryInfo("CustomKey2", "CustomValue2")
        
        # Verify count
        assert info.numCustomInfo() == 2
        
        # Get specific custom info
        key, val = info.getCustomSummaryInfo("CustomKey1")
        assert key == "CustomKey1"
        assert val == "CustomValue1"
        
        # Verify iteration (based on __getitem__ signature)
        # Note: Depending on the underlying implementation, iteration might yield tuples
        count = 0
        for item in info:
            assert isinstance(item, tuple)
            assert len(item) == 2
            count += 1
        assert count == 2

    def test_custom_properties_dict_operations(self):
        """Test bulk operations using dictionaries."""
        info = Db.DatabaseSummaryInfo()
        info.removeAllCustomSummaryInfo()
        
        # Set multiple custom info at once
        data = {"KeyA": "ValA", "KeyB": "ValB", "KeyC": "ValC"}
        info.setCustomSummaryFromDict(data)
        
        assert info.numCustomInfo() == 3
        
        # Verify retrieval
        assert info.getCustomSummaryInfo("KeyA") == ("KeyA", "ValA")
        assert info.getCustomSummaryInfo("KeyB") == ("KeyB", "ValB")

    def test_custom_properties_delete(self):
        """Test deleting custom summary info."""
        info = Db.DatabaseSummaryInfo()
        info.removeAllCustomSummaryInfo()
        
        info.addCustomSummaryInfo("ToDelete", "Value")
        assert info.numCustomInfo() == 1
        
        # Delete by key
        info.deleteCustomSummaryInfo("ToDelete")
        assert info.numCustomInfo() == 0
        
        # Delete by index (if available)
        info.addCustomSummaryInfo("IndexTest", "Value")
        info.addCustomSummaryInfo("IndexTest2", "Value")
        assert info.numCustomInfo() == 2
        
        # Assuming index 0 is the first added item
        info.deleteCustomSummaryInfo(0)
        assert info.numCustomInfo() == 1

    def test_has_custom_key(self):
        """Test checking existence of a custom key."""
        info = Db.DatabaseSummaryInfo()
        
        info.addCustomSummaryInfo("Exists", "Yes")
        
        assert info.hasCustomKey("Exists") is True
        assert info.hasCustomKey("DoesNotExist") is False

    def test_remove_all_custom_info(self):
        """Test removing all custom info."""
        info = Db.DatabaseSummaryInfo()
        info.removeAllCustomSummaryInfo()
        
        info.addCustomSummaryInfo("A", "1")
        info.addCustomSummaryInfo("B", "2")
        
        assert info.numCustomInfo() == 2
        
        info.removeAllCustomSummaryInfo()
        
        assert info.numCustomInfo() == 0

    def test_persistence_set_into_database(self, db_06457: Db.Database):
        """Test that changes are persisted back to the database."""
        info = Db.DatabaseSummaryInfo(db_06457)
        
        info.setTitle("Persisted Title")
        info.setAuthor("Persisted Author")
        
        # Commit changes to the database
        info.setIntoDatabase(db_06457)
        
        # Retrieve info from the database directly to verify persistence
        db_info = Db.DatabaseSummaryInfo(db_06457)
        assert db_info.getTitle() == "Persisted Title"
        assert db_info.getAuthor() == "Persisted Author"

    def test_as_dict(self, db_06457: Db.Database):
        """Test converting summary info to a dictionary."""
        info = Db.DatabaseSummaryInfo(db_06457)
        info.addCustomSummaryInfo("Custom", "Value")
        result = info.asDict()
        
        assert isinstance(result, dict)
        assert result.get("Custom") == "Value"
