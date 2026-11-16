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


def create_text(
    x: float,
    y: float,
    text: str,
    height: float = 1.0,
    rotation: float = 0.0,
    layer: str = "0",
):
    h = float(height)
    if h <= 0.0:
        raise ValueError("Text height must be positive.")

    db = Db.curDb()
    txt = Db.Text(Ge.Point3d(float(x), float(y), 0.0), str(text))
    txt.setHeight(h)
    txt.setRotation(math.radians(float(rotation)))
    txt.setLayer(layer)
    obj_id = db.addToCurrentspace(txt)
    return {
        "status": "created",
        "type": "Text",
        "handle": str(obj_id.handle()),
        "text": str(text),
        "height": h,
        "rotation": float(rotation),
    }


def create_cuboid(
    cx: float,
    cy: float,
    cz: float,
    x_len: float,
    y_len: float,
    z_len: float,
    rot_x: float = 0.0,
    rot_y: float = 0.0,
    rot_z: float = 0.0,
    layer: str = "0",
):
    xl, yl, zl = float(x_len), float(y_len), float(z_len)
    if xl <= 0.0 or yl <= 0.0 or zl <= 0.0:
        raise ValueError("x_len, y_len, and z_len must all be positive.")

    db = Db.curDb()
    solid = Db.Solid3d()
    solid.setDatabaseDefaults(db)
    solid.createBox(xl, yl, zl)

    rx = Ge.Matrix3d.rotation(math.radians(float(rot_x)), Ge.Vector3d.kXAxis, Ge.Point3d.kOrigin)
    ry = Ge.Matrix3d.rotation(math.radians(float(rot_y)), Ge.Vector3d.kYAxis, Ge.Point3d.kOrigin)
    rz = Ge.Matrix3d.rotation(math.radians(float(rot_z)), Ge.Vector3d.kZAxis, Ge.Point3d.kOrigin)

    translation = Ge.Matrix3d.translation(
        Ge.Point3d(float(cx), float(cy), float(cz)) - Ge.Point3d.kOrigin
    )

    # Apply X -> Y -> Z rotation around local center, then translate to (cx, cy, cz)
    transform = translation * rz * ry * rx
    solid.transformBy(transform)
    solid.setLayer(layer)

    obj_id = db.addToCurrentspace(solid)
    return {
        "status": "created",
        "type": "Solid3d",
        "handle": str(obj_id.handle()),
        "is_null": solid.isNull(),
        "dimensions": [xl, yl, zl],
    }


