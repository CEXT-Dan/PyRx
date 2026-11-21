from __future__ import annotations

from pyrx import Ap, Ax


class TestAxDictionary:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()
    
    def test_dict_name(self):
        _dict = self.axDoc.dictionaries().add("testdict_name")
        assert _dict.name() == "testdict_name"

    def test_dict_className(self):
        assert Ax.AcadDictionary.className() == "AcadDictionary"

    def test_dict_count(self):
        _dict = self.axDoc.dictionaries().add("testdict_dcount")
        count = _dict.count()
        _dict.addXRecord("KEY1")
        assert _dict.count() == count + 1

    def test_dict_addXRecord(self):
        _dict = self.axDoc.dictionaries().add("testdict_xrec")
        xrec = _dict.addXRecord("MYKEY")
        assert xrec.name() == "MYKEY"
        assert xrec.objectName() == "AcDbXrecord"

    def test_dict_addObject(self):
        pass
        
    def test_dict_setName(self):
        _dict = self.axDoc.dictionaries().add("testdict_setname")
        _dict.setName("testdict_setname_new")
        assert _dict.name() == "testdict_setname_new"

    def test_dict_objName(self):
        _dict = self.axDoc.dictionaries().add("testdict_objname")
        xrec = _dict.addXRecord("MYKEY")
        assert _dict.objName(xrec) == "MYKEY"

    def test_dict_object(self):
        _dict = self.axDoc.dictionaries().add("testdict_obj")
        _dict.addXRecord("MYKEY")
        obj = _dict.object("MYKEY")
        assert Ax.AcadXRecord.cast(obj).name() == "MYKEY"

    def test_dict_item(self):
        _dict = self.axDoc.dictionaries().add("testdict_item")
        xrec = _dict.addXRecord("MYKEY")
        _item = Ax.AcadXRecord.cast(_dict.item(0))
        assert _item.objectId() == xrec.objectId()

    def test_dict_items(self):
        _dict = self.axDoc.dictionaries().add("testdict_items")
        _dict.addXRecord("KEY1")
        _dict.addXRecord("KEY2")
        items = _dict.items()
        assert len(items) == 2

    def test_dict_rename(self):
        _dict = self.axDoc.dictionaries().add("testdict_rename")
        _dict.addXRecord("OLDKEY")
        _dict.rename("OLDKEY", "NEWKEY")
        obj = _dict.object("NEWKEY")
        assert Ax.AcadXRecord.cast(obj).name() == "NEWKEY"

    def test_dict_replace(self):
        _dict = self.axDoc.dictionaries().add("testdict_replace")
        _dict.addXRecord("KEY1")
        xrec2 = _dict.addXRecord("KEY2")
        _dict.replace("KEY1", xrec2)
        obj = _dict.object("KEY1")
        assert obj.objectId() == xrec2.objectId()

    def test_dict_remove(self):
        _dict = self.axDoc.dictionaries().add("testdict_remove")
        _dict.addXRecord("MYKEY")
        count = _dict.count()
        _dict.remove("MYKEY")
        assert _dict.count() == count - 1

    def test_dict_cast(self):
        _dict = self.axDoc.dictionaries().add("testdict_cast")
        _cast = Ax.AcadDictionary.cast(_dict)
        assert _cast.name() == _dict.name()
