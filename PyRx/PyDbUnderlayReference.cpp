#include "stdafx.h"
#include "PyDbUnderlayReference.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyUnderlayLayer
void makePyUnderlayLayerWrapper()
{
    class_<PyUnderlayLayer>("UnderlayLayer")
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
        .def("name", &PyUnderlayLayer::name)
        .def("state", &PyUnderlayLayer::state)
        .def("setName", &PyUnderlayLayer::setName)
        .def("setState", &PyUnderlayLayer::setState)
#endif
        ;
}

PyUnderlayLayer::PyUnderlayLayer()
{
}

#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
PyUnderlayLayer::PyUnderlayLayer(const AcUnderlayLayer& layer)
    : imp(layer)
{
}

std::string PyUnderlayLayer::name()
{
    return wstr_to_utf8(imp.name());
}

bool PyUnderlayLayer::state() const
{
    return imp.state() == AcUnderlayLayer::kOn;
}

void PyUnderlayLayer::setName(const std::string& name)
{
    return PyThrowBadEs(imp.setName(utf8_to_wstr(name).c_str()));
}

void PyUnderlayLayer::setState(bool state)
{
    return PyThrowBadEs(imp.setState(state ? AcUnderlayLayer::kOn : AcUnderlayLayer::kOff));
}
#endif

