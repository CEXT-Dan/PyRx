from __future__ import annotations

from pyrx import Ap, Ge


class TestAxPoint:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_coordinates(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addPoint(Ge.Point3d(1,1,1))
        assert ent.objectName() == "AcDbPoint"
        assert ent.coordinates() == Ge.Point3d(1,1,1)
        ent.setCoordinates(Ge.Point3d(5,5,5))
        assert ent.coordinates() == Ge.Point3d(5,5,5)
        


