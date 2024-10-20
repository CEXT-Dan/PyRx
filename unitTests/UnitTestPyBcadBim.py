import os
import unittest
import math
import testcfg

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyBrxBim as Bm
import dbc

host = Ap.Application.hostAPI()


class TestBCadBim(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestBCadBim, self).__init__(*args, **kwargs)

    def __del__(self):
        pass

    def test_IfcEntityDesc(self):
        w = Bm.IfcEntityDesc.IfcWindow()
        self.assertEqual(w.name(), "IfcWindow")

        wc = Bm.IfcEntityDesc.IfcWallStandardCase()
        self.assertFalse(wc.isDerivedFrom(w, Bm.IfcSchemaId.eIfcSchemaLast))

        wc = Bm.IfcEntityDesc.IfcWindowStandardCase()
        self.assertTrue(wc.isDerivedFrom(w, Bm.IfcSchemaId.eIfcSchemaLast))

    def test_IfcVariant(self):
        v = Bm.IfcVariant()

        v.setBool(True)
        self.assertEqual(v.type(), Bm.IfcValueType.eBool)
        self.assertEqual(v.getBool(), True)

        v.setInt(42)
        self.assertEqual(v.type(), Bm.IfcValueType.eInt)
        self.assertEqual(v.getInt(), 42)

        v.setUInt(44)
        self.assertEqual(v.type(), Bm.IfcValueType.eUInt)
        self.assertEqual(v.getUInt(), 44)

        v.setReal(3.14)
        self.assertEqual(v.type(), Bm.IfcValueType.eReal)
        self.assertEqual(v.getReal(), 3.14)

        vs = Bm.IfcString("OMG YAY")
        v.setString(vs)
        self.assertEqual(v.type(), Bm.IfcValueType.eString)
        self.assertEqual(v.getString().c_str(), "OMG YAY")

    def test_bimClassification_Window_properties(self):
        objHnd = Db.Handle("81B")
        objId = dbc.dbs["ebim1"].getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        self.assertTrue(Bm.BimClassification.isClassifiedAsAnyBuildingElement(objId))
        bimtype = Bm.BimClassification.getClassification(objId)
        self.assertEqual(bimtype, Bm.BimElementType.eBimWindow)
        data = Bm.BimClassification.getPropertyDict(objId)
        self.assertTrue("OverallWidth" in data)
        self.assertTrue("OverallHeight" in data)
        wv = Bm.BimClassification.getProperty(
            objId, "OverallWidth", data["OverallWidth"]
        )
        hv = Bm.BimClassification.getProperty(
            objId, "OverallHeight", data["OverallHeight"]
        )
        self.assertAlmostEqual(wv.getDouble(), 1866.0, 4)
        self.assertAlmostEqual(hv.getDouble(), 1091.5, 4)

def pybcbimtest():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestBCadBim)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestBricsCADBim"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print("TestBricsCADBim")
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
