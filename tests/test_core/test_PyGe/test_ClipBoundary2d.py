from __future__ import annotations

import pytest
from pyrx import Db, Ge

class TestClipBoundary2d:

    # --- 1. Segments Fully Inside the Bounding Box ---

    def test_segment_fully_inside_center(self):
        """A line segment completely inside the box should return the same length segment."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(2, 2), Ge.Point2d(8, 8))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        assert outseg.startPoint() == Ge.Point2d(2, 2)
        assert outseg.endPoint() == Ge.Point2d(8, 8)
        
        assert pytest.approx(outseg.length()) == pytest.approx(6 * (2 ** 0.5))
        assert outseg.length() == seg.length()

    def test_segment_fully_inside_corner(self):
        """A segment touching the top-left corner."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(0, 0), Ge.Point2d(5, 5))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        assert outseg.startPoint() == Ge.Point2d(0, 0)
        assert outseg.endPoint() == Ge.Point2d(5, 5)

    # --- 2. Segments Fully Outside the Bounding Box ---

    def test_segment_fully_outside_top(self):
        """Segment is completely above the box."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(0, 20), Ge.Point2d(10, 30))
        success, outseg = ex.clipLineSeg2d(seg)
        assert success == False


    def test_segment_fully_outside_bottom(self):
        """Segment is completely below the box."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(0, -20), Ge.Point2d(10, -10))
        success, outseg = ex.clipLineSeg2d(seg)
        assert success == False


    def test_segment_fully_outside_left(self):
        """Segment is completely to the left of the box."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(-20, 0), Ge.Point2d(-10, 10))
        success, outseg = ex.clipLineSeg2d(seg)
        assert success == False


    def test_segment_fully_outside_right(self):
        """Segment is completely to the right of the box."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(20, 0), Ge.Point2d(30, 10))
        success, outseg = ex.clipLineSeg2d(seg)
        assert success == False

    def test_segment_fully_outside_corner(self):
        """Segment is in the top-right quadrant relative to the box."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(20, 20), Ge.Point2d(30, 30))
        success, outseg = ex.clipLineSeg2d(seg)
        assert success == False

    # --- 3. Partial Overlap (Clipping) ---

    def test_partial_overlap_top_edge(self):
        """Segment enters from top and exits top (should result in empty segment)."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(0, 15), Ge.Point2d(10, 15))
        success, outseg = ex.clipLineSeg2d(seg)
        
        # Depending on implementation, this might return False or a zero-length segment
        # We expect no valid segment
        assert success == False


    def test_partial_overlap_vertical_side(self):
        """Segment enters from left and exits right."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(-5, 2), Ge.Point2d(15, 8))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        # Start should be clipped to x=0
        assert outseg.startPoint().x == 0
        # End should be clipped to x=10
        assert outseg.endPoint().x == 10
        # Y should be interpolated
        assert outseg.startPoint().y == 3.5
        assert outseg.endPoint().y == 6.5

    def test_partial_overlap_horizontal_side(self):
        """Segment enters from bottom and exits top."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(2, -5), Ge.Point2d(8, 15))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        # Start should be clipped to y=0
        assert outseg.startPoint().y == 0
        # End should be clipped to y=10
        assert outseg.endPoint().y == 10
        # X should be interpolated
        assert outseg.startPoint().x == 3.5
        assert outseg.endPoint().x == 6.5

    def test_partial_overlap_corner_entry(self):
        """Segment enters at the top-left corner."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(-5, 15), Ge.Point2d(5, 5))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        # Should start at (0, 10) and end at (5, 5)
        assert outseg.startPoint().x == 0
        assert outseg.startPoint().y == 10
        assert outseg.endPoint().x == 5
        assert outseg.endPoint().y == 5

    def test_partial_overlap_corner_exit(self):
        """Segment exits at the bottom-right corner."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(5, 5), Ge.Point2d(15, -5))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        # Should start at (5, 5) and end at (10, 0)
        assert outseg.startPoint().x == 5
        assert outseg.startPoint().y == 5
        assert outseg.endPoint().x == 10
        assert outseg.endPoint().y == 0

    # --- 4. Tangency (Touching Edges) ---

    def test_tangent_horizontal_top(self):
        """Segment lies exactly on the top edge."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(0, 10), Ge.Point2d(10, 10))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        assert outseg.startPoint() == Ge.Point2d(0, 10)
        assert outseg.endPoint() == Ge.Point2d(10, 10)

    def test_tangent_horizontal_bottom(self):
        """Segment lies exactly on the bottom edge."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(0, 0), Ge.Point2d(10, 0))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        assert outseg.startPoint() == Ge.Point2d(0, 0)
        assert outseg.endPoint() == Ge.Point2d(10, 0)

    def test_tangent_vertical_left(self):
        """Segment lies exactly on the left edge."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(0, 0), Ge.Point2d(0, 10))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        assert outseg.startPoint() == Ge.Point2d(0, 0)
        assert outseg.endPoint() == Ge.Point2d(0, 10)

    def test_tangent_vertical_right(self):
        """Segment lies exactly on the right edge."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(10, 0), Ge.Point2d(10, 10))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        assert outseg.startPoint() == Ge.Point2d(10, 0)
        assert outseg.endPoint() == Ge.Point2d(10, 10)

    def test_segment_fully_inside_diagonal(self):
        """Diagonal segment from Top-Left to Bottom-Right is fully inside."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(0, 10), Ge.Point2d(10, 0))
        success, outseg = ex.clipLineSeg2d(seg)
        assert success == True
        assert outseg.length() == pytest.approx(14.142135623730951)

    # --- 5. Edge Cases & Degeneracy ---

    def test_zero_length_segment_inside(self):
        """A point inside the box."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(5, 5), Ge.Point2d(5, 5))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == False #zero length is false
        assert outseg.startPoint() == Ge.Point2d(5, 5)
        assert outseg.endPoint() == Ge.Point2d(5, 5)

    def test_zero_length_segment_outside(self):
        """A point outside the box."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(20, 20), Ge.Point2d(20, 20))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == False


    def test_segment_parallel_to_edge(self):
        """Segment is parallel to the top edge but inside."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(2, 5), Ge.Point2d(8, 5))
        success, outseg = ex.clipLineSeg2d(seg)
        
        assert success == True
        assert outseg.startPoint().y == 5
        assert outseg.endPoint().y == 5

    def test_segment_parallel_to_edge_outside(self):
        """Segment is parallel to the top edge but outside."""
        ex = Db.Extents2d(Ge.Point2d(0, 0), Ge.Point2d(10, 10))
        seg = Ge.LineSeg2d(Ge.Point2d(2, 15), Ge.Point2d(8, 15))
        success, outseg = ex.clipLineSeg2d(seg)
        assert success == False

    def test_box_with_negative_coordinates_1(self):
        """Box and segment with negative coordinates."""
        ex = Db.Extents2d(Ge.Point2d(-10, -10), Ge.Point2d(0, 0))
        seg = Ge.LineSeg2d(Ge.Point2d(-15, -5), Ge.Point2d(-5, 5))
        success, outseg = ex.clipLineSeg2d(seg)
    
        assert success == False
        
    def test_box_with_negative_coordinates_2(self):
        """Box and segment with negative coordinates."""
        ex = Db.Extents2d(Ge.Point2d(-10, -10), Ge.Point2d(0, 0))
        seg = Ge.LineSeg2d(Ge.Point2d(-10, -10), Ge.Point2d(0, 0))
        success, outseg = ex.clipLineSeg2d(seg)
        
        outseg.length() == seg.length()
        assert success == True


