from __future__ import annotations

from pyrx import Ap, Ax
from tests import MEDIA_DIR


class TestAxDocuments:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDocs = self.axApp.documents()

    def test_className(self):
        assert Ax.AcadDocuments.className() == "AcadDocuments"

    def test_count(self):
        assert self.axDocs.count() >= 1

    def test_add(self):
        count = self.axDocs.count()
        doc = self.axDocs.add()
        assert doc.className() == "AcadDocument"
        assert len(doc.name()) != 0
        assert self.axDocs.count() == count + 1
        doc.close(False)

    def test_add_template(self):
        doc = self.axDocs.add(str(MEDIA_DIR / "SSTest.dst"))
        assert doc.className() == "AcadDocument"
        doc.close(False)

    def test_item(self):
        doc = self.axDocs.item(0)
        assert doc.className() == "AcadDocument"

    def test_getitem(self):
        doc = self.axDocs[0]
        assert doc.className() == "AcadDocument"

    def test_open(self):
        doc = self.axDocs.open(str(MEDIA_DIR / "06457.dwg"), True)
        assert doc.isReadOnly() is True
        assert doc.name() == "06457.dwg"
        doc.close(False)

    def test_close(self):
        doc = self.axDocs.add()
        count = self.axDocs.count()
        doc.close(False)
        assert self.axDocs.count() == count - 1
