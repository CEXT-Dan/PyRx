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

    @unittest.skipIf(*testcfg.makeSkip(testcfg.ETFlags.eGRX))
    def test_gs_getBlockImage(self):
        objHnd = Db.Handle("36f")
        objId = dbc.dbs["dynblock"].getObjectId(False, objHnd)
        img: wx.Image = Gs.Core.getBlockImage(objId, 32, 32, 1.0, [0, 0, 0])
        self.assertTrue(img.IsOk, True)
        self.assertEqual(img.GetHeight(), 32)
        self.assertEqual(img.GetWidth(), 32)

    def test_ap_command_decorator(self):
        commands = Ed.Core.getCommands()
        subcmds = commands["PY_UNITTESTRUNNER"]
        names = [tp[0] for tp in subcmds]
        self.assertTrue("FAR" in names)
        self.assertTrue("FOO" in names)
        self.assertTrue("FOOBAR" in names)
        self.assertTrue("FOOFAR" in names)
        self.assertTrue("SOMEFUNC" in names)

    def test_ap_lisp_decorator(self):
        args = [(Rx.LispType.kText, "C:LPF1"), (Rx.LispType.kNone, 0)]
        rbout = Ed.Core.invoke(args)
        self.assertEqual(rbout, [(Rx.LispType.kInt16, 2)])


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
