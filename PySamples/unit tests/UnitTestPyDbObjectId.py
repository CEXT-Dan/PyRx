import os 
import unittest

import PyRxApp# = all the global methods like acutPrintf, 
import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 
print("testname = pydbobjectid")


class TestDbObjectId(unittest.TestCase):
        def test_property_ids(self):
                id = PyDb.HostApplicationServices().workingDatabase().blockTableId()
                self.assertFalse(id.isNull())
                self.assertNotEqual(id.asOldId(), 0)
                self.assertTrue(id.isResident())
                self.assertTrue(id.isValid())
                db = id.database()
                self.assertEqual(db.className(),"AcDbDatabase")
                self.assertEqual(id.database().className(),"AcDbDatabase")
                self.assertNotEqual(id.database(), None)
                self.assertEqual(id.objectClass().name(),"AcDbBlockTable")
                
def PyRxCmd_pydbobjectid():
        try:
                suite = unittest.TestLoader().loadTestsFromTestCase(TestDbObjectId)
                print('TestDbObjectId')
                print(unittest.TextTestRunner(verbosity=0).run(suite))
        except Exception as err:
                PyRxApp.Printf(err)


    

