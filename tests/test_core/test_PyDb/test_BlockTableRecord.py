from __future__ import annotations
from pyrx import Db
from tests import MEDIA_DIR
import pytest


class TestBlockTableRecord:
    def setup_class(self):
        self.brxdb = Db.Database(False,True)
        self.brxdb.readDwgFile(str(MEDIA_DIR / "parametric.dwg"))
        self.brxdb.closeInput(True)
        
    def teardown_class(self):
        del self.brxdb
    
    def test_effective_name(self, db_dynblock: Db.Database):
        bt = Db.BlockTable(db_dynblock.blockTableId())
        for id in bt.toDict().values():
            btr = Db.BlockTableRecord(id)
            if btr.isLayout():
                continue
            assert not "*" in btr.effectiveName()
            
    @pytest.mark.known_failure_ARX
    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_BRX
    def test_effective_name_brx(self):
        bt = Db.BlockTable(self.brxdb.blockTableId())
        for id in bt.toDict().values():
            btr = Db.BlockTableRecord(id)
            if btr.isLayout():
                continue
            assert not "*" in btr.effectiveName()
            
        