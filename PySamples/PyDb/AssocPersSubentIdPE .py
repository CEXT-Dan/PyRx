# Import the traceback module for detailed error information
import traceback

# Import PyRx modules for AutoCAD API functionality
from pyrx import Ap, Db, Ed, Ge

# Print confirmation that the command has been registered
print("added command pygetsubents")


@Ap.Command()
def pygetsubents():
    """
    Command function to extract subentities (vertices, edges, faces) from a picked entity.
    
    This function demonstrates how to:
    1. Prompt user to select an entity
    2. Access the selected entity's subentities using AssocPersSubentIdPE
    3. Extract and display vertex positions
    4. Extract and display edge geometry (start/end points)
    5. Extract and display surface information
    """
    try:
        # Prompt user to select an entity and get selection data
        # Returns: es (selection set), id (entity ID), pnt (pick point)
        es, id, pnt = Ed.Editor.entSel("\nPick it: \n")
        
        # Create an Entity object from the selected entity ID
        ent = Db.Entity(id)

        # Get the AssocPersSubentIdPE
        # This allows access to subentities of complex entities like 3D solids, surfaces, etc.
        pe = Db.AssocPersSubentIdPE(ent.queryX(Db.AssocPersSubentIdPE.desc()))

        # Extract and print all vertex subentities
        print("vertex")
        for vtx in pe.getAllSubentities(ent, Db.SubentType.kVertexSubentType):
            # Get the geometric position of each vertex
            pos = pe.getVertexSubentityGeometry(ent, vtx)
            print(pos)

        # Extract and print all edge subentities
        print("edge")
        for edge in pe.getAllSubentities(ent, Db.SubentType.kEdgeSubentType):
            # Get the curve geometry of each edge
            curve = pe.getEdgeSubentityGeometry(ent, edge)
            # Print start and end points of the edge
            print(curve.getStartPoint(), curve.getEndPoint())

        # Extract and print all face subentities (surfaces)
        print("surface")
        for face in pe.getAllSubentities(ent, Db.SubentType.kFaceSubentType):
            # Get the geometric surface representation
            gesurface: Ge.Surface = pe.getFaceSubentityGeometry(ent, face)
            print("Ge.Surface", gesurface)

            # Get the database surface version of the same face
            dbsurface = Db.Surface.cast(ent.subent(Db.FullSubentPath(id, face)))
            print("Db.Surface", dbsurface)

    except Exception as err:
        # Print detailed exception information including traceback
        # This helps with debugging by showing exactly where and why an error occurred
        traceback.print_exception(err)
