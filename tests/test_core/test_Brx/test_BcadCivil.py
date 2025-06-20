from __future__ import annotations

import unittest

import pytest

from pyrx import Cv, Db


@pytest.mark.known_failure_ARX
@pytest.mark.known_failure_GRX
@pytest.mark.known_failure_ZRX
class TestBCadCivil:
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")
        self.assertEqual = self.assertions.assertEqual
        self.assertNotEqual = self.assertions.assertNotEqual
        self.assertGreater = self.assertions.assertGreater
        self.assertFalse = self.assertions.assertFalse
        self.assertTrue = self.assertions.assertTrue
        self.assertIsNotNone = self.assertions.assertIsNotNone

    def test_stylemanager_getManagerId(self, db_brcivil: Db.Database):
        db = db_brcivil
        #
        manid = Cv.CvDbSurfaceElevationLabelStyleManager.getManagerId(db)
        self.assertEqual(manid.isValid(), True)
        self.assertTrue(manid.isDerivedFrom(Cv.CvDbSurfaceElevationLabelStyleManager.desc()))
        man = Cv.CvDbSurfaceElevationLabelStyleManager(manid)
        self.assertEqual(man.managerId(), "BrxCvDbSurfaceElevationLabelStyleManager")
        #
        manid = Cv.CvDbSurfaceSlopeLabelStyleManager.getManagerId(db)
        self.assertEqual(manid.isValid(), True)
        self.assertTrue(manid.isDerivedFrom(Cv.CvDbSurfaceSlopeLabelStyleManager.desc()))
        man = Cv.CvDbSurfaceSlopeLabelStyleManager(manid)
        self.assertEqual(man.managerId(), "BrxCvDbSurfaceSlopeLabelStyleManager")
        #
        manid = Cv.CvDbSurfaceContourLabelStyleManager.getManagerId(db)
        self.assertEqual(manid.isValid(), True)
        self.assertTrue(manid.isDerivedFrom(Cv.CvDbSurfaceContourLabelStyleManager.desc()))
        man = Cv.CvDbSurfaceContourLabelStyleManager(manid)
        self.assertEqual(man.managerId(), "BrxCvDbSurfaceContourLabelStyleManager")
        #
        manid = Cv.CvDbPointLabelStyleManager.getManagerId(db)
        self.assertEqual(manid.isValid(), True)
        self.assertTrue(manid.isDerivedFrom(Cv.CvDbPointLabelStyleManager.desc()))
        man = Cv.CvDbPointLabelStyleManager(manid)
        self.assertEqual(man.managerId(), "BrxCvDbPointLabelStyleManager")
        #
        manid = Cv.CvDbCurveLabelStyleManager.getManagerId(db)
        self.assertEqual(manid.isValid(), True)
        self.assertTrue(manid.isDerivedFrom(Cv.CvDbCurveLabelStyleManager.desc()))
        man = Cv.CvDbCurveLabelStyleManager(manid)
        self.assertEqual(man.managerId(), "BrxCvDbCurveLabelStyleManager")
        #
        manid = Cv.CvDbLineLabelStyleManager.getManagerId(db)
        self.assertEqual(manid.isValid(), True)
        self.assertTrue(manid.isDerivedFrom(Cv.CvDbLineLabelStyleManager.desc()))
        man = Cv.CvDbLineLabelStyleManager(manid)
        self.assertEqual(man.managerId(), "BrxCvDbLineLabelStyleManager")
        #
        manid = Cv.CvDbSymbolStyleManager.getManagerId(db)
        self.assertEqual(manid.isValid(), True)
        self.assertTrue(manid.isDerivedFrom(Cv.CvDbSymbolStyleManager.desc()))
        man = Cv.CvDbSymbolStyleManager(manid)
        self.assertEqual(man.managerId(), "BrxCvDbSymbolStyleManager")

    def test_BsysCvDbAlignment_dxfName(self, db_brcivil: Db.Database):
        objHnd = Db.Handle("AE")
        objId = db_brcivil.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        dbo = Db.Entity(objId)
        self.assertEqual(dbo.isA().dxfName(), "BsysCvDbAlignment")

    def test_BsysCvDbAlignment_obj(self, db_brcivil: Db.Database):
        objHnd = Db.Handle("AE")
        objId = db_brcivil.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        hAlignment = Cv.CvDbHAlignment(objId)
        self.assertFalse(hAlignment.isNullObj())
        self.assertEqual(hAlignment.elementCount(), 3)

    def test_BsysCvDbAlignment_cast(self, db_brcivil: Db.Database):
        objHnd = Db.Handle("AE")
        objId = db_brcivil.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        hAlignment = Cv.CvDbHAlignment(objId)

        for id in hAlignment.getUnorderedElementIds():
            element: Cv.CvDbHAlignmentElement = hAlignment.elementAtId(id)
            self.assertFalse(element.isNullObj())
            if Cv.HAlignmentElementType.eLine == element.type():
                line: Cv.CvDbHAlignmentLine = Cv.CvDbHAlignmentLine.cast(element)
                self.assertGreater(line.length(), 0)
                flag = line.isA().isDerivedFrom(Cv.CvDbHAlignmentLine.desc())
                self.assertTrue(flag)
            elif Cv.HAlignmentElementType.eSpiralCurveSpiral == element.type():
                spiral: Cv.CvDbHAlignmentSCS = Cv.CvDbHAlignmentSCS.cast(element)
                self.assertGreater(spiral.length(), 0)
                flag = spiral.isA().isDerivedFrom(Cv.CvDbHAlignmentSCS.desc())
                self.assertTrue(flag)

    def test_CvDbVAlignment_getPVIsArrays(self, db_brcivil: Db.Database):
        objHnd = Db.Handle("AF")
        objId = db_brcivil.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        valign = Cv.CvDbVAlignment(objId)
        for item in valign.getPVIsArrays():
            self.assertIsNotNone(item)

    def test_BsysCvDbHAlignment_iter(self, db_brcivil: Db.Database):
        objHnd = Db.Handle("AE")
        objId = db_brcivil.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        hAlignment = Cv.CvDbHAlignment(objId)

        ids = []
        elementId = hAlignment.firstElementId()
        while elementId != 0:
            element = hAlignment.elementAtId(elementId)
            if elementId != 0:
                ids.append(elementId)
            elementId = element.nextId()
        self.assertEqual(len(ids), 3)
