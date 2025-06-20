import traceback
from pathlib import Path

import wx

from pyrx import Sm

# this sample is based off
# https://adndevblog.typepad.com/autocad/2013/09/using-sheetset-manager-api-in-vbnet.html
# some commands require the data from http://www.hyperpics.com/au2009/CP318-4


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
            print("{}, {} ,{}".format(smdb.className(), smdb.getFileName(), smdb.getLockStatus()))

    except Exception as err:
        traceback.print_exception(err)


def PyRxCmd_pycreateSubset():
    try:

        path = "E:\\temp\\CP318-4.dst"
        mgr = Sm.SheetSetMgr()
        ssdb = mgr.createDatabase(path)
        sset = ssdb.getSheetSet()
        ssdb.lockDb()

        sset.setName("CP318-4")
        sset.setDesc("AU2009 Sheet Set Object Demo")

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
    finally:
        ssdb.unlockDb(True)


def PyRxCmd_pycreateSheetSetAddSheet():
    try:

        path = "E:\\temp"
        fullpath = "E:\\temp\\CP318-5.dst"
        dwtfullpath = "E:\\temp\\CP318-5.dwt"

        mgr = Sm.SheetSetMgr()
        ssdb = mgr.createDatabase(fullpath)

        ssdb.lockDb()

        setSheetSetDefaults(
            ssdb,
            "CP318-5",
            "AU2009 Sheet Set Object Demo",
            path,
            dwtfullpath,
            "Sheet",
            False,
        )

        addSheet(ssdb, "Title Page", "Project Title Page", "Title Page", "T1")

    except Exception as err:
        traceback.print_exception(err)
    finally:
        ssdb.unlockDb(True)


def createSubset(
    sheetSetDatabase: Sm.SmDatabase,
    name: str,
    description: str,
    newSheetLocation: str,
    newSheetDWTLocation: str,
    newSheetDWTLayout: str,
    promptForDWT: bool,
) -> None:

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


def setSheetSetDefaults(
    sheetSetDatabase: Sm.SmDatabase,
    name: str,
    description: str,
    newSheetLocation: str,
    newSheetDWTLocation: str,
    newSheetDWTLayout: str,
    promptForDWT: bool,
):

    sheetSet = sheetSetDatabase.getSheetSet()
    sheetSet.setName(name)
    sheetSet.setDesc(description)

    if len(newSheetLocation) == 0:
        newSheetLocation = str(Path(sheetSetDatabase.getFileName()).parent)

    fileReference = sheetSet.getNewSheetLocation()
    fileReference.setFileName(newSheetLocation)
    sheetSet.setNewSheetLocation(fileReference)

    if len(newSheetDWTLocation) != 0:
        layoutReference = sheetSet.getDefDwtLayout()
        layoutReference.setFileName(newSheetDWTLocation)
        layoutReference.setName(newSheetDWTLayout)
        sheetSet.setDefDwtLayout(layoutReference)

    sheetSet.setPromptForDwt(promptForDWT)


def addSheet(component: Sm.Component, name: str, description: str, title: str, number: str):

    sheet = None

    if component.getTypeName() == Sm.Subset.className():
        subset = Sm.Subset.cast(component)
        sheet = subset.addNewSheet(name, description)
        subset.insertComponentFirst(sheet)
    else:
        smdb = component.getDatabase()
        ss = smdb.getSheetSet()
        sheet = ss.addNewSheet(name, description)
        ss.insertComponentFirst(sheet)

    sheet.setNumber(number)
    sheet.setTitle(title)
