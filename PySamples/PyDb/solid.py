"""
PyRx Solids Sample Module

This module demonstrates various 3D solid operations using PyRx, including:
- Creating boxes and projecting entities onto solids
- Revolving curves around axes to create 3D solids
- Extruding regions along paths or normal vectors
- Working with AutoCAD's database and block table records

Each function represents a different way to generate 3D solids in AutoCAD using PyRx:
- pyproject(): Projects a circle onto a solid box
- pyrevolve(): Revolves a curve around an axis to create a solid
- pyextrudepath(): Extrudes a region along a path curve
- pyextrude(): Extrudes a region along its normal vector

These commands are designed to be executed within AutoCAD's Python environment using PyRx.
They require proper database context and valid entity selections from the drawing.

Example usage in AutoCAD:
    Type 'pyproject', 'pyrevolve', 'pyextrudepath', or 'pyextrude' at the command line
    to execute each respective solid generation operation.

Dependencies:
    - pyrx (PyRx library for AutoCAD Python scripting)
"""

import math
from pyrx import Ap, Db, Ed, Ge

print("added command pyproject")
print("added command pyrevolve")
print("added command pyextrudepath")
print("added command pyextrude")


@Ap.Command()
def pyproject():
    """
    Demonstrates how to create a 3D solid box and project a circle onto it,
    then appends both entities to the model space.

    This command creates:
        - A 3D box using `createBox`.
        - A circle with specific position and normal vector.
        - Projects that circle onto the solid using `projectOnToSolid`.

    The resulting solid and projected entities are added to the current drawing's model space.
    
    Example usage in AutoCAD:
        Type 'pyproject' in command line to run this sample.

    Notes:
        This requires a valid database context (i.e., an open drawing).
    """
    try:
        # Create a 3D solid box with dimensions 20x20x1
        box = Db.Solid3d()
        box.setDatabaseDefaults()
        box.createBox(20.0, 20.0, 1.0)

        # Define a circle at specific point and orientation
        circle = Db.Circle(
            Ge.Point3d(3.0, 3.0, 7.0), 
            Ge.Vector3d(-0.537925, -0.651525, -0.534932), 
            1.0
        )

        # Project the circle onto the solid along a given direction (Z-axis)
        ents = box.projectOnToSolid(circle, Ge.Vector3d(0.0, 0.0, 1.0))

        # Get model space block table record and write to it
        model = Db.BlockTableRecord(Db.curDb().modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(box)

        # Append all projected entities (e.g., curves) to the drawing
        for e in ents:
            model.appendAcDbEntity(e)

        # Print mass properties of the solid
        print("Box Mass Properties:", box.getMassProp())

    except Exception as err:
        print(f"Error occurred: {err}")


@Ap.Command()
def pyrevolve():
    """
    Creates a 3D solid by revolving a selected curve around an axis defined by a line.

    Prompts the user to select:
        - Curve (to revolve).
        - Line (used as rotation axis).

    Uses `createRevolvedSolid` with default settings for twist and draft angles.
    
    Example usage in AutoCAD:
        Type 'pyrevolve' in command line to run this sample.

    Notes:
        Requires selection of a valid curve and line. The curve must be derived from Db.Curve,
        and the line from Db.Line.
    """
    try:
        # Prompt user for selecting the curve to revolve
        entsel = Ed.Editor.entSel("\nSelect curve to revolve: ")
        if entsel[0] != Ed.PromptStatus.eNormal:
            return
        if not entsel[1].isDerivedFrom(Db.Curve.desc()):
            print("Selected entity is not a valid curve.")
            return

        # Prompt user for selecting the axis line
        pathsel = Ed.Editor.entSel("\nSelect Line: ")
        if pathsel[0] != Ed.PromptStatus.eNormal:
            return
        if not pathsel[1].isDerivedFrom(Db.Line.desc()):
            print("Selected entity is not a valid line.")
            return

        # Cast selected entities into appropriate classes
        curve = Db.Curve(entsel[1])
        line = Db.Line(pathsel[1])

        # Set revolve options (default values used here)
        rob = Db.RevolveOptions()
        rob.setCloseToAxis(False)  # No closing of the solid if needed
        rob.setDraftAngle(0)       # No draft angle
        rob.setTwistAngle(0)       # No twist during revolution

        # Create revolved solid using start point and vector from line
        solid = Db.Solid3d()
        vec = line.getEndPoint() - line.getStartPoint()
        solid.createRevolvedSolid(curve, line.getStartPoint(), vec, math.pi * 2, 0, rob)

        # Add the generated solid to model space
        model = Db.BlockTableRecord(Db.curDb().modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(solid)

    except Exception as err:
        print(f"Error occurred: {err}")


@Ap.Command()
def pyextrudepath():
    """
    Extrudes a region along a specified path curve to generate a 3D solid.

    Prompts the user to select:
        - A curve (to be converted into a region).
        - A path curve (used for extrusion direction and shape).

    Uses `extrudeAlongPath` method which allows complex shapes via paths.

    Example usage in AutoCAD:
        Type 'pyextrudepath' in command line to run this sample.

    Notes:
        The selected curves must be valid. Also, the region creation from curve
        must succeed for the extrusion process.
    """
    try:
        # Prompt user for selecting the base curve
        entsel = Ed.Editor.entSel("\nSelect curve: ")
        if entsel[0] != Ed.PromptStatus.eNormal:
            return
        if not entsel[1].isDerivedFrom(Db.Curve.desc()):
            print("Selected entity is not a valid curve.")
            return

        # Prompt user for selecting the path
        pathsel = Ed.Editor.entSel("\nSelect path: ")
        if pathsel[0] != Ed.PromptStatus.eNormal:
            return
        if not pathsel[1].isDerivedFrom(Db.Curve.desc()):
            print("Selected entity is not a valid curve.")
            return

        # Convert selected curve into list of curves and create region(s)
        curves = []
        curve = Db.Curve(entsel[1])
        curves.append(curve)
        regions = Db.Region.createFromCurves(curves)

        if len(regions) == 0:
            print("Failed to create a valid region from the selected curve.")
            return

        # Get path and extrude along it
        path = Db.Curve(pathsel[1])
        solid = Db.Solid3d()
        solid.extrudeAlongPath(regions[0], path)

        # Add resulting solid to model space
        model = Db.BlockTableRecord(Db.curDb().modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(solid)

    except Exception as err:
        print(f"Error occurred: {err}")


@Ap.Command()
def pyextrude():
    """
    Extrudes a region in the direction of its normal by a specified distance.

    Prompts the user to select one curve, converts it into a region,
    and then extrudes that region along its normal vector.

    Example usage in AutoCAD:
        Type 'pyextrude' in command line to run this sample.

    Notes:
        The selected entity should be a valid curve.
    """
    try:
        # Prompt user for selecting the base curve
        entsel = Ed.Editor.entSel("Select curve: ")
        if entsel[0] != Ed.PromptStatus.eNormal:
            return
        if not entsel[1].isDerivedFrom(Db.Curve.desc()):
            print("Selected entity is not a valid curve.")
            return

        # Create region from the selected curve
        curves = []
        curve = Db.Curve(entsel[1])
        curves.append(curve)
        regions = Db.Region.createFromCurves(curves)

        if len(regions) == 0:
            print("Failed to create a valid region.")
            return

        # Extrude the region along its normal by specified distance (25.4 units)
        solid = Db.Solid3d()
        solid.extrude(regions[0], 25.4)

        # Add resulting solid to model space
        model = Db.BlockTableRecord(Db.curDb().modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(solid)

    except Exception as err:
        print(f"Error occurred: {err}")
