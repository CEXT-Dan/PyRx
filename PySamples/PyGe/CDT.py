import traceback
from pyrx import Ap, Ax, Db, Ed, Ge, Rx, Gi


def getEdgeData(pl, pntmap: dict[Ge.Point3d, int]):
    plpnts = pl.toPoint3dArray()
    edgedata = []
    for p in plpnts:
        edgedata.append(pntmap[p])
    return edgedata

def selectPoly(pntmap: dict[Ge.Point3d, int]):
    ps, id1, _ = Ed.Editor.entSel("\nSelect Polyline", Db.Polyline.desc())
    if ps != Ed.PromptStatus.eOk:
        raise RuntimeError("oof:")
    pl = Db.Polyline(id1)
    return getEdgeData(pl, pntmap)

def selectPoly3(pntmap: dict[Ge.Point3d, int]):
    ps, id1, _ = Ed.Editor.entSel("\nSelect Polyline", Db.Polyline3d.desc())
    if ps != Ed.PromptStatus.eOk:
        raise RuntimeError("oof:")
    pl = Db.Polyline3d(id1)
    return getEdgeData(pl, pntmap)

@Ap.Command()
def doit1():
    try:

        ps, ss = Ed.Editor.select([(0, "POINT")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("oof:")

        edgedata = []
        pnts = Ge.Point3dArray([Db.Point(id).position() for id in ss.objectIds()])

        # use a dict for fast index lookup
        pntmap = {}
        for i, p in enumerate(pnts):
            pntmap[p] = i

        result = selectPoly(pntmap)
        edgedata.extend(list(zip(result, result[1:] + [result[0]])))

        result = selectPoly(pntmap)
        edgedata.extend(list(zip(result, result[1:] + [result[0]])))

        faces = []
        for _a, _b, _c in Ge.CDT.triangulate(pnts, edgedata, True):
            faces.append(Db.Face(pnts[_a], pnts[_b], pnts[_c]))

        db = Db.curDb()
        db.addToModelspace(faces)

    except Exception:
        print(traceback.format_exc())


@Ap.Command()
def doit2():
    try:

        ps, ss = Ed.Editor.select([(0, "POINT")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("oof:")

        edgedata = []
        pnts = [Db.Point(id).position() for id in ss.objectIds()]

        pntmap = {}
        for i, p in enumerate(pnts):
            pntmap[p] = i

        result = selectPoly3(pntmap)
        edgedata.extend(list(zip(result, result[1:] + [result[0]])))

        result = selectPoly3(pntmap)
        edgedata.extend(list(zip(result, result[1:] + [result[0]])))

        faces = []
        for _a, _b, _c in Ge.CDT.triangulate(pnts, edgedata, True):
            faces.append(Db.Face(pnts[_a], pnts[_b], pnts[_c]))

        db = Db.curDb()
        db.addToModelspace(faces)

    except Exception:
        print(traceback.format_exc())
