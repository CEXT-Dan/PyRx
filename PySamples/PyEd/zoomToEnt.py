"""
PyRx AutoCAD Command Module

This module provides two AutoCAD commands for zooming to selected entities:
- pyzoomx: Uses ActiveX interface (AxApp) for zoom operations
- pyzoom: Uses standard PyRx interface for zoom operations

Both commands select an entity and zoom the current view to fit the entity's extents.
"""

import traceback

from pyrx import Ap, Db, Ed, Ge

# Print registration messages for debugging purposes
print("added comand pyzoom")
print("added comand pyzoomx")

# Prefer this approach as it handles view directions better using ActiveX
@Ap.Command()
def pyzoomx() -> None:
    """
    PyRx command to zoom to selected entity using ActiveX interface.
    
    This function demonstrates the use of AutoCAD's ActiveX application object
    to perform zoom operations. It selects an entity, calculates its extents,
    and centers the view on that entity with appropriate zoom level.
    
    Usage:
        pyzoomx - Selects an entity and zooms to fit it in current view
        
    Example:
        Command line: pyzoomx
        Selection prompt: Select: [entity selection]
        
    ActiveX Approach:
        Uses Ap.Application.acadApplication() to access AutoCAD's COM interface
        Directly calls zoomCenter method for precise control over zoom operations
        
    Raises:
        RuntimeError: If entity selection fails or other errors occur during execution
    """
    try:
        # Get AutoCAD application instance using ActiveX
        axapp = Ap.Application.acadApplication()
        
        # Prompt user to select an entity
        ps, id, _ = Ed.Editor.entSel("\nSelect: ")
        
        # Check if selection was successful
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))
        
        # Get the selected entity and its geometric extents
        ent = Db.Entity(id)
        ext = ent.getGeomExtents()
        
        # Calculate dimensions for zoom operation
        v : Ge.Vector3d = ext.maxPoint() - ext.minPoint()
        
        # Use ActiveX method to zoom center on entity with calculated size
        axapp.zoomCenter(ext.midPoint(), v.length())

    except Exception as err:
        # Print exception details for debugging
        traceback.print_exception(err)


@Ap.Command()
def pyzoom() -> None:
    """
    PyRx command to zoom to selected entity using standard PyRx interface.
    
    This function uses the standard PyRx API to select an entity and adjust
    the current view to fit that entity's extents. It manually sets center point,
    width, and height of the view.
    
    Usage:
        pyzoom - Selects an entity and zooms to fit it in current view
        
    Example:
        Command line: pyzoom
        Selection prompt: Select: [entity selection]
        
    Standard PyRx Approach:
        Uses Ed.Core.getCurrentView() and Ed.Core.setCurrentView()
        Manually calculates view properties using geometric extents
        
    Raises:
        RuntimeError: If entity selection fails or other errors occur during execution
    """
    try:
        # Prompt user to select an entity
        ps, id, _ = Ed.Editor.entSel("\nSelect: ")
        
        # Check if selection was successful
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection Error! {}: ".format(ps))

        # Get the selected entity and its geometric extents
        ent = Db.Entity(id)
        ext = ent.getGeomExtents()
        
        # Calculate dimensions for zoom operation
        v : Ge.Vector3d = ext.maxPoint() - ext.minPoint()

        # Get current view and modify it to fit the entity
        view = Ed.Core.getCurrentView()
        view.setCenterPoint(Ge.Point2d(ext.midPoint().x, ext.midPoint().y))
        view.setWidth(v.length())
        view.setHeight(v.length())
        
        # Apply modified view back to AutoCAD
        Ed.Core.setCurrentView(view)

    except Exception as err:
        # Print exception details for debugging
        traceback.print_exception(err)
