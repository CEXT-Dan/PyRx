from __future__ import annotations

from pyrx import Ap


# test UTF-8  -> UTF-16 -> UTF-8
class TestUTFConversion:

    def test_polish(self):
        val = "ą, ć, ę, ł, ń, ó, ś, ź, ż"
        assert Ap.Internal.stringTest(val) == val

    def test_chinese_traditional(self):
        val = "這是一個測試"
        assert Ap.Internal.stringTest(val) == val

    def test_chinese_traditional_cmp(self):
        val = "這是一個測試"
        assert Ap.Internal.icompare(val, val) == True

    def test_polish_cmp(self):
        left = "ą, ć, ę, ł, ń, ó, ś, ź, ż"
        right = "Ą, Ć, Ę, Ł, Ń, Ó, Ś, Ź, Ż"
        assert Ap.Internal.icompare(left, right) == True

    def test_german_cmp(self):
        """Tests German sharp S (Eszett) expansion."""
        assert Ap.Internal.icompare("groß", "GROSS") == True
        assert Ap.Internal.icompare("ä, ö, ü", "Ä, Ö, Ü") == True

    # locale dependant
    # def test_turkish_cmp(self):
    #     """Tests Turkish dotted and dotless I distinction."""
    #     assert Db.Core.icompare("ısparta", "ISPARTA") == True
    #     assert Db.Core.icompare("diyarbakır", "DİYARBAKIR") == True

    # def test_greek_cmp(self):
    #     """Tests Greek sigma variants."""
    #     assert Db.Core.icompare("κόσμος", "ΚΟΣΜΟΣ") == True