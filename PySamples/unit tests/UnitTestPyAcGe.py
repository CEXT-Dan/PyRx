import os 
import unittest

import PyRxApp# = all the global methods like acutPrintf, 
import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 
print("testname = pyge")


class TestGe(unittest.TestCase):
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

def PyRxCmd_pyge():
        try:
                print(".\nstart tests----------------------------------------------------------------------")
                suite = unittest.TestLoader().loadTestsFromTestCase(TestGe)
                unittest.TextTestRunner(verbosity=2).run(suite)
                print(".\nend tests  ----------------------------------------------------------------------")
        except Exception as err:
                PyRxApp.Printf(err)


    

