#include "stdafx.h"
#include "PyRxOverrule.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyRxOverruleBase
void makePyRxOverruleWrapper()
{
    PyDocString DS("Overrule");
    class_<PyRxOverrule, bases<PyRxObject>>("Overrule", boost::python::no_init)
        .def("addOverrule", &PyRxOverrule::addOverrule1, DS.SARGS({ "rxClass: PyRx.RxClass","overrule: PyRx.Overrule" })).staticmethod("addOverrule")
        .def("addOverruleLast", &PyRxOverrule::addOverrule2, DS.SARGS({ "rxClass: PyRx.RxClass","overrule: PyRx.Overrule","addLast: bool" })).staticmethod("addOverruleLast")
        .def("removeOverrule", &PyRxOverrule::removeOverrule, DS.SARGS({ "rxClass: PyRx.RxClass","overrule: PyRx.Overrule" })).staticmethod("removeOverrule")
        .def("setIsOverruling", &PyRxOverrule::setIsOverruling, DS.ARGS({ "flag: bool" })).staticmethod("setIsOverruling")
        .def("isOverruling", &PyRxOverrule::isOverruling, DS.ARGS()).staticmethod("isOverruling")
        .def("hasOverrule", &PyRxOverrule::hasOverrule, DS.SARGS({ "subject: PyRx.RxObject","rxClass: PyRx.RxClass" })).staticmethod("hasOverrule")
        .def("className", &PyRxOverrule::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyRxOverrule::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyRxOverrule::PyRxOverrule(AcRxOverrule* ptr)
    : PyRxObject(ptr, false, false)
{
}

void PyRxOverrule::addOverrule1(PyRxClass& pClass, PyRxOverrule& pOverrule)
{
    PyThrowBadEs(AcRxOverrule::addOverrule(pClass.impObj(), pOverrule.impObj()));
}

void PyRxOverrule::addOverrule2(PyRxClass& pClass, PyRxOverrule& pOverrule, bool bAddAtLast)
{
    PyThrowBadEs(AcRxOverrule::addOverrule(pClass.impObj(), pOverrule.impObj(), bAddAtLast));
}

void PyRxOverrule::removeOverrule(PyRxClass& pClass, PyRxOverrule& pOverrule)
{
    PyThrowBadEs(AcRxOverrule::removeOverrule(pClass.impObj(), pOverrule.impObj()));
}

void PyRxOverrule::setIsOverruling(bool bIsOverruling)
{
    AcRxOverrule::setIsOverruling(bIsOverruling);
}

bool PyRxOverrule::isOverruling(void)
{
    return AcRxOverrule::isOverruling();
}

bool PyRxOverrule::hasOverrule(PyRxObject& pSubject, PyRxClass& pOverruleClass)
{
    return AcRxOverrule::hasOverrule(pSubject.impObj(), pOverruleClass.impObj());
}

std::string PyRxOverrule::className()
{
    return "AcRxOverruleBase";
}

PyRxClass PyRxOverrule::desc()
{
    return PyRxClass(AcRxOverrule::desc(), false);
}

AcRxOverrule* PyRxOverrule::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcRxOverrule*>(m_pyImp.get());
}
