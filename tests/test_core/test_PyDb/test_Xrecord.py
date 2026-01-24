from __future__ import annotations
from pyrx import Db


class TestDbXrecord:

    def test_rbchain_1(self):
        chain = [(1, "helloWorld"), (38, 12.9),(70, 4500)]
        xr = Db.Xrecord()
        xr.setFromRbChain(chain)
        assert xr.rbChain() == chain
        
    def test_rbchain_2(self):
        chain = [(Db.DxfCode.kDxfBlockName, "helloWorld"), (38, 12.9),(70, 4500)]
        xr = Db.Xrecord()
        xr.setFromRbChain(chain)
        assert xr.rbChain() == chain
        

        
