from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxMaterials:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _materials(self) -> Ax.AcadMaterials:
        return self.axDoc.materials()

    def test_className(self):
        assert Ax.AcadMaterials.className() == "AcadMaterials"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadMaterials()

    def test_count(self):
        materials = self._materials()
        assert isinstance(materials.count(), int)
        # A drawing always contains at least the "ByBlock" and "ByLayer"
        # materials, so the count must be at least 2.
        assert materials.count() >= 2

    def test_add(self):
        materials = self._materials()
        count = materials.count()
        material = materials.add("axmaterials_add")
        assert material.className() == "AcadMaterial"
        assert material.name() == "axmaterials_add"
        assert materials.count() == count + 1

    def test_add_existing_returns_existing(self):
        # Adding a name that already exists returns the existing material and
        # does not create a new one (count is unchanged).
        materials = self._materials()
        first = materials.add("axmaterials_dup")
        assert first.name() == "axmaterials_dup"
        count = materials.count()
        second = materials.add("axmaterials_dup")
        assert second.name() == "axmaterials_dup"
        assert materials.count() == count

    def test_item(self):
        # The collection is ordered by material name, not insertion order, so
        # verify the added material is reachable by some index rather than a
        # specific one.
        materials = self._materials()
        materials.add("axmaterials_item")
        names = [materials.item(i).name() for i in range(materials.count())]
        assert "axmaterials_item" in names

    def test_item_out_of_range(self):
        materials = self._materials()
        with pytest.raises(IndexError):
            materials.item(materials.count())

    def test_getitem(self):
        materials = self._materials()
        materials.add("axmaterials_getitem")
        names = [materials[i].name() for i in range(materials.count())]
        assert "axmaterials_getitem" in names

    def test_getitem_out_of_range(self):
        materials = self._materials()
        with pytest.raises(IndexError):
            materials[materials.count()]

    def test_items(self):
        materials = self._materials()
        items = materials.items()
        assert len(items) == materials.count()
        assert all(m.className() == "AcadMaterial" for m in items)

    def test_iter(self):
        materials = self._materials()
        count = materials.count()
        names = [m.name() for m in materials]
        assert len(names) == count

    def test_cast(self):
        materials = self._materials()
        casted = Ax.AcadMaterials.cast(materials)
        assert casted.count() == materials.count()
