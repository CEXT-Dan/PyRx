import os
import unittest
import math
import testcfg
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb as Db  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor
import dbc


host = PyAp.Application.hostAPI()


class TestGe(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestGe, self).__init__(*args, **kwargs)

    def __del__(self):
        pass

    

    @unittest.skipIf(
        *testcfg.makeSkip(
            testcfg.ETFlags.eBRX | testcfg.ETFlags.eGRX | testcfg.ETFlags.eZRX
        )
    )
   
    def test_dbextents3d_contains(self):
        ex1 = Db.Extents(PyGe.Point3d(0, 0, 0), PyGe.Point3d(100, 100, 100))
        self.assertTrue(ex1.contains(PyGe.Point3d(50, 50, 50)))
        self.assertFalse(ex1.contains(PyGe.Point3d(101, 50, 50)))

    def test_dbextents2d_contains(self):
        ex1 = Db.Extents2d(PyGe.Point2d(0, 0), PyGe.Point2d(100, 100))
        self.assertTrue(ex1.contains(PyGe.Point2d(50.0, 50)))
        self.assertFalse(ex1.contains(PyGe.Point2d(101, 50)))


def pyge():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestGe)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestGe"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print("TestGe")
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
