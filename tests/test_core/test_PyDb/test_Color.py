from __future__ import annotations

from pyrx import Db


class TestColor:

    def test_Color_1(self):
        # Standard format: #RRGGBB
        color = Db.Color("#FFA500")
        assert color.red() == 255
        assert color.green() == 165
        assert color.blue() == 0
        assert color.toHTMLColor() == "#FFA500"

    def test_Color_2(self):
        # color index
        color = Db.Color(1)
        assert color.isByACI() == True
        assert color.colorIndex() == 1

    def test_Color_3(self):
        # r,g,b
        color = Db.Color(255, 165, 0)
        assert color.isByACI() == False
        assert color.red() == 255
        assert color.green() == 165
        assert color.blue() == 0
        assert color.toHTMLColor() == "#FFA500"

    def test_Color_4(self):
        # Short format: #FFF
        color = Db.Color("#0FA")
        assert color.red() == 0
        assert color.green() == 255
        assert color.blue() == 170
        assert color.isByACI() == False
        assert color.toHTMLColor() == "#00FFAA"

    def test_Color_5(self):
        # Standard format: #RRGGBB, leading 00
        color = Db.Color("#00FFAA")
        assert color.red() == 0
        assert color.green() == 255
        assert color.blue() == 170
        assert color.isByACI() == False
        assert color.toHTMLColor() == "#00FFAA"

    def test_Color_set(self):
        # Standard format, get set
        color = Db.Color()
        color.fromHTMLColor("#00FFAA")
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
        assert color.colorIndex() == 1

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

    def test_Color_5(self):
        color = Db.EntityColor("#00FFAA")
        assert color.red() == 0
        assert color.green() == 255
        assert color.blue() == 170
        assert color.isByACI() == False
        assert color.toHTMLColor() == "#00FFAA"

    def test_Color_set(self):
        color = Db.EntityColor()
        color.fromHTMLColor("#00FFAA")
        assert color.red() == 0
        assert color.green() == 255
        assert color.blue() == 170
        assert color.isByACI() == False
        assert color.toHTMLColor() == "#00FFAA"
