from __future__ import annotations

import math

import pytest

from pyrx import Ap, Ax


class TestAxTextStyle:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _add_style(self, name: str) -> Ax.AcadTextStyle:
        return self.axDoc.textStyles().add(name)

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadTextStyle.className() == "AcadTextStyle"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadTextStyle()

    # --- name (read-only for text styles) ---

    def test_name(self):
        style = self._add_style("axts_name")
        assert isinstance(style.name(), str)
        assert style.name() == "axts_name"

    # --- object / class identity ---

    def test_objectName(self):
        style = self._add_style("axts_objname")
        assert style.objectName() == "AcDbTextStyleTableRecord"

    def test_isNull(self):
        style = self._add_style("axts_isnull")
        assert style.isNull() is False

    # --- height ---

    def test_height(self):
        style = self._add_style("axts_height")
        style.setHeight(2.5)
        assert style.height() == 2.5

    # --- width factor ---

    def test_width(self):
        style = self._add_style("axts_width")
        style.setWidth(1.5)
        assert style.width() == 1.5

    # --- oblique angle ---

    def test_obliqueAngle(self):
        style = self._add_style("axts_oblique")
        style.setObliqueAngle(math.radians(15.0))
        assert style.obliqueAngle() == math.radians(15.0)

    # --- last height ---

    def test_lastHeight(self):
        style = self._add_style("axts_lastheight")
        style.setLastHeight(3.0)
        assert style.lastHeight() == 3.0

    # --- font file ---

    def test_fontFile(self):
        style = self._add_style("axts_fontfile")
        assert isinstance(style.fontFile(), str)

    @pytest.mark.known_failure_ARX
    def test_setFontFile(self):
        style = self._add_style("axts_setfontfile")
        style.setFontFile("arial.ttf")
        assert style.fontFile() == "arial.ttf"
        # OBSERVED BUG: setFontFile("arial.ttf") raises
        #   RuntimeError: Exception!(unknown error, function PyIAcadTextStyleImpl::SetFontFile,
        #   Line 1737, File PyAcadDbObjectImpl.cpp
        # The getter (test_fontFile) works, but the setter throws an unknown ARX error.
        # Not clear which font file value is valid on the target machine.

    # --- big font file ---

    def test_bigFontFile(self):
        style = self._add_style("axts_bigfont")
        assert isinstance(style.bigFontFile(), str)

    # --- font (returns a tuple) ---

    def test_font(self):
        style = self._add_style("axts_font")
        assert isinstance(style.font(), tuple)

    # --- text generation flag ---

    def test_textGenerationFlag(self):
        style = self._add_style("axts_tgflag")
        style.setTextGenerationFlag(1)
        assert style.textGenerationFlag() == 1

    # --- cast ---

    def test_cast(self):
        style = self._add_style("axts_cast")
        casted = Ax.AcadTextStyle.cast(style)
        assert casted is not None
        assert casted.name() == "axts_cast"
        assert casted.objectName() == "AcDbTextStyleTableRecord"

    # --- document active text style ---

    def test_activeTextStyle(self):
        active = self.axDoc.activeTextStyle()
        assert active.objectName() == "AcDbTextStyleTableRecord"
        assert isinstance(active.name(), str)

    def test_setActiveTextStyle(self):
        original = self.axDoc.activeTextStyle()
        style = self._add_style("axts_active")
        self.axDoc.setActiveTextStyle(style)
        try:
            active = self.axDoc.activeTextStyle()
            assert active.name() == "axts_active"
        finally:
            self.axDoc.setActiveTextStyle(original)
