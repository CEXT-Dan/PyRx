from __future__ import annotations

from pyrx import Db


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
        assert objId.isValid() is True
        dynref = Db.DynBlockReference(objId)
        assert dynref.isDynamicBlock() is True
        btr = Db.BlockTableRecord(dynref.anonymousBlockTableRecord())
        assert len(btr.objectIds()) == 8
        assert len(btr.visibleObjectIds()) == 5


