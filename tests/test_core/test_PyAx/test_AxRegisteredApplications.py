from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxRegisteredApplications:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _apps(self) -> Ax.AcadRegisteredApplications:
        return self.axDoc.registeredApplications()

    def test_className(self):
        assert Ax.AcadRegisteredApplications.className() == "AcadRegisteredApplications"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadRegisteredApplications()

    def test_add(self):
        apps = self._apps()
        app = apps.add("PYRX_RA_ADD")
        assert app.name() == "PYRX_RA_ADD"
        assert app.className() == "AcadRegisteredApplication"

    def test_count(self):
        apps = self._apps()
        count = apps.count()
        apps.add("PYRX_RA_COUNT")
        assert apps.count() == count + 1

    def test_item(self):
        apps = self._apps()
        count = apps.count()
        apps.add("PYRX_RA_ITEM")
        item = apps.item(count)
        assert item.name() == "PYRX_RA_ITEM"

    def test_item_out_of_range(self):
        apps = self._apps()
        with pytest.raises(IndexError):
            apps.item(apps.count())

    def test_getitem(self):
        apps = self._apps()
        count = apps.count()
        apps.add("PYRX_RA_GETITEM")
        assert apps[count].name() == "PYRX_RA_GETITEM"

    def test_getitem_out_of_range(self):
        apps = self._apps()
        with pytest.raises(IndexError):
            apps[apps.count()]

    def test_items(self):
        apps = self._apps()
        apps.add("PYRX_RA_ITEMS")
        items = apps.items()
        assert len(items) == apps.count()

    def test_iter(self):
        apps = self._apps()
        apps.add("PYRX_RA_ITER")
        names = [a.name() for a in apps]
        assert "PYRX_RA_ITER" in names

    def test_cast(self):
        apps = self._apps()
        casted = Ax.AcadRegisteredApplications.cast(apps)
        assert casted.count() == apps.count()
