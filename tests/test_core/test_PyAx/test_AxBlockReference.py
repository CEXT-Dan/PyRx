from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Db


class TestAxBlockReference:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_getDynamic(self, db_06457: Db.Database):
        axDb = db_06457.acadDatabase()
        axSpace = axDb.modelSpace()
        num = 0
        ent: Ax.AcadEntity
        for ent in axSpace:
            if ent.objectName() != "AcDbBlockReference":
                continue
            ref = Ax.AcadBlockReference.cast(ent)
            if ref.isDynamicBlock():
                num += 1
        assert num != 0

    def test_getAttributes(self, db_06457: Db.Database):
        axDb = db_06457.acadDatabase()
        axSpace = axDb.modelSpace()
        num = 0
        ent: Ax.AcadEntity
        for ent in axSpace:
            if ent.objectName() != "AcDbBlockReference":
                continue
            ref = Ax.AcadBlockReference.cast(ent)
            if ref.hasAttributes():
                att: Ax.AcadAttributeReference
                for att in ref.attributes():
                    att.textString()
                    num += 1
        assert num != 0


class TestAxDynBlockReference:
    
    @pytest.mark.known_failure_GRX
    def test_allowed_values(self, db_dynblock: Db.Database):
        objHnd = Db.Handle("70c")
        objId = db_dynblock.getObjectId(False, objHnd)
        assert objId.isValid() is True
        axDyn = Ax.AcadBlockReference.cast(objId.acadObject())
        assert axDyn.objectName() == "AcDbBlockReference"
        assert axDyn.isDynamicBlock() == True
        actual = [
            Db.EvalVariant("Limit Switch NO"),
            Db.EvalVariant("Limit Switch Held Closed"),
            Db.EvalVariant("Limit Switch NC"),
            Db.EvalVariant("Limit Switch Held Open"),
        ]
        result = []
        for prop in axDyn.dynamicBlockProperties():
            result.extend(prop.allowedValues())
        assert result == actual
        
    def test_set_value(self, db_dynblock: Db.Database):
        objHnd = Db.Handle("70c")
        objId = db_dynblock.getObjectId(False, objHnd)
        assert objId.isValid() is True
        axDyn = Ax.AcadBlockReference.cast(objId.acadObject())
        assert axDyn.objectName() == "AcDbBlockReference"
        assert axDyn.isDynamicBlock() == True
        actual = [
            Db.EvalVariant("Limit Switch NO"),
            Db.EvalVariant("Limit Switch Held Closed"),
            Db.EvalVariant("Limit Switch NC"),
            Db.EvalVariant("Limit Switch Held Open"),
        ]
        prop : Ax.AcadDynamicBlockReferenceProperty = axDyn.dynamicBlockProperties()[0]
        for item in actual:
            prop.setValue(item)
            assert prop.value() == item
        

        