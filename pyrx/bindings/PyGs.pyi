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
from typing import overload
from typing import Any

class Core(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def getBlockImage (blkid: PyDb.ObjectId,sx: int,sy: int,zoomFactor: float,bkrgb: list[int]=None)-> object :
        '''                             '''
        ...

    @staticmethod
    def getCurrent3DAcGsView (vpNum : int)-> PyGs.GsView :
        '''                             '''
        ...

    @staticmethod
    def getCurrentAcGsView (vpNum : int)-> PyGs.GsView :
        '''                             '''
        ...

    @staticmethod
    def getViewParameters (vpNum : int,view : PyGs.View)-> bool :
        '''                             '''
        ...

    @staticmethod
    def setViewParameters (vpNum : int,view : PyGs.View,bRegen: bool,bRescale: bool,bSync: bool=False)-> bool :
        '''                             '''
        ...

class GraphicsKernel(object):
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

class GsManager(object):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class GsView(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def backClip (self)-> float :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def fieldHeight (self)-> float :
        '''                             '''
        ...
    def fieldWidth (self)-> float :
        '''                             '''
        ...
    def frontClip (self)-> float :
        '''                             '''
        ...
    def getViewport (self)-> tuple[PyGe.Point2d,PyGe.Point2d] :
        '''                             '''
        ...
    def graphicsKernel (self)-> PyGs.GraphicsKernel :
        '''                             '''
        ...
    def isBackClipped (self)-> bool :
        '''                             '''
        ...
    def isFrontClipped (self)-> bool :
        '''                             '''
        ...
    def isNullObj (self)-> bool :
        '''                             '''
        ...
    def isPerspective (self)-> bool :
        '''                             '''
        ...
    def isViewportBorderVisible (self)-> bool :
        '''                             '''
        ...
    def objectToDeviceMatrix (self)-> PyGe.Matrix3d :
        '''                             '''
        ...
    def position (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def projectionMatrix (self)-> PyGe.Matrix3d :
        '''                             '''
        ...
    def screenMatrix (self)-> PyGe.Matrix3d :
        '''                             '''
        ...
    def setBackClip (self, val: float)-> None :
        '''                             '''
        ...
    def setEnableBackClip (self, val: bool)-> None :
        '''                             '''
        ...
    def setEnableFrontClip (self, val: bool)-> None :
        '''                             '''
        ...
    def setFrontClip (self, val: float)-> None :
        '''                             '''
        ...
    def setView (self, pos: PyGe.Point3d, target: PyGe.Point3d, upVector: PyGe.Vector3d, fWidth: float, fHeight: float, projection: PyGs.ViewProjection = PyGs.ViewProjection.kParallel)-> None :
        '''                             '''
        ...
    def setViewport (self, lowerLeft: PyGe.Point2d, upperRight: PyGe.Point2d)-> None :
        '''                             '''
        ...
    def setViewportBorderVisibility (self, val: bool)-> None :
        '''                             '''
        ...
    def target (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def upVector (self)-> PyGe.Vector3d :
        '''                             '''
        ...
    def viewingMatrix (self)-> PyGe.Matrix3d :
        '''                             '''
        ...
    def worldToDeviceMatrix (self)-> PyGe.Matrix3d :
        '''                             '''
        ...

class KernelDescriptor(object):
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

class ViewProjection(object):
    def kAerial (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNoMap (self, *args, **kwargs)-> None :
        '''None'''
        ...
