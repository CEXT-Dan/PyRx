from __future__ import annotations

from pyrx import Ap, Ax, Db, Ge

# note AcadDictionaries can hold different types
# we need to check 
class TestAxDictionaries:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()
        
    def test_iter(self):
        _dicts = self.axDoc.dictionaries()
        names = set()
        for item in _dicts:
            if item.objectId().isDerivedFrom(Db.Dictionary.desc()):
                _dict = Ax.AcadDictionary.cast(item)
                names.add(_dict.name())
            elif item.objectId().isDerivedFrom(Db.Xrecord.desc()):
                _rec = Ax.AcadDictionary.cast(item)
                names.add(_rec.name())
        assert 'AcDbVariableDictionary' in names

    def test_add(self):
        _dicts = self.axDoc.dictionaries()
        _dict = _dicts.add("testdict")
        assert _dict.name() == "testdict"

    def test_count(self):
        _dicts = self.axDoc.dictionaries()
        count = _dicts.count()
        _dicts.add("testdict_count")
        assert _dicts.count() == count + 1

    def test_item(self):
        _dicts = self.axDoc.dictionaries()
        count = _dicts.count()
        _dict = _dicts.add("testdict_item")
        _item = Ax.AcadDictionary.cast(_dicts.item(count))
        assert _item.name() == "testdict_item"
        _nitem = Ax.AcadDictionary.cast(_dicts[count])
        assert _nitem.name() == "testdict_item"

    def test_items(self):
        _dicts = self.axDoc.dictionaries()
        items = _dicts.items()
        assert len(items) == _dicts.count()

    def test_className(self):
        assert Ax.AcadDictionaries.className() == "AcadDictionaries"

    def test_cast(self):
        _dicts = self.axDoc.dictionaries()
        _cast = Ax.AcadDictionaries.cast(_dicts)
        assert _cast.count() == _dicts.count()
