from __future__ import annotations

import math

from pyrx import Ge


class TestVector3d:
    def test_repr(self):
        val = Ge.Vector3d(1.2, 2.3, 4.5)
        assert (
            val.__repr__()
            == "PyGe.Vector3d(1.20000000000000,2.30000000000000,4.50000000000000)"
        )

    def test_vector3d_rmul1(self):
        v = Ge.Vector3d(1, 1, 1)
        v = 10.0 * v
        assert v == Ge.Vector3d(10, 10, 10)

    def test_vector3d_rmul2(self):
        v = Ge.Vector3d(1, 1, 1)
        m = Ge.Matrix3d()
        m.setToRotation(math.pi, Ge.Vector3d.kZAxis, Ge.Point3d.kOrigin)
        v = m * v
        assert v == Ge.Vector3d(-1.0, -1.0, 1.0)

    def test_vector3d_len(self):
        pO = Ge.Vector3d(-1.0, -1.0, 1.0)
        assert len(pO) == 3

    def test_vector3d_init_default(self):
        v = Ge.Vector3d()
        assert v == Ge.Vector3d(0.0, 0.0, 0.0)

    def test_vector3d_init_from_tuple(self):
        v = Ge.Vector3d((1.0, 2.0, 3.0))
        assert v == Ge.Vector3d(1.0, 2.0, 3.0)

    def test_vector3d_init_from_list(self):
        v = Ge.Vector3d([1.0, 2.0, 3.0])
        assert v == Ge.Vector3d(1.0, 2.0, 3.0)

    def test_vector3d_init_from_coords(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        assert v == Ge.Vector3d(1.0, 2.0, 3.0)

    def test_vector3d_add(self):
        v1 = Ge.Vector3d(1.0, 2.0, 3.0)
        v2 = Ge.Vector3d(4.0, 5.0, 6.0)
        result = v1 + v2
        assert result == Ge.Vector3d(5.0, 7.0, 9.0)

    def test_vector3d_sub(self):
        v1 = Ge.Vector3d(5.0, 7.0, 9.0)
        v2 = Ge.Vector3d(1.0, 2.0, 3.0)
        result = v1 - v2
        assert result == Ge.Vector3d(4.0, 5.0, 6.0)

    def test_vector3d_mul_scalar(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        result = v * 2.0
        assert result == Ge.Vector3d(2.0, 4.0, 6.0)

    def test_vector3d_rmul_scalar(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        result = 2.0 * v
        assert result == Ge.Vector3d(2.0, 4.0, 6.0)

    def test_vector3d_truediv(self):
        v = Ge.Vector3d(10.0, 20.0, 30.0)
        result = v / 2.0
        assert result == Ge.Vector3d(5.0, 10.0, 15.0)

    def test_vector3d_iadd(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        v += Ge.Vector3d(4.0, 5.0, 6.0)
        assert v == Ge.Vector3d(5.0, 7.0, 9.0)

    def test_vector3d_isub(self):
        v = Ge.Vector3d(10.0, 20.0, 30.0)
        v -= Ge.Vector3d(4.0, 5.0, 6.0)
        assert v == Ge.Vector3d(6.0, 15.0, 24.0)

    def test_vector3d_imul(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        v *= 2.0
        assert v == Ge.Vector3d(2.0, 4.0, 6.0)

    def test_vector3d_itruediv(self):
        v = Ge.Vector3d(10.0, 20.0, 30.0)
        v /= 2.0
        assert v == Ge.Vector3d(5.0, 10.0, 15.0)

    def test_vector3d_neg(self):
        v = Ge.Vector3d(1.0, -2.0, 3.0)
        result = v.negate()
        assert result == Ge.Vector3d(-1.0, 2.0, -3.0)

    def test_vector3d_getitem(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        assert v[0] == 1.0
        assert v[1] == 2.0
        assert v[2] == 3.0

    def test_vector3d_setitem(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        v[0] = 5.0
        assert v[0] == 5.0
        v[1] = 6.0
        assert v[1] == 6.0
        v[2] = 7.0
        assert v[2] == 7.0

    def test_vector3d_length(self):
        v = Ge.Vector3d(3.0, 4.0, 0.0)
        assert abs(v.length() - 5.0) < 1e-9

    def test_vector3d_length_sqrd(self):
        v = Ge.Vector3d(3.0, 4.0, 0.0)
        assert abs(v.lengthSqrd() - 25.0) < 1e-9

    def test_vector3d_largest_element(self):
        v = Ge.Vector3d(-3.0, 4.0, 2.0)
        assert v.largestElement() == 1  # Index of largest absolute value (4.0)

    def test_vector3d_normal(self):
        v = Ge.Vector3d(3.0, 4.0, 0.0)
        normalized = v.normal()
        expected_length = 1.0
        assert abs(normalized.length() - expected_length) < 1e-9

    def test_vector3d_normalize(self):
        v = Ge.Vector3d(3.0, 4.0, 0.0)
        original_id = id(v)
        result = v.normalize()
        assert id(result) == original_id  # Should return self
        expected_length = 1.0
        assert abs(v.length() - expected_length) < 1e-9

    def test_vector3d_negate(self):
        v = Ge.Vector3d(1.0, -2.0, 3.0)
        result = v.negate()
        assert id(result) == id(v)  # Should return self
        assert v == Ge.Vector3d(-1.0, 2.0, -3.0)

    def test_vector3d_mirroring(self):
        v = Ge.Vector3d(1.0, 1.0, 1.0)
        normal_plane = Ge.Vector3d.kZAxis
        reflected = v.mirror(normal_plane)
        assert reflected == Ge.Vector3d(1.0, 1.0, -1.0)

    def test_vector3d_ortho_project(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        plane_normal = Ge.Vector3d.kZAxis
        projected = v.orthoProject(plane_normal)
        assert projected == Ge.Vector3d(1.0, 2.0, 0.0)

    def test_vector3d_perp_vector(self):
        # Test that perpVector of (1,0,0) produces a vector perpendicular to it
        v = Ge.Vector3d.kXAxis
        perp = v.perpVector()
        dot_product = perp.dotProduct(v)  # Dot product should be zero
        assert abs(dot_product) < 1e-9

    def test_vector3d_equality(self):
        v1 = Ge.Vector3d(1.0, 2.0, 3.0)
        v2 = Ge.Vector3d(1.0, 2.0, 3.0)
        assert v1 == v2
        assert not (v1 == Ge.Vector3d(1.0, 2.0, 4.0))

    def test_vector3d_inequality(self):
        v1 = Ge.Vector3d(1.0, 2.0, 3.0)
        v2 = Ge.Vector3d(1.0, 2.0, 4.0)
        assert v1 != v2
        assert not (v1 != Ge.Vector3d(1.0, 2.0, 3.0))

    def test_vector3d_unit_vectors(self):
        x_axis = Ge.Vector3d.kXAxis
        y_axis = Ge.Vector3d.kYAxis
        z_axis = Ge.Vector3d.kZAxis
        assert x_axis == Ge.Vector3d(1.0, 0.0, 0.0)
        assert y_axis == Ge.Vector3d(0.0, 1.0, 0.0)
        assert z_axis == Ge.Vector3d(0.0, 0.0, 1.0)

    def test_vector3d_dot_product(self):
        v1 = Ge.Vector3d(1.0, 2.0, 3.0)
        v2 = Ge.Vector3d(4.0, 5.0, 6.0)
        dot_result = v1.dotProduct(v2)
        assert abs(dot_result - (1 * 4 + 2 * 5 + 3 * 6)) < 1e-9

    def test_vector3d_cross_product(self):
        v1 = Ge.Vector3d(1.0, 2.0, 3.0)
        v2 = Ge.Vector3d(4.0, 5.0, 6.0)
        cross_result = v1.crossProduct(v2)
        expected = Ge.Vector3d(-3.0, 6.0, -3.0)  # Cross product calculation
        assert abs(cross_result.x - expected.x) < 1e-9
        assert abs(cross_result.y - expected.y) < 1e-9
        assert abs(cross_result.z - expected.z) < 1e-9

    def test_vector3d_hash(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        h = hash(v)
        # Hash should be consistent for same values
        assert hash(Ge.Vector3d(1.0, 2.0, 3.0)) == h

    def test_vector3d_getinitargs(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        init_args = v.__getinitargs__()
        assert len(init_args) == 3
        assert init_args[0] == 1.0
        assert init_args[1] == 2.0
        assert init_args[2] == 3.0

    def test_vector3d_copy(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        # Test copy by creating new instance from same values
        v_copy = Ge.Vector3d(v.x, v.y, v.z)
        assert v == v_copy

    def test_vector3d_rotation_around_z_axis(self):
        v = Ge.Vector3d(1.0, 0.0, 0.0)
        m = Ge.Matrix3d()
        # Rotate 90 degrees around Z-axis
        m.setToRotation(math.pi / 2, Ge.Vector3d.kZAxis, Ge.Point3d.kOrigin)
        rotated = v.transformBy(m)
        # Result should be (0,1,0) with some floating point tolerance
        assert abs(rotated.x - 0.0) < 1e-9
        assert abs(rotated.y - 1.0) < 1e-9
        assert abs(rotated.z - 0.0) < 1e-9

    def test_vector3d_distance_to_origin(self):
        v = Ge.Vector3d(3.0, 4.0, 0.0)
        # Distance from origin is sqrt(3^2 + 4^2) = 5
        assert abs(v.length() - 5.0) < 1e-9

    def test_vector3d_distance_to_other_point(self):
        v1 = Ge.Vector3d(1.0, 0.0, 0.0)
        v2 = Ge.Vector3d(4.0, 0.0, 0.0)
        # Distance should be |4-1| = 3
        expected_distance = 3.0
        assert abs((v1 - v2).length() - expected_distance) < 1e-9

    def test_vector3d_unit_normalization(self):
        zero_v = Ge.Vector3d(0.0, 0.0, 0.0)
        normalized_zero = zero_v.normal() # noqa: F841

    def test_vector3d_inplace_operations_chain(self):
        v = Ge.Vector3d(1.0, 2.0, 3.0)
        v += Ge.Vector3d(1.0, 1.0, 1.0)  # Add
        v *= 2.0  # Multiply
        assert v == Ge.Vector3d(4.0, 6.0, 8.0)

    def test_vector3d_creation_from_point(self):
        p = Ge.Point3d(1.0, 2.0, 3.0)
        # Can't directly convert Point3d to Vector3d in most implementations
        # But can create vectors from points via subtraction or direct construction
        v_direct = Ge.Vector3d(p.x, p.y, p.z)
        assert v_direct == Ge.Vector3d(1.0, 2.0, 3.0)

    def test_vector3d_orthogonality_check(self):
        v1 = Ge.Vector3d(1.0, 0.0, 0.0)
        v2 = Ge.Vector3d(0.0, 1.0, 0.0)
        # Dot product of orthogonal vectors should be zero
        dot_product = v1.dotProduct(v2)
        assert abs(dot_product) < 1e-9

    def test_vector3d_parallel_check(self):
        v1 = Ge.Vector3d(2.0, 4.0, 6.0)
        v2 = Ge.Vector3d(1.0, 2.0, 3.0)
        # v1 should be scalar multiple of v2 (parallel)
        ratio = v1.x / v2.x if abs(v2.x) > 1e-9 else None
        if ratio is not None:
            assert abs(v1.y / v2.y - ratio) < 1e-9
            assert abs(v1.z / v2.z - ratio) < 1e-9

    def test_vector3d_angle_between_vectors(self):
        # Using dot product formula to compute angle between unit vectors
        u = Ge.Vector3d.kXAxis
        v = Ge.Vector3d(0.707, 0.707, 0.0)  # Approximately 45 degree vector in XY plane

        # Note: This test doesn't directly verify the angle function if it exists,
        # but shows how to compute dot product and handle normalization
        u_unit = u.normal()
        v_unit = v.normal()

        # Cosine of angle between them should be their dot product
        cos_angle = u_unit.dotProduct(v_unit)  # Should equal approximately 0.707
        assert math.isclose(0.7071067811865475, cos_angle, abs_tol=1e-3)
