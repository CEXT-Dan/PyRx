from __future__ import annotations

from pyrx import Db


class TestDbDictionary:

    def test_setat_getat(self):
        db = Db.curDb()
        d = Db.Dictionary(db.namedObjectsDictionaryId(), Db.OpenMode.kForWrite)
        xr = Db.Xrecord()
        xr.setFromRbChain([(Db.DxfCode.kDxfText, "hello")])
        id = d.setAt("my_key", xr)
        assert d.getAt("my_key") == id
        assert d["my_key"] == id
        assert d.has("my_key") == True

    def test_iter(self):
        db = Db.curDb()
        d = Db.Dictionary(db.namedObjectsDictionaryId())
        cnt = 0
        for name, id in d:
            cnt += 1
            assert name is not None
            assert id.isNull() == False
        assert cnt > 0


class TestDbDefaultDictionary:

    def test_iter(self):
        db = Db.curDb()
        nod_id = db.namedObjectsDictionaryId()
        nod = Db.Dictionary(nod_id)
        if nod.has("ACAD_PLOTSTYLENAME"):
            defualt_dict_id = nod.getAt("ACAD_PLOTSTYLENAME")
            assert defualt_dict_id.isDerivedFrom(Db.DictionaryWithDefault.desc()) == True
            defualt_dict = Db.DictionaryWithDefault(defualt_dict_id)
            ver, maintver = defualt_dict.getObjectBirthVersion()
            assert ver > 0
            assert maintver > 0
            did = defualt_dict.defaultId()
            assert did.isNull() == False
            cnt = 0
            for name, id in defualt_dict:
                cnt += 1
                assert name is not None
                assert id.isNull() == False
            assert cnt > 0
