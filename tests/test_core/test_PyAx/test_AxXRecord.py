from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxXRecord:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _make_xrec(self, name: str) -> Ax.AcadXRecord:
        _dict = self.axDoc.dictionaries().add(f"testdict_{name}")
        return _dict.addXRecord(name)

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadXRecord.className() == "AcadXRecord"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadXRecord()

    def test_cast(self):
        _dict = self.axDoc.dictionaries().add("testdict_xrec_cast")
        _dict.addXRecord("axxrec_cast_key")
        obj = _dict.object("axxrec_cast_key")
        casted = Ax.AcadXRecord.cast(obj)
        assert casted.name() == "axxrec_cast_key"
        assert casted.objectName() == "AcDbXrecord"

    # --- name ---

    def test_name(self):
        xrec = self._make_xrec("axxrec_name")
        assert xrec.name() == "axxrec_name"

    def test_setName(self):
        xrec = self._make_xrec("axxrec_rename_old")
        xrec.setName("axxrec_rename_new")
        assert xrec.name() == "axxrec_rename_new"

    # --- object identity ---

    def test_objectName(self):
        xrec = self._make_xrec("axxrec_objname")
        assert xrec.objectName() == "AcDbXrecord"

    def test_objectId(self):
        xrec = self._make_xrec("axxrec_objid")
        assert xrec.objectId().isNull() is False

    def test_isNull(self):
        xrec = self._make_xrec("axxrec_isnull")
        assert xrec.isNull() is False

    def test_handle(self):
        xrec = self._make_xrec("axxrec_handle")
        handle = xrec.handle()
        assert handle is not None
        assert len(handle.toString()) > 0

    def test_database(self):
        xrec = self._make_xrec("axxrec_database")
        assert xrec.database().className() == "AcadDatabase"

    # --- xrecordData ---
    def test_xrecordData_empty(self):
        xrec = self._make_xrec("axxrec_data_empty")
        data = xrec.xrecordData()
        assert isinstance(data, list)
        assert len(data) == 0

    def test_setXRecordData_text(self):
        xrec = self._make_xrec("axxrec_data_text")
        data = [(1, "hello"), (2, "world")]
        xrec.setXRecordData(data)
        assert xrec.xrecordData() == data

    def test_setXRecordData_real(self):
        xrec = self._make_xrec("axxrec_data_real")
        data = [(40, 1.234), (41, 12345.678)]
        xrec.setXRecordData(data)
        assert xrec.xrecordData() == data

    def test_setXRecordData_int(self):
        xrec = self._make_xrec("axxrec_data_int")
        data = [(70, 32767), (90, 123456789)]
        xrec.setXRecordData(data)
        assert xrec.xrecordData() == data

    def test_setXRecordData_point3d(self):
        xrec = self._make_xrec("axxrec_data_point")
        data = [(10, Ge.Point3d(1.0, 2.0, 3.0))]
        xrec.setXRecordData(data)
        assert xrec.xrecordData() == data

    def test_setXRecordData_mixed(self):
        xrec = self._make_xrec("axxrec_data_mixed")
        data = [
            (1, "text_value"),
            (40, 3.14159),
            (70, 42),
            (10, Ge.Point3d(4.0, 5.0, 6.0)),
            (300, "long_string_value"),
        ]
        xrec.setXRecordData(data)
        assert xrec.xrecordData() == data

    def test_setXRecordData_overwrite(self):
        xrec = self._make_xrec("axxrec_data_overwrite")
        data1 = [(1, "first"), (40, 1.111)]
        xrec.setXRecordData(data1)
        assert xrec.xrecordData() == data1

        data2 = [(2, "second"), (70, 99)]
        xrec.setXRecordData(data2)
        assert xrec.xrecordData() == data2

    # --- translateIDs ---

    def test_translateIDs_default(self):
        xrec = self._make_xrec("axxrec_xlate_default")
        assert isinstance(xrec.translateIDs(), bool)

    def test_setTranslateIDs_true(self):
        xrec = self._make_xrec("axxrec_xlate_true")
        xrec.setTranslateIDs(True)
        assert xrec.translateIDs() is True

    def test_setTranslateIDs_false(self):
        xrec = self._make_xrec("axxrec_xlate_false")
        xrec.setTranslateIDs(False)
        assert xrec.translateIDs() is False
