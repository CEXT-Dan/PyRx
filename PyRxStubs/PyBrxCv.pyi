import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
import PyBrxCv
from typing import overload

class ArcParameterType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class ArcType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eCompound (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eReverse (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Civil3dAlignmentType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Civil3dEntityType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Civil3dLabels:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Civil3dProfileType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class CvCivil3dConverter:
    def __init__ (self, sourceDb: PyDb.Database=None, targetDb: PyDb.Database=None, doLabels: PyBrxCv.Civil3dLabels=eDefaultLabels)-> None :
      '''                             '''
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
    def getCivilEntities (self, *args, **kwargs)-> list :
      '''getCivilEntities( (CvCivil3dConverter)arg1) -> list :

    C++ signature :
        class boost::python::list getCivilEntities(class PyBrxCvCivil3dConverter {lvalue})'''
    ...
    def getInsertedEntities (self, *args, **kwargs)-> list :
      '''getInsertedEntities( (CvCivil3dConverter)arg1) -> list :

    C++ signature :
        class boost::python::list getInsertedEntities(class PyBrxCvCivil3dConverter {lvalue})

getInsertedEntities( (CvCivil3dConverter)arg1) -> list :

    C++ signature :
        class boost::python::list getInsertedEntities(class PyBrxCvCivil3dConverter {lvalue})'''
    ...
    def unattachedLabels (self, *args, **kwargs)-> list :
      '''unattachedLabels( (CvCivil3dConverter)arg1) -> list :

    C++ signature :
        class boost::python::list unattachedLabels(class PyBrxCvCivil3dConverter {lvalue})'''
    ...

class CvCivil3dEntityInfo:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def alignmentType (self, *args, **kwargs)-> PyBrxCv.Civil3dAlignmentType :
      '''alignmentType( (CvCivil3dEntityInfo)arg1) -> Civil3dAlignmentType :

    C++ signature :
        enum BrxCvCivil3dEntityInfo::Civil3dAlignmentType alignmentType(class PyBrxCvCivil3dEntityInfo {lvalue})'''
    ...
    def baseAlignment (self, *args, **kwargs)-> PyBrxCv.CvCivil3dEntityInfo :
      '''baseAlignment( (CvCivil3dEntityInfo)arg1) -> CvCivil3dEntityInfo :

    C++ signature :
        class PyBrxCvCivil3dEntityInfo baseAlignment(class PyBrxCvCivil3dEntityInfo {lvalue})'''
    ...
    def baseSurface (self, *args, **kwargs)-> PyBrxCv.CvCivil3dEntityInfo :
      '''baseSurface( (CvCivil3dEntityInfo)arg1) -> CvCivil3dEntityInfo :

    C++ signature :
        class PyBrxCvCivil3dEntityInfo baseSurface(class PyBrxCvCivil3dEntityInfo {lvalue})'''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def description (self, *args, **kwargs)-> str :
      '''description( (CvCivil3dEntityInfo)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > description(class PyBrxCvCivil3dEntityInfo {lvalue})'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (CvCivil3dEntityInfo)arg1) -> bool :

    C++ signature :
        bool isNull(class PyBrxCvCivil3dEntityInfo {lvalue})'''
    ...
    def name (self, *args, **kwargs)-> str :
      '''name( (CvCivil3dEntityInfo)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > name(class PyBrxCvCivil3dEntityInfo {lvalue})'''
    ...
    def objectId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''objectId( (CvCivil3dEntityInfo)arg1) -> ObjectId :

    C++ signature :
        class PyDbObjectId objectId(class PyBrxCvCivil3dEntityInfo {lvalue})'''
    ...
    def profileType (self, *args, **kwargs)-> PyBrxCv.Civil3dProfileType :
      '''profileType( (CvCivil3dEntityInfo)arg1) -> Civil3dProfileType :

    C++ signature :
        enum BrxCvCivil3dEntityInfo::Civil3dProfileType profileType(class PyBrxCvCivil3dEntityInfo {lvalue})'''
    ...
    def profiles (self, *args, **kwargs)-> list :
      '''profiles( (CvCivil3dEntityInfo)arg1) -> list :

    C++ signature :
        class boost::python::list profiles(class PyBrxCvCivil3dEntityInfo {lvalue})'''
    ...
    def type (self, *args, **kwargs)-> PyBrxCv.Civil3dEntityType :
      '''type( (CvCivil3dEntityInfo)arg1) -> Civil3dEntityType :

    C++ signature :
        enum BrxCvCivil3dEntityInfo::Civil3dEntityType type(class PyBrxCvCivil3dEntityInfo {lvalue})'''
    ...

class CvDb3dAlignment:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def baseHAlignment (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDb3dAlignment :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def close (self)-> None :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def createFromAcGeCurve (curve: PyGe.Curve3d,normal: PyGe.Vector3d = kZAxis,tol: Tol = default)-> PyDb.Curve :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self)-> list :
      '''                             '''
    ...
    def extend (self, *args, **kwargs)-> None :
      '''extend( (Curve)arg1, (float)arg2) -> None :

    C++ signature :
        void extend(class PyDbCurve {lvalue},double)

extend( (Curve)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void extend(class PyDbCurve {lvalue},int,class AcGePoint3d)'''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getAcGeCurve (self, tol: Tol = default)-> PyGe.Curve3d :
      '''                             '''
    ...
    def getArea (self)-> float :
      '''                             '''
    ...
    def getClosestPointTo (self, point3d: PyGe.Point3d, direction: PyGe.Vector3d=None, extend: bool=False)-> PyGe.Point3d :
      '''                             '''
    ...
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getDistAtParam (self, param: float)-> float :
      '''                             '''
    ...
    def getDistAtPoint (self, point3d: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getEndParam (self)-> float :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFirstDeriv (self, param: float|PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def getOffsetCurves (self, dist: float)-> list :
      '''                             '''
    ...
    def getOffsetCurvesGivenPlaneNormal (self, normal: PyGe.Vector3d, dist: float)-> list :
      '''                             '''
    ...
    def getOrthoProjectedCurve (self, plane: PyGe.Plane)-> PyDb.Curve :
      '''                             '''
    ...
    def getParamAtDist (self, dist: float)-> float :
      '''                             '''
    ...
    def getParamAtPoint (self, point3d: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getPointAtDist (self, dist: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def getPointAtParam (self, param: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def getPointsArray (self)-> list :
      '''                             '''
    ...
    def getProjectedCurve (self, plane: PyGe.Plane, projDir: PyGe.Vector3d)-> PyDb.Curve :
      '''                             '''
    ...
    def getSecondDeriv (self, param: float|PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getSpline (self)-> PyDb.Spline :
      '''                             '''
    ...
    def getSplitCurves (self, paramsOrPoints: list)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtParam (self, param: float)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtParams (self, params: list)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtPoint (self, point: PyGe.Point3d)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtPoints (self, points: list)-> list :
      '''                             '''
    ...
    def getStartParam (self)-> float :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isClosed (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPeriodic (self)-> int :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def reverseCurve (self)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setBaseHAlignment (self, id : PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setFromAcGeCurve (self, curve: PyGe.Curve3d, normal: PyGe.Vector3d = kZAxis, tol: Tol = default)-> None :
      '''                             '''
    ...
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setVAlignment (self, id : PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def vAlignment (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbCurve:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbCurve :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def close (self)-> None :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def createFromAcGeCurve (curve: PyGe.Curve3d,normal: PyGe.Vector3d = kZAxis,tol: Tol = default)-> PyDb.Curve :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self)-> list :
      '''                             '''
    ...
    def extend (self, *args, **kwargs)-> None :
      '''extend( (Curve)arg1, (float)arg2) -> None :

    C++ signature :
        void extend(class PyDbCurve {lvalue},double)

extend( (Curve)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void extend(class PyDbCurve {lvalue},int,class AcGePoint3d)'''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getAcGeCurve (self, tol: Tol = default)-> PyGe.Curve3d :
      '''                             '''
    ...
    def getArea (self)-> float :
      '''                             '''
    ...
    def getClosestPointTo (self, point3d: PyGe.Point3d, direction: PyGe.Vector3d=None, extend: bool=False)-> PyGe.Point3d :
      '''                             '''
    ...
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getDistAtParam (self, param: float)-> float :
      '''                             '''
    ...
    def getDistAtPoint (self, point3d: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getEndParam (self)-> float :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFirstDeriv (self, param: float|PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def getOffsetCurves (self, dist: float)-> list :
      '''                             '''
    ...
    def getOffsetCurvesGivenPlaneNormal (self, normal: PyGe.Vector3d, dist: float)-> list :
      '''                             '''
    ...
    def getOrthoProjectedCurve (self, plane: PyGe.Plane)-> PyDb.Curve :
      '''                             '''
    ...
    def getParamAtDist (self, dist: float)-> float :
      '''                             '''
    ...
    def getParamAtPoint (self, point3d: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getPointAtDist (self, dist: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def getPointAtParam (self, param: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def getProjectedCurve (self, plane: PyGe.Plane, projDir: PyGe.Vector3d)-> PyDb.Curve :
      '''                             '''
    ...
    def getSecondDeriv (self, param: float|PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getSpline (self)-> PyDb.Spline :
      '''                             '''
    ...
    def getSplitCurves (self, paramsOrPoints: list)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtParam (self, param: float)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtParams (self, params: list)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtPoint (self, point: PyGe.Point3d)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtPoints (self, points: list)-> list :
      '''                             '''
    ...
    def getStartParam (self)-> float :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isClosed (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPeriodic (self)-> int :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def reverseCurve (self)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setFromAcGeCurve (self, curve: PyGe.Curve3d, normal: PyGe.Vector3d = kZAxis, tol: Tol = default)-> None :
      '''                             '''
    ...
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbEntity:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbEntity :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def close (self)-> None :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self)-> list :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbFileFormatManager:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def allFileFormats (self)-> list :
      '''                             '''
    ...
    def applicableFileFormats (self, val : str)-> list :
      '''                             '''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
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
    def close (self)-> None :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def elementCount (self)-> int :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...

    @staticmethod
    def getManager (db: PyDb.Database)-> PyDb.ObjectId :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
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
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def idAt (self, val : int|str)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ids (self)-> list :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def nameAt (self, val : int)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...

    @staticmethod
    def openManager (db: PyDb.Database,mode: PyDb.OpenMode)-> PyBrxCv.CvDbFileFormatManager :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def remove1 (self)-> bool :
      '''                             '''
    ...
    def remove2 (self, id : str|PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbGrading:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbGrading :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def close (self)-> None :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self)-> list :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getCalculationCurve (self)-> PyGe.Curve3d :
      '''                             '''
    ...
    def getCalculationMethod (self)-> PyBrxCv.GradingCalculationMethod :
      '''                             '''
    ...
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGradingVisualStyle (self)-> PyBrxCv.GradingVisualStyle :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
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
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
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
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isClosed (self)-> bool :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def resultDayLight (self)-> list :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def rule (self)-> PyBrxCv.CvGradingRule :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setCalculationMethod (self, val : PyBrxCv.GradingCalculationMethod)-> bool :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setDrawInfill (self, val : bool)-> PyBrxCv.GradingStatus :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
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
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMidOrdinateDist (self, val : float)-> PyBrxCv.GradingStatus :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
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
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def targetSurface (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def update (self, val : bool)-> PyBrxCv.GradingStatus :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbHAlignment:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addArcAuto (self, *args, **kwargs)-> int :
      '''addArcAuto( (CvDbHAlignment)arg1, (int)arg2, (int)arg3) -> int :

    C++ signature :
        unsigned __int64 addArcAuto(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,unsigned __int64)'''
    ...
    def addArcBetween (self, *args, **kwargs)-> int :
      '''addArcBetween( (CvDbHAlignment)arg1, (int)arg2, (int)arg3, (Point2d)arg4) -> int :

    C++ signature :
        unsigned __int64 addArcBetween(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,unsigned __int64,class AcGePoint2d)

addArcBetween( (CvDbHAlignment)arg1, (int)arg2, (int)arg3, (float)arg4, (ArcParameterType)arg5, (bool)arg6, (ArcType)arg7) -> int :

    C++ signature :
        unsigned __int64 addArcBetween(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,unsigned __int64,double,enum BrxCvDbHAlignment::EArcParameterType,bool,enum BrxCvDbHAlignment::EArcType)'''
    ...
    def addArcFixed (self, *args, **kwargs)-> int :
      '''addArcFixed( (CvDbHAlignment)arg1, (Point2d)arg2, (float)arg3, (bool)arg4) -> int :

    C++ signature :
        unsigned __int64 addArcFixed(class PyBrxCvDbHAlignment {lvalue},class AcGePoint2d,double,bool)

addArcFixed( (CvDbHAlignment)arg1, (Point2d)arg2, (Point2d)arg3, (Point2d)arg4) -> int :

    C++ signature :
        unsigned __int64 addArcFixed(class PyBrxCvDbHAlignment {lvalue},class AcGePoint2d,class AcGePoint2d,class AcGePoint2d)'''
    ...
    def addArcFrom (self, *args, **kwargs)-> int :
      '''addArcFrom( (CvDbHAlignment)arg1, (int)arg2, (Point2d)arg3) -> int :

    C++ signature :
        unsigned __int64 addArcFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,class AcGePoint2d)

addArcFrom( (CvDbHAlignment)arg1, (int)arg2, (Point2d)arg3, (Vector2d)arg4) -> int :

    C++ signature :
        unsigned __int64 addArcFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,class AcGePoint2d,class AcGeVector2d)

addArcFrom( (CvDbHAlignment)arg1, (int)arg2, (Point2d)arg3, (float)arg4, (bool)arg5, (ArcType)arg6) -> int :

    C++ signature :
        unsigned __int64 addArcFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,class AcGePoint2d,double,bool,enum BrxCvDbHAlignment::EArcType)

addArcFrom( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (float)arg4, (ArcParameterType)arg5, (bool)arg6) -> int :

    C++ signature :
        unsigned __int64 addArcFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,double,enum BrxCvDbHAlignment::EArcParameterType,bool)'''
    ...
    def addArcTo (self, *args, **kwargs)-> int :
      '''addArcTo( (CvDbHAlignment)arg1, (int)arg2, (Point2d)arg3) -> int :

    C++ signature :
        unsigned __int64 addArcTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,class AcGePoint2d)

