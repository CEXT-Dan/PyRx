from __future__ import annotations

from pyrx import Db


class TestDbDictionary:

    def test_setat_getat(self):
        db = Db.curDb()
        d = Db.Dictionary(db.namedObjectsDictionaryId(),Db.OpenMode.kForWrite)
        xr = Db.Xrecord()
        xr.setFromRbChain([(Db.DxfCode.kDxfText,"hello")])
        id = d.setAt("my_key",xr)
        assert d.getAt("my_key") == id
        assert d["my_key"] == id
        
    def test_iter(self):
        db = Db.curDb()
        d = Db.Dictionary(db.namedObjectsDictionaryId())
        cnt = 0
        for name, id in d:
            cnt +=1 
            assert name is not None
            assert id.isNull() == False
        assert cnt > 0
            



        
