from __future__ import annotations

import pytest

from pyrx import Db, Ax


class TestAxColor:

    def test_Color_1(self):
        # Standard format: #RRGGBB
        Ax.AcColor()
        color = Ax.AcadAcCmColor ("#FFA500")
        assert color.red() == 255
        assert color.green() == 165
        assert color.blue() == 0
        assert color.toHTMLColor() == "#FFA500"

    def test_Color_2(self):
        color = Ax.AcadAcCmColor(Ax.AcColor.acRed)
        color.colorIndex() == Ax.AcColor.acRed

    def test_Color_3(self):
        color = Ax.AcadAcCmColor(255, 165, 0)
        assert color.red() == 255
        assert color.green() == 165
        assert color.blue() == 0
        assert color.toHTMLColor() == "#FFA500"

    def test_Color_4(self):
        # Standard format: #FFF
        color = Ax.AcadAcCmColor("#0FA")
        assert color.red() == 0
        assert color.green() == 255
        assert color.blue() == 170
        assert color.toHTMLColor() == "#00FFAA"

    def test_Color_5(self):
        color = Ax.AcadAcCmColor("#00FFAA")
        assert color.red() == 0
        assert color.green() == 255
        assert color.blue() == 170
        assert color.toHTMLColor() == "#00FFAA"

    def test_Color_set(self):
        color = Ax.AcadAcCmColor()
        color.fromHTMLColor("#00FFAA")
        assert color.red() == 0
        assert color.green() == 255
        assert color.blue() == 170
        assert color.toHTMLColor() == "#00FFAA"