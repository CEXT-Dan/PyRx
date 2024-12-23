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
import PyBrxCv
import PyBrxBim
import PyBrx
from typing import overload
from typing import Any

class Core(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def getOpenObjects ()-> list :
        '''                             '''
        ...

    @staticmethod
    def isLicenseAvailable (val: PyBrx.LicensedFeature)-> bool :
        '''                             '''
        ...

class DbProperties(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def dumpAll (id: PyDb.ObjectId)-> None :
        '''                             '''
        ...

    @staticmethod
    def getValue (id: PyDb.ObjectId,name: str)-> PyDb.AcValue :
        '''                             '''
        ...

    @staticmethod
    def isReadOnly (id: PyDb.ObjectId,name: str)-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def isValid (id: PyDb.ObjectId,name: str)-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def listAll (id: PyDb.ObjectId)-> list :
        '''                             '''
        ...

    @staticmethod
    def setValue (id: PyDb.ObjectId,name: str,val: PyDb.AcValue)-> None :
        '''                             '''
        ...

class LicensedFeature(object):
    def eBim (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCommunicator (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCore (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMechanical (self, *args, **kwargs)-> None :
        '''None'''
        ...
