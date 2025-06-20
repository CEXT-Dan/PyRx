from __future__ import annotations

from pyrx import Db


#test UTF-8  -> UTF-16 -> UTF-8
class TestUTFConversion:
    
    def test_polish(self):
        val = "ą, ć, ę, ł, ń, ó, ś, ź, ż"
        assert Db.Core.stringTest(val) == val
        
    def test_chinese_traditional(self):
        val = "這是一個測試"
        assert Db.Core.stringTest(val) == val
        
        
