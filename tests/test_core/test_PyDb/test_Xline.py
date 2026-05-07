from __future__ import annotations

from pyrx import Db, Ge


class TestDbXline:

    def test_line_creation_1(self):
        line = Db.Xline(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        assert line.unitDir() == Ge.Vector3d.kXAxis

    def test_line_creation_2(self):
        line = Db.Xline(Ge.Point3d(0, 0, 0), Ge.Point3d(0, 100, 0))
        assert line.unitDir() == Ge.Vector3d.kYAxis

    def test_line_creation_3(self):
        line = Db.Xline()
        line.setBasePoint(Ge.Point3d(0, 0, 0))
        line.setSecondPoint(Ge.Point3d(100, 0, 0))
        assert line.basePoint() == Ge.Point3d(0, 0, 0)
        assert line.secondPoint() == Ge.Point3d(1, 0, 0)


class TestRay:

    def test_line_creation_1(self):
        line = Db.Ray(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        assert line.unitDir() == Ge.Vector3d.kXAxis

    def test_line_creation_2(self):
        line = Db.Ray(Ge.Point3d(0, 0, 0), Ge.Point3d(0, 100, 0))
        assert line.unitDir() == Ge.Vector3d.kYAxis

    def test_line_creation_3(self):
        line = Db.Xline()
        line.setBasePoint(Ge.Point3d(0, 0, 0))
        line.setSecondPoint(Ge.Point3d(100, 0, 0))
        assert line.basePoint() == Ge.Point3d(0, 0, 0)
        assert line.secondPoint() == Ge.Point3d(1, 0, 0)
