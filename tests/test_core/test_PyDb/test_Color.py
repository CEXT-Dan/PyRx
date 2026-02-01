from __future__ import annotations

import pytest

from pyrx import Db, Ed


class TestColor:

    def test_Color_1(self):
        # Standard format: #RRGGBB
        color = Db.Color("#FFA500")
        assert color.red() == 255
        assert color.green() == 165
        assert color.blue() == 0
        assert color.toHTMLColor() == "#FFA500"

    def test_Color_2(self):
        color = Db.Color(1)
        assert color.isByACI() == True
        color.colorIndex() == 1

    def test_Color_3(self):
        color = Db.Color(255, 165, 0)
        assert color.isByACI() == False
        assert color.red() == 255
        assert color.green() == 165
        assert color.blue() == 0
        assert color.toHTMLColor() == "#FFA500"

    def test_Color_4(self):
        # Standard format: #FFF
        color = Db.Color("#0FA")
        assert color.red() == 0
        assert color.green() == 255
        assert color.blue() == 170
        assert color.isByACI() == False
        assert color.toHTMLColor() == "#00FFAA"


class TestEntityColor:

    def test_Color_1(self):
        # Standard format: #RRGGBB
        color = Db.EntityColor("#FFA500")
        assert color.isByACI() == False
        assert color.red() == 255
        assert color.green() == 165
        assert color.blue() == 0
        assert color.toHTMLColor() == "#FFA500"

    def test_Color_2(self):
        color = Db.EntityColor(1)
        assert color.isByACI() == True
        color.colorIndex() == 1

    def test_Color_3(self):
        color = Db.EntityColor(255, 165, 0)
        assert color.isByACI() == False
        assert color.red() == 255
        assert color.green() == 165
        assert color.blue() == 0
        assert color.toHTMLColor() == "#FFA500"

    def test_Color_4(self):
        # Standard format: #FFF
        color = Db.EntityColor("#0FA")
        assert color.red() == 0
        assert color.green() == 255
        assert color.blue() == 170
        assert color.isByACI() == False
        assert color.toHTMLColor() == "#00FFAA"
