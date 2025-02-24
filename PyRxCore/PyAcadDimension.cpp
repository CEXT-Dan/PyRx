#include "stdafx.h"
#include "PyAcadDimension.h"
#include "PyAcadDimensionImpl.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadObjectImpl.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyAcadDimension
void makePyAcadDimensionWrapper()
{
    PyDocString DS("AcadDimension");
    class_<PyAcadDimension, bases<PyAcadEntity>>("AcadDimension", boost::python::no_init)
        .def("cast", &PyAcadDimension::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimension::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimension::PyAcadDimension(std::shared_ptr<PyIAcadDimensionImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadDimension PyAcadDimension::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimension>(src);
}

std::string PyAcadDimension::className()
{
    return "AcadDimension";
}

PyIAcadDimensionImpl* PyAcadDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimensionImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimAligned
void makePyAcadDimAlignedWrapper()
{
    PyDocString DS("AcadDimAligned");
    class_<PyAcadDimAligned, bases<PyAcadDimension>>("AcadDimAligned", boost::python::no_init)
        .def("cast", &PyAcadDimAligned::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimAligned::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimAligned::PyAcadDimAligned(std::shared_ptr<PyIAcadDimAlignedImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimAligned PyAcadDimAligned::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimAligned>(src);
}

std::string PyAcadDimAligned::className()
{
    return "AcadDimAligned";
}

PyIAcadDimAlignedImpl* PyAcadDimAligned::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimAlignedImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimAngular
void makePyAcadDimAngularWrapper()
{
    PyDocString DS("AcadDimAngular");
    class_<PyAcadDimAngular, bases<PyAcadDimension>>("AcadDimAngular", boost::python::no_init)
        .def("cast", &PyAcadDimAngular::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimAngular::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimAngular::PyAcadDimAngular(std::shared_ptr<PyIAcadDimAngularImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimAngular PyAcadDimAngular::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimAngular>(src);
}

std::string PyAcadDimAngular::className()
{
    return "AcadDimAngular";
}

PyIAcadDimAngularImpl* PyAcadDimAngular::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimAngularImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimDiametric
void makePyAcadDimDiametricWrapper()
{
    PyDocString DS("AcadDimDiametric");
    class_<PyAcadDimDiametric, bases<PyAcadDimension>>("AcadDimDiametric", boost::python::no_init)
        .def("cast", &PyAcadDimDiametric::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimDiametric::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimDiametric::PyAcadDimDiametric(std::shared_ptr<PyIAcadDimDiametricImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimDiametric PyAcadDimDiametric::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimDiametric>(src);
}

std::string PyAcadDimDiametric::className()
{
    return "AcadDimDiametric";
}

PyIAcadDimDiametricImpl* PyAcadDimDiametric::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimDiametricImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRotated
void makePyAcadDimRotatedWrapper()
{
    PyDocString DS("AcadDimRotated");
    class_<PyAcadDimRotated, bases<PyAcadDimension>>("AcadDimRotated", boost::python::no_init)
        .def("cast", &PyAcadDimRotated::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRotated::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRotated::PyAcadDimRotated(std::shared_ptr<PyIAcadDimRotatedImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimRotated PyAcadDimRotated::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRotated>(src);
}

std::string PyAcadDimRotated::className()
{
    return "AcadDimRotated";
}

PyIAcadDimRotatedImpl* PyAcadDimRotated::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRotatedImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimOrdinate
void makePyAcadDimOrdinateWrapper()
{
    PyDocString DS("AcadDimOrdinate");
    class_<PyAcadDimOrdinate, bases<PyAcadDimension>>("AcadDimOrdinate", boost::python::no_init)
        .def("cast", &PyAcadDimOrdinate::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimOrdinate::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimOrdinate::PyAcadDimOrdinate(std::shared_ptr<PyIAcadDimOrdinateImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimOrdinate PyAcadDimOrdinate::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimOrdinate>(src);
}

std::string PyAcadDimOrdinate::className()
{
    return "AcadDimOrdinate";
}

PyIAcadDimOrdinateImpl* PyAcadDimOrdinate::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimOrdinateImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRadial
void makePyAcadDimRadialWrapper()
{
    PyDocString DS("AcadDimRadial");
    class_<PyAcadDimRadial, bases<PyAcadDimension>>("AcadDimRadial", boost::python::no_init)
        .def("cast", &PyAcadDimRadial::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRadial::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRadial::PyAcadDimRadial(std::shared_ptr<PyIAcadDimRadialImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimRadial PyAcadDimRadial::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRadial>(src);
}

std::string PyAcadDimRadial::className()
{
    return "AcadDimRadial";
}

PyIAcadDimRadialImpl* PyAcadDimRadial::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRadialImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDim3PointAngular
void makePyAcadDim3PointAngularWrapper()
{
    PyDocString DS("AcadDim3PointAngular");
    class_<PyAcadDim3PointAngular, bases<PyAcadDimension>>("AcadDim3PointAngular", boost::python::no_init)
        .def("cast", &PyAcadDim3PointAngular::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDim3PointAngular::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDim3PointAngular::PyAcadDim3PointAngular(std::shared_ptr<PyIAcadDim3PointAngularImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDim3PointAngular PyAcadDim3PointAngular::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDim3PointAngular>(src);
}

std::string PyAcadDim3PointAngular::className()
{
    return "AcadDim3PointAngular";
}

PyIAcadDim3PointAngularImpl* PyAcadDim3PointAngular::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDim3PointAngularImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimArcLength
void makePyAcadDimArcLengthWrapper()
{
    PyDocString DS("AcadDimArcLength");
    class_<PyAcadDimArcLength, bases<PyAcadDimension>>("AcadDimArcLength", boost::python::no_init)
        .def("cast", &PyAcadDimArcLength::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimArcLength::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimArcLength::PyAcadDimArcLength(std::shared_ptr<PyIAcadDimArcLengthImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimArcLength PyAcadDimArcLength::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimArcLength>(src);
}

std::string PyAcadDimArcLength::className()
{
    return "AcadDimArcLength";
}

PyIAcadDimArcLengthImpl* PyAcadDimArcLength::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimArcLengthImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRadialLarge
void makePyAcadDimRadialLargeWrapper()
{
    PyDocString DS("AcadDimRadialLarge");
    class_<PyAcadDimRadialLarge, bases<PyAcadDimension>>("AcadDimRadialLarge", boost::python::no_init)
        .def("cast", &PyAcadDimRadialLarge::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRadialLarge::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRadialLarge::PyAcadDimRadialLarge(std::shared_ptr<PyIAcadDimRadialLargeImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimRadialLarge PyAcadDimRadialLarge::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRadialLarge>(src);
}

std::string PyAcadDimRadialLarge::className()
{
    return "AcadDimRadialLarge";
}

PyIAcadDimRadialLargeImpl* PyAcadDimRadialLarge::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRadialLargeImpl*>(m_pyImp.get());
}