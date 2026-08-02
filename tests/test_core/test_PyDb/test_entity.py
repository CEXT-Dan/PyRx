from __future__ import annotations

import pytest

from pyrx import Ap, Db, Ge


def create_dbPoint():
    db = Db.curDb()
    dbp = Db.Point()
    dbp.setDatabaseDefaults(db)
    model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
    id = model.appendAcDbEntity(dbp)
    return id


class TestDbEntity:
    def test_dbpoint_open_ctor1(self):
        id = create_dbPoint()
        dbp = Db.Point(id)
        assert dbp.isReadEnabled() == True
        dbp.upgradeOpen()
        dbp.erase()

    def test_dbpoint_open_ctor2(self):
        id = create_dbPoint()
        dbp = Db.Point(id, Db.OpenMode.kForRead)
        assert dbp.isReadEnabled() == True
        dbp.upgradeOpen()
        dbp.erase()

    def test_dbpoint_open_ctor3(self):
        id = create_dbPoint()
        dbp = Db.Point(id, Db.OpenMode.kForWrite)
        assert dbp.isWriteEnabled() == True
        dbp.erase()

    def test_dbpoint_properties_ids(self):
        point = Db.Point(Ge.Point3d(1, 2, 3))
        db = Ap.Application().docManager().curDocument().database()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(point)
        assert point.position() == Ge.Point3d(1, 2, 3)
        assert point.objectId() == Db.ObjectId()
        assert Db.Point.className() == "AcDbPoint"
        point.downgradeOpen()
        assert not point.isWriteEnabled()
        point.upgradeOpen()
        assert point.isWriteEnabled()
        point.setNormal(Ge.Vector3d.kYAxis)
        assert point.normal() == Ge.Vector3d.kYAxis
        point.setNormal(Ge.Vector3d.kZAxis)
        point.setPosition(Ge.Point3d.kOrigin)
        assert point.position() == Ge.Point3d.kOrigin
        point.setThickness(1.2)
        assert point.thickness() == 1.2

    def test_dbpoint(self):
        db = Db.curDb()
        pos = Ge.Point3d(100, 100, 0)
        dbp = Db.Point(pos)
        dbp.setDatabaseDefaults(db)
        assert dbp.position() == pos

    def test_getGripPointsGripData(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c91ef")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        mt = Db.MText(objId)
        grpdata = mt.getGripPoints(1.0, 1, Ge.Vector3d.kZAxis, 0)
        assert len(grpdata) > 0

    def test_dbline(self):
        """also tests tome entity items, so leave here"""
        db = Db.curDb()
        line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        assert line.objectId().isNull() == True
        line.setDatabaseDefaults()
        line.setColorIndex(7)
        line2 = Db.Line()
        line2.setPropertiesFrom(line)
        assert line2.colorIndex() == 7
        assert line.startPoint() == Ge.Point3d(0, 0, 0)
        assert line.endPoint() == Ge.Point3d(100, 100, 0)
        line.extend(False, Ge.Point3d(200, 200, 0))
        assert line.endPoint() == Ge.Point3d(200, 200, 0)
        line.setEndPoint(Ge.Point3d(100, 100, 0))
        assert line.endPoint() == Ge.Point3d(100, 100, 0)
        line.setStartPoint(Ge.Point3d(1, 11, 0))
        assert line.startPoint() == Ge.Point3d(1, 11, 0)
        lid = db.addToModelspace(line)
        line.close()
        line2 = Db.Line(lid)
        assert line2.startPoint() == Ge.Point3d(1, 11, 0)
        line2.close()
        line3 = Db.Line(lid, Db.OpenMode.ForRead)
        assert line3.startPoint() == Ge.Point3d(1, 11, 0)
        line3.close()
        line4 = Db.Line(lid, Db.OpenMode.ForWrite)
        assert line4.startPoint() == Ge.Point3d(1, 11, 0)

    def test_dbcircle(self):
        circle = Db.Circle()
        circle.setCenter(Ge.Point3d(1, 2, 3))
        assert circle.center() == Ge.Point3d(1, 2, 3)
        circle.setRadius(20)
        assert circle.radius() == 20

    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_IRX
    def test_dbtext(self):
        db = Db.curDb()
        text = Db.Text()
        text.setDatabaseDefaults()
        text.setPosition(Ge.Point3d(100, 100, 0))
        assert text.position() == Ge.Point3d(100, 100, 0)
        text.setTextString("Hello World")
        assert text.textString() == "Hello World"
        text.setTextStyle(db.textstyle())
        text.setJustification(Db.TextAlignment.kTextAlignmentMiddleCenter)
        assert text.justification() == Db.TextAlignment.kTextAlignmentMiddleCenter
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(text)

    def test_dbmtext(self):
        db = Db.curDb()
        mt = Db.MText()
        mt.setDatabaseDefaults(db)
        mt.setTextStyle(db.textstyle())
        assert mt.textStyle() == db.textstyle()
        mt.setLocation(Ge.Point3d(1, 20, 3))
        assert mt.location() == Ge.Point3d(1, 20, 3)
        mt.setContents("THIS IS IT!")
        assert mt.contents() == "THIS IS IT!"
        mt.setAttachment(Db.MTextAttachmentPoint.kBottomCenter)
        assert mt.attachment() == Db.MTextAttachmentPoint.kBottomCenter
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(mt)
        for frag in mt.getFragments():
            assert len(frag) == Db.MTextFragmentType.kEndFragmentTypes

    @pytest.mark.known_failure_ZRX
    def test_dbmtext_fragtextvalue(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c91ef")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        mt = Db.MText(objId)
        for i, frag in enumerate(mt.getFragments()):
            if i == 0:
                assert frag[Db.MTextFragmentType.kTextValue] == "Test1"
            elif i == 1:
                assert frag[Db.MTextFragmentType.kTextValue] == "Test2"
            elif i == 2:
                assert frag[Db.MTextFragmentType.kTextValue] == "Test3"
            else:
                pass

    @pytest.mark.known_failure_IRX
    def test_dbleader(self):
        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)

        # create anno
        mtext = Db.MText()
        mtext.setDatabaseDefaults()
        mtext.setLocation(Ge.Point3d(105, 100, 0))
        mtext.setContents("what we have, is failure to communicate")

        # add anno to db and close!
        mtid = model.appendAcDbEntity(mtext)
        mtext.close()
        #del mtext icad

        # create leader
        leader = Db.Leader()
        leader.setDatabaseDefaults()
        leader.appendVertex(Ge.Point3d(0, 0, 0))
        leader.appendVertex(Ge.Point3d(100, 100, 0))

        assert leader.vertexAt(0) == Ge.Point3d(0, 0, 0)
        assert leader.vertexAt(1) == Ge.Point3d(100, 100, 0)

        # set leader to red
        c = Db.Color()
        c.setRGB(255, 0, 0)
        leader.setColor(c)

        # add leader to db
        model.appendAcDbEntity(leader)

        # attach
        leader.attachAnnotation(mtid)
        assert leader.annotationObjId() == mtid

    @pytest.mark.known_failure_IRX
    def test_table_cells1(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        table = Db.Table(objId)
        iter = table.cells()
        assert len(iter) == 1044

    @pytest.mark.known_failure_IRX
    def test_table_cells2(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        table = Db.Table(objId)
        cr = Db.CellRange(1, 1, 3, 3)
        iter = table.cells(cr)
        assert len(iter) == 9

    @pytest.mark.known_failure_IRX
    @pytest.mark.known_failure_GRX
    def test_table_cells3(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        table = Db.Table(objId)
        opt = Db.TableIteratorOption.kTableIteratorSkipMerged
        iter = table.cells(Db.CellRange(1, 1, 3, 3), opt)
        assert len(iter) == 9

    @pytest.mark.known_failure_IRX
    @pytest.mark.known_failure_GRX
    def test_table_cells4(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        table = Db.Table(objId)
        opt = Db.TableIteratorOption.kTableIteratorSkipMerged
        iter = table.cells(opt)
        assert len(iter) == 1036

    @pytest.mark.known_failure_IRX
    def test_table_cellValues1(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        table = Db.Table(objId)
        iter = table.cellValues()
        assert len(iter) == 1044

    @pytest.mark.known_failure_IRX
    def test_table_cellValues2(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        table = Db.Table(objId)
        cr = Db.CellRange(1, 1, 3, 3)
        iter = table.cellValues(cr)
        assert len(iter) == 9

    @pytest.mark.known_failure_IRX
    @pytest.mark.known_failure_GRX
    def test_table_cellValues3(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        table = Db.Table(objId)
        opt = Db.TableIteratorOption.kTableIteratorSkipMerged
        iter = table.cellValues(opt)
        assert len(iter) == 1036

    @pytest.mark.known_failure_IRX
    def test_table_cellValues4(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        table = Db.Table(objId)
        opt = Db.TableIteratorOption.kTableIteratorSkipMerged
        iter = table.cellValues(Db.CellRange(1, 1, 3, 3), opt)
        assert len(iter) == 9

    def test_table_getstring(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() == False
        table = Db.Table(objId)
        assert table.textString(4, 0) == "{\\fMS Sans Serif|b0|i0|c0;R380"
        assert table.textString(4, 0, 0) == "{\\fMS Sans Serif|b0|i0|c0;R380"
        opt = Db.ValueFormatOption.kIgnoreMtextFormat
        assert table.textStringFmt(4, 0, opt) == "R380"
        assert table.textStringFmt(4, 0, 0, opt) == "R380"

    def test_table_AcCell(self):
        cell1 = Db.Cell()
        assert cell1.row == -1
        assert cell1.column == -1
        cell2 = Db.Cell(1, 1)
        assert cell2.row == 1
        assert cell2.column == 1

    def test_table_AcCellRange(self):
        cr = Db.CellRange()
        assert cr.topRow == -1
        assert cr.leftColumn == -1
        assert cr.bottomRow == -1
        assert cr.rightColumn == -1
        cr2 = Db.CellRange(1, 2, 3, 4)
        assert cr2.topRow == 1
        assert cr2.leftColumn == 2
        assert cr2.bottomRow == 3
        assert cr2.rightColumn == 4

    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_IRX
    def test_table_calcTextExtents(self):
        db = Db.curDb()
        rec = Db.TableStyle(db.tablestyle())
        ts = rec.textStyle(Db.RowType.kDataRow)
        w, h = Db.Table.calcTextExtents("This is", ts)
        assert w == 0, 2
        assert h == 0, 2
        w, h = Db.Table.calcTextExtents("This is a test", ts)
        assert w == 0, 2
        assert h == 0, 2

    @pytest.mark.known_failure_IRX
    def test_create_wipout(self):
        db = Db.curDb()
        pts = [
            Ge.Point2d(0, 0),
            Ge.Point2d(100, 0),
            Ge.Point2d(100, 100),
            Ge.Point2d(0, 100),
            Ge.Point2d(0, 0),
        ]
        wipout = Db.Wipeout(pts, Ge.Vector3d.kZAxis)
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        id = model.appendAcDbEntity(wipout)
        assert not id.isNull()

    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_IRX
    def test_create_extruded_surface(self):
        db = Db.curDb()
        opts = Db.SweepOptions()
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        dir = Ge.Point3d(0, 0, 100) - Ge.Point3d(0, 0, 0)
        profile = Db.Profile3d(circle)
        surf = Db.Surface.createExtrudedSurface(profile, dir, opts)
        id = db.addToModelspace(surf)
        assert not id.isNull()

    def test_create_region(self):
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        regions = Db.Region.createFromCurves([circle])
        assert int(regions[0].getArea()) == 314
