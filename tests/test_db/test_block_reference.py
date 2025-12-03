from pyrx import Db
from pyrx.db.block_reference import BlockReference

import pytest

class TestBlockReference:
    def test_attributes(self, db_06457: Db.Database):
        db = db_06457
        bref_id = db.getObjectId(False, Db.Handle("ED51"))
        bref = BlockReference(bref_id)

        # as ids
        attrs = bref.attributes("id")
        assert isinstance(attrs, dict)
        assert len(attrs) == 3
        assert isinstance(attrs["DRAWING"], Db.ObjectId)
        assert isinstance(attrs["NUMBER"], Db.ObjectId)
        assert isinstance(attrs["SCALE"], Db.ObjectId)

        # as attribute references
        attrs = bref.attributes("obj")
        assert isinstance(attrs, dict)
        assert len(attrs) == 3
        assert isinstance(attrs["DRAWING"], Db.AttributeReference)
        assert isinstance(attrs["NUMBER"], Db.AttributeReference)
        assert isinstance(attrs["SCALE"], Db.AttributeReference)
        assert attrs["DRAWING"].textString() == "Section"
        assert attrs["NUMBER"].textString() == "2"
        assert attrs["SCALE"].textString() == "1\"=1'"

        del attrs

        # as attribute references with open mode
        attrs = bref.attributes("obj", Db.OpenMode.kForWrite)
        assert isinstance(attrs, dict)
        assert len(attrs) == 3
        attr = attrs["DRAWING"]
        assert isinstance(attr, Db.AttributeReference)
        assert attr.isWriteEnabled()

    @pytest.mark.known_failure_IRX
    def test_get_attribute(self, db_06457: Db.Database):
        db = db_06457
        bref_id = db.getObjectId(False, Db.Handle("ED51"))
        bref = BlockReference(bref_id)

        attr = bref.get_attribute("DRAWING")
        assert isinstance(attr, Db.AttributeReference)
        assert attr.textString() == "Section"
        attr.close()
        attr.dispose()

        attr = bref.get_attribute("DRAWING", Db.OpenMode.kForWrite)
        assert isinstance(attr, Db.AttributeReference)
        assert attr.isWriteEnabled()
        attr.close()
        attr.dispose()

        attr = bref.get_attribute("NOT_EXISTING")
        assert attr is None

    def test_get_attribute_text(self, db_block_reference: Db.Database):
        db = db_block_reference
        bref_id = db.getObjectId(False, Db.Handle("25D"))
        bref = BlockReference(bref_id)

        res_text = bref.get_attribute_text("TEXT_ATTR")
        assert res_text == "text_attr_value"

        res_mtext = bref.get_attribute_text("MTEXT_ATTR")
        assert res_mtext == "mtext\nattr\nvalue"
