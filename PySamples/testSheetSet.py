from pyrx_imp import Rx, Ge, Gi, Db, Ap, Ed, Sm
from pathlib import Path
import traceback
import wx

def PyRxCmd_pycreatesheetset():
    try:
        path = "E:\\temp\\Test.dst"

        # Get a reference to the Sheet Set Manager object
        mgr = Sm.SheetSetMgr()
        ssdb = mgr.createDatabase(path)

        # lock the db for write
        ssdb.lockDb()
        try:
            sset = ssdb.getSheetSet()
            sset.setName("Test2")
            sset.setDesc("Lightweight Baby")
        finally:
            ssdb.unlockDb(True)
            mgr.close(ssdb)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pyopensheetset():
    try:
        path = "E:\\temp\\Test.dst"

        # Get a reference to the Sheet Set Manager object
        mgr = Sm.SheetSetMgr()
        ssdb = mgr.openDatabase(path)

        # get instance of sheetset
        sset = ssdb.getSheetSet()

        # print the name and description of the sheet set
        ssinfo = "Name={}, Desc={}".format(sset.getName(), sset.getDesc())
        wx.MessageBox(ssinfo, "WooHoo", wx.OK | wx.ICON_INFORMATION)

        # close the sheetset
        mgr.close(ssdb)

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pystepThroughTheOpenSheetSets():
    try:
        # Get a reference to the Sheet Set Manager object
        mgr = Sm.SheetSetMgr()

        #' Get the loaded databases as a list
        smdbs = mgr.getDatabases()
        print("Sheet sets open = {}: ".format(len(smdbs)))

        # iterate the databases
        for smdb in smdbs:
            print(
                "{}, {} ,{}".format(
                    smdb.className(), smdb.getFileName(), smdb.getLockStatus()
                )
            )

    except Exception as err:
        traceback.print_exception(err)


def createSubset(
    sheetSetDatabase: Sm.Database,
    name: str,
    description: str,
    newSheetLocation: str,
    newSheetDWTLocation: str,
    newSheetDWTLayout: str,
    promptForDWT: bool,
) -> None:
    try:
        sheetSetDatabase.lockDb()

        # Check to see if a path was provided
        if len(newSheetLocation) == 0:
            newSheetLocation = str(Path(sheetSetDatabase.getFileName()).parent)

        # Create a subset with the provided name and description
        sheetset = sheetSetDatabase.getSheetSet()
        subset = sheetset.createSubset(name, description)

        # Create a reference to a File Reference object
        fileref = subset.getNewSheetLocation()
        fileref.setFileName(newSheetLocation)

        # Set the location for new sheets added to the subset
        subset.setNewSheetLocation(fileref)

        # Create a reference to a Layout Reference object
        layoutref = subset.getDefDwtLayout()
        if len(newSheetDWTLocation) != 0:
            layoutref.setFileName(newSheetDWTLocation)
            layoutref.setName(newSheetDWTLayout)
            subset.setDefDwtLayout(layoutref)

        subset.setPromptForDwt(promptForDWT)

    finally:
        sheetSetDatabase.unlockDb(True)


def PyRxCmd_pycreateSubset():
    try:

        path = "E:\\temp\\CP318-4.dst"
        mgr = Sm.SheetSetMgr()
        ssdb = mgr.createDatabase(path)
        sset = ssdb.getSheetSet()
        ssdb.lockDb()
        sset.setName("CP318-4")
        sset.setDesc("AU2009 Sheet Set Object Demo")
        ssdb.unlockDb(True)

        createSubset(
            ssdb,
            "Plans",
            "Building Plans",
            "",
            "E:\\temp\\CP318-4.dwt",
            "Sheet",
            False,
        )
        
        createSubset(
            ssdb,
            "Elevations",
            "Building Elevations",
            "",
            "E:\\temp\\CP318-4.dwt",
            "Sheet",
            False,
        )

    except Exception as err:
        traceback.print_exception(err)


