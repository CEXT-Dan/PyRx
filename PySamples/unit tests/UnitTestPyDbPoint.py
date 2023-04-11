import os 
import unittest

import PyRxApp# = all the global methods like acutPrintf, 
import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 
print("testname = pydbpoint")


class TestDbPoint(unittest.TestCase):
        def test_property_ids(self):
                point = PyDb.Point(PyGe.Point3d(1,2,3))
				
                db = PyAp.Application().docManager().curDocument().database()
                model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
                model.appendAcDbEntity(point)
                self.assertEqual(point.position(),PyGe.Point3d(1,2,3))
                self.assertNotEqual(point.objectId(), PyDb.DbObjectId())
                self.assertEqual(PyDb.Point.className(),"AcDbPoint")
                point.downgradeOpen()
                self.assertFalse(point.isWriteEnabled())
                point.upgradeOpen()
                self.assertTrue(point.isWriteEnabled())
                point.setNormal(PyGe.Vector3d.kYAxis)
                self.assertEqual(point.normal(),PyGe.Vector3d.kYAxis)
                point.setNormal(PyGe.Vector3d.kZAxis)
                point.setPosition(PyGe.Point3d.kOrigin)
                self.assertEqual(point.position(),PyGe.Point3d.kOrigin)
                point.setThickness(1.2)
                self.assertEqual(point.thickness(),1.2)


def PyRxCmd_pydbpoint():
        try:
                print(".\nstart tests----------------------------------------------------------------------")
                suite = unittest.TestLoader().loadTestsFromTestCase(TestDbPoint)
                unittest.TextTestRunner(verbosity=2).run(suite)
                print(".\nend tests  ----------------------------------------------------------------------")
        except Exception as err:
                PyRxApp.Printf(err)


    

