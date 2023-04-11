import os 
import unittest

import PyRxApp# = all the global methods like acutPrintf, 
import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 
print("testname = pydbobject")


class TestDbObject(unittest.TestCase):
        def test_property_ids(self):
                id = PyDb.HostApplicationServices().workingDatabase().blockTableId()
                bdo = PyDb.DbObject(id, PyDb.OpenMode.ForRead)
                self.assertEqual(bdo.className(),"AcDbObject") 
                self.assertEqual(bdo.isA().name(),"AcDbBlockTable") 
                self.assertEqual(bdo.isReadEnabled(), True) 
                self.assertEqual(bdo.isWriteEnabled(), False) 
                self.assertEqual(bdo.isAProxy(), False) 
                self.assertEqual(bdo.isNewObject(), False)
                #
                self.assertEqual(bdo.upgradeOpen(), PyDb.ErrorStatus.Ok)
                self.assertEqual(bdo.isWriteEnabled(), True) 
                #
                self.assertEqual(bdo.downgradeOpen(), PyDb.ErrorStatus.Ok)
                self.assertEqual(bdo.isWriteEnabled(), False)
                #
                self.assertEqual(bdo.database(), PyDb.DbHostApplicationServices().workingDatabase())  
                #
                self.assertEqual(bdo.close(), PyDb.ErrorStatus.Ok)  
                self.assertEqual(bdo.isReadEnabled(), False)

        def test_xdata(self):
                #regapp
                success = PyDb.RegApp("PYTHONTEST")
                self.assertEqual(success, 5100)

                #set
                id = PyDb.HostApplicationServices().workingDatabase().blockTableId()
                dbo = PyDb.DbObject(id, PyDb.OpenMode.kForWrite)
                self.assertEqual(dbo.isWriteEnabled(), True) 
                xd = [(PyDb.DxfCode.kDxfRegAppName, "PYTHONTEST"),(PyDb.DxfCode.kDxfXdXCoord, PyGe.Point3d(1,10,100))]
                dbo.setXData(xd)

                #get
                xdres = dbo.xData("PYTHONTEST")
                p = xdres[1][1]
                self.assertEqual(p.x, 1)
                self.assertEqual(p.y, 10)
                self.assertEqual(p.z, 100)
               


def PyRxCmd_pydbobject():
        try:
                print(".\nstart tests----------------------------------------------------------------------")
                suite = unittest.TestLoader().loadTestsFromTestCase(TestDbObject)
                unittest.TextTestRunner(verbosity=2).run(suite)
                print(".\nend tests  ----------------------------------------------------------------------")
        except Exception as err:
                PyRxApp.Printf(err)


    

