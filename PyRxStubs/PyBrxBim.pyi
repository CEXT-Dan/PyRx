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

class IFCBinary(object):
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
        '''getEncodedString( (IFCBinary)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getEncodedString(class PyIFCBinary {lvalue})'''
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

class IFCEntity(object):
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
    def create ()-> PyBrxBim.IFCEntity :
        '''                             '''
        ...
    def getAttribute (self, val: str)-> object :
        '''                             '''
        ...
    def getInverseRefs (self)-> list :
        '''                             '''
        ...
    def ifcId (self)-> int :
        '''                             '''
        ...
    def isA (self)-> PyBrxBim.IFCEntityDesc :
        '''                             '''
        ...
    def isKindOf (self, val: PyBrxBim.IFCEntityDesc)-> bool :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def setAttribute (self, val: str, attribValue: PyBrxBim.IFCVariant)-> None :
        '''                             '''
        ...

class IFCEntityDesc(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def isDerivedFrom (self, entDesc: PyBrxBim.IFCEntityDesc, eSchema: IfcSchemaId)-> bool :
        '''                             '''
        ...

class IFCEnumValue(object):
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

class IFCGuid(object):
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
    def create ()-> PyBrxBim.IFCGuid :
        '''                             '''
        ...

    @staticmethod
    def createFromBase64 (val: str)-> PyBrxBim.IFCGuid :
        '''                             '''
        ...

    @staticmethod
    def createFromText (val: str)-> PyBrxBim.IFCGuid :
        '''                             '''
        ...
    def getBase64 (self)-> str :
        '''                             '''
        ...
    def getText (self)-> str :
        '''                             '''
        ...

class IFCHeader(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...
    def author (self)-> PyBrxBim.IFCString :
        '''                             '''
        ...
    def authorization (self)-> PyBrxBim.IFCString :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def fileDescription (self)-> PyBrxBim.IFCString :
        '''                             '''
        ...
    def fileName (self)-> PyBrxBim.IFCString :
        '''                             '''
        ...
    def fileSchema (self)-> PyBrxBim.IFCString :
        '''                             '''
        ...
    def implementationLevel (self)-> PyBrxBim.IFCString :
        '''                             '''
        ...
    def organization (self)-> PyBrxBim.IFCString :
        '''                             '''
        ...
    def originatingSystem (self)-> PyBrxBim.IFCString :
        '''                             '''
        ...
    def preprocessorVersion (self)-> PyBrxBim.IFCString :
        '''                             '''
        ...
    def setAuthor (self, val: PyBrxBim.IFCString)-> None :
        '''                             '''
        ...
    def setAuthorization (self, val: PyBrxBim.IFCString)-> None :
        '''                             '''
        ...
    def setFileDescription (self, val: PyBrxBim.IFCString)-> None :
        '''                             '''
        ...
    def setFileName (self, val: PyBrxBim.IFCString)-> None :
        '''                             '''
        ...
    def setFileSchema (self, val: PyBrxBim.IFCString)-> None :
        '''                             '''
        ...
    def setOrganization (self, val: PyBrxBim.IFCString)-> None :
        '''                             '''
        ...
    def setOriginatingSystem (self, val: PyBrxBim.IFCString)-> None :
        '''                             '''
        ...
    def setPreprocessorVersion (self, val: PyBrxBim.IFCString)-> None :
        '''                             '''
        ...
    def setTimeStamp (self, val: PyBrxBim.IFCString)-> None :
        '''                             '''
        ...
    def timeStamp (self)-> PyBrxBim.IFCString :
        '''                             '''
        ...

class IFCLogical(object):
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

class IFCModel(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def get (self, val: int)-> PyBrxBim.IFCEntity :
        '''                             '''
        ...
    def getNumEntities (self)-> int :
        '''                             '''
        ...

    @staticmethod
    def read (val: str)-> PyBrxBim.IFCModel :
        '''                             '''
        ...
    def release (self)-> None :
        '''                             '''
        ...
    def schemaId (self)-> object :
        '''                             '''
        ...

    @staticmethod
    def write (val: str,val: PyBrxBim.IFCHeader)-> bool :
        '''                             '''
        ...

class IFCSelectValue(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getValue (self)-> object :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def setValue (self, tag: str, val: PyBrxBim.IFCVariant)-> str :
        '''                             '''
        ...
    def tag (self)-> str :
        '''                             '''
        ...

class IFCSelectorDesc(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class IFCString(object):
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
    def decode (val: str)-> PyBrxBim.IFCString :
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

class IFCVectorDesc(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class IFCVectorValue(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def add (self, val: PyBrxBim.IFCVariant)-> PyBrxBim.IfcResult :
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

class IfcImportContext(object):
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
    def createDefaultRepresentation (self, entity: PyBrxBim.IFCEntity, isParent: bool, parent: PyBrxBim.IFCEntity)-> PyDb.Entity :
        '''                             '''
        ...
    def createPoint (self, entity: PyBrxBim.IFCEntity)-> PyGe.Point3d :
        '''                             '''
        ...
    def createRepresentationFromItem (self, entity: PyBrxBim.IFCEntity)-> PyDb.Entity :
        '''                             '''
        ...
    def createSweptArea (self, entity: PyBrxBim.IFCEntity)-> list :
        '''                             '''
        ...
    def database (self)-> PyDb.Database :
        '''                             '''
        ...
    def getEntity (self, entity: PyBrxBim.IFCEntity)-> PyDb.Entity :
        '''                             '''
        ...
    def getEntityId (self, entity: PyBrxBim.IFCEntity)-> PyDb.ObjectId :
        '''                             '''
        ...
    def getLocalPlacement (self, entity: PyBrxBim.IFCEntity)-> PyGe.Matrix3d :
        '''                             '''
        ...
    def ifcModel (self)-> PyBrxBim.IFCModel :
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
    def importIfcFile ()-> None :
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
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def className ()-> str :
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
