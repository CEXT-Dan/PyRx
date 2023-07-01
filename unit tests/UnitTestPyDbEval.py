import os 
import unittest

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("testname = pydbeval")

class TestPyDbEvalVariant(unittest.TestCase):
        
    def test_ctor(self):
        a = Db.EvalVariant(1.1234)
        self.assertEqual(a.getType(),Db.DwgDataType.kDwgReal)
        self.assertEqual(a.getDouble(),1.1234)
        
        b = Db.EvalVariant("hello world")
        self.assertEqual(b.getType(),Db.DwgDataType.kDwgText)
        self.assertEqual(b.getString(),"hello world")
        
        c = Db.EvalVariant(1001)
        self.assertEqual(c.getType(),Db.DwgDataType.kDwgInt32)
        self.assertEqual(c.getInt32(),1001)
        
        id = Db.curDb().blockTableId()
        d = Db.EvalVariant(id)
        self.assertEqual(d.getType(),Db.DwgDataType.kDwgSoftPointerId)
        self.assertEqual(d.getObjectId(),id)
        
        #point 3d ctore is wrong, there is not Db.DwgDataType.kDwg2Real
        p1 = Ge.Point2d(1,2)
        p2 = Ge.Point3d(1,2,0)
        e = Db.EvalVariant(p1)
        self.assertEqual(e.getType(),Db.DwgDataType.kDwg3Real)
        self.assertEqual(e.getPoint3d(),p2)
        
        p3 = Ge.Point3d(1,2,3)
        e = Db.EvalVariant(p3)
        self.assertEqual(e.getType(),Db.DwgDataType.kDwg3Real)
        self.assertEqual(e.getPoint3d(),p3)
        
    def test_setter(self):
        a = Db.EvalVariant()
        a.setDouble(Db.DxfCode.kDxfAngle, 1.1234)
        self.assertEqual(a.getType(),Db.DwgDataType.kDwgReal)
        self.assertEqual(a.getDouble(),1.1234)
            
        b = Db.EvalVariant()
        b.setString(Db.DxfCode.kDxfDimPostStr, "hello world")
        self.assertEqual(b.getType(),Db.DwgDataType.kDwgText)
        self.assertEqual(b.getString(),"hello world")
            
        c = Db.EvalVariant()
        c.setInt32(Db.DxfCode.kDxfXdInteger32, 1001)
        self.assertEqual(c.getType(),Db.DwgDataType.kDwgInt32)
        self.assertEqual(c.getInt32(),1001)
            
        id = Db.curDb().blockTableId()
        d = Db.EvalVariant()
        d.setObjectId(Db.DxfCode.kDxfSoftPointerId,id)
        self.assertEqual(d.getType(),Db.DwgDataType.kDwgSoftPointerId)
        self.assertEqual(d.getObjectId(),id)
            
        p3 = Ge.Point3d(1,2,3)
        e = Db.EvalVariant()
        e.setPoint3d(Db.DxfCode.kDxfXCoord,p3)
        self.assertEqual(e.getType(),Db.DwgDataType.kDwg3Real)
        self.assertEqual(e.getPoint3d(),p3)
            
def PyRxCmd_pydbeval(): 
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestPyDbEvalVariant)
        print('TestDbEval')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        PyRxApp.Printf(err)


    

