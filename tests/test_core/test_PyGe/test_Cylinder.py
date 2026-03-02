from __future__ import annotations

import pytest
import math

from pyrx import Ge


class TestCylinder:

    def test_intersect_with_unbounded(self):
        v = Ge.Point3d(0, 0, -50) - Ge.Point3d(0, 0, 50)
        c = Ge.Cylinder(10, Ge.Point3d(0, 0, 0), v)

        s = Ge.LineSeg3d(Ge.Point3d(-50, 0, 0), Ge.Point3d(50, 0, 0))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == True
        assert i == 2
        assert p1 == Ge.Point3d(10, 0, 0)
        assert p2 == Ge.Point3d(-10, 0, 0)

        s = Ge.LineSeg3d(Ge.Point3d(0, -50, 0), Ge.Point3d(0, 0, 0))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == True
        assert i == 1
        assert p1 == Ge.Point3d(0, -10, 0)
        assert p2 == Ge.Point3d(0, 0, 0)

        s = Ge.LineSeg3d(Ge.Point3d(0, 0, 0), Ge.Point3d(0, 50, 0))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == True
        assert i == 1
        assert p1 == Ge.Point3d(0, 10, 0)
        assert p2 == Ge.Point3d(0, 0, 0)
        
        s = Ge.LineSeg3d(Ge.Point3d(0, 0, 100), Ge.Point3d(0, 0, -100))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == False
        assert i == 0
        assert p1 == Ge.Point3d(0, 0, 0)
        assert p2 == Ge.Point3d(0, 0, 0)
        
    def test_intersect_with_bounded(self):
        iv = Ge.Interval(0.0, 100.0)
        c = Ge.Cylinder(
            10,
            Ge.Point3d(0, 0, -50),
            Ge.Vector3d.kZAxis,
            Ge.Vector3d.kXAxis,
            iv,
            0,
            math.tau,
        )
        
        s = Ge.LineSeg3d(Ge.Point3d(-50, 0, 0), Ge.Point3d(50, 0, 0))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == True
        assert i == 2
        assert p1 == Ge.Point3d(10, 0, 0)
        assert p2 == Ge.Point3d(-10, 0, 0)

        s = Ge.LineSeg3d(Ge.Point3d(0, -50, 0), Ge.Point3d(0, 0, 0))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == True
        assert i == 1
        assert p1 == Ge.Point3d(0, -10, 0)
        assert p2 == Ge.Point3d(0, 0, 0)

        s = Ge.LineSeg3d(Ge.Point3d(0, 0, 0), Ge.Point3d(0, 50, 0))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == True
        assert i == 1
        assert p1 == Ge.Point3d(0, 10, 0)
        assert p2 == Ge.Point3d(0, 0, 0)
        
        s = Ge.LineSeg3d(Ge.Point3d(0, 0, 100), Ge.Point3d(0, 0, -100))
        b, i, p1, p2 = c.intersectWith(s)
        assert b == False
        assert i == 0
        assert p1 == Ge.Point3d(0, 0, 0)
        assert p2 == Ge.Point3d(0, 0, 0)
