from __future__ import annotations

from pyrx import Ge

class TestPoint2d:
    def test_repr(self):
        val = Ge.Point2d(1.2,2.3)
        assert val.__repr__()  == "PyGe.Point2d(1.20000000000000,2.30000000000000)"
        
        
