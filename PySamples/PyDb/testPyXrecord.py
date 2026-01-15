"""
PyRx Command Module for XRecord Manipulation.

This module provides a command to read and modify an existing XRecord entity 
in the current AutoCAD drawing. It demonstrates how to work with XRecords, 
which are named data storage objects that can hold various types of data.

Commands:
    pyxrecord - Reads and modifies an XRecord named "AcadDim_CRX"

Functions:
    pyxrecord() -> None
        Main command function that reads and modifies an existing XRecord

Example usage:
    Run 'pyxrecord' command in AutoCAD to read and modify the AcadDim_CRX XRecord.
"""

from pyrx import Ap, Db

print("added command = pyxrecord")


@Ap.Command()
def pyxrecord() -> None:
    """
    Read and modify an existing XRecord entity named "AcadDim_CRX".

    This function performs the following operations:
    1. Gets the current database and accesses the named objects dictionary
    2. Checks if the XRecord "AcadDim_CRX" exists in the dictionary
    3. If it exists, opens the XRecord for reading and retrieves its rbChain (result buffer chain)
    4. Prints the original rbChain data
    5. Modifies a specific element in the rbChain (index 7) to change spline type
    6. Upgrades the XRecord to write mode, updates it with modified data, then downgrades back
    7. Prints the updated rbChain data

    The function demonstrates:
    - Working with named objects dictionary
    - Reading XRecord data using rbChain()
    - Modifying XRecord data by updating specific elements in the result buffer chain
    - Proper open mode management (upgrade/downgrade for write operations)

    Note: This command requires that an XRecord named "AcadDim_CRX" already exists 
    in the current drawing's named objects dictionary. If it doesn't exist, the function
    will print "fail" and exit.

    Example usage:
        In AutoCAD command line, type 'pyxrecord' then press Enter
        
    Expected behavior:
        - Prints original XRecord data (rbChain)
        - Modifies element at index 7 to set spline type flag (65, 0)
        - Prints updated XRecord data
    """
    try:
        # Get current database and named objects dictionary
        db = Db.HostApplicationServices().workingDatabase()
        nod = Db.Dictionary(db.namedObjectsDictionaryId(), Db.OpenMode.kForRead)
        
        # Check if the target XRecord exists
        if not nod.has("AcadDim_CRX"):
            print("fail")
            return

        # Get the XRecord object by name
        xid = nod.getAt("AcadDim_CRX")
        xrec = Db.Xrecord(xid, Db.OpenMode.kForRead)

        # Retrieve the result buffer chain (list of tuples representing data)
        rbChain = xrec.rbChain()
        print(rbChain)

        # Modify a specific element in the chain - change spline type flag
        rbChain[7] = (65, 0)  # Set spline type to 0 (likely indicating non-spline or default)

        # Upgrade to write mode, update with modified data, then downgrade
        xrec.upgradeOpen()
        xrec.setFromRbChain(rbChain)
        xrec.downgradeOpen()

        # Print the updated chain to verify changes
        print(xrec.rbChain())

    except Exception as err:
        print(err)
