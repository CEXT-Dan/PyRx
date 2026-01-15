"""
PyRx Command Module for DbObject Reactor Registration.

This module demonstrates how to create and register custom reactors with AutoCAD entities.
A reactor listens to various events that occur on database objects, allowing developers
to respond to changes in DbObject state such as modifications, erasures, or copies.

Classes:
    MyReactor(Db.DbObjectReactor) - Custom reactor class that handles DbObject events

Commands:
    doit - Registers a custom reactor with a selected DbObject

Functions:
    doit() -> None
        Main command function that selects an DbObject and registers the reactor

Example usage:
    Run 'doit' command in AutoCAD, then select an DbObject to register the reactor.
    The reactor will print messages when various events occur on the DbObject.
"""

from pyrx import Ap, Db, Ed


class MyReactor(Db.DbObjectReactor):
    """
    Custom reactor class that implements various database object event handlers.
    
    This reactor inherits from DbObjectReactor and overrides methods to handle
    different events that can occur on AutoCAD entities. Each method prints a 
    message indicating the type of event and the DbObject involved.
    
    Event Handlers:
        cancelled() - Called when an operation is cancelled
        copied() - Called when an object is copied
        erased() - Called when an object is erased
        goodbye() - Called before an object is destroyed
        openedForModify() - Called when an object is opened for modification
        modified() - Called when an object is modified
        subObjModified() - Called when a sub-object is modified
        modifyUndone() - Called when a modification is undone
        modifiedXData() - Called when extended data is modified
        unappended() - Called when an object is unappended
        reappended() - Called when an object is reappended
        objectClosed() - Called when an object is closed
    """
    
    def __init__(self):
        """Initialize the reactor and call parent constructor."""
        Db.DbObjectReactor.__init__(self)

    def cancelled(self, Obj: Db.DbObject) -> None:
        """Handle cancelled operations on the DbObject."""
        print("cancelled", Obj.isA().dxfName())

    def copied(self, Obj: Db.DbObject, newObj: Db.DbObject) -> None:
        """Handle object copying events."""
        print("copied", Obj.isA().dxfName(), newObj.isA().dxfName())

    def erased(self, Obj: Db.DbObject, flag: bool) -> None:
        """Handle DbObject erasure events."""
        print("erased", Obj.isA().dxfName(), flag)

    def goodbye(self, Obj: Db.DbObject) -> None:
        """Handle object destruction events."""
        print("goodbye", Obj.isA().dxfName())

    def openedForModify(self, Obj: Db.DbObject) -> None:
        """Handle when an object is opened for modification."""
        print("openedForModify", Obj.isA().dxfName())

    def modified(self, Obj: Db.DbObject) -> None:
        """Handle DbObject modification events."""
        print("modified", Obj.isA().dxfName())

    def subObjModified(self, Obj: Db.DbObject, subObj: Db.DbObject):
        """Handle sub-object modification events."""
        print("subObjModified", Obj.isA().dxfName(), subObj.isA().dxfName())

    def modifyUndone(self, Obj: Db.DbObject) -> None:
        """Handle modification undo events."""
        print("modifyUndone", Obj.isA().dxfName())

    def modifiedXData(self, Obj: Db.DbObject) -> None:
        """Handle extended data modification events."""
        print("modifiedXData", Obj.isA().dxfName())

    def unappended(self, Obj: Db.DbObject) -> None:
        """Handle when an object is unappended."""
        print("unappended", Obj.isA().dxfName())

    def reappended(self, Obj: Db.DbObject) -> None:
        """Handle when an object is reappended."""
        print("reappended", Obj.isA().dxfName())

    def objectClosed(self, id: Db.ObjectId) -> None:
        """Handle object closure events."""
        print("objectClosed", id.objectClass().dxfName())


# Create a global instance of the reactor
myReactor = MyReactor()


@Ap.Command()
def doit() -> None:
    """
    Register a custom reactor with a selected entity (DbObject).
    
    This command performs the following steps:
    1. Gets the current database
    2. Prompts user to select an entity
    3. If selection is successful, adds the custom reactor to the selected entity
    
    Once registered, the reactor will print messages whenever various events occur
    on the selected entity such as modification, erasure, copying, etc.
    
    Example usage:
        In AutoCAD command line, type 'doit' then press Enter
        Select an entity when prompted
        
    Events that will be logged (when they occur):
        - cancelled: Operation was cancelled
        - copied: Object was copied 
        - erased: Object was erased
        - goodbye: Object is being destroyed
        - openedForModify: Object opened for modification
        - modified: Object was modified
        - subObjModified: Sub-object was modified
        - modifyUndone: Modification undone
        - modifiedXData: Extended data modified
        - unappended: Object unappended
        - reappended: Object reappended
        - objectClosed: Object closed
    
    Note: The reactor remains active until the entity is removed or the application closes.
    """
    try:
        _db = Db.curDb()
        entRes = Ed.Editor.entSel("\nSelect Ent: ")
        if entRes[0] != Ed.PromptStatus.eNormal:
            return
        ent = Db.Entity(entRes[1])
        ent.addReactor(myReactor)
    except Exception as err:
        print(err)
