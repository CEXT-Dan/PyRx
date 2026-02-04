from __future__ import annotations
from pyrx import Db, Ge


class TestDbWipeout:

    def test_create_1(self):
        pts = [
            Ge.Point2d(0, 0),
            Ge.Point2d(100, 0),
            Ge.Point2d(100, 100),
            Ge.Point2d(0, 100),
            Ge.Point2d(0, 0),
        ]

        wipout = Db.Wipeout(pts, Ge.Vector3d.kZAxis)
        assert wipout.scale() == Ge.Vector2d(1.00000000000000, 1.00000000000000)

    def test_create_2(self):
        pts = [
            Ge.Point2d(0, 0),
            Ge.Point2d(100, 0),
            Ge.Point2d(100, 100),
            Ge.Point2d(0, 100),
            Ge.Point2d(0, 0),
        ]

        wipout = Db.Wipeout()
        wipout.setFrom(pts, Ge.Vector3d.kZAxis)
        assert wipout.scale() == Ge.Vector2d(1.00000000000000, 1.00000000000000)
