from __future__ import annotations

from pyrx import Ge

class TestVector3d:
    def test_repr(self):
        val = Ge.Vector3d(1.2,2.3,4.5)
        assert val.__repr__()  == "PyGe.Vector3d(1.20000000000000,2.30000000000000,4.50000000000000)"
        
        
