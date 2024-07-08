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
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BimStory :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

class BrxBimBuilding(BimSpatialLocation):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PyBrxBim.BimObject)-> PyBrxBim.BrxBimBuilding :
        '''                             '''
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
