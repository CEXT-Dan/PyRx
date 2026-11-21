from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxDimStyle:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _add_style(self, name: str) -> Ax.AcadDimStyle:
        return self.axDoc.dimStyles().add(name)

    def test_className(self):
        assert Ax.AcadDimStyle.className() == "AcadDimStyle"

    def test_objectName(self):
        style = self._add_style("axds_objname")
        assert style.objectName() == "AcDbDimStyleTableRecord"

    def test_name(self):
        style = self._add_style("axds_name")
        assert isinstance(style.name(), str)
        assert style.name() == "axds_name"

    def test_setName(self):
        style = self._add_style("axds_setname")
        style.setName("axds_setname2")
        assert style.name() == "axds_setname2"

    def test_cast(self):
        style = self._add_style("axds_cast")
        casted = Ax.AcadDimStyle.cast(style)
        assert casted is not None
        assert casted.name() == "axds_cast"
        assert casted.objectName() == "AcDbDimStyleTableRecord"

    def test_copyFrom(self):
        src = self._add_style("axds_copy_src")
        dst = self._add_style("axds_copy_dst")
        dst.copyFrom(src)
        assert dst.name() == "axds_copy_dst"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadDimStyle()

    def test_activeDimStyle(self):
        active = self.axDoc.activeDimStyle()
        assert active.objectName() == "AcDbDimStyleTableRecord"
        assert isinstance(active.name(), str)
