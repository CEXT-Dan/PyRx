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
