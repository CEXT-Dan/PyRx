import os
import unittest
import math

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
        
    def test_dbarc(self):
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 20, 0, math.pi)
        self.assertEqual(arc.startAngle(), 0)
        self.assertEqual(arc.endAngle(),  math.pi)
        self.assertEqual(arc.totalAngle(),  math.pi)
        #curve
        self.assertEqual(arc.getStartPoint(),  Ge.Point3d(20, 0, 0))
        self.assertEqual(arc.getEndPoint(),  Ge.Point3d(-20, 0, 0))
        
    def test_dbcircle(self):
        circle = Db.Circle()
        circle.setCenter(Ge.Point3d(1, 2, 3))
        self.assertEqual(circle.center(),  Ge.Point3d(1, 2, 3))
        circle.setRadius(20)
        self.assertEqual(circle.radius(), 20)
        self.assertEqual(circle.diameter(), 40)

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
    
    def test_dbmtext(self):
        db = Db.curDb()
        mt = Db.MText()
        mt.setDatabaseDefaults(db)
        mt.setTextStyle(db.textstyle())
        self.assertEqual(mt.textStyle(),db.textstyle())
        mt.setLocation(Ge.Point3d(1,20,3))
        self.assertEqual(mt.location(),Ge.Point3d(1, 20, 3))
        mt.setContents("THIS IS IT!")
        self.assertEqual(mt.contents(),"THIS IS IT!")
        mt.setAttachment(Db.MTextAttachmentPoint.kBottomCenter)
        self.assertEqual(mt.attachment(), Db.MTextAttachmentPoint.kBottomCenter)
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(mt)
        
    def test_dbleader(self):
        db = Db.HostApplicationServices().workingDatabase();
        model = Db.BlockTableRecord(db.modelSpaceId(),Db.OpenMode.ForWrite)
        
        #create anno
        mtext = Db.MText()
        mtext.setDatabaseDefaults()
        mtext.setLocation(Ge.Point3d(105, 100,0))
        mtext.setContents("what we have, is failure to communicate")
        
        #add anno to db and close!
        mtid = model.appendAcDbEntity(mtext)
        mtext.close()
       
        #create leader
        leader = Db.Leader()
        leader.setDatabaseDefaults()
        leader.appendVertex(Ge.Point3d(0,0,0))
        leader.appendVertex(Ge.Point3d(100,100,0))
        
        self.assertEqual(leader.vertexAt(0),Ge.Point3d(0, 0, 0))
        self.assertEqual(leader.vertexAt(1),Ge.Point3d(100, 100, 0))
        
        #set leader to red
        c = Db.Color()
        c.setRGB(255,0,0)
        leader.setColor(c)
        
        #add leader to db
        model.appendAcDbEntity(leader)
        
        #attach
        leader.attachAnnotation(mtid)
        self.assertEqual(leader.annotationObjId(), mtid)
        

        
def PyRxCmd_pyentity():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestDbEntity)
        print('TestDbPoint')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        PyRxApp.Printf(err)
