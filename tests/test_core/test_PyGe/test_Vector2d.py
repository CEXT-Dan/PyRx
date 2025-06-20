from __future__ import annotations

import math

from pyrx import Ge


class TestVector2d:
    def test_repr(self):
        val = Ge.Vector2d(1.2, 2.3)
        assert val.__repr__() == "PyGe.Vector2d(1.20000000000000,2.30000000000000)"

    def test_vector2d_mul2(self):
        v = Ge.Vector2d(1, 1)
        v = v * 10
        assert v == Ge.Vector2d(10, 10)

    def test_vector2d_rmul1(self):
        v = Ge.Vector2d(1, 1)
        v = 10.0 * v
        assert v == Ge.Vector2d(10, 10)

    def test_vector2d_rmul2(self):
        v = Ge.Vector2d(1, 1)
        m = Ge.Matrix2d()
        m.setToRotation(math.pi, Ge.Point2d.kOrigin)
        v = m * v
        assert v == Ge.Vector2d(-1.0, -1.0)

    def test_vector2d_setToProduct(self):
        v1 = Ge.Vector2d.kXAxis
        m = Ge.Matrix2d.kIdentity
        v1.setToProduct(Ge.Vector2d.kYAxis, math.pi)
        assert v1 == Ge.Vector2d(0.000000, math.pi)
        v1 = Ge.Vector2d.kXAxis
        m.setToRotation(math.pi)
        v1.setToProduct(m, Ge.Vector2d.kYAxis)
        assert v1 == Ge.Vector2d(-0.0, -1.0)

    def test_vector2d_isParallelTo(self):
        v1 = Ge.Vector2d.kXAxis
        v2 = Ge.Vector2d.kXAxis
        ans = v1.isParallelTo(v2)
        assert ans == True
        ans = v1.isParallelTo(v2, Ge.Tol.current())
        assert ans == True

    def test_vector2d_isPerpendicularTo(self):
        v1 = Ge.Vector2d.kXAxis
        v2 = Ge.Vector2d.kYAxis
        ans = v1.isPerpendicularTo(v2)
        assert ans == True
        ans = v1.isPerpendicularTo(v2, Ge.Tol.current())
        assert ans == True

    def test_vector2d_make1(self):
        p1 = Ge.Point2d(100, 0)
        p2 = Ge.Point2d(0, 0)
        v1 = p2 - p1
        assert v1.isParallelTo(Ge.Vector2d.kXAxis) == True
        assert v1.isPerpendicularTo(Ge.Vector2d.kYAxis) == True
        assert v1.isUnitLength() == False
        assert v1.isZeroLength() == False
        assert v1.length() == 100
        v1.rotateBy(math.pi)
        v1.negate()
        assert v1.isParallelTo(Ge.Vector2d.kXAxis) == True
