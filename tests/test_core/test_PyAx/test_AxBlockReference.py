from __future__ import annotations
from pyrx import Ap, Ge, Ax, Db


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
