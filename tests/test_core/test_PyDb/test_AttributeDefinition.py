from __future__ import annotations

import pytest

from pyrx import Db, Ge, Rx


class TestAttributeDefinition:
    
    @pytest.mark.known_failure_IRX
    @pytest.mark.known_failure_GRX
    def test_setMTextAttributeDefinition(self):
        db = Db.curDb()
        mtext = Db.MText()
        mtext.setDatabaseDefaults(db)
        mtext.setContents("NEWATT") 

        attr = Db.AttributeDefinition()
        attr.setDatabaseDefaults(db)
        attr.setTag("TEST")
        attr.setPosition(Ge.Point3d(0.0, 0.0, 0.0))
        attr.setPrompt("TEST")

        attr.convertIntoMTextAttributeDefinition(True)
        attr.setMTextAttributeDefinition(mtext)
        db.addToModelspace(attr)
        assert attr.textString() == "NEWATT"
        
        
    @pytest.mark.known_failure_IRX
    @pytest.mark.known_failure_GRX
    def test_getMTextAttributeDefinition(self):
        db = Db.curDb()
        mtext = Db.MText()
        mtext.setDatabaseDefaults(db)
        mtext.setContents("OLDATT") 

        attr = Db.AttributeDefinition()
        attr.setDatabaseDefaults(db)
        attr.setTag("TEST")
        attr.setPosition(Ge.Point3d(0.0, 0.0, 0.0))
        attr.setPrompt("TEST")
        attr.convertIntoMTextAttributeDefinition(True)
        attr.setMTextAttributeDefinition(mtext)
        
        mt2 = attr.getMTextAttributeDefinition()
        mt2.setContents("NEWATT") 
        attr.setMTextAttributeDefinition(mt2)
        assert attr.textString() == "NEWATT"
        db.addToModelspace(attr)
    
    def test_create_default(self):
        """Test creating an AttributeDefinition with default constructor"""
        attdef = Db.AttributeDefinition()
        assert isinstance(attdef, Db.AttributeDefinition)
        
    def test_create_with_parameters(self):
        """Test creating an AttributeDefinition with all parameters"""
        position = Ge.Point3d(10, 20, 0)
        text = "test_text"
        tag = "test_tag"
        prompt = "Enter value"
        styleid = Db.curDb().textstyle()  # Placeholder for actual style ID
        
        attdef = Db.AttributeDefinition(position, text, tag, prompt, styleid)
        assert isinstance(attdef, Db.AttributeDefinition)
        
    def test_position_and_set_position(self):
        """Test getting and setting position"""
        attdef = Db.AttributeDefinition()
        position = Ge.Point3d(10, 10, 0)
        attdef.setPosition(position)
        assert attdef.position() == position
        
    def test_prompt_and_set_prompt(self):
        """Test getting and setting prompt"""
        attdef = Db.AttributeDefinition()
        prompt_text = "Enter value"
        attdef.setPrompt(prompt_text)
        assert attdef.prompt() == prompt_text
        
    def test_tag_and_set_tag(self):
        """Test getting and setting tag"""
        attdef = Db.AttributeDefinition()
        tag_value = "test_tag"
        attdef.setTag(tag_value)
        assert attdef.tag() == tag_value
        
    def test_constant_flags(self):
        """Test constant flag functionality"""
        attdef = Db.AttributeDefinition()
        
        # Test default state (should be False)
        assert not attdef.isConstant()
        
        # Set to True
        attdef.setConstant(True)
        assert attdef.isConstant()
        
        # Set to False
        attdef.setConstant(False)
        assert not attdef.isConstant()
        
    def test_invisible_flags(self):
        """Test invisible flag functionality"""
        attdef = Db.AttributeDefinition()
        
        # Test default state (should be False)
        assert not attdef.isInvisible()
        
        # Set to True
        attdef.setInvisible(True)
        assert attdef.isInvisible()
        
        # Set to False
        attdef.setInvisible(False)
        assert not attdef.isInvisible()
        
    def test_preset_flags(self):
        """Test preset flag functionality"""
        attdef = Db.AttributeDefinition()
        
        # Test default state (should be False)
        assert not attdef.isPreset()
        
        # Set to True
        attdef.setPreset(True)
        assert attdef.isPreset()
        
        # Set to False
        attdef.setPreset(False)
        assert not attdef.isPreset()
        
    def test_verifiable_flags(self):
        """Test verifiable flag functionality"""
        attdef = Db.AttributeDefinition()
        
        # Test default state (should be False)
        assert not attdef.isVerifiable()
        
        # Set to True
        attdef.setVerifiable(True)
        assert attdef.isVerifiable()
        
        # Set to False
        attdef.setVerifiable(False)
        assert not attdef.isVerifiable()
        
    def test_lock_position_flags(self):
        """Test lock position flag functionality"""
        attdef = Db.AttributeDefinition()
        
        # Test default state (should be False)
        assert not attdef.lockPositionInBlock()
        
        # Set to True
        attdef.setLockPositionInBlock(True)
        assert attdef.lockPositionInBlock()
        
        # Set to False
        attdef.setLockPositionInBlock(False)
        assert not attdef.lockPositionInBlock()
        
    def test_field_length(self):
        """Test field length functionality"""
        attdef = Db.AttributeDefinition()
        length = 50
        
        # Test setting and getting field length
        attdef.setFieldLength(length)
        assert attdef.fieldLength() == length
        
    def test_class_methods(self):
        """Test static class methods"""
        # Test className method
        class_name = Db.AttributeDefinition.className()
        assert isinstance(class_name, str)
        
        # Test desc method
        rx_class = Db.AttributeDefinition.desc()
        assert rx_class.isDerivedFrom(Db.AttributeDefinition.desc())
        assert isinstance(rx_class, Rx.RxClass)

