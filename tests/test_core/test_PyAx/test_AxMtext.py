from __future__ import annotations

from pyrx import Ap, Ge


class TestAxMText:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_setMtext(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addMText(Ge.Point3d(0, 0, 0), 1, "MTEXT")
        assert ent.objectName() == "AcDbMText"
        assert ent.textString() == "MTEXT"

    def test_strip_mtcode(self):
        axSpace = self.axDoc.modelSpace()
        tstr = r"\A1;{\fAIGDT|b0|i0;m}\H2.5000;80"
        ent = axSpace.addMText(Ge.Point3d(0, 0, 0), 1, tstr)
        assert ent.objectName() == "AcDbMText"
        assert ent.textString() == tstr
        assert ent.text() == "m80"
