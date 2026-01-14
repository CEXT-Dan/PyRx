"""
PyRx AutoCAD Application Module for Database Reactor Management

This module demonstrates how to create and manage AutoCAD Database Reactors using PyRx.
Database reactors allow Python applications to respond to various AutoCAD database events
such as object creation, modification, deletion, and system variable changes.

The module provides:
1. Application initialization messages
2. A custom MyReactor class that responds to various AutoCAD database events
3. Commands to register and unregister the database reactor

Functions:
    MyReactor: Custom database reactor class with comprehensive event handlers
    addDbreactor: Command to register the database reactor
    remDbreactor: Command to unregister the database reactor

Note: This module requires proper AutoCAD environment setup and PyRx installation.
"""

from pyrx import Ap, Db

# Print registration messages for debugging purposes
print("added command - addDbreactor")
print("added command - remDbreactor")


class MyReactor(Db.DatabaseReactor):
    """
    Custom Database Reactor class that listens to AutoCAD database events.
    
    This class inherits from Db.DatabaseReactor and overrides several event handler
    methods to respond to different types of AutoCAD database operations. The reactor can
    monitor:
    - Object creation and modification (append, unappend, reappend)
    - Object editing and erasure
    - Header system variable changes
    - Proxy object resurrection
    - Database shutdown events
    
    Event Handlers:
        objectAppended: Triggered when an object is appended to the database
        objectUnAppended: Triggered when an object is unappended from the database  
        objectReAppended: Triggered when an object is reappended to the database
        objectOpenedForModify: Triggered when an object is opened for modification
        objectModified: Triggered when an object is modified
        objectErased: Triggered when an object is erased
        headerSysVarWillChange: Triggered before a system variable change
        headerSysVarChanged: Triggered after a system variable change
        proxyResurrectionCompleted: Triggered when proxy objects are resurrected
        goodbye: Triggered when database is shutting down
    
    Usage:
        Create an instance of MyReactor and register it with AutoCAD database using addReactor()
    """
    
    def __init__(self):
        """Initialize the database reactor."""
        Db.DatabaseReactor.__init__(self)

    def objectAppended(self, db: Db.Database, Obj: Db.DbObject) -> None:
        """
        Handle object append event.
        
        This method is called when an object is appended (added) to the database.
        It prints information about the database file and the type of object added.
        
        Args:
            db (Db.Database): The database where the object was appended
            Obj (Db.DbObject): The object that was appended
            
        Example Output:
            objectAppended C:\\temp\\drawing.dwg LINE
        """
        print("objectAppended", db.getFilename(), Obj.isA().dxfName())

    def objectUnAppended(self, db: Db.Database, Obj: Db.DbObject) -> None:
        """
        Handle object unappend event.
        
        This method is called when an object is removed from the database.
        It prints information about the database file and the type of object removed.
        
        Args:
            db (Db.Database): The database where the object was unappended
            Obj (Db.DbObject): The object that was unappended
            
        Example Output:
            objectUnAppended C:\\temp\\drawing.dwg LINE
        """
        print("objectUnAppended", db.getFilename(), Obj.isA().dxfName())

    def objectReAppended(self, db: Db.Database, Obj: Db.DbObject) -> None:
        """
        Handle object reappend event.
        
        This method is called when an object is reappended to the database.
        It prints information about the database file and the type of object reappended.
        
        Args:
            db (Db.Database): The database where the object was reappended
            Obj (Db.DbObject): The object that was reappended
            
        Example Output:
            objectReAppended C:\\temp\\drawing.dwg LINE
        """
        print("objectReAppended", db.getFilename(), Obj.isA().dxfName())

    def objectOpenedForModify(self, db: Db.Database, Obj: Db.DbObject) -> None:
        """
        Handle object open for modification event.
        
        This method is called when an object is opened for editing/modification.
        It prints information about the database file and the type of object being modified.
        
        Args:
            db (Db.Database): The database containing the object
            Obj (Db.DbObject): The object being opened for modification
            
        Example Output:
            objectOpenedForModify C:\\temp\\drawing.dwg LINE
        """
        print("objectOpenedForModify", db.getFilename(), Obj.isA().dxfName())

    def objectModified(self, db: Db.Database, Obj: Db.DbObject) -> None:
        """
        Handle object modification event.
        
        This method is called when an object has been successfully modified.
        It prints information about the database file and the type of object modified.
        
        Args:
            db (Db.Database): The database containing the modified object
            Obj (Db.DbObject): The object that was modified
            
        Example Output:
            objectModified C:\\temp\\drawing.dwg LINE
        """
        print("objectModified", db.getFilename(), Obj.isA().dxfName())

    def objectErased(self, db: Db.Database, Obj: Db.DbObject, erased) -> None:
        """
        Handle object erase event.
        
        This method is called when an object is erased from the database.
        It prints information about the database file, object type, and erase status.
        
        Args:
            db (Db.Database): The database where the object was erased
            Obj (Db.DbObject): The object that was erased
            erased: Boolean indicating if the erase operation succeeded
            
        Example Output:
            objectErased C:\\temp\\drawing.dwg LINE True
        """
        print("objectErased", db.getFilename(), Obj.isA().dxfName(), erased)

    def headerSysVarWillChange(self, db: Db.Database, name) -> None:
        """
        Handle system variable change start event.
        
        This method is called before a header system variable changes value.
        It prints information about the database file and the system variable being changed.
        
        Args:
            db (Db.Database): The database where the system variable will change
            name: Name of the system variable that will change
            
        Example Output:
            headerSysVarWillChange C:\\temp\\drawing.dwg ANGDIR
        """
        print("headerSysVarWillChange", db.getFilename(), name)

    def headerSysVarChanged(self, db: Db.Database, name, bSuccess) -> None:
        """
        Handle system variable change completion event.
        
        This method is called after a header system variable has changed value.
        It prints information about the database file, system variable, and success status.
        
        Args:
            db (Db.Database): The database where the system variable changed
            name: Name of the system variable that was changed
            bSuccess: Boolean indicating if the change succeeded
            
        Example Output:
            headerSysVarChanged C:\\temp\\drawing.dwg ANGDIR True
        """
        print("headerSysVarChanged", db.getFilename(), name, bSuccess)

    def proxyResurrectionCompleted(self, db: Db.Database, name, objects) -> None:
        """
        Handle proxy object resurrection event.
        
        This method is called when proxy objects are successfully resurrected.
        It prints information about the database file, proxy name, and associated objects.
        
        Args:
            db (Db.Database): The database where proxy resurrection occurred
            name: Name of the proxy that was resurrected
            objects: List or collection of resurrected objects
            
        Example Output:
            proxyResurrectionCompleted C:\\temp\\drawing.dwg ProxyName [object_list]
        """
        print("proxyResurrectionCompleted", db.getFilename(), name, objects)

    def goodbye(self, db: Db.Database) -> None:
        """
        Handle database shutdown event.
        
        This method is called when the database is shutting down or closing.
        It prints information about which database is closing.
        
        Args:
            db (Db.Database): The database that is shutting down
            
        Example Output:
            goodbye C:\\temp\\drawing.dwg
        """
        print("goodbye", db.getFilename())


# Create a global instance of the reactor to be shared between commands
myReactor = MyReactor()


@Ap.Command()
def addDbreactor():
    """
    Register the database reactor with AutoCAD.
    
    This command registers the global MyReactor instance with the current database,
    enabling it to respond to various database events such as object creation,
    modification, and system variable changes.
    
    Usage:
        Command line: addDbreactor
        
    Note:
        - The reactor is registered with the currently active database
        - This command must be run before any of the monitored events occur  
        - Events will continue to be logged until explicitly unregistered
        - Errors during registration are caught and printed to console
    """
    try:
        db = Db.curDb()
        db.addReactor(myReactor)

    except Exception as err:
        print(err)


@Ap.Command()
def remDbreactor():
    """
    Unregister the database reactor from AutoCAD.
    
    This command removes the currently registered database reactor instance
    from the current database, stopping it from receiving any further events.
    
    Usage:
        Command line: remDbreactor
        
    Note:
        - Must be called after addDbreactor has been executed
        - Safely handles cases where no reactor is currently registered
        - Properly removes the reactor from AutoCAD's event system
        - Errors during unregistration are caught and printed to console
    """
    try:
        db = Db.curDb()
        db.removeReactor(myReactor)
    except Exception as err:
        print(err)
