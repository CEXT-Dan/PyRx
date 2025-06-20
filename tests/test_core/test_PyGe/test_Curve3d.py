from __future__ import annotations

import unittest

import pytest

from pyrx import Db, Ge


class TestCurve3d:
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")

    def test_Ge_line3d_static_properties(self):
        xline = Ge.Line3d.kXAxis
        yline = Ge.Line3d.kYAxis
        zline = Ge.Line3d.kZAxis
        assert xline.isPerpendicularTo(yline) == True
        assert xline.isPerpendicularTo(zline) == True

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_ZRX
    def test_CurveCurveInt3d_overlap(self, db_06457: Db.Database):
        objHnd1 = Db.Handle("2c9405")
        objId1 = db_06457.getObjectId(False, objHnd1)
        assert objId1.isValid() == True
        objHnd2 = Db.Handle("2c9406")
        objId2 = db_06457.getObjectId(False, objHnd2)
        assert objId2.isValid() == True
        dbcurve1 = Db.Curve(objId1)
        dbcurve2 = Db.Curve(objId2)
        gecurve1 = dbcurve1.getAcGeCurve()
        gecurve2 = dbcurve2.getAcGeCurve()
        inter = Ge.CurveCurveInt3d(gecurve1, gecurve2)
        assert inter.overlapCount() == 1
        ranges = inter.getOverlapRanges(0)
        r1: Ge.Interval = ranges[0]
        r2: Ge.Interval = ranges[1]
        self.assertions.assertAlmostEqual(r1.length(), 1142.86444953577)
        self.assertions.assertAlmostEqual(r2.length(), 1142.86444953577)

    def test_Ge_lineseg3d_1(self):
        s1 = Ge.LineSeg3d(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        s2 = Ge.LineSeg3d(Ge.Point3d(0, 100, 0), Ge.Point3d(100, 0, 0))
        assert s1.isPerpendicularTo(s2) == True
        assert s1.intersectWith(s2)[0] == True
        assert s1.isOn(s2.midPoint())[0] == True
        s3 = Ge.LineSeg3d()
        s3.set(Ge.Point3d(0, 0, 0), Ge.Point3d(0, 100, 0))
        assert s3.length() == 100
        assert s3.length(0, 1) == 100
        assert s3.length(0.5, 1) == 50
        assert s3.length(0.0, 0.5) == 50
        s4 = Ge.LineSeg3d()
        s4.set(Ge.Point3d(100, 0, 0), Ge.Point3d(100, 100, 0))
        assert s3.isParallelTo(s4) == True

    def test_lineseg3d_reverse(self):
        pnt1 = Ge.Point3d(0, 0, 0)
        pnt2 = Ge.Point3d(1, 2, 3)
        seg = Ge.LineSeg3d(pnt1, pnt2)
        assert seg.startPoint() == pnt1
        seg.reverseParam()
        assert seg.startPoint() == pnt2

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    def test_surfSurfInt(self):
        vec = Ge.Vector3d.kXAxis
        pnt = Ge.Point3d(4000.0, 3000.0, 0.0)
        p1 = Ge.Plane(pnt, vec)
        p3 = Ge.Plane(pnt, vec)
        si = Ge.SurfSurfInt(p1, p3)
        assert si.numResults() == 1

    def test_ge3dcurve_length(self):
        seg = Ge.LineSeg3d(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        length = seg.length(0, 1)
        assert length == 100

    def test_CompositeCurve3d_getCurveList(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c92e2")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isValid() == True
        pl = Db.Polyline(objId)
        composite = pl.getAcGeCurve()
        gecurves = composite.getCurveList()
        assert len(gecurves) == 21

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_ZRX
    def test_CurveCurveInt3d_inter(self, db_06457: Db.Database):
        objHnd1 = Db.Handle("2c959f")
        objId1 = db_06457.getObjectId(False, objHnd1)
        assert objId1.isValid() == True
        objHnd2 = Db.Handle("2c95a0")
        objId2 = db_06457.getObjectId(False, objHnd2)
        assert objId2.isValid() == True
        dbcurve1 = Db.Curve(objId1)
        dbcurve2 = Db.Curve(objId2)
        gecurve1 = dbcurve1.getAcGeCurve()
        gecurve2 = dbcurve2.getAcGeCurve()
        inter = Ge.CurveCurveInt3d(gecurve1, gecurve2)
        assert inter.numIntPoints() == 1
        tp = Ge.Point3d(-38169.03679118369473, -8356.39529306029726, 0.00000000000000)
        assert inter.intPoint(0) == tp
