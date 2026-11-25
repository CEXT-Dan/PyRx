from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxUCSs:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _ucs(self) -> Ax.AcadUCSs:
        return self.axDoc.userCoordinateSystems()

    def _add(self, name: str) -> Ax.AcadUCS:
        return self._ucs().add(
            Ge.Point3d(0, 0, 0),
            Ge.Vector3d.kXAxis,
            Ge.Vector3d.kYAxis,
            name,
        )

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadUCSs.className() == "AcadUCSs"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadUCSs()

    # --- count ---

    def test_count(self):
        assert self._ucs().count() >= 0

    # --- add ---

    def test_add(self):
        ucs = self._ucs()
        count = ucs.count()
        new_ucs = self._add("axucs_add")
        assert new_ucs.className() == "AcadUCS"
        assert new_ucs.name() == "axucs_add"
        assert ucs.count() == count + 1

    def test_add_existing_returns_existing(self):
        ucs = self._ucs()
        first = self._add("axucs_dup")
        assert first.name() == "axucs_dup"
        count = ucs.count()
        second = self._add("axucs_dup")
        assert second.name() == "axucs_dup"
        assert ucs.count() == count

    # --- item / __getitem__ ---

    def test_item(self):
        ucs = self._ucs()
        self._add("axucs_item")
        names = [ucs.item(i).name() for i in range(ucs.count())]
        assert "axucs_item" in names

    def test_item_out_of_range(self):
        ucs = self._ucs()
        with pytest.raises(IndexError):
            ucs.item(ucs.count())

    def test_getitem(self):
        ucs = self._ucs()
        self._add("axucs_getitem")
        names = [ucs[i].name() for i in range(ucs.count())]
        assert "axucs_getitem" in names

    def test_getitem_out_of_range(self):
        ucs = self._ucs()
        with pytest.raises(IndexError):
            ucs[ucs.count()]

    # --- items / __iter__ ---

    def test_items(self):
        ucs = self._ucs()
        items = ucs.items()
        assert len(items) == ucs.count()
        assert all(u.className() == "AcadUCS" for u in items)

    def test_iter(self):
        ucs = self._ucs()
        count = ucs.count()
        names = [u.name() for u in ucs]
        assert len(names) == count

    # --- cast ---

    def test_cast(self):
        ucs = self._ucs()
        casted = Ax.AcadUCSs.cast(ucs)
        assert casted.count() == ucs.count()
