"""
PyRx Command Module for Context Execution Methods.

This module provides three commands that demonstrate different ways to execute 
functions within specific application contexts in AutoCAD. These methods allow 
developers to run code in controlled environments with different levels of 
isolation and synchronization.

Commands:
    exeappctx - Executes a function in the application context
    exebappctx - Begins execution in the application context
    exebcmdctx - Begins execution in the command context (session flag)

Functions:
    Data(message) -> None
        Helper class to demonstrate object lifecycle during context execution
        
    worker(args=None) -> None
        Worker function that calls classWorker() on passed arguments
        
    exeappctx() -> None
        Executes a function in the application context using executeInApplicationContext
        
    exebappctx() -> None
        Begins execution in the application context using beginExecuteInApplicationContext
        
    exebcmdctx() -> None
        Begins execution in the command context with SESSION flag

Example usage:
    Run any of the three commands to see how different context execution methods work.
"""

from pyrx import Ap

print("command = exeappctx")
print("command = exebappctx")
print("command = exebcmdctx")


class Data:
    """
    Helper class to demonstrate object lifecycle during context execution.
    
    This class is used as a data container for the worker functions. It includes
    constructors and destructors that print messages to show when objects are created
    and destroyed, helping visualize the scope of different execution contexts.
    
    Attributes:
        message (str): A string message to be printed by the worker function
    """
    def __init__(self, message):
        """Initialize Data object and print constructor message."""
        print("ctor")
        self.message = message

    def __del__(self):
        """Destructor that prints when object is destroyed."""
        print("dtor")

    def classWorker(self):
        """Method to be called by worker function - prints stored message."""
        print(self.message)


def worker(args=None) -> None:
    """
    Worker function that calls the classWorker method on passed arguments.
    
    This function serves as a bridge between context execution methods and
    the actual work to be performed. It takes an argument (typically a Data object)
    and calls its classWorker() method.
    
    Args:
        args: Object containing a classWorker method to call (default: None)
    """
    args.classWorker()


@Ap.Command()
def exeappctx() -> None:
    """
    Execute a function in the application context using executeInApplicationContext.
    
    This command demonstrates synchronous execution within the AutoCAD application
    context. It creates a Data object, gets the DocManager instance, and calls
    executeInApplicationContext which executes the worker function with the data
    as an argument, returning the result.
    
    The execution is blocking - it waits for completion before continuing.
    
    Example usage:
        In AutoCAD command line, type 'exeappctx' then press Enter
        
    Expected behavior:
        - Prints "ctor" (object creation)
        - Prints "executeInApplicationContext" 
        - Prints "dtor" (object destruction after execution)
    """
    try:
        data = Data("executeInApplicationContext")
        man = Ap.DocManager()
        print(man.executeInApplicationContext(worker, data))
    except Exception as err:
        print(err)


@Ap.Command()
def exebappctx() -> None:
    """
    Begin execution in the application context using beginExecuteInApplicationContext.
    
    This command demonstrates asynchronous execution within the AutoCAD application
    context. It creates a Data object and calls beginExecuteInApplicationContext,
    which begins executing the worker function with the data as an argument.
    
    Unlike executeInApplicationContext, this method is non-blocking - it returns 
    immediately after starting the execution.
    
    Example usage:
        In AutoCAD command line, type 'exebappctx' then press Enter
        
    Expected behavior:
        - Prints "ctor" (object creation)
        - Prints "beginExecuteInApplicationContext"
        - Prints "dtor" (object destruction after execution)
    """
    try:
        data = Data("beginExecuteInApplicationContext")
        man = Ap.DocManager()
        print(man.beginExecuteInApplicationContext(worker, data))
    except Exception as err:
        print(err)


# note the session context
@Ap.Command("exebcmdctx", Ap.CmdFlags.SESSION)
def exebcmdctx() -> None:
    """
    Begin execution in the command context with SESSION flag.
    
    This command demonstrates execution within a command's context, using the 
    SESSION command flag which makes it persistent across multiple executions
    during a single AutoCAD session. It creates a Data object and calls
    beginExecuteInCommandContext to execute the worker function.
    
    The SESSION flag ensures that this command can maintain state between 
    invocations within the same drawing session.
    
    Example usage:
        In AutoCAD command line, type 'exebcmdctx' then press Enter
        
    Expected behavior:
        - Prints "ctor" (object creation)
        - Prints "beginExecuteInCommandContext"
        - Prints "dtor" (object destruction after execution)
        
    Note: The SESSION flag makes this command behave as a persistent session
    command, useful for multi-step operations or maintaining state.
    """
    try:
        data = Data("beginExecuteInCommandContext")
        man = Ap.DocManager()
        print(man.beginExecuteInCommandContext(worker, data))
    except Exception as err:
        print(err)

