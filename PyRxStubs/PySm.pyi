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

class PySmDatabase(SmComponent):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def smObjects (self, *args, **kwargs)-> list :
        '''smObjects( (PySmDatabase)arg1) -> list :

    C++ signature :
        class boost::python::list smObjects(class PySmDatabase {lvalue})'''
        ...

class SmComponent(SmPersist):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getDesc (self, *args, **kwargs)-> str :
        '''getDesc( (SmComponent)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getDesc(class PySmComponent {lvalue})'''
        ...
    def getName (self, *args, **kwargs)-> str :
        '''getName( (SmComponent)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getName(class PySmComponent {lvalue})'''
        ...
    def setDesc (self, *args, **kwargs)-> None :
        '''setDesc( (SmComponent)arg1, (str)arg2) -> None :

    C++ signature :
        void setDesc(class PySmComponent {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setName (self, *args, **kwargs)-> None :
        '''setName( (SmComponent)arg1, (str)arg2) -> None :

    C++ signature :
        void setName(class PySmComponent {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...

class SmPersist(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def getTypeName ()-> str :
        '''                             '''
        ...

class SmSheetSetMgr(object):
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
        '''close( (SmSheetSetMgr)arg1, (PySmDatabase)arg2) -> None :

    C++ signature :
        void close(class PySmSheetSetMgr {lvalue},class PySmDatabase {lvalue})'''
        ...
    def closeAll (self, *args, **kwargs)-> None :
        '''closeAll( (SmSheetSetMgr)arg1) -> None :

    C++ signature :
        void closeAll(class PySmSheetSetMgr {lvalue})'''
        ...
    def createDatabase (self, *args, **kwargs)-> PySm.PySmDatabase :
        '''createDatabase( (SmSheetSetMgr)arg1, (str)arg2) -> PySmDatabase :

    C++ signature :
        class PySmDatabase createDatabase(class PySmSheetSetMgr {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)

createDatabase( (SmSheetSetMgr)arg1, (str)arg2, (str)arg3, (bool)arg4) -> PySmDatabase :

    C++ signature :
        class PySmDatabase createDatabase(class PySmSheetSetMgr {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool)'''
        ...
    def databases (self, *args, **kwargs)-> list :
        '''databases( (SmSheetSetMgr)arg1) -> list :

    C++ signature :
        class boost::python::list databases(class PySmSheetSetMgr {lvalue})'''
        ...
    def findOpenDatabase (self, *args, **kwargs)-> PySm.PySmDatabase :
        '''findOpenDatabase( (SmSheetSetMgr)arg1, (str)arg2) -> PySmDatabase :

    C++ signature :
        class PySmDatabase findOpenDatabase(class PySmSheetSetMgr {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def getParentSheetSet (self, *args, **kwargs)-> tuple[Any,...] :
        '''getParentSheetSet( (SmSheetSetMgr)arg1, (str)arg2, (str)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getParentSheetSet(class PySmSheetSetMgr {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def getSheetFromLayout (self, *args, **kwargs)-> tuple[Any,...] :
        '''getSheetFromLayout( (SmSheetSetMgr)arg1, (DbObject)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSheetFromLayout(class PySmSheetSetMgr {lvalue},class PyDbObject {lvalue})'''
        ...
    def openDatabase (self, *args, **kwargs)-> PySm.PySmDatabase :
        '''openDatabase( (SmSheetSetMgr)arg1, (str)arg2) -> PySmDatabase :

    C++ signature :
        class PySmDatabase openDatabase(class PySmSheetSetMgr {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
