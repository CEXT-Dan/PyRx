from __future__ import annotations
from optparse import Values

from pyrx import Ax, Db, Ge


class TestAxDynamicBlockReferenceProperty:

    def get_dynamic_block(self, db: Db.Database):
        objHnd = Db.Handle("70c")
        objId = db.getObjectId(False, objHnd)
        assert objId.isDerivedFrom(Db.BlockReference.desc())
        return Ax.AcadBlockReference.cast(objId.acadObject())

    def test_get(self, db_dynblock: Db.Database):
        values = [
            "Limit Switch NO",
            "Limit Switch Held Closed",
            "Limit Switch NC",
            "Limit Switch Held Open",
        ]
        blkref = self.get_dynamic_block(db_dynblock)
        count = 0
        for prop in blkref.dynamicBlockProperties():
            for val in prop.allowedValues():
                count +=1
                assert str(val.toString()) in values
        assert count == 4
        
