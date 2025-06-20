from __future__ import annotations

import pytest

from pyrx import Db, Ge


class TestAttributeDefinition:
    
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
    
