import os
import unittest

import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("testname = pyentity")


class TestDbEntity(unittest.TestCase):
    
    def test_dbpoint(self):
        db = Db.curDb()
        pos = Ge.Point3d(100, 100, 0)
        dbp = Db.Point(pos)
        dbp.setDatabaseDefaults(db)
        self.assertEqual(dbp.position(), pos)
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(dbp)
        
    def test_dbline(self):
        line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        self.assertEqual(line.objectId().isNull(), True)
        line.setDatabaseDefaults()
        line.setColorIndex(7)
        line2 =  Db.Line()
        line2.setPropertiesFrom(line)
        self.assertEqual(line2.colorIndex(), 7)
        self.assertEqual(line.startPoint(), Ge.Point3d(0, 0, 0))
        self.assertEqual(line.endPoint(), Ge.Point3d(100, 100, 0))
        line.extend(False,Ge.Point3d(200, 200, 0))
        self.assertEqual(line.endPoint(), Ge.Point3d(200, 200, 0))
        line.setEndPoint(Ge.Point3d(100, 100, 0))
        self.assertEqual(line.endPoint(), Ge.Point3d(100, 100, 0))
        line.setStartPoint(Ge.Point3d(1, 11, 0))
        self.assertEqual(line.startPoint(), Ge.Point3d(1, 11, 0))
        
    def test_dbtext(self):
        db = Db.curDb()
        text = Db.Text()
        text.setDatabaseDefaults()
        text.setPosition(Ge.Point3d(100, 100, 0))
        self.assertEqual(text.position(),Ge.Point3d(100, 100, 0))
        text.setTextString("Hello World")
        self.assertEqual(text.textString(),"Hello World")
        text.setTextStyle(db.textstyle())
        text.setJustification(Db.TextAlignment.kTextAlignmentMiddleCenter)
        self.assertEqual(text.justification(),Db.TextAlignment.kTextAlignmentMiddleCenter)
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(text)
        
       
        
        

        
    

        
def PyRxCmd_pyentity():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestDbEntity)
        print('TestDbPoint')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        PyRxApp.Printf(err)
