#include "stdafx.h"
#include "PyDbLayerTableRecord.h"
#include "PyDbObjectId.h"

using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//AcDbLayerTableRecord wrapper
void makeAcDbLayerTableRecordWrapper()
{
    static auto wrapper = class_<PyDbLayerTableRecord, bases<PyDbSymbolTableRecord>>("DbLayerTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbLayerTableRecord::className).staticmethod("className")
        .def("isFrozen", &PyDbLayerTableRecord::isFrozen)
        .def("setIsFrozen", &PyDbLayerTableRecord::setIsFrozen)
        .def("isOff", &PyDbLayerTableRecord::isOff)
        .def("setIsOff", &PyDbLayerTableRecord::setIsOff)
        .def("VPDFLT", &PyDbLayerTableRecord::VPDFLT)
        .def("setVPDFLT", &PyDbLayerTableRecord::setVPDFLT)
        .def("isLocked", &PyDbLayerTableRecord::isLocked)
        .def("setIsLocked", &PyDbLayerTableRecord::setIsLocked)

        .def<AcCmColor(PyDbLayerTableRecord::*)(void)const>("color", &PyDbLayerTableRecord::color)
        .def<AcCmColor(PyDbLayerTableRecord::*)(const PyDbObjectId&)const>("color", &PyDbLayerTableRecord::color)

        .def<void(PyDbLayerTableRecord::*)(const AcCmColor& color)>("setColor", &PyDbLayerTableRecord::setColor)
        .def<Acad::ErrorStatus(PyDbLayerTableRecord::*)(const AcCmColor& color, const PyDbObjectId&)>("setColor", &PyDbLayerTableRecord::setColor)

        .def("entityColor", &PyDbLayerTableRecord::entityColor)

        .def<AcCmTransparency(PyDbLayerTableRecord::*)(void)const>("transparency", &PyDbLayerTableRecord::transparency)
        .def<AcCmTransparency(PyDbLayerTableRecord::*)(const PyDbObjectId&)const>("transparency", &PyDbLayerTableRecord::transparency)

        .def<Acad::ErrorStatus(PyDbLayerTableRecord::*)(const AcCmTransparency&)>("setTransparency", &PyDbLayerTableRecord::setTransparency)
        .def<Acad::ErrorStatus(PyDbLayerTableRecord::*)(const AcCmTransparency&, const PyDbObjectId&)>("setTransparency", &PyDbLayerTableRecord::setTransparency)

        .def("linetypeObjectId", &PyDbLayerTableRecord::linetypeObjectId)
        .def("setLinetypeObjectId", &PyDbLayerTableRecord::setLinetypeObjectId)
        .def("materialId", &PyDbLayerTableRecord::materialId)
        .def("setMaterialId", &PyDbLayerTableRecord::setMaterialId)
        .def("isPlottable", &PyDbLayerTableRecord::isPlottable)
        .def("setIsPlottable", &PyDbLayerTableRecord::setIsPlottable)

        .def<AcDb::LineWeight(PyDbLayerTableRecord::*)(void)const>("lineWeight", &PyDbLayerTableRecord::lineWeight)
        .def<AcDb::LineWeight(PyDbLayerTableRecord::*)(const PyDbObjectId&)const>("lineWeight", &PyDbLayerTableRecord::lineWeight)

        .def<Acad::ErrorStatus(PyDbLayerTableRecord::*)(AcDb::LineWeight)>("setLineWeight", &PyDbLayerTableRecord::setLineWeight)
        .def<Acad::ErrorStatus(PyDbLayerTableRecord::*)(AcDb::LineWeight, const PyDbObjectId&)>("setLineWeight", &PyDbLayerTableRecord::setLineWeight)


        .def<std::string(PyDbLayerTableRecord::*)(void)const>("plotStyleName", &PyDbLayerTableRecord::plotStyleName)
        .def<std::string(PyDbLayerTableRecord::*)(const PyDbObjectId&)const>("plotStyleName", &PyDbLayerTableRecord::plotStyleName)

        .def<PyDbObjectId(PyDbLayerTableRecord::*)(void)const>("plotStyleNameId", &PyDbLayerTableRecord::plotStyleNameId)
        .def<PyDbObjectId(PyDbLayerTableRecord::*)(const PyDbObjectId&)const>("plotStyleNameId", &PyDbLayerTableRecord::plotStyleNameId)

        .def<Acad::ErrorStatus(PyDbLayerTableRecord::*)(const std::string&)>("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName)
        .def<Acad::ErrorStatus(PyDbLayerTableRecord::*)(const PyDbObjectId&)>("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName)
        .def<Acad::ErrorStatus(PyDbLayerTableRecord::*)(const PyDbObjectId&, const PyDbObjectId&)>("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName)
        .def<Acad::ErrorStatus(PyDbLayerTableRecord::*)(const std::string&, const PyDbObjectId&)>("setPlotStyleName", &PyDbLayerTableRecord::setPlotStyleName)

        .def("isInUse", &PyDbLayerTableRecord::isInUse)
        .def("description", &PyDbLayerTableRecord::description)
        .def("setDescription", &PyDbLayerTableRecord::setDescription)

        .def("setIsHidden", &PyDbLayerTableRecord::setIsHidden)
        .def("isHidden", &PyDbLayerTableRecord::isHidden)
        .def("isHidden", &PyDbLayerTableRecord::isHiddenS).staticmethod("isHidden")//TODO: can't override with a static

        .def("removeColorOverride", &PyDbLayerTableRecord::removeColorOverride)
        .def("removeLinetypeOverride", &PyDbLayerTableRecord::removeLinetypeOverride)
        .def("removeLineWeightOverride", &PyDbLayerTableRecord::removeLineWeightOverride)
        .def("removePlotStyleOverride", &PyDbLayerTableRecord::removePlotStyleOverride)
        .def("removeTransparencyOverride", &PyDbLayerTableRecord::removeTransparencyOverride)
        .def("removeViewportOverrides", &PyDbLayerTableRecord::removeViewportOverrides)
        .def("removeAllOverrides", &PyDbLayerTableRecord::removeAllOverrides)
        .def("removeAllOverrides", &PyDbLayerTableRecord::removeAllOverrides)

        .def("hasOverrides", &PyDbLayerTableRecord::hasOverrides)
        .def("hasAnyOverrides", &PyDbLayerTableRecord::hasAnyOverrides)
        .def("isReconciled", &PyDbLayerTableRecord::isReconciled)
        .def("isReconciled", &PyDbLayerTableRecord::isReconciledS).staticmethod("isReconciled")//TODO: can't override with a static test
        ;
}

//---------------------------------------------------------------------------------------- -
//AcDbLayerTableRecord wrapper
PyDbLayerTableRecord::PyDbLayerTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete)
    :PyDbSymbolTableRecord(ptr, false)
{
}

PyDbLayerTableRecord::PyDbLayerTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(nullptr, false)
{
    AcDbLayerTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbLayerTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);

    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

bool PyDbLayerTableRecord::isFrozen() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isFrozen();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setIsFrozen(bool frozen)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setIsFrozen(frozen);
    throw PyNullObject();
}

bool PyDbLayerTableRecord::isOff() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isOff();
    throw PyNullObject();
}

void PyDbLayerTableRecord::setIsOff(bool off)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setIsOff(off);
    throw PyNullObject();
}

