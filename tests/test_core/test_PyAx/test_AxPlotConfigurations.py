from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxPlotConfigurations:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _configs(self) -> Ax.AcadPlotConfigurations:
        return self.axDoc.plotConfigurations()

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadPlotConfigurations.className() == "AcadPlotConfigurations"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadPlotConfigurations()

    def test_cast(self):
        configs = self._configs()
        casted = Ax.AcadPlotConfigurations.cast(configs)
        assert casted.count() == configs.count()

    # --- count ---

    def test_count(self):
        configs = self._configs()
        assert isinstance(configs.count(), int)
        assert configs.count() >= 0

    # --- add ---

    def test_add(self):
        configs = self._configs()
        count = configs.count()
        config = configs.add("axplotconfigs_add")
        assert config.className() == "AcadPlotConfiguration"
        assert config.name() == "axplotconfigs_add"
        assert configs.count() == count + 1

    # --- item / items / __getitem__ / __iter__ ---

    def test_item(self):
        configs = self._configs()
        configs.add("axplotconfigs_item")
        names = [configs.item(i).name() for i in range(configs.count())]
        assert "axplotconfigs_item" in names

    def test_item_out_of_range(self):
        configs = self._configs()
        with pytest.raises(IndexError):
            configs.item(configs.count())

    def test_getitem(self):
        configs = self._configs()
        configs.add("axplotconfigs_getitem")
        names = [configs[i].name() for i in range(configs.count())]
        assert "axplotconfigs_getitem" in names

    def test_getitem_out_of_range(self):
        configs = self._configs()
        with pytest.raises(IndexError):
            configs[configs.count()]

    def test_items(self):
        configs = self._configs()
        items = configs.items()
        assert len(items) == configs.count()
        assert all(c.className() == "AcadPlotConfiguration" for c in items)

    def test_iter(self):
        configs = self._configs()
        count = configs.count()
        names = [c.name() for c in configs]
        assert len(names) == count
