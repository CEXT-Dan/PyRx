from __future__ import annotations

import math
import time

import pytest

from pyrx import Ap, Db, Ed, Ge, Rx
from tests import MEDIA_DIR


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

    def test_getBlocks(self, db_06457: Db.Database):
        blks = db_06457.getBlocks()
        assert blks["*Model_Space"] == db_06457.modelSpaceId()

    def test_dbopbjectforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() is False
        dbo = Db.DbObject(objId)
        assert bool(dbo.isReadEnabled()) is True

    @pytest.mark.known_failure_IRX
    def test_dbopbject_dxfname(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isNull() is False
        dbo = Db.DbObject(objId)
        assert dbo.isA().dxfName() == "LINE"

    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_IRX
    @pytest.mark.known_failure_ZRX
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
        assert flag
        flag = Ed.Core.setVar("DIMZIN", 0)
        assert flag
        val = Db.Core.angToF("180", 0)
        assert val == pytest.approx(math.pi, rel=1e-8)
        val = Db.Core.angToF("180d0'0\"", 1)
        assert val == pytest.approx(math.pi, rel=1e-8)
        val = Db.Core.angToF("200.0000g", 2)
        assert val == pytest.approx(math.pi, rel=1e-8)
        val = Db.Core.angToF("3.1416r", 3)
        assert val == 3.1416
        val = Db.Core.angToF("W", 4)
        assert val == pytest.approx(math.pi, rel=1e-8)
        sval = Db.Core.angToS(math.pi, 0, 2)
        assert sval == "180.00"

    def test_dbcore_activeDatabaseArray(self):
        dbs = Db.Core.activeDatabaseArray()
        assert len(dbs) != 0

    def test_property_ids(self):
        assert Db.Database.className() == "AcDbDatabase"
        db = Db.HostApplicationServices().workingDatabase()
        angbase = db.angbase()
        db.setAngbase(1)
        assert db.angbase() == 1
        db.setAngbase(angbase)
        assert db.angbase() == angbase
        assert db.byBlockLinetype().objectClass().name() == "AcDbLinetypeTableRecord"
        assert db.byBlockMaterial().objectClass().name() == "AcDbMaterial"
        assert db.byLayerLinetype().objectClass().name() == "AcDbLinetypeTableRecord"
        assert db.byLayerMaterial().objectClass().name() == "AcDbMaterial"
        assert db.clayer().objectClass().name() == "AcDbLayerTableRecord"
        assert db.cmlstyleID().objectClass().name() == "AcDbMlineStyle"
        assert db.colorDictionaryId().objectClass().name() == "AcDbDictionary"

    @pytest.mark.known_failure_GRX
    def test_SymUtilServices(self):
        db = Db.HostApplicationServices().workingDatabase()
        sus = Db.SymUtilServices()
        assert sus.blockModelSpaceId(db) == db.modelSpaceId()
        assert sus.blockModelSpaceName() == "*Model_Space"
        assert sus.hasVerticalBar("str|str")
        assert not sus.hasVerticalBar("strstr")
        assert sus.compareSymbolName("strstr", "strstr") == 0
        assert sus.compareSymbolName("strstr","ztrstr") == -1

    def test_handle(self, db_06457: Db.Database):
        lineHnd = Db.Handle("20127")
        lineId = db_06457.getObjectId(False, lineHnd)
        assert not lineId.isNull()
        assert not lineHnd.isNull()
        assert lineId.isDerivedFrom(Db.Line.desc())
        assert lineHnd.toString() == "20127"
        assert Db.Handle("20127") == Db.Handle("20127")
        assert not Db.Handle("20127") != Db.Handle("20127")

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

    @pytest.mark.known_failure_IRX
    def test_getSummaryInfo(self):
        TestDatabase.putSummaryInfo()
        customDict = {"Ford": "Mustang", "Chevy": "Camaro", "VW": " Bug"}
        db = Db.curDb()
        info = Db.Core.getSummaryInfo(db)
        assert info.getTitle() == "MyTitle"
        assert info.getSubject() == "MySubject"
        assert info.getAuthor() == "MyAuthor"
        assert info.getKeywords() == "MyKeywords"
        assert info.getComments() == "MyComments"
        assert info.getLastSavedBy() == "Me"
        assert info.getRevisionNumber() == "1.1.0001"
        assert info.getHyperlinkBase() == "myHyperlinkBase"

        cs = info.asDict()
        keys = cs.keys()
        values = cs.values()

        for key, value in customDict.items():
            assert key in keys
            assert value in values

    def test_dbentityforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        assert not objId.isNull()
        dbo = Db.Entity(objId)
        assert dbo.isA().name() == "AcDbLine"

    def test_dbcurveforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        assert not objId.isNull()
        dbo = Db.Curve(objId)
        assert dbo.isA() == Db.Line.desc()

    def test_dblineforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("20127")
        objId = db_06457.getObjectId(False, objHnd)
        assert not objId.isNull()
        line = Db.Line(objId)
        assert line.isKindOf(Db.Line.desc())
        assert line.layer() == "1_1_WALLS"

    def test_dbpolylineforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("201ee")
        objId = db_06457.getObjectId(False, objHnd)
        assert not objId.isNull()
        pline = Db.Polyline(objId)
        assert pline.isKindOf(Db.Curve.desc())
        assert pline.isKindOf(Db.Polyline.desc())
        assert pline.layer() == "1_CRP_WALLS"
        assert pline.numVerts() == 5
        assert pline.getArea() == pytest.approx(7222764.7277, rel=1e-4)

    def test_dbsplineforread(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c62a1")
        objId = db_06457.getObjectId(False, objHnd)
        assert not objId.isNull()
        spline = Db.Spline(objId)
        assert spline.isKindOf(Db.Curve.desc())
        assert spline.isKindOf(Db.Spline.desc())
        assert spline.numFitPoints() == 3

    def test_addToModelspaced1(self, db_06457: Db.Database):
        db = db_06457
        line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        id = db.addToModelspace(line)
        assert not id.isNull()
        assert id.isDerivedFrom(Db.Line.desc())

    def test_addToModelspaced2(self, db_06457: Db.Database):
        db = db_06457
        lines = [
            Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0)),
            Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0)),
        ]
        ids = db.addToBlock(db.modelSpaceId(), lines)
        for id in ids:
            assert not id.isNull()
            assert id.isDerivedFrom(Db.Line.desc())

    @pytest.mark.known_failure_IRX
    def test_blocktable(self, db_06457: Db.Database):
        db: Db.Database = db_06457
        bt = Db.BlockTable(db.blockTableId())
        data = bt.toDict()

        mid = Db.SymUtilServices().blockModelSpaceId(db)
        mname = Db.SymUtilServices().blockModelSpaceName()
        pid = Db.SymUtilServices().blockPaperSpaceId(db)
        pname = Db.SymUtilServices().blockPaperSpaceName()

        assert bt.has(mid)
        assert bt.has(mname)
        assert bt.has(pid)
        assert bt.has(pname)

        assert mid in bt
        assert mname in bt
        assert pid in bt
        assert pname in bt

        assert mid in data.values()
        assert mname in data.keys()
        assert pid in data.values()
        assert pname in data.keys()

        cnt1 = 0
        for id in bt:
            cnt1 += 1
        cnt2 = 0
        for id in data.values():
            cnt2 += 1
        assert cnt1 == cnt2

    def test_btr_iter(self, db_points: Db.Database):
        db: Db.Database = db_points
        model = Db.BlockTableRecord(db.modelSpaceId())
        cnt1 = 0
        for id in model:
            cnt1 += 1
        cnt2 = 0
        for id in model.objectIds():
            cnt2 += 1
        assert cnt1 == cnt2

    def test_addToBlock1(self, db_06457: Db.Database):
        db = db_06457
        line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        id = db.addToBlock(db.modelSpaceId(), line)
        assert not id.isNull()
        assert id.isDerivedFrom(Db.Line.desc())

    def test_addToBlock2(self, db_06457: Db.Database):
        db = db_06457
        lines = [
            Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0)),
            Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0)),
        ]

        ids = db.addToBlock(db.modelSpaceId(), lines)
        for id in ids:
            assert not id.isNull()
            assert id.isDerivedFrom(Db.Line.desc())

    def test_inrecord(self, db_06457: Db.Database):
        db = db_06457
        lt = Db.LayerTable(db.layerTableId())
        assert "0" in lt
        assert db.layerZero() in lt
        assert db.layerZero() == lt["0"]

    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_IRX
    def test_GeoPositionMarker(self, db_geo: Db.Database):
        db = db_geo
        model = Db.BlockTableRecord(db.modelSpaceId())
        geoPosDesc = Db.GeoPositionMarker.desc()
        markers = [Db.GeoPositionMarker(id) for id in model.objectIds(geoPosDesc)]
        for marker in markers:
            assert marker.latLonAlt() is not None
        for marker in markers:
            assert marker.position() is not None
        for marker in markers:
            assert marker.geoPosition() is not None

    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_IRX
    def test_GeoData(self, db_geo: Db.Database) -> None:
        db = db_geo
        geoDataId = Db.Core.getGeoDataObjId(db)
        assert not geoDataId.isNull()
        geoData = Db.GeoData(geoDataId)
        assert geoData.coordinateSystem() is not None

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_IRX
    def test_GeoData_transformFromLonLatAlt(self, db_geo: Db.Database) -> None:
        db = db_geo
        geoDataId = Db.Core.getGeoDataObjId(db)
        geoData = Db.GeoData(geoDataId)
        result = geoData.transformFromLonLatAlt(Ge.Point3d(0.8894, 90.0000, 1))
        assert result.x == -13839395.1337296
        assert result.y == 8430914.179736577
        assert result.z == 1.00000000000000

    def test_dbextents(self) -> None:
        ex1 = Db.Extents(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 100))
        ex2 = Db.Extents(Ge.Point3d(10, 10, 0), Ge.Point3d(110, 110, 110))
        assert ex1.intersectsWith(ex2)
        assert ex1.midPoint() == Ge.Point3d(50, 50, 50)

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_IRX
    @pytest.mark.known_failure_GRX
    def test_tdusrtimer(self) -> None:
        db = Db.curDb()
        date1 = db.tdusrtimer()
        time.sleep(1)
        date2 = db.tdusrtimer()
        assert date2.second() - date1.second() == 1
        date3 = date2 - date1
        date1 += date3
        assert date1 == date2

    def test_dblayoutmanager_sidedb_countLayouts(self, db_06457: Db.Database) -> None:
        lm = Db.LayoutManager()
        cnt = lm.countLayouts(db_06457)
        assert cnt == 12

    def test_symboltable_contains(self):
        db = Db.curDb()
        lt = Db.LayerTable(db.layerTableId())
        assert "0" in lt
        id = lt["0"]
        assert id in lt
        assert db.layerZero() in lt
        bt = Db.BlockTable(db.blockTableId())
        assert Db.SymUtilServices().blockModelSpaceName() in bt

    def test_using_decorator(self):
        sdb = Db.Database(False, True)
        sdb.readDwgFile(str(MEDIA_DIR / "sidedb.dwg"))
        sdb.closeInput(True)
        ids = []

        @Ap.using_scope()
        def _() -> None:
            ms = sdb.modelSpace()
            ids.extend([Db.Curve(id).objectId() for id in ms.objectIds(Db.Curve.desc())])

        assert len(ids) != 0

    def helper(self, sdb, ids):
        ms = sdb.modelSpace()
        ids.extend([Db.Curve(id).objectId() for id in ms.objectIds(Db.Curve.desc())])

    def test_using_helper(self):
        sdb = Db.Database(False, True)
        sdb.readDwgFile(str(MEDIA_DIR / "sidedb.dwg"))
        sdb.closeInput(True)
        ids = []
        self.helper(sdb, ids)
        assert len(ids) != 0

    def test_overrulableEntity(self, db_06457: Db.Database):
        objHnd = Db.Handle("2c97d0")
        objId = db_06457.getObjectId(False, objHnd)
        ore = Db.OverrulableEntity(objId)
        assert ore.position() == Ge.Point3d(1, 1, 1)
        assert ore.direction() == Ge.Vector3d.kYAxis
        assert ore.normal() == Ge.Vector3d.kXAxis
        assert ore.guid() == "12345"
        assert ore.name() == "name"
        assert ore.description() == "description"
        assert ore.typing() == 1
        assert ore.mask() == 2
        assert ore.index() == 3
        assert ore.flags() == [1, 2, 3]
        assert ore.ints() == [4, 5, 6]
        assert ore.doubles() == [7, 8, 9]
        assert ore.strings() == ["1", "2", "3"]
        assert ore.points() == [Ge.Point3d(1, 1, 1), Ge.Point3d(2, 2, 2)]

    def test_blocktable_iter(self, db_06457: Db.Database):
        niter = 0
        for k, v in db_06457.blockTable():
            niter += 1
        assert niter != 0

    def test_regapp_db(delf):
        name = "TESTAPPSDB"
        sdb = Db.Database()
        sdb.registerApp(name)
        assert sdb.isAppRegistered(name) == True
        cur_db = Db.curDb()
        assert cur_db.isAppRegistered(name) == False

    def test_layerTable1(self, db_06457: Db.Database):
        data = []
        for name, id in db_06457.layerTable():
            data.append((name, id))
        assert len(data) != 0

    def test_layerTable2(self, db_06457: Db.Database):
        data = []
        for name, id in db_06457.layerTable(Db.OpenMode.kForRead):
            data.append((name, id))
        assert len(data) != 0
