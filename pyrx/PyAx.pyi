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

class AcadApplication(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def quit (self)-> None :
        '''                             '''
        ...
    def runMacro (self, macro: str)-> None :
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

class AcadDatabase(object):
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
