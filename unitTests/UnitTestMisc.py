import unittest
import testcfg
import dbc

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PySm as Sm
import PyGs as Gs
import wx


host = Ap.Application.hostAPI()


class TestMisc(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestMisc, self).__init__(*args, **kwargs)
        
    def test_gs_getBlockImage(self):
        objHnd = Db.Handle("36f")
        objId = dbc.dbs["dynblock"].getObjectId(False, objHnd)
        img: wx.Image = Gs.Core.getBlockImage(objId, 32, 32, 1.0, [0, 0, 0])
        self.assertTrue(img.IsOk, True)
        self.assertEqual(img.GetHeight(),32)
        self.assertEqual(img.GetWidth(),32)

    
def MiscTester():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestMisc)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestMisc"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print("TestMisc")
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
