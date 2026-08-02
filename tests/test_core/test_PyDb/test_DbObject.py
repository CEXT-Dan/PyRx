from __future__ import annotations

import pickle

import pytest

from pyrx import Db, Ge


class PyData:
    sd1 = "check out the brain on brad, lets make this bigger than 127 bytes"
    sd2 = "check out the brain on brad, lets make this bigger than 127 bytes"
    fd1 = 3.14159265359
    id1 = 42

    def printData(self):
        print("\n{}\n{}\n{}\n{}".format(self.sd1, self.sd2, self.fd1, self.id1))


class TestDbObject:

    def test_property_ids(self):
        id = Db.HostApplicationServices().workingDatabase().blockTableId()
        bdo = Db.DbObject(id, Db.OpenMode.ForRead)
        assert bdo.className() == "AcDbObject"
        assert bdo.isA().name() == "AcDbBlockTable"
        assert bdo.isReadEnabled()
        assert not bdo.isWriteEnabled()
        assert not bdo.isAProxy()
        assert not bdo.isNewObject()
        #
        bdo.upgradeOpen()
        assert bdo.isWriteEnabled()
        #
        bdo.downgradeOpen()
        assert not bdo.isWriteEnabled()
        #
        assert bdo.database() == Db.workingDb()

    @pytest.mark.known_failure_IRX
    def test_property_ids2(self):
        id = Db.HostApplicationServices().workingDatabase().blockTableId()
        bdo = Db.DbObject(id, Db.OpenMode.ForRead)
        
        #iacad is deleted
        bdo.close()
        assert not bdo.isReadEnabled()

    @pytest.mark.known_failure_IRX
    def test_undo_recording(self):
        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        curstate = not model.isUndoRecordingDisabled()
        model.disableUndoRecording(True)
        assert model.isUndoRecordingDisabled()
        model.disableUndoRecording(False)
        assert not model.isUndoRecordingDisabled()
        model.disableUndoRecording(curstate)

    def test_propertys(self):
        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForRead)
        oid = model.ownerId()
        dbo = Db.DbObject(oid, Db.OpenMode.ForRead)
        assert dbo.isA().name() == "AcDbBlockTable"
        assert dbo.database() == db
        assert not dbo.isAProxy()
        assert not dbo.isErased()

    def test_xdata(self):
        # regapp
        success = Db.Core.regApp("PYTHONTEST")
        assert success
        # set
        id = Db.HostApplicationServices().workingDatabase().textstyle()
        dbo = Db.DbObject(id, Db.OpenMode.kForWrite)
        assert dbo.isWriteEnabled()
        xd = [
            (Db.DxfCode.kDxfRegAppName, "PYTHONTEST"),
            (Db.DxfCode.kDxfXdXCoord, Ge.Point3d(1, 10, 100)),
        ]
        dbo.setXData(xd)

        # get
        xdres = dbo.xData("PYTHONTEST")
        p = xdres[1][1]
        assert p.x == 1
        assert p.y == 10
        assert p.z == 100

    @pytest.mark.known_failure_IRX
    def test_BinaryData(self):
        data = PyData()
        dataBytes = pickle.dumps(data)
        id = Db.HostApplicationServices().workingDatabase().dimStyleTableId()
        dbo = Db.DbObject(id, Db.OpenMode.kForWrite)
        xrid: Db.ObjectId = dbo.setBinaryData("PYXR", dataBytes)
        bOut = dbo.getBinaryData("PYXR")
        assert bOut == dataBytes
        assert not xrid.isNull()
        assert xrid.isDerivedFrom(Db.Xrecord.desc())

    @pytest.mark.known_failure_IRX
    def test_BinaryXdData(self):
        data = PyData()
        dataBytes = pickle.dumps(data)
        id = Db.HostApplicationServices().workingDatabase().dimStyleTableId()
        dbo = Db.DbObject(id, Db.OpenMode.kForWrite)
        dbo.setXDBinaryData("PYXD", dataBytes)
        bOut = dbo.getXDBinaryData("PYXD")
        assert bOut == dataBytes

    def test_isdynamicblock(self, db_dynblock: Db.Database):
        objHnd = Db.Handle("36f")
        objId = db_dynblock.getObjectId(False, objHnd)
        assert Db.DynBlockTableRecord.getIsDynamicBlock(objId)
        btr = Db.BlockTableRecord(objId)
        assert btr.isDynamicBlock()

    def test_isDerivedFrom(self):
        line = Db.Line()
        assert not line.isDerivedFrom(Db.Circle.desc())
        assert line.isDerivedFrom(Db.Curve.desc())

    def EntityHyperlinkPE(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c95f5")
        objId = db_06457.getObjectId(False, objHnd)
        obj = Db.DbObject(objId)
        pe = Db.EntityHyperlinkPE(obj.queryX(Db.EntityHyperlinkPE.desc()))
        hpc = pe.getHyperlinkCollection(obj)
        assert hpc.count() == 1
        for idx in range(hpc.count()):
            lnk = hpc.item(idx)
            assert lnk.name() == "http://www.theswamp.org/"
            assert lnk.description() == "theSwamp"
