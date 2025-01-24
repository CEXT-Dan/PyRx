from __future__ import annotations

from pyrx import Ge

class TestVector2d:
    def test_repr(self):
        val = Ge.Vector2d(1.2,2.3)
        assert val.__repr__()  == "PyGe.Vector2d(1.20000000000000,2.30000000000000)"
        
        
