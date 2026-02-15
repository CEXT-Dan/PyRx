import traceback
from time import perf_counter
from pyrx import Ap, Db, Ed, Ge

print("added command pyvoronoiCCM")
print("added command pyvoronoiCEN")
print("added command pydelaunator")


# Ge.Delaunator uses a modified version of https://github.com/abellgithub/delaunator-cpp. 
# Its modified in that it’s designed to use a collection of Ge.Point3d. 
# its documented here https://mapbox.github.io/delaunator/ 
# Also see https://github.com/mapbox/delaunator, https://github.com/HakanSeven12/Delaunator-Python


def do_select():
    filter = [(Db.DxfCode.kDxfStart, "POINT")]
    ps, ss = Ed.Editor.selectPrompt("\nSelect points: ", "\nRemove points: ", filter)
    if ps == Ed.PromptStatus.eNormal:
        return ss


def circumcenter(a, b, c):
    ac = c - a
    ab = b - a
    abXac = ab.crossProduct(ac)
    cc = (
        abXac.crossProduct(ab) * ac.lengthSqrd()
        + ac.crossProduct(abXac) * ab.lengthSqrd()
    )
    toCircumsphereCenter = cc / (2.0 * abXac.lengthSqrd())
    return a + toCircumsphereCenter


def centroid(a, b, c):
    CX1 = (a.x + b.x + c.x) / 3
    CX2 = (a.y + b.y + c.y) / 3
    CX3 = (a.z + b.z + c.z) / 3
    return Ge.Point3d(CX1, CX2, CX3)


def triangle(idx, d, pnts):
    triangles = d.triangles()
    return [
        pnts[triangles[idx + 0]],
        pnts[triangles[idx + 1]],
        pnts[triangles[idx + 2]],
    ]


def getVoronoiEdgesCCM(d: Ge.Delaunator, pnts):
    edges = []
    triangles = d.triangles()
    halfedges = d.halfedges()
    for i in range(0, len(triangles), 3):
        tri1 = triangle(i, d, pnts)
        p = circumcenter(tri1[0], tri1[1], tri1[2])
        for o in range(3):
            if halfedges[i + o] != -1:
                e = halfedges[i + o]
                nt = triangleAtEdge(e)
                if nt < len(triangles):
                    tri2 = triangle(nt, d, pnts)
                    q = circumcenter(tri2[0], tri2[1], tri2[2])
                    edges.append((p, q))
    return edges


def getVoronoiEdgesCEN(d: Ge.Delaunator, pnts):
    edges = []
    triangles = d.triangles()
    halfedges = d.halfedges()
    for i in range(0, len(triangles), 3):
        tri1 = triangle(i, d, pnts)
        p = centroid(tri1[0], tri1[1], tri1[2])
        for o in range(3):
            if halfedges[i + o] != -1:
                e = halfedges[i + o]
                nt = triangleAtEdge(e)
                if nt < len(triangles):
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


@Ap.Command()
def pyvoronoiCCM():
    try:
        ss = do_select()
        t1_start = perf_counter()
        pnt3ds = get_3dpointds(ss)

        # doit
        d = Ge.Delaunator(pnt3ds)
        for e in getVoronoiEdgesCCM(d, pnt3ds):
            Ed.Core.grDraw(e[0], e[1], 4, 0)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop - t1_start))

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def pyvoronoiCEN():
    try:
        ss = do_select()

        t1_start = perf_counter()
        pnt3ds = get_3dpointds(ss)

        # doit
        d = Ge.Delaunator(pnt3ds)
        for e in getVoronoiEdgesCEN(d, pnt3ds):
            Ed.Core.grDraw(e[0], e[1], 3, 0)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop - t1_start))

    except Exception as err:
        traceback.print_exception(err)


# Generate contour lines
def interpolate_point(p1, p2, level):
    t = (level - p1[2]) / (p2[2] - p1[2])
    return [p1[0] + t * (p2[0] - p1[0]), p1[1] + t * (p2[1] - p1[1]), level]


def process_triangle_contours(triangle_points, level):
    points_below = []
    points_above = []

    for point in triangle_points:
        if point[2] < level:
            points_below.append(point)
        else:
            points_above.append(point)

    if len(points_below) == 0 or len(points_above) == 0:
        return None

    contour_points = []
    if len(points_below) == 1:
        p1 = points_below[0]
        p2, p3 = points_above
        contour_points = [
            interpolate_point(p1, p2, level),
            interpolate_point(p1, p3, level),
        ]
    elif len(points_below) == 2:
        p1, p2 = points_below
        p3 = points_above[0]
        contour_points = [
            interpolate_point(p1, p3, level),
            interpolate_point(p2, p3, level),
        ]
    return contour_points


@Ap.Command()
def pydelaunator():
    try:
        ss = do_select()
        t1_start = perf_counter()
        pnt3ds = get_3dpointds(ss)


        # doit
        t = Ge.Delaunator(pnt3ds).triangles()

        # Calculate min/max Z values
        ncontours = 20
        z_values = [p[2] for p in pnt3ds]
        min_z = min(z_values)
        max_z = max(z_values)
        step = (max_z - min_z) / ncontours

        contour_lines = []
        for level in [min_z + i * step for i in range(1, ncontours)]:
            for i in range(0, len(t), 3):
                triangle_points = [pnt3ds[t[i]], pnt3ds[t[i + 1]], pnt3ds[t[i + 2]]]
                contour_segment = process_triangle_contours(triangle_points, level)
                if contour_segment:
                    contour_lines.append(contour_segment)

        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)

        # draw triangles
        for i in range(0, len(t), 3):
            f = Db.Face(pnt3ds[t[i]], pnt3ds[t[i + 1]], pnt3ds[t[i + 2]])
            f.setColorIndex(8)
            model.appendAcDbEntity(f)

        # draw contours
        segs = []
        for contour in contour_lines:
            segs.append(Ge.LineSeg3d(Ge.Point3d(contour[0]), Ge.Point3d(contour[1])))

        ccs = Ge.CompositeCurve3d.createFromLineSeg3dArray(segs)
        for cc in ccs:
            dbc = Db.Core.convertGelibCurveToAcDbCurve(cc)
            dbc.setColorIndex(3)
            model.appendAcDbEntity(dbc)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop - t1_start))
    except Exception as err:
        print(err)