addArcTo( (CvDbHAlignment)arg1, (int)arg2, (Point2d)arg3, (Vector2d)arg4) -> int :

    C++ signature :
        unsigned __int64 addArcTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,class AcGePoint2d,class AcGeVector2d)

addArcTo( (CvDbHAlignment)arg1, (int)arg2, (Point2d)arg3, (float)arg4, (bool)arg5, (ArcType)arg6) -> int :

    C++ signature :
        unsigned __int64 addArcTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,class AcGePoint2d,double,bool,enum BrxCvDbHAlignment::EArcType)

addArcTo( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (float)arg4, (ArcParameterType)arg5, (bool)arg6) -> int :

    C++ signature :
        unsigned __int64 addArcTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,double,enum BrxCvDbHAlignment::EArcParameterType,bool)'''
    ...
    def addCSSTo (self, *args, **kwargs)-> int :
      '''addCSSTo( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (float)arg4, (SpiralParameterType2)arg5, (float)arg6, (Point2d)arg7, (SpiralDefinitionType2)arg8) -> int :

    C++ signature :
        unsigned __int64 addCSSTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,double,enum BrxCvDbHAlignment::ESpiralParameterType,double,class AcGePoint2d,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addCSTo (self, *args, **kwargs)-> int :
      '''addCSTo( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (SpiralParameterType2)arg4, (float)arg5, (Point2d)arg6, (bool)arg7, (SpiralDefinitionType2)arg8) -> int :

    C++ signature :
        unsigned __int64 addCSTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,enum BrxCvDbHAlignment::ESpiralParameterType,double,class AcGePoint2d,bool,enum BrxCvDbHAlignment::ESpiralDefinitionType)

addCSTo( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (SpiralParameterType2)arg4, (float)arg5, (float)arg6, (bool)arg7, (SpiralDefinitionType2)arg8) -> int :

    C++ signature :
        unsigned __int64 addCSTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,enum BrxCvDbHAlignment::ESpiralParameterType,double,double,bool,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addLineBetween (self, *args, **kwargs)-> int :
      '''addLineBetween( (CvDbHAlignment)arg1, (int)arg2, (int)arg3) -> int :

    C++ signature :
        unsigned __int64 addLineBetween(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,unsigned __int64)'''
    ...
    def addLineFixed (self, *args, **kwargs)-> int :
      '''addLineFixed( (CvDbHAlignment)arg1, (int)arg2, (float)arg3) -> int :

    C++ signature :
        unsigned __int64 addLineFixed(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double)

addLineFixed( (CvDbHAlignment)arg1, (Point2d)arg2, (Point2d)arg3) -> int :

    C++ signature :
        unsigned __int64 addLineFixed(class PyBrxCvDbHAlignment {lvalue},class AcGePoint2d,class AcGePoint2d)'''
    ...
    def addLineFrom (self, *args, **kwargs)-> int :
      '''addLineFrom( (CvDbHAlignment)arg1, (int)arg2, (Point2d)arg3) -> int :

    C++ signature :
        unsigned __int64 addLineFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,class AcGePoint2d)

addLineFrom( (CvDbHAlignment)arg1, (int)arg2, (float)arg3) -> int :

    C++ signature :
        unsigned __int64 addLineFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double)'''
    ...
    def addLineTo (self, *args, **kwargs)-> int :
      '''addLineTo( (CvDbHAlignment)arg1, (int)arg2, (Point2d)arg3) -> int :

    C++ signature :
        unsigned __int64 addLineTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,class AcGePoint2d)

addLineTo( (CvDbHAlignment)arg1, (int)arg2, (float)arg3) -> int :

    C++ signature :
        unsigned __int64 addLineTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double)'''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSCFrom (self, *args, **kwargs)-> int :
      '''addSCFrom( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (SpiralParameterType2)arg4, (float)arg5, (Point2d)arg6, (bool)arg7, (SpiralDefinitionType2)arg8) -> int :

    C++ signature :
        unsigned __int64 addSCFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,enum BrxCvDbHAlignment::ESpiralParameterType,double,class AcGePoint2d,bool,enum BrxCvDbHAlignment::ESpiralDefinitionType)

addSCFrom( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (SpiralParameterType2)arg4, (float)arg5, (float)arg6, (bool)arg7, (SpiralDefinitionType2)arg8) -> int :

    C++ signature :
        unsigned __int64 addSCFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,enum BrxCvDbHAlignment::ESpiralParameterType,double,double,bool,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addSCSAuto (self, *args, **kwargs)-> int :
      '''addSCSAuto( (CvDbHAlignment)arg1, (int)arg2, (int)arg3) -> int :

    C++ signature :
        unsigned __int64 addSCSAuto(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,unsigned __int64)'''
    ...
    def addSCSBetween (self, *args, **kwargs)-> int :
      '''addSCSBetween( (CvDbHAlignment)arg1, (int)arg2, (int)arg3, (float)arg4, (float)arg5, (SpiralParameterType2)arg6, (float)arg7, (SpiralDefinitionType2)arg8) -> int :

    C++ signature :
        unsigned __int64 addSCSBetween(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,unsigned __int64,double,double,enum BrxCvDbHAlignment::ESpiralParameterType,double,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addSSBetween (self, *args, **kwargs)-> int :
      '''addSSBetween( (CvDbHAlignment)arg1, (int)arg2, (int)arg3, (float)arg4, (SpiralParameterType2)arg5, (SpiralDefinitionType2)arg6) -> int :

    C++ signature :
        unsigned __int64 addSSBetween(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,unsigned __int64,double,enum BrxCvDbHAlignment::ESpiralParameterType,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addSSCFrom (self, *args, **kwargs)-> int :
      '''addSSCFrom( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (float)arg4, (SpiralParameterType2)arg5, (float)arg6, (Point2d)arg7, (SpiralDefinitionType2)arg8) -> int :

    C++ signature :
        unsigned __int64 addSSCFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,double,enum BrxCvDbHAlignment::ESpiralParameterType,double,class AcGePoint2d,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addSTFrom (self, *args, **kwargs)-> int :
      '''addSTFrom( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (SpiralParameterType2)arg4, (Point2d)arg5, (SpiralDefinitionType2)arg6) -> int :

    C++ signature :
        unsigned __int64 addSTFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,enum BrxCvDbHAlignment::ESpiralParameterType,class AcGePoint2d,enum BrxCvDbHAlignment::ESpiralDefinitionType)

