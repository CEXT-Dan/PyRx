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
    def getDesc (self, *args, **kwargs)-> str :
        '''getDesc( (Component)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getDesc(class PySmComponent {lvalue})'''
        ...
    def getName (self, *args, **kwargs)-> str :
        '''getName( (Component)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getName(class PySmComponent {lvalue})'''
        ...
    def setDesc (self, *args, **kwargs)-> None :
        '''setDesc( (Component)arg1, (str)arg2) -> None :

    C++ signature :
        void setDesc(class PySmComponent {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setName (self, *args, **kwargs)-> None :
        '''setName( (Component)arg1, (str)arg2) -> None :

    C++ signature :
        void setName(class PySmComponent {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...

class Database(Component):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Database :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getPersistObjects (self, *args, **kwargs)-> list :
        '''getPersistObjects( (Database)arg1) -> list :

    C++ signature :
        class boost::python::list getPersistObjects(class PySmDatabase {lvalue})'''
        ...
    def lockDb (self, *args, **kwargs)-> None :
        '''lockDb( (Database)arg1) -> None :

    C++ signature :
        void lockDb(class PySmDatabase {lvalue})'''
        ...
    def unlockDb (self, *args, **kwargs)-> None :
        '''unlockDb( (Database)arg1, (bool)arg2) -> None :

    C++ signature :
        void unlockDb(class PySmDatabase {lvalue},bool)'''
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
    def getDatabase (self, *args, **kwargs)-> PySm.Database :
        '''getDatabase( (Persist)arg1) -> Database :

    C++ signature :
        class PySmDatabase getDatabase(class PySmPersist {lvalue})'''
        ...

    @staticmethod
    def getIsDirty ()-> bool :
        '''                             '''
        ...
    def getOwner (self, *args, **kwargs)-> PySm.Persist :
        '''getOwner( (Persist)arg1) -> Persist :

    C++ signature :
        class PySmPersist getOwner(class PySmPersist {lvalue})'''
        ...

    @staticmethod
    def getTypeName ()-> str :
        '''                             '''
        ...
    def initNew (self, *args, **kwargs)-> None :
        '''initNew( (Persist)arg1, (Persist)arg2) -> None :

    C++ signature :
        void initNew(class PySmPersist {lvalue},class PySmPersist)'''
        ...
    def setOwner (self, *args, **kwargs)-> None :
        '''setOwner( (Persist)arg1, (Persist)arg2) -> None :

    C++ signature :
        void setOwner(class PySmPersist {lvalue},class PySmPersist)'''
        ...

class Sheet(Component):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
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

class SheetSet(Subset):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
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

class Subset(Component):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PySm.Persist)-> PySm.Subset :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...