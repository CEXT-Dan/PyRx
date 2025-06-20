import unittest

from pyrx import Db, Ge, Rx


class TestPyDbEvalVariant:
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")
        self.assertEqual = self.assertions.assertEqual
        
    def test_ctor(self):
        
        on = Db.EvalVariant(1,True)#int16
        self.assertEqual(on.getType(),Db.DwgDataType.kDwgInt16)
        self.assertEqual(on.getInt16(),1)
        self.assertEqual(on.toString(),'1')
        
        off = Db.EvalVariant(0,True)
        self.assertEqual(off.getType(),Db.DwgDataType.kDwgInt16)
        self.assertEqual(off.getInt16(),0)
        self.assertEqual(off.toString(),'0')
        
        a = Db.EvalVariant(1.1234)
        self.assertEqual(a.getType(),Db.DwgDataType.kDwgReal)
        self.assertEqual(a.getDouble(),1.1234)
        self.assertEqual(a.toString(),'1.1234')
        
        b = Db.EvalVariant("hello world")
        self.assertEqual(b.getType(),Db.DwgDataType.kDwgText)
        self.assertEqual(b.getString(),"hello world")
        self.assertEqual(b.toString(),"hello world")
        
        c = Db.EvalVariant(1001)
        self.assertEqual(c.getType(),Db.DwgDataType.kDwgInt32)
        self.assertEqual(c.getInt32(),1001)
        self.assertEqual(c.toString(),'1001')
        
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
        self.assertEqual(e.toString(),'(1,2,3)')
        
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
        
        on = Db.EvalVariant()
        on.setInt16(Rx.LispType.kInt16, 1)
        self.assertEqual(on.getType(),Db.DwgDataType.kDwgInt16)
        self.assertEqual(on.getInt16(),1)
        
        off = Db.EvalVariant()
        off.setInt16(Rx.LispType.kInt16, 0)
        self.assertEqual(off.getType(),Db.DwgDataType.kDwgInt16)
        self.assertEqual(off.getInt16(),0)


    