addSTFrom( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (SpiralParameterType2)arg4, (float)arg5, (SpiralDefinitionType2)arg6) -> int :

    C++ signature :
        unsigned __int64 addSTFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,enum BrxCvDbHAlignment::ESpiralParameterType,double,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addSTSBetween (self, *args, **kwargs)-> int :
      '''addSTSBetween( (CvDbHAlignment)arg1, (int)arg2, (int)arg3, (float)arg4, (float)arg5, (SpiralParameterType2)arg6, (SpiralDefinitionType2)arg7) -> int :

    C++ signature :
        unsigned __int64 addSTSBetween(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,unsigned __int64,double,double,enum BrxCvDbHAlignment::ESpiralParameterType,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addSpiralBetween (self, *args, **kwargs)-> int :
      '''addSpiralBetween( (CvDbHAlignment)arg1, (int)arg2, (int)arg3, (SpiralDefinitionType2)arg4) -> int :

    C++ signature :
        unsigned __int64 addSpiralBetween(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,unsigned __int64,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addSpiralFrom (self, *args, **kwargs)-> int :
      '''addSpiralFrom( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (float)arg4, (bool)arg5, (SpiralDefinitionType2)arg6) -> int :

    C++ signature :
        unsigned __int64 addSpiralFrom(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,double,bool,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addSpiralTo (self, *args, **kwargs)-> int :
      '''addSpiralTo( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (float)arg4, (bool)arg5, (SpiralDefinitionType2)arg6) -> int :

    C++ signature :
        unsigned __int64 addSpiralTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,double,bool,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def addTSTo (self, *args, **kwargs)-> int :
      '''addTSTo( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (SpiralParameterType2)arg4, (Point2d)arg5, (SpiralDefinitionType2)arg6) -> int :

    C++ signature :
        unsigned __int64 addTSTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,enum BrxCvDbHAlignment::ESpiralParameterType,class AcGePoint2d,enum BrxCvDbHAlignment::ESpiralDefinitionType)

addTSTo( (CvDbHAlignment)arg1, (int)arg2, (float)arg3, (SpiralParameterType2)arg4, (float)arg5, (SpiralDefinitionType2)arg6) -> int :

    C++ signature :
        unsigned __int64 addTSTo(class PyBrxCvDbHAlignment {lvalue},unsigned __int64,double,enum BrxCvDbHAlignment::ESpiralParameterType,double,enum BrxCvDbHAlignment::ESpiralDefinitionType)'''
    ...
    def alignment3dAt (self, *args, **kwargs)-> PyDb.ObjectId :
      '''alignment3dAt( (CvDbHAlignment)arg1, (SubentType)arg2) -> ObjectId :

    C++ signature :
        class PyDbObjectId alignment3dAt(class PyBrxCvDbHAlignment {lvalue},unsigned long)'''
    ...
    def alignment3dCount (self, *args, **kwargs)-> int :
      '''alignment3dCount( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned long alignment3dCount(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignment :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def close (self)-> None :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def createFromAcGeCurve (curve: PyGe.Curve3d,normal: PyGe.Vector3d = kZAxis,tol: Tol = default)-> PyDb.Curve :
      '''                             '''
    ...
    def curveAtPI (self, *args, **kwargs)-> int :
      '''curveAtPI( (CvDbHAlignment)arg1, (CvDbHAlignmentPI)arg2) -> int :

    C++ signature :
        unsigned __int64 curveAtPI(class PyBrxCvDbHAlignment {lvalue},class PyBrxCvDbHAlignmentPI)'''
    ...
    def curveElementColor (self, *args, **kwargs)-> int :
      '''curveElementColor( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned long curveElementColor(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def deleteElement (self, *args, **kwargs)-> bool :
      '''deleteElement( (CvDbHAlignment)arg1, (int)arg2) -> bool :

    C++ signature :
        bool deleteElement(class PyBrxCvDbHAlignment {lvalue},unsigned __int64)'''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def elementAtId (self, *args, **kwargs)-> PyBrxCv.CvDbHAlignmentElement :
      '''elementAtId( (CvDbHAlignment)arg1, (int)arg2) -> CvDbHAlignmentElement :

    C++ signature :
        class PyBrxCvDbHAlignmentElement elementAtId(class PyBrxCvDbHAlignment {lvalue},unsigned __int64)'''
    ...
    def elementAtStation (self, *args, **kwargs)-> PyBrxCv.CvDbHAlignmentElement :
      '''elementAtStation( (CvDbHAlignment)arg1, (float)arg2) -> CvDbHAlignmentElement :

    C++ signature :
        class PyBrxCvDbHAlignmentElement elementAtStation(class PyBrxCvDbHAlignment {lvalue},double)'''
    ...
    def elementCount (self, *args, **kwargs)-> int :
      '''elementCount( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned __int64 elementCount(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def elementExtensionColor (self, *args, **kwargs)-> int :
      '''elementExtensionColor( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned long elementExtensionColor(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self)-> list :
      '''                             '''
    ...
    def extend (self, *args, **kwargs)-> None :
      '''extend( (Curve)arg1, (float)arg2) -> None :

    C++ signature :
        void extend(class PyDbCurve {lvalue},double)

extend( (Curve)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void extend(class PyDbCurve {lvalue},int,class AcGePoint3d)'''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def firstElementId (self, *args, **kwargs)-> int :
      '''firstElementId( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned __int64 firstElementId(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def firstLineElementId (self, *args, **kwargs)-> int :
      '''firstLineElementId( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned __int64 firstLineElementId(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def getAcGeCurve (self, tol: Tol = default)-> PyGe.Curve3d :
      '''                             '''
    ...
    def getArea (self)-> float :
      '''                             '''
    ...
    def getClosestPointTo (self, point3d: PyGe.Point3d, direction: PyGe.Vector3d=None, extend: bool=False)-> PyGe.Point3d :
      '''                             '''
    ...
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getDistAtParam (self, param: float)-> float :
      '''                             '''
    ...
    def getDistAtPoint (self, point3d: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getElementId (self, *args, **kwargs)-> int :
      '''getElementId( (CvDbHAlignment)arg1, (int)arg2) -> int :

    C++ signature :
        unsigned __int64 getElementId(class PyBrxCvDbHAlignment {lvalue},__int64)'''
    ...
    def getEndParam (self)-> float :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFirstDeriv (self, param: float|PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def getOffsetCurves (self, dist: float)-> list :
      '''                             '''
    ...
    def getOffsetCurvesGivenPlaneNormal (self, normal: PyGe.Vector3d, dist: float)-> list :
      '''                             '''
    ...
    def getOrthoProjectedCurve (self, plane: PyGe.Plane)-> PyDb.Curve :
      '''                             '''
    ...
    def getPIsArray (self, *args, **kwargs)-> list :
      '''getPIsArray( (CvDbHAlignment)arg1) -> list :

    C++ signature :
        class boost::python::list getPIsArray(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def getParamAtDist (self, dist: float)-> float :
      '''                             '''
    ...
    def getParamAtPoint (self, point3d: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getPointAtDist (self, dist: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def getPointAtParam (self, param: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def getPointAtStation (self, *args, **kwargs)-> tuple :
      '''getPointAtStation( (CvDbHAlignment)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getPointAtStation(class PyBrxCvDbHAlignment {lvalue},double)'''
    ...
    def getProjectedCurve (self, plane: PyGe.Plane, projDir: PyGe.Vector3d)-> PyDb.Curve :
      '''                             '''
    ...
    def getRadius (self, *args, **kwargs)-> float :
      '''getRadius( (CvDbHAlignment)arg1, (float)arg2) -> float :

    C++ signature :
        double getRadius(class PyBrxCvDbHAlignment {lvalue},double)'''
    ...
    def getSecondDeriv (self, param: float|PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getSpline (self)-> PyDb.Spline :
      '''                             '''
    ...
    def getSplitCurves (self, paramsOrPoints: list)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtParam (self, param: float)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtParams (self, params: list)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtPoint (self, point: PyGe.Point3d)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtPoints (self, points: list)-> list :
      '''                             '''
    ...
    def getStartParam (self)-> float :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getStationAtPoint (self, *args, **kwargs)-> tuple :
      '''getStationAtPoint( (CvDbHAlignment)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getStationAtPoint(class PyBrxCvDbHAlignment {lvalue},class AcGePoint2d)

getStationAtPoint( (CvDbHAlignment)arg1, (Point2d)arg2, (float)arg3, (float)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple getStationAtPoint(class PyBrxCvDbHAlignment {lvalue},class AcGePoint2d,double,double)'''
    ...
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def getUnorderedElementIds (self, *args, **kwargs)-> list :
      '''getUnorderedElementIds( (CvDbHAlignment)arg1) -> list :

    C++ signature :
        class boost::python::list getUnorderedElementIds(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def insertLineFixed (self, *args, **kwargs)-> int :
      '''insertLineFixed( (CvDbHAlignment)arg1, (Point2d)arg2, (Point2d)arg3, (int)arg4) -> int :

    C++ signature :
        unsigned __int64 insertLineFixed(class PyBrxCvDbHAlignment {lvalue},class AcGePoint2d,class AcGePoint2d,unsigned __int64)'''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isClosed (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPeriodic (self)-> int :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def lastElementId (self, *args, **kwargs)-> int :
      '''lastElementId( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned __int64 lastElementId(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (CvDbHAlignment)arg1) -> float :

    C++ signature :
        double length(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def lineElementColor (self, *args, **kwargs)-> int :
      '''lineElementColor( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned long lineElementColor(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def nextLineElementId (self, *args, **kwargs)-> int :
      '''nextLineElementId( (CvDbHAlignment)arg1, (int)arg2) -> int :

    C++ signature :
        unsigned __int64 nextLineElementId(class PyBrxCvDbHAlignment {lvalue},unsigned __int64)'''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
      '''                             '''
    ...
    def previousLineElementId (self, *args, **kwargs)-> int :
      '''previousLineElementId( (CvDbHAlignment)arg1, (int)arg2) -> int :

    C++ signature :
        unsigned __int64 previousLineElementId(class PyBrxCvDbHAlignment {lvalue},unsigned __int64)'''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def reverseCurve (self)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setCurveElementColor (self, *args, **kwargs)-> bool :
      '''setCurveElementColor( (CvDbHAlignment)arg1, (SubentType)arg2) -> bool :

    C++ signature :
        bool setCurveElementColor(class PyBrxCvDbHAlignment {lvalue},unsigned long)'''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setElementExtensionColor (self, *args, **kwargs)-> bool :
      '''setElementExtensionColor( (CvDbHAlignment)arg1, (SubentType)arg2) -> bool :

    C++ signature :
        bool setElementExtensionColor(class PyBrxCvDbHAlignment {lvalue},unsigned long)'''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setFromAcGeCurve (self, curve: PyGe.Curve3d, normal: PyGe.Vector3d = kZAxis, tol: Tol = default)-> None :
      '''                             '''
    ...
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineElementColor (self, *args, **kwargs)-> bool :
      '''setLineElementColor( (CvDbHAlignment)arg1, (SubentType)arg2) -> bool :

    C++ signature :
        bool setLineElementColor(class PyBrxCvDbHAlignment {lvalue},unsigned long)'''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setSpiralElementColor (self, *args, **kwargs)-> bool :
      '''setSpiralElementColor( (CvDbHAlignment)arg1, (SubentType)arg2) -> bool :

    C++ signature :
        bool setSpiralElementColor(class PyBrxCvDbHAlignment {lvalue},unsigned long)'''
    ...
    def setStationEquations (self, *args, **kwargs)-> bool :
      '''setStationEquations( (CvDbHAlignment)arg1, (CvStationEquations)arg2) -> bool :

    C++ signature :
        bool setStationEquations(class PyBrxCvDbHAlignment {lvalue},class PyBrxCvStationEquations)'''
    ...
    def setStyle (self, *args, **kwargs)-> bool :
      '''setStyle( (CvDbHAlignment)arg1, (SubentType)arg2) -> bool :

    C++ signature :
        bool setStyle(class PyBrxCvDbHAlignment {lvalue},unsigned long)'''
    ...
    def setTangentExtensionColor (self, *args, **kwargs)-> bool :
      '''setTangentExtensionColor( (CvDbHAlignment)arg1, (SubentType)arg2) -> bool :

    C++ signature :
        bool setTangentExtensionColor(class PyBrxCvDbHAlignment {lvalue},unsigned long)'''
    ...
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def spiralElementColor (self, *args, **kwargs)-> int :
      '''spiralElementColor( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned long spiralElementColor(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def stationEquations (self, *args, **kwargs)-> PyBrxCv.CvStationEquations :
      '''stationEquations( (CvDbHAlignment)arg1) -> CvStationEquations :

    C++ signature :
        class PyBrxCvStationEquations stationEquations(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def style (self, *args, **kwargs)-> int :
      '''style( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned long style(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def tangentExtensionColor (self, *args, **kwargs)-> int :
      '''tangentExtensionColor( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned long tangentExtensionColor(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def update (self, *args, **kwargs)-> bool :
      '''update( (CvDbHAlignment)arg1) -> bool :

    C++ signature :
        bool update(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def verticalAlignmentAt (self, *args, **kwargs)-> PyDb.ObjectId :
      '''verticalAlignmentAt( (CvDbHAlignment)arg1, (SubentType)arg2) -> ObjectId :

    C++ signature :
        class PyDbObjectId verticalAlignmentAt(class PyBrxCvDbHAlignment {lvalue},unsigned long)'''
    ...
    def verticalAlignmentCount (self, *args, **kwargs)-> int :
      '''verticalAlignmentCount( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned long verticalAlignmentCount(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def verticalAlignmentViewAt (self, *args, **kwargs)-> PyDb.ObjectId :
      '''verticalAlignmentViewAt( (CvDbHAlignment)arg1, (SubentType)arg2) -> ObjectId :

    C++ signature :
        class PyDbObjectId verticalAlignmentViewAt(class PyBrxCvDbHAlignment {lvalue},unsigned long)'''
    ...
    def verticalAlignmentViewCount (self, *args, **kwargs)-> int :
      '''verticalAlignmentViewCount( (CvDbHAlignment)arg1) -> int :

    C++ signature :
        unsigned long verticalAlignmentViewCount(class PyBrxCvDbHAlignment {lvalue})'''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbHAlignmentArc:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def endStation (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isClockwise (self)-> bool :
      '''                             '''
    ...
    def isCompound (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isLessThan180 (self)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isSubentity (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def nextId (self)-> int :
      '''                             '''
    ...
    def paramLength (self)-> float :
      '''                             '''
    ...
    def parameterConstraint (self)-> PyBrxCv.HAlignmentParameterConstraint :
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
    def previousId (self)-> int :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setLessThan180 (self, val : bool)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setNextId (self, val : int)-> bool :
      '''                             '''
    ...
    def setParamLength (self, val : float)-> bool :
      '''                             '''
    ...
    def setParameterConstraint (self, val : PyBrxCv.EParameterConstraint)-> bool :
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
    def setPreviousId (self, val : int)-> bool :
      '''                             '''
    ...
    def setRadius (self, val : float)-> bool :
      '''                             '''
    ...
    def setTangencyConstraint (self, val : PyBrxCv.ETangencyConstraint)-> bool :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def startStation (self)-> float :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.HAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.HAlignmentElementType :
      '''                             '''
    ...

class CvDbHAlignmentCurve:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def endStation (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isSubentity (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def startStation (self)-> float :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.HAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.HAlignmentElementType :
      '''                             '''
    ...

class CvDbHAlignmentElement:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isSubentity (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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

class CvDbHAlignmentLine:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentLine :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def endStation (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isSubentity (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def nextId (self)-> int :
      '''                             '''
    ...
    def paramLength (self)-> float :
      '''                             '''
    ...
    def parameterConstraint (self)-> PyBrxCv.HAlignmentParameterConstraint :
      '''                             '''
    ...
    def passThroughPoint1 (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def passThroughPoint2 (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def previousId (self)-> int :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setNextId (self, val : int)-> bool :
      '''                             '''
    ...
    def setParamLength (self, val : float)-> bool :
      '''                             '''
    ...
    def setParameterConstraint (self, val : PyBrxCv.EParameterConstraint)-> bool :
      '''                             '''
    ...
    def setPassThroughPoint1 (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setPassThroughPoint2 (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setPreviousId (self, val : int)-> bool :
      '''                             '''
    ...
    def setTangencyConstraint (self, val : PyBrxCv.ETangencyConstraint)-> bool :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def startStation (self)-> float :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.HAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.HAlignmentElementType :
      '''                             '''
    ...

class CvDbHAlignmentPI:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentPI :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isSubentity (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def location (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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

class CvDbHAlignmentSCS:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def endStation (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isSubentity (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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
    def spiralIn (self)-> PyBrxCv.CvDbHAlignmentSpiral :
      '''                             '''
    ...
    def spiralOut (self)-> PyBrxCv.CvDbHAlignmentSpiral :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def startStation (self)-> float :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.HAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.HAlignmentElementType :
      '''                             '''
    ...

class CvDbHAlignmentSSCSS:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def endStation (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isSubentity (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def startStation (self)-> float :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.HAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.HAlignmentElementType :
      '''                             '''
    ...

class CvDbHAlignmentSTS:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentSTS :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def endStation (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isSubentity (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def line (self)-> PyBrxCv.CvDbHAlignmentLine :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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
    def spiralIn (self)-> PyBrxCv.CvDbHAlignmentSpiral :
      '''                             '''
    ...
    def spiralOut (self)-> PyBrxCv.CvDbHAlignmentSpiral :
      '''                             '''
    ...
    def spiralRatio (self)-> float :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def startStation (self)-> float :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.HAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.HAlignmentElementType :
      '''                             '''
    ...

class CvDbHAlignmentSpiral:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbHAlignmentSpiral :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endDirection (self)-> float :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def endStation (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isCompound (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isSubentity (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def nextId (self)-> int :
      '''                             '''
    ...
    def paramA (self)-> float :
      '''                             '''
    ...
    def paramLength (self)-> float :
      '''                             '''
    ...
    def parameterConstraint (self)-> PyBrxCv.HAlignmentParameterConstraint :
      '''                             '''
    ...
    def previousId (self)-> int :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setEndDirection (self, val : float)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setNextId (self, val : int)-> bool :
      '''                             '''
    ...
    def setParamA (self, val : float)-> bool :
      '''                             '''
    ...
    def setParamLength (self, val : float)-> bool :
      '''                             '''
    ...
    def setParameterConstraint (self, val : PyBrxCv.EParameterConstraint)-> bool :
      '''                             '''
    ...
    def setPreviousId (self, val : int)-> bool :
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
    def setTangencyConstraint (self, val : PyBrxCv.ETangencyConstraint)-> bool :
      '''                             '''
    ...
    def spiralCurveType (self)-> PyBrxCv.SpiralCurveType :
      '''                             '''
    ...
    def spiralDefinition (self)-> PyBrxCv.SpiralDefinitionType :
      '''                             '''
    ...
    def startDirection (self)-> float :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def startStation (self)-> float :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.HAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.HAlignmentElementType :
      '''                             '''
    ...

class CvDbObject:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
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
    def close (self)-> None :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbObjectManager:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
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
    def close (self)-> None :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def elementCount (self)-> int :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
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
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def idAt (self, val : int|str)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ids (self)-> list :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def nameAt (self, val : int)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def remove1 (self)-> bool :
      '''                             '''
    ...
    def remove2 (self, id : str|PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbPoint:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbPoint :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def close (self)-> None :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def easting (self)-> float :
      '''                             '''
    ...
    def elevation (self)-> float :
      '''                             '''
    ...
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self)-> list :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def fullDescription (self)-> str :
      '''                             '''
    ...
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isLabelDragged (self)-> bool :
      '''                             '''
    ...
    def isLabelPinned (self)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
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
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def northing (self)-> float :
      '''                             '''
    ...
    def number (self)-> int :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def rawDescription (self)-> str :
      '''                             '''
    ...
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def referencedEntityAt (self, val : int)-> PyBrxCv.CvDbPointReferencedEntity :
      '''                             '''
    ...
    def referencedEntityCount (self)-> int :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def resetLabel (self)-> bool :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setEasting (self, val : float)-> bool :
      '''                             '''
    ...
    def setElevation (self, val : float)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
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
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setNorthing (self, val : float)-> bool :
      '''                             '''
    ...
    def setNumber (self, val : int)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPosition (self, pt : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setRawDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setSymbolId (self, id : PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def setSymbolRotation (self, val : float)-> bool :
      '''                             '''
    ...
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def symbolId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def symbolRotation (self)-> float :
      '''                             '''
    ...
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def update (self)-> bool :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbPointGroup:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
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
    def close (self)-> None :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
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
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasPoint (self, val : int)-> PyDb.ObjectId :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
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
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isApplicable (self)-> bool :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEditable (self)-> bool :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def pointCount (self)-> int :
      '''                             '''
    ...
    def pointIds (self)-> list :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
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

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
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
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def update (self)-> bool :
      '''                             '''
    ...
    def updateNeeded (self)-> bool :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbPointGroupManager:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
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
    def close (self)-> None :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def createPointGroup (self, val : str)-> PyDb.ObjectId :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def elementCount (self)-> int :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...

    @staticmethod
    def getManagerId (db: PyDb.Database)-> PyDb.ObjectId :
      '''                             '''
    ...
    def groupsWithPoint (self, val : int)-> list :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
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
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def idAt (self, val : int|str)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ids (self)-> list :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def nameAt (self, val : int)-> str :
      '''                             '''
    ...
    def nextPointNumber (self)-> int :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...

    @staticmethod
    def openManager (db: PyDb.Database,mode: PyDb.OpenMode)-> PyBrxCv.CvDbPointGroupManager :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def remove1 (self)-> bool :
      '''                             '''
    ...
    def remove2 (self, id : str|PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setNextPointNumber (self, val : int)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def updatePointGroups (self)-> int :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbPointReferencedEntity:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbPointReferencedEntity :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setId (self, id : PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def type (self)-> PyRx.RxClass :
      '''                             '''
    ...

class CvDbStyleManager:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
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
    def close (self)-> None :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def elementCount (self)-> int :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...

    @staticmethod
    def getManager (db: PyDb.Database,PyBrxCv.EStyleManagerType)-> PyDb.ObjectId :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
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
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def idAt (self, val : int|str)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ids (self)-> list :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def nameAt (self, val : int)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...

    @staticmethod
    def openManager (db: PyDb.Database,mode: PyDb.OpenMode,PyBrxCv.EStyleManagerType)-> PyBrxCv.CvDbObjectManager :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def remove1 (self)-> bool :
      '''                             '''
    ...
    def remove2 (self, id : str|PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbSubObject:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbObject :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...

class CvDbTinSurface:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addConstraint (self, constraint : PyBrxCv.CvDbTinSurfaceConstraint, addReactor : bool)-> bool :
      '''                             '''
    ...
    def addConstraints (self, constraints : list[PyBrxCv.CvDbTinSurfaceConstraint], addReactor : bool)-> bool :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addDefinition (self, ref : PyBrxCv.CvDbTinSurfaceDefinition)-> int :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addPoint (self, pt : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def addPoints (self, pts : list[PyGe.Point3d])-> bool :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def area2d (self, visibleOnly : bool=False)-> float :
      '''                             '''
    ...
    def area3d (self, visibleOnly : bool=False)-> float :
      '''                             '''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def boundingBox (self)-> tuple :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbTinSurface :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def close (self)-> None :
      '''                             '''
    ...
    def closestPointTo (self, pt : PyGe.Point3d)-> PyGe.Point3d :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def contains (self, pt : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def contoursAtElevation (self, elevation : float)-> list :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def createSnapshot (self)-> int :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def definitionAt (self, index : int)-> PyBrxCv.CvDbTinSurfaceDefinition :
      '''                             '''
    ...
    def definitionCount (self)-> int :
      '''                             '''
    ...
    def definitionIndex (self, ref : PyBrxCv.CvDbTinSurfaceDefinition)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def drapeId (self, id : PyDb.ObjectId)-> list :
      '''                             '''
    ...
    def drapePoint (self, pts : list[PyGe.Point3d])-> list :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def elevationAtPoint (self, pt : PyGe.Point3d)-> tuple :
      '''                             '''
    ...
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
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
    def explode (self)-> list :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def findDefinition (self, id : int)-> PyBrxCv.CvDbTinSurfaceDefinition :
      '''                             '''
    ...
    def findTinPointAt (self, pt : PyGe.Point3d)-> tuple :
      '''                             '''
    ...
    def findTinTrianglesAt (self, pt : PyGe.Point3d)-> list :
      '''                             '''
    ...
    def getBorders (self)-> list :
      '''                             '''
    ...
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getConstraint (self, id : PyDb.ObjectId|int)-> PyBrxCv.CvDbTinSurfaceConstraint :
      '''                             '''
    ...
    def getConstraints (self)-> list :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getPoints (self, visibleOnly : bool=False)-> list :
      '''                             '''
    ...
    def getPointsInsidePolygon (self, pts : list[PyGe.Point3d], includeOnEdge : bool)-> list :
      '''                             '''
    ...
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTinPoints (self)-> list :
      '''                             '''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasSnapshot (self)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def initialize (self, min : PyGe.Point3d, max : PyGe.Point3d, numOfPoints : int)-> None :
      '''                             '''
    ...
    def insertDefinitionAt (self, index : int, ref : PyBrxCv.CvDbTinSurfaceDefinition)-> int :
      '''                             '''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def intersectionsWithLine (self, start : PyGe.Point3d, end : PyGe.Point3d, type : PyBrxCv.TinSurfaceIntersectType, visibleOnly : bool)-> tuple :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isAssociative (self)-> bool :
      '''                             '''
    ...
    def isAutoUpdate (self)-> bool :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isRebuildPossible (self)-> bool :
      '''                             '''
    ...
    def isSnapshotUpdateNeeded (self)-> bool :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isUpdateNeeded (self)-> bool :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def majorContours (self)-> list :
      '''                             '''
    ...
    def majorContoursColor (self)-> tuple :
      '''                             '''
    ...
    def majorContoursInterval (self)-> tuple :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def maxElevation (self, visibleOnly : bool=False)-> float :
      '''                             '''
    ...
    def merge (self, other : PyBrxCv.CvDbTinSurface)-> bool :
      '''                             '''
    ...
    def minElevation (self, visibleOnly : bool=False)-> float :
      '''                             '''
    ...
    def minorContours (self)-> list :
      '''                             '''
    ...
    def minorContoursColor (self)-> tuple :
      '''                             '''
    ...
    def minorContoursInterval (self)-> tuple :
      '''                             '''
    ...
    def moveDefinition (self, from : int, to : int)-> int :
      '''                             '''
    ...
    def movePoint (self, from : PyGe.Point3d, to : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def movePoints (self, from : list[PyGe.Point3d], to : list[PyGe.Point3d])-> bool :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
      '''                             '''
    ...
    def pointsCount (self, visibleOnly : bool=False)-> int :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeAllDefinitions (self)-> int :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeDefinitionAt (self,  index: int)-> bool :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removePoint (self, pt : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def removePoints (self, pts : list[PyGe.Point3d])-> bool :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def removeSnapshot (self)-> bool :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAssociative (self, isAssociative : bool)-> bool :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setIsAutoUpdate (self, autoUpdateOn : bool)-> bool :
      '''                             '''
    ...
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMajorContoursColor (self, colorIndex : int)-> bool :
      '''                             '''
    ...
    def setMajorContoursInterval (self, interval : float)-> bool :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMinorContoursColor (self, colorIndex : int)-> bool :
      '''                             '''
    ...
    def setMinorContoursInterval (self, interval : float)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setStyle (self, style : PyBrxCv.TinSurfaceStyle)-> bool :
      '''                             '''
    ...
    def setSurfaceElevation (self, elevation : float)-> bool :
      '''                             '''
    ...
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def solid3d (self, *args, **kwargs)-> PyDb.Solid3d :
      '''solid3d( (CvDbTinSurface)arg1, (TinSurfaceSolidType)arg2, (float)arg3) -> Solid3d :

    C++ signature :
        class PyDb3dSolid solid3d(class PyBrxCvDbTinSurface {lvalue},enum BrxCvDbTinSurface::ETinSurfaceSolidType,double)

solid3d( (CvDbTinSurface)arg1, (CvDbTinSurface)arg2) -> Solid3d :

    C++ signature :
        class PyDb3dSolid solid3d(class PyBrxCvDbTinSurface {lvalue},class PyBrxCvDbTinSurface)'''
    ...
    def style (self)-> PyBrxCv.TinSurfaceStyle :
      '''                             '''
    ...
    def subDMesh (self, *args, **kwargs)-> PyDb.SubDMesh :
      '''subDMesh( (CvDbTinSurface)arg1, (TinSurfaceMeshType)arg2, (float)arg3) -> SubDMesh :

    C++ signature :
        class PyDbSubDMesh subDMesh(class PyBrxCvDbTinSurface {lvalue},enum BrxCvDbTinSurface::ETinSurfaceMeshType,double)

subDMesh( (CvDbTinSurface)arg1 [, (CvDbTinSurface)arg2]) -> SubDMesh :

    C++ signature :
        class PyDbSubDMesh subDMesh(class PyBrxCvDbTinSurface {lvalue} [,class PyBrxCvDbTinSurface])'''
    ...
    def swapEdge (self, pt : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def tinTriangles (self)-> list :
      '''                             '''
    ...
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
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
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbTinSurfaceBoundary:
    def __init__ (self, type: PyBrxCv.TinBoundaryType)-> None :
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
    def wallType (self)-> PyBrxCv.TinBoundaryType :
      '''                             '''
    ...

class CvDbTinSurfaceBreakline:
    def __init__ (self, type: PyBrxCv.TinBreaklineType)-> None :
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
    def intersectionElevation (self)-> PyBrxCv.TinIntersectionElevation :
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
    def setIntersectionElevation (self, val : PyBrxCv.TinBreaklineType)-> None :
      '''                             '''
    ...
    def setIsDbResident (self, val : bool)-> None :
      '''                             '''
    ...
    def setMidOrdinateDistance (self, val : float)-> None :
      '''                             '''
    ...

class CvDbTinSurfaceConstraint:
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

class CvDbTinSurfaceDefinition:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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

class CvDbTinSurfaceDefinitionAddDrawingObjects:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2, (float)arg3, (bool)arg4, (RewriteSymbolics)arg5) -> None :

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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def crossingsElevation (self)-> RewriteSymbolics :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def drawingObjectAt (self, idx : int)-> tuple :
      '''                             '''
    ...
    def drawingObjectsCount (self)-> int :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isApplyEdges (self)-> bool :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setIsApplyEdges (self, val : bool)-> bool :
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

class CvDbTinSurfaceDefinitionAddFromFiles:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def fileFormatId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def filesPaths (self)-> list :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setFileFormatId (self, id : PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def setFilesPaths (self, val : list[str])-> bool :
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

class CvDbTinSurfaceDefinitionAddFromPointClouds:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def pcObjectIds (self)-> list :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setPcObjectIds (self, val : list[PyDb.ObjectId])-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionAddLine:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def line (self)-> PyGe.LineSeg2d :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setLine (self, line : PyGe.LineSeg2d)-> bool :
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

class CvDbTinSurfaceDefinitionAddLines:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def lines (self)-> list :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setLines (self, lines : list[PyGe.LineSeg2d])-> bool :
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

class CvDbTinSurfaceDefinitionAddPoint:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def position (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setPosition (self, pt : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionAddPointGroups:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def pointGroupsIds (self)-> list :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setPointGroupsIds (self, val : list[PyDb.ObjectId])-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionAddPoints:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def positions (self)-> list :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setPositions (self, pt : list[PyGe.Point3d])-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionCreateFromC3D:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def filePath (self)-> str :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setFilePath (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, name : str)-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def setSurfaceName (self, val : str)-> bool :
      '''                             '''
    ...
    def surfaceName (self)-> str :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionCreateFromFaces:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def faceAt (self, *args, **kwargs)-> tuple :
      '''faceAt( (CvDbTinSurfaceDefinitionCreateFromFaces)arg1, (SubentType)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple faceAt(class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces {lvalue},unsigned long)'''
    ...
    def facesCount (self, *args, **kwargs)-> int :
      '''facesCount( (CvDbTinSurfaceDefinitionCreateFromFaces)arg1) -> int :

    C++ signature :
        unsigned long facesCount(class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces {lvalue})'''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isApplyEdgesVisibility (self, *args, **kwargs)-> bool :
      '''isApplyEdgesVisibility( (CvDbTinSurfaceDefinitionCreateFromFaces)arg1) -> bool :

    C++ signature :
        bool isApplyEdgesVisibility(class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces {lvalue})'''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def points (self, *args, **kwargs)-> list :
      '''points( (CvDbTinSurfaceDefinitionCreateFromFaces)arg1) -> list :

    C++ signature :
        class boost::python::list points(class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces {lvalue})'''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setIsApplyEdgesVisibility (self, *args, **kwargs)-> bool :
      '''setIsApplyEdgesVisibility( (CvDbTinSurfaceDefinitionCreateFromFaces)arg1, (bool)arg2) -> bool :

    C++ signature :
        bool setIsApplyEdgesVisibility(class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces {lvalue},bool)'''
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

class CvDbTinSurfaceDefinitionCreateFromLandXML:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def dwgUnits (self)-> PyDb.UnitsValue :
      '''                             '''
    ...
    def filePath (self)-> str :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def scaleToDwgUnits (self)-> bool :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setFilePath (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, name : str)-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
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
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionDeleteEdge:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def position (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setPosition (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionDeleteEdges:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def polygonAt (self, index : int)-> tuple :
      '''                             '''
    ...
    def polygonsCount (self)-> int :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def removeAllPolygons (self)-> bool :
      '''                             '''
    ...
    def removePolygonAt (self, index : int)-> bool :
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

class CvDbTinSurfaceDefinitionDeletePoint:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def position (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setPosition (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionGroupDefs:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def findSubDefinition (self, defid : int)-> int :
      '''                             '''
    ...
    def getSubDefinitionAt (self, index : int)-> PyBrxCv.CvDbTinSurfaceDefinition :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def numSubDefinitions (self)-> int :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def removeSubDefinitionAt (self, index : int)-> bool :
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

class CvDbTinSurfaceDefinitionModifyPointElevation:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def elevation (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isDeltaElevation (self)-> bool :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def position (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setElevation (self, val : float)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setIsDeltaElevation (self, val : float)-> bool :
      '''                             '''
    ...
    def setName (self, name : str)-> bool :
      '''                             '''
    ...
    def setPosition (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionModifyPointsElevation:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def elevation (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isDeltaElevation (self)-> bool :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def positions (self)-> list :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setElevation (self, val : float)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setName (self, name : str)-> bool :
      '''                             '''
    ...
    def setPositions (self, pt : list[PyGe.Point2d])-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionModifyPointsElevations:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def pointElevationAt (self, *args, **kwargs)-> tuple :
      '''pointElevationAt( (CvDbTinSurfaceDefinitionModifyPointsElevations)arg1, (SubentType)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple pointElevationAt(class PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations {lvalue},unsigned long)'''
    ...
    def pointElevationsCount (self, *args, **kwargs)-> int :
      '''pointElevationsCount( (CvDbTinSurfaceDefinitionModifyPointsElevations)arg1) -> int :

    C++ signature :
        unsigned long pointElevationsCount(class PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations {lvalue})'''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
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

class CvDbTinSurfaceDefinitionMovePoint:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def fromPosition (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setFromPosition (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setName (self, name : str)-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def setToPosition (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def toPosition (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionMovePoints:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def displacement (self)-> PyGe.Vector2d :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def fromPoints (self)-> list :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setDisplacement (self, vec : PyGe.Vector3d)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
      '''                             '''
    ...
    def setFromPoints (self, pt : list[PyGe.Point2d])-> bool :
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

class CvDbTinSurfaceDefinitionRemoveElevations:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
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
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionRemoveOuterEdges:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
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
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, desc : str)-> bool :
      '''                             '''
    ...
    def setEnabled (self, val : bool)-> bool :
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
    def setName (self, name : str)-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
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
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
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

class CvDbTinSurfaceDefinitionRiseLower:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def offset (self)-> float :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setOffset (self, val : float)-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionSwapEdge:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def position (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setPosition (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionTransform:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setTransformationMatrix (self, xform : PyGe.Matrix3d)-> bool :
      '''                             '''
    ...
    def transformationMatrix (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...

class CvDbTinSurfaceDefinitionTrianglesVisibility:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isEnabled (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
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
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def positions (self)-> list :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setPositions (self, val : list[PyGe.Point2d])-> bool :
      '''                             '''
    ...
    def setReadOnly (self, val : bool)-> bool :
      '''                             '''
    ...
    def setVisible (self, val : bool)-> bool :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.TinSurfaceDefinitionType :
      '''                             '''
    ...
    def visible (self)-> bool :
      '''                             '''
    ...

class CvDbTinSurfaceWall:
    def __init__ (self, type: PyBrxCv.TinWallType)-> None :
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
    def setHeight (self, val : float)-> None :
      '''                             '''
    ...
    def setIsDbResident (self, val : bool)-> None :
      '''                             '''
    ...
    def setMidOrdinateDistance (self, val : float)-> None :
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

class CvDbVAlignment:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addArcAuto (self, prevId: int, nextId: int)-> int :
      '''                             '''
    ...
    def addArcBetween (self, prevId: int, nextId: int, radius: float)-> int :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addParabolaAuto (self, prevId: int, nextId: int)-> int :
      '''                             '''
    ...
    def addParabolaBetween (self, prevId: int, nextId: int, radius: float)-> int :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def addTangentFixed (self, startPoint: PyGe.Point2d, endPoint: PyGe.Point2d)-> int :
      '''                             '''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def baseHAlignment (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def baseSurface (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignment :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def close (self)-> None :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def createFromAcGeCurve (curve: PyGe.Curve3d,normal: PyGe.Vector3d = kZAxis,tol: Tol = default)-> PyDb.Curve :
      '''                             '''
    ...
    def curveAtPVI (self, val: PyBrxCv.CvDbVAlignmentPVI)-> int :
      '''                             '''
    ...
    def curveElementColor (self)-> int :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def deleteElement (self, id: int)-> bool :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def elementAtId (self, val: int)-> PyBrxCv.CvDbVAlignmentElement :
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
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self)-> list :
      '''                             '''
    ...
    def extend (self, *args, **kwargs)-> None :
      '''extend( (Curve)arg1, (float)arg2) -> None :

    C++ signature :
        void extend(class PyDbCurve {lvalue},double)

extend( (Curve)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void extend(class PyDbCurve {lvalue},int,class AcGePoint3d)'''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def firstElementId (self)-> int :
      '''                             '''
    ...
    def firstTangentElementId (self)-> int :
      '''                             '''
    ...
    def getAcGeCurve (self, tol: Tol = default)-> PyGe.Curve3d :
      '''                             '''
    ...
    def getArea (self)-> float :
      '''                             '''
    ...
    def getClosestPointTo (self, point3d: PyGe.Point3d, direction: PyGe.Vector3d=None, extend: bool=False)-> PyGe.Point3d :
      '''                             '''
    ...
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getDistAtParam (self, param: float)-> float :
      '''                             '''
    ...
    def getDistAtPoint (self, point3d: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getElementId (self, val: int)-> int :
      '''                             '''
    ...
    def getElevationAt (self, val: float)-> tuple :
      '''                             '''
    ...
    def getElevations (self)-> list :
      '''                             '''
    ...
    def getEndParam (self)-> float :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFirstDeriv (self, param: float|PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def getOffsetCurves (self, dist: float)-> list :
      '''                             '''
    ...
    def getOffsetCurvesGivenPlaneNormal (self, normal: PyGe.Vector3d, dist: float)-> list :
      '''                             '''
    ...
    def getOrthoProjectedCurve (self, plane: PyGe.Plane)-> PyDb.Curve :
      '''                             '''
    ...
    def getPVIsArrays (self)-> list :
      '''                             '''
    ...
    def getParamAtDist (self, dist: float)-> float :
      '''                             '''
    ...
    def getParamAtPoint (self, point3d: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getPointAtDist (self, dist: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def getPointAtParam (self, param: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def getProjectedCurve (self, plane: PyGe.Plane, projDir: PyGe.Vector3d)-> PyDb.Curve :
      '''                             '''
    ...
    def getRadius (self, val: float)-> float :
      '''                             '''
    ...
    def getSecondDeriv (self, param: float|PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getSpline (self)-> PyDb.Spline :
      '''                             '''
    ...
    def getSplitCurves (self, paramsOrPoints: list)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtParam (self, param: float)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtParams (self, params: list)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtPoint (self, point: PyGe.Point3d)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtPoints (self, points: list)-> list :
      '''                             '''
    ...
    def getStartParam (self)-> float :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def getUnorderedElementIds (self)-> list :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def insertTangentFixed (self, startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, val: int)-> int :
      '''                             '''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isClosed (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPeriodic (self)-> int :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def lastElementId (self)-> int :
      '''                             '''
    ...
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def lineElementColor (self)-> int :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def nextTangentElementId (self, val: int)-> int :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
      '''                             '''
    ...
    def previousTangentElementId (self, val: int)-> int :
      '''                             '''
    ...
    def pviAtCurve (self, val: PyBrxCv.CvDbVAlignmentCurve)-> PyBrxCv.CvDbVAlignmentPVI :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def reverseCurve (self)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setBaseHAlignment (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def setBaseSurface (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setCurveElementColor (self, val: int)-> bool :
      '''                             '''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setFromAcGeCurve (self, curve: PyGe.Curve3d, normal: PyGe.Vector3d = kZAxis, tol: Tol = default)-> None :
      '''                             '''
    ...
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineElementColor (self, val: int)-> bool :
      '''                             '''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
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
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def style (self)-> int :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def tangentPolygonColor (self)-> int :
      '''                             '''
    ...
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.VAlignmentType :
      '''                             '''
    ...
    def update (self, updateDependencies: bool)-> bool :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbVAlignmentArc:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def gradeIn (self)-> float :
      '''                             '''
    ...
    def gradeOut (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isClockwise (self)-> bool :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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
    def setRadius (self, val : float)-> bool :
      '''                             '''
    ...
    def setTangencyConstraint (self, val : PyBrxCv.VAlignmentTangencyConstraint)-> bool :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.VAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.VAlignmentElementType :
      '''                             '''
    ...

class CvDbVAlignmentCurve:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.VAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.VAlignmentElementType :
      '''                             '''
    ...

class CvDbVAlignmentElement:
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
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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

class CvDbVAlignmentPVI:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentPVI :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def location (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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

class CvDbVAlignmentParabola:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentParabola :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def gradeIn (self)-> float :
      '''                             '''
    ...
    def gradeOut (self)-> float :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def name (self)-> str :
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
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def radius (self)-> float :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
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
    def setRadius (self, val : float)-> bool :
      '''                             '''
    ...
    def setTangencyConstraint (self, val : PyBrxCv.VAlignmentTangencyConstraint)-> bool :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.VAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.VAlignmentElementType :
      '''                             '''
    ...

class CvDbVAlignmentTangent:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentTangent :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def id (self)-> int :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def nextId (self)-> int :
      '''                             '''
    ...
    def parameterConstraint (self)-> PyBrxCv.VAlignmentParameterConstraint :
      '''                             '''
    ...
    def passThroughPoint1 (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def passThroughPoint2 (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def previousId (self)-> int :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setNextId (self, val : int)-> bool :
      '''                             '''
    ...
    def setParameterConstraint (self, val : PyBrxCv.VAlignmentParameterConstraint)-> bool :
      '''                             '''
    ...
    def setPassThroughPoint1 (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setPassThroughPoint2 (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setPreviousId (self, val : int)-> bool :
      '''                             '''
    ...
    def setTangencyConstraint (self, val : PyBrxCv.VAlignmentTangencyConstraint)-> bool :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def tangencyConstraint (self)-> PyBrxCv.VAlignmentTangencyConstraint :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.VAlignmentElementType :
      '''                             '''
    ...

class CvDbVAlignmentView:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addGraph (self, id : PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def baseElevation (self)-> float :
      '''                             '''
    ...
    def baseHAlignment (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVAlignmentView :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def close (self)-> None :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self)-> list :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
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
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def graphAt (self, val : int)-> PyDb.ObjectId :
      '''                             '''
    ...
    def graphCount (self)-> int :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def height (self)-> float :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def horizontalScale (self)-> float :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def origin (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removeGraph (self, *args, **kwargs)-> bool :
      '''removeGraph( (CvDbView)arg1, (ObjectId)arg2) -> bool :

    C++ signature :
        bool removeGraph(class PyBrxCvDbView {lvalue},class PyDbObjectId)'''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setBaseElevation (self, val : float)-> bool :
      '''                             '''
    ...
    def setBaseHAlignment (self, id : PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setHeight (self, val : float)-> bool :
      '''                             '''
    ...
    def setHorizontalScale (self, val : float)-> bool :
      '''                             '''
    ...
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLength (self, val : float)-> bool :
      '''                             '''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOrigin (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setVerticalScale (self, val : float)-> bool :
      '''                             '''
    ...
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
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
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def update (self, bUpdateDependencies : bool=True, updateOrigin : bool=True)-> bool :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def verticalScale (self)-> float :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbView:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addGraph (self, id : PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def baseElevation (self)-> float :
      '''                             '''
    ...
    def baseHAlignment (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbView :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def close (self)-> None :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self)-> list :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
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
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def graphAt (self, val : int)-> PyDb.ObjectId :
      '''                             '''
    ...
    def graphCount (self)-> int :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def height (self)-> float :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def horizontalScale (self)-> float :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def origin (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removeGraph (self, *args, **kwargs)-> bool :
      '''removeGraph( (CvDbView)arg1, (ObjectId)arg2) -> bool :

    C++ signature :
        bool removeGraph(class PyBrxCvDbView {lvalue},class PyDbObjectId)'''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setBaseElevation (self, val : float)-> bool :
      '''                             '''
    ...
    def setBaseHAlignment (self, id : PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setHeight (self, val : float)-> bool :
      '''                             '''
    ...
    def setHorizontalScale (self, val : float)-> bool :
      '''                             '''
    ...
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLength (self, val : float)-> bool :
      '''                             '''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOrigin (self, pt : PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setVerticalScale (self, val : float)-> bool :
      '''                             '''
    ...
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
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
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def verticalScale (self)-> float :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvDbVolumeSurface:
    def __init__ (self, id: ObjectId, mode: PyDb.OpenMode=kForRead, erased: bool=False)-> None :
      '''                             '''
    ...
    def addConstraint (self, constraint : PyBrxCv.CvDbTinSurfaceConstraint, addReactor : bool)-> bool :
      '''                             '''
    ...
    def addConstraints (self, constraints : list[PyBrxCv.CvDbTinSurfaceConstraint], addReactor : bool)-> bool :
      '''                             '''
    ...
    def addContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addDefinition (self, ref : PyBrxCv.CvDbTinSurfaceDefinition)-> int :
      '''                             '''
    ...
    def addPersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addPoint (self, pt : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def addPoints (self, pts : list[PyGe.Point3d])-> bool :
      '''                             '''
    ...
    def addReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def area2d (self, visibleOnly : bool=False)-> float :
      '''                             '''
    ...
    def area3d (self, visibleOnly : bool=False)-> float :
      '''                             '''
    ...
    def assertNotifyEnabled (self)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self)-> None :
      '''                             '''
    ...
    def baseSurfaceObjectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def blockId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def boundingBox (self)-> tuple :
      '''                             '''
    ...
    def boundingPolygon (self)-> list :
      '''                             '''
    ...
    def boundingPolygonObjectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self, ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVolumeSurface :
      '''                             '''
    ...
    def castShadows (self)-> bool :
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
    def cloneFrom (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbVolumeSurface :
      '''                             '''
    ...
    def close (self)-> None :
      '''                             '''
    ...
    def closestPointTo (self, pt : PyGe.Point3d)-> PyGe.Point3d :
      '''                             '''
    ...
    def collisionType (self)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self)-> int :
      '''                             '''
    ...
    def comparedTo (self, other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def comparisonSurfaceObjectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def contains (self, pt : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def contoursAtElevation (self, elevation : float)-> list :
      '''                             '''
    ...
    def copyFrom (self, other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def createSnapshot (self)-> int :
      '''                             '''
    ...
    def cutVolume (self)-> float :
      '''                             '''
    ...
    def database (self)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self, owner: PyDb.DbObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def definitionAt (self, index : int)-> PyBrxCv.CvDbTinSurfaceDefinition :
      '''                             '''
    ...
    def definitionCount (self)-> int :
      '''                             '''
    ...
    def definitionIndex (self, ref : PyBrxCv.CvDbTinSurfaceDefinition)-> tuple :
      '''                             '''
    ...
    def depthElevation (self)-> float :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self, disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self)-> None :
      '''                             '''
    ...
    def downgradeOpen (self)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def drapeId (self, id : PyDb.ObjectId)-> list :
      '''                             '''
    ...
    def drapePoint (self, pts : list[PyGe.Point3d])-> list :
      '''                             '''
    ...
    def draw (self)-> None :
      '''                             '''
    ...
    def drawableType (self)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def elevationAtPoint (self, pt : PyGe.Point3d)-> tuple :
      '''                             '''
    ...
    def entityColor (self)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self, erasing : bool=True)-> None :
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
    def explode (self)-> list :
      '''                             '''
    ...
    def extensionDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def fillVolume (self)-> float :
      '''                             '''
    ...
    def findDefinition (self, id : int)-> PyBrxCv.CvDbTinSurfaceDefinition :
      '''                             '''
    ...
    def findTinPointAt (self, pt : PyGe.Point3d)-> tuple :
      '''                             '''
    ...
    def findTinTrianglesAt (self, pt : PyGe.Point3d)-> list :
      '''                             '''
    ...
    def getBorders (self)-> list :
      '''                             '''
    ...
    def getCompoundObjectTransform (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getConstraint (self, id : PyDb.ObjectId|int)-> PyBrxCv.CvDbTinSurfaceConstraint :
      '''                             '''
    ...
    def getConstraints (self)-> list :
      '''                             '''
    ...
    def getEcs (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getField (self, prop: str='TEXT')-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getGeomExtents (self)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self)-> PyDb.Handle :
      '''                             '''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getPoints (self, visibleOnly : bool=False)-> list :
      '''                             '''
    ...
    def getPointsInsidePolygon (self, pts : list[PyGe.Point3d], includeOnEdge : bool)-> list :
      '''                             '''
    ...
    def getStretchPoints (self)-> list :
      '''                             '''
    ...
    def getSubentPathsAtGsMarker (self, *args, **kwargs)-> list :
      '''getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d)

getSubentPathsAtGsMarker( (Entity)arg1, (SubentType)arg2, (int)arg3, (Point3d)arg4, (Matrix3d)arg5, (int)arg6, (ObjectId)arg7) -> list :

    C++ signature :
        class boost::python::list getSubentPathsAtGsMarker(class PyDbEntity {lvalue},unsigned long,__int64,class AcGePoint3d,class AcGeMatrix3d,int,class PyDbObjectId {lvalue})'''
    ...
    def getTinPoints (self)-> list :
      '''                             '''
    ...
    def getTransformedCopy (self, matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def handOverTo (self, newObject: PyDb.DbObject, keepXData: bool, keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasSnapshot (self)-> bool :
      '''                             '''
    ...
    def hasXData (self, appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self, path: PyDb.FullSubentPath = None, highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self)-> int :
      '''                             '''
    ...
    def initialize (self, min : PyGe.Point3d, max : PyGe.Point3d, numOfPoints : int)-> None :
      '''                             '''
    ...
    def initialize1 (self, *args, **kwargs)-> bool :
      '''initialize1( (CvDbVolumeSurface)arg1, (CvDbTinSurface)arg2, (CvDbTinSurface)arg3, (list)arg4) -> bool :

    C++ signature :
        bool initialize1(class PyBrxCvDbVolumeSurface {lvalue},class PyBrxCvDbTinSurface,class PyBrxCvDbTinSurface,class boost::python::list)'''
    ...
    def initialize2 (self, *args, **kwargs)-> bool :
      '''initialize2( (CvDbVolumeSurface)arg1, (CvDbTinSurface)arg2, (CvDbTinSurface)arg3, (ObjectId)arg4, (float)arg5) -> bool :

    C++ signature :
        bool initialize2(class PyBrxCvDbVolumeSurface {lvalue},class PyBrxCvDbTinSurface,class PyBrxCvDbTinSurface,class PyDbObjectId,double)'''
    ...
    def initialize3 (self, *args, **kwargs)-> bool :
      '''initialize3( (CvDbVolumeSurface)arg1, (CvDbTinSurface)arg2, (float)arg3, (VolumeSurfaceType)arg4, (list)arg5) -> bool :

    C++ signature :
        bool initialize3(class PyBrxCvDbVolumeSurface {lvalue},class PyBrxCvDbTinSurface,double,enum BrxCvDbVolumeSurface::EVolumeSurfaceType,class boost::python::list)'''
    ...
    def initialize4 (self, *args, **kwargs)-> bool :
      '''initialize4( (CvDbVolumeSurface)arg1, (CvDbTinSurface)arg2, (float)arg3, (VolumeSurfaceType)arg4, (ObjectId)arg5, (float)arg6) -> bool :

    C++ signature :
        bool initialize4(class PyBrxCvDbVolumeSurface {lvalue},class PyBrxCvDbTinSurface,double,enum BrxCvDbVolumeSurface::EVolumeSurfaceType,class PyDbObjectId,double)'''
    ...
    def insertDefinitionAt (self, index : int, ref : PyBrxCv.CvDbTinSurfaceDefinition)-> int :
      '''                             '''
    ...

    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane)-> list : ...
    @overload
    def intersectWith (self, entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int)-> list : ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''Overloads:
    - entity: PyDb.Entity, intType : PyDb.Intersect
    - entity: PyDb.Entity, intType : PyDb.Intersect, thisGsMarker : int, otherGsMarker : int
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane
    - entity: PyDb.Entity, intType : PyDb.Intersect, plane : PyGe.Plane, thisGsMarker : int, otherGsMarker : int
    '''
    ...
    def intersectionsWithLine (self, start : PyGe.Point3d, end : PyGe.Point3d, type : PyBrxCv.TinSurfaceIntersectType, visibleOnly : bool)-> tuple :
      '''                             '''
    ...
    def isA (self)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self)-> int :
      '''                             '''
    ...
    def isAnnotative (self)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isAssociative (self)-> bool :
      '''                             '''
    ...
    def isAutoUpdate (self)-> bool :
      '''                             '''
    ...
    def isCancelling (self)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self)-> int :
      '''                             '''
    ...
    def isErased (self)-> int :
      '''                             '''
    ...
    def isKindOf (self, rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self)-> int :
      '''                             '''
    ...
    def isModifiedXData (self)-> int :
      '''                             '''
    ...
    def isNewObject (self)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self)-> int :
      '''                             '''
    ...
    def isNotifying (self)-> int :
      '''                             '''
    ...
    def isNullObj (self)-> bool :
      '''                             '''
    ...
    def isPersistent (self)-> int :
      '''                             '''
    ...
    def isPlanar (self)-> int :
      '''                             '''
    ...
    def isReadEnabled (self)-> int :
      '''                             '''
    ...
    def isReallyClosing (self)-> int :
      '''                             '''
    ...
    def isRebuildPossible (self)-> bool :
      '''                             '''
    ...
    def isSnapshotUpdateNeeded (self)-> bool :
      '''                             '''
    ...
    def isTransactionResident (self)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self)-> bool :
      '''                             '''
    ...
    def isUndoing (self)-> int :
      '''                             '''
    ...
    def isUpdateNeeded (self)-> bool :
      '''                             '''
    ...
    def isWriteEnabled (self)-> int :
      '''                             '''
    ...
    def keepAlive (self, flag: bool)-> None :
      '''                             '''
    ...
    def layer (self)-> str :
      '''                             '''
    ...
    def layerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineWeight (self)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self)-> str :
      '''                             '''
    ...
    def linetypeId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self)-> float :
      '''                             '''
    ...
    def list (self)-> None :
      '''                             '''
    ...
    def majorContours (self)-> list :
      '''                             '''
    ...
    def majorContoursColor (self)-> tuple :
      '''                             '''
    ...
    def majorContoursInterval (self)-> tuple :
      '''                             '''
    ...
    def material (self)-> str :
      '''                             '''
    ...
    def materialId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def maxElevation (self, visibleOnly : bool=False)-> float :
      '''                             '''
    ...
    def merge (self, other : PyBrxCv.CvDbTinSurface)-> bool :
      '''                             '''
    ...
    def minElevation (self, visibleOnly : bool=False)-> float :
      '''                             '''
    ...
    def minorContours (self)-> list :
      '''                             '''
    ...
    def minorContoursColor (self)-> tuple :
      '''                             '''
    ...
    def minorContoursInterval (self)-> tuple :
      '''                             '''
    ...
    def moveDefinition (self, from : int, to : int)-> int :
      '''                             '''
    ...
    def movePoint (self, from : PyGe.Point3d, to : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def movePoints (self, from : list[PyGe.Point3d], to : list[PyGe.Point3d])-> bool :
      '''                             '''
    ...
    def name (self)-> str :
      '''                             '''
    ...
    def objectId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self)-> str :
      '''                             '''
    ...
    def pointsCount (self, visibleOnly : bool=False)-> int :
      '''                             '''
    ...
    def queryX (self, rhs: PyRx.RxClass)-> PyRx.RxObject :
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
    def receiveShadows (self)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self)-> None :
      '''                             '''
    ...
    def removeAllDefinitions (self)-> int :
      '''                             '''
    ...
    def removeContext (self, obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeDefinitionAt (self,  index: int)-> bool :
      '''                             '''
    ...
    def removeField (self, id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removePoint (self, pt : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def removePoints (self, pts : list[PyGe.Point3d])-> bool :
      '''                             '''
    ...
    def removeReactor (self, reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def removeSnapshot (self)-> bool :
      '''                             '''
    ...
    def rolloverHit (self, nSubentId: int, nMouseFlags: int, bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self)-> None :
      '''                             '''
    ...
    def setAnnotative (self, state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAssociative (self, isAssociative : bool)-> bool :
      '''                             '''
    ...
    def setAttributes (self, traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setCastShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setColor (self, clr: PyDb.AcCmColor, dosubents : bool=True, db : Database='current')-> None :
      '''                             '''
    ...
    def setColorIndex (self, clr: int, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self, db: Database = 'current')-> None :
      '''                             '''
    ...
    def setDescription (self, val : str)-> bool :
      '''                             '''
    ...

    @overload
    def setField (self, field: PyDb.Field)-> PyDb.ObjectId : ...
    @overload
    def setField (self, propName: str, field: PyDb.Field)-> PyDb.ObjectId : ...
    def setField (self, *args, **kwargs)-> PyDb.ObjectId :
      '''Overloads:
    - field: PyDb.Field
    - propName: str, field: PyDb.Field
    '''
    ...
    def setIsAutoUpdate (self, autoUpdateOn : bool)-> bool :
      '''                             '''
    ...
    def setLayer (self, val: str|ObjectId, dosubents : bool=True, allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineWeight (self, val: LineWeight, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self, val: float, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMajorContoursColor (self, colorIndex : int)-> bool :
      '''                             '''
    ...
    def setMajorContoursInterval (self, interval : float)-> bool :
      '''                             '''
    ...
    def setMaterial (self, val: str|ObjectId, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMinorContoursColor (self, colorIndex : int)-> bool :
      '''                             '''
    ...
    def setMinorContoursInterval (self, interval : float)-> bool :
      '''                             '''
    ...
    def setName (self, val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self, owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setPlotStyleName (self, *args, **kwargs)-> None :
      '''setPlotStyleName( (Entity)arg1, (str)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (int)arg3) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,int)

setPlotStyleName( (Entity)arg1, (PlotStyleNameType)arg2, (ObjectId)arg3, (int)arg4) -> None :

    C++ signature :
        void setPlotStyleName(class PyDbEntity {lvalue},enum AcDb::PlotStyleNameType,class PyDbObjectId,int)'''
    ...
    def setPropertiesFrom (self, entity: PyDb.Entity, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self, val: bool)-> None :
      '''                             '''
    ...
    def setStyle (self, style : PyBrxCv.TinSurfaceStyle)-> bool :
      '''                             '''
    ...
    def setSurfaceElevation (self, elevation : float)-> bool :
      '''                             '''
    ...
    def setVisibility (self, val: Visibility, dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self, xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self,  filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def solid3d (self, *args, **kwargs)-> PyDb.Solid3d :
      '''solid3d( (CvDbTinSurface)arg1, (TinSurfaceSolidType)arg2, (float)arg3) -> Solid3d :

    C++ signature :
        class PyDb3dSolid solid3d(class PyBrxCvDbTinSurface {lvalue},enum BrxCvDbTinSurface::ETinSurfaceSolidType,double)

solid3d( (CvDbTinSurface)arg1, (CvDbTinSurface)arg2) -> Solid3d :

    C++ signature :
        class PyDb3dSolid solid3d(class PyBrxCvDbTinSurface {lvalue},class PyBrxCvDbTinSurface)'''
    ...
    def style (self)-> PyBrxCv.TinSurfaceStyle :
      '''                             '''
    ...
    def subDMesh (self, *args, **kwargs)-> PyDb.SubDMesh :
      '''subDMesh( (CvDbTinSurface)arg1, (TinSurfaceMeshType)arg2, (float)arg3) -> SubDMesh :

    C++ signature :
        class PyDbSubDMesh subDMesh(class PyBrxCvDbTinSurface {lvalue},enum BrxCvDbTinSurface::ETinSurfaceMeshType,double)

subDMesh( (CvDbTinSurface)arg1 [, (CvDbTinSurface)arg2]) -> SubDMesh :

    C++ signature :
        class PyDbSubDMesh subDMesh(class PyBrxCvDbTinSurface {lvalue} [,class PyBrxCvDbTinSurface])'''
    ...
    def swapEdge (self, pt : PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def swapIdWith (self, otherId: PyDb.DbObject, swapXdata: bool, swapExtDict: bool)-> None :
      '''                             '''
    ...
    def tinTriangles (self)-> list :
      '''                             '''
    ...
    def transformBy (self, matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def triangles (self, visibleOnly : bool=False)-> list :
      '''                             '''
    ...
    def trianglesCount (self, visibleOnly : bool=False)-> int :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.VolumeSurfaceType :
      '''                             '''
    ...
    def updateConstraint (self, val : PyBrxCv.CvDbTinSurfaceConstraint)-> bool :
      '''                             '''
    ...
    def updateObjectData (self)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self, wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self)-> None :
      '''                             '''
    ...
    def viewportDraw (self, vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self, vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self, owner: PyRx.RxObject, mapping: PyDb.IdMapping, isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self, wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self, appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self, xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self)-> None :
      '''                             '''
    ...

class CvGradingRule:
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

class CvGradingSlopeOffsetRule:
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
    def offset (self)-> float :
      '''                             '''
    ...
    def release (self)-> bool :
      '''                             '''
    ...
    def setOffset (self, offset : float)-> bool :
      '''                             '''
    ...
    def setSide (self, format : int)-> bool :
      '''                             '''
    ...
    def setSlope (self, slope : float)-> bool :
      '''                             '''
    ...
    def setSlopeFormat (self, format : int)-> bool :
      '''                             '''
    ...
    def side (self)-> PyBrxCv.GradingSide :
      '''                             '''
    ...
    def slope (self)-> float :
      '''                             '''
    ...
    def slopeFormat (self)-> PyBrxCv.GradingSlopeFormat :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.GradingType :
      '''                             '''
    ...

class CvGradingSlopeSurfaceRule:
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

    @staticmethod
    def convertRadToSlope ()-> float :
      '''                             '''
    ...

    @staticmethod
    def convertSlopeToRad ()-> float :
      '''                             '''
    ...
    def cutSlope (self)-> float :
      '''                             '''
    ...
    def fillSlope (self)-> float :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def release (self)-> bool :
      '''                             '''
    ...
    def setCutSlope (self, val : float)-> bool :
      '''                             '''
    ...
    def setFillSlope (self, val : float)-> bool :
      '''                             '''
    ...
    def setSide (self, format : int)-> bool :
      '''                             '''
    ...
    def setSlopeFormat (self, format : int)-> bool :
      '''                             '''
    ...
    def setSurfaceId (self, id : PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def side (self)-> PyBrxCv.GradingSide :
      '''                             '''
    ...
    def slopeFormat (self)-> PyBrxCv.GradingSlopeFormat :
      '''                             '''
    ...
    def surfaceId (self)-> PyDb.ObjectId :
      '''                             '''
    ...
    def type (self)-> PyBrxCv.GradingType :
      '''                             '''
    ...

class CvStationEquation:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (float)arg2, (float)arg3, (StationEquationType)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double,enum BrxCvStationEquation::EStationEquationType)'''
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

class CvStationEquations:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (CvDbHAlignment)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyBrxCvDbHAlignment {lvalue})'''
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

class CvTinPoint:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def isValid (self, *args, **kwargs)-> bool :
      '''isValid( (CvTinPoint)arg1) -> bool :

    C++ signature :
        bool isValid(class BrxCvTinPoint {lvalue})'''
    ...
    def location (self, *args, **kwargs)-> PyGe.Point3d :
      '''location( (CvTinPoint)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d location(class BrxCvTinPoint {lvalue})'''
    ...
    def triangleWithPoint (self, *args, **kwargs)-> PyBrxCv.CvTinTriangle :
      '''triangleWithPoint( (CvTinPoint)arg1) -> CvTinTriangle :

    C++ signature :
        class BrxCvTinTriangle triangleWithPoint(class BrxCvTinPoint {lvalue})'''
    ...

class CvTinTriangle:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def isValid (self, *args, **kwargs)-> bool :
      '''isValid( (CvTinTriangle)arg1) -> bool :

    C++ signature :
        bool isValid(class BrxCvTinTriangle {lvalue})'''
    ...
    def isVisible (self, *args, **kwargs)-> bool :
      '''isVisible( (CvTinTriangle)arg1) -> bool :

    C++ signature :
        bool isVisible(class BrxCvTinTriangle {lvalue})'''
    ...
    def locationAt (self, *args, **kwargs)-> PyGe.Point3d :
      '''locationAt( (CvTinTriangle)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d locationAt(class BrxCvTinTriangle {lvalue},unsigned short)'''
    ...
    def neighborAt (self, *args, **kwargs)-> PyBrxCv.CvTinTriangle :
      '''neighborAt( (CvTinTriangle)arg1, (int)arg2) -> CvTinTriangle :

    C++ signature :
        class BrxCvTinTriangle neighborAt(class BrxCvTinTriangle {lvalue},unsigned short)'''
    ...
    def pointAt (self, *args, **kwargs)-> PyBrxCv.CvTinPoint :
      '''pointAt( (CvTinTriangle)arg1, (int)arg2) -> CvTinPoint :

    C++ signature :
        class BrxCvTinPoint pointAt(class BrxCvTinTriangle {lvalue},unsigned short)'''
    ...

class DrawingObjectType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class GradingCalculationMethod:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eGradingAccurate (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eGradingFast (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class GradingSide:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eGradingSideLeft (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eGradingSideNone (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eGradingSideRight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class GradingSlopeFormat:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class GradingStatus:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class GradingType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eGradingTypeNone (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eGradingTypeSlopeOffset (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eGradingTypeSlopeSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class GradingVisualStyle:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class HAlignmentElementType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class HAlignmentParameterConstraint:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class HAlignmentTangencyConstraint:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class HAlignmentVisualStyle:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class SpiralCurveType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eInCurve (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eOutCurve (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class SpiralDefinitionType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eClothoid (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eCubicParabola (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class SpiralDefinitionType2:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eClothoid (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eCubicParabola (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class SpiralDirectionType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eDirectionLeft (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eDirectionRight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class SpiralParameterType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eClothoid (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eCubicParabola (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class SpiralParameterType2:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eParamA (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eParamLength (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class StationEquationType:
    def Decreasing (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def Increasing (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class StyleManagerType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eContourLabel (self, *args, **kwargs)-> None :
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinBoundaryType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eTinHide (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinOuter (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinShow (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinBreaklineType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eTinBreaklineNormal (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinNonDestructive (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinConstraintType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eTinBoundary (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinBreakline (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinWall (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinIntersectionElevation:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinSurfaceDefinitionType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinSurfaceIntersectType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eTinSurfaceAll (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinSurfaceFirstOnly (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinSurfaceMeshType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eTinSurfaceMeshDepth (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinSurfaceMeshElevation (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinSurfaceMeshSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinSurfaceSolidType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eSolidTypeSurfaceDepth (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eSolidTypeSurfaceElevation (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eSolidTypeSurfaceSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinSurfaceStyle:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinWallSide:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eTinWallLeft (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinWallRight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class TinWallType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eTinWallNormal (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinWallProjected (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class VAlignmentElementType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class VAlignmentParameterConstraint:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class VAlignmentTangencyConstraint:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class VAlignmentType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
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
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class VAlignmentVisualStyle:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eElements (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eExtensions (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTangents (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class VolumeSurfaceType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eTinVolumeBaseComparison (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinVolumeToDepth (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTinVolumeToElevation (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...
