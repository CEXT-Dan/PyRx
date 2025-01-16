from __future__ import annotations
import pytest

from pyrx import Ap, Ax

class TestAxDocument:
    def test_getinstance(self):
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        assert len(axDoc.name()) != 0
        assert axDoc.className() == 'AcadDocument'

