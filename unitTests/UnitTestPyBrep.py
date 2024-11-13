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

    # Cylinder
    def test_BrepEdgeTraverser1(self):
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
        self.assertAlmostEqual(props[0][0].x, 665.87415581415257, 4)
        self.assertAlmostEqual(props[0][0].y, -391.31862653049518, 4)
        self.assertAlmostEqual(props[0][0].z, 16.84222491137716, 4)
        self.assertAlmostEqual(props[0][1], 29.365207012326316, 4)

        self.assertAlmostEqual(props[1][0].x, 665.87415581415257, 4)
        self.assertAlmostEqual(props[1][0].y, -391.31862653049518, 4)
        self.assertAlmostEqual(props[1][0].z, 0, 0, 4)
        self.assertAlmostEqual(props[1][1], 29.365207012326316, 4)


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
