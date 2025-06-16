import traceback
from pyrx import Rx, Ge, Gi, Db, Ap, Ed

print("added command pydimassoc")
print("added command pydimassocread")
print("added command pyremdimassoc")
print("added command assocleader")


def PyRxCmd_pydimassoc():
    try:
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(15, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)

        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)

        line = Db.Line(pt1, pt2)
        line.setDatabaseDefaults()
        lineid = model.appendAcDbEntity(line)
        line.close()

        dim = Db.AlignedDimension(pt1, pt2, pt3)
        dim.setDatabaseDefaults()
        dimId = model.appendAcDbEntity(dim)
        dim.close()

        ref1 = Db.OsnapPointRef(pt1)
        ref1.setOsnapType(Db.OsnapType.kOsnapStart)
        ref1.setIdPath(lineid, Db.SubentType.kEdgeSubentType, 0)

        ref2 = Db.OsnapPointRef(pt2)
        ref2.setOsnapType(Db.OsnapType.kOsnapEnd)
        ref2.setIdPath(lineid, Db.SubentType.kEdgeSubentType, 0)

        dimAssoc = Db.DimAssoc()
        dimAssoc.setDimObjId(dimId)
        dimAssoc.setPointRef(Db.DimAssocPointType.kXline1Point, ref1)
        dimAssoc.setPointRef(Db.DimAssocPointType.kXline2Point, ref2)
        dimAssoc.updateDimension()

        dimAssoc.post(dimId)
        # or
        # Db.Core.postDimAssoc(dimId,dimAssoc)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pydimassocread():
    try:
        res = Ed.Editor.entSel("\nPick a dim", Db.Dimension.desc())
        if res[0] != Ed.PromptStatus.eOk:
            return

        # acdbGetDimAssocId
        assocId = Db.Core.getDimAssocId(res[1])
        dimAssoc = Db.DimAssoc(assocId)

        # added dimAssoc.osnapPointRef so we don't need to cast in Python
        ref1 = dimAssoc.osnapPointRef(Db.DimAssocPointType.kXline1Point)
        ref2 = dimAssoc.osnapPointRef(Db.DimAssocPointType.kXline2Point)

        print(ref1.point(), ref2.point())

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pyremdimassoc():
    try:
        res = Ed.Editor.entSel("\nPick a dim", Db.Dimension.desc())
        if res[0] != Ed.PromptStatus.eOk:
            return

        # acdbGetDimAssocId
        assocId = Db.Core.getDimAssocId(res[1])
        dimAssoc = Db.DimAssoc(assocId, Db.OpenMode.ForWrite)

        dimAssoc.removeAssociativity()

    except Exception as err:
        traceback.print_exception(err)

#------------------------------------------
#leader
def makeLeader(db: Db.Database):
    mtext = Db.MText()
    mtext.setDatabaseDefaults()
    mtext.setLocation(Ge.Point3d(120, 102.5, 0))
    mtext.setContents("what we have, is failure to communicate")

    # create MLeader
    leader = Db.MLeader()
    leader.setDatabaseDefaults()
    leader.setContentType(Db.MLeaderContentType.kMTextContent)
    leader.setMText(mtext)

    # add a leader
    idx = leader.addLeaderLine(Ge.Point3d(100, 100, 0))
    leader.addFirstVertex(idx, Ge.Point3d(50, 0, 0))
    return db.addToModelspace(leader)


def makeLine(db: Db.Database):
    line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
    return db.addToModelspace(line)


@Ap.Command()
def assocleader() -> None:
    try:

        db = Db.curDb()
        lid = makeLeader(db)
        lineid = makeLine(db)

        oref = Db.OsnapPointRef(Ge.Point3d(50, 0, 0))
        oref.setOsnapType(Db.OsnapType.kOsnapMid)
        oref.setIdPath(lineid, Db.SubentType.kEdgeSubentType, 0)

        dimAssoc = Db.DimAssoc()
        dimAssoc.setDimObjId(lid)
        dimAssoc.setPointRef(Db.DimAssocPointType.kLeaderPoint, oref)
        dimAssoc.post(lid)

    except Exception as err:
        traceback.print_exception(err)
