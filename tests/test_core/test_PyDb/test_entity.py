from __future__ import annotations

import math
import unittest

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
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")
        self.assertEqual = self.assertions.assertEqual
        self.assertNotEqual = self.assertions.assertNotEqual
        self.assertGreater = self.assertions.assertGreater
        self.assertFalse = self.assertions.assertFalse
        self.assertTrue = self.assertions.assertTrue

    def test_dbpoint_open_ctor1(self):
        id = create_dbPoint()
        dbp = Db.Point(id)
        self.assertEqual(dbp.isReadEnabled(), True)
        dbp.upgradeOpen()
        dbp.erase()

    def test_dbpoint_open_ctor2(self):
        id = create_dbPoint()
        dbp = Db.Point(id, Db.OpenMode.kForRead)
        self.assertEqual(dbp.isReadEnabled(), True)
        dbp.upgradeOpen()
        dbp.erase()

    def test_dbpoint_open_ctor3(self):
        id = create_dbPoint()
        dbp = Db.Point(id, Db.OpenMode.kForWrite)
        self.assertEqual(dbp.isWriteEnabled(), True)
        dbp.erase()

    def test_dbpoint_properties_ids(self):
        point = Db.Point(Ge.Point3d(1, 2, 3))
        db = Ap.Application().docManager().curDocument().database()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(point)
        self.assertEqual(point.position(), Ge.Point3d(1, 2, 3))
        self.assertNotEqual(point.objectId(), Db.ObjectId())
        self.assertEqual(Db.Point.className(), "AcDbPoint")
        point.downgradeOpen()
        self.assertFalse(point.isWriteEnabled())
        point.upgradeOpen()
        self.assertTrue(point.isWriteEnabled())
        point.setNormal(Ge.Vector3d.kYAxis)
        self.assertEqual(point.normal(), Ge.Vector3d.kYAxis)
        point.setNormal(Ge.Vector3d.kZAxis)
        point.setPosition(Ge.Point3d.kOrigin)
        self.assertEqual(point.position(), Ge.Point3d.kOrigin)
        point.setThickness(1.2)
        self.assertEqual(point.thickness(), 1.2)

    def test_dbpoint(self):
        db = Db.curDb()
        pos = Ge.Point3d(100, 100, 0)
        dbp = Db.Point(pos)
        dbp.setDatabaseDefaults(db)
        self.assertEqual(dbp.position(), pos)

    def test_getGripPointsGripData(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c91ef")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        mt = Db.MText(objId)
        grpdata = mt.getGripPoints(1.0, 1, Ge.Vector3d.kZAxis, 0)
        self.assertGreater(len(grpdata), 0)

    def test_dbline(self):
        db = Db.curDb()
        line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        self.assertEqual(line.objectId().isNull(), True)
        line.setDatabaseDefaults()
        line.setColorIndex(7)
        line2 = Db.Line()
        line2.setPropertiesFrom(line)
        self.assertEqual(line2.colorIndex(), 7)
        self.assertEqual(line.startPoint(), Ge.Point3d(0, 0, 0))
        self.assertEqual(line.endPoint(), Ge.Point3d(100, 100, 0))
        line.extend(False, Ge.Point3d(200, 200, 0))
        self.assertEqual(line.endPoint(), Ge.Point3d(200, 200, 0))
        line.setEndPoint(Ge.Point3d(100, 100, 0))
        self.assertEqual(line.endPoint(), Ge.Point3d(100, 100, 0))
        line.setStartPoint(Ge.Point3d(1, 11, 0))
        self.assertEqual(line.startPoint(), Ge.Point3d(1, 11, 0))
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        lid = model.appendAcDbEntity(line)
        line.close()
        line2 = Db.Line(lid)
        self.assertEqual(line2.startPoint(), Ge.Point3d(1, 11, 0))
        line2.close()
        line3 = Db.Line(lid, Db.OpenMode.ForRead)
        self.assertEqual(line3.startPoint(), Ge.Point3d(1, 11, 0))

    def test_dbarc(self):
        db = Db.curDb()
        arc = Db.Arc(Ge.Point3d(0, 0, 0), 20, 0, math.pi)
        self.assertEqual(arc.startAngle(), 0)
        self.assertEqual(arc.endAngle(), math.pi)
        self.assertEqual(arc.totalAngle(), math.pi)
        # curve
        self.assertEqual(arc.getStartPoint(), Ge.Point3d(20, 0, 0))
        self.assertEqual(arc.getEndPoint(), Ge.Point3d(-20, 0, 0))
        # add
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        eid = model.appendAcDbEntity(arc)
        arc.close()
        # ctor
        arc2 = Db.Arc(eid)
        self.assertEqual(arc2.endAngle(), math.pi)
        arc2.close(), Db.ErrorStatus.eOk
        # ctor
        arc3 = Db.Arc(eid, Db.OpenMode.kForRead)
        self.assertEqual(arc3.endAngle(), math.pi)
        arc3.close()

    def test_dbcircle(self):
        circle = Db.Circle()
        circle.setCenter(Ge.Point3d(1, 2, 3))
        self.assertEqual(circle.center(), Ge.Point3d(1, 2, 3))
        circle.setRadius(20)
        self.assertEqual(circle.radius(), 20)

    @pytest.mark.known_failure_ZRX
    def test_dbtext(self):
        db = Db.curDb()
        text = Db.Text()
        text.setDatabaseDefaults()
        text.setPosition(Ge.Point3d(100, 100, 0))
        self.assertEqual(text.position(), Ge.Point3d(100, 100, 0))
        text.setTextString("Hello World")
        self.assertEqual(text.textString(), "Hello World")
        text.setTextStyle(db.textstyle())
        text.setJustification(Db.TextAlignment.kTextAlignmentMiddleCenter)
        self.assertEqual(text.justification(), Db.TextAlignment.kTextAlignmentMiddleCenter)
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(text)

    def test_dbmtext(self):
        db = Db.curDb()
        mt = Db.MText()
        mt.setDatabaseDefaults(db)
        mt.setTextStyle(db.textstyle())
        self.assertEqual(mt.textStyle(), db.textstyle())
        mt.setLocation(Ge.Point3d(1, 20, 3))
        self.assertEqual(mt.location(), Ge.Point3d(1, 20, 3))
        mt.setContents("THIS IS IT!")
        self.assertEqual(mt.contents(), "THIS IS IT!")
        mt.setAttachment(Db.MTextAttachmentPoint.kBottomCenter)
        self.assertEqual(mt.attachment(), Db.MTextAttachmentPoint.kBottomCenter)
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(mt)
        for frag in mt.getFragments():
            self.assertEqual(len(frag), Db.MTextFragmentType.kEndFragmentTypes)

    @pytest.mark.known_failure_ZRX
    def test_dbmtext_fragtextvalue(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c91ef")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        mt = Db.MText(objId)
        for i, frag in enumerate(mt.getFragments()):
            if i == 0:
                self.assertEqual(frag[Db.MTextFragmentType.kTextValue], "Test1")
            elif i == 1:
                self.assertEqual(frag[Db.MTextFragmentType.kTextValue], "Test2")
            elif i == 2:
                self.assertEqual(frag[Db.MTextFragmentType.kTextValue], "Test3")
            else:
                pass

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

        # create leader
        leader = Db.Leader()
        leader.setDatabaseDefaults()
        leader.appendVertex(Ge.Point3d(0, 0, 0))
        leader.appendVertex(Ge.Point3d(100, 100, 0))

        self.assertEqual(leader.vertexAt(0), Ge.Point3d(0, 0, 0))
        self.assertEqual(leader.vertexAt(1), Ge.Point3d(100, 100, 0))

        # set leader to red
        c = Db.Color()
        c.setRGB(255, 0, 0)
        leader.setColor(c)

        # add leader to db
        model.appendAcDbEntity(leader)

        # attach
        leader.attachAnnotation(mtid)
        self.assertEqual(leader.annotationObjId(), mtid)

    def test_polyline_listctor1(self):
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        pnts = []
        pnts.append(Ge.Point2d(0, 0))
        pnts.append(Ge.Point2d(1, 0))
        pnts.append(Ge.Point2d(1, 1))
        pnts.append(Ge.Point2d(0, 1))
        pnts.append(Ge.Point2d(0, 0))
        pline = Db.Polyline(pnts)
        pline.setColorIndex(1)
        self.assertEqual(pline.numVerts(), 5)
        self.assertEqual(len(pline.toPoint2dList()), 5)
        self.assertEqual(len(pline.toPoint3dList()), 5)
        self.assertEqual(len(pline.toList()), 5)
        self.assertEqual(pline.toPoint2dList(), pnts)
        model.appendAcDbEntity(pline)

    def test_polyline_listctor2(self):
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        pnts = []
        pnts.append(Ge.Point3d(0, 0, 0))
        pnts.append(Ge.Point3d(2, 0, 0))
        pnts.append(Ge.Point3d(2, 2, 0))
        pnts.append(Ge.Point3d(0, 2, 0))
        pnts.append(Ge.Point3d(0, 0, 0))
        pline = Db.Polyline(pnts)
        pline.setColorIndex(2)
        self.assertEqual(pline.numVerts(), 5)
        self.assertEqual(len(pline.toPoint2dList()), 5)
        self.assertEqual(len(pline.toPoint3dList()), 5)
        self.assertEqual(len(pline.toList()), 5)
        self.assertEqual(pline.toPoint3dList(), pnts)
        model.appendAcDbEntity(pline)

    def test_polyline_listctor3(self):
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        pnts = []
        pnts.append((0, 0))
        pnts.append((3, 0))
        pnts.append((3, 3))
        pnts.append((0, 3))
        pnts.append((0, 0))
        pline = Db.Polyline(pnts)
        pline.setColorIndex(3)
        self.assertEqual(pline.numVerts(), 5)
        self.assertEqual(len(pline.toPoint2dList()), 5)
        self.assertEqual(len(pline.toPoint3dList()), 5)
        self.assertEqual(len(pline.toList()), 5)
        model.appendAcDbEntity(pline)

    def test_polyline_listctor4(self):
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        pnts = []
        pnts.append((0, 0, 0))
        pnts.append((4, 0, 0))
        pnts.append((4, 4, 0))
        pnts.append((0, 4, 0))
        pnts.append((0, 0, 0))
        pline = Db.Polyline(pnts)
        pline.setColorIndex(4)
        self.assertEqual(pline.numVerts(), 5)
        self.assertEqual(len(pline.toPoint2dList()), 5)
        self.assertEqual(len(pline.toPoint3dList()), 5)
        self.assertEqual(len(pline.toList()), 5)
        model.appendAcDbEntity(pline)

    def test_polyline_listctor5(self):
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        pnts = []
        pnts.append([0, 0])
        pnts.append([5, 0])
        pnts.append([5, 5])
        pnts.append([0, 5])
        pnts.append([0, 0])
        pline = Db.Polyline(pnts)
        pline.setColorIndex(5)
        self.assertEqual(pline.numVerts(), 5)
        self.assertEqual(len(pline.toPoint2dList()), 5)
        self.assertEqual(len(pline.toPoint3dList()), 5)
        self.assertEqual(len(pline.toList()), 5)
        model.appendAcDbEntity(pline)

    def test_polyline_listctor6(self):
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        pnts = []
        pnts.append([0, 0, 0])
        pnts.append([6, 0, 0])
        pnts.append([6, 6, 0])
        pnts.append([0, 6, 0])
        pnts.append([0, 0, 0])
        pline = Db.Polyline(pnts)
        pline.setColorIndex(6)
        self.assertEqual(pline.numVerts(), 5)
        self.assertEqual(len(pline.toPoint2dList()), 5)
        self.assertEqual(len(pline.toPoint3dList()), 5)
        self.assertEqual(len(pline.toList()), 5)
        model.appendAcDbEntity(pline)

    def test_table_cells1(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        table = Db.Table(objId)
        iter = table.cells()
        self.assertEqual(len(iter), 1044)

    def test_table_cells2(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        table = Db.Table(objId)
        cr = Db.CellRange(1, 1, 3, 3)
        iter = table.cells(cr)
        self.assertEqual(len(iter), 9)

    @pytest.mark.known_failure_GRX
    def test_table_cells3(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        table = Db.Table(objId)
        opt = Db.TableIteratorOption.kTableIteratorSkipMerged
        iter = table.cells(Db.CellRange(1, 1, 3, 3), opt)
        self.assertEqual(len(iter), 9)

    @pytest.mark.known_failure_GRX
    def test_table_cells4(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        table = Db.Table(objId)
        opt = Db.TableIteratorOption.kTableIteratorSkipMerged
        iter = table.cells(opt)
        self.assertEqual(len(iter), 1036)

    def test_table_cellValues1(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        table = Db.Table(objId)
        iter = table.cellValues()
        self.assertEqual(len(iter), 1044)

    def test_table_cellValues2(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        table = Db.Table(objId)
        cr = Db.CellRange(1, 1, 3, 3)
        iter = table.cellValues(cr)
        self.assertEqual(len(iter), 9)

    @pytest.mark.known_failure_GRX
    def test_table_cellValues3(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        table = Db.Table(objId)
        opt = Db.TableIteratorOption.kTableIteratorSkipMerged
        iter = table.cellValues(opt)
        self.assertEqual(len(iter), 1036)

    def test_table_cellValues4(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        table = Db.Table(objId)
        opt = Db.TableIteratorOption.kTableIteratorSkipMerged
        iter = table.cellValues(Db.CellRange(1, 1, 3, 3), opt)
        self.assertEqual(len(iter), 9)

    def test_table_getstring(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c8cc9")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        table = Db.Table(objId)
        self.assertEqual(table.textString(4, 0), "{\\fMS Sans Serif|b0|i0|c0;R380")
        self.assertEqual(table.textString(4, 0, 0), "{\\fMS Sans Serif|b0|i0|c0;R380")
        opt = Db.ValueFormatOption.kIgnoreMtextFormat
        self.assertEqual(table.textStringFmt(4, 0, opt), "R380")
        self.assertEqual(table.textStringFmt(4, 0, 0, opt), "R380")

    def test_table_AcCell(self):
        cell1 = Db.Cell()
        self.assertEqual(cell1.row, -1)
        self.assertEqual(cell1.column, -1)
        cell2 = Db.Cell(1, 1)
        self.assertEqual(cell2.row, 1)
        self.assertEqual(cell2.column, 1)

    def test_table_AcCellRange(self):
        cr = Db.CellRange()
        self.assertEqual(cr.topRow, -1)
        self.assertEqual(cr.leftColumn, -1)
        self.assertEqual(cr.bottomRow, -1)
        self.assertEqual(cr.rightColumn, -1)
        cr2 = Db.CellRange(1, 2, 3, 4)
        self.assertEqual(cr2.topRow, 1)
        self.assertEqual(cr2.leftColumn, 2)
        self.assertEqual(cr2.bottomRow, 3)
        self.assertEqual(cr2.rightColumn, 4)

    @pytest.mark.known_failure_GRX
    def test_table_calcTextExtents(self):
        db = Db.curDb()
        rec = Db.TableStyle(db.tablestyle())
        ts = rec.textStyle(Db.RowType.kDataRow)
        w, h = Db.Table.calcTextExtents("This is", ts)
        self.assertGreater(w, 0, 2)
        self.assertGreater(h, 0, 2)
        w, h = Db.Table.calcTextExtents("TThis is a test", ts)
        self.assertGreater(w, 0, 2)
        self.assertGreater(h, 0, 2)

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
        self.assertTrue(id.isValid())

    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_BRX
    def test_create_extruded_surface(self):
        db = Db.curDb()
        opts = Db.SweepOptions()
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        dir = Ge.Point3d(0, 0, 100) - Ge.Point3d(0, 0, 0)
        profile = Db.Profile3d(circle)
        surf = Db.Surface.createExtrudedSurface(profile, dir, opts)
        id = db.addToModelspace(surf)
        self.assertTrue(id.isValid())
