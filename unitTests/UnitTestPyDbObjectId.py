import os 
import unittest
import testcfg

import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 

host = PyAp.Application.hostAPI()


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
                
    def test_handle(self):
        db = PyDb.HostApplicationServices().workingDatabase()
        id = db.blockTableId()
        bt = PyDb.BlockTable(id, PyDb.OpenMode.ForRead)
        hn = bt.getHandle()
        self.assertEqual(hn.isNull(),False)
        id2 = db.getObjectId(False,hn)
        self.assertEqual(id,id2)
        self.assertTrue(id.isValid())
        self.assertTrue(id2.isValid())
        bt.close()
                
def pydbobjectid():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestDbObjectId)
        print('TestDbObjectId')
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)


    

