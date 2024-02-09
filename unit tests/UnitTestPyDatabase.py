import os
import unittest
import math

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

print("testname = pydbtest")


class TestDatabase(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestDatabase, self).__init__(*args, **kwargs)
        # open and keep open for all 06457 tests
        self.db06457 = Db.Database(False, True)
        self.db06457.readDwgFile("./testmedia/06457.dwg")
        self.db06457.closeInput(True)
        
        self.geodb = Db.Database(False, True)
        self.geodb.readDwgFile("./testmedia/geomarker.dwg")
        self.geodb.closeInput(True)
        
    def __del__(self):
        del(self.db06457)
        del(self.geodb)
        
    def test_dbcore_entmake(self):
        flag = Db.Core.entMake(
            [(0, "LINE"), (10, Ge.Point3d(0, 0, 0)), (11, Ge.Point3d(100, 100, 0))]
        )

        self.assertEqual(flag, True)
        lastid = Db.Core.entLast()
        entlist = Db.Core.entGet(lastid)

        for i, x in enumerate(entlist):
            if x[0] == 10:
                entlist[i] = (10, Ge.Point3d(0, 100, 0))

        Db.Core.entMod(entlist)
        entlist2 = Db.Core.entGet(lastid)

        for x in entlist2:
            if x[0] == 10:
                self.assertEqual(x[1], Ge.Point3d(0, 100, 0))

    def test_dbcore_strconversions(self):
        flag = Ed.Core.setVar("DIMZIN", 0)
        self.assertEqual(flag, True)
        val = Db.Core.angToF("180", 0)
        self.assertAlmostEqual(val, math.pi, 8)
        val = Db.Core.angToF("180d0'0\"", 1)
        self.assertAlmostEqual(val, math.pi, 8)
        val = Db.Core.angToF("200.0000g", 2)
        self.assertAlmostEqual(val, math.pi, 8)
        val = Db.Core.angToF("3.1416r", 3)
        self.assertEqual(val, 3.1416)
        val = Db.Core.angToF("W", 4)
        self.assertAlmostEqual(val, math.pi, 8)
        sval = Db.Core.angToS(math.pi, 0, 2)
        self.assertEqual(sval, "180.00")

    def test_dbcore_activeDatabaseArray(self):
        dbs = Db.Core.activeDatabaseArray()
        self.assertNotEqual(len(dbs), 0)

    def test_property_ids(self):
        self.assertEqual(Db.Database.className(), "AcDbDatabase")
        db = Db.HostApplicationServices().workingDatabase()
        angbase = db.angbase()
        db.setAngbase(1)
        self.assertEqual(db.angbase(), 1)
        db.setAngbase(angbase)
        self.assertEqual(db.angbase(), angbase)
        self.assertEqual(
            db.byBlockLinetype().objectClass().name(), "AcDbLinetypeTableRecord"
        )
        self.assertEqual(db.byBlockMaterial().objectClass().name(), "AcDbMaterial")
        self.assertEqual(
            db.byLayerLinetype().objectClass().name(), "AcDbLinetypeTableRecord"
        )
        self.assertEqual(db.byLayerMaterial().objectClass().name(), "AcDbMaterial")
        self.assertEqual(db.clayer().objectClass().name(), "AcDbLayerTableRecord")
        self.assertEqual(db.cmlstyleID().objectClass().name(), "AcDbMlineStyle")
        self.assertEqual(db.colorDictionaryId().objectClass().name(), "AcDbDictionary")

    def test_SymUtilServices(self):
        db = Db.HostApplicationServices().workingDatabase()
        sus = Db.SymUtilServices()
        self.assertEqual(sus.blockModelSpaceId(db), db.modelSpaceId())
        self.assertEqual(sus.blockModelSpaceName(), "*Model_Space")
        self.assertEqual(sus.hasVerticalBar("str|str"), True)
        self.assertEqual(sus.hasVerticalBar("strstr"), False)
        self.assertEqual(sus.compareSymbolName("strstr", "strstr"), 0)
        self.assertEqual(sus.compareSymbolName("strstr", "ztrstr"), -1)

    def test_handle(self):
        sideDb = Db.Database(False, True)
        sideDb.readDwgFile("./testmedia/test.dwg")
        sideDb.closeInput(True)
        lineHnd = Db.Handle("296")
        lineId = sideDb.getObjectId(False, lineHnd)
        self.assertEqual(lineId.isNull(), False)
        self.assertEqual(lineHnd.isNull(), False)
        self.assertEqual(lineId.isDerivedFrom(Db.Line.desc()), True)
        self.assertEqual(lineHnd.toString(), "296")
        self.assertEqual(Db.Handle("296") == Db.Handle("296"), True)
        self.assertEqual(Db.Handle("296") != Db.Handle("296"), False)

    def putSummaryInfo():
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
        self.assertEqual(info.getTitle(), "MyTitle")
        self.assertEqual(info.getSubject(), "MySubject")
        self.assertEqual(info.getAuthor(), "MyAuthor")
        self.assertEqual(info.getKeywords(), "MyKeywords")
        self.assertEqual(info.getComments(), "MyComments")
        self.assertEqual(info.getLastSavedBy(), "Me")
        self.assertEqual(info.getRevisionNumber(), "1.1.0001")
        self.assertEqual(info.getHyperlinkBase(), "myHyperlinkBase")
        self.assertEqual(info.asDict(), customDict)

    def test_dbopbjectforread(self):
        objHnd = Db.Handle("20127")
        objId = self.db06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        dbo = Db.DbObject(objId)
        self.assertEqual(dbo.isA().dxfName(), "LINE")

    def test_dbentityforread(self):
        objHnd = Db.Handle("20127")
        objId = self.db06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        dbo = Db.Entity(objId)
        self.assertEqual(dbo.isA().dxfName(), "LINE")

    def test_dbcurveforread(self):
        objHnd = Db.Handle("20127")
        objId = self.db06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        dbo = Db.Curve(objId)
        self.assertEqual(dbo.isA(), Db.Line.desc())

    def test_dblineforread(self):
        objHnd = Db.Handle("20127")
        objId = self.db06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        line = Db.Line(objId)
        self.assertEqual(line.isKindOf(Db.Line.desc()), True)
        self.assertEqual(line.layer(), "1_1_WALLS")

    def test_dbpolylineforread(self):
        objHnd = Db.Handle("201ee")
        objId = self.db06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        pline = Db.Polyline(objId)
        self.assertEqual(pline.isKindOf(Db.Curve.desc()), True)
        self.assertEqual(pline.isKindOf(Db.Polyline.desc()), True)
        self.assertEqual(pline.layer(), "1_CRP_WALLS")
        self.assertEqual(pline.numVerts(), 5)
        self.assertAlmostEqual(pline.getArea(), 7222764.7277, 4)

    def test_dbsplineforread(self):
        objHnd = Db.Handle("2c62a1")
        objId = self.db06457.getObjectId(False, objHnd)
        self.assertEqual(objId.isValid(), True)
        spline = Db.Spline(objId)
        self.assertEqual(spline.isKindOf(Db.Curve.desc()), True)
        self.assertEqual(spline.isKindOf(Db.Spline.desc()), True)
        self.assertEqual(spline.numFitPoints(), 3)

    def test_addToModelspaced1(self):
        db = self.db06457
        line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        id = db.addToModelspace(line)
        self.assertTrue(id.isValid())
        self.assertTrue(id.isDerivedFrom(Db.Line.desc()))
        
    def test_addToModelspaced2(self):
        db = self.db06457
        lines = [Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0)),
         Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))]
        ids = db.addToBlock(db.modelSpaceId(), lines)
        for id in ids:
            self.assertTrue(id.isValid())
            self.assertTrue(id.isDerivedFrom(Db.Line.desc()))
        
    def test_addToBlock1(self):
        db = self.db06457
        line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        id = db.addToBlock(db.modelSpaceId(), line)
        self.assertTrue(id.isValid())
        self.assertTrue(id.isDerivedFrom(Db.Line.desc()))
        
    def test_addToBlock2(self):
        db = self.db06457
        lines = [Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0)),
         Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))]
        
        ids = db.addToBlock(db.modelSpaceId(), lines)
        for id in ids:
            self.assertTrue(id.isValid())
            self.assertTrue(id.isDerivedFrom(Db.Line.desc()))
        
    def test_inrecord(self):
        db = self.db06457
        lt = Db.LayerTable(db.layerTableId())
        self.assertTrue('0' in lt)
        self.assertTrue(db.layerZero() in lt)
        self.assertEqual(db.layerZero(),lt['0'])
        
    def test_GeoPositionMarker(self):
        db = self.geodb
        model = Db.BlockTableRecord(db.modelSpaceId())
        
        geoPosDesc = Db.GeoPositionMarker.desc()
        markers = [Db.GeoPositionMarker(id) for id in model.objectIds(geoPosDesc)]

        for marker in markers:
            self.assertIsNotNone(marker.latLonAlt())

        for marker in markers:
            self.assertIsNotNone(marker.position())

        for marker in markers:
            self.assertIsNotNone(marker.geoPosition())
            
    def test_GeoData(self):
        db = self.geodb
        geoDataId = Db.Core.getGeoDataObjId(db)
        self.assertTrue(geoDataId.isValid())
        geoData = Db.GeoData(geoDataId)
        self.assertIsNotNone(geoData.coordinateSystem())
        
def PyRxCmd_pydbtest():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestDatabase)
        print("TestDatabase")
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        print(err)
