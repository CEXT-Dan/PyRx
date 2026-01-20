#include "stdafx.h"
#include "PyDbEllipse.h"
#include "PyDbObjectId.h"
#include "PyGeCurve3d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbCurve
void makePyDbEllipseWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- center: PyGe.Point3d, unitNormal: PyGe.Vector3d, majorAxis: PyGe.Vector3d, radiusRatio: float\n"
        "- center: PyGe.Point3d, unitNormal: PyGe.Vector3d, majorAxis: PyGe.Vector3d, radiusRatio: float, startAngle: float, endAngle: float\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- center: PyGe.Point3d, unitNormal: PyGe.Vector3d, majorAxis: PyGe.Vector3d, radiusRatio: float\n"
        "- center: PyGe.Point3d, unitNormal: PyGe.Vector3d, majorAxis: PyGe.Vector3d, radiusRatio: float, startAngle: float, endAngle: float\n";

    PyDocString DS("Ellipse");
    class_<PyDbEllipse, bases<PyDbCurve>>("Ellipse")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double, double, double>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 4240)))
        .def("center", &PyDbEllipse::center, DS.ARGS(4243))
        .def("setCenter", &PyDbEllipse::setCenter, DS.ARGS({ "val : PyGe.Point3d" }, 4255))
        .def("normal", &PyDbEllipse::normal, DS.ARGS(4251))
        .def("majorAxis", &PyDbEllipse::majorAxis, DS.ARGS(4247))
        .def("minorAxis", &PyDbEllipse::minorAxis, DS.ARGS(4249))
        .def("majorRadius", &PyDbEllipse::majorRadius, DS.ARGS(4248))
        .def("minorRadius", &PyDbEllipse::minorRadius, DS.ARGS(4250))
        .def("setMajorRadius", &PyDbEllipse::setMajorRadius, DS.ARGS({ "val : float" }, 4258))
        .def("setMinorRadius", &PyDbEllipse::setMinorRadius, DS.ARGS({ "val : float" }, 4259))
        .def("radiusRatio", &PyDbEllipse::radiusRatio, DS.ARGS(4253))
        .def("setRadiusRatio", &PyDbEllipse::setRadiusRatio, DS.ARGS({ "val : float" }, 4260))
        .def("startAngle", &PyDbEllipse::startAngle, DS.ARGS(4263))
        .def("setStartAngle", &PyDbEllipse::setStartAngle, DS.ARGS({ "val : float" }, 4261))
        .def("endAngle", &PyDbEllipse::endAngle, DS.ARGS(4244))
        .def("setEndAngle", &PyDbEllipse::setEndAngle, DS.ARGS({ "val : float" }, 4256))
        .def("setStartParam", &PyDbEllipse::setStartParam, DS.ARGS({ "val : float" }, 4262))
        .def("setEndParam", &PyDbEllipse::setEndParam, DS.ARGS({ "val : float" }, 4257))
        .def("paramAtAngle", &PyDbEllipse::paramAtAngle, DS.ARGS({ "val : float" }, 4252))
        .def("angleAtParam", &PyDbEllipse::angleAtParam, DS.ARGS({ "val : float" }, 4242))
        .def("get", &PyDbEllipse::get, DS.ARGS(4245))
        .def("set", &PyDbEllipse::set1)
        .def("set", &PyDbEllipse::set2, DS.OVRL(setOverloads, 4254))
        .def("isNull", &PyDbEllipse::isNull, DS.ARGS(4246))
        .def("className", &PyDbEllipse::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbEllipse::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbEllipse::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbEllipse::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbEllipse::PyDbEllipse()
    : PyDbEllipse(new AcDbEllipse(), true)
{
}

PyDbEllipse::PyDbEllipse(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio)
    : PyDbEllipse(new AcDbEllipse(center, unitNormal, majorAxis, radiusRatio), true)
{
}

PyDbEllipse::PyDbEllipse(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio, double startAngle, double endAngle)
    : PyDbEllipse(new AcDbEllipse(center, unitNormal, majorAxis, radiusRatio, startAngle, endAngle), true)
{
}

PyDbEllipse::PyDbEllipse(const PyDbObjectId& id)
    : PyDbCurve(openAcDbObject<AcDbEllipse>(id, AcDb::kForRead), false)
{
}

PyDbEllipse::PyDbEllipse(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbEllipse>(id, mode), false)
{
}

PyDbEllipse::PyDbEllipse(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbCurve(openAcDbObject<AcDbEllipse>(id, mode, erased), false)
{
}

PyDbEllipse::PyDbEllipse(AcDbEllipse* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

AcGePoint3d PyDbEllipse::center() const
{
    return impObj()->center();
}

void PyDbEllipse::setCenter(const AcGePoint3d& center) const
{
    PyThrowBadEs(impObj()->setCenter(center));
}

AcGeVector3d PyDbEllipse::normal() const
{
    return impObj()->normal();
}

AcGeVector3d PyDbEllipse::majorAxis() const
{
    return impObj()->majorAxis();
}

AcGeVector3d PyDbEllipse::minorAxis() const
{
    return impObj()->minorAxis();
}

double PyDbEllipse::majorRadius() const
{
    return impObj()->majorRadius();
}

double PyDbEllipse::minorRadius() const
{
    return impObj()->minorRadius();
}

void PyDbEllipse::setMajorRadius(double val) const
{
    PyThrowBadEs(impObj()->setMajorRadius(val));
}

void PyDbEllipse::setMinorRadius(double val) const
{
    PyThrowBadEs(impObj()->setMinorRadius(val));
}

double PyDbEllipse::radiusRatio() const
{
    return impObj()->radiusRatio();
}

void PyDbEllipse::setRadiusRatio(double ratio) const
{
    PyThrowBadEs(impObj()->setRadiusRatio(ratio));
}

double PyDbEllipse::startAngle() const
{
    return impObj()->startAngle();
}

void PyDbEllipse::setStartAngle(double startAngle) const
{
    PyThrowBadEs(impObj()->setStartAngle(startAngle));
}

double PyDbEllipse::endAngle() const
{
    return impObj()->endAngle();
}

void PyDbEllipse::setEndAngle(double endAngle) const
{
    PyThrowBadEs(impObj()->setEndAngle(endAngle));
}

void PyDbEllipse::setStartParam(double startParam) const
{
    PyThrowBadEs(impObj()->setStartParam(startParam));
}

void PyDbEllipse::setEndParam(double endParam) const
{
    PyThrowBadEs(impObj()->setEndParam(endParam));
}

double PyDbEllipse::paramAtAngle(double angle) const
{
    return impObj()->paramAtAngle(angle);
}

double PyDbEllipse::angleAtParam(double param) const
{
    return impObj()->angleAtParam(param);
}

boost::python::tuple PyDbEllipse::get() const
{
    AcGePoint3d center;
    AcGeVector3d unitNormal;
    AcGeVector3d majorAxis;
    double radiusRatio = 0.0;
    double startAngle = 0.0;
    double endAngle = 0.0;
    PyThrowBadEs(impObj()->get(center, unitNormal, majorAxis, radiusRatio, startAngle, endAngle));
    return boost::python::make_tuple(center, unitNormal, majorAxis, radiusRatio, startAngle, endAngle);
}

void PyDbEllipse::set1(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio) const
{
    PyThrowBadEs(impObj()->set(center, unitNormal, majorAxis, radiusRatio));
}

void PyDbEllipse::set2(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio, double startAngle, double endAngle) const
{
    PyThrowBadEs(impObj()->set(center, unitNormal, majorAxis, radiusRatio, startAngle, endAngle));
}

Adesk::Boolean PyDbEllipse::isNull() const
{
    return impObj()->isNull();
}

PyGeEllipArc3d PyDbEllipse::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeEllipArc3d(pGeCurve);
}

PyGeEllipArc3d PyDbEllipse::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeEllipArc3d(pGeCurve);
}

std::string PyDbEllipse::className()
{
    return "AcDbEllipse";
}

PyRxClass PyDbEllipse::desc()
{
    return PyRxClass(AcDbEllipse::desc(), false);
}

PyDbEllipse PyDbEllipse::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbEllipse, AcDbEllipse>(src);
}

PyDbEllipse PyDbEllipse::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbEllipse>(src);
}

AcDbEllipse* PyDbEllipse::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbEllipse*>(m_pyImp.get());
}