//-----------------------------------------------------------------------------------
//PyDbUnderlayDefinition
void makePyDbUnderlayDefinitionWrapper()
{
    class_<PyDbUnderlayDefinition, bases<PyDbObject>>("UnderlayDefinition", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("setSourceFileName", &PyDbUnderlayDefinition::setSourceFileName)
        .def("getSourceFileName", &PyDbUnderlayDefinition::getSourceFileName)
        .def("getActiveFileName", &PyDbUnderlayDefinition::getActiveFileName)
        .def("setItemName", &PyDbUnderlayDefinition::setItemName)
        .def("getItemName", &PyDbUnderlayDefinition::getItemName)
        .def("load", &PyDbUnderlayDefinition::load1)
        .def("load", &PyDbUnderlayDefinition::load2)
        .def("unload", &PyDbUnderlayDefinition::unload)
        .def("isLoaded", &PyDbUnderlayDefinition::isLoaded)
        .def("dictionaryKey", &PyDbUnderlayDefinition::dictionaryKey).staticmethod("dictionaryKey")
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

PyDbUnderlayDefinition::PyDbUnderlayDefinition(const PyDbObjectId& id)
    : PyDbUnderlayDefinition(id, AcDb::OpenMode::kForRead)
{
}

void PyDbUnderlayDefinition::setSourceFileName(const std::string& file)
{
    return PyThrowBadEs(impObj()->setSourceFileName(utf8_to_wstr(file).c_str()));
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

void PyDbUnderlayDefinition::setItemName(const std::string& item)
{
    return PyThrowBadEs(impObj()->setItemName(utf8_to_wstr(item).c_str()));
}

std::string PyDbUnderlayDefinition::getItemName() const
{
    return wstr_to_utf8(impObj()->getItemName());
}

void PyDbUnderlayDefinition::load1()
{
    return PyThrowBadEs(impObj()->load(nullptr));
}

void PyDbUnderlayDefinition::load2(const std::string& password)
{
    return PyThrowBadEs(impObj()->load(utf8_to_wstr(password).c_str()));
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
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbUnderlayReference::position)
        .def("setPosition", &PyDbUnderlayReference::setPosition)
        .def("scaleFactors", &PyDbUnderlayReference::scaleFactors)
        .def("setScaleFactors", &PyDbUnderlayReference::setScaleFactors)
        .def("rotation", &PyDbUnderlayReference::rotation)
        .def("setRotation", &PyDbUnderlayReference::setRotation)
        .def("normal", &PyDbUnderlayReference::normal)
        .def("setNormal", &PyDbUnderlayReference::setNormal)
        .def("transform", &PyDbUnderlayReference::transform)
        .def("setTransform", &PyDbUnderlayReference::setTransform)
        .def("definitionId", &PyDbUnderlayReference::definitionId)
        .def("setDefinitionId", &PyDbUnderlayReference::setDefinitionId)
        .def("setWidth", &PyDbUnderlayReference::setWidth)
        .def("width", &PyDbUnderlayReference::width)
        .def("setHeight", &PyDbUnderlayReference::setHeight)
        .def("height", &PyDbUnderlayReference::height)
        .def("clipBoundary", &PyDbUnderlayReference::clipBoundary)
        .def("setClipBoundary", &PyDbUnderlayReference::setClipBoundary)
        .def("isClipped", &PyDbUnderlayReference::isClipped)
        .def("setIsClipped", &PyDbUnderlayReference::setIsClipped)
        .def("contrast", &PyDbUnderlayReference::contrast)
        .def("setContrast", &PyDbUnderlayReference::setContrast)
        .def("fade", &PyDbUnderlayReference::fade)
        .def("setFade", &PyDbUnderlayReference::setFade)
        .def("isOn", &PyDbUnderlayReference::isOn)
        .def("setIsOn", &PyDbUnderlayReference::setIsOn)
        .def("isMonochrome", &PyDbUnderlayReference::isMonochrome)
        .def("setIsMonochrome", &PyDbUnderlayReference::setIsMonochrome)
        .def("isAdjustedForBackground", &PyDbUnderlayReference::isAdjustedForBackground)
        .def("setIsAdjustedForBackground", &PyDbUnderlayReference::setIsAdjustedForBackground)
        .def("isFrameVisible", &PyDbUnderlayReference::isFrameVisible)
        .def("isFramePlottable", &PyDbUnderlayReference::isFramePlottable)
        .def("underlayLayerCount", &PyDbUnderlayReference::underlayLayerCount)
        .def("getUnderlayLayer", &PyDbUnderlayReference::getUnderlayLayer)
        .def("setUnderlayLayer", &PyDbUnderlayReference::setUnderlayLayer)
        .def("isClipInverted", &PyDbUnderlayReference::isClipInverted)
        .def("setClipInverted", &PyDbUnderlayReference::setClipInverted)
        .def("generateClipBoundaryFromPline", &PyDbUnderlayReference::generateClipBoundaryFromPline)
        .def("contrastLowerLimit", &PyDbUnderlayReference::contrastLowerLimit).staticmethod("contrastLowerLimit")
        .def("contrastDefault", &PyDbUnderlayReference::contrastDefault).staticmethod("contrastDefault")
        .def("fadeLowerLimit", &PyDbUnderlayReference::fadeLowerLimit).staticmethod("fadeLowerLimit")
        .def("fadeUpperLimit", &PyDbUnderlayReference::fadeUpperLimit).staticmethod("fadeUpperLimit")
        .def("fadeDefault", &PyDbUnderlayReference::fadeDefault).staticmethod("fadeDefault")
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

PyDbUnderlayReference::PyDbUnderlayReference(const PyDbObjectId& id)
    : PyDbUnderlayReference(id, AcDb::OpenMode::kForRead)
{
}

AcGePoint3d PyDbUnderlayReference::position() const
{
    return impObj()->position();
}

void PyDbUnderlayReference::setPosition(const AcGePoint3d& position)
{
    return PyThrowBadEs(impObj()->setPosition(position));
}

AcGeScale3d PyDbUnderlayReference::scaleFactors() const
{
    return impObj()->scaleFactors();
}

void PyDbUnderlayReference::setScaleFactors(const AcGeScale3d& scale)
{
    return PyThrowBadEs(impObj()->setScaleFactors(scale));
}

double PyDbUnderlayReference::rotation() const
{
    return impObj()->rotation();
}

void PyDbUnderlayReference::setRotation(double rotation)
{
    return PyThrowBadEs(impObj()->setRotation(rotation));
}

AcGeVector3d PyDbUnderlayReference::normal() const
{
    return impObj()->normal();
}

void PyDbUnderlayReference::setNormal(const AcGeVector3d& normal)
{
    return PyThrowBadEs(impObj()->setNormal(normal));
}

AcGeMatrix3d PyDbUnderlayReference::transform() const
{
    return impObj()->transform();
}

void PyDbUnderlayReference::setTransform(const AcGeMatrix3d& transform)
{
    return PyThrowBadEs(impObj()->setTransform(transform));
}

PyDbObjectId PyDbUnderlayReference::definitionId() const
{
    return PyDbObjectId(impObj()->definitionId());
}

void PyDbUnderlayReference::setDefinitionId(const PyDbObjectId& id)
{
    return PyThrowBadEs(impObj()->setDefinitionId(id.m_id));
}

void PyDbUnderlayReference::setWidth(double width)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setWidth(width));
#endif
}


double PyDbUnderlayReference::width() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    double val = 0;
    if (auto es = impObj()->width(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
#endif
}

void PyDbUnderlayReference::setHeight(double width)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setHeight(width));
#endif
}

double PyDbUnderlayReference::height() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
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

void PyDbUnderlayReference::setClipBoundary(const boost::python::list& clip)
{
    AcGePoint2dArray _clip;
    auto pnts = py_list_to_std_vector<AcGePoint2d>(clip);
    for (auto& item : pnts)
        _clip.append(item);
    return PyThrowBadEs(impObj()->setClipBoundary(_clip));
}

bool PyDbUnderlayReference::isClipped() const
{
    return impObj()->isClipped();
}

void PyDbUnderlayReference::setIsClipped(bool value)
{
    return PyThrowBadEs(impObj()->setIsClipped(value));
}

Adesk::UInt8 PyDbUnderlayReference::contrast() const
{
    return impObj()->contrast();
}

void PyDbUnderlayReference::setContrast(Adesk::UInt8 value)
{
    return PyThrowBadEs(impObj()->setContrast(value));
}

Adesk::UInt8 PyDbUnderlayReference::fade() const
{
    return impObj()->fade();
}

