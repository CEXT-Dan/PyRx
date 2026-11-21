from __future__ import annotations

from pyrx import Ap, Ax


class TestAxDimStyles:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_className(self):
        assert Ax.AcadDimStyle.className() == "AcadDimStyle"
        assert Ax.AcadDimStyles.className() == "AcadDimStyles"

    def test_count(self):
        styles = self.axDoc.dimStyles()
        ncnt = 0
        for _style in styles:
            ncnt += 1
        assert styles.count() == ncnt

    def test_add(self):
        styles = self.axDoc.dimStyles()
        style = styles.add("testdimstyle")
        assert style.name() == "testdimstyle"
        assert style.objectName() == "AcDbDimStyleTableRecord"

    def test_count_after_add(self):
        styles = self.axDoc.dimStyles()
        count = styles.count()
        styles.add("testdimstyle_count")
        assert styles.count() == count + 1

    def test_item(self):
        styles = self.axDoc.dimStyles()
        count = styles.count()
        styles.add("testdimstyle_item")
        assert styles.item(count).name() == "testdimstyle_item"
        assert styles[count].name() == "testdimstyle_item"

    def test_items(self):
        styles = self.axDoc.dimStyles()
        items = styles.items()
        assert len(items) == styles.count()
        assert all(s.objectName() == "AcDbDimStyleTableRecord" for s in items)

    def test_iter(self):
        styles = self.axDoc.dimStyles()
        count = styles.count()
        names = [s.name() for s in styles]
        assert len(names) == count

    def test_name(self):
        styles = self.axDoc.dimStyles()
        style = styles.add("testdimstyle_name")
        assert style.name() == "testdimstyle_name"
        style.setName("testdimstyle_name2")
        assert style.name() == "testdimstyle_name2"

    def test_cast(self):
        styles = self.axDoc.dimStyles()
        style = styles.add("testdimstyle_cast")
        casted = Ax.AcadDimStyle.cast(style)
        assert casted.name() == "testdimstyle_cast"
        casted_styles = Ax.AcadDimStyles.cast(styles)
        assert casted_styles.count() == styles.count()

    def test_copyFrom(self):
        styles = self.axDoc.dimStyles()
        src = styles.add("testdimstyle_src")
        dst = styles.add("testdimstyle_dst")
        dst.copyFrom(src)
        assert dst.name() == "testdimstyle_dst"

    def test_activeDimStyle(self):
        active = self.axDoc.activeDimStyle()
        assert active.objectName() == "AcDbDimStyleTableRecord"
        assert isinstance(active.name(), str)

    def test_setActiveDimStyle(self):
        styles = self.axDoc.dimStyles()
        original = self.axDoc.activeDimStyle()
        style = styles.add("testdimstyle_active")
        self.axDoc.setActiveDimStyle(style)
        try:
            active = self.axDoc.activeDimStyle()
            assert active.name() == "testdimstyle_active"
        finally:
            self.axDoc.setActiveDimStyle(original)

    def test_objectName(self):
        styles = self.axDoc.dimStyles()
        style = styles.add("testdimstyle_objname")
        assert style.objectName() == "AcDbDimStyleTableRecord"
