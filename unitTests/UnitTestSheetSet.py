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

host = Ap.Application.hostAPI()


class TestSheetSet(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestSheetSet, self).__init__(*args, **kwargs)

    def test_cast_to_sheet(self):
        path = dbc.mediapath + "SSTest.dst"
        mgr = Sm.SheetSetMgr()
        smdb = mgr.openDatabase(path)
        for smo in smdb.getPersistObjects():
            if Sm.Sheet.className() == smo.getTypeName():
                sheet = Sm.Sheet.cast(smo)
                self.assertGreater(len(sheet.getTitle()), 0)
                self.assertGreater(len(sheet.getTitle()), 0)
        mgr.closeAll()


def sheetSetTester():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestSheetSet)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestSheetSet"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print("TestSheetSet")
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
