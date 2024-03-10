#include "stdafx.h"
#include "PyBrxCvDbTinSurface.h"
#include "PyBrxCvDbTinSurfaceDef.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceConstraint
void makePyBrxCvDbTinSurfaceConstraintWrapper()
{
    PyDocString DS("CvDbTinSurfaceConstraint");
    class_<PyBrxCvDbTinSurfaceConstraint>("CvDbTinSurfaceConstraint")
        .def(init<>())
        .def(init<BrxCvDbTinSurfaceConstraint::ETinConstraintType>())
        .def("constraintType", &BrxCvDbTinSurfaceConstraint::constraintType, DS.ARGS())
        .def("setData", &PyBrxCvDbTinSurfaceConstraint::setData1, DS.ARGS({ "val : int" ,"pts : list[PyGe.Point3d]" }))
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
        .def(init<BrxCvDbTinSurfaceBreakline::ETinBreaklineType>())
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
        .def(init<BrxCvDbTinSurfaceWall::ETinWallType>())
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
        .def(init<BrxCvDbTinSurfaceBoundary::ETinBoundaryType>())
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=kForRead", "erased: bool=False" })))

        .def("initialize", &PyBrxCvDbTinSurface::initialize)
        .def("updateObjectData", &PyBrxCvDbTinSurface::updateObjectData)
        .def("addPoint", &PyBrxCvDbTinSurface::addPoint)
        .def("addPoints", &PyBrxCvDbTinSurface::addPoints)
        .def("removePoint", &PyBrxCvDbTinSurface::removePoint)
        .def("removePoints", &PyBrxCvDbTinSurface::removePoints)
        .def("movePoint", &PyBrxCvDbTinSurface::movePoint)
        .def("movePoints", &PyBrxCvDbTinSurface::movePoints)
        .def("swapEdge", &PyBrxCvDbTinSurface::swapEdge)
        .def("setStyle", &PyBrxCvDbTinSurface::setStyle)
        .def("setAssociative", &PyBrxCvDbTinSurface::setAssociative)
        .def("raiseSurface", &PyBrxCvDbTinSurface::raiseSurface)
        .def("setSurfaceElevation", &PyBrxCvDbTinSurface::setSurfaceElevation)
        .def("changePointsElevations", &PyBrxCvDbTinSurface::changePointsElevations)
        .def("setMinorContoursInterval", &PyBrxCvDbTinSurface::setMinorContoursInterval)
        .def("setMajorContoursInterval", &PyBrxCvDbTinSurface::setMajorContoursInterval)
        .def("setMinorContoursColor", &PyBrxCvDbTinSurface::setMinorContoursColor)
        .def("setMajorContoursColor", &PyBrxCvDbTinSurface::setMajorContoursColor)
        .def("merge", &PyBrxCvDbTinSurface::merge)
        .def("getPoints", &PyBrxCvDbTinSurface::getPoints)
        .def("getTinPoints", &PyBrxCvDbTinSurface::getTinPoints)
        .def("findTinPointAt", &PyBrxCvDbTinSurface::findTinPointAt)
        .def("triangles", &PyBrxCvDbTinSurface::triangles)
        .def("tinTriangles", &PyBrxCvDbTinSurface::tinTriangles)
        .def("findTinTrianglesAt", &PyBrxCvDbTinSurface::findTinTrianglesAt)
        .def("pointsCount", &PyBrxCvDbTinSurface::pointsCount)
        .def("trianglesCount", &PyBrxCvDbTinSurface::trianglesCount)
        .def("area2d", &PyBrxCvDbTinSurface::area2d)
        .def("area3d", &PyBrxCvDbTinSurface::area3d)
        .def("minElevation", &PyBrxCvDbTinSurface::minElevation)
        .def("maxElevation", &PyBrxCvDbTinSurface::maxElevation)
        .def("contains", &PyBrxCvDbTinSurface::contains)
        .def("elevationAtPoint", &PyBrxCvDbTinSurface::elevationAtPoint)
        .def("closestPointTo", &PyBrxCvDbTinSurface::closestPointTo)
        .def("boundingBox", &PyBrxCvDbTinSurface::boundingBox)
        .def("getPointsInsidePolygon", &PyBrxCvDbTinSurface::getPointsInsidePolygon)
        .def("style", &PyBrxCvDbTinSurface::style)
        .def("isAssociative", &PyBrxCvDbTinSurface::isAssociative)
        .def("getBorders", &PyBrxCvDbTinSurface::getBorders)
        .def("minorContoursInterval", &PyBrxCvDbTinSurface::minorContoursInterval)
        .def("majorContoursInterval", &PyBrxCvDbTinSurface::majorContoursInterval)
        .def("minorContoursColor", &PyBrxCvDbTinSurface::minorContoursColor)
        .def("majorContoursColor", &PyBrxCvDbTinSurface::majorContoursColor)
        .def("minorContours", &PyBrxCvDbTinSurface::minorContours)
        .def("majorContours", &PyBrxCvDbTinSurface::majorContours)
        .def("contoursAtElevation", &PyBrxCvDbTinSurface::contoursAtElevation)
        .def("drapePoint", &PyBrxCvDbTinSurface::drapePoint)
        .def("drapeId", &PyBrxCvDbTinSurface::drapeId)
        .def("intersectionsWithLine", &PyBrxCvDbTinSurface::intersectionsWithLine)
        .def("getConstraints", &PyBrxCvDbTinSurface::getConstraints)
        .def("getConstraint", &PyBrxCvDbTinSurface::getConstraint1)
        .def("getConstraint", &PyBrxCvDbTinSurface::getConstraint2)
        .def("addConstraint", &PyBrxCvDbTinSurface::addConstraint)
        .def("updateConstraint", &PyBrxCvDbTinSurface::updateConstraint)
        .def("eraseConstraint", &PyBrxCvDbTinSurface::eraseConstraint1)
        .def("eraseConstraint", &PyBrxCvDbTinSurface::eraseConstraint2)
        .def("eraseConstraints", &PyBrxCvDbTinSurface::eraseConstraints)
        .def("eraseConstraintsIds", &PyBrxCvDbTinSurface::eraseConstraintsIds)
        .def("hasSnapshot", &PyBrxCvDbTinSurface::hasSnapshot)
        .def("isSnapshotUpdateNeeded", &PyBrxCvDbTinSurface::isSnapshotUpdateNeeded)
        .def("createSnapshot", &PyBrxCvDbTinSurface::createSnapshot)
        .def("rebuildSnapshot", &PyBrxCvDbTinSurface::rebuildSnapshot)
        .def("removeSnapshot", &PyBrxCvDbTinSurface::removeSnapshot)
        .def("isUpdateNeeded", &PyBrxCvDbTinSurface::isUpdateNeeded)
        .def("isRebuildPossible", &PyBrxCvDbTinSurface::isRebuildPossible)
        .def("rebuild", &PyBrxCvDbTinSurface::rebuild)
        .def("isAutoUpdate", &PyBrxCvDbTinSurface::isAutoUpdate)
        .def("setIsAutoUpdate", &PyBrxCvDbTinSurface::setIsAutoUpdate)
        .def("definitionCount", &PyBrxCvDbTinSurface::definitionCount)
        .def("addDefinition", &PyBrxCvDbTinSurface::addDefinition)
        .def("insertDefinitionAt", &PyBrxCvDbTinSurface::insertDefinitionAt)
        .def("definitionIndex", &PyBrxCvDbTinSurface::definitionIndex)
        .def("definitionAt", &PyBrxCvDbTinSurface::definitionAt)
        .def("findDefinition", &PyBrxCvDbTinSurface::findDefinition)
        .def("moveDefinition", &PyBrxCvDbTinSurface::moveDefinition)
        .def("removeDefinitionAt", &PyBrxCvDbTinSurface::removeDefinitionAt)
        .def("removeAllDefinitions", &PyBrxCvDbTinSurface::removeAllDefinitions)

        .def("className", &PyBrxCvDbTinSurface::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbTinSurface::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbTinSurface::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbTinSurface::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbTinSurface::PyBrxCvDbTinSurface()
    : PyBrxCvDbTinSurface(new BrxCvDbTinSurface(),true)
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

bool PyBrxCvDbTinSurface::findTinPointAt(BrxCvTinPoint& tinPoint, const AcGePoint3d& pnt) const
{
    return impObj()->findTinPointAt(tinPoint, pnt);
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
    return boost::python::make_tuple(flag,Point3dArrayToPyList(val));
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
    return impObj()->addConstraint(*constraint.impObj(), addReactor);
}

bool PyBrxCvDbTinSurface::updateConstraint(const PyBrxCvDbTinSurfaceConstraint& constraint)
{
    return impObj()->updateConstraint(*constraint.impObj());
}

bool PyBrxCvDbTinSurface::eraseConstraint1(const Adesk::UInt64 id, bool removeReactor)
{
    return impObj()->eraseConstraint(id, removeReactor);
}

bool PyBrxCvDbTinSurface::eraseConstraint2(const PyDbObjectId& entityId, bool removeReactor /*= true*/)
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

    return impObj()->insertDefinitionAt(index ,*surfaceDefinition.impObj());
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
    return PyBrxCvDbTinSurface(BrxCvDbTinSurface::merge(theOne.impObj(), theOther.impObj()),true);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=kForRead", "erased: bool=False" })))
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
    PyDocString DS("CvDbTinSurface");
    class_<PyBrxCvDbGrading, bases<PyBrxCvDbEntity>>("CvDbTinSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=kForRead", "erased: bool=False" })))
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