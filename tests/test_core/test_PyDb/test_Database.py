from __future__ import annotations
import pytest
from pyrx import Db, Rx, Ed

def do_capture_audit()-> str:
    capture = Db.HostApplicationServices.createOutputCapture()
    capture.setMuteCmdLine(True)
    cmdData = [
        (Rx.LispType.kText, "AUDIT"),
        (Rx.LispType.kText, "N"),
        (Rx.LispType.kNone, 0),
    ]
    Ed.Core.cmdS(cmdData)
    return capture.output()

class TestDatabase:
    def test_dbopbjectforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isValid() is True
        dbo = Db.DbObject(objId)
        assert dbo.isA().dxfName() == "LINE"
    
    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_BRX
    def test_capture_cmdline_output(self):
        result = do_capture_audit()
        assert len(result) != 0
