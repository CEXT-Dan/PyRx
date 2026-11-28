from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxLayouts:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _layouts(self) -> Ax.AcadLayouts:
        return self.axDoc.layouts()

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadLayouts.className() == "AcadLayouts"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadLayouts()

    def test_cast(self):
        layouts = self._layouts()
        casted = Ax.AcadLayouts.cast(layouts)
        assert casted.count() == layouts.count()

    # --- count ---

    def test_count(self):
        layouts = self._layouts()
        assert isinstance(layouts.count(), int)
        # A drawing always contains at least the "Model" layout.
        assert layouts.count() >= 1

    # --- add ---

    def test_add(self):
        layouts = self._layouts()
        count = layouts.count()
        layout = layouts.add("axlayouts_add")
        assert layout.className() == "AcadLayout"
        assert layout.name() == "axlayouts_add"
        assert layouts.count() == count + 1

    # --- item / items / __getitem__ / __iter__ ---

    def test_item(self):
        # The collection is ordered by layout name, not insertion order, so
        # verify the added layout is reachable by some index rather than a
        # specific one.
        layouts = self._layouts()
        layouts.add("axlayouts_item")
        names = [layouts.item(i).name() for i in range(layouts.count())]
        assert "axlayouts_item" in names

    def test_item_out_of_range(self):
        layouts = self._layouts()
        with pytest.raises(IndexError):
            layouts.item(layouts.count())

    def test_getitem(self):
        layouts = self._layouts()
        layouts.add("axlayouts_getitem")
        names = [layouts[i].name() for i in range(layouts.count())]
        assert "axlayouts_getitem" in names

    def test_getitem_out_of_range(self):
        layouts = self._layouts()
        with pytest.raises(IndexError):
            layouts[layouts.count()]

    def test_items(self):
        layouts = self._layouts()
        items = layouts.items()
        assert len(items) == layouts.count()
        assert all(layout.className() == "AcadLayout" for layout in items)

    def test_iter(self):
        layouts = self._layouts()
        count = layouts.count()
        names = [layout.name() for layout in layouts]
        assert len(names) == count

    # --- item methods reachable through the collection ---

    def test_block(self):
        layouts = self._layouts()
        layout = layouts.add("axlayouts_block")
        block = layout.block()
        assert block is not None
        assert isinstance(block.name(), str)

    def test_tabOrder(self):
        layouts = self._layouts()
        layout = layouts.add("axlayouts_taborder")
        assert isinstance(layout.tabOrder(), int)

    # --- document-level layout methods ---

    def test_activeLayout(self):
        layout = self.axDoc.activeLayout()
        assert layout.className() == "AcadLayout"

    def test_setActiveLayout(self):
        layouts = self._layouts()
        layout = layouts.add("axlayouts_active")
        self.axDoc.setActiveLayout(layout)
        assert self.axDoc.activeLayout().name() == "axlayouts_active"
