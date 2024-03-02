import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl

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
