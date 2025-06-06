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

    def test_dbextents2d_intersects(self):
        ext1 = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        ext2 = Db.Extents2d(Ge.Point2d(5, 5), Ge.Point2d(7, 7))
        assert ext1.intersectsWith(ext2) == False
        assert ext2.intersectsWith(ext1) == False
        #
        ext1 = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        ext2 = Db.Extents2d(Ge.Point2d(5, 5), Ge.Point2d(17, 17))
        assert ext1.overlaps(ext2) == True
        assert ext2.overlaps(ext1) == True

    def test_dbextents2d_overlaps(self):
        ext1 = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        ext2 = Db.Extents2d(Ge.Point2d(5, 5), Ge.Point2d(7, 7))
        assert ext1.overlaps(ext2) == True
        assert ext2.overlaps(ext1) == True
        #
        ext1 = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        ext2 = Db.Extents2d(Ge.Point2d(5, 5), Ge.Point2d(17, 17))
        assert ext1.overlaps(ext2) == True
        assert ext2.overlaps(ext1) == True
