from __future__ import annotations

from pyrx import Ge, Db


class TestDbExtents:
    def test_dbextents3d_contains(self):
        ex1 = Db.Extents(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 100))
        assert ex1.contains(Ge.Point3d(50, 50, 50)) == True
        assert not ex1.contains(Ge.Point3d(101, 50, 50)) == True

    def test_dbextents2d_contains(self):
        ex1 = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(100, 100))
        assert ex1.contains(Ge.Point2d(50.0, 50)) == True
        assert not ex1.contains(Ge.Point2d(101, 50)) == True
