import os
import unittest
import testcfg

import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor

host = PyAp.Application.hostAPI()

class TestRxObject(unittest.TestCase):
    def test_isA(self):
        line1 = PyDb.Line()
        line2 = PyDb.Line()
        circle = PyDb.Circle()
        self.assertEqual(line1.isA(),line2.isA())
        self.assertEqual(line1.isA(),line2.isA())
        self.assertNotEqual(line1.isA(),circle.isA())
        
    def test_isKindOf(self):
        line1 = PyDb.Line()
        self.assertTrue(line1.isKindOf(PyDb.Line.desc()))
        self.assertTrue(line1.isKindOf(PyDb.Curve.desc()))
        self.assertTrue(line1.isKindOf(PyDb.Entity.desc()))
        self.assertTrue(line1.isKindOf(PyDb.DbObject.desc()))
        self.assertTrue(line1.isKindOf(PyGi.Drawable.desc()))
        self.assertTrue(line1.isKindOf(PyRx.RxObject.desc()))
        self.assertFalse(line1.isKindOf(PyDb.Circle.desc()))
        self.assertFalse(line1.isKindOf(PyDb.BlockReference.desc()))
        
    #PyRxClass tests
    def test_isDerivedFrom(self):
        line1 = PyDb.Line()
        clss = line1.isA()
        self.assertTrue(clss.isDerivedFrom(PyDb.Line.desc()))
        self.assertTrue(clss.isDerivedFrom(PyDb.Curve.desc()))
        self.assertTrue(clss.isDerivedFrom(PyDb.Entity.desc()))
        self.assertTrue(clss.isDerivedFrom(PyDb.DbObject.desc()))
        self.assertTrue(clss.isDerivedFrom(PyGi.Drawable.desc()))
        self.assertTrue(clss.isDerivedFrom(PyRx.RxObject.desc()))
        self.assertFalse(clss.isDerivedFrom(PyDb.Circle.desc()))
        self.assertFalse(clss.isDerivedFrom(PyDb.BlockReference.desc()))
        
    def test_myParent(self):
        pline = PyDb.Polyline()
        clss = pline.isA()
        line = PyDb.Line()
        clss2 = line.isA()
        self.assertEqual(clss.myParent(),PyDb.Curve.desc())
        self.assertEqual(clss.myParent(),clss2.myParent())
        
    def test_name(self):
        pline = PyDb.Polyline()
        clss = pline.isA()
        name = clss.name()
        appname = clss.appName()
        dxfName = clss.dxfName()
        self.assertEqual(name,'AcDbPolyline')
        self.assertEqual(appname,'ObjectDBX Classes')
        self.assertEqual(dxfName,'LWPOLYLINE')


def pyrxobject():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestRxObject)
        print('pyrxobject')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        print.Printf(err)
