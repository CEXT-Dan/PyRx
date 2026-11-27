from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxTextStyles:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _styles(self) -> Ax.AcadTextStyles:
        return self.axDoc.textStyles()

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadTextStyles.className() == "AcadTextStyles"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadTextStyles()

    # --- count ---

    def test_count(self):
        styles = self._styles()
        assert isinstance(styles.count(), int)
        # A drawing always contains at least the "Standard" text style, so the
        # count must be at least 1.
        assert styles.count() >= 1

    # --- add ---

    def test_add(self):
        styles = self._styles()
        count = styles.count()
        style = styles.add("axtstyles_add")
        assert style.className() == "AcadTextStyle"
        assert style.name() == "axtstyles_add"
        assert style.objectName() == "AcDbTextStyleTableRecord"
        assert styles.count() == count + 1

    def test_add_existing_returns_existing(self):
        # Adding a name that already exists returns the existing text style and
        # does not create a new one (count is unchanged).
        styles = self._styles()
        first = styles.add("axtstyles_dup")
        assert first.name() == "axtstyles_dup"
        count = styles.count()
        second = styles.add("axtstyles_dup")
        assert second.name() == "axtstyles_dup"
        assert styles.count() == count

    # --- item / getitem ---

    def test_item(self):
        # The collection is ordered by text style name, not insertion order, so
        # verify the added text style is reachable by some index rather than a
        # specific one.
        styles = self._styles()
        styles.add("axtstyles_item")
        names = [styles.item(i).name() for i in range(styles.count())]
        assert "axtstyles_item" in names

    def test_item_out_of_range(self):
        styles = self._styles()
        with pytest.raises(IndexError):
            styles.item(styles.count())

    def test_getitem(self):
        styles = self._styles()
        styles.add("axtstyles_getitem")
        names = [styles[i].name() for i in range(styles.count())]
        assert "axtstyles_getitem" in names

    def test_getitem_out_of_range(self):
        styles = self._styles()
        with pytest.raises(IndexError):
            styles[styles.count()]

    # --- items / iter ---

    def test_items(self):
        styles = self._styles()
        items = styles.items()
        assert len(items) == styles.count()
        assert all(s.objectName() == "AcDbTextStyleTableRecord" for s in items)

    def test_iter(self):
        styles = self._styles()
        count = styles.count()
        names = [s.name() for s in styles]
        assert len(names) == count

    # --- cast ---

    def test_cast(self):
        styles = self._styles()
        casted = Ax.AcadTextStyles.cast(styles)
        assert casted.count() == styles.count()
