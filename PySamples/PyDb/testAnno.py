"""
PyRx AutoCAD Command Module for Annotation Scale Management

This module demonstrates various operations related to AutoCAD's annotation scale system,
specifically focusing on working with MText objects and their annotation scale contexts.
The code shows how to:
1. Create and manage annotative MText objects
2. Add and remove annotation scale contexts
3. Work with AnnotationScale objects using casting techniques

Functions:
    doit1: Demonstrates creating annotative MText with specific annotation scales
    doit2: Demonstrates removing annotation scale contexts from MText objects  
    doit3: Demonstrates listing all available annotation scales

Note: This module requires proper AutoCAD environment setup and PyRx installation.
"""

import traceback

from pyrx import Ap, Db, Ed


@Ap.Command()
def doit1() -> None:
    """
    Demonstrate creating annotative MText with specific annotation scales.
    
    This command selects an MText entity and performs the following operations:
    1. Checks if the MText is already annotative
    2. Converts it to annotative if necessary
    3. Adds annotation scale contexts to the MText object
    
    The function demonstrates both direct context usage (without casting) and
    casting to AnnotationScale objects when specific methods are needed.
    
    Usage:
        Command line: doit1
        Selection prompt: Select an mtext [entity selection]
        
    Steps performed:
        1. Prompts user to select an MText entity
        2. Gets current database's object context manager  
        3. Retrieves annotation scale collection
        4. Checks and sets annotative state of selected MText
        5. Adds specific annotation scales as contexts to the MText
        
    Example Output:
        False (initial annotative state)
        True (after setting annotative)
        ScaleName1
        ScaleName2
        
    Note: This example shows how to work with annotation scale contexts for
          creating annotative content that displays at different scales.
    """
    try:
        db = Db.curDb()

        # Prompt user to select an MText entity
        entres = Ed.Editor.entSel("\nSelect an mtext", Db.MText.desc())
        if entres[0] != Ed.PromptStatus.eOk:
            print("Oops: ", entres[0])
            return

        # Get object context manager and annotation scale collection
        ctxman = db.objectContextManager()
        ctxcoll = ctxman.contextCollection("ACDB_ANNOTATIONSCALES")

        # Open selected MText for writing
        mt = Db.MText(entres[1], Db.OpenMode.kForWrite)

        print(mt.isAnnotative())

        # Convert to annotative if not already
        if mt.isAnnotative() == Db.AnnotativeStates.kFalse:
            mt.setAnnotative(Db.AnnotativeStates.kTrue)

        print(mt.isAnnotative())

        # Add annotation scale contexts - no casting needed for basic operations
        if ctxcoll.hasContext("1:1"):
            annoScale = ctxcoll.getContext("1:100")
            mt.addContext(annoScale)

        # Add annotation scale context with explicit casting to AnnotationScale
        if ctxcoll.hasContext("1:100"):
            annoScale = Db.AnnotationScale.cast(ctxcoll.getContext("1:100"))
            print(annoScale.getName())
            mt.addContext(annoScale)

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def doit2() -> None:
    """
    Demonstrate removing annotation scale contexts from MText objects.
    
    This command selects an MText entity and removes specific annotation scale
    contexts from it. It shows how to properly remove contexts that were previously
    added to annotative content.
    
    Usage:
        Command line: doit2
        Selection prompt: Select an mtext [entity selection]
        
    Steps performed:
        1. Prompts user to select an MText entity  
        2. Gets current database's object context manager
        3. Retrieves annotation scale collection
        4. Opens selected MText for writing
        5. Removes specific annotation scale contexts from the MText
        
    Example Output:
        (No direct output, but removes specified scales from MText)
        
    Note: This example demonstrates cleanup operations - removing contexts that
          were previously added to annotative content.
    """
    try:
        db = Db.curDb()

        # Prompt user to select an MText entity
        entres = Ed.Editor.entSel("\nSelect an mtext", Db.MText.desc())
        if entres[0] != Ed.PromptStatus.eOk:
            print("Oops: ", entres[0])
            return

        # Get object context manager and annotation scale collection
        ctxman = db.objectContextManager()
        ctxcoll = ctxman.contextCollection("ACDB_ANNOTATIONSCALES")

        # Open selected MText for writing
        mt = Db.MText(entres[1], Db.OpenMode.kForWrite)

        # Remove annotation scale context - no casting needed for removal operations
        if ctxcoll.hasContext("1:100"):
            annoScale = ctxcoll.getContext("1:100")
            mt.removeContext(annoScale)

    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def doit3() -> None:
    """
    Demonstrate listing all available annotation scales.
    
    This command retrieves and displays information about all available annotation
    scales in the current database. It shows how to enumerate annotation scale objects
    without requiring explicit casting when using standard methods.
    
    Usage:
        Command line: doit3
        
    Steps performed:
        1. Gets current database's object context manager
        2. Retrieves annotation scale collection  
        3. Converts collection to list of AnnotationScale objects
        4. Prints the name of each available annotation scale
        
    Example Output:
        1:1
        1:50
        1:100
        1:200
        ...
        
    Note: This example shows how to work with collections and enumerate all 
          available annotation scales for use in other operations.
    """
    try:
        db = Db.curDb()
        ctxman = db.objectContextManager()
        ctxcoll = ctxman.contextCollection("ACDB_ANNOTATIONSCALES")

        # Optional: Convert collection to list using AnnotationScale.desc() for type safety
        annoScales = ctxcoll.toList(Db.AnnotationScale.desc())

        # Print names of all available annotation scales
        for annoScale in annoScales:
            print(annoScale.getName())

    except Exception as err:
        traceback.print_exception(err)
