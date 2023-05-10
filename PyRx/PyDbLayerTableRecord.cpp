#include "stdafx.h"
#include "PyDbLayerTableRecord.h"
#include "PyDbObjectId.h"
using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//AcDbLayerTableRecord wrapper
void makeAcDbLayerTableRecordWrapper()
{
    class_<PyDbLayerTableRecord, bases<PyDbSymbolTableRecord>>("LayerTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
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
        .def("className", &PyDbLayerTableRecord::className).staticmethod("className")
        .def("desc", &PyDbLayerTableRecord::desc).staticmethod("desc")
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
}

bool PyDbLayerTableRecord::isFrozen() const
{
    return impObj()->isFrozen();
}

Acad::ErrorStatus PyDbLayerTableRecord::setIsFrozen(bool frozen)
{
    return impObj()->setIsFrozen(frozen);
}

bool PyDbLayerTableRecord::isOff() const
{
    return impObj()->isOff();
}

void PyDbLayerTableRecord::setIsOff(bool off)
{
    return impObj()->setIsOff(off);
}

bool PyDbLayerTableRecord::VPDFLT() const
{
    return impObj()->VPDFLT();
}

void PyDbLayerTableRecord::setVPDFLT(bool frozen)
{
    return impObj()->setVPDFLT(frozen);
}

bool PyDbLayerTableRecord::isLocked() const
{
    return impObj()->isLocked();
}

void PyDbLayerTableRecord::setIsLocked(bool locked)
{
    return impObj()->setIsLocked(locked);
}

AcCmColor PyDbLayerTableRecord::color() const
{
    return impObj()->color();
}

AcCmColor PyDbLayerTableRecord::color(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->color(viewportId.m_id, flag);
}

void PyDbLayerTableRecord::setColor(const AcCmColor& _color)
{
    return impObj()->setColor(_color);
}

Acad::ErrorStatus PyDbLayerTableRecord::setColor(const AcCmColor& color, const PyDbObjectId& viewportId)
{
    return impObj()->setColor(color, viewportId.m_id);
}

AcCmEntityColor PyDbLayerTableRecord::entityColor(void) const
{
    return impObj()->entityColor();
}

AcCmTransparency PyDbLayerTableRecord::transparency(void) const
{
    return impObj()->transparency();
}

AcCmTransparency PyDbLayerTableRecord::transparency(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->transparency(viewportId.m_id, flag);
}

Acad::ErrorStatus PyDbLayerTableRecord::setTransparency(const AcCmTransparency& trans)
{
    return impObj()->setTransparency(trans);
}

Acad::ErrorStatus PyDbLayerTableRecord::setTransparency(const AcCmTransparency& trans, const PyDbObjectId& viewportId)
{
    return impObj()->setTransparency(trans, viewportId.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::removeColorOverride(const PyDbObjectId& viewportId)
{
    return impObj()->removeColorOverride(viewportId.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::removeLinetypeOverride(const PyDbObjectId& viewportId)
{
    return impObj()->removeLinetypeOverride(viewportId.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::removeLineWeightOverride(const PyDbObjectId& viewportId)
{
    return impObj()->removeLineWeightOverride(viewportId.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::removePlotStyleOverride(const PyDbObjectId& viewportId)
{
    return impObj()->removePlotStyleOverride(viewportId.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::removeTransparencyOverride(const PyDbObjectId& viewportId)
{
    return impObj()->removeTransparencyOverride(viewportId.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::removeViewportOverrides(const PyDbObjectId& viewportId)
{
    return impObj()->removeViewportOverrides(viewportId.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::removeAllOverrides()
{
    return impObj()->removeAllOverrides();
}

bool PyDbLayerTableRecord::hasOverrides(const PyDbObjectId& viewportId) const
{
    return impObj()->hasOverrides(viewportId.m_id);
}

bool PyDbLayerTableRecord::hasAnyOverrides() const
{
    return impObj()->hasAnyOverrides();
}

PyDbObjectId PyDbLayerTableRecord::linetypeObjectId() const
{
    return PyDbObjectId(impObj()->linetypeObjectId());
}

Acad::ErrorStatus PyDbLayerTableRecord::setLinetypeObjectId(const PyDbObjectId& id)
{
#ifdef BRXAPP
    impObj()->setLinetypeObjectId(id.m_id);
    return eOk;
#else
    return impObj()->setLinetypeObjectId(id.m_id);
#endif // BRXAPP
}

PyDbObjectId PyDbLayerTableRecord::materialId() const
{
    return PyDbObjectId(impObj()->linetypeObjectId());
}

Acad::ErrorStatus PyDbLayerTableRecord::setMaterialId(const PyDbObjectId& id)
{
    return impObj()->setMaterialId(id.m_id);
}

bool PyDbLayerTableRecord::isPlottable() const
{
    return impObj()->isPlottable();
}

Acad::ErrorStatus PyDbLayerTableRecord::setIsPlottable(bool plot)
{
    return impObj()->setIsPlottable(plot);
}

AcDb::LineWeight PyDbLayerTableRecord::lineWeight() const
{
    return impObj()->lineWeight();
}

AcDb::LineWeight PyDbLayerTableRecord::lineWeight(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return impObj()->lineWeight(viewportId.m_id, flag);
}

Acad::ErrorStatus PyDbLayerTableRecord::setLineWeight(AcDb::LineWeight weight)
{
    return impObj()->setLineWeight(weight);
}

Acad::ErrorStatus PyDbLayerTableRecord::setLineWeight(AcDb::LineWeight weight, const PyDbObjectId& viewportId)
{
    return impObj()->setLineWeight(weight, viewportId.m_id);
}

std::string PyDbLayerTableRecord::plotStyleName() const
{
    return wstr_to_utf8(impObj()->plotStyleName());
}

std::string PyDbLayerTableRecord::plotStyleName(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return wstr_to_utf8(impObj()->plotStyleName(viewportId.m_id, flag));
}

PyDbObjectId PyDbLayerTableRecord::plotStyleNameId() const
{
    return PyDbObjectId(impObj()->plotStyleNameId());
}

PyDbObjectId PyDbLayerTableRecord::plotStyleNameId(const PyDbObjectId& viewportId) const
{
    bool flag = false;
    return PyDbObjectId(impObj()->plotStyleNameId(viewportId.m_id, flag));
}

Acad::ErrorStatus PyDbLayerTableRecord::setPlotStyleName(const std::string& newName)
{
    return impObj()->setPlotStyleName(utf8_to_wstr(newName).c_str());
}

Acad::ErrorStatus PyDbLayerTableRecord::setPlotStyleName(const PyDbObjectId& newId)
{
    return impObj()->setPlotStyleName(newId.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::setPlotStyleName(const std::string& newName, const PyDbObjectId& viewportId)
{
    return impObj()->setPlotStyleName(utf8_to_wstr(newName).c_str(), viewportId.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::setPlotStyleName(const PyDbObjectId& newId, const PyDbObjectId& viewportId)
{
    return impObj()->setPlotStyleName(newId.m_id, viewportId.m_id);
}

bool PyDbLayerTableRecord::isInUse() const
{
    return impObj()->isInUse();
}

std::string PyDbLayerTableRecord::description() const
{
    return wstr_to_utf8(impObj()->description());
}

Acad::ErrorStatus PyDbLayerTableRecord::setDescription(const std::string& description)
{
    return impObj()->setDescription(utf8_to_wstr(description).c_str());
}

bool PyDbLayerTableRecord::isHidden() const
{
    return impObj()->isHidden();
}

bool PyDbLayerTableRecord::isHiddenS(const PyDbObjectId& id)
{
    return AcDbLayerTableRecord::isHidden(id.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::setIsHidden(bool on)
{
    return impObj()->setIsHidden(on);
}

bool PyDbLayerTableRecord::isReconciled() const
{
    return impObj()->isReconciled();
}

bool PyDbLayerTableRecord::isReconciledS(const PyDbObjectId& id)
{
    return AcDbLayerTableRecord::isReconciled(id.m_id);
}

Acad::ErrorStatus PyDbLayerTableRecord::setIsReconciled(bool bReconcile /*= true*/)
{
    return impObj()->setIsReconciled(bReconcile);
}

std::string PyDbLayerTableRecord::className()
{
    return "AcDbLayerTableRecord";
}

PyRxClass PyDbLayerTableRecord::desc()
{
    return PyRxClass(AcDbLayerTableRecord::desc(), false);
}

AcDbLayerTableRecord* PyDbLayerTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbLayerTableRecord*>(m_pImp.get());
}

