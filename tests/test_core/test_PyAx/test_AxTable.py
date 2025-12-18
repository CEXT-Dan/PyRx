from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge, Db


class TestAxTable:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()
        
    def test_create_table_settext(self):
        axModel = self.axDoc.modelSpace()
        axTable = axModel.addTable(Ge.Point3d(0, 0, 0), 7, 5, 1, 5)
        axTable.setText(0, 0, "woowhoo")
        assert axTable.text(0, 0) == "woowhoo"

    @pytest.mark.known_failure_GRX
    def test_create_table_setvalue(self):
        axModel = self.axDoc.modelSpace()
        axTable = axModel.addTable(Ge.Point3d(0, 0, 0), 7, 5, 1, 5)
        axTable.setValue(1,0,0,Db.AcValue(2.1))
        assert "2.1" in axTable.text(1, 0)
 
        
