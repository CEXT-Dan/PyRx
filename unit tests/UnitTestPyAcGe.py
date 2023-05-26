import os 
import unittest
import math 

import PyRxApp# = all the global methods like acutPrintf, 
import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 
print("testname = pyge")

class TestGe(unittest.TestCase):
        
        def test_ge_class_names(self):
                self.assertEqual(PyGe.BoundBlock2d.className(), 'AcGeBoundBlock2d')
                self.assertEqual(PyGe.BoundBlock3d.className(), 'AcGeBoundBlock3d')
                self.assertEqual(PyGe.CircArc2d.className(), 'AcGeCircArc2d')
                self.assertEqual(PyGe.CircArc3d.className(), 'AcGeCircArc3d')
                self.assertEqual(PyGe.CircArc3d().type(), PyGe.EntityId.kCircArc3d)
                
        def test_point2d_add(self):
                point = PyGe.Point2d(100,100)
                p = point +  PyGe.Vector2d.kXAxis
                self.assertEqual(p, PyGe.Point2d(101,100))

        def test_point2d_iadd(self):
                point = PyGe.Point2d(100,100)
                point +=  PyGe.Vector2d.kXAxis
                self.assertEqual(point, PyGe.Point2d(101,100))

        def test_point2d_mul(self):
                point = PyGe.Point2d(100,100)
                point = point *  2.0
                self.assertEqual(point, PyGe.Point2d(200,200))

        def test_point2d_imul(self):
                point = PyGe.Point2d(100,100)
                point *=  2.0
                self.assertEqual(point, PyGe.Point2d(200,200))

        def test_point2d_sub(self):
                point = PyGe.Point2d(100,100)
                p = point - PyGe.Vector2d.kXAxis
                self.assertEqual(p, PyGe.Point2d(99,100))

        def test_point2d_isub(self):
                point = PyGe.Point2d(100,100)
                point -=  PyGe.Vector2d.kXAxis
                self.assertEqual(point, PyGe.Point2d(99,100))

        def test_point2d_div(self):
                point = PyGe.Point2d(100,100)
                p = point / 2.0
                self.assertEqual(p, PyGe.Point2d(50,50))

        def test_point2d_idiv(self):
                point = PyGe.Point2d(100,100)
                point /=  2.0
                self.assertEqual(point, PyGe.Point2d(50,50))

        def test_point2d_isEqualTo(self):
                point1 = PyGe.Point2d(100,100)
                point2 = PyGe.Point2d(100,100)
                point1.isEqualTo(point2)
                self.assertTrue(point1.isEqualTo(point2))
                self.assertTrue(point1.isEqualTo(point2,PyGe.Tol.current))
				
        def test_vector2d_Mul(self):
                v = PyGe.Vector2d.kXAxis
                m = PyGe.Matrix2d.kIdentity
                v =  v * m
                self.assertEqual( v, PyGe.Vector2d(1,0))

        def test_vector2d_MatMul(self):
                v = PyGe.Vector2d.kXAxis
                m = PyGe.Matrix2d.kIdentity
                m.setToRotation(3.14,PyGe.Point2d.kOrigin)
                v =  v @ m
                self.assertEqual( v, PyGe.Vector2d(-0.9999987317275395,0.0015926529164868282))
				
        def test_vector2d_MatMul_default(self):
                v = PyGe.Vector2d.kXAxis
                m = PyGe.Matrix2d.kIdentity
                m.setToRotation(3.14)
                v =  v @ m
                self.assertEqual( v, PyGe.Vector2d(-0.9999987317275395,0.0015926529164868282))

        def test_vector2d_setToProduct(self):
                v1 = PyGe.Vector2d.kXAxis
                m = PyGe.Matrix2d.kIdentity
                v1.setToProduct(PyGe.Vector2d.kYAxis,3.14)
                self.assertEqual( v1, PyGe.Vector2d(0.000000,3.140000))
                v1 = PyGe.Vector2d.kXAxis
                m.setToRotation(3.14)
                v1.setToProduct(m, PyGe.Vector2d.kYAxis)
                self.assertEqual( v1, PyGe.Vector2d(-0.0015926529164868282,-0.9999987317275395))

        def test_vector2d_isParallelTo(self): # test adding default values on the C++ side
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
                p1 = PyGe.Point2d(100,0)
                p2 = PyGe.Point2d(0,0)
                v1 = p2 - p1
                self.assertTrue(v1.isParallelTo(PyGe.Vector2d.kXAxis))
                self.assertTrue(v1.isPerpendicularTo(PyGe.Vector2d.kYAxis))
                self.assertFalse(v1.isUnitLength())
                self.assertFalse(v1.isZeroLength())
                self.assertEqual(v1.length(), 100)
                v1.rotateBy(math.pi)
                v1.negate()
                self.assertTrue(v1.isParallelTo(PyGe.Vector2d.kXAxis))

        def test_point3d_toVec(self):
                pO = PyGe.Point3d(0,0,0)
                p1 = PyGe.Point3d(0,100,0)
                v1 = p1 - pO
                self.assertEqual(v1.length(), 100)
                self.assertTrue(v1.isParallelTo(PyGe.Vector3d.kYAxis))

        def test_matrix3d_set1(self):
                pO = PyGe.Point3d(1,10,100)
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
                self.assertEqual(pO,pO2)
                self.assertEqual(vX,vX2)
                self.assertEqual(vY,vY2)
                self.assertEqual(vZ,vZ2)
                self.assertEqual(vX2.length(),2)
                self.assertEqual(vY2.length(),3)
                self.assertEqual(vZ2.length(),4)
                #print(xf)

        def test_point3d_translation(self):
                pO = PyGe.Point3d(1,10,100)
                vX = PyGe.Vector3d.kXAxis
                vY = PyGe.Vector3d.kYAxis
                vZ = PyGe.Vector3d.kZAxis
                xf = PyGe.Matrix3d.translation(pO.asVector())
                pO2 = PyGe.Point3d.kOrigin
                vX2 = PyGe.Vector3d.kXAxis
                vY2 = PyGe.Vector3d.kYAxis
                vZ2 = PyGe.Vector3d.kZAxis
                xf.getCoordSystem(pO2, vX2, vY2, vZ2)
                self.assertEqual(pO,pO2)
                self.assertEqual(vX,vX2)
                self.assertEqual(vY,vY2)
                self.assertEqual(vZ,vZ2)
                
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
                
                
def PyRxCmd_pyge():
        try:
                suite = unittest.TestLoader().loadTestsFromTestCase(TestGe)
                print('TestGe')
                print(unittest.TextTestRunner(verbosity=0).run(suite))
        except Exception as err:
                PyRxApp.Printf(err)


    

