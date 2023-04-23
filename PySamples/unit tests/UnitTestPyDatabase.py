import os 
import unittest

import PyRxApp# = all the global methods like acutPrintf, 
import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 
print("testname = pydbtest")

class TestDatabase(unittest.TestCase):
        def test_fail(self):
                self.assertEqual("Scooby","Scooby")
        def test_property_ids(self):
                self.assertEqual(PyDb.Database.className(),"AcDbDatabase")
                db = PyDb.HostApplicationServices().workingDatabase() 
                db.setAngbase(1)
                self.assertEqual(db.angbase(),1)
                self.assertEqual(db.byBlockLinetype().objectClass().name(),"AcDbLinetypeTableRecord")
                self.assertEqual(db.byBlockMaterial().objectClass().name(),"AcDbMaterial")
                self.assertEqual(db.byLayerLinetype().objectClass().name(),"AcDbLinetypeTableRecord")
                self.assertEqual(db.byLayerMaterial().objectClass().name(),"AcDbMaterial")

                self.assertEqual(db.clayer().objectClass().name(),"AcDbLayerTableRecord")
                self.assertEqual(db.cmlstyleID().objectClass().name(),"AcDbMlineStyle")
                self.assertEqual(db.colorDictionaryId().objectClass().name(),"AcDbDictionary")


def PyRxCmd_pydbtest():
        try:
                suite = unittest.TestLoader().loadTestsFromTestCase(TestDatabase)
                print('TestDatabase')
                print(unittest.TextTestRunner(verbosity=0).run(suite))
        except Exception as err:
                PyRxApp.Printf(err)


    

