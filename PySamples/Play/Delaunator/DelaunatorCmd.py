from time import perf_counter

from Delaunator import Delaunator

from pyrx import Ap, Db, Ed, Ge

# PySamples\dwg\TestPoints.dwg
print("added command pydelaunator")


def do_select():
    filter = [(Db.DxfCode.kDxfStart, "POINT")]
    ss = Ed.Editor.selectPrompt("\nSelect points: ", "\nRemove points: ", filter)
    if ss[0] == Ed.PromptStatus.eNormal:
        return ss[1]


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
        pnt3ds = get_3dpointds(ss.toList())
        pnt2ds = get_2dpointd(pnt3ds)

        # doit
        t = Delaunator(pnt2ds).triangles

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
            f.setColorIndex(31)
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
