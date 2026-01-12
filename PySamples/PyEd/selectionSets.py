"""
PyRx Selection Set Commands Module

This module defines several AutoCAD commands that demonstrate various
ways to work with selection sets using PyRx (Python for Autodesk AutoCAD).
Each function corresponds to a separate command which can be invoked from
the AutoCAD command line once loaded into the system.
"""

import traceback

from pyrx import Ap, Db, Ed, Ge, Gi


# --- Registering Commands ---
print("Added command = pyselectall")
print("Added command = pyselectallf")
print("Added command = pyselectf")
print("Added command = pyssget1")
print("Added command = pyssget2")
print("Added command = pyssget3")
print("Added command = pyssget4")
print("Added command = pyssget5")


# === Command: pyselectall ===
@Ap.Command()
def pyselectall():
    """
    Selects all entities in the drawing and demonstrates basic selection set operations.

    Operations performed:
        - Gets a full selection set of all objects.
        - Prints size of the selection.
        - Lists object IDs in the selection.
        - Tests membership of an item.
        - Removes an item from the selection, checks size/contains again.
        - Adds back the removed item and verifies it's present.

    Usage:
        Run 'pyselectall' in AutoCAD command line.
    """
    try:
        # Prompt user to select all entities
        ps, ss = Ed.Editor.selectAll()

        # Check if we received a valid selection set
        if ps == Ed.PromptStatus.eNormal:
            print(f"Selection size: {ss.size()}")

            # Get list of object IDs in the selection
            ids = ss.toList()
            print("Object IDs:", ids)

            # Test if first ID exists in the set
            print(f"Has member ({ids[0]}): {ss.hasMember(ids[0])}")

            # Remove one item from the selection
            ss.remove(ids[0])
            print(f"After removal size: {ss.size()}")
            print(f"Still has member after removal? {ss.hasMember(ids[0])}")

            # Add back that same object ID
            ss.add(ids[0])
            print(f"After adding back - Has member? {ss.hasMember(ids[0])}")
            print(f"Final size: {ss.size()}")

    except Exception as err:
        traceback.print_exception(type(err), err, err.__traceback__)


# === Command: pyselectallf ===
@Ap.Command()
def pyselectallf():
    """
    Selects all entities matching a specified filter (e.g., only CIRCLES on layer "0").

    Filters used:
        - Type = CIRCLE
        - Layer = 0

    Usage:
        Run 'pyselectallf' in AutoCAD command line.
    """
    try:
        # Define the selection filter as list of tuples:
        # (DxfCode, Value)
        filter = [
            (Db.DxfCode.kDxfStart, "CIRCLE"),  # Entity type
            (Db.DxfCode.kDxfLayerName, "0"),  # Layer name
        ]

        # Execute selection with filters applied
        ssres = Ed.Editor.selectAll(filter)

        if ssres[0] == Ed.PromptStatus.eNormal:
            selection = ssres[1]
            print(f"Filtered selection size: {selection.size()}")

    except Exception as err:
        traceback.print_exception(type(err), err, err.__traceback__)


# === Command: pyselectf ===
@Ap.Command()
def pyselectf():
    """
    Demonstrates filtering and selecting entities using a custom filter.

    Filters used:
        - Entity types: LINE or CIRCLE
        - Layer name: 0

    Outputs the count of total objects, lines, and circles in the selection.

    Usage:
        Run 'pyselectf' in AutoCAD command line.
    """
    try:
        # Filter example for Lines or Circles on layer "0"
        filter = [
            (Db.DxfCode.kDxfStart, "LINE,CIRCLE"),  # Multiple types
            (Db.DxfCode.kDxfLayerName, "0"),
        ]

        # Perform selection with filter
        ssres = Ed.Editor.select(filter)

        if ssres[0] == Ed.PromptStatus.eNormal:
            selection_set = ssres[1]

            # Get all IDs
            ids = selection_set.objectIds()

            # Filter specific object types
            line_ids = selection_set.objectIds(Db.Line.desc())
            circle_ids = selection_set.objectIds(Db.Circle.desc())

            print(f"Total selected: {len(ids)}")
            print(f"Lines only: {len(line_ids)}")
            print(f"Circles only: {len(circle_ids)}")

    except Exception as err:
        traceback.print_exception(type(err), err, err.__traceback__)


