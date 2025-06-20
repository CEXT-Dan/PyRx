from __future__ import annotations

import math

from pyrx import Ge


class TestVector3d:
    def test_repr(self):
        val = Ge.Vector3d(1.2, 2.3, 4.5)
        assert (
            val.__repr__() == "PyGe.Vector3d(1.20000000000000,2.30000000000000,4.50000000000000)"
        )

    def test_vector3d_rmul1(self):
        v = Ge.Vector3d(1, 1, 1)
        v = 10.0 * v
        assert v == Ge.Vector3d(10, 10, 10)

    def test_vector3d_rmul2(self):
        v = Ge.Vector3d(1, 1, 1)
        m = Ge.Matrix3d()
        m.setToRotation(math.pi, Ge.Vector3d.kZAxis, Ge.Point3d.kOrigin)
        v = m * v
        assert v == Ge.Vector3d(-1.0, -1.0, 1.0)
