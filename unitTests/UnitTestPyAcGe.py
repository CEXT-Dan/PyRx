import os
import unittest
import math
import testcfg
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb as Db  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor
import dbc


host = PyAp.Application.hostAPI()


class TestGe(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestGe, self).__init__(*args, **kwargs)

    def __del__(self):
        pass

    
    def test_vector3d_rmul1(self):
        v = PyGe.Vector3d(1, 1, 1)
        v = 10.0 * v
        self.assertEqual(v, PyGe.Vector3d(10, 10, 10))

    def test_vector3d_rmul2(self):
        v = PyGe.Vector3d(1, 1, 1)
        m = PyGe.Matrix3d()
        m.setToRotation(math.pi, PyGe.Vector3d.kZAxis, PyGe.Point3d.kOrigin)
        v = m * v
        self.assertEqual(v, PyGe.Vector3d(-1.0, -1.0, 1.0))

   

    def test_pyge_line2d_static_properties(self):
        xline = PyGe.Line2d.kXAxis
        yline = PyGe.Line2d.kYAxis
        self.assertTrue(xline.isPerpendicularTo(yline))

    def test_pyge_line3d_static_properties(self):
        xline = PyGe.Line3d.kXAxis
        yline = PyGe.Line3d.kYAxis
        zline = PyGe.Line3d.kZAxis
        self.assertTrue(xline.isPerpendicularTo(yline))
        self.assertTrue(xline.isPerpendicularTo(zline))

    def test_pyge_lineseg3d_1(self):
        s1 = PyGe.LineSeg3d(PyGe.Point3d(0, 0, 0), PyGe.Point3d(100, 100, 0))
        s2 = PyGe.LineSeg3d(PyGe.Point3d(0, 100, 0), PyGe.Point3d(100, 0, 0))
        self.assertTrue(s1.isPerpendicularTo(s2))
        self.assertTrue(s1.intersectWith(s2)[0])
        self.assertTrue(s1.isOn(s2.midPoint()))
        s3 = PyGe.LineSeg3d()
        s3.set(PyGe.Point3d(0, 0, 0), PyGe.Point3d(0, 100, 0))
        self.assertEqual(s3.length(), 100)
        self.assertEqual(s3.length(0, 1), 100)
        self.assertEqual(s3.length(0.5, 1), 50)
        self.assertEqual(s3.length(0.0, 0.5), 50)
        s4 = PyGe.LineSeg3d()
        s4.set(PyGe.Point3d(100, 0, 0), PyGe.Point3d(100, 100, 0))
        self.assertTrue(s3.isParallelTo(s4))

    def test_lineseg3d_reverse(self):
        pnt1 = PyGe.Point3d(0, 0, 0)
        pnt2 = PyGe.Point3d(1, 2, 3)
        seg = PyGe.LineSeg3d(pnt1, pnt2)
        self.assertEqual(seg.startPoint(), pnt1)
        seg.reverseParam()
        self.assertEqual(seg.startPoint(), pnt2)

    @unittest.skipIf(
        *testcfg.makeSkip(
            testcfg.ETFlags.eBRX | testcfg.ETFlags.eGRX | testcfg.ETFlags.eZRX
        )
    )
    def test_surfSurfInt(self):
        vec = PyGe.Vector3d.kXAxis
        pnt = PyGe.Point3d(4000.0, 3000.0, 0.0)
        p1 = PyGe.Plane(pnt, vec)
        p3 = PyGe.Plane(pnt, vec)
        si = PyGe.SurfSurfInt(p1, p3)
        self.assertEqual(si.numResults(), 1)

    def test_ge3dcurve_length(self):
        seg = PyGe.LineSeg3d(PyGe.Point3d(0, 0, 0), PyGe.Point3d(100, 0, 0))
        length = seg.length(0, 1)
        self.assertEqual(length, 100)

    def test_ge2dcurve_length(self):
        seg = PyGe.LineSeg2d(PyGe.Point2d(0, 0), PyGe.Point2d(100, 0))
        length = seg.length(0, 1)
        self.assertEqual(length, 100)

    def test_CompositeCurve3d_getCurveList(self):
        objHnd = Db.Handle("2c92e2")
        objId = dbc.dbs["06457"].getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        pl = Db.Polyline(objId)
        composite = pl.getAcGeCurve()
        gecurves = composite.getCurveList()
        self.assertEqual(len(gecurves), 21)

    @unittest.skipIf(*testcfg.makeSkip(testcfg.ETFlags.eBRX | testcfg.ETFlags.eZRX))
    def test_CurveCurveInt2d_inter(self):
        objHnd1 = Db.Handle("2c959f")
        objId1 = dbc.dbs["06457"].getObjectId(False, objHnd1)
        self.assertEqual(objId1.isValid(), True)
        objHnd2 = Db.Handle("2c95a0")
        objId2 = dbc.dbs["06457"].getObjectId(False, objHnd2)
        self.assertEqual(objId2.isValid(), True)
        dbcurve1 = Db.Polyline(objId1)
        dbcurve2 = Db.Polyline(objId2)
        gecurve1 = dbcurve1.getAcGeCurve2d()
        gecurve2 = dbcurve2.getAcGeCurve2d()
        inter = PyGe.CurveCurveInt2d(gecurve1, gecurve2)
        self.assertEqual(inter.numIntPoints(), 1)
        tp = PyGe.Point2d(-38169.03679118369473, -8356.39529306029726)
        self.assertEqual(inter.intPoint(0), tp)

    @unittest.skipIf(*testcfg.makeSkip(testcfg.ETFlags.eBRX | testcfg.ETFlags.eZRX))
    def test_CurveCurveInt3d_inter(self):
        objHnd1 = Db.Handle("2c959f")
        objId1 = dbc.dbs["06457"].getObjectId(False, objHnd1)
        self.assertEqual(objId1.isValid(), True)
        objHnd2 = Db.Handle("2c95a0")
        objId2 = dbc.dbs["06457"].getObjectId(False, objHnd2)
        self.assertEqual(objId2.isValid(), True)
        dbcurve1 = Db.Curve(objId1)
        dbcurve2 = Db.Curve(objId2)
        gecurve1 = dbcurve1.getAcGeCurve()
        gecurve2 = dbcurve2.getAcGeCurve()
        inter = PyGe.CurveCurveInt3d(gecurve1, gecurve2)
        self.assertEqual(inter.numIntPoints(), 1)
        tp = PyGe.Point3d(-38169.03679118369473, -8356.39529306029726, 0.00000000000000)
        self.assertEqual(inter.intPoint(0), tp)

    @unittest.skipIf(*testcfg.makeSkip(testcfg.ETFlags.eBRX | testcfg.ETFlags.eZRX))
    def test_CurveCurveInt2d_overlap(self):
        objHnd1 = Db.Handle("2c94f5")
        objId1 = dbc.dbs["06457"].getObjectId(False, objHnd1)
        self.assertEqual(objId1.isValid(), True)
        objHnd2 = Db.Handle("2c94f6")
        objId2 = dbc.dbs["06457"].getObjectId(False, objHnd2)
        self.assertEqual(objId2.isValid(), True)
        dbcurve1 = Db.Polyline(objId1)
        dbcurve2 = Db.Polyline(objId2)
        gecurve1 = dbcurve1.getAcGeCurve2d()
        gecurve2 = dbcurve2.getAcGeCurve2d()
        inter = PyGe.CurveCurveInt2d(gecurve1, gecurve2)
        self.assertEqual(inter.overlapCount(), 1)
        ranges = inter.getOverlapRanges(0)
        r1: PyGe.Interval = ranges[0]
        r2: PyGe.Interval = ranges[1]
        self.assertAlmostEqual(r1.length(), 1421.1194776994016, 4)
        self.assertAlmostEqual(r2.length(), 1421.1194776994016, 4)

    @unittest.skipIf(*testcfg.makeSkip(testcfg.ETFlags.eBRX | testcfg.ETFlags.eZRX))
    def test_CurveCurveInt3d_overlap(self):
        objHnd1 = Db.Handle("2c9405")
        objId1 = dbc.dbs["06457"].getObjectId(False, objHnd1)
        self.assertEqual(objId1.isValid(), True)
        objHnd2 = Db.Handle("2c9406")
        objId2 = dbc.dbs["06457"].getObjectId(False, objHnd2)
        self.assertEqual(objId2.isValid(), True)
        dbcurve1 = Db.Curve(objId1)
        dbcurve2 = Db.Curve(objId2)
        gecurve1 = dbcurve1.getAcGeCurve()
        gecurve2 = dbcurve2.getAcGeCurve()
        inter = PyGe.CurveCurveInt3d(gecurve1, gecurve2)
        self.assertEqual(inter.overlapCount(), 1)
        ranges = inter.getOverlapRanges(0)
        r1: PyGe.Interval = ranges[0]
        r2: PyGe.Interval = ranges[1]
        self.assertAlmostEqual(r1.length(), 1142.86444953577)
        self.assertAlmostEqual(r2.length(), 1142.86444953577)

    def test_dbextents3d_contains(self):
        ex1 = Db.Extents(PyGe.Point3d(0, 0, 0), PyGe.Point3d(100, 100, 100))
        self.assertTrue(ex1.contains(PyGe.Point3d(50, 50, 50)))
        self.assertFalse(ex1.contains(PyGe.Point3d(101, 50, 50)))

    def test_dbextents2d_contains(self):
        ex1 = Db.Extents2d(PyGe.Point2d(0, 0), PyGe.Point2d(100, 100))
        self.assertTrue(ex1.contains(PyGe.Point2d(50.0, 50)))
        self.assertFalse(ex1.contains(PyGe.Point2d(101, 50)))


def pyge():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestGe)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestGe"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print("TestGe")
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
