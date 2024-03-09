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
