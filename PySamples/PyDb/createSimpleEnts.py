"""
PyRx Command Module for Creating Basic Geometric Entities.

This module provides several AutoCAD commands that demonstrate how to create 
basic geometric entities (lines, circles, polylines) in AutoCAD/BricsCAD using PyRx.
Each command creates a different type of entity with specific properties and 
adds it to the current drawing's model space.

Commands:
    pycreate_line - Creates a colored line from (0,0,0) to (100,100,0)
    pycreate_circle - Creates a colored circle centered at (100,100,0) with radius 10
    pycreate_polyline - Creates a colored closed polyline with specified vertices

Functions:
    pycreate_line() -> None
        Creates and adds a line entity to the current drawing's model space
        
    pycreate_circle() -> None
        Creates and adds a circle entity to the current drawing's model space
        
    PyRxCmd_pycreate_polyline() -> None
        Creates and adds a closed polyline entity to the current drawing's model space

Example usage:
    Run any of the commands in AutoCAD/BricsCAD command line:
    - Type 'pycreate_line' then press Enter
    - Type 'pycreate_circle' then press Enter  
    - Type 'pycreate_polyline' then press Enter
"""

from pyrx import Ap, Db, Ge

print("added command - pycreate_line")
print("added command - pycreate_circle")
print("added command - pycreate_polyline")


# define a command
@Ap.Command()
def pycreate_line() -> None:
    """
    Creates and adds a colored line to the current drawing's model space.

    This function demonstrates creating a simple line entity with:
    - Start point at (0, 0, 0)
    - End point at (100, 100, 0)
    - Yellow color (RGB: 255, 255, 0)

    The line is created using the database's addToModelspace helper method
    which handles opening and closing of entities properly.

    Example usage:
        In AutoCAD/BricsCAD command line, type 'pycreate_line' then press Enter.
    """
    try:
        db = Db.curDb()

        # create a line entity
        line = Db.Line()
        line.setDatabaseDefaults()

        # use Ge point to set start and end points
        line.setStartPoint(Ge.Point3d(0, 0, 0))
        line.setEndPoint(Ge.Point3d(100, 100, 0))

        # set a yellow color (RGB: 255, 255, 0)
        color = Db.Color()
        color.setRGB(255, 255, 0)
        line.setColor(color)

        # helper method to add the line directly to modelspace
        db.addToModelspace(line)
        # python garbage collects here, line and model will be closed or deleted
        # automatically after this scope

    except Exception as err:
        print(err)


# define a command
@Ap.Command()
def pycreate_circle() -> None:
    """
    Creates and adds a colored circle to the current drawing's model space.

    This function demonstrates creating a circle entity with:
    - Center point at (100, 100, 0)
    - Radius of 10 units
    - Cyan color (RGB: 0, 255, 255)

    The circle is created by manually opening the model space record for writing
    and appending the entity directly.

    Example usage:
        In AutoCAD/BricsCAD command line, type 'pycreate_circle' then press Enter.
    """
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()

        # create a circle entity
        circle = Db.Circle()
        circle.setDatabaseDefaults()

        # use Ge point to set center and define radius
        circle.setCenter(Ge.Point3d(100, 100, 0))
        circle.setRadius(10)

        # set a cyan color (RGB: 0, 255, 255)
        color = Db.Color()
        color.setRGB(0, 255, 255)
        circle.setColor(color)

        # open modelspace for write and add the entity
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(circle)

        # python garbage collects here, circle and model will be closed or deleted
        # automatically after this scope

    except Exception as err:
        print(err)


# old way to define a command (using PyRxCmd naming convention)
def PyRxCmd_pycreate_polyline() -> None:
    """
    Creates and adds a colored closed polyline to the current drawing's model space.

    This function demonstrates creating a polyline entity with:
    - Four vertices forming a square
    - Bulge at vertex 2 for curved edge
    - Closed polygon (first and last points connected)
    - Magenta color (RGB: 255, 0, 255)

    The polyline is created by manually opening the model space record for writing
    and appending the entity directly.

    Example usage:
        In AutoCAD/BricsCAD command line, type 'pycreate_polyline' then press Enter.
    """
    try:
        # get the working database, database is also a property of Document
        db = Db.HostApplicationServices().workingDatabase()

        # create a Polyline with 4 vertices
        pline = Db.Polyline(4)
        pline.setDatabaseDefaults()

        # add vertices using zero-based indexing (2D points)
        pline.addVertexAt(0, Ge.Point2d(0, 0))
        pline.addVertexAt(1, Ge.Point2d(100, 0))

        # add a bulge here to create curved edge
        pline.addVertexAt(2, Ge.Point2d(100, 100), 3, 0, 0)
        pline.addVertexAt(3, Ge.Point2d(0, 100))
        pline.setClosed(True)  # close the polyline

        # set a magenta color (RGB: 255, 0, 255)
        color = Db.Color()
        color.setRGB(255, 0, 255)
        pline.setColor(color)

        # open modelspace for write and add the entity
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(pline)

        # python garbage collects here, circle and model will be closed or deleted
        # automatically after this scope

    except Exception as err:
        print(err)
