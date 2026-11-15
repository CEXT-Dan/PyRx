# --- CAD Tools ---
# Tool implementations and LM Studio / OpenAI tool schemas.
# These run inside the AutoCAD application context via dispatch_to_acad().

import math

from pyrx import Db, Ge


def get_drawing_info():
    db = Db.curDb()
    ms = Db.BlockTableRecord(db.currentSpaceId(), Db.OpenMode.kForRead)
    entity_counts = {}
    for obj_id in ms.objectIds():
        ent = Db.Entity(obj_id)
        etype = ent.isA().name()
        entity_counts[etype] = entity_counts.get(etype, 0) + 1
    return {"modelspace_entity_counts": entity_counts}


def create_layer(layer: str, color: str):
    db = Db.curDb()
    lt = Db.LayerTable(db.layerTableId(), Db.OpenMode.kForWrite)
    if lt.has(layer):
        obj_id = lt.getAt(layer)
        return {
            "status": "created",
            "type": "Layer",
            "handle": str(obj_id.handle()),
        }
    ltr = Db.LayerTableRecord()
    obj_id = lt.add(ltr)
    ltr.setName(layer)
    ltr.setColor(Db.Color(color))
    return {"status": "created", "type": "Layer", "handle": str(obj_id.handle())}


def create_circle(cx: float, cy: float, radius: float, layer: str = "0"):
    db = Db.curDb()
    circle = Db.Circle(Ge.Point3d(cx, cy, 0.0), Ge.Vector3d.kZAxis, radius)
    circle.setLayer(layer)
    obj_id = db.addToCurrentspace(circle)
    return {"status": "created", "type": "Circle", "handle": str(obj_id.handle())}


def create_line(x1: float, y1: float, x2: float, y2: float, layer: str = "0"):
    db = Db.curDb()
    line = Db.Line(Ge.Point3d(x1, y1, 0.0), Ge.Point3d(x2, y2, 0.0))
    line.setLayer(layer)
    obj_id = db.addToCurrentspace(line)
    return {"status": "created", "type": "Line", "handle": str(obj_id.handle())}


def create_polyline(
    points: list[tuple[float, float]],
    closed: bool = False,
    layer: str = "0",
):
    if len(points) < 2:
        raise ValueError("A polyline needs at least two (x, y) points.")

    db = Db.curDb()
    polyline = Db.Polyline([(float(x), float(y)) for x, y in points])
    polyline.setClosed(bool(closed))
    polyline.setLayer(layer)
    obj_id = db.addToCurrentspace(polyline)
    return {
        "status": "created",
        "type": "Polyline",
        "handle": str(obj_id.handle()),
        "num_vertices": len(points),
        "closed": bool(closed),
    }


def create_arc(
    cx: float,
    cy: float,
    radius: float,
    start_angle: float,
    end_angle: float,
    layer: str = "0",
):
    r = float(radius)
    if r <= 0.0:
        raise ValueError("Radius must be positive.")

    db = Db.curDb()
    arc = Db.Arc(
        Ge.Point3d(float(cx), float(cy), 0.0),
        r,
        math.radians(start_angle),
        math.radians(end_angle),
    )
    arc.setLayer(layer)
    obj_id = db.addToCurrentspace(arc)
    return {"status": "created", "type": "Arc", "handle": str(obj_id.handle())}


def create_dimension(
    x1: float,
    y1: float,
    x2: float,
    y2: float,
    dim_line_point_x: float,
    dim_line_point_y: float,
    layer: str = "0",
):
    db = Db.curDb()
    xl1 = Ge.Point3d(float(x1), float(y1), 0.0)
    xl2 = Ge.Point3d(float(x2), float(y2), 0.0)
    dim_pt = Ge.Point3d(float(dim_line_point_x), float(dim_line_point_y), 0.0)

    dim = Db.AlignedDimension(xl1, xl2, dim_pt)

    dim.setLayer(layer)
    obj_id = db.addToCurrentspace(dim)
    return {
        "status": "created",
        "type": "AlignedDimension",
        "handle": str(obj_id.handle()),
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
    "get_drawing_info": get_drawing_info,
    "create_layer": create_layer,
    "create_polyline": create_polyline,
    "create_cylinder": create_cylinder,
    "create_circle": create_circle,
    "create_line": create_line,
    "create_arc": create_arc,
    "create_dimension": create_dimension,
}

TOOL_SCHEMAS = [
    {
        "type": "function",
        "function": {
            "name": "create_layer",
            "description": (
                "Create a named layer in the active AutoCAD drawing. "
                "It is safe to call this tool if the layer already exists: the existing layer will simply be returned. "
                "Use an HTML color for the color argument, e.g. '#FF0000' or '#336699'."
            ),
            "parameters": {
                "type": "object",
                "properties": {
                    "layer": {"type": "string", "description": "Layer name to create"},
                    "color": {
                        "type": "string",
                        "description": "Layer color as an HTML color code, e.g. '#FF0000' or '#336699'",
                    },
                },
                "required": ["layer", "color"],
            },
        },
    },
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
            "name": "create_arc",
            "description": (
                "Draw a 2D circular arc in AutoCAD modelspace. "
                "(cx, cy) is the center of the arc. Angles are in degrees, measured "
                "counterclockwise from the positive X axis (0 degrees points along +X). "
                "The arc is swept counterclockwise from start_angle to end_angle; "
                "end_angle may be less than start_angle, in which case it wraps around 360 degrees."
            ),
            "parameters": {
                "type": "object",
                "properties": {
                    "cx": {"type": "number", "description": "Center X coordinate"},
                    "cy": {"type": "number", "description": "Center Y coordinate"},
                    "radius": {"type": "number", "description": "Arc radius"},
                    "start_angle": {"type": "number", "description": "Start angle in degrees, counterclockwise from +X"},
                    "end_angle": {"type": "number", "description": "End angle in degrees, counterclockwise from +X"},
                    "layer": {"type": "string", "description": "Target layer name"},
                },
                "required": ["cx", "cy", "radius", "start_angle", "end_angle"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "create_dimension",
            "description": (
                "Add an aligned linear dimension in AutoCAD modelspace. "
                "The dimension measures the true distance between the two points (x1, y1) and (x2, y2), "
                "and the dimension line runs parallel to the line connecting those two points. "
                "(dim_line_point_x, dim_line_point_y) is a point the dimension line passes through, "
                "controlling where the dimension is placed relative to the measured points. "
                "AutoCAD displays the measured distance as the dimension text."
            ),
            "parameters": {
                "type": "object",
                "properties": {
                    "x1": {"type": "number", "description": "First extension-line point X"},
                    "y1": {"type": "number", "description": "First extension-line point Y"},
                    "x2": {"type": "number", "description": "Second extension-line point X"},
                    "y2": {"type": "number", "description": "Second extension-line point Y"},
                    "dim_line_point_x": {"type": "number", "description": "X of a point the dimension line passes through (controls placement)"},
                    "dim_line_point_y": {"type": "number", "description": "Y of a point the dimension line passes through (controls placement)"},
                    "layer": {"type": "string", "description": "Target layer name"},
                },
                "required": ["x1", "y1", "x2", "y2", "dim_line_point_x", "dim_line_point_y"],
            },
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
