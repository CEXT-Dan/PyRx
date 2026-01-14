"""
PyRx AutoCAD Application Module for Document Reactor Management

This module demonstrates how to create and manage AutoCAD Document Reactors using PyRx.
Document reactors allow Python applications to respond to various AutoCAD document events
such as document creation, activation, locking, and destruction.

The module provides:
1. Application initialization and cleanup functions
2. A custom DocReactor class that responds to various AutoCAD document events
3. Commands to register and unregister the document reactor

Functions:
    OnPyInitApp: Called when the Python application is initialized
    OnPyUnloadApp: Called when the Python application is unloaded
    DocReactor: Custom document reactor class with comprehensive event handlers
    pyregdocreactor: Command to register the document reactor
    pyunregdocreactor: Command to unregister the document reactor

Note: This module requires proper AutoCAD environment setup and PyRx installation.
"""

from pyrx import Ap


def OnPyInitApp():
    """
    Application initialization callback function.
    
    This function is automatically called when the Python application is loaded
    into AutoCAD. It prints registration messages to indicate that the commands
    have been successfully added to the AutoCAD environment.
    
    Expected Output:
        Added command pyregdocreactor
        Added command pyunregdocreactor
        
    Note: This function should be called automatically by PyRx when the module
          is loaded, but it can also be invoked manually for testing purposes.
    """
    print("\nadded command pyregdocreactor")
    print("\nadded command pyunregdocreactor")


def OnPyUnloadApp():
    """
    Application cleanup callback function.
    
    This function is automatically called when the Python application is unloaded
    from AutoCAD. It ensures proper cleanup by unregistering any active document
    reactors before the module is removed from memory.
    
    The function calls pyunregdocreactor() to safely remove any registered document
    reactor instances and clean up associated resources.
    
    Note: This function should be called automatically when the Python application
          is unloaded, but can also be invoked manually for testing or cleanup purposes.
    """
    pyunregdocreactor()


