from __future__ import annotations

from typing import Any, ClassVar, Collection, Iterator, Self, overload

import wx

from pyrx import Ap as PyAp
from pyrx import Db as PyDb
from pyrx import Ed as PyEd
from pyrx import Ge as PyGe
from pyrx import Gi as PyGi
from pyrx import Rx as PyRx
from pyrx.doc_utils.boost_meta import _BoostPythonEnum

eAligned: PointHistory  # 1024
eAppFiltered: PointHistory  # 2048
eCancel: PromptStatus  # -5002
eCartSnapped: PointHistory  # 16
eCoordPending: PointHistory  # 458752
eCyclingPt: PointHistory  # 64
eDidNotPick: PointHistory  # 0
eDirect: PromptStatus  # -5999
eDirectDistance: PointHistory  # 2097152
eError: PromptStatus  # -5001
eFailed: PromptStatus  # -5004
eForcedPick: PointHistory  # 4096
eFromKeyboard: PointHistory  # 524288
eGizmoConstrainted: PointHistory  # 4194304
eGripped: PointHistory  # 8
eKeyword: PromptStatus  # -5005
eLastPt: PointHistory  # 4
eModeless: PromptStatus  # 5027
eNoEmpty: PromptCondition  # 1
eNoNegative: PromptCondition  # 2
eNoZero: PromptCondition  # 1
eNone: PromptCondition  # 0
eNormal: PromptStatus  # 5100
eNotDigitizer: PointHistory  # 2
eNotInteractive: PointHistory  # 1048576
eOk: PromptStatus  # 5100
eOrtho: PointHistory  # 32
eOsnapped: PointHistory  # 128
ePickAborted: PointHistory  # 32768
ePickMask: PointHistory  # 57344
ePolarAngle: PointHistory  # 256
eRejected: PromptStatus  # -5003
eTablet: PointHistory  # 1
eUsedOsnapBox: PointHistory  # 16384
eUsedPickBox: PointHistory  # 8192
eXPending: PointHistory  # 65536
eYPending: PointHistory  # 131072
eZPending: PointHistory  # 262144
kAccept3dCoordinates: UserInputControls  # 128
kAcceptMouseUpAsPoint: UserInputControls  # 256
kAcceptOtherInputString: UserInputControls  # 2048
kAnyBlankTerminatesInput: UserInputControls  # 512
kCancel: DragStatus  # -4
kCrosshair: CursorType  # 0
kCrosshairDashed: CursorType  # 12
kCrosshairNoRotate: CursorType  # 6
kDeletedEffect: DragStyleType  # 4
kDisableDirectDistanceInput: UserInputControls  # 65536
kDontEchoCancelForCtrlC: UserInputControls  # 4
kDontUpdateLastPoint: UserInputControls  # 8
kDrawOrderAbove: DrawOrderCmdType  # 4
kDrawOrderBelow: DrawOrderCmdType  # 3
kDrawOrderBottom: DrawOrderCmdType  # 1
kDrawOrderNone: DrawOrderCmdType  # 0
kDrawOrderTop: DrawOrderCmdType  # 2
kEntitySelect: CursorType  # 8
kEntitySelectNoPersp: CursorType  # 10
kGovernedByOrthoMode: UserInputControls  # 1
kGovernedByUCSDetect: UserInputControls  # 4096
kHide: DragStyleType  # 1
kHighlight: DragStyleType  # 5
kImpliedFaceForUCSChange: UserInputControls  # 16384
kInitialBlankTerminatesInput: UserInputControls  # 1024
kInvisible: CursorType  # 7
kKW1: DragStatus  # 1
kKW2: DragStatus  # 2
kKW3: DragStatus  # 3
kKW4: DragStatus  # 4
kKW5: DragStatus  # 5
kKW6: DragStatus  # 6
kKW7: DragStatus  # 7
kKW8: DragStatus  # 8
kKW9: DragStatus  # 9
kModeless: DragStatus  # -17
kNoChange: DragStatus  # -6
kNoDwgLimitsChecking: UserInputControls  # 16
kNoNegativeResponseAccepted: UserInputControls  # 64
kNoSpecialCursor: CursorType  # -1
kNoZDirectionOrtho: UserInputControls  # 8192
kNoZeroResponseAccepted: UserInputControls  # 32
kNone: DragStyleType  # 0
kNormal: PromptStatus  # 5100
kNotRotated: CursorType  # 3
kNotSet: DragStyleType  # 6
kNull: DragStatus  # -1
kNullResponseAccepted: UserInputControls  # 2
kOther: DragStatus  # -3
kParallelogram: CursorType  # 9
kPkfirstOrGrips: CursorType  # 11
kRectCursor: CursorType  # 1
kRotatedCrosshair: CursorType  # 5
kRubberBand: CursorType  # 2
kTargetBox: CursorType  # 4
kTransparent25: DragStyleType  # 2
kTransparent75: DragStyleType  # 3
kUseBasePointElevation: UserInputControls  # 32768

