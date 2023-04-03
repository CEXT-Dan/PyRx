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
                id = PyDb.DbHostApplicationServices().workingDatabase().blockTableId()
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
                print(".\nstart tests----------------------------------------------------------------------")
                suite = unittest.TestLoader().loadTestsFromTestCase(TestDbObjectId)
                unittest.TextTestRunner(verbosity=2).run(suite)
                print(".\nend tests  ----------------------------------------------------------------------")
        except Exception as err:
                PyRxApp.Printf(err)


    

