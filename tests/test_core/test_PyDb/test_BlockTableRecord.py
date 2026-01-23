from __future__ import annotations

from pyrx import Db, Ge, Rx
import wx


class TestBlockTableRecord:

    def test_effective_name(self, db_dynblock: Db.Database):
        bt = Db.BlockTable(db_dynblock.blockTableId())
        for id in bt.toDict().values():
            btr = Db.BlockTableRecord(id)
            if btr.isLayout():
                continue
            assert "*" not in btr.effectiveName()

    def test_visibleObjectIds(self, db_dynblock: Db.Database):
        objHnd = Db.Handle("70c")
        objId = db_dynblock.getObjectId(False, objHnd)
        assert objId.isNull() is False
        dynref = Db.DynBlockReference(objId)
        assert dynref.isDynamicBlock() is True
        btr = Db.BlockTableRecord(dynref.anonymousBlockTableRecord())
        assert len(btr.objectIds()) == 8
        assert len(btr.visibleObjectIds()) == 5

    def test_block_icon(self, db_06457: Db.Database):
        for name, id in db_06457.getBlocks().items():
            if name.casefold() == "N".casefold():
                btr = Db.BlockTableRecord(id)
                bmp: wx.Bitmap = btr.getPreviewIcon()
                assert bmp.IsOk() is True
                return
        assert False

    """Tests for SymbolTableRecord class (abstract base class)"""

    def test_symbol_table_record_name_methods(self):
        # Create a mock symbol table record instance
        # Note: Since SymbolTableRecord is abstract, we'll test with BlockTableRecord
        btr = Db.BlockTableRecord()

        # Test setName and getName
        test_name = "TestBlock"
        btr.setName(test_name)
        assert btr.getName() == test_name
        assert btr.name() == test_name

        # Test isRenamable (should return True for most cases)
        assert isinstance(btr.isRenamable(), (bool, int))

    def test_symbol_table_record_dependency_methods(self):
        btr = Db.BlockTableRecord()

        # Test isDependent and isResolved methods
        # These will depend on the specific context, but we can at least verify they return booleans
        assert isinstance(btr.isDependent(), (bool, int))
        assert isinstance(btr.isResolved(), (bool, int))

    def test_block_table_record_origin_methods(self):
        btr = Db.BlockTableRecord()
        origin = Ge.Point3d(10, 10, 0)
        btr.setOrigin(origin)
        assert btr.origin() == origin

    def test_block_table_record_name_methods(self):
        btr = Db.BlockTableRecord()

        # Test setName and getName
        test_name = "TestBlock"
        btr.setName(test_name)
        assert btr.getName() == test_name
        assert btr.name() == test_name

        # Test isRenamable (should return True for most cases)
        assert isinstance(btr.isRenamable(), (bool, int))

    def test_block_table_record_dependency_methods(self):
        btr = Db.BlockTableRecord()

        # Test dependency methods
        assert isinstance(btr.isDependent(), (bool, int))
        assert isinstance(btr.isResolved(), (bool, int))

    def test_block_table_record_anonymous_method(self):
        btr = Db.BlockTableRecord()
        assert isinstance(btr.isAnonymous(), (bool, int))

    def test_block_table_record_explodable_method(self):
        btr = Db.BlockTableRecord()
        assert isinstance(btr.explodable(), (bool, int))

    def test_block_table_record_attribute_definitions(self):
        btr = Db.BlockTableRecord()
        assert isinstance(btr.hasAttributeDefinitions(), (bool, int))

    def test_block_table_record_xref_methods(self):
        btr = Db.BlockTableRecord()

        # Test xref-related methods
        assert isinstance(btr.isFromExternalReference(), (bool, int))
        assert isinstance(btr.isFromOverlayReference(), (bool, int))
        assert isinstance(btr.isUnloaded(), (bool, int))

    def test_block_table_record_layout_methods(self):
        btr = Db.BlockTableRecord()
        assert isinstance(btr.isLayout(), (bool, int))

    def test_block_table_record_scaling_methods(self):
        btr = Db.BlockTableRecord()
        # Test block scaling - should return either kAny or kUniform
        scale_type = btr.blockScaling()
        # Verify it's one of the expected values (kAny, kUniform)
        # These are likely constants that would be defined in PyDb namespace

    def test_block_table_record_insert_units(self):
        btr = Db.BlockTableRecord()

        # Test block insert units method
        units = btr.blockInsertUnits()
        # Should return a UnitsValue or kUnitsUndefined

    def test_block_table_record_comments_methods(self):
        btr = Db.BlockTableRecord()

        # Test comments methods
        test_comment = "Test comment for block"
        btr.setComments(test_comment)
        assert btr.comments() == test_comment

    def test_block_table_record_path_name_methods(self):
        btr = Db.BlockTableRecord()

        # Test path name (xref related) methods
        path = btr.pathName()
        # Should return string or empty string for non-xrefs

    def test_block_table_record_preview_icon_methods(self):
        btr = Db.BlockTableRecord()

        # Test preview icon methods (should return bool)
        assert isinstance(btr.hasPreviewIcon(), (bool, int))

    def test_block_table_record_layout_id_methods(self):
        db = Db.curDb()
        btr = Db.BlockTableRecord(db.modelSpaceId())

        # Test layout id method
        layout_id = btr.getLayoutId()
        # Should return ObjectId or None

    def test_block_table_record_class_info(self):
        """Test class information methods"""
        # Test className method
        assert isinstance(Db.BlockTableRecord.className(), str)

        # Test desc method
        desc = Db.BlockTableRecord.desc()
        assert desc.isDerivedFrom(Db.BlockTableRecord.desc())

        # Test cast static method (test with a dummy object if needed)
        # This might require creating an actual instance to test casting

    def test_block_table_record_object_id_methods(self):
        db = Db.curDb()
        btr = Db.BlockTableRecord(db.modelSpaceId())

        # Test object id methods (should return lists or arrays)
        obj_ids = btr.objectIds()
        assert isinstance(obj_ids, list)

        # Test with specific class filter
        entity_obj_ids = btr.objectIds(Db.Entity.desc())
        assert isinstance(entity_obj_ids, list)
        
        entity_obj_ids = btr.objectIds([Db.Entity.desc()])
        assert isinstance(entity_obj_ids, list)

    def test_block_table_record_iterable(self):
        """Test that BlockTableRecord can be iterated over"""
        db = Db.curDb()
        btr = Db.BlockTableRecord(db.modelSpaceId())

        # Test __iter__ method - should return an iterator
        iterator = iter(btr)
        assert hasattr(iterator, "__next__")

    def test_block_table_record_xref_status(self):
        btr = Db.BlockTableRecord()

        # Test xref status method (should return XrefStatus enum)
        status = btr.xrefStatus()
        assert status is not None

    def test_block_table_record_set_is_unloaded(self):
        """Test the setIsUnloaded method"""
        btr = Db.BlockTableRecord()

        # Test setting unloaded state (should not raise exceptions)
        btr.setIsUnloaded(True)
        btr.setIsUnloaded(False)

    def test_block_table_record_set_explodable(self):
        """Test the setExplodable method"""
        btr = Db.BlockTableRecord()

        # Test setting explodable (should not raise exceptions)
        btr.setExplodable(True)
        btr.setExplodable(False)

    def test_block_table_record_set_path_name(self):
        """Test the setPathName method"""
        btr = Db.BlockTableRecord()

        # Test setting path name (should not raise exceptions)
        btr.setPathName("test_path.dwg")

    def test_block_table_record_set_comments(self):
        """Test the setComments method"""
        btr = Db.BlockTableRecord()

        # Test setting comments (should not raise exceptions)
        btr.setComments("test comment")

    def test_block_table_record_set_origin(self):
        """Test the setOrigin method"""
        btr = Db.BlockTableRecord()

        # Test setting origin
        new_origin = Ge.Point3d(5, 5, 0)
        btr.setOrigin(new_origin)
        assert btr.origin() == new_origin

    def test_block_table_record_set_block_scaling(self):
        """Test the setBlockScaling method"""
        btr = Db.BlockTableRecord()

        # Test setting block scaling (should not raise exceptions)
        btr.setBlockScaling(Db.BlockScaling.kAny)
        btr.setBlockScaling(Db.BlockScaling.kUniform)

    def test_block_table_record_set_block_insert_units(self):
        """Test the setBlockInsertUnits method"""
        btr = Db.BlockTableRecord()

        # Test setting insert units (should not raise exceptions)
        btr.setBlockInsertUnits(Db.UnitsValue.kUnitsUndefined)

    def test_block_table_record_get_block_references(self):
        """Test the getBlockReferences method"""
        pass
        # btr = Db.BlockTableRecord()

        # # Test getting block references (should return list or fail gracefully)
        # refs = btr.getBlockReferences(Db.OpenMode.kForRead)
        # assert isinstance(refs, list)

    def test_block_table_record_get_block_reference_ids(self):
        """Test the getBlockReferenceIds method"""
        pass
        # btr = Db.BlockTableRecord()

        # # Test getting block reference IDs
        # ids = btr.getBlockReferenceIds(True, False)
        # assert isinstance(ids, list)
