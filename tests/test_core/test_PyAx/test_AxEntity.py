from __future__ import annotations
import pytest
from tests import MEDIA_DIR
from pyrx import Ap, Ge, Ax

class TestAxEntity:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_trueColore(self):
        axSpace = self.axDoc.modelSpace()
        axColor = Ax.AcadAcCmColor()
        axColor.setRGB(100,100,100)
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0),Ge.Point3d(100, 0, 0))
        ent.setTrueColor(axColor)
        axColor2 = ent.trueColor()
        assert axColor.red() == axColor2.red()
        assert axColor.green() == axColor2.green()
        assert axColor.blue() == axColor2.blue()
     
