from __future__ import annotations

from pyrx import Ap, Ge


class TestAxEllipse:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_setCenter(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addEllipse(Ge.Point3d(5, 5, 0), Ge.Vector3d(10, 20, 0), 0.3)
        assert ent.objectName() == "AcDbEllipse"
        ent.setCenter(Ge.Point3d(0, 0, 0))
        assert ent.center() == Ge.Point3d(0, 0, 0)
        
    def test_set_offset(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addEllipse(Ge.Point3d(5, 5, 0), Ge.Vector3d(10, 20, 0), 0.3)
        assert ent.objectName() == "AcDbEllipse"
        assert len(ent.offset(1)) != 0



