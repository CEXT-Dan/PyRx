from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxPlotConfiguration:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _add_config(self, name: str) -> Ax.AcadPlotConfiguration:
        return self.axDoc.plotConfigurations().add(name)

    def _find_config(self, name: str) -> Ax.AcadPlotConfiguration:
        configs = self.axDoc.plotConfigurations()
        for i in range(configs.count()):
            if configs.item(i).name() == name:
                return configs.item(i)
        raise LookupError(f"config {name!r} not found")

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadPlotConfiguration.className() == "AcadPlotConfiguration"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadPlotConfiguration()

    def test_cast(self):
        config = self._add_config("axplotconfig_cast")
        casted = Ax.AcadPlotConfiguration.cast(config)
        assert casted.name() == "axplotconfig_cast"

    # --- name / setName ---

    def test_name(self):
        config = self._add_config("axplotconfig_name")
        assert config.name() == "axplotconfig_name"

    def test_setName(self):
        config = self._add_config("axplotconfig_rename_old")
        config.setName("axplotconfig_rename_new")
        assert config.name() == "axplotconfig_rename_new"

    # --- configName / setConfigName ---

    def test_configName(self):
        config = self._add_config("axplotconfig_configname")
        assert isinstance(config.configName(), str)

    # --- modelType ---

    def test_modelType(self):
        config = self._add_config("axplotconfig_modeltype")
        assert isinstance(config.modelType(), bool)

    # --- centerPlot / setCenterPlot ---

    def test_centerPlot(self):
        config = self._add_config("axplotconfig_centerplot")
        assert isinstance(config.centerPlot(), bool)

    # --- customScale / setCustomScale ---

    def test_customScale(self):
        config = self._add_config("axplotconfig_customscale")
        scale = config.customScale()
        assert len(scale) == 2
        assert isinstance(scale[0], float)
        assert isinstance(scale[1], float)

    def test_setCustomScale(self):
        config = self._add_config("axplotconfig_setcustomscale")
        config.setCustomScale(1.0, 100.0)
        scale = config.customScale()
        assert scale[0] == 1.0
        assert scale[1] == 100.0

    # --- paperSize ---

    def test_paperSize(self):
        config = self._add_config("axplotconfig_papersize")
        size = config.paperSize()
        assert len(size) == 2
        assert isinstance(size[0], float)
        assert isinstance(size[1], float)

    # --- paperMargins ---

    def test_paperMargins(self):
        config = self._add_config("axplotconfig_papermargins")
        margins = config.paperMargins()
        assert len(margins) == 2

    # --- paperUnits / setPaperUnits ---

    def test_paperUnits(self):
        config = self._add_config("axplotconfig_paperunits")
        units = config.paperUnits()
        assert units in (
            Ax.AcPlotPaperUnits.acInches,
            Ax.AcPlotPaperUnits.acMillimeters,
            Ax.AcPlotPaperUnits.acPixels,
        )

    def test_setPaperUnits(self):
        config = self._add_config("axplotconfig_setpaperunits")
        config.setPaperUnits(Ax.AcPlotPaperUnits.acInches)
        assert config.paperUnits() == Ax.AcPlotPaperUnits.acInches

    # --- plotHidden / setPlotHidden ---

    def test_plotHidden(self):
        config = self._add_config("axplotconfig_plothidden")
        assert isinstance(config.plotHidden(), bool)

    def test_setPlotHidden(self):
        config = self._add_config("axplotconfig_setplothidden")
        config.setPlotHidden(True)
        assert config.plotHidden() is True
        config.setPlotHidden(False)
        assert config.plotHidden() is False

    # --- plotOrigin / setPlotOrigin ---

    def test_plotOrigin(self):
        config = self._add_config("axplotconfig_plotorigin")
        origin = config.plotOrigin()
        assert origin is not None

    # --- plotRotation / setPlotRotation ---

    def test_plotRotation(self):
        config = self._add_config("axplotconfig_plotrotation")
        rotation = config.plotRotation()
        assert rotation in (
            Ax.AcPlotRotation.ac0degrees,
            Ax.AcPlotRotation.ac90degrees,
            Ax.AcPlotRotation.ac180degrees,
            Ax.AcPlotRotation.ac270degrees,
        )

    def test_setPlotRotation(self):
        config = self._add_config("axplotconfig_setplotrotation")
        config.setPlotRotation(Ax.AcPlotRotation.ac90degrees)
        assert config.plotRotation() == Ax.AcPlotRotation.ac90degrees

    # --- plotType / setPlotType ---

    def test_plotType(self):
        config = self._add_config("axplotconfig_plottype")
        plot_type = config.plotType()
        assert plot_type in (
            Ax.AcPlotType.acDisplay,
            Ax.AcPlotType.acExtents,
            Ax.AcPlotType.acLimits,
            Ax.AcPlotType.acView,
            Ax.AcPlotType.acWindow,
            Ax.AcPlotType.acLayout,
        )

    def test_setPlotType(self):
        config = self._add_config("axplotconfig_setplottype")
        config.setPlotType(Ax.AcPlotType.acExtents)
        assert config.plotType() == Ax.AcPlotType.acExtents

    # --- plotViewportBorders / setPlotViewportBorders ---

    def test_plotViewportBorders(self):
        config = self._add_config("axplotconfig_plotvpborders")
        assert isinstance(config.plotViewportBorders(), bool)

    def test_setPlotViewportBorders(self):
        config = self._add_config("axplotconfig_setplotvpborders")
        config.setPlotViewportBorders(True)
        assert config.plotViewportBorders() is True
        config.setPlotViewportBorders(False)
        assert config.plotViewportBorders() is False

    # --- plotViewportsFirst / setPlotViewportsFirst ---

    def test_plotViewportsFirst(self):
        config = self._add_config("axplotconfig_plotvpfirst")
        assert isinstance(config.plotViewportsFirst(), bool)

    def test_setPlotViewportsFirst(self):
        config = self._add_config("axplotconfig_setplotvpfirst")
        config.setPlotViewportsFirst(True)
        assert config.plotViewportsFirst() is True
        config.setPlotViewportsFirst(False)
        assert config.plotViewportsFirst() is False

    # --- plotWithLineweights / setPlotWithLineweights ---

    def test_plotWithLineweights(self):
        config = self._add_config("axplotconfig_plotlw")
        assert isinstance(config.plotWithLineweights(), bool)

    def test_setPlotWithLineweights(self):
        config = self._add_config("axplotconfig_setplotlw")
        config.setPlotWithLineweights(True)
        assert config.plotWithLineweights() is True
        config.setPlotWithLineweights(False)
        assert config.plotWithLineweights() is False

    # --- plotWithPlotStyles / setPlotWithPlotStyles ---

    def test_plotWithPlotStyles(self):
        config = self._add_config("axplotconfig_plotps")
        assert isinstance(config.plotWithPlotStyles(), bool)

    def test_setPlotWithPlotStyles(self):
        config = self._add_config("axplotconfig_setplotps")
        config.setPlotWithPlotStyles(True)
        assert config.plotWithPlotStyles() is True
        config.setPlotWithPlotStyles(False)
        assert config.plotWithPlotStyles() is False

    # --- scaleLineweights / setScaleLineweights ---

    def test_scaleLineweights(self):
        config = self._add_config("axplotconfig_scalerlw")
        assert isinstance(config.scaleLineweights(), bool)

    def test_setScaleLineweights(self):
        config = self._add_config("axplotconfig_setscalerlw")
        config.setScaleLineweights(True)
        assert config.scaleLineweights() is True
        config.setScaleLineweights(False)
        assert config.scaleLineweights() is False

    # --- showPlotStyles / setShowPlotStyles ---

    def test_showPlotStyles(self):
        config = self._add_config("axplotconfig_showps")
        assert isinstance(config.showPlotStyles(), bool)

    def test_setShowPlotStyles(self):
        config = self._add_config("axplotconfig_setshowps")
        config.setShowPlotStyles(True)
        assert config.showPlotStyles() is True
        config.setShowPlotStyles(False)
        assert config.showPlotStyles() is False

    # --- standardScale / setStandardScale ---

    def test_standardScale(self):
        config = self._add_config("axplotconfig_stdscale")
        scale = config.standardScale()
        assert isinstance(int(scale), int)

    def test_setStandardScale(self):
        config = self._add_config("axplotconfig_setstdscale")
        config.setStandardScale(Ax.AcPlotScale.acScaleToFit)
        assert config.standardScale() == Ax.AcPlotScale.acScaleToFit

    # --- useStandardScale / setUseStandardScale ---

    def test_useStandardScale(self):
        config = self._add_config("axplotconfig_usestdscale")
        assert isinstance(config.useStandardScale(), bool)

    def test_setUseStandardScale(self):
        config = self._add_config("axplotconfig_setusestdscale")
        config.setUseStandardScale(True)
        assert config.useStandardScale() is True
        config.setUseStandardScale(False)
        assert config.useStandardScale() is False

    # --- styleSheet ---

    def test_styleSheet(self):
        config = self._add_config("axplotconfig_stylesheet")
        assert isinstance(config.styleSheet(), str)

    # --- canonicalMediaName ---

    def test_canonicalMediaName(self):
        config = self._add_config("axplotconfig_canonicalmedia")
        name = config.canonicalMediaName()
        assert isinstance(name, str)

    # --- canonicalMediaNames ---

    def test_canonicalMediaNames(self):
        config = self._add_config("axplotconfig_canonicalmedianns")
        names = config.canonicalMediaNames()
        assert isinstance(names, list)
        assert all(isinstance(n, str) for n in names)

    # --- plotDeviceNames ---

    def test_plotDeviceNames(self):
        config = self._add_config("axplotconfig_plotdevices")
        names = config.plotDeviceNames()
        assert isinstance(names, list)
        assert all(isinstance(n, str) for n in names)

    # --- plotStyleTableNames ---

    def test_plotStyleTableNames(self):
        config = self._add_config("axplotconfig_plotstyletables")
        names = config.plotStyleTableNames()
        assert isinstance(names, list)
        assert all(isinstance(n, str) for n in names)

    # --- viewToPlot ---

    def test_viewToPlot(self):
        config = self._add_config("axplotconfig_viewtoplot")
        assert isinstance(config.viewToPlot(), str)

    # --- windowToPlot / setWindowToPlot ---

    def test_windowToPlot(self):
        config = self._add_config("axplotconfig_windowtoplot")
        window = config.windowToPlot()
        assert len(window) == 2

    def test_setWindowToPlot(self):
        config = self._add_config("axplotconfig_setwindowtoplot")
        config.setWindowToPlot(Ge.Point2d(0, 0), Ge.Point2d(100, 100))
        window = config.windowToPlot()
        assert len(window) == 2

    # --- copyFrom ---

    def test_copyFrom(self):
        src = self._add_config("axplotconfig_copyfrom_src")
        dst = self._add_config("axplotconfig_copyfrom_dst")
        src.setPlotHidden(True)
        dst.copyFrom(src)
        assert dst.plotHidden() is True

    # --- refreshPlotDeviceInfo ---

    def test_refreshPlotDeviceInfo(self):
        config = self._add_config("axplotconfig_refresh")
        config.refreshPlotDeviceInfo()

    # --- localeMediaName ---

    def test_localeMediaName(self):
        config = self._add_config("axplotconfig_localemedia")
        names = config.canonicalMediaNames()
        if names:
            result = config.localeMediaName(names[0])
            assert isinstance(result, str)

    # --- inherited AcadObject identity ---

    def test_isNull(self):
        config = self._add_config("axplotconfig_isnull")
        assert config.isNull() is False

    def test_objectId(self):
        config = self._add_config("axplotconfig_objectid")
        assert config.objectId().isNull() is False

    def test_handle(self):
        config = self._add_config("axplotconfig_handle")
        handle = config.handle()
        assert handle is not None
        assert len(handle.toString()) > 0

    def test_database(self):
        config = self._add_config("axplotconfig_database")
        assert config.database().className() == "AcadDatabase"

    def test_objectName(self):
        config = self._add_config("axplotconfig_objectname")
        assert isinstance(config.objectName(), str)
        assert len(config.objectName()) > 0
