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
    PyDocString DS("PyGi.Drawable");
    class_<PyGiDrawable, bases<PyRxObject>>("Drawable", boost::python::no_init)
        .def("setAttributes", &PyGiDrawable::setAttributes, DS.ARGS({ "traits: PyGi.DrawableTraits" }, 13061))
        .def("worldDraw", &PyGiDrawable::worldDraw, DS.ARGS({ "wdraw: PyGi.WorldDraw" }, 13070))
        .def("viewportDraw", &PyGiDrawable::viewportDraw, DS.ARGS({ "vpdraw: PyGi.ViewportDraw" }, 13068))
        .def("viewportDrawLogicalFlags", &PyGiDrawable::viewportDrawLogicalFlags, DS.ARGS({ "vpdraw: PyGi.ViewportDraw" }, 13069))
        .def("isPersistent", &PyGiDrawable::isPersistent, DS.ARGS(13059))
        .def("id", &PyGiDrawable::id, DS.ARGS(13058))
        .def("drawableType", &PyGiDrawable::drawableType, DS.ARGS(13055))
        .def("rolloverHit", &PyGiDrawable::rolloverHit, DS.ARGS({ "nSubentId: int", "nMouseFlags: int", "bReset: bool" }, 13060))
        .def("bounds", &PyGiDrawable::bounds, DS.ARGS({ "ext: PyDb.Extents" }, 13054))
        .def("className", &PyGiDrawable::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyGiDrawable::desc, DS.SARGS(15560)).staticmethod("desc")
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
#if !defined (_BRXTARGET250)
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
#if defined(_ARXTARGET)
        .value("kThreadedWorldDrawViewportDraw", AcGiDrawable::SetAttributesFlags::kThreadedWorldDrawViewportDraw)
#endif
        .export_values()
        ;
}

PyGiDrawable::PyGiDrawable(AcGiDrawable* ptr, bool autoDelete, bool isDbObject)
    : PyRxObject(ptr, autoDelete, isDbObject)
{
}

Adesk::UInt32 PyGiDrawable::setAttributes(PyGiDrawableTraits& traits) const
{
    return impObj()->setAttributes(traits.impObj());
}

Adesk::Boolean PyGiDrawable::worldDraw(PyGiWorldDraw& wd) const
{
    return impObj()->worldDraw(wd.impObj());
}

void PyGiDrawable::viewportDraw(PyGiViewportDraw& vd) const
{
    return impObj()->viewportDraw(vd.impObj());
}

Adesk::UInt32 PyGiDrawable::viewportDrawLogicalFlags(PyGiViewportDraw& vd) const
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

Adesk::Boolean PyGiDrawable::rolloverHit(Adesk::ULongPtr nSubentId, Adesk::ULongPtr nMouseFlags, Adesk::Boolean bReset) const
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

PyGiDrawable PyGiDrawable::cast(const PyRxObject& src)
{
    return PyRxObjectCast<PyGiDrawable>(src);
}

AcGiDrawable* PyGiDrawable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiDrawable*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiDrawableOverrule
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
    : PyRxOverrule(this)
{
}

Adesk::UInt32 PyGiDrawableOverrule::setAttributes(PyGiDrawable& pSubject, PyGiDrawableTraits& traits) const
{
    return impObj()->setAttributes(pSubject.impObj(), traits.impObj());
}

bool PyGiDrawableOverrule::isApplicableWr(PyRxObject& pOverruledSubject) const
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = get_override("isApplicable"))
            return f(pOverruledSubject);
        isApplicableOverride = false;
        return false;
    }
    catch (...)
    {
        isApplicableOverride = false;
        printExceptionMsg();
    }
    return false;
}

Adesk::Boolean PyGiDrawableOverrule::worldDrawWr(PyGiDrawable& pSubject, PyGiWorldDraw& wd)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("worldDraw"))
            return f(pSubject, wd);
        return baseWorldDraw(pSubject, wd);
    }
    catch (...)
    {
        isWorldDrawOverride = false;
        printExceptionMsg();
    }
    return false;
}

void PyGiDrawableOverrule::viewportDrawWr(PyGiDrawable& pSubject, PyGiViewportDraw& vd)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("viewportDraw"))
            f(pSubject, vd);
        else
            baseViewportDraw(pSubject, vd);
    }
    catch (...)
    {
        isViewportDrawOverride = false;
        printExceptionMsg();
    }
}

Adesk::UInt32 PyGiDrawableOverrule::viewportDrawLogicalFlagsWr(PyGiDrawable& pSubject, PyGiViewportDraw& vd)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("viewportDrawLogicalFlags"))
            return f(pSubject, vd);
        isViewportDrawLogicalFlagsOverride = false;
        return baseViewportDrawLogicalFlags(pSubject, vd);
    }
    catch (...)
    {
        isViewportDrawLogicalFlagsOverride = false;
        printExceptionMsg();
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
#ifdef BRXAPP
    std::lock_guard<std::mutex> lk(PyGiDrawableOverruleMutex);
#endif // BRXAPP
    if (!isApplicableOverride)
        return false;
    PyRxObject obj(pOverruledSubject);
    return this->isApplicableWr(obj);
}

Adesk::Boolean PyGiDrawableOverrule::worldDraw(AcGiDrawable* pSubject, AcGiWorldDraw* wd)
{
    if (!isWorldDrawOverride)
        return AcGiDrawableOverrule::worldDraw(pSubject, wd);
    PyGiWorldDraw _wd(wd, false);
    PyGiDrawable _dr(pSubject, false, false);
    return worldDrawWr(_dr, _wd);
}

void PyGiDrawableOverrule::viewportDraw(AcGiDrawable* pSubject, AcGiViewportDraw* vd)
{
    if (!isViewportDrawOverride)
        return AcGiDrawableOverrule::viewportDraw(pSubject, vd);
    PyGiViewportDraw _vd(vd, false);
    PyGiDrawable _dr(pSubject, false, false);
    return viewportDrawWr(_dr, _vd);
}

Adesk::UInt32 PyGiDrawableOverrule::viewportDrawLogicalFlags(AcGiDrawable* pSubject, AcGiViewportDraw* vd)
{
    if (!isViewportDrawLogicalFlagsOverride)
        return AcGiDrawableOverrule::viewportDrawLogicalFlags(pSubject, vd);
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiDrawableOverrule*>(m_pyImp.get());
}