class AutoSysVar:
    def __init__(self, varName: str, value, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def detach(self, val: bool, /) -> None: ...

class Core:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def addSupplementalCursorImage(
        image: wx.Image, order: int = 0, alpha: int = 255, /
    ) -> bool: ...
    @staticmethod
    def alert(msg: str, /) -> int:
        """
        Displays an alert box with an error or warning message. An alert box is a dialog box with a
        single OK button. If you want the message to have multiple lines, you can include newline
        characters (specified by n) in the string.
        """
    @staticmethod
    def arxLoad(path: str, /) -> int:
        """
        Loads an ARX module. Corresponds to the AutoLISP (arxload). acedArxLoad() returns an error
        status code when the string parameter does not specify an existing file or when the file
        cannot be loaded for some other reason.
        """
    @staticmethod
    def arxLoaded() -> list:
        """
        Returns a pointer to a list of the external ARX applications that are currently loaded. The
        name of each application is returned as a string in its own result buffer
        (resval->rstring). If no external applications are currently loaded, acedArxLoaded()
        returns NULL.
        """
    @staticmethod
    def arxUnload(app: str, /) -> int:
        """
        Unloads an ARX module. Corresponds to the AutoLISP (arxunload) function. The
        acedArxUnload() function returns an error status code when the string parameter does not
        specify a loaded ARX program or when the program to be unloaded has dependents registered
        on its services.
        """
    @staticmethod
    def audit(db: PyDb.Database, fix: bool, echo: bool = False, /) -> None:
        """
        This function audits the AcDbDatabase pointed to by pDb.
        """
    @staticmethod
    def autoSetVar(name: str, value, /) -> AutoSysVar: ...
    @staticmethod
    def calcTextExtents(val: str, textStyleId: PyDb.ObjectId, /) -> tuple[float, float]: ...
    @staticmethod
    def callBackOnCancel() -> None:
        """
        If you have made a call to acedCommandC or acedCmdC and wish to have your registered
        callback called when a CANCEL or other error occurs, call this function before returning.
        If you don't call this function and a CANCEL or other error occurs, your callback will not
        be called, instead AutoCAD will directly cancel the command state.
        """
    @staticmethod
    def clearOLELock(handle: int, /) -> bool:
        """
        This function is for use with OLE Automation applications. Whenever such an application
        uses any of the ObjectARX API functions, it must call acedSetOLELock() to set a lock. When
        the lock is set, the application calls this function to clear the lock and allow other OLE
        applications their chance to lock and use ObjectARX API functions. handle is a lock 'code'
        integer that is used to make sure that the setting and clearing of the lock are done by the
        same application. Both acedSetOLELock() and this function must be passed this integer lock
        code as an identifier. If handle is a different code than was used to set the lock, then
        the clear attempt will fail. Returns Adesk::kTrue is the lock is successfully cleared,
        otherwise returns Adesk::kFalse.
        """
    @staticmethod
    def clipFormatName() -> str:
        """
        Returns the clipboard format name string for the product. This string is the same for all
        AutoCAD based products, but is different for OEM and LT products. This function replaces
        the CF_AUTOCAD macro.
        """
    @staticmethod
    def cmdCWasCancelled() -> bool:
        """
        When your registered callback is called in response to a CANCEL or error, this function
        will return true, else it will return false.
        """
    @overload
    @staticmethod
    def cmdS(commandName: str, /) -> bool:
        """
        This function does the same thing with the same restructions as acedCommandS, with a resbuf
        chain rather than a veriable arguments list. Two more supplied parameters are intended for
        future use.
        """
    @overload
    @staticmethod
    def cmdS(resultBuffer: list[tuple[int, Any]], /) -> bool:
        """
        This function does the same thing with the same restructions as acedCommandS, with a resbuf
        chain rather than a veriable arguments list. Two more supplied parameters are intended for
        future use.
        """
    @overload
    @staticmethod
    def cmdS(*args) -> bool:
        """
        This function does the same thing with the same restructions as acedCommandS, with a resbuf
        chain rather than a veriable arguments list. Two more supplied parameters are intended for
        future use.
        """
    @staticmethod
    def cmdUndefine(name: str, undefineit: int, /) -> int:
        """
        This function searches the command stack of registered commands for the command name cmdstr
        and if found sets (if undefit == 1) or unsets (if undefit == 0) the 'undefine' bit in the
        command flags for that command. If the 'undefine' bit is set, then AutoCAD will treat this
        command as though it is undefined in the same way that internal AutoCAD commands are
        treated if they have been undefined via the AutoCAD UNDEFINE command.
        """
    @overload
    @staticmethod
    def coordFromPixelToWorld(pt: tuple[int, int], /) -> PyGe.Point3d:
        """
        Converts coordinates from AutoCAD drawing window to current active viewport's coordinates.
        Returns TRUE if it successfully converts the coordinates; otherwise, it returns FALSE.
        """
    @overload
    @staticmethod
    def coordFromPixelToWorld(winnum: int, pt: tuple[int, int], /) -> PyGe.Point3d:
        """
        Converts coordinates from AutoCAD drawing window to current active viewport's coordinates.
        Returns TRUE if it successfully converts the coordinates; otherwise, it returns FALSE.
        """
    @overload
    @staticmethod
    def coordFromPixelToWorld(*args) -> PyGe.Point3d:
        """
        Converts coordinates from AutoCAD drawing window to current active viewport's coordinates.
        Returns TRUE if it successfully converts the coordinates; otherwise, it returns FALSE.
        """
    @staticmethod
    def coordFromWorldToPixel(windnum: int, pnt: PyGe.Point3d, /) -> tuple[int, int]:
        """
        Converts coordinates in given viewport to Windows screen coordinates. Returns TRUE if it
        successfully converts the coordinates; otherwise, returns FALSE.
        """
    @staticmethod
    def createInternetShortcut(szURL: str, szShortcutPath: str, /) -> bool:
        """
        Creates an MSIE-compatible Internet shortcut using the arguments passed to it.
        """
    @staticmethod
    def createViewportByView(
        db: PyDb.Database, view: PyDb.ObjectId, pt: PyGe.Point2d, scale: float, /
    ) -> PyDb.ObjectId:
        """
        This function creates a viewport for the given model view at the desired location. It bases
        the size of the viewport on the scale factor and the size of the model view. For example, a
        model view 20 feet across and a scale of one foot to a quarter inch would yield a viewport
        that was five inches across on the paper of the layout. This call assumes that the viewport
        is being created in the current layout. Returns eOk on success. Possible error codes
        include Acad::eNotInPaperspace if not currently in a layout, Acad::eWrongDatabase if the
        AcDbDatabase passed in was not the current database, various open errors if the
        AcDbViewTableRecord could not be opened, or Acad::eInvalidInput if another error occurred
        preventing the creation of the viewport.
        """
    @staticmethod
    def curDwgXrefGraph() -> PyDb.XrefGraph: ...
    @staticmethod
    def defun(name: str, funcnumber: int, /) -> int:
        """
        Defines an ARX application function as an external AutoLISP function and clears any
        existing acedSetFunHelp() reference. Once a function in an ARX application has been defined
        by a call to acedDefun(), it can be called from AutoLISP. When AutoLISP sends an
        kInvkSubrMsg message to the application, the funcno for the function can be retrieved by a
        call to acedGetFunCode(), and any arguments can be retrieved by a call to acedGetArgs(). As
        in AutoLISP, if the first characters of sname are C:, you can invoke the function as an
        AutoCAD command without enclosing its name in parentheses. You can invoke it also as a
        function, provided that the prefix C: is included as part of its name. Warning If two or
        more external applications define functions that have the same name, AutoLISP can recognize
        only the most recently defined external function. The previously loaded function will be
        lost. The acedSetFunHelp() function is usually called directly after acedDefun() to
        register command line help for the defined function. AutoLISP saves function and command
        names in uppercase characters, but if pszName is lowercase, acedDefun() converts it before
        passing it to AutoLISP. AutoLISP binds functions defined by acedDefun() to the Exsubr
        symbol type. Warning If the application defines a C:XXX command whose name conflicts with a
        built-in command or with a command name defined in the acad.pgp file, AutoCAD does not
        recognize the external function as a command (though it can still be invoked as an AutoLISP
        external function). For example, after the call to acedDefun('c:cp', 0), a user input of cp
        invokes the AutoCAD COPY command (this alias is defined in the sample acad.pgp), but the
        user could invoke the external function with (c:cp). Function names defined by acedDefun()
        can be undefined by calling acedUndef(). This removes the function name from the AutoLISP
        atom list. After a function has been undefined, an attempt to invoke it causes an error. If
        acedDefun() succeeds, it returns RTNORM; otherwise, it returns an error code.
        """
    @staticmethod
    def defunEx(globalName: str, name: str, funcnumber: int, /) -> int:
        """
        Defines an ARX application function as an external AutoLISP function and clears any
        existing acedSetFunHelp() references. It is similar to acedDefun(), but takes both global
        and local name arguments. If you want to set up global and local names for the same
        function, please use a single call to acedDefunEx(), rather than two calls to acedDefun().
        Once a function in an ARX application has been defined by a call to acedDefunEx(), it can
        be called from AutoLISP. When AutoLISP sends an kInvkSubrMsg message to the application,
        the nFuncNum for the function can be retrieved by a call to acedGetFunCode(), and any
        arguments can be retrieved by a call to acedGetArgs(). As in AutoLISP, if the first
        characters of the name are C:, you can invoke the function as an AutoCAD command without
        enclosing its name in parentheses. You can invoke it also as a function, provided that the
        prefix C: is included as part of its name. Warning: If two or more external applications
        define functions that have the same name, AutoLISP can recognize only the most recently
        defined external function. The previously loaded function will be lost. The
        acedSetFunHelp() function is usually called directly after acedDefunEx() to register
        command line help for the defined function. It is also common to call acedRegFunc()
        immedately after acedDefunEx(). This frees your application from the need to handle
        kInvkSubrMsg messages. AutoLISP saves function and command names in uppercase characters,
        but if the name is lowercase, acedDefunEx() converts it before passing it to AutoLISP.
        AutoLISP binds functions defined by acedDefunEx() to the Exsubr symbol type. Warning: If
        the application defines a C:XXX command whose name conflicts with a built-in command or
        with a command name defined in the acad.pgp file, AutoCAD does not recognize the external
        function as a command (though it can still be invoked as an AutoLISP external function).
        For example, after the call to acedDefunEx('c:cp', 0), a user input of cp invokes the
        AutoCAD COPY command (this alias is defined in the sample acad.pgp), but the user could
        invoke the external function with (c:cp). Function names defined by acedDefunEx() can be
        undefined by calling acedUndef(). This removes the function name from the AutoLISP atom
        list. After a function has been undefined, an attempt to invoke it causes an error.
        """
    @staticmethod
    def disableDefaultARXExceptionHandler(val: bool, /) -> None:
        """
        This function will disable (if disable is Adesk::kTrue) or enable (if disable is
        Adesk::kFalse) exception handling in AutoCAD for exceptions thrown while code is executing
        in an ObjectARX or ObjectDBX module. When AutoCAD starts up, this exception handling is
        enabled. Disabling this exception handling allows applications to do their own exception
        handling of exceptions thrown while an ObjectARX or ObjectDBX module is executing.
        """
    @staticmethod
    def disableUsrbrk() -> None:
        """
        This function disables the user break mechanism for the current document.
        """
    @staticmethod
    def displayBorder(val: bool, /) -> bool:
        """
        Shows or hides a blue border around the inner edge of the drawing area of the current
        window. This behavior is used with the Drawing Compare feature (COMPARE command).
        """
    @staticmethod
    def drawOrderInherit(
        parent: PyDb.ObjectId, childids: list[PyDb.ObjectId], cmd: PyEd.DrawOrderCmdType, /
    ) -> None:
        """
        This function is called to set the draw order on a new child array object or objects. It
        should be called after the child array objects are added to the database, but before they
        are regen'ed, so that they are regen'ed to the proper location the first time. If cmd
        argument is kDrawOrderBelow or kDrawOrderAbove, then a valid parent ID must be supplied,
        and children objects are placed either just below or just above the parent entity,
        visually. If the cmd argument is kDrawOrderTop or kDrawOrderBottom, the parent entity can
        be null and any parent value is ignored because the entity is moving to the very top or
        bottom of draw order. The parent and all child entities must all be in the same space
        (model, paper, or a given block).
        """
    @staticmethod
    def drawingStatusBarsVisible() -> bool:
        """
        This global method returns a value indicating whether or not the drawing status bars are
        visible in AutoCAD. By default, the drawing status bars are hidden in AutoCAD. Use this
        method to query the display state of the drawing status bars. If the display state is
        FALSE, acedShowDrawingStatusBars() can be used to display the drawing status bars in
        AutoCAD.
        """
    @staticmethod
    def dropOpenFile(val: str, /) -> None: ...
    @staticmethod
    def eatCommandThroat() -> int:
        """
        For internal use only.
        """
    @staticmethod
    def editMTextInteractive(mt: PyDb.MText, usenewUI: bool, allowTabs: bool, /) -> int:
        """
        Invokes the MTEXT user interface.
        """
    @staticmethod
    def enableUsrbrk() -> None:
        """
        This function enables the user break mechanism for the the current document.
        """
    @staticmethod
    def evaluateDiesel(statement: str, /) -> str: ...
    @staticmethod
    def evaluateLisp(statement: str, /) -> list: ...
    @staticmethod
    def exceptionTest() -> str: ...
    @staticmethod
    def findFile(fname: str, /) -> str:
        """
        Deprecated. Searches for the specified file. The result argument must point to a buffer
        large enough to hold the qualified file name: depending on the directory structure of the
        current environment, this can be quite long. The maximum length of result is platform
        dependent. On platforms that restrict file-name length, it is 78 characters; on platforms
        that don't restrict file-name length, it is 511. This function makes no assumption about
        the type of the file, and does not attempt to append any kind of file-name extension. If
        the file you are searching for does have an extension to its name, the extension must be
        included in the fname argument. If fname is qualified by including a drive or directory
        prefix (for example, 'd:test.exp'), acedFindFile() searches only that disk or directory.
        Otherwise, acedFindFile() searches for fname according to the current AutoCAD library path,
        which consists of the following directories, in order: The current directoryThe directory
        that contains the current drawing fileThe directories named by the ACAD environment
        variable (if this variable has been specified)The directory that contains the AutoCAD
        program files Depending on the current environment, two or more of these directories may be
        the same. If acedFindFile() finds the file, it returns RTNORM; otherwise, it returns
        RTERROR.
        """
    @staticmethod
    def findTrustedFile(fname: str, /) -> str:
        """
        Deprecated. Searches the AutoCAD trusted file paths for the specified file. The command
        looks for the file in the regular AutoCAD search path. If a match is found, it verifies if
        the file path is part of trustedpaths. If the file is not present in any of the directories
        in the trusted file paths, the function returns NULL
        """
    @staticmethod
    def getAcadDockCmdLine() -> int:
        """
        This function is used to get the AutoCAD's Command Line window. For building ObjectARX
        applications with a static MFC library, or when not using the same shared MFC DLL as
        AutoCAD, a pointer to a window cannot be used. Instead, use the window handle. To get the
        window handle, use acedGetAcadDockCmdLine()->m_hWnd;
        """
    @staticmethod
    def getAcadTextCmdLine() -> int:
        """
        This function is used to get the AutoCAD's Text Command Line window. For building ObjectARX
        applications with a static MFC library, or when not using the same shared MFC DLL as
        AutoCAD, a pointer to a window cannot be used. Instead, use the window handle. To get the
        window handle, use acedGetAcadTextCmdLine()->m_hWnd;
        """
    @staticmethod
    def getBlockEditMode() -> int:
        """
        This function returns the current BlockEdit mode value. The possible values are defined in
        the BlockEditModeFlags enum. The returned value may be a bitwise combination of the various
        enum values.
        """
    @staticmethod
    def getCfg(val: str, /) -> str:
        """
        Deprecated. Retrieves application data from the AppData section of the acad.cfg file.
        """
    @staticmethod
    def getCommandForDocument(doc: PyAp.Document, /) -> str:
        """
        Gets the global or local name of the innermost current command for the given document.
        """
    @staticmethod
    def getCommandPromptString() -> str: ...
    @staticmethod
    def getCommands() -> dict: ...
    @staticmethod
    def getCurVportPixelToDisplay() -> tuple[float, float]:
        """
        This function sets xFactor and yFactor to the x and y pixel space to display space
        conversion factors for the current viewport. These values represent the size of a pixel in
        display coordinates. If there is no current viewport, then both are set to 0.0.
        """
    @staticmethod
    def getCurVportScreenToDisplay() -> tuple[float, float]:
        """
        This function sets xFactor and yFactor to the x and y screen space to display space
        conversion factors for the current viewport. If there is no current viewport, then both are
        set to 0.0.
        """
    @staticmethod
    def getCurrentSelectionSet() -> list[PyDb.ObjectId]:
        """
        This function fills sset in with the object IDs of all entities in the current selection
        set within AutoCAD. The 'current selection set' may be one of the following: a pickfirst
        set, a selection set selected by the select command or any other command that does a
        selection (that is, similar to the 'Previous' selection option), or the most recent set
        from an ssget. If a pickfirst set is available it will always be used. If no pickfirst set
        is available, then whichever of the other two types is available will be used. If both of
        the other two types are available, then whichever was most recently created will be used.
        If a pickfirst selection set is 'selected' by a call to this function, then the entity
        highlighting and grips will disappear just as they would when any AutoCAD command uses a
        pickfirst selection set. If an ssget type of selection is 'selected' by a call to this
        function, then sset will essentially be a copy of the selection set and the original ssget
        selection set will still be valid. Only certain AutoCAD commands create a selection set
        that can be found by acdbGetCurrentSelectionSet(). These commands are listed below: ACISOUT
        AMECONVERT ARRAY ATTEXT AUDIT BHATCH BMPOUT CHANGE CHPROP CONVERT CONVERTPOLY COPY COPYCLIP
        CUTCLIP DIVIDE DVIEW DXFOUT (partial) ERASE EXPLODE EXTEND EXTRUDE GROUP HATCH HIDE
        INTERFERE INTERSECT LIST MASSPROP MEASURE MIRROR MOVE MVIEW OOPS PEDIT REGION REVOLVE
        ROTATE SCALE SECTION SELECT SLICE SPELL SPLINE STLOUT STRETCH SUBTRACT TRIM UNION VPVIS
        WBLOCK WMFOUT XCLIP
        """
    @staticmethod
    def getCurrentView() -> PyDb.ViewTableRecord: ...
    @staticmethod
    def getDpiScalingValue() -> float:
        """
        Returns DPI scaling value for Windows system. Returns 1.0 on Mac platform.
        """
    @staticmethod
    def getEnv(val: str, /) -> str:
        """
        Deprecated. Retrieves the value of an environment variable. Looks first in the
        AutoCAD-specific FixedProfile/General section of the registry: HKEY_CURRENT_USER Software
        Autodesk AutoCAD R25.0 <Install ID> FixedProfile GeneralIf an entry is not found in the
        registry, retrieves the value from the Windows system environment table.
        """
    @staticmethod
    def getFileD(title: str, defawlt: str, ext: str, flags: int, /) -> str:
        """
        Prompts the user for a file name with the standard AutoCAD file dialog box.WarningThis
        function must never be called in zero-document state. Always check to see if any documents
        are loaded in the editor before calling this function. You can do this with the
        AcApDocManager::curDocument() function, which returns null if no documents are opened in
        the editor. The title argument specifies the caption of the entire dialog box, defawlt
        specifies the default file name (which can be NULL), and ext is the default file-name
        extension (if passed as NULL, ext defaults to *). If the default file name is NULL or
        specifies only a path, the Default button in the dialog box is disabled. Beginning with
        AutoCAD Release 13, the ext argument accepts multiple filename extensions separated by
        semicolons, as shown in the following example call to acedGetFileD(): const char* filea =
        'myfile.dwg';result = acutNewRb(RTSTR);acedGetFileD(filea, NULL, 'dwg;eps;abc', 33,
        result);If the dialog box gets a filename from the user, acedGetFileD() sets the string in
        the result argument to a string specifying the filename. The acedGetFileD() function
        allocates memory for the pathname string. Your program is responsible for freeing the
        string by calling free() (if result is a static buffer) or acutRelRb() (if result is a
        dynamically allocated resbuf). The maximum length of a pathname is platform dependent. On
        platforms that restrict filename length, it is 78 characters; on platforms that don't
        restrict filename length, it is 511. The effects of user responses are defined in the
        following ways: Response Action OK Prevents the function from returning unless a file name
        is selected Cancel Returns RTERROR Help Brings up the help dialog box but doesn't close
        acedGetFileD() The flags argument is a bit-coded field that controls the behavior of the
        dialog box. To set more than one condition at a time, add the values together to create a
        flags value between 0 and 127. The control bits have the following meanings: Value Use
        Description Bit 0 (= 1 if set) Indicates a request to create a new file Set this bit when
        you include a prompt for the name of a new file to create. Leave bit 0 set to 0 when you
        include a prompt for the name of an existing file to open. In this case, if the user enters
        the name of a nonexistent file, the dialog box displays an error message at the bottom of
        the box.If bit 0 is set (create) and the user enters an existing file name for a new file,
        acedGetFileD() displays an alert box to warn the user that the file exists and to offer the
        choice of proceeding with or canceling the operation.If bit 0 is not set (open) and bit 2
        is not set, only the default extension (or none) is accepted. If no extension is entered,
        the default extension is automatically used. If the user enters any extension other than
        the default, an 'Invalid filename' message box is displayed and the user is required to try
        again or cancel.If bit 0 is set (create) and bit 2 is not set, the default extension is
        added if it is not entered as part of the file name.
        """
    @staticmethod
    def getFileNavDialog(title: str, defawlt: str, ext: str, dlgname: str, flags: int, /) -> list:
        """
        The acedGetFileNavDialog() function prompts the user for a file name using the AutoCAD file
        navigation dialog box. The title argument specifies the caption of the entire dialog box;
        default specifies the default file name (which can be null); and ext is the default file
        name extension (if passed as null, ext defaults to '*'). The ext argument accepts multiple
        file name extensions separated by semicolons, as shown in the following example call to
        acedGetFileNavDialog(): const ACHAR * filea = 'myfile.dwg';const ACHAR * dlgname = 'My File
        Dialog';struct resbuf* result = NULL;acedGetFileNavDialog(filea, NULL, 'dwg;eps;abc',
        dlgname, 33, &result);//... do whatever with resultacutRelRb(result); The dlgname argument
        specifies a name for the dialog. This name is used as a key in the Windows registry for
        saving dialog-persistent data such as size and position. For example, in the code above,
        the dialog's position and size are stored in the user's profile under the Dialogs>My File
        Dialog key. If the dialog box gets a file name (or names) or a folder name from the user,
        acedGetFileNavDialog() allocates a resbuf chain for the result. Your program is responsible
        for freeing the resbuf chain by calling acutRelRb(). The effects of user responses are
        defined in the following ways: Response Action Open Prevents the function from returning
        unless a file name is selected Cancel Returns RTERROR The flags argument is a bit-coded
        field that controls the behavior of the dialog box. To set more than one condition at a
        time, add the values together to create a flags value between 0 and 65535. The control bits
        have the following meanings: Value Use Description Bit 0 (= 1 if set) Indicates a request
        to create a new file Set this bit when you include a prompt for the name of a new file to
        create. Leave bit 0 set to 0 when you include a prompt for the name of an existing file to
        open. In this case, if the user enters the name of a nonexistent file, the dialog box
        displays an error message at the bottom of the box.If bit 0 is set (create) and the user
        enters an existing file name for a new file, acedGetFileNavDialog() displays an alert box
        to warn the user that the file exists and to offer the choice of proceeding with or
        canceling the operation.If bit 0 is not set (open) and bit 2 is not set, only the default
        extension (or none) is accepted. If no extension is entered, the default extension is
        automatically used. If the user enters any extension other than the default, an 'Invalid
        filename' message box is displayed and the user is required to try again or cancel.If bit 0
        is set (create) and bit 2 is not set, the default extension is added if it is not entered
        as part of the file name.
        """
    @staticmethod
    def getLastCommandLines(lineCount: int, ignoreNull: bool, /) -> list[str]: ...
    @staticmethod
    def getMousePositionUCS() -> PyGe.Point3d: ...
    @staticmethod
    def getMousePositionWCS() -> PyGe.Point3d: ...
    @staticmethod
    def getPredefinedHatchPatterns() -> list[str]: ...
    @staticmethod
    def getRGB(colorIndex: int, /) -> tuple[int, ...]:
        """
        This function returns a RGB color value in Win32 COLORREF (0x00bbggrr) format for the color
        specified by the AutoCAD Color Index (ACI) number. The ACI number must be a value between 0
        and 255. If this function is passed a value less than 0 or greater than 255, then the
        return value will be meaningless.
        """
    @staticmethod
    def getSupplementalCursorOffset() -> tuple: ...
    @staticmethod
    def getSym(val: str, /) -> list:
        """
        Retrieves the value of a bound AutoLISP symbol. This function can be used in the ARX
        program environment only when AutoCAD sends the message kInvkSubrMsg to the application. If
        the AutoLISP symbol is bound to a value of a type that can't be represented by a list of
        ARX result buffers (such as a subr or exsubr), the acedGetSym() call fails. If the symbol
        is not found or is nil, acedGetSym() returns RTNORM and sets the contents of value (*value)
        to null. The acedGetSym() function returns RTNORM if it succeeds and RTERROR if it fails.
        It returns RTMODELESS, if the active command was registered using the
        ACRX_CMD_INTERRUPTIBLE flag and the document has received a modeless interrupt signal from
        a call to AcApDocManager::sendModelessInterrupt(). When acedGetSym() fails, it sets the
        system variable ERRNO to a value that indicates the reason for the failure.
        """
    @staticmethod
    def getSysVars() -> dict: ...
    @staticmethod
    def getUserFavoritesDir() -> str:
        """
        This function provides access to the Windows Favorites directory of the current user.
        """
    @staticmethod
    def getVar(name: str, /) -> object:
        """
        Retrieves the current value of the specified AutoCAD system variable. The result argument
        must point to a resbuf structure, because the system variables consist of a variety of
        types. Warning The result argument must point to an allocated resbuf (it can be static,
        automatic, or dynamically allocated). It must not be declared as just a pointer; if the
        application doesn't allocate enough space for the resbuf structure, acedGetVar() will
        return garbage or corrupt other data in memory. If the requested system variable is a
        string value, acedGetVar() dynamically allocates the memory needed to hold the string. The
        ARX application is responsible for releasing this memory. This can be accomplished by a
        call to the C utility function free(), or by a call to acutRelRb() if the buffer used for
        the result argument was allocated dynamically. This function is the complement of the
        acedSetVar() function. If acedGetVar() succeeds, it returns RTNORM; otherwise, it returns
        an error code.
        """
    @staticmethod
    def getWinNum(ptx: int, pty: int, /) -> int:
        """
        Provide coordinates in AutoCAD drawing window (in client coordinates) and this function
        will return the viewport number the coordinates correspond to. This function usually is
        used with acedCoordFromWorldToPixel() or acedCoordFromPixelToWorld(). Returns the viewport
        number based on Windows client coordinates.
        """
    @staticmethod
    def grDraw(
        pt1: PyGe.Point2d | PyGe.Point3d,
        pt2: PyGe.Point2d | PyGe.Point3d,
        color: int,
        highlight: int,
        /,
    ) -> int:
        """
        Draws a vector between two points in the current viewport. AutoCAD clips the vector as
        required to fit the screen. Highlighting, controlled by the hl argument, depends on the
        display device. Most display drivers indicate highlighting by a dashed line, but some
        indicate it by using a distinctive color. Unless a critical error occurs, acedGrDraw()
        returns RTNORM.
        """
    @staticmethod
    def grDrawArc(
        pt1: PyGe.Point3d, pt2: PyGe.Point3d, pt3: PyGe.Point3d, numsegs: int, color: int, /
    ) -> int: ...
    @staticmethod
    def grDrawBox(pts: list[PyGe.Point3d], color: int, highlight: int, /) -> int: ...
    @staticmethod
    def grDrawCircle(cen: PyGe.Point3d, radius: float, numsegs: int, color: int, /) -> int: ...
    @staticmethod
    def grDrawPoly2d(pts: list[PyGe.Point2d], color: int, /) -> int: ...
    @staticmethod
    def grDrawPoly3d(pts: list[PyGe.Point3d], color: int, /) -> int: ...
    @staticmethod
    def grText(box: int, text: str, hl: int, /) -> int:
        """
        Displays the specified text in the menu, mode, or status area of the graphics screen. If
        box equals the number of a screen menu box and hl is less than 0, acedGrText() displays
        text in that box. The menu boxes are numbered beginning at 0. If the value of box is
        greater than the number of menu boxes minus one, the call to acedGrText() usually has no
        effect. If box specifies a screen menu box and hl is greater than 0, the text displayed by
        acedGrText() is highlighted. If hl equals 0 and the box is highlighted, acedGrText() turns
        highlighting off. (Remember that AutoCAD allows only one menu box to be highlighted at a
        time. A call that highlights a different box automatically turns off any previous
        highlighting.) When hl is greater than or equal to 0, the text argument is ignored. If box
        equals -1, acedGrText() writes the text into the mode status line (the hl argument is
        ignored). The length of the mode status line differs from display to display; most allow at
        least 40 characters. If text contains more characters than the mode status line allows, it
        is truncated; if it contains fewer characters, it is padded with blanks. If box equals -2,
        acedGrText() writes the text into the coordinate status line (the hl argument is ignored).
        If coordinate tracking is turned on, any value written into this field is overwritten as
        soon as the pointer sends another set of coordinates. Finally, if box is less than -2 (for
        example: box equals -5), acedGrText() restores all the text areas on the screen to their
        standard values. If it succeeds, acedGrText() returns RTNORM. It returns RTERROR if the box
        number is out of range.
        """
    @staticmethod
    def grVecs(resbuf: list, xform: PyGe.Matrix3d, /) -> int:
        """
        Draws multiple vectors on the graphics screen. Result-buffer elements in the vlist can be
        as follows: A pair of points (RTPOINT or RT3DPOINT) that specify the endpoints of the
        vector, expressed in the current UCS; these can be three-dimensional points.
        """
    @staticmethod
    def graphScr() -> None:
        """
        On single-screen AutoCAD installations, causes the display to switch from the text screen
        to the graphics screen. This is equivalent to using the AutoCAD GRAPHSCR command or to
        pressing the Flip Screen function key (when the text screen is current). The acedTextScr()
        function is the complement of acedGraphScr(). If acedGraphScr() succeeds, it returns
        RTNORM; otherwise, it returns an error code.
        """
    @staticmethod
    def hasSupplementalCursorImage() -> bool: ...
    @staticmethod
    def hatchPalletteDialog(pattern: str, custom: bool, /) -> str: ...
    @staticmethod
    def initDialog(useDialog: bool, /) -> bool:
        """
        This function sets an internal flag in AutoCAD so that when a command that has a dialog
        that is normally not activated by LISP (such as the PLOT command) is run, the dialog will
        be activated rather than using the command line interface. If useDialog is Adesk::kTrue,
        then the next use (and next use only) of the command (such as PLOT) when run from LISP or
        ObjectARX, will display the command's dialog rather than its command line prompts. If
        useDialog is Adesk::kFalse, then any previous call to this function (or the LISP (initdia)
        function) to tell AutoCAD to display dialogs will be cleared so that the default behavior
        of presenting the command line interface will be restored. Returns the value that the
        internal flag was set to before this function was called.
        """
    @staticmethod
    def invoke(resultBuffer: list, /) -> list:
        """
        Invokes an external function defined in another ARX application. When acedInvoke() returns
        RTNORM, this implies that the external function was called and returned successfully. It
        does not imply that the external function successfully obtained a result. To determine the
        result, your program must inspect the result argument. If the external function failed or
        returned no value, result will be NULL; otherwise, result points to a list of return
        values. The external function being invoked must be an external function in an ARX
        application currently loaded. From the external function's point of view, the acedInvoke()
        call is invisible. It retrieves its arguments by calling acedGetArgs() and returns a value
        by calling one of the value-return functions (acedRetInt(), acedRetReal(), and so on), as
        it does when invoked by an AutoLISP function or by the AutoCAD user. Warning If the
        external function being invoked has been registered (in its application) by a call to
        acedRegFunc(), another function in the same application can call it--directly or
        indirectly--with acedInvoke(). Otherwise, acedInvoke() returns RTERROR. This also applies
        to a calling sequence that the first function initiates. If the calling chain leads back
        into the same application, acedInvoke() returns RTERROR unless the function in the same
        application has been registered by acedRegFunc(). To avoid acedInvoke() failure, be certain
        that all external functions that are meant to be called by acedInvoke() are registered by a
        call to acedRegFunc() after their application has successfully called acedDefun(). The
        first result buffer in the args list must contain the name of the external function. If the
        function was defined as an AutoCAD command, the string must include the C: prefix. The
        remaining result buffers in the args list must match the external function's argument list
        in their order, types, and value ranges. If the external function has called acedRetList(),
        result points to a list of values.
        """
    @staticmethod
    def isDragging() -> int:
        """
        This function indicates whether dragging is occurring in AutoCAD's editor. Returns 0 if no
        dragging is occurring, and a non-zero value otherwise.
        """
    @staticmethod
    def isInBackgroundMode() -> bool:
        """
        This function returns true if the AutoCAD session in which it is called is running in
        background mode for plotting.
        """
    @staticmethod
    def isInputPending() -> bool:
        """
        This function should be called from a dialog after a user-interactive action has been
        canceled. If this function returns false, the dialog should be restored. Otherwise, the
        dialog should be terminated in order to allow the queued input to be processed by AutoCAD.
        """
    @staticmethod
    def isMenuGroupLoaded(mnu: str, /) -> bool:
        """
        This function checks to see if the menugroup pszGroupName is currently loaded in the
        AutoCAD editor. Returns Adesk::kTrue if the pszGroupName menugroup is currently loaded, or
        Adesk::kFalse if not.
        """
    @staticmethod
    def isOsnapOverride() -> bool:
        """
        Informs a custom Osnap routine whether it was called by a running Osnap or an Osnap
        override. In other words, this function returns true if a custom Osnap routine was called
        by an Osnap override.
        """
    @staticmethod
    def isUpdateDisplayPaused() -> bool:
        """
        Returns true if display updates are paused, or false otherwise. This function should be
        used before calling acedUpdateDisplayPause(), to record the current update display pause
        state and restore that when finished pausing the display. This prevents other users of
        acedUpdateDisplayPause() from having the display re-enabled prematurely.
        """
    @staticmethod
    def isUsrbrkDisabled() -> bool:
        """
        This function returns true if the user break mechanism is enabled for the current document.
        """
    @staticmethod
    def lineWeightDialog(lt: PyDb.LineWeight, includeByBlockByLayer: bool, /) -> tuple: ...
    @staticmethod
    def linetypeDialog(id: PyDb.ObjectId, includeByBlockByLayer: bool, /) -> tuple: ...
    @staticmethod
    def loadJSScript(scr: str, /) -> None: ...
    @staticmethod
    def loadMainMenu(mnu: str, /) -> bool: ...
    @staticmethod
    def loadPartialMenu(mnu: str, /) -> bool:
        """
        Adds (loads) a partial menu to the current main menu.
        """
    @staticmethod
    def mSpace() -> None:
        """
        When called in a layout, this function switches the editor to model space. Returns
        Acad::eOk if successful, or if the editor is already in model space. Returns
        Acad::eInvalidInput if TILEMODE is set to 1, or if there is no current drawing. Returns
        Acad::eCannotChangeActiveViewport if no on-screen viewports are available for switching.
        """
    @staticmethod
    def markForDelayXRefRelativePathResolve(id: PyDb.ObjectId, /) -> None:
        """
        Marks the input Xref definition object ID that helps to delay resolving its referenced file
        path type to relative . This function should be used for unnamed host drawing, in which the
        host drawing's file path is still not determined until it is saved, so relative type path
        cannot be saved in Xref definitions with this function. These marked XRef definitions will
        be resolved to relative path when the host drawing is saved.
        """
    @staticmethod
    def menuCmd(cmd: str, /) -> int: ...
    @staticmethod
    def osnap(pt: PyGe.Point3d, mode: str, /) -> PyGe.Point3d:
        """
        Finds a point by means of object snap. Applies the specified Object Snap modes to find the
        closest point to a reference point. The APERTURE system variable determines the allowable
        proximity of a selected point to an entity when using Object Snap. If acedOsnap() can find
        a point, it returns RTNORM; otherwise, it returns an error code.
        """
    @staticmethod
    def pSpace() -> None:
        """
        When called in a layout, this function switches the editor to paper space. Returns
        Acad::eOk if successful, or if the editor is currently in paper space. Returns
        Acad::eInvalidInput if TILEMODE is set to 1, or if there is no current drawing.
        """
    @staticmethod
    def postCommand(str: str, /) -> None: ...
    @staticmethod
    def postCommandPrompt() -> None:
        """
        This function causes AutoCAD to repost the last command prompt message. This is intended to
        be used from OLE applications that are invoked without going through the normal AutoCAD
        user interface. In such a case this function should be called just prior to exiting from
        the OLE application.
        """
    @staticmethod
    def prompt(val: str, /) -> int:
        """
        Displays the specified string on the command line of the AutoCAD graphics screen. If the
        length of the string is greater than the prompt line length (typically no more than 80
        characters), the characters may wrap around and be visible on the text screen. On some
        platforms, however, they will be truncated. The acedPrompt() function returns RTNORM if
        successful; otherwise, it returns an error code.
        """
    @staticmethod
    def putSym(sym: str, resultBuffer: list, /) -> bool:
        """
        Sets the value of an AutoLISP symbol. Warning This command can be used in the ARX program
        environment only when AutoCAD sends the message kInvkSubrMsg to the application. To set the
        value of the AutoLISP symbol to nil, make the following assignment: value->restype = RTNIL;
        If sname is not the name of a current symbol, acedPutSym() creates a new AutoLISP symbol
        with this name and assigns it the value.
        """
    @staticmethod
    def redraw(id: PyDb.ObjectId, mode: int, /) -> int:
        """
        Redraws either the graphics viewport or a single entity, according to the arguments. The
        following table shows the acceptable values for mode and the effect that each has. (If ent
        is not NULL but mode is 0, the call has no effect.) Modes for acedRedraw: Redraw mode
        Action 1 Redraw entity 2 Undraw entity (blank it out) 3 Highlight entity 4 Unhighlight
        entity If ent is NULL, acedRedraw() is identical to the AutoCAD REDRAW command. If ent is a
        valid entity name, and mode is nonzero, acedRedraw() affects only the specified entity.
        acedRedraw() calls must be made in matched pairs. Every call with a mode of 2 must be
        followed at some point by a call with a mode of 1. Every call with a mode of 3 must be
        followed at some point by a call with a mode of 4. Mismatched calls such as a call with a
        mode of 3 followed by a call with a mode of 1 are not allowed. (This is a change from the
        previous behaviour of this function that was necessary for display performance
        optimization.) If acedRedraw() succeeds, it returns RTNORM; otherwise, it returns an error
        code. When acedRedraw() fails, it sets the system variable ERRNO to a value that indicates
        the reason for the failure.
        """
    @staticmethod
    def regen() -> None: ...
    @staticmethod
    def reloadMenus(bIncrementalReloading: bool, /) -> None:
        """
        Updates the User Interface in AutoCAD to reflect any changes made to the currently loaded
        menus.
        """
    @staticmethod
    def removeSupplementalCursorImage() -> bool: ...
    @staticmethod
    def restoreCurrentView(vid: PyDb.ObjectId, /) -> None:
        """
        Restore a named view to the current active viewport. This function restores the view
        parameters, layers state, and all associated properties to the current active viewport. The
        fucntion is equivalent to the -view restore command. Returns Acad::eOk if it successfully
        restores a named view into the current active viewport.
        """
    @staticmethod
    def restorePreviousUCS() -> None:
        """
        Sets the previous UCS to be the current UCS. This function operates on the document
        currently displayed in the editor. Returns Acad::eOk if successful. Returns
        Acad::eNotApplicable if there is no previous UCS to restore, or if there is no current
        document.
        """
    @staticmethod
    def restoreStatusBar() -> None:
        """
        Restores AutoCAD's original status bar.
        """
    @staticmethod
    def sendModelessOperationEnded(ctx: str, /) -> None:
        """
        Informs AutoCAD when a modeless application has finished some significant operation
        identified by strContext.
        """
    @staticmethod
    def sendModelessOperationStart(ctx: str, /) -> None:
        """
        Informs AutoCAD when a modeless application is starting some significant operation
        identified by strContext.
        """
    @staticmethod
    def setCfg(sym: str, val: str, /) -> None:
        """
        Writes application data to the AppData section of the acad.cfg file.
        """
    @staticmethod
    def setColorDialog(
        clr: int, bAllowMetaColor: bool, nCurLayerColor, int, /
    ) -> tuple[bool, int]:
        """
        This function starts the SetColor dialog within the AutoCAD editor. The value passed in via
        nColor is used as the default color index in the dialog. Upon return nColor contains the
        color index of the color selected by the user. If bAllowMetaColor is Adesk::kTrue, the
        BYLAYER and BYBLOCK meta-colors are allowed in the dialog. nCurLayerColor is used as the
        color index of the color to show for BYLAYER. If the SetColor dialog is invoked using this
        function, only the color index tab is available. To enable the user to select additional
        color types, invoke the SetColor dialog with the acedSetColorDialogTrueColor() function.
        Returns Adesk::kTrue if the dialog was successfully terminated via the OK button, or
        Adesk::kFalse if the dialog was canceled.
        """
    @staticmethod
    def setColorDialogTrueColor(
        clr: PyDb.AcCmColor, bAllowMetaColor: bool, nCurLayerColor: PyDb.AcCmColor, tab: int = 7, /
    ) -> tuple[bool, PyDb.Color]:
        """
        This function starts the Set Color dialog box within the AutoCAD editor. The value passed
        in color is the default color in the dialog. This can affect which tab and controls are
        active upon entering the dialog box. When the function returns, color contains the color
        selected by the user or the original value if the dialog box was aborted. If
        bAllowMetaColor is Adesk::kTrue, the BYLAYER and BYBLOCK metacolors are allowed in the
        dialog. curLayerColor is the color to show for BYLAYER. The function returns Adesk::kTrue
        if the dialog box was successfully terminated by the OK button; it returns Adesk::kFalse if
        the dialog box was canceled.
        """
    @staticmethod
    def setColorPrompt(prompt: str, bAllowMetaColor: bool, /) -> PyDb.Color:
        """
        Prompts the user for a color on the command line. Returns true if successful; otherwise,
        returns false.
        """
    @staticmethod
    def setCurrentVPort(vp: PyDb.Viewport, /) -> None:
        """
        This function sets the current viewport from the viewport index vpnumber. Viewport index
        numbers are the numbers reported by the CVPORT system variable. SysVarWillChange and
        SysVarChanged notification are generated by this function. Returns Acad::eOk if successful.
        Returns Acad::eOutOfRange if vpnumber isn't valid for the current environment.
        """
    @staticmethod
    def setCurrentView(vrec: PyDb.ViewTableRecord, vp: PyDb.Viewport = ..., /) -> None:
        """
        This function uses the information from the AcDbViewTableRecord pointed to by pVwRec to set
        the view in the AcDbViewport pointed to by pVP (if pVP != NULL) or in the current viewport
        (if pVP == NULL).
        """
    @staticmethod
    def setEnv(sym: str, val: str, /) -> None:
        """
        The acedSetEnv() function sets the value of an environment variable. It stores the data
        only in the AutoCAD-specific FixedProfile/General section of the registry:
        HKEY_CURRENT_USER Software Autodesk AutoCAD R25.0 <Install ID> FixedProfile General If this
        function is called on a Windows system environment variable, that variable will be
        overridden in the AutoCAD section of the registry and will remain overridden until the
        associated registry entry is manually deleted.
        """
    @staticmethod
    def setFieldUpdateEnabled(doc: PyAp.Document, enabled: bool, /) -> None:
        """
        Gets the flag of field update enabled.
        """
    @staticmethod
    def setFunHelp(functionName: str, helpfile: str, topic: str, iCmd: int, /) -> int:
        """
        Defines a Help call that should be made if a transparent Help request is made during a
        command line prompt for the function named pszFunctionName. This function registers Help
        for functions that are called from the AutoCAD command line so that the appropriate Help
        file and topic are called when help is requested at a user prompt. acedSetFunHelp() may be
        used for ObjectARX commands, as well as ObjectARX and AutoLISP commands that start with C:.
        """
    @staticmethod
    def setStatusBarProgressMeter(lable: str, nMinPos: int, nMaxPos: int, /) -> int:
        """
        This displays an option label and a progress meter on the AutoCAD status bar. Pass NULL or
        an empty string for the label if no label is desired. Returns 0 if it successfully creates
        the label and progress meter; otherwise, returns -1.
        """
    @staticmethod
    def setStatusBarProgressMeterPos(pos: int, /) -> int:
        """
        Call this with a positive value within the range specified to set the current position of
        the status bar. Pass a negative number to add an amount to the current position (relative).
        Returns 0 if it successfully creates the label and progress meter; otherwise, returns -1.
        """
    @staticmethod
    def setSupplementalCursorOffset(x: int, y: int, /) -> None: ...
    @staticmethod
    def setUndoMark(flag: bool, /) -> None: ...
    @staticmethod
    def setVar(name: str, value, /) -> bool:
        """
        Sets the specified AutoCAD system variable. The val argument must point to a result buffer,
        because the system variables consist of a variety of types. The result buffer must be
        initialized and must contain a valid result type code and value that correspond to the type
        and values allowed for the specified system variable. AutoCAD system variables that take
        integer values are 16-bit short integers. The value supplied in the val->resval.rint field
        of the result buffer must be between -32,768 and +32,767. Some AutoCAD commands inspect the
        values of system variables before they prompt the user. If the application calls
        acedSetVar() while such a command is in progress, the new value may not become current
        until the command has completed its execution. This function is the complement of the
        acedGetVar() function. If acedSetVar() succeeds, it returns RTNORM; otherwise, it returns
        an error code. When acedSetVar() fails, it sets the system variable ERRNO to a value that
        indicates the reason for the failure.
        """
    @staticmethod
    def setXrefResolvedWithUpdateStatus(rec: PyDb.BlockTableRecord, /) -> None:
        """
        This function forces the Xref Notification feature to treat the specified Xref as having
        been resolved with an updated drawing, just as if it was reloaded through the user
        interface. Returns Acad::eOk if successful; otherwise, eInvalidInput if pBTR was NULL or
        invalid.
        """
    @staticmethod
    def showHTMLModalWindow(
        hwnd: int, uriOfHtmlPage: str, persistSizeAndPosition: bool = True, /
    ) -> bool:
        """
        This function can be used to launch a modal dialog with the specified URI. The window hosts
        a browser window which displays the html page.
        """
    @staticmethod
    def showHTMLModelessWindow(
        hwnd: int, uriOfHtmlPage: str, persistSizeAndPosition: bool = True, /
    ) -> int:
        """
        This function can be used to launch a modeless dialog with the specified URI. The window
        hosts a browser window which displays the html page.
        """
    @staticmethod
    def skipXrefNotification(db: PyDb.Database, name: str, /) -> None:
        """
        This function directs the Xref Notification feature to ignore the update of the Xref,
        identified by its name, xrefName, for the specified host database, pHostDb. In effect, the
        Xref is treated as if it had been reloaded as of the time this function is called. Returns
        Acad::eOk if the xref notification will be skipped for the specified xref. Returns
        Acad::eNotApplicable if the XREFNOTIFY system variable is 0 (indicating xref notification
        is disabled). Returns Acad::eInvalidInput if the pHostDb parameter is NULL or xrefName is
        the empty string. Returns Acad::eKeyNotFound if the xref cannot be found.
        """
    @staticmethod
    def textBox(resultBuffer: list, /) -> tuple[PyGe.Point3d, PyGe.Point3d]:
        """
        Finds the coordinates of a box that encloses a text entity. Assumes that the origin is
        (0,0) and the rotation is 0 (or 270 if the text is vertical). If the text is located at a
        different point or is rotated, your program must handle these values explicitly. If the
        text is horizontal and is not rotated, p1 (the bottom-left corner) and p2 (the top-right
        corner) describe the bounding box of the text. The coordinates are expressed in the ECS of
        ent, with the origin (0,0) at the left endpoint of the baseline. (The origin is not the
        bottom-left corner if the text contains letters with descenders, such as g and p.) If the
        text is vertical or rotated, p1 and p2 still observe the left-to-right, bottom-to-top
        order; the offsets are negative, if necessary. If the result-buffer list passed in ent
        begins with a -1 (entity name) group, this group must name an existing text, attdef, or
        attrib entity. No further groups need to be present, but if the list contains further
        groups, these override the entity's actual attributes. If the result-buffer list doesn't
        begin with a -1 group, it must begin with a 0 (entity type) group, and it must contain a
        group that contains the string itself. This is a 1 (value) group for a text or attrib
        entity, or a 2 (tag string) group for an attdef entity. Other values are assumed to be the
        default values unless they are explicitly specified. The defaults are as follows: Style
        (group 7)--Defaults to the current text style Size (group 40)--Defaults to the size of the
        style if that is fixed; otherwise, defaults to the current default size of the style Width
        factor (group 41)--Defaults to the default width of the style Obliquing angle (group
        51)--Defaults to the default angle of the style If acedTextBox() succeeds, it returns
        RTNORM; it returns RTERROR if ent does not correctly specify a text entity. If
        acedTextBox() fails, it sets the system variable ERRNO to a value that indicates the reason
        for the failure.
        """
    @staticmethod
    def textPage() -> None:
        """
        On single-screen AutoCAD installations, this function causes the display to switch from the
        graphics screen to the text screen. This is identical to the acedTextScr() function. If
        acedTextPage() succeeds, it returns RTNORM. Otherwise, it returns an error code.
        """
    @staticmethod
    def textScr() -> None:
        """
        On single-screen AutoCAD installations, causes the display to switch from the graphics
        screen to the text screen. This is equivalent to the AutoCAD TEXTSCR command or to pressing
        the flip screen function key (when the graphics screen is current). Its functionality is
        also identical to that of the acedTextPage() function. The acedGraphScr() function is the
        complement of acedTextScr(). If acedTextScr() succeeds, it returns RTNORM. Otherwise, it
        returns an error code.
        """
    @staticmethod
    def trans(pt: PyGe.Point3d, rbFrom: tuple, rbTo: tuple, disp: bool, /) -> PyGe.Point3d:
        """
        Translates a point or a displacement from one coordinate system into another. The from and
        to arguments can specify a coordinate system in any of the following ways: An integer code
        (restype == RTSHORT) that specifies the WCS, current User Coordinate System (UCS), or
        current Drawing Coordinate System (DCS) (of either the current viewport or paper space), as
        described in the following table.An entity name (restype == RTENAME), as returned by one of
        the entity name or selection set functions. This specifies the ECS of the named entity.For
        planar entities, the ECS can differ from the WCS. If the ECS does not differ, conversion
        between ECS and WCS is an identity operation. A 3D extrusion vector (restype == RT3DPOINT).
        This is another method of specifying an entity's ECS.Extrusion vectors are always
        represented in World coordinates; an extrusion vector of (0,0,1) specifies the WCS.
        Coordinate system codes: 0 World (WCS) 1 User (current UCS) 2 Display:DCS of current
        viewport when used with code 0 or 1DCS of current model space viewport when used with code
        3 3 Paper space DCS (PSDCS; used only with code 2) Warning The paper space DCS (PSDCS) can
        be transformed only to or from the model space DCS. Therefore, if the from argument equals
        3, the to argument must equal 2, and conversely. If acedTrans() succeeds, it returns
        RTNORM; otherwise, it returns an error code. When acedTrans() fails, it sets the system
        variable ERRNO to a value that indicates the reason for the failure.
        """
    @staticmethod
    def unloadPartialMenu(mnu: str, /) -> bool:
        """
        Removes (unloads) a partial menu from the current main menu.
        """
    @staticmethod
    def unmarkForDelayXRefRelativePathResolve(id: PyDb.ObjectId, /) -> None:
        """
        Unmarks the input Xref definition object ID, which is marked in the function
        acedMarkForDelayXRefRelativePathResolve(.)If this object ID is not marked before by the
        function acedMarkForDelayXRefRelativePathResolve(), then this function will be a
        no-operation.
        """
    @staticmethod
    def update(vport: int, pt1: PyGe.Point2d, pt2: PyGe.Point2d, /) -> int:
        """
        Refreshes a rectangular sub-area of the viewport. The corners must be specified in drawing
        coordinates. As long as p1 and p2 are diagonally opposite each other, it does not matter
        which two corners of the area are specified.
        """
    @staticmethod
    def updateDisplay() -> None:
        """
        This function causes AutoCAD to update its display screen. The update is essentially a
        repaint of the AutoCAD graphics window with what AutoCAD's display engine has cached as the
        window's image. AutoCAD manages its display area in the most efficient way by keeping track
        of which portions of the screen are affected as you make various calls to AutoCAD. In
        general the calls you make will not immediately be reflected in screen changes. AutoCAD
        will conglomerate the calls and make them apparent at times that minimize disturbances to
        the screen. When AutoCAD is not active or has no focus, it will not update its display at
        all. If you're in a modeless dialog and adding or updating an entity, the display won't
        show the changes when they occur. In such cases, you can use this function to force AutoCAD
        to update its display.
        """
    @staticmethod
    def updateDisplayPause(val: bool, /) -> None:
        """
        This function allows an application to turn off display updates in order to hide automated
        tasks from the user. All documents are affected by this call. This call should not be
        enabled if any kind of drawing area input is expected from the user. The restrictions on
        what can be done in this paused state are the same as they would be if the display was not
        paused. Callers of this function should first save the return value from
        acedIsUpdateDisplayPaused(), then restore that value when finished pausing the display.
        """
    @staticmethod
    def usrBrk() -> bool:
        """
        Checks whether the user has pressed [Esc] to interrupt execution of the current external
        function. This function enables ARX applications that do long, complex operations to check
        for a user interrupt. The interactive ARX library functions, such as acedEntSel() or those
        in the user input (acedGetXxx()) group, check for [Esc] before they return to the ARX
        application (returning a status of RTCAN if [Esc] was pressed). Because of this, ARX
        applications don't need to call acedUsrBrk() unless they perform a lot of computation
        between requests for user input. Your application should call this function at strategic
        locations, such as at the top of a long evaluation loop. Do not use this function as a
        substitute for checking the value returned by ARX library functions. If an application
        ignores a user's cancellation request, it must call acedUsrBrk() to clear the request.
        Otherwise, the [Esc] will still be outstanding and will cancel the next call to an
        acedGetXxx() function or to the acedCommand(), acedCmd(), acedDragGen(), acedEntSel(),
        acedNEntSelP(), acedNEntSel(), or acedSSGet() functions. If the user has pressed [Esc],
        acedUsrBrk() returns 1; otherwise, it returns 0.
        """
    @staticmethod
    def viewportIdFromNumber(val: int, /) -> PyDb.ObjectId:
        """
        Returns the objectID that corresponds to the viewport number specified by nVpNum. This
        number is the same as that reported by the CVPORT AutoCAD system variable. For example, the
        Paper Space viewport is number 1. In tilemode the returned ID is obtained from a viewport
        table record. In layout mode it is obtained from a viewport entity. Returns null if no
        documents are open, or if the number does not correspond to a valid viewport.
        """
    @staticmethod
    def vpLayer(
        id: PyDb.ObjectId, layerIds: list[PyDb.ObjectId], operation: PyDb.VpFreezeOps, /
    ) -> None:
        """
        This function modifies the viewport specified by vpId to freeze, thaw, or reset the layers
        specified by the object IDs in layerIds. If operation is AcDb::kFreeze, the specified
        layers will be frozen in the viewport. If operation is AcDb::kThaw, the specified layers
        will be thawed in the viewport. If operation is AcDb::Reset, the specified layers whose
        VPDFLT() method returns true will be frozen in the viewport and those whose VPDFLT() method
        returns false will be thawed in the viewport. WarningThe viewport specified by vpId must be
        closed when this function is called. operation may be one of the following: kFreeze, kThaw,
        kReset. Returns Acad::eOk if successful. Returns Acad::eInvalidInput under any of the
        following circumstances: if vpId is NULL or is not in the current drawingif the object
        specified by vpId is not an instance of either AcDbViewport or a class derived from
        AcDbViewportif operation is not valid
        """
    @staticmethod
    def vportTableRecords2Vports() -> None:
        """
        For the currenlty active drawing, this function copies the data from the
        AcDbViewportTableRecords with the name '*ACTIVE' over into the corresponding displayed
        viewports creating or removing display viewports if necessary. This function will result in
        a regen in all viewports. Returns Acad::eOk if successful. Returns Acad::eNotApplicable
        when called while tilemode is 0.
        """
    @staticmethod
    def vports() -> list:
        """
        Returns a pointer to a list of viewport descriptors for the current viewport configuration.
        Warning To avoid a memory leak, before calling acedVports(), set result to null to ensure
        that it does not point to allocated memory. If the AutoCAD TILEMODE system variable is set
        to 1 (on), the returned list describes the viewport configuration created with the AutoCAD
        VIEWPORTS command. The corners of the viewports are expressed in values between 0.0 and
        1.0, with (0.0, 0.0) representing the lower-left corner of the display screen's graphics
        area, and (1.0, 1.0) representing the upper-right corner. Each viewport descriptor is a
        sublist consisting of the viewport identification number and the coordinates of the
        viewport's lower-left and upper-right corners. If TILEMODE is 0 (off), the returned list
        describes the viewport entities created with the MVIEW command. The viewport entity corners
        are expressed in paper space coordinates. Viewport number 1 is always paper space when
        TILEMODE is off. The current viewport's descriptor is always first in the list. If it
        succeeds, acedVports() returns RTNORM; it returns RTERROR if it can't allocate the list.
        Call acutRelRb() to deallocate memory for the contents of result.
        """
    @staticmethod
    def vports2VportTableRecords() -> None:
        """
        For the currently active drawing, this function copies the displayed viewport data over
        into the corresponding AcDbViewportTableRecords (those with the name '*ACTIVE'), creating
        or erasing '*ACTIVE' AcDbViewportTableRecords as necessary. Returns Acad::eOk if
        successful. Returns Acad::eNotApplicable when called while tilemode is 0.
        """
    @overload
    @staticmethod
    def xrefAttach(path: str, name: str, /) -> None: ...
    @overload
    @staticmethod
    def xrefAttach(
        path: str,
        name: str,
        btrid: PyDb.ObjectId,
        refid: PyDb.ObjectId,
        pt: PyGe.Point3d,
        sc: PyGe.Scale3d,
        rot: float,
        bQuiet: bool,
        pHostDb: PyDb.Database,
        passwd: str,
        /,
    ) -> None: ...
    @overload
    @staticmethod
    def xrefAttach(*args) -> None: ...
    @overload
    @staticmethod
    def xrefBind(XrefBlockname: str, /) -> None: ...
    @overload
    @staticmethod
    def xrefBind(
        XrefBlockname: str, bInsertBind: bool, bQuiet: bool, pHostDb: PyDb.Database, /
    ) -> None: ...
    @overload
    @staticmethod
    def xrefBind(*args) -> None: ...
    @staticmethod
    def xrefCreateBlockname(XrefPathname: str, /) -> str: ...
    @overload
    @staticmethod
    def xrefDetach(XrefBlockname: str, /) -> None: ...
    @overload
    @staticmethod
    def xrefDetach(XrefBlockname: str, bQuiet: bool, pHostDb: PyDb.Database, /) -> None: ...
    @overload
    @staticmethod
    def xrefDetach(*args) -> None: ...
    @staticmethod
    def xrefNotifyCheckFileChanged(id: PyDb.ObjectId, /) -> bool: ...
    @overload
    @staticmethod
    def xrefOverlay(path: str, name: str, /) -> None: ...
    @overload
    @staticmethod
    def xrefOverlay(
        path: str,
        name: str,
        btrid: PyDb.ObjectId,
        refid: PyDb.ObjectId,
        pt: PyGe.Point3d,
        sc: PyGe.Scale3d,
        rot: float,
        bQuiet: bool,
        pHostDb: PyDb.Database,
        passwd: str,
        /,
    ) -> None: ...
    @overload
    @staticmethod
    def xrefOverlay(*args) -> None: ...
    @overload
    @staticmethod
    def xrefReload(symbolIds: list[PyDb.ObjectId], /) -> None: ...
    @overload
    @staticmethod
    def xrefReload(
        symbolIds: list[PyDb.ObjectId], bQuiet: bool, pHostDb: PyDb.Database, /
    ) -> None: ...
    @overload
    @staticmethod
    def xrefReload(name: str, /) -> None: ...
    @overload
    @staticmethod
    def xrefReload(name: str, bQuiet: bool, pHostDb: PyDb.Database, /) -> None: ...
    @overload
    @staticmethod
    def xrefReload(*args) -> None: ...
    @staticmethod
    def xrefResolve(db: PyDb.Database, bQuiet: bool = True, /) -> None: ...
    @overload
    @staticmethod
    def xrefUnload(XrefBlockname: str, /) -> None: ...
    @overload
    @staticmethod
    def xrefUnload(XrefBlockname: str, bQuiet: bool, pHostDb: PyDb.Database, /) -> None: ...
    @overload
    @staticmethod
    def xrefUnload(*args) -> None: ...
    @overload
    @staticmethod
    def xrefXBind(symbolIds: list[PyDb.ObjectId], /) -> None: ...
    @overload
    @staticmethod
    def xrefXBind(
        symbolIds: list[PyDb.ObjectId], bQuiet: bool, pHostDb: PyDb.Database, /
    ) -> None: ...
    @overload
    @staticmethod
    def xrefXBind(*args) -> None: ...

class CursorType(_BoostPythonEnum):
    kNoSpecialCursor: ClassVar[Self]  # -1
    kCrosshair: ClassVar[Self]  # 0
    kRectCursor: ClassVar[Self]  # 1
    kRubberBand: ClassVar[Self]  # 2
    kNotRotated: ClassVar[Self]  # 3
    kTargetBox: ClassVar[Self]  # 4
    kRotatedCrosshair: ClassVar[Self]  # 5
    kCrosshairNoRotate: ClassVar[Self]  # 6
    kInvisible: ClassVar[Self]  # 7
    kEntitySelect: ClassVar[Self]  # 8
    kParallelogram: ClassVar[Self]  # 9
    kEntitySelectNoPersp: ClassVar[Self]  # 10
    kPkfirstOrGrips: ClassVar[Self]  # 11
    kCrosshairDashed: ClassVar[Self]  # 12

class DragStatus(_BoostPythonEnum):
    kModeless: ClassVar[Self]  # -17
    kNoChange: ClassVar[Self]  # -6
    kCancel: ClassVar[Self]  # -4
    kOther: ClassVar[Self]  # -3
    kNull: ClassVar[Self]  # -1
    eNormal: ClassVar[Self]  # 0
    eOk: ClassVar[Self]  # 0
    kNormal: ClassVar[Self]  # 0
    kKW1: ClassVar[Self]  # 1
    kKW2: ClassVar[Self]  # 2
    kKW3: ClassVar[Self]  # 3
    kKW4: ClassVar[Self]  # 4
    kKW5: ClassVar[Self]  # 5
    kKW6: ClassVar[Self]  # 6
    kKW7: ClassVar[Self]  # 7
    kKW8: ClassVar[Self]  # 8
    kKW9: ClassVar[Self]  # 9

class DragStyle:
    def __init__(
        self, styleTypeForOriginal: PyEd.DragStyleType, styleTypeForDragged: PyEd.DragStyleType, /
    ) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def setStyleTypeForDragged(
        self, styleTypeForDragged: PyEd.DragStyleType, /
    ) -> PyDb.ErrorStatus: ...
    def setStyleTypeForOriginal(
        self, styleTypeForOriginal: PyEd.DragStyleType, /
    ) -> PyDb.ErrorStatus: ...
    def styleTypeForDragged(self, /) -> DragStyleType: ...
    def styleTypeForOriginal(self, /) -> DragStyleType: ...

class DragStyleType(_BoostPythonEnum):
    kNone: ClassVar[Self]  # 0
    kHide: ClassVar[Self]  # 1
    kTransparent25: ClassVar[Self]  # 2
    kTransparent75: ClassVar[Self]  # 3
    kDeletedEffect: ClassVar[Self]  # 4
    kHighlight: ClassVar[Self]  # 5
    kNotSet: ClassVar[Self]  # 6

class DrawJig:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def acquireAngle(self, basePnt: PyGe.Point3d = ..., /) -> tuple[PyEd.DragStatus, float]: ...
    def acquireDist(self, basePnt: PyGe.Point3d = ..., /) -> tuple[PyEd.DragStatus, float]: ...
    def acquirePoint(
        self, basePnt: PyGe.Point3d = ..., /
    ) -> tuple[PyEd.DragStatus, PyGe.Point3d]: ...
    def acquireString(self, /) -> tuple[PyEd.DragStatus, str]: ...
    @staticmethod
    def className() -> str: ...
    def dispPrompt(self, /) -> str: ...
    def drag(self, style: PyEd.DragStyle = ..., /) -> DragStatus: ...
    def keywordList(self, /) -> str: ...
    def sampler(self, /) -> DragStatus: ...
    def setDispPrompt(self, val: str, /) -> None: ...
    def setKeywordList(self, val: str, /) -> None: ...
    def setSpecialCursorType(self, val: PyEd.CursorType, /) -> None: ...
    def setUserInputControls(self, val: PyEd.UserInputControls, /) -> None: ...
    def specialCursorType(self, /) -> CursorType: ...
    def update(self, /) -> bool: ...
    def userInputControls(self, /) -> UserInputControls: ...
    def viewportDraw(self, wd: PyGi.ViewportDraw, /) -> None: ...
    def worldDraw(self, wd: PyGi.WorldDraw, /) -> bool: ...

class DrawOrderCmdType(_BoostPythonEnum):
    kDrawOrderNone: ClassVar[Self]  # 0
    kDrawOrderBottom: ClassVar[Self]  # 1
    kDrawOrderTop: ClassVar[Self]  # 2
    kDrawOrderBelow: ClassVar[Self]  # 3
    kDrawOrderAbove: ClassVar[Self]  # 4

class Editor:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def activeViewportId() -> PyDb.ObjectId:
        """
        Returns the object ID of the viewport that is currently active in the editor. In tilemode,
        it returns the ID is of a viewport table record. In layout mode, returns the object ID of a
        viewport entity . Returns a null object ID if no document is open.
        """
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def curViewportObjectId() -> PyDb.ObjectId:
        """
        This function returns the objectId of the current AcDbViewport entity (it does not work
        with AcDbViewportTableRecords). If TILEMODE is 1, then there is no AcDbViewport entity
        current so it will return AcDbObjectId::kNull.
        """
    @staticmethod
    def duplicateSelectionsAllowed(doc: PyAp.Document, /) -> bool:
        """
        Returns true if pDoc is non-NULL and duplicate selections are allowed for the document to
        which it points. Otherwise, returns false.
        """
    @overload
    @staticmethod
    def entSel(prompt: str, /) -> tuple[PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d]:
        """
        Prompts the user to select an entity by specifying a point. Pauses for user input and
        returns both an entity name and the point that is used to select the entity. The
        acedEntSel() function does not return the names of nongraphical objects. Some entity
        operations require knowledge of the point by which the entity was selected. Examples are
        the AutoCAD BREAK, TRIM, and EXTEND commands, as well as OSNAP; acedEntSel() provides the
        same capability to ARX applications. The acedEntSel() function ignores the current OSNAP
        setting (no object snap) unless the user specifically requests it. When the user responds
        to acedEntSel() by specifying a complex entity, it returns the polyline or block header.
        This differs from the function acedNEntSelP(), which returns the nearest block attribute or
        polyline vertex. The acedEntSel() function returns RTNORM if it succeeds, RTERROR if it
        fails, or RTCAN if the user cancels the request (by pressing [Esc]). A prior call to
        acedInitGet() can also enable a return value of RTKWORD (see the description of
        acedInitGet()). When acedEntSel() fails, it sets the system variable ERRNO to a value that
        indicates the reason for the failure.
        """
    @overload
    @staticmethod
    def entSel(
        prompt: str, eType: PyRx.RxClass, /
    ) -> tuple[PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d]:
        """
        Prompts the user to select an entity by specifying a point. Pauses for user input and
        returns both an entity name and the point that is used to select the entity. The
        acedEntSel() function does not return the names of nongraphical objects. Some entity
        operations require knowledge of the point by which the entity was selected. Examples are
        the AutoCAD BREAK, TRIM, and EXTEND commands, as well as OSNAP; acedEntSel() provides the
        same capability to ARX applications. The acedEntSel() function ignores the current OSNAP
        setting (no object snap) unless the user specifically requests it. When the user responds
        to acedEntSel() by specifying a complex entity, it returns the polyline or block header.
        This differs from the function acedNEntSelP(), which returns the nearest block attribute or
        polyline vertex. The acedEntSel() function returns RTNORM if it succeeds, RTERROR if it
        fails, or RTCAN if the user cancels the request (by pressing [Esc]). A prior call to
        acedInitGet() can also enable a return value of RTKWORD (see the description of
        acedInitGet()). When acedEntSel() fails, it sets the system variable ERRNO to a value that
        indicates the reason for the failure.
        """
    @overload
    @staticmethod
    def entSel(
        prompt: str, eTypes: list[PyRx.RxClass], /
    ) -> tuple[PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d]:
        """
        Prompts the user to select an entity by specifying a point. Pauses for user input and
        returns both an entity name and the point that is used to select the entity. The
        acedEntSel() function does not return the names of nongraphical objects. Some entity
        operations require knowledge of the point by which the entity was selected. Examples are
        the AutoCAD BREAK, TRIM, and EXTEND commands, as well as OSNAP; acedEntSel() provides the
        same capability to ARX applications. The acedEntSel() function ignores the current OSNAP
        setting (no object snap) unless the user specifically requests it. When the user responds
        to acedEntSel() by specifying a complex entity, it returns the polyline or block header.
        This differs from the function acedNEntSelP(), which returns the nearest block attribute or
        polyline vertex. The acedEntSel() function returns RTNORM if it succeeds, RTERROR if it
        fails, or RTCAN if the user cancels the request (by pressing [Esc]). A prior call to
        acedInitGet() can also enable a return value of RTKWORD (see the description of
        acedInitGet()). When acedEntSel() fails, it sets the system variable ERRNO to a value that
        indicates the reason for the failure.
        """
    @overload
    @staticmethod
    def entSel(*args) -> tuple[PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d]:
        """
        Prompts the user to select an entity by specifying a point. Pauses for user input and
        returns both an entity name and the point that is used to select the entity. The
        acedEntSel() function does not return the names of nongraphical objects. Some entity
        operations require knowledge of the point by which the entity was selected. Examples are
        the AutoCAD BREAK, TRIM, and EXTEND commands, as well as OSNAP; acedEntSel() provides the
        same capability to ARX applications. The acedEntSel() function ignores the current OSNAP
        setting (no object snap) unless the user specifically requests it. When the user responds
        to acedEntSel() by specifying a complex entity, it returns the polyline or block header.
        This differs from the function acedNEntSelP(), which returns the nearest block attribute or
        polyline vertex. The acedEntSel() function returns RTNORM if it succeeds, RTERROR if it
        fails, or RTCAN if the user cancels the request (by pressing [Esc]). A prior call to
        acedInitGet() can also enable a return value of RTKWORD (see the description of
        acedInitGet()). When acedEntSel() fails, it sets the system variable ERRNO to a value that
        indicates the reason for the failure.
        """
    @staticmethod
    def getAngle(basePt: PyGe.Point3d, prompt: str, /) -> tuple[PyEd.PromptStatus, float]:
        """
        Gets user input for an angle, taking into account the current value of the ANGBASE system
        variable. The AutoCAD user can specify the angle by entering a number in the current
        angular units format. The user can set the angle also by specifying two 2D locations on the
        graphics screen. AutoCAD draws a rubber-band line from the first point to the current
        crosshair position to help the user visualize the angle. If the pt argument is not null,
        AutoCAD uses this value as the first of the two points. The angle is measured in the XY
        plane of the current UCS (acedGetAngle() ignores the Z field of pt). The direction of
        angular increase is always counterclockwise. The acedGetAngle() function is almost
        identical to acedGetOrient(), but it takes into account the current value of the ANGBASE
        system variable. For acedGetOrient(), the 0 angle is always to the right: 'east' or '3
        o'clock.' For acedGetAngle(), the 0 angle is the value of ANGBASE, which can be set to any
        of the four 90-degree quadrants. Both acedGetAngle() and acedGetOrient() return a (real)
        angle value in radians measured counterclockwise from a base (0) angle. For acedGetAngle(),
        the base equals ANGBASE; for acedGetOrient(), the base is at the right. Both functions
        honor the current value of ANGDIR, which affects the value the user enters but not the
        value that these functions return. For example, if ANGBASE is set to 90 degrees (north) and
        ANGDIR is set to 1 (clockwise direction for increasing angles), as shown in the figure that
        accompanies the following table, then given these conditions, the values returned by
        acedGetAngle() and acedGetOrient() will be as shown in the table. Results from acedGetAngle
        and acedGetOrient: User input (degrees) acedGetAngle() returns acedGetOrient() returns 0
        0.0 1.5708 -90 1.5708 3.14159 180 3.14159 4.71239 90 4.71239 0.0 The user cannot respond to
        acedGetAngle() by entering an AutoLISP expression. You can use acedGetAngle() to obtain a
        rotation amount for a block insertion, because an input of 0 degrees always returns 0
        radians. You can use acedGetOrient() to obtain the baseline angle for a text entity to be
        aligned with other objects. The acedGetAngle() function returns RTNORM if it succeeds,
        RTERROR if it fails, or RTCAN if the user cancels the request (by pressing [Esc] ). It
        returns RTMODELESS, if the active command was registered using the ACRX_CMD_INTERRUPTIBLE
        flag and the document has received a modeless interrupt signal from a call to
        AcApDocManager::sendModelessInterrupt(). A prior call to acedInitGet() can also enable
        return values of RTNONE or RTKWORD (see the description of acedInitGet()). If the optional
        pt or prompt is not used, pass a null pointer for these arguments.
        """
    @staticmethod
    def getCorner(basePt: PyGe.Point3d, prompt: str, /) -> tuple[PyEd.PromptStatus, PyGe.Point3d]:
        """
        Gets user input for the corner of a rectangle. The AutoCAD user can specify the corner by
        entering a point in the current units format; acedGetCorner() treats pt as a
        three-dimensional point. The user can specify the corner also by specifying a location on
        the graphics screen. AutoCAD draws a dynamically sized rectangle from pt to the current
        crosshair position to help the user visualize the location of the second corner. The
        rectangle is drawn in the XY plane of the current DCS. When the pointing device is used,
        acedGetCorner() ignores the Z field of pt and sets the Z field of result to the current
        elevation. The user cannot respond to acedGetCorner() by entering an AutoLISP expression.
        The acedGetCorner() function returns one of the following: RTNORM if it succeeds, RTERROR
        if it fails, or RTCAN if the user cancels the request (by pressing [Esc]). It returns
        RTMODELESS, if the active command was registered using the ACRX_CMD_INTERRUPTIBLE flag and
        the document has received a modeless interrupt signal from a call to
        AcApDocManager::sendModelessInterrupt(). A prior call to acedInitGet() can also enable
        return values of RTNONE or RTKWORD.
        """
    @staticmethod
    def getCurrentSelectionSet() -> list[PyDb.ObjectId]:
        """
        This function fills sset in with the object IDs of all entities in the current selection
        set within AutoCAD. The 'current selection set' may be one of the following: a pickfirst
        set, a selection set selected by the select command or any other command that does a
        selection (that is, similar to the 'Previous' selection option), or the most recent set
        from an ssget. If a pickfirst set is available it will always be used. If no pickfirst set
        is available, then whichever of the other two types is available will be used. If both of
        the other two types are available, then whichever was most recently created will be used.
        If a pickfirst selection set is 'selected' by a call to this function, then the entity
        highlighting and grips will disappear just as they would when any AutoCAD command uses a
        pickfirst selection set. If an ssget type of selection is 'selected' by a call to this
        function, then sset will essentially be a copy of the selection set and the original ssget
        selection set will still be valid. Only certain AutoCAD commands create a selection set
        that can be found by acdbGetCurrentSelectionSet(). These commands are listed below: ACISOUT
        AMECONVERT ARRAY ATTEXT AUDIT BHATCH BMPOUT CHANGE CHPROP CONVERT CONVERTPOLY COPY COPYCLIP
        CUTCLIP DIVIDE DVIEW DXFOUT (partial) ERASE EXPLODE EXTEND EXTRUDE GROUP HATCH HIDE
        INTERFERE INTERSECT LIST MASSPROP MEASURE MIRROR MOVE MVIEW OOPS PEDIT REGION REVOLVE
        ROTATE SCALE SECTION SELECT SLICE SPELL SPLINE STLOUT STRETCH SUBTRACT TRIM UNION VPVIS
        WBLOCK WMFOUT XCLIP
        """
    @staticmethod
    def getCurrentUCS() -> PyGe.Matrix3d:
        """
        This function sets mat to the matrix that maps the World Coordinate System (WCS) to the
        User Coordinate System (UCS) that is current in the current document. Returns Acad::eOk if
        successful.
        """
    @overload
    @staticmethod
    def getDist(prompt: str, /) -> tuple[PyEd.PromptStatus, float]:
        """
        Gets user input for a linear distance. The AutoCAD user can specify the distance by
        entering a number in the current units format. The user can set the distance also by
        specifying two locations on the graphics screen. AutoCAD draws a rubber-band line from the
        first point to the current crosshair position to help the user visualize the distance. If
        the pt argument is not null, AutoCAD uses this value as the first of the two points. By
        default, acedGetDist() treats pt and result as three-dimensional points. A prior call to
        acedInitGet() can force pt to be two dimensional, ensuring that acedGetDist() returns
        result as a planar distance. Regardless of the method used to specify the distance, or the
        current linear units (for example, feet and inches), acedGetDist() always sets result to a
        double-precision floating-point value. The user cannot respond to acedGetDist() by entering
        an AutoLISP expression. The acedGetDist() function returns one of the following: RTNORM if
        it succeeds, RTERROR if it fails, or RTCAN if the user cancels the request (by pressing
        [Esc]). It returns RTMODELESS, if the active command was registered using the
        ACRX_CMD_INTERRUPTIBLE flag and the document has received a modeless interrupt signal from
        a call to AcApDocManager::sendModelessInterrupt(). A prior call to acedInitGet() can also
        enable return values of RTNONE or RTKWORD. If pt or prompt is not used, pass a null pointer
        for these arguments.
        """
    @overload
    @staticmethod
    def getDist(basePt: PyGe.Point3d, prompt: str, /) -> tuple[PyEd.PromptStatus, float]:
        """
        Gets user input for a linear distance. The AutoCAD user can specify the distance by
        entering a number in the current units format. The user can set the distance also by
        specifying two locations on the graphics screen. AutoCAD draws a rubber-band line from the
        first point to the current crosshair position to help the user visualize the distance. If
        the pt argument is not null, AutoCAD uses this value as the first of the two points. By
        default, acedGetDist() treats pt and result as three-dimensional points. A prior call to
        acedInitGet() can force pt to be two dimensional, ensuring that acedGetDist() returns
        result as a planar distance. Regardless of the method used to specify the distance, or the
        current linear units (for example, feet and inches), acedGetDist() always sets result to a
        double-precision floating-point value. The user cannot respond to acedGetDist() by entering
        an AutoLISP expression. The acedGetDist() function returns one of the following: RTNORM if
        it succeeds, RTERROR if it fails, or RTCAN if the user cancels the request (by pressing
        [Esc]). It returns RTMODELESS, if the active command was registered using the
        ACRX_CMD_INTERRUPTIBLE flag and the document has received a modeless interrupt signal from
        a call to AcApDocManager::sendModelessInterrupt(). A prior call to acedInitGet() can also
        enable return values of RTNONE or RTKWORD. If pt or prompt is not used, pass a null pointer
        for these arguments.
        """
    @overload
    @staticmethod
    def getDist(*args) -> tuple[PyEd.PromptStatus, float]:
        """
        Gets user input for a linear distance. The AutoCAD user can specify the distance by
        entering a number in the current units format. The user can set the distance also by
        specifying two locations on the graphics screen. AutoCAD draws a rubber-band line from the
        first point to the current crosshair position to help the user visualize the distance. If
        the pt argument is not null, AutoCAD uses this value as the first of the two points. By
        default, acedGetDist() treats pt and result as three-dimensional points. A prior call to
        acedInitGet() can force pt to be two dimensional, ensuring that acedGetDist() returns
        result as a planar distance. Regardless of the method used to specify the distance, or the
        current linear units (for example, feet and inches), acedGetDist() always sets result to a
        double-precision floating-point value. The user cannot respond to acedGetDist() by entering
        an AutoLISP expression. The acedGetDist() function returns one of the following: RTNORM if
        it succeeds, RTERROR if it fails, or RTCAN if the user cancels the request (by pressing
        [Esc]). It returns RTMODELESS, if the active command was registered using the
        ACRX_CMD_INTERRUPTIBLE flag and the document has received a modeless interrupt signal from
        a call to AcApDocManager::sendModelessInterrupt(). A prior call to acedInitGet() can also
        enable return values of RTNONE or RTKWORD. If pt or prompt is not used, pass a null pointer
        for these arguments.
        """
    @staticmethod
    def getDouble(
        prompt: str, condition: PyEd.PromptCondition = PyEd.PromptCondition.eNone, /
    ) -> tuple[PyEd.PromptStatus, float]:
        """
        Gets user input for a real value. The AutoCAD user can enter any valid real value, but the
        user cannot respond to acedGetReal() by entering an AutoLISP expression. The acedGetReal()
        function returns one of the following: RTNORM if it succeeds, RTERROR if it fails, or RTCAN
        if the user cancels the request (by pressing [Esc]). It returns RTMODELESS, if the active
        command was registered using the ACRX_CMD_INTERRUPTIBLE flag and the document has received
        a modeless interrupt signal from a call to AcApDocManager::sendModelessInterrupt(). A prior
        call to acedInitGet() can also enable return values of RTNONE or RTKWORD.
        """
    @staticmethod
    def getInput() -> str:
        """
        Deprecated. Retrieves a keyword entered by the AutoCAD user during a call to one of the
        user-input functions (acedGetxxx(), acedEntSel(), acedNEntSelP(), acedNEntSel(), or
        acedDragGen()). Function acedGetInput() truncates any characters beyond 131 characters in
        the user's input and returns at most 132 characters in str (position 132 is reserved for
        the null character). A call to acedGetInput() is meaningless and will fail unless it
        immediately follows a call to one of the user-input functions. Even then, the call will be
        successful only if the user-input function has returned the value RTKWORD (or RTSTR, in the
        case of acedDragGen()). It isn't necessary to call acedGetInput() after a call to
        acedGetKword(). The keywords recognized by the ARX application are specified by a prior
        call to acedInitGet(). The interpretation of the keywords is entirely up to the
        application. Keywords should not duplicate the names of AutoCAD commands. The user can
        abbreviate a keyword, but acedGetInput() always returns the full keyword as it was defined
        in the acedInitGet() call with the original capitalization, so the application needs to do
        only one string comparison for each keyword it defines. The acedGetInput() function also
        retrieves arbitrary input, if that input was enabled by a prior acedInitGet() call that
        specified the RSG_OTHER bit. (If RSG_OTHER is enabled before an acedDragGen() call,
        acedDragGen() indicates that it has received arbitrary input by returning RTSTR instead of
        RTKWORD.) If acedGetInput() succeeds, it returns RTNORM; otherwise, it returns RTERROR. It
        returns RTMODELESS, if the active command was registered using the ACRX_CMD_INTERRUPTIBLE
        flag and the document has received a modeless interrupt signal from a call to
        AcApDocManager::sendModelessInterrupt().
        """
    @staticmethod
    def getInteger(
        prompt: str, condition: PyEd.PromptCondition = PyEd.PromptCondition.eNone, /
    ) -> tuple[PyEd.PromptStatus, int]:
        """
        Gets user input for an integer. The AutoCAD user can enter any valid 32-bit integer. The
        user cannot respond to acedGetInt() by entering an AutoLISP expression. The acedGetInt()
        function returns one of the following: RTNORM if it succeeds, RTERROR if it fails, or RTCAN
        if the user cancels the request (by pressing [ESC]). A prior call to acedInitGet() can also
        enable return values of RTNONE or RTKWORD.
        """
    @staticmethod
    def getKword(keyword: str, /) -> tuple[PyEd.PromptStatus, str]:
        """
        Deprecated. Function acedGetFullKword() is an alternate form of acedGetKword(). Instead of
        truncating any characters beyond the 131, acedGetFullKword() returns a new copy of the
        entire string using acutUpdString() and updates pStr to point to the new copy. Aside from
        the manner in which it returns the input string, this function behaves exactly like
        acedGetKword(). The caller is responsible for freeing the returned string using
        acutDelString(). This function returns the same error codes as acedGetInput(). If there is
        insufficient memory for a copy of the string, this function returns RTERROR. See function
        acedGetKword() for more information.
        """
    @overload
    @staticmethod
    def getPoint(prompt: str, /) -> tuple[PyEd.PromptStatus, PyGe.Point3d]:
        """
        Gets user input for a point. The AutoCAD user can specify the point by entering a
        coordinate in the current units format; acedGetPoint() treats pt and result as
        three-dimensional points. The user can specify the point also by specifying a location on
        the graphics screen. If the pt argument is not null, AutoCAD draws a rubber-band line from
        pt to the current crosshair position. The coordinates of the point stored in result are
        expressed in terms of the current UCS. The user cannot respond to acedGetPoint() by
        entering an AutoLISP expression. The acedGetPoint() function returns one of the following:
        RTNORM if it succeeds, RTERROR if it fails, or RTCAN if the user cancels the request (by
        pressing [Esc]). It returns RTMODELESS, if the active command was registered using the
        ACRX_CMD_INTERRUPTIBLE flag and the document has received a modeless interrupt signal from
        a call to AcApDocManager::sendModelessInterrupt(). A prior call to acedInitGet() can also
        enable return values of RTNONE or RTKWORD.
        """
    @overload
    @staticmethod
    def getPoint(basePt: PyGe.Point3d, prompt: str, /) -> tuple[PyEd.PromptStatus, PyGe.Point3d]:
        """
        Gets user input for a point. The AutoCAD user can specify the point by entering a
        coordinate in the current units format; acedGetPoint() treats pt and result as
        three-dimensional points. The user can specify the point also by specifying a location on
        the graphics screen. If the pt argument is not null, AutoCAD draws a rubber-band line from
        pt to the current crosshair position. The coordinates of the point stored in result are
        expressed in terms of the current UCS. The user cannot respond to acedGetPoint() by
        entering an AutoLISP expression. The acedGetPoint() function returns one of the following:
        RTNORM if it succeeds, RTERROR if it fails, or RTCAN if the user cancels the request (by
        pressing [Esc]). It returns RTMODELESS, if the active command was registered using the
        ACRX_CMD_INTERRUPTIBLE flag and the document has received a modeless interrupt signal from
        a call to AcApDocManager::sendModelessInterrupt(). A prior call to acedInitGet() can also
        enable return values of RTNONE or RTKWORD.
        """
    @overload
    @staticmethod
    def getPoint(*args) -> tuple[PyEd.PromptStatus, PyGe.Point3d]:
        """
        Gets user input for a point. The AutoCAD user can specify the point by entering a
        coordinate in the current units format; acedGetPoint() treats pt and result as
        three-dimensional points. The user can specify the point also by specifying a location on
        the graphics screen. If the pt argument is not null, AutoCAD draws a rubber-band line from
        pt to the current crosshair position. The coordinates of the point stored in result are
        expressed in terms of the current UCS. The user cannot respond to acedGetPoint() by
        entering an AutoLISP expression. The acedGetPoint() function returns one of the following:
        RTNORM if it succeeds, RTERROR if it fails, or RTCAN if the user cancels the request (by
        pressing [Esc]). It returns RTMODELESS, if the active command was registered using the
        ACRX_CMD_INTERRUPTIBLE flag and the document has received a modeless interrupt signal from
        a call to AcApDocManager::sendModelessInterrupt(). A prior call to acedInitGet() can also
        enable return values of RTNONE or RTKWORD.
        """
    @staticmethod
    def getReal(
        prompt: str, condition: PyEd.PromptCondition = PyEd.PromptCondition.eNone, /
    ) -> tuple[PyEd.PromptStatus, float]:
        """
        Gets user input for a real value. The AutoCAD user can enter any valid real value, but the
        user cannot respond to acedGetReal() by entering an AutoLISP expression. The acedGetReal()
        function returns one of the following: RTNORM if it succeeds, RTERROR if it fails, or RTCAN
        if the user cancels the request (by pressing [Esc]). It returns RTMODELESS, if the active
        command was registered using the ACRX_CMD_INTERRUPTIBLE flag and the document has received
        a modeless interrupt signal from a call to AcApDocManager::sendModelessInterrupt(). A prior
        call to acedInitGet() can also enable return values of RTNONE or RTKWORD.
        """
    @overload
    @staticmethod
    def getString(prompt: str, /) -> tuple[PyEd.PromptStatus, str]:
        """
        Gets user input for a string, cronly If nonzero, the string can contain blanks and the user
        must terminate it by entering [Return]; if zero, entering either a blank or [Return]
        terminates the string
        """
    @overload
    @staticmethod
    def getString(
        prompt: str, condition: PyEd.PromptCondition, /
    ) -> tuple[PyEd.PromptStatus, str]:
        """
        Gets user input for a string, cronly If nonzero, the string can contain blanks and the user
        must terminate it by entering [Return]; if zero, entering either a blank or [Return]
        terminates the string
        """
    @overload
    @staticmethod
    def getString(cronly: int, prompt: str, /) -> tuple[PyEd.PromptStatus, str]:
        """
        Gets user input for a string, cronly If nonzero, the string can contain blanks and the user
        must terminate it by entering [Return]; if zero, entering either a blank or [Return]
        terminates the string
        """
    @overload
    @staticmethod
    def getString(
        cronly: int, prompt: str, condition: PyEd.PromptCondition, /
    ) -> tuple[PyEd.PromptStatus, str]:
        """
        Gets user input for a string, cronly If nonzero, the string can contain blanks and the user
        must terminate it by entering [Return]; if zero, entering either a blank or [Return]
        terminates the string
        """
    @overload
    @staticmethod
    def getString(*args) -> tuple[PyEd.PromptStatus, str]:
        """
        Gets user input for a string, cronly If nonzero, the string can contain blanks and the user
        must terminate it by entering [Return]; if zero, entering either a blank or [Return]
        terminates the string
        """
    @staticmethod
    def getViewportNumber(ptx: int, pty: int, /) -> int:
        """
        Provide coordinates in AutoCAD drawing window (in client coordinates) and this function
        will return the viewport number the coordinates correspond to. This function usually is
        used with acedCoordFromWorldToPixel() or acedCoordFromPixelToWorld(). Returns the viewport
        number based on Windows client coordinates.
        """
    @staticmethod
    def initGet(val: int, keyword: str, /) -> PromptStatus:
        """
        Initializes the options used by the next call to a user-input function, such as
        acedGetXxx(), acedDragGen(), acedEntSel(), acedNEntSelP(), or acedNEntSel().
        """
    @staticmethod
    def nEntSelP(
        prompt: str, selpt: PyGe.Point3d = ..., /
    ) -> tuple[
        PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d, PyGe.Matrix3d, list[PyDb.ObjectId]
    ]: ...
    @overload
    @staticmethod
    def nEntSelPEx(
        prompt: str, flags: int, /
    ) -> tuple[
        PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d, PyGe.Matrix3d, int, list[PyDb.ObjectId]
    ]: ...
    @overload
    @staticmethod
    def nEntSelPEx(
        prompt: str, selpt: PyGe.Point3d, flags: int, /
    ) -> tuple[
        PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d, PyGe.Matrix3d, int, list[PyDb.ObjectId]
    ]: ...
    @overload
    @staticmethod
    def nEntSelPEx(
        *args,
    ) -> tuple[
        PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d, PyGe.Matrix3d, int, list[PyDb.ObjectId]
    ]: ...
    @staticmethod
    def regen() -> None: ...
    @staticmethod
    def select(
        filter: Collection[tuple[int, Any]] = ..., /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
        """
        Returns a selection set obtained by specifying one of the AutoCAD selection modes. A
        selection mode is specified either by prompting the AutoCAD user or by filtering the
        drawing database. You must release the allocated selection set after you are finished with
        processing the selection. If you fail to do this the selection set will be kept on the
        stack until AutoCAD terminates. Since AutoCAD can only hold 128 application-based selection
        sets per session, the unreleased selection sets can result in failed object selections
        through ObjectARX.
        """
    @staticmethod
    def selectAll(
        filter: Collection[tuple[int, Any]] = ..., /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
        """
        Returns a selection set obtained by specifying one of the AutoCAD selection modes. A
        selection mode is specified either by prompting the AutoCAD user or by filtering the
        drawing database. You must release the allocated selection set after you are finished with
        processing the selection. If you fail to do this the selection set will be kept on the
        stack until AutoCAD terminates. Since AutoCAD can only hold 128 application-based selection
        sets per session, the unreleased selection sets can result in failed object selections
        through ObjectARX.
        """
    @staticmethod
    def selectFence(
        points: Collection[PyGe.Point3d], filter: Collection[tuple[int, Any]] = ..., /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
        """
        Returns a selection set obtained by specifying one of the AutoCAD selection modes. A
        selection mode is specified either by prompting the AutoCAD user or by filtering the
        drawing database. You must release the allocated selection set after you are finished with
        processing the selection. If you fail to do this the selection set will be kept on the
        stack until AutoCAD terminates. Since AutoCAD can only hold 128 application-based selection
        sets per session, the unreleased selection sets can result in failed object selections
        through ObjectARX.
        """
    @staticmethod
    def selectImplied() -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]: ...
    @staticmethod
    def selectLast(
        filter: Collection[tuple[int, Any]] = ..., /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
        """
        Returns a selection set obtained by specifying one of the AutoCAD selection modes. A
        selection mode is specified either by prompting the AutoCAD user or by filtering the
        drawing database. You must release the allocated selection set after you are finished with
        processing the selection. If you fail to do this the selection set will be kept on the
        stack until AutoCAD terminates. Since AutoCAD can only hold 128 application-based selection
        sets per session, the unreleased selection sets can result in failed object selections
        through ObjectARX.
        """
    @staticmethod
    def selectPrevious(
        filter: Collection[tuple[int, Any]] = ..., /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
        """
        Returns a selection set obtained by specifying one of the AutoCAD selection modes. A
        selection mode is specified either by prompting the AutoCAD user or by filtering the
        drawing database. You must release the allocated selection set after you are finished with
        processing the selection. If you fail to do this the selection set will be kept on the
        stack until AutoCAD terminates. Since AutoCAD can only hold 128 application-based selection
        sets per session, the unreleased selection sets can result in failed object selections
        through ObjectARX.
        """
    @staticmethod
    def selectPrompt(
        addPromt: str, remPromt: str, filter: Collection[tuple[int, Any]] = ..., /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
        """
        Returns a selection set obtained by specifying one of the AutoCAD selection modes. A
        selection mode is specified either by prompting the AutoCAD user or by filtering the
        drawing database. You must release the allocated selection set after you are finished with
        processing the selection. If you fail to do this the selection set will be kept on the
        stack until AutoCAD terminates. Since AutoCAD can only hold 128 application-based selection
        sets per session, the unreleased selection sets can result in failed object selections
        through ObjectARX.
        """
    @staticmethod
    def selectWindow(
        pt1: PyGe.Point3d, pt2: PyGe.Point3d, filter: Collection[tuple[int, Any]] = ..., /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
        """
        Returns a selection set obtained by specifying one of the AutoCAD selection modes. A
        selection mode is specified either by prompting the AutoCAD user or by filtering the
        drawing database. You must release the allocated selection set after you are finished with
        processing the selection. If you fail to do this the selection set will be kept on the
        stack until AutoCAD terminates. Since AutoCAD can only hold 128 application-based selection
        sets per session, the unreleased selection sets can result in failed object selections
        through ObjectARX.
        """
    @staticmethod
    def selectWindowPolygon(
        points: Collection[PyGe.Point3d], filter: Collection[tuple[int, Any]] = ..., /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
        """
        Returns a selection set obtained by specifying one of the AutoCAD selection modes. A
        selection mode is specified either by prompting the AutoCAD user or by filtering the
        drawing database. You must release the allocated selection set after you are finished with
        processing the selection. If you fail to do this the selection set will be kept on the
        stack until AutoCAD terminates. Since AutoCAD can only hold 128 application-based selection
        sets per session, the unreleased selection sets can result in failed object selections
        through ObjectARX.
        """
    @staticmethod
    def setAllowDuplicateSelection(doc: PyAp.Document, flag: bool, /) -> None:
        """
        This function allows and disallows duplicate entities in selection sets. If flag is true, a
        reference counter is incremented that, when non-zero, enables duplicate selection. If flag
        is false, the counter is decremented. This setting impacts the PICKFIRST selection set, the
        PREVIOUS selection set, and AutoCAD commands that acquire selection sets from the user. An
        application that enables duplicate selections is responsible for removing duplicate entries
        in the AcEdSSGetFilter::endSSGet() notification if the current command cannot handle
        duplicate entries. Returns Acad::eOk if successful. Returns Acad::eInvalidContext if flag
        is false and duplicate selection is already disabled. Returns Acad::eInvalidInput if pDoc
        is NULL.
        """
    @staticmethod
    def setCurrentUCS(ucs: PyGe.Matrix3d, /) -> None:
        """
        This function sets the current UCS from the 3D matrix mat. The first row of the matrix is
        the UCS X-axis (in WCS coordinates), the second row is the UCS Y-axis, and the third row is
        the UCS Z-axis. This function must not be used while acedCommand is active. Always returns
        Acad::eOk.
        """
    @staticmethod
    def ssget(
        mode: str, arg1: object, arg2: object, filter: Collection[tuple[int, Any]] = ..., /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
        """
        Returns a selection set obtained by specifying one of the AutoCAD selection modes. A
        selection mode is specified either by prompting the AutoCAD user or by filtering the
        drawing database. You must release the allocated selection set after you are finished with
        processing the selection. If you fail to do this the selection set will be kept on the
        stack until AutoCAD terminates. Since AutoCAD can only hold 128 application-based selection
        sets per session, the unreleased selection sets can result in failed object selections
        through ObjectARX.
        """
    @staticmethod
    def traceBoundary(point: PyGe.Point3d, detectIslands: bool, /) -> list[PyDb.Polyline]:
        """
        Performs a boundary trace on the given seedPoint, and returns a set of AcDbPolyline *
        objects that represent the boundary found. To succeed, the entities that form the boundary
        to be found must be entirely visible on screen in the AutoCAD editor.
        """
    @staticmethod
    def ucsNormalVector() -> PyGe.Vector3d:
        """
        Returns a vector indicating the Z-axis direction of the current UCS. The vector is the
        normal to the X and Y axes.
        """
    @staticmethod
    def ucsXDir() -> PyGe.Vector3d:
        """
        Returns the X-axis direction of the current UCS.
        """
    @staticmethod
    def ucsYDir() -> PyGe.Vector3d:
        """
        Returns the Y-axis direction of the current UCS.
        """

class EditorReactor:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def abortAttach(self, dbFrom: PyDb.Database, /) -> None: ...
    def abortDeepClone(self, idMap: PyDb.IdMapping, /) -> None: ...
    def abortDxfIn(self, db: PyDb.Database, /) -> None: ...
    def abortDxfOut(self, db: PyDb.Database, /) -> None: ...
    def abortInsert(self, db: PyDb.Database, /) -> None: ...
    def abortRestore(self, dbTo: PyDb.Database, /) -> None: ...
    def abortSave(self, db: PyDb.Database, /) -> None: ...
    def abortWblock(self, db: PyDb.Database, /) -> None: ...
    def addReactor(self, /) -> None: ...
    def beginAttach(self, dbTo: PyDb.Database, val: str, dbFrom: PyDb.Database, /) -> None: ...
    def beginCloseAll(self, /) -> None: ...
    def beginDeepClone(self, db: PyDb.Database, idMap: PyDb.IdMapping, /) -> None: ...
    def beginDeepCloneXlation(self, idMap: PyDb.IdMapping, /) -> PyDb.ErrorStatus: ...
    def beginDocClose(self, db: PyDb.Database, /) -> None: ...
    def beginDoubleClick(self, pt: PyGe.Point3d, /) -> None: ...
    def beginDwgOpen(self, fineName: str, /) -> None: ...
    def beginDxfIn(self, db: PyDb.Database, /) -> None: ...
    def beginDxfOut(self, db: PyDb.Database, /) -> None: ...
    @overload
    def beginInsert(
        self, dbTo: PyDb.Database, pBlockName: str, dbFrom: PyDb.Database, /
    ) -> None: ...
    @overload
    def beginInsert(
        self, dbTo: PyDb.Database, xform: PyGe.Matrix3d, dbFrom: PyDb.Database, /
    ) -> None: ...
    @overload
    def beginInsert(self, *args) -> None: ...
    def beginQuit(self, /) -> None: ...
    def beginRestore(self, dbTo: PyDb.Database, val: str, dbFrom: PyDb.Database, /) -> None: ...
    def beginRightClick(self, pt: PyGe.Point3d, /) -> None: ...
    def beginSave(self, db: PyDb.Database, fname: str, /) -> None: ...
    def beginWblock(
        self, dbTo: PyDb.Database, dbFrom: PyDb.Database, id: PyDb.ObjectId, /
    ) -> None: ...
    def beginWblockObjects(self, dbTo: PyDb.Database, idMap: PyDb.IdMapping, /) -> None: ...
    def cmdIUnkModified(self, command: str, /) -> None: ...
    def comandeered(
        self, dbTo: PyDb.Database, id: PyDb.ObjectId, dbFrom: PyDb.Database, /
    ) -> None: ...
    def commandCancelled(self, cmdStr: str, /) -> None: ...
    def commandEnded(self, cmdStr: str, /) -> None: ...
    def commandFailed(self, cmdStr: str, /) -> None: ...
    def commandWillStart(self, cmdStr: str, /) -> None: ...
    def databaseConstructed(self, db: PyDb.Database, /) -> None: ...
    def databaseToBeDestroyed(self, db: PyDb.Database, /) -> None: ...
    def docCloseAborted(self, db: PyDb.Database, /) -> None: ...
    def docCloseWillStart(self, db: PyDb.Database, /) -> None: ...
    def docFrameMovedOrResized(self, hwndDocFrame: int, moved: bool, /) -> None: ...
    def dwgViewResized(self, hwndDwgView: int, /) -> None: ...
    def dxfInComplete(self, db: PyDb.Database, /) -> None: ...
    def dxfOutComplete(self, db: PyDb.Database, /) -> None: ...
    def endAttach(self, db: PyDb.Database, /) -> None: ...
    def endDeepClone(self, idMap: PyDb.IdMapping, /) -> None: ...
    def endDwgOpen(self, fineName: str, db: PyDb.Database, /) -> None: ...
    def endInsert(self, db: PyDb.Database, /) -> None: ...
    def endRestore(self, dbTo: PyDb.Database, /) -> None: ...
    def endWblock(self, db: PyDb.Database, /) -> None: ...
    def fullRegenEnded(self, db: PyDb.Database, regenedViewports: list[int], /) -> None: ...
    def fullRegenWillStart(self, db: PyDb.Database, /) -> None: ...
    def initialDwgFileOpenComplete(self, db: PyDb.Database, /) -> None: ...
    def layoutSwitched(self, layoutName: str, /) -> None: ...
    def layoutToBeSwitched(self, oldLayoutName: str, newLayoutName: str, /) -> None: ...
    def lispCancelled(self, /) -> None: ...
    def lispEnded(self, /) -> None: ...
    def lispWillStart(self, val: str, /) -> None: ...
    def mainFrameMovedOrResized(self, hwndDocFrame: int, moved: bool, /) -> None: ...
    def modelessOperationEnded(self, context: str, /) -> None: ...
    def modelessOperationWillStart(self, context: str, /) -> None: ...
    def objectsLazyLoaded(self, ids: list[PyDb.ObjectId], /) -> None: ...
    def otherAttach(self, dbTo: PyDb.Database, dbFrom: PyDb.Database, /) -> None: ...
    def otherInsert(
        self, dbTo: PyDb.Database, idMap: PyDb.IdMapping, dbFrom: PyDb.Database, /
    ) -> None: ...
    def otherWblock(
        self, dbTo: PyDb.Database, idMap: PyDb.IdMapping, dbFrom: PyDb.Database, /
    ) -> None: ...
    def partialOpenNotice(self, db: PyDb.Database, /) -> None: ...
    def pickfirstModified(self, /) -> None: ...
    def preXrefLockFile(self, id: PyDb.ObjectId, /) -> None: ...
    def quitAborted(self, /) -> None: ...
    def quitWillStart(self, /) -> None: ...
    def redirected(self, newId: PyDb.ObjectId, oldId: PyDb.ObjectId, /) -> None: ...
    def removeReactor(self, /) -> None: ...
    def saveComplete(self, db: PyDb.Database, fname: str, /) -> None: ...
    def sysVarChanged(self, varName: str, success: bool, /) -> None: ...
    def sysVarWillChange(self, varName: str, /) -> None: ...
    def toolbarBitmapSizeChanged(self, large: bool, /) -> None: ...
    def toolbarBitmapSizeWillChange(self, large: bool, /) -> None: ...
    def undoSubcommandAuto(self, activity: int, state: bool, /) -> None: ...
    def undoSubcommandBack(self, activity: int, /) -> None: ...
    def undoSubcommandBegin(self, activity: int, /) -> None: ...
    def undoSubcommandControl(self, activity: int, option: int, /) -> None: ...
    def undoSubcommandEnd(self, activity: int, /) -> None: ...
    def undoSubcommandMark(self, activity: int, /) -> None: ...
    def undoSubcommandNumber(self, activity: int, num: int, /) -> None: ...
    def veto(self, /) -> PyDb.ErrorStatus: ...
    def viewChanged(self, /) -> None: ...
    def wblockNotice(self, db: PyDb.Database, /) -> None: ...
    def xrefSubcommandAttachItem(self, db: PyDb.Database, activity: int, path: str, /) -> None: ...
    def xrefSubcommandBindItem(
        self, db: PyDb.Database, activity: int, blockId: PyDb.ObjectId, /
    ) -> None: ...
    def xrefSubcommandDetachItem(
        self, db: PyDb.Database, activity: int, blockId: PyDb.ObjectId, /
    ) -> None: ...
    def xrefSubcommandOverlayItem(
        self, db: PyDb.Database, activity: int, path: str, /
    ) -> None: ...
    def xrefSubcommandPathItem(
        self, activity: int, blockId: PyDb.ObjectId, path: str, /
    ) -> None: ...
    def xrefSubcommandReloadItem(
        self, db: PyDb.Database, activity: int, blockId: PyDb.ObjectId, /
    ) -> None: ...
    def xrefSubcommandUnloadItem(
        self, db: PyDb.Database, activity: int, blockId: PyDb.ObjectId, /
    ) -> None: ...

class InputPoint:
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def alignmentPaths(self, /) -> list[PyGe.Curve]: ...
    def cartesianSnappedPoint(self, /) -> PyGe.Point3d: ...
    def computedPoint(self, /) -> PyGe.Point3d: ...
    def document(self, /) -> PyAp.Document: ...
    def drawContext(self, /) -> PyGi.ViewportDraw: ...
    def grippedPoint(self, /) -> PyGe.Point3d: ...
    def gsSelectionMark(self, /) -> list[int]: ...
    def history(self, /) -> PointHistory: ...
    def keyPointEntities(self, /) -> list[PyDb.ObjectId]: ...
    def keyPointGsSelectionMark(self, /) -> list[int]: ...
    def lastPoint(self, /) -> PyGe.Point3d: ...
    def nestedKeyPointEntities(self, /) -> list[list[PyDb.ObjectId]]: ...
    def nestedPickedEntities(self, /) -> list[list[PyDb.ObjectId]]: ...
    def osnapMask(self, /) -> PyDb.OsnapMask: ...
    def osnapOverrides(self, /) -> PyDb.OsnapMask: ...
    def osnappedPoint(self, /) -> PyGe.Point3d: ...
    def pickedEntities(self, /) -> list[PyDb.ObjectId]: ...
    def pointComputed(self, /) -> bool: ...
    def rawPoint(self, /) -> PyGe.Point3d: ...
    def tooltipString(self, /) -> str: ...

class InputPointFilter:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def processInputPoint(
        self, input: PyEd.InputPoint, output: PyEd.InputPointFilterResult, /
    ) -> PyDb.ErrorStatus: ...

class InputPointFilterResult:
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def displayOsnapGlyph(self, /) -> bool: ...
    def newPoint(self, /) -> PyGe.Point3d: ...
    def newTooltipString(self, /) -> str: ...
    def retry(self, /) -> bool: ...
    def setDisplayOsnapGlyph(self, val: bool, /) -> None: ...
    def setNewPoint(self, val: PyGe.Point3d, /) -> None: ...
    def setNewTooltipString(self, val: str, /) -> None: ...
    def setRetry(self, val: bool, /) -> None: ...

class InputPointManager:
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def addPointMonitor(self, monitor: PyEd.InputPointMonitor, /) -> None: ...
    def disableSystemCursorGraphics(self, /) -> bool: ...
    def enableMultiSubentPathSelection(self, /) -> None: ...
    def enableSystemCursorGraphics(self, /) -> bool: ...
    def forcedPickCount(self, /) -> int: ...
    def hasFilter(self, /) -> bool: ...
    def mouseHasMoved(self, /) -> int: ...
    def registerPointFilter(self, filter: PyEd.InputPointFilter, /) -> None: ...
    def removePointMonitor(self, monitor: PyEd.InputPointMonitor, /) -> None: ...
    def revokePointFilter(self, /) -> None: ...
    def systemCursorDisableCount(self, /) -> int: ...
    def turnOffForcedPick(self, /) -> bool: ...
    def turnOffSubentityWindowSelection(self, /) -> bool: ...
    def turnOnSubentityWindowSelection(self, /) -> bool: ...

class InputPointMonitor:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def monitorInputPoint(
        self, input: PyEd.InputPoint, output: PyEd.InputPointMonitorResult, /
    ) -> PyDb.ErrorStatus: ...

class InputPointMonitorResult:
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def additionalTooltipString(self, /) -> str: ...
    def appendToTooltipStr(self, /) -> bool: ...
    def setAdditionalTooltipString(self, val: str, /) -> None: ...

class Jig:
    def __init__(self, entity: PyDb.Entity, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def acquireAngle(self, basePnt: PyGe.Point3d = ..., /) -> tuple[PyEd.DragStatus, float]: ...
    def acquireDist(self, basePnt: PyGe.Point3d = ..., /) -> tuple[PyEd.DragStatus, float]: ...
    def acquirePoint(
        self, basePnt: PyGe.Point3d = ..., /
    ) -> tuple[PyEd.DragStatus, PyGe.Point3d]: ...
    def acquireString(self, /) -> tuple[PyEd.DragStatus, str]: ...
    def append(self, /) -> PyDb.ObjectId: ...
    @staticmethod
    def className() -> str: ...
    def dispPrompt(self, /) -> str: ...
    def drag(self, style: PyEd.DragStyle = ..., /) -> DragStatus: ...
    def keywordList(self, /) -> str: ...
    def sampler(self, /) -> DragStatus: ...
    def setDispPrompt(self, val: str, /) -> None: ...
    def setKeywordList(self, val: str, /) -> None: ...
    def setSpecialCursorType(self, val: PyEd.CursorType, /) -> None: ...
    def setUserInputControls(self, val: PyEd.UserInputControls, /) -> None: ...
    def specialCursorType(self, /) -> CursorType: ...
    def update(self, /) -> bool: ...
    def userInputControls(self, /) -> UserInputControls: ...

class PointHistory(_BoostPythonEnum):
    eTablet: ClassVar[Self]  # 1
    eNotDigitizer: ClassVar[Self]  # 2
    eLastPt: ClassVar[Self]  # 4
    eGripped: ClassVar[Self]  # 8
    eCartSnapped: ClassVar[Self]  # 16
    eOrtho: ClassVar[Self]  # 32
    eCyclingPt: ClassVar[Self]  # 64
    eOsnapped: ClassVar[Self]  # 128
    ePolarAngle: ClassVar[Self]  # 256
    eAligned: ClassVar[Self]  # 1024
    eAppFiltered: ClassVar[Self]  # 2048
    eForcedPick: ClassVar[Self]  # 4096
    ePickMask: ClassVar[Self]  # 57344
    eDidNotPick: ClassVar[Self]  # 0
    eUsedPickBox: ClassVar[Self]  # 8192
    eUsedOsnapBox: ClassVar[Self]  # 16384
    ePickAborted: ClassVar[Self]  # 32768
    eXPending: ClassVar[Self]  # 65536
    eYPending: ClassVar[Self]  # 131072
    eZPending: ClassVar[Self]  # 262144
    eCoordPending: ClassVar[Self]  # 458752
    eFromKeyboard: ClassVar[Self]  # 524288
    eNotInteractive: ClassVar[Self]  # 1048576
    eDirectDistance: ClassVar[Self]  # 2097152
    eGizmoConstrainted: ClassVar[Self]  # 4194304

class PromptCondition(_BoostPythonEnum):
    eNone: ClassVar[Self]  # 0
    eNoZero: ClassVar[Self]  # 1
    eNoEmpty: ClassVar[Self]  # 1
    eNoNegative: ClassVar[Self]  # 2

class PromptStatus(_BoostPythonEnum):
    eNone: ClassVar[Self]  # 5000
    eModeless: ClassVar[Self]  # 5027
    eNormal: ClassVar[Self]  # 5100
    kNormal: ClassVar[Self]  # 5100
    eOk: ClassVar[Self]  # 5100
    eError: ClassVar[Self]  # -5001
    eCancel: ClassVar[Self]  # -5002
    eRejected: ClassVar[Self]  # -5003
    eFailed: ClassVar[Self]  # -5004
    eKeyword: ClassVar[Self]  # -5005
    eDirect: ClassVar[Self]  # -5999

class SelectionSet:
    def __init__(self, /) -> None: ...
    def __iter__(self, /) -> Iterator[PyDb.ObjectId]: ...
    def __reduce__(self, /) -> Any: ...
    def add(self, id: PyDb.ObjectId, /) -> None: ...
    def adsname(self, /) -> PyDb.AdsName: ...
    def clear(self, /) -> None: ...
    def hasMember(self, id: PyDb.ObjectId, /) -> bool: ...
    def isInitialized(self, /) -> bool: ...
    def keepAlive(self, flag: bool, /) -> None: ...
    @overload
    def objectIdArray(self, desc: PyRx.RxClass = PyDb.Entity, /) -> PyDb.ObjectIdArray: ...
    @overload
    def objectIdArray(self, descList: list[PyRx.RxClass], /) -> PyDb.ObjectIdArray: ...
    @overload
    def objectIdArray(self, *args) -> PyDb.ObjectIdArray: ...
    @overload
    def objectIds(self, desc: PyRx.RxClass = PyDb.Entity, /) -> list[PyDb.ObjectId]: ...
    @overload
    def objectIds(self, descList: list[PyRx.RxClass], /) -> list[PyDb.ObjectId]: ...
    @overload
    def objectIds(self, *args) -> list[PyDb.ObjectId]: ...
    def remove(self, id: PyDb.ObjectId, /) -> None: ...
    def size(self, /) -> int: ...
    def ssNameX(self, val: int = 0, /) -> list: ...
    def ssSetFirst(self, /) -> bool: ...
    def ssXform(self, xform: PyGe.Matrix3d, /) -> PromptStatus: ...
    def toList(self, /) -> list[PyDb.ObjectId]: ...

class UIContext:
    def OnUpdateMenu(self, /) -> None: ...
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def addDefaultContextMenu(context: PyEd.UIContext, appName: str = ..., /) -> bool: ...
    @staticmethod
    def addObjectContextMenu(val: PyRx.RxClass, context: PyEd.UIContext, /) -> bool: ...
    def getMenuContext(self, val: PyRx.RxClass, ids: list[PyDb.ObjectId], /) -> object: ...
    def hitPoint(self, /) -> PyGe.Point3d: ...
    def onCommand(self, mnuCmd: int, /) -> None: ...
    @staticmethod
    def removeDefaultContextMenu(context: PyEd.UIContext, /) -> bool: ...
    @staticmethod
    def removeObjectContextMenu(val: PyRx.RxClass, context: PyEd.UIContext, /) -> bool: ...

class UserInputControls(_BoostPythonEnum):
    kGovernedByOrthoMode: ClassVar[Self]  # 1
    kNullResponseAccepted: ClassVar[Self]  # 2
    kDontEchoCancelForCtrlC: ClassVar[Self]  # 4
    kDontUpdateLastPoint: ClassVar[Self]  # 8
    kNoDwgLimitsChecking: ClassVar[Self]  # 16
    kNoZeroResponseAccepted: ClassVar[Self]  # 32
    kNoNegativeResponseAccepted: ClassVar[Self]  # 64
    kAccept3dCoordinates: ClassVar[Self]  # 128
    kAcceptMouseUpAsPoint: ClassVar[Self]  # 256
    kAnyBlankTerminatesInput: ClassVar[Self]  # 512
    kInitialBlankTerminatesInput: ClassVar[Self]  # 1024
    kAcceptOtherInputString: ClassVar[Self]  # 2048
    kGovernedByUCSDetect: ClassVar[Self]  # 4096
    kNoZDirectionOrtho: ClassVar[Self]  # 8192
    kImpliedFaceForUCSChange: ClassVar[Self]  # 16384
    kUseBasePointElevation: ClassVar[Self]  # 32768
    kDisableDirectDistanceInput: ClassVar[Self]  # 65536

class UserInteraction:
    def __init__(self, doc: PyAp.Document = "current", isPrompting: bool = True, /) -> None: ...
    def __reduce__(self, /) -> Any: ...

class Util:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def angle(pt1: PyGe.Point3d, pt2: PyGe.Point3d, /) -> float: ...
    @staticmethod
    def cvUnit(val: float, oldunit: str, newunit: str, /) -> float: ...
    @staticmethod
    def distance(pt1: PyGe.Point3d, pt2: PyGe.Point3d, /) -> float: ...
    @staticmethod
    def polar(pt1: PyGe.Point3d, angle: float, dist: float, /) -> PyGe.Point3d: ...
    @staticmethod
    def wcMatch(string: str, pattern: str, ignoreCase: bool, /) -> bool: ...

def print(*args) -> None:
    """
    print( (object)arg1) -> None :

    C++ signature :
        void print(class boost::python::api::object)
    """
