from __future__ import annotations

from pyrx import Ap, Ax, Ge


class TestAxAttribute:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_setMtext(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addAttribute(
            1,
            Ax.AcAttributeMode.acAttributeModeNormal,
            "prompt",
            Ge.Point3d(0, 0, 0),
            "tag","value"
        )
        assert ent.objectName() == "AcDbAttributeDefinition"
        assert ent.isMTextAttribute() == False
        ent.setIsMTextAttribute(True)
        assert ent.isMTextAttribute() == True


