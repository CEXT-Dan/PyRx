from __future__ import annotations

from pyrx import Ge


class TestPoint2d:
    def test_repr(self):
        val = Ge.Point2d(1.2, 2.3)
        assert val.__repr__() == "PyGe.Point2d(1.20000000000000,2.30000000000000)"

    def test_point2d_default_ctor(self):
        point = Ge.Point2d()
        assert point == Ge.Point2d(0, 0)

    def test_point2d_arg_ctor(self):
        point = Ge.Point2d(100, 100)
        assert point == Ge.Point2d(100, 100)
        point2 = Ge.Point2d([300, 400])
        assert point2 == Ge.Point2d(300, 400)
        point3 = Ge.Point2d((400, 500))
        assert point3 == Ge.Point2d(400, 500)

    def test_point2d_add(self):
        point = Ge.Point2d(100, 100)
        p = point + Ge.Vector2d.kXAxis
        assert p == Ge.Point2d(101, 100)

    def test_point2d_iadd(self):
        point = Ge.Point2d(100, 100)
        point += Ge.Vector2d.kXAxis
        assert point == Ge.Point2d(101, 100)

    def test_point2d_mul(self):
        point = Ge.Point2d(100, 100)
        point = point * 2.0
        assert point == Ge.Point2d(200, 200)

    def test_point2d_imul(self):
        point = Ge.Point2d(100, 100)
        point *= 2.0
        assert point == Ge.Point2d(200, 200)

    def test_point2d_sub(self):
        point = Ge.Point2d(100, 100)
        p = point - Ge.Vector2d.kXAxis
        assert p == Ge.Point2d(99, 100)

    def test_point2d_isub(self):
        point = Ge.Point2d(100, 100)
        point -= Ge.Vector2d.kXAxis
        assert point == Ge.Point2d(99, 100)

    def test_point2d_div(self):
        point = Ge.Point2d(100, 100)
        p = point / 2.0
        assert p == Ge.Point2d(50, 50)

    def test_point2d_idiv(self):
        point = Ge.Point2d(100, 100)
        point /= 2.0
        assert point == Ge.Point2d(50, 50)

    def test_point2d_isEqualTo(self):
        point1 = Ge.Point2d(100, 100)
        point2 = Ge.Point2d(100, 100)
        point1.isEqualTo(point2)
        assert point1.isEqualTo(point2) == True
        assert point1.isEqualTo(point2, Ge.Tol.current()) == True

    def test_point2d_kOrigin(self):
        origin = Ge.Point2d.kOrigin
        point = Ge.Point2d(0, 0)
        assert origin, point
