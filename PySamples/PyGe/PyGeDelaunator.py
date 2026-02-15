import traceback
from time import perf_counter
from pyrx import Ap, Db, Ed, Ge

# Ge.Delaunator uses a modified version of https://github.com/abellgithub/delaunator-cpp.
# Its modified in that it’s designed to use a collection of Ge.Point3d.
# its documented here https://mapbox.github.io/delaunator/
# Also see https://github.com/mapbox/delaunator, https://github.com/HakanSeven12/Delaunator-Python

# ----------------------------------------------------------------------
# Module: PyRx Voronoi & Delaunator Tools
# Description: Provides AutoCAD commands to generate Voronoi diagrams
#              (using Circumcenters and Centroids) and Delaunay triangulation
#              with contour line generation.
# ----------------------------------------------------------------------

print("added command pyvoronoiCCM")
print("added command pyvoronoiCEN")
print("added command pydelaunator")


# ----------------------------------------------------------------------
# Helper Functions
# ----------------------------------------------------------------------


def do_select():
    """
    Prompts the user to select AutoCAD POINT entities.

    Returns:
        Ed.SelectionSet: The selected set if successful, None otherwise.
    """
    # Define a filter to only select POINT entities
    filter = [(Db.DxfCode.kDxfStart, "POINT")]

    # Prompt user for selection and removal
    # Returns (PromptStatus, SelectionSet)
    ps, ss = Ed.Editor.selectPrompt("\nSelect points: ", "\nRemove points: ", filter)

    if ps == Ed.PromptStatus.eNormal:
        return ss
    return None


def circumcenter(a: Ge.Point3d, b: Ge.Point3d, c: Ge.Point3d):
    """
    Calculates the circumcenter of a triangle defined by three points.

    The circumcenter is the center of the circle that passes through all three vertices.
    It is calculated using vector algebra (barycentric coordinates).

    Args:
        a (Ge.Point3d): First vertex
        b (Ge.Point3d): Second vertex
        c (Ge.Point3d): Third vertex

    Returns:
        Ge.Point3d: The circumcenter of the triangle.
    """
    ac: Ge.Vector3d = c - a
    ab: Ge.Vector3d = b - a

    # Cross product of AB and AC
    abXac = ab.crossProduct(ac)

    # Vector calculation for the circumcenter
    # Formula: (|AC|^2 * (AB x (AB x AC)) + |AB|^2 * ((AB x AC) x AC)) / (2 * |AB x AC|^2)
    cc = (
        abXac.crossProduct(ab) * ac.lengthSqrd()
        + ac.crossProduct(abXac) * ab.lengthSqrd()
    )

    # Normalize and translate to point A
    toCircumsphereCenter = cc / (2.0 * abXac.lengthSqrd())
    return a + toCircumsphereCenter


def centroid(a: Ge.Point3d, b: Ge.Point3d, c: Ge.Point3d):
    """
    Calculates the centroid (geometric center) of a triangle.

    The centroid is the arithmetic mean position of all the points in the figure.

    Args:
        a (Ge.Point3d): First vertex
        b (Ge.Point3d): Second vertex
        c (Ge.Point3d): Third vertex

    Returns:
        Ge.Point3d: The centroid of the triangle.
    """
    CX1 = (a.x + b.x + c.x) / 3
    CX2 = (a.y + b.y + c.y) / 3
    CX3 = (a.z + b.z + c.z) / 3
    return Ge.Point3d(CX1, CX2, CX3)


def triangle(idx: int, d: Ge.Delaunator, pnts: list[Ge.Point3d]):
    """
    Helper to extract the three vertices of a specific triangle from the Delaunator data.

    Args:
        idx (int): Index of the triangle in the flat array (every 3rd index is a new triangle).
        d (Ge.Delaunator): The Delaunator object.
        pnts (list): List of input points.

    Returns:
        list: A list of three Ge.Point3d objects.
    """
    triangles = d.triangles()
    return [
        pnts[triangles[idx + 0]],
        pnts[triangles[idx + 1]],
        pnts[triangles[idx + 2]],
    ]


