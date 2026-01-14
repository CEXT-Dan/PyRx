"""
PyRx Model Space Iteration Module

This module demonstrates how to iterate through all entities in AutoCAD's model space
and perform operations on specific entity types. It provides a command that scans
the entire model space and changes the layer of all LINE entities to "0".

Features:
- Iterates through all entities in the current drawing's model space
- Identifies and processes only AcDbLine entities
- Changes the layer property of matching entities
- Demonstrates proper ActiveX casting and error handling

Usage:
    Load this script into AutoCAD's Python environment.
    Run 'itermodel' from the AutoCAD command line to process all lines in model space.

Requirements:
    - Active AutoCAD document with entities in model space
    - AutoCAD must be running with ActiveX support enabled

Example:
    After running 'itermodel', all LINE entities in the drawing will have their
    layer property set to "0".
"""

import traceback

from pyrx import Ap, Ax

# --- Registering Commands ---
print("added command itermodel")


# === Command: itermodel ===
@Ap.Command()
def itermodel() -> None:
    """
    Iterate through all entities in model space and set LINE entities to layer "0".

    This function demonstrates how to:
    1. Access the active AutoCAD document
    2. Get reference to the model space collection
    3. Iterate through all entities in model space
    4. Filter for specific entity types (AcDbLine)
    5. Cast entities to their specific ActiveX types
    6. Modify properties of matching entities

    Processing Logic:
        - For each entity in model space:
          * Check if entity name equals "AcDbLine"
          * If so, cast to AcadLine type
          * Set the layer property to "0"

    Usage:
        Run 'itermodel' from AutoCAD command line.

    Side Effects:
        - Modifies layer property of all LINE entities in model space
        - Changes entity properties directly in the drawing database

    Requirements:
        - Active AutoCAD document with existing LINE entities
        - Valid AutoCAD installation with ActiveX support

    Example Output:
        (No console output, but modifies drawing entities)

    Note:
        This command processes ALL entities in model space regardless of current selection.
        It will affect every LINE entity in the entire drawing.
    """
    try:
        # Get the active AutoCAD application instance
        axApp = Ap.Application.acadApplication()

        # Get reference to the active document
        axDoc = axApp.activeDocument()

        # Get reference to the model space collection
        axModel = axDoc.modelSpace()

        # Iterate through all entities in model space
        for ent in axModel:
            # Check if entity is a LINE type
            if ent.entityName() == "AcDbLine":
                # Cast the generic entity to specific AcadLine type
                line = Ax.AcadLine.cast(ent)

                # Set the layer property of the line to "0"
                line.setLayer("0")

    except Exception as err:
        traceback.print_exception(err)
