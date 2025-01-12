from __future__ import annotations

from pyrx import Db


class TestDatabase:
    def test_dbopbjectforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isValid() is True
        dbo = Db.DbObject(objId)
        assert dbo.isA().dxfName() == "LINE"
