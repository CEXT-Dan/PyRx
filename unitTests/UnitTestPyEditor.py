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
       
    def test_ed_core_getsym(self):
        rb = Ed.Core.getSym("PYRXGLOBALVAR")
        self.assertEqual(rb,[(Rx.LispType.kInt16, 1)])
        
    def test_ed_core_invoke(self):
        args = [(Rx.LispType.kText, "c:testLispInvoke"),(Rx.LispType.kInt16,10),(Rx.LispType.kNone,0) ]
        rbout = Ed.Core.invoke(args)
        self.assertEqual(rbout,[(Rx.LispType.kInt16,10)])
        
    @unittest.skipIf(host == "ZRX24", "known failure")  
    def test_ed_core_invoke_ss(self):
        args = [(Rx.LispType.kText, "c:LispInvokeSStest"),(Rx.LispType.kNone,0) ]
        rbout = Ed.Core.invoke(args)
        self.assertEqual(rbout,[(Rx.LispType.kT_atom,0)])
         
    @unittest.skipIf(host == "BRX24" or host == "GRX24" or host == "ZRX24", "BricsCAD known failure")
    def test_evaluateDiesel(self):
        val = Ed.Core.evaluateDiesel('$(eval,"Current layer: "$(getvar,clayer))')
        self.assertEqual(val, "Current layer: 0")
        
    def test_ed_core_grDrawPoly2d(self):
        p2d = [Ge.Point2d(100,100),Ge.Point2d(200,100),Ge.Point2d(200,200)]
        res = Ed.Core.grDrawPoly2d(p2d,2)
        self.assertEqual(res, 5100)
        
    def test_ed_core_grDrawPoly3d(self):
        p3d = [Ge.Point3d(0,0,0),Ge.Point3d(100,0,0),Ge.Point3d(100,100,0)]
        res = Ed.Core.grDrawPoly3d(p3d,3)
        self.assertEqual(res, 5100)
def pyeditor():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestEditor)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestEditor"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print('TestEditor')
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
