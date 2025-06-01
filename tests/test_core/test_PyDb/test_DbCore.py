from pyrx import Db


class TestPyDbCore:

    def test_utf8_wstr(self):
        actual = "\nĄ, Ć, Ę, Ł, Ń, Ó, Ś, Ź, Ż"
        assert Db.Core.stringTest(actual) == actual

    def test_tolower(self):
        upper = "\nĄ, Ć, Ę, Ł, Ń, Ó, Ś, Ź, Ż"
        lower = "\ną, ć, ę, ł, ń, ó, ś, ź, ż"
        assert Db.Core.stringtolower(upper) == lower

    def test_toupper(self):
        upper = "\nĄ, Ć, Ę, Ł, Ń, Ó, Ś, Ź, Ż"
        lower = "\ną, ć, ę, ł, ń, ó, ś, ź, ż"
        assert Db.Core.stringtoupper(lower) == upper
        
    def test_icompare(self):
        upper = "\nĄ, Ć, Ę, Ł, Ń, Ó, Ś, Ź, Ż"
        lower = "\ną, ć, ę, ł, ń, ó, ś, ź, ż"
        assert Db.Core.icompare(upper,lower) == True
        
