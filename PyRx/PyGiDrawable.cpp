#include "stdafx.h"
#include "PyGiDrawable.h"
#include "PyGiCommonDraw.h"
#include "PyGiSubEntityTraits.h"

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

std::mutex PyGiDrawableOverruleMutex;
void makeAcGiDrawableOverruleWrapper()
{
    class_<PyGiDrawableOverrule, bases<PyRxOverrule>>("DrawableOverrule")
        //.def("setAttributes", &PyGiDrawableOverrule::setAttributes)

        .def("isApplicable", &PyGiDrawableOverrule::isApplicableWr)
        .def("worldDraw", &PyGiDrawableOverrule::worldDrawWr)
        .def("viewportDraw", &PyGiDrawableOverrule::viewportDrawWr)
        .def("viewportDrawLogicalFlags", &PyGiDrawableOverrule::viewportDrawLogicalFlagsWr)

        .def("baseWorldDraw", &PyGiDrawableOverrule::baseWorldDraw)
        .def("baseViewportDraw", &PyGiDrawableOverrule::baseViewportDraw)
        .def("baseViewportDrawLogicalFlags", &PyGiDrawableOverrule::baseViewportDrawLogicalFlags)

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

Adesk::UInt32 PyGiDrawableOverrule::setAttributes(PyGiDrawable& pSubject, PyGiDrawableTraits& traits)
{
    return impObj()->setAttributes(pSubject.impObj(), traits.impObj());
}

bool PyGiDrawableOverrule::isApplicableWr(PyRxObject& pOverruledSubject) const
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = get_override("isApplicable"))
        {
            return f(pOverruledSubject);
        }
        else
        {
            isApplicableOverride = false;
            return false;
        }
    }
    catch (...)
    {
        isApplicableOverride = false;
        acutPrintf(_T("Exception @ %ls: "), __FUNCTIONW__);
    }
    return false;
}

Adesk::Boolean PyGiDrawableOverrule::worldDrawWr(PyGiDrawable& pSubject, PyGiWorldDraw& wd)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("worldDraw"))
        {
            return f(pSubject, wd);
        }
        else
        {
            isWorldDrawOverride = false;
            return baseWorldDraw(pSubject, wd);
        }
    }
    catch (...)
    {
        isWorldDrawOverride = false;
        acutPrintf(_T("Exception @ %ls: "), __FUNCTIONW__);
    }
    return false;
}

void PyGiDrawableOverrule::viewportDrawWr(PyGiDrawable& pSubject, PyGiViewportDraw& vd)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("viewportDraw"))
        {
            f(pSubject, vd);
        }
        else
        {
            isViewportDrawOverride = false;
            baseViewportDraw(pSubject, vd);
        }
    }
    catch (...)
    {
        isViewportDrawOverride = false;
        acutPrintf(_T("Exception @ %ls: "), __FUNCTIONW__);
    }
}

Adesk::UInt32 PyGiDrawableOverrule::viewportDrawLogicalFlagsWr(PyGiDrawable& pSubject, PyGiViewportDraw& vd)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("viewportDrawLogicalFlags"))
        {
            return f(pSubject, vd);
        }
        else
        {
            isViewportDrawLogicalFlagsOverride = false;
            return baseViewportDrawLogicalFlags(pSubject,vd);
        }
    }
    catch (...)
    {
        isViewportDrawLogicalFlagsOverride = false;
        acutPrintf(_T("Exception @ %ls: "), __FUNCTIONW__);
    }
    return 0;
}

Adesk::Boolean PyGiDrawableOverrule::baseWorldDraw(PyGiDrawable& pSubject, PyGiWorldDraw& wd)
{
    return AcGiDrawableOverrule::worldDraw(pSubject.impObj(), wd.impObj());
}

void PyGiDrawableOverrule::baseViewportDraw(PyGiDrawable& pSubject, PyGiViewportDraw& vd)
{
    return AcGiDrawableOverrule::viewportDraw(pSubject.impObj(), vd.impObj());
}

Adesk::UInt32 PyGiDrawableOverrule::baseViewportDrawLogicalFlags(PyGiDrawable& pSubject, PyGiViewportDraw& vd)
{
    return AcGiDrawableOverrule::viewportDrawLogicalFlags(pSubject.impObj(), vd.impObj());
}

bool PyGiDrawableOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
    if (!isApplicableOverride)
        return false;
    std::lock_guard<std::mutex> guard(PyGiDrawableOverruleMutex);
    PyRxObject obj(pOverruledSubject);
    return this->isApplicableWr(obj);
}

Adesk::Boolean PyGiDrawableOverrule::worldDraw(AcGiDrawable* pSubject, AcGiWorldDraw* wd)
{
    if (!isWorldDrawOverride)
        return AcGiDrawableOverrule::worldDraw(pSubject, wd);
    std::lock_guard<std::mutex> guard(PyGiDrawableOverruleMutex);
    PyGiWorldDraw _wd(wd, false);
    PyGiDrawable _dr(pSubject, false, false);
    return worldDrawWr(_dr, _wd);
}

void PyGiDrawableOverrule::viewportDraw(AcGiDrawable* pSubject, AcGiViewportDraw* vd)
{
    if (!isViewportDrawOverride)
        return AcGiDrawableOverrule::viewportDraw(pSubject, vd);
    std::lock_guard<std::mutex> guard(PyGiDrawableOverruleMutex);
    PyGiViewportDraw _vd(vd, false);
    PyGiDrawable _dr(pSubject, false, false);
    return viewportDrawWr(_dr, _vd);
}

Adesk::UInt32 PyGiDrawableOverrule::viewportDrawLogicalFlags(AcGiDrawable* pSubject, AcGiViewportDraw* vd)
{
    if (!isViewportDrawLogicalFlagsOverride)
        return AcGiDrawableOverrule::viewportDrawLogicalFlags(pSubject, vd);
    std::lock_guard<std::mutex> guard(PyGiDrawableOverruleMutex);
    PyGiViewportDraw _vd(vd, false);
    PyGiDrawable _dr(pSubject, false, false);
    return viewportDrawLogicalFlagsWr(_dr, _vd);
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
