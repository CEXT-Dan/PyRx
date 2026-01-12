"""
PyRx Context Menu Commands Module

This module demonstrates how to create and manage custom context menus in AutoCAD
using PyRx. It shows how to add a custom menu item that appears when right-clicking
on BlockReference entities, allowing users to perform specific actions like printing
attribute information.

The module implements:
- A custom UIContext class that defines the context menu behavior
- Commands to add and remove the custom context menu from AutoCAD

Usage:
    Load this script into AutoCAD's Python environment.
    Run 'pyaddmenu' to register the custom context menu.
    Run 'pyremovemenu' to unregister it.
"""

import wx

from pyrx import Ap, Db, Ed


# --- Registering Commands ---
print("Added command = pyaddmenu")
print("Added command = pyremovemenu")


# === Custom UI Context Class ===
class MyMenu(Ed.UIContext):
    """
    A custom context menu implementation for AutoCAD using PyRx.
    
    This class extends Ed.UIContext to provide a right-click context menu
    that appears when selecting BlockReference entities. The menu includes
    an option to print attributes of the selected block and its sub-entities.
    
    Features:
        - Custom context menu with "Print Attributes" option
        - Iterates through nested block references and attributes
        - Displays text strings of all attribute references
        
    Attributes:
        contextMenu (wx.Menu): The actual wxPython menu object
        ids (list): List of selected entity IDs
        rxClass (object): The class descriptor for the current selection type
    """
    
    def __init__(self):
        """Initialize the custom menu with default values."""
        Ed.UIContext.__init__(self)
        self.contextMenu = wx.Menu()
        # Add a menu item with emoji icon
        self.contextMenu.Append(10001, "🖨️ Print Attributes")
        self.ids = []
        self.rxClass = None

    def getMenuContext(self, rxClass, ids):
        """
        Return the context menu for the specified entity type.
        
        This method is called by AutoCAD when a user right-clicks on an entity
        that matches our registered class descriptor.
        
        Args:
            rxClass: The class descriptor of the selected entity type
            ids (list): List of ObjectIds for the selected entities
            
        Returns:
            wx.Menu: The context menu to display
        """
        self.rxClass = rxClass
        self.ids = ids
        return self.contextMenu

    def onCommand(self, cmd):
        """
        Handle commands from the context menu.
        
        This method is called when a user selects an item from our custom menu.
        
        Args:
            cmd (int): The command ID of the selected menu item
        """
        if cmd == 10001:
            self.doCmd10001()

    def OnUpdateMenu(self):
        """
        Update the context menu before display.
        
        This method is called periodically to allow dynamic updates to the menu.
        Currently, it just prints a message to console for debugging purposes.
        """
        print("update")

    def doCmd10001(self):
        """
        Execute the "Print Attributes" command.
        
        Iterates through all selected BlockReference entities and their nested
        structures to extract and display attribute text values.
        
        For each block reference:
            - Gets the block table record
            - Finds all block references within that record
            - Extracts attribute references from those sub-blocks
            - Prints the text string of each attribute
        """
        for id in self.ids:
            bref = Db.BlockReference(id)
            brec = Db.BlockTableRecord(bref.blockTableRecord())
            for refid in brec.getBlockReferenceIds():
                subbref = Db.BlockReference(refid)
                for attid in subbref.attributeIds():
                    att = Db.AttributeReference(attid)
                    print(att.textString())


# === Global Variables ===
# Global list to store menu instances so they don't get garbage collected
menus = []


# === Command: pyaddmenu ===
@Ap.Command()
def pyaddmenu():
    """
    Add the custom context menu to AutoCAD for BlockReference entities.
    
    This command registers our MyMenu instance as a context menu handler for 
    BlockReference entities. Once registered, right-clicking on any block will
    show the custom "Print Attributes" option in the context menu.
    
    Usage:
        Run 'pyaddmenu' from AutoCAD command line to activate the custom menu.
        
    Side Effects:
        - Registers the custom context menu with AutoCAD
        - Prints success/failure message to console
        
    Returns:
        None
    """
    try:
        # Create new menu instance and add it to global list
        menus.append(MyMenu())
        
        # Register the context menu for BlockReference entities
        flag = Ed.UIContext.addObjectContextMenu(Db.BlockReference.desc(), menus[0])
        
        if flag:
            print("YaY! Context menu successfully added.")
        else:
            print("Boo! Failed to add context menu.")
            
    except Exception as err:
        print(f"Error in pyaddmenu: {err}")


# === Command: pyremovemenu ===
@Ap.Command()
def pyremovemenu():
    """
    Remove the custom context menu from AutoCAD.
    
    This command unregisters our MyMenu instance, removing it from the 
    context menu system for BlockReference entities. The menu will no longer
    appear when right-clicking on blocks.
    
    Usage:
        Run 'pyremovemenu' from AutoCAD command line to deactivate the custom menu.
        
    Side Effects:
        - Unregisters the custom context menu with AutoCAD  
        - Clears the menu reference in global list
        - Prints success/failure message to console
        
    Returns:
        None
    """
    try:
        # Remove the registered context menu for BlockReference entities
        flag = Ed.UIContext.removeObjectContextMenu(Db.BlockReference.desc(), menus[0])
        
        if flag:
            # Clear the reference to allow garbage collection
            menus[0] = None
            print("YaY! Context menu successfully removed.")
        else:
            print("Boo! Failed to remove context menu.")
            
    except Exception as err:
        print(f"Error in pyremovemenu: {err}")
