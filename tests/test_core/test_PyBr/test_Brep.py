from __future__ import annotations

import unittest

from pyrx import Br, Db, Ge


class TestBrep:
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")

    def test_BrepEdgeTraverserCylinder(self, db_brep: Db.Database):
        objHnd = Db.Handle("1962")
        objId = db_brep.getObjectId(False, objHnd)
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
        assert len(props) == 2

        p1, r1 = props[0]
        self.assertions.assertAlmostEqual(p1.x, 665.87415581415257, 4)
        self.assertions.assertAlmostEqual(p1.y, -391.31862653049518, 4)
        self.assertions.assertAlmostEqual(p1.z, 16.84222491137716, 4)
        self.assertions.assertAlmostEqual(r1, 29.365207012326316, 4)

        p2, r2 = props[1]
        self.assertions.assertAlmostEqual(p2.x, 665.87415581415257, 4)
        self.assertions.assertAlmostEqual(p2.y, -391.31862653049518, 4)
        self.assertions.assertAlmostEqual(p2.z, 0, 0, 4)
        self.assertions.assertAlmostEqual(r2, 29.365207012326316, 4)

    def test_BrepEdgeTraverserCube(self, db_brep: Db.Database):
        objHnd = Db.Handle("195e")
        objId = db_brep.getObjectId(False, objHnd)
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
                self.assertions.assertAlmostEqual(seg.length(), 100, 4)
            et.next()

    def test_BrepEdgeTraverserCubeList(self, db_brep: Db.Database):
        objHnd = Db.Handle("195e")
        objId = db_brep.getObjectId(False, objHnd)
        dbent = Db.Entity(objId)
        brep = Br.Brep(dbent)
        et = Br.EdgeTraverser(brep)
        assert len(et.getEdges()) == 12

    def test_BrepFaceTraverserCubeList(self, db_brep: Db.Database):
        objHnd = Db.Handle("195e")
        objId = db_brep.getObjectId(False, objHnd)
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
        assert areas == tareas
        assert types == ttypes
        assert ors == tors

    def test_BrepShellTraverserCubeList(self, db_brep: Db.Database):
        objHnd = Db.Handle("195e")
        objId = db_brep.getObjectId(False, objHnd)
        dbent = Db.Entity(objId)
        brep = Br.Brep(dbent)
        st = Br.ShellTraverser(brep)
        types = [shell.getType() for shell in st.getShells()]
        assert types == [Br.ShellType.kShellExterior]

    def test_BrepVertexTraverserList(self, db_brep: Db.Database):
        objHnd = Db.Handle("1392")
        objId = db_brep.getObjectId(False, objHnd)
        dbent = Db.Entity(objId)
        brep = Br.Brep(dbent)
        vt = Br.VertexTraverser(brep)
        pts = [vt.getPoint() for vt in vt.getVertexs()]
        assert len(pts) == 16
