import traceback

from pyrx import Ap, Ge

print("added command xextrudededsolid")

@Ap.Command()
def xextrudededsolid() -> None:
    """
    Creates an extruded solid from a circle in AutoCAD using CAD-PyRx.
    
    This command performs the following operations:
    1. Gets references to the active AutoCAD application and model space
    2. Computes an extrusion direction vector from two points
    3. Creates a circle at a specified location with a given radius
    4. Sets the normal of the circle to align with the extrusion direction
    5. Creates a region from the circle
    6. Extrudes the region to create a solid with specified height
    7. Cleans up by erasing the original circle
    
    The resulting solid will be extruded along the computed vector direction.
    
    Example:
        In AutoCAD command line, type 'xextrudededsolid' and press Enter
        
    Returns:
        None: This function performs operations directly on the AutoCAD document
              and does not return any values
        
    Exceptions:
        Catches any exceptions that occur during execution and prints detailed
        error information using traceback.print_exception()
    """
    try:
        # Get references to AutoCAD application and active document
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axModel = axDoc.modelSpace()

        # Compute the extrusion direction vector from point (10, 0, 0) to (15, 20, 0)
        direction = Ge.Point3d(15, 20, 0) - Ge.Point3d(10, 0, 0)

        # Create a circle with center at (10, 0, 0) and radius of 5
        circle = axModel.addCircle(Ge.Point3d(10, 0, 0), 5)

        # Set the normal vector of the circle to match the extrusion direction
        # This ensures the circle is oriented correctly for extrusion
        circle.setNormal(direction)

        # Create a region from the circle (required for extrusion)
        regions = axModel.addRegion([circle])

        # Extrude the region to create a solid
        # Parameters: region object, extrusion height (length of direction vector), taper angle
        _solid = axModel.addExtrudedSolid(regions[0], direction.length(), 0.0)

        # Remove the original circle geometry as it's no longer needed
        circle.erase()

    except Exception as err:
        # Print detailed exception information for debugging
        traceback.print_exception(err)
