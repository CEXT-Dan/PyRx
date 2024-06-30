import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
import PySm
from typing import overload
from typing import Any

class AcDbDatabase(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getAcDbDatabase (self)-> PySm.Database :
        '''                             '''
        ...

class CalloutBlocks(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def add (self, val: PySm.DbBlockRecordReference)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.CalloutBlocks :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getDbBlockRecordReferences (self)-> list :
        '''                             '''
        ...
    def remove (self, val: PySm.DbBlockRecordReference)-> None :
        '''                             '''
        ...

class Component(Persist):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Component :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getCustomPropertyBag (self)-> PySm.CustomPropertyBag :
        '''                             '''
        ...
    def getDesc (self)-> str :
        '''                             '''
        ...
    def getName (self)-> str :
        '''                             '''
        ...
    def setDesc (self, val: str)-> None :
        '''                             '''
        ...
    def setName (self, val: str)-> None :
        '''                             '''
        ...

class CustomPropertyBag(Persist):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.CustomPropertyBag :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getProperties (self)-> list :
        '''                             '''
        ...
    def getPropertyValues (self)-> list :
        '''                             '''
        ...
    def getValue (self, prop: str)-> PySm.CustomPropertyValue :
        '''                             '''
        ...
    def setValue (self, prop: str, val: PySm.CustomPropertyValue)-> None :
        '''                             '''
        ...

class CustomPropertyValue(Persist):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.CustomPropertyValue :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getFlags (self)-> PySm.PropertyFlags :
        '''                             '''
        ...
    def getValue (self)-> PyDb.AcValue :
        '''                             '''
        ...
    def setFlags (self, flags: PySm.PropertyFlags)-> None :
        '''                             '''
        ...
    def setValue (self, val: PyDb.AcValue)-> None :
        '''                             '''
        ...

class Database(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Database :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getFileName (self)-> str :
        '''                             '''
        ...
    def getLockOwnerInfo (self)-> tuple[Any,...] :
        '''                             '''
        ...
    def getLockStatus (self)-> PySm.LockStatus :
        '''                             '''
        ...
    def getPersistObjects (self)-> list :
        '''                             '''
        ...
    def getSheetSet (self)-> PySm.SheetSet :
        '''                             '''
        ...
    def getTemplateDstFileName (self)-> str :
        '''                             '''
        ...
    def loadFromFile (self, filename: str)-> None :
        '''                             '''
        ...
    def lockDb (self)-> None :
        '''                             '''
        ...
    def setFileName (self, filename: str)-> None :
        '''                             '''
        ...
    def unlockDb (self, commit: bool)-> None :
        '''                             '''
        ...

class DbBlockRecordReference(NamedDbObjectReference):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.DbBlockRecordReference :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class DbLayoutReference(NamedDbObjectReference):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.DbLayoutReference :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class DbObjectReference(FileReference):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.DbObjectReference :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getAcDbHandle (self)-> PyDb.Handle :
        '''                             '''
        ...
    def getAcSmAcDbDatabase (self)-> PySm.AcDbDatabase :
        '''                             '''
        ...
    def resolveAcDbObject (self, db: PyDb.Database)-> PyDb.Handle :
        '''                             '''
        ...
    def setAcDbHandle (self, val: PyDb,Handle)-> None :
        '''                             '''
        ...
    def setAcDbObject (self, val: PyDb.Object)-> None :
        '''                             '''
        ...

class DbViewReference(NamedDbObjectReference):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.DbViewReference :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class FileReference(Persist):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.FileReference :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getFileName (self)-> str :
        '''                             '''
        ...
    def setFileName (self, val: str)-> None :
        '''                             '''
        ...

class LockStatus(object):
    def kLockedAccessDenied (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kLockedLocal (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kLockedNotConnected (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kLockedReadOnly (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kLockedRemote (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kUnLocked (self, *args, **kwargs)-> None :
        '''None'''
        ...

class NamedDbObjectReference(DbObjectReference):
    def GetOwnerAcDbHandle (self)-> PyDb.Handle :
        '''                             '''
        ...
    def SetOwnerAcDbHandle (self, val: PyDb,Handle)-> None :
        '''                             '''
        ...
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.NamedDbObjectReference :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class ObjectReference(Persist):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.ObjectReference :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getReferenceFlags (self)-> PySm.ObjectReferenceFlags :
        '''                             '''
        ...
    def getReferencedObject (self)-> PySm.Persist :
        '''                             '''
        ...
    def setReferenceFlags (self, val: PySm.ObjectReferenceFlags)-> None :
        '''                             '''
        ...
    def setReferencedObject (self, val: PySm.Persist)-> None :
        '''                             '''
        ...

class ObjectReferenceFlags(object):
    def kHardPointer (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSoftPointer (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Persist(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Persist :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def clear (self)-> None :
        '''                             '''
        ...
    def getDatabase (self)-> PySm.Database :
        '''                             '''
        ...
    def getIsDirty (self)-> bool :
        '''                             '''
        ...
    def getObjectId (self)-> object :
        '''                             '''
        ...
    def getOwner (self)-> PySm.Persist :
        '''                             '''
        ...
    def getTypeName (self)-> str :
        '''                             '''
        ...
    def initNew (self, owner: PySm.Persist)-> None :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def setOwner (self, owner: PySm.Persist)-> None :
        '''                             '''
        ...

class PersistProxy(Persist):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.PersistProxy :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class ProjectPointLocation(Persist):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.ProjectPointLocation :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getFolder (self)-> str :
        '''                             '''
        ...
    def getPassword (self)-> str :
        '''                             '''
        ...
    def getResourceType (self)-> int :
        '''                             '''
        ...
    def getURL (self)-> str :
        '''                             '''
        ...
    def getUsername (self)-> str :
        '''                             '''
        ...
    def setFolder (self, val: str)-> None :
        '''                             '''
        ...
    def setPassword (self, val: str)-> None :
        '''                             '''
        ...
    def setResourceType (self, val: int)-> None :
        '''                             '''
        ...
    def setUsername (self, val: str)-> None :
        '''                             '''
        ...

class ProjectPointLocations(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def addNewLocation (self, name: str, url: str, folder: str, username: str, password: str)-> PySm.ProjectPointLocation :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.ProjectPointLocations :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getLocation (self, locationName: str)-> PySm.ProjectPointLocation :
        '''                             '''
        ...
    def removeLocation (self, val: PySm.ProjectPointLocation)-> None :
        '''                             '''
        ...

class PropertyFlags(object):
    def kEmpty (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kIsChild (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSheetProp (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSheetSetProp (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSubSetProp (self, *args, **kwargs)-> None :
        '''None'''
        ...

class PublishOptions(Persist):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.PublishOptions :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getDefaultFilename (self)-> str :
        '''                             '''
        ...
    def getDefaultOutputdir (self)-> PySm.FileReference :
        '''                             '''
        ...
    def getDwfType (self)-> bool :
        '''                             '''
        ...
    def getEplotFormat (self)-> int :
        '''                             '''
        ...
    def getIncludeSheetData (self)-> bool :
        '''                             '''
        ...
    def getIncludeSheetSetData (self)-> bool :
        '''                             '''
        ...
    def getLayerInfo (self)-> bool :
        '''                             '''
        ...
    def getLinesMerge (self)-> bool :
        '''                             '''
        ...
    def getPromptForName (self)-> bool :
        '''                             '''
        ...
    def getPromptForPassword (self)-> bool :
        '''                             '''
        ...
    def getUnrecognizedData (self)-> PySm.CustomPropertyBag :
        '''                             '''
        ...
    def getUnrecognizedSections (self)-> PySm.CustomPropertyBag :
        '''                             '''
        ...
    def getUsePassword (self)-> bool :
        '''                             '''
        ...
    def setDefaultFilename (self, val: str)-> None :
        '''                             '''
        ...
    def setDefaultOutputdir (self, *args, **kwargs)-> None :
        '''setDefaultOutputdir( (PublishOptions)arg1, (FileReference)arg2) -> None :

    C++ signature :
        void setDefaultOutputdir(class PySmPublishOptions {lvalue},class PySmFileReference {lvalue})'''
        ...
    def setDwfType (self, val: bool)-> None :
        '''                             '''
        ...
    def setEplotFormat (self, val: int)-> None :
        '''                             '''
        ...
    def setIncludeSheetData (self, val: bool)-> None :
        '''                             '''
        ...
    def setIncludeSheetSetData (self, val: bool)-> None :
        '''                             '''
        ...
    def setLayerInfo (self, val: bool)-> None :
        '''                             '''
        ...
    def setLinesMerge (self, val: bool)-> None :
        '''                             '''
        ...
    def setPromptForName (self, val: bool)-> None :
        '''                             '''
        ...
    def setPromptForPassword (self, val: bool)-> None :
        '''                             '''
        ...
    def setUnrecognizedData (self, val: PySm.CustomPropertyBag)-> None :
        '''                             '''
        ...
    def setUnrecognizedSections (self, val: PySm.CustomPropertyBag)-> None :
        '''                             '''
        ...
    def setUsePassword (self, val: bool)-> None :
        '''                             '''
        ...

class Resources(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def add (self, val: PySm.FileReference)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Resources :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getFileReferences (self)-> list :
        '''                             '''
        ...
    def remove (self, val: PySm.FileReference)-> None :
        '''                             '''
        ...

class Sheet(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Sheet :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getCategory (self)-> str :
        '''                             '''
        ...
    def getDoNotPlot (self)-> bool :
        '''                             '''
        ...
    def getIssuePurpose (self)-> str :
        '''                             '''
        ...
    def getLayout (self)-> PySm.DbLayoutReference :
        '''                             '''
        ...
    def getNumber (self)-> str :
        '''                             '''
        ...
    def getRevisionDate (self)-> str :
        '''                             '''
        ...
    def getRevisionNumber (self)-> str :
        '''                             '''
        ...
    def getSheetViews (self)-> PySm.SheetViews :
        '''                             '''
        ...
    def getTitle (self)-> str :
        '''                             '''
        ...
    def setCategory (self, val: str)-> None :
        '''                             '''
        ...
    def setDoNotPlot (self, val: bool)-> None :
        '''                             '''
        ...
    def setIssuePurpose (self, val: str)-> None :
        '''                             '''
        ...
    def setLayout (self, val: PySm.DbLayoutReference)-> None :
        '''                             '''
        ...
    def setNumber (self, val: str)-> None :
        '''                             '''
        ...
    def setRevisionDate (self, val: str)-> None :
        '''                             '''
        ...
    def setRevisionNumber (self, val: str)-> None :
        '''                             '''
        ...
    def setTitle (self, val: str)-> None :
        '''                             '''
        ...

class SheetSelSet(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def add (self, val: PySm.Component)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.SheetSelSet :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getComponents (self)-> list :
        '''                             '''
        ...
    def remove (self)-> None :
        '''                             '''
        ...

class SheetSelSets(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def add (self, name: str, desc: str)-> PySm.SheetSelSet :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.SheetSelSets :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getSheetSelSets (self)-> list :
        '''                             '''
        ...
    def remove (self, val: PySm.SheetSelSet)-> None :
        '''                             '''
        ...

class SheetSet(Subset):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.SheetSet :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getAltPageSetups (self)-> PySm.FileReference :
        '''                             '''
        ...
    def getCalloutBlocks (self)-> PySm.CalloutBlocks :
        '''                             '''
        ...
    def getDefAltPageSetup (self)-> PySm.NamedDbObjectReference :
        '''                             '''
        ...
    def getDefLabelBlk (self)-> PySm.DbBlockRecordReference :
        '''                             '''
        ...
    def getPromptForDwgName (self)-> bool :
        '''                             '''
        ...
    def getPublishOptions (self)-> PySm.PublishOptions :
        '''                             '''
        ...
    def getResources (self)-> PySm.Resources :
        '''                             '''
        ...
    def getSheetSelSets (self)-> PySm.SheetSelSets :
        '''                             '''
        ...
    def getViewCategories (self)-> PySm.ViewCategories :
        '''                             '''
        ...
    def setAltPageSetups (self, val: PySm.FileReference)-> None :
        '''                             '''
        ...
    def setDefAltPageSetup (self, val: PySm.NamedDbObjectReference)-> None :
        '''                             '''
        ...
    def setDefLabelBlk (self, val: PySm.DbBlockRecordReference)-> None :
        '''                             '''
        ...
    def setPromptForDwgName (self, val: bool)-> None :
        '''                             '''
        ...
    def sync (self, db: PyDb.Database)-> None :
        '''                             '''
        ...
    def updateSheetCustomProps (self)-> None :
        '''                             '''
        ...

class SheetSetMgr(object):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def close (self, smDb: PySm.Database)-> None :
        '''                             '''
        ...

    @staticmethod
    def closeAll ()-> None :
        '''                             '''
        ...

    @overload
    def createDatabase (self, filename: str)-> PySm.Database : ...
    @overload
    def createDatabase (self, filename: str, template: str, bAlwaysCreate: bool)-> PySm.Database : ...
    def createDatabase (self, *args, **kwargs)-> PySm.Database :
        '''Overloads:
    - filename: str
    - filename: str, template: str, bAlwaysCreate: bool
    '''
        ...
    def databases (self)-> list :
        '''                             '''
        ...
    def findOpenDatabase (self, filename: str)-> PySm.Database :
        '''                             '''
        ...
    def getParentSheetSet (self, dwg: str, dwg: layout)-> tuple[Any,...] :
        '''                             '''
        ...
    def getSheetFromLayout (self, layout: PyDb.Object)-> tuple[Any,...] :
        '''                             '''
        ...
    def openDatabase (self, filename: str)-> PySm.Database :
        '''                             '''
        ...

    @staticmethod
    def runTest ()-> bool :
        '''                             '''
        ...

class SheetView(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.SheetView :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getCategory (self)-> PySm.ViewCategory :
        '''                             '''
        ...
    def getNamedView (self)-> PySm.DbViewReference :
        '''                             '''
        ...
    def getNumber (self)-> str :
        '''                             '''
        ...
    def getTitle (self)-> str :
        '''                             '''
        ...
    def setCategory (self, val: PySm.ViewCategory)-> None :
        '''                             '''
        ...
    def setNamedView (self, val: PySm.AcDbViewReference)-> None :
        '''                             '''
        ...
    def setNumber (self, val: str)-> None :
        '''                             '''
        ...
    def setTitle (self, val: str)-> None :
        '''                             '''
        ...

class SheetViews(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.SheetViews :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getSheetViews (self)-> list :
        '''                             '''
        ...
    def sync (self, val: PySm.AcDbLayoutReference, db: PyDb.Database)-> None :
        '''                             '''
        ...

class Subset(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def addNewSheet (self, name: str, desc: str)-> PySm.Sheet :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Subset :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def createSubset (self, name: str, desc: str)-> PySm.Subset :
        '''                             '''
        ...
    def getDefDwtLayout (self)-> PySm.DbLayoutReference :
        '''                             '''
        ...
    def getNewSheetLocation (self)-> PySm.FileReference :
        '''                             '''
        ...
    def getOverrideSheetPublish (self)-> bool :
        '''                             '''
        ...
    def getPromptForDwt (self)-> bool :
        '''                             '''
        ...
    def getSheets (self)-> list :
        '''                             '''
        ...
    def importSheet (self, val: PySm.DbLayoutReference)-> PySm.Sheet :
        '''                             '''
        ...
    def insertComponent (self, newSheet: PySm.Component, beforeSheet: PySm.Component)-> None :
        '''                             '''
        ...
    def insertComponentAfter (self, newSheet: PySm.Component, afterSheet: PySm.Component)-> None :
        '''                             '''
        ...
    def removeSheet (self, val: PySm.Sheet)-> None :
        '''                             '''
        ...
    def removeSubset (self, val: PySm.Subset)-> None :
        '''                             '''
        ...
    def setDefDwtLayout (self, val: PySm.DbLayoutReference)-> None :
        '''                             '''
        ...
    def setNewSheetLocation (self, val: PySm.FileReference)-> None :
        '''                             '''
        ...
    def setOverrideSheetPublish (self, val: bool)-> None :
        '''                             '''
        ...
    def setPromptForDwt (self, val: bool)-> None :
        '''                             '''
        ...
    def updateInMemoryDwgHints (self)-> None :
        '''                             '''
        ...

class ViewCategories(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.ViewCategories :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def createViewCategory (self, name: str, desc: str, id: str)-> PySm.ViewCategory :
        '''                             '''
        ...
    def getDefaultViewCategory (self)-> PySm.ViewCategory :
        '''                             '''
        ...
    def getViewCategories (self)-> list :
        '''                             '''
        ...
    def removeViewCategory (self, val: PySm.ViewCategory)-> None :
        '''                             '''
        ...

class ViewCategory(Component):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.ViewCategory :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getCalloutBlocks (self)-> PySm.CalloutBlocks :
        '''                             '''
        ...
    def getSheetViews (self)-> list :
        '''                             '''
        ...
