"""
PyRx Command Module for Dimensional Association and Leader Creation.

This module provides several AutoCAD commands related to dimension association,
reading associations, removing associations, and creating leaders with
associative behavior using PyRx (Python for AutoCAD).

Commands:
    pydimassoc     - Creates a dimension associated with two endpoints of a line.
    pydimassocread - Reads the associative references of a selected dimension.
    pyremdimassoc  - Removes all association from a selected dimension.
    assocleader    - Creates an MLeader that associates to a point on a line.

Functions:
    makeLine(db: Db.Database) -> Db.ObjectId
        Helper function to create and add a line entity to the modelspace.
    
    makeLeader(db: Db.Database) -> Db.ObjectId
        Helper function to create and add an MLeader with associated text to the modelspace.
"""

import traceback

from pyrx import Ap, Db, Ed, Ge


print("added command pydimassoc")
print("added command pydimassocread")
print("added command pyremdimassoc")
print("added command assocleader")


@Ap.Command()
def pydimassoc() -> None:
    """
    Creates a dimension associated with two endpoints of a line using associative references.

    This function creates a line, a dimension aligned to that line,
    and then associates the dimension points to specific subentities
    (start/end) of the line via osnap references.

    Example usage in AutoCAD:
        Run 'pydimassoc' command.
    """
    try:
        # Define three 3D points for geometry creation
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(15, 0, 0)
        pt3 = Ge.Point3d(5, 5, 0)

        # Get current database and open model space for writing
        db = Db.curDb()
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.kForWrite)

        # Create a line between pt1 and pt2
        line = Db.Line(pt1, pt2)
        line.setDatabaseDefaults()
        lineid = model.appendAcDbEntity(line)
        line.close()

        # Create an aligned dimension using the points
        dim = Db.AlignedDimension(pt1, pt2, pt3)
        dim.setDatabaseDefaults()
        dimId = model.appendAcDbEntity(dim)
        dim.close()

        # Set up osnap references to associate dimension endpoints with line subentities
        ref1 = Db.OsnapPointRef(pt1)
        ref1.setOsnapType(Db.OsnapType.kOsnapStart)
        ref1.setIdPath(lineid, Db.SubentType.kEdgeSubentType, 0)

        ref2 = Db.OsnapPointRef(pt2)
        ref2.setOsnapType(Db.OsnapType.kOsnapEnd)
        ref2.setIdPath(lineid, Db.SubentType.kEdgeSubentType, 0)

        # Create and configure the dimension association
        dimAssoc = Db.DimAssoc()
        dimAssoc.setDimObjId(dimId)
        dimAssoc.setPointRef(Db.DimAssocPointType.kXline1Point, ref1)
        dimAssoc.setPointRef(Db.DimAssocPointType.kXline2Point, ref2)
        dimAssoc.updateDimension()

        # Post the association to database
        dimAssoc.post(dimId)

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def pydimassocread() -> None:
    """
    Reads and prints the osnap point references of a selected dimension.

    Prompts user to select a dimension, then retrieves its associated objects
    (specifically the osnap point refs) and logs their coordinates.

    Example usage in AutoCAD:
        Run 'pydimassocread' command, then pick a dimension.
    """
    try:
        # Prompt user to select a dimension entity
        res = Ed.Editor.entSel("\nPick a dim", Db.Dimension.desc())
        if res[0] != Ed.PromptStatus.eOk:
            return

        # Get the associated ID of the selected dimension
        assocId = Db.Core.getDimAssocId(res[1])
        dimAssoc = Db.DimAssoc(assocId)

        # Retrieve the osnap references for both lines (Xline1 and Xline2)
        ref1 = dimAssoc.osnapPointRef(Db.DimAssocPointType.kXline1Point)
        ref2 = dimAssoc.osnapPointRef(Db.DimAssocPointType.kXline2Point)

        print(ref1.point(), ref2.point())

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def pyremdimassoc() -> None:
    """
    Removes all associative behavior from a selected dimension.

    Allows the user to remove dimensional associations so that modifications
    do not affect underlying geometry anymore.

    Example usage in AutoCAD:
        Run 'pyremdimassoc' command, then select a dimension.
    """
    try:
        # Prompt user to pick a dimension
        res = Ed.Editor.entSel("\nPick a dim", Db.Dimension.desc())
        if res[0] != Ed.PromptStatus.eOk:
            return

        # Get the associated ID and open it for write access
        assocId = Db.Core.getDimAssocId(res[1])
        dimAssoc = Db.DimAssoc(assocId, Db.OpenMode.ForWrite)

        # Remove all associativity from this dimension
        dimAssoc.removeAssociativity()

    except Exception as err:
        traceback.print_exception(err)


# ------------------------------------------
# Leader related functions


def makeLeader(db: Db.Database) -> Db.ObjectId:
    """
    Creates an MLeader with associated text in the given database.

    Args:
        db (Db.Database): The current AutoCAD database to add entities into.

    Returns:
        Db.ObjectId: The ObjectId of the newly created MLeader.
    """
    # Create MText content
    mtext = Db.MText()
    mtext.setDatabaseDefaults()
    mtext.setLocation(Ge.Point3d(120, 102.5, 0))
    mtext.setContents("what we have, is failure to communicate")

    # Initialize and configure the MLeader object
    leader = Db.MLeader()
    leader.setDatabaseDefaults()
    leader.setContentType(Db.MLeaderContentType.kMTextContent)
    leader.setMText(mtext)

    # Add a leader line with vertex points
    idx = leader.addLeaderLine(Ge.Point3d(100, 100, 0))
    leader.addFirstVertex(idx, Ge.Point3d(50, 0, 0))

    return db.addToModelspace(leader)


def makeLine(db: Db.Database) -> Db.ObjectId:
    """
    Creates a simple line in the given database.

    Args:
        db (Db.Database): The current AutoCAD database to add entities into.

    Returns:
        Db.ObjectId: The ObjectId of the newly created Line.
    """
    # Create and return a line from origin to 100 units along X-axis
    line = Db.Line(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
    return db.addToModelspace(line)


@Ap.Command()
def assocleader() -> None:
    """
    Creates a leader (MLeader) associated with a point on a line.

    This command demonstrates how to create an MLeader that is linked
    to a specific subentity of a line using osnap references.

    Example usage in AutoCAD:
        Run 'assocleader' command.
    """
    try:
        # Get current database and create required entities
        db = Db.curDb()
        lid = makeLeader(db)
        lineid = makeLine(db)

        # Define an osnap reference to associate leader to a midpoint of the line
        oref = Db.OsnapPointRef(Ge.Point3d(50, 0, 0))
        oref.setOsnapType(Db.OsnapType.kOsnapMid)
        oref.setIdPath(lineid, Db.SubentType.kEdgeSubentType, 0)

        # Create and configure the association between leader and line
        dimAssoc = Db.DimAssoc()
        dimAssoc.setDimObjId(lid)
        dimAssoc.setPointRef(Db.DimAssocPointType.kLeaderPoint, oref)
        dimAssoc.post(lid)

    except Exception as err:
        traceback.print_exception(err)
