from __future__ import annotations

from pyrx import Ap


class TestAxLayout:

    def test_acadLayouts(self):
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axLayouts = axDoc.layouts()
        axLayout = axLayouts.add("WOOHOO")
        assert axLayout.name() == "WOOHOO"
        names = [axLayout.name() for axLayout in axLayouts]
        assert "WOOHOO" in names
