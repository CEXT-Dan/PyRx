"""
PyRx Command Module for Extracting Thumbnails from AutoCAD Drawings.

This module provides functionality to extract thumbnails (preview images) 
from all block definitions in AutoCAD DWG files and save them as PNG images.
The extracted thumbnails are saved with filenames that include the drawing name 
and block name for easy identification.

Commands:
    doit - Main command that extracts thumbnails from all DWG files in a directory

Functions:
    extractThumbnailsFromDb(db: Db.Database, path: str, targetpath: str) -> None
        Extracts thumbnails from all valid blocks in a database and saves them as PNG files
        
    extractThumbnails(path: str, targetpath: str) -> None
        Reads a DWG file and extracts thumbnails from it
        
    doit() -> None
        Main command function that processes all DWG files in a directory

Example usage:
    Run 'doit' command to extract thumbnails from all .dwg files in E:\temp 
    and save them to E:/temp/icons directory.
"""

import os
import traceback

import wx

from pyrx import Ap, Db, Gs


def extractThumbnailsFromDb(db: Db.Database, path: str, targetpath: str) -> None:
    """
    Extract thumbnails from all valid block definitions in a database and save them as PNG files.

    This function iterates through all blocks in the given database, filters out
    special blocks (layouts, anonymous blocks, external references), and extracts 
    128x128 pixel thumbnails for each valid block using Gs.Core.getBlockImage().

    Args:
        db (Db.Database): The AutoCAD database object containing blocks to process
        path (str): The full file path of the source DWG file
        targetpath (str): The directory path where thumbnail PNG files will be saved

    Example usage:
        extractThumbnailsFromDb(database, "C:/drawings/example.dwg", "E:/temp/thumbs")
    """
    # Extract filename without extension for naming thumbnails
    path_without_extension, _ = os.path.splitext(path)
    dwgname = os.path.basename(path_without_extension)
    
    # Get the block table to iterate through all blocks
    bt = Db.BlockTable(db.blockTableId())
    
    # Process each block in the database
    for name, id in bt.asDict().items():
        blk = Db.BlockTableRecord(id)
        
        # Skip special types of blocks that don't need thumbnails
        if (
            blk.isLayout()
            or blk.isAnonymous()
            or blk.isFromExternalReference()
            or blk.isFromOverlayReference()
        ):
            continue
            
        # Extract thumbnail image using Gs.Core.getBlockImage()
        img: wx.Image = Gs.Core.getBlockImage(id, 128, 128, 1.0, [0, 0, 0])
        
        # Save the image with a descriptive filename
        img.SaveFile("{}/{}_{}_128.png".format(targetpath, dwgname, name), wx.BITMAP_TYPE_PNG)


def extractThumbnails(path: str, targetpath: str) -> None:
    """
    Read a DWG file and extract thumbnails from all its blocks.

    This function creates a new database object, reads the specified DWG file,
    closes the input stream, then calls the thumbnail extraction function.
    The database object is properly disposed of after processing to ensure
    proper memory management (using FIFO garbage collection).

    Args:
        path (str): Full file path to the source DWG file
        targetpath (str): Directory path where extracted thumbnails will be saved

    Example usage:
        extractThumbnails("C:/drawings/example.dwg", "E:/temp/thumbs")
    """
    # Create a new database object for reading (not sharing with current session)
    db = Db.Database(False, True)
    
    # Read the DWG file into memory
    db.readDwgFile(path)
    
    # Close the input stream to release resources
    db.closeInput(True)
    
    # Extract thumbnails from this database
    extractThumbnailsFromDb(db, path, targetpath)


# Register a new command and ensure the target directory exists
@Ap.Command()
def doit() -> None:
    """
    Main command function that processes all DWG files in E:\temp directory.

    This command:
    1. Creates or ensures existence of the target directory (E:/temp/icons)
    2. Finds all .dwg files in E:\temp using Ap.Application.listFilesInPath()
    3. Calls extractThumbnails() for each found file
    4. Handles any exceptions that occur during processing

    The command extracts thumbnails from all blocks in each DWG file and saves them
    as PNG images with descriptive filenames in the target directory.

    Example usage:
        In AutoCAD/BricsCAD, type 'doit' then press Enter to start extraction process.
    """
    try:
        # Set up the target directory for saving thumbnails
        targetpath = "E:/temp/icons"
        os.makedirs(targetpath, exist_ok=True)
        
        # Get list of all DWG files in the source directory
        for path in Ap.Application.listFilesInPath("E:\\temp", ".dwg"):
            extractThumbnails(path, targetpath)

    except Exception as err:
        traceback.print_exception(err)
