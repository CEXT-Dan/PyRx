"""
PyRx AutoCAD Command Module for Spatial Filter Creation

This module demonstrates how to create and apply spatial filters to block references
in AutoCAD using PyRx. The implementation shows how to:
1. Select a block reference
2. Define a 2D area in model space
3. Create a spatial filter based on that area
4. Apply the filter to the selected block reference

The spatial filter restricts the visibility of the block's contents within specified boundaries,
which is useful for creating viewports, clipping regions, or controlling what parts of a block
are displayed.

Functions:
    addFilter_getmat: Helper function to add filter and return transformation matrix
    doit: Main command that performs the spatial filtering operation

Constants:
    ACDB_INFINITE_XCLIP_DEPTH: Defines infinite depth for xclip operations
"""

from pyrx import Ap, Db, Ed, Ge

# Constant defining infinite depth for extended clipping operations
ACDB_INFINITE_XCLIP_DEPTH = 1.0e300


def addFilter_getmat(refid, filter):
    """
    Add a spatial filter to a block reference and return its transformation matrix.
    
    This helper function takes a block reference ID and a spatial filter object,
    adds the filter to the block reference, and returns the block's transformation
    matrix for coordinate system conversions.
    
    Args:
        refid: The database ID of the block reference
        filter: A Db.SpatialFilter object to be added to the block reference
        
    Returns:
        Ge.Matrix3d: The transformation matrix of the block reference
        
    Note:
        This function opens the block reference in write mode to modify it,
        then retrieves and returns its transformation matrix.
    """
    ref = Db.BlockReference(refid, Db.OpenMode.kForWrite)
    Db.IndexFilterManager.addFilter(ref, filter)
    return ref.blockTransform()


@Ap.Command()
def doit():
    """
    Create a spatial filter for a selected block reference based on user-defined area.
    
    This command performs the following operations:
    1. Prompts user to select a block reference
    2. Gets lower left corner point from user
    3. Gets top right corner point from user (using getCorner for convenience)
    4. Creates a spatial filter using the defined rectangle area
    5. Applies the filter to the selected block reference
    
    The spatial filter uses the two points to define a rectangular clipping region
    in the XY plane, with infinite depth and elevation based on current drawing settings.
    
    Usage:
        Command line: doit
        Steps:
            1. Select block reference
            2. Specify lower left corner point
            3. Specify top right corner point (automatically uses getCorner)
            
    Expected Behavior:
        - Creates a rectangular spatial filter in model space
        - Applies the filter to selected block reference
        - Filter affects visibility within specified boundaries
        
    Error Handling:
        - Catches and prints any exceptions during execution
        - Handles selection errors gracefully with RuntimeError exceptions
        
    Example Workflow:
        Command line: doit
        Select: [block reference selection]
        Get lower left: [point coordinates]
        Get top right: [point coordinates]
        
    Notes:
        - Uses Db.SpatialFilter for 2D area-based clipping
        - Converts 3D points to 2D using transformation matrix
        - Applies infinite depth for z-axis clipping (no depth limitations)
        - Uses current drawing elevation as reference plane
        
    Requirements:
        - AutoCAD must have a valid drawing database context
        - User must select a valid block reference entity
        - Points should define a valid rectangle in model space
    """
    try:
        db = Db.curDb()

        # Select the block reference to apply filter to
        ps, refid, _ = Ed.Editor.entSel("\nSelect ", Db.BlockReference.desc())
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))

        # Get lower left corner point from user
        ps, pt1 = Ed.Editor.getPoint("\nGet lower left: ")
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("GetPoint Error! {}: ".format(ps))

        # Get top right corner point (uses getCorner for rectangular input)
        ps, pt2 = Ed.Editor.getCorner(pt1, "\nGet top right: ")
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("GetPoint Error! {}: ".format(ps))

        # Create spatial filter and get transformation matrix
        filter = Db.SpatialFilter()
        mat = addFilter_getmat(refid, filter)

        # Transform points to block coordinate system and convert to 2D
        pts2d = []
        for pt in [pt1, pt2]:
            pt.transformBy(mat)
            pts2d.append(Ge.Point2d(pt.x, pt.y))

        # Set the spatial filter definition with infinite depth
        filter.setDefinition(
            pts2d,
            Ge.Vector3d.kZAxis,
            db.elevation(),
            ACDB_INFINITE_XCLIP_DEPTH,
            -ACDB_INFINITE_XCLIP_DEPTH,
            True,
        )

    except Exception as err:
        # Print any errors that occur during execution
        print(err)
