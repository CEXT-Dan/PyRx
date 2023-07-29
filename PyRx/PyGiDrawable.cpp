#include "stdafx.h"
#include "PyGiDrawable.h"
#include "PyGiCommonDraw.h"
#include "PyGiSubEntityTraits.h"
#include "PyDbObjectId.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyGiDrawable
void makePyGiObjectWrapper()
{
    PyDocString DS("Drawable");
    class_<PyGiDrawable, bases<PyRxObject>>("Drawable", boost::python::no_init)
        .def("setAttributes", &PyGiDrawable::setAttributes, DS.CLASSARGS({ "traits: PyGi.DrawableTraits" }))
        .def("worldDraw", &PyGiDrawable::worldDraw, DS.CLASSARGS({ "wdraw: PyGi.WorldDraw" }))
        .def("viewportDraw", &PyGiDrawable::viewportDraw, DS.CLASSARGS({ "vpdraw: PyGi.ViewportDraw" }))
        .def("viewportDrawLogicalFlags", &PyGiDrawable::viewportDrawLogicalFlags, DS.CLASSARGS({ "vpdraw: PyGi.ViewportDraw" }))
        .def("isPersistent", &PyGiDrawable::isPersistent, DS.CLASSARGS())
        .def("id", &PyGiDrawable::id, DS.CLASSARGS())
        .def("drawableType", &PyGiDrawable::drawableType, DS.CLASSARGS())
        .def("rolloverHit", &PyGiDrawable::rolloverHit, DS.CLASSARGS({ "nSubentId: int", "nMouseFlags: int", "bReset: bool" }))
        .def("bounds", &PyGiDrawable::bounds, DS.CLASSARGS({ "ext: PyDb.Extents" }))
        .def("className", &PyGiDrawable::className, DS.CLASSARGSSTATIC()).staticmethod("className")
        .def("desc", &PyGiDrawable::desc, DS.CLASSARGSSTATIC()).staticmethod("desc")
        ;
    enum_<AcGiDrawable::DrawableType>("GiDrawableType")
        .value("kGeometry", AcGiDrawable::DrawableType::kGeometry)
        .value("kDistantLight", AcGiDrawable::DrawableType::kDistantLight)
        .value("kPointLight", AcGiDrawable::DrawableType::kPointLight)
        .value("kSpotLight", AcGiDrawable::DrawableType::kSpotLight)
        .value("kAmbientLight", AcGiDrawable::DrawableType::kAmbientLight)
        .value("kSolidBackground", AcGiDrawable::DrawableType::kSolidBackground)
        .value("kGradientBackground", AcGiDrawable::DrawableType::kGradientBackground)
        .value("kImageBackground", AcGiDrawable::DrawableType::kImageBackground)
        .value("kGroundPlaneBackground", AcGiDrawable::DrawableType::kGroundPlaneBackground)
        .value("kViewport", AcGiDrawable::DrawableType::kViewport)
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
        .value("kWebLight", AcGiDrawable::DrawableType::kWebLight)
        .value("kSkyBackground", AcGiDrawable::DrawableType::kSkyBackground)
        .value("kImageBasedLightingBackground", AcGiDrawable::DrawableType::kImageBasedLightingBackground)
#endif
        .export_values()
        ;

    enum_<AcGiDrawable::SetAttributesFlags>("GiAttributesFlags")
        .value("kDrawableNone", AcGiDrawable::SetAttributesFlags::kDrawableNone)
        .value("kDrawableIsAnEntity", AcGiDrawable::SetAttributesFlags::kDrawableIsAnEntity)
        .value("kDrawableUsesNesting", AcGiDrawable::SetAttributesFlags::kDrawableUsesNesting)
        .value("kDrawableIsCompoundObject", AcGiDrawable::SetAttributesFlags::kDrawableIsCompoundObject)
        .value("kDrawableViewIndependentViewportDraw", AcGiDrawable::SetAttributesFlags::kDrawableViewIndependentViewportDraw)
        .value("kDrawableIsInvisible", AcGiDrawable::SetAttributesFlags::kDrawableIsInvisible)
        .value("kDrawableHasAttributes", AcGiDrawable::SetAttributesFlags::kDrawableHasAttributes)
        .value("kDrawableRegenTypeDependentGeometry", AcGiDrawable::SetAttributesFlags::kDrawableRegenTypeDependentGeometry)
        .value("kDrawableIsDimension", AcGiDrawable::SetAttributesFlags::kDrawableIsDimension)
        .value("kDrawableRegenDraw", AcGiDrawable::SetAttributesFlags::kDrawableRegenDraw)
        .value("kDrawableStandardDisplaySingleLOD", AcGiDrawable::SetAttributesFlags::kDrawableStandardDisplaySingleLOD)
        .value("kDrawableShadedDisplaySingleLOD", AcGiDrawable::SetAttributesFlags::kDrawableShadedDisplaySingleLOD)
        .value("kDrawableViewDependentViewportDraw", AcGiDrawable::SetAttributesFlags::kDrawableViewDependentViewportDraw)
        .value("kDrawableBlockDependentViewportDraw", AcGiDrawable::SetAttributesFlags::kDrawableBlockDependentViewportDraw)
        .value("kDrawableIsExternalReference", AcGiDrawable::SetAttributesFlags::kDrawableIsExternalReference)
        .value("kDrawableNotPlottable", AcGiDrawable::SetAttributesFlags::kDrawableNotPlottable)
        .value("kDrawableNotAllowLCS", AcGiDrawable::SetAttributesFlags::kDrawableNotAllowLCS)
        .value("kDrawableMergeControlOff", AcGiDrawable::SetAttributesFlags::kDrawableMergeControlOff)
#ifdef ARXAPP
        .value("kThreadedWorldDrawViewportDraw", AcGiDrawable::SetAttributesFlags::kThreadedWorldDrawViewportDraw)
#endif
        .export_values()
        ;
}

