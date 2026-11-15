# --- CAD Tools ---
# Tool implementations and LM Studio / OpenAI tool schemas.
# These run inside the AutoCAD application context via dispatch_to_acad().

from pyrx import Db, Ge


def get_drawing_info():
    db = Db.curDb()
    ms = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForRead)
    entity_counts = {}
    for obj_id in ms.objectIds():
        ent = Db.Entity(obj_id)
        etype = ent.isA().name()
        entity_counts[etype] = entity_counts.get(etype, 0) + 1
    return {"modelspace_entity_counts": entity_counts}


def create_circle(cx: float, cy: float, radius: float, layer: str = "0"):
    db = Db.curDb()
    ms = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
    circle = Db.Circle(Ge.Point3d(cx, cy, 0.0), Ge.Vector3d.kZAxis, radius)
    circle.setLayer(layer)
    obj_id = ms.appendAcDbEntity(circle)
    return {"status": "created", "type": "Circle", "handle": str(obj_id.handle())}


def create_line(x1: float, y1: float, x2: float, y2: float, layer: str = "0"):
    db = Db.curDb()
    ms = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
    line = Db.Line(Ge.Point3d(x1, y1, 0.0), Ge.Point3d(x2, y2, 0.0))
    line.setLayer(layer)
    obj_id = ms.appendAcDbEntity(line)
    return {"status": "created", "type": "Line", "handle": str(obj_id.handle())}


def create_polyline(
    points: list[tuple[float, float]],
    closed: bool = False,
    layer: str = "0",
):
    if len(points) < 2:
        raise ValueError("A polyline needs at least two (x, y) points.")

    db = Db.curDb()
    ms = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)
    polyline = Db.Polyline([(float(x), float(y)) for x, y in points])
    polyline.setClosed(bool(closed))
    polyline.setLayer(layer)
    obj_id = ms.appendAcDbEntity(polyline)
    return {
        "status": "created",
        "type": "Polyline",
        "handle": str(obj_id.handle()),
        "num_vertices": len(points),
        "closed": bool(closed),
    }


def create_cylinder(
    cx: float,
    cy: float,
    cz: float,
    radius: float,
    height: float,
    layer: str = "0",
):
    r = float(radius)
    h = float(height)
    if r <= 0.0 or h <= 0.0:
        raise ValueError("Radius and height must be positive.")

    db = Db.curDb()
    solid = Db.Solid3d()
    solid.setDatabaseDefaults(db)
    solid.createFrustum(h, r, r, r)

    # Translate from origin (0,0,0) to (cx, cy, cz)
    vec = Ge.Point3d(float(cx), float(cy), float(cz)) - Ge.Point3d.kOrigin
    solid.transformBy(Ge.Matrix3d.translation(vec))
    solid.setLayer(layer)

    obj_id = db.addToCurrentspace(solid)
    return {
        "status": "created",
        "type": "Solid3d",
        "handle": str(obj_id.handle()),
        "is_null": solid.isNull(),
    }


TOOL_FUNCTIONS = {
    "create_polyline": create_polyline,
    "create_cylinder": create_cylinder,
    "get_drawing_info": get_drawing_info,
    "create_circle": create_circle,
    "create_line": create_line,
}

TOOL_SCHEMAS = [
    {
        "type": "function",
        "function": {
            "name": "create_polyline",
            "description": (
                "Draw a 2D polyline (lightweight) through a sequence of points in AutoCAD modelspace. "
                "Points are (x, y) coordinate pairs in drawing units. Set closed to true to connect "
                "the last point back to the first."
            ),
            "parameters": {
                "type": "object",
                "properties": {
                    "points": {
                        "type": "array",
                        "description": "Ordered (x, y) coordinate pairs, e.g. [[0, 0], [1, 1], [3, 1]]",
                        "minItems": 2,
                        "items": {
                            "type": "array",
                            "minItems": 2,
                            "maxItems": 2,
                            "items": {"type": "number"},
                        },
                    },
                    "closed": {
                        "type": "boolean",
                        "description": "Whether to close the polyline (connect last point to first)",
                    },
                    "layer": {"type": "string", "description": "Target layer name"},
                },
                "required": ["points"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "create_cylinder",
            "description": (
                "Create a 3D solid cylinder aligned with the Z-axis. "
                "(cx, cy, cz) is the geometric center of the cylinder."
            ),
            "parameters": {
                "type": "object",
                "properties": {
                    "cx": {"type": "number"},
                    "cy": {"type": "number"},
                    "cz": {"type": "number"},
                    "radius": {"type": "number"},
                    "height": {"type": "number"},
                    "layer": {"type": "string"},
                },
                "required": ["cx", "cy", "cz", "radius", "height"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "get_drawing_info",
            "description": "Inspect entity counts in the active AutoCAD modelspace.",
            "parameters": {"type": "object", "properties": {}, "required": []},
        },
    },
    {
        "type": "function",
        "function": {
            "name": "create_circle",
            "description": "Draw a 2D circle in AutoCAD modelspace.",
            "parameters": {
                "type": "object",
                "properties": {
                    "cx": {"type": "number", "description": "Center X coordinate"},
                    "cy": {"type": "number", "description": "Center Y coordinate"},
                    "radius": {"type": "number", "description": "Circle radius"},
                    "layer": {"type": "string", "description": "Target layer name"},
                },
                "required": ["cx", "cy", "radius"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "create_line",
            "description": "Draw a 2D line segment between two points in AutoCAD.",
            "parameters": {
                "type": "object",
                "properties": {
                    "x1": {"type": "number"},
                    "y1": {"type": "number"},
                    "x2": {"type": "number"},
                    "y2": {"type": "number"},
                    "layer": {"type": "string"},
                },
                "required": ["x1", "y1", "x2", "y2"],
            },
        },
    },
]
