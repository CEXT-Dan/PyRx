from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxLayer:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _make_layer(self, name: str) -> Ax.AcadLayer:
        return self.axDoc.layers().add(name)

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadLayer.className() == "AcadLayer"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadLayer()

    # --- name ---

    def test_name(self):
        layer = self._make_layer("axlayer_name")
        assert layer.name() == "axlayer_name"

    def test_setName(self):
        layer = self._make_layer("axlayer_rename_old")
        layer.setName("axlayer_rename_new")
        assert layer.name() == "axlayer_rename_new"

    # --- description ---

    def test_setDescription(self):
        layer = self._make_layer("axlayer_desc")
        layer.setDescription("axlayer description")
        assert layer.description() == "axlayer description"

    # --- color ---

    def test_setColor(self):
        layer = self._make_layer("axlayer_color")
        layer.setColor(Ax.AcColor.acRed)
        assert layer.color() == Ax.AcColor.acRed

    def test_setTrueColor(self):
        layer = self._make_layer("axlayer_truecolor")
        axColor = Ax.AcadAcCmColor(255, 0, 0)
        layer.setTrueColor(axColor)
        tc = layer.trueColor()
        assert tc.red() == 255
        assert tc.green() == 0
        assert tc.blue() == 0

    # --- freeze ---

    def test_setFreeze(self):
        layer = self._make_layer("axlayer_freeze")
        layer.setFreeze(True)
        assert layer.freeze() is True
        layer.setFreeze(False)
        assert layer.freeze() is False

    # --- layerOn ---

    def test_setLayerOn(self):
        layer = self._make_layer("axlayer_on")
        layer.setLayerOn(False)
        assert layer.layerOn() is False
        layer.setLayerOn(True)
        assert layer.layerOn() is True

    # --- linetype ---

    def test_setLinetype(self):
        layer = self._make_layer("axlayer_linetype")
        layer.setLinetype("Continuous")
        assert layer.linetype() == "Continuous"

    # --- lineweight ---

    def test_setLineWeight(self):
        layer = self._make_layer("axlayer_lineweight")
        layer.setLineWeight(Ax.AcLineWeight.acLnWt070)
        assert layer.lineweight() == Ax.AcLineWeight.acLnWt070

    # --- lock ---

    def test_setLock(self):
        layer = self._make_layer("axlayer_lock")
        layer.setLock(True)
        assert layer.lock() is True
        layer.setLock(False)
        assert layer.lock() is False

    # --- material ---

    def test_setMaterial(self):
        layer = self._make_layer("axlayer_material")
        layer.setMaterial("ByLayer")
        assert layer.material() == "ByLayer"

    # --- plotStyleName ---

    def test_plotStyleName(self):
        layer = self._make_layer("axlayer_plotstyle")
        # The getter should return a non-empty string for a new layer.
        current = layer.plotStyleName()
        assert isinstance(current, str)
        assert current  # should not be empty

    @pytest.mark.known_failure_ARX
    def test_setPlotStyleName(self):
        # Fails with "unknown error" from put_PlotStyleName even when PSTYLEMODE = 1
        # and even when setting the value to the layer's own current plot style.
        layer = self._make_layer("axlayer_plotstyle")
        layer.setPlotStyleName("Normal")
        assert layer.plotStyleName() == "Normal"

    # --- plottable ---

    def test_setPlottable(self):
        layer = self._make_layer("axlayer_plottable")
        layer.setPlottable(False)
        assert layer.plottable() is False
        layer.setPlottable(True)
        assert layer.plottable() is True

    # --- viewportDefault ---

    def test_setViewportDefault(self):
        layer = self._make_layer("axlayer_vpdefault")
        layer.setViewportDefault(True)
        assert layer.viewportDefault() is True
        layer.setViewportDefault(False)
        assert layer.viewportDefault() is False

    # --- used ---

    def test_used(self):
        # A freshly created layer has no entities on it, so it is not used.
        layer = self._make_layer("axlayer_used")
        assert layer.used() is False

    # --- AcadObject inherited ---

    def test_isNull(self):
        layer = self._make_layer("axlayer_isnull")
        assert layer.isNull() is False

    # --- cast ---

    def test_cast(self):
        layer = self._make_layer("axlayer_cast")
        casted = Ax.AcadLayer.cast(layer)
        assert casted.name() == "axlayer_cast"
