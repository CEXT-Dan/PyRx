#include "stdafx.h"
#include "PyBrxCvDbTinSurface.h"
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
