#include "stdafx.h"
#include "PyGiDrawable.h"
#include "PyGiCommonDraw.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyGiDrawable
void makeAcGiObjectWrapper()
{
	class_<PyGiDrawable, bases<PyRxObject>>("Drawable", boost::python::no_init)
		.def("isA", &PyRxObject::isA)
		.def("className", &PyGiDrawable::className).staticmethod("className")
		.def("desc", &PyGiDrawable::desc).staticmethod("desc")
		;
}

PyGiDrawable::PyGiDrawable(AcGiDrawable* ptr, bool autoDelete, bool isDbObject)
	: PyRxObject(ptr, autoDelete, isDbObject)
{
}

std::string PyGiDrawable::className()
{
	return "AcGiDrawable";
}

PyRxClass PyGiDrawable::desc()
{
	return PyRxClass(AcGiDrawable::desc(), false);
}

AcGiDrawable* PyGiDrawable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
	if (m_pyImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiDrawable*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiDrawableOverrule
void makeAcGiDrawableOverruleWrapper()
{
	class_<PyGiDrawableOverrule, bases<PyRxOverrule>>("DrawableOverrule")
		//.def("setAttributes", &PyGiDrawableOverrule::setAttributes)
		.def("isApplicable", &PyGiDrawableOverrule::isApplicableWr)
		.def("worldDraw", &PyGiDrawableOverrule::worldDrawWr)
		.def("viewportDraw", &PyGiDrawableOverrule::viewportDrawWr)

		.def("baseWorldDraw", &PyGiDrawableOverrule::baseWorldDraw)

		.def("viewportDrawLogicalFlags", &PyGiDrawableOverrule::viewportDrawLogicalFlagsWr)
		.def("className", &PyGiDrawableOverrule::className).staticmethod("className")
		.def("desc", &PyGiDrawableOverrule::desc).staticmethod("desc")
		;
}

PyGiDrawableOverrule::PyGiDrawableOverrule()
	: PyRxOverrule(nullptr, this)
{
	this->resetImp(this, false, false);
}

PyGiDrawableOverrule::PyGiDrawableOverrule(AcGiDrawableOverrule* ptr, bool autoDelete)
	: PyRxOverrule(ptr, autoDelete)
{
}

bool PyGiDrawableOverrule::isApplicableWr(PyRxObject& pOverruledSubject) const
{
	PyAutoLockGIL lock;
	if (override f = get_override("isApplicable"))
		return f(pOverruledSubject);
	return false;
}

Adesk::Boolean PyGiDrawableOverrule::worldDrawWr(PyGiDrawable& pSubject, PyGiWorldDraw& wd)
{
	PyAutoLockGIL lock;
	if (override f = this->get_override("worldDraw"))
		return f(pSubject, wd);
	return false;
}

void PyGiDrawableOverrule::viewportDrawWr(PyGiDrawable& pSubject, PyGiViewportDraw& vd)
{
	PyAutoLockGIL lock;
	if (override f = this->get_override("viewportDraw"))
		f(pSubject, vd);
}

Adesk::UInt32 PyGiDrawableOverrule::viewportDrawLogicalFlagsWr(PyGiDrawable& pSubject, PyGiViewportDraw& vd)
{
	PyAutoLockGIL lock;
	if (override f = this->get_override("viewportDrawLogicalFlags"))
		f(pSubject, vd);
	return 0;
}

Adesk::Boolean PyGiDrawableOverrule::baseWorldDraw(PyGiDrawable& pSubject, PyGiWorldDraw& wd)
{
	return AcGiDrawableOverrule::worldDraw(pSubject.impObj(), wd.impObj());
}

bool PyGiDrawableOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
	PyRxObject obj(pOverruledSubject);
	return this->isApplicableWr(obj);
}

Adesk::Boolean PyGiDrawableOverrule::worldDraw(AcGiDrawable* pSubject, AcGiWorldDraw* wd)
{
	PyGiWorldDraw _wd(wd, false);
	PyGiDrawable _dr(pSubject, false, false);
	return worldDrawWr(_dr, _wd);
}

std::string PyGiDrawableOverrule::className()
{
	return "AcGiDrawable";
}

PyRxClass PyGiDrawableOverrule::desc()
{
	return PyRxClass(AcGiDrawableOverrule::desc(), false);
}

AcGiDrawableOverrule* PyGiDrawableOverrule::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
	if (m_pyImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiDrawableOverrule*>(m_pyImp.get());
}
