from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAcadHyperlinks:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _hyperlinks(self) -> Ax.AcadHyperlinks:
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(10, 0, 0))
        return ent.hyperlinks()

    def test_className(self):
        assert Ax.AcadHyperlinks.className() == "AcadHyperlinks"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadHyperlinks()

    def test_count_empty(self):
        assert self._hyperlinks().count() == 0

    def test_add(self):
        links = self._hyperlinks()
        count = links.count()
        link = links.add("https://example.com", "desc", "loc")
        assert link.className() == "AcadHyperlink"
        assert links.count() == count + 1

    def test_add_url(self):
        links = self._hyperlinks()
        link = links.add("https://example.com/page", "desc", "loc")
        assert link.url() == "https://example.com/page"

    def test_add_description(self):
        links = self._hyperlinks()
        link = links.add("https://example.com", "my description", "loc")
        assert link.urlDescription() == "my description"

    def test_add_named_location(self):
        links = self._hyperlinks()
        link = links.add("https://example.com", "desc", "my location")
        assert link.urlNamedLocation() == "my location"

    def test_item_returns_added(self):
        links = self._hyperlinks()
        links.add("https://first.example", "d", "l")
        links.add("https://second.example", "d", "l")
        urls = [links.item(i).url() for i in range(links.count())]
        assert "https://first.example" in urls
        assert "https://second.example" in urls

    def test_item_out_of_range(self):
        links = self._hyperlinks()
        with pytest.raises(IndexError):
            links.item(links.count())

    def test_getitem_returns_added(self):
        links = self._hyperlinks()
        links.add("https://first.example", "d", "l")
        links.add("https://second.example", "d", "l")
        urls = [links[i].url() for i in range(links.count())]
        assert "https://first.example" in urls
        assert "https://second.example" in urls

    def test_getitem_out_of_range(self):
        links = self._hyperlinks()
        with pytest.raises(IndexError):
            links[links.count()]
