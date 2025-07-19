from __future__ import annotations

from pyrx import Ge


class TestMatrix3d:
    # def test_repr(self):
    #     val = Ge.Point3d(1.2,2.3,4.5)
    #     assert val.__repr__()  == "PyGe.Point3d(1.20000000000000,2.30000000000000,4.50000000000000)"

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
        assert pO == pO2
        assert vX == vX2
        assert vY == vY2
        assert vZ == vZ2
        assert vX2.length() == 2
        assert vY2.length() == 3
        assert vZ2.length() == 4
        # print(xf)

    def test_point3d_translation(self):
        pO = Ge.Point3d(1, 10, 100)
        vX = Ge.Vector3d.kXAxis
        vY = Ge.Vector3d.kYAxis
        vZ = Ge.Vector3d.kZAxis
        xf = Ge.Matrix3d.translation(pO.asVector())
        pO2 = Ge.Point3d.kOrigin
        vX2 = Ge.Vector3d.kXAxis
        vY2 = Ge.Vector3d.kYAxis
        vZ2 = Ge.Vector3d.kZAxis
        xf.getCoordSystem(pO2, vX2, vY2, vZ2)
        assert pO, pO2
        assert vX, vX2
        assert vY, vY2
        assert vZ, vZ2

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
