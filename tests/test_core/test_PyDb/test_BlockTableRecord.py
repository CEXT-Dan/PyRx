from __future__ import annotations

from pyrx import Db
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
            if name.casefold() == 'N'.casefold():
                btr = Db.BlockTableRecord(id)
                bmp: wx.Bitmap = btr.getPreviewIcon()
                assert bmp.IsOk() is True
                return 
        assert False
       



