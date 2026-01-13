"""
PyRx Batch Processing Module

This module provides batch processing capabilities for AutoCAD drawing files (.dwg).
It demonstrates how to programmatically modify multiple drawings by performing a series
of operations on each file, including layer management and entity attribute changes.

Features:
- Batch processing of multiple .dwg files in a directory
- Automated layer creation and management
- Entity color and layer assignment modifications  
- File I/O operations with AutoCAD database handling
- Directory selection dialog for user input

Usage:
    Load this script into AutoCAD's Python environment.
    Run 'pybatch' from the AutoCAD command line to process all .dwg files in a selected directory.

Requirements:
    - Active AutoCAD installation with Python support
    - wxPython library installed (for file/directory dialogs)
    - Write permissions to directories containing .dwg files

Example Workflow:
    1. User selects directory containing .dwg files
    2. Each drawing is loaded in isolated database context  
    3. Worker function processes each drawing:
       - Creates layer "800"
       - Moves model space entities to layer "800" 
       - Sets block entities to layer "0" with by-layer color
       - Removes all layers except "0" and "800"
    4. Processed drawings are saved (commented out by default)

Note:
    The save operation is commented out by default for safety.
    Uncomment the save line in openSideDatabase() to enable file saving.
"""

import traceback
import wx

from pyrx import Ap, Db

# --- Registering Commands ---
print("added command pybatch")


def addLayer(sidedb: Db.Database, name: str):
    """
    Create a new layer in the specified database if it doesn't already exist.
    
    This function:
    1. Gets the LayerTable from the database
    2. Checks if layer with given name already exists  
    3. If not found, creates a new LayerTableRecord with default color (index 255)
    4. Adds the layer to the LayerTable and returns its ObjectId
    
    Args:
        sidedb (Db.Database): The database where layer should be created
        name (str): Name of the layer to create
        
    Returns:
        Db.ObjectId: ObjectId of the newly created or existing layer
        
    Side Effects:
        - Modifies the LayerTable in the provided database
        - May add a new layer record to the database
    """
    lt = Db.LayerTable(sidedb.layerTableId())
    if lt.has(name):
        return lt.getAt(name)
    clr = Db.Color()
    clr.setColorIndex(255)
    layer = Db.LayerTableRecord()
    layer.setName(name)
    layer.setColor(clr)
    lt.upgradeOpen()
    return lt.add(layer)


def moveModelSpaceEntsToLayer(sidedb: Db.Database, lid: Db.ObjectId):
    """
    Move all entities from model space to a specified layer.
    
    This function:
    1. Gets the ModelSpace BlockTableRecord
    2. Iterates through all entities in model space  
    3. Opens each entity for writing and assigns it to the specified layer
    
    Args:
        sidedb (Db.Database): Database containing the model space to process
        lid (Db.ObjectId): ObjectId of target layer to assign entities to
        
    Side Effects:
        - Modifies layer assignment of all entities in model space
        - Opens entities in write mode for modification
    """
    model = Db.BlockTableRecord(sidedb.modelSpaceId())
    for id in model.objectIds():
        ent = Db.Entity(id, Db.OpenMode.kForWrite)
        ent.setLayer(lid)


def moveBlockEntsToZeroLayer(sidedb: Db.Database):
    """
    Set all block entities to layer "0" with by-layer color.
    
    This function:
    1. Gets the BlockTable from the database
    2. Iterates through all non-layout, non-external reference blocks
    3. For each entity in those blocks:
       - Sets color to by-layer (index 256)
       - Assigns layer "0"
       
    Args:
        sidedb (Db.Database): Database containing blocks to process
        
    Side Effects:
        - Modifies color and layer assignment of entities in all non-layout blocks
        - Opens entities in write mode for modification
    """
    bt = Db.BlockTable(sidedb.blockTableId())
    for _name, id in bt.toDict().items():
        block = Db.BlockTableRecord(id)
        # skip a name if you want
        if block.isLayout():
            continue
        if block.isFromExternalReference():
            continue
        for id in block.objectIds():
            ent = Db.Entity(id, Db.OpenMode.kForWrite)
            ent.setColorIndex(256)  # by layer
            ent.setLayer("0")


