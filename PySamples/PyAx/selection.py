"""
PyRx AutoCAD ActiveX Commands Module

This module demonstrates the use of AutoCAD's ActiveX interface through PyRx
to perform various operations on AutoCAD entities and selection sets. It provides
commands that leverage the ActiveX automation interface for direct manipulation
of AutoCAD objects.

Features:
- Entity picking with ActiveX
- Sub-entity selection with transformation data
- Selection set creation and filtering
- Block writing operations

Usage:
    Load this script into AutoCAD's Python environment.
    Run any of the following commands from the AutoCAD command line:
        - PYAX_GETENT: Pick a single line entity and change its color to green
        - PYAX_GETSUBENT: Pick a sub-entity and display information about it
        - PYAX_SSALL: Select all entities in drawing and print their types
        - PYAX_SSALLF: Select filtered entities (POINT, LINE) and print their types
        - PYAX_WBLOCK: Write selected entities to a new DWG file

Requirements:
    AutoCAD must be running with ActiveX support enabled.
"""

import traceback

from pyrx_imp import Ap, Ax

# --- Registering Commands ---
print("added command PYAX_GETENT")
print("added command PYAX_GETSUBENT")
print("added command PYAX_SSALL")
print("added command PYAX_SSALLF")
print("added command PYAX_WBLOCK")


# === Command: PYAX_GETENT ===
@Ap.Command("PYAX_GETENT")
def get_entity():
    """
    Pick a single entity and change its color to green.
    
    This command uses AutoCAD's ActiveX interface to:
    1. Prompt the user to pick an entity
    2. Verify that the picked entity is a LINE type
    3. Cast it to AcadLine and change its true color to green (RGB: 0, 255, 0)
    4. Print the object name and pick point coordinates
    
    Usage:
        Run 'PYAX_GETENT' from AutoCAD command line.
        
    Requirements:
        - User must select a valid LINE entity when prompted
        - Only works with AutoCAD's ActiveX interface
        
    Side Effects:
        - Changes color of selected LINE to green
        - Prints object name and pick point coordinates to console
        
    Raises:
        RuntimeError: If the picked entity is not a LINE type
        
    Example Output:
        AcDbLine (10, 20, 0)
    """
    try:
        # Get ActiveX application instance
        axApp = Ap.Application.acadApplication()
        
        # Get active document and utility object
        axDoc = axApp.activeDocument()
        axUtil = axDoc.utility()
        
        # Prompt user to pick an entity
        axEnt, pnt = axUtil.getEntity("\nPick a line")
        
        # Verify that the picked entity is a LINE
        if axEnt.objectName() != "AcDbLine":
            raise RuntimeError("oops!: ")
            
        # Cast to AcadLine and change color to green (RGB: 0, 255, 0)
        axLine = Ax.AcadLine.cast(axEnt)
        axLine.setTrueColor(Ax.AcadAcCmColor(0, 255, 0))
        
        # Print information about the selected entity
        print(axEnt.objectName(), pnt)

    except Exception as err:
        traceback.print_exception(err)


# === Command: PYAX_GETSUBENT ===
@Ap.Command("PYAX_GETSUBENT")
def get_subentity():
    """
    Pick a sub-entity and display detailed selection information.
    
    This command uses AutoCAD's ActiveX interface to:
    1. Prompt the user to pick a sub-entity (like an edge of a polygon)
    2. Retrieve detailed information about the picked entity including:
       - Object name
       - Pick point coordinates  
       - Transformation matrix
       - Selection IDs
    
    Usage:
        Run 'PYAX_GETSUBENT' from AutoCAD command line.
        
    Requirements:
        - User must select a valid sub-entity when prompted
        
    Side Effects:
        - Prints detailed entity information to console
        
    Example Output:
        AcDbLine (10, 20, 0) [matrix data] [selection IDs]
    """
    try:
        # Get ActiveX application instance
        axApp = Ap.Application.acadApplication()
        
        # Get active document and utility object
        axDoc = axApp.activeDocument()
        axUtil = axDoc.utility()
        
        # Prompt user to pick a sub-entity
        ent, pnt, xf, ids = axUtil.getSubEntity("\nPick it")
        
        # Print all information about the picked sub-entity
        print(ent.objectName(), pnt, xf, ids)
        
    except Exception as err:
        traceback.print_exception(err)