PyGiDrawable::PyGiDrawable(AcGiDrawable* ptr, bool autoDelete, bool isDbObject)
    : PyRxObject(ptr, autoDelete, isDbObject)
{
}

Adesk::UInt32 PyGiDrawable::setAttributes(PyGiDrawableTraits& traits)
{
    return impObj()->setAttributes(traits.impObj());
}

Adesk::Boolean PyGiDrawable::worldDraw(PyGiWorldDraw& wd)
{
    return impObj()->worldDraw(wd.impObj());
}

void PyGiDrawable::viewportDraw(PyGiViewportDraw& vd)
{
    return impObj()->viewportDraw(vd.impObj());
}

Adesk::UInt32 PyGiDrawable::viewportDrawLogicalFlags(PyGiViewportDraw& vd)
{
    return impObj()->viewportDrawLogicalFlags(vd.impObj());
}

Adesk::Boolean PyGiDrawable::isPersistent(void) const
{
    return impObj()->isPersistent();
}

PyDbObjectId PyGiDrawable::id(void) const
{
    return PyDbObjectId(impObj()->id());
}

AcGiDrawable::DrawableType PyGiDrawable::drawableType(void) const
{
    return impObj()->drawableType();
}

Adesk::Boolean PyGiDrawable::rolloverHit(Adesk::ULongPtr nSubentId, Adesk::ULongPtr nMouseFlags, Adesk::Boolean bReset)
{
    return impObj()->RolloverHit(nSubentId, nMouseFlags, bReset);
}

bool PyGiDrawable::bounds(AcDbExtents& ext) const
{
    return impObj()->bounds(ext);
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
void makePyGiDrawableOverruleWrapper()
{
    class_<PyGiDrawableOverrule, bases<PyRxOverrule>>("DrawableOverrule")
        .def("setAttributes", &PyGiDrawableOverrule::setAttributes)
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
            return baseViewportDrawLogicalFlags(pSubject, vd);
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
#ifndef ARXAPP
    std::lock_guard<std::mutex> guard(PyGiDrawableOverruleMutex);
#endif
    PyRxObject obj(pOverruledSubject);
    return this->isApplicableWr(obj);
}

Adesk::Boolean PyGiDrawableOverrule::worldDraw(AcGiDrawable* pSubject, AcGiWorldDraw* wd)
{
    if (!isWorldDrawOverride)
        return AcGiDrawableOverrule::worldDraw(pSubject, wd);
#ifndef ARXAPP
    std::lock_guard<std::mutex> guard(PyGiDrawableOverruleMutex);
#endif
    PyGiWorldDraw _wd(wd, false);
    PyGiDrawable _dr(pSubject, false, false);
    return worldDrawWr(_dr, _wd);
}

void PyGiDrawableOverrule::viewportDraw(AcGiDrawable* pSubject, AcGiViewportDraw* vd)
{
    if (!isViewportDrawOverride)
        return AcGiDrawableOverrule::viewportDraw(pSubject, vd);
#ifndef ARXAPP
    std::lock_guard<std::mutex> guard(PyGiDrawableOverruleMutex);
#endif
    PyGiViewportDraw _vd(vd, false);
    PyGiDrawable _dr(pSubject, false, false);
    return viewportDrawWr(_dr, _vd);
}

Adesk::UInt32 PyGiDrawableOverrule::viewportDrawLogicalFlags(AcGiDrawable* pSubject, AcGiViewportDraw* vd)
{
    if (!isViewportDrawLogicalFlagsOverride)
        return AcGiDrawableOverrule::viewportDrawLogicalFlags(pSubject, vd);
#ifndef ARXAPP
    std::lock_guard<std::mutex> guard(PyGiDrawableOverruleMutex);
#endif
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
