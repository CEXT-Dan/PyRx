from pyrx import Ap, Db, Ge

print("added command = pycreate_hatch")
print("added command = create_hatch_pline")


def PyRxCmd_pycreate_hatch():
    try:
        db = Db.HostApplicationServices().workingDatabase()

        hatch = Db.Hatch()
        hatch.setDatabaseDefaults()
        normal = Ge.Vector3d(0, 0, 1)
        hatch.setNormal(normal)
        hatch.setElevation(0)

        hatch.setAssociative(False)

        hatch.setPattern(Db.HatchPatternType.kPreDefined, "SOLID")
        hatch.setHatchStyle(Db.HatchStyle.kNormal)

        vertexPts = []
        vertexPts.append(Ge.Point2d(2.0, 2.0))
        vertexPts.append(Ge.Point2d(8.0, 2.0))
        vertexPts.append(Ge.Point2d(8.0, 8.0))
        vertexPts.append(Ge.Point2d(2.0, 8.0))
        vertexPts.append(Ge.Point2d(2.0, 2.0))

        vertexBulges = []
        for n in range(len(vertexPts)):
            vertexBulges.append(0.0)

        hatch.appendLoopBulges(Db.HatchLoopType.kExternal, vertexPts, vertexBulges)

        cenPt = Ge.Point2d(5.0, 5.0)
        TWOPI = 2.0 * 3.1415926535897932
        cirArc = Ge.CircArc2d()
        cirArc.setCenter(cenPt)
        cirArc.setRadius(1.0)
        cirArc.setAngles(0.0, TWOPI)

        edgePtrs = []
        edgeTypes = []

        edgePtrs.append(cirArc)
        edgeTypes.append(Db.HatchEdgeType.kCirArc)

        hatch.appendLoopEdges(Db.HatchLoopType.kDefault, edgePtrs, edgeTypes)
        hatch.evaluateHatch()

        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
        model.appendAcDbEntity(hatch)
    except Exception as err:
        print(err)


def createpline(btr: Db.BlockTableRecord):
    vertexPts = []
    vertexPts.append(Ge.Point2d(2.0, 2.0))
    vertexPts.append(Ge.Point2d(8.0, 2.0))
    vertexPts.append(Ge.Point2d(8.0, 8.0))
    vertexPts.append(Ge.Point2d(2.0, 8.0))
    vertexPts.append(Ge.Point2d(2.0, 2.0))
    pl = Db.Polyline(vertexPts)
    pl.setDatabaseDefaults()
    pl.setClosed(True)
    return btr.appendAcDbEntity(pl)


def createHatch(btr: Db.BlockTableRecord, plid: Db.ObjectId):
    hatch = Db.Hatch()
    hatch.setDatabaseDefaults()
    hatch.setAssociative(True)
    hatch.setPattern(Db.HatchPatternType.kPreDefined, "SOLID")
    hatch.setHatchStyle(Db.HatchStyle.kNormal)
    hid = btr.appendAcDbEntity(hatch)
    hatch.appendLoop(Db.HatchLoopType.kExternal, [plid])
    hatch.evaluateHatch(True)
    return hid


@Ap.Command()
def create_hatch_pline():
    try:
        db = Db.curDb()

        # block
        btr = Db.BlockTableRecord()
        btr.setName("TestBlock")
        bt = Db.BlockTable(db.blockTableId(), Db.OpenMode.kForWrite)
        bt.add(btr)

        plid = createpline(btr)
        hid = createHatch(btr, plid)

        ids = [plid, hid]
        mat = Ge.Matrix3d()
        mat.setToRotation(0.785398, Ge.Vector3d.kZAxis, Ge.Point3d.kOrigin)

        for id in ids:
            ent = Db.Entity(id, Db.OpenMode.kForWrite)
            ent.transformBy(mat)

    except Exception as err:
        print(err)
