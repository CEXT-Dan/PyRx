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
    
    @unittest.skipIf(*testcfg.makeSkip(testcfg.ETFlags.eBRX))
    def test_all_ctor(self):
        self.assertFalse(Sm.CustomPropertyValue().isNull())
        self.assertFalse(Sm.CustomPropertyBag().isNull())
        self.assertFalse(Sm.FileReference().isNull())
        self.assertFalse(Sm.NamedDbObjectReference().isNull())
        self.assertFalse(Sm.DbLayoutReference().isNull())
        self.assertFalse(Sm.DbViewReference().isNull())
        self.assertFalse(Sm.DbBlockRecordReference().isNull())
        self.assertFalse(Sm.ProjectPointLocation().isNull())
        self.assertFalse(Sm.DbObjectReference().isNull())
        self.assertFalse(Sm.PersistProxy().isNull())
        self.assertFalse(Sm.ObjectReference().isNull())
        self.assertFalse(Sm.PublishOptions().isNull())
        self.assertFalse(Sm.SheetSelSet().isNull())
        self.assertFalse(Sm.SheetSelSets().isNull())
        self.assertFalse(Sm.SheetView().isNull())
        self.assertFalse(Sm.SheetViews().isNull())
        self.assertFalse(Sm.ProjectPointLocations().isNull())
        self.assertFalse(Sm.Resources().isNull())
        self.assertFalse(Sm.ViewCategory().isNull())
        self.assertFalse(Sm.ViewCategories().isNull())
        self.assertFalse(Sm.CalloutBlocks().isNull())
        self.assertFalse(Sm.Subset().isNull())
        self.assertFalse(Sm.Sheet().isNull())
        self.assertFalse(Sm.SheetSet().isNull())
        self.assertFalse(Sm.SmDatabase().isNull())
       
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
