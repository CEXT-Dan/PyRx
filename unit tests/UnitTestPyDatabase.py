import os 
import unittest
import math

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("testname = pydbtest")

class TestDatabase(unittest.TestCase):

    def test_dbcore_strconversions(self):
        flag = Ed.Core.setVar("DIMZIN", 0)
        self.assertEqual(flag,True)
        val = Db.Core.angToF("180", 0)
        self.assertAlmostEqual(val, math.pi,8)
        val = Db.Core.angToF("180d0'0\"", 1)
        self.assertAlmostEqual(val, math.pi,8)
        val = Db.Core.angToF("200.0000g", 2)
        self.assertAlmostEqual(val, math.pi,8)
        val = Db.Core.angToF("3.1416r", 3)
        self.assertEqual(val, 3.1416)
        val = Db.Core.angToF("W", 4)
        self.assertAlmostEqual(val, math.pi,8)
        sval = Db.Core.angToS(math.pi, 0, 2)
        self.assertEqual(sval,"180.00")
        
    def test_dbcore_activeDatabaseArray(self):
        dbs = Db.Core.activeDatabaseArray()
        self.assertNotEqual(len(dbs), 0)
        
    def test_property_ids(self):
        self.assertEqual(Db.Database.className(),"AcDbDatabase")
        db = Db.HostApplicationServices().workingDatabase() 
        angbase = db.angbase()
        db.setAngbase(1)
        self.assertEqual(db.angbase(),1)
        db.setAngbase(angbase)
        self.assertEqual(db.angbase(),angbase)
        self.assertEqual(db.byBlockLinetype().objectClass().name(),"AcDbLinetypeTableRecord")
        self.assertEqual(db.byBlockMaterial().objectClass().name(),"AcDbMaterial")
        self.assertEqual(db.byLayerLinetype().objectClass().name(),"AcDbLinetypeTableRecord")
        self.assertEqual(db.byLayerMaterial().objectClass().name(),"AcDbMaterial")

        self.assertEqual(db.clayer().objectClass().name(),"AcDbLayerTableRecord")
        self.assertEqual(db.cmlstyleID().objectClass().name(),"AcDbMlineStyle")
        self.assertEqual(db.colorDictionaryId().objectClass().name(),"AcDbDictionary")
        
    def test_SymUtilServices(self):
        db = Db.HostApplicationServices().workingDatabase() 
        sus = Db.SymUtilServices()
        self.assertEqual(sus.blockModelSpaceId(db), db.modelSpaceId())
        self.assertEqual(sus.blockModelSpaceName(), "*Model_Space")
        self.assertEqual(sus.hasVerticalBar("str|str"), True)
        self.assertEqual(sus.hasVerticalBar("strstr"), False)
        self.assertEqual(sus.compareSymbolName("strstr", "strstr"),0)
        self.assertEqual(sus.compareSymbolName("strstr", "ztrstr"),-1)


def PyRxCmd_pydbtest():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestDatabase)
        print('TestDatabase')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        print(err)


    

