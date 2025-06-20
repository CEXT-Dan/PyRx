from __future__ import annotations

from pyrx import Ap, Ge


class TestAxCircle:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_setCenter(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addCircle(Ge.Point3d(0, 0, 0), 5)
        assert ent.objectName() == "AcDbCircle"
        ent.setCenter(Ge.Point3d(1, 1, 1))
        assert ent.center() == Ge.Point3d(1, 1, 1)

    def test_setRadius(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addCircle(Ge.Point3d(0, 0, 0), 5)
        assert ent.objectName() == "AcDbCircle"
        ent.setRadius(6)
        assert ent.radius() == 6
