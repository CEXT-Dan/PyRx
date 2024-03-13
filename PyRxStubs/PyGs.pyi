import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
from typing import overload

class Core:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def getCurrent3DAcGsView (self: Core,vpNum : int)-> PyGs.GsView :
      '''                             '''
    ...
    def getCurrentAcGsView (self: Core,vpNum : int)-> PyGs.GsView :
      '''                             '''
    ...

class GraphicsKernel:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def addRef (self, *args, **kwargs)-> None :
      '''addRef( (GraphicsKernel)arg1) -> None :

    C++ signature :
        void addRef(class PyGsGraphicsKernel {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def delRef (self, *args, **kwargs)-> bool :
      '''delRef( (GraphicsKernel)arg1) -> bool :

    C++ signature :
        bool delRef(class PyGsGraphicsKernel {lvalue})'''
    ...

class GsManager:
    def __init__ (self: GsManager)-> None :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...

class GsView:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def isNullObj (self: PyGsView)-> bool :
      '''                             '''
    ...
    def position (self: PyGsView)-> PyGe.Point3d :
      '''                             '''
    ...

class KernelDescriptor:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def addSupport (self, *args, **kwargs)-> None :
      '''addSupport( (KernelDescriptor)arg1, (str)arg2) -> None :

    C++ signature :
        void addSupport(class PyGsKernelDescriptor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
