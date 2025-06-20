from __future__ import annotations

import unittest

import pytest

from pyrx import Sm
from tests import MEDIA_DIR


def getTestSheetNames():
   return [
        "1 06457 - 14.0",
        "2 06457 - 14.1",
        "3 06457 - S3",
        "4 06457 - 14.2",
        "5 06457 - 30.1",
        "6 06457 - S4",
        "7 06457 - S5",
        "8 06457 - S6",
        "9 06457 - S7",
        "10 06457 - S1",
        "11 06457 - S2",
    ]

def getSheetNamesFromDst():
    path = str(MEDIA_DIR / "SSTest.dst")
    mgr = Sm.SheetSetMgr()
    ssdb = mgr.openDatabase(path)
    ssdb.lockDb()
    try:
        sset = ssdb.getSheetSet()
        return [sheet.getName() for sheet in sset.getSheets()]
    finally:
        ssdb.unlockDb(True)

@pytest.mark.known_failure_ZRX
@pytest.mark.known_failure_GRX
@pytest.mark.known_failure_BRX
class TestSheetSet:
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")
        self.assertEqual = self.assertions.assertEqual
        self.assertFalse = self.assertions.assertFalse
        self.assertTrue = self.assertions.assertTrue
        self.assertGreater = self.assertions.assertGreater
       
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
        
    def test_getsheetnames(self):
        self.assertEqual(getTestSheetNames(),getSheetNamesFromDst())
       
    def test_cast_to_sheet(self):
        try:
            path = str(MEDIA_DIR / "SSTest.dst")
            mgr = Sm.SheetSetMgr()
            smdb = mgr.openDatabase(path)
            for smo in smdb.getPersistObjects():
                if Sm.Sheet.className() == smo.getTypeName():
                    sheet = Sm.Sheet.cast(smo)
                    self.assertGreater(len(sheet.getTitle()), 0)
        finally:
            mgr.closeAll()

    def test_sheet_count(self):
        try:
            path = str(MEDIA_DIR / "SSTest.dst")
            mgr = Sm.SheetSetMgr()
            smdb = mgr.openDatabase(path)
            smdb.lockDb()
            numsheets = 0
            for smo in smdb.getPersistObjects():
                if Sm.SheetSet.className() == smo.getTypeName():
                    numsheets += 1   
            self.assertTrue(numsheets == 1)
        finally:
            smdb.unlockDb(True)
        
    def test_getPropertyValues(self):
        try:
            path = str(MEDIA_DIR / "SSTest.dst")
            mgr = Sm.SheetSetMgr()
            smdb = mgr.openDatabase(path)
            smdb.lockDb()
            for smo in smdb.getPersistObjects():
                if Sm.SheetSet.className() == smo.getTypeName():
                    #bricscad has different behavior here
                    print(smo.getTypeName())
                    ss = Sm.SheetSet.cast(smo)
                    bag = ss.getCustomPropertyBag()
                    #print(bag.getPropertyValues())
                    self.assertFalse(bag.isNull())
                    if len(bag.getPropertyValues()) == 0:
                        continue
                    self.assertTrue(bag.hasProperty('CustProp1'))
        finally:
            smdb.unlockDb(True)
                