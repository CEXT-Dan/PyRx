from __future__ import annotations

import math
from pyrx import Ge


class TestMatrix3d:

    def test_matrix3d_scale3d(self):
        pO = Ge.Point3d(1, 10, 100)
        vX = Ge.Vector3d.kXAxis * 2
        vY = Ge.Vector3d.kYAxis * 3
        vZ = Ge.Vector3d.kZAxis * 4
        xf = Ge.Matrix3d.kIdentity
        xf.setCoordSystem(pO, vX, vY, vZ)
        sc = xf.scale3d()
        assert sc.sx == 2
        assert sc.sy == 3
        assert sc.sz == 4

    def test_matrix3d_set1(self):
        pO = Ge.Point3d(1, 10, 100)
        vX = Ge.Vector3d.kXAxis * 2
        vY = Ge.Vector3d.kYAxis * 3
        vZ = Ge.Vector3d.kZAxis * 4
        xf = Ge.Matrix3d.kIdentity
        xf.setCoordSystem(pO, vX, vY, vZ)
        pO2 = Ge.Point3d.kOrigin
        vX2 = Ge.Vector3d.kXAxis
        vY2 = Ge.Vector3d.kYAxis
        vZ2 = Ge.Vector3d.kZAxis
        xf.getCoordSystem(pO2, vX2, vY2, vZ2)
        assert pO == pO2  # Fixed: was 'assert pO, pO2'
        assert vX == vX2  # Fixed: was 'assert vX, vX2'
        assert vY == vY2  # Fixed: was 'assert vY, vY2'
        assert vZ == vZ2  # Fixed: was 'assert vZ, vZ2'
        assert vX2.length() == 2
        assert vY2.length() == 3
        assert vZ2.length() == 4

    def test_point3d_translation(self):
        pO = Ge.Point3d(1, 10, 100)
        xf = Ge.Matrix3d.translation(pO.asVector())
        pO2 = Ge.Point3d.kOrigin
        vX2 = Ge.Vector3d.kXAxis
        vY2 = Ge.Vector3d.kYAxis
        vZ2 = Ge.Vector3d.kZAxis
        xf.getCoordSystem(pO2, vX2, vY2, vZ2)
        assert pO == pO2  # Fixed: was 'assert pO, pO2'
        assert vX2 == Ge.Vector3d.kXAxis  # Fixed: was 'assert vX, vX2'
        assert vY2 == Ge.Vector3d.kYAxis
        assert vZ2 == Ge.Vector3d.kZAxis

    def test_matrix3d_ctor(self):
        mat1 = Ge.Matrix3d.kIdentity
        mat1.setToRotation(0.785398, Ge.Vector3d.kZAxis)
        mat2 = Ge.Matrix3d(mat1.toTuple())
        mat3 = Ge.Matrix3d(mat1.toList())
        assert mat2 == mat1 == mat3

        mat1 = Ge.Matrix2d.kIdentity
        mat1.setToRotation(0.785398)
        mat2 = Ge.Matrix2d(mat1.toTuple())
        mat3 = Ge.Matrix2d(mat1.toList())
        assert mat2 == mat1 == mat3

    def test_matrix3d_fromCollection(self):
        mat1 = Ge.Matrix3d.kIdentity
        mat1.setToRotation(0.785398, Ge.Vector3d.kZAxis)
        mat2 = Ge.Matrix3d.fromCollection(mat1.toTuple())
        mat3 = Ge.Matrix3d.fromCollection(mat1.toList())
        assert mat2 == mat1 == mat3

        mat1 = Ge.Matrix2d.kIdentity
        mat1.setToRotation(0.785398)
        mat2 = Ge.Matrix2d.fromCollection(mat1.toTuple())
        mat3 = Ge.Matrix2d.fromCollection(mat1.toList())
        assert mat2 == mat1 == mat3

    def test_matrix3d_set_to_translation(self):
        # Test basic translation
        v = Ge.Vector3d(10, 20, 30)
        xf = Ge.Matrix3d.kIdentity
        xf.setToTranslation(v)

        # Verify that the matrix correctly stores the translation
        # Get the coordinate system to verify translation component
        pos = Ge.Point3d.kOrigin
        x_axis = Ge.Vector3d.kXAxis
        y_axis = Ge.Vector3d.kYAxis
        z_axis = Ge.Vector3d.kZAxis

        xf.getCoordSystem(pos, x_axis, y_axis, z_axis)

        # Check translation components match - the position should be at our vector values
        assert abs(pos.x - v.x) < 1e-6
        assert abs(pos.y - v.y) < 1e-6
        assert abs(pos.z - v.z) < 1e-6

        # Verify that orientation axes remain unchanged (identity)
        assert x_axis == Ge.Vector3d.kXAxis
        assert y_axis == Ge.Vector3d.kYAxis  
        assert z_axis == Ge.Vector3d.kZAxis

        # Test with zero vector
        xf2 = Ge.Matrix3d.kIdentity
        xf2.setToTranslation(Ge.Vector3d(0, 0, 0))
        pos_zero = Ge.Point3d.kOrigin
        x_axis_zero = Ge.Vector3d.kXAxis
        y_axis_zero = Ge.Vector3d.kYAxis
        z_axis_zero = Ge.Vector3d.kZAxis
        xf2.getCoordSystem(pos_zero, x_axis_zero, y_axis_zero, z_axis_zero)

        assert pos_zero == Ge.Point3d.kOrigin  # Should be at origin

        # Test that we can apply this translation to a point
        test_point = Ge.Point3d(1, 2, 3)
        transformed_point = test_point.transformBy(xf)
        expected_point = Ge.Point3d(v.x + 1, v.y + 2, v.z + 3)  # Add translation vector

        assert abs(transformed_point.x - expected_point.x) < 1e-6
        assert abs(transformed_point.y - expected_point.y) < 1e-6  
        assert abs(transformed_point.z - expected_point.z) < 1e-6


    def test_matrix3d_set_to_rotation(self):
        angle_rad = math.pi / 4  # 45 degrees
        axis = Ge.Vector3d.kZAxis  # Rotation around Z-axis

        xf = Ge.Matrix3d.kIdentity
        xf.setToRotation(angle_rad, axis)

        # Get the resulting coordinate system to validate rotation
        pos = Ge.Point3d.kOrigin
        x_axis = Ge.Vector3d.kXAxis
        y_axis = Ge.Vector3d.kYAxis
        z_axis = Ge.Vector3d.kZAxis

        xf.getCoordSystem(pos, x_axis, y_axis, z_axis)

        # For a 45° rotation around Z-axis:
        expected_x = Ge.Vector3d(1.0 / math.sqrt(2), 1.0 / math.sqrt(2), 0)
        expected_y = Ge.Vector3d(-1.0 / math.sqrt(2), 1.0 / math.sqrt(2), 0)

        assert abs(x_axis.x - expected_x.x) < 1e-6
        assert abs(x_axis.y - expected_x.y) < 1e-6
        assert x_axis.z == 0

        assert abs(y_axis.x - expected_y.x) < 1e-6
        assert abs(y_axis.y - expected_y.y) < 1e-6
        assert y_axis.z == 0

    def test_matrix3d_transform_by(self):
        # Define a transformation matrix (scaling)
        scale_factor = 2.0
        xf = Ge.Matrix3d.kIdentity
        xf.setToScaling(scale_factor)

        # Apply to a vector
        v_in = Ge.Vector3d(1, 2, 3)
        v_out = v_in.transformBy(xf)  # Should result in (2,4,6)
        v_test = Ge.Vector3d(2, 4, 6)
        assert v_test == v_out

    def test_matrix3d_determinant(self):
        # Identity matrix determinant = 1.0
        identity = Ge.Matrix3d.kIdentity
        det_identity = identity.det()
        assert abs(det_identity - 1.0) < 1e-6


