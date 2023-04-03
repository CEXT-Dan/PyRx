import os 
import unittest

import PyRxApp# = all the global methods like acutPrintf, 
import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 


class TestDbObject(unittest.TestCase):
        def test_property_ids(self):
                self.assertEqual(PyDb.DbObject.className(),"AcDbDatabase")
                
def PyRxCmd_pydbobject():
        try:
                print(".\nstart tests----------------------------------------------------------------------")
                suite = unittest.TestLoader().loadTestsFromTestCase(TestDbObject)
                unittest.TextTestRunner(verbosity=2).run(suite)
                print(".\nend tests  ----------------------------------------------------------------------")
        except Exception as err:
                PyRxApp.Printf(err)


    

