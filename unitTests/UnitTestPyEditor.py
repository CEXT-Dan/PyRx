import os
import unittest
import testcfg

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed


host = Ap.Application.hostAPI()

def autoSysVarOSMODE():
    var = Ed.Core.autoSetVar("OSMODE", 0)
    
def autoSysVarANGBASE():
    var = Ed.Core.autoSetVar("ANGBASE", 90)
    
def autoSysVarHPORIGIN():
    var = Ed.Core.autoSetVar("HPORIGIN", Ge.Point2d(100, 100))

class TestEditor(unittest.TestCase):

    def test_get_setvar(self): #just test possible types 
        Ed.Core.setVar("OSMODE", 191)
        self.assertEqual(Ed.Core.getVar("OSMODE"), 191)
        self.assertEqual(Ed.Core.getVar("HPORIGIN"), Ge.Point2d(0, 0))
        self.assertEqual(Ed.Core.getVar("UCSORG"), Ge.Point3d(0, 0, 0))
        self.assertEqual(Ed.Core.getVar("DIMTXSTY"),  "Standard")
        
    def test_autosysvar(self):
        Ed.Core.setVar("OSMODE", 191)
        autoSysVarOSMODE()
        self.assertEqual(Ed.Core.getVar("OSMODE"), 191)
        autoSysVarHPORIGIN()
        self.assertEqual(Ed.Core.getVar("HPORIGIN"), Ge.Point2d(0, 0))
        Ed.Core.setVar("ANGBASE", 0)
        autoSysVarANGBASE()
        self.assertEqual(Ed.Core.getVar("ANGBASE"),0)
        
    def test_ed_core_trans(self):
        rbfrom = [(Rx.LispType.kInt16, 0)] #wcs
        rbto = [(Rx.LispType.kInt16, 1)] #ucs
        ucs = Ed.Editor.getCurrentUCS()
        ucs.setToRotation(3.14159,Ge.Vector3d.kZAxis)
        Ed.Editor.setCurrentUCS(ucs)
        pt = Ge.Point3d(1,2,3)
        out = Ed.Core.trans(pt,rbfrom,rbto,False)
        self.assertTrue(out[0] < 0)
        self.assertTrue(out[1] < 0)
        self.assertTrue(out[2] > 0)
        Ed.Editor.setCurrentUCS(Ge.Matrix3d())

    @unittest.skipIf(host == "BRX24", "BricsCAD known failure")
    def test_evaluateDiesel(self):
        val = Ed.Core.evaluateDiesel('$(eval,"Current layer: "$(getvar,clayer))')
        self.assertEqual(val, "Current layer: 0")
        
def pyeditor():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestEditor)
        print('TestEditor')
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print(unittest.TextTestRunner(testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
