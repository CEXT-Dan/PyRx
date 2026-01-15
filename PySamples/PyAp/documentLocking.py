"""
PyRx Command Module for Document Locking Operations.

This module demonstrates various methods of document locking in AutoCAD/BricsCAD
using PyRx. Document locking is crucial when working with database operations that
require exclusive access to prevent conflicts between multiple processes or threads
accessing the same drawing simultaneously.

The importance of document locks:
- Prevents data corruption during concurrent modifications
- Ensures thread safety when multiple processes access the same document
- Maintains consistency of drawing objects and their properties
- Required for safe database operations in multi-user environments

Commands:
    doit - Executes all document lock demonstration functions

Functions:
    test1() -> None
        Demonstrates AutoDocLock construction with default constructor
        
    test2() -> None
        Demonstrates AutoDocLock construction with specific document parameter
        
    test3() -> None
        Demonstrates getting AutoDocLock from DocumentManager
        
    test4() -> None
        Demonstrates getting AutoDocLock directly from Document class
        
    test5() -> None
        Demonstrates manual document locking without AutoDocLock
        
    doit() -> None
        Main command function that runs all lock demonstration tests

Example usage:
    Run 'doit' command in AutoCAD to see various document locking methods.
"""

from pyrx import Ap


# lock the document using AutoDocLock default ctor
# is curdoc
def test1():
    """
    Demonstrate AutoDocLock construction with default constructor.
    
    This method creates an AutoDocLock without specifying a document,
    which defaults to locking the current document (Ap.curDoc()).
    
    The lock ensures exclusive access to the current document during operations.
    """
    lock = Ap.AutoDocLock()

    # get the doc from the lock
    doc = lock.doc()
    print(doc == Ap.curDoc())


# lock the document using AutoDocLock other doc ctor
def test2():
    """
    Demonstrate AutoDocLock construction with specific document parameter.
    
    This method explicitly specifies which document to lock by passing
    the current document as a parameter to the constructor.
    
    Useful when working with multiple documents or when clarity is needed
    about which document is being locked.
    """
    lock = Ap.AutoDocLock(Ap.curDoc())
    doc = lock.doc()
    print(doc == Ap.curDoc())


# get an autolock from the document manager
def test3():
    """
    Demonstrate getting AutoDocLock from DocumentManager.
    
    This approach uses the DocumentManager to acquire a lock on a specific
    document, providing more control over which document is locked and how.
    
    The autoLock method handles the locking mechanism automatically,
    making it safer than manual locking in most cases.
    """
    man = Ap.DocManager()
    mdidoc = man.mdiActiveDocument()
    lock = man.autoLock(mdidoc)
    doc = lock.doc()
    print(doc == mdidoc)


# get an autolock from the document class
def test4():
    """
    Demonstrate getting AutoDocLock directly from Document class.
    
    This method calls autoLock() directly on a Document object,
    which is often the most straightforward approach when working with
    a known document instance.
    
    Ensures that operations on this specific document are protected from
    concurrent access by other processes or threads.
    """
    man = Ap.DocManager()
    mdidoc = man.mdiActiveDocument()
    lock = mdidoc.autoLock()
    print(mdidoc == lock.doc())


# lock with no autolock
def test5():
    """
    Demonstrate manual document locking without AutoDocLock wrapper.
    
    This method shows the traditional approach of manually locking and 
    unlocking documents using DocManager.lockDocument() and unlockDocument().
    
    Important considerations:
    - Requires explicit unlock in finally block to prevent deadlocks
    - Manual management increases risk of errors if unlock is forgotten
    - Less safe than AutoDocLock which automatically releases lock on destruction
    
    Used for scenarios where more fine-grained control over locking behavior
    is required, or when working with legacy code patterns.
    """
    try:
        # Arx
        man = Ap.DocManager()
        mdidoc = man.mdiActiveDocument()
        man.lockDocument(mdidoc, Ap.DocLockMode.kProtectedAutoWrite)
    finally:
        man.unlockDocument(mdidoc)


@Ap.Command()
def doit() -> None:
    """
    Execute all document locking demonstration functions.
    
    This main command function runs through each of the lock testing methods
    to show different approaches to document locking in PyRx. Each test
    demonstrates a different way to acquire locks on AutoCAD documents,
    with verification that the correct document is being locked.
    
    The purpose is educational - showing developers various ways to handle
    document locking safely, emphasizing why proper lock management is crucial
    for preventing data corruption and ensuring thread safety in multi-user
    or multi-process environments.
    
    Example usage:
        In AutoCAD command line, type 'doit' then press Enter to run all tests.
    """
    try:
        test1()
        test2()
        test3()
        test4()
        test5()
    except Exception as e:
        print(e)
