# Import necessary modules from pyrx
from pyrx import Ap, Db, Ed, Ge
import traceback  # For detailed error tracing


def orthogonalize_points(in_points):
    """
    Corrects non-orthogonal interior points while preserving X/Y direction changes.
    
    First and last points are left unchanged because they're typically part of the 
    boundary or have special meaning.

    Args:
        points (list): List of Ge.Point2d objects representing polyline vertices

    Returns:
        list: New list of corrected points where corners form right angles
    """
    # If there are fewer than 3 points, nothing to orthogonalize
    if len(in_points) < 3:
        return in_points

    # Iterate through all interior vertices (excluding first and last)
    for i in range(1, len(in_points) - 1):
        p0 = in_points[i - 1]   # Previous point
        p1 = in_points[i]       # Current point being adjusted
        p2 = in_points[i + 1]   # Next point

        v_in = p1 - p0       # Vector from previous to current
        v_out = p2 - p1      # Vector from current to next

        # Determine if incoming vector is more horizontal than vertical
        in_is_h = abs(v_in.x) >= abs(v_in.y)
        # Determine if outgoing vector is more horizontal than vertical
        out_is_h = abs(v_out.x) >= abs(v_out.y)

        # Case 1: Proper corner (one horizontal, one vertical)
        # e.g., right-angle turn from vertical to horizontal or vice versa
        if in_is_h != out_is_h:
            if in_is_h:
                # Incoming vector is horizontal → outgoing must be vertical
                new_x = p2.x    # Keep x of next point (vertical move)
                new_y = p0.y    # Keep y of previous point (horizontal move)
            else:
                # Incoming vector is vertical → outgoing must be horizontal
                new_x = p0.x    # Keep x of previous point (horizontal move)
                new_y = p2.y    # Keep y of next point (vertical move)

        # Case 2: Both vectors are horizontal → align Y with the incoming segment
        elif in_is_h:
            new_x = p1.x    # Preserve current X coordinate
            new_y = p0.y    # Align Y with previous point

        # Case 3: Both vectors are vertical → align X with the incoming segment
        else:
            new_x = p0.x    # Align X with previous point
            new_y = p1.y    # Preserve current Y coordinate

        # Set corrected vertex position
        in_points[i] = Ge.Point2d(new_x, new_y)

    return in_points


@Ap.Command()
def doit():
    """
    Main command function that prompts the user to select a polyline,
    orthogonalizes its vertices, and creates a new one in model space.
    """
    try:
        # Prompt user to select a polyline entity
        ps, pid, pnt = Ed.Editor.entSel("\nSelect a polyline", Db.Polyline.desc())
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))

        # Get the original selected polyline and create a copy
        original_pline = Db.Polyline(pid)
        copy_pline = Db.Polyline()
        copy_pline.copyFrom(original_pline)  # Copy properties from original
        copy_pline.reset(True, original_pline.numVerts())  # Reset vertex count

        # Orthogonalize the points and add them to the new polyline
        for idx, pnt in enumerate(orthogonalize_points(original_pline.toPoint2dList())):
            copy_pline.addVertexAt(idx, pnt)

        # Add the corrected polyline to model space
        db = Db.curDb()
        db.addToModelspace(copy_pline)

    except Exception:
        # Print full traceback in case of any error
        print(traceback.format_exc())
