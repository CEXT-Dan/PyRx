from __future__ import annotations

import pickle
import unittest

from pyrx import Db, Ge


class PyData:
    sd1 = "check out the brain on brad, lets make this bigger than 127 bytes"
    sd2 = "check out the brain on brad, lets make this bigger than 127 bytes"
    fd1 = 3.14159265359
    id1 = 42

    def printData(self):
        print("\n{}\n{}\n{}\n{}".format(self.sd1, self.sd2, self.fd1, self.id1))


class TestDbObject:
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")
        self.assertEqual = self.assertions.assertEqual
        self.assertNotEqual = self.assertions.assertNotEqual
        self.assertGreater = self.assertions.assertGreater
        self.assertFalse = self.assertions.assertFalse
        self.assertTrue = self.assertions.assertTrue

    def test_property_ids(self):
        id = Db.HostApplicationServices().workingDatabase().blockTableId()
        bdo = Db.DbObject(id, Db.OpenMode.ForRead)
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
        self.assertEqual(bdo.database(), Db.HostApplicationServices().workingDatabase())
        #
        bdo.close()
        self.assertEqual(bdo.isReadEnabled(), False)

    def test_undo_recording(self):
        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        curstate = not model.isUndoRecordingDisabled()
        model.disableUndoRecording(True)
        self.assertEqual(model.isUndoRecordingDisabled(), True)
        model.disableUndoRecording(False)
        self.assertEqual(model.isUndoRecordingDisabled(), False)
        model.disableUndoRecording(curstate)

    def test_propertys(self):
        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForRead)
        oid = model.ownerId()
        dbo = Db.DbObject(oid, Db.OpenMode.ForRead)
        self.assertEqual(dbo.isA().name(), "AcDbBlockTable")
        self.assertEqual(dbo.database(), db)
        self.assertEqual(dbo.isAProxy(), False)
        self.assertEqual(dbo.isErased(), False)

    def test_xdata(self):
        # regapp
        success = Db.Core.regApp("PYTHONTEST")
        self.assertEqual(success, True)
        # set
        id = Db.HostApplicationServices().workingDatabase().textstyle()
        dbo = Db.DbObject(id, Db.OpenMode.kForWrite)
        self.assertEqual(dbo.isWriteEnabled(), True)
        xd = [
            (Db.DxfCode.kDxfRegAppName, "PYTHONTEST"),
            (Db.DxfCode.kDxfXdXCoord, Ge.Point3d(1, 10, 100)),
        ]
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
        id = Db.HostApplicationServices().workingDatabase().dimStyleTableId()
        dbo = Db.DbObject(id, Db.OpenMode.kForWrite)
        xrid: Db.ObjectId = dbo.setBinaryData("PYXR", dataBytes)
        bOut = dbo.getBinaryData("PYXR")
        self.assertEqual(bOut, dataBytes)
        self.assertTrue(xrid.isValid())
        self.assertTrue(xrid.isDerivedFrom(Db.Xrecord.desc()))

    def test_BinaryXdData(self):
        data = PyData()
        dataBytes = pickle.dumps(data)
        id = Db.HostApplicationServices().workingDatabase().dimStyleTableId()
        dbo = Db.DbObject(id, Db.OpenMode.kForWrite)
        dbo.setXDBinaryData("PYXD", dataBytes)
        bOut = dbo.getXDBinaryData("PYXD")
        self.assertEqual(bOut, dataBytes)

    def test_isdynamicblock(self, db_dynblock: Db.Database):
        objHnd = Db.Handle("36f")
        objId = db_dynblock.getObjectId(False, objHnd)
        self.assertTrue(Db.DynBlockTableRecord.getIsDynamicBlock(objId))
        btr = Db.BlockTableRecord(objId)
        self.assertTrue(btr.isDynamicBlock())

    def test_isDerivedFrom(self):
        line = Db.Line()
        self.assertFalse(line.isDerivedFrom(Db.Circle.desc()))
        self.assertTrue(line.isDerivedFrom(Db.Curve.desc()))

    def EntityHyperlinkPE(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c95f5")
        objId = db_06457.getObjectId(False, objHnd)
        obj = Db.DbObject(objId)
        pe = Db.EntityHyperlinkPE(obj.queryX(Db.EntityHyperlinkPE.desc()))
        hpc = pe.getHyperlinkCollection(obj)
        self.assertEqual(hpc.count(), 1)
        for idx in range(hpc.count()):
            lnk = hpc.item(idx)
            self.assertEqual(lnk.name(), "http://www.theswamp.org/")
            self.assertEqual(lnk.description(), "theSwamp")
