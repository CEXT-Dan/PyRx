from __future__ import annotations

import math
import pytest

from pyrx import Ap, Db, Ge


def create_polyline():
    pnts = []
    pnts.append(Ge.Point3d(0, 0, 0))
    pnts.append(Ge.Point3d(2, 0, 0))
    pnts.append(Ge.Point3d(2, 2, 0))
    pnts.append(Ge.Point3d(0, 2, 0))
    pnts.append(Ge.Point3d(0, 0, 0))
    return Db.Polyline(pnts)


class TestDbPolyline:

    def test_polyline_listctor1(self):
        pnts = []
        pnts.append(Ge.Point2d(0, 0))
        pnts.append(Ge.Point2d(1, 0))
        pnts.append(Ge.Point2d(1, 1))
        pnts.append(Ge.Point2d(0, 1))
        pnts.append(Ge.Point2d(0, 0))
        pline = Db.Polyline(pnts)
        assert pline.numVerts() == 5
        assert len(pline.toPoint2dList()) == 5
        assert len(pline.toPoint3dList()) == 5
        assert len(pline.toList()) == 5
        assert pline.toPoint2dList() == pnts

    def test_polyline_listctor2(self):
        pnts = []
        pnts.append(Ge.Point3d(0, 0, 0))
        pnts.append(Ge.Point3d(2, 0, 0))
        pnts.append(Ge.Point3d(2, 2, 0))
        pnts.append(Ge.Point3d(0, 2, 0))
        pnts.append(Ge.Point3d(0, 0, 0))
        pline = Db.Polyline(pnts)
        assert pline.numVerts() == 5
        assert len(pline.toPoint2dList()) == 5
        assert len(pline.toPoint3dList()) == 5
        assert len(pline.toList()) == 5
        assert pline.toPoint3dList() == pnts

    def test_polyline_listctor3(self):
        pnts = []
        pnts.append((0, 0))
        pnts.append((3, 0))
        pnts.append((3, 3))
        pnts.append((0, 3))
        pnts.append((0, 0))
        pline = Db.Polyline(pnts)
        assert pline.numVerts() == 5
        assert len(pline.toPoint2dList()) == 5
        assert len(pline.toPoint3dList()) == 5
        assert len(pline.toList()) == 5

    def test_polyline_listctor4(self):
        pnts = []
        pnts.append((0, 0, 0))
        pnts.append((4, 0, 0))
        pnts.append((4, 4, 0))
        pnts.append((0, 4, 0))
        pnts.append((0, 0, 0))
        pline = Db.Polyline(pnts)
        assert pline.numVerts() == 5
        assert len(pline.toPoint2dList()) == 5
        assert len(pline.toPoint3dList()) == 5
        assert len(pline.toList()) == 5

    def test_polyline_listctor5(self):
        pnts = []
        pnts.append([0, 0])
        pnts.append([5, 0])
        pnts.append([5, 5])
        pnts.append([0, 5])
        pnts.append([0, 0])
        pline = Db.Polyline(pnts)
        assert pline.numVerts() == 5
        assert len(pline.toPoint2dList()) == 5
        assert len(pline.toPoint3dList()) == 5
        assert len(pline.toList()) == 5

    def test_polyline_listctor6(self):
        pnts = []
        pnts.append([0, 0, 0])
        pnts.append([6, 0, 0])
        pnts.append([6, 6, 0])
        pnts.append([0, 6, 0])
        pnts.append([0, 0, 0])
        pline = Db.Polyline(pnts)
        assert pline.numVerts() == 5
        assert len(pline.toPoint2dList()) == 5
        assert len(pline.toPoint3dList()) == 5
        assert len(pline.toList()) == 5

    def test_polyline_listctor7(self):
        pnts = Ge.Point3dArray()
        pnts.append(Ge.Point3d(0, 0, 0))
        pnts.append(Ge.Point3d(2, 0, 0))
        pnts.append(Ge.Point3d(2, 2, 0))
        pnts.append(Ge.Point3d(0, 2, 0))
        pnts.append(Ge.Point3d(0, 0, 0))
        pline = Db.Polyline(pnts)
        assert pline.numVerts() == 5
        assert len(pline.toPoint2dList()) == 5
        assert len(pline.toPoint3dList()) == 5
        assert len(pline.toList()) == 5

    def test_polyline_listctor8(self):
        pnts = Ge.Point2dArray()
        pnts.append(Ge.Point2d(0, 0))
        pnts.append(Ge.Point2d(1, 0))
        pnts.append(Ge.Point2d(1, 1))
        pnts.append(Ge.Point2d(0, 1))
        pnts.append(Ge.Point2d(0, 0))
        pline = Db.Polyline(pnts)
        assert pline.numVerts() == 5
        assert len(pline.toPoint2dList()) == 5
        assert len(pline.toPoint3dList()) == 5
        assert len(pline.toList()) == 5

    def test_polyline_constructor_no_args(self):
        # Test default constructor (no args)
        pline = Db.Polyline()
        assert pline.numVerts() == 0
        assert isinstance(pline, Db.Polyline)

    def test_polyline_constructor_with_num_verts(self):
        # Test constructor with number of vertices
        pline = Db.Polyline(3)
        assert pline.numVerts() == 0  # No points yet added

    def test_add_vertex_at(self):
        # Create a basic polyline first
        pline = create_polyline()
        original_count = pline.numVerts()

        # Add vertex at the beginning
        new_point = Ge.Point2d(1, 1)
        pline.addVertexAt(0, new_point)

        assert pline.numVerts() == original_count + 1
        assert pline.getPoint2dAt(0) == new_point

        # Add vertex in middle (should be at index 2 now due to previous insert)
        another_point = Ge.Point2d(3, 3)
        pline.addVertexAt(2, another_point)

        assert pline.numVerts() == original_count + 2
        assert pline.getPoint2dAt(2) == another_point

    def test_remove_vertex_at(self):
        pline = create_polyline()

        # Remove last vertex (should be the duplicate start/end point)
        old_count = pline.numVerts()
        pline.removeVertexAt(old_count - 1)

        assert pline.numVerts() == old_count - 1

    def test_get_point_at(self):
        pline = create_polyline()

        # Get first vertex
        pt = pline.getPoint3dAt(0)
        expected = Ge.Point3d(0, 0, 0)
        assert pt == expected

        # Get last vertex (should be the duplicate start point in this case)
        pt_last = pline.getPoint2dAt(pline.numVerts() - 1)  # Last item
        expected_last = Ge.Point2d(0, 0)
        assert pt_last == expected_last

    def test_get_bulge_at(self):
        pline = create_polyline()
        # All lines have bulge=0 by default (no arcs)
        for i in range(pline.numVerts()):
            bulge = pline.getBulgeAt(i)
            if i < pline.numVerts() - 1:  # Last vertex is the same as first
                assert bulge == 0.0

    def test_has_bulges(self):
        pline = create_polyline()
        assert not pline.hasBulges()

    def test_is_only_lines(self):
        pline = create_polyline()
        assert pline.isOnlyLines() == True

    def test_normal_and_elevation(self):
        pline = create_polyline()
        normal = pline.normal()
        elevation = pline.elevation()
        # Should be a vector perpendicular to the plane (z-axis for XY-plane)
        expected_normal = Ge.Vector3d(0, 0, 1)
        assert abs(normal.x - expected_normal.x) < 1e-6
        assert abs(normal.y - expected_normal.y) < 1e-6
        assert abs(normal.z - expected_normal.z) < 1e-6
        # Elevation should be zero for a planar polygon in XY plane
        assert elevation == 0.0

    def test_set_closed(self):
        pline = create_polyline()
        assert pline.numVerts() > 2  # Ensure we have at least one segment to close

        # Test setting closed as False (open)
        pline.setClosed(False)
        # Note: This may not change the actual count of vertices, just flag.

    def test_set_thickness(self):
        pline = create_polyline()
        thickness_value = 5.0
        pline.setThickness(thickness_value)

        retrieved_thickness = pline.thickness()
        assert abs(retrieved_thickness - thickness_value) < 1e-6

    def test_constant_width_methods(self):
        pline = create_polyline()

        # Try setting constant width
        width_value = 2.0
        pline.setConstantWidth(width_value)

        retrieved_width = pline.getConstantWidth()
        assert abs(retrieved_width - width_value) < 1e-6

    def test_get_line_segments(self):
        pline = create_polyline()

        # Get first line segment (between vertex 0 and 1)
        line_seg_2d = pline.getLineSeg2dAt(0)
        assert isinstance(line_seg_2d, Ge.LineSeg2d)

        line_seg_3d = pline.getLineSeg3dAt(0)
        assert isinstance(line_seg_3d, Ge.LineSeg3d)

    def test_seg_type(self):
        pline = create_polyline()

        # All segments should be lines
        for i in range(pline.numVerts() - 1):  # Exclude last since it wraps around
            seg_type = pline.segType(i)
            assert seg_type.name == "kLine"

    def test_reset(self):
        pline = create_polyline()
        pline.reset(False, 2)
        pnts = [Ge.Point2d(1, 1), Ge.Point2d(2, 2)]
        for i, pt in enumerate(pnts):
            pline.addVertexAt(i, pt)
        assert pline.numVerts() == 2

    def test_num_verts(self):
        pline = create_polyline()
        # Should be 5 vertices (including duplicate start/end)
        expected_count = 5
        actual_count = pline.numVerts()
        assert actual_count == expected_count

    def test_to_list_functions(self):
        pline = create_polyline()

        point2d_list = pline.toPoint2dList()
        point3d_list = pline.toPoint3dList()
        list_form = pline.toList()

        # Check types
        assert isinstance(point2d_list, list)
        assert isinstance(point3d_list, list)
        assert isinstance(list_form, list)

        # Lengths should match number of vertices
        assert len(point2d_list) == pline.numVerts()
        assert len(point3d_list) == pline.numVerts()
        assert len(list_form) == pline.numVerts()

    def test_get_segments(self):
        pline = create_polyline()  # Regular lines, no arcs
        for i in range(pline.numVerts() - 1):
            seg_3d = pline.getLineSeg3dAt(i)
            seg_3d.type() == Ge.EntityId.kLineSeg3d

    def test_polyline_isPointInside(self, db_06457: Db.Database):
        desc = Db.Polyline.desc()
        model = Db.BlockTableRecord(db_06457.modelSpaceId())
        plines = [Db.Polyline(id) for id in model.objectIds(desc)]

        c = 0
        p = Ge.Point3d(-32381.8897, 1917.3546, 0.0000)

        for pline in plines:
            if pline.isPointInside(p):
                c += 1
        assert c == 5

    def test_polyline_isCCW(self, db_06457: Db.Database):
        objHnd1 = Db.Handle("2c92e2")
        objId1 = db_06457.getObjectId(False, objHnd1)
        pline1 = Db.Polyline(objId1)
        assert pline1.isCCW() == False

        objHnd2 = Db.Handle("2c9703")
        objId2 = db_06457.getObjectId(False, objHnd2)
        pline2 = Db.Polyline(objId2)
        assert pline2.isCCW() == True
        
    def test_length(self):
        # Create a basic polyline first
        pline = create_polyline()
        assert pline.length() == 8.0