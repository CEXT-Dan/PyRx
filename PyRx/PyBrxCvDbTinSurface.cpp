#include "stdafx.h"
#include "PyBrxCvDbTinSurface.h"

#ifdef BRXAPP
#include "PyBrxCvDbTinSurfaceDef.h"
#include "PyDbObjectId.h"
#include "PyDbCurve.h"
#include "PyGeCurve3d.h"
#include "PyDbSubDMesh.h"
#include "PyDb3dSolid.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceConstraint
void makePyBrxCvDbTinSurfaceConstraintWrapper()
{
    PyDocString DS("CvDbTinSurfaceConstraint");
    class_<PyBrxCvDbTinSurfaceConstraint>("CvDbTinSurfaceConstraint")
        .def(init<>())
        .def(init<BrxCvDbTinSurfaceConstraint::ETinConstraintType>(DS.ARGS({"type: PyBrxCv.TinConstraintType"})))
        .def("constraintType", &PyBrxCvDbTinSurfaceConstraint::constraintType, DS.ARGS())
        .def("setData", &PyBrxCvDbTinSurfaceConstraint::setData1, DS.ARGS({ "intId : int" ,"pts : list[PyGe.Point3d]" }))
        .def("setDataId", &PyBrxCvDbTinSurfaceConstraint::setData2, DS.ARGS({ "id : PyDb.ObjectId","midOrdinateDist : float" }))
        .def("data", &PyBrxCvDbTinSurfaceConstraint::data, DS.ARGS())
        .def("id", &PyBrxCvDbTinSurfaceConstraint::id, DS.ARGS())
        .def("setMidOrdinateDistance", &PyBrxCvDbTinSurfaceConstraint::setMidOrdinateDistance, DS.ARGS({ "val : float" }))
        .def("midOrdinateDistance", &PyBrxCvDbTinSurfaceConstraint::midOrdinateDistance, DS.ARGS())
        .def("setIsDbResident", &PyBrxCvDbTinSurfaceConstraint::setIsDbResident, DS.ARGS({ "val : bool" }))
        .def("isDbResident", &PyBrxCvDbTinSurfaceConstraint::isDbResident, DS.ARGS())
        .def("className", &PyBrxCvDbTinSurfaceConstraint::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxCvDbTinSurfaceConstraint::PyBrxCvDbTinSurfaceConstraint()
    :m_pyImp(new BrxCvDbTinSurfaceConstraint())
{
}

PyBrxCvDbTinSurfaceConstraint::PyBrxCvDbTinSurfaceConstraint(BrxCvDbTinSurfaceConstraint::ETinConstraintType type)
    :m_pyImp(new BrxCvDbTinSurfaceConstraint(type))
{
}

PyBrxCvDbTinSurfaceConstraint::PyBrxCvDbTinSurfaceConstraint(const BrxCvDbTinSurfaceConstraint& other)
    :m_pyImp(new BrxCvDbTinSurfaceConstraint(other))
{
}

PyBrxCvDbTinSurfaceConstraint::PyBrxCvDbTinSurfaceConstraint(BrxCvDbTinSurfaceConstraint* ptr)
    :m_pyImp(ptr)
{
}

BrxCvDbTinSurfaceConstraint::ETinConstraintType PyBrxCvDbTinSurfaceConstraint::constraintType() const
{
    return impObj()->constraintType();
}

void PyBrxCvDbTinSurfaceConstraint::setData1(Adesk::UInt64 id, const boost::python::list& points)
{
    return impObj()->setData(id, PyListToPoint3dArray(points));
}

void PyBrxCvDbTinSurfaceConstraint::setData2(const PyDbObjectId& id, double midOrdinateDist)
{
    return impObj()->setData(id.m_id, midOrdinateDist);
}

boost::python::list PyBrxCvDbTinSurfaceConstraint::data() const
{
    return Point3dArrayToPyList(impObj()->data());
}

Adesk::UInt64 PyBrxCvDbTinSurfaceConstraint::id() const
{
    return impObj()->id();
}

void PyBrxCvDbTinSurfaceConstraint::setMidOrdinateDistance(double midOrdinateDist)
{
    return impObj()->setMidOrdinateDistance(midOrdinateDist);
}

double PyBrxCvDbTinSurfaceConstraint::midOrdinateDistance() const
{
    return impObj()->midOrdinateDistance();
}

void PyBrxCvDbTinSurfaceConstraint::setIsDbResident(bool isResident)
{
    return impObj()->setIsDbResident(isResident);
}

bool PyBrxCvDbTinSurfaceConstraint::isDbResident() const
{
    return impObj()->isDbResident();
}

std::string PyBrxCvDbTinSurfaceConstraint::className()
{
    return "BrxCvDbTinSurfaceConstraint";
}

BrxCvDbTinSurfaceConstraint* PyBrxCvDbTinSurfaceConstraint::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceBreakline
void makePyBrxCvDbTinSurfaceBreaklineWrapper()
{
    PyDocString DS("CvDbTinSurfaceBreakline");
    class_<PyBrxCvDbTinSurfaceBreakline, bases<PyBrxCvDbTinSurfaceConstraint>>("CvDbTinSurfaceBreakline", no_init)
        .def(init<BrxCvDbTinSurfaceBreakline::ETinBreaklineType>(DS.ARGS({ "type: PyBrxCv.TinBreaklineType" })))
        .def("intersectionElevation", &PyBrxCvDbTinSurfaceBreakline::intersectionElevation, DS.ARGS())
        .def("setIntersectionElevation", &PyBrxCvDbTinSurfaceBreakline::setIntersectionElevation, DS.ARGS({ "val : PyBrxCv.TinBreaklineType" }))
        .def("className", &PyBrxCvDbTinSurfaceBreakline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxCvDbTinSurfaceBreakline::PyBrxCvDbTinSurfaceBreakline(BrxCvDbTinSurfaceBreakline::ETinBreaklineType type)
    :PyBrxCvDbTinSurfaceConstraint(new BrxCvDbTinSurfaceBreakline(type))
{
}

BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation PyBrxCvDbTinSurfaceBreakline::intersectionElevation() const
{
    return impObj()->intersectionElevation();
}

void PyBrxCvDbTinSurfaceBreakline::setIntersectionElevation(const BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation elevationType)
{
    return impObj()->setIntersectionElevation(elevationType);
}

std::string PyBrxCvDbTinSurfaceBreakline::className()
{
    return "BrxCvDbTinSurfaceBreakline";
}

BrxCvDbTinSurfaceBreakline* PyBrxCvDbTinSurfaceBreakline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceBreakline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceWall
void makePyBrxCvDbTinSurfaceWallWrapper()
{
    PyDocString DS("CvDbTinSurfaceWall");
    class_<PyBrxCvDbTinSurfaceWall, bases<PyBrxCvDbTinSurfaceConstraint>>("CvDbTinSurfaceWall", no_init)
        .def(init<BrxCvDbTinSurfaceWall::ETinWallType>(DS.ARGS({ "type: PyBrxCv.TinWallType" })))
        .def("wallType", &PyBrxCvDbTinSurfaceWall::wallType, DS.ARGS())
        .def("setHeight", &PyBrxCvDbTinSurfaceWall::setHeight, DS.ARGS({ "val : float" }))
        .def("setWallSide", &PyBrxCvDbTinSurfaceWall::setWallSide, DS.ARGS({ "val : PyBrxCv.TinWallSide" }))
        .def("wallSide", &PyBrxCvDbTinSurfaceWall::wallSide, DS.ARGS())
        .def("className", &PyBrxCvDbTinSurfaceWall::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxCvDbTinSurfaceWall::PyBrxCvDbTinSurfaceWall(BrxCvDbTinSurfaceWall::ETinWallType wallType)
    :PyBrxCvDbTinSurfaceConstraint(new BrxCvDbTinSurfaceWall(wallType))
{
}

BrxCvDbTinSurfaceWall::ETinWallType PyBrxCvDbTinSurfaceWall::wallType() const
{
    return impObj()->wallType();
}

double PyBrxCvDbTinSurfaceWall::height() const
{
    return impObj()->height();
}

void PyBrxCvDbTinSurfaceWall::setHeight(double height)
{
    return impObj()->setHeight(height);
}

void PyBrxCvDbTinSurfaceWall::setWallSide(BrxCvDbTinSurfaceWall::ETinWallSide side)
{
    return impObj()->setWallSide(side);
}

BrxCvDbTinSurfaceWall::ETinWallSide PyBrxCvDbTinSurfaceWall::wallSide() const
{
    return impObj()->wallSide();
}

std::string PyBrxCvDbTinSurfaceWall::className()
{
    return "BrxCvDbTinSurfaceWall";
}

BrxCvDbTinSurfaceWall* PyBrxCvDbTinSurfaceWall::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceWall*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceBoundary
void makePyBrxCvDbTinSurfaceBoundaryWrapper()
{
    PyDocString DS("CvDbTinSurfaceBoundary");
    class_<PyBrxCvDbTinSurfaceBoundary, bases<PyBrxCvDbTinSurfaceConstraint>>("CvDbTinSurfaceBoundary", no_init)
        .def(init<BrxCvDbTinSurfaceBoundary::ETinBoundaryType>(DS.ARGS({ "type: PyBrxCv.TinBoundaryType" })))
        .def("wallType", &PyBrxCvDbTinSurfaceBoundary::boundaryType, DS.ARGS())
        .def("className", &PyBrxCvDbTinSurfaceBoundary::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxCvDbTinSurfaceBoundary::PyBrxCvDbTinSurfaceBoundary(BrxCvDbTinSurfaceBoundary::ETinBoundaryType boundaryType)
    :PyBrxCvDbTinSurfaceConstraint(new BrxCvDbTinSurfaceBoundary(boundaryType))
{
}

BrxCvDbTinSurfaceBoundary::ETinBoundaryType PyBrxCvDbTinSurfaceBoundary::boundaryType() const
{
    return impObj()->boundaryType();
}

std::string PyBrxCvDbTinSurfaceBoundary::className()
{
    return "BrxCvDbTinSurfaceBoundary";
}

BrxCvDbTinSurfaceBoundary* PyBrxCvDbTinSurfaceBoundary::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurfaceBoundary*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurface
void makePyBrxCvDbTinSurfaceWrapper()
{
    PyDocString DS("CvDbTinSurface");
    class_<PyBrxCvDbTinSurface, bases<PyBrxCvDbEntity>>("CvDbTinSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("initialize", &PyBrxCvDbTinSurface::initialize, DS.ARGS({ "min : PyGe.Point3d" , "max : PyGe.Point3d","numOfPoints : int" }))
        .def("updateObjectData", &PyBrxCvDbTinSurface::updateObjectData, DS.ARGS())
        .def("addPoint", &PyBrxCvDbTinSurface::addPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("addPoints", &PyBrxCvDbTinSurface::addPoints, DS.ARGS({ "pts : list[PyGe.Point3d]" }))
        .def("removePoint", &PyBrxCvDbTinSurface::removePoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("removePoints", &PyBrxCvDbTinSurface::removePoints, DS.ARGS({ "pts : list[PyGe.Point3d]" }))
        .def("movePoint", &PyBrxCvDbTinSurface::movePoint, DS.ARGS({ "_from : PyGe.Point3d","_to : PyGe.Point3d" }))
        .def("movePoints", &PyBrxCvDbTinSurface::movePoints, DS.ARGS({ "_from : list[PyGe.Point3d]", "_to : list[PyGe.Point3d]" }))
        .def("swapEdge", &PyBrxCvDbTinSurface::swapEdge, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("setStyle", &PyBrxCvDbTinSurface::setStyle, DS.ARGS({ "style : PyBrxCv.TinSurfaceStyle" }))
        .def("setAssociative", &PyBrxCvDbTinSurface::setAssociative, DS.ARGS({ "isAssociative : bool" }))
        .def("raiseSurface", &PyBrxCvDbTinSurface::raiseSurface, DS.ARGS({ "offset : float" }))
        .def("setSurfaceElevation", &PyBrxCvDbTinSurface::setSurfaceElevation, DS.ARGS({ "elevation : float" }))
        .def("changePointsElevations", &PyBrxCvDbTinSurface::changePointsElevations, DS.ARGS({ "pts : list[PyGe.Point3d]","newZValues : list[float]" }))
        .def("setMinorContoursInterval", &PyBrxCvDbTinSurface::setMinorContoursInterval, DS.ARGS({ "interval : float" }))
        .def("setMajorContoursInterval", &PyBrxCvDbTinSurface::setMajorContoursInterval, DS.ARGS({ "interval : float" }))
        .def("setMinorContoursColor", &PyBrxCvDbTinSurface::setMinorContoursColor, DS.ARGS({ "colorIndex : int" }))
        .def("setMajorContoursColor", &PyBrxCvDbTinSurface::setMajorContoursColor, DS.ARGS({ "colorIndex : int" }))
        .def("merge", &PyBrxCvDbTinSurface::merge, DS.ARGS({ "other : PyBrxCv.CvDbTinSurface" }))
        .def("getPoints", &PyBrxCvDbTinSurface::getPoints, DS.ARGS({ "visibleOnly : bool=False" }), arg("visibleOnly") = false)
        .def("getTinPoints", &PyBrxCvDbTinSurface::getTinPoints, DS.ARGS())
        .def("findTinPointAt", &PyBrxCvDbTinSurface::findTinPointAt, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("triangles", &PyBrxCvDbTinSurface::triangles, DS.ARGS({ "visibleOnly : bool=False" }), arg("visibleOnly") = false)
        .def("tinTriangles", &PyBrxCvDbTinSurface::tinTriangles, DS.ARGS())
        .def("findTinTrianglesAt", &PyBrxCvDbTinSurface::findTinTrianglesAt, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("pointsCount", &PyBrxCvDbTinSurface::pointsCount, DS.ARGS({ "visibleOnly : bool=False" }), arg("visibleOnly") = false)
        .def("trianglesCount", &PyBrxCvDbTinSurface::trianglesCount, DS.ARGS({ "visibleOnly : bool=False" }), arg("visibleOnly") = false)
        .def("area2d", &PyBrxCvDbTinSurface::area2d, DS.ARGS({ "visibleOnly : bool=False" }), arg("visibleOnly") = false)
        .def("area3d", &PyBrxCvDbTinSurface::area3d, DS.ARGS({ "visibleOnly : bool=False" }), arg("visibleOnly") = false)
        .def("minElevation", &PyBrxCvDbTinSurface::minElevation, DS.ARGS({ "visibleOnly : bool=False" }), arg("visibleOnly") = false)
        .def("maxElevation", &PyBrxCvDbTinSurface::maxElevation, DS.ARGS({ "visibleOnly : bool=False" }), arg("visibleOnly") = false)
        .def("contains", &PyBrxCvDbTinSurface::contains, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("elevationAtPoint", &PyBrxCvDbTinSurface::elevationAtPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("closestPointTo", &PyBrxCvDbTinSurface::closestPointTo, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("boundingBox", &PyBrxCvDbTinSurface::boundingBox, DS.ARGS())
        .def("getPointsInsidePolygon", &PyBrxCvDbTinSurface::getPointsInsidePolygon, DS.ARGS({ "pts : list[PyGe.Point3d]" , "includeOnEdge : bool" }))
        .def("style", &PyBrxCvDbTinSurface::style, DS.ARGS())
        .def("isAssociative", &PyBrxCvDbTinSurface::isAssociative, DS.ARGS())
        .def("getBorders", &PyBrxCvDbTinSurface::getBorders, DS.ARGS())
        .def("minorContoursInterval", &PyBrxCvDbTinSurface::minorContoursInterval, DS.ARGS())
        .def("majorContoursInterval", &PyBrxCvDbTinSurface::majorContoursInterval, DS.ARGS())
        .def("minorContoursColor", &PyBrxCvDbTinSurface::minorContoursColor, DS.ARGS())
        .def("majorContoursColor", &PyBrxCvDbTinSurface::majorContoursColor, DS.ARGS())
        .def("minorContours", &PyBrxCvDbTinSurface::minorContours, DS.ARGS())
        .def("majorContours", &PyBrxCvDbTinSurface::majorContours, DS.ARGS())
        .def("contoursAtElevation", &PyBrxCvDbTinSurface::contoursAtElevation, DS.ARGS({ "elevation : float" }))
        .def("subDMesh", &PyBrxCvDbTinSurface::subDMesh1)//TODO DocStrings
        .def("subDMesh", &PyBrxCvDbTinSurface::subDMesh2)
        .def("subDMesh", &PyBrxCvDbTinSurface::subDMesh3)
        .def("solid3d", &PyBrxCvDbTinSurface::solid3d1)
        .def("solid3d", &PyBrxCvDbTinSurface::solid3d2)
        .def("drapePoint", &PyBrxCvDbTinSurface::drapePoint, DS.ARGS({ "pts : list[PyGe.Point3d]" }))
        .def("drapeId", &PyBrxCvDbTinSurface::drapeId, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("intersectionsWithLine", &PyBrxCvDbTinSurface::intersectionsWithLine, DS.ARGS({ "start : PyGe.Point3d","end : PyGe.Point3d", "type : PyBrxCv.TinSurfaceIntersectType","visibleOnly : bool" }))
        .def("getConstraints", &PyBrxCvDbTinSurface::getConstraints, DS.ARGS())
        .def("getConstraint", &PyBrxCvDbTinSurface::getConstraint1)
        .def("getConstraint", &PyBrxCvDbTinSurface::getConstraint2, DS.ARGS({ "id : PyDb.ObjectId|int" }))
        .def("addConstraint", &PyBrxCvDbTinSurface::addConstraint, DS.ARGS({ "constraint : PyBrxCv.CvDbTinSurfaceConstraint","addReactor : bool" }))
        .def("addConstraints", &PyBrxCvDbTinSurface::addConstraints, DS.ARGS({ "constraints : list[PyBrxCv.CvDbTinSurfaceConstraint]","addReactor : bool" }))
        .def("updateConstraint", &PyBrxCvDbTinSurface::updateConstraint, DS.ARGS({ "val : PyBrxCv.CvDbTinSurfaceConstraint" }))
        .def("eraseConstraint", &PyBrxCvDbTinSurface::eraseConstraint1)
        .def("eraseConstraint", &PyBrxCvDbTinSurface::eraseConstraint2, DS.ARGS({ "id : PyDb.ObjectId | int" ,"removeReactor : bool" }))
        .def("eraseConstraints", &PyBrxCvDbTinSurface::eraseConstraints, DS.ARGS({ "int64ids : list[int]","removeReactor : bool" }))
        .def("eraseConstraintsIds", &PyBrxCvDbTinSurface::eraseConstraintsIds, DS.ARGS({ "ids : list[PyDb.ObjectId]","removeReactor : bool" }))
        .def("hasSnapshot", &PyBrxCvDbTinSurface::hasSnapshot, DS.ARGS())
        .def("isSnapshotUpdateNeeded", &PyBrxCvDbTinSurface::isSnapshotUpdateNeeded, DS.ARGS())
        .def("createSnapshot", &PyBrxCvDbTinSurface::createSnapshot, DS.ARGS())
        .def("rebuildSnapshot", &PyBrxCvDbTinSurface::rebuildSnapshot, DS.ARGS())
        .def("removeSnapshot", &PyBrxCvDbTinSurface::removeSnapshot, DS.ARGS())
        .def("isUpdateNeeded", &PyBrxCvDbTinSurface::isUpdateNeeded, DS.ARGS())
        .def("isRebuildPossible", &PyBrxCvDbTinSurface::isRebuildPossible, DS.ARGS())
        .def("rebuild", &PyBrxCvDbTinSurface::rebuild, DS.ARGS({ "val : bool" }))
        .def("isAutoUpdate", &PyBrxCvDbTinSurface::isAutoUpdate, DS.ARGS())
        .def("setIsAutoUpdate", &PyBrxCvDbTinSurface::setIsAutoUpdate, DS.ARGS({ "autoUpdateOn : bool" }))
        .def("definitionCount", &PyBrxCvDbTinSurface::definitionCount, DS.ARGS())
        .def("addDefinition", &PyBrxCvDbTinSurface::addDefinition, DS.ARGS({ "ref : PyBrxCv.CvDbTinSurfaceDefinition" }))
        .def("insertDefinitionAt", &PyBrxCvDbTinSurface::insertDefinitionAt, DS.ARGS({ "index : int","ref : PyBrxCv.CvDbTinSurfaceDefinition" }))
        .def("definitionIndex", &PyBrxCvDbTinSurface::definitionIndex, DS.ARGS({ "ref : PyBrxCv.CvDbTinSurfaceDefinition" }))
        .def("definitionAt", &PyBrxCvDbTinSurface::definitionAt, DS.ARGS({ "index : int" }))
        .def("findDefinition", &PyBrxCvDbTinSurface::findDefinition, DS.ARGS({ "id : int" }))
        .def("moveDefinition", &PyBrxCvDbTinSurface::moveDefinition, DS.ARGS({ "_from : int","_to : int" }))
        .def("removeDefinitionAt", &PyBrxCvDbTinSurface::removeDefinitionAt, DS.ARGS({ " index: int" }))
        .def("removeAllDefinitions", &PyBrxCvDbTinSurface::removeAllDefinitions, DS.ARGS())

        .def("className", &PyBrxCvDbTinSurface::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurface::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbTinSurface::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbTinSurface::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurface::PyBrxCvDbTinSurface()
    : PyBrxCvDbTinSurface(new BrxCvDbTinSurface(), true)
{
}

PyBrxCvDbTinSurface::PyBrxCvDbTinSurface(const PyDbObjectId& id)
    : PyBrxCvDbTinSurface(openAcDbObject<BrxCvDbTinSurface>(id), false)
{
}

PyBrxCvDbTinSurface::PyBrxCvDbTinSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbTinSurface(openAcDbObject<BrxCvDbTinSurface>(id, mode), false)
{
}

PyBrxCvDbTinSurface::PyBrxCvDbTinSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbTinSurface(openAcDbObject<BrxCvDbTinSurface>(id, mode, erased), false)
{
}

PyBrxCvDbTinSurface::PyBrxCvDbTinSurface(BrxCvDbTinSurface* ptr, bool autoDelete)
    :PyBrxCvDbEntity(ptr, autoDelete)
{
}

void PyBrxCvDbTinSurface::initialize(const AcGePoint3d& minPt, const AcGePoint3d& maxPt, const size_t numOfPoints)
{
    return impObj()->initialize(minPt, maxPt, numOfPoints);
}

void PyBrxCvDbTinSurface::updateObjectData()
{
    return impObj()->updateObjectData();
}

bool PyBrxCvDbTinSurface::addPoint(const AcGePoint3d& point)
{
    return impObj()->addPoint(point);
}

bool PyBrxCvDbTinSurface::addPoints(const boost::python::list& points)
{
    return impObj()->addPoints(PyListToPoint3dArray(points));
}

bool PyBrxCvDbTinSurface::removePoint(const AcGePoint3d& point)
{
    return impObj()->removePoint(point);
}

bool PyBrxCvDbTinSurface::removePoints(const boost::python::list& points)
{
    return impObj()->removePoints(PyListToPoint3dArray(points));
}

bool PyBrxCvDbTinSurface::movePoint(const AcGePoint3d& from, const AcGePoint3d& to)
{
    return impObj()->movePoint(from, to);
}

bool PyBrxCvDbTinSurface::movePoints(const boost::python::list& from, const boost::python::list& to)
{
    return impObj()->movePoints(PyListToPoint3dArray(from), PyListToPoint3dArray(to));
}

bool PyBrxCvDbTinSurface::swapEdge(const AcGePoint3d& atPoint)
{
    return impObj()->swapEdge(atPoint);
}

bool PyBrxCvDbTinSurface::setStyle(const BrxCvDbTinSurface::ETinSurfaceStyle style)
{
    return impObj()->setStyle(style);
}

bool PyBrxCvDbTinSurface::setAssociative(bool isAssociative)
{
    return impObj()->setAssociative(isAssociative);
}

bool PyBrxCvDbTinSurface::raiseSurface(double offset)
{
    return impObj()->raiseSurface(offset);
}

bool PyBrxCvDbTinSurface::setSurfaceElevation(double elevation)
{
    return impObj()->setSurfaceElevation(elevation);
}

bool PyBrxCvDbTinSurface::changePointsElevations(const boost::python::list& points, const boost::python::list& newZValues)
{
    return impObj()->changePointsElevations(PyListToPoint3dArray(points), PyListToDoubleArray(newZValues));
}

bool PyBrxCvDbTinSurface::setMinorContoursInterval(double interval)
{
    return impObj()->setMinorContoursInterval(interval);
}

bool PyBrxCvDbTinSurface::setMajorContoursInterval(double interval)
{
    return impObj()->setMajorContoursInterval(interval);
}

bool PyBrxCvDbTinSurface::setMinorContoursColor(Adesk::UInt16 colorIndex)
{
    return impObj()->setMinorContoursColor(colorIndex);
}

bool PyBrxCvDbTinSurface::setMajorContoursColor(Adesk::UInt16 colorIndex)
{
    return impObj()->setMajorContoursColor(colorIndex);
}

bool PyBrxCvDbTinSurface::merge(const PyBrxCvDbTinSurface& theOther)
{
    return impObj()->merge(theOther.impObj());
}

boost::python::list PyBrxCvDbTinSurface::getPoints(bool visibleOnly) const
{
    AcGePoint3dArray points;
    impObj()->getPoints(points, visibleOnly);
    return Point3dArrayToPyList(points);
}

boost::python::list PyBrxCvDbTinSurface::getTinPoints() const
{
    BrxCvTinPointArray points;
    impObj()->getTinPoints(points);
    return TinPointArrayToPyList(points);
}

boost::python::tuple PyBrxCvDbTinSurface::findTinPointAt(const AcGePoint3d& pnt) const
{
    PyAutoLockGIL lock;
    BrxCvTinPoint tinPoint;
    bool flag = impObj()->findTinPointAt(tinPoint, pnt);
    return boost::python::make_tuple(flag, tinPoint);
}

boost::python::list PyBrxCvDbTinSurface::triangles(bool visibleOnly) const
{
    BrxCvDbTinSurface::TriangleArray triangles;
    impObj()->triangles(triangles);

    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : triangles)
        pylist.append(boost::python::make_tuple(item.m_p1, item.m_p2, item.m_p3));
    return pylist;
}

boost::python::list PyBrxCvDbTinSurface::tinTriangles() const
{
    BrxCvTinTriangleArray tinTriangles;
    impObj()->tinTriangles(tinTriangles);
    return TriangleArrayToPyList(tinTriangles);
}

boost::python::list PyBrxCvDbTinSurface::findTinTrianglesAt(const AcGePoint3d& pnt) const
{
    BrxCvTinTriangleArray tinTriangles;
    impObj()->findTinTrianglesAt(tinTriangles, pnt);
    return TriangleArrayToPyList(tinTriangles);
}

size_t PyBrxCvDbTinSurface::pointsCount(bool visibleOnly) const
{
    return impObj()->pointsCount(visibleOnly);
}

size_t PyBrxCvDbTinSurface::trianglesCount(bool visibleOnly) const
{
    return impObj()->trianglesCount(visibleOnly);
}

double PyBrxCvDbTinSurface::area2d(bool visibleOnly) const
{
    return impObj()->area2d(visibleOnly);
}

double PyBrxCvDbTinSurface::area3d(bool visibleOnly) const
{
    return impObj()->area3d(visibleOnly);
}

double PyBrxCvDbTinSurface::minElevation(bool visibleOnly) const
{
    return impObj()->minElevation(visibleOnly);
}

double PyBrxCvDbTinSurface::maxElevation(bool visibleOnly) const
{
    return impObj()->maxElevation(visibleOnly);
}

bool PyBrxCvDbTinSurface::contains(const AcGePoint3d& point) const
{
    return impObj()->contains(point);
}

boost::python::tuple PyBrxCvDbTinSurface::elevationAtPoint(const AcGePoint3d& point) const
{
    PyAutoLockGIL lock;
    double elevation = 0;
    bool flag = impObj()->elevationAtPoint(point, elevation);
    return boost::python::make_tuple(flag, elevation);
}

AcGePoint3d PyBrxCvDbTinSurface::closestPointTo(const AcGePoint3d& point) const
{
    return impObj()->closestPointTo(point);
}

boost::python::tuple PyBrxCvDbTinSurface::boundingBox() const
{
    PyAutoLockGIL lock;
    AcGePoint2d ptMin;
    AcGePoint2d ptMax;
    impObj()->boundingBox(ptMin, ptMax);
    return boost::python::make_tuple(ptMin, ptMax);
}

boost::python::list PyBrxCvDbTinSurface::getPointsInsidePolygon(const boost::python::list& polygon, bool includeOnEdge) const
{
    return Point3dArrayToPyList(impObj()->getPointsInsidePolygon(PyListToPoint3dArray(polygon), includeOnEdge));
}

BrxCvDbTinSurface::ETinSurfaceStyle PyBrxCvDbTinSurface::style() const
{
    return impObj()->style();
}

bool PyBrxCvDbTinSurface::isAssociative() const
{
    return impObj()->isAssociative();
}

boost::python::list PyBrxCvDbTinSurface::getBorders() const
{
    PyAutoLockGIL lock;
    AcArray<AcGePoint3dArray> borders;
    impObj()->getBorders(borders);
    boost::python::list pylist;
    for (const auto& item : borders)
        pylist.append(Point3dArrayToPyList(item));
    return pylist;
}

boost::python::tuple PyBrxCvDbTinSurface::minorContoursInterval()
{
    PyAutoLockGIL lock;
    double interval = 0;
    auto flag = impObj()->minorContoursInterval(interval);
    return boost::python::make_tuple(flag, interval);
}

boost::python::tuple PyBrxCvDbTinSurface::majorContoursInterval()
{
    PyAutoLockGIL lock;
    double interval = 0;
    auto flag = impObj()->majorContoursInterval(interval);
    return boost::python::make_tuple(flag, interval);
}

boost::python::tuple PyBrxCvDbTinSurface::minorContoursColor() const
{
    PyAutoLockGIL lock;
    Adesk::UInt16 colorIndex = 0;
    auto flag = impObj()->minorContoursColor(colorIndex);
    return boost::python::make_tuple(flag, colorIndex);
}

boost::python::tuple PyBrxCvDbTinSurface::majorContoursColor() const
{
    PyAutoLockGIL lock;
    Adesk::UInt16 colorIndex = 0;
    auto flag = impObj()->majorContoursColor(colorIndex);
    return boost::python::make_tuple(flag, colorIndex);
}

boost::python::list PyBrxCvDbTinSurface::minorContours() const
{
    PyAutoLockGIL lock;
    AcArray<AcGePoint3dArray> borders;
    impObj()->minorContours(borders);
    boost::python::list pylist;
    for (const auto& item : borders)
        pylist.append(Point3dArrayToPyList(item));
    return pylist;
}

boost::python::list PyBrxCvDbTinSurface::majorContours() const
{
    PyAutoLockGIL lock;
    AcArray<AcGePoint3dArray> borders;
    impObj()->majorContours(borders);
    boost::python::list pylist;
    for (const auto& item : borders)
        pylist.append(Point3dArrayToPyList(item));
    return pylist;
}

boost::python::list PyBrxCvDbTinSurface::contoursAtElevation(double elevation) const
{
    PyAutoLockGIL lock;
    AcArray<AcGePoint3dArray> borders;
    impObj()->contoursAtElevation(borders, elevation);
    boost::python::list pylist;
    for (const auto& item : borders)
        pylist.append(Point3dArrayToPyList(item));
    return pylist;
}

PyDbSubDMesh PyBrxCvDbTinSurface::subDMesh1(const BrxCvDbTinSurface::ETinSurfaceMeshType surfaceType, double depthOrElevation) const
{
    return PyDbSubDMesh(impObj()->subDMesh(surfaceType, depthOrElevation), true);
}

PyDbSubDMesh PyBrxCvDbTinSurface::subDMesh2(const PyBrxCvDbTinSurface& other) const
{
    return PyDbSubDMesh(impObj()->subDMesh(other.impObj()), true);
}

PyDbSubDMesh PyBrxCvDbTinSurface::subDMesh3() const
{
    return PyDbSubDMesh(impObj()->subDMesh(), true);
}

PyDb3dSolid PyBrxCvDbTinSurface::solid3d1(const BrxCvDbTinSurface::ETinSurfaceSolidType solidType, double thickness) const
{
    return PyDb3dSolid(impObj()->solid3d(solidType, thickness), true);
}

PyDb3dSolid PyBrxCvDbTinSurface::solid3d2(const PyBrxCvDbTinSurface& other) const
{
    return PyDb3dSolid(impObj()->solid3d(other.impObj()), true);
}

boost::python::list PyBrxCvDbTinSurface::drapePoint(const AcGePoint3dArray& points) const
{
    PyAutoLockGIL lock;
    AcArray<AcGePoint3dArray> borders;
    impObj()->drape(borders, points);
    boost::python::list pylist;
    for (const auto& item : borders)
        pylist.append(Point3dArrayToPyList(item));
    return pylist;
}

boost::python::list PyBrxCvDbTinSurface::drapeId(const PyDbObjectId& entId) const
{
    PyAutoLockGIL lock;
    AcArray<AcGePoint3dArray> borders;
    impObj()->drape(borders, entId.m_id);
    boost::python::list pylist;
    for (const auto& item : borders)
        pylist.append(Point3dArrayToPyList(item));
    return pylist;
}

boost::python::tuple PyBrxCvDbTinSurface::intersectionsWithLine(const AcGePoint3d& ptLineStart, const AcGePoint3d& ptLineEnd, BrxCvDbTinSurface::ETinSurfaceIntersectType type, bool visibleOnly) const
{
    PyAutoLockGIL lock;
    AcGePoint3dArray val;
    auto flag = impObj()->intersectionsWithLine(val, ptLineStart, ptLineEnd, type, visibleOnly);
    return boost::python::make_tuple(flag, Point3dArrayToPyList(val));
}

boost::python::list PyBrxCvDbTinSurface::getConstraints() const
{
    PyAutoLockGIL lock;
    BrxCvDbTinSurfaceConstraintArray constraints;
    impObj()->getConstraints(constraints);
    boost::python::list pylist;
    for (const auto& item : constraints)
        pylist.append(PyBrxCvDbTinSurfaceConstraint(item));
    return pylist;
}

PyBrxCvDbTinSurfaceConstraint PyBrxCvDbTinSurface::getConstraint1(const Adesk::UInt64 id) const
{
    return PyBrxCvDbTinSurfaceConstraint(impObj()->getConstraint(id));
}

PyBrxCvDbTinSurfaceConstraint PyBrxCvDbTinSurface::getConstraint2(const PyDbObjectId& id) const
{
    return PyBrxCvDbTinSurfaceConstraint(impObj()->getConstraint(id.m_id));
}

bool PyBrxCvDbTinSurface::addConstraint(const PyBrxCvDbTinSurfaceConstraint& constraint, bool addReactor)
{
    return impObj()->addConstraint(*constraint.impObj(), addReactor); (*constraint.impObj(), addReactor);
}

bool PyBrxCvDbTinSurface::addConstraints(const boost::python::list& constraints, bool addReactor)
{
    const auto& vec = py_list_to_std_vector<PyBrxCvDbTinSurfaceConstraint>(constraints);
    BrxCvDbTinSurfaceConstraintArray items;
    for (const auto& item : vec)
        items.append(BrxCvDbTinSurfaceConstraint(*item.impObj()));
    return impObj()->addConstraints(items, addReactor);
}

bool PyBrxCvDbTinSurface::updateConstraint(const PyBrxCvDbTinSurfaceConstraint& constraint)
{
    return impObj()->updateConstraint(*constraint.impObj());
}

bool PyBrxCvDbTinSurface::eraseConstraint1(const Adesk::UInt64 id, bool removeReactor)
{
    return impObj()->eraseConstraint(id, removeReactor);
}

bool PyBrxCvDbTinSurface::eraseConstraint2(const PyDbObjectId& entityId, bool removeReactor)
{
    return impObj()->eraseConstraint(entityId.m_id, removeReactor);
}

bool PyBrxCvDbTinSurface::eraseConstraints(const boost::python::list& ids, bool removeReactor)
{
    return impObj()->eraseConstraints(PyListToUInt64Array(ids), removeReactor);
}

bool PyBrxCvDbTinSurface::eraseConstraintsIds(const boost::python::list& ids, bool removeReactor)
{
    return impObj()->eraseConstraints(PyListToObjectIdArray(ids), removeReactor);
}

bool PyBrxCvDbTinSurface::hasSnapshot() const
{
    return impObj()->hasSnapshot();
}

bool PyBrxCvDbTinSurface::isSnapshotUpdateNeeded() const
{
    return impObj()->isSnapshotUpdateNeeded();
}

Adesk::UInt32 PyBrxCvDbTinSurface::createSnapshot()
{
    return impObj()->createSnapshot();
}

bool PyBrxCvDbTinSurface::rebuildSnapshot()
{
    return impObj()->rebuildSnapshot();
}

bool PyBrxCvDbTinSurface::removeSnapshot()
{
    return impObj()->removeSnapshot();
}

bool PyBrxCvDbTinSurface::isUpdateNeeded() const
{
    return impObj()->isUpdateNeeded();
}

bool PyBrxCvDbTinSurface::isRebuildPossible() const
{
    return impObj()->isRebuildPossible();
}

bool PyBrxCvDbTinSurface::rebuild(bool rebuildSnapshotIfNeeded)
{
    return impObj()->rebuild(rebuildSnapshotIfNeeded);
}

bool PyBrxCvDbTinSurface::isAutoUpdate() const
{
    return impObj()->isAutoUpdate();
}

bool PyBrxCvDbTinSurface::setIsAutoUpdate(bool autoUpdateOn)
{
    return impObj()->setIsAutoUpdate(autoUpdateOn);
}

Adesk::UInt32 PyBrxCvDbTinSurface::definitionCount() const
{
    return impObj()->definitionCount();
}

Adesk::UInt32 PyBrxCvDbTinSurface::addDefinition(const PyBrxCvDbTinSurfaceDefinition& surfaceDefinition)
{
    return impObj()->addDefinition(*surfaceDefinition.impObj());
}

Adesk::UInt32 PyBrxCvDbTinSurface::insertDefinitionAt(Adesk::UInt32 index, const PyBrxCvDbTinSurfaceDefinition& surfaceDefinition)
{

    return impObj()->insertDefinitionAt(index, *surfaceDefinition.impObj());
}

boost::python::tuple PyBrxCvDbTinSurface::definitionIndex(const PyBrxCvDbTinSurfaceDefinition& surfaceDefinition) const
{
    PyAutoLockGIL lock;
    Adesk::UInt32 val = 0;
    auto flag = impObj()->definitionIndex(*surfaceDefinition.impObj(), val);
    return boost::python::make_tuple(flag, val);
}

PyBrxCvDbTinSurfaceDefinition PyBrxCvDbTinSurface::definitionAt(const Adesk::UInt32 index) const
{
    auto ptr = impObj()->definitionAt(index);
    if (ptr.refCount() == 1)
        return PyBrxCvDbTinSurfaceDefinition(ptr.detach(), true);
    throw PyAcadErrorStatus(Acad::eInvalidOpenState);
}

PyBrxCvDbTinSurfaceDefinition PyBrxCvDbTinSurface::findDefinition(Adesk::UInt64 definitionId) const
{
    auto ptr = impObj()->findDefinition(definitionId);
    if (ptr.refCount() == 1)
        return PyBrxCvDbTinSurfaceDefinition(ptr.detach(), true);
    throw PyAcadErrorStatus(Acad::eInvalidOpenState);
}

Adesk::UInt32 PyBrxCvDbTinSurface::moveDefinition(const Adesk::UInt32 fromIndex, const Adesk::UInt32 toIndex)
{
    return impObj()->moveDefinition(fromIndex, toIndex);
}

bool PyBrxCvDbTinSurface::removeDefinitionAt(const Adesk::UInt32 index)
{
    return impObj()->removeDefinitionAt(index);
}

Adesk::UInt32 PyBrxCvDbTinSurface::removeAllDefinitions()
{
    return impObj()->removeAllDefinitions();
}

PyBrxCvDbTinSurface PyBrxCvDbTinSurface::mergeSurfaces(const PyBrxCvDbTinSurface& theOne, const PyBrxCvDbTinSurface& theOther)
{
    return PyBrxCvDbTinSurface(BrxCvDbTinSurface::merge(theOne.impObj(), theOther.impObj()), true);
}

std::string PyBrxCvDbTinSurface::className()
{
    return "BrxCvDbTinSurface";
}

PyRxClass PyBrxCvDbTinSurface::desc()
{
    return PyRxClass(BrxCvDbTinSurface::desc(), false);
}

PyBrxCvDbTinSurface PyBrxCvDbTinSurface::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbTinSurface::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbTinSurface(static_cast<BrxCvDbTinSurface*>(src.impObj()->clone()), true);
}

PyBrxCvDbTinSurface PyBrxCvDbTinSurface::cast(const PyRxObject& src)
{
    PyBrxCvDbTinSurface dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbTinSurface* PyBrxCvDbTinSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbTinSurface*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbVolumeSurface
void makePyBrxCvDbVolumeSurfaceWrapper()
{
    PyDocString DS("CvDbVolumeSurface");
    class_<PyBrxCvDbVolumeSurface, bases<PyBrxCvDbTinSurface>>("CvDbVolumeSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("initialize1", &PyBrxCvDbVolumeSurface::initialize1)
        .def("initialize2", &PyBrxCvDbVolumeSurface::initialize2)
        .def("initialize3", &PyBrxCvDbVolumeSurface::initialize3)
        .def("initialize4", &PyBrxCvDbVolumeSurface::initialize4)

        .def("type", &PyBrxCvDbVolumeSurface::type, DS.ARGS())
        .def("baseSurfaceObjectId", &PyBrxCvDbVolumeSurface::baseSurfaceObjectId, DS.ARGS())
        .def("comparisonSurfaceObjectId", &PyBrxCvDbVolumeSurface::comparisonSurfaceObjectId, DS.ARGS())
        .def("boundingPolygonObjectId", &PyBrxCvDbVolumeSurface::boundingPolygonObjectId, DS.ARGS())
        .def("boundingPolygon", &PyBrxCvDbVolumeSurface::boundingPolygon, DS.ARGS())
        .def("fillVolume", &PyBrxCvDbVolumeSurface::fillVolume, DS.ARGS())
        .def("cutVolume", &PyBrxCvDbVolumeSurface::cutVolume, DS.ARGS())
        .def("depthElevation", &PyBrxCvDbVolumeSurface::depthElevation, DS.ARGS())

        .def("className", &PyBrxCvDbVolumeSurface::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbVolumeSurface::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbVolumeSurface::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbVolumeSurface::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbVolumeSurface::PyBrxCvDbVolumeSurface()
    : PyBrxCvDbVolumeSurface(new BrxCvDbVolumeSurface(), true)
{
}

PyBrxCvDbVolumeSurface::PyBrxCvDbVolumeSurface(const PyDbObjectId& id)
    : PyBrxCvDbVolumeSurface(openAcDbObject<BrxCvDbVolumeSurface>(id), false)
{
}

PyBrxCvDbVolumeSurface::PyBrxCvDbVolumeSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbVolumeSurface(openAcDbObject<BrxCvDbVolumeSurface>(id, mode), false)
{
}

PyBrxCvDbVolumeSurface::PyBrxCvDbVolumeSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbVolumeSurface(openAcDbObject<BrxCvDbVolumeSurface>(id, mode, erased), false)
{
}

PyBrxCvDbVolumeSurface::PyBrxCvDbVolumeSurface(BrxCvDbVolumeSurface* ptr, bool autoDelete)
    :PyBrxCvDbTinSurface(ptr, autoDelete)
{
}

bool PyBrxCvDbVolumeSurface::initialize1(const PyBrxCvDbTinSurface& baseSurface, const PyBrxCvDbTinSurface& compSurface, const boost::python::list& boundingPolygon)
{
    return impObj()->initialize(baseSurface.impObj(), compSurface.impObj(), PyListToPoint3dArray(boundingPolygon));
}

bool PyBrxCvDbVolumeSurface::initialize2(const PyBrxCvDbTinSurface& baseSurface, const PyBrxCvDbTinSurface& compSurface, const PyDbObjectId& boundingPolygonId, double midOrdinateDist)
{
    return impObj()->initialize(baseSurface.impObj(), compSurface.impObj(), boundingPolygonId.m_id, midOrdinateDist);
}

bool PyBrxCvDbVolumeSurface::initialize3(const PyBrxCvDbTinSurface& baseSurface, double referenceElevation, BrxCvDbVolumeSurface::EVolumeSurfaceType type, const boost::python::list& boundingPolygon)
{
    return impObj()->initialize(baseSurface.impObj(), referenceElevation, type, PyListToPoint3dArray(boundingPolygon));
}

bool PyBrxCvDbVolumeSurface::initialize4(const PyBrxCvDbTinSurface& baseSurface, double referenceElevation, BrxCvDbVolumeSurface::EVolumeSurfaceType type, const PyDbObjectId& boundingPolygonId, double midOrdinateDist)
{
    return impObj()->initialize(baseSurface.impObj(), referenceElevation, type, boundingPolygonId.m_id, midOrdinateDist);
}

BrxCvDbVolumeSurface::EVolumeSurfaceType PyBrxCvDbVolumeSurface::type() const
{
    return impObj()->type();
}

PyDbObjectId PyBrxCvDbVolumeSurface::baseSurfaceObjectId() const
{
    return PyDbObjectId(impObj()->baseSurfaceObjectId());
}

PyDbObjectId PyBrxCvDbVolumeSurface::comparisonSurfaceObjectId() const
{
    return PyDbObjectId(impObj()->comparisonSurfaceObjectId());
}

PyDbObjectId PyBrxCvDbVolumeSurface::boundingPolygonObjectId() const
{
    return PyDbObjectId(impObj()->boundingPolygonObjectId());
}

boost::python::list PyBrxCvDbVolumeSurface::boundingPolygon() const
{
    return Point3dArrayToPyList(impObj()->boundingPolygon());
}

double PyBrxCvDbVolumeSurface::fillVolume() const
{
    return impObj()->fillVolume();
}

double PyBrxCvDbVolumeSurface::cutVolume() const
{
    return impObj()->cutVolume();
}

double PyBrxCvDbVolumeSurface::depthElevation() const
{
    return impObj()->depthElevation();
}

std::string PyBrxCvDbVolumeSurface::className()
{
    return "BrxCvDbVolumeSurface";
}

PyRxClass PyBrxCvDbVolumeSurface::desc()
{
    return PyRxClass(BrxCvDbVolumeSurface::desc(), false);
}

PyBrxCvDbVolumeSurface PyBrxCvDbVolumeSurface::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbVolumeSurface::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbVolumeSurface(static_cast<BrxCvDbVolumeSurface*>(src.impObj()->clone()), true);
}

PyBrxCvDbVolumeSurface PyBrxCvDbVolumeSurface::cast(const PyRxObject& src)
{
    PyBrxCvDbVolumeSurface dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbVolumeSurface* PyBrxCvDbVolumeSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbVolumeSurface*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbGrading
void makePyBrxCvDbGradingWrapper()
{
    PyDocString DS("CvDbGrading");
    class_<PyBrxCvDbGrading, bases<PyBrxCvDbEntity>>("CvDbGrading")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("update", &PyBrxCvDbGrading::update, DS.ARGS({ "val : bool" }))
        .def("setInputDataId", &PyBrxCvDbGrading::setInputDataId, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("setInputData", &PyBrxCvDbGrading::setInputData, DS.ARGS({ "curve: PyGe.Curve3d" }))
        .def("getInputEntityId", &PyBrxCvDbGrading::getInputEntityId, DS.ARGS())
        .def("rule", &PyBrxCvDbGrading::rule, DS.ARGS())
        .def("setRule", &PyBrxCvDbGrading::setRule, DS.ARGS({ "val : PyBrxCv.CvGradingRule" }))
        .def("isClosed", &PyBrxCvDbGrading::isClosed, DS.ARGS())
        .def("targetSurface", &PyBrxCvDbGrading::targetSurface, DS.ARGS())
        .def("resultDayLight", &PyBrxCvDbGrading::resultDayLight, DS.ARGS())
        .def("getCalculationCurve", &PyBrxCvDbGrading::getCalculationCurve, DS.ARGS())
        .def("getCalculationMethod", &PyBrxCvDbGrading::getCalculationMethod, DS.ARGS())
        .def("setCalculationMethod", &PyBrxCvDbGrading::setCalculationMethod, DS.ARGS({ "val : PyBrxCv.GradingCalculationMethod" }))
        .def("getRegionStart", &PyBrxCvDbGrading::getRegionStart, DS.ARGS())
        .def("setRegionStart", &PyBrxCvDbGrading::setRegionStart, DS.ARGS({ "val : float" }))
        .def("getRegionEnd", &PyBrxCvDbGrading::getRegionEnd, DS.ARGS())
        .def("setRegionEnd", &PyBrxCvDbGrading::setRegionEnd, DS.ARGS({ "val : float" }))
        .def("getIsDrawInfill", &PyBrxCvDbGrading::getIsDrawInfill, DS.ARGS())
        .def("setDrawInfill", &PyBrxCvDbGrading::setDrawInfill, DS.ARGS({ "val : bool" }))
        .def("getSegmentMaxLength", &PyBrxCvDbGrading::getSegmentMaxLength, DS.ARGS())
        .def("setSegmentMaxLength", &PyBrxCvDbGrading::setSegmentMaxLength, DS.ARGS({ "val : float" }))
        .def("getSegmentMaxAngle", &PyBrxCvDbGrading::getSegmentMaxAngle, DS.ARGS())
        .def("setSegmentMaxAngle", &PyBrxCvDbGrading::setSegmentMaxAngle, DS.ARGS({ "val : float" }))
        .def("getMidOrdinateDist", &PyBrxCvDbGrading::getMidOrdinateDist, DS.ARGS())
        .def("setMidOrdinateDist", &PyBrxCvDbGrading::setMidOrdinateDist, DS.ARGS({ "val : float" }))
        .def("getIsAssociative", &PyBrxCvDbGrading::getIsAssociative, DS.ARGS())
        .def("setIsAssociative", &PyBrxCvDbGrading::setIsAssociative, DS.ARGS({ "val : bool" }))
        .def("getGradingVisualStyle", &PyBrxCvDbGrading::getGradingVisualStyle, DS.ARGS())
        .def("setGradingVisualStyle", &PyBrxCvDbGrading::setGradingVisualStyle, DS.ARGS({ "val : PyBrxCv.GradingVisualStyle" }))

        .def("className", &PyBrxCvDbGrading::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbGrading::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbGrading::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbGrading::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbGrading::PyBrxCvDbGrading()
    : PyBrxCvDbGrading(new BrxCvDbGrading(), true)
{
}

PyBrxCvDbGrading::PyBrxCvDbGrading(const PyDbObjectId& id)
    : PyBrxCvDbGrading(openAcDbObject<BrxCvDbGrading>(id), false)
{
}

PyBrxCvDbGrading::PyBrxCvDbGrading(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbGrading(openAcDbObject<BrxCvDbGrading>(id, mode), false)
{
}

PyBrxCvDbGrading::PyBrxCvDbGrading(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbGrading(openAcDbObject<BrxCvDbGrading>(id, mode, erased), false)
{
}

PyBrxCvDbGrading::PyBrxCvDbGrading(BrxCvDbGrading* ptr, bool autoDelete)
    :PyBrxCvDbTinSurface(ptr, autoDelete)
{
}

BrxCvDbGrading::EGradingStatus PyBrxCvDbGrading::update(bool forceUpdate)
{
    return impObj()->update(forceUpdate);
}

BrxCvDbGrading::EGradingStatus PyBrxCvDbGrading::setInputDataId(const PyDbObjectId& id)
{
    return impObj()->setInputData(id.m_id);
}

BrxCvDbGrading::EGradingStatus PyBrxCvDbGrading::setInputData(const PyDbCurve& pCurve)
{
    return impObj()->setInputData(pCurve.impObj());
}

PyDbObjectId PyBrxCvDbGrading::getInputEntityId() const
{
    return PyDbObjectId(impObj()->getInputEntityId());
}

PyBrxCvGradingRule PyBrxCvDbGrading::rule() const
{
    return PyBrxCvGradingRule{ impObj()->rule() };
}

BrxCvDbGrading::EGradingStatus PyBrxCvDbGrading::setRule(const PyBrxCvGradingRule& rule) const
{
    return impObj()->setRule(*rule.impObj());
}

bool PyBrxCvDbGrading::isClosed() const
{
    return impObj()->isClosed();
}

PyDbObjectId PyBrxCvDbGrading::targetSurface() const
{
    return PyDbObjectId(impObj()->targetSurface());
}

boost::python::list PyBrxCvDbGrading::resultDayLight() const
{
    PyAutoLockGIL lock;
    AcArray<AcGePoint3dArray> contours;
    impObj()->resultDayLight(contours);
    boost::python::list pylist;
    for (const auto& item : contours)
        pylist.append(Point3dArrayToPyList(item));
    return pylist;
}

PyGeCurve3d PyBrxCvDbGrading::getCalculationCurve() const
{
    return PyGeCurve3d(impObj()->getCalculationCurve());
}

BrxCvDbGrading::EGradingCalculationMethod PyBrxCvDbGrading::getCalculationMethod() const
{
    return impObj()->getCalculationMethod();
}

bool PyBrxCvDbGrading::setCalculationMethod(BrxCvDbGrading::EGradingCalculationMethod method)
{
    return impObj()->setCalculationMethod(method);
}

double PyBrxCvDbGrading::getRegionStart() const
{
    return impObj()->getRegionStart();
}

BrxCvDbGrading::EGradingStatus PyBrxCvDbGrading::setRegionStart(double startParam)
{
    return impObj()->setRegionStart(startParam);
}

double PyBrxCvDbGrading::getRegionEnd() const
{
    return impObj()->getRegionEnd();
}

BrxCvDbGrading::EGradingStatus PyBrxCvDbGrading::setRegionEnd(double endParam)
{
    return impObj()->setRegionEnd(endParam);
}

bool PyBrxCvDbGrading::getIsDrawInfill() const
{
    return impObj()->getIsDrawInfill();
}

BrxCvDbGrading::EGradingStatus PyBrxCvDbGrading::setDrawInfill(bool drawInfill)
{
    return impObj()->setDrawInfill(drawInfill);
}

double PyBrxCvDbGrading::getSegmentMaxLength() const
{
    return impObj()->getSegmentMaxLength();
}

BrxCvDbGrading::EGradingStatus PyBrxCvDbGrading::setSegmentMaxLength(double maxLength)
{
    return impObj()->setSegmentMaxLength(maxLength);
}

double PyBrxCvDbGrading::getSegmentMaxAngle() const
{
    return impObj()->getSegmentMaxAngle();
}

BrxCvDbGrading::EGradingStatus PyBrxCvDbGrading::setSegmentMaxAngle(double maxAngle)
{
    return impObj()->setSegmentMaxAngle(maxAngle);
}

double PyBrxCvDbGrading::getMidOrdinateDist() const
{
    return impObj()->getMidOrdinateDist();
}

BrxCvDbGrading::EGradingStatus PyBrxCvDbGrading::setMidOrdinateDist(double midOrdinateDist)
{
    return impObj()->setMidOrdinateDist(midOrdinateDist);
}

bool PyBrxCvDbGrading::getIsAssociative() const
{
    return impObj()->getIsAssociative();
}

bool PyBrxCvDbGrading::setIsAssociative(bool associative)
{
    return impObj()->setIsAssociative(associative);
}

BrxCvDbGrading::EGradingVisualStyle PyBrxCvDbGrading::getGradingVisualStyle() const
{
    return impObj()->getGradingVisualStyle();
}

bool PyBrxCvDbGrading::setGradingVisualStyle(BrxCvDbGrading::EGradingVisualStyle style)
{
    return impObj()->setGradingVisualStyle(style);
}

std::string PyBrxCvDbGrading::className()
{
    return "BrxCvDbGrading";
}

PyRxClass PyBrxCvDbGrading::desc()
{
    return PyRxClass(BrxCvDbGrading::desc(), false);
}

PyBrxCvDbGrading PyBrxCvDbGrading::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(BrxCvDbGrading::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyBrxCvDbGrading(static_cast<BrxCvDbGrading*>(src.impObj()->clone()), true);
}

PyBrxCvDbGrading PyBrxCvDbGrading::cast(const PyRxObject& src)
{
    PyBrxCvDbGrading dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

BrxCvDbGrading* PyBrxCvDbGrading::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvDbGrading*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvGradingRule
void makePyBrxCvGradingRuleWrapper()
{
    PyDocString DS("CvGradingRule");
    class_<PyBrxCvGradingRule>("CvGradingRule")
        .def(init<>())
        .def("release", &PyBrxCvGradingRule::release, DS.ARGS())
        .def("isNull", &PyBrxCvGradingRule::isNull, DS.ARGS())
        .def("type", &PyBrxCvGradingRule::type, DS.ARGS())
        .def("slopeFormat", &PyBrxCvGradingRule::slopeFormat, DS.ARGS())
        .def("setSlopeFormat", &PyBrxCvGradingRule::setSlopeFormat, DS.ARGS({ "format : int" }))
        .def("side", &PyBrxCvGradingRule::side, DS.ARGS())
        .def("setSide", &PyBrxCvGradingRule::setSide, DS.ARGS({ "format : int" }))
        .def("convertSlopeToRad", &PyBrxCvGradingRule::convertSlopeToRad, DS.SARGS()).staticmethod("convertSlopeToRad")
        .def("convertRadToSlope", &PyBrxCvGradingRule::convertRadToSlope, DS.SARGS()).staticmethod("convertRadToSlope")
        .def("className", &PyBrxCvGradingRule::className, DS.SARGS()).staticmethod("className")
        .def("cast", &PyBrxCvGradingRule::cast, DS.SARGS({ "otherObject: PyBrxCv.CvGradingRule" })).staticmethod("cast")
        ;
}

PyBrxCvGradingRule::PyBrxCvGradingRule()
    :PyBrxCvGradingRule(new BrxCvGradingRule())
{
}

PyBrxCvGradingRule::PyBrxCvGradingRule(const BrxCvGradingRule& other)
    :PyBrxCvGradingRule(new BrxCvGradingRule(other))
{
}

PyBrxCvGradingRule::PyBrxCvGradingRule(BrxCvGradingRule* ptr)
    : m_pyImp(ptr)
{
}

bool PyBrxCvGradingRule::release()
{
    return impObj()->release();
}

bool PyBrxCvGradingRule::isNull() const
{
    return impObj()->isNull();
}

BrxCvGradingRule::EGradingType PyBrxCvGradingRule::type() const
{
    return impObj()->type();
}

BrxCvGradingRule::EGradingSlopeFormat PyBrxCvGradingRule::slopeFormat() const
{
    return impObj()->slopeFormat();
}

bool PyBrxCvGradingRule::setSlopeFormat(BrxCvGradingRule::EGradingSlopeFormat format)
{
    return impObj()->setSlopeFormat(format);
}

BrxCvGradingRule::EGradingSide PyBrxCvGradingRule::side() const
{
    return impObj()->side();
}

bool PyBrxCvGradingRule::setSide(const BrxCvGradingRule::EGradingSide side)
{
    return impObj()->setSide(side);
}

double PyBrxCvGradingRule::convertSlopeToRad(BrxCvGradingRule::EGradingSlopeFormat format, double slope)
{
    return BrxCvGradingRule::convertSlopeToRad(format, slope);
}

double PyBrxCvGradingRule::convertRadToSlope(BrxCvGradingRule::EGradingSlopeFormat format, double angle)
{
    return BrxCvGradingRule::convertRadToSlope(format, angle);
}

PyBrxCvGradingRule PyBrxCvGradingRule::cast(const PyBrxCvGradingRule& src)
{
    PyBrxCvGradingRule dest(nullptr);
    PyBrxCvGradingRule rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

std::string PyBrxCvGradingRule::className()
{
    return "BrxCvGradingRule";
}

BrxCvGradingRule* PyBrxCvGradingRule::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvGradingRule*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvGradingSlopeSurfaceRule
void makePyBrxCvGradingSlopeSurfaceRuleWrapper()
{
    PyDocString DS("CvGradingSlopeSurfaceRule");
    class_<PyBrxCvGradingSlopeSurfaceRule, bases<PyBrxCvGradingRule>>("CvGradingSlopeSurfaceRule")
        .def(init<>())
        .def(init<const PyDbObjectId&, double, double>())
        .def("surfaceId", &PyBrxCvGradingSlopeSurfaceRule::surfaceId, DS.ARGS())
        .def("setSurfaceId", &PyBrxCvGradingSlopeSurfaceRule::setSurfaceId, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("cutSlope", &PyBrxCvGradingSlopeSurfaceRule::cutSlope, DS.ARGS())
        .def("setCutSlope", &PyBrxCvGradingSlopeSurfaceRule::setCutSlope, DS.ARGS({ "val : float" }))
        .def("fillSlope", &PyBrxCvGradingSlopeSurfaceRule::fillSlope, DS.ARGS())
        .def("setFillSlope", &PyBrxCvGradingSlopeSurfaceRule::setFillSlope, DS.ARGS({ "val : float" }))
        .def("className", &PyBrxCvGradingSlopeSurfaceRule::className, DS.SARGS()).staticmethod("className")
        .def("cast", &PyBrxCvGradingSlopeSurfaceRule::cast, DS.SARGS({ "otherObject: PyBrxCv.CvGradingRule" })).staticmethod("cast")
        ;
}

PyBrxCvGradingSlopeSurfaceRule::PyBrxCvGradingSlopeSurfaceRule()
{
}

PyBrxCvGradingSlopeSurfaceRule::PyBrxCvGradingSlopeSurfaceRule(const PyDbObjectId& surfId, double cutSlope, double fillSlope)
    :PyBrxCvGradingSlopeSurfaceRule(new BrxCvGradingSlopeSurfaceRule(surfId.m_id, cutSlope, fillSlope))
{
}

PyBrxCvGradingSlopeSurfaceRule::PyBrxCvGradingSlopeSurfaceRule(BrxCvGradingSlopeSurfaceRule* ptr)
    :PyBrxCvGradingRule(ptr)
{
}

PyDbObjectId PyBrxCvGradingSlopeSurfaceRule::surfaceId() const
{
    return impObj()->surfaceId();
}

bool PyBrxCvGradingSlopeSurfaceRule::setSurfaceId(const PyDbObjectId& surfId)
{
    return impObj()->setSurfaceId(surfId.m_id);
}

double PyBrxCvGradingSlopeSurfaceRule::cutSlope() const
{
    return impObj()->cutSlope();
}

bool PyBrxCvGradingSlopeSurfaceRule::setCutSlope(double cutSlope)
{
    return impObj()->setCutSlope(cutSlope);
}

double PyBrxCvGradingSlopeSurfaceRule::fillSlope() const
{
    return impObj()->fillSlope();
}

bool PyBrxCvGradingSlopeSurfaceRule::setFillSlope(double fillSlope)
{
    return impObj()->setFillSlope(fillSlope);
}

PyBrxCvGradingSlopeSurfaceRule PyBrxCvGradingSlopeSurfaceRule::cast(const PyBrxCvGradingRule& src)
{
    PyBrxCvGradingSlopeSurfaceRule dest(nullptr);
    PyBrxCvGradingRule rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

std::string PyBrxCvGradingSlopeSurfaceRule::className()
{
    return "BrxCvGradingSlopeSurfaceRule";
}

BrxCvGradingSlopeSurfaceRule* PyBrxCvGradingSlopeSurfaceRule::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvGradingSlopeSurfaceRule*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvGradingSlopeOffsetRule
void makePyBrxCvGradingSlopeOffsetRule()
{
    PyDocString DS("CvGradingSlopeOffsetRule");
    class_<PyBrxCvGradingSlopeOffsetRule, bases<PyBrxCvGradingRule>>("CvGradingSlopeOffsetRule")
        .def(init<>())
        .def(init<double, double>())
        .def("slope", &PyBrxCvGradingSlopeOffsetRule::slope, DS.ARGS())
        .def("setSlope", &PyBrxCvGradingSlopeOffsetRule::setSlope, DS.ARGS({ "slope : float" }))
        .def("offset", &PyBrxCvGradingSlopeOffsetRule::offset, DS.ARGS())
        .def("setOffset", &PyBrxCvGradingSlopeOffsetRule::setOffset, DS.ARGS({ "offset : float" }))
        .def("className", &PyBrxCvGradingSlopeOffsetRule::className, DS.SARGS()).staticmethod("className")
        .def("cast", &PyBrxCvGradingSlopeOffsetRule::cast, DS.SARGS({ "otherObject: PyBrxCv.CvGradingRule" })).staticmethod("cast")
        ;
}

PyBrxCvGradingSlopeOffsetRule::PyBrxCvGradingSlopeOffsetRule()
    :PyBrxCvGradingSlopeOffsetRule(new BrxCvGradingSlopeOffsetRule())
{
}

PyBrxCvGradingSlopeOffsetRule::PyBrxCvGradingSlopeOffsetRule(double slope, double offset)
    :PyBrxCvGradingSlopeOffsetRule(new BrxCvGradingSlopeOffsetRule(slope, offset))
{
}

PyBrxCvGradingSlopeOffsetRule::PyBrxCvGradingSlopeOffsetRule(BrxCvGradingSlopeOffsetRule* ptr)
    :PyBrxCvGradingRule(ptr)
{
}

double PyBrxCvGradingSlopeOffsetRule::slope() const
{
    return impObj()->slope();
}

bool PyBrxCvGradingSlopeOffsetRule::setSlope(double slope)
{
    return impObj()->setSlope(slope);
}

double PyBrxCvGradingSlopeOffsetRule::offset() const
{
    return impObj()->offset();
}

bool PyBrxCvGradingSlopeOffsetRule::setOffset(double offset)
{
    return impObj()->setOffset(offset);
}

PyBrxCvGradingSlopeOffsetRule PyBrxCvGradingSlopeOffsetRule::cast(const PyBrxCvGradingRule& src)
{
    PyBrxCvGradingSlopeOffsetRule dest(nullptr);
    PyBrxCvGradingRule rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

std::string PyBrxCvGradingSlopeOffsetRule::className()
{
    return "BrxCvGradingSlopeOffsetRule";
}

BrxCvGradingSlopeOffsetRule* PyBrxCvGradingSlopeOffsetRule::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BrxCvGradingSlopeOffsetRule*>(m_pyImp.get());
}
#endif//BRXAPP