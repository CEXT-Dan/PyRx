from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge
from tests import MEDIA_DIR


class TestAxExternalReference:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()
        self.xrefPath = str(MEDIA_DIR / "18X36RP.dwg")

    def _attach(self, name, pnt=None, scale=None, rotation=0.0):
        axSpace = self.axDoc.modelSpace()
        if pnt is None:
            pnt = Ge.Point3d(0, 0, 0)
        if scale is None:
            scale = Ge.Scale3d(1, 1, 1)
        return axSpace.attachExternalReference(
            self.xrefPath, name, pnt, scale, rotation, True
        )

    def test_attach_type(self):
        xref = self._attach("xref_type")
        assert isinstance(xref, Ax.AcadExternalReference)
        assert xref.objectName() == "AcDbBlockReference"
        assert xref.entityType() == Ax.AcEntityName.acBlockReference

    def test_path(self):
        xref = self._attach("xref_path")
        assert "18X36RP.dwg" in xref.path()

    def test_name(self):
        xref = self._attach("xref_name")
        assert xref.name() == "xref_name"

    def test_effectiveName(self):
        xref = self._attach("xref_effective")
        assert xref.effectiveName() == "xref_effective"

    def test_insertionPoint(self):
        pnt = Ge.Point3d(10, 20, 0)
        xref = self._attach("xref_ip", pnt=pnt)
        assert xref.insertionPoint() == pnt

    def test_rotation(self):
        xref = self._attach("xref_rot", rotation=1.0)
        assert xref.rotation() == 1.0

    @pytest.mark.known_failure_ARX
    def test_scaleFactors(self):
        xref = self._attach("xref_scale", scale=Ge.Scale3d(2.0))
        assert xref.xScaleFactor() == 2.0
        assert xref.yScaleFactor() == 2.0
        assert xref.zScaleFactor() == 2.0

    def test_setRotation(self):
        xref = self._attach("xref_setrot")
        xref.setRotation(2.0)
        assert xref.rotation() == 2.0

    def test_setInsertionPoint(self):
        xref = self._attach("xref_setip")
        pnt = Ge.Point3d(5, 6, 7)
        xref.setInsertionPoint(pnt)
        assert xref.insertionPoint() == pnt

    def test_setXScaleFactor(self):
        xref = self._attach("xref_setscale")
        xref.setXScaleFactor(3.0)
        assert xref.xScaleFactor() == 3.0

    def test_cast(self):
        xref = self._attach("xref_cast")
        casted = Ax.AcadExternalReference.cast(xref)
        assert isinstance(casted, Ax.AcadExternalReference)
        assert casted.path() == xref.path()

    def test_className(self):
        assert Ax.AcadExternalReference.className() == "AcadExternalReference"

    @pytest.mark.known_failure_ARX
    def test_layerPropertyOverrides(self):
        xref = self._attach("xref_layerprops")
        assert isinstance(xref.layerPropertyOverrides("0"), bool)

    def test_setPath(self):
        xref = self._attach("xref_setpath")
        xref.setPath(self.xrefPath)
        assert "18X36RP.dwg" in xref.path()
