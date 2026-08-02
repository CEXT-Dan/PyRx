
from pyrx import Db, Ge, Rx


class TestPyDbEvalVariant:
    def test_ctor(self):
        
        on = Db.EvalVariant(1,True)#int16
        assert on.getType() == Db.DwgDataType.kDwgInt16
        assert on.getInt16() == 1
        assert on.toString() == '1'
        
        on = Db.EvalVariant(1,False)#int32
        assert on.getType() == Db.DwgDataType.kDwgInt32
        assert on.getInt32() == 1
        assert on.toString() == '1'
        
        on = Db.EvalVariant(1)#int16
        assert on.getType() == Db.DwgDataType.kDwgInt16
        assert on.getInt16() == 1
        assert on.toString() == '1'
        
        on = Db.EvalVariant(33000)#int32
        assert on.getType() == Db.DwgDataType.kDwgInt32
        assert on.getInt32() == 33000
        assert on.toString() == '33000'
        
        off = Db.EvalVariant(0,True)
        assert off.getType() == Db.DwgDataType.kDwgInt16
        assert off.getInt16() == 0
        assert off.toString() == '0'
        
        a = Db.EvalVariant(1.1234)
        assert a.getType() == Db.DwgDataType.kDwgReal
        assert a.getDouble() == 1.1234
        assert a.toString() == '1.1234'
        
        b = Db.EvalVariant("hello world")
        assert b.getType() == Db.DwgDataType.kDwgText
        assert b.getString() == "hello world"
        assert b.toString() == "hello world"
        
        id = Db.curDb().blockTableId()
        d = Db.EvalVariant(id)
        assert d.getType() == Db.DwgDataType.kDwgSoftPointerId
        assert d.getObjectId() == id
        
        #point 3d ctore is wrong, there is not Db.DwgDataType.kDwg2Real
        p1 = Ge.Point2d(1,2)
        p2 = Ge.Point3d(1,2,0)
        e = Db.EvalVariant(p1)
        assert e.getType() == Db.DwgDataType.kDwg3Real
        assert e.getPoint3d() == p2
        
        p3 = Ge.Point3d(1,2,3)
        e = Db.EvalVariant(p3)
        assert e.getType() == Db.DwgDataType.kDwg3Real
        assert e.getPoint3d() == p3
        assert e.toString() == '(1,2,3)'
        
    def test_setter(self):
        a = Db.EvalVariant()
        a.setDouble(Db.DxfCode.kDxfAngle, 1.1234)
        assert a.getType() == Db.DwgDataType.kDwgReal
        assert a.getDouble() == 1.1234
            
        b = Db.EvalVariant()
        b.setString(Db.DxfCode.kDxfDimPostStr, "hello world")
        assert b.getType() == Db.DwgDataType.kDwgText
        assert b.getString() == "hello world"
            
        c = Db.EvalVariant()
        c.setInt32(Db.DxfCode.kDxfXdInteger32, 1001)
        assert c.getType() == Db.DwgDataType.kDwgInt32
        assert c.getInt32() == 1001
            
        id = Db.curDb().blockTableId()
        d = Db.EvalVariant()
        d.setObjectId(Db.DxfCode.kDxfSoftPointerId,id)
        assert d.getType() == Db.DwgDataType.kDwgSoftPointerId
        assert d.getObjectId() == id
            
        p3 = Ge.Point3d(1,2,3)
        e = Db.EvalVariant()
        e.setPoint3d(Db.DxfCode.kDxfXCoord,p3)
        assert e.getType() == Db.DwgDataType.kDwg3Real
        assert e.getPoint3d() == p3
        
        on = Db.EvalVariant()
        on.setInt16(Rx.LispType.kInt16, 1)
        assert on.getType() == Db.DwgDataType.kDwgInt16
        assert on.getInt16() == 1
        
        off = Db.EvalVariant()
        off.setInt16(Rx.LispType.kInt16, 0)
        assert off.getType() == Db.DwgDataType.kDwgInt16
        assert off.getInt16() == 0


    

