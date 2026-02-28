from __future__ import annotations

from pyrx import Ge


class TestCylinder:

    def test_intersect_with(self):
        v = Ge.Point3d(0, 0, -50) - Ge.Point3d(0, 0, 50)
        c = Ge.Cylinder(10, Ge.Point3d(0, 0, 0), v)
        
        # fail, i should be 0 or 2
        # s = Ge.LineSeg3d(Ge.Point3d(0, 0, 100), Ge.Point3d(0, 0, -100))
        # b, i, p1, p2 = c.intersectWith(s)
        # assert b == True
        # assert i == 2
        # assert p1 == Ge.Point3d(0, 0, -50)
        # assert p2 == Ge.Point3d(0, 0, 50)
        # Actual True 1 (0,0,100) (0,0,100)

        #ok
        s = Ge.LineSeg3d(Ge.Point3d(-50, 0, 0), Ge.Point3d(50, 0, 0))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == True
        assert i == 2
        assert p1 == Ge.Point3d(10, 0, 0)
        assert p2 == Ge.Point3d(-10, 0, 0)

        #ok
        s = Ge.LineSeg3d(Ge.Point3d(0, -50, 0), Ge.Point3d(0, 0, 0))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == True
        assert i == 1
        assert p1 == Ge.Point3d(0, -10, 0)
        assert p2 == Ge.Point3d(0, 0, 0)

        #ok
        s = Ge.LineSeg3d(Ge.Point3d(0, 0, 0), Ge.Point3d(0, 50, 0))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == True
        assert i == 1
        assert p1 == Ge.Point3d(0, 10, 0)
        assert p2 == Ge.Point3d(0, 0, 0)

