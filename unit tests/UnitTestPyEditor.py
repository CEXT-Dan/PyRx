import os
import unittest


import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("testname = pyeditor")    
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
        
    @unittest.skipIf(host == "BRX24", "BricsCAD known failure")
    def test_evaluateDiesel(self):
        val = Ed.Core.evaluateDiesel('$(eval,"Current layer: "$(getvar,clayer))')
        self.assertEqual(val, "Current layer: 0")
        
def PyRxCmd_pyeditor():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestEditor)
        print('TestEditor')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        print(err)
