from __future__ import annotations

from pyrx import Ap, Ax, Ge


class TestAxMLine:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _make_mline(self):
        axSpace = self.axDoc.modelSpace()
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        return axSpace.addMLine(pnts)

    def test_create(self):
        ent = self._make_mline()
        assert ent.objectName() == "AcDbMline"
        assert ent.entityType() == Ax.AcEntityName.acMline

    def test_cast(self):
        ent = self._make_mline()
        casted = Ax.AcadMLine.cast(ent)
        assert casted is not None
        assert casted.objectName() == "AcDbMline"

    def test_className(self):
        assert Ax.AcadMLine.className() == "AcadMLine"

    def test_coordinates(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        ent = self.axDoc.modelSpace().addMLine(pnts)
        assert ent.coordinates() == pnts

    def test_setCoordinates(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        ent = self.axDoc.modelSpace().addMLine(pnts)
        new_pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(50, 0, 0),
            Ge.Point3d(50, 50, 0),
            Ge.Point3d(0, 50, 0),
        ]
        ent.setCoordinates(new_pnts)
        assert ent.coordinates() == new_pnts

    def test_justification(self):
        ent = self._make_mline()
        assert isinstance(ent.justification(), Ax.AcMLineJustification)

    def test_setJustification(self):
        ent = self._make_mline()
        ent.setJustification(Ax.AcMLineJustification.acBottom)
        assert ent.justification() == Ax.AcMLineJustification.acBottom

    def test_mlineScale(self):
        ent = self._make_mline()
        assert isinstance(ent.mlineScale(), float)
        assert ent.mlineScale() > 0.0

    def test_setMLineScale(self):
        ent = self._make_mline()
        ent.setMLineScale(2.0)
        assert ent.mlineScale() == 2.0

    def test_styleName(self):
        ent = self._make_mline()
        name = ent.styleName()
        assert isinstance(name, str)
        assert len(name) > 0
