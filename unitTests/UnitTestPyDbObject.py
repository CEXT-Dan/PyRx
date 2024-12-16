import os
import unittest
import testcfg
import pickle

import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor
import dbc

class PyData:
    sd1 = "check out the brain on brad, lets make this bigger than 127 bytes"
    sd2 = "check out the brain on brad, lets make this bigger than 127 bytes"
    fd1 = 3.14159265359
    id1 = 42
    
    def printData(self):
        print("\n{}\n{}\n{}\n{}".format(self.sd1,self.sd2,self.fd1,self.id1))

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
        model = PyDb.BlockTableRecord(db.modelSpaceId(), PyDb.OpenMode.kForWrite)
        curstate = not model.isUndoRecordingDisabled()
        model.disableUndoRecording(True)
        self.assertEqual(model.isUndoRecordingDisabled(), True )
        model.disableUndoRecording(False)
        self.assertEqual(model.isUndoRecordingDisabled(), False)
        model.disableUndoRecording(curstate)
        
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
        id = PyDb.HostApplicationServices().workingDatabase().textstyle()
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
        
    def test_BinaryData(self):
        data = PyData()
        dataBytes = pickle.dumps(data)
        id = PyDb.HostApplicationServices().workingDatabase().dimStyleTableId()
        dbo = PyDb.DbObject(id, PyDb.OpenMode.kForWrite)
        xrid :PyDb.ObjectId = dbo.setBinaryData("PYXR", dataBytes)
        bOut = dbo.getBinaryData("PYXR")
        self.assertEqual(bOut, dataBytes)
        self.assertTrue(xrid.isValid())
        self.assertTrue(xrid.isDerivedFrom(PyDb.Xrecord.desc()))
    
    def test_BinaryXdData(self):
        data = PyData()
        dataBytes = pickle.dumps(data)
        id = PyDb.HostApplicationServices().workingDatabase().dimStyleTableId()
        dbo = PyDb.DbObject(id, PyDb.OpenMode.kForWrite)
        dbo.setXDBinaryData("PYXD", dataBytes)
        bOut = dbo.getXDBinaryData("PYXD")
        self.assertEqual(bOut, dataBytes)
        
    def test_isdynamicblock(self):
        objHnd = PyDb.Handle("36f")
        objId = dbc.dbs["dynblock"].getObjectId(False, objHnd)
        self.assertTrue(PyDb.DynBlockTableRecord.getIsDynamicBlock(objId))
        btr = PyDb.BlockTableRecord(objId)
        self.assertTrue(btr.isDynamicBlock())
        
    def test_isDerivedFrom(self):
        line = PyDb.Line()
        self.assertFalse(line.isDerivedFrom(PyDb.Circle.desc()))
        self.assertTrue(line.isDerivedFrom(PyDb.Curve.desc()))
        
    @unittest.skipIf(*testcfg.makeSkip(testcfg.ETFlags.eBRX))
    def EntityHyperlinkPE(self):
        objHnd = PyDb.Handle("2c95f5")
        objId = dbc.dbs["06457"].getObjectId(False, objHnd)
        obj = PyDb.DbObject(objId)
        pe = PyDb.EntityHyperlinkPE(obj.queryX(PyDb.EntityHyperlinkPE.desc()))
        self.assertTrue(pe.hasHyperlink(obj))
        if not pe.hasHyperlink(obj):
            return
        hpc = pe.getHyperlinkCollection(obj)
        self.assertEqual(hpc.count(),1)
        for idx in range(hpc.count()):
            lnk = hpc.item(idx)
            self.assertEqual(lnk.name(),"http://www.theswamp.org/")
            self.assertEqual(lnk.description(),"theSwamp")

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
        print(err)
