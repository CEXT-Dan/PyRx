from __future__ import annotations

import pytest
from pyrx import Db, Ge


class TestFace:

    @pytest.fixture
    def warped_face(self) -> Db.Face:
        """Returns the baseline warped face from your test."""
        p0 = Ge.Point3d(-10, 10, 0)
        p1 = Ge.Point3d(-10, -10, 0)
        p2 = Ge.Point3d(10, -10, 0)
        p3 = Ge.Point3d(10, 10, 20)
        return Db.Face(p0, p1, p2, p3)

    @pytest.fixture
    def flat_quad(self) -> Db.Face:
        """A planar quadrilateral lying flat on the XY plane (Z=0)."""
        return Db.Face(
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(10, 0, 0),
            Ge.Point3d(10, 10, 0),
            Ge.Point3d(0, 10, 0),
        )

    @staticmethod
    def _pts() -> tuple[Ge.Point3d, Ge.Point3d, Ge.Point3d, Ge.Point3d]:
        """Standard 4 vertices: a non-planar (warped) quad, p3 lifted to Z=20."""
        return (
            Ge.Point3d(-10, 10, 0),
            Ge.Point3d(-10, -10, 0),
            Ge.Point3d(10, -10, 0),
            Ge.Point3d(10, 10, 20),
        )

    @staticmethod
    def _add_to_db(face: Db.Face) -> Db.ObjectId:
        """Adds the face to the modelspace and closes it. Caller must clean up via _erase."""
        face.setDatabaseDefaults()
        face_id = Db.curDb().addToModelspace(face)
        assert not face_id.isNull()
        face.close()
        return face_id

    @staticmethod
    def _erase(face_id: Db.ObjectId) -> None:
        """Soft-erases a face in the database (test cleanup)."""
        face = Db.Face(face_id, Db.OpenMode.kForWrite)
        face.erase()
        face.close()

    # ==================== Class introspection ====================

    def test_class_name(self):
        assert Db.Face.className() == "AcDbFace"

    def test_desc(self):
        assert Db.Face.desc().name() == "AcDbFace"

    def test_isa_and_iskindof(self, warped_face):
        assert warped_face.isA() == Db.Face.desc()
        assert warped_face.isA().name() == "AcDbFace"
        assert warped_face.isKindOf(Db.Face.desc())
        assert warped_face.isKindOf(Db.Entity.desc())
        assert warped_face.isKindOf(Db.DbObject.desc())

    def test_cast(self, warped_face):
        cast = Db.Face.cast(warped_face)
        assert isinstance(cast, Db.Face)
        for i, p in enumerate(self._pts()):
            assert cast.getVertexAt(i) == p

    def test_clone_from(self):
        face = Db.Face(*self._pts(), False, True, False, True)
        clone = Db.Face.cloneFrom(face)
        assert isinstance(clone, Db.Face)
        assert clone is not face
        assert clone.objectId().isNull()  # clone is not database resident
        for i, p in enumerate(self._pts()):
            assert clone.getVertexAt(i) == p
        for i in range(4):
            assert clone.isEdgeVisibleAt(i) == face.isEdgeVisibleAt(i)

    # ==================== Constructors ====================

    def test_ctor_default(self):
        face = Db.Face()
        assert face.objectId().isNull() == True
        assert face.isA() == Db.Face.desc()

    def test_ctor_3pts_triangle(self):
        p0, p1, p2 = Ge.Point3d(0, 0, 0), Ge.Point3d(10, 0, 0), Ge.Point3d(0, 10, 0)
        face = Db.Face(p0, p1, p2)
        assert face.objectId().isNull() == True
        assert face.getVertexAt(0) == p0
        assert face.getVertexAt(1) == p1
        assert face.getVertexAt(2) == p2
        # A 3-vertex face is a triangle: vertex 3 coincides with vertex 2.
        assert face.getVertexAt(3) == p2

    def test_ctor_4pts(self):
        p0, p1, p2, p3 = self._pts()
        face = Db.Face(p0, p1, p2, p3)
        for i, p in enumerate((p0, p1, p2, p3)):
            assert face.getVertexAt(i) == p

    def test_ctor_3pts_with_visibility(self):
        # NOTE: the binding takes 4 edge-visibility booleans (e0..e3), despite the .pyi showing 5.
        p0, p1, p2, _ = self._pts()
        face = Db.Face(p0, p1, p2, True, False, True, False)
        assert face.isEdgeVisibleAt(0) == True
        assert face.isEdgeVisibleAt(1) == False
        assert face.isEdgeVisibleAt(2) == True
        assert face.isEdgeVisibleAt(3) == False

    def test_ctor_4pts_with_visibility(self):
        face = Db.Face(*self._pts(), False, True, False, True)
        assert face.isEdgeVisibleAt(0) == False
        assert face.isEdgeVisibleAt(1) == True
        assert face.isEdgeVisibleAt(2) == False
        assert face.isEdgeVisibleAt(3) == True

    def test_ctor_from_objectid(self):
        p0, p1, p2, p3 = self._pts()
        face = Db.Face(p0, p1, p2, p3)
        face_id = self._add_to_db(face)

        ro = Db.Face(face_id)
        assert ro.objectId() == face_id
        assert ro.isReadEnabled() == True
        assert ro.isWriteEnabled() == False
        for i, p in enumerate((p0, p1, p2, p3)):
            assert ro.getVertexAt(i) == p
        ro.close()

        rw = Db.Face(face_id, Db.OpenMode.kForWrite)
        assert rw.isWriteEnabled() == True
        rw.close()

        self._erase(face_id)

    # ==================== Vertices ====================

    def test_get_vertex_roundtrip(self, warped_face):
        for i, p in enumerate(self._pts()):
            assert warped_face.getVertexAt(i) == p

    def test_set_vertex_roundtrip(self):
        face = Db.Face(*self._pts())
        new_pts = (
            Ge.Point3d(1, 2, 3),
            Ge.Point3d(4, 5, 6),
            Ge.Point3d(7, 8, 9),
            Ge.Point3d(10, 11, 12),
        )
        for i, p in enumerate(new_pts):
            face.setVertexAt(i, p)
        for i, p in enumerate(new_pts):
            assert face.getVertexAt(i) == p

    def test_set_vertex_persists_in_db(self):
        p0, p1, p2, p3 = self._pts()
        face = Db.Face(p0, p1, p2, p3)
        face_id = self._add_to_db(face)

        new_p0 = Ge.Point3d(99, 88, 77)
        rw = Db.Face(face_id, Db.OpenMode.kForWrite)
        rw.setVertexAt(0, new_p0)
        rw.close()

        ro = Db.Face(face_id)
        assert ro.getVertexAt(0) == new_p0
        ro.close()

        self._erase(face_id)

    def test_set_vertex_changes_intersection(self, warped_face):
        seg = Ge.LineSeg3d(Ge.Point3d(5, 5, 100), Ge.Point3d(5, 5, -100))
        assert warped_face.intersectWith(seg) == [Ge.Point3d(5, 5, 10)]
        # Flatten the lifted corner -> the face is planar at Z=0.
        warped_face.setVertexAt(3, Ge.Point3d(10, 10, 0))
        assert warped_face.intersectWith(seg) == [Ge.Point3d(5, 5, 0)]

    def test_get_vertex_invalid_index(self, warped_face):
        with pytest.raises(RuntimeError):
            warped_face.getVertexAt(4)
        # -1 dies at C++ arg conversion (unsigned parameter), not as an error status
        with pytest.raises((OverflowError, ValueError)):
            warped_face.getVertexAt(-1)

    def test_set_vertex_invalid_index(self, warped_face):
        with pytest.raises(RuntimeError):
            warped_face.setVertexAt(4, Ge.Point3d(1, 1, 1))

    # ==================== Edge visibility ====================

    def test_default_edge_visibility(self, warped_face):
        for i in range(4):
            assert warped_face.isEdgeVisibleAt(i) == True

    def test_make_edge_invisible(self):
        face = Db.Face(*self._pts())
        face.makeEdgeInvisibleAt(1)
        assert face.isEdgeVisibleAt(0) == True
        assert face.isEdgeVisibleAt(1) == False
        assert face.isEdgeVisibleAt(2) == True
        assert face.isEdgeVisibleAt(3) == True

    def test_make_edge_visible(self):
        face = Db.Face(*self._pts())
        face.makeEdgeInvisibleAt(0)
        face.makeEdgeInvisibleAt(2)
        face.makeEdgeVisibleAt(2)
        assert face.isEdgeVisibleAt(0) == False
        assert face.isEdgeVisibleAt(1) == True
        assert face.isEdgeVisibleAt(2) == True
        assert face.isEdgeVisibleAt(3) == True

    def test_edge_visibility_persists_in_db(self):
        face = Db.Face(*self._pts(), False, True, False, True)
        face_id = self._add_to_db(face)

        ro = Db.Face(face_id)
        assert ro.isEdgeVisibleAt(0) == False
        assert ro.isEdgeVisibleAt(1) == True
        assert ro.isEdgeVisibleAt(2) == False
        assert ro.isEdgeVisibleAt(3) == True
        ro.close()

        self._erase(face_id)

    def test_is_edge_visible_invalid_index(self, warped_face):
        with pytest.raises(RuntimeError):
            warped_face.isEdgeVisibleAt(4)

    # ==================== intersectWith: existing baseline tests ====================

    def test_intersect_warped_quadrant(self, warped_face):
        """Your original test: Checks intersection squarely inside the warped triangle."""
        ge_line_seg = Ge.LineSeg3d(Ge.Point3d(5, 5, 100), Ge.Point3d(5, 5, -100))
        results = warped_face.intersectWith(ge_line_seg)
        assert len(results) == 1
        assert results[0] == Ge.Point3d(5, 5, 10)

    def test_intersect_flat_quadrant(self, warped_face):
        """Checks the lower-left quadrant which should sit perfectly flat on Z=0."""
        ge_line_seg = Ge.LineSeg3d(Ge.Point3d(-5, -5, 100), Ge.Point3d(-5, -5, -100))
        results = warped_face.intersectWith(ge_line_seg)
        assert len(results) == 1
        assert results[0] == Ge.Point3d(-5, -5, 0)

    def test_intersect_on_diagonal_seam(self, warped_face):
        """Tests a line piercing exactly on the shared diagonal edge (p0 to p2).

        Verifies that your C++ tolerance check cleanly returns exactly 1 point instead of duplicates.
        """
        # Line passing through (0,0) which is on the diagonal seam between p0(-10,10) and p2(10,-10)
        ge_line_seg = Ge.LineSeg3d(Ge.Point3d(0, 0, 100), Ge.Point3d(0, 0, -100))
        results = warped_face.intersectWith(ge_line_seg)
        assert len(results) == 1
        assert results[0] == Ge.Point3d(0, 0, 0)

    def test_intersect_three_sided_face(self):
        """Verifies that 3-sided native triangles work flawlessly."""
        p0 = Ge.Point3d(-10, 10, 0)
        p1 = Ge.Point3d(-10, -10, 0)
        p2 = Ge.Point3d(10, -10, 0)
        # In AutoCAD, a 3-sided face sets p3 equal to p2
        db_face_tri = Db.Face(p0, p1, p2, p2)

        # Line passing through the lower flat triangle
        ge_line_seg = Ge.LineSeg3d(Ge.Point3d(-5, -5, 100), Ge.Point3d(-5, -5, -100))
        results = db_face_tri.intersectWith(ge_line_seg)
        assert len(results) == 1
        assert results[0] == Ge.Point3d(-5, -5, 0)

        # Line passing through where Triangle 2 would have been (upper right)
        # Should cleanly return 0 intersections now
        ge_line_seg_empty = Ge.LineSeg3d(Ge.Point3d(5, 5, 100), Ge.Point3d(5, 5, -100))
        results_empty = db_face_tri.intersectWith(ge_line_seg_empty)
        assert len(results_empty) == 0

    def test_no_intersection_miss(self, warped_face):
        """Verifies lines completely outside the perimeter return an empty list."""
        ge_line_seg = Ge.LineSeg3d(Ge.Point3d(20, 20, 100), Ge.Point3d(20, 20, -100))
        results = warped_face.intersectWith(ge_line_seg)
        assert len(results) == 0

    def test_no_intersection_parallel(self, warped_face):
        """Verifies lines running parallel to the face (and hovering above it) do not collide."""
        # Line segment running parallel above the face from Z=50
        ge_line_seg = Ge.LineSeg3d(Ge.Point3d(-5, -5, 50), Ge.Point3d(5, 5, 50))
        results = warped_face.intersectWith(ge_line_seg)
        assert len(results) == 0

    def test_intersect_short_segment_falls_short(self, warped_face):
        """Verifies bounded segments fail if they stop short along the Z axis."""
        # The sloped surface is at Z=10. 
        # By stopping the segment at Z=15, it now truly falls short and misses the surface.
        ge_line_seg = Ge.LineSeg3d(Ge.Point3d(5, 5, 100), Ge.Point3d(5, 5, 15))
        results = warped_face.intersectWith(ge_line_seg)
        assert len(results) == 0

    # ==================== intersectWith: additional coverage ====================

    def test_intersect_flat_quad_center(self, flat_quad):
        """A planar quad at Z=0 is hit at the expected Z by a vertical segment."""
        seg = Ge.LineSeg3d(Ge.Point3d(5, 5, 100), Ge.Point3d(5, 5, -100))
        assert flat_quad.intersectWith(seg) == [Ge.Point3d(5, 5, 0)]

    def test_intersect_at_lower_corner(self, warped_face):
        """A line through the shared corner (p1) on the flat triangle."""
        seg = Ge.LineSeg3d(Ge.Point3d(-10, -10, 100), Ge.Point3d(-10, -10, -100))
        assert warped_face.intersectWith(seg) == [Ge.Point3d(-10, -10, 0)]

    def test_intersect_at_lifted_corner(self, warped_face):
        """A line through the lifted corner (p3) hits at Z=20."""
        seg = Ge.LineSeg3d(Ge.Point3d(10, 10, 100), Ge.Point3d(10, 10, -100))
        assert warped_face.intersectWith(seg) == [Ge.Point3d(10, 10, 20)]

    def test_intersect_with_ray3d(self, warped_face):
        """Ray3d is also a LinearEnt3d and should intersect the same way."""
        ray = Ge.Ray3d(Ge.Point3d(5, 5, 100), Ge.Point3d(5, 5, -100))
        assert warped_face.intersectWith(ray) == [Ge.Point3d(5, 5, 10)]

    def test_intersect_with_line3d(self, warped_face):
        """An unbounded Line3d should intersect the face as well."""
        line = Ge.Line3d(Ge.Point3d(5, 5, 100), Ge.Point3d(5, 5, -100))
        assert warped_face.intersectWith(line) == [Ge.Point3d(5, 5, 10)]

    def test_intersect_returns_list_of_point3d(self, warped_face):
        seg = Ge.LineSeg3d(Ge.Point3d(5, 5, 100), Ge.Point3d(5, 5, -100))
        results = warped_face.intersectWith(seg)
        assert isinstance(results, list)
        assert all(isinstance(p, Ge.Point3d) for p in results)

    def test_intersect_miss_returns_empty_list(self, warped_face):
        seg = Ge.LineSeg3d(Ge.Point3d(20, 20, 100), Ge.Point3d(20, 20, -100))
        assert warped_face.intersectWith(seg) == []

    # ==================== Entity behavior ====================

    def test_object_id_null_until_added(self):
        face = Db.Face(*self._pts())
        assert face.objectId().isNull() == True
        face_id = self._add_to_db(face)
        assert face.objectId() == face_id
        self._erase(face_id)

    def test_color(self):
        # Face has no setNormal/thickness binding; colorIndex is shared by all entities.
        face = Db.Face(*self._pts())
        face.setColorIndex(3)
        assert face.colorIndex() == 3

    def test_cast_shadows(self):
        face = Db.Face(*self._pts())
        # castShadows() is a base Entity property; just verify it is queryable without error.
        assert face.castShadows() in (True, False)

    def test_erase(self):
        face = Db.Face(*self._pts())
        face_id = self._add_to_db(face)

        rw = Db.Face(face_id, Db.OpenMode.kForWrite)
        rw.erase()
        rw.close()

        # The erased=True ctor flag allows opening the erased object.
        erased = Db.Face(face_id, Db.OpenMode.kForRead, True)
        assert erased.isErased() == True
        erased.close()
        
    def test_centroid(self):
        # Test 1: 4-Point Quad Face (Centered at origin)
        p0 = Ge.Point3d(-10, 10, 0)
        p1 = Ge.Point3d(-10, -10, 0)
        p2 = Ge.Point3d(10, -10, 0)
        p3 = Ge.Point3d(10, 10, 0)
        db_face1 = Db.Face(p0, p1, p2, p3)
        centroid1 = db_face1.centroid()
        assert centroid1 == Ge.Point3d.kOrigin
        
        # Test 2: 3-Point Triangle Face (Symmetrical balance centered at origin)
        tp0 = Ge.Point3d(0, 10, 0)
        tp1 = Ge.Point3d(-10, -5, 0)
        tp2 = Ge.Point3d(10, -5, 0)
        db_face2 = Db.Face(tp0, tp1, tp2)
        centroid2 = db_face2.centroid()
        assert centroid2 == Ge.Point3d.kOrigin
        
        # Test 3: 3-Point Triangle Face with Z-axis offset
        # Expected centroid: (0, 0, 10)
        zp0 = Ge.Point3d(0, 10, 5)
        zp1 = Ge.Point3d(-10, -5, 10)
        zp2 = Ge.Point3d(10, -5, 15)
        db_face3 = Db.Face(zp0, zp1, zp2)
        centroid3 = db_face3.centroid()
        assert centroid3 == Ge.Point3d(0, 0, 10)
        
        