#include "stdafx.h"
#include "PyDbUnderlayReference.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyUnderlayLayer
void makePyUnderlayLayerWrapper()
{

}

PyUnderlayLayer::PyUnderlayLayer()
{
}

#ifndef BRXAPP
PyUnderlayLayer::PyUnderlayLayer(const AcUnderlayLayer& layer)
    : imp(layer)
{
}

std::string PyUnderlayLayer::name()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(imp.name());
#endif
}

bool PyUnderlayLayer::state() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return imp.state() == AcUnderlayLayer::kOn;
#endif
}

Acad::ErrorStatus PyUnderlayLayer::setName(const std::string& name)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return imp.setName(utf8_to_wstr(name).c_str());
#endif
}

Acad::ErrorStatus PyUnderlayLayer::setState(bool state)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return imp.setState(state ? AcUnderlayLayer::kOn : AcUnderlayLayer::kOff);
#endif
}

#endif
//-----------------------------------------------------------------------------------
//PyDbUnderlayDefinition
void makePyDbUnderlayDefinitionWrapper()
{
    class_<PyDbUnderlayDefinition, bases<PyDbObject>>("UnderlayDefinition", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbUnderlayDefinition::className).staticmethod("className")
        .def("desc", &PyDbUnderlayDefinition::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbUnderlayDefinition::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbUnderlayDefinition::cast).staticmethod("cast")
        ;
}