def triangleAtEdge(e: int):
    """
    Determines the index of the adjacent triangle sharing a half-edge.

    The Delaunator stores triangles in a flat array. Each edge is shared by two triangles.
    This function calculates the index of the other triangle based on the half-edge index.

    Args:
        e (int): The half-edge index.

    Returns:
        int: The index of the adjacent triangle.
    """
    if e % 3 == 1:
        return e - 1
    elif e % 3 == 2:
        return e - 2
    return e


def get_3dpointds(objs: list[Db.ObjectId]):
    """
    Extracts the 3D position of selected objects.

    Args:
        objs (Ed.SelectionSet): The selection set containing POINT entities.

    Returns:
        list: A list of Ge.Point3d objects.
    """
    pnts = []
    for id in objs:
        p = Db.Point(id)
        pnts.append(p.position())
    return pnts


# ----------------------------------------------------------------------
# Voronoi Generation Functions
# ----------------------------------------------------------------------


def getVoronoiEdgesCCM(d: Ge.Delaunator, pnts: list[Ge.Point3d]):
    """
    Generates Voronoi edges using the Circumcenter (CCM) method.

    For every edge shared by two triangles, the circumcenter of each triangle is calculated.
    The line connecting these two circumcenters is a Voronoi edge.

    Args:
        d (Ge.Delaunator): The Delaunator object.
        pnts (list): List of input points.

    Returns:
        list: A list of tuples, where each tuple contains two Ge.Point3d (start, end).
    """
    edges = []
    triangles = d.triangles()
    halfedges = d.halfedges()

    # Iterate through the flat triangle array (step 3 for each triangle)
    for i in range(0, len(triangles), 3):
        tri1 = triangle(i, d, pnts)

        # Calculate circumcenter of the current triangle
        p = circumcenter(tri1[0], tri1[1], tri1[2])

        # Check each of the 3 edges of the triangle
        for o in range(3):
            if halfedges[i + o] != -1:
                e = halfedges[i + o]
                nt = triangleAtEdge(e)

                # Ensure the adjacent triangle exists
                if nt < len(triangles):
                    tri2 = triangle(nt, d, pnts)
                    q = circumcenter(tri2[0], tri2[1], tri2[2])
                    edges.append((p, q))
    return edges


def getVoronoiEdgesCEN(d: Ge.Delaunator, pnts: list[Ge.Point3d]):
    """
    Generates Voronoi edges using the Centroid (CEN) method.

    Similar to CCM, but uses the geometric centroid of the triangle instead of the circumcenter.

    Args:
        d (Ge.Delaunator): The Delaunator object.
        pnts (list): List of input points.

    Returns:
        list: A list of tuples, where each tuple contains two Ge.Point3d (start, end).
    """
    edges = []
    triangles = d.triangles()
    halfedges = d.halfedges()

    for i in range(0, len(triangles), 3):
        tri1 = triangle(i, d, pnts)

        # Calculate centroid of the current triangle
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


# ----------------------------------------------------------------------
# Contour Generation Functions
# ----------------------------------------------------------------------


def interpolate_point(p1, p2, level):
    """
    Linearly interpolates a point on a line segment at a specific Z level.

    Args:
        p1 (list): Start point [x, y, z]
        p2 (list): End point [x, y, z]
        level (float): The Z elevation to interpolate to.

    Returns:
        list: The interpolated point [x, y, z].
    """
    t = (level - p1[2]) / (p2[2] - p1[2])
    return [p1[0] + t * (p2[0] - p1[0]), p1[1] + t * (p2[1] - p1[1]), level]


def process_triangle_contours(triangle_points: list[Ge.Point3d], level: float):
    """
    Processes a single triangle to generate contour segments at a specific Z level.

    Checks which vertices are below and above the level, then interpolates the intersection
    points on the edges.

    Args:
        triangle_points (list): List of 3 points [x, y, z].
        level (float): The Z level to generate contours for.

    Returns:
        list: A list of interpolated contour points, or None if no intersection occurs.
    """
    points_below = []
    points_above = []

    for point in triangle_points:
        if point[2] < level:
            points_below.append(point)
        else:
            points_above.append(point)

    # No intersection if all points are on one side
    if len(points_below) == 0 or len(points_above) == 0:
        return None

    contour_points = []

    # Case 1: One point below, two above -> Interpolate two edges
    if len(points_below) == 1:
        p1 = points_below[0]
        p2, p3 = points_above
        contour_points = [
            interpolate_point(p1, p2, level),
            interpolate_point(p1, p3, level),
        ]
    # Case 2: Two points below, one above -> Interpolate two edges
    elif len(points_below) == 2:
        p1, p2 = points_below
        p3 = points_above[0]
        contour_points = [
            interpolate_point(p1, p3, level),
            interpolate_point(p2, p3, level),
        ]

    return contour_points


