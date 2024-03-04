import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
import PyBrxCv
import PyBrxCv

class CvDbCurve:
    def __init__ (self: CvDbCurve,id: ObjectId,mode: OpenMode=kForRead,erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self: DbObject,obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self: DbObject,id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self: Entity,reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def assertNotifyEnabled (self: DbObject)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self: DbObject)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self: DbObject)-> None :
      '''                             '''
    ...
    def blockId (self: Entity)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self: Drawable,ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self: DbObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbCurve :
      '''                             '''
    ...
    def castShadows (self: Entity)-> bool :
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
    def close (self: DbObject)-> None :
      '''                             '''
    ...
    def collisionType (self: Entity)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self: Entity)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self: Entity)-> int :
      '''                             '''
    ...
    def comparedTo (self: RxObject,other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self: DbObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def createFromAcGeCurve (curve: PyGe.Curve3d,normal: PyGe.Vector3d = kZAxis,tol: Tol = default)-> PyDb.Curve :
      '''                             '''
    ...
    def database (self: DbObject)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self: DbObject,owner: PyDb.DbObject,mapping: PyDb.IdMapping,isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self: CvDbCurve)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self: DbObject,disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def downgradeOpen (self: DbObject)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self: DbObject,wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self: Entity)-> None :
      '''                             '''
    ...
    def drawableType (self: Drawable)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def entityColor (self: Entity)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self: DbObject,erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self: Entity)-> list :
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
    def extensionDictionary (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getAcGeCurve (self: Curve,tol: Tol = default)-> PyGe.Curve3d :
      '''                             '''
    ...
    def getArea (self: Curve)-> float :
      '''                             '''
    ...
    def getClosestPointTo (self: Curve,point3d: PyGe.Point3d,direction: PyGe.Vector3d=None,extend: bool=False)-> PyGe.Point3d :
      '''                             '''
    ...
    def getCompoundObjectTransform (self: Entity)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getDistAtParam (self: Curve,param: float)-> float :
      '''                             '''
    ...
    def getDistAtPoint (self: Curve,point3d: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def getEcs (self: Entity)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getEndParam (self: Curve)-> float :
      '''                             '''
    ...
    def getEndPoint (self: Curve)-> PyGe.Point3d :
      '''                             '''
    ...
    def getField (self: DbObject,prop: str=TEXT)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFirstDeriv (self: Curve,param: float|PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getGeomExtents (self: Entity)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self: Entity)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self: DbObject)-> PyDb.Handle :
      '''                             '''
    ...
    def getOffsetCurves (self: Curve,dist: float)-> list :
      '''                             '''
    ...
    def getOffsetCurvesGivenPlaneNormal (self: Curve,normal: PyGe.Vector3d,dist: float)-> list :
      '''                             '''
    ...
    def getOrthoProjectedCurve (self: Curve,plane: PyGe.Plane)-> PyDb.Curve :
      '''                             '''
    ...
    def getParamAtDist (self: Curve,dist: float)-> float :
      '''                             '''
    ...
    def getParamAtPoint (self: Curve,point3d: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def getPlane (self: Entity)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self: Entity)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getPointAtDist (self: Curve,dist: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def getPointAtParam (self: Curve,param: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def getProjectedCurve (self: Curve,plane: PyGe.Plane,projDir: PyGe.Vector3d)-> PyDb.Curve :
      '''                             '''
    ...
    def getSecondDeriv (self: Curve,param: float|PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getSpline (self: Curve)-> PyDb.Spline :
      '''                             '''
    ...
    def getSplitCurves (self: Curve,paramsOrPoints: list)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtParam (self: Curve,param: float)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtParams (self: Curve,params: list)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtPoint (self: Curve,point: PyGe.Point3d)-> list :
      '''                             '''
    ...
    def getSplitCurvesAtPoints (self: Curve,points: list)-> list :
      '''                             '''
    ...
    def getStartParam (self: Curve)-> float :
      '''                             '''
    ...
    def getStartPoint (self: Curve)-> PyGe.Point3d :
      '''                             '''
    ...
    def getStretchPoints (self: Entity)-> list :
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
    def getTransformedCopy (self: Entity,matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def handOverTo (self: DbObject,newObject: PyDb.DbObject,keepXData: bool,keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self: DbObject)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self: DbObject,id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self: DbObject,appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self: Entity,path: PyDb.FullSubentPath = None,highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self: Drawable)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''intersectWith( (Entity)arg1, (Entity)arg2, (Intersect)arg3) -> list :

    C++ signature :
        class boost::python::list intersectWith(class PyDbEntity {lvalue},class PyDbEntity,enum AcDb::Intersect)

intersectWith( (Entity)arg1, (Entity)arg2, (Intersect)arg3, (int)arg4, (int)arg5) -> list :

    C++ signature :
        class boost::python::list intersectWith(class PyDbEntity {lvalue},class PyDbEntity,enum AcDb::Intersect,__int64,__int64)

intersectWith( (Entity)arg1, (Entity)arg2, (Intersect)arg3, (Plane)arg4) -> list :

    C++ signature :
        class boost::python::list intersectWith(class PyDbEntity {lvalue},class PyDbEntity,enum AcDb::Intersect,class PyGePlane)

intersectWith( (Entity)arg1, (Entity)arg2, (Intersect)arg3, (Plane)arg4, (int)arg5, (int)arg6) -> list :

    C++ signature :
        class boost::python::list intersectWith(class PyDbEntity {lvalue},class PyDbEntity,enum AcDb::Intersect,class PyGePlane,__int64,__int64)'''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self: DbObject)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self: DbObject)-> int :
      '''                             '''
    ...
    def isAnnotative (self: DbObject)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self: DbObject)-> int :
      '''                             '''
    ...
    def isClosed (self: Curve)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self: DbObject)-> int :
      '''                             '''
    ...
    def isErased (self: DbObject)-> int :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self: DbObject)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self: DbObject)-> int :
      '''                             '''
    ...
    def isModifiedXData (self: DbObject)-> int :
      '''                             '''
    ...
    def isNewObject (self: DbObject)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self: DbObject)-> int :
      '''                             '''
    ...
    def isNotifying (self: DbObject)-> int :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def isPeriodic (self: Curve)-> int :
      '''                             '''
    ...
    def isPersistent (self: Drawable)-> int :
      '''                             '''
    ...
    def isPlanar (self: Entity)-> int :
      '''                             '''
    ...
    def isReadEnabled (self: DbObject)-> int :
      '''                             '''
    ...
    def isReallyClosing (self: DbObject)-> int :
      '''                             '''
    ...
    def isTransactionResident (self: DbObject)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self: DbObject)-> bool :
      '''                             '''
    ...
    def isUndoing (self: DbObject)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self: DbObject)-> int :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag: bool)-> None :
      '''                             '''
    ...
    def layer (self: Entity)-> str :
      '''                             '''
    ...
    def layerId (self: Entity)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineWeight (self: Entity)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self: Entity)-> str :
      '''                             '''
    ...
    def linetypeId (self: Entity)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self: Entity)-> float :
      '''                             '''
    ...
    def list (self: Entity)-> None :
      '''                             '''
    ...
    def material (self: Entity)-> str :
      '''                             '''
    ...
    def materialId (self: Entity)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self: CvDbCurve)-> str :
      '''                             '''
    ...
    def objectId (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self: Entity)-> str :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def receiveShadows (self: Entity)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self: Entity)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self: DbObject)-> None :
      '''                             '''
    ...
    def removeContext (self: DbObject,obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self: DbObject,id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self: DbObject,id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self: Entity,reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def reverseCurve (self: Curve)-> None :
      '''                             '''
    ...
    def rolloverHit (self: Drawable,nSubentId: int,nMouseFlags: int,bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self: DbObject)-> None :
      '''                             '''
    ...
    def setAnnotative (self: DbObject,state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self: Drawable,traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setCastShadows (self: Entity,val: bool)-> None :
      '''                             '''
    ...
    def setColor (self: Entity,clr: AcCmColor,dosubents : bool=True,db : Database=current)-> None :
      '''                             '''
    ...
    def setColorIndex (self: Entity,clr: int,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self: Entity,db: Database = current)-> None :
      '''                             '''
    ...
    def setDescription (self: CvDbCurve,val : str)-> bool :
      '''                             '''
    ...
    def setField (self: DbObject,prop: str=TEXT,fld: PyDb.Field)-> PyDb.ObjectId :
      '''                             '''
    ...
    def setFromAcGeCurve (self: Curve,curve: PyGe.Curve3d,normal: PyGe.Vector3d = kZAxis,tol: Tol = default)-> None :
      '''                             '''
    ...
    def setLayer (self: Entity,val: str|ObjectId,dosubents : bool=True,allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineWeight (self: Entity,val: LineWeight,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self: Entity,val: str|ObjectId,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self: Entity,val: float,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self: Entity,val: str|ObjectId,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setName (self: CvDbCurve,val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self: DbObject,owner: PyDb.ObjectId)-> None :
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
    def setPropertiesFrom (self: Entity,ent: Entity,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self: Entity,val: bool)-> None :
      '''                             '''
    ...
    def setVisibility (self: Entity,val: Visibility,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self: DbObject,xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self: DbObject, filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self: DbObject,otherId: PyDb.DbObject,swapXdata: bool,swapExtDict: bool)-> None :
      '''                             '''
    ...
    def transformBy (self: Entity,matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self: DbObject,wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self: DbObject)-> None :
      '''                             '''
    ...
    def viewportDraw (self: Drawable,vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self: Drawable,vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self: Entity)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self: DbObject,owner: PyRx.RxObject,mapping: PyDb.IdMapping,isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self: Drawable,wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self: DbObject,appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self: DbObject,xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self: DbObject)-> None :
      '''                             '''
    ...

class CvDbEntity:
    def __init__ (self: CvDbEntity,id: ObjectId,mode: OpenMode=kForRead,erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self: DbObject,obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self: DbObject,id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self: Entity,reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def addSubentPaths (self, *args, **kwargs)-> None :
      '''addSubentPaths( (Entity)arg1, (list)arg2) -> None :

    C++ signature :
        void addSubentPaths(class PyDbEntity {lvalue},class boost::python::list)'''
    ...
    def assertNotifyEnabled (self: DbObject)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self: DbObject)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self: DbObject)-> None :
      '''                             '''
    ...
    def blockId (self: Entity)-> PyDb.ObjectId :
      '''                             '''
    ...
    def bounds (self: Drawable,ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self: DbObject)-> None :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyRx.RxObject)-> PyBrxCv.CvDbEntity :
      '''                             '''
    ...
    def castShadows (self: Entity)-> bool :
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
    def close (self: DbObject)-> None :
      '''                             '''
    ...
    def collisionType (self: Entity)-> PyDb.CollisionType :
      '''                             '''
    ...
    def color (self: Entity)-> PyDb.Color :
      '''                             '''
    ...
    def colorIndex (self: Entity)-> int :
      '''                             '''
    ...
    def comparedTo (self: RxObject,other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self: DbObject)-> None :
      '''                             '''
    ...
    def database (self: DbObject)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self: DbObject,owner: PyDb.DbObject,mapping: PyDb.IdMapping,isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self: CvDbEntity)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self: DbObject,disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def downgradeOpen (self: DbObject)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self: DbObject,wasWritable: bool)-> None :
      '''                             '''
    ...
    def draw (self: Entity)-> None :
      '''                             '''
    ...
    def drawableType (self: Drawable)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def entityColor (self: Entity)-> PyDb.EntityColor :
      '''                             '''
    ...
    def erase (self: DbObject,erasing : bool=True)-> None :
      '''                             '''
    ...
    def explode (self: Entity)-> list :
      '''                             '''
    ...
    def extensionDictionary (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getCompoundObjectTransform (self: Entity)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getEcs (self: Entity)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def getField (self: DbObject,prop: str=TEXT)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getGeomExtents (self: Entity)-> PyDb.Extents :
      '''                             '''
    ...
    def getGeomExtents2d (self: Entity)-> PyDb.Extents2d :
      '''                             '''
    ...
    def getGripPoints (self, *args, **kwargs)-> None :
      '''getGripPoints( (Entity)arg1, (list)arg2, (list)arg3, (list)arg4) -> None :

    C++ signature :
        void getGripPoints(class PyDbEntity {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue},class boost::python::list {lvalue})'''
    ...
    def getHandle (self: DbObject)-> PyDb.Handle :
      '''                             '''
    ...
    def getPlane (self: Entity)-> PyGe.Plane :
      '''                             '''
    ...
    def getPlotStyleNameId (self: Entity)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getStretchPoints (self: Entity)-> list :
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
    def getTransformedCopy (self: Entity,matrix3d: PyGe.Matrix3d)-> PyDb.Entity :
      '''                             '''
    ...
    def handOverTo (self: DbObject,newObject: PyDb.DbObject,keepXData: bool,keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self: DbObject)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self: DbObject,id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self: DbObject,appname: str)-> bool :
      '''                             '''
    ...
    def highlight (self: Entity,path: PyDb.FullSubentPath = None,highlightAll : bool = False)-> None :
      '''                             '''
    ...
    def id (self: Drawable)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> list :
      '''intersectWith( (Entity)arg1, (Entity)arg2, (Intersect)arg3) -> list :

    C++ signature :
        class boost::python::list intersectWith(class PyDbEntity {lvalue},class PyDbEntity,enum AcDb::Intersect)

intersectWith( (Entity)arg1, (Entity)arg2, (Intersect)arg3, (int)arg4, (int)arg5) -> list :

    C++ signature :
        class boost::python::list intersectWith(class PyDbEntity {lvalue},class PyDbEntity,enum AcDb::Intersect,__int64,__int64)

intersectWith( (Entity)arg1, (Entity)arg2, (Intersect)arg3, (Plane)arg4) -> list :

    C++ signature :
        class boost::python::list intersectWith(class PyDbEntity {lvalue},class PyDbEntity,enum AcDb::Intersect,class PyGePlane)

intersectWith( (Entity)arg1, (Entity)arg2, (Intersect)arg3, (Plane)arg4, (int)arg5, (int)arg6) -> list :

    C++ signature :
        class boost::python::list intersectWith(class PyDbEntity {lvalue},class PyDbEntity,enum AcDb::Intersect,class PyGePlane,__int64,__int64)'''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self: DbObject)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self: DbObject)-> int :
      '''                             '''
    ...
    def isAnnotative (self: DbObject)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self: DbObject)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self: DbObject)-> int :
      '''                             '''
    ...
    def isErased (self: DbObject)-> int :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self: DbObject)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self: DbObject)-> int :
      '''                             '''
    ...
    def isModifiedXData (self: DbObject)-> int :
      '''                             '''
    ...
    def isNewObject (self: DbObject)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self: DbObject)-> int :
      '''                             '''
    ...
    def isNotifying (self: DbObject)-> int :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def isPersistent (self: Drawable)-> int :
      '''                             '''
    ...
    def isPlanar (self: Entity)-> int :
      '''                             '''
    ...
    def isReadEnabled (self: DbObject)-> int :
      '''                             '''
    ...
    def isReallyClosing (self: DbObject)-> int :
      '''                             '''
    ...
    def isTransactionResident (self: DbObject)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self: DbObject)-> bool :
      '''                             '''
    ...
    def isUndoing (self: DbObject)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self: DbObject)-> int :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag: bool)-> None :
      '''                             '''
    ...
    def layer (self: Entity)-> str :
      '''                             '''
    ...
    def layerId (self: Entity)-> PyDb.ObjectId :
      '''                             '''
    ...
    def lineWeight (self: Entity)-> PyDb.LineWeight :
      '''                             '''
    ...
    def linetype (self: Entity)-> str :
      '''                             '''
    ...
    def linetypeId (self: Entity)-> PyDb.ObjectId :
      '''                             '''
    ...
    def linetypeScale (self: Entity)-> float :
      '''                             '''
    ...
    def list (self: Entity)-> None :
      '''                             '''
    ...
    def material (self: Entity)-> str :
      '''                             '''
    ...
    def materialId (self: Entity)-> PyDb.ObjectId :
      '''                             '''
    ...
    def name (self: CvDbEntity)-> str :
      '''                             '''
    ...
    def objectId (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def plotStyleName (self: Entity)-> str :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def receiveShadows (self: Entity)-> bool :
      '''                             '''
    ...
    def recordGraphicsModified (self: Entity)-> None :
      '''                             '''
    ...
    def releaseExtensionDictionary (self: DbObject)-> None :
      '''                             '''
    ...
    def removeContext (self: DbObject,obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self: DbObject,id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self: DbObject,id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self: Entity,reactor: EntityReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self: Drawable,nSubentId: int,nMouseFlags: int,bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self: DbObject)-> None :
      '''                             '''
    ...
    def setAnnotative (self: DbObject,state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self: Drawable,traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setCastShadows (self: Entity,val: bool)-> None :
      '''                             '''
    ...
    def setColor (self: Entity,clr: AcCmColor,dosubents : bool=True,db : Database=current)-> None :
      '''                             '''
    ...
    def setColorIndex (self: Entity,clr: int,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setDatabaseDefaults (self: Entity,db: Database = current)-> None :
      '''                             '''
    ...
    def setDescription (self: CvDbEntity,val : str)-> bool :
      '''                             '''
    ...
    def setField (self: DbObject,prop: str=TEXT,fld: PyDb.Field)-> PyDb.ObjectId :
      '''                             '''
    ...
    def setLayer (self: Entity,val: str|ObjectId,dosubents : bool=True,allowHiddenLayer : bool=False)-> None :
      '''                             '''
    ...
    def setLineWeight (self: Entity,val: LineWeight,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetype (self: Entity,val: str|ObjectId,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setLinetypeScale (self: Entity,val: float,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setMaterial (self: Entity,val: str|ObjectId,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setName (self: CvDbEntity,val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self: DbObject,owner: PyDb.ObjectId)-> None :
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
    def setPropertiesFrom (self: Entity,ent: Entity,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setReceiveShadows (self: Entity,val: bool)-> None :
      '''                             '''
    ...
    def setVisibility (self: Entity,val: Visibility,dosubents : bool=True)-> None :
      '''                             '''
    ...
    def setXData (self: DbObject,xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self: DbObject, filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self: DbObject,otherId: PyDb.DbObject,swapXdata: bool,swapExtDict: bool)-> None :
      '''                             '''
    ...
    def transformBy (self: Entity,matrix3d: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self: DbObject,wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self: DbObject)-> None :
      '''                             '''
    ...
    def viewportDraw (self: Drawable,vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self: Drawable,vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def visibility (self: Entity)-> PyDb.Visibility :
      '''                             '''
    ...
    def wblockClone (self: DbObject,owner: PyRx.RxObject,mapping: PyDb.IdMapping,isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self: Drawable,wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self: DbObject,appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self: DbObject,xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self: DbObject)-> None :
      '''                             '''
    ...

class CvDbObject:
    def __init__ (self: CvDbObject,id: ObjectId,mode: OpenMode=kForRead,erased: bool=False)-> None :
      '''                             '''
    ...
    def addContext (self: DbObject,obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def addPersistentReactor (self: DbObject,id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def addReactor (self: DbObject,reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def assertNotifyEnabled (self: DbObject)-> None :
      '''                             '''
    ...
    def assertReadEnabled (self: DbObject)-> None :
      '''                             '''
    ...
    def assertWriteEnabled (self: DbObject)-> None :
      '''                             '''
    ...
    def bounds (self: Drawable,ext: PyDb.Extents)-> bool :
      '''                             '''
    ...
    def cancel (self: DbObject)-> None :
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
    def close (self: DbObject)-> None :
      '''                             '''
    ...
    def comparedTo (self: RxObject,other: PyRx.RxObject)-> PyRx.Ordering :
      '''                             '''
    ...
    def copyFrom (self: RxObject,other: PyRx.RxObject)-> None :
      '''                             '''
    ...
    def createExtensionDictionary (self: DbObject)-> None :
      '''                             '''
    ...
    def database (self: DbObject)-> PyDb.Database :
      '''                             '''
    ...
    def deepClone (self: DbObject,owner: PyDb.DbObject,mapping: PyDb.IdMapping,isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...

    @staticmethod
    def desc ()-> PyRx.RxClass :
      '''                             '''
    ...
    def description (self: CvDbObject)-> str :
      '''                             '''
    ...
    def disableUndoRecording (self: DbObject,disable: bool)-> None :
      '''                             '''
    ...
    def dispose (self: RxObject)-> None :
      '''                             '''
    ...
    def downgradeOpen (self: DbObject)-> None :
      '''                             '''
    ...
    def downgradeToNotify (self: DbObject,wasWritable: bool)-> None :
      '''                             '''
    ...
    def drawableType (self: Drawable)-> PyGi.GiDrawableType :
      '''                             '''
    ...
    def erase (self: DbObject,erasing : bool=True)-> None :
      '''                             '''
    ...
    def extensionDictionary (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getField (self: DbObject,prop: str=TEXT)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getFieldDictionary (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def getHandle (self: DbObject)-> PyDb.Handle :
      '''                             '''
    ...
    def handOverTo (self: DbObject,newObject: PyDb.DbObject,keepXData: bool,keepExtDict: bool)-> None :
      '''                             '''
    ...
    def hasFields (self: DbObject)-> bool :
      '''                             '''
    ...
    def hasPersistentReactor (self: DbObject,id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def hasXData (self: DbObject,appname: str)-> bool :
      '''                             '''
    ...
    def id (self: Drawable)-> PyDb.ObjectId :
      '''                             '''
    ...
    def implRefCount (self: RxObject)-> int :
      '''                             '''
    ...
    def isA (self: RxObject)-> PyRx.RxClass :
      '''                             '''
    ...
    def isAProxy (self: DbObject)-> int :
      '''                             '''
    ...
    def isAcDbObjectIdsInFlux (self: DbObject)-> int :
      '''                             '''
    ...
    def isAnnotative (self: DbObject)-> PyDb.AnnotativeStates :
      '''                             '''
    ...
    def isCancelling (self: DbObject)-> int :
      '''                             '''
    ...
    def isEraseStatusToggled (self: DbObject)-> int :
      '''                             '''
    ...
    def isErased (self: DbObject)-> int :
      '''                             '''
    ...
    def isKindOf (self: RxObject,rhs: PyRx.RxClass)-> bool :
      '''                             '''
    ...
    def isModified (self: DbObject)-> int :
      '''                             '''
    ...
    def isModifiedGraphics (self: DbObject)-> int :
      '''                             '''
    ...
    def isModifiedXData (self: DbObject)-> int :
      '''                             '''
    ...
    def isNewObject (self: DbObject)-> int :
      '''                             '''
    ...
    def isNotifyEnabled (self: DbObject)-> int :
      '''                             '''
    ...
    def isNotifying (self: DbObject)-> int :
      '''                             '''
    ...
    def isNullObj (self: RxObject)-> bool :
      '''                             '''
    ...
    def isPersistent (self: Drawable)-> int :
      '''                             '''
    ...
    def isReadEnabled (self: DbObject)-> int :
      '''                             '''
    ...
    def isReallyClosing (self: DbObject)-> int :
      '''                             '''
    ...
    def isTransactionResident (self: DbObject)-> int :
      '''                             '''
    ...
    def isUndoRecordingDisabled (self: DbObject)-> bool :
      '''                             '''
    ...
    def isUndoing (self: DbObject)-> int :
      '''                             '''
    ...
    def isWriteEnabled (self: DbObject)-> int :
      '''                             '''
    ...
    def keepAlive (self: RxObject,flag: bool)-> None :
      '''                             '''
    ...
    def name (self: CvDbObject)-> str :
      '''                             '''
    ...
    def objectId (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def ownerId (self: DbObject)-> PyDb.ObjectId :
      '''                             '''
    ...
    def queryX (self: RxObject,rhs: PyRx.RxClass)-> PyRx.RxObject :
      '''                             '''
    ...
    def releaseExtensionDictionary (self: DbObject)-> None :
      '''                             '''
    ...
    def removeContext (self: DbObject,obj : PyDb.ObjectContext)-> None :
      '''                             '''
    ...
    def removeField (self: DbObject,id: str|ObjectId)-> None :
      '''                             '''
    ...
    def removePersistentReactor (self: DbObject,id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def removeReactor (self: DbObject,reactor: DbObjectReactor)-> None :
      '''                             '''
    ...
    def rolloverHit (self: Drawable,nSubentId: int,nMouseFlags: int,bReset: bool)-> int :
      '''                             '''
    ...
    def setAcDbObjectIdsInFlux (self: DbObject)-> None :
      '''                             '''
    ...
    def setAnnotative (self: DbObject,state : PyDb.AnnotativeStates)-> None :
      '''                             '''
    ...
    def setAttributes (self: Drawable,traits: PyGi.DrawableTraits)-> int :
      '''                             '''
    ...
    def setDescription (self: CvDbObject,val : str)-> bool :
      '''                             '''
    ...
    def setField (self: DbObject,prop: str=TEXT,fld: PyDb.Field)-> PyDb.ObjectId :
      '''                             '''
    ...
    def setName (self: CvDbObject,val : str)-> bool :
      '''                             '''
    ...
    def setOwnerId (self: DbObject,owner: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def setXData (self: DbObject,xdata: list)-> None :
      '''                             '''
    ...
    def snoop (self: DbObject, filer : PyDb.SnoopDwgFiler)-> None :
      '''                             '''
    ...
    def swapIdWith (self: DbObject,otherId: PyDb.DbObject,swapXdata: bool,swapExtDict: bool)-> None :
      '''                             '''
    ...
    def upgradeFromNotify (self: DbObject,wasWritable: bool)-> None :
      '''                             '''
    ...
    def upgradeOpen (self: DbObject)-> None :
      '''                             '''
    ...
    def viewportDraw (self: Drawable,vpdraw: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def viewportDrawLogicalFlags (self: Drawable,vpdraw: PyGi.ViewportDraw)-> int :
      '''                             '''
    ...
    def wblockClone (self: DbObject,owner: PyRx.RxObject,mapping: PyDb.IdMapping,isPrimary:bool=True)-> PyDb.DbObject :
      '''                             '''
    ...
    def worldDraw (self: Drawable,wdraw: PyGi.WorldDraw)-> int :
      '''                             '''
    ...
    def xData (self: DbObject,appname: str)-> list :
      '''                             '''
    ...
    def xDataTransformBy (self: DbObject,xform: PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def xmitPropagateModify (self: DbObject)-> None :
      '''                             '''
    ...
