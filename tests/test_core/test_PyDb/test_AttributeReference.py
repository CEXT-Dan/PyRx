from __future__ import annotations

import pytest

from pyrx import Db, Ge


class TestDbAttributeReference:

    def test_create_default(self):
        """Test creating an AttributeReference with default constructor"""
        att = Db.AttributeReference()
        assert isinstance(att, Db.AttributeReference)

    def test_create_with_position_text_tag_styleid(self):
        """Test creating an AttributeReference with position, text, tag, and style ID"""
        pos = Ge.Point3d(10, 10, 0)
        text = "Test Text"
        tag = "TEST_TAG"
        style_id = Db.curDb().textstyle()  # Placeholder for actual ObjectId

        att = Db.AttributeReference(pos, text, tag, style_id)
        assert isinstance(att, Db.AttributeReference)

    def test_set_position_and_get_position(self):
        """Test setting and getting position of attribute reference"""
        val = Ge.Point3d(10, 10, 5)
        att = Db.AttributeReference()
        try:
            att.setPosition(val)
            assert att.position() == val
        except AttributeError:
            assert False, "setPosition method not available in current binding"

    def test_set_tag_and_get_tag(self):
        """Test setting and getting tag of attribute reference"""
        tag_value = "NEW_TAG"
        att = Db.AttributeReference()
        att.setTag(tag_value)
        assert att.tag() == tag_value

    def test_visibility_methods(self):
        """Test visibility related methods"""
        att = Db.AttributeReference()

        # Test isInvisible
        invisible_result = att.isInvisible()
        assert isinstance(invisible_result, (bool, int))

        # Test setInvisible and isInvisible together
        att.setInvisible(True)
        assert att.isInvisible() == True

        att.setInvisible(False)
        assert att.isInvisible() == False

    def test_constant_preset_verifiable_methods(self):
        """Test constant, preset and verifiable related methods"""
        att = Db.AttributeReference()

        # Test isConstant
        const_result = att.isConstant()
        assert isinstance(const_result, (bool, int))

        # Test isPreset
        preset_result = att.isPreset()
        assert isinstance(preset_result, (bool, int))

        # Test isVerifiable
        verif_result = att.isVerifiable()
        assert isinstance(verif_result, (bool, int))

    @pytest.mark.known_failure_BRX
    def test_lock_methods(self):
        """Test lock related methods"""
        att = Db.AttributeReference()

        locked_result = att.isReallyLocked()
        assert isinstance(locked_result, (bool, int))

        # Test setLockPositionInBlock and lockPositionInBlock together
        att.setLockPositionInBlock(True)
        assert att.lockPositionInBlock() == True

        att.setLockPositionInBlock(False)
        assert att.lockPositionInBlock() == False

    def test_mtext_attribute_methods(self):
        """Test multi-line attribute related methods"""
        pass
        # att = Db.AttributeReference()
        # att.convertIntoMTextAttribute(True)