void PyDbUnderlayReference::setFade(Adesk::UInt8 value)
{
    return PyThrowBadEs(impObj()->setFade(value));
}

bool PyDbUnderlayReference::isOn() const
{
    return impObj()->isOn();
}

void PyDbUnderlayReference::setIsOn(bool value)
{
    return PyThrowBadEs(impObj()->setIsOn(value));
}

bool PyDbUnderlayReference::isMonochrome() const
{
    return impObj()->isMonochrome();
}

void PyDbUnderlayReference::setIsMonochrome(bool value)
{
    return PyThrowBadEs(impObj()->setIsMonochrome(value));
}

bool PyDbUnderlayReference::isAdjustedForBackground() const
{
    return impObj()->isAdjustedForBackground();
}

void PyDbUnderlayReference::setIsAdjustedForBackground(bool value)
{
    return PyThrowBadEs(impObj()->setIsAdjustedForBackground(value));
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->underlayLayerCount();
#endif
}

PyUnderlayLayer PyDbUnderlayReference::getUnderlayLayer(int index) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcUnderlayLayer val;
    if (auto es = impObj()->getUnderlayLayer(index, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyUnderlayLayer(val);
#endif
}

void PyDbUnderlayReference::setUnderlayLayer(int index, const PyUnderlayLayer& layer)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUnderlayLayer(index, layer.imp));
#endif
}

bool PyDbUnderlayReference::isClipInverted() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->isClipInverted();
#endif
}

void PyDbUnderlayReference::setClipInverted(bool value)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setClipInverted(value));
#endif
}

void PyDbUnderlayReference::generateClipBoundaryFromPline(PyDbObjectId& polyId)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->generateClipBoundaryFromPline(polyId.m_id));
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



//-----------------------------------------------------------------------------------
//PyDbPdfDefinition
void makePyDbPdfDefinitionWrapper()
{
    class_<PyDbPdfDefinition, bases<PyDbUnderlayDefinition>>("PdfDefinition")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbUnderlayDefinition::className).staticmethod("className")
        .def("desc", &PyDbUnderlayDefinition::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbUnderlayDefinition::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbUnderlayDefinition::cast).staticmethod("cast")
        ;
}

PyDbPdfDefinition::PyDbPdfDefinition()
  : PyDbUnderlayDefinition(new AcDbPdfDefinition(), true)
{

}

PyDbPdfDefinition::PyDbPdfDefinition(AcDbUnderlayDefinition* ptr, bool autoDelete)
    : PyDbUnderlayDefinition(ptr, autoDelete)
{

}

PyDbPdfDefinition::PyDbPdfDefinition(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbUnderlayDefinition(nullptr, false)
{
    AcDbPdfDefinition* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPdfDefinition>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbPdfDefinition::PyDbPdfDefinition(const PyDbObjectId& id)
    : PyDbPdfDefinition(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbPdfDefinition::className()
{
    return "AcDbPdfDefinition";
}

PyRxClass PyDbPdfDefinition::desc()
{
    return PyRxClass(AcDbPdfDefinition::desc(), false);
}

PyDbPdfDefinition PyDbPdfDefinition::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPdfDefinition::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPdfDefinition(static_cast<AcDbPdfDefinition*>(src.impObj()->clone()), true);
}

PyDbPdfDefinition PyDbPdfDefinition::cast(const PyRxObject& src)
{
    PyDbPdfDefinition dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPdfDefinition* PyDbPdfDefinition::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbPdfDefinition*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbPdfReference
void makePyDbPdfReferenceWrapper()
{
    class_<PyDbPdfReference, bases<PyDbUnderlayReference>>("PdfReference")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbPdfReference::className).staticmethod("className")
        .def("desc", &PyDbPdfReference::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbPdfReference::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbPdfReference::cast).staticmethod("cast")
        ;
}

PyDbPdfReference::PyDbPdfReference()
    : PyDbUnderlayReference(new AcDbPdfReference(), true)
{
}

PyDbPdfReference::PyDbPdfReference(AcDbPdfReference* ptr, bool autoDelete)
    : PyDbUnderlayReference(ptr, autoDelete)
{
}

PyDbPdfReference::PyDbPdfReference(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbUnderlayReference(nullptr,false)
{
    AcDbPdfReference* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPdfReference>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbPdfReference::PyDbPdfReference(const PyDbObjectId& id)
    : PyDbPdfReference(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbPdfReference::className()
{
    return "AcDbPdfReference";
}

PyRxClass PyDbPdfReference::desc()
{
    return PyRxClass(AcDbPdfReference::desc(), false);
}

PyDbPdfReference PyDbPdfReference::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPdfReference::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPdfReference(static_cast<AcDbPdfReference*>(src.impObj()->clone()), true);
}

PyDbPdfReference PyDbPdfReference::cast(const PyRxObject& src)
{
    PyDbPdfReference dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPdfReference* PyDbPdfReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbPdfReference*>(m_pyImp.get());
}