def removeLayersExcept(sidedb: Db.Database, keep: list[str]):
    """
    Remove all layers except those specified in the keep list.
    
    This function:
    1. Gets the LayerTable from the database
    2. Iterates through all existing layers  
    3. Deletes layers that are not in the keep list
    4. Skips deletion of layers that cannot be erased
    
    Args:
        sidedb (Db.Database): Database containing layers to process
        keep (list[str]): List of layer names to preserve
        
    Side Effects:
        - Modifies LayerTable by deleting unwanted layers
        - May skip deletion if layer is in use or protected
    """
    lt = Db.LayerTable(sidedb.layerTableId())
    for name, id in lt.asDict().items():
        if name in keep:
            continue
        layer = Db.LayerTableRecord(id, Db.OpenMode.kForWrite)
        try:
            layer.erase()
        except Exception:
            print("cannot delete {}".format(name))


# === Main Processing Function ===
def worker(sidedb: Db.Database):
    """
    Perform batch processing operations on a single database.
    
    This is the core function that orchestrates all modifications to be applied
    to each drawing file. It performs these steps in sequence:
    1. Creates layer "800" 
    2. Moves model space entities to layer "800"
    3. Sets block entities to layer "0" with by-layer color  
    4. Removes all layers except "0" and "800"
    
    Args:
        sidedb (Db.Database): Database to process
        
    Side Effects:
        - Modifies the database through various layer and entity operations
        - May add/remove layers and change entity properties
    """
    lid = addLayer(sidedb, "800")
    moveModelSpaceEntsToLayer(sidedb, lid)
    moveBlockEntsToZeroLayer(sidedb)
    removeLayersExcept(sidedb, ["0", "800"])


# === Database Processing Function ===
def openSideDatabase(path, worker):
    """
    Load a drawing file, process it with the worker function, and optionally save.
    
    This function:
    1. Creates an isolated database instance (no document)
    2. Reads the specified .dwg file into memory  
    3. Closes input stream to prevent locking
    4. Calls the worker function to modify the database
    5. Optionally saves changes back to original file (currently commented out)
    
    Args:
        path (str): File path of .dwg drawing to process
        worker (function): Function that performs modifications on database
        
    Side Effects:
        - Reads from specified .dwg file
        - Modifies database in memory via worker function  
        - Optionally writes changes back to original file (if uncommented)
        
    Note:
        The saveAs() line is commented out for safety. Uncomment if you want to 
        permanently modify the input files.
    """
    sideDb = Db.Database(False, True)  # no doc
    sideDb.readDwgFile(path)
    sideDb.closeInput(True)
    worker(sideDb)
    #uncomment to save
    #sideDb.saveAs(path)


# === File Selection Function ===
def getDwgFiles():
    """
    Prompt user to select a directory and return all .dwg files in it.
    
    This function:
    1. Opens a wxPython directory selection dialog
    2. If user confirms selection, gets list of .dwg files from that directory
    3. Returns empty list if user cancels or no files found
    
    Returns:
        list[str]: List of full file paths for all .dwg files in selected directory
        
    Side Effects:
        - Opens system dialog window (wxPython UI)
        - May display console message if user cancels
    """
    dlg = wx.DirDialog(None, "Choose directory", "", wx.DD_DIR_MUST_EXIST)
    if dlg.ShowModal() != wx.ID_OK:
        print("You Cancelled The Dialog!")
        return []
    return Ap.Application.listFilesInPath(dlg.GetPath(), ".dwg")


# === Command: pybatch ===
@Ap.Command()
def pybatch() -> None:
    """
    Main batch processing command for .dwg files.
    
    This is the primary entry point that:
    1. Opens a directory selection dialog
    2. Gets list of all .dwg files in selected directory  
    3. Processes each file through the worker function
    4. Reports progress and completion status
    
    Usage:
        Run 'pybatch' from AutoCAD command line.
        
    Side Effects:
        - Opens system directory dialog for user input
        - Processes multiple .dwg files sequentially
        - Prints processing status to console
        - May modify drawing files (if save is uncommented)
        
    Error Handling:
        - Catches and prints any exceptions during file processing
        
    Example Workflow:
        1. User selects directory containing drawings  
        2. For each .dwg file:
           - File loads into isolated database context
           - Layer operations applied via worker()
           - File processed without modifying original (unless save is enabled)
        3. Console shows progress and completion message
        
    Note:
        This command processes files in a read-only manner by default.
        To actually modify the files, uncomment the sideDb.saveAs() line 
        in the openSideDatabase function.
    """
    try:
        for _item in getDwgFiles():
            print("\nProcessing {}".format(_item))
            openSideDatabase(_item, worker)
        print("done")
    except Exception as err:
        traceback.print_exception(err)