class DocReactor(Ap.DocManagerReactor):
    """
    Custom Document Reactor class that listens to AutoCAD document events.
    
    This class inherits from Ap.DocManagerReactor and overrides several event handler
    methods to respond to different types of AutoCAD document operations. The reactor can
    monitor:
    - Document creation (start, completion, cancellation)
    - Document destruction and cleanup
    - Document activation/deactivation
    - Document locking mode changes
    
    Event Handlers:
        documentCreateStarted: Triggered when document creation begins
        documentCreated: Triggered when document creation is complete
        documentToBeDestroyed: Triggered before document destruction
        documentDestroyed: Triggered after document destruction
        documentCreateCanceled: Triggered when document creation is canceled
        documentLockModeWillChange: Triggered before lock mode change
        documentLockModeChangeVetoed: Triggered when lock mode change is vetoed
        documentLockModeChanged: Triggered after lock mode change
        documentBecameCurrent: Triggered when document becomes current
        documentToBeActivated: Triggered before document activation
        documentToBeDeactivated: Triggered before document deactivation
        documentActivationModified: Triggered when document activation status changes
    
    Usage:
        Create an instance of DocReactor and register it with AutoCAD using addReactor()
    """
    
    def __init__(self):
        """Initialize the document reactor."""
        Ap.DocManagerReactor.__init__(self)

    def documentCreateStarted(self, dwgdoc: Ap.Document):
        """
        Handle document creation start event.
        
        This method is called when AutoCAD begins creating a new document.
        It prints the title of the document that is about to be created.
        
        Args:
            dwgdoc (Ap.Document): The document object being created
            
        Example Output:
            documentCreateStarted-Untitled-1
        """
        if not dwgdoc.isNullObj():
            print("\ndocumentCreateStarted-{}".format(dwgdoc.docTitle()))

    def documentCreated(self, dwgdoc: Ap.Document):
        """
        Handle document creation completion event.
        
        This method is called when AutoCAD has completed creating a new document.
        It prints the title of the newly created document.
        
        Args:
            dwgdoc (Ap.Document): The newly created document object
            
        Example Output:
            documentCreated-Untitled-1
        """
        if not dwgdoc.isNullObj():
            print("\ndocumentCreated-{}".format(dwgdoc.docTitle()))

    def documentToBeDestroyed(self, dwgdoc: Ap.Document):
        """
        Handle document destruction start event.
        
        This method is called when AutoCAD begins destroying a document.
        It prints the title of the document that is about to be destroyed.
        
        Args:
            dwgdoc (Ap.Document): The document object being destroyed
            
        Example Output:
            documentToBeDestroyed-Untitled-1
        """
        if not dwgdoc.isNullObj():
            print("\ndocumentToBeDestroyed-{}".format(dwgdoc.docTitle()))

    def documentDestroyed(self, filename: str):
        """
        Handle document destruction completion event.
        
        This method is called after AutoCAD has completed destroying a document.
        It prints the name of the file that was destroyed.
        
        Args:
            filename (str): The path and name of the file that was destroyed
            
        Example Output:
            documentDestroyed-C:\\temp\\drawing.dwg
        """
        print("\ndocumentDestroyed-{}".format(filename))

    def documentCreateCanceled(self, dwgdoc: Ap.Document):
        """
        Handle document creation cancellation event.
        
        This method is called when AutoCAD cancels the creation of a new document.
        It prints the title of the document whose creation was canceled.
        
        Args:
            dwgdoc (Ap.Document): The document object for which creation was canceled
            
        Example Output:
            documentCreateCanceled-Untitled-1
        """
        if not dwgdoc.isNullObj():
            print("\ndocumentCreateCanceled-{}".format(dwgdoc.docTitle()))

    def documentLockModeWillChange(self, dwgdoc: Ap.Document,
                                   myCurrentMode, myNewMode, currentMode, pGlobalCmdName):
        """
        Handle document lock mode change start event.
        
        This method is called before a document's lock mode changes.
        It prints detailed information about the proposed lock mode change.
        
        Args:
            dwgdoc (Ap.Document): The document object whose lock mode will change
            myCurrentMode: Current lock mode of this application
            myNewMode: New lock mode being requested by this application  
            currentMode: Current global lock mode
            pGlobalCmdName: Name of the global command causing the change
            
        Example Output:
            documentLockModeWillChange-Untitled-1 0 1 1 OpenDocument
        """
        if not dwgdoc.isNullObj():
            print("\ndocumentLockModeWillChange-{} {} {} {} {}".format(
                dwgdoc.docTitle(), myCurrentMode, myNewMode, currentMode, pGlobalCmdName))

    def documentLockModeChangeVetoed(self, dwgdoc: Ap.Document, pGlobalCmdName):
        """
        Handle document lock mode change veto event.
        
        This method is called when a requested document lock mode change is denied.
        It prints information about the vetoed change and the command that caused it.
        
        Args:
            dwgdoc (Ap.Document): The document object whose lock mode change was vetoed
            pGlobalCmdName: Name of the global command that requested the change
            
        Example Output:
            documentLockModeChangeVetoed-Untitled-1 OpenDocument
        """
        if not dwgdoc.isNullObj():
            print("\ndocumentLockModeChangeVetoed-{} {}".format(
                dwgdoc.docTitle(), pGlobalCmdName))

    def documentLockModeChanged(self, dwgdoc: Ap.Document,
                                myPreviousMode, myCurrentMode, currentMode, pGlobalCmdName):
        """
        Handle document lock mode change completion event.
        
        This method is called after a document's lock mode has successfully changed.
        It prints detailed information about the completed lock mode change.
        
        Args:
            dwgdoc (Ap.Document): The document object whose lock mode has changed
            myPreviousMode: Previous lock mode of this application
            myCurrentMode: Current lock mode of this application  
            currentMode: Current global lock mode
            pGlobalCmdName: Name of the global command that caused the change
            
        Example Output:
            documentLockModeChanged-Untitled-1 0 1 1 OpenDocument
        """
        if not dwgdoc.isNullObj():
            print("\ndocumentLockModeChanged-{} {} {} {} {}".format(
                dwgdoc.docTitle(), myCurrentMode, myPreviousMode, currentMode, pGlobalCmdName))

    def documentBecameCurrent(self, dwgdoc: Ap.Document):
        """
        Handle document becoming current event.
        
        This method is called when a document becomes the active/current document.
        It prints the title of the document that became current.
        
        Args:
            dwgdoc (Ap.Document): The document object that became current
            
        Example Output:
            documentBecameCurrent-Untitled-1
        """
        if not dwgdoc.isNullObj():
            print("\ndocumentBecameCurrent-{}".format(dwgdoc.docTitle()))

    def documentToBeActivated(self, dwgdoc: Ap.Document):
        """
        Handle document activation start event.
        
        This method is called before a document becomes activated (made current).
        It prints the title of the document that will be activated.
        
        Args:
            dwgdoc (Ap.Document): The document object that will be activated
            
        Example Output:
            documentToBeActivated-Untitled-1
        """
        if not dwgdoc.isNullObj():
            print("\ndocumentToBeActivated-{}".format(dwgdoc.docTitle()))

    def documentToBeDeactivated(self, dwgdoc: Ap.Document):
        """
        Handle document deactivation start event.
        
        This method is called before a document becomes deactivated (no longer current).
        It prints the title of the document that will be deactivated.
        
        Args:
            dwgdoc (Ap.Document): The document object that will be deactivated
            
        Example Output:
            documentToBeDeactivated-Untitled-1
        """
        if not dwgdoc.isNullObj():
            print("\ndocumentToBeDeactivated-{}".format(dwgdoc.docTitle()))

    def documentActivationModified(self, bActivation: bool):
        """
        Handle document activation status change event.
        
        This method is called when the overall activation state of documents changes.
        It prints whether documents are being activated (True) or deactivated (False).
        
        Args:
            bActivation (bool): True if documents are being activated, False otherwise
            
        Example Output:
            documentToBeDeactivated-True
        """
        print("\ndocumentToBeDeactivated-{}".format(bActivation))


@Ap.Command()
def pyregdocreactor():
    """
    Register the document reactor with AutoCAD.
    
    This command creates an instance of DocReactor and registers it to listen
    for document events. Once registered, the reactor will respond to various
    AutoCAD document operations as defined in its event handlers.
    
    Usage:
        Command line: pyregdocreactor
        
    Note:
        - Only one reactor can be active at a time (global instance)
        - This command must be run before any of the monitored events occur
        - The reactor will continue to operate until explicitly unregistered
        - Errors during registration are caught and printed to console
    """
    try:
        global docReactorInstance
        docReactorInstance = DocReactor()
        docReactorInstance.addReactor()
    except Exception as err:
        print(err)


@Ap.Command()
def pyunregdocreactor():
    """
    Unregister the document reactor from AutoCAD.
    
    This command removes the currently registered document reactor instance,
    stopping it from receiving any further events. It also cleans up the
    global instance variable to prevent memory leaks.
    
    Usage:
        Command line: pyunregdocreactor
        
    Note:
        - Must be called after pyregdocreactor has been executed
        - Safely handles cases where no reactor is currently registered
        - Properly removes the reactor from AutoCAD's event system
        - Errors during unregistration are caught and printed to console
    """
    try:
        global docReactorInstance
        if docReactorInstance is None:
            return
        docReactorInstance.removeReactor()
        del (docReactorInstance)
    except Exception as err:
        print(err)
