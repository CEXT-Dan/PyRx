from __future__ import annotations

import math

from pyrx import Ge


class TestMatrix3d:

    def test_matrix3d_scale3d_magnitude3d(self):
        pO = Ge.Point3d(1, 10, 100)
        vX = Ge.Vector3d.kXAxis * 2
        vY = Ge.Vector3d.kYAxis * 3
        vZ = Ge.Vector3d.kZAxis * 4
        xf = Ge.Matrix3d.kIdentity
        xf.setCoordSystem(pO, vX, vY, vZ)
        sc = xf.scale3dMagnitude()
        assert sc.sx == 2
        assert sc.sy == 3
        assert sc.sz == 4
        
        vX = Ge.Vector3d.kXAxis * -2
        vY = Ge.Vector3d.kYAxis * -3
        vZ = Ge.Vector3d.kZAxis * -4
        xf = Ge.Matrix3d.kIdentity
        xf.setCoordSystem(pO, vX, vY, vZ)
        sc = xf.scale3dMagnitude()
        assert sc.sx == 2
        assert sc.sy == 3
        assert sc.sz == 4
        
    def test_matrix3d_scale3d_1(self):
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
        
        vX = Ge.Vector3d.kXAxis * -2
        vY = Ge.Vector3d.kYAxis * -3
        vZ = Ge.Vector3d.kZAxis * -4
        xf = Ge.Matrix3d.kIdentity
        xf.setCoordSystem(pO, vX, vY, vZ)
        sc = xf.scale3d()
        assert sc.sx == -2
        assert sc.sy == -3
        assert sc.sz == -4

    def test_matrix3d_scale3d_2(self):
        xf = Ge.Matrix3d.kIdentity
        pl = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kXAxis)
        xf.setToMirroring(pl)
        assert xf.scale3d() == Ge.Scale3d(-1.0, 1.0, 1.0)

        xf = Ge.Matrix3d.kIdentity
        pl = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kYAxis)
        xf.setToMirroring(pl)
        assert xf.scale3d() == Ge.Scale3d(1.0, -1.0, 1.0)

        xf = Ge.Matrix3d.kIdentity
        pl = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kZAxis)
        xf.setToMirroring(pl)
        assert xf.scale3d() == Ge.Scale3d(1.0, 1.0, -1.0)

        xf = Ge.Matrix3d.kIdentity
        xf.setToRotation(math.radians(45), Ge.Vector3d.kZAxis, Ge.Point3d.kOrigin)
        assert xf.scale3d() == Ge.Scale3d(1.0, 1.0, 1.0)
        
        xf = Ge.Matrix3d.kIdentity
        xf.setToRotation(math.radians(181), Ge.Vector3d.kZAxis, Ge.Point3d.kOrigin)
        assert xf.scale3d() == Ge.Scale3d(-1.0, -1.0, 1.0)

        xf = Ge.Matrix3d.kIdentity
        xf.setCoordSystem(
            Ge.Point3d(-100, -100, -100),
            Ge.Vector3d.kXAxis,
            Ge.Vector3d.kYAxis,
            Ge.Vector3d.kZAxis,
        )
        xf.setToRotation(math.radians(45), Ge.Vector3d.kZAxis, Ge.Point3d.kOrigin)
        assert xf.scale3d() == Ge.Scale3d(1.0, 1.0, 1.0)

        xf = Ge.Matrix3d.kIdentity
        pl = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kZAxis)
        xf.setToMirroring(pl)
        xf = xf * Ge.Matrix3d.kIdentity.setToScaling(8)
        assert xf.scale3d() == Ge.Scale3d(8.0, 8.0, -8.0)

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
        assert pO == pO2
        assert vX == vX2
        assert vY == vY2
        assert vZ == vZ2
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
        assert pO == pO2
        assert vX2 == Ge.Vector3d.kXAxis
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

    def test_matrix3d_set_to_mirroring(self):
        # no exeption is pass
        xf = Ge.Matrix3d.kIdentity
        pl = Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kYAxis)
        xf.setToMirroring(pl)
        line = Ge.Line3d(Ge.Point3d.kOrigin, Ge.Point3d(100, 0, 0))
        xf.setToMirroring(line)
        xf.setToMirroring(Ge.Point3d.kOrigin)

    def test_matrix3d_set_to_projection(self):
        """Test Matrix3d.setToProjection method"""
        # Create a plane for projection
        origin = Ge.Point3d(0, 0, 0)
        normal = Ge.Vector3d.kZAxis
        plane = Ge.Plane(origin, normal)

        # Define projection direction (project along Z-axis)
        project_dir = Ge.Vector3d.kZAxis

        # Create identity matrix and set to projection onto the plane
        xf = Ge.Matrix3d.kIdentity
        xf.setToProjection(plane, project_dir)

        # Verify that we can apply this transformation to a point
        test_point = Ge.Point3d(10, 20, 30)  # Point above the XY-plane
        transformed_point = test_point.transformBy(xf)

        # The Z coordinate should be zero after projection onto XY plane (Z=0)
        assert abs(transformed_point.z) < 1e-6

    def test_matrix3d_world_to_plane(self):
        """Test Matrix3d.worldToPlane method"""
        # Define a plane with origin at (5, 5, 5) and normal along Z-axis
        origin = Ge.Point3d(5, 5, 5)
        normal = Ge.Vector3d.kZAxis
        plane = Ge.Plane(origin, normal)

        # Create world to plane transformation matrix
        xf_world_to_plane = Ge.Matrix3d.worldToPlane(plane)

        # Apply transformation to a point in world space
        world_point = Ge.Point3d(10, 15, 20)  # Point at some position
        local_point = world_point.transformBy(xf_world_to_plane)

        # Verify that we can transform back using planeToWorld
        xf_plane_to_world = Ge.Matrix3d.planeToWorld(plane)
        restored_point = local_point.transformBy(xf_plane_to_world)

        # The restored point should be close to original (with tolerance)
        assert abs(world_point.x - restored_point.x) < 1e-6
        assert abs(world_point.y - restored_point.y) < 1e-6
        assert abs(world_point.z - restored_point.z) < 1e-6

    def test_matrix3d_plane_to_world(self):
        """Test Matrix3d.planeToWorld method"""
        # Define a plane with origin at (2, 3, 4)
        origin = Ge.Point3d(2, 3, 4)
        normal = Ge.Vector3d.kYAxis  # Normal along Y-axis
        plane = Ge.Plane(origin, normal)

        # Create plane to world transformation matrix
        xf_plane_to_world = Ge.Matrix3d.planeToWorld(plane)

        # Apply transformation to a point in local (plane) space
        local_point = Ge.Point3d(10, 20, 30)  # Point relative to the plane
        world_point = local_point.transformBy(xf_plane_to_world)

        # Verify that we can transform back using worldToPlane
        xf_world_to_plane = Ge.Matrix3d.worldToPlane(plane)
        restored_point = world_point.transformBy(xf_world_to_plane)

        # The restored point should be close to original (with tolerance)
        assert abs(local_point.x - restored_point.x) < 1e-6
        assert abs(local_point.y - restored_point.y) < 1e-6
        assert abs(local_point.z - restored_point.z) < 1e-6
