from __future__ import annotations

import unittest

import pytest

from pyrx import Db, Ge


class TestCurve2d:
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")

    def test_Ge_line2d_static_properties(self):
        xline = Ge.Line2d.kXAxis
        yline = Ge.Line2d.kYAxis
        assert xline.isPerpendicularTo(yline) == True

    def test_ge2dcurve_length(self):
        seg = Ge.LineSeg2d(Ge.Point2d(0, 0), Ge.Point2d(100, 0))
        length = seg.length(0, 1)
        assert length == 100

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_ZRX
    def test_CurveCurveInt2d_inter(self, db_06457: Db.Database):
        objHnd1 = Db.Handle("2c959f")
        objId1 = db_06457.getObjectId(False, objHnd1)
        assert objId1.isValid() == True
        objHnd2 = Db.Handle("2c95a0")
        objId2 = db_06457.getObjectId(False, objHnd2)
        assert objId2.isValid() == True
        dbcurve1 = Db.Polyline(objId1)
        dbcurve2 = Db.Polyline(objId2)
        gecurve1 = dbcurve1.getAcGeCurve2d()
        gecurve2 = dbcurve2.getAcGeCurve2d()
        inter = Ge.CurveCurveInt2d(gecurve1, gecurve2)
        assert inter.numIntPoints() == 1
        tp = Ge.Point2d(-38169.03679118369473, -8356.39529306029726)
        assert inter.intPoint(0) == tp

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_ZRX
    def test_CurveCurveInt2d_overlap(self, db_06457: Db.Database):
        objHnd1 = Db.Handle("2c94f5")
        objId1 = db_06457.getObjectId(False, objHnd1)
        assert objId1.isValid() == True
        objHnd2 = Db.Handle("2c94f6")
        objId2 = db_06457.getObjectId(False, objHnd2)
        assert objId2.isValid() == True
        dbcurve1 = Db.Polyline(objId1)
        dbcurve2 = Db.Polyline(objId2)
        gecurve1 = dbcurve1.getAcGeCurve2d()
        gecurve2 = dbcurve2.getAcGeCurve2d()
        inter = Ge.CurveCurveInt2d(gecurve1, gecurve2)
        assert inter.overlapCount() == 1
        ranges = inter.getOverlapRanges(0)
        r1: Ge.Interval = ranges[0]
        r2: Ge.Interval = ranges[1]
        self.assertions.assertAlmostEqual(r1.length(), 1421.1194776994016, 4)
        self.assertions.assertAlmostEqual(r2.length(), 1421.1194776994016, 4)
