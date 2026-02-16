from __future__ import annotations

import pytest
from pyrx import Db, Ge


class TestDelaunator:
    
    def test_triangles(self):
        """
        Test that the Delaunator correctly triangulates a set of points.
        We use a known set of points (a square) to verify the output.
        """
        # 1. Setup: Create a square of points
        pnts = Ge.Point3dArray()
        pnts.append(Ge.Point3d(0, 0, 0))
        pnts.append(Ge.Point3d(1, 0, 0))
        pnts.append(Ge.Point3d(1, 1, 0))
        pnts.append(Ge.Point3d(0, 1, 0))

        # 2. Execute: Create Delaunator instance
        d = Ge.Delaunator(pnts)

        # 3. Retrieve results
        triangles = d.triangles()

        # 4. Validate: 
        # A Delaunay triangulation of a convex hull (square) should result in 2 triangles.
        # The indices should be 0, 1, 2 and 0, 2, 3 (or a rotation thereof).
        assert len(triangles) == 6, f"Expected 6 indices (2 triangles), got {len(triangles)}"
        
        # Check that the triangles are valid (no repeated indices in a single triangle)
        for i in range(0, len(triangles), 3):
            t = triangles[i:i+3]
            assert len(set(t)) == 3, f"Triangle {t} has duplicate indices"

    def test_halfedges(self):
        """
        Test that halfedges are correctly generated and form a valid mesh structure.
        """
        # 1. Setup: Create a set of random points
        pnts = Ge.Point3dArray()
        pnts.append(Ge.Point3d(0, 0, 0))
        pnts.append(Ge.Point3d(2, 0, 0))
        pnts.append(Ge.Point3d(1, 1, 0))
        pnts.append(Ge.Point3d(0, 2, 0))
        pnts.append(Ge.Point3d(1, 3, 0))

        # 2. Execute
        d = Ge.Delaunator(pnts)
        triangles = d.triangles()
        halfedges = d.halfedges()

        # 3. Validate
        # There should be 3 triangles, so 6 halfedges.
        assert len(halfedges) == len(triangles), "Halfedges count must match triangles count"

        # Validate that every halfedge has a valid partner
        for i, edge in enumerate(halfedges):
            # If edge is -1, it is a boundary edge (no partner)
            if edge != -1:
                # The partner of halfedge i should be halfedge i+1 (or i-1 depending on winding)
                # In standard Delaunator, the opposite halfedge of triangle[i] is triangle[i+1]
                assert edge < len(triangles), f"Halfedge {i} points to invalid triangle index {edge}"
                
                # Verify that the partner halfedge actually points back to i
                # (This depends on the winding order of the library, but usually they are symmetric)
                # Assuming standard winding: edge i is opposite edge i+1
                assert halfedges[edge] == i, f"Halfedge {i} and {edge} are not mutual partners"

    def test_empty_collection(self):
        """
        Test behavior with an empty point collection.
        """
        pnts = Ge.Point3dArray()
        
        # Depending on the implementation, this might raise an error or return empty arrays
        with pytest.raises(Db.ErrorStatusException): 
            d = Ge.Delaunator(pnts)


    def test_duplicate_points(self):
        """
        Test that the wrapper handles duplicate points gracefully.
        """
        pnts = Ge.Point3dArray()
        pnts.append(Ge.Point3d(0, 0, 0))
        pnts.append(Ge.Point3d(0, 0, 0)) # Duplicate
        pnts.append(Ge.Point3d(2, 0, 0))
        pnts.append(Ge.Point3d(1, 1, 0))
        pnts.append(Ge.Point3d(0, 2, 0))
        pnts.append(Ge.Point3d(1, 3, 0))
        
        d = Ge.Delaunator(pnts)
        triangles = d.triangles()
        
        # Should ideally handle this without crashing
        assert isinstance(triangles, list)

    def test_convex_hull(self):
        """
        Test that points on the convex hull are handled correctly.
        """
        # A triangle shape
        pnts = Ge.Point3dArray()
        pnts.append(Ge.Point3d(0, 0, 0))
        pnts.append(Ge.Point3d(1, 0, 0))
        pnts.append(Ge.Point3d(0.5, 0.866, 0)) # Equilateral triangle height approx
        
        d = Ge.Delaunator(pnts)
        triangles = d.triangles()
        
        # Should result in exactly 1 triangle
        assert len(triangles) == 3
