import os
import unittest
import testcfg

import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor

host = PyAp.Application.hostAPI()

class TestDbObject(unittest.TestCase):
    def test_property_ids(self):
        id = PyDb.HostApplicationServices().workingDatabase().blockTableId()
        bdo = PyDb.DbObject(id, PyDb.OpenMode.ForRead)
        self.assertEqual(bdo.className(), "AcDbObject")
        self.assertEqual(bdo.isA().name(), "AcDbBlockTable")
        self.assertEqual(bdo.isReadEnabled(), True)
        self.assertEqual(bdo.isWriteEnabled(), False)
        self.assertEqual(bdo.isAProxy(), False)
        self.assertEqual(bdo.isNewObject(), False)
        #
        bdo.upgradeOpen()
        self.assertEqual(bdo.isWriteEnabled(), True)
        #
        bdo.downgradeOpen()
        self.assertEqual(bdo.isWriteEnabled(), False)
        #
        self.assertEqual(
            bdo.database(), PyDb.HostApplicationServices().workingDatabase())
        #
        bdo.close()
        self.assertEqual(bdo.isReadEnabled(), False)
        
    def test_undo_recording(self):
        db = PyDb.HostApplicationServices().workingDatabase()
        flag = db.isUndoRecordingDisabled()
        db.disableUndoRecording(True)
        self.assertEqual(db.isUndoRecordingDisabled(), True)
        db.disableUndoRecording(False)
        self.assertEqual(db.isUndoRecordingDisabled(), False)
        db.disableUndoRecording(flag)
        self.assertEqual(db.isUndoRecordingDisabled(), flag)

    def test_propertys(self):
        db = PyDb.HostApplicationServices().workingDatabase()
        model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.ForRead)
        oid = model.ownerId()
        dbo = PyDb.DbObject(oid, PyDb.OpenMode.ForRead)
        self.assertEqual(dbo.isA().name(), "AcDbBlockTable")
        self.assertEqual(dbo.database(), db)
        self.assertEqual(dbo.isAProxy(), False)
        self.assertEqual(dbo.isErased(), False)

    def test_xdata(self):
        # regapp
        success = PyDb.Core.regApp("PYTHONTEST")
        self.assertEqual(success, True)
        # set
        id = PyDb.HostApplicationServices().workingDatabase().blockTableId()
        dbo = PyDb.DbObject(id, PyDb.OpenMode.kForWrite)
        self.assertEqual(dbo.isWriteEnabled(), True)
        xd = [(PyDb.DxfCode.kDxfRegAppName, "PYTHONTEST"),
              (PyDb.DxfCode.kDxfXdXCoord, PyGe.Point3d(1, 10, 100))]
        dbo.setXData(xd)

        # get
        xdres = dbo.xData("PYTHONTEST")
        p = xdres[1][1]
        self.assertEqual(p.x, 1)
        self.assertEqual(p.y, 10)
        self.assertEqual(p.z, 100)


def pydbobject():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestDbObject)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestDbObject"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print('TestDbObject')
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print.Printf(err)
