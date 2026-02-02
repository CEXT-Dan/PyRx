from __future__ import annotations

import pytest

from pyrx import Db, Ge, Rx


class TestDbBlockReference:

    def test_hasAttributes_1(self, db_06457: Db.Database):
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)
        assert r.hasAttributes() == True

    def test_hasAttributes_2(self, db_06457: Db.Database):
        objHnd = Db.Handle("54d2e")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)
        assert r.hasAttributes() == False

    def test_blockTableRecord(self, db_06457: Db.Database):
        """Test getting the block table record ID"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)
        block_table_record_id = r.blockTableRecord()

        # Verify it returns a valid ObjectId
        assert isinstance(block_table_record_id, Db.ObjectId)
        assert not block_table_record_id.isNull()

    def test_position(self):
        """Test getting the position of the block reference"""
        r = Db.BlockReference()
        pos = r.position()
        assert isinstance(pos, Ge.Point3d)

    def test_setPosition(self):
        """Test setting the position of the block reference"""
        r = Db.BlockReference()
        original_pos = r.position()

        # Set new position
        new_pos = Ge.Point3d(10.0, 20.0, 30.0)
        r.setPosition(new_pos)

        # Verify the position was set correctly
        assert r.position() == new_pos

    def test_normal(self):
        """Test getting the normal vector of the block reference"""
        r = Db.BlockReference()

        normal = r.normal()

        # Verify it returns a valid Vector3d
        assert isinstance(normal, Ge.Vector3d)
        # Normal should be normalized (length of 1.0)
        assert abs(normal.length() - 1.0) < 1e-6

    def test_setNormal(self):
        """Test setting the normal vector of the block reference"""
        r = Db.BlockReference()

        # Get current normal
        original_normal = r.normal()
        assert original_normal == Ge.Vector3d.kZAxis

        # Set new normal (should be normalized)
        new_normal = Ge.Vector3d(0.0, 0.0, 1.0)  # Z-axis
        r.setNormal(new_normal)

        # Verify the normal was set correctly
        assert abs(r.normal().length() - 1.0) < 1e-6
    

    def test_rotation(self):
        """Test getting the rotation of the block reference"""
        r = Db.BlockReference()
        rotation = r.rotation()
        
        # Verify it returns a float
        assert isinstance(rotation, float)

    def test_setRotation(self):
        """Test setting the rotation of the block reference"""
        r = Db.BlockReference()

        # Get current rotation
        original_rotation = r.rotation()

        # Set new rotation (in radians)
        new_rotation = 1.5708  # 90 degrees in radians
        r.setRotation(new_rotation)

        # Verify the rotation was set correctly
        assert abs(r.rotation() - new_rotation) < 1e-6

    def test_scaleFactors(self):
        """Test getting the scale factors of the block reference"""
        r = Db.BlockReference()
        scales = r.scaleFactors()

        # Verify it returns a valid Scale3d
        assert isinstance(scales, Ge.Scale3d)

    def test_setScaleFactors(self):
        """Test setting the scale factors of the block reference"""
        r = Db.BlockReference()

        # Get current scales
        original_scales = r.scaleFactors()

        # Set new scale factors
        new_scales = Ge.Scale3d(2.0, 2.0, 2.0)
        r.setScaleFactors(new_scales)

        # Verify the scales were set correctly
        assert r.scaleFactors() == new_scales

    def test_blockTransform(self, db_06457: Db.Database):
        """Test getting the block transformation matrix"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)

        transform = r.blockTransform()

        # Verify it returns a valid Matrix3d
        assert isinstance(transform, Ge.Matrix3d)

    @pytest.mark.known_failure_BRX
    def test_nonAnnotationBlockTransform(self, db_06457: Db.Database):
        """Test getting the non-annotation block transformation matrix"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)

        transform = r.nonAnnotationBlockTransform()

        # Verify it returns a valid Matrix3d
        assert isinstance(transform, Ge.Matrix3d)

    @pytest.mark.known_failure_BRX
    def test_nonAnnotationScaleFactors(self, db_06457: Db.Database):
        """Test getting the non-annotation scale factors"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)

        scales = r.nonAnnotationScaleFactors()

        # Verify it returns a valid Scale3d
        assert isinstance(scales, Ge.Scale3d)

    def test_getBlockName(self, db_06457: Db.Database):
        """Test getting the block name"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)

        block_name = r.getBlockName()

        # Verify it returns a string
        assert isinstance(block_name, str)
        assert len(block_name) > 0

    def test_effectiveName(self, db_06457: Db.Database):
        """Test getting the effective name"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)

        effective_name = r.effectiveName()

        # Verify it returns a string
        assert isinstance(effective_name, str)

    def test_attributeIds(self, db_06457: Db.Database):
        """Test getting attribute IDs"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)

        attr_ids = r.attributeIds()

        # Verify it returns a list
        assert isinstance(attr_ids, list)

        # If attributes exist, verify they are ObjectIds
        if len(attr_ids) > 0:
            for attr_id in attr_ids:
                assert isinstance(attr_id, Db.ObjectId)

    def test_attlist(self, db_06457: Db.Database):
        """Test getting attribute list"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)

        attr_list = r.attlist()

        # Verify it returns a list
        assert isinstance(attr_list, list)

    def test_attdict(self, db_06457: Db.Database):
        """Test getting attribute dictionary"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)

        attr_dict = r.attdict()

        # Verify it returns a dict
        assert isinstance(attr_dict, dict)

    def test_className(self):
        """Test getting the class name"""
        class_name = Db.BlockReference.className()

        # Verify it returns a string
        assert isinstance(class_name, str)
        assert len(class_name) > 0

    def test_desc(self):
        """Test getting the RxClass description"""
        desc = Db.BlockReference.desc()
        # Verify it returns an RxClass
        assert isinstance(desc, Rx.RxClass)

    def test_geomExtentsBestFit(self, db_06457: Db.Database):
        """Test getting best fit geometry extents"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)

        # Test with default identity matrix
        extents = r.geomExtentsBestFit()

        # Verify it returns valid extents
        assert isinstance(extents, Db.Extents)

    def test_setBlockTransform(self):
        """Test setting the block transform"""
        r = Db.BlockReference()

        # Get current transformation
        original_transform = r.blockTransform()
        assert original_transform ==  Ge.Matrix3d.kIdentity

        # Create a new transformation matrix
        identity_matrix = Ge.Matrix3d.kIdentity
        r.setBlockTransform(identity_matrix)


    def test_treatAsAcDbBlockRefForExplode(self, db_06457: Db.Database):
        """Test the explode treatment flag"""
        objHnd = Db.Handle("212b3")
        objId = db_06457.getObjectId(False, objHnd)
        r = Db.BlockReference(objId)

        # This should return a boolean
        result = r.treatAsAcDbBlockRefForExplode()
        assert isinstance(result, (bool, int,  Db.AdskBoolean))
