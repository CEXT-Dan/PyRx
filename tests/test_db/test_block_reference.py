from pyrx import Db
from pyrx.db.block_reference import BlockReference


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
