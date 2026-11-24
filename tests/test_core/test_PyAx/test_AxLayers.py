from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxLayers:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _layers(self) -> Ax.AcadLayers:
        return self.axDoc.layers()

    def test_className(self):
        assert Ax.AcadLayers.className() == "AcadLayers"

    def test_count(self):
        layers = self._layers()
        assert isinstance(layers.count(), int)
        # A drawing always contains at least the "0" and "Defpoints" layers.
        assert layers.count() >= 1

    def test_add(self):
        layers = self._layers()
        count = layers.count()
        layer = layers.add("axlayers_add")
        assert layer.className() == "AcadLayer"
        assert layer.name() == "axlayers_add"
        assert layers.count() == count + 1

    def test_add_existing_returns_existing(self):
        # Adding a name that already exists returns the existing layer and
        # does not create a new one (count is unchanged).
        layers = self._layers()
        first = layers.add("axlayers_dup")
        assert first.name() == "axlayers_dup"
        count = layers.count()
        second = layers.add("axlayers_dup")
        assert second.name() == "axlayers_dup"
        assert layers.count() == count

    def test_item(self):
        # The collection is ordered by layer name, not insertion order, so
        # verify the added layer is reachable by some index rather than a
        # specific one.
        layers = self._layers()
        layers.add("axlayers_item")
        names = [layers.item(i).name() for i in range(layers.count())]
        assert "axlayers_item" in names

    def test_item_out_of_range(self):
        layers = self._layers()
        with pytest.raises(IndexError):
            layers.item(layers.count())

    def test_getitem(self):
        layers = self._layers()
        layers.add("axlayers_getitem")
        names = [layers[i].name() for i in range(layers.count())]
        assert "axlayers_getitem" in names

    def test_getitem_out_of_range(self):
        layers = self._layers()
        with pytest.raises(IndexError):
            layers[layers.count()]

    def test_items(self):
        layers = self._layers()
        items = layers.items()
        assert len(items) == layers.count()
        assert all(l.className() == "AcadLayer" for l in items)

    def test_iter(self):
        layers = self._layers()
        count = layers.count()
        names = [l.name() for l in layers]
        assert len(names) == count

    def test_cast(self):
        layers = self._layers()
        casted = Ax.AcadLayers.cast(layers)
        assert casted.count() == layers.count()

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadLayers()
