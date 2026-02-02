from __future__ import annotations

from pyrx import Ap


class TestAxDocument:
    def test_getinstance(self):
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        assert len(axDoc.name()) != 0
        assert axDoc.className() == 'AcadDocument'
        
    def test_getVariable(self):
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axDoc.setVariable("osmode", 191)
        assert axDoc.getVariable("osmode") == 191
        axDoc.setVariable("osmode", 0)
        assert axDoc.getVariable("osmode") == 0