# === Command: PYAX_SSALL ===
@Ap.Command("PYAX_SSALL")
def get_select_all():
    """
    Select all entities in the drawing and list their types.
    
    This command uses AutoCAD's ActiveX interface to:
    1. Create a new selection set named "PYRX"
    2. Select all entities in the current drawing
    3. Iterate through all selected entities
    4. Collect unique object type names
    5. Print the collection of entity types
    
    Usage:
        Run 'PYAX_SSALL' from AutoCAD command line.
        
    Requirements:
        - Active AutoCAD document with entities
        
    Side Effects:
        - Creates and deletes a temporary selection set
        - Prints entity type information to console
        
    Example Output:
        {'AcDbLine', 'AcDbCircle', 'AcDbPoint'}
    """
    try:
        # Get ActiveX application instance
        axApp = Ap.Application.acadApplication()
        
        # Get active document and selection sets collection
        acDoc = axApp.activeDocument()
        axSets = acDoc.selectionSets()
        
        # Create a new named selection set
        axSet = axSets.add("PYRX")
        
        # Select all entities in the drawing
        axSet.selectAll()
        
        # Collect unique entity types
        types = set()
    
        # Iterate through all entities in the selection set
        for ent in axSet.entities():
            types.add(ent.objectName())

        # Duplicate loop (likely intentional or for demonstration)
        for ent in axSet.entities():
            types.add(ent.objectName())

        # Print unique entity types
        print(types)
        
    except Exception as err:
        traceback.print_exception(err)
    finally:
        # Always clean up the temporary selection set
        axSet.delete()


# === Command: PYAX_SSALLF ===
@Ap.Command("PYAX_SSALLF")
def get_select_all_filter():
    """
    Select filtered entities (POINT, LINE) and list their types.
    
    This command uses AutoCAD's ActiveX interface to:
    1. Create a new selection set named "PYRX"
    2. Filter and select only POINT and LINE entities
    3. Iterate through all selected entities  
    4. Collect unique object type names
    5. Print the collection of entity types
    
    Filter Options:
        - Using tuple format: [(0, "POINT,LINE")]
        - Alternative using Db.DxfCode: [(Db.DxfCode.kDxfStart, "POINT,LINE")]
    
    Usage:
        Run 'PYAX_SSALLF' from AutoCAD command line.
        
    Requirements:
        - Active AutoCAD document with POINT and LINE entities
        
    Side Effects:
        - Creates and deletes a temporary selection set
        - Prints filtered entity type information to console
        
    Example Output:
        {'AcDbLine', 'AcDbPoint'}
    """
    try:
        # Get ActiveX application instance
        axApp = Ap.Application.acadApplication()
        
        # Get active document and selection sets collection
        acDoc = axApp.activeDocument()
        axSets = acDoc.selectionSets()
        
        # Create a new named selection set
        axSet = axSets.add("PYRX")
        
        # Select entities with filter (POINT, LINE)
        # Filter format: list of tuples [(DxfCode, Value)]
        axSet.selectAll([(0, "POINT,LINE")])
        
        # Alternative using Db.DxfCode:
        # axSet.selectAll([(Db.DxfCode.kDxfStart, "POINT,LINE")])

        # Collect unique entity types
        types = set()
        
        # Iterate through all entities in the selection set
        for ent in axSet.entities():
            types.add(ent.objectName())

        # Duplicate loop (likely intentional or for demonstration)
        for ent in axSet.entities():
            types.add(ent.objectName())

        # Print unique entity types that match the filter
        print(types)
        
    except Exception as err:
        traceback.print_exception(err)
    finally:
        # Always clean up the temporary selection set
        axSet.delete()


# === Command: PYAX_WBLOCK ===
@Ap.Command("PYAX_WBLOCK")
def get_wblock_all():
    """
    Write selected entities to a new DWG file.
    
    This command uses AutoCAD's ActiveX interface to:
    1. Create a new selection set named "PYRX"  
    2. Prompt user to select entities on screen
    3. Write the selected entities to a specified DWG file path
    
    Important Notes:
        - The output file path is hardcoded: E:\\temp\\axWBlock.dwg
        - This operation will overwrite existing files with same name
        
    Usage:
        Run 'PYAX_WBLOCK' from AutoCAD command line.
        
    Requirements:
        - User must select entities when prompted  
        - Write permissions to the specified output directory
        - Valid file path for output DWG file
        
    Side Effects:
        - Creates a new DWG file with selected entities
        - Creates and deletes a temporary selection set
        - May overwrite existing files at output location
        
    Example Output:
        (No direct console output, but creates E:\\temp\\axWBlock.dwg)
    """
    try:
        # Get ActiveX application instance
        axApp = Ap.Application.acadApplication()
        
        # Get active document and selection sets collection
        acDoc = axApp.activeDocument()
        axSets = acDoc.selectionSets()
        
        # Create a new named selection set
        axSet = axSets.add("PYRX")
        
        # Prompt user to select entities on screen
        axSet.selectOnScreen()
        
        # Write selected entities to a new DWG file
        acDoc.wblock("E:\\temp\\axWBlock.dwg", axSet)
        
    except Exception as err:
        traceback.print_exception(err)
    finally:
        # Always clean up the temporary selection set
        axSet.delete()
