import os
import unittest
import math

import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor
print("testname = pyge")

class TestGe(unittest.TestCase):
    def test_scale2_default_ctor(self):
        scale = PyGe.Scale2d()
        self.assertEqual(scale.sx,1)
        self.assertEqual(scale.sy,1)
        
    def test_scale2_ctor1(self):
        scale = PyGe.Scale2d(3)
        self.assertEqual(scale.sx,3)
        self.assertEqual(scale.sy,3)
        
    def test_scale2_ctor2(self):
        scale = PyGe.Scale2d(4,4)
        self.assertEqual(scale.sx,4)
        self.assertEqual(scale.sy,4)
        
    def test_scale2_preMultBy(self):
        scaleL = PyGe.Scale2d(2,2)
        scaleR = PyGe.Scale2d(4,4)
        scaleL.preMultBy(scaleR)
        self.assertEqual(scaleL.sx,8)
        self.assertEqual(scaleL.sy,8)
        
    def test_scale2_postMultBy(self):
        scaleL = PyGe.Scale2d(2,2)
        scaleR = PyGe.Scale2d(4,4)
        scaleL.postMultBy(scaleR)
        self.assertEqual(scaleL.sx,8)
        self.assertEqual(scaleL.sy,8)
        
    def test_scale2_setToProduct1(self):
        scale1 = PyGe.Scale2d()
        scale2 =  PyGe.Scale2d(2,2)
        scale1.setToProduct(scale2,2)
        self.assertEqual(scale1.sx,4)
        self.assertEqual(scale1.sy,4)

    def test_point2d_default_ctor(self):
        point = PyGe.Point2d()
        self.assertEqual(point, PyGe.Point2d(0, 0))

    def test_point2d_arg_ctor(self):
        point = PyGe.Point2d(100, 100)
        self.assertEqual(point, PyGe.Point2d(100, 100))
        point2 = PyGe.Point2d([300,400])
        self.assertEqual(point2, PyGe.Point2d(300, 400))
        point3 = PyGe.Point2d((400,500))
        self.assertEqual(point3, PyGe.Point2d(400, 500))
        
    def test_point2d_add(self):
        point = PyGe.Point2d(100, 100)
        p = point + PyGe.Vector2d.kXAxis
        self.assertEqual(p, PyGe.Point2d(101, 100))

    def test_point2d_iadd(self):
        point = PyGe.Point2d(100, 100)
        point += PyGe.Vector2d.kXAxis
        self.assertEqual(point, PyGe.Point2d(101, 100))

    def test_point2d_mul(self):
        point = PyGe.Point2d(100, 100)
        point = point * 2.0
        self.assertEqual(point, PyGe.Point2d(200, 200))

    def test_point2d_imul(self):
        point = PyGe.Point2d(100, 100)
        point *= 2.0
        self.assertEqual(point, PyGe.Point2d(200, 200))

    def test_point2d_sub(self):
        point = PyGe.Point2d(100, 100)
        p = point - PyGe.Vector2d.kXAxis
        self.assertEqual(p, PyGe.Point2d(99, 100))

    def test_point2d_isub(self):
        point = PyGe.Point2d(100, 100)
        point -= PyGe.Vector2d.kXAxis
        self.assertEqual(point, PyGe.Point2d(99, 100))

    def test_point2d_div(self):
        point = PyGe.Point2d(100, 100)
        p = point / 2.0
        self.assertEqual(p, PyGe.Point2d(50, 50))

    def test_point2d_idiv(self):
        point = PyGe.Point2d(100, 100)
        point /= 2.0
        self.assertEqual(point, PyGe.Point2d(50, 50))

    def test_point2d_isEqualTo(self):
        point1 = PyGe.Point2d(100, 100)
        point2 = PyGe.Point2d(100, 100)
        point1.isEqualTo(point2)
        self.assertTrue(point1.isEqualTo(point2))
        self.assertTrue(point1.isEqualTo(point2, PyGe.Tol.current))

    def test_point2d_kOrigin(self):
        origin = PyGe.Point2d.kOrigin
        point = PyGe.Point2d(0, 0)
        self.assertEqual(origin, point)

    def test_vector2d_mul2(self):
        v = PyGe.Vector2d(1, 1)
        v = v * 10
        self.assertEqual(v, PyGe.Vector2d(10, 10))

    def test_vector2d_rmul1(self):
        v = PyGe.Vector2d(1, 1)
        v = 10.0 * v
        self.assertEqual(v, PyGe.Vector2d(10, 10))

    def test_vector2d_rmul2(self):
        v = PyGe.Vector2d(1, 1)
        m = PyGe.Matrix2d()
        m.setToRotation(math.pi, PyGe.Point2d.kOrigin)
        v = m * v
        self.assertEqual(v, PyGe.Vector2d(-1.0, -1.0))

    def test_vector2d_setToProduct(self):
        v1 = PyGe.Vector2d.kXAxis
        m = PyGe.Matrix2d.kIdentity
        v1.setToProduct(PyGe.Vector2d.kYAxis,math.pi)
        self.assertEqual(v1, PyGe.Vector2d(0.000000, math.pi))
        v1 = PyGe.Vector2d.kXAxis
        m.setToRotation(math.pi)
        v1.setToProduct(m, PyGe.Vector2d.kYAxis)
        self.assertEqual(v1, PyGe.Vector2d(-0.0, -1.0))

    # test adding default values on the C++ side
    def test_vector2d_isParallelTo(self):
        v1 = PyGe.Vector2d.kXAxis
        v2 = PyGe.Vector2d.kXAxis
        ans = v1.isParallelTo(v2)
        self.assertEqual(ans, True)
        ans = v1.isParallelTo(v2, PyGe.Tol.current)
        self.assertEqual(ans, True)

    def test_vector2d_isParallelTo(self):
        v1 = PyGe.Vector2d.kXAxis
        v2 = PyGe.Vector2d.kYAxis
        ans = v1.isPerpendicularTo(v2)
        self.assertEqual(ans, True)
        ans = v1.isPerpendicularTo(v2, PyGe.Tol.current)
        self.assertEqual(ans, True)

    def test_vector2d_make1(self):
        p1 = PyGe.Point2d(100, 0)
        p2 = PyGe.Point2d(0, 0)
        v1 = p2 - p1
        self.assertTrue(v1.isParallelTo(PyGe.Vector2d.kXAxis))
        self.assertTrue(v1.isPerpendicularTo(PyGe.Vector2d.kYAxis))
        self.assertFalse(v1.isUnitLength())
        self.assertFalse(v1.isZeroLength())
        self.assertEqual(v1.length(), 100)
        v1.rotateBy(math.pi)
        v1.negate()
        self.assertTrue(v1.isParallelTo(PyGe.Vector2d.kXAxis))
        
    def test_vector3d_rmul1(self):
        v = PyGe.Vector3d(1, 1, 1)
        v = 10.0 * v
        self.assertEqual(v, PyGe.Vector3d(10, 10, 10))

    def test_vector3d_rmul2(self):
        v = PyGe.Vector3d(1, 1, 1)
        m = PyGe.Matrix3d()
        m.setToRotation(math.pi, PyGe.Vector3d.kZAxis, PyGe.Point3d.kOrigin)
        v = m * v
        self.assertEqual(v, PyGe.Vector3d(-1.0, -1.0, 1.0))

    def test_point3d_toVec(self):
        pO = PyGe.Point3d(0, 0, 0)
        p1 = PyGe.Point3d(0, 100, 0)
        v1 = p1 - pO
        self.assertEqual(v1.length(), 100)
        self.assertTrue(v1.isParallelTo(PyGe.Vector3d.kYAxis))
        
    def test_point3d_getset(self):
        pO = PyGe.Point3d(1, 2, 3)
        x = pO[0]
        y = pO[1]
        z = pO[2]
        self.assertEqual(x, 1.0)
        self.assertEqual(y, 2.0)
        self.assertEqual(z, 3.0)
        pO[0] = 12
        pO[1] = 13
        pO[2] = 14
        self.assertEqual(pO.x, 12.0)
        self.assertEqual(pO.y, 13.0)
        self.assertEqual(pO.z, 14.0)
        
    def test_point3dlist_getset(self):
        iterable = [1, 2, 3]
        pO = PyGe.Point3d(iterable)
        x = pO[0]
        y = pO[1]
        z = pO[2]
        self.assertEqual(x, 1.0)
        self.assertEqual(y, 2.0)
        self.assertEqual(z, 3.0)
        pO[0] = 12
        pO[1] = 13
        pO[2] = 14
        self.assertEqual(pO.x, 12.0)
        self.assertEqual(pO.y, 13.0)
        self.assertEqual(pO.z, 14.0)
        
    def test_point3dtuple_getset(self):
        iterable = (1, 2, 3)
        pO = PyGe.Point3d(iterable)
        x = pO[0]
        y = pO[1]
        z = pO[2]
        self.assertEqual(x, 1.0)
        self.assertEqual(y, 2.0)
        self.assertEqual(z, 3.0)
        pO[0] = 12
        pO[1] = 13
        pO[2] = 14
        self.assertEqual(pO.x, 12.0)
        self.assertEqual(pO.y, 13.0)
        self.assertEqual(pO.z, 14.0)
        
    def test_matrix3d_set1(self):
        pO = PyGe.Point3d(1, 10, 100)
        vX = PyGe.Vector3d.kXAxis * 2
        vY = PyGe.Vector3d.kYAxis * 3
        vZ = PyGe.Vector3d.kZAxis * 4
        xf = PyGe.Matrix3d.kIdentity
        xf.setCoordSystem(pO, vX, vY, vZ)
        pO2 = PyGe.Point3d.kOrigin
        vX2 = PyGe.Vector3d.kXAxis
        vY2 = PyGe.Vector3d.kYAxis
        vZ2 = PyGe.Vector3d.kZAxis
        xf.getCoordSystem(pO2, vX2, vY2, vZ2)
        self.assertEqual(pO, pO2)
        self.assertEqual(vX, vX2)
        self.assertEqual(vY, vY2)
        self.assertEqual(vZ, vZ2)
        self.assertEqual(vX2.length(), 2)
        self.assertEqual(vY2.length(), 3)
        self.assertEqual(vZ2.length(), 4)
        # print(xf)

    def test_point3d_translation(self):
        pO = PyGe.Point3d(1, 10, 100)
        vX = PyGe.Vector3d.kXAxis
        vY = PyGe.Vector3d.kYAxis
        vZ = PyGe.Vector3d.kZAxis
        xf = PyGe.Matrix3d.translation(pO.asVector())
        pO2 = PyGe.Point3d.kOrigin
        vX2 = PyGe.Vector3d.kXAxis
        vY2 = PyGe.Vector3d.kYAxis
        vZ2 = PyGe.Vector3d.kZAxis
        xf.getCoordSystem(pO2, vX2, vY2, vZ2)
        self.assertEqual(pO, pO2)
        self.assertEqual(vX, vX2)
        self.assertEqual(vY, vY2)
        self.assertEqual(vZ, vZ2)

    def test_pyge_line2d_static_properties(self):
        xline = PyGe.Line2d.kXAxis
        yline = PyGe.Line2d.kYAxis
        self.assertTrue(xline.isPerpendicularTo(yline))

    def test_pyge_line3d_static_properties(self):
        xline = PyGe.Line3d.kXAxis
        yline = PyGe.Line3d.kYAxis
        zline = PyGe.Line3d.kZAxis
        self.assertTrue(xline.isPerpendicularTo(yline))
        self.assertTrue(xline.isPerpendicularTo(zline))
        
    def test_pyge_lineseg3d_1(self):
        s1 = PyGe.LineSeg3d(PyGe.Point3d(0, 0, 0), PyGe.Point3d(100, 100, 0))
        s2 = PyGe.LineSeg3d(PyGe.Point3d(0, 100, 0), PyGe.Point3d(100, 0, 0))
        self.assertTrue(s1.isPerpendicularTo(s2))
        self.assertTrue(s1.intersectWith(s2)[0])
        self.assertTrue(s1.isOn(s2.midPoint()))

    def test_lineseg3d_reverse(self):
        pnt1 = PyGe.Point3d(0,0,0)
        pnt2 = PyGe.Point3d(1,2,3)
        seg = PyGe.LineSeg3d(pnt1,pnt2)
        self.assertEqual(seg.startPoint(), pnt1)
        seg.reverseParam()
        self.assertEqual(seg.startPoint(), pnt2)
        
    def test_surfSurfInt(self):
        vec = PyGe.Vector3d.kXAxis
        pnt = PyGe.Point3d(4000.0,3000.0,0.0)
        p1 = PyGe.Plane(pnt, vec)
        p3 = PyGe.Plane(pnt, vec)
        si = PyGe.SurfSurfInt(p1,p3)
        self.assertEqual(si.numResults(),1)
    
        
def PyRxCmd_pyge():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestGe)
        print('TestGe')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        print(err)
