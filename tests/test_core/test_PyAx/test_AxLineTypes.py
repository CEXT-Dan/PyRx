from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxLineTypes:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _linetypes(self) -> Ax.AcadLineTypes:
        return self.axDoc.lineTypes()

    def test_className(self):
        assert Ax.AcadLineTypes.className() == "AcadLineTypes"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadLineTypes()

    def test_count(self):
        linetypes = self._linetypes()
        assert isinstance(linetypes.count(), int)
        # A drawing always contains at least the "ByLayer" and "ByBlock"
        # linetypes, so the count must be at least 2.
        assert linetypes.count() >= 2

    def test_add(self):
        linetypes = self._linetypes()
        count = linetypes.count()
        linetype = linetypes.add("axlinetypes_add")
        assert linetype.className() == "AcadLineType"
        assert linetype.name() == "axlinetypes_add"
        assert linetypes.count() == count + 1

    def test_add_existing_returns_existing(self):
        # Adding a name that already exists returns the existing linetype and
        # does not create a new one (count is unchanged).
        linetypes = self._linetypes()
        first = linetypes.add("axlinetypes_dup")
        assert first.name() == "axlinetypes_dup"
        count = linetypes.count()
        second = linetypes.add("axlinetypes_dup")
        assert second.name() == "axlinetypes_dup"
        assert linetypes.count() == count

    def test_item(self):
        # The collection is ordered by linetype name, not insertion order, so
        # verify the added linetype is reachable by some index rather than a
        # specific one.
        linetypes = self._linetypes()
        linetypes.add("axlinetypes_item")
        names = [linetypes.item(i).name() for i in range(linetypes.count())]
        assert "axlinetypes_item" in names

    def test_item_out_of_range(self):
        linetypes = self._linetypes()
        with pytest.raises(IndexError):
            linetypes.item(linetypes.count())

    def test_getitem(self):
        linetypes = self._linetypes()
        linetypes.add("axlinetypes_getitem")
        names = [linetypes[i].name() for i in range(linetypes.count())]
        assert "axlinetypes_getitem" in names

    def test_getitem_out_of_range(self):
        linetypes = self._linetypes()
        with pytest.raises(IndexError):
            linetypes[linetypes.count()]

    def test_items(self):
        linetypes = self._linetypes()
        items = linetypes.items()
        assert len(items) == linetypes.count()
        assert all(lt.className() == "AcadLineType" for lt in items)

    def test_iter(self):
        linetypes = self._linetypes()
        count = linetypes.count()
        names = [lt.name() for lt in linetypes]
        assert len(names) == count

    def test_cast(self):
        linetypes = self._linetypes()
        casted = Ax.AcadLineTypes.cast(linetypes)
        assert casted.count() == linetypes.count()
