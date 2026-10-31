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
