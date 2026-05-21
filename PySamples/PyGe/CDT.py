import traceback
from itertools import pairwise

from pyrx import Ap, Db, Ed, Ge

print("Added command CDTInsertedges")
print("Added command CDTConformedges")


def getEdgeData(id, pntmap: dict[Ge.Point3d, int]):
    pl = Db.Polyline3d(id)
    plpnts = pl.toPoint3dArray()
    edgedata = []
    for p in plpnts:
        edgedata.append(pntmap[p])
    return edgedata

@Ap.Command()
def CDTInsertedges():
    try:
        ps, pss = Ed.Editor.select([(0, "POINT")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("oof:")

        ps, plss = Ed.Editor.select([(0, "POLYLINE")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("oof:")

        edgedata = []
        pnts = [Db.Point(id).position() for id in pss.objectIds()]

        pntmap = {}
        for i, p in enumerate(pnts):
            pntmap[p] = i

        for id in plss.objectIds():
            result = getEdgeData(id, pntmap)
            #this closes, I.e adds end to start 
            #edgedata.extend(list(zip(result, result[1:] + [result[0]])))
            edgedata.extend(pairwise(result))
            
        opts = Ge.CDTOpts(Ge.CDTOpts.KEraseSuperTriangle | Ge.CDTOpts.KInsertEdges)

        faces = []

        np, tris = Ge.CDT.triangulate(pnts, edgedata, opts)
        for _a, _b, _c in tris:
            faces.append(Db.Face(np[_a], np[_b], np[_c]))
        db = Db.curDb()
        db.addToModelspace(faces)

    except Exception:
        print(traceback.format_exc())

@Ap.Command()
def CDTConformedges():
    try:
        ps, pss = Ed.Editor.select([(0, "POINT")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("oof:")

        ps, plss = Ed.Editor.select([(0, "POLYLINE")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("oof:")

        edgedata = []
        pnts = [Db.Point(id).position() for id in pss.objectIds()]

        pntmap = {}
        for i, p in enumerate(pnts):
            pntmap[p] = i

        for id in plss.objectIds():
            result = getEdgeData(id, pntmap)
            #edgedata.extend(list(zip(result, result[1:] + [result[0]])))
            edgedata.extend(pairwise(result))

        opts = Ge.CDTOpts(Ge.CDTOpts.KEraseSuperTriangle | Ge.CDTOpts.KConformToEdges)

        faces = []

        np, tris = Ge.CDT.triangulate(pnts, edgedata, opts)
        for _a, _b, _c in tris:
            faces.append(Db.Face(np[_a], np[_b], np[_c]))
        db = Db.curDb()
        db.addToModelspace(faces)

    except Exception:
        print(traceback.format_exc())
