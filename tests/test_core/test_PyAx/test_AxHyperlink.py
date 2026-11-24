from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAcadHyperlink:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _add_link(
        self, url: str = "https://example.com", desc: str = "desc", loc: str = "loc"
    ) -> Ax.AcadHyperlink:
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(10, 0, 0))
        return ent.hyperlinks().add(url, desc, loc)

    def test_className(self):
        assert Ax.AcadHyperlink.className() == "AcadHyperlink"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadHyperlink()

    def test_url(self):
        link = self._add_link(url="https://example.com/x")
        assert link.url() == "https://example.com/x"

    def test_urlDescription(self):
        link = self._add_link(desc="the description")
        assert link.urlDescription() == "the description"

    def test_urlNamedLocation(self):
        link = self._add_link(loc="the location")
        assert link.urlNamedLocation() == "the location"

    def test_setURL(self):
        link = self._add_link()
        link.setURL("https://changed.example")
        assert link.url() == "https://changed.example"

    def test_setURLDescription(self):
        link = self._add_link()
        link.setURLDescription("changed desc")
        assert link.urlDescription() == "changed desc"

    def test_setURLNamedLocation(self):
        link = self._add_link()
        link.setURLNamedLocation("changed loc")
        assert link.urlNamedLocation() == "changed loc"

    def test_clear(self):
        link = self._add_link()
        link.clear()
        # Observed behavior: clear() invalidates the hyperlink, and a
        # subsequent property access raises (Catastrophic failure in
        # PyIAcadHyperlinkImpl::GetURL) rather than returning empty fields.
        with pytest.raises(Exception):
            link.url()
