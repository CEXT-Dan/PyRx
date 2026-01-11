import traceback
from pyrx import Ap, Db, Ge


def create_line(db: Db.Database) -> Db.ObjectId:
    """
    Creates a line entity in the given database.
    
    Args:
        db (Db.Database): The AutoCAD database to add the line to.

    Returns:
        Db.ObjectId: The ObjectId of the newly created line.
    """
    # Create a Line object between two 3D points
    line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
    
    # Set default properties for this database
    line.setDatabaseDefaults(db)
    
    # Set color index to red (index 1)
    line.setColorIndex(1)
    
    # Add the line to model space and return its ObjectId
    return db.addToModelspace(line)


def create_arc(db: Db.Database) -> Db.ObjectId:
    """
    Creates an arc entity in the given database.
    
    Args:
        db (Db.Database): The AutoCAD database to add the arc to.

    Returns:
        Db.ObjectId: The ObjectId of the newly created arc.
    """
    # Define a circular arc using three points
    gearc = Ge.CircArc3d(
        Ge.Point3d(0, 50, 0),   # Start point
        Ge.Point3d(50, 100, 0), # Middle point
        Ge.Point3d(100, 50, 0)  # End point
    )
    
    # Create an Arc object using center, radius, start angle and end angle from the circular arc
    arc = Db.Arc(gearc.center(), gearc.radius(), gearc.startAng(), gearc.endAng())
    
    # Set default properties for this database
    arc.setDatabaseDefaults(db)
    
    # Set color index to yellow (index 2)
    arc.setColorIndex(2)
    
    # Add the arc to model space and return its ObjectId
    return db.addToModelspace(arc)


def create_ployline(db: Db.Database) -> Db.ObjectId:
    """
    Creates a closed polyline entity in the given database.
    
    Args:
        db (Db.Database): The AutoCAD database to add the polyline to.

    Returns:
        Db.ObjectId: The ObjectId of the newly created polyline.
    """
    # Define list of points for the polyline
    pnts = [
        Ge.Point3d(0, 0, 0),
        Ge.Point3d(100, 0, 0),
        Ge.Point3d(100, 100, 0),
        Ge.Point3d(0, 100, 0),
    ]
    
    # Create a Polyline object from the list of points
    pline = Db.Polyline(pnts)
    
    # Set default properties for this database
    pline.setDatabaseDefaults(db)
    
    # Close the polyline to form a rectangle
    pline.setClosed(True)
    
    # Set color index to blue (index 3)
    pline.setColorIndex(3)
    
    # Add the polyline to model space and return its ObjectId
    return db.addToModelspace(pline)


def check_types(ids: list[Db.ObjectId]):
    """
    Checks and prints the type of each object identified by its ObjectId.
    
    Args:
        ids (list[Db.ObjectId]): List of ObjectIds representing AutoCAD entities.
    """
    for id in ids:
        if id.isDerivedFrom(Db.Line.desc()):
            print("Line")
        elif id.isDerivedFrom(Db.Arc.desc()):
            print("Arc")
        elif id.isDerivedFrom(Db.Polyline.desc()):
            print("Polyline")


def play_with_curves(ids: list[Db.ObjectId]):
    """
    Demonstrates object-oriented programming using inheritance.
    
    In AutoCAD's database structure, Line, Arc, and Polyline are all derived
    classes from the base Curve class. This function shows how we can use
    polymorphism to treat different curve types uniformly through their 
    shared base class interface.
    
    For each ObjectId that represents a Curve (which includes Line, Arc, and Polyline),
    this function:
    1. Opens as base Curve type using Db.Curve(id)
    2. Retrieves the end parameter value
    3. Calculates and prints the distance at that end parameter
    
    This approach allows us to write generic code that works with any curve-derived object,
    regardless of its specific type - showcasing proper OOP design principles.
    
    Args:
        ids (list[Db.ObjectId]): List of ObjectIds representing AutoCAD entities that are curves.
    """
    for id in ids:
        # Check if the ObjectId represents a Curve (base class)
        # All of Line, Arc, and Polyline inherit from Curve
        if id.isDerivedFrom(Db.Curve.desc()):
            # Open as a Curve type - this is polymorphism in action!
            # Even though we have different object types (Line, Arc, Polyline),
            # they can all be treated as Curve objects through their common interface
            curve = Db.Curve(id)
            
            # Get the end parameter value of any curve
            ep = curve.getEndParam()
            
            # Calculate and print the distance at that end parameter
            # This works for ANY curve type because Curve base class defines this method
            print(curve.getDistAtParam(ep))


@Ap.Command()
def pyrx_curve():
    """
    Main command function called by AutoCAD.
    
    This function creates three geometric entities: a line, an arc,
    and a closed polyline. Then it checks their types and performs
    operations on any curve-like objects found in the list of ObjectIds.
    """
    try:
        # Get current AutoCAD database
        db = Db.curDb()

        # Create a list to store created object IDs
        ids: list[Db.ObjectId] = []
        
        # Add line, arc, and polyline to the model space
        ids.append(create_line(db))
        ids.append(create_arc(db))
        ids.append(create_ployline(db))

        # Print types of all objects
        check_types(ids)
        
        # Process curve-based entities using polymorphism
        # This demonstrates how all derived classes can be treated through base class interface
        play_with_curves(ids)

    except Exception as e:
        print(f"Error in doit(): {str(e)}")
        traceback.print_exc()
