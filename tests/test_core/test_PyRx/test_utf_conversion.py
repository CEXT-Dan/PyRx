from __future__ import annotations

from pyrx import Db


# test UTF-8  -> UTF-16 -> UTF-8
class TestUTFConversion:

    def test_polish(self):
        val = "ą, ć, ę, ł, ń, ó, ś, ź, ż"
        assert Db.Core.stringTest(val) == val

    def test_chinese_traditional(self):
        val = "這是一個測試"
        assert Db.Core.stringTest(val) == val

    def test_chinese_traditional_cmp(self):
        val = "這是一個測試"
        assert Db.Core.icompare(val, val) == True

    def test_polish_cmp(self):
        l = "ą, ć, ę, ł, ń, ó, ś, ź, ż"
        u = "Ą, Ć, Ę, Ł, Ń, Ó, Ś, Ź, Ż"
        assert Db.Core.icompare(l, u) == True

    def test_german_cmp(self):
        """Tests German sharp S (Eszett) expansion."""
        assert Db.Core.icompare("groß", "GROSS") == True
        assert Db.Core.icompare("ä, ö, ü", "Ä, Ö, Ü") == True

    # locale dependant
    # def test_turkish_cmp(self):
    #     """Tests Turkish dotted and dotless I distinction."""
    #     assert Db.Core.icompare("ısparta", "ISPARTA") == True
    #     assert Db.Core.icompare("diyarbakır", "DİYARBAKIR") == True

    # def test_greek_cmp(self):
    #     """Tests Greek sigma variants."""
    #     assert Db.Core.icompare("κόσμος", "ΚΟΣΜΟΣ") == True