from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxGroups:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _groups(self) -> Ax.AcadGroups:
        return self.axDoc.groups()

    def test_className(self):
        assert Ax.AcadGroups.className() == "AcadGroups"

    def test_count(self):
        groups = self._groups()
        assert isinstance(groups.count(), int)
        assert groups.count() >= 0

    def test_add(self):
        groups = self._groups()
        count = groups.count()
        group = groups.add("axgroups_add")
        assert group.className() == "AcadGroup"
        assert group.name() == "axgroups_add"
        assert groups.count() == count + 1

    def test_add_existing_returns_existing(self):
        # Adding a name that already exists returns the existing group and
        # does not create a new one (count is unchanged).
        groups = self._groups()
        first = groups.add("axgroups_dup")
        assert first.name() == "axgroups_dup"
        count = groups.count()
        second = groups.add("axgroups_dup")
        assert second.name() == "axgroups_dup"
        assert groups.count() == count

    def test_item(self):
        # The collection is ordered by group name, not insertion order, so
        # verify the added group is reachable by some index rather than a
        # specific one.
        groups = self._groups()
        groups.add("axgroups_item")
        names = [groups.item(i).name() for i in range(groups.count())]
        assert "axgroups_item" in names

    def test_item_out_of_range(self):
        groups = self._groups()
        with pytest.raises(IndexError):
            groups.item(groups.count())

    def test_getitem(self):
        groups = self._groups()
        groups.add("axgroups_getitem")
        names = [groups[i].name() for i in range(groups.count())]
        assert "axgroups_getitem" in names

    def test_items(self):
        groups = self._groups()
        items = groups.items()
        assert len(items) == groups.count()
        assert all(g.className() == "AcadGroup" for g in items)

    def test_iter(self):
        groups = self._groups()
        count = groups.count()
        names = [g.name() for g in groups]
        assert len(names) == count

    def test_cast(self):
        groups = self._groups()
        casted = Ax.AcadGroups.cast(groups)
        assert casted.count() == groups.count()

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadGroups()
