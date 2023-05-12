import os
import unittest

import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor
print("testname = pyentity")


class TestDbEntity(unittest.TestCase):
    def test_property_ids(self):
        line = PyDb.Line(PyGe.Point3d(0, 0, 0), PyGe.Point3d(100, 100, 0))
        self.assertEqual(line.objectId().isNull(), True)
        line.setDatabaseDefaults()
        line.setColorIndex(7)
        line2 =  PyDb.Line()
        line2.setPropertiesFrom(line)
        self.assertEqual(line2.colorIndex(), 7)
        
        
def PyRxCmd_pyentity():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestDbEntity)
        print('TestDbPoint')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        PyRxApp.Printf(err)
