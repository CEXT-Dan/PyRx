from __future__ import annotations

from pyrx import Ge


class TestPoint3d:
    def test_repr(self):
        val = Ge.Point3d(1.2, 2.3, 4.5)
        assert (
            val.__repr__()
            == "PyGe.Point3d(1.20000000000000,2.30000000000000,4.50000000000000)"
        )

    def test_point3d_len(self):
        pO = Ge.Point3d(0, 0, 0)
        assert len(pO) == 3

    def test_point3d_toVec(self):
        pO = Ge.Point3d(0, 0, 0)
        p1 = Ge.Point3d(0, 100, 0)
        v1 = p1 - pO
        assert v1.length() == 100
        assert v1.isParallelTo(Ge.Vector3d.kYAxis) == True

    def test_point3d_arg_ctor(self):
        point = Ge.Point3d(100, 100, 0)
        assert point == Ge.Point3d(100, 100, 0)
        point2 = Ge.Point3d([300, 400])
        assert point2 == Ge.Point3d(300, 400, 0)
        point3 = Ge.Point3d((400, 500))
        assert point3 == Ge.Point3d(400, 500, 0)
        point4 = Ge.Point3d([300, 400, 500])
        assert point4 == Ge.Point3d(300, 400, 500)
        point5 = Ge.Point3d((400, 500, 600))
        assert point5 == Ge.Point3d(400, 500, 600)
        point6 = Ge.Point3d([300, 400, 500, 900])
        assert point6 == Ge.Point3d(300, 400, 500)
        point7 = Ge.Point3d((400, 500, 600, 900))
        assert point7 == Ge.Point3d(400, 500, 600)

    def test_point3d_getset(self):
        pO = Ge.Point3d(1, 2, 3)
        x = pO[0]
        y = pO[1]
        z = pO[2]
        assert x == 1.0
        assert y == 2.0
        assert z == 3.0
        pO[0] = 12
        pO[1] = 13
        pO[2] = 14
        assert pO.x == 12.0
        assert pO.y == 13.0
        assert pO.z == 14.0

    def test_point3dlist_getset(self):
        iterable = [1, 2, 3]
        pO = Ge.Point3d(iterable)
        x = pO[0]
        y = pO[1]
        z = pO[2]
        assert x == 1.0
        assert y == 2.0
        assert z == 3.0
        pO[0] = 12
        pO[1] = 13
        pO[2] = 14
        assert pO.x == 12.0
        assert pO.y == 13.0
        assert pO.z == 14.0

    def test_point3dtuple_getset(self):
        iterable = (1, 2, 3)
        pO = Ge.Point3d(iterable)
        x = pO[0]
        y = pO[1]
        z = pO[2]
        assert x == 1.0
        assert y == 2.0
        assert z == 3.0
        pO[0] = 12
        pO[1] = 13
        pO[2] = 14
        assert pO.x == 12.0
        assert pO.y == 13.0
        assert pO.z == 14.0

    def test_Point3dArray_init(self):
        vals = [Ge.Point3d(0, 0, 0), Ge.Point3d(10, 0, 0), Ge.Point3d(10, 10, 0)]
        pnts = Ge.Point3dArray(vals)
        assert pnts[2] == vals[2]

    def test_Point3dArray_sort(self):
        pnts = Ge.Point3dArray()
        for i in range(5, 0, -1):
            pnts.append(Ge.Point3d(i, i, i))
        assert pnts[0] != Ge.Point3d(1, 1, 1)
        pnts.sortByDistFrom(Ge.Point3d(0, 0, 0))
        assert pnts[0] == Ge.Point3d(1, 1, 1)

    def test_Point3dTree_knn(self):
        pnts = Ge.Point3dArray()
        for x in range(10):
            for y in range(10):
                for z in range(10):
                    pnts.append(Ge.Point3d(x, y, z))

        tree = Ge.Point3dTree(pnts)
        idxs, _ = tree.knnSearch(Ge.Point3d(0.4, 0.4, 0.4), 1)
        assert pnts[0] == pnts[idxs[0]]

        idxs, _ = tree.knnSearch(Ge.Point3d(10.4, 10.4, 10.4), 1)
        assert pnts[999] == pnts[idxs[0]]

    def test_mirror(self):
        """Test mirror operation"""
        planeA1 = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kZAxis)
        point1 = Ge.Point3d(25, 35, 100)
        result = point1.mirror(planeA1)
        expected = Ge.Point3d(25, 35, -100)
        assert result.isEqualTo(expected)

    def test_convert2d(self):
        """Test 2D conversion"""
        planeA1 = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kZAxis)
        point1 = Ge.Point3d(25, 35, 100)
        result = point1.convert2d(planeA1)
        expected = Ge.Point2d(25, 35)
        assert result.isEqualTo(expected)

    def test_ortho_project(self):
        """Test orthogonal projection"""
        planeA1 = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kZAxis)
        point1 = Ge.Point3d(25, 35, 100)
        result = point1.orthoProject(planeA1)
        expected = Ge.Point3d(25, 35, 0)
        assert result.isEqualTo(expected)

    def test_project(self):
        """Test general projection"""
        planeA1 = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kZAxis)
        point1 = Ge.Point3d(25, 35, 100)
        direction_vector = Ge.Point3d(10, 5, 1) - point1
        result = point1.project(planeA1, direction_vector)
        assert abs(result.z) < 1e-10

    def test_project_with_different_direction(self):
        """Test general projection with a different direction"""
        planeA1 = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kZAxis)
        point1 = Ge.Point3d(25, 35, 100)
        direction_vector = Ge.Vector3d.kZAxis
        result = point1.project(planeA1, direction_vector)
        expected = point1.orthoProject(planeA1)
        assert result.isEqualTo(expected)

    def test_project_with_zero_direction(self):
        """Test general projection with negative Z-axis direction"""
        planeA1 = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kZAxis)
        point1 = Ge.Point3d(25, 35, 100)
        direction_vector = Ge.Vector3d.kZAxis * -1
        result = point1.project(planeA1, direction_vector)
        expected = point1.orthoProject(planeA1)
        assert result.isEqualTo(expected)

    def test_rotate_by(self):
        """Test rotation around an axis"""
        point = Ge.Point3d(1, 0, 0)
        axis = Ge.Vector3d.kZAxis
        center = Ge.Point3d.kOrigin

        # Rotate 90 degrees counterclockwise around Z-axis
        result = point.rotateBy(1.5708, axis, center)
        expected = Ge.Point3d(0, 1, 0)
        tol = Ge.Tol()
        tol.setEqualPoint(1e4)
        assert result.isEqualTo(expected, tol)

    def test_scale_by(self):
        """Test scaling from origin"""
        point = Ge.Point3d(2, 4, 6)
        factor = 2.0
        center = Ge.Point3d.kOrigin

        result = point.scaleBy(factor, center)
        expected = Ge.Point3d(4, 8, 12)
        assert result.isEqualTo(expected)

    def test_scale_by_with_center(self):
        """Test scaling from a specific center point"""
        point = Ge.Point3d(2, 4, 6)
        factor = 0.5
        center = Ge.Point3d(1, 2, 3)

        result = point.scaleBy(factor, center)
        # Calculation: (point - center) * factor + center
        expected = Ge.Point3d((2 - 1) * 0.5 + 1, (4 - 2) * 0.5 + 2, (6 - 3) * 0.5 + 3)
        assert result.isEqualTo(expected)

    def test_set_method(self):
        """Test the set method with different parameters"""
        point = Ge.Point3d(0, 0, 0)

        # Set with x,y,z
        point.set(1, 2, 3)
        assert point == Ge.Point3d(1, 2, 3)

        # Test setting to origin
        point.set(0.0, 0.0, 0.0)
        assert point == Ge.Point3d.kOrigin

    def test_point3d_addition(self):
        """Test Point3d addition with Vector3d"""
        p1 = Ge.Point3d(1, 2, 3)
        v = Ge.Vector3d(4, 5, 6)
        result = p1 + v
        expected = Ge.Point3d(5, 7, 9)
        assert result.isEqualTo(expected)

    def test_point3d_subtraction(self):
        """Test Point3d subtraction with another Point3d"""
        p1 = Ge.Point3d(5, 7, 9)
        p2 = Ge.Point3d(1, 2, 3)
        result = p1 - p2
        expected = Ge.Vector3d(4, 5, 6)
        assert result.isEqualTo(expected)

    def test_point3d_multiplication(self):
        """Test Point3d multiplication with scalar"""
        p1 = Ge.Point3d(2, 4, 6)
        result = p1 * 2.0
        expected = Ge.Point3d(4, 8, 12)
        assert result.isEqualTo(expected)

    def test_point3d_division(self):
        """Test Point3d division by scalar"""
        p1 = Ge.Point3d(6, 8, 12)
        result = p1 / 2.0
        expected = Ge.Point3d(3, 4, 6)
        assert result.isEqualTo(expected)

    def test_point3d_iadd(self):
        """Test in-place addition with Vector3d"""
        p1 = Ge.Point3d(1, 2, 3)
        v = Ge.Vector3d(4, 5, 6)
        p1 += v
        expected = Ge.Point3d(5, 7, 9)
        assert p1.isEqualTo(expected)

    def test_point3d_imul(self):
        """Test in-place multiplication with scalar"""
        p1 = Ge.Point3d(2, 4, 6)
        p1 *= 2.0
        expected = Ge.Point3d(4, 8, 12)
        assert p1.isEqualTo(expected)

    def test_point3d_itruediv(self):
        """Test in-place division by scalar"""
        p1 = Ge.Point3d(6, 8, 12)
        p1 /= 2.0
        expected = Ge.Point3d(3, 4, 6)
        assert p1.isEqualTo(expected)

    def test_point3d_equality(self):
        """Test Point3d equality with tolerance"""
        p1 = Ge.Point3d(1.0, 2.0, 3.0)
        p2 = Ge.Point3d(1.0 + 1e-12, 2.0 + 1e-12, 3.0 + 1e-12)
        assert p1.isEqualTo(p2)

    def test_point3d_distance_to(self):
        """Test distance calculation to another point"""
        p1 = Ge.Point3d(0, 0, 0)
        p2 = Ge.Point3d(3, 4, 0)
        dist = p1.distanceTo(p2)
        assert abs(dist - 5.0) < 1e-10

    def test_point3d_distance_to_self(self):
        """Test distance to self is zero"""
        p1 = Ge.Point3d(1, 2, 3)
        dist = p1.distanceTo(p1)
        assert abs(dist) < 1e-10

    def test_point3d_isEqualTo_without_tolerance(self):
        """Test equality without tolerance (uses default)"""
        p1 = Ge.Point3d(1.0, 2.0, 3.0)
        p2 = Ge.Point3d(1.0 + 1e-14, 2.0 + 1e-14, 3.0 + 1e-14)
        assert p1.isEqualTo(p2)

    def test_point3d_from_plane_and_2d(self):
        """Test construction from plane and 2D point"""
        # Create a plane in XY plane at z=5
        plane = Ge.Plane(Ge.Point3d(0, 0, 5), Ge.Vector3d.kZAxis)
        point2d = Ge.Point2d(10, 20)

        result = Ge.Point3d(plane, point2d)
        expected = Ge.Point3d(10, 20, 5)
        assert result.isEqualTo(expected)

    def test_point3d_zero_length_vector(self):
        """Test operations with zero vector"""
        p1 = Ge.Point3d(1, 2, 3)
        zero_vec = Ge.Vector3d.kZAxis * 0
        # This should not fail even though vector has zero length
        result = p1 + zero_vec
        assert result.isEqualTo(p1)

    def test_point3d_large_coordinates(self):
        """Test with very large coordinates"""
        p1 = Ge.Point3d(1e15, 2e15, 3e15)
        # Ensure operations don't cause overflow issues
        distance = p1.distanceTo(Ge.Point3d.kOrigin)
        assert distance > 0

    def test_point3d_negative_coordinates(self):
        """Test with negative coordinates"""
        p1 = Ge.Point3d(-1, -2, -3)
        # Test that operations work correctly
        result = p1 + Ge.Vector3d(1, 2, 3)
        expected = Ge.Point3d.kOrigin
        assert result.isEqualTo(expected)

    def test_point3d_very_small_coordinates(self):
        """Test with very small coordinates"""
        p1 = Ge.Point3d(1e-15, 2e-15, 3e-15)
        # Test that operations work correctly
        distance = p1.distanceTo(Ge.Point3d.kOrigin)
        assert abs(distance) > 0