def create_cylinder(
    cx: float,
    cy: float,
    cz: float,
    radius: float,
    height: float,
    direction: tuple[float, float, float] | list[float] = (0.0, 0.0, 1.0),
    layer: str = "0",
):
    """Creates a 3D cylinder centered at (cx, cy, cz) aligned along `direction`."""
    r = float(radius)
    h = float(height)
    if r <= 0.0 or h <= 0.0:
        raise ValueError("Radius and height must be positive.")

    dx, dy, dz = (float(v) for v in direction)
    target_dir = Ge.Vector3d(dx, dy, dz)
    if target_dir.length() <= 0.0:
        raise ValueError("direction must be a non-zero vector.")
    target_dir.normalize()

    db = Db.curDb()
    solid = Db.Solid3d()
    solid.setDatabaseDefaults(db)
    # createFrustum builds a cylinder centered at (0,0,0) aligned with +Z
    solid.createFrustum(h, r, r, r)

    # Rotate +Z axis directly onto target_dir at the origin
    rotation = Ge.Vector3d.kZAxis.rotateTo(target_dir)
    translation = Ge.Matrix3d.translation(
        Ge.Point3d(float(cx), float(cy), float(cz)) - Ge.Point3d.kOrigin
    )

    # Rotate first (at origin), then translate to (cx, cy, cz)
    solid.transformBy(translation * rotation)
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
    "create_cuboid": create_cuboid,
    "create_circle": create_circle,
    "create_line": create_line,
    "create_arc": create_arc,
    "create_dimension": create_dimension,
    "create_text": create_text,
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
                "Create a 3D solid cylinder centered at (cx, cy, cz). "
                "The cylinder's height axis is aligned along the `direction` vector [dx, dy, dz]. "
                "For example, [0, 0, 1] creates a vertical cylinder along Z, [1, 0, 0] aligns it along X, "
                "and [1, 1, 0] tilts it diagonally at 45 degrees in the XY plane. "
                "The geometric center remains fixed at (cx, cy, cz)."
            ),
            "parameters": {
                "type": "object",
                "properties": {
                    "cx": {
                        "type": "number",
                        "description": "X coordinate of the cylinder's geometric center.",
                    },
                    "cy": {
                        "type": "number",
                        "description": "Y coordinate of the cylinder's geometric center.",
                    },
                    "cz": {
                        "type": "number",
                        "description": "Z coordinate of the cylinder's geometric center.",
                    },
                    "radius": {
                        "type": "number",
                        "description": "Radius of the cylinder (must be positive).",
                    },
                    "height": {
                        "type": "number",
                        "description": "Total length/height of the cylinder along its axis (must be positive).",
                    },
                    "direction": {
                        "type": "array",
                        "description": (
                            "3D direction vector [dx, dy, dz] along which the cylinder's axis points "
                            "(does not need to be normalized). Default [0, 0, 1] (vertical along Z)."
                        ),
                        "minItems": 3,
                        "maxItems": 3,
                        "items": {"type": "number"},
                    },
                    "layer": {
                        "type": "string",
                        "description": "CAD layer name. Default '0'.",
                    },
                },
                "required": ["cx", "cy", "cz", "radius", "height"],
            },
        },
    },
    {
        "type": "function",
        "function": {
            "name": "create_cuboid",
            "description": (
                "Create a 3D box (cuboid) solid centered at (cx, cy, cz). "
                "x_len, y_len, and z_len are the initial dimensions along the X, Y, and Z axes. "
                "Use rot_x, rot_y, and rot_z (in degrees) to rotate the box around its own center. "
                "Rotations are applied around the world X, then Y, then Z axes (extrinsic XYZ) "
                "before moving the center to (cx, cy, cz), so the center stays fixed at (cx, cy, cz)."
            ),
            "parameters": {
                "type": "object",
                "properties": {
                    "cx": {
                        "type": "number",
                        "description": "X coordinate of the box's geometric center.",
                    },
                    "cy": {
                        "type": "number",
                        "description": "Y coordinate of the box's geometric center.",
                    },
                    "cz": {
                        "type": "number",
                        "description": "Z coordinate of the box's geometric center.",
                    },
                    "x_len": {
                        "type": "number",
                        "description": "Box dimension along the X axis before rotation (must be positive).",
                    },
                    "y_len": {
                        "type": "number",
                        "description": "Box dimension along the Y axis before rotation (must be positive).",
                    },
                    "z_len": {
                        "type": "number",
                        "description": "Box dimension along the Z axis before rotation (must be positive).",
                    },
                    "rot_x": {
                        "type": "number",
                        "description": "Rotation angle in degrees around the X axis (roll/tilt forward-back). Default 0.",
                    },
                    "rot_y": {
                        "type": "number",
                        "description": "Rotation angle in degrees around the Y axis (pitch/tilt left-right). Default 0.",
                    },
                    "rot_z": {
                        "type": "number",
                        "description": "Rotation angle in degrees around the Z axis (yaw/spin in XY plane). Default 0.",
                    },
                    "layer": {
                        "type": "string",
                        "description": "CAD layer name. Default '0'.",
                    },
                },
                "required": ["cx", "cy", "cz", "x_len", "y_len", "z_len"],
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
                    "start_angle": {
                        "type": "number",
                        "description": "Start angle in degrees, counterclockwise from +X",
                    },
                    "end_angle": {
                        "type": "number",
                        "description": "End angle in degrees, counterclockwise from +X",
                    },
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
                    "dim_line_point_x": {
                        "type": "number",
                        "description": "X of a point the dimension line passes through (controls placement)",
                    },
                    "dim_line_point_y": {
                        "type": "number",
                        "description": "Y of a point the dimension line passes through (controls placement)",
                    },
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
    {
        "type": "function",
        "function": {
            "name": "create_text",
            "description": (
                "Add a single-line text entity in AutoCAD modelspace. "
                "(x, y) is the insertion point of the text. "
                "height is the text height in drawing units. "
                "rotation is the text rotation in degrees, counterclockwise from the positive X axis (default 0)."
            ),
            "parameters": {
                "type": "object",
                "properties": {
                    "x": {"type": "number", "description": "Insertion point X coordinate"},
                    "y": {"type": "number", "description": "Insertion point Y coordinate"},
                    "text": {"type": "string", "description": "Text string to display"},
                    "height": {
                        "type": "number",
                        "description": "Text height in drawing units. Must be positive. Default 1.0.",
                    },
                    "rotation": {
                        "type": "number",
                        "description": "Text rotation in degrees, counterclockwise from +X. Default 0.",
                    },
                    "layer": {"type": "string", "description": "Target layer name"},
                },
                "required": ["x", "y", "text"],
            },
        },
    },
]
