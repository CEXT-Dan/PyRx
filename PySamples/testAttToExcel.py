"""
PyRx Block Reference Attributes to Excel Module

This module demonstrates how to extract attribute information from BlockReference entities
in AutoCAD and export that data to an Excel spreadsheet using openpyxl. It provides a command
that allows users to select block references and outputs their attribute values to a CSV/Excel file.

Features:
- Interactive selection of BlockReference entities  
- Extraction of all attribute values from selected blocks
- Export of attribute data to Excel format (.xlsx)
- Error handling for invalid selections and file operations

Usage:
    Load this script into AutoCAD's Python environment.
    Run 'doit' from the AutoCAD command line to select blocks and export attributes.

Requirements:
    - Active AutoCAD document with BlockReference entities containing attributes
    - openpyxl library installed (pip install openpyxl)
    - Write permissions to E:\ directory

Example Output:
    Creates e:\pyattout.xlsx containing attribute data from selected blocks.
    Each row represents a block reference, each column represents an attribute value.
"""

import traceback
import openpyxl as Ex  # using openpyxl

from pyrx import Ap, Db, Ed


def selectRefs() -> list[Db.ObjectId]:
    """
    Select BlockReference entities and return their object IDs.
    
    This function prompts the user to select one or more BlockReference entities
    from the drawing and returns a list of their ObjectIds. It handles the selection
    process and validates that at least one entity was selected successfully.
    
    Returns:
        list[Db.ObjectId]: List of ObjectIds for the selected BlockReference entities
        
    Raises:
        Exception: If no entities are selected or if selection fails
        
    Usage:
        Called internally by doit() function to get block reference selections
    """
    # Prompt user to select a block reference entity
    entSetRes = Ed.Editor.entSel("\nSelectBlock: \n", Db.BlockReference.desc())
    
    # Check if selection was successful
    if entSetRes[0] != Ed.PromptStatus.eNormal:
        raise Exception(entSetRes[0])

    # Get the selected block reference
    ref = Db.BlockReference(entSetRes[1])
    
    # Get the block table record that contains this block reference
    btr = Db.BlockTableRecord(ref.blockTableRecord())
    
    # Return list of all block reference IDs within this block table record
    return btr.getBlockReferenceIds()


# === Command: doit ===
@Ap.Command()
def doit():
    """
    Extract attributes from selected BlockReferences and export to Excel.
    
    This command performs the following operations:
    1. Prompts user to select BlockReference entities
    2. For each selected block reference:
       - Retrieves all attribute references within that block
       - Extracts text strings from each attribute
    3. Writes the extracted data to an Excel spreadsheet (e:\pyattout.xlsx)
    
    Data Structure in Excel:
        - Each row represents one BlockReference entity  
        - Each column represents one AttributeReference within that block
        - Cell values contain the text string of each attribute
    
    Usage:
        Run 'doit' from AutoCAD command line.
        
    Requirements:
        - Active AutoCAD document with BlockReference entities containing attributes
        - openpyxl library installed
        - Write permissions to E:\ directory
        
    Side Effects:
        - Creates e:\pyattout.xlsx file with attribute data
        - May overwrite existing file at same location
        - No direct console output (except error messages)
        
    Example Output:
        Creates Excel file where rows correspond to block references and columns 
        correspond to attributes within each block. Each cell contains the text value
        of an attribute reference.
        
    Error Handling:
        - Catches all exceptions during selection, data extraction, and file operations
        - Prints exception details via traceback for debugging
        
    Note:
        This command extracts nested block references as well, not just top-level ones.
    """
    try:
        # Create a new workbook and get the active worksheet
        wb = Ex.Workbook()
        ws = wb.active

        # Iterate through all selected block reference IDs
        for nrow, refId in enumerate(selectRefs()):
            # Get the block reference entity
            ref = Db.BlockReference(refId)
            
            # Get all attribute IDs from this block reference
            attIds = ref.attributeIds()
            
            # Process each attribute in this block reference
            for ncol, attid in enumerate(attIds):
                # Get the attribute reference
                att = Db.AttributeReference(attid)
                
                # Write the text string value to Excel cell
                ws.cell(row=nrow + 1, column=ncol + 1, value=att.textString())

        # Save the workbook to specified location
        wb.save("e:\\pyattout.xlsx")

    except Exception as err:
        traceback.print_exception(err)
