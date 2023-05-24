#include "stdafx.h"
#include "PyRxOverrule.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyRxOverruleBase
void makePyRxOverruleBaseWrapper()
{
	class_<PyRxOverrule, bases<PyRxObject>>("Overrule", boost::python::no_init)
		.def("className", &PyRxOverrule::className).staticmethod("className")
		.def("desc", &PyRxOverrule::desc).staticmethod("desc")
		;
}

PyRxOverrule::PyRxOverrule(AcRxOverrule* ptr, bool autoDelete)
	: PyRxObject(ptr, false, false)
{
}

bool PyRxOverrule::isApplicable(PyRxObject& pOverruledSubject) const
{
	return impObj()->isApplicable(pOverruledSubject.impObj());
}

Acad::ErrorStatus PyRxOverrule::addOverrule1(PyRxClass& pClass, PyRxOverrule& pOverrule)
{
	return AcRxOverrule::addOverrule(pClass.impObj(), pOverrule.impObj());
}

Acad::ErrorStatus PyRxOverrule::addOverrule2(PyRxClass& pClass, PyRxOverrule& pOverrule, bool bAddAtLast)
{
	return AcRxOverrule::addOverrule(pClass.impObj(), pOverrule.impObj(), bAddAtLast);
}

Acad::ErrorStatus PyRxOverrule::removeOverrule(PyRxClass& pClass, PyRxOverrule& pOverrule)
{
	return AcRxOverrule::removeOverrule(pClass.impObj(), pOverrule.impObj());
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
	if (m_pImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcRxOverrule*>(m_pImp.get());
}
