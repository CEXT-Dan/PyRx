from __future__ import annotations

import math

import pytest

from pyrx import Ap, Ax, Ge
from tests import MEDIA_DIR


class TestAxRasterImage:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _add_raster(self):
        axSpace = self.axDoc.modelSpace()
        rasterPath = str(MEDIA_DIR / "rastertest.jpg")
        return axSpace.addRaster(rasterPath, Ge.Point3d.kOrigin, 1, 0)

    def test_addRaster(self):
        ent = self._add_raster()
        assert ent.objectName() == "AcDbRasterImage"
        assert ent.entityType() == Ax.AcEntityName.acRaster

    def test_className(self):
        assert Ax.AcadRasterImage.className() == "AcadRasterImage"

    def test_cast(self):
        ent = self._add_raster()
        casted = Ax.AcadRasterImage.cast(ent)
        assert casted is not None
        assert casted.objectName() == "AcDbRasterImage"

    def test_imageFile(self):
        ent = self._add_raster()
        assert isinstance(ent.imageFile(), str)
        assert "rastertest.jpg" in ent.imageFile()

    def test_imageWidth(self):
        ent = self._add_raster()
        assert isinstance(ent.imageWidth(), float)
        assert ent.imageWidth() > 0

    def test_imageHeight(self):
        ent = self._add_raster()
        assert isinstance(ent.imageHeight(), float)
        assert ent.imageHeight() > 0

    def test_width(self):
        ent = self._add_raster()
        assert isinstance(ent.width(), float)
        assert ent.width() > 0

    def test_height(self):
        ent = self._add_raster()
        assert isinstance(ent.height(), float)
        assert ent.height() > 0

    def test_setImageWidth(self):
        ent = self._add_raster()
        ent.setImageWidth(200.0)
        assert ent.imageWidth() == 200.0

    def test_setImageHeight(self):
        ent = self._add_raster()
        ent.setImageHeight(150.0)
        assert ent.imageHeight() == 150.0

    def test_origin(self):
        ent = self._add_raster()
        assert isinstance(ent.origin(), Ge.Point3d)
        new_origin = Ge.Point3d(5, 5, 0)
        ent.setOrigin(new_origin)
        assert ent.origin() == new_origin

    def test_rotation(self):
        ent = self._add_raster()
        assert isinstance(ent.rotation(), float)
        new_rotation = math.pi / 4
        ent.setRotation(new_rotation)
        assert ent.rotation() == new_rotation

    def test_scaleFactor(self):
        ent = self._add_raster()
        assert isinstance(ent.scaleFactor(), float)
        ent.setScaleFactor(2.0)
        assert ent.scaleFactor() == 2.0

    def test_brightness(self):
        ent = self._add_raster()
        assert isinstance(ent.brightness(), int)
        ent.setBrightness(75)
        assert ent.brightness() == 75

    def test_contrast(self):
        ent = self._add_raster()
        assert isinstance(ent.contrast(), int)
        ent.setContrast(75)
        assert ent.contrast() == 75

    def test_fade(self):
        ent = self._add_raster()
        assert isinstance(ent.fade(), int)
        ent.setFade(50)
        assert ent.fade() == 50

    def test_imageVisibility(self):
        ent = self._add_raster()
        assert isinstance(ent.imageVisibility(), bool)
        ent.setImageVisibility(False)
        assert ent.imageVisibility() is False
        ent.setImageVisibility(True)
        assert ent.imageVisibility() is True

    def test_name(self):
        ent = self._add_raster()
        assert isinstance(ent.name(), str)
        ent.setName("myraster")
        assert ent.name() == "myraster"

    def test_transparency(self):
        ent = self._add_raster()
        assert isinstance(ent.transparency(), bool)
        ent.setTransparency(True)
        assert ent.transparency() is True
        ent.setTransparency(False)
        assert ent.transparency() is False

    def test_showRotation(self):
        ent = self._add_raster()
        assert isinstance(ent.showRotation(), bool)
        ent.setShowRotation(True)
        assert ent.showRotation() is True
        ent.setShowRotation(False)
        assert ent.showRotation() is False

    def test_clippingEnabled(self):
        ent = self._add_raster()
        assert isinstance(ent.clippingEnabled(), bool)
        ent.setClippingEnabled(True)
        assert ent.clippingEnabled() is True
        ent.setClippingEnabled(False)
        assert ent.clippingEnabled() is False

    @pytest.mark.known_failure_ARX
    def test_clipBoundary(self):
        ent = self._add_raster()
        boundary = [
            Ge.Point2d(0, 0),
            Ge.Point2d(10, 0),
            Ge.Point2d(10, 10),
            Ge.Point2d(0, 10),
            Ge.Point2d(0, 0),
        ]
        ent.clipBoundary(boundary)
        assert ent.objectName() == "AcDbRasterImage"
