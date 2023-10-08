import os
import unittest

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

#requires win32com.client
import AcadApp24 as AcadApp
import AcadAppUtils24 as AcUtils

print("testname = pyactivex")

class TestActiveX(unittest.TestCase):
    def test_get_app(self): 
        app = AcUtils.getApp()
        self.assertEqual(app.Name, 'AutoCAD')

    def test_get_dbx(self):
        dbx = AcUtils.getDbx()
        path = ".\\testmedia\\06457.dwg"
        dbx.Open(path,None)
        self.assertEqual(dbx.Name, path)
        self.assertNotEqual(dbx.ModelSpace.Count, 0)

def PyRxCmd_pyactivex():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestActiveX)
        print('TestActiveX')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        print(err)
