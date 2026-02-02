from __future__ import annotations
from pyrx import Db, Ge
import pytest


class TestDbPolyline2d:

    def test_create_1(self):
        """
        Tests creating a simple polyline and verifying vertex positions.
        """
        db = Db.curDb()
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(2, 0, 0),
            Ge.Point3d(2, 2, 0),
            Ge.Point3d(0, 2, 0),
            Ge.Point3d(0, 0, 0),
        ]

        # Create polyline and add to database
        pline = Db.Polyline2d(Db.Poly2dType.k2dSimplePoly, pnts, False)
        db.addToModelspace(pline)

        # Verify vertices exist and have correct positions
        vtids = pline.vertexIds()
        assert len(vtids) == 5

        for i, expected_pos in enumerate(pnts):
            vt = Db.Vertex2d(vtids[i])
            assert vt.position() == expected_pos

    def test_create_2_object_id(self):
        """
        Tests creating a polyline via ObjectId constructor.
        This is necessary to test database-resident operations like appendVertex.
        """
        db = Db.curDb()
        pnts = [Ge.Point3d(0, 0, 0), Ge.Point3d(1, 1, 0)]

        # Create and add to DB
        pline = Db.Polyline2d(Db.Poly2dType.k2dSimplePoly, pnts, False)
        id = db.addToModelspace(pline)
        pline.close()

        # Re-open using ObjectId
        pline_open = Db.Polyline2d(id, Db.OpenMode.kForWrite)

        # Verify we can access properties
        assert pline_open.length() > 0
        assert pline_open.elevation() == 0.0

    def test_append_vertex(self):
        """
        Tests appending a vertex to an existing polyline.
        """
        db = Db.curDb()
        pnts = [Ge.Point3d(0, 0, 0), Ge.Point3d(2, 0, 0)]

        pline = Db.Polyline2d(Db.Poly2dType.k2dSimplePoly, pnts, False)
        id = db.addToModelspace(pline)
        pline.close()

        # Open for write to modify
        pline_open = Db.Polyline2d(id, Db.OpenMode.kForWrite)

        # Create a new vertex
        new_pt = Ge.Point3d(4, 0, 0)
        new_vt = Db.Vertex2d(new_pt)

        # Append vertex
        pline_open.appendVertex(new_vt)
        new_vt.close()

        # Verify
        vtids = pline_open.vertexIds()
        assert len(vtids) == 3
        last_vt = Db.Vertex2d(vtids[-1])
        assert last_vt.position() == new_pt

    def test_insert_vertex_at(self):
        """
        Tests inserting a vertex at a specific index.
        """
        db = Db.curDb()
        pnts = [Ge.Point3d(0, 0, 0), Ge.Point3d(2, 0, 0), Ge.Point3d(2, 2, 0)]

        pline = Db.Polyline2d(Db.Poly2dType.k2dSimplePoly, pnts, False)
        id = db.addToModelspace(pline)
        pline.close()

        pline_open = Db.Polyline2d(id, Db.OpenMode.kForWrite)

        # Insert a vertex between index 0 and 1
        new_vt = Db.Vertex2d()
        new_vt.setPosition(Ge.Point3d(1, 0, 0))

        # Insert after the first vertex (index 0)
        ids = pline_open.vertexIds()
        outId = Db.ObjectId()
        pline_open.insertVertexAt(outId, ids[0], new_vt)
        assert outId.isNull() == False
        new_vt.close()

        # Verify
        vtids = pline_open.vertexIds()
        assert len(vtids) == 4

        # Check the new vertex is at index 1
        inserted_vt = Db.Vertex2d(vtids[1])
        assert inserted_vt.position() == Ge.Point3d(1, 0, 0)

    def test_make_closed(self):
        """
        Tests making a polyline closed.
        """
        db = Db.curDb()
        pnts = [Ge.Point3d(0, 0, 0), Ge.Point3d(2, 0, 0), Ge.Point3d(2, 2, 0)]

        pline = Db.Polyline2d(Db.Poly2dType.k2dSimplePoly, pnts, False)
        id = db.addToModelspace(pline)
        pline.close()

        pline_open = Db.Polyline2d(id, Db.OpenMode.kForWrite)

        # Make closed
        pline_open.makeClosed()

          # Verify
        assert pline_open.isClosed() == True
    
    def test_spline_fit(self):
        """
        Tests converting a polyline to a spline fit type.
        """
        db = Db.curDb()
        pnts = [Ge.Point3d(0, 0, 0), Ge.Point3d(1, 1, 0), Ge.Point3d(2, 0, 0)]

        pline = Db.Polyline2d(Db.Poly2dType.k2dFitCurvePoly, pnts, False)
        id = db.addToModelspace(pline)

        pline.close()
        pline_open = Db.Polyline2d(id, Db.OpenMode.kForWrite)

        # Perform spline fit
        pline_open.splineFit()

        # Verify type changed
        # k2dFitCurvePoly is the type for curve fit
        assert pline_open.polyType() == Db.Poly2dType.k2dCubicSplinePoly

    def test_straighten(self):
        """
        Tests removing spline/curve-fit vertices.
        """
        db = Db.curDb()
        pnts = [Ge.Point3d(0, 0, 0), Ge.Point3d(1, 1, 0), Ge.Point3d(2, 0, 0)]

        pline = Db.Polyline2d(Db.Poly2dType.k2dSimplePoly, pnts, False)
        id = db.addToModelspace(pline)
        pline.close()

        pline_open = Db.Polyline2d(id, Db.OpenMode.kForWrite)

        # Perform spline fit first
        pline_open.splineFit()

        # Now straighten
        pline_open.straighten()

        # Verify type reverted to simple
        assert pline_open.polyType() == Db.Poly2dType.k2dSimplePoly

    def test_thickness_and_elevation(self):
        """
        Tests setting and getting thickness and elevation.
        """
        db = Db.curDb()
        pnts = [Ge.Point3d(0, 0, 0), Ge.Point3d(1, 1, 0), Ge.Point3d(2, 0, 0)]

        pline = Db.Polyline2d(Db.Poly2dType.k2dSimplePoly, pnts, False)
        id = db.addToModelspace(pline)
        pline.close()

        pline_open = Db.Polyline2d(id, Db.OpenMode.kForWrite)

        # Set values
        pline_open.setThickness(5.0)
        pline_open.setElevation(10.0)

        # Get values
        assert pline_open.thickness() == 5.0
        assert pline_open.elevation() == 10.0
