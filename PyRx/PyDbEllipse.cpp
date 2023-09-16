#include "stdafx.h"
#include "PyDbEllipse.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbCurve
void makePyDbEllipseWrapper()
{
    PyDocString DS("Ellipse");
    class_<PyDbEllipse, bases<PyDbCurve>>("Ellipse")
        .def(init<>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&, double, double, double>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("center", &PyDbEllipse::center)
        .def("setCenter", &PyDbEllipse::setCenter)
        .def("normal", &PyDbEllipse::normal)
        .def("majorAxis", &PyDbEllipse::majorAxis)
        .def("minorAxis", &PyDbEllipse::minorAxis)
        .def("majorRadius", &PyDbEllipse::majorRadius)
        .def("minorRadius", &PyDbEllipse::minorRadius)
        .def("setMajorRadius", &PyDbEllipse::setMajorRadius)
        .def("setMinorRadius", &PyDbEllipse::setMinorRadius)
        .def("radiusRatio", &PyDbEllipse::radiusRatio)
        .def("setRadiusRatio", &PyDbEllipse::setRadiusRatio)
        .def("startAngle", &PyDbEllipse::startAngle)
        .def("setStartAngle", &PyDbEllipse::setStartAngle)
        .def("endAngle", &PyDbEllipse::endAngle)
        .def("setEndAngle", &PyDbEllipse::setEndAngle)
        .def("setStartParam", &PyDbEllipse::setStartParam)
        .def("setEndParam", &PyDbEllipse::setEndParam)
        .def("paramAtAngle", &PyDbEllipse::paramAtAngle)
        .def("angleAtParam", &PyDbEllipse::angleAtParam)
        .def("get", &PyDbEllipse::get)
        .def("set", &PyDbEllipse::set1)
        .def("set", &PyDbEllipse::set2)
        .def("isNull", &PyDbEllipse::isNull)
        .def("className", &PyDbEllipse::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbEllipse::desc, DS.SARGS()).staticmethod("desc")
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

void PyDbEllipse::setCenter(const AcGePoint3d& center)
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

void PyDbEllipse::setMajorRadius(double val)
{
    PyThrowBadEs(impObj()->setMajorRadius(val));
}

void PyDbEllipse::setMinorRadius(double val)
{
    PyThrowBadEs(impObj()->setMinorRadius(val));
}

double PyDbEllipse::radiusRatio() const
{
    return impObj()->radiusRatio();
}

void PyDbEllipse::setRadiusRatio(double ratio)
{
    PyThrowBadEs(impObj()->setRadiusRatio(ratio));
}

double PyDbEllipse::startAngle() const
{
    return impObj()->startAngle();
}

void PyDbEllipse::setStartAngle(double startAngle)
{
    PyThrowBadEs(impObj()->setStartAngle(startAngle));
}

double PyDbEllipse::endAngle() const
{
    return impObj()->endAngle();
}

void PyDbEllipse::setEndAngle(double endAngle)
{
    PyThrowBadEs(impObj()->setEndAngle(endAngle));
}

void PyDbEllipse::setStartParam(double startParam)
{
    PyThrowBadEs(impObj()->setStartParam(startParam));
}

void PyDbEllipse::setEndParam(double endParam)
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
    double radiusRatio; 
    double startAngle;
    double endAngle;
    PyThrowBadEs(impObj()->get(center, unitNormal, majorAxis, radiusRatio, startAngle, endAngle));
    return boost::python::make_tuple(center, unitNormal, majorAxis, radiusRatio, startAngle, endAngle);
}

void PyDbEllipse::set1(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio)
{
    PyThrowBadEs(impObj()->set(center, unitNormal, majorAxis, radiusRatio));
}

void PyDbEllipse::set2(const AcGePoint3d& center, const AcGeVector3d& unitNormal, const AcGeVector3d& majorAxis, double radiusRatio, double startAngle, double endAngle)
{
    PyThrowBadEs(impObj()->set(center, unitNormal, majorAxis, radiusRatio, startAngle, endAngle));
}

Adesk::Boolean PyDbEllipse::isNull() const
{
    return impObj()->isNull();
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
    if (!src.impObj()->isKindOf(AcDbCurve::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbEllipse(static_cast<AcDbEllipse*>(src.impObj()->clone()), true);
}

PyDbEllipse PyDbEllipse::cast(const PyRxObject& src)
{
    PyDbEllipse dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbEllipse* PyDbEllipse::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbEllipse*>(m_pyImp.get());
}
