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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.CalloutBlocks :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.CustomPropertyBag :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getProperties (self, *args, **kwargs)-> list :
        '''getProperties( (CustomPropertyBag)arg1) -> list :

    C++ signature :
        class boost::python::list getProperties(class PySmCustomPropertyBag {lvalue})'''
        ...
    def getPropertyValues (self, *args, **kwargs)-> list :
        '''getPropertyValues( (CustomPropertyBag)arg1) -> list :

    C++ signature :
        class boost::python::list getPropertyValues(class PySmCustomPropertyBag {lvalue})'''
        ...
    def getValue (self, *args, **kwargs)-> PySm.CustomPropertyValue :
        '''getValue( (CustomPropertyBag)arg1, (str)arg2) -> CustomPropertyValue :

    C++ signature :
        class PySmCustomPropertyValue getValue(class PySmCustomPropertyBag {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setValue (self, *args, **kwargs)-> None :
        '''setValue( (CustomPropertyBag)arg1, (str)arg2, (CustomPropertyValue)arg3) -> None :

    C++ signature :
        void setValue(class PySmCustomPropertyBag {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PySmCustomPropertyValue)'''
        ...

class CustomPropertyValue(Persist):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.CustomPropertyValue :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getFlags (self, *args, **kwargs)-> PySm.PropertyFlags :
        '''getFlags( (CustomPropertyValue)arg1) -> PropertyFlags :

    C++ signature :
        enum SmPropertyFlags getFlags(class PySmCustomPropertyValue {lvalue})'''
        ...
    def getValue (self, *args, **kwargs)-> PyDb.AcValue :
        '''getValue( (CustomPropertyValue)arg1) -> AcValue :

    C++ signature :
        class PyDbAcValue getValue(class PySmCustomPropertyValue {lvalue})'''
        ...
    def setFlags (self, *args, **kwargs)-> None :
        '''setFlags( (CustomPropertyValue)arg1, (PropertyFlags)arg2) -> None :

    C++ signature :
        void setFlags(class PySmCustomPropertyValue {lvalue},enum SmPropertyFlags)'''
        ...
    def setValue (self, *args, **kwargs)-> None :
        '''setValue( (CustomPropertyValue)arg1, (AcValue)arg2) -> None :

    C++ signature :
        void setValue(class PySmCustomPropertyValue {lvalue},class PyDbAcValue)'''
        ...

class Database(Component):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Database :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getFileName (self, *args, **kwargs)-> str :
        '''getFileName( (Database)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getFileName(class PySmDatabase {lvalue})'''
        ...
    def getLockOwnerInfo (self, *args, **kwargs)-> tuple[Any,...] :
        '''getLockOwnerInfo( (Database)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getLockOwnerInfo(class PySmDatabase {lvalue})'''
        ...
    def getLockStatus (self, *args, **kwargs)-> PySm.LockStatus :
        '''getLockStatus( (Database)arg1) -> LockStatus :

    C++ signature :
        enum SmLockStatus getLockStatus(class PySmDatabase {lvalue})'''
        ...
    def getPersistObjects (self, *args, **kwargs)-> list :
        '''getPersistObjects( (Database)arg1) -> list :

    C++ signature :
        class boost::python::list getPersistObjects(class PySmDatabase {lvalue})'''
        ...
    def getSheetSet (self, *args, **kwargs)-> PySm.SheetSet :
        '''getSheetSet( (Database)arg1) -> SheetSet :

    C++ signature :
        class PySmSheetSet getSheetSet(class PySmDatabase {lvalue})'''
        ...
    def getTemplateDstFileName (self, *args, **kwargs)-> str :
        '''getTemplateDstFileName( (Database)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getTemplateDstFileName(class PySmDatabase {lvalue})'''
        ...
    def loadFromFile (self, *args, **kwargs)-> None :
        '''loadFromFile( (Database)arg1, (str)arg2) -> None :

    C++ signature :
        void loadFromFile(class PySmDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def lockDb (self, *args, **kwargs)-> None :
        '''lockDb( (Database)arg1) -> None :

    C++ signature :
        void lockDb(class PySmDatabase {lvalue})'''
        ...
    def setFileName (self, *args, **kwargs)-> None :
        '''setFileName( (Database)arg1, (str)arg2) -> None :

    C++ signature :
        void setFileName(class PySmDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def unlockDb (self, *args, **kwargs)-> None :
        '''unlockDb( (Database)arg1, (bool)arg2) -> None :

    C++ signature :
        void unlockDb(class PySmDatabase {lvalue},bool)'''
        ...

class DbBlockRecordReference(NamedDbObjectReference):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.ObjectReference :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getReferenceFlags (self)-> object :
        '''                             '''
        ...
    def getReferencedObject (self)-> PySm.Persist :
        '''                             '''
        ...
    def setReferenceFlags (self, val: PySm.SmObjectReferenceFlags)-> None :
        '''                             '''
        ...
    def setReferencedObject (self, val: PySm.Persist)-> None :
        '''                             '''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Sheet :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getCategory (self, *args, **kwargs)-> str :
        '''getCategory( (Sheet)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getCategory(class PySmSheet {lvalue})'''
        ...
    def getDoNotPlot (self, *args, **kwargs)-> bool :
        '''getDoNotPlot( (Sheet)arg1) -> bool :

    C++ signature :
        bool getDoNotPlot(class PySmSheet {lvalue})'''
        ...
    def getIssuePurpose (self, *args, **kwargs)-> str :
        '''getIssuePurpose( (Sheet)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getIssuePurpose(class PySmSheet {lvalue})'''
        ...
    def getNumber (self, *args, **kwargs)-> str :
        '''getNumber( (Sheet)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getNumber(class PySmSheet {lvalue})'''
        ...
    def getRevisionDate (self, *args, **kwargs)-> str :
        '''getRevisionDate( (Sheet)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getRevisionDate(class PySmSheet {lvalue})'''
        ...
    def getRevisionNumber (self, *args, **kwargs)-> str :
        '''getRevisionNumber( (Sheet)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getRevisionNumber(class PySmSheet {lvalue})'''
        ...
    def getTitle (self, *args, **kwargs)-> str :
        '''getTitle( (Sheet)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getTitle(class PySmSheet {lvalue})'''
        ...
    def setCategory (self, *args, **kwargs)-> None :
        '''setCategory( (Sheet)arg1, (str)arg2) -> None :

    C++ signature :
        void setCategory(class PySmSheet {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

setCategory( (Sheet)arg1, (str)arg2) -> None :

    C++ signature :
        void setCategory(class PySmSheet {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setDoNotPlot (self, *args, **kwargs)-> None :
        '''setDoNotPlot( (Sheet)arg1, (bool)arg2) -> None :

    C++ signature :
        void setDoNotPlot(class PySmSheet {lvalue},bool)'''
        ...
    def setIssuePurpose (self, *args, **kwargs)-> None :
        '''setIssuePurpose( (Sheet)arg1, (str)arg2) -> None :

    C++ signature :
        void setIssuePurpose(class PySmSheet {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setNumber (self, *args, **kwargs)-> None :
        '''setNumber( (Sheet)arg1, (str)arg2) -> None :

    C++ signature :
        void setNumber(class PySmSheet {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setRevisionDate (self, *args, **kwargs)-> None :
        '''setRevisionDate( (Sheet)arg1, (str)arg2) -> None :

    C++ signature :
        void setRevisionDate(class PySmSheet {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setRevisionNumber (self, *args, **kwargs)-> None :
        '''setRevisionNumber( (Sheet)arg1, (str)arg2) -> None :

    C++ signature :
        void setRevisionNumber(class PySmSheet {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setTitle (self, *args, **kwargs)-> None :
        '''setTitle( (Sheet)arg1, (str)arg2) -> None :

    C++ signature :
        void setTitle(class PySmSheet {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...

class SheetSelSet(Component):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.SheetSet :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class SheetSetMgr(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def close (self, *args, **kwargs)-> None :
        '''close( (SheetSetMgr)arg1, (Database)arg2) -> None :

    C++ signature :
        void close(class PySmSheetSetMgr {lvalue},class PySmDatabase {lvalue})'''
        ...

    @staticmethod
    def closeAll ()-> None :
        '''                             '''
        ...
    def createDatabase (self, *args, **kwargs)-> PySm.Database :
        '''createDatabase( (SheetSetMgr)arg1, (str)arg2) -> Database :

    C++ signature :
        class PySmDatabase createDatabase(class PySmSheetSetMgr {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

createDatabase( (SheetSetMgr)arg1, (str)arg2, (str)arg3, (bool)arg4) -> Database :

    C++ signature :
        class PySmDatabase createDatabase(class PySmSheetSetMgr {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool)'''
        ...
    def databases (self, *args, **kwargs)-> list :
        '''databases( (SheetSetMgr)arg1) -> list :

    C++ signature :
        class boost::python::list databases(class PySmSheetSetMgr {lvalue})'''
        ...
    def findOpenDatabase (self, *args, **kwargs)-> PySm.Database :
        '''findOpenDatabase( (SheetSetMgr)arg1, (str)arg2) -> Database :

    C++ signature :
        class PySmDatabase findOpenDatabase(class PySmSheetSetMgr {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def getParentSheetSet (self, *args, **kwargs)-> tuple[Any,...] :
        '''getParentSheetSet( (SheetSetMgr)arg1, (str)arg2, (str)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getParentSheetSet(class PySmSheetSetMgr {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def getSheetFromLayout (self, *args, **kwargs)-> tuple[Any,...] :
        '''getSheetFromLayout( (SheetSetMgr)arg1, (DbObject)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSheetFromLayout(class PySmSheetSetMgr {lvalue},class PyDbObject {lvalue})'''
        ...
    def openDatabase (self, *args, **kwargs)-> PySm.Database :
        '''openDatabase( (SheetSetMgr)arg1, (str)arg2) -> Database :

    C++ signature :
        class PySmDatabase openDatabase(class PySmSheetSetMgr {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...

    @staticmethod
    def runTest ()-> bool :
        '''                             '''
        ...

class SheetView(Component):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Subset :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class ViewCategories(Component):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.ViewCategories :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class ViewCategory(Component):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.ViewCategory :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
