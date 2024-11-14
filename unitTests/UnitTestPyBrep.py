import unittest
import testcfg
import dbc

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PySm as Sm
import PyBr as Br

host = Ap.Application.hostAPI()


class TestBrep(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestBrep, self).__init__(*args, **kwargs)

    def test_BrepEdgeTraverserCylinder(self):
        objHnd = Db.Handle("1962")
        objId = dbc.dbs["brep"].getObjectId(False, objHnd)
        dbent = Db.Entity(objId)
        brep = Br.Brep()
        brep.set(dbent)
        et = Br.BrepEdgeTraverser()
        et.setBrep(brep)
        props = []
        while not et.done():
            edge = et.getEdge()
            curveType = edge.getCurveType()
            excurve = Ge.ExternalCurve3d.cast(edge.getCurve())
            if curveType == Ge.EntityId.kCircArc3d:
                carc = Ge.CircArc3d.cast(excurve.getNativeCurve())
                props.append((carc.center(), carc.radius()))
            et.next()
        self.assertEqual(len(props), 2)

        p1, r1 = props[0]
        self.assertAlmostEqual(p1.x, 665.87415581415257, 4)
        self.assertAlmostEqual(p1.y, -391.31862653049518, 4)
        self.assertAlmostEqual(p1.z, 16.84222491137716, 4)
        self.assertAlmostEqual(r1, 29.365207012326316, 4)

        p2, r2 = props[1]
        self.assertAlmostEqual(p2.x, 665.87415581415257, 4)
        self.assertAlmostEqual(p2.y, -391.31862653049518, 4)
        self.assertAlmostEqual(p2.z, 0, 0, 4)
        self.assertAlmostEqual(r2, 29.365207012326316, 4)

    def test_BrepEdgeTraverserCube(self):
        objHnd = Db.Handle("195e")
        objId = dbc.dbs["brep"].getObjectId(False, objHnd)
        dbent = Db.Entity(objId)
        brep = Br.Brep()
        brep.set(dbent)
        et = Br.BrepEdgeTraverser()
        et.setBrep(brep)
        while not et.done():
            edge = et.getEdge()
            curveType = edge.getCurveType()
            excurve = Ge.ExternalCurve3d.cast(edge.getCurve())
            if curveType == Ge.EntityId.kLineSeg3d:
                seg = Ge.LineSeg3d.cast(excurve.getNativeCurve())
                self.assertAlmostEqual(seg.length(), 100, 4)
            et.next()

    def test_BrepEdgeTraverserCubeList(self):
        objHnd = Db.Handle("195e")
        objId = dbc.dbs["brep"].getObjectId(False, objHnd)
        dbent = Db.Entity(objId)
        brep = Br.Brep(dbent)
        et = Br.BrepEdgeTraverser(brep)
        self.assertEqual(len(et.getEdges()), 12)


def brepTester():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestBrep)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestBrep"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print("TestBrep")
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
