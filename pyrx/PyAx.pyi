import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
import PySm
import PyBr
import PyAx
from typing import overload
from typing import Any

class AcActiveSpace(object):
    def acModelSpace (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acPaperSpace (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcAlignmentPointAcquisition(object):
    def acAlignPntAcquisitionAutomatic (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acAlignPntAcquisitionShiftToAcquire (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcColor(object):
    def acBlue (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acByBlock (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acByLayer (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acCyan (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acGreen (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acMagenta (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acRed (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acWhite (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acYellow (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcColorMethod(object):
    def acColorMethodByACI (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acColorMethodByBlock (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acColorMethodByLayer (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acColorMethodByRGB (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acColorMethodForeground (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcDrawingAreaSCMCommand(object):
    def acEnableSCM (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acEnableSCMOptions (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acEnter (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcDrawingAreaSCMDefault(object):
    def acRepeatLastCommand (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acSCM (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcDrawingAreaSCMEdit(object):
    def acEdRepeatLastCommand (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acEdSCM (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcInsertUnits(object):
    def acInsertUnitsAngstroms (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsAstronomicalUnits (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsCentimeters (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsDecameters (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsDecimeters (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsFeet (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsGigameters (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsHectometers (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsInches (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsKilometers (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsLightYears (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsMeters (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsMicroinches (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsMicrons (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsMiles (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsMillimeters (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsMils (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsNanometers (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsParsecs (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsUSSurveyFeet (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsUSSurveyInch (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsUSSurveyMile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsUSSurveyYard (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsUnitless (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acInsertUnitsYards (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcKeyboardAccelerator(object):
    def acPreferenceClassic (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcKeyboardPriority(object):
    def acKeyboardEntry (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acKeyboardEntryExceptScripts (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acKeyboardRunningObjSnap (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcMenuFileType(object):
    def acMenuFileCompiled (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acMenuFileSource (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcMenuGroupType(object):
    def acBaseMenuGroup (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acPartialMenuGroup (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcMenuItemType(object):
    def acMenuItem (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acMenuSeparator (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acMenuSubMenu (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcPreviewMode(object):
    def acFullPreview (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acPartialPreview (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcSectionGeneration(object):
    def acSectionGenerationDestinationFile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acSectionGenerationDestinationNewBlock (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acSectionGenerationDestinationReplaceBlock (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acSectionGenerationSourceAllObjects (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acSectionGenerationSourceSelectedObjects (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcToolbarDockStatus(object):
    def acToolbarDockBottom (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acToolbarDockLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acToolbarDockRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acToolbarDockTop (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acToolbarFloating (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcToolbarItemType(object):
    def acToolbarButton (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acToolbarControl (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acToolbarFlyout (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acToolbarSeparator (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcWindowState(object):
    def acMax (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acMin (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acNorm (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcZoomScaleType(object):
    def acZoomScaledAbsolute (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acZoomScaledRelative (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def acZoomScaledRelativePSpace (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcadAcCmColor(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadApplication(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...
    def acadState (self)-> PyAx.AcadState :
        '''                             '''
        ...
    def activeDocument (self)-> PyAx.AcadDocument :
        '''                             '''
        ...
    def caption (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def documents (self)-> PyAx.AcadDocuments :
        '''                             '''
        ...
    def eval (self, sval: str)-> None :
        '''                             '''
        ...
    def fullName (self)-> str :
        '''                             '''
        ...
    def getHWND (self)-> int :
        '''                             '''
        ...
    def getHeight (self)-> int :
        '''                             '''
        ...
    def getName (self)-> str :
        '''                             '''
        ...
    def getPath (self)-> str :
        '''                             '''
        ...
    def getWidth (self)-> int :
        '''                             '''
        ...
    def getWindowLeft (self)-> int :
        '''                             '''
        ...
    def getWindowState (self)-> PyAx.AcWindowState :
        '''                             '''
        ...
    def getWindowTop (self)-> int :
        '''                             '''
        ...
    def isVisible (self)-> bool :
        '''                             '''
        ...
    def listArx (self)-> list :
        '''                             '''
        ...
    def loadArx (self, arx: str)-> None :
        '''                             '''
        ...
    def loadDVB (self, dvb: str)-> None :
        '''                             '''
        ...
    def localeId (self)-> int :
        '''                             '''
        ...
    def menuBar (self)-> PyAx.AcadMenuBar :
        '''                             '''
        ...
    def menuGroups (self)-> PyAx.AcadMenuGroups :
        '''                             '''
        ...
    def preferences (self)-> PyAx.AcadPreferences :
        '''                             '''
        ...
    def quit (self)-> None :
        '''                             '''
        ...
    def runMacro (self, macro: str)-> None :
        '''                             '''
        ...
    def setActiveDocument (self, doc : PyAx.AcadDocument)-> None :
        '''                             '''
        ...
    def setHeight (self, height: int)-> None :
        '''                             '''
        ...
    def setVisible (self, visible: bool)-> None :
        '''                             '''
        ...
    def setWidth (self, width: int)-> None :
        '''                             '''
        ...
    def setWindowLeft (self, left: int)-> None :
        '''                             '''
        ...
    def setWindowState (self, state: PyAx.AcWindowState)-> None :
        '''                             '''
        ...
    def setWindowTop (self, top: int)-> None :
        '''                             '''
        ...
    def unloadArx (self, arx: str)-> None :
        '''                             '''
        ...
    def unloadDVB (self, dvb: str)-> None :
        '''                             '''
        ...
    def update (self)-> None :
        '''                             '''
        ...
    def version (self)-> str :
        '''                             '''
        ...
    def zoomAll (self)-> None :
        '''                             '''
        ...
    def zoomCenter (self, pt: PyGe.Point3d, magnify: float)-> None :
        '''                             '''
        ...
    def zoomExtents (self)-> None :
        '''                             '''
        ...
    def zoomPickWindow (self)-> None :
        '''                             '''
        ...
    def zoomPrevious (self)-> None :
        '''                             '''
        ...
    def zoomScaled (self, magnify: float, scaletype: PyAx.AcZoomScaleType)-> None :
        '''                             '''
        ...

class AcadDatabase(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadDatabasePreferences(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadDocument(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...

class AcadDocuments(object):
    def __getitem__ (self, index: int)-> PyAx.AcadDocument :
        '''                             '''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def add (self, template: str = None)-> PyAx.AcadDocument :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def close (self)-> None :
        '''                             '''
        ...
    def count (self)-> int :
        '''                             '''
        ...
    def item (self, index: int)-> PyAx.AcadDocument :
        '''                             '''
        ...
    def open (self, path: str, readOnly: bool)-> PyAx.AcadDocument :
        '''                             '''
        ...

class AcadDynamicBlockReferenceProperty(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadEntity(AcadObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyAx.AcadObject)-> PyAx.AcadEntity :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def transformBy (self, xform: PyGe.Matrix3d)-> None :
        '''                             '''
        ...

class AcadHyperlink(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadMenuBar(object):
    def __getitem__ (self, index: int)-> PyAx.AcadPopupMenu :
        '''                             '''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def count (self)-> int :
        '''                             '''
        ...
    def item (self, index)-> PyAx.AcadPopupMenu :
        '''                             '''
        ...

class AcadMenuGroup(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def fileName (self)-> str :
        '''                             '''
        ...
    def menuType (self)-> PyAx.AcMenuGroupType :
        '''                             '''
        ...
    def menus (self)-> PyAx.AcadPopupMenus :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def parent (self)-> PyAx.AcadMenuGroups :
        '''                             '''
        ...
    def save (self, menuType: PyAx.AcadMenuGroup)-> None :
        '''                             '''
        ...
    def saveAs (self, menuFileName: str, menuType: PyAx.AcadMenuGroup)-> None :
        '''                             '''
        ...
    def toolbars (self)-> PyAx.AcadToolbars :
        '''                             '''
        ...
    def unload (self)-> None :
        '''                             '''
        ...

class AcadMenuGroups(object):
    def __getitem__ (self, index: int)-> PyAx.AcadMenuGroup :
        '''                             '''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def count (self)-> int :
        '''                             '''
        ...
    def item (self, idx : int)-> PyAx.AcadMenuGroup :
        '''                             '''
        ...
    def load (self, menuFileName : str, baseMenu : PyAx.AcadMenuGroup = None)-> PyAx.AcadMenuGroup :
        '''                             '''
        ...

class AcadObject(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyAx.AcadObject)-> PyAx.AcadObject :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def delete (self)-> None :
        '''                             '''
        ...
    def erase (self)-> None :
        '''                             '''
        ...
    def getXData (self, appName: str)-> list :
        '''                             '''
        ...
    def handle (self)-> PyDb.Handle :
        '''                             '''
        ...
    def hasExtensionDictionary (self)-> bool :
        '''                             '''
        ...
    def isEqualTo (self)-> bool :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def objectId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def objectName (self)-> str :
        '''                             '''
        ...
    def ownerId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def setXdata (self)-> None :
        '''                             '''
        ...

class AcadPlot(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadPopupMenu(object):
    def __getitem__ (self, index: int)-> PyAx.AcadPopupMenuItem :
        '''                             '''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def addMenuItem (self, idx : int, label : str, macro : str)-> PyAx.AcadPopupMenuItem :
        '''                             '''
        ...
    def addSeparator (self, idx : int)-> PyAx.AcadPopupMenuItem :
        '''                             '''
        ...
    def addSubMenu (self, idx : int, label : str)-> PyAx.AcadPopupMenuItem :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def count (self)-> int :
        '''                             '''
        ...
    def insertInMenuBar (self, idx : int)-> None :
        '''                             '''
        ...
    def isOnMenuBar (self)-> bool :
        '''                             '''
        ...
    def isShortcutMenu (self)-> bool :
        '''                             '''
        ...
    def item (self, idx : int)-> PyAx.AcadPopupMenuItem :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def nameNoMnemonic (self)-> str :
        '''                             '''
        ...
    def parent (self)-> PyAx.AcadPopupMenus :
        '''                             '''
        ...
    def removeFromMenuBar (self)-> None :
        '''                             '''
        ...
    def setName (self, name: str)-> None :
        '''                             '''
        ...
    def tagString (self)-> str :
        '''                             '''
        ...

class AcadPopupMenuItem(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def caption (self)-> str :
        '''                             '''
        ...
    def check (self)-> bool :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def clear (self)-> None :
        '''                             '''
        ...
    def enable (self)-> bool :
        '''                             '''
        ...
    def endSubMenuLevel (self)-> int :
        '''                             '''
        ...
    def getType (self)-> PyAx.AcMenuItemType :
        '''                             '''
        ...
    def helpString (self)-> str :
        '''                             '''
        ...
    def index (self)-> int :
        '''                             '''
        ...
    def label (self)-> str :
        '''                             '''
        ...
    def macro (self)-> str :
        '''                             '''
        ...
    def parent (self)-> PyAx.AcadPopupMenu :
        '''                             '''
        ...
    def setCheck (self, enable: bool)-> None :
        '''                             '''
        ...
    def setEnable (self, enable: bool)-> None :
        '''                             '''
        ...
    def setEndSubMenuLevel (self, val: int)-> None :
        '''                             '''
        ...
    def setHelpString (self, helpString: str)-> None :
        '''                             '''
        ...
    def setLabel (self, label: str)-> None :
        '''                             '''
        ...
    def setMacro (self, macro: str)-> None :
        '''                             '''
        ...
    def setTagString (self, tag: str)-> None :
        '''                             '''
        ...
    def subMenu (self)-> PyAx.AcadPopupMenu :
        '''                             '''
        ...
    def tagString (self)-> str :
        '''                             '''
        ...

class AcadPopupMenus(object):
    def __getitem__ (self, index: int)-> PyAx.AcadPopupMenu :
        '''                             '''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def add (self, toolbarName: str)-> PyAx.AcadPopupMenu :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def count (self)-> int :
        '''                             '''
        ...
    def insertMenuInMenuBar (self, insertMenuInMenuBar: str, idx : int)-> None :
        '''                             '''
        ...
    def item (self, idx : int)-> PyAx.AcadPopupMenu :
        '''                             '''
        ...
    def parent (self)-> PyAx.AcadMenuGroup :
        '''                             '''
        ...
    def removeMenuFromMenuBar (self, idx : int)-> None :
        '''                             '''
        ...

class AcadPreferences(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def display (self)-> PyAx.AcadPreferencesDisplay :
        '''                             '''
        ...
    def drafting (self)-> PyAx.AcadPreferencesDrafting :
        '''                             '''
        ...
    def files (self)-> PyAx.AcadPreferencesFiles :
        '''                             '''
        ...
    def openSave (self)-> PyAx.AcadPreferencesOpenSave :
        '''                             '''
        ...
    def output (self)-> PyAx.AcadPreferencesOutput :
        '''                             '''
        ...
    def profiles (self)-> PyAx.AcadPreferencesProfiles :
        '''                             '''
        ...
    def selection (self)-> PyAx.AcadPreferencesSelection :
        '''                             '''
        ...
    def system (self)-> PyAx.AcadPreferencesSystem :
        '''                             '''
        ...
    def user (self)-> PyAx.AcadPreferencesUser :
        '''                             '''
        ...

class AcadPreferencesDisplay(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadPreferencesDrafting(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def alignmentPointAcquisition (self)-> PyAx.AcAlignmentPointAcquisition :
        '''                             '''
        ...
    def autoSnapAperture (self)-> bool :
        '''                             '''
        ...
    def autoSnapApertureSize (self)-> int :
        '''                             '''
        ...
    def autoSnapMagnet (self)-> bool :
        '''                             '''
        ...
    def autoSnapMarker (self)-> bool :
        '''                             '''
        ...
    def autoSnapMarkerColor (self)-> PyAx.AcColor :
        '''                             '''
        ...
    def autoSnapMarkerSize (self)-> int :
        '''                             '''
        ...
    def autoSnapTooltip (self)-> bool :
        '''                             '''
        ...
    def autoTrackTooltip (self)-> bool :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def fullScreenTrackingVector (self)-> bool :
        '''                             '''
        ...
    def polarTrackingVector (self)-> bool :
        '''                             '''
        ...
    def setAlignmentPointAcquisition (self, flag:PyAx.AcAlignmentPointAcquisition)-> None :
        '''                             '''
        ...
    def setAutoSnapAperture (self, flag:bool)-> None :
        '''                             '''
        ...
    def setAutoSnapApertureSize (self, flag:int)-> None :
        '''                             '''
        ...
    def setAutoSnapMagnet (self, flag:bool)-> None :
        '''                             '''
        ...
    def setAutoSnapMarker (self, flag:bool)-> None :
        '''                             '''
        ...
    def setAutoSnapMarkerColor (self, flag:PyAx.AcColor)-> None :
        '''                             '''
        ...
    def setAutoSnapMarkerSize (self, flag:int)-> None :
        '''                             '''
        ...
    def setAutoSnapTooltip (self, flag:bool)-> None :
        '''                             '''
        ...
    def setAutoTrackTooltip (self, flag:bool)-> None :
        '''                             '''
        ...
    def setFullScreenTrackingVector (self, flag:bool)-> None :
        '''                             '''
        ...
    def setPolarTrackingVector (self, flag:bool)-> None :
        '''                             '''
        ...

class AcadPreferencesFiles(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadPreferencesOpenSave(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadPreferencesOutput(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadPreferencesProfiles(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def activeProfile (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def copyProfile (self, oldProfileName:str, newProfileName:str)-> None :
        '''                             '''
        ...
    def deleteProfile (self, profileName:str)-> None :
        '''                             '''
        ...
    def exportProfile (self, profileName:str, regFile:str)-> None :
        '''                             '''
        ...
    def getAllProfileNames (self)-> list :
        '''                             '''
        ...
    def importProfile (self, profileName:str, regFile:str, IncludePathInfo:bool)-> None :
        '''                             '''
        ...
    def renameProfile (self, origProfileName:str, newProfileName:str)-> None :
        '''                             '''
        ...
    def resetProfile (self, profile:str)-> None :
        '''                             '''
        ...
    def setActiveProfile (self, activeProfile:str)-> None :
        '''                             '''
        ...

class AcadPreferencesSelection(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def displayGrips (self)-> bool :
        '''                             '''
        ...
    def displayGripsWithinBlocks (self)-> bool :
        '''                             '''
        ...
    def gripColorSelected (self)-> PyAx.AcColor :
        '''                             '''
        ...
    def gripColorUnselected (self)-> PyAx.AcColor :
        '''                             '''
        ...
    def gripSize (self)-> int :
        '''                             '''
        ...
    def pickAdd (self)-> bool :
        '''                             '''
        ...
    def pickAuto (self)-> bool :
        '''                             '''
        ...
    def pickBoxSize (self)-> int :
        '''                             '''
        ...
    def pickDrag (self)-> bool :
        '''                             '''
        ...
    def pickFirst (self)-> bool :
        '''                             '''
        ...
    def pickGroup (self)-> bool :
        '''                             '''
        ...
    def setDisplayGrips (self, flag:bool)-> None :
        '''                             '''
        ...
    def setDisplayGripsWithinBlocks (self, flag:bool)-> None :
        '''                             '''
        ...
    def setGripColorSelected (self, clr:PyAx.AcColor)-> None :
        '''                             '''
        ...
    def setGripColorUnselected (self, clr:PyAx.AcColor)-> None :
        '''                             '''
        ...
    def setGripSize (self, flag:int)-> None :
        '''                             '''
        ...
    def setPickAdd (self, flag:bool)-> None :
        '''                             '''
        ...
    def setPickAuto (self, flag:bool)-> None :
        '''                             '''
        ...
    def setPickBoxSize (self, flag:int)-> None :
        '''                             '''
        ...
    def setPickDrag (self, flag:bool)-> None :
        '''                             '''
        ...
    def setPickFirst (self, flag:bool)-> None :
        '''                             '''
        ...
    def setPickGroup (self, flag:bool)-> None :
        '''                             '''
        ...

class AcadPreferencesSystem(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def beepOnError (self)-> bool :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def displayOLEScale (self)-> bool :
        '''                             '''
        ...
    def enableStartupDialog (self)-> bool :
        '''                             '''
        ...
    def loadAcadLspInAllDocuments (self)-> bool :
        '''                             '''
        ...
    def setBeepOnError (self, val:bool)-> None :
        '''                             '''
        ...
    def setDisplayOLEScale (self, val:bool)-> None :
        '''                             '''
        ...
    def setEnableStartupDialog (self, val:bool)-> None :
        '''                             '''
        ...
    def setLoadAcadLspInAllDocuments (self, val:bool)-> None :
        '''                             '''
        ...
    def setShowWarningMessages (self, val:bool)-> None :
        '''                             '''
        ...
    def setSingleDocumentMode (self, val:bool)-> None :
        '''                             '''
        ...
    def setStoreSQLIndex (self, val:bool)-> None :
        '''                             '''
        ...
    def setTablesReadOnly (self, val:bool)-> None :
        '''                             '''
        ...
    def showWarningMessages (self)-> bool :
        '''                             '''
        ...
    def singleDocumentMode (self)-> bool :
        '''                             '''
        ...
    def storeSQLIndex (self)-> bool :
        '''                             '''
        ...
    def tablesReadOnly (self)-> bool :
        '''                             '''
        ...

class AcadPreferencesUser(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def acmEditMode (self)-> PyAx.AcDrawingAreaSCMEdit :
        '''                             '''
        ...
    def adcInsertUnitsDefaultSource (self)-> PyAx.AcInsertUnits :
        '''                             '''
        ...
    def adcInsertUnitsDefaultTarget (self)-> PyAx.AcInsertUnits :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def hyperlinkDisplayCursor (self)-> bool :
        '''                             '''
        ...
    def keyboardAccelerator (self)-> PyAx.AcKeyboardAccelerator :
        '''                             '''
        ...
    def keyboardPriority (self)-> PyAx.AcKeyboardPriority :
        '''                             '''
        ...
    def scmCommandMode (self)-> PyAx.AcDrawingAreaSCMCommand :
        '''                             '''
        ...
    def scmDefaultMode (self)-> PyAx.AcDrawingAreaSCMDefault :
        '''                             '''
        ...
    def scmTimeMode (self)-> bool :
        '''                             '''
        ...
    def scmTimeValue (self)-> int :
        '''                             '''
        ...
    def setADCInsertUnitsDefaultSource (self, val:PyAx.AcInsertUnits)-> None :
        '''                             '''
        ...
    def setADCInsertUnitsDefaultTarget (self, val:PyAx.AcInsertUnits)-> None :
        '''                             '''
        ...
    def setHyperlinkDisplayCursor (self, val:bool)-> None :
        '''                             '''
        ...
    def setKeyboardAccelerator (self, val:PyAx.AcKeyboardAccelerator)-> None :
        '''                             '''
        ...
    def setKeyboardPriority (self, val:PyAx.AcKeyboardPriority)-> None :
        '''                             '''
        ...
    def setSCMCommandMode (self, val:PyAx.AcDrawingAreaSCMCommand)-> None :
        '''                             '''
        ...
    def setSCMDefaultMode (self, val:PyAx.AcDrawingAreaSCMDefault)-> None :
        '''                             '''
        ...
    def setSCMEditMode (self, val:PyAx.AcDrawingAreaSCMEdit)-> None :
        '''                             '''
        ...
    def setSCMTimeMode (self, val:bool)-> None :
        '''                             '''
        ...
    def setSCMTimeValue (self, val:int)-> None :
        '''                             '''
        ...
    def setShortCutMenuDisplay (self, val:bool)-> None :
        '''                             '''
        ...
    def shortCutMenuDisplay (self)-> bool :
        '''                             '''
        ...

class AcadSectionTypeSettings(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadState(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def isQuiescent (self)-> bool :
        '''                             '''
        ...

class AcadSummaryInfo(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadToolbar(object):
    def __getitem__ (self, index: int)-> PyAx.AcadToolbarItem :
        '''                             '''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def addToolbarButton (self, index: int, name: str, helpstr: str, macro: str, flyoutButton:bool)-> PyAx.AcadToolbarItem :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def clear (self)-> None :
        '''                             '''
        ...
    def count (self)-> int :
        '''                             '''
        ...
    def dock (self, val: PyAx.AcToolbarDockStatus)-> None :
        '''                             '''
        ...
    def dockStatus (self)-> PyAx.AcToolbarDockStatus :
        '''                             '''
        ...
    def floatingRows (self)-> int :
        '''                             '''
        ...
    def height (self)-> int :
        '''                             '''
        ...
    def helpString (self)-> str :
        '''                             '''
        ...
    def isVisible (self)-> bool :
        '''                             '''
        ...
    def item (self, idx : int)-> PyAx.AcadToolbarItem :
        '''                             '''
        ...
    def largeButtons (self)-> bool :
        '''                             '''
        ...
    def left (self)-> int :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def parent (self)-> PyAx.AcadToolbars :
        '''                             '''
        ...
    def setFloat (self, top:int, left:int, numberFloatRows:int)-> None :
        '''                             '''
        ...
    def setFloatingRows (self, nRows:int)-> None :
        '''                             '''
        ...
    def setHelpString (self, helpString: str)-> None :
        '''                             '''
        ...
    def setLeft (self, left:int)-> None :
        '''                             '''
        ...
    def setName (self, name:str)-> None :
        '''                             '''
        ...
    def setTop (self, top:int)-> None :
        '''                             '''
        ...
    def setVisible (self, visible:bool)-> None :
        '''                             '''
        ...
    def tagString (self)-> str :
        '''                             '''
        ...
    def top (self)-> int :
        '''                             '''
        ...
    def width (self)-> int :
        '''                             '''
        ...

class AcadToolbarItem(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def attachToolbarToFlyout (self, menuGroupName: str, menuGroupName: str)-> None :
        '''                             '''
        ...
    def bitmaps (self)-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def clear (self)-> None :
        '''                             '''
        ...
    def commandDisplayName (self)-> str :
        '''                             '''
        ...
    def getType (self)-> PyAx.AcToolbarItemType :
        '''                             '''
        ...
    def helpString (self)-> str :
        '''                             '''
        ...
    def index (self)-> int :
        '''                             '''
        ...
    def macro (self)-> str :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def parent (self)-> PyAx.AcadToolbar :
        '''                             '''
        ...
    def setBitmaps (self, smallIconName: str, largeIconName: str)-> None :
        '''                             '''
        ...
    def setCommandDisplayName (self, commandDisplayName: str)-> None :
        '''                             '''
        ...
    def setHelpString (self, helpString: str)-> None :
        '''                             '''
        ...
    def setMacro (self, macro: str)-> None :
        '''                             '''
        ...
    def setName (self, name: str)-> None :
        '''                             '''
        ...
    def setTagString (self, tag: str)-> None :
        '''                             '''
        ...
    def tagString (self)-> str :
        '''                             '''
        ...

class AcadToolbars(object):
    def __getitem__ (self, index: int)-> PyAx.AcadToolbar :
        '''                             '''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def add (self, toolbarName:str)-> PyAx.AcadToolbar :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def count (self)-> int :
        '''                             '''
        ...
    def item (self, idx : int)-> PyAx.AcadToolbar :
        '''                             '''
        ...
    def largeButtons (self)-> bool :
        '''                             '''
        ...
    def parent (self)-> PyAx.AcadMenuGroup :
        '''                             '''
        ...
    def setLargeButtons (self, largeButtons:bool)-> None :
        '''                             '''
        ...