# ----------------------------------------------------------------------
# AutoCAD Commands
# ----------------------------------------------------------------------
@Ap.Command()
def pyvoronoiCCM():
    """
    AutoCAD Command: pyvoronoiCCM
    Generates a Voronoi diagram using Circumcenters.
    """
    try:
        ss = do_select()
        if not ss:
            return

        t1_start = perf_counter()
        pnt3ds = get_3dpointds(ss)

        # Perform Delaunay triangulation
        d = Ge.Delaunator(pnt3ds)

        # Generate Voronoi edges
        for e in getVoronoiEdgesCCM(d, pnt3ds):
            # Draw the edge using the Graphics API
            Ed.Core.grDraw(e[0], e[1], 4, 0)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop - t1_start))

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def pyvoronoiCEN():
    """
    AutoCAD Command: pyvoronoiCEN
    Generates a Voronoi diagram using Centroids.
    """
    try:
        ss = do_select()
        if not ss:
            return

        t1_start = perf_counter()
        pnt3ds = get_3dpointds(ss)

        # Perform Delaunay triangulation
        d = Ge.Delaunator(pnt3ds)

        # Generate Voronoi edges
        for e in getVoronoiEdgesCEN(d, pnt3ds):
            # Draw the edge using the Graphics API
            Ed.Core.grDraw(e[0], e[1], 3, 0)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop - t1_start))

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def pydelaunator():
    """
    AutoCAD Command: pydelaunator
    Generates Delaunay triangles and contour lines based on point Z values.
    """
    try:
        ss = do_select()
        if not ss:
            return

        t1_start = perf_counter()
        pnt3ds = get_3dpointds(ss)

        # Perform Delaunay triangulation
        t = Ge.Delaunator(pnt3ds).triangles()

        # Calculate min/max Z values for contour generation
        ncontours = 20
        z_values = [p[2] for p in pnt3ds]
        min_z = min(z_values)
        max_z = max(z_values)
        step = (max_z - min_z) / ncontours

        contour_lines = []

        # Generate contour lines for each elevation level
        for level in [min_z + i * step for i in range(1, ncontours)]:
            for i in range(0, len(t), 3):
                triangle_points = [pnt3ds[t[i]], pnt3ds[t[i + 1]], pnt3ds[t[i + 2]]]
                contour_segment = process_triangle_contours(triangle_points, level)
                if contour_segment:
                    contour_lines.append(contour_segment)

        db = Db.HostApplicationServices().workingDatabase()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)

        # Draw triangles
        for i in range(0, len(t), 3):
            f = Db.Face(pnt3ds[t[i]], pnt3ds[t[i + 1]], pnt3ds[t[i + 2]])
            f.setColorIndex(8)  # Color 8 is usually White/Light Gray
            model.appendAcDbEntity(f)

        # Draw contours
        segs = []
        for contour in contour_lines:
            segs.append(Ge.LineSeg3d(Ge.Point3d(contour[0]), Ge.Point3d(contour[1])))

        # Convert line segments to a CompositeCurve and then to AutoCAD Curve entities
        ccs = Ge.CompositeCurve3d.createFromLineSeg3dArray(segs)
        for cc in ccs:
            dbc = Db.Core.convertGelibCurveToAcDbCurve(cc)
            dbc.setColorIndex(3)  # Color 3 is usually Cyan
            model.appendAcDbEntity(dbc)

        t1_stop = perf_counter()
        print("Elapsed time: {t:.4f}".format(t=t1_stop - t1_start))
    except Exception as err:
        print(err)
