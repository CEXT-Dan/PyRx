from __future__ import annotations

import math
import time
import unittest

import pytest

from pyrx import Db, Ed, Ge, Rx


def do_capture_audit() -> str:
    capture = Db.HostApplicationServices.createOutputCapture()
    capture.setMuteCmdLine(True)
    cmdData = [
        (Rx.LispType.kText, "AUDIT"),
        (Rx.LispType.kText, "N"),
        (Rx.LispType.kNone, 0),
    ]
    Ed.Core.cmdS(cmdData)
    return capture.output()


class TestDatabase:
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")

    def test_dbopbjectforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isValid() is True
        dbo = Db.DbObject(objId)
        assert dbo.isA().dxfName() == "LINE"

    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_BRX
    def test_capture_cmdline_output(self):
        result = do_capture_audit()
        assert len(result) != 0

    def test_dbcore_entmake(self):
        flag = Db.Core.entMake(
            [(0, "LINE"), (10, Ge.Point3d(0, 0, 0)), (11, Ge.Point3d(100, 100, 0))]
        )

        assert flag == True
        lastid = Db.Core.entLast()
        entlist = Db.Core.entGet(lastid)

        for i, x in enumerate(entlist):
            if x[0] == 10:
                entlist[i] = (10, Ge.Point3d(0, 100, 0))

        Db.Core.entMod(entlist)
        entlist2 = Db.Core.entGet(lastid)

        for x in entlist2:
            if x[0] == 10:
                assert x[1] == Ge.Point3d(0, 100, 0)

    def test_dbcore_strconversions(self):
        flag = Ed.Core.setVar("ANGBASE", 0)
        self.assertions.assertEqual(flag, True)
        flag = Ed.Core.setVar("DIMZIN", 0)
        self.assertions.assertEqual(flag, True)
        val = Db.Core.angToF("180", 0)
        self.assertions.assertAlmostEqual(val, math.pi, 8)
        val = Db.Core.angToF("180d0'0\"", 1)
        self.assertions.assertAlmostEqual(val, math.pi, 8)
        val = Db.Core.angToF("200.0000g", 2)
        self.assertions.assertAlmostEqual(val, math.pi, 8)
        val = Db.Core.angToF("3.1416r", 3)
        self.assertions.assertEqual(val, 3.1416)
        val = Db.Core.angToF("W", 4)
        self.assertions.assertAlmostEqual(val, math.pi, 8)
        sval = Db.Core.angToS(math.pi, 0, 2)
        self.assertions.assertEqual(sval, "180.00")

    def test_dbcore_activeDatabaseArray(self):
        dbs = Db.Core.activeDatabaseArray()
        self.assertions.assertNotEqual(len(dbs), 0)

    def test_property_ids(self):
        self.assertions.assertEqual(Db.Database.className(), "AcDbDatabase")
        db = Db.HostApplicationServices().workingDatabase()
        angbase = db.angbase()
        db.setAngbase(1)
        self.assertions.assertEqual(db.angbase(), 1)
        db.setAngbase(angbase)
        self.assertions.assertEqual(db.angbase(), angbase)
        self.assertions.assertEqual(
            db.byBlockLinetype().objectClass().name(), "AcDbLinetypeTableRecord"
        )
        self.assertions.assertEqual(db.byBlockMaterial().objectClass().name(), "AcDbMaterial")
        self.assertions.assertEqual(
            db.byLayerLinetype().objectClass().name(), "AcDbLinetypeTableRecord"
        )
        self.assertions.assertEqual(db.byLayerMaterial().objectClass().name(), "AcDbMaterial")
        self.assertions.assertEqual(db.clayer().objectClass().name(), "AcDbLayerTableRecord")
        self.assertions.assertEqual(db.cmlstyleID().objectClass().name(), "AcDbMlineStyle")
        self.assertions.assertEqual(
            db.colorDictionaryId().objectClass().name(), "AcDbDictionary"
        )

    @pytest.mark.known_failure_GRX
    def test_SymUtilServices(self):
        db = Db.HostApplicationServices().workingDatabase()
        sus = Db.SymUtilServices()
        self.assertions.assertEqual(sus.blockModelSpaceId(db), db.modelSpaceId())
        self.assertions.assertEqual(sus.blockModelSpaceName(), "*Model_Space")
        self.assertions.assertEqual(sus.hasVerticalBar("str|str"), True)
        self.assertions.assertEqual(sus.hasVerticalBar("strstr"), False)
        self.assertions.assertEqual(sus.compareSymbolName("strstr", "strstr"), 0)
        self.assertions.assertEqual(sus.compareSymbolName("strstr", "ztrstr"), -1)

    def test_handle(self, db_06457: Db.Database):
        lineHnd = Db.Handle("20127")
        lineId = db_06457.getObjectId(False, lineHnd)
        self.assertions.assertEqual(lineId.isNull(), False)
        self.assertions.assertEqual(lineHnd.isNull(), False)
        self.assertions.assertEqual(lineId.isDerivedFrom(Db.Line.desc()), True)
        self.assertions.assertEqual(lineHnd.toString(), "20127")
        self.assertions.assertEqual(Db.Handle("20127") == Db.Handle("20127"), True)
        self.assertions.assertEqual(Db.Handle("20127") != Db.Handle("20127"), False)

    @staticmethod
    def putSummaryInfo() -> None:
        db = Db.curDb()
        customDict = {"Ford": "Mustang", "Chevy": "Camaro", "VW": " Bug"}
        info = Db.Core.getSummaryInfo(db)
        info.setCustomSummaryFromDict(customDict)
        info.setTitle("MyTitle")
        info.setSubject("MySubject")
        info.setAuthor("MyAuthor")
        info.setKeywords("MyKeywords")
        info.setComments("MyComments")
        info.setLastSavedBy("Me")
        info.setRevisionNumber("1.1.0001")
        info.setHyperlinkBase("myHyperlinkBase")
        Db.Core.putSummaryInfo(info, db)

    def test_getSummaryInfo(self):
        TestDatabase.putSummaryInfo()
        customDict = {"Ford": "Mustang", "Chevy": "Camaro", "VW": " Bug"}
        db = Db.curDb()
        info = Db.Core.getSummaryInfo(db)
        self.assertions.assertEqual(info.getTitle(), "MyTitle")
        self.assertions.assertEqual(info.getSubject(), "MySubject")
        self.assertions.assertEqual(info.getAuthor(), "MyAuthor")
        self.assertions.assertEqual(info.getKeywords(), "MyKeywords")
        self.assertions.assertEqual(info.getComments(), "MyComments")
        self.assertions.assertEqual(info.getLastSavedBy(), "Me")
        self.assertions.assertEqual(info.getRevisionNumber(), "1.1.0001")
        self.assertions.assertEqual(info.getHyperlinkBase(), "myHyperlinkBase")

        cs = info.asDict()
        keys = cs.keys()
        values = cs.values()

        for key, value in customDict.items():
            self.assertions.assertEqual(key in keys, True)
            self.assertions.assertEqual(value in values, True)

    def test_dbentityforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertions.assertEqual(objId.isValid(), True)
        dbo = Db.Entity(objId)
        self.assertions.assertEqual(dbo.isA().dxfName(), "LINE")

    def test_dbcurveforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertions.assertEqual(objId.isValid(), True)
        dbo = Db.Curve(objId)
        self.assertions.assertEqual(dbo.isA(), Db.Line.desc())

    def test_dblineforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertions.assertEqual(objId.isValid(), True)
        line = Db.Line(objId)
        self.assertions.assertEqual(line.isKindOf(Db.Line.desc()), True)
        self.assertions.assertEqual(line.layer(), "1_1_WALLS")

    def test_dbpolylineforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("201ee")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertions.assertEqual(objId.isValid(), True)
        pline = Db.Polyline(objId)
        self.assertions.assertEqual(pline.isKindOf(Db.Curve.desc()), True)
        self.assertions.assertEqual(pline.isKindOf(Db.Polyline.desc()), True)
        self.assertions.assertEqual(pline.layer(), "1_CRP_WALLS")
        self.assertions.assertEqual(pline.numVerts(), 5)
        self.assertions.assertAlmostEqual(pline.getArea(), 7222764.7277, 4)

    def test_dbsplineforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c62a1")
        objId = db_06457.getObjectId(False, objHnd)
        self.assertions.assertEqual(objId.isValid(), True)
        spline = Db.Spline(objId)
        self.assertions.assertEqual(spline.isKindOf(Db.Curve.desc()), True)
        self.assertions.assertEqual(spline.isKindOf(Db.Spline.desc()), True)
        self.assertions.assertEqual(spline.numFitPoints(), 3)

    def test_addToModelspaced1(self, db_06457: Db.Database):
        db = db_06457
        line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        id = db.addToModelspace(line)
        self.assertions.assertTrue(id.isValid())
        self.assertions.assertTrue(id.isDerivedFrom(Db.Line.desc()))

    def test_addToModelspaced2(self, db_06457: Db.Database):
        db = db_06457
        lines = [
            Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0)),
            Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0)),
        ]
        ids = db.addToBlock(db.modelSpaceId(), lines)
        for id in ids:
            self.assertions.assertTrue(id.isValid())
            self.assertions.assertTrue(id.isDerivedFrom(Db.Line.desc()))

    def test_blocktable(self, db_06457: Db.Database):
        db: Db.Database = db_06457
        bt = Db.BlockTable(db.blockTableId())
        data = bt.toDict()

        mid = Db.SymUtilServices().blockModelSpaceId(db)
        mname = Db.SymUtilServices().blockModelSpaceName()
        pid = Db.SymUtilServices().blockPaperSpaceId(db)
        pname = Db.SymUtilServices().blockPaperSpaceName()

        self.assertions.assertTrue(bt.has(mid))
        self.assertions.assertTrue(bt.has(mname))
        self.assertions.assertTrue(bt.has(pid))
        self.assertions.assertTrue(bt.has(pname))

        self.assertions.assertTrue((mid in bt))
        self.assertions.assertTrue((mname in bt))
        self.assertions.assertTrue((pid in bt))
        self.assertions.assertTrue((pname in bt))

        self.assertions.assertTrue((mid in data.values()))
        self.assertions.assertTrue((mname in data.keys()))
        self.assertions.assertTrue((pid in data.values()))
        self.assertions.assertTrue((pname in data.keys()))

        cnt1 = 0
        for id in bt:
            cnt1 += 1
        cnt2 = 0
        for id in data.values():
            cnt2 += 1
        self.assertions.assertEqual(cnt1, cnt2)

    def test_btr_iter(self, db_points: Db.Database):
        db: Db.Database = db_points
        model = Db.BlockTableRecord(db.modelSpaceId())
        cnt1 = 0
        for id in model:
            cnt1 += 1
        cnt2 = 0
        for id in model.objectIds():
            cnt2 += 1
        self.assertions.assertEqual(cnt1, cnt2)

    def test_addToBlock1(self, db_06457: Db.Database):
        db = db_06457
        line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        id = db.addToBlock(db.modelSpaceId(), line)
        self.assertions.assertTrue(id.isValid())
        self.assertions.assertTrue(id.isDerivedFrom(Db.Line.desc()))

    def test_addToBlock2(self, db_06457: Db.Database):
        db = db_06457
        lines = [
            Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0)),
            Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0)),
        ]

        ids = db.addToBlock(db.modelSpaceId(), lines)
        for id in ids:
            self.assertions.assertTrue(id.isValid())
            self.assertions.assertTrue(id.isDerivedFrom(Db.Line.desc()))

    def test_inrecord(self, db_06457: Db.Database):
        db = db_06457
        lt = Db.LayerTable(db.layerTableId())
        self.assertions.assertTrue("0" in lt)
        self.assertions.assertTrue(db.layerZero() in lt)
        self.assertions.assertEqual(db.layerZero(), lt["0"])

    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    def test_GeoPositionMarker(self, db_geo: Db.Database):
        db = db_geo
        model = Db.BlockTableRecord(db.modelSpaceId())
        geoPosDesc = Db.GeoPositionMarker.desc()
        markers = [Db.GeoPositionMarker(id) for id in model.objectIds(geoPosDesc)]
        for marker in markers:
            self.assertions.assertIsNotNone(marker.latLonAlt())
        for marker in markers:
            self.assertions.assertIsNotNone(marker.position())
        for marker in markers:
            self.assertions.assertIsNotNone(marker.geoPosition())

    @pytest.mark.known_failure_ZRX
    def test_GeoData(self, db_geo: Db.Database) -> None:
        db = db_geo
        geoDataId = Db.Core.getGeoDataObjId(db)
        self.assertions.assertTrue(geoDataId.isValid())
        geoData = Db.GeoData(geoDataId)
        self.assertions.assertIsNotNone(geoData.coordinateSystem())

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    def test_GeoData_transformFromLonLatAlt(self, db_geo: Db.Database) -> None:
        db = db_geo
        geoDataId = Db.Core.getGeoDataObjId(db)
        geoData = Db.GeoData(geoDataId)
        result = geoData.transformFromLonLatAlt(Ge.Point3d(0.8894, 90.0000, 1))
        self.assertions.assertEqual(result.x, -13839395.1337296)
        self.assertions.assertEqual(result.y, 8430914.179736577)
        self.assertions.assertEqual(result.z, 1.00000000000000)

    def test_dbextents(self) -> None:
        ex1 = Db.Extents(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 100))
        ex2 = Db.Extents(Ge.Point3d(10, 10, 0), Ge.Point3d(110, 110, 110))
        self.assertions.assertEqual(ex1.intersectsWith(ex2), True)
        self.assertions.assertEqual(ex1.midPoint(), Ge.Point3d(50, 50, 50))

    @pytest.mark.known_failure_BRX
    def test_tdusrtimer(self) -> None:
        db = Db.curDb()
        date1 = db.tdusrtimer()
        time.sleep(1)
        date2 = db.tdusrtimer()
        self.assertions.assertEqual(date2.second() - date1.second(), 1)
        date3 = date2 - date1
        date1 += date3
        self.assertions.assertEqual(date1, date2)

    def test_dblayoutmanager_sidedb_countLayouts(self, db_06457: Db.Database) -> None:
        lm = Db.LayoutManager()
        cnt = lm.countLayouts(db_06457)
        self.assertions.assertEqual(cnt, 12)

    def test_symboltable_contains(self):
        db = Db.curDb()
        lt = Db.LayerTable(db.layerTableId())
        self.assertions.assertTrue("0" in lt)
        id = lt["0"]
        self.assertions.assertTrue(id in lt)
        self.assertions.assertTrue(db.layerZero() in lt)
        bt = Db.BlockTable(db.blockTableId())
        self.assertions.assertTrue(Db.SymUtilServices().blockModelSpaceName() in bt)
