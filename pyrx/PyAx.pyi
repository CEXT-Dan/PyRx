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

class AcadMenuGroups(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
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

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadPopupMenus(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
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

    @staticmethod
    def className ()-> str :
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

    @staticmethod
    def className ()-> str :
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

class AcadPreferencesSystem(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class AcadPreferencesUser(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
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

class AcadToolbars(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
