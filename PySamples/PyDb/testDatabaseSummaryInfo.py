import traceback

from pyrx import Ap, Db


def open_db(path: str):
    """
    Opens an AutoCAD database file (.dwg) without loading it into the current session.

    Args:
        path (str): The file system path to the .dwg file.

    Returns:
        Db.Database: An open database object representing the file.
    """
    db = Db.Database(False, True)
    db.readDwgFile(path)
    db.closeInput(True)
    return db

@Ap.Command()
def doit0():
    """
    Demonstrates how to import DatabaseSummaryInfo from a side database,
    modify the metadata, and set the updated information into the current database.
    """
    try:
        # Get the currently open AutoCAD database
        db = Db.curDb()
        
        # Open a side database (06457.dwg) to read summary information from
        db_06457 = open_db("M:\\Dev\\Projects\\PyRxGit\\tests\\media\\06457.dwg")
        
        # Retrieve the DatabaseSummaryInfo object from the side database
        info = Db.DatabaseSummaryInfo(db_06457)
        
        # Print original summary information
        for k, v in info:
            print(k, v)
            
        # Check if a custom key exists and add it if not
        if not info.hasCustomKey("foo"):
            info.addCustomSummaryInfo("foo", "bar")
            
        # Print summary information after modification
        for k, v in info:
            print(k, v)
            
        # Commit the changes: set the modified info into the current database
        info.setIntoDatabase(db)
        
        # Verify the changes by printing the current database's summary info
        for k, v in Db.DatabaseSummaryInfo(db):
            print(k, v)
            
    except Exception:
        # Print stack trace if an error occurs
        traceback.print_exc()