# === Command: pyssget1 ===
@Ap.Command()
def pyssget1():
    """
    Uses the ssget function directly with a window selection defined by two points.

    This command creates a box between (0, 0) and (100, 100), then selects everything inside.

    Usage:
        Run 'pyssget1' in AutoCAD command line.
    """
    try:
        # Define point pairs for window selection
        pt1 = Ge.Point3d(0, 0, 0)
        pt2 = Ge.Point3d(100, 100, 0)

        ssResult = Ed.Editor.ssget("F", [pt1, pt2], None)

        if ssResult[0] == Ed.PromptStatus.eNormal:
            obj_count = len(ssResult[1].toList())
            print(f"Objects selected in window: {obj_count}")

    except Exception as err:
        print(err)


# === Command: pyssget2 ===
@Ap.Command()
def pyssget2():
    """
    Uses ssget with a complex selection mode "_:$", using custom keywords.

    This example uses the "MYADD" and "MYREMOVE" user-defined keywords.

    Usage:
        Run 'pyssget2' in AutoCAD command line.
    """
    try:
        # Select objects using dynamic keyword-based selection
        ssResult = Ed.Editor.ssget("_:$", ("MYADD", "MYREMOVE"), None)

        if ssResult[0] == Ed.PromptStatus.eNormal:
            obj_count = len(ssResult[1].toList())
            print(f"Selected with custom mode: {obj_count}")

    except Exception as err:
        traceback.print_exception(type(err), err, err.__traceback__)


# === Command: pyssget3 ===
@Ap.Command()
def pyssget3():
    """
    Demonstrates advanced selection using the "_:n" (Nested) option.

    This selects entities within nested selections and retrieves information about their hierarchy.

    Usage:
        Run 'pyssget3' in AutoCAD command line.
    """
    try:
        # Use nested selection mode
        ssResult = Ed.Editor.ssget("_:n", None, None)

        if ssResult[0] != Ed.PromptStatus.eNormal:
            return

        ss = ssResult[1]
        nested_info = ss.ssNameX()
        print("Nested info:", nested_info)

    except Exception as err:
        traceback.print_exception(type(err), err, err.__traceback__)


# === Command: pyssget4 ===
@Ap.Command()
def pyssget4():
    """
    Uses selectPrompt for manual selection with "Add" and "Remove" options.

    Allows interactive selection via command line prompt (like when typing SELECT).

    Usage:
        Run 'pyssget4' in AutoCAD command line.
    """
    try:
        # Prompt user to add/remove entities
        ssResult = Ed.Editor.selectPrompt("Add", "Remove")

        if ssResult[0] == Ed.PromptStatus.eNormal:
            obj_count = len(ssResult[1].toList())
            print(f"Objects selected via prompt: {obj_count}")

    except Exception as err:
        traceback.print_exception(type(err), err, err.__traceback__)


# === Command: pyssget5 ===
@Ap.Command()
def pyssget5():
    """
    Forces subentity selection (like pressing `v`) for solids/surfaces/regions.

    Highlights each selected sub-entity with a dashed and thickened style.

    Usage:
        Run 'pyssget5' in AutoCAD command line.
    """
    try:
        # Select objects using "subentity mode" (`_:v`)
        ps, ss = Ed.Editor.ssget("_:v", None, None)

        for idx in range(ss.size()):
            ent = Db.Entity(ss.getAt(idx), Db.OpenMode.kForWrite)

            # Iterate over all subentities of the current entity
            for sidx in range(ss.subentLength(idx)):
                sep = ss.subentName(idx, sidx)
                ent.pushHighlight(sep, Gi.HighlightStyle.kAcGiHighlightDashedAndThicken)

    except Exception as err:
        traceback.print_exception(type(err), err, err.__traceback__)
