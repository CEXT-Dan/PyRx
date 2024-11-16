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
        et = Br.EdgeTraverser()
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
        et = Br.EdgeTraverser()
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
        et = Br.EdgeTraverser(brep)
        self.assertEqual(len(et.getEdges()), 12)

    def test_BrepFaceTraverserCubeList(self):
        objHnd = Db.Handle("195e")
        objId = dbc.dbs["brep"].getObjectId(False, objHnd)
        dbent = Db.Entity(objId)
        brep = Br.Brep(dbent)
        ft = Br.FaceTraverser(brep)
        faces = ft.getFaces()
        areas = [face.getArea() for face in faces]
        types = [face.getSurfaceType() for face in faces]
        ors = [face.getOrientToSurface() for face in faces]

        tareas = [10000.0, 10000.0, 10000.0, 10000.0, 10000.0, 10000.0]
        ttypes = [
            Ge.EntityId.kPlane,
            Ge.EntityId.kPlane,
            Ge.EntityId.kPlane,
            Ge.EntityId.kPlane,
            Ge.EntityId.kPlane,
            Ge.EntityId.kPlane,
        ]
        tors = [True, False, False, False, False, False]
        self.assertEqual(areas, tareas)
        self.assertEqual(types, ttypes)
        self.assertEqual(ors, tors)
        
           
    def test_BrepShellTraverserCubeList(self):
        objHnd = Db.Handle("195e")
        objId = dbc.dbs["brep"].getObjectId(False, objHnd)
        dbent = Db.Entity(objId)
        brep = Br.Brep(dbent)
        st = Br.ShellTraverser(brep)
        types = [shell.getType() for shell in st.getShells()]
        self.assertEqual(types, [Br.ShellType.kShellExterior])
        
    def test_BrepVertexTraverserList(self):
        objHnd = Db.Handle("1392")
        objId = dbc.dbs["brep"].getObjectId(False, objHnd)
        dbent = Db.Entity(objId)
        brep = Br.Brep(dbent)
        vt = Br.VertexTraverser(brep)
        pts = [vt.getPoint() for vt in vt.getVertexs()]
        self.assertEqual(len(pts), 16)

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
