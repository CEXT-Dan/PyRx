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

class BimAssets(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BimBuilding(BimSpatialLocation):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def allObjectBuildings (db: PyDb.Database)-> list :
        '''                             '''
        ...
    def allObjectStories (self)-> list :
        '''                             '''
        ...
    def allObjectStoriesFromDb (self, db: PyDb.Database)-> list :
        '''                             '''
        ...

    @staticmethod
    def allStringBuildings (db: PyDb.Database)-> list :
        '''                             '''
        ...
    def allStringStories (self)-> list :
        '''                             '''
        ...
    def allStringStoriesFromDb (self, db: PyDb.Database)-> list :
        '''                             '''
        ...
    def assignToEntity (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...

    @staticmethod
    def assignedBuilding (building: PyBrxBim.BimBuilding,id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def assignedObjects (self, db: PyDb.Database)-> list :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimBuilding :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def createBuilding (self, name: str, db: PyDb.Database)-> None :
        '''                             '''
        ...

    @staticmethod
    def createNewBuilding (db: PyDb.Database,name: str)-> PyBrxBim.BimBuilding :
        '''                             '''
        ...
    def createStory (self, name: str)-> None :
        '''                             '''
        ...

    @staticmethod
    def deleteBuildingFromDb (db: PyDb.Database,name: str)-> None :
        '''                             '''
        ...
    def deleteStoryObject (self, story: PyBrxBim.BimStory)-> None :
        '''                             '''
        ...
    def deleteStoryString (self, story: str)-> None :
        '''                             '''
        ...
    def description (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def getBuilding (db: PyDb.Database,name: str)-> PyBrxBim.BimBuilding :
        '''                             '''
        ...
    def getStory (self, story: str)-> PyBrxBim.BimStory :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def longName (self)-> str :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def setDescription (self, desc: str)-> None :
        '''                             '''
        ...
    def setLongName (self, name: str)-> None :
        '''                             '''
        ...
    def setName (self, name: str)-> None :
        '''                             '''
        ...
    def setNull (self)-> None :
        '''                             '''
        ...
    def typeDesc (self)-> PyBrxBim.BimObjectType :
        '''                             '''
        ...
    def typeName (self)-> str :
        '''                             '''
        ...

class BimCategory(object):
    def kBricsys (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kClassfication (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kIFC2x3 (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kIFC4 (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kIFCCustom (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kIFCQuantity (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kQuantity (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kStandard (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kUser (self, *args, **kwargs)-> None :
        '''None'''
        ...

class BimClassification(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @overload
    @staticmethod
    def classifyAs (id: PyDb.ObjectId, objectType: PyBrxBim.BimElementType)-> None : ...
    @overload
    @staticmethod
    def classifyAs (database: PyDb.database, objectType: PyBrxBim.BimElementType)-> None : ...
    @overload
    @staticmethod
    def classifyAs (id: PyDb.ObjectId, typeName: str)-> None : ...
    @overload
    @staticmethod
    def classifyAs (id: PyDb.ObjectId, typeName: str, localName: bool)-> None : ...
    @staticmethod
    def classifyAs (self, *args, **kwargs)-> None :
        '''Overloads:
    - id: PyDb.ObjectId, objectType: PyBrxBim.BimElementType
    - database: PyDb.database, objectType: PyBrxBim.BimElementType
    - id: PyDb.ObjectId, typeName: str
    - id: PyDb.ObjectId, typeName: str, localName: bool
    '''
        ...

    @overload
    @staticmethod
    def deleteProperty (id: PyDb.ObjectId, propertyName: str)-> bool : ...
    @overload
    @staticmethod
    def deleteProperty (id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory)-> bool : ...
    @overload
    @staticmethod
    def deleteProperty (id: PyDb.ObjectId, propertyName: str, category: str)-> bool : ...
    @staticmethod
    def deleteProperty (self, *args, **kwargs)-> bool :
        '''Overloads:
    - id: PyDb.ObjectId, propertyName: str
    - id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory
    - id: PyDb.ObjectId, propertyName: str, category: str
    '''
        ...

    @staticmethod
    def getAllClassified (db: PyDb.Database)-> list :
        '''                             '''
        ...

    @staticmethod
    def getAllClassifiedAs (name: str,db: PyDb.Database)-> list :
        '''                             '''
        ...

    @staticmethod
    def getAllClassifiedAsName (name: str,db: PyDb.Database,local: bool = False)-> list :
        '''                             '''
        ...

    @staticmethod
    def getAllUnclassified (db: PyDb.Database)-> list :
        '''                             '''
        ...

    @staticmethod
    def getAllUsedClassificationNames (db: PyDb.Database,local: bool = False)-> list :
        '''                             '''
        ...

    @staticmethod
    def getAllUsedClassifications (db: PyDb.Database)-> list :
        '''                             '''
        ...

    @staticmethod
    def getBimTypeNames (local: bool = False)-> list :
        '''                             '''
        ...
    def getClassification (self, *args, **kwargs)-> method

Convert a function to be a static method.

A static method does not receive an implicit first argument.
To declare a static method, use this idiom :
        '''staticmethod(function) -> method

Convert a function to be a static method.

A static method does not receive an implicit first argument.
To declare a static method, use this idiom:

     class C:
         @staticmethod
         def f(arg1, arg2, argN):
             ...

It can be called either on the class (e.g. C.f()) or on an instance
(e.g. C().f()). Both the class and the instance are ignored, and
neither is passed implicitly as the first argument to the method.

Static methods in Python are similar to those found in Java or C++.
For a more advanced concept, see the classmethod builtin.'''
        ...

    @staticmethod
    def getClassificationName (id: PyDb.ObjectId,localName : bool = False)-> str :
        '''                             '''
        ...

    @staticmethod
    def getDescription (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...

    @staticmethod
    def getGUID (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...

    @staticmethod
    def getName (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...

    @overload
    @staticmethod
    def getProperty (id: PyDb.ObjectId, propertyName: str)-> PyDb.AcValue : ...
    @overload
    @staticmethod
    def getProperty (id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory)-> PyDb.AcValue : ...
    @overload
    @staticmethod
    def getProperty (id: PyDb.ObjectId, propertyName: str, category: str)-> PyDb.AcValue : ...
    @staticmethod
    def getProperty (self, *args, **kwargs)-> PyDb.AcValue :
        '''Overloads:
    - id: PyDb.ObjectId, propertyName: str
    - id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory
    - id: PyDb.ObjectId, propertyName: str, category: str
    '''
        ...

    @staticmethod
    def getPropertyDict (id: PyDb.ObjectId)-> dict :
        '''                             '''
        ...

    @staticmethod
    def getPropertyNames (id: PyDb.ObjectId)-> list :
        '''                             '''
        ...

    @overload
    @staticmethod
    def hasProperty (id: PyDb.ObjectId, propertyName: str)-> bool : ...
    @overload
    @staticmethod
    def hasProperty (id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory)-> bool : ...
    @overload
    @staticmethod
    def hasProperty (id: PyDb.ObjectId, propertyName: str, category: str)-> bool : ...
    @staticmethod
    def hasProperty (self, *args, **kwargs)-> bool :
        '''Overloads:
    - id: PyDb.ObjectId, propertyName: str
    - id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory
    - id: PyDb.ObjectId, propertyName: str, category: str
    '''
        ...

    @staticmethod
    def isClassified (val: PyDb.Database)-> bool :
        '''                             '''
        ...

    @overload
    @staticmethod
    def isClassifiedAs (id: PyDb.ObjectId, objectType: PyBrxBim.BimElementType)-> bool : ...
    @overload
    @staticmethod
    def isClassifiedAs (database: PyDb.database, objectType: PyBrxBim.BimElementType)-> bool : ...
    @overload
    @staticmethod
    def isClassifiedAs (id: PyDb.ObjectId, typeName: str)-> bool : ...
    @overload
    @staticmethod
    def isClassifiedAs (id: PyDb.ObjectId, typeName: str, localName: bool)-> bool : ...
    @staticmethod
    def isClassifiedAs (self, *args, **kwargs)-> bool :
        '''Overloads:
    - id: PyDb.ObjectId, objectType: PyBrxBim.BimElementType
    - database: PyDb.database, objectType: PyBrxBim.BimElementType
    - id: PyDb.ObjectId, typeName: str
    - id: PyDb.ObjectId, typeName: str, localName: bool
    '''
        ...

    @staticmethod
    def isClassifiedAsAnyBuildingElement (id: PyDb.ObjectId)-> bool :
        '''                             '''
        ...

    @staticmethod
    def isUnclassified (id: PyDb.ObjectId)-> bool :
        '''                             '''
        ...

    @staticmethod
    def setDescription (id: PyDb.ObjectId,description: str)-> None :
        '''                             '''
        ...

    @staticmethod
    def setName (id: PyDb.ObjectId,description: str)-> None :
        '''                             '''
        ...

    @overload
    @staticmethod
    def setProperty (id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue)-> None : ...
    @overload
    @staticmethod
    def setProperty (id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue,category : PyBrxBim.EBimCategory)-> None : ...
    @overload
    @staticmethod
    def setProperty (id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue, category: str)-> None : ...
    @staticmethod
    def setProperty (self, *args, **kwargs)-> None :
        '''Overloads:
    - id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue
    - id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue,category : PyBrxBim.EBimCategory
    - id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue, category: str
    '''
        ...

    @staticmethod
    def unClassify (val: PyDb.ObjectId|PyDb.Database)-> None :
        '''                             '''
        ...

class BimComposition(BimObject):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, name: str)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - name: str
    '''
        ...

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimComposition :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BimElementType(object):
    def eBimAnnotation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimBeam (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimBuildingType (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimColumn (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimCovering (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimCurtainWall (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimDetail (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimDiscreteAccessory (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimDistributionChamberElement (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimDistributionControlElement (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimDistributionFlowElement (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimDistributionPort (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimDoor (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimEnergyConversionDevice (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFastener (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFlowConnectionPoint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFlowController (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFlowFitting (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFlowMovingDevice (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFlowSegment (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFlowStorageDevice (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFlowTerminal (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFlowTreatmentDevice (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFooting (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimFurnishingElement (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimGenericBuildingElt (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimGrid (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimGridAxis (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimMechanicalFastener (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimMember (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimOpening (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimPile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimPlate (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimProduct (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimRailing (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimRamp (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimRampFlight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimReinforcingBar (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimReinforcingMesh (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimRoof (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimRoom (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimSchedule (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimSection (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimSite (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimSlab (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimSpaceType (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimSpatialElementType (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimStair (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimStairFlight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimStoryType (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimTendon (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimTendonAnchor (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimViewportType (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimWall (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimWindow (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimXReference (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNoBuildingElement (self, *args, **kwargs)-> None :
        '''None'''
        ...

class BimHatchPattern(object):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, scaleOrSpacing: float,angle: float=0.0,cross: bool=False)-> None : ...
    @overload
    def __init__ (self, hType: PyBrxBim.BimHatchType, name:str, scaleOrSpacing: float= 1.0, angle: float=0.0)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - scaleOrSpacing: float,angle: float=0.0,cross: bool=False
    - hType: PyBrxBim.BimHatchType, name:str, scaleOrSpacing: float= 1.0, angle: float=0.0
    '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BimHatchType(object):
    def eHatchCustom (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eHatchNone (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eHatchPredefined (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eHatchUserDefined (self, *args, **kwargs)-> None :
        '''None'''
        ...

class BimInformationalAssets(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BimLinearGeometry(object):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, id: PyDb.ObjectId)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - id: PyDb.ObjectId
    '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BimMaterial(BimObject):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, name: str)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - name: str
    '''
        ...

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimMaterial :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BimNameSpaces(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @overload
    @staticmethod
    def createNameSpace (szName: str)-> None : ...
    @overload
    @staticmethod
    def createNameSpace (szName: str, szLabel: str, visible: bool, db: PyDb.Database)-> None : ...
    @staticmethod
    def createNameSpace (self, *args, **kwargs)-> None :
        '''Overloads:
    - szName: str
    - szName: str, szLabel: str, visible: bool, db: PyDb.Database
    '''
        ...

    @staticmethod
    def deleteNameSpace (szNameOrLabel: str,db: PyDb.Database=None)-> None :
        '''                             '''
        ...

    @staticmethod
    def getIsNameSpaceVisible (szNameOrLabel: str,db: PyDb.Database=None)-> bool :
        '''                             '''
        ...

    @staticmethod
    def getNameSpaceLabel (szName: str,db: PyDb.Database=None)-> str :
        '''                             '''
        ...

    @staticmethod
    def hasNameSpace (szNameOrLabel: str,db: PyDb.Database=None)-> bool :
        '''                             '''
        ...

    @staticmethod
    def listNameSpaces (db: PyDb.Database=None)-> dict :
        '''                             '''
        ...

    @staticmethod
    def setIsNameSpaceVisible (visible: bool,szNameOrLabel: str,db: PyDb.Database=None)-> None :
        '''                             '''
        ...

    @staticmethod
    def setNameSpaceLabel (szName: str,szLable: str,db: PyDb.Database=None)-> None :
        '''                             '''
        ...

class BimObject(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimObject :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def description (self)-> str :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def setDescription (self, val: str)-> None :
        '''                             '''
        ...
    def setName (self, val: str)-> None :
        '''                             '''
        ...
    def setNull (self)-> None :
        '''                             '''
        ...
    def typeDesc (self)-> PyBrxBim.BimObjectType :
        '''                             '''
        ...
    def typeName (self)-> str :
        '''                             '''
        ...

class BimObjectType(object):
    def eBimBuilding (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimComposition (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimMaterial (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimPly (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimRoomObject (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimSpatialLocation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimStory (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimUnknownObject (self, *args, **kwargs)-> None :
        '''None'''
        ...

class BimPly(BimObject):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, material: PyBrxBim.BimMaterial, function: PyBrxBim.MaterialFunction=PyBrxBim.MaterialFunction.eNone, thickness:float=1.0)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - material: PyBrxBim.BimMaterial, function: PyBrxBim.MaterialFunction=PyBrxBim.MaterialFunction.eNone, thickness:float=1.0 
    '''
        ...

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimPly :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BimPolicies(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def getPolicy (option: PyBrxBim.BimPolicyOptions)-> bool :
        '''                             '''
        ...

    @staticmethod
    def setPolicy (option: PyBrxBim.BimPolicyOptions,enable: bool)-> None :
        '''                             '''
        ...

class BimPolicyOptions(object):
    def eInstantSave (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNothing (self, *args, **kwargs)-> None :
        '''None'''
        ...

class BimProfile(object):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, id: PyDb.ObjectId)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - id: PyDb.ObjectId
    '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BimRoom(BimObject):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, id: PyDb.ObjectId)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - id: PyDb.ObjectId
    '''
        ...
    def assignToBuilding (self, val: PyBrxBim.BimBuilding)-> None :
        '''                             '''
        ...

    @staticmethod
    def assignToBuildingS (id: PyDb.ObjectId,val: PyBrxBim.BimBuilding)-> None :
        '''                             '''
        ...
    def assignToStory (self, val: PyBrxBim.BimStory)-> None :
        '''                             '''
        ...

    @staticmethod
    def assignToStoryS (id: PyDb.ObjectId,val: PyBrxBim.BimStory)-> None :
        '''                             '''
        ...

    @staticmethod
    def buildAssociativeRoomS (insidePoint: PyGe.Point3d,basePlane: PyGe.Plane)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def buildNonAssociativeRoomS (id: PyDb.ObjectId)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimRoom :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def createAssociativeRoom (self, insidePoint: PyGe.Point3d, basePlane: PyGe.Plane)-> PyDb.ObjectId :
        '''                             '''
        ...
    def createNonAssociativeRoom (self, id: PyDb.ObjectId)-> PyDb.ObjectId :
        '''                             '''
        ...
    def description (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def descriptionS (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...

    @overload
    @staticmethod
    def getAllRoomsS (/)-> list : ...
    @overload
    @staticmethod
    def getAllRoomsS (id: PyDb.Database)-> list : ...
    @overload
    @staticmethod
    def getAllRoomsS (val: PyBrxBim.BimStory)-> list : ...
    @overload
    @staticmethod
    def getAllRoomsS (val: PyBrxBim.BimStory, id: PyDb.Database)-> list : ...
    @overload
    @staticmethod
    def getAllRoomsS (val: PyBrxBim.BimBuilding)-> list : ...
    @overload
    @staticmethod
    def getAllRoomsS (val: PyBrxBim.BimBuilding, id: PyDb.Database)-> list : ...
    @staticmethod
    def getAllRoomsS (self, *args, **kwargs)-> list :
        '''Overloads:
    - None: Any
    - id: PyDb.Database
    - val: PyBrxBim.BimStory- val: PyBrxBim.BimStory, id: PyDb.Database
    - val: PyBrxBim.BimBuilding- val: PyBrxBim.BimBuilding, id: PyDb.Database
    '''
        ...
    def getAssignedBuilding (self)-> PyBrxBim.BimBuilding :
        '''                             '''
        ...

    @staticmethod
    def getAssignedBuildingS (id: PyDb.ObjectId)-> PyBrxBim.BimBuilding :
        '''                             '''
        ...
    def getAssignedLocation (self)-> PyBrxBim.BimSpatialLocation :
        '''                             '''
        ...

    @staticmethod
    def getAssignedLocationS (id: PyDb.ObjectId)-> PyBrxBim.BimSpatialLocation :
        '''                             '''
        ...
    def getAssignedStory (self)-> PyBrxBim.BimStory :
        '''                             '''
        ...

    @staticmethod
    def getAssignedStoryS (id: PyDb.ObjectId)-> PyBrxBim.BimStory :
        '''                             '''
        ...
    def getBoundingElements (self)-> list :
        '''                             '''
        ...

    @staticmethod
    def getBoundingElementsS (id: PyDb.ObjectId)-> list :
        '''                             '''
        ...
    def getId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def getOpenings (self)-> list :
        '''                             '''
        ...

    @staticmethod
    def getOpeningsS (id: PyDb.ObjectId)-> list :
        '''                             '''
        ...
    def getRoomDepartment (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def getRoomDepartmentS (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...
    def getRoomEntity (self)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def getRoomEntityS (val: PyBrxBim.BimRoom)-> PyDb.ObjectId :
        '''                             '''
        ...
    def getRoomRepresentation (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def getRoomRepresentationS (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...
    def isAssociativeRoom (self)-> bool :
        '''                             '''
        ...

    @staticmethod
    def isAssociativeRoomS (id: PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def isRoomValid (self)-> bool :
        '''                             '''
        ...

    @staticmethod
    def isRoomValidS (id: PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def roomArea (self)-> float :
        '''                             '''
        ...

    @staticmethod
    def roomAreaS (id: PyDb.ObjectId)-> float :
        '''                             '''
        ...
    def roomIdent (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def roomIdentS (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...
    def roomName (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def roomNameS (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...
    def roomNumber (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def roomNumberS (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...
    def setDescription (self, val: str)-> None :
        '''                             '''
        ...

    @staticmethod
    def setDescriptionS (id: PyDb.ObjectId,val: str)-> None :
        '''                             '''
        ...
    def setId (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setName (self, val: str)-> None :
        '''                             '''
        ...
    def setNull (self)-> None :
        '''                             '''
        ...
    def setRoomDepartment (self, val: str)-> None :
        '''                             '''
        ...

    @staticmethod
    def setRoomDepartmentS (id: PyDb.ObjectId,val: str)-> None :
        '''                             '''
        ...
    def setRoomName (self, val: str)-> None :
        '''                             '''
        ...

    @staticmethod
    def setRoomNameS (id: PyDb.ObjectId,val: str)-> None :
        '''                             '''
        ...
    def setRoomNumber (self, val: str)-> None :
        '''                             '''
        ...

    @staticmethod
    def setRoomNumberS (id: PyDb.ObjectId,val: str)-> None :
        '''                             '''
        ...
    def setRoomRepresentation (self, val: str)-> None :
        '''                             '''
        ...

    @staticmethod
    def setRoomRepresentationS (id: PyDb.ObjectId,val: str)-> None :
        '''                             '''
        ...
    def typeDesc (self)-> PyBrxBim.BimObjectType :
        '''                             '''
        ...
    def typeName (self)-> str :
        '''                             '''
        ...
    def unassignLocation (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def unassignLocationS (id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def updateAssociativeRoom (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def updateAssociativeRoomS (id: PyDb.ObjectId)-> None :
        '''                             '''
        ...

class BimSpace(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def assignToBuilding (id: PyDb.ObjectId,building: PyBrxBim.BimBuilding)-> None :
        '''                             '''
        ...

    @staticmethod
    def assignToStory (id: PyDb.ObjectId,building: PyBrxBim.BimStory)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def createSpace (pt: PyGe.Point3d)-> PyDb.ObjectId :
        '''                             '''
        ...

    @overload
    @staticmethod
    def getAllSpaces (/)-> list : ...
    @overload
    @staticmethod
    def getAllSpaces (id: PyDb.Database)-> list : ...
    @overload
    @staticmethod
    def getAllSpaces (val: PyBrxBim.BimStory)-> list : ...
    @overload
    @staticmethod
    def getAllSpaces (val: PyBrxBim.BimStory, id: PyDb.Database)-> list : ...
    @overload
    @staticmethod
    def getAllSpaces (val: PyBrxBim.BimBuilding)-> list : ...
    @overload
    @staticmethod
    def getAllSpaces (val: PyBrxBim.BimBuilding, id: PyDb.Database)-> list : ...
    @staticmethod
    def getAllSpaces (self, *args, **kwargs)-> list :
        '''Overloads:
    - None: Any
    - id: PyDb.Database
    - val: PyBrxBim.BimStory- val: PyBrxBim.BimStory, id: PyDb.Database
    - val: PyBrxBim.BimBuilding- val: PyBrxBim.BimBuilding, id: PyDb.Database
    '''
        ...

    @staticmethod
    def getAssignedEntities (val: str|PyDb.ObjectId,db: PyDb.Database=None)-> list :
        '''                             '''
        ...

    @staticmethod
    def getAssignedSpace (id: PyDb.ObjectId)-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def getBoundingElements (id: PyDb.ObjectId)-> list :
        '''                             '''
        ...

    @staticmethod
    def getSpaceArea (id: PyDb.ObjectId)-> float :
        '''                             '''
        ...

    @staticmethod
    def getSpaceEntity (spaceName: str,db: PyDb.Database = None)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def getSpaceName (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...

    @staticmethod
    def getSpaceNumber (id: PyDb.ObjectId)-> str :
        '''                             '''
        ...

    @staticmethod
    def getSpaceRepresentation (id: PyDb.ObjectId)-> PyBrxBim.BimSpaceRepresentation :
        '''                             '''
        ...

    @staticmethod
    def isSpaceUpdated (id: PyDb.ObjectId)-> bool :
        '''                             '''
        ...

    @staticmethod
    def isSpaceValid (id: PyDb.ObjectId)-> bool :
        '''                             '''
        ...

    @staticmethod
    def setAssignedSpace (id: PyDb.ObjectId,val: str|PyDb.ObjectId)-> None :
        '''                             '''
        ...

    @staticmethod
    def setSpaceName (id: PyDb.ObjectId,val: str)-> None :
        '''                             '''
        ...

    @staticmethod
    def setSpaceNumber (id: PyDb.ObjectId,val: str)-> None :
        '''                             '''
        ...

    @staticmethod
    def setSpaceRepresentation (id: PyDb.ObjectId,val: PyBrxBim.BimSpaceRepresentation)-> None :
        '''                             '''
        ...

    @staticmethod
    def updateSpace (id: PyDb.ObjectId)-> None :
        '''                             '''
        ...

class BimSpaceRepresentation(object):
    def eFootprint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSolid (self, *args, **kwargs)-> None :
        '''None'''
        ...

class BimSpatialLocation(BimObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...
    def assignToEntity (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def assignedObjects (self, id: PyDb.ObjectId)-> list :
        '''                             '''
        ...

    @staticmethod
    def assignedSpatialLocation (id: PyDb.ObjectId)-> PyBrxBim.BimSpatialLocation :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimSpatialLocation :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def description (self)-> str :
        '''                             '''
        ...
    def hasBuilding (self)-> bool :
        '''                             '''
        ...
    def hasStory (self)-> bool :
        '''                             '''
        ...
    def isBuilding (self)-> bool :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def isStory (self)-> bool :
        '''                             '''
        ...
    def longName (self)-> str :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def removeSpatialLocationFrom (id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setDescription (self, desc: str)-> None :
        '''                             '''
        ...
    def setLongName (self, *args, **kwargs)-> None :
        '''setLongName( (BimSpatialLocation)arg1, (str)arg2) -> None :

    C++ signature :
        void setLongName(class PyBrxBimSpatialLocation {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...
    def setName (self, name: str)-> None :
        '''                             '''
        ...
    def setNull (self)-> None :
        '''                             '''
        ...
    def typeDesc (self)-> PyBrxBim.BimObjectType :
        '''                             '''
        ...
    def typeName (self)-> str :
        '''                             '''
        ...

class BimStory(BimSpatialLocation):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def allStories (db: PyDb.Database)-> list :
        '''                             '''
        ...

    @staticmethod
    def allStoryNames (db: PyDb.Database)-> list :
        '''                             '''
        ...
    def assignToEntity (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def assignedObjects (self, db: PyDb.Database)-> list :
        '''                             '''
        ...

    @staticmethod
    def assignedStory (id: PyDb.ObjectId)-> PyBrxBim.BimStory :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimStory :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def createNewStory (db: PyDb.Database,buildingName: str,storyName: str)-> PyBrxBim.BimStory :
        '''                             '''
        ...
    def createStory (self, szName: str, building: PyBrxBim.BimBuilding)-> None :
        '''                             '''
        ...
    def deleteStory (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def deleteStoryFromDatabase (db: PyDb.Database,buildingName: str,storyName: str)-> None :
        '''                             '''
        ...
    def description (self)-> str :
        '''                             '''
        ...
    def elevation (self)-> float :
        '''                             '''
        ...
    def getBuilding (self)-> PyBrxBim.BimBuilding :
        '''                             '''
        ...
    def getStory (self, db: PyDb.Database, buildingName: str, storyName: str)-> PyBrxBim.BimStory :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def longName (self)-> str :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def setDescription (self, desc: str)-> None :
        '''                             '''
        ...
    def setElevation (self, val: float)-> None :
        '''                             '''
        ...
    def setLongName (self, name: str)-> None :
        '''                             '''
        ...
    def setName (self, name: str)-> None :
        '''                             '''
        ...
    def setNull (self)-> None :
        '''                             '''
        ...

class BrxBimAttributeSet(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BrxBimDialogs(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class Core(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def createAnchoredBlockReference (blockRefId: PyDb.ObjectId,faceSubentPath: PyDb.FullSubentPath,pt: PyGe.Point3d,keepOrientation: bool)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def findMatchingBlockDefinition (entitySet: list[PyDb.ObjectId])-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def findSimilar3dSolids (entitySet: list[PyDb.ObjectId])-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def findSimilarGeometry (matchSet: list[PyDb.ObjectId],searchSet: list[PyDb.ObjectId])-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def getAnchorFace (id: PyDb.ObjectId)-> PyDb.FullSubentPath :
        '''                             '''
        ...

    @staticmethod
    def getAnchoredBlockReferences (db: PyDb.Database)-> list :
        '''                             '''
        ...

    @staticmethod
    def isAnchoredBlockRef (id: PyDb.ObjectId)-> bool :
        '''                             '''
        ...

    @staticmethod
    def isSimilarGeometry (firstSet: list[PyDb.ObjectId],secondSet: list[PyDb.ObjectId])-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def matchEntitiesToBlockDefinitions (entitySet: list[PyDb.ObjectId])-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def queryValidAnchorPt (pt: PyGe.Point3d,db: PyDb.Database)-> PyDb.FullSubentPath :
        '''                             '''
        ...

    @staticmethod
    def replaceGeometryByBlocks (similarGroups: tuple)-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def unAnchorBlockReference (id: PyDb.ObjectId)-> None :
        '''                             '''
        ...

class IfcBinary(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def clear (self)-> None :
        '''                             '''
        ...
    def getBit (self, val: int)-> bool :
        '''                             '''
        ...
    def getEncodedString (self, *args, **kwargs)-> str :
        '''getEncodedString( (IfcBinary)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getEncodedString(class PyIfcBinary {lvalue})'''
        ...
    def isEmpty (self)-> bool :
        '''                             '''
        ...
    def numBits (self)-> int :
        '''                             '''
        ...
    def reset (self, val: str)-> None :
        '''                             '''
        ...
    def resize (self, val: int)-> None :
        '''                             '''
        ...

class IfcEntity(object):
    def IfcId (self)-> int :
        '''                             '''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def create ()-> PyBrxBim.IfcEntity :
        '''                             '''
        ...
    def getAttribute (self, val: str)-> PyBrxBim.IfcVariant :
        '''                             '''
        ...
    def getInverseRefs (self)-> list :
        '''                             '''
        ...
    def isA (self)-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...
    def isKindOf (self, val: PyBrxBim.IfcEntityDesc)-> bool :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def setAttribute (self, val: str, attribValue: PyBrxBim.IfcVariant)-> None :
        '''                             '''
        ...

class IfcEntityDesc(object):

    @staticmethod
    def Ifc2DCompositeCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcActionRequest ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcActor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcActorRole ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcActuator ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcActuatorType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAddress ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAdvancedBrep ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAdvancedBrepWithVoids ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAdvancedFace ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAirTerminal ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAirTerminalBox ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAirTerminalBoxType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAirTerminalType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAirToAirHeatRecovery ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAirToAirHeatRecoveryType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlarm ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlarmType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlignment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlignment2DHorizontal ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlignment2DHorizontalSegment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlignment2DSegment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlignment2DVerSegCircularArc ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlignment2DVerSegLine ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlignment2DVerSegParabolicArc ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlignment2DVertical ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlignment2DVerticalSegment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAlignmentCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAngularDimension ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAnnotation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAnnotationCurveOccurrence ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAnnotationFillArea ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAnnotationFillAreaOccurrence ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAnnotationOccurrence ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAnnotationSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAnnotationSurfaceOccurrence ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAnnotationSymbolOccurrence ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAnnotationTextOccurrence ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcApplication ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAppliedValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAppliedValueRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcApproval ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcApprovalActorRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcApprovalPropertyRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcApprovalRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcArbitraryClosedProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcArbitraryOpenProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcArbitraryProfileDefWithVoids ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAsset ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAsymmetricIShapeProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAudioVisualAppliance ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAudioVisualApplianceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAxis1Placement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAxis2Placement2D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcAxis2Placement3D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBSplineCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBSplineCurveWithKnots ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBSplineSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBSplineSurfaceWithKnots ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBeam ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBeamStandardCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBeamType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBezierCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBlobTexture ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBlock ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoiler ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoilerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBooleanClippingResult ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBooleanResult ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoundaryCondition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoundaryCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoundaryEdgeCondition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoundaryFaceCondition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoundaryNodeCondition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoundaryNodeConditionWarping ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoundedCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoundedSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoundingBox ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBoxedHalfSpace ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBuilding ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBuildingElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBuildingElementComponent ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBuildingElementPart ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBuildingElementPartType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBuildingElementProxy ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBuildingElementProxyType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBuildingElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBuildingStorey ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBuildingSystem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBurner ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcBurnerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCShapeProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCableCarrierFitting ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCableCarrierFittingType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCableCarrierSegment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCableCarrierSegmentType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCableFitting ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCableFittingType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCableSegment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCableSegmentType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCalendarDate ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCartesianPoint ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCartesianPointList ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCartesianPointList2D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCartesianPointList3D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCartesianTransformationOperator ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCartesianTransformationOperator2D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCartesianTransformationOperator2DnonUniform ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCartesianTransformationOperator3D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCartesianTransformationOperator3DnonUniform ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCenterLineProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcChamferEdgeFeature ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcChiller ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcChillerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcChimney ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcChimneyType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCircle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCircleHollowProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCircleProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCircularArcSegment2D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCivilElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCivilElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcClassification ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcClassificationItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcClassificationItemRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcClassificationNotation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcClassificationNotationFacet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcClassificationReference ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcClosedShell ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCoil ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCoilType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcColourRgb ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcColourRgbList ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcColourSpecification ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcColumn ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcColumnStandardCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcColumnType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCommunicationsAppliance ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCommunicationsApplianceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcComplexProperty ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcComplexPropertyTemplate ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCompositeCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCompositeCurveOnSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCompositeCurveSegment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCompositeProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCompressor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCompressorType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCondenser ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCondenserType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCondition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConditionCriterion ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConic ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConnectedFaceSet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConnectionCurveGeometry ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConnectionGeometry ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConnectionPointEccentricity ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConnectionPointGeometry ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConnectionPortGeometry ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConnectionSurfaceGeometry ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConnectionVolumeGeometry ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstraint ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstraintAggregationRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstraintClassificationRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstraintRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstructionEquipmentResource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstructionEquipmentResourceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstructionMaterialResource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstructionMaterialResourceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstructionProductResource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstructionProductResourceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstructionResource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConstructionResourceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcContext ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcContextDependentUnit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcControl ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcController ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcControllerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConversionBasedUnit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcConversionBasedUnitWithOffset ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCooledBeam ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCooledBeamType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCoolingTower ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCoolingTowerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCoordinateOperation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCoordinateReferenceSystem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCoordinatedUniversalTimeOffset ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCostItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCostSchedule ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCostValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCovering ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCoveringType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCraneRailAShapeProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCraneRailFShapeProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCrewResource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCrewResourceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCsgPrimitive3D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCsgSolid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurrencyRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurtainWall ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurtainWallType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurveBoundedPlane ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurveBoundedSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurveSegment2D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurveStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurveStyleFont ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurveStyleFontAndScaling ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCurveStyleFontPattern ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcCylindricalSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDamper ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDamperType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDateAndTime ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDefinedSymbol ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDerivedProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDerivedUnit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDerivedUnitElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDiameterDimension ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDimensionCalloutRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDimensionCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDimensionCurveDirectedCallout ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDimensionCurveTerminator ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDimensionPair ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDimensionalExponents ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDirection ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDiscreteAccessory ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDiscreteAccessoryType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistanceExpression ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionChamberElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionChamberElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionCircuit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionControlElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionControlElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionFlowElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionFlowElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionPort ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDistributionSystem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDocumentElectronicFormat ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDocumentInformation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDocumentInformationRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDocumentReference ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDoor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDoorLiningProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDoorPanelProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDoorStandardCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDoorStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDoorType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDraughtingCallout ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDraughtingCalloutRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDraughtingPreDefinedColour ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDraughtingPreDefinedCurveFont ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDraughtingPreDefinedTextFont ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDuctFitting ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDuctFittingType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDuctSegment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDuctSegmentType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDuctSilencer ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcDuctSilencerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEdge ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEdgeCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEdgeFeature ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEdgeLoop ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricAppliance ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricApplianceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricDistributionBoard ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricDistributionBoardType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricDistributionPoint ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricFlowStorageDevice ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricFlowStorageDeviceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricGenerator ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricGeneratorType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricHeaterType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricMotor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricMotorType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricTimeControl ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricTimeControlType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricalBaseProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricalCircuit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElectricalElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElementAssembly ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElementAssemblyType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElementComponent ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElementComponentType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElementQuantity ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcElementarySurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEllipse ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEllipseProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEnergyConversionDevice ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEnergyConversionDeviceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEnergyProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEngine ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEngineType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEnvironmentalImpactValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEquipmentElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEquipmentStandard ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEvaporativeCooler ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEvaporativeCoolerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEvaporator ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEvaporatorType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEvent ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEventTime ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcEventType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExtendedMaterialProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExtendedProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExternalInformation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExternalReference ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExternalReferenceRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExternalSpatialElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExternalSpatialStructureElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExternallyDefinedHatchStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExternallyDefinedSurfaceStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExternallyDefinedSymbol ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExternallyDefinedTextFont ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExtrudedAreaSolid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcExtrudedAreaSolidTapered ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFace ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFaceBasedSurfaceModel ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFaceBound ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFaceOuterBound ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFaceSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFacetedBrep ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFacetedBrepWithVoids ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFailureConnectionCondition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFan ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFanType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFastener ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFastenerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFeatureElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFeatureElementAddition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFeatureElementSubtraction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFillAreaStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFillAreaStyleHatching ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFillAreaStyleTileSymbolWithStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFillAreaStyleTiles ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFilter ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFilterType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFireSuppressionTerminal ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFireSuppressionTerminalType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFixedReferenceSweptAreaSolid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowController ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowControllerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowFitting ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowFittingType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowInstrument ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowInstrumentType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowMeter ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowMeterType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowMovingDevice ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowMovingDeviceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowSegment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowSegmentType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowStorageDevice ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowStorageDeviceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowTerminal ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowTerminalType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowTreatmentDevice ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFlowTreatmentDeviceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFluidFlowProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFooting ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFootingType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFuelProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFurnishingElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFurnishingElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFurniture ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFurnitureStandard ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcFurnitureType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGasTerminalType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGeneralMaterialProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGeneralProfileProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGeographicElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGeographicElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGeometricCurveSet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGeometricRepresentationContext ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGeometricRepresentationItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGeometricRepresentationSubContext ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGeometricSet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGrid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGridAxis ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGridPlacement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcGroup ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcHalfSpaceSolid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcHeatExchanger ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcHeatExchangerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcHumidifier ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcHumidifierType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcHygroscopicMaterialProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcIShapeProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcImageTexture ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcIndexedColourMap ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcIndexedPolyCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcIndexedPolygonalFace ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcIndexedPolygonalFaceWithVoids ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcIndexedTextureMap ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcIndexedTriangleTextureMap ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcInterceptor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcInterceptorType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcIntersectionCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcInventory ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcIrregularTimeSeries ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcIrregularTimeSeriesValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcJunctionBox ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcJunctionBoxType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLShapeProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLaborResource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLaborResourceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLagTime ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLamp ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLampType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLibraryInformation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLibraryReference ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLightDistributionData ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLightFixture ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLightFixtureType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLightIntensityDistribution ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLightSource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLightSourceAmbient ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLightSourceDirectional ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLightSourceGoniometric ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLightSourcePositional ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLightSourceSpot ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLine ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLineSegment2D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLinearDimension ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLinearPlacement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLinearPositioningElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLocalPlacement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLocalTime ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcLoop ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcManifoldSolidBrep ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMapConversion ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMappedItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterial ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialClassificationRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialConstituent ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialConstituentSet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialDefinition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialDefinitionRepresentation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialLayer ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialLayerSet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialLayerSetUsage ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialLayerWithOffsets ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialList ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialProfile ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialProfileSet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialProfileSetUsage ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialProfileSetUsageTapering ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialProfileWithOffsets ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMaterialUsageDefinition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMeasureWithUnit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMechanicalConcreteMaterialProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMechanicalFastener ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMechanicalFastenerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMechanicalMaterialProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMechanicalSteelMaterialProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMedicalDevice ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMedicalDeviceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMember ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMemberStandardCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMemberType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMetric ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMirroredProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMonetaryUnit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMotorConnection ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMotorConnectionType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcMove ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcNamedUnit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcObject ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcObjectDefinition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcObjectPlacement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcObjective ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOccupant ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOffsetCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOffsetCurve2D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOffsetCurve3D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOffsetCurveByDistances ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOneDirectionRepeatFactor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOpenShell ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOpeningElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOpeningStandardCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOpticalMaterialProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOrderAction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOrganization ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOrganizationRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOrientationExpression ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOrientedEdge ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOuterBoundaryCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOutlet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOutletType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcOwnerHistory ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcParameterizedProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPath ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPcurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPerformanceHistory ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPermeableCoveringProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPermit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPerson ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPersonAndOrganization ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPhysicalComplexQuantity ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPhysicalQuantity ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPhysicalSimpleQuantity ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPile ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPileType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPipeFitting ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPipeFittingType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPipeSegment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPipeSegmentType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPixelTexture ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPlacement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPlanarBox ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPlanarExtent ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPlane ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPlate ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPlateStandardCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPlateType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPoint ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPointOnCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPointOnSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPolyLoop ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPolygonalBoundedHalfSpace ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPolygonalFaceSet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPolyline ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPort ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPositioningElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPostalAddress ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPreDefinedColour ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPreDefinedCurveFont ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPreDefinedDimensionSymbol ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPreDefinedItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPreDefinedPointMarkerSymbol ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPreDefinedProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPreDefinedPropertySet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPreDefinedSymbol ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPreDefinedTerminatorSymbol ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPreDefinedTextFont ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPresentationItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPresentationLayerAssignment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPresentationLayerWithStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPresentationStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPresentationStyleAssignment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProcedure ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProcedureType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProcess ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProduct ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProductDefinitionShape ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProductRepresentation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProductsOfCombustionProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProfileProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProject ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProjectLibrary ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProjectOrder ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProjectOrderRecord ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProjectedCRS ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProjectionCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProjectionElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProperty ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyAbstraction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyBoundedValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyConstraintRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyDefinition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyDependencyRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyEnumeratedValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyEnumeration ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyListValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyReferenceValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertySet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertySetDefinition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertySetTemplate ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertySingleValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyTableValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyTemplate ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPropertyTemplateDefinition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProtectiveDevice ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProtectiveDeviceTrippingUnit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProtectiveDeviceTrippingUnitType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProtectiveDeviceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcProxy ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPump ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcPumpType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcQuantityArea ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcQuantityCount ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcQuantityLength ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcQuantitySet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcQuantityTime ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcQuantityVolume ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcQuantityWeight ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRadiusDimension ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRailing ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRailingType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRamp ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRampFlight ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRampFlightType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRampType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRationalBSplineCurveWithKnots ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRationalBSplineSurfaceWithKnots ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRationalBezierCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRectangleHollowProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRectangleProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRectangularPyramid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRectangularTrimmedSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRecurrencePattern ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReference ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReferencesValueDocument ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReferent ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRegularTimeSeries ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReinforcementBarProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReinforcementDefinitionProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReinforcingBar ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReinforcingBarType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReinforcingElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReinforcingElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReinforcingMesh ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReinforcingMeshType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAggregates ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssigns ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssignsTasks ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssignsToActor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssignsToControl ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssignsToGroup ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssignsToGroupByFactor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssignsToProcess ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssignsToProduct ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssignsToProjectOrder ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssignsToResource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssociates ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssociatesAppliedValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssociatesApproval ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssociatesClassification ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssociatesConstraint ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssociatesDocument ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssociatesLibrary ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssociatesMaterial ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelAssociatesProfileProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelConnects ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelConnectsElements ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelConnectsPathElements ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelConnectsPortToElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelConnectsPorts ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelConnectsStructuralActivity ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelConnectsStructuralElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelConnectsStructuralMember ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelConnectsWithEccentricity ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelConnectsWithRealizingElements ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelContainedInSpatialStructure ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelCoversBldgElements ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelCoversSpaces ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelDeclares ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelDecomposes ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelDefines ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelDefinesByObject ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelDefinesByProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelDefinesByTemplate ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelDefinesByType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelFillsElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelFlowControlElements ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelInteractionRequirements ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelInterferesElements ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelNests ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelOccupiesSpaces ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelOverridesProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelProjectsElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelReferencedInSpatialStructure ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelSchedulesCostItems ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelSequence ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelServicesBuildings ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelSpaceBoundary ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelSpaceBoundary1stLevel ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelSpaceBoundary2ndLevel ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelVoidsElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRelaxation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcReparametrisedCompositeCurveSegment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRepresentation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRepresentationContext ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRepresentationItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRepresentationMap ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcResource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcResourceApprovalRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcResourceConstraintRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcResourceLevelRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcResourceTime ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRevolvedAreaSolid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRevolvedAreaSolidTapered ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRibPlateProfileProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRightCircularCone ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRightCircularCylinder ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRoof ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRoofType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRoot ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRoundedEdgeFeature ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcRoundedRectangleProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSIUnit ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSanitaryTerminal ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSanitaryTerminalType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcScheduleTimeControl ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSchedulingTime ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSeamCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSectionProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSectionReinforcementProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSectionedSolid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSectionedSolidHorizontal ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSectionedSpine ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSensor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSensorType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcServiceLife ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcServiceLifeFactor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcShadingDevice ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcShadingDeviceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcShapeAspect ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcShapeModel ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcShapeRepresentation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcShellBasedSurfaceModel ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSimpleProperty ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSimplePropertyTemplate ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSite ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSlab ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSlabElementedCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSlabStandardCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSlabType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSlippageConnectionCondition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSolarDevice ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSolarDeviceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSolidModel ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSoundProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSoundValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpace ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpaceHeater ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpaceHeaterType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpaceProgram ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpaceThermalLoadProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpaceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpatialElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpatialElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpatialStructureElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpatialStructureElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpatialZone ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSpatialZoneType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSphere ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSphericalSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStackTerminal ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStackTerminalType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStair ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStairFlight ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStairFlightType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStairType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralAction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralActivity ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralAnalysisModel ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralConnection ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralConnectionCondition ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralCurveAction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralCurveConnection ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralCurveMember ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralCurveMemberVarying ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralCurveReaction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLinearAction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLinearActionVarying ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoad ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadConfiguration ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadGroup ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadLinearForce ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadOrResult ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadPlanarForce ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadSingleDisplacement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadSingleDisplacementDistortion ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadSingleForce ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadSingleForceWarping ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadStatic ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralLoadTemperature ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralMember ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralPlanarAction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralPlanarActionVarying ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralPointAction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralPointConnection ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralPointReaction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralProfileProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralReaction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralResultGroup ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralSteelProfileProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralSurfaceAction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralSurfaceConnection ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralSurfaceMember ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralSurfaceMemberVarying ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuralSurfaceReaction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStructuredDimensionCallout ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStyleModel ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStyledItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcStyledRepresentation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSubContractResource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSubContractResourceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSubedge ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceCurveSweptAreaSolid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceFeature ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceOfLinearExtrusion ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceOfRevolution ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceReinforcementArea ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceStyleLighting ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceStyleRefraction ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceStyleRendering ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceStyleShading ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceStyleWithTextures ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSurfaceTexture ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSweptAreaSolid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSweptDiskSolid ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSweptDiskSolidPolygonal ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSweptSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSwitchingDevice ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSwitchingDeviceType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSymbolStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSystem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSystemFurnitureElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcSystemFurnitureElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTShapeProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTable ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTableColumn ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTableRow ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTank ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTankType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTask ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTaskTime ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTaskTimeRecurring ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTaskType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTelecomAddress ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTendon ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTendonAnchor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTendonAnchorType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTendonType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTerminatorSymbol ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTessellatedFaceSet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTessellatedItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextLiteral ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextLiteralWithExtent ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextStyleFontModel ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextStyleForDefinedFont ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextStyleTextModel ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextStyleWithBoxCharacteristics ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextureCoordinate ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextureCoordinateGenerator ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextureMap ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextureVertex ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTextureVertexList ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcThermalMaterialProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTimePeriod ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTimeSeries ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTimeSeriesReferenceRelationship ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTimeSeriesSchedule ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTimeSeriesValue ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTopologicalRepresentationItem ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTopologyRepresentation ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcToroidalSurface ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTransformer ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTransformerType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTransitionCurveSegment2D ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTransportElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTransportElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTrapeziumProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTriangulatedFaceSet ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTriangulatedIrregularNetwork ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTrimmedCurve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTubeBundle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTubeBundleType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTwoDirectionRepeatFactor ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTypeObject ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTypeProcess ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTypeProduct ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcTypeResource ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcUShapeProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcUnitAssignment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcUnitaryControlElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcUnitaryControlElementType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcUnitaryEquipment ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcUnitaryEquipmentType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcValve ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcValveType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcVector ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcVertex ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcVertexBasedTextureMap ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcVertexLoop ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcVertexPoint ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcVibrationIsolator ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcVibrationIsolatorType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcVirtualElement ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcVirtualGridIntersection ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcVoidingFeature ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWall ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWallElementedCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWallStandardCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWallType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWasteTerminal ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWasteTerminalType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWaterProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWindow ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWindowLiningProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWindowPanelProperties ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWindowStandardCase ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWindowStyle ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWindowType ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWorkCalendar ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWorkControl ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWorkPlan ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWorkSchedule ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcWorkTime ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcZShapeProfileDef ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...

    @staticmethod
    def IfcZone ()-> PyBrxBim.IfcEntityDesc :
        '''                             '''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def isDerivedFrom (self, entDesc: PyBrxBim.IfcEntityDesc, eSchema: IfcSchemaId)-> bool :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...

class IfcEnumValue(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getValue (self)-> str :
        '''                             '''
        ...
    def setValue (self, val: str)-> None :
        '''                             '''
        ...

class IfcGuid(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def create ()-> PyBrxBim.IfcGuid :
        '''                             '''
        ...

    @staticmethod
    def createFromBase64 (val: str)-> PyBrxBim.IfcGuid :
        '''                             '''
        ...

    @staticmethod
    def createFromText (val: str)-> PyBrxBim.IfcGuid :
        '''                             '''
        ...
    def getBase64 (self)-> str :
        '''                             '''
        ...
    def getText (self)-> str :
        '''                             '''
        ...

class IfcHeader(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...
    def author (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...
    def authorization (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def fileDescription (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...
    def fileName (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...
    def fileSchema (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...
    def implementationLevel (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...
    def organization (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...
    def originatingSystem (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...
    def preprocessorVersion (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...
    def setAuthor (self, val: PyBrxBim.IfcString)-> None :
        '''                             '''
        ...
    def setAuthorization (self, val: PyBrxBim.IfcString)-> None :
        '''                             '''
        ...
    def setFileDescription (self, val: PyBrxBim.IfcString)-> None :
        '''                             '''
        ...
    def setFileName (self, val: PyBrxBim.IfcString)-> None :
        '''                             '''
        ...
    def setFileSchema (self, val: PyBrxBim.IfcString)-> None :
        '''                             '''
        ...
    def setOrganization (self, val: PyBrxBim.IfcString)-> None :
        '''                             '''
        ...
    def setOriginatingSystem (self, val: PyBrxBim.IfcString)-> None :
        '''                             '''
        ...
    def setPreprocessorVersion (self, val: PyBrxBim.IfcString)-> None :
        '''                             '''
        ...
    def setTimeStamp (self, val: PyBrxBim.IfcString)-> None :
        '''                             '''
        ...
    def timeStamp (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...

class IfcImportContext(object):
    def IfcModel (self)-> PyBrxBim.IfcModel :
        '''                             '''
        ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def angleConversionFactor (self)-> float :
        '''                             '''
        ...
    def areaConversionFactor (self)-> float :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def createDefaultRepresentation (self, entity: PyBrxBim.IfcEntity, isParent: bool, parent: PyBrxBim.IfcEntity)-> PyBr.Entity :
        '''                             '''
        ...
    def createPoint (self, entity: PyBrxBim.IfcEntity)-> PyGe.Point3d :
        '''                             '''
        ...
    def createRepresentationFromItem (self, entity: PyBrxBim.IfcEntity)-> PyBr.Entity :
        '''                             '''
        ...
    def createSweptArea (self, entity: PyBrxBim.IfcEntity)-> list :
        '''                             '''
        ...
    def database (self)-> PyDb.Database :
        '''                             '''
        ...
    def getEntity (self, entity: PyBrxBim.IfcEntity)-> PyBr.Entity :
        '''                             '''
        ...
    def getEntityId (self, entity: PyBrxBim.IfcEntity)-> PyDb.ObjectId :
        '''                             '''
        ...
    def getLocalPlacement (self, entity: PyBrxBim.IfcEntity)-> PyGe.Matrix3d :
        '''                             '''
        ...
    def lengthConversionFactor (self)-> float :
        '''                             '''
        ...
    def precision (self)-> float :
        '''                             '''
        ...
    def volumeConversionFactor (self)-> float :
        '''                             '''
        ...

class IfcImportInfo(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...
    def author (self)-> str :
        '''                             '''
        ...
    def authorization (self)-> str :
        '''                             '''
        ...
    def className (self)-> str :
        '''                             '''
        ...
    def importBimData (self)-> bool :
        '''                             '''
        ...
    def importBrepGeometryAsMeshes (self)-> bool :
        '''                             '''
        ...
    def importIfcProjectStructureAsXrefs (self)-> bool :
        '''                             '''
        ...
    def importIfcSpace (self)-> bool :
        '''                             '''
        ...
    def importParametricComponents (self)-> bool :
        '''                             '''
        ...
    def organization (self)-> str :
        '''                             '''
        ...
    def originatingSystem (self)-> str :
        '''                             '''
        ...
    def preprocessorVersion (self)-> str :
        '''                             '''
        ...
    def timeStamp (self)-> str :
        '''                             '''
        ...

class IfcImportModelOrigin(object):
    def eIfcGlobalOrigin (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eIfcProjectLocation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eIfcSiteLocation (self, *args, **kwargs)-> None :
        '''None'''
        ...

class IfcImportOptions(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def importBimData (self)-> bool :
        '''                             '''
        ...
    def importBrepGeometryAsMeshes (self)-> bool :
        '''                             '''
        ...

    @staticmethod
    def importIfcFile (db: PyDb.Database,filename: str,options: PyBrxIfc.ImportOptions=None)-> None :
        '''                             '''
        ...
    def importIfcProjectStructureAsXrefs (self)-> bool :
        '''                             '''
        ...
    def importIfcSpace (self)-> bool :
        '''                             '''
        ...
    def importModelOrigin (self)-> PyBrxBim.IfcImportModelOrigin :
        '''                             '''
        ...
    def importParametricComponents (self)-> bool :
        '''                             '''
        ...
    def setImportBimData (self, val: bool)-> None :
        '''                             '''
        ...
    def setImportBrepGeometryAsMeshes (self, val: bool)-> None :
        '''                             '''
        ...
    def setImportIfcProjectStructureAsXrefs (self, val: bool)-> None :
        '''                             '''
        ...
    def setImportIfcSpace (self, val: bool)-> None :
        '''                             '''
        ...
    def setImportModelOrigin (self, val: PyBrxBim.IfcImportModelOrigin)-> None :
        '''                             '''
        ...
    def setImportParametricComponents (self, val: bool)-> None :
        '''                             '''
        ...

class IfcImportReactor(object):
    def __init__ (self, displayName: str, guid: str)-> None :
        '''                             '''
        ...
    def attachReactor (self)-> bool :
        '''                             '''
        ...
    def beforeCompletion (self, context: PyBrxBim.IfcImportContext, success: bool)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def detachReactor (self)-> bool :
        '''                             '''
        ...
    def onIfcProduct (self, context: PyBrxBim.IfcImportContext, entity:  PyBrxBim.IfcEntity, isParent: bool, parentEntity:  PyBrxBim.IfcEntity)-> bool :
        '''                             '''
        ...
    def onIfcProductImported (self, desc: PyBrxBim.IfcEntityDesc, schema: EIfcSchemaId)-> None :
        '''                             '''
        ...
    def onStart (self, context: PyBrxBim.IfcImportContext, project:  PyBrxBim.IfcEntity, info: PyBrxBim.IfcImportInfo)-> None :
        '''                             '''
        ...

class IfcLogical(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def isKnown (self)-> bool :
        '''                             '''
        ...
    def isUnknown (self)-> bool :
        '''                             '''
        ...

class IfcModel(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def get (self, val: int)-> PyBrxBim.IfcEntity :
        '''                             '''
        ...
    def getNumEntities (self)-> int :
        '''                             '''
        ...

    @staticmethod
    def read (val: str)-> PyBrxBim.IfcModel :
        '''                             '''
        ...
    def release (self)-> None :
        '''                             '''
        ...
    def schemaId (self)-> PyBrxBim.IfcSchemaId :
        '''                             '''
        ...

    @staticmethod
    def write (val: str,val: PyBrxBim.IfcHeader)-> bool :
        '''                             '''
        ...

class IfcResult(object):
    def eInternalError (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNotInitialized (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eOk (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eWrongName (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eWrongType (self, *args, **kwargs)-> None :
        '''None'''
        ...

class IfcSchemaId(object):
    def eIFC2X3 (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eIFC4 (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eIFC4X1 (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eIfcSchemaLast (self, *args, **kwargs)-> None :
        '''None'''
        ...

class IfcSelectValue(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getValue (self)-> PyBrxBim.IfcVariant :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def setValue (self, tag: str, val: PyBrxBim.IfcVariant)-> str :
        '''                             '''
        ...
    def tag (self)-> str :
        '''                             '''
        ...

class IfcSelectorDesc(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class IfcString(object):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, text: str)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - text: str
    '''
        ...
    def c_str (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def decode (val: str)-> PyBrxBim.IfcString :
        '''                             '''
        ...
    def getEncoded (self)-> str :
        '''                             '''
        ...
    def isEmpty (self)-> bool :
        '''                             '''
        ...
    def setEmpty (self)-> None :
        '''                             '''
        ...

class IfcValueType(object):
    def eBinary (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBool (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eEmpty (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eEntity (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eEnum (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGuid (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInt (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLogical (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eReal (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSelect (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eString (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUInt (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eVector (self, *args, **kwargs)-> None :
        '''None'''
        ...

class IfcVariant(object):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getBinary (self)-> PyBrxBim.IfcBinary :
        '''                             '''
        ...
    def getBool (self)-> bool :
        '''                             '''
        ...
    def getEntity (self)-> PyBrxBim.IfcEntity :
        '''                             '''
        ...
    def getEnum (self)-> PyBrxBim.IfcEnumValue :
        '''                             '''
        ...
    def getGuid (self)-> PyBrxBim.IfcGuid :
        '''                             '''
        ...
    def getInt (self)-> int :
        '''                             '''
        ...
    def getLogical (self)-> PyBrxBim.IfcLogical :
        '''                             '''
        ...
    def getReal (self)-> float :
        '''                             '''
        ...
    def getSelect (self)-> PyBrxBim.IfcSelectValue :
        '''                             '''
        ...
    def getString (self)-> PyBrxBim.IfcString :
        '''                             '''
        ...
    def getUInt (self)-> int :
        '''                             '''
        ...
    def getVector (self)-> PyBrxBim.IfcVectorValue :
        '''                             '''
        ...
    def setBinary (self, val: PyBrxBim.IfcBinary)-> None :
        '''                             '''
        ...
    def setBool (self, val: bool)-> None :
        '''                             '''
        ...
    def setEntity (self, val: PyBrxBim.IfcEntity)-> None :
        '''                             '''
        ...
    def setEnum (self, val: PyBrxBim.IfcEnumValue)-> None :
        '''                             '''
        ...
    def setGuid (self, val: PyBrxBim.IfcGuid)-> None :
        '''                             '''
        ...
    def setInt (self, val: int)-> None :
        '''                             '''
        ...
    def setLogical (self, val: PyBrxBim.IfcLogical)-> None :
        '''                             '''
        ...
    def setReal (self, val: float)-> None :
        '''                             '''
        ...
    def setSelect (self, val: PyBrxBim.IfcVectorValue)-> None :
        '''                             '''
        ...
    def setString (self, val: PyBrxBim.IfcString)-> None :
        '''                             '''
        ...
    def setUInt (self, val: int)-> None :
        '''                             '''
        ...
    def setVector (self, val: PyBrxBim.IfcVectorValue)-> None :
        '''                             '''
        ...
    def type (self)-> PyBrxBim.IfcValueType :
        '''                             '''
        ...

class IfcVectorDesc(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class IfcVectorValue(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def add (self, val: PyBrxBim.IfcVariant)-> PyBrxBim.IfcResult :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def clear (self)-> None :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def remove (self, val: int)-> bool :
        '''                             '''
        ...
    def size (self)-> int :
        '''                             '''
        ...

class PyBrxBimPropertySets(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class ResultStatus(object):
    def eAssociatedLibraryNotAccessible (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimNotAvailable (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBimNotImplementedYet (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDbNotAccessible (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDbNotOpenForWrite (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDbObjectNotSupported (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInternalError (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidArgument (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidIndex (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidInput (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidMaterial (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidMaterialComposition (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidName (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidSpatialLocation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidValue (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInvalidXmlFormat (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eModelSpaceNotAccessible (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNameSpaceAlreadyExists (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNoAttributeSet (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNoData (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNoDbResidentObject (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNoNameSpace (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNoProfileAssigned (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNoProperty (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNoPropertySet (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNotApplicableForTheseParameters (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNotAssignedToLibrary (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNotImplemented (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNotLinearBuildingElement (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNullDatabase (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNullDocument (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNullObject (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNullObjectId (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNullString (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eObjectAlreadyExists (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eObjectCouldNotBeDeleted (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eObjectNotExisting (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eObjectNotSupported (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eOk (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eProjectDbNotAccessible (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePropertySetAlreadyExists (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUnassignedEntity (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUnknownData (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUnknownError (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eWrongDataType (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eXmlFileCouldNotBeParsed (self, *args, **kwargs)-> None :
        '''None'''
        ...
