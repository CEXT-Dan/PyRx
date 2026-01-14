"""
PyRx System Variables Pickling Module

This module demonstrates how to serialize and deserialize AutoCAD system variables
using Python's pickle module. It provides commands to save system variable states to disk,
load them back, and compare different states for debugging or configuration management.

Features:
- Save current AutoCAD system variables to a binary file
- Load system variables from saved files  
- Compare system variable states before and after changes
- Demonstrate pickle serialization/deserialization patterns

Usage:
    Load this script into AutoCAD's Python environment.
    Run any of the following commands:
        - 'pickle1': Save current system variables to E:\SysVar.p
        - 'pickle2': Load and display saved system variables  
        - 'pickle3': Compare original save vs. load for consistency check
        - 'pickle4': Demonstrate state changes with OSMODE variable

Requirements:
    - Active AutoCAD installation with Python support
    - Write permissions to E:\ directory
    - pickle module (standard library, no additional installation needed)

Example Output:
    Various console outputs depending on which command is run:
    - pickle1: No output (just saves file)
    - pickle2: Displays all loaded system variables  
    - pickle3: Shows any mismatches between save/load operations
    - pickle4: Shows differences when OSMODE changes from 191 to 0

Note:
    The saved file E:\SysVar.p contains binary serialized data of current system variables.
    This can be useful for configuration backup, testing, or state management.
"""

import pickle

from pyrx import Ap, Ed


def pickleizer():
    """
    Save current AutoCAD system variables to a binary file.
    
    This function:
    1. Gets the current system variable dictionary using Ed.Core.getSysVars()
    2. Serializes it using pickle.dump() 
    3. Saves to E:\SysVar.p in binary write mode
    4. Returns the original sysvars dictionary for further use
    
    Returns:
        dict: Current AutoCAD system variables dictionary
        
    Side Effects:
        - Creates/overwrites E:\SysVar.p file with current system variable state
        - No console output (unless error occurs)
        
    Example Usage:
        sysvars = pickleizer()  # Saves and returns current sysvars
    """
    sysvars = Ed.Core.getSysVars()
    pickle.dump(sysvars, open("E:\\SysVar.p", "wb"))
    return sysvars


def depickleizer():
    """
    Load AutoCAD system variables from a previously saved binary file.
    
    This function:
    1. Reads the binary file E:\SysVar.p using pickle.load()
    2. Returns the deserialized system variables dictionary
    
    Returns:
        dict: System variables loaded from E:\SysVar.p
        
    Side Effects:
        - Reads from E:\SysVar.p file
        - No console output (unless error occurs)
        
    Example Usage:
        sysvars = depickleizer()  # Loads and returns saved sysvars
    """
    sysvars = pickle.load(open("E:\\SysVar.p", "rb"))
    return sysvars


# === Command: pickle1 ===
@Ap.Command()
def pickle1():
    """
    Save current AutoCAD system variables to E:\SysVar.p.
    
    This command is the primary interface for saving the current state of 
    all AutoCAD system variables. It calls pickleizer() which:
    1. Gets current system variable values
    2. Serializes them to binary format  
    3. Writes to file E:\SysVar.p
    
    Usage:
        Run 'pickle' from AutoCAD command line.
        
    Side Effects:
        - Creates/overwrites E:\SysVar.p with current system variable state
        - No console output (success or failure handled internally)
        
    Error Handling:
        - Catches and prints any exceptions during the save operation
        
    Example Output:
        None (file is created silently)
    """
    try:
        pickleizer()
    except Exception as err:
        print(err)


# === Command: pickle2 ===
@Ap.Command()
def pickle2():
    """
    Load and display saved AutoCAD system variables from E:\SysVar.p.
    
    This command loads the previously saved system variable state using 
    depickleizer() and prints all key-value pairs to the console. It's useful
    for verifying that system variables can be properly deserialized.
    
    Usage:
        Run 'pickle2' from AutoCAD command line.
        
    Side Effects:
        - Reads E:\SysVar.p file  
        - Prints entire system variable dictionary to console
        
    Error Handling:
        - Catches and prints any exceptions during load/display operations
        
    Example Output:
        {'OSMODE': 191, 'LUNITS': 2, 'LUINIT': 0.0, ...}
    """
    try:
        sysvars = depickleizer()
        print(sysvars)
    except Exception as err:
        print(err)


# === Command: pickle3 ===
@Ap.Command()
def pickle3():
    """
    Compare original save vs. load for consistency verification.
    
    This command performs a comprehensive test by:
    1. Saving current system variables (pickleizer)
    2. Loading them back (depickleizer)  
    3. Comparing the original and loaded dictionaries
    4. Printing any key-value pairs that don't match
    
    Purpose:
        Validates that pickle serialization/deserialization works correctly.
        
    Usage:
        Run 'pickle3' from AutoCAD command line.
        
    Side Effects:
        - Reads E:\SysVar.p file (if it exists)
        - Compares original and loaded system variables
        - Prints mismatched key-value pairs to console
        
    Error Handling:
        - Catches and prints any exceptions during the comparison process
        
    Example Output:
        (No output if all values match, otherwise shows mismatches like:)
        OSMODE 191 != OSMODE 0
    """
    try:
        sysvars1 = pickleizer()
        sysvars2 = depickleizer()
        
        # Compare original vs loaded system variables
        for leftKey, leftValue, rightKey, rightValue in zip(
            sysvars1.keys(), sysvars1.values(), sysvars2.keys(), sysvars2.values()
        ):
            if leftValue != rightValue:
                print(leftKey, leftValue, "!=", rightKey, rightValue)

    except Exception as err:
        print(err)


# === Command: pickle4 ===
@Ap.Command()
def pickle4():
    """
    Demonstrate system variable state changes with OSMODE modification.
    
    This advanced command shows how system variables change by:
    1. Setting OSMODE to 191 (standard AutoCAD object snap mode)
    2. Saving the current state
    3. Changing OSMODE to 0 (no object snaps)
    4. Loading and comparing with original state
    5. Showing only differences between states
    
    Purpose:
        Demonstrates practical use of system variable management for testing 
        or configuration switching scenarios.
        
    Usage:
        Run 'pickle4' from AutoCAD command line.
        
    Side Effects:
        - Modifies current OSMODE setting (temporarily sets to 0)
        - Reads/writes E:\SysVar.p file
        - Compares system variable states and prints differences
        
    Error Handling:
        - Catches and prints any exceptions during state changes or comparisons
        
    Example Output:
        Shows only the OSMODE difference: 
        OSMODE 191 != OSMODE 0
        
    Note:
        After execution, OSMODE will be set to 0 in current session.
    """
    try:
        # Set OSMODE to 191 and save state
        Ed.Core.setVar("OSMODE", 191)
        pickleizer()
        
        # Load the saved state
        sysvars1 = depickleizer()

        # Change OSMODE to 0 (no object snaps) 
        Ed.Core.setVar("OSMODE", 0)
        
        # Get current system variables after change
        sysvars2 = Ed.Core.getSysVars()

        # Compare and show only differences
        for leftKey, leftValue, rightKey, rightValue in zip(
            sysvars1.keys(), sysvars1.values(), sysvars2.keys(), sysvars2.values()
        ):
            if leftValue != rightValue:
                print(leftKey, leftValue, "!=", rightKey, rightValue)

    except Exception as err:
        print(err)