PyDbUnderlayDefinition::PyDbUnderlayDefinition(AcDbUnderlayDefinition* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbUnderlayDefinition::PyDbUnderlayDefinition(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbUnderlayDefinition* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbUnderlayDefinition>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

Acad::ErrorStatus PyDbUnderlayDefinition::setSourceFileName(const std::string& file)
{
    return impObj()->setSourceFileName(utf8_to_wstr(file).c_str());

}

const std::string PyDbUnderlayDefinition::getSourceFileName() const
{
    return wstr_to_utf8(impObj()->getSourceFileName());
}

std::string PyDbUnderlayDefinition::getActiveFileName() const
{
    const TCHAR* file = nullptr;
    if (auto es = impObj()->getActiveFileName(file); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(file);
}

Acad::ErrorStatus PyDbUnderlayDefinition::setItemName(const std::string& item)
{
    return impObj()->setItemName(utf8_to_wstr(item).c_str());
}

std::string PyDbUnderlayDefinition::getItemName() const
{
    return wstr_to_utf8(impObj()->getItemName());
}

Acad::ErrorStatus PyDbUnderlayDefinition::load1()
{
    return impObj()->load(nullptr);
}

Acad::ErrorStatus PyDbUnderlayDefinition::load2(const std::string& password)
{
    return impObj()->load(utf8_to_wstr(password).c_str());
}

void PyDbUnderlayDefinition::unload()
{
    impObj()->unload();
}

bool PyDbUnderlayDefinition::isLoaded() const
{
    return impObj()->isLoaded();
}

std::string PyDbUnderlayDefinition::dictionaryKey(const PyRxClass& underlayDefinitionType)
{
    return wstr_to_utf8(AcDbUnderlayDefinition::dictionaryKey(underlayDefinitionType.impObj()));
}

std::string PyDbUnderlayDefinition::className()
{
    return "AcDbUnderlayDefinition";
}

PyRxClass PyDbUnderlayDefinition::desc()
{
    return PyRxClass(AcDbUnderlayDefinition::desc(), false);
}

PyDbUnderlayDefinition PyDbUnderlayDefinition::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbUnderlayDefinition::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbUnderlayDefinition(static_cast<AcDbUnderlayDefinition*>(src.impObj()->clone()), true);
}

PyDbUnderlayDefinition PyDbUnderlayDefinition::cast(const PyRxObject& src)
{
    PyDbUnderlayDefinition dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbUnderlayDefinition* PyDbUnderlayDefinition::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbUnderlayDefinition*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbUnderlayReference
void makePyDbUnderlayReferenceWrapper()
{
    class_<PyDbUnderlayReference, bases<PyDbEntity>>("UnderlayReference", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbUnderlayReference::className).staticmethod("className")
        .def("desc", &PyDbUnderlayReference::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbUnderlayReference::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbUnderlayReference::cast).staticmethod("cast")
        ;
}

PyDbUnderlayReference::PyDbUnderlayReference(AcDbUnderlayReference* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbUnderlayReference::PyDbUnderlayReference(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbUnderlayReference* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbUnderlayReference>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

AcGePoint3d PyDbUnderlayReference::position() const
{
    return impObj()->position();
}

Acad::ErrorStatus PyDbUnderlayReference::setPosition(const AcGePoint3d& position)
{
    return impObj()->setPosition(position);
}

AcGeScale3d PyDbUnderlayReference::scaleFactors() const
{
    return impObj()->scaleFactors();
}

Acad::ErrorStatus PyDbUnderlayReference::setScaleFactors(const AcGeScale3d& scale)
{
    return impObj()->setScaleFactors(scale);
}

double PyDbUnderlayReference::rotation() const
{
    return impObj()->rotation();
}

Acad::ErrorStatus PyDbUnderlayReference::setRotation(double rotation)
{
    return impObj()->setRotation(rotation);
}

AcGeVector3d PyDbUnderlayReference::normal() const
{
    return impObj()->normal();
}

Acad::ErrorStatus PyDbUnderlayReference::setNormal(const AcGeVector3d& normal)
{
    return impObj()->setNormal(normal);
}

AcGeMatrix3d PyDbUnderlayReference::transform() const
{
    return impObj()->transform();
}

Acad::ErrorStatus PyDbUnderlayReference::setTransform(const AcGeMatrix3d& transform)
{
    return impObj()->setTransform(transform);
}

PyDbObjectId PyDbUnderlayReference::definitionId() const
{
    return PyDbObjectId(impObj()->definitionId());
}

Acad::ErrorStatus PyDbUnderlayReference::setDefinitionId(const PyDbObjectId& id)
{
    return impObj()->setDefinitionId(id.m_id);
}

Acad::ErrorStatus PyDbUnderlayReference::setWidth(double width)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setWidth(width);
#endif
}


double PyDbUnderlayReference::width() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    double val = 0;
    if (auto es = impObj()->width(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
#endif
}

Acad::ErrorStatus PyDbUnderlayReference::setHeight(double width)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setHeight(width);
#endif
}

double PyDbUnderlayReference::height() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    double val = 0;
    if (auto es = impObj()->height(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
#endif
}

boost::python::list PyDbUnderlayReference::clipBoundary() const
{
    PyAutoLockGIL lock;
    boost::python::list result;
    const AcGePoint2dArray& clip = impObj()->clipBoundary();
    for (auto& item : clip)
        result.append(item);
    return result;
}

Acad::ErrorStatus PyDbUnderlayReference::setClipBoundary(const boost::python::list& clip)
{
    AcGePoint2dArray _clip;
    auto pnts = py_list_to_std_vector<AcGePoint2d>(clip);
    for (auto& item : pnts)
        _clip.append(item);
    return impObj()->setClipBoundary(_clip);
}

bool PyDbUnderlayReference::isClipped() const
{
    return impObj()->isClipped();
}

Acad::ErrorStatus PyDbUnderlayReference::setIsClipped(bool value)
{
    return impObj()->setIsClipped(value);
}

Adesk::UInt8 PyDbUnderlayReference::contrast() const
{
    return impObj()->contrast();
}

Acad::ErrorStatus PyDbUnderlayReference::setContrast(Adesk::UInt8 value)
{
    return impObj()->setContrast(value);
}

Adesk::UInt8 PyDbUnderlayReference::fade() const
{
    return impObj()->fade();
}

Acad::ErrorStatus PyDbUnderlayReference::setFade(Adesk::UInt8 value)
{
    return impObj()->setFade(value);
}

bool PyDbUnderlayReference::isOn() const
{
    return impObj()->isOn();
}

Acad::ErrorStatus PyDbUnderlayReference::setIsOn(bool value)
{
    return impObj()->setIsOn(value);
}

bool PyDbUnderlayReference::isMonochrome() const
{
    return impObj()->isMonochrome();
}

Acad::ErrorStatus PyDbUnderlayReference::setIsMonochrome(bool value)
{
    return impObj()->setIsMonochrome(value);
}

bool PyDbUnderlayReference::isAdjustedForBackground() const
{
    return impObj()->isAdjustedForBackground();
}

Acad::ErrorStatus PyDbUnderlayReference::setIsAdjustedForBackground(bool value)
{
    return impObj()->setIsAdjustedForBackground(value);
}

bool PyDbUnderlayReference::isFrameVisible() const
{
    return impObj()->isFrameVisible();
}

bool PyDbUnderlayReference::isFramePlottable() const
{
    return impObj()->isFramePlottable();
}

Adesk::UInt32 PyDbUnderlayReference::underlayLayerCount() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->underlayLayerCount();
#endif
}

PyUnderlayLayer PyDbUnderlayReference::getUnderlayLayer(int index) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcUnderlayLayer val;
    if (auto es = impObj()->getUnderlayLayer(index, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyUnderlayLayer(val);
#endif
}

Acad::ErrorStatus PyDbUnderlayReference::setUnderlayLayer(int index, const PyUnderlayLayer& layer)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setUnderlayLayer(index, layer.imp);
#endif
}

bool PyDbUnderlayReference::isClipInverted() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isClipInverted();
#endif
}

Acad::ErrorStatus PyDbUnderlayReference::setClipInverted(bool value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setClipInverted(value);
#endif
}

Acad::ErrorStatus PyDbUnderlayReference::generateClipBoundaryFromPline(PyDbObjectId& polyId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->generateClipBoundaryFromPline(polyId.m_id);
#endif
}

Adesk::UInt8 PyDbUnderlayReference::contrastLowerLimit()
{
   return AcDbUnderlayReference::contrastLowerLimit();
}

Adesk::UInt8 PyDbUnderlayReference::contrastDefault()
{
    return AcDbUnderlayReference::contrastDefault();
}

Adesk::UInt8 PyDbUnderlayReference::fadeLowerLimit()
{
    return AcDbUnderlayReference::fadeLowerLimit();
}

Adesk::UInt8 PyDbUnderlayReference::fadeUpperLimit()
{
    return AcDbUnderlayReference::fadeUpperLimit();
}

Adesk::UInt8 PyDbUnderlayReference::fadeDefault()
{
    return AcDbUnderlayReference::fadeDefault();
}

std::string PyDbUnderlayReference::className()
{
    return "AcDbUnderlayReference";
}

PyRxClass PyDbUnderlayReference::desc()
{
    return PyRxClass(AcDbUnderlayReference::desc(), false);
}

PyDbUnderlayReference PyDbUnderlayReference::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbUnderlayReference::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbUnderlayReference(static_cast<AcDbUnderlayReference*>(src.impObj()->clone()), true);
}

PyDbUnderlayReference PyDbUnderlayReference::cast(const PyRxObject& src)
{
    PyDbUnderlayReference dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbUnderlayReference* PyDbUnderlayReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbUnderlayReference*>(m_pyImp.get());
}

