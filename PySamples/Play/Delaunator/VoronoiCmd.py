import traceback
from time import perf_counter
from Delaunator import Delaunator
from pyrx import Db, Ed, Ge

# PySamples\dwg\TestPoints.dwg
print("added command pyvoronoiCCM")
print("added command pyvoronoiCEN")


def do_select():
    filter = [(Db.DxfCode.kDxfStart, "POINT")]
    ss = Ed.Editor.selectPrompt("\nSelect points: ", "\nRemove points: ", filter)
    if ss[0] == Ed.PromptStatus.eNormal:
        return ss[1]


def circumcenter(a, b, c):
    ac = c - a
    ab = b - a
    abXac = ab.crossProduct(ac)
    cc = abXac.crossProduct(ab) * ac.lengthSqrd() + ac.crossProduct(abXac) * ab.lengthSqrd()
    toCircumsphereCenter = cc / (2.0 * abXac.lengthSqrd())
    return a + toCircumsphereCenter


def centroid(a, b, c):
    CX1 = (a.x + b.x + c.x) / 3
    CX2 = (a.y + b.y + c.y) / 3
    CX3 = (a.z + b.z + c.z) / 3
    return Ge.Point3d(CX1, CX2, CX3)


def triangle(idx, d, pnts):
    return [pnts[d.triangles[idx + 0]], pnts[d.triangles[idx + 1]], pnts[d.triangles[idx + 2]]]


def getVoronoiEdgesCCM(d, pnts):
    edges = []

    for i in range(0, len(d.triangles), 3):
        tri1 = triangle(i, d, pnts)
        p = circumcenter(tri1[0], tri1[1], tri1[2])
        for o in range(3):
            if d.halfedges[i + o] != -1:
                e = d.halfedges[i + o]
                nt = triangleAtEdge(e)
                if nt < len(d.triangles):
                    tri2 = triangle(nt, d, pnts)
                    q = circumcenter(tri2[0], tri2[1], tri2[2])
                    edges.append((p, q))
    return edges


def getVoronoiEdgesCEN(d, pnts):
    edges = []
    for i in range(0, len(d.triangles), 3):
        tri1 = triangle(i, d, pnts)
        p = centroid(tri1[0], tri1[1], tri1[2])
        for o in range(3):
            if d.halfedges[i + o] != -1:
                e = d.halfedges[i + o]
                nt = triangleAtEdge(e)
                if nt < len(d.triangles):
                    tri2 = triangle(nt, d, pnts)
                    q = centroid(tri2[0], tri2[1], tri2[2])
                    edges.append((p, q))
    return edges


def triangleAtEdge(e):
    if e % 3 == 1:
        return e - 1
    elif e % 3 == 2:
        return e - 2
    return e


def get_3dpointds(objs):
    pnts = []
    for id in objs:
        p = Db.Point(id)
        pnts.append(p.position())
    return pnts


def get_2dpointd(pnt3ds):
    pnts = []
    for p in pnt3ds:
        pnts.append([p.x, p.y])
    return pnts


def PyRxCmd_pyvoronoiCCM():
    try:
        ss = do_select()

        t1_start = perf_counter()

        pnt3ds = get_3dpointds(ss.toList())
        pnt2ds = get_2dpointd(pnt3ds)

        # doit
        d = Delaunator(pnt2ds)

        for e in getVoronoiEdgesCCM(d, pnt3ds):
            Ed.Core.grDraw(e[0], e[1], 4, 0)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop - t1_start))

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pyvoronoiCEN():
    try:
        ss = do_select()

        t1_start = perf_counter()

        pnt3ds = get_3dpointds(ss.toList())
        pnt2ds = get_2dpointd(pnt3ds)

        # doit
        d = Delaunator(pnt2ds)

        for e in getVoronoiEdgesCEN(d, pnt3ds):
            Ed.Core.grDraw(e[0], e[1], 3, 0)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop - t1_start))

    except Exception as err:
        traceback.print_exception(err)
