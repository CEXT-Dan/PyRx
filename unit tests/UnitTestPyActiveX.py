import os
import unittest

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

#requires win32com.client
import AxApp24 as Ax
import AxAppUtils24 as AxUt

print("testname = pyactivex")

class TestActiveX(unittest.TestCase):
    def test_get_app(self): 
        app = Ax.getApp()
        self.assertEqual(app.Name, 'AutoCAD')
    
    def test_get_dbx(self):
        dbx = Ax.getDbx()
        path = ".\\testmedia\\06457.dwg"
        dbx.Open(path,None)
        for ent in dbx.ModelSpace:
            self.assertNotEqual(ent.ObjectID, 0)
            
        self.assertEqual(dbx.Name, path)
        self.assertNotEqual(dbx.ModelSpace.Count, 0)
        
    def test_Add3DFaceProps(self): 
        app = Ax.getApp()
        model = app.ActiveDocument.ModelSpace
        face = model.Add3DFace((0,0,0),(0,100,0),(100,100,0),(100,0,0))
        face.SetCoordinate(3,face.Coordinate(3))
        self.assertEqual(face.Coordinate(3), (100,0,0))
        
    def test_ent_copy(self): 
        app = Ax.getApp()
        model = app.ActiveDocument.ModelSpace
        line = model.AddLine((0,0,0),(100,100,0))
        lineCopy = line.Copy()
        self.assertEqual(line.StartPoint,lineCopy.StartPoint)
        self.assertEqual(line.EndPoint,lineCopy.EndPoint)

def PyRxCmd_pyactivex():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestActiveX)
        print('TestActiveX')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        print(err)
