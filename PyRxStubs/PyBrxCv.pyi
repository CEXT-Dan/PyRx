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
from typing import overload
from typing import Any

class ArcParameterType(object):
    def eChordLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCurveAngle (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCurveLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCurveThroughPoint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDegreeOfCurve (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eExternalDist (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMiddleOrdinate (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eRadius (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTangentLength (self, *args, **kwargs)-> None :
        '''None'''
        ...

class ArcType(object):
    def eCompound (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eReverse (self, *args, **kwargs)-> None :
        '''None'''
        ...

class BlockAttachment(object):
    def eBlockAttachmentBottomCenter (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBlockAttachmentBottomLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBlockAttachmentBottomRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBlockAttachmentInsertionPoint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBlockAttachmentMiddleCenter (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBlockAttachmentMiddleLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBlockAttachmentMiddleRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBlockAttachmentTopCenter (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBlockAttachmentTopLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBlockAttachmentTopRight (self, *args, **kwargs)-> None :
        '''None'''
        ...

class BorderType(object):
    def eBorderTypeCircular (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBorderTypeRectangular (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eBorderTypeRoundedRectangular (self, *args, **kwargs)-> None :
        '''None'''
        ...

class BreaklineIntersectionElevation(object):
    def eTinElevationMax (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinElevationMid (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinElevationMin (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinNotAllowed (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Civil3dAlignmentType(object):
    def eCenterline (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCurbReturn (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMiscellaneous (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNotAlignment (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eOffset (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eRail (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Civil3dEntityType(object):
    def eAlignment (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNoEntity (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eProfile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eProfileView (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Civil3dLabels(object):
    def eAlignmentsLabels (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAllLabels (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDefaultLabels (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNoLabels (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSurfaceLabels (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUnattachedLabels (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Civil3dProfileType(object):
    def eDynamicSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLayout (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNotProfile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eQuick (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eStaticSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...

class CvCivil3dConverter(object):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, sourceDb: PyDb.Database, targetDb: PyDb.Database, doLabels: PyBrxCv.Civil3dLabels)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - sourceDb: PyDb.Database, targetDb: PyDb.Database, doLabels: PyBrxCv.Civil3dLabels
    '''
        ...
    def attachedLabels (self, civilEntity: PyBrxCv.CvCivil3dEntityInfo)-> list :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def convert (self, entitiesToConvert : list)-> list :
        '''                             '''
        ...
    def getCivilEntities (self)-> list :
        '''                             '''
        ...
    def getInsertedEntities (self)-> list :
        '''                             '''
        ...
    def unattachedLabels (self)-> list :
        '''                             '''
        ...

class CvCivil3dEntityInfo(object):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def alignmentType (self)-> PyBrxCv.Civil3dAlignmentType :
        '''                             '''
        ...
    def baseAlignment (self)-> PyBrxCv.CvCivil3dEntityInfo :
        '''                             '''
        ...
    def baseSurface (self)-> PyBrxCv.CvCivil3dEntityInfo :
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
    def objectId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def profileType (self)-> PyBrxCv.Civil3dProfileType :
        '''                             '''
        ...
    def profiles (self)-> list :
        '''                             '''
        ...
    def type (self)-> PyBrxCv.Civil3dEntityType :
        '''                             '''
        ...

class CvDb3dAlignment(CvDbCurve):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...
    def baseHAlignment (self)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDb3dAlignment :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDb3dAlignment :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getPointsArray (self)-> list :
        '''                             '''
        ...
    def length (self)-> float :
        '''                             '''
        ...
    def setBaseHAlignment (self, id : PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def setVAlignment (self, id : PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def vAlignment (self)-> PyDb.ObjectId :
        '''                             '''
        ...

class CvDbCurve(PyDb.Curve):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbCurve :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbCurve :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def description (self)-> str :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def setDescription (self, val : str)-> bool :
        '''                             '''
        ...
    def setName (self, val : str)-> bool :
        '''                             '''
        ...

class CvDbEntity(PyDb.Entity):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbEntity :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbEntity :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def description (self)-> str :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def setDescription (self, val : str)-> bool :
        '''                             '''
        ...
    def setName (self, val : str)-> bool :
        '''                             '''
        ...

class CvDbFileFormatManager(CvDbObjectManager):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...
    def allFileFormats (self)-> list :
        '''                             '''
        ...
    def applicableFileFormats (self, val : str)-> list :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbFileFormatManager :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbFileFormatManager :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...

    @staticmethod
    def getManager (db: PyDb.Database)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def openManager (db: PyDb.Database,mode: PyDb.OpenMode)-> PyBrxCv.CvDbFileFormatManager :
        '''                             '''
        ...

class CvDbGrading(CvDbEntity):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbGrading :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbGrading :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def getCalculationCurve (self)-> PyGe.Curve3d :
        '''                             '''
        ...
    def getCalculationMethod (self)-> PyBrxCv.GradingCalculationMethod :
        '''                             '''
        ...
    def getGradingVisualStyle (self)-> PyBrxCv.GradingVisualStyle :
        '''                             '''
        ...
    def getInputEntityId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def getIsAssociative (self)-> bool :
        '''                             '''
        ...
    def getIsDrawInfill (self)-> bool :
        '''                             '''
        ...
    def getMidOrdinateDist (self)-> float :
        '''                             '''
        ...
    def getRegionEnd (self)-> float :
        '''                             '''
        ...
    def getRegionStart (self)-> float :
        '''                             '''
        ...
    def getSegmentMaxAngle (self)-> float :
        '''                             '''
        ...
    def getSegmentMaxLength (self)-> float :
        '''                             '''
        ...
    def isClosed (self)-> bool :
        '''                             '''
        ...
    def resultDayLight (self)-> list :
        '''                             '''
        ...
    def rule (self)-> PyBrxCv.CvGradingRule :
        '''                             '''
        ...
    def setCalculationMethod (self, val : PyBrxCv.GradingCalculationMethod)-> bool :
        '''                             '''
        ...
    def setDrawInfill (self, val : bool)-> PyBrxCv.GradingStatus :
        '''                             '''
        ...
    def setGradingVisualStyle (self, val : PyBrxCv.GradingVisualStyle)-> bool :
        '''                             '''
        ...
    def setInputData (self, curve: PyGe.Curve3d)-> PyBrxCv.GradingStatus :
        '''                             '''
        ...
    def setInputDataId (self, id : PyDb.ObjectId)-> PyBrxCv.GradingStatus :
        '''                             '''
        ...
    def setIsAssociative (self, val : bool)-> bool :
        '''                             '''
        ...
    def setMidOrdinateDist (self, val : float)-> PyBrxCv.GradingStatus :
        '''                             '''
        ...
    def setRegionEnd (self, val : float)-> PyBrxCv.GradingStatus :
        '''                             '''
        ...
    def setRegionStart (self, val : float)-> PyBrxCv.GradingStatus :
        '''                             '''
        ...
    def setRule (self, val : PyBrxCv.CvGradingRule)-> PyBrxCv.GradingStatus :
        '''                             '''
        ...
    def setSegmentMaxAngle (self, val : float)-> PyBrxCv.GradingStatus :
        '''                             '''
        ...
    def setSegmentMaxLength (self, val : float)-> PyBrxCv.GradingStatus :
        '''                             '''
        ...
    def targetSurface (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def update (self, val : bool)-> PyBrxCv.GradingStatus :
        '''                             '''
        ...

class CvDbHAlignment(CvDbCurve):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...
    def addArcAuto (self, prevId: int, nextId: int)-> int :
        '''                             '''
        ...

    @overload
    def addArcBetween (self, prevId: int, nextId: int, passThroughPoint: PyGe.Point2d)-> int : ...
    @overload
    def addArcBetween (self, prevId: int, nextId: int, parameter: float, paramType: PyBrxCv.EArcParameterType, isGreaterThan180: bool, arcType: PyBrxCv.ArcType)-> int : ...
    def addArcBetween (self, *args, **kwargs)-> int :
        '''Overloads:
    - prevId: int, nextId: int, passThroughPoint: PyGe.Point2d
    - prevId: int, nextId: int, parameter: float, paramType: PyBrxCv.EArcParameterType, isGreaterThan180: bool, arcType: PyBrxCv.ArcType
    '''
        ...

    @overload
    def addArcFixed (self, center: PyGe.Point2d, radius: float, clockwise: bool)-> int : ...
    @overload
    def addArcFixed (self, startPoint: PyGe.Point2d, midPoint: PyGe.Point2d, endPoint: PyGe.Point2d)-> int : ...
    def addArcFixed (self, *args, **kwargs)-> int :
        '''Overloads:
    - center: PyGe.Point2d, radius: float, clockwise: bool
    - startPoint: PyGe.Point2d, midPoint: PyGe.Point2d, endPoint: PyGe.Point2d
    '''
        ...

    @overload
    def addArcFrom (self, prevId: int, passThroughPoint: PyGe.Point2d)-> int : ...
    @overload
    def addArcFrom (self, prevId: int, passThroughPoint: PyGe.Point2d, direction: PyGe.Vector2d)-> int : ...
    @overload
    def addArcFrom (self, prevId: int, passThroughPoint: PyGe.Point2d, radius: float, isGreaterThan180: bool, arcType: PyBrxCv.ArcType)-> int : ...
    @overload
    def addArcFrom (self, prevId: int, radius: float, paramValue: float, paramType: PyBrxCv.ArcType, isClockwise: bool)-> int : ...
    def addArcFrom (self, *args, **kwargs)-> int :
        '''Overloads:
    - prevId: int, passThroughPoint: PyGe.Point2d
    - prevId: int, passThroughPoint: PyGe.Point2d, direction: PyGe.Vector2d
    - prevId: int, passThroughPoint: PyGe.Point2d, radius: float, isGreaterThan180: bool, arcType: PyBrxCv.ArcType
    - prevId: int, radius: float, paramValue: float, paramType: PyBrxCv.ArcType, isClockwise: bool
    '''
        ...

    @overload
    def addArcTo (self, nextId: int, passThroughPoint: PyGe.Point2d)-> int : ...
    @overload
    def addArcTo (self, nextId: int, passThroughPoint: PyGe.Point2d, direction: PyGe.Vector2d)-> int : ...
    @overload
    def addArcTo (self, nextId: int, passThroughPoint: PyGe.Point2d, radius: float, isGreaterThan180: bool, arcType: PyBrxCv.ArcType)-> int : ...
    @overload
    def addArcTo (self, nextId: int, radius: float, paramValue: float, paramType: PyBrxCv.ArcType, isClockwise: bool)-> int : ...
    def addArcTo (self, *args, **kwargs)-> int :
        '''Overloads:
    - nextId: int, passThroughPoint: PyGe.Point2d
    - nextId: int, passThroughPoint: PyGe.Point2d, direction: PyGe.Vector2d
    - nextId: int, passThroughPoint: PyGe.Point2d, radius: float, isGreaterThan180: bool, arcType: PyBrxCv.ArcType
    - nextId: int, radius: float, paramValue: float, paramType: PyBrxCv.ArcType, isClockwise: bool
    '''
        ...
    def addCSSTo (self, nextId: int, spiral1Param: float, spiral2Param: float, spiralParamType, radius: float, passThroughPoint: PyGe.Point2d, spiralDef : PyBrxCv.SpiralDefinitionType)-> int :
        '''                             '''
        ...

    @overload
    def addCSTo (self, nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  passThroughPoint: PyGe.Point2d, isGreaterThan180: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType)-> int : ...
    @overload
    def addCSTo (self, nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  arcLength: float, isClockwise: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType)-> int : ...
    def addCSTo (self, *args, **kwargs)-> int :
        '''Overloads:
    - nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  passThroughPoint: PyGe.Point2d, isGreaterThan180: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType
    - nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  arcLength: float, isClockwise: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType
    '''
        ...
    def addLineBetween (self, prevId: int, nextId: int)-> int :
        '''                             '''
        ...

    @overload
    def addLineFixed (self, prevId : int, length: float)-> int : ...
    @overload
    def addLineFixed (self, start: PyGe.Point2d, end: PyGe.Point2d)-> int : ...
    def addLineFixed (self, *args, **kwargs)-> int :
        '''Overloads:
    - prevId : int, length: float
    - start: PyGe.Point2d, end: PyGe.Point2d
    '''
        ...

    @overload
    def addLineFrom (self, prevId : int, length: float)-> int : ...
    @overload
    def addLineFrom (self, prevId : int, to: PyGe.Point2d)-> int : ...
    def addLineFrom (self, *args, **kwargs)-> int :
        '''Overloads:
    - prevId : int, length: float
    - prevId : int, to: PyGe.Point2d
    '''
        ...

    @overload
    def addLineTo (self, nextId : int, length: float)-> int : ...
    @overload
    def addLineTo (self, nextId : int, to: PyGe.Point2d)-> int : ...
    def addLineTo (self, *args, **kwargs)-> int :
        '''Overloads:
    - nextId : int, length: float
    - nextId : int, to: PyGe.Point2d
    '''
        ...

    @overload
    def addSCFrom (self, prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  passThroughPoint: PyGe.Point2d, isGreaterThan180: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType)-> int : ...
    @overload
    def addSCFrom (self, prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  arcLength: float, isClockwise: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType)-> int : ...
    def addSCFrom (self, *args, **kwargs)-> int :
        '''Overloads:
    - prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  passThroughPoint: PyGe.Point2d, isGreaterThan180: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType
    - prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, radius: float,  arcLength: float, isClockwise: bool, spiralDefinition: PyBrxCv.SpiralDefinitionType
    '''
        ...
    def addSCSAuto (self, prevId: int, nextId: int)-> int :
        '''                             '''
        ...
    def addSCSBetween (self, prevId: int, nextId: int, spiral1: float, spiral2: float, spiralType: PyBrxCv.SpiralParameterType, radius: float, spiralDef: PyBrxCv.SpiralDefinitionType)-> int :
        '''                             '''
        ...
    def addSSBetween (self, prevId: int, nextId: int, spiralRatio: float, spiralParamType : PyBrxCv.SpiralParameterType, spiralDef : PyBrxCv.SpiralDefinitionType)-> int :
        '''                             '''
        ...
    def addSSCFrom (self, prevId: int, spiral1Param: float, spiral2Param: float, spiralParamType, radius: float, passThroughPoint: PyGe.Point2d, spiralDef : PyBrxCv.SpiralDefinitionType)-> int :
        '''                             '''
        ...

    @overload
    def addSTFrom (self, prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, passThroughPoint: PyGe.Point2d,  spiralDefinition: PyBrxCv.SpiralDefinitionType)-> int : ...
    @overload
    def addSTFrom (self, prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, tangentLength: float,  spiralDefinition: PyBrxCv.SpiralDefinitionType)-> int : ...
    def addSTFrom (self, *args, **kwargs)-> int :
        '''Overloads:
    - prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, passThroughPoint: PyGe.Point2d,  spiralDefinition: PyBrxCv.SpiralDefinitionType
    - prevId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, tangentLength: float,  spiralDefinition: PyBrxCv.SpiralDefinitionType
    '''
        ...
    def addSTSBetween (self, prevId: int, nextId: int, spiral1Param: float, spiral2Param: float, spiralType : PyBrxCv.SpiralParameterType, spiralDef : PyBrxCv.SpiralDefinitionType)-> int :
        '''                             '''
        ...
    def addSpiralBetween (self, prevId: int, nextId: int, spiralDef: PyBrxCv.SpiralDefinitionType)-> int :
        '''                             '''
        ...
    def addSpiralFrom (self, prevId: int, radius: float, length: float, isClockwise: bool, spiralDef : PyBrxCv.SpiralDefinitionType)-> int :
        '''                             '''
        ...
    def addSpiralTo (self, nextId: int, radius: float, length: float, isClockwise: bool, spiralDef : PyBrxCv.SpiralDefinitionType)-> int :
        '''                             '''
        ...

    @overload
    def addTSTo (self, nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, passThroughPoint: PyGe.Point2d,  spiralDefinition: PyBrxCv.SpiralDefinitionType)-> int : ...
    @overload
    def addTSTo (self, nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, tangentLength: float,  spiralDefinition: PyBrxCv.SpiralDefinitionType)-> int : ...
    def addTSTo (self, *args, **kwargs)-> int :
        '''Overloads:
    - nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, passThroughPoint: PyGe.Point2d,  spiralDefinition: PyBrxCv.SpiralDefinitionType
    - nextId: int, spiralParam: float, spiralParamType: PyBrxCv.EArcParameterType, tangentLength: float,  spiralDefinition: PyBrxCv.SpiralDefinitionType
    '''
        ...
    def alignment3dAt (self, index: int)-> PyDb.ObjectId :
        '''                             '''
        ...
    def alignment3dCount (self)-> int :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignment :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignment :
        '''                             '''
        ...
    def curveAtPI (self, pi: PyBrxCv.CvDbHAlignmentPI)-> int :
        '''                             '''
        ...
    def curveElementColor (self)-> int :
        '''                             '''
        ...
    def deleteElement (self, id: int)-> bool :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def elementAtId (self, Id: int)-> PyBrxCv.CvDbHAlignmentElement :
        '''                             '''
        ...
    def elementAtStation (self, station: float)-> PyBrxCv.CvDbHAlignmentElement :
        '''                             '''
        ...
    def elementCount (self)-> int :
        '''                             '''
        ...
    def elementExtensionColor (self)-> int :
        '''                             '''
        ...
    def firstElementId (self)-> int :
        '''                             '''
        ...
    def firstLineElementId (self)-> int :
        '''                             '''
        ...
    def getElementId (self, gsMarker: int)-> int :
        '''                             '''
        ...
    def getPIsArray (self)-> list :
        '''                             '''
        ...
    def getPointAtStation (self, station: float)-> tuple[Any,...] :
        '''                             '''
        ...
    def getRadius (self, param: float)-> float :
        '''                             '''
        ...

    @overload
    def getStationAtPoint (self, station: PyGe.Point2d)-> tuple[Any,...] : ...
    @overload
    def getStationAtPoint (self, station: PyGe.Point2d,fromStation: float, toStation: float)-> tuple[Any,...] : ...
    def getStationAtPoint (self, *args, **kwargs)-> tuple[Any,...] :
        '''Overloads:
    - station: PyGe.Point2d
    - station: PyGe.Point2d,fromStation: float, toStation: float
    '''
        ...
    def getUnorderedElementIds (self)-> list :
        '''                             '''
        ...
    def insertLineFixed (self, start: PyGe.Point2d, end: PyGe.Point2d, prevId: int)-> int :
        '''                             '''
        ...
    def lastElementId (self)-> int :
        '''                             '''
        ...
    def length (self)-> float :
        '''                             '''
        ...
    def lineElementColor (self)-> int :
        '''                             '''
        ...
    def nextLineElementId (self, Id: int)-> int :
        '''                             '''
        ...
    def previousLineElementId (self, Id: int)-> int :
        '''                             '''
        ...
    def setCurveElementColor (self, colACI: int)-> bool :
        '''                             '''
        ...
    def setElementExtensionColor (self, colACI: int)-> bool :
        '''                             '''
        ...
    def setLineElementColor (self, colACI: int)-> bool :
        '''                             '''
        ...
    def setSpiralElementColor (self, colACI: int)-> bool :
        '''                             '''
        ...
    def setStationEquations (self, val: PyBrxCv.CvStationEquations)-> bool :
        '''                             '''
        ...
    def setStyle (self, style: int)-> bool :
        '''                             '''
        ...
    def setTangentExtensionColor (self, colACI: int)-> bool :
        '''                             '''
        ...
    def spiralElementColor (self)-> int :
        '''                             '''
        ...
    def stationEquations (self)-> PyBrxCv.CvStationEquations :
        '''                             '''
        ...
    def style (self)-> int :
        '''                             '''
        ...
    def tangentExtensionColor (self)-> int :
        '''                             '''
        ...
    def update (self)-> bool :
        '''                             '''
        ...
    def verticalAlignmentAt (self, index: int)-> PyDb.ObjectId :
        '''                             '''
        ...
    def verticalAlignmentCount (self)-> int :
        '''                             '''
        ...
    def verticalAlignmentViewAt (self, index: int)-> PyDb.ObjectId :
        '''                             '''
        ...
    def verticalAlignmentViewCount (self)-> int :
        '''                             '''
        ...

class CvDbHAlignmentArc(CvDbHAlignmentCurve):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentArc :
        '''                             '''
        ...
    def center (self)-> PyGe.Point2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def isClockwise (self)-> bool :
        '''                             '''
        ...
    def isCompound (self)-> bool :
        '''                             '''
        ...
    def isLessThan180 (self)-> bool :
        '''                             '''
        ...
    def paramLength (self)-> float :
        '''                             '''
        ...
    def passThroughPoint1 (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def passThroughPoint2 (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def passThroughPoint3 (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def radius (self)-> float :
        '''                             '''
        ...
    def setCenter (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def setClockwise (self, val : bool)-> bool :
        '''                             '''
        ...
    def setCompound (self, val : bool)-> bool :
        '''                             '''
        ...
    def setLessThan180 (self, val : bool)-> bool :
        '''                             '''
        ...
    def setParamLength (self, val : float)-> bool :
        '''                             '''
        ...
    def setPassThroughPoint1 (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def setPassThroughPoint2 (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def setPassThroughPoint3 (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def setRadius (self, val : float)-> bool :
        '''                             '''
        ...

class CvDbHAlignmentCurve(CvDbHAlignmentElement):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentCurve :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def endPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def endStation (self)-> float :
        '''                             '''
        ...
    def length (self)-> float :
        '''                             '''
        ...
    def startPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def startStation (self)-> float :
        '''                             '''
        ...

class CvDbHAlignmentElement(CvDbSubObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentElement :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def id (self)-> int :
        '''                             '''
        ...
    def isSubentity (self)-> bool :
        '''                             '''
        ...
    def nextId (self)-> int :
        '''                             '''
        ...
    def parameterConstraint (self)-> PyBrxCv.HAlignmentParameterConstraint :
        '''                             '''
        ...
    def previousId (self)-> int :
        '''                             '''
        ...
    def setNextId (self, val : int)-> bool :
        '''                             '''
        ...
    def setParameterConstraint (self, val : PyBrxCv.EParameterConstraint)-> bool :
        '''                             '''
        ...
    def setPreviousId (self, val : int)-> bool :
        '''                             '''
        ...
    def setTangencyConstraint (self, val : PyBrxCv.ETangencyConstraint)-> bool :
        '''                             '''
        ...
    def tangencyConstraint (self)-> PyBrxCv.HAlignmentTangencyConstraint :
        '''                             '''
        ...
    def type (self)-> PyBrxCv.HAlignmentElementType :
        '''                             '''
        ...

class CvDbHAlignmentLine(CvDbHAlignmentCurve):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentLine :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def paramLength (self)-> float :
        '''                             '''
        ...
    def passThroughPoint1 (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def passThroughPoint2 (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def setParamLength (self, val : float)-> bool :
        '''                             '''
        ...
    def setPassThroughPoint1 (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def setPassThroughPoint2 (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...

class CvDbHAlignmentPI(CvDbHAlignmentElement):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentPI :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def location (self)-> PyGe.Point2d :
        '''                             '''
        ...

class CvDbHAlignmentSCS(CvDbHAlignmentCurve):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def arc (self)-> PyBrxCv.CvDbHAlignmentArc :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentSCS :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def spiralIn (self)-> PyBrxCv.CvDbHAlignmentSpiral :
        '''                             '''
        ...
    def spiralOut (self)-> PyBrxCv.CvDbHAlignmentSpiral :
        '''                             '''
        ...

class CvDbHAlignmentSSCSS(CvDbHAlignmentCurve):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def arc (self)-> PyBrxCv.CvDbHAlignmentArc :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentSSCSS :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def spiral1 (self)-> PyBrxCv.CvDbHAlignmentSpiral :
        '''                             '''
        ...
    def spiral2 (self)-> PyBrxCv.CvDbHAlignmentSpiral :
        '''                             '''
        ...
    def spiral3 (self)-> PyBrxCv.CvDbHAlignmentSpiral :
        '''                             '''
        ...
    def spiral4 (self)-> PyBrxCv.CvDbHAlignmentSpiral :
        '''                             '''
        ...

class CvDbHAlignmentSTS(CvDbHAlignmentCurve):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentSTS :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def line (self)-> PyBrxCv.CvDbHAlignmentLine :
        '''                             '''
        ...
    def spiralIn (self)-> PyBrxCv.CvDbHAlignmentSpiral :
        '''                             '''
        ...
    def spiralOut (self)-> PyBrxCv.CvDbHAlignmentSpiral :
        '''                             '''
        ...
    def spiralRatio (self)-> float :
        '''                             '''
        ...

class CvDbHAlignmentSpiral(CvDbHAlignmentCurve):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentSpiral :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def endDirection (self)-> float :
        '''                             '''
        ...
    def isCompound (self)-> bool :
        '''                             '''
        ...
    def paramA (self)-> float :
        '''                             '''
        ...
    def paramLength (self)-> float :
        '''                             '''
        ...
    def radiusIn (self)-> float :
        '''                             '''
        ...
    def radiusOut (self)-> float :
        '''                             '''
        ...
    def setClockwise (self, val : bool)-> bool :
        '''                             '''
        ...
    def setCompound (self, val : float)-> bool :
        '''                             '''
        ...
    def setEndDirection (self, val : float)-> bool :
        '''                             '''
        ...
    def setParamA (self, val : float)-> bool :
        '''                             '''
        ...
    def setParamLength (self, val : float)-> bool :
        '''                             '''
        ...
    def setRadiusIn (self, val : float)-> bool :
        '''                             '''
        ...
    def setRadiusOut (self, val : float)-> bool :
        '''                             '''
        ...
    def setSpiralCurveType (self, val : PyBrxCv.ESpiralCurveType)-> bool :
        '''                             '''
        ...
    def setSpiralDefinition (self, val : PyBrxCv.ESpiralDefinitionType)-> bool :
        '''                             '''
        ...
    def spiralCurveType (self)-> PyBrxCv.SpiralCurveType :
        '''                             '''
        ...
    def spiralDefinition (self)-> PyBrxCv.SpiralDefinitionTypeSpiral :
        '''                             '''
        ...
    def startDirection (self)-> float :
        '''                             '''
        ...

class CvDbLabelStyle(CvDbStyle):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def addComponent (self, val: PyBrxCv.CvDbLabelStyleComponent)-> None :
        '''                             '''
        ...
    def componentCount (self)-> int :
        '''                             '''
        ...
    def draggedStateBackgroundMask (self)-> bool :
        '''                             '''
        ...
    def draggedStateBorderAndLeaderGap (self)-> float :
        '''                             '''
        ...
    def draggedStateBorderAndLeaderGapExprIndex (self)-> int :
        '''                             '''
        ...
    def draggedStateBorderIsVisible (self)-> bool :
        '''                             '''
        ...
    def draggedStateBorderType (self)-> PyBrxCv.BorderType :
        '''                             '''
        ...
    def draggedStateColor (self)-> PyDb.Color :
        '''                             '''
        ...
    def draggedStateDisplayMode (self)-> PyBrxCv.DisplayMode :
        '''                             '''
        ...
    def draggedStateLeaderArrowHeadSize (self)-> float :
        '''                             '''
        ...
    def draggedStateLeaderArrowHeadSizeExprIndex (self)-> int :
        '''                             '''
        ...
    def draggedStateLeaderArrowHeadStyle (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def draggedStateLeaderAttachment (self)-> PyBrxCv.LeaderAttachment :
        '''                             '''
        ...
    def draggedStateLeaderColor (self)-> PyDb.Color :
        '''                             '''
        ...
    def draggedStateLeaderIsVisible (self)-> bool :
        '''                             '''
        ...
    def draggedStateLeaderJustification (self)-> bool :
        '''                             '''
        ...
    def draggedStateLeaderLinetype (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def draggedStateLeaderLineweight (self)-> PyDb.LineWeight :
        '''                             '''
        ...
    def draggedStateLeaderTail (self)-> bool :
        '''                             '''
        ...
    def draggedStateLeaderType (self)-> PyBrxCv.LeaderType :
        '''                             '''
        ...
    def draggedStateLinetype (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def draggedStateLineweight (self)-> PyDb.LineWeight :
        '''                             '''
        ...
    def draggedStateMaximumTextWidth (self)-> float :
        '''                             '''
        ...
    def draggedStateMaximumTextWidthExprIndex (self)-> int :
        '''                             '''
        ...
    def draggedStateTagDisplayMode (self)-> bool :
        '''                             '''
        ...
    def draggedStateTextHeight (self)-> float :
        '''                             '''
        ...
    def draggedStateTextHeightExprIndex (self)-> int :
        '''                             '''
        ...
    def expressionAt (self, index: int)-> tuple[Any,...] :
        '''                             '''
        ...
    def expressionCount (self)-> int :
        '''                             '''
        ...
    def flipAnchorsWithText (self)-> bool :
        '''                             '''
        ...
    def forceInsideCurve (self)-> bool :
        '''                             '''
        ...
    def forcedInsertion (self)-> PyBrxCv.ForcedInsertion :
        '''                             '''
        ...
    def isVisible (self)-> bool :
        '''                             '''
        ...
    def layer (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def moveComponent (self, _from: int, _to:int)-> None :
        '''                             '''
        ...
    def orientationReference (self)-> PyBrxCv.OrientationRef :
        '''                             '''
        ...
    def planReadable (self)-> bool :
        '''                             '''
        ...
    def readabilityBias (self)-> float :
        '''                             '''
        ...
    def removeComponent_1 (self, *args, **kwargs)-> None :
        '''removeComponent_1( (CvDbLabelStyle)arg1, (CvDbLabelStyleComponent)arg2) -> None :

    C++ signature :
        void removeComponent_1(class PyBrxCvDbLabelStyle {lvalue},class PyBrxCvDbLabelStyleComponent)'''
        ...
    def removeComponent_2 (self, val: int|PyBrxCv.CvDbLabelStyleComponent)-> None :
        '''                             '''
        ...
    def setDraggedStateBackgroundMask (self, val: bool)-> None :
        '''                             '''
        ...
    def setDraggedStateBorderAndLeaderGap (self, val: float)-> None :
        '''                             '''
        ...
    def setDraggedStateBorderAndLeaderGapExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setDraggedStateBorderType (self, val: BorderType)-> None :
        '''                             '''
        ...
    def setDraggedStateBorderVisibility (self, val: bool)-> None :
        '''                             '''
        ...
    def setDraggedStateColor (self, val: AcCmColor)-> None :
        '''                             '''
        ...
    def setDraggedStateDisplayMode (self, val: DisplayMode)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderArrowHeadSize (self, val: float)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderArrowHeadSizeExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderArrowHeadStyle (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderAttachment (self, val: LeaderAttachment)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderColor (self, val: AcCmColor)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderJustification (self, val: bool)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderLinetype (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderLineweight (self, val: PyDb.LineWeight)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderTail (self, val: bool)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderType (self, val: LeaderType)-> None :
        '''                             '''
        ...
    def setDraggedStateLeaderVisibility (self, val: bool)-> None :
        '''                             '''
        ...
    def setDraggedStateLinetype (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setDraggedStateLineweight (self, val: PyDb.LineWeight)-> None :
        '''                             '''
        ...
    def setDraggedStateMaximumTextWidth (self, val: float)-> None :
        '''                             '''
        ...
    def setDraggedStateMaximumTextWidthExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setDraggedStateTagDisplayMode (self, val: bool)-> None :
        '''                             '''
        ...
    def setDraggedStateTextHeight (self, val: float)-> None :
        '''                             '''
        ...
    def setDraggedStateTextHeightExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setExpressionAt (self, val: int, val:str, val:str, val:BrxCvDataType)-> None :
        '''                             '''
        ...
    def setFlipAnchorsWithText (self, val: bool)-> None :
        '''                             '''
        ...
    def setForceInsideCurve (self, val: bool)-> None :
        '''                             '''
        ...
    def setForcedInsertion (self, val: ForcedInsertion)-> None :
        '''                             '''
        ...
    def setLayer (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setOrientationReference (self, val: PyBrxCv.OrientationRef)-> None :
        '''                             '''
        ...
    def setPlanReadable (self, val: bool)-> None :
        '''                             '''
        ...
    def setReadabilityBias (self, val: float)-> None :
        '''                             '''
        ...
    def setTextStyle (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setVisibility (self, val: bool)-> None :
        '''                             '''
        ...
    def textStyle (self)-> PyDb.ObjectId :
        '''                             '''
        ...

class CvDbLabelStyleArrow(CvDbLabelStyleComponent):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def angle (self)-> float :
        '''                             '''
        ...
    def angleExprIndex (self)-> int :
        '''                             '''
        ...
    def arrowHeadSize (self)-> float :
        '''                             '''
        ...
    def arrowHeadStyle (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def isFixedLength (self)-> bool :
        '''                             '''
        ...
    def length (self)-> float :
        '''                             '''
        ...
    def lengthExprIndex (self)-> int :
        '''                             '''
        ...
    def linetype (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def lineweight (self)-> PyDb.LineWeight :
        '''                             '''
        ...
    def offset (self)-> PyGe.Vector2d :
        '''                             '''
        ...
    def setAngle (self, val: float)-> None :
        '''                             '''
        ...
    def setAngleExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setArrowHeadSize (self, val: float)-> None :
        '''                             '''
        ...
    def setArrowHeadSizeExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setArrowHeadStyle (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setFixedLength (self, val: bool)-> None :
        '''                             '''
        ...
    def setLength (self, val: float)-> None :
        '''                             '''
        ...
    def setLengthExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setLinetype (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setLineweight (self, val: PyDb.LineWeight)-> None :
        '''                             '''
        ...
    def setOffset (self, val: AcGeVector2d)-> None :
        '''                             '''
        ...

class CvDbLabelStyleBlock(CvDbLabelStyleComponent):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def angle (self)-> float :
        '''                             '''
        ...
    def angleExprIndex (self)-> int :
        '''                             '''
        ...
    def attachment (self)-> PyBrxCv.BlockAttachment :
        '''                             '''
        ...
    def blockId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def height (self)-> float :
        '''                             '''
        ...
    def heightExprIndex (self)-> int :
        '''                             '''
        ...
    def linetype (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def lineweight (self)-> PyDb.LineWeight :
        '''                             '''
        ...
    def offset (self)-> PyGe.Vector2d :
        '''                             '''
        ...
    def setAngle (self, val: float)-> None :
        '''                             '''
        ...
    def setAngleExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setAttachment (self, attachment: PyBrxCv.BlockAttachment)-> None :
        '''                             '''
        ...
    def setBlockId (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setHeight (self, val: float)-> None :
        '''                             '''
        ...
    def setHeightExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setLinetype (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setLineweight (self, lineWeight: PyDbLineWeight)-> None :
        '''                             '''
        ...
    def setOffset (self, val: AcGeVector2d)-> None :
        '''                             '''
        ...

class CvDbLabelStyleComponent(CvDbSubObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def anchorIndex (self)-> int :
        '''                             '''
        ...
    def anchorPoint (self)-> PyBrxCv.LabelAnchor :
        '''                             '''
        ...
    def color (self)-> PyDb.Color :
        '''                             '''
        ...
    def displaySetting (self)-> bool :
        '''                             '''
        ...
    def setAnchorIndex (self, val : int)-> None :
        '''                             '''
        ...
    def setAnchorPoint (self, val : PyBrxCv.LabelAnchor)-> None :
        '''                             '''
        ...
    def setColor (self, clr: PyDb.Color)-> None :
        '''                             '''
        ...
    def setVisible (self, val: bool)-> None :
        '''                             '''
        ...

class CvDbLabelStyleLine(CvDbLabelStyleComponent):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def angle (self)-> float :
        '''                             '''
        ...
    def angleExprIndex (self)-> int :
        '''                             '''
        ...
    def endPointAnchorIndex (self)-> int :
        '''                             '''
        ...
    def endPointAnchorPoint (self)-> PyBrxCv.LabelAnchor :
        '''                             '''
        ...
    def endPointOffset (self)-> PyGe.Vector2d :
        '''                             '''
        ...
    def length (self)-> float :
        '''                             '''
        ...
    def lengthExprIndex (self)-> int :
        '''                             '''
        ...
    def lengthPercentage (self)-> float :
        '''                             '''
        ...
    def lengthPercentageExprIndex (self)-> int :
        '''                             '''
        ...
    def lengthType (self)-> PyBrxCv.LengthType :
        '''                             '''
        ...
    def linetype (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def lineweight (self)-> PyDb.LineWeight :
        '''                             '''
        ...
    def setAngle (self, val: float)-> None :
        '''                             '''
        ...
    def setAngleExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setEndPointAnchorIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setEndPointAnchorPoint (self,  val : PyBrxCv.LabelAnchor)-> None :
        '''                             '''
        ...
    def setEndPointOffset (self, val: AcGeVector2d)-> None :
        '''                             '''
        ...
    def setLength (self, val: float)-> None :
        '''                             '''
        ...
    def setLengthExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setLengthPercentage (self, val: float)-> None :
        '''                             '''
        ...
    def setLengthPercentageExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setLengthType (self,  val : PyBrxCv.LengthType)-> None :
        '''                             '''
        ...
    def setLinetype (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setLineweight (self, id: PyDb.LineWeight)-> None :
        '''                             '''
        ...
    def setStartPointOffset (self, val: AcGeVector2d)-> None :
        '''                             '''
        ...
    def setUseEndPointAnchor (self, val: bool)-> None :
        '''                             '''
        ...
    def startPointOffset (self)-> PyGe.Vector2d :
        '''                             '''
        ...
    def useEndPointAnchor (self)-> bool :
        '''                             '''
        ...

class CvDbLabelStyleText(CvDbLabelStyleComponent):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def allowCurvedText (self)-> bool :
        '''                             '''
        ...
    def borderBackgroudMask (self)-> bool :
        '''                             '''
        ...
    def borderColor (self)-> PyDb.Color :
        '''                             '''
        ...
    def borderGap (self)-> float :
        '''                             '''
        ...
    def borderGapExprIndex (self)-> int :
        '''                             '''
        ...
    def borderIsVisible (self)-> bool :
        '''                             '''
        ...
    def borderLinetype (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def borderLineweight (self, val: PyDb.LineWeight)-> PyDb.LineWeight :
        '''                             '''
        ...
    def borderType (self)-> PyBrxCv.BorderType :
        '''                             '''
        ...
    def contents (self)-> str :
        '''                             '''
        ...
    def setAllowCurvedText (self, val: bool)-> None :
        '''                             '''
        ...
    def setBorderBackgroudMask (self, val: bool)-> None :
        '''                             '''
        ...
    def setBorderColor (self, val: AcCmColor)-> None :
        '''                             '''
        ...
    def setBorderGap (self, val: float)-> None :
        '''                             '''
        ...
    def setBorderGapExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setBorderLinetype (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setBorderLineweight (self)-> None :
        '''                             '''
        ...
    def setBorderType (self, val: BrxCvLabelStyle::BorderType)-> None :
        '''                             '''
        ...
    def setBorderVisibility (self, val: bool)-> None :
        '''                             '''
        ...
    def setContents (self, val: str)-> None :
        '''                             '''
        ...
    def setTextAngle (self, val: float)-> None :
        '''                             '''
        ...
    def setTextAngleExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setTextAttachment (self, val: AcDbMtext::AttachmentPoint)-> None :
        '''                             '''
        ...
    def setTextHeight (self, val: float)-> None :
        '''                             '''
        ...
    def setTextHeightExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setTextHorizontalAlignment (self, val: PyDb.TextHorzMode)-> None :
        '''                             '''
        ...
    def setTextLinetype (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setTextLineweight (self, val: PyDb.LineWeight)-> None :
        '''                             '''
        ...
    def setTextMaximumWidth (self, val: float)-> None :
        '''                             '''
        ...
    def setTextMaximumWidthExprIndex (self, val: int)-> None :
        '''                             '''
        ...
    def setTextOffset (self, val: AcGeVector2d)-> None :
        '''                             '''
        ...
    def textAngle (self)-> float :
        '''                             '''
        ...
    def textAngleExprIndex (self)-> int :
        '''                             '''
        ...
    def textAttachment (self)-> PyDb.MTextAttachmentPoint :
        '''                             '''
        ...
    def textHeight (self)-> float :
        '''                             '''
        ...
    def textHeightExprIndex (self)-> int :
        '''                             '''
        ...
    def textHorizontalAlignment (self)-> PyDb.TextHorzMode :
        '''                             '''
        ...
    def textLinetype (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def textLineweight (self)-> PyDb.LineWeight :
        '''                             '''
        ...
    def textMaximumWidth (self)-> float :
        '''                             '''
        ...
    def textMaximumWidthExprIndex (self)-> int :
        '''                             '''
        ...
    def textOffset (self)-> PyGe.Vector2d :
        '''                             '''
        ...

class CvDbObject(PyDb.DbObject):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbObject :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbObject :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def description (self)-> str :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def setDescription (self, val : str)-> bool :
        '''                             '''
        ...
    def setName (self, val : str)-> bool :
        '''                             '''
        ...

class CvDbObjectManager(CvDbObject):
    def __getitem__ (self, val : int|str)-> PyDb.ObjectId :
        '''                             '''
        ...
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbObjectManager :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbObjectManager :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def elementCount (self)-> int :
        '''                             '''
        ...
    def has1 (self, *args, **kwargs)-> bool :
        '''has1( (CvDbObjectManager)arg1, (ObjectId)arg2) -> bool :

    C++ signature :
        bool has1(class PyBrxCvDbObjectManager {lvalue},class PyDbObjectId)'''
        ...
    def has2 (self, id : str|PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def idAt (self, val : int|str)-> PyDb.ObjectId :
        '''                             '''
        ...
    def ids (self)-> list :
        '''                             '''
        ...
    def nameAt (self, val : int)-> str :
        '''                             '''
        ...
    def remove1 (self)-> bool :
        '''                             '''
        ...
    def remove2 (self, id : str|PyDb.ObjectId)-> bool :
        '''                             '''
        ...

class CvDbPoint(CvDbEntity):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbPoint :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbPoint :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def easting (self)-> float :
        '''                             '''
        ...
    def elevation (self)-> float :
        '''                             '''
        ...
    def fullDescription (self)-> str :
        '''                             '''
        ...
    def isLabelDragged (self)-> bool :
        '''                             '''
        ...
    def isLabelPinned (self)-> bool :
        '''                             '''
        ...
    def labelId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def labelLeaderVertices (self)-> list :
        '''                             '''
        ...
    def labelPosition (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def labelRotation (self)-> float :
        '''                             '''
        ...
    def northing (self)-> float :
        '''                             '''
        ...
    def number (self)-> int :
        '''                             '''
        ...
    def pointGroupsIds (self)-> list :
        '''                             '''
        ...
    def pointGroupsNames (self)-> list :
        '''                             '''
        ...
    def position (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def rawDescription (self)-> str :
        '''                             '''
        ...
    def referencedEntityAt (self, val : int)-> PyBrxCv.CvDbPointReferencedEntity :
        '''                             '''
        ...
    def referencedEntityCount (self)-> int :
        '''                             '''
        ...
    def resetLabel (self)-> bool :
        '''                             '''
        ...
    def setEasting (self, val : float)-> bool :
        '''                             '''
        ...
    def setElevation (self, val : float)-> bool :
        '''                             '''
        ...
    def setLabelId (self, id : PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def setLabelLeaderVertices (self, vertices : list[PyGe.Point3d])-> bool :
        '''                             '''
        ...
    def setLabelPinned (self, val : bool)-> bool :
        '''                             '''
        ...
    def setLabelPosition (self, pt : PyGe.Point3d)-> bool :
        '''                             '''
        ...
    def setLabelRotation (self, val : float)-> bool :
        '''                             '''
        ...
    def setNorthing (self, val : float)-> bool :
        '''                             '''
        ...
    def setNumber (self, val : int)-> bool :
        '''                             '''
        ...
    def setPosition (self, pt : PyGe.Point3d)-> bool :
        '''                             '''
        ...
    def setRawDescription (self, val : str)-> bool :
        '''                             '''
        ...
    def setSymbolId (self, id : PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def setSymbolRotation (self, val : float)-> bool :
        '''                             '''
        ...
    def symbolId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def symbolRotation (self)-> float :
        '''                             '''
        ...
    def update (self)-> bool :
        '''                             '''
        ...

class CvDbPointGroup(CvDbObject):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbPointGroup :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbPointGroup :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def excludeElevations (self, *args, **kwargs)-> str :
        '''excludeElevations( (CvDbPointGroup)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > excludeElevations(class PyBrxCvDbPointGroup {lvalue})'''
        ...
    def excludeFullDescriptions (self)-> str :
        '''                             '''
        ...
    def excludeNames (self)-> str :
        '''                             '''
        ...
    def excludeNumbers (self)-> str :
        '''                             '''
        ...
    def excludeRawDescriptions (self)-> str :
        '''                             '''
        ...
    def excludeUserAttributesKeys (self)-> str :
        '''                             '''
        ...
    def excludeUserAttributesValues (self)-> str :
        '''                             '''
        ...
    def hasPoint (self, val : int)-> PyDb.ObjectId :
        '''                             '''
        ...
    def includeElevations (self)-> str :
        '''                             '''
        ...
    def includeFullDescriptions (self)-> str :
        '''                             '''
        ...
    def includeNames (self)-> str :
        '''                             '''
        ...
    def includeNumbers (self)-> str :
        '''                             '''
        ...
    def includeRawDescriptions (self)-> str :
        '''                             '''
        ...
    def includeUserAttributesKeys (self)-> str :
        '''                             '''
        ...
    def includeUserAttributesValues (self)-> str :
        '''                             '''
        ...
    def isApplicable (self)-> bool :
        '''                             '''
        ...
    def isEditable (self)-> bool :
        '''                             '''
        ...
    def pointCount (self)-> int :
        '''                             '''
        ...
    def pointIds (self)-> list :
        '''                             '''
        ...
    def setExcludeElevations (self, filter : str)-> bool :
        '''                             '''
        ...
    def setExcludeFullDescriptions (self, filter : str)-> bool :
        '''                             '''
        ...
    def setExcludeNames (self, filter : str)-> bool :
        '''                             '''
        ...
    def setExcludeNumbers (self, filter : str)-> bool :
        '''                             '''
        ...
    def setExcludeRawDescriptions (self, filter : str)-> bool :
        '''                             '''
        ...
    def setExcludeUserAttributesKeys (self, filter : str)-> bool :
        '''                             '''
        ...
    def setIncludeElevations (self, filter : str)-> bool :
        '''                             '''
        ...
    def setIncludeFullDescriptions (self, filter : str)-> bool :
        '''                             '''
        ...
    def setIncludeNames (self, filter : str)-> bool :
        '''                             '''
        ...
    def setIncludeNumbers (self, filter : str)-> bool :
        '''                             '''
        ...
    def setIncludeRawDescriptions (self, filter : str)-> bool :
        '''                             '''
        ...
    def setIncludeUserAttributesKeys (self, filter : str)-> bool :
        '''                             '''
        ...
    def setIncludeUserAttributesValues (self, filter : str)-> bool :
        '''                             '''
        ...
    def update (self)-> bool :
        '''                             '''
        ...
    def updateNeeded (self)-> bool :
        '''                             '''
        ...

class CvDbPointGroupManager(CvDbObjectManager):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbPointGroupManager :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbPointGroupManager :
        '''                             '''
        ...
    def createPointGroup (self, val : str)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...

    @staticmethod
    def getManagerId (db: PyDb.Database)-> PyDb.ObjectId :
        '''                             '''
        ...
    def groupsWithPoint (self, val : int)-> list :
        '''                             '''
        ...
    def nextPointNumber (self)-> int :
        '''                             '''
        ...

    @staticmethod
    def openManager (db: PyDb.Database,mode: PyDb.OpenMode)-> PyBrxCv.CvDbPointGroupManager :
        '''                             '''
        ...
    def setNextPointNumber (self, val : int)-> bool :
        '''                             '''
        ...
    def updatePointGroups (self)-> int :
        '''                             '''
        ...

class CvDbPointReferencedEntity(CvDbSubObject):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbPointReferencedEntity :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def id (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def setId (self, id : PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def type (self)-> PyRx.RxClass :
        '''                             '''
        ...

class CvDbStyle(CvDbObject):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbObject :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbObject :
        '''                             '''
        ...
    def createdBy (self)-> str :
        '''                             '''
        ...
    def createdDate (self)-> PyDb.Date :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def displaySetting (self, orientation: PyBrxCv.DisplayOrientation, partName: str)-> PyBrxCv.CvDbStylePartDisplaySettings :
        '''                             '''
        ...
    def displaySettings (self, orientation: PyBrxCv.DisplayOrientation)-> list :
        '''                             '''
        ...
    def lastEditedBy (self)-> str :
        '''                             '''
        ...
    def lastEditedDate (self)-> PyDb.Date :
        '''                             '''
        ...
    def setCreatedBy (self, filter : str)-> None :
        '''                             '''
        ...

class CvDbStyleManager(CvDbObjectManager):
    def __init__ (self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbStyleManager :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbStyleManager :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...

    @staticmethod
    def getManager (db: PyDb.Database,styleType: PyBrxCv.StyleManagerType)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def openManager (db: PyDb.Database,mode: PyDb.OpenMode,styleType: PyBrxCv.StyleManagerType)-> PyBrxCv.CvDbObjectManager :
        '''                             '''
        ...

class CvDbStylePartDisplaySettings(CvDbSubObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...
    def color (self)-> PyDb.Color :
        '''                             '''
        ...
    def displaySetting (self)-> bool :
        '''                             '''
        ...
    def layer (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def lineType (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def lineTypeScale (self)-> float :
        '''                             '''
        ...
    def lineWeight (self)-> PyDb.LineWeight :
        '''                             '''
        ...
    def plotStyleNameId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def plotStyleNameType (self)-> PyDb.PlotStyleNameType :
        '''                             '''
        ...
    def setColor (self, clr: PyDb.Color)-> None :
        '''                             '''
        ...
    def setLayer (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setLineType (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setLineTypeScale (self, val: float)-> None :
        '''                             '''
        ...
    def setLineWeight (self, val: PyDb.LineWeight)-> None :
        '''                             '''
        ...
    def setPlotStyleNameId (self, id: PyDb.ObjectId)-> None :
        '''                             '''
        ...
    def setPlotStyleNameType (self, val: PyDb.PlotStyleNameType)-> None :
        '''                             '''
        ...
    def setVisible (self, val: bool)-> None :
        '''                             '''
        ...

class CvDbSubObject(PyRx.RxObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbSubObject :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def description (self)-> str :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def setDescription (self, val : str)-> bool :
        '''                             '''
        ...
    def setName (self, val : str)-> bool :
        '''                             '''
        ...

class CvDbTinSurface(CvDbEntity):
    def __init__ (self, id: PyDb.ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...
    def addConstraint (self, constraint : PyBrxCv.CvDbTinSurfaceConstraint, addReactor : bool)-> bool :
        '''                             '''
        ...
    def addConstraints (self, constraints : list[PyBrxCv.CvDbTinSurfaceConstraint], addReactor : bool)-> bool :
        '''                             '''
        ...
    def addDefinition (self, ref : PyBrxCv.CvDbTinSurfaceDefinition)-> int :
        '''                             '''
        ...
    def addPoint (self, pt : PyGe.Point3d)-> bool :
        '''                             '''
        ...
    def addPoints (self, pts : list[PyGe.Point3d])-> bool :
        '''                             '''
        ...
    def area2d (self, visibleOnly : bool=False)-> float :
        '''                             '''
        ...
    def area3d (self, visibleOnly : bool=False)-> float :
        '''                             '''
        ...
    def boundingBox (self)-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurface :
        '''                             '''
        ...
    def changePointsElevations (self, pts : list[PyGe.Point3d], newZValues : list[float])-> bool :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurface :
        '''                             '''
        ...
    def closestPointTo (self, pt : PyGe.Point3d)-> PyGe.Point3d :
        '''                             '''
        ...
    def contains (self, pt : PyGe.Point3d)-> bool :
        '''                             '''
        ...
    def contoursAtElevation (self, elevation : float)-> list :
        '''                             '''
        ...
    def createSnapshot (self)-> int :
        '''                             '''
        ...
    def definitionAt (self, index : int)-> PyBrxCv.CvDbTinSurfaceDefinition :
        '''                             '''
        ...
    def definitionCount (self)-> int :
        '''                             '''
        ...
    def definitionIndex (self, ref : PyBrxCv.CvDbTinSurfaceDefinition)-> tuple[Any,...] :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def drapeId (self, id : PyDb.ObjectId)-> list :
        '''                             '''
        ...
    def drapePoints (self, pts : list[PyGe.Point3d])-> list :
        '''                             '''
        ...
    def elevationAtPoint (self, pt : PyGe.Point3d)-> tuple[Any,...] :
        '''                             '''
        ...
    def eraseConstraint (self, id : PyDb.ObjectId | int, removeReactor : bool)-> bool :
        '''                             '''
        ...
    def eraseConstraints (self, int64ids : list[int], removeReactor : bool)-> bool :
        '''                             '''
        ...
    def eraseConstraintsIds (self, ids : list[PyDb.ObjectId], removeReactor : bool)-> bool :
        '''                             '''
        ...
    def findDefinition (self, id : int)-> PyBrxCv.CvDbTinSurfaceDefinition :
        '''                             '''
        ...
    def findTinPointAt (self, pt : PyGe.Point3d)-> tuple[Any,...] :
        '''                             '''
        ...
    def findTinTrianglesAt (self, pt : PyGe.Point3d)-> list :
        '''                             '''
        ...
    def getBorders (self)-> list :
        '''                             '''
        ...
    def getConstraint (self, id : PyDb.ObjectId|int)-> PyBrxCv.CvDbTinSurfaceConstraint :
        '''                             '''
        ...
    def getConstraints (self)-> list :
        '''                             '''
        ...
    def getPoints (self, visibleOnly : bool=False)-> list :
        '''                             '''
        ...
    def getPointsInsidePolygon (self, pts : list[PyGe.Point3d], includeOnEdge : bool)-> list :
        '''                             '''
        ...
    def getTinPoints (self)-> list :
        '''                             '''
        ...
    def hasSnapshot (self)-> bool :
        '''                             '''
        ...
    def initialize (self, min : PyGe.Point3d, max : PyGe.Point3d, numOfPoints : int)-> None :
        '''                             '''
        ...
    def insertDefinitionAt (self, index : int, ref : PyBrxCv.CvDbTinSurfaceDefinition)-> int :
        '''                             '''
        ...
    def intersectionsWithLine (self, start : PyGe.Point3d, end : PyGe.Point3d, type : PyBrxCv.TinSurfaceIntersectType, visibleOnly : bool)-> tuple[Any,...] :
        '''                             '''
        ...
    def isAssociative (self)-> bool :
        '''                             '''
        ...
    def isAutoUpdate (self)-> bool :
        '''                             '''
        ...
    def isRebuildPossible (self)-> bool :
        '''                             '''
        ...
    def isSnapshotUpdateNeeded (self)-> bool :
        '''                             '''
        ...
    def isUpdateNeeded (self)-> bool :
        '''                             '''
        ...
    def majorContours (self)-> list :
        '''                             '''
        ...
    def majorContoursColor (self)-> tuple[Any,...] :
        '''                             '''
        ...
    def majorContoursInterval (self)-> tuple[Any,...] :
        '''                             '''
        ...
    def maxElevation (self, visibleOnly : bool=False)-> float :
        '''                             '''
        ...
    def merge (self, other : PyBrxCv.CvDbTinSurface)-> bool :
        '''                             '''
        ...

    @staticmethod
    def mergeSurfaces (theOne: PyBrxCv.CvDbTinSurface,theOther: PyBrxCv.CvDbTinSurface)-> PyBrxCv.CvDbTinSurface :
        '''                             '''
        ...
    def minElevation (self, visibleOnly : bool=False)-> float :
        '''                             '''
        ...
    def minorContours (self)-> list :
        '''                             '''
        ...
    def minorContoursColor (self)-> tuple[Any,...] :
        '''                             '''
        ...
    def minorContoursInterval (self)-> tuple[Any,...] :
        '''                             '''
        ...
    def moveDefinition (self, _from : int, _to : int)-> int :
        '''                             '''
        ...
    def movePoint (self, _from : PyGe.Point3d, _to : PyGe.Point3d)-> bool :
        '''                             '''
        ...
    def movePoints (self, _from : list[PyGe.Point3d], _to : list[PyGe.Point3d])-> bool :
        '''                             '''
        ...
    def pointsCount (self, visibleOnly : bool=False)-> int :
        '''                             '''
        ...
    def raiseSurface (self, offset : float)-> bool :
        '''                             '''
        ...
    def rebuild (self, val : bool)-> bool :
        '''                             '''
        ...
    def rebuildSnapshot (self)-> bool :
        '''                             '''
        ...
    def removeAllDefinitions (self)-> int :
        '''                             '''
        ...
    def removeDefinitionAt (self, index: int)-> bool :
        '''                             '''
        ...
    def removePoint (self, pt : PyGe.Point3d)-> bool :
        '''                             '''
        ...
    def removePoints (self, pts : list[PyGe.Point3d])-> bool :
        '''                             '''
        ...
    def removeSnapshot (self)-> bool :
        '''                             '''
        ...
    def setAssociative (self, isAssociative : bool)-> bool :
        '''                             '''
        ...
    def setIsAutoUpdate (self, autoUpdateOn : bool)-> bool :
        '''                             '''
        ...
    def setMajorContoursColor (self, colorIndex : int)-> bool :
        '''                             '''
        ...
    def setMajorContoursInterval (self, interval : float)-> bool :
        '''                             '''
        ...
    def setMinorContoursColor (self, colorIndex : int)-> bool :
        '''                             '''
        ...
    def setMinorContoursInterval (self, interval : float)-> bool :
        '''                             '''
        ...
    def setStyle (self, style : PyBrxCv.TinSurfaceStyle)-> bool :
        '''                             '''
        ...
    def setSurfaceElevation (self, elevation : float)-> bool :
        '''                             '''
        ...

    @overload
    def solid3d (self, surface: PyBrxCv.CvDbTinSurface)-> PyDb.Solid3d : ...
    @overload
    def solid3d (self, surfaceType: PyBrxCv.TinSurfaceMeshType, thickness: float)-> PyDb.Solid3d : ...
    def solid3d (self, *args, **kwargs)-> PyDb.Solid3d :
        '''Overloads:
    - surface: PyBrxCv.CvDbTinSurface
    - surfaceType: PyBrxCv.TinSurfaceMeshType, thickness: float 
    '''
        ...
    def style (self)-> PyBrxCv.TinSurfaceStyle :
        '''                             '''
        ...

    @overload
    def subDMesh (self, /)-> PyDb.SubDMesh : ...
    @overload
    def subDMesh (self, surface: PyBrxCv.CvDbTinSurface)-> PyDb.SubDMesh : ...
    @overload
    def subDMesh (self, surfaceType: PyBrxCv.TinSurfaceMeshType, depthOrElevation: float)-> PyDb.SubDMesh : ...
    def subDMesh (self, *args, **kwargs)-> PyDb.SubDMesh :
        '''Overloads:
    - None: Any
    - surface: PyBrxCv.CvDbTinSurface
    - surfaceType: PyBrxCv.TinSurfaceMeshType, depthOrElevation: float 
    '''
        ...
    def swapEdge (self, pt : PyGe.Point3d)-> bool :
        '''                             '''
        ...
    def tinTriangles (self)-> list :
        '''                             '''
        ...
    def triangles (self, visibleOnly : bool=False)-> list :
        '''                             '''
        ...
    def trianglesCount (self, visibleOnly : bool=False)-> int :
        '''                             '''
        ...
    def updateConstraint (self, val : PyBrxCv.CvDbTinSurfaceConstraint)-> bool :
        '''                             '''
        ...
    def updateObjectData (self)-> None :
        '''                             '''
        ...

class CvDbTinSurfaceBoundary(CvDbTinSurfaceConstraint):
    def __init__ (self, type: PyBrxCv.TinBoundaryType)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def wallType (self)-> PyBrxCv.TinBoundaryType :
        '''                             '''
        ...

class CvDbTinSurfaceBreakline(CvDbTinSurfaceConstraint):
    def __init__ (self, type: PyBrxCv.TinBreaklineType)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def intersectionElevation (self)-> PyBrxCv.BreaklineIntersectionElevation :
        '''                             '''
        ...
    def setIntersectionElevation (self, val : PyBrxCv.TinBreaklineType)-> None :
        '''                             '''
        ...

class CvDbTinSurfaceConstraint(object):
    def __init__ (self, type: PyBrxCv.TinConstraintType)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def constraintType (self)-> PyBrxCv.TinConstraintType :
        '''                             '''
        ...
    def data (self)-> list :
        '''                             '''
        ...
    def id (self)-> int :
        '''                             '''
        ...
    def isDbResident (self)-> bool :
        '''                             '''
        ...
    def midOrdinateDistance (self)-> float :
        '''                             '''
        ...
    def setData (self, intId : int, pts : list[PyGe.Point3d])-> None :
        '''                             '''
        ...
    def setDataId (self, id : PyDb.ObjectId, midOrdinateDist : float)-> None :
        '''                             '''
        ...
    def setIsDbResident (self, val : bool)-> None :
        '''                             '''
        ...
    def setMidOrdinateDistance (self, val : float)-> None :
        '''                             '''
        ...

class CvDbTinSurfaceDefinition(CvDbSubObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinition :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def description (self)-> str :
        '''                             '''
        ...
    def id (self)-> int :
        '''                             '''
        ...
    def isEnabled (self)-> bool :
        '''                             '''
        ...
    def isReadOnly (self)-> bool :
        '''                             '''
        ...
    def isSubDefinition (self)-> bool :
        '''                             '''
        ...
    def isUpdateNeeded (self)-> bool :
        '''                             '''
        ...
    def isValid (self)-> bool :
        '''                             '''
        ...
    def name (self)-> str :
        '''                             '''
        ...
    def setDescription (self, desc : str)-> bool :
        '''                             '''
        ...
    def setEnabled (self, val : bool)-> bool :
        '''                             '''
        ...
    def setName (self, name : str)-> bool :
        '''                             '''
        ...
    def setReadOnly (self, val : bool)-> bool :
        '''                             '''
        ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionAddDrawingObjects(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2, (float)arg3, (bool)arg4, (TinIntersectionElevation)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,double,bool,enum BrxCvDbTinSurfaceDefinitionAddDrawingObjects::ETinIntersectionElevation)'''
        ...
    def addEntity (self, entity: PyDb.Entity)-> bool :
        '''                             '''
        ...
    def addEntityId (self, id : PyDb.ObjectId)-> bool :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionAddDrawingObjects :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def crossingsElevation (self)-> PyBrxCv.TinIntersectionElevation :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def drawingObjectAt (self, idx : int)-> tuple[Any,...] :
        '''                             '''
        ...
    def drawingObjectsCount (self)-> int :
        '''                             '''
        ...
    def isApplyEdges (self)-> bool :
        '''                             '''
        ...
    def removeAllDrawingObjects (self)-> bool :
        '''                             '''
        ...
    def removeDrawingObjectAt (self, idx : int)-> bool :
        '''                             '''
        ...
    def setCrossingsElevation (self, val : PyBrxCv.TinIntersectionElevation)-> bool :
        '''                             '''
        ...
    def setIsApplyEdges (self, val : bool)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionAddFromFiles(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2, (ObjectId)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class PyDbObjectId)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionAddFromFiles :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def fileFormatId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def filesPaths (self)-> list :
        '''                             '''
        ...
    def setFileFormatId (self, id : PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def setFilesPaths (self, val : list[str])-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionAddFromPointClouds(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionAddFromPointClouds :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def pcObjectIds (self)-> list :
        '''                             '''
        ...
    def setPcObjectIds (self, val : list[PyDb.ObjectId])-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionAddLine(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (object)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGeLineSeg2d)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionAddLine :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def line (self)-> PyGe.LineSeg2d :
        '''                             '''
        ...
    def setLine (self, line : PyGe.LineSeg2d)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionAddLines(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionAddLines :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def lines (self)-> list :
        '''                             '''
        ...
    def setLines (self, lines : list[PyGe.LineSeg2d])-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionAddPoint(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionAddPoint :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def position (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def setPosition (self, pt : PyGe.Point3d)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionAddPointGroups(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionAddPointGroups :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def pointGroupsIds (self)-> list :
        '''                             '''
        ...
    def setPointGroupsIds (self, val : list[PyDb.ObjectId])-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionAddPoints(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionAddPoints :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def positions (self)-> list :
        '''                             '''
        ...
    def setPositions (self, pt : list[PyGe.Point3d])-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionCreateFromC3D(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (str)arg2, (str)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionCreateFromC3D :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def filePath (self)-> str :
        '''                             '''
        ...
    def setFilePath (self, val : str)-> bool :
        '''                             '''
        ...
    def setSurfaceName (self, val : str)-> bool :
        '''                             '''
        ...
    def surfaceName (self)-> str :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionCreateFromFaces(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2, (bool)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,bool)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionCreateFromFaces :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def faceAt (self, *args, **kwargs)-> tuple[Any,...] :
        '''faceAt( (CvDbTinSurfaceDefinitionCreateFromFaces)arg1, (SubentType)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple faceAt(class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces {lvalue},unsigned long)'''
        ...
    def facesCount (self, *args, **kwargs)-> int :
        '''facesCount( (CvDbTinSurfaceDefinitionCreateFromFaces)arg1) -> int :

    C++ signature :
        unsigned long facesCount(class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces {lvalue})'''
        ...
    def isApplyEdgesVisibility (self, *args, **kwargs)-> bool :
        '''isApplyEdgesVisibility( (CvDbTinSurfaceDefinitionCreateFromFaces)arg1) -> bool :

    C++ signature :
        bool isApplyEdgesVisibility(class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces {lvalue})'''
        ...
    def points (self, *args, **kwargs)-> list :
        '''points( (CvDbTinSurfaceDefinitionCreateFromFaces)arg1) -> list :

    C++ signature :
        class boost::python::list points(class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces {lvalue})'''
        ...
    def setIsApplyEdgesVisibility (self, *args, **kwargs)-> bool :
        '''setIsApplyEdgesVisibility( (CvDbTinSurfaceDefinitionCreateFromFaces)arg1, (bool)arg2) -> bool :

    C++ signature :
        bool setIsApplyEdgesVisibility(class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces {lvalue},bool)'''
        ...

class CvDbTinSurfaceDefinitionCreateFromLandXML(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (str)arg2, (str)arg3, (UnitsValue)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,enum AcDb::UnitsValue,bool)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionCreateFromLandXML :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def dwgUnits (self)-> PyDb.UnitsValue :
        '''                             '''
        ...
    def filePath (self)-> str :
        '''                             '''
        ...
    def scaleToDwgUnits (self)-> bool :
        '''                             '''
        ...
    def setFilePath (self, val : str)-> bool :
        '''                             '''
        ...
    def setScaleToDwgUnits (self, val : bool)-> bool :
        '''                             '''
        ...
    def setSurfaceName (self, val : str)-> bool :
        '''                             '''
        ...
    def surfaceName (self)-> str :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionDeleteEdge(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionDeleteEdge :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def position (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def setPosition (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionDeleteEdges(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...
    def addPolygon (self, edgePolygon : list[PyGe.Point2d], includeIntersected : bool)-> bool :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionDeleteEdges :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def polygonAt (self, index : int)-> tuple[Any,...] :
        '''                             '''
        ...
    def polygonsCount (self)-> int :
        '''                             '''
        ...
    def removeAllPolygons (self)-> bool :
        '''                             '''
        ...
    def removePolygonAt (self, index : int)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionDeletePoint(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionDeletePoint :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def position (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def setPosition (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionGroupDefs(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...
    def addSubDefinition (self, val : PyBrxCv.CvDbTinSurfaceDefinition)-> int :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionGroupDefs :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def findSubDefinition (self, defid : int)-> int :
        '''                             '''
        ...
    def getSubDefinitionAt (self, index : int)-> PyBrxCv.CvDbTinSurfaceDefinition :
        '''                             '''
        ...
    def numSubDefinitions (self)-> int :
        '''                             '''
        ...
    def removeSubDefinitionAt (self, index : int)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionModifyPointElevation(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (float)arg3, (bool)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,double,bool)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionModifyPointElevation :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def elevation (self)-> float :
        '''                             '''
        ...
    def isDeltaElevation (self)-> bool :
        '''                             '''
        ...
    def position (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def setElevation (self, val : float)-> bool :
        '''                             '''
        ...
    def setIsDeltaElevation (self, val : float)-> bool :
        '''                             '''
        ...
    def setPosition (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionModifyPointsElevation(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2, (float)arg3, (bool)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,double,bool)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionModifyPointsElevation :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def elevation (self)-> float :
        '''                             '''
        ...
    def isDeltaElevation (self)-> bool :
        '''                             '''
        ...
    def positions (self)-> list :
        '''                             '''
        ...
    def setElevation (self, val : float)-> bool :
        '''                             '''
        ...
    def setPositions (self, pt : list[PyGe.Point2d])-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionModifyPointsElevations(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...
    def addPointElevation (self, *args, **kwargs)-> bool :
        '''addPointElevation( (CvDbTinSurfaceDefinitionModifyPointsElevations)arg1, (Point2d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool addPointElevation(class PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations {lvalue},class AcGePoint2d,double)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionModifyPointsElevations :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def pointElevationAt (self, *args, **kwargs)-> tuple[Any,...] :
        '''pointElevationAt( (CvDbTinSurfaceDefinitionModifyPointsElevations)arg1, (SubentType)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple pointElevationAt(class PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations {lvalue},unsigned long)'''
        ...
    def pointElevationsCount (self, *args, **kwargs)-> int :
        '''pointElevationsCount( (CvDbTinSurfaceDefinitionModifyPointsElevations)arg1) -> int :

    C++ signature :
        unsigned long pointElevationsCount(class PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations {lvalue})'''
        ...
    def removeAllPointElevations (self, *args, **kwargs)-> bool :
        '''removeAllPointElevations( (CvDbTinSurfaceDefinitionModifyPointsElevations)arg1) -> bool :

    C++ signature :
        bool removeAllPointElevations(class PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations {lvalue})'''
        ...
    def removePointElevationAt (self, *args, **kwargs)-> bool :
        '''removePointElevationAt( (CvDbTinSurfaceDefinitionModifyPointsElevations)arg1, (SubentType)arg2) -> bool :

    C++ signature :
        bool removePointElevationAt(class PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations {lvalue},unsigned long)'''
        ...

class CvDbTinSurfaceDefinitionMovePoint(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionMovePoint :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def fromPosition (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def setFromPosition (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def setToPosition (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def toPosition (self)-> PyGe.Point2d :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionMovePoints(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeVector2d)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionMovePoints :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def displacement (self)-> PyGe.Vector2d :
        '''                             '''
        ...
    def fromPoints (self)-> list :
        '''                             '''
        ...
    def setDisplacement (self, vec : PyGe.Vector3d)-> bool :
        '''                             '''
        ...
    def setFromPoints (self, pt : list[PyGe.Point2d])-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionRemoveElevations(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (bool)arg2, (float)arg3, (bool)arg4, (float)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,bool,double,bool,double)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionRemoveElevations :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def removeAbove (self)-> bool :
        '''                             '''
        ...
    def removeAboveElevation (self)-> float :
        '''                             '''
        ...
    def removeBelow (self)-> bool :
        '''                             '''
        ...
    def removeBelowElevation (self)-> float :
        '''                             '''
        ...
    def removedPointsCount (self)-> int :
        '''                             '''
        ...
    def setRemoveAbove (self, val : bool)-> bool :
        '''                             '''
        ...
    def setRemoveAboveElevation (self, val : float)-> bool :
        '''                             '''
        ...
    def setRemoveBelow (self, val : bool)-> bool :
        '''                             '''
        ...
    def setRemoveBelowElevation (self, val : float)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionRemoveOuterEdges(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (bool)arg2, (float)arg3, (bool)arg4, (float)arg5, (bool)arg6, (float)arg7) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,bool,double,bool,double,bool,double)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionRemoveOuterEdges :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def maxAdjAngle (self)-> float :
        '''                             '''
        ...
    def maxEdgeLength (self)-> float :
        '''                             '''
        ...
    def minEdgeLength (self)-> float :
        '''                             '''
        ...
    def setMaxAdjAngle (self, val : float)-> bool :
        '''                             '''
        ...
    def setMaxEdgeLength (self, val : float)-> bool :
        '''                             '''
        ...
    def setMinEdgeLength (self, val : float)-> bool :
        '''                             '''
        ...
    def setUseMaxAdjAngle (self, val : bool)-> bool :
        '''                             '''
        ...
    def setUseMaxEdgeLength (self, val : bool)-> bool :
        '''                             '''
        ...
    def setUseMinEdgeLength (self, val : bool)-> bool :
        '''                             '''
        ...
    def useMaxAdjAngle (self)-> bool :
        '''                             '''
        ...
    def useMaxEdgeLength (self)-> bool :
        '''                             '''
        ...
    def useMinEdgeLength (self)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionRiseLower(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (float)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionRiseLower :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def offset (self)-> float :
        '''                             '''
        ...
    def setOffset (self, val : float)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionSwapEdge(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionSwapEdge :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def position (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def setPosition (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionTransform(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Matrix3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGeMatrix3d)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionTransform :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def setTransformationMatrix (self, xform : PyGe.Matrix3d)-> bool :
        '''                             '''
        ...
    def transformationMatrix (self)-> PyGe.Matrix3d :
        '''                             '''
        ...

class CvDbTinSurfaceDefinitionTrianglesVisibility(CvDbTinSurfaceDefinition):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2, (bool)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,bool)'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurfaceDefinitionTrianglesVisibility :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def positions (self)-> list :
        '''                             '''
        ...
    def setPositions (self, val : list[PyGe.Point2d])-> bool :
        '''                             '''
        ...
    def setVisible (self, val : bool)-> bool :
        '''                             '''
        ...
    def visible (self)-> bool :
        '''                             '''
        ...

class CvDbTinSurfaceWall(CvDbTinSurfaceConstraint):
    def __init__ (self, type: PyBrxCv.TinWallType)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def setHeight (self, val : float)-> None :
        '''                             '''
        ...
    def setWallSide (self, val : PyBrxCv.TinWallSide)-> None :
        '''                             '''
        ...
    def wallSide (self)-> PyBrxCv.TinWallSide :
        '''                             '''
        ...
    def wallType (self)-> PyBrxCv.TinWallType :
        '''                             '''
        ...

class CvDbVAlignment(CvDbCurve):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...
    def addArcAuto (self, prevId: int, nextId: int)-> int :
        '''                             '''
        ...
    def addArcBetween (self, prevId: int, nextId: int, radius: float)-> int :
        '''                             '''
        ...
    def addParabolaAuto (self, prevId: int, nextId: int)-> int :
        '''                             '''
        ...
    def addParabolaBetween (self, prevId: int, nextId: int, radius: float)-> int :
        '''                             '''
        ...
    def addTangentFixed (self, startPoint: PyGe.Point2d, endPoint: PyGe.Point2d)-> int :
        '''                             '''
        ...
    def baseHAlignment (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def baseSurface (self)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignment :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignment :
        '''                             '''
        ...
    def curveAtPVI (self, pvi: PyBrxCv.CvDbVAlignmentPVI)-> int :
        '''                             '''
        ...
    def curveElementColor (self)-> int :
        '''                             '''
        ...
    def deleteElement (self, id: int)-> bool :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def elementAtId (self, id: int)-> PyBrxCv.CvDbVAlignmentElement :
        '''                             '''
        ...
    def elementCount (self)-> int :
        '''                             '''
        ...
    def elevationMax (self)-> float :
        '''                             '''
        ...
    def elevationMin (self)-> float :
        '''                             '''
        ...
    def firstElementId (self)-> int :
        '''                             '''
        ...
    def firstTangentElementId (self)-> int :
        '''                             '''
        ...
    def getElementId (self, gsMarker: int)-> int :
        '''                             '''
        ...
    def getElevationAt (self, station: float)-> tuple[Any,...] :
        '''                             '''
        ...
    def getElevations (self)-> list :
        '''                             '''
        ...
    def getPVIsArrays (self)-> list :
        '''                             '''
        ...
    def getRadius (self, param: float)-> float :
        '''                             '''
        ...
    def getUnorderedElementIds (self)-> list :
        '''                             '''
        ...
    def insertTangentFixed (self, startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, val: int)-> int :
        '''                             '''
        ...
    def lastElementId (self)-> int :
        '''                             '''
        ...
    def length (self)-> float :
        '''                             '''
        ...
    def lineElementColor (self)-> int :
        '''                             '''
        ...
    def nextTangentElementId (self, id: int)-> int :
        '''                             '''
        ...
    def previousTangentElementId (self, id: int)-> int :
        '''                             '''
        ...
    def pviAtCurve (self, curve: PyBrxCv.CvDbVAlignmentCurve)-> PyBrxCv.CvDbVAlignmentPVI :
        '''                             '''
        ...
    def setBaseHAlignment (self, id: PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def setBaseSurface (self, id: PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def setCurveElementColor (self, val: int)-> bool :
        '''                             '''
        ...
    def setLineElementColor (self, val: int)-> bool :
        '''                             '''
        ...
    def setStyle (self, val: int)-> bool :
        '''                             '''
        ...
    def setTangentPolygonColor (self, val: int)-> bool :
        '''                             '''
        ...
    def setType (self, val: VAlignmentType)-> bool :
        '''                             '''
        ...
    def style (self)-> int :
        '''                             '''
        ...
    def tangentPolygonColor (self)-> int :
        '''                             '''
        ...
    def type (self)-> PyBrxCv.VAlignmentType :
        '''                             '''
        ...
    def update (self, updateDependencies: bool)-> bool :
        '''                             '''
        ...

class CvDbVAlignmentArc(CvDbVAlignmentCurve):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentArc :
        '''                             '''
        ...
    def center (self)-> PyGe.Point2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def gradeIn (self)-> float :
        '''                             '''
        ...
    def gradeOut (self)-> float :
        '''                             '''
        ...
    def isClockwise (self)-> bool :
        '''                             '''
        ...
    def radius (self)-> float :
        '''                             '''
        ...
    def setCenter (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def setClockwise (self, val : bool)-> bool :
        '''                             '''
        ...
    def setRadius (self, val : float)-> bool :
        '''                             '''
        ...

class CvDbVAlignmentCurve(CvDbVAlignmentElement):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentCurve :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def endPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def length (self)-> float :
        '''                             '''
        ...
    def startPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...

class CvDbVAlignmentElement(CvDbSubObject):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentElement :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def id (self)-> int :
        '''                             '''
        ...
    def nextId (self)-> int :
        '''                             '''
        ...
    def parameterConstraint (self)-> PyBrxCv.VAlignmentParameterConstraint :
        '''                             '''
        ...
    def previousId (self)-> int :
        '''                             '''
        ...
    def setNextId (self, val : int)-> bool :
        '''                             '''
        ...
    def setParameterConstraint (self, val : PyBrxCv.VAlignmentParameterConstraint)-> bool :
        '''                             '''
        ...
    def setPreviousId (self, val : int)-> bool :
        '''                             '''
        ...
    def setTangencyConstraint (self, val : PyBrxCv.VAlignmentTangencyConstraint)-> bool :
        '''                             '''
        ...
    def tangencyConstraint (self)-> PyBrxCv.VAlignmentTangencyConstraint :
        '''                             '''
        ...
    def type (self)-> PyBrxCv.VAlignmentElementType :
        '''                             '''
        ...

class CvDbVAlignmentPVI(CvDbVAlignmentElement):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentPVI :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def location (self)-> PyGe.Point2d :
        '''                             '''
        ...

class CvDbVAlignmentParabola(CvDbVAlignmentCurve):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentParabola :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def gradeIn (self)-> float :
        '''                             '''
        ...
    def gradeOut (self)-> float :
        '''                             '''
        ...
    def radius (self)-> float :
        '''                             '''
        ...
    def setRadius (self, val : float)-> bool :
        '''                             '''
        ...

class CvDbVAlignmentTangent(CvDbVAlignmentCurve):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentTangent :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def passThroughPoint1 (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def passThroughPoint2 (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def setPassThroughPoint1 (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def setPassThroughPoint2 (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...

class CvDbVAlignmentView(CvDbView):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentView :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentView :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def update (self, bUpdateDependencies : bool=True, updateOrigin : bool=True)-> bool :
        '''                             '''
        ...

class CvDbView(CvDbEntity):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...
    def addGraph (self, id : PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def baseElevation (self)-> float :
        '''                             '''
        ...
    def baseHAlignment (self)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbView :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbView :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def fromWCSPoint2d (self, pt : PyGe.Point2d)-> PyGe.Point2d :
        '''                             '''
        ...
    def fromWCSX (self, val : float)-> float :
        '''                             '''
        ...
    def fromWCSY (self, val : float)-> float :
        '''                             '''
        ...
    def graphAt (self, val : int)-> PyDb.ObjectId :
        '''                             '''
        ...
    def graphCount (self)-> int :
        '''                             '''
        ...
    def height (self)-> float :
        '''                             '''
        ...
    def horizontalScale (self)-> float :
        '''                             '''
        ...
    def length (self)-> float :
        '''                             '''
        ...
    def origin (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def removeGraph (self, id: PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def setBaseElevation (self, val : float)-> bool :
        '''                             '''
        ...
    def setBaseHAlignment (self, id : PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def setHeight (self, val : float)-> bool :
        '''                             '''
        ...
    def setHorizontalScale (self, val : float)-> bool :
        '''                             '''
        ...
    def setLength (self, val : float)-> bool :
        '''                             '''
        ...
    def setOrigin (self, pt : PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def setVerticalScale (self, val : float)-> bool :
        '''                             '''
        ...
    def toWCSPoint2d (self, pt : PyGe.Point2d)-> PyGe.Point2d :
        '''                             '''
        ...
    def toWCSX (self, val : float)-> float :
        '''                             '''
        ...
    def toWCSY (self, val : float)-> float :
        '''                             '''
        ...
    def verticalScale (self)-> float :
        '''                             '''
        ...

class CvDbVolumeSurface(CvDbTinSurface):
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=PyDb.OpenMode.kForRead, erased: bool=False)-> None :
        '''                             '''
        ...
    def baseSurfaceObjectId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def boundingPolygon (self)-> list :
        '''                             '''
        ...
    def boundingPolygonObjectId (self)-> PyDb.ObjectId :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVolumeSurface :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVolumeSurface :
        '''                             '''
        ...
    def comparisonSurfaceObjectId (self)-> PyDb.ObjectId :
        '''                             '''
        ...
    def cutVolume (self)-> float :
        '''                             '''
        ...
    def depthElevation (self)-> float :
        '''                             '''
        ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
        '''Returns a pointer to the AcRxClass object representing the specific class, or most recent parent class explicitly registered with ObjectARX of either the pointer type used to invoke it or the class qualifier used with it. (Remember that when a static member function is invoked via a pointer, the pointer type, not the object type, determines which implementation of the function is invoked.)When working with a pointer to an object and the proper AcRxClass object for the class of the object pointed to is desired, the AcRxObject::isA() function should be used, since it is a virtual non-static method and is therefore not pointer type dependent.Caching the value of the pointer returned by this method is acceptable, provided the application knows that the AcRxClass object pointed to by the returned pointer was created by an ObjectARX application that will not be unloaded. '''
        ...
    def fillVolume (self)-> float :
        '''                             '''
        ...

    @overload
    def initialize (self, baseSurface: PyBrxCv.CvDbTinSurface, compSurface: PyBrxCv.CvDbTinSurface, boundingPolygon: list[PyGe.Poin3d])-> bool : ...
    @overload
    def initialize (self, baseSurface: PyBrxCv.CvDbTinSurface, compSurface: PyBrxCv.CvDbTinSurface, boundingPolygon: list[PyGe.Poin3d], midOrdinateDist: float)-> bool : ...
    @overload
    def initialize (self, baseSurface: PyBrxCv.CvDbTinSurface, referenceElevation: float, vType: PyBrxCv.VolumeSurfaceType, boundingPolygon: list[PyGe.Poin3d])-> bool : ...
    @overload
    def initialize (self, baseSurface: PyBrxCv.CvDbTinSurface, referenceElevation: float, vType: PyBrxCv.VolumeSurfaceType, boundingPolygonId: PyDb.ObjectId, midOrdinateDist: float)-> bool : ...
    def initialize (self, *args, **kwargs)-> bool :
        '''Overloads:
    - baseSurface: PyBrxCv.CvDbTinSurface, compSurface: PyBrxCv.CvDbTinSurface, boundingPolygon: list[PyGe.Poin3d]
    - baseSurface: PyBrxCv.CvDbTinSurface, compSurface: PyBrxCv.CvDbTinSurface, boundingPolygon: list[PyGe.Poin3d], midOrdinateDist: float
    - baseSurface: PyBrxCv.CvDbTinSurface, referenceElevation: float, vType: PyBrxCv.VolumeSurfaceType, boundingPolygon: list[PyGe.Poin3d]
    - baseSurface: PyBrxCv.CvDbTinSurface, referenceElevation: float, vType: PyBrxCv.VolumeSurfaceType, boundingPolygonId: PyDb.ObjectId, midOrdinateDist: float
    '''
        ...
    def type (self)-> PyBrxCv.VolumeSurfaceType :
        '''                             '''
        ...

class CvGradingRule(object):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
        ...

    @staticmethod
    def cast (otherObject: PyBrxCv.CvGradingRule)-> PyBrxCv.CvGradingRule :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def convertRadToSlope ()-> float :
        '''                             '''
        ...

    @staticmethod
    def convertSlopeToRad ()-> float :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def release (self)-> bool :
        '''                             '''
        ...
    def setSide (self, format : int)-> bool :
        '''                             '''
        ...
    def setSlopeFormat (self, format : int)-> bool :
        '''                             '''
        ...
    def side (self)-> PyBrxCv.GradingSide :
        '''                             '''
        ...
    def slopeFormat (self)-> PyBrxCv.GradingSlopeFormat :
        '''                             '''
        ...
    def type (self)-> PyBrxCv.GradingType :
        '''                             '''
        ...

class CvGradingSlopeOffsetRule(CvGradingRule):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double)'''
        ...

    @staticmethod
    def cast (otherObject: PyBrxCv.CvGradingRule)-> PyBrxCv.CvGradingSlopeOffsetRule :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def offset (self)-> float :
        '''                             '''
        ...
    def setOffset (self, offset : float)-> bool :
        '''                             '''
        ...
    def setSlope (self, slope : float)-> bool :
        '''                             '''
        ...
    def slope (self)-> float :
        '''                             '''
        ...

class CvGradingSlopeSurfaceRule(CvGradingRule):
    def __init__ (self, *args, **kwargs)-> None :
        '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (ObjectId)arg2, (float)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyDbObjectId,double,double)'''
        ...

    @staticmethod
    def cast (otherObject: PyBrxCv.CvGradingRule)-> PyBrxCv.CvGradingSlopeSurfaceRule :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def cutSlope (self)-> float :
        '''                             '''
        ...
    def fillSlope (self)-> float :
        '''                             '''
        ...
    def setCutSlope (self, val : float)-> bool :
        '''                             '''
        ...
    def setFillSlope (self, val : float)-> bool :
        '''                             '''
        ...
    def setSurfaceId (self, id : PyDb.ObjectId)-> bool :
        '''                             '''
        ...
    def surfaceId (self)-> PyDb.ObjectId :
        '''                             '''
        ...

class CvStationEquation(object):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, rawStation: float, stationForward: float, type: StationEquationType)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - rawStation: float, stationForward: float, type: StationEquationType
    '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getRawStation (self)-> float :
        '''                             '''
        ...
    def getStationForward (self)-> float :
        '''                             '''
        ...
    def getType (self)-> PyBrxCv.StationEquationType :
        '''                             '''
        ...
    def isNull (self)-> bool :
        '''                             '''
        ...
    def setRawStation (self, val : float)-> bool :
        '''                             '''
        ...
    def setStationForward (self, val : float)-> bool :
        '''                             '''
        ...
    def setType (self, val : PyBrxCv.EStationEquationType)-> bool :
        '''                             '''
        ...

class CvStationEquations(object):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, alignment: PyBrxCv.CvDbHAlignment)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - alignment: PyBrxCv.CvDbHAlignment
    '''
        ...
    def addStationEquation (self, equation : PyBrxCv.CvStationEquation)-> bool :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def getLengthFromRawStation (self, rawStation : float)-> float :
        '''                             '''
        ...
    def getRawStation (self, station : float)-> list :
        '''                             '''
        ...
    def getRawStationFromLength (self, length : float)-> float :
        '''                             '''
        ...
    def getRefRawStartingStation (self)-> float :
        '''                             '''
        ...
    def getRefStartingLength (self)-> float :
        '''                             '''
        ...
    def getStartingStation (self)-> float :
        '''                             '''
        ...
    def getStation (self, rawStation : float)-> float :
        '''                             '''
        ...
    def getStationBack (self, idx : int)-> float :
        '''                             '''
        ...
    def getStationEquation (self, idx : int)-> PyBrxCv.CvStationEquation :
        '''                             '''
        ...
    def removeAllStationEquations (self)-> bool :
        '''                             '''
        ...
    def removeStationEquation (self, idx : int)-> bool :
        '''                             '''
        ...
    def setRefRawStartingStation (self, rawStartingStation : float)-> bool :
        '''                             '''
        ...
    def setRefStartingLength (self, startingStation : float)-> bool :
        '''                             '''
        ...
    def stationEquationsCount (self)-> int :
        '''                             '''
        ...
    def update (self, *args, **kwargs)-> bool :
        '''update( (CvStationEquations)arg1) -> bool :

    C++ signature :
        bool update(class PyBrxCvStationEquations {lvalue})'''
        ...

class CvTinPoint(object):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def isValid (self)-> bool :
        '''                             '''
        ...
    def location (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def triangleWithPoint (self)-> PyBrxCv.CvTinTriangle :
        '''                             '''
        ...

class CvTinTriangle(object):
    def __init__ (self)-> None :
        '''                             '''
        ...
    def isValid (self)-> bool :
        '''                             '''
        ...
    def isVisible (self)-> bool :
        '''                             '''
        ...
    def locationAt (self, index: int)-> PyGe.Point3d :
        '''                             '''
        ...
    def neighborAt (self, index: int)-> PyBrxCv.CvTinTriangle :
        '''                             '''
        ...
    def pointAt (self, index: int)-> PyBrxCv.CvTinPoint :
        '''                             '''
        ...

class DisplayMode(object):
    def eDisplayModeAsComposed (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDisplayModeStackedText (self, *args, **kwargs)-> None :
        '''None'''
        ...

class DisplayOrientation(object):
    def eDisplayOrientationModel (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDisplayOrientationPlan (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDisplayOrientationProfile (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDisplayOrientationSection (self, *args, **kwargs)-> None :
        '''None'''
        ...

class DrawingObjectType(object):
    def eBlock (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCivilPoint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eFace (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLine (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePoint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePolyline (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eText (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUnknown (self, *args, **kwargs)-> None :
        '''None'''
        ...

class ForcedInsertion(object):
    def eForcedInsertionBottom (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eForcedInsertionNone (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eForcedInsertionTop (self, *args, **kwargs)-> None :
        '''None'''
        ...

class GradingCalculationMethod(object):
    def eGradingAccurate (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingFast (self, *args, **kwargs)-> None :
        '''None'''
        ...

class GradingSide(object):
    def eGradingSideLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingSideNone (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingSideRight (self, *args, **kwargs)-> None :
        '''None'''
        ...

class GradingSlopeFormat(object):
    def eSlopeDegrees (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSlopeNoFormat (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSlopePercent (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSlopeRadians (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSlopeRiseRun (self, *args, **kwargs)-> None :
        '''None'''
        ...

class GradingStatus(object):
    def eGradingGradingOutsideSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingIncorrectInputData (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingInputDataMissing (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingInputDataOutsideSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingInvalidInput (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingInvalidRule (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingMultipleOffsetResult (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingNoStatus (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingOffsetFailed (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingOk (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingRuleMissing (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingSurfaceMissing (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingTimeout (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingUnknownError (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingUpdateNeeded (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingZeroGrading (self, *args, **kwargs)-> None :
        '''None'''
        ...

class GradingType(object):
    def eGradingTypeNone (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingTypeSlopeOffset (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingTypeSlopeSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...

class GradingVisualStyle(object):
    def eGradingDrawDaylight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingDrawNothing (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingDrawRays (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGradingDrawSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...

class HAlignmentElementType(object):
    def eArc (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCurveCurveReverseCurve (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCurveLineCurve (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCurveReverseCurve (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCurveSpiral (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCurveSpiralSpiral (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLine (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLineSpiral (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMultipleSegments (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePI (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiral (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiralCurve (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiralCurveSpiral (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiralCurveSpiralCurveSpiral (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiralCurveSpiralSpiralCurveSpiral (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiralLine (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiralLineSpiral (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiralSpiral (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiralSpiralCurve (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiralSpiralCurveSpiralSpiral (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUndefined (self, *args, **kwargs)-> None :
        '''None'''
        ...

class HAlignmentParameterConstraint(object):
    def eArc_BestFit (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eArc_CenterPassThrough (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eArc_CenterRadius (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eArc_PassThrough (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eArc_PassThroughAttachToEnd (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eArc_PassThroughDirection (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eArc_PassThroughRadius (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eArc_PointOnTangent (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eArc_Radius (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eArc_RadiusAndLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eArc_ThreePoints (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAutomatic (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLine_BestFit (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLine_Length (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLine_ThroughPoint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLine_TwoPoints (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_PointOnTangent (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralAVal (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralAValRadius (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralAValRadiusArcLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralAValRadiusPassThrough (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralInAValRadiusSpiralOutAVal (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralInAValSpiralOutAVal (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralInLengthSpiralOutLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralInRadiusSpiralOut (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralLengthRadius (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralLengthRadiusArcLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSCS_SpiralLengthRadiusPassThrough (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSSCSS_Sp1AValSp2AValPt1Pt2 (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSSCSS_Sp1AValSp2AValRadiusPt (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSSCSS_Sp1LenSp2LenPt1Pt2 (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSSCSS_Sp1LenSp2LenRadiusPt (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSTS_SpiralAValTangentLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSTS_SpiralAValTangentPassThrough  (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSTS_SpiralInAValSpiralOutAVal (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSTS_SpiralInLengthSpiralOutLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSTS_SpiralLengthTangentLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSTS_SpiralLengthTangentPassThrough (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSTS_TangentLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiral_StartPointDirRadiusLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSpiral_StartPointDirStartAndEndRadiusLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUndefined (self, *args, **kwargs)-> None :
        '''None'''
        ...

class HAlignmentTangencyConstraint(object):
    def eBoth (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eFixed (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNext (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePrevious (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUndefined (self, *args, **kwargs)-> None :
        '''None'''
        ...

class HAlignmentVisualStyle(object):
    def eElementExtensions (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eElements (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTangentExtensions (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUndefined (self, *args, **kwargs)-> None :
        '''None'''
        ...

class LabelAnchor(object):
    def eLabelAnchorBottomCenter (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorBottomLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorBottomRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorCurveCenter (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorCurvePI (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorEnd (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorFeatureLocation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorInsertionPoint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorMiddle (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorMiddleCenter (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorMiddleLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorMiddleRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorStart (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorTopCenter (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorTopLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchorTopRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLabelAnchors (self, *args, **kwargs)-> None :
        '''None'''
        ...

class LeaderAttachment(object):
    def eLeaderAttachmentBottomOfBottomLine (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLeaderAttachmentMiddle (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLeaderAttachmentMiddleOfBottomLine (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLeaderAttachmentMiddleOfTopLine (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLeaderAttachmentTopOfTopLine (self, *args, **kwargs)-> None :
        '''None'''
        ...

class LeaderType(object):
    def eLeaderTypeSpline (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLeaderTypeStraight (self, *args, **kwargs)-> None :
        '''None'''
        ...

class LengthType(object):
    def eLengthTypeFixed (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLengthTypePercentage (self, *args, **kwargs)-> None :
        '''None'''
        ...

class OrientationRef(object):
    def eOrientationReferenceObject (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eOrientationReferenceStartLeaderAtMarker (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eOrientationReferenceView (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eOrientationReferenceWCS (self, *args, **kwargs)-> None :
        '''None'''
        ...

class ScalingType(object):
    def eScalingTypeAbsoluteUnits (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eScalingTypeDrawingScale (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eScalingTypeFixedScale (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eScalingTypeRelativeToScreen (self, *args, **kwargs)-> None :
        '''None'''
        ...

class SpiralCurveType(object):
    def eInCurve (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eOutCurve (self, *args, **kwargs)-> None :
        '''None'''
        ...

class SpiralDefinitionType(object):
    def eClothoid (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCubicParabola (self, *args, **kwargs)-> None :
        '''None'''
        ...

class SpiralDefinitionTypeSpiral(object):
    def eClothoid (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCubicParabola (self, *args, **kwargs)-> None :
        '''None'''
        ...

class SpiralDirectionType(object):
    def eDirectionLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDirectionRight (self, *args, **kwargs)-> None :
        '''None'''
        ...

class SpiralParameterType(object):
    def eClothoid (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCubicParabola (self, *args, **kwargs)-> None :
        '''None'''
        ...

class SpiralParameterType2(object):
    def eParamA (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eParamLength (self, *args, **kwargs)-> None :
        '''None'''
        ...

class StationEquationType(object):
    def Decreasing (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def Increasing (self, *args, **kwargs)-> None :
        '''None'''
        ...

class StyleManagerType(object):
    def eContourLabel (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCurveLabel (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLineLabel (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePointLabel (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSurfaceElevationLabel (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSurfaceSlopeLabel (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSymbolStyle (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinBoundaryType(object):
    def eTinHide (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinOuter (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinShow (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinBreaklineType(object):
    def eTinBreaklineNormal (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinNonDestructive (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinConstraintType(object):
    def eTinBoundary (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinBreakline (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinWall (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinIntersectionElevation(object):
    def eTinElevationMax (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinElevationMid (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinElevationMin (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinNotAllowed (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinSurfaceDefinitionType(object):
    def eAddBoundaries (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAddBreaklines (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAddDrawingObjects (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAddLine (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAddLines (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAddPoint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAddPointClouds (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAddPointFiles (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAddPointGroups (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAddPoints (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAddWalls (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCreateFromC3D (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCreateFromContours (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCreateFromCorridor (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCreateFromFaces (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCreateMerged (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCreateSnapshot (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eCreateTypedSnapshot (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDeform (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDeleteEdge (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDeleteEdges (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDeletePoint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDeletePoints (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eGroupDefinitions (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eIFC (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLandXML (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMerge (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMinimizeFlatAreas (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eModifyPointElevation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eModifyPointsElevation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eModifyPointsElevations (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMovePoint (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eMovePoints (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNone (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eRemoveBelowAboveElevation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eRemoveOuterEdges (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eRiseLower (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSmoothen (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSwapEdge (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTransform (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTrianglesVisibility (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eVolume (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinSurfaceIntersectType(object):
    def eTinSurfaceAll (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinSurfaceFirstOnly (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinSurfaceMeshType(object):
    def eTinSurfaceMeshDepth (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinSurfaceMeshElevation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinSurfaceMeshSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinSurfaceSolidType(object):
    def eSolidTypeSurfaceDepth (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSolidTypeSurfaceElevation (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eSolidTypeSurfaceSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinSurfaceStyle(object):
    def eTinStyleBoundaryLine (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinStyleContours (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinStyleElevationTooltip (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinStyleNone (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinStylePoints (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinStyleTriangles (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinWallSide(object):
    def eTinWallLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinWallRight (self, *args, **kwargs)-> None :
        '''None'''
        ...

class TinWallType(object):
    def eTinWallNormal (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinWallProjected (self, *args, **kwargs)-> None :
        '''None'''
        ...

class VAlignmentElementType(object):
    def eArc (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePVI (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eParabola (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTangent (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUndefined (self, *args, **kwargs)-> None :
        '''None'''
        ...

class VAlignmentParameterConstraint(object):
    def eAngle (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eAutomatic (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLength (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePassThroughPoints (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePointOnTangent (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eRadius (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUndefined (self, *args, **kwargs)-> None :
        '''None'''
        ...

class VAlignmentTangencyConstraint(object):
    def eBoth (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eFixed (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eNext (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def ePrevious (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eUndefined (self, *args, **kwargs)-> None :
        '''None'''
        ...

class VAlignmentType(object):
    def eAutomatic (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eDynamicSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eLayout (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eStaticSurface (self, *args, **kwargs)-> None :
        '''None'''
        ...

class VAlignmentVisualStyle(object):
    def eElements (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eExtensions (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTangents (self, *args, **kwargs)-> None :
        '''None'''
        ...

class VolumeSurfaceType(object):
    def eTinVolumeBaseComparison (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinVolumeToDepth (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def eTinVolumeToElevation (self, *args, **kwargs)-> None :
        '''None'''
        ...
