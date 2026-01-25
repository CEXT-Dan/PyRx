from collections import defaultdict
from typing import Any

from pyrx import Ap, Db, Rx


def pylisp_get_arg(args: list[tuple[Rx.LispType, Any]]):
    """
    Extract and validate a single string argument from Lisp function arguments.
    
    Args:
        args (list[tuple[Rx.LispType, Any]]): List of argument tuples containing type and value
        
    Returns:
        str: The extracted string argument value
        
    Raises:
        RuntimeError: If exactly one argument is not provided or if the argument is not a string
    """
    if len(args) != 1:
        raise RuntimeError("Expected exactly 1 argument, got {}".format(len(args)))
    t, v = args[0]
    if t != Rx.LispType.kText:
        raise RuntimeError("Expected string argument, got {}".format(t))
    return v

def proccess_drawing(db: Db.Database, data: dict[str, int]):
    """
    Process a drawing database to count block occurrences.
    
    This function operates within its own scope. This will ensure database resident objects
    are disposed before the database is garbage collected
    
    Args:
        db (Db.Database): Opened AutoCAD database object
        data (dict[str, int]): Dictionary to store block name counts
        
    Note:
        - This function creates its own scope for memory management
        - Database objects are automatically garbage collected upon function exit
        - Block names from the drawing are added to the 'data' dictionary with incremented counters
        - All database resident objects will be properly disposed before this function exits
    """
    for name in db.getBlocks().keys():
        data[name] += 1

def open_drawing(_path: str, data: dict[str, int]):
    """
    Open a DWG file and process its contents.
    
    This function operates within its own scope and performs garbage collection 
    when the function exits. The Database object created here will be automatically 
    cleaned up by Python's garbage collector after this function completes.
    
    Args:
        _path (str): File path to the DWG drawing
        data (dict[str, int]): Dictionary to store block name counts
        
    Note:
        - This function creates its own scope for memory management
        - Database objects are automatically garbage collected upon function exit
        - The function opens the DWG file, processes it, then closes it
        - All processed drawing data is accumulated in the shared 'data' dictionary
        - Database resident objects will be properly disposed before this function exits
    """
    db = Db.Database(False, True)
    db.readDwgFile(_path)
    db.closeInput(True)
    proccess_drawing(db, data)

# Lisp function entry point: (pylisp "E:\\FloorPlans")
@Ap.LispFunction()
def pylisp(args: list[tuple[Rx.LispType, Any]]):
    """
    Main Lisp function that processes all DWG files in a directory.
    
    This is the entry point for AutoCAD Lisp command 'pylisp'. It walks through
    all .dwg files in the specified directory and counts block occurrences across
    all drawings.
    
    Args:
        args (list[tuple[Rx.LispType, Any]]): List of argument tuples from AutoCAD Lisp
        
    Example usage in AutoCAD:
        Command: pylisp "E:\\FloorPlans"
        
    Note:
        - Uses defaultdict(int) for automatic zero-initialization of new keys
        - Processes all .dwg files recursively in the specified directory
        - Each drawing is processed within its own scope with independent garbage collection
        - Results are printed to the AutoCAD command line
        
    Sample output:
        defaultdict(<class 'int'>, {'Block1': 5, 'Block2': 3, ...})
    """
    try:
        data = defaultdict(int)
        _path = pylisp_get_arg(args)
        for item in Ap.Application.listFilesInPath(_path, '.dwg'):
            open_drawing(item, data)
        print(data)
    except Exception as err:
        print(err)
