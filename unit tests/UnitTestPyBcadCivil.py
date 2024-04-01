import os
import unittest
import math

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyBrxCv as Cv
import time

print("testname = pybcciviltest")
host = Ap.Application.hostAPI()


class TestBCadCivil(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestBCadCivil, self).__init__(*args, **kwargs)

        self.BCADCIVIL1 = Db.Database(False, True)
        self.BCADCIVIL1.readDwgFile("./testmedia/BCADCIVIL1.dwg")
        self.BCADCIVIL1.closeInput(True)

    def __del__(self):
        del(self.BCADCIVIL1)

    def test_BsysCvDbAlignment_dxfName(self):
        objHnd = Db.Handle("AE")
        objId = self.BCADCIVIL1.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        dbo = Db.Entity(objId)
        self.assertEqual(dbo.isA().dxfName(), "BsysCvDbAlignment")
        
    def test_BsysCvDbAlignment_obj(self):
        objHnd = Db.Handle("AE")
        objId = self.BCADCIVIL1.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        hAlignment = Cv.CvDbHAlignment(objId)
        self.assertFalse(hAlignment.isNullObj())
        self.assertEqual(hAlignment.elementCount() ,3)
        
    def test_BsysCvDbAlignment_cast(self):
        objHnd = Db.Handle("AE")
        objId = self.BCADCIVIL1.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        hAlignment = Cv.CvDbHAlignment(objId)
        
        for id in hAlignment.getUnorderedElementIds():
            element : Cv.CvDbHAlignmentElement = hAlignment.elementAtId(id)
            self.assertFalse(element.isNullObj())
            if Cv.HAlignmentElementType.eLine == element.type():
                line: Cv.CvDbHAlignmentLine = Cv.CvDbHAlignmentLine.cast(element)
                self.assertGreater(line.length(), 0)
                flag = line.isA().isDerivedFrom(Cv.CvDbHAlignmentLine.desc())
                self.assertTrue(flag)
            elif Cv.HAlignmentElementType.eSpiralCurveSpiral == element.type():
                spiral : Cv.CvDbHAlignmentSCS = Cv.CvDbHAlignmentSCS.cast(element)
                self.assertGreater(spiral.length(), 0)
                flag = spiral.isA().isDerivedFrom(Cv.CvDbHAlignmentSCS.desc())
                self.assertTrue(flag)
                
    def test_CvDbVAlignment_getPVIsArrays(self):
        objHnd = Db.Handle("AF")
        objId = self.BCADCIVIL1.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        valign = Cv.CvDbVAlignment(objId)
        for item in valign.getPVIsArrays():
            self.assertIsNotNone(item)
            
def pybcciviltest():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestBCadCivil)
        print("TestBricsCADCivil")
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        print(err)
