"""
PyRx AutoCAD Application Module for Editor Reactor Management

This module demonstrates how to create and manage AutoCAD Editor Reactors using PyRx.
Editor reactors allow Python applications to respond to various AutoCAD events such as
command execution, file operations, and document changes.

The module provides:
1. Application initialization and cleanup functions
2. A custom EditorReactor class that responds to various AutoCAD events
3. Commands to register and unregister the reactor

Functions:
    OnPyInitApp: Called when the Python application is initialized
    OnPyUnloadApp: Called when the Python application is unloaded
    EdReactor: Custom editor reactor class with event handlers
    pyregedreactor: Command to register the editor reactor
    pyunregedreactor: Command to unregister the editor reactor

Note: This module requires proper AutoCAD environment setup and PyRx installation.
"""

from pyrx import Ap, Ed


def OnPyInitApp():
    """
    Application initialization callback function.
    
    This function is automatically called when the Python application is loaded
    into AutoCAD. It prints registration messages to indicate that the commands
    have been successfully added to the AutoCAD environment.
    
    Expected Output:
        Added command pyregedreactor
        Added command pyunregedreactor
        
    Note: This function should be called automatically by PyRx when the module
          is loaded, but it can also be invoked manually for testing purposes.
    """
    print("\nadded command pyregedreactor")
    print("\nadded command pyunregedreactor")


def OnPyUnloadApp():
    """
    Application cleanup callback function.
    
    This function is automatically called when the Python application is unloaded
    from AutoCAD. It ensures proper cleanup by unregistering any active reactors
    before the module is removed from memory.
    
    The function calls pyunregedreactor() to safely remove any registered editor
    reactor instances and clean up associated resources.
    
    Note: This function should be called automatically when the Python application
          is unloaded, but can also be invoked manually for testing or cleanup purposes.
    """
    pyunregedreactor()


class EdReactor(Ed.EditorReactor):
    """
    Custom Editor Reactor class that listens to AutoCAD editor events.
    
    This class inherits from Ed.EditorReactor and overrides several event handler
    methods to respond to different types of AutoCAD operations. The reactor can
    monitor:
    - Command execution start
    - Lisp command execution start  
    - Drawing file opening
    - Document saving
    
    Event Handlers:
        commandWillStart: Triggered when any AutoCAD command begins execution
        lispWillStart: Triggered when a Lisp command begins execution
        beginDwgOpen: Triggered when a drawing file is about to be opened
        beginSave: Triggered when a document is about to be saved
    
    Usage:
        Create an instance of EdReactor and register it with AutoCAD using addReactor()
    """
    
    def __init__(self):
        """Initialize the editor reactor."""
        Ed.EditorReactor.__init__(self)

    def commandWillStart(self, cmdstr):
        """
        Handle command start event.
        
        This method is called when any AutoCAD command begins execution.
        It prints a message showing which command has started.
        
        Args:
            cmdstr (str): The name of the command that is starting
            
        Example Output:
            commandWillStart-pline
            commandWillStart-line
        """
        print("\ncommandWillStart-{}".format(cmdstr))
        
    def lispWillStart(self, firstLine):
        """
        Handle Lisp command start event.
        
        This method is called when a Lisp command begins execution.
        It prints a message showing the first line of the Lisp command.
        
        Args:
            firstLine (str): The first line of the Lisp command being executed
            
        Example Output:
            lispWillStart-(command "pline")
        """
        print("\ncommandWillStart-{}".format(firstLine))
        
    def beginDwgOpen(self, fileName):
        """
        Handle drawing file open event.
        
        This method is called when AutoCAD begins opening a drawing file.
        It prints the name of the file that is about to be opened.
        
        Args:
            fileName (str): The path and name of the drawing file being opened
            
        Example Output:
            beginDwgOpen-C:\\temp\\drawing.dwg
        """
        print("\nbeginDwgOpen-{}".format(fileName))
        
    def beginSave(self, db , fileName):
        """
        Handle document save event.
        
        This method is called when AutoCAD begins saving a document.
        It prints information about both the database and file name being saved.
        
        Args:
            db: The database object being saved
            fileName (str): The path and name of the file being saved
            
        Example Output:
            beginSave- C:\\temp\\drawing.dwg
        """
        print("\nbeginSave-{} {}".format(db.getFilename(), fileName))


@Ap.Command()
def pyregedreactor():
    """
    Register the editor reactor with AutoCAD.
    
    This command creates an instance of EdReactor and registers it to listen
    for editor events. Once registered, the reactor will respond to various
    AutoCAD operations as defined in its event handlers.
    
    Usage:
        Command line: pyregedreactor
        
    Note:
        - Only one reactor can be active at a time (global instance)
        - This command must be run before any of the monitored events occur
        - The reactor will continue to operate until explicitly unregistered
        - Errors during registration are caught and printed to console
    """
    try:
        global inst
        inst = EdReactor()
        inst.addReactor()
    except Exception as err:
        print(err)


@Ap.Command()
def pyunregedreactor():
    """
    Unregister the editor reactor from AutoCAD.
    
    This command removes the currently registered editor reactor instance,
    stopping it from receiving any further events. It also cleans up the
    global instance variable to prevent memory leaks.
    
    Usage:
        Command line: pyunregedreactor
        
    Note:
        - Must be called after pyregedreactor has been executed
        - Safely handles cases where no reactor is currently registered
        - Properly removes the reactor from AutoCAD's event system
        - Errors during unregistration are caught and printed to console
    """
    try:
        global inst
        if inst is None:
            return
        inst.removeReactor()
        del(inst)
    except Exception as err:
        print(err)
