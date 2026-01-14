"""
PyRx AutoCAD Command Module for Lisp Function Invocation

This module demonstrates how to invoke AutoCAD Lisp functions from Python using
the PyRx framework's Ed.Core.invoke() method. It provides three example commands
that call different Lisp functions through the command interface.

The module shows two approaches:
1. Direct Lisp function calls using Ed.Core.invoke()
2. Usage of Rx.LispType constants for proper argument formatting

Functions:
    doit1: Calls C:ADDNUM Lisp function with parameter 10
    doit2: Calls C:GETLASTENT Lisp function to get last entity data  
    doit3: Calls C:GETENTSEL Lisp function to get selected entity data
"""

from pyrx import Ap, Ed, Rx

# Note: Arguments for Ed.Core.invoke() must end with (Rx.LispType.kNone, 0)
# This is required for proper argument list termination in the AutoCAD API


@Ap.Command()
def doit1(CmDFlags=Ap.CmdFlags.SESSION):
    """
    Execute the C:ADDNUM Lisp function with parameter 10.
    
    This command demonstrates calling a custom Lisp function that takes one 
    numeric parameter and returns the result of adding it to itself (+ x x).
    
    The function is called as: (C:ADDNUM 10)
    
    Args:
        CmDFlags: AutoCAD command flags (default: Ap.CmdFlags.SESSION)
        
    Example Lisp Function Definition:
        (defun C:ADDNUM ( x / ) (+ x x))
        
    Expected Output:
        If successful, prints the result of 10 + 10 = 20
        If failed, prints the error message
        
    AutoCAD Command Line Usage:
        Command line: doit1
        Result: [Function output or error]
    """
    try:
        # Define arguments for Lisp function call
        # Format: [(Rx.LispType.kText, "function_name"), (Rx.LispType.kInt16, parameter_value), (Rx.LispType.kNone, 0)]
        args = [(Rx.LispType.kText, "C:ADDNUM"), (Rx.LispType.kInt16, 10), (Rx.LispType.kNone, 0)]
        
        # Execute the Lisp function through PyRx interface
        result = Ed.Core.invoke(args)
        print(result)

    except Exception as err:
        # Print any exceptions that occur during execution
        print(err)


@Ap.Command()
def doit2(CmDFlags=Ap.CmdFlags.SESSION):
    """
    Execute the C:GETLASTENT Lisp function to retrieve last entity data.
    
    This command calls a custom Lisp function that gets information about 
    the last entity created in the drawing using (entget(entlast)).
    
    The function is called as: (C:GETLASTENT)
    
    Args:
        CmDFlags: AutoCAD command flags (default: Ap.CmdFlags.SESSION)
        
    Example Lisp Function Definition:
        (defun C:GETLASTENT () (entget(entlast)))
        
    Expected Output:
        If successful, prints the entity data structure of the last entity
        If failed, prints the error message
        
    AutoCAD Command Line Usage:
        Command line: doit2
        Result: [Entity data or error]
    """
    try:
        # Define arguments for Lisp function call (no parameters needed)
        args = [(Rx.LispType.kText, "C:GETLASTENT"), (Rx.LispType.kNone, 0)]
        
        # Execute the Lisp function through PyRx interface
        result = Ed.Core.invoke(args)
        print(result)

    except Exception as err:
        # Print any exceptions that occur during execution
        print(err)


@Ap.Command()
def doit3():
    """
    Execute the C:GETENTSEL Lisp function to retrieve selected entity data.
    
    This command calls a custom Lisp function that gets information about 
    the currently selected entity using (entget(car(entsel))).
    
    The function is called as: (C:GETENTSEL)
    
    Args:
        No arguments required - uses default command flags
        
    Example Lisp Function Definition:
        (defun C:GETENTSEL () (entget(car(entsel))))
        
    Expected Output:
        If successful, prints the entity data structure of selected entity
        If failed, prints the error message
        
    AutoCAD Command Line Usage:
        Command line: doit3
        Result: [Entity data or error]
        
    Note: This command will prompt user to select an entity before execution.
    """
    try:
        # Define arguments for Lisp function call (no parameters needed)
        args = [(Rx.LispType.kText, "C:GETENTSEL"), (Rx.LispType.kNone, 0)]
        
        # Execute the Lisp function through PyRx interface
        result = Ed.Core.invoke(args)
        print(result)

    except Exception as err:
        # Print any exceptions that occur during execution
        print(err)
