from __future__ import annotations

from pyrx import Ap, Ax, Ge, Db


class TestAxTable:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_create_table(self):
        axModel = self.axDoc.modelSpace()
        axTable = axModel.addTable(Ge.Point3d(0, 0, 0), 7, 5, 1, 5)
        axTable.setText(0, 0, "woowhoo")
        axTable.setValue(1,0,0,Db.AcValue(2.1))
        
        assert axTable.text(0, 0) == "woowhoo"
        assert "2.1" in axTable.text(1, 0)
 
        
