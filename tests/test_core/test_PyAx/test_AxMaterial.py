from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxMaterial:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _make_material(self, name: str) -> Ax.AcadMaterial:
        return self.axDoc.materials().add(name)

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadMaterial.className() == "AcadMaterial"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadMaterial()

    # --- name ---

    def test_name(self):
        material = self._make_material("axmaterial_name")
        assert material.name() == "axmaterial_name"

    def test_setName(self):
        material = self._make_material("axmaterial_rename_old")
        material.setName("axmaterial_rename_new")
        assert material.name() == "axmaterial_rename_new"

    # --- description ---

    def test_description(self):
        material = self._make_material("axmaterial_desc")
        # A freshly created material should report a string description.
        assert isinstance(material.description(), str)

    def test_setDescription(self):
        material = self._make_material("axmaterial_setdesc")
        material.setDescription("axmaterial description")
        assert material.description() == "axmaterial description"

    # --- AcadObject inherited ---

    def test_isNull(self):
        material = self._make_material("axmaterial_isnull")
        assert material.isNull() is False

    # --- cast ---

    def test_cast(self):
        material = self._make_material("axmaterial_cast")
        casted = Ax.AcadMaterial.cast(material)
        assert casted.name() == "axmaterial_cast"