bool PyDbLayerTableRecord::VPDFLT() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->VPDFLT();
    throw PyNullObject();
}

void PyDbLayerTableRecord::setVPDFLT(bool frozen)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setVPDFLT(frozen);
    throw PyNullObject();
}

bool PyDbLayerTableRecord::isLocked() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isLocked();
    throw PyNullObject();
}

void PyDbLayerTableRecord::setIsLocked(bool locked)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setIsLocked(locked);
    throw PyNullObject();
}

AcCmColor PyDbLayerTableRecord::color() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->color();
    throw PyNullObject();
}

AcCmColor PyDbLayerTableRecord::color(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    auto imp = impObj();
    if (imp != nullptr)
        return imp->color(viewportId.m_id, flag);
    throw PyNullObject();
}

void PyDbLayerTableRecord::setColor(const AcCmColor& _color)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setColor(_color);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setColor(const AcCmColor& color, const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setColor(color, viewportId.m_id);
    throw PyNullObject();
}

AcCmEntityColor PyDbLayerTableRecord::entityColor(void) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->entityColor();
    throw PyNullObject();
}

AcCmTransparency PyDbLayerTableRecord::transparency(void) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->transparency();
    throw PyNullObject();
}

AcCmTransparency PyDbLayerTableRecord::transparency(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    auto imp = impObj();
    if (imp != nullptr)
        return imp->transparency(viewportId.m_id, flag);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setTransparency(const AcCmTransparency& trans)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setTransparency(trans);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setTransparency(const AcCmTransparency& trans, const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setTransparency(trans, viewportId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::removeColorOverride(const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->removeColorOverride(viewportId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::removeLinetypeOverride(const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->removeLinetypeOverride(viewportId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::removeLineWeightOverride(const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->removeLineWeightOverride(viewportId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::removePlotStyleOverride(const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->removePlotStyleOverride(viewportId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::removeTransparencyOverride(const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->removeTransparencyOverride(viewportId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::removeViewportOverrides(const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->removeViewportOverrides(viewportId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::removeAllOverrides()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->removeAllOverrides();
    throw PyNullObject();
}

bool PyDbLayerTableRecord::hasOverrides(const PyDbObjectId& viewportId) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->hasOverrides(viewportId.m_id);
    throw PyNullObject();
}

bool PyDbLayerTableRecord::hasAnyOverrides() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->hasAnyOverrides();
    throw PyNullObject();
}

PyDbObjectId PyDbLayerTableRecord::linetypeObjectId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->linetypeObjectId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setLinetypeObjectId(const PyDbObjectId& id)
{
    auto imp = impObj();
#ifdef BRXAPP
    if (imp != nullptr)
    {
        imp->setLinetypeObjectId(id.m_id);
        return eOk;
    }
#else
    if (imp != nullptr)
        return imp->setLinetypeObjectId(id.m_id);
#endif // BRXAPP
    throw PyNullObject();
}

PyDbObjectId PyDbLayerTableRecord::materialId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->linetypeObjectId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setMaterialId(const PyDbObjectId& id)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setMaterialId(id.m_id);
    throw PyNullObject();
}

bool PyDbLayerTableRecord::isPlottable() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isPlottable();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setIsPlottable(bool plot)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setIsPlottable(plot);
    throw PyNullObject();
}

AcDb::LineWeight PyDbLayerTableRecord::lineWeight() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lineWeight();
    throw PyNullObject();
}

AcDb::LineWeight PyDbLayerTableRecord::lineWeight(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lineWeight(viewportId.m_id, flag);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setLineWeight(AcDb::LineWeight weight)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setLineWeight(weight);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setLineWeight(AcDb::LineWeight weight, const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setLineWeight(weight, viewportId.m_id);
    throw PyNullObject();
}

std::string PyDbLayerTableRecord::plotStyleName() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->plotStyleName());
    throw PyNullObject();
}

std::string PyDbLayerTableRecord::plotStyleName(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->plotStyleName(viewportId.m_id, flag));
    throw PyNullObject();
}

PyDbObjectId PyDbLayerTableRecord::plotStyleNameId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->plotStyleNameId());
    throw PyNullObject();
}

PyDbObjectId PyDbLayerTableRecord::plotStyleNameId(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->plotStyleNameId(viewportId.m_id, flag));
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setPlotStyleName(const std::string& newName)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setPlotStyleName(utf8_to_wstr(newName).c_str());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setPlotStyleName(const PyDbObjectId& newId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setPlotStyleName(newId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setPlotStyleName(const std::string& newName, const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setPlotStyleName(utf8_to_wstr(newName).c_str(), viewportId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setPlotStyleName(const PyDbObjectId& newId, const PyDbObjectId& viewportId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setPlotStyleName(newId.m_id, viewportId.m_id);
    throw PyNullObject();
}

bool PyDbLayerTableRecord::isInUse() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isInUse();
    throw PyNullObject();
}

std::string PyDbLayerTableRecord::description() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->description());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbLayerTableRecord::setDescription(const std::string& description)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setDescription(utf8_to_wstr(description).c_str());
    throw PyNullObject();
}

bool PyDbLayerTableRecord::isHidden() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isHidden();
    throw PyNullObject();
}

bool PyDbLayerTableRecord::isHiddenS(const PyDbObjectId& id)
{
    return AcDbLayerTableRecord::isHidden(id.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::setIsHidden(bool on)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setIsHidden(on);
    throw PyNullObject();
}

bool PyDbLayerTableRecord::isReconciled() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isReconciled();
    throw PyNullObject();
}

bool PyDbLayerTableRecord::isReconciledS(const PyDbObjectId& id)
{
    return AcDbLayerTableRecord::isReconciled(id.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::setIsReconciled(bool bReconcile /*= true*/)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setIsReconciled(bReconcile);
    throw PyNullObject();
}

std::string PyDbLayerTableRecord::className()
{
    return "AcDbLayerTableRecord";
}

AcDbLayerTableRecord* PyDbLayerTableRecord::impObj() const
{
    return static_cast<AcDbLayerTableRecord*>(m_pImp.get());
}
