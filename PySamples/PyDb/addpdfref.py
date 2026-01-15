"""
PyRx Command Module for PDF Underlay Management.

This module provides functionality to add PDF underlays to AutoCAD/BricsCAD drawings.
It demonstrates how to create and manage PDF definitions and references within the 
named objects dictionary of a drawing.

Commands:
    pyaddpdf - Adds a PDF underlay to the current model space

Functions:
    OnPyInitApp() -> None
        Called when the PyRx application initializes, prints initialization message
        
    addToNod(nod, defDictKey) -> None
        Helper function to add a new dictionary entry for PDF definitions
        
    pyaddpdf() -> None
        Main command that creates and inserts a PDF underlay into the drawing

Example usage:
    Run 'pyaddpdf' command in AutoCAD/BricsCAD to insert a PDF underlay from 
    E:\\JacksonSetup.pdf into the current model space.
"""

import traceback

from pyrx import Ap, Db


def OnPyInitApp():
    """
    Initialize the PyRx application and print startup message.

    This function is called when the PyRx application starts up. It prints
    a notification that the 'pyaddpdf' command has been added to the system.
    
    Example usage:
        Called automatically during application initialization.
    """
    print("\nAdded command - pyaddpdf")


# define a function just for scope, dict is closed
def addToNod(nod, defDictKey):
    """
    Add a new dictionary entry for PDF definitions to the named objects dictionary.

    This helper function creates and adds a new dictionary under the named 
    objects dictionary specifically for storing PDF definitions. It opens 
    the parent dictionary in write mode, sets up a new dictionary with 
    the specified key, then closes it back down.

    Args:
        nod (Db.Dictionary): The named objects dictionary to modify
        defDictKey (str): The key name to use for the PDF definition dictionary

    Example usage:
        addToNod(namedObjectsDict, Db.UnderlayDefinition.dictionaryKey(Db.PdfDefinition.desc()))
    """
    dict = Db.Dictionary()
    nod.upgradeOpen()
    nod.setAt(defDictKey, dict)
    nod.downgradeOpen()


@Ap.Command()
def pyaddpdf():
    """
    Add a PDF underlay to the current drawing's model space.

    This command performs the following steps:
    1. Gets the current database and named objects dictionary
    2. Checks if a PDF definition dictionary exists, creates it if needed
    3. Creates a new PDF definition from a specified file path
    4. Loads the PDF (with platform-specific handling for BricsCAD)
    5. Adds the PDF definition to the appropriate dictionary
    6. Creates a PDF reference and adds it to model space

    The PDF is loaded from "E:\\JacksonSetup.pdf" and inserted into the 
    current drawing's model space as an underlay.

    Example usage:
        In AutoCAD/BricsCAD command line, type 'pyaddpdf' then press Enter
    """
    try:
        # Get current database and named objects dictionary for reading
        db = Db.HostApplicationServices().workingDatabase()
        nod = Db.Dictionary(db.namedObjectsDictionaryId(), Db.OpenMode.kForRead)
        defDictKey = Db.UnderlayDefinition.dictionaryKey(Db.PdfDefinition.desc())

        # Check if PDF definition dictionary exists, create it if not
        if not nod.has(defDictKey):
            addToNod(nod, defDictKey)

        # Create new PDF definition and set source file path
        pdfDef = Db.PdfDefinition()
        pdfDef.setSourceFileName("E:\\JacksonSetup.pdf")

        # Platform-specific handling for BricsCAD (required for compatibility)
        if Db.HostApplicationServices().product() == "BricsCAD":
            pdfDef.load("")

        # Get the PDF definition dictionary and add our PDF definition to it
        pdfDict = Db.Dictionary(nod.getAt(defDictKey), Db.OpenMode.kForWrite)
        idPdfDef = pdfDict.setAt("WOOHOO", pdfDef)

        # Create a reference to the PDF definition and set up its properties
        pdfRef = Db.PdfReference()
        pdfRef.setDefinitionId(idPdfDef)
        pdfRef.setDatabaseDefaults()

        # Add the PDF reference to model space
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForWrite)
        model.appendAcDbEntity(pdfRef)

    except Exception:
        print(traceback.format_exc())
