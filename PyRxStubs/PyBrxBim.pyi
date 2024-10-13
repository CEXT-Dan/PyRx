import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
import PySm
import PyBrxCv
import PyBrxBim
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimBuilding :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
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

class BimPropertyInfo(object):
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

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimRoom :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BimSpace(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
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
    def hasBuilding (self)-> bool :
        '''                             '''
        ...
    def hasStory (self)-> bool :
        '''                             '''
        ...
    def isBuilding (self)-> bool :
        '''                             '''
        ...
    def isStory (self)-> bool :
        '''                             '''
        ...
    def longName (self)-> str :
        '''                             '''
        ...

    @staticmethod
    def removeSpatialLocationFrom (id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setLongName (self, *args, **kwargs)-> None :
        '''setLongName( (BimSpatialLocation)arg1, (str)arg2) -> None :

    C++ signature :
        void setLongName(class PyBrxBimSpatialLocation {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...

class BimStory(BimSpatialLocation):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def allStories (db: PyDb.Database)-> list :
        '''                             '''
        ...

    @staticmethod
    def allStoryNames (db: PyDb.Database)-> list :
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
    def createStory (self, szName: str, building: PyBrxBim.Building)-> None :
        '''                             '''
        ...
    def deleteStory (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def deleteStoryFromDatabase (db: PyDb.Database,buildingName: str,storyName: str)-> None :
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
    def setElevation (self, val: float)-> None :
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
    def IfcWindow ()-> PyBrxBim.IfcEntityDesc :
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
    def createDefaultRepresentation (self, entity: PyBrxBim.IfcEntity, isParent: bool, parent: PyBrxBim.IfcEntity)-> PyDb.Entity :
        '''                             '''
        ...
    def createPoint (self, entity: PyBrxBim.IfcEntity)-> PyGe.Point3d :
        '''                             '''
        ...
    def createRepresentationFromItem (self, entity: PyBrxBim.IfcEntity)-> PyDb.Entity :
        '''                             '''
        ...
    def createSweptArea (self, entity: PyBrxBim.IfcEntity)-> list :
        '''                             '''
        ...
    def database (self)-> PyDb.Database :
        '''                             '''
        ...
    def getEntity (self, entity: PyBrxBim.IfcEntity)-> PyDb.Entity :
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
    def schemaId (self)-> object :
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
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def eBinary, (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBool, (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eEmpty (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eEntity, (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eEnum, (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGuid, (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eInt, (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLogical (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eReal, (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSelect, (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eString, (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUInt, (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eVector, (self, *args, **kwargs)-> None :
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
