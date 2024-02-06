#include "stdafx.h"
#include "PyDbUnderlayReference.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyUnderlayLayer
void makePyUnderlayLayerWrapper()
{
    PyDocString DS("UnderlayLayer");
    class_<PyUnderlayLayer>("UnderlayLayer")
        .def("name", &PyUnderlayLayer::name, DS.ARGS())
        .def("state", &PyUnderlayLayer::state, DS.ARGS())
        .def("setName", &PyUnderlayLayer::setName, DS.ARGS({ "name : str" }))
        .def("setState", &PyUnderlayLayer::setState, DS.ARGS({ "state : bool" }))
        ;
}

PyUnderlayLayer::PyUnderlayLayer()
{
}

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

//-----------------------------------------------------------------------------------
//PyDbUnderlayDefinition
void makePyDbUnderlayDefinitionWrapper()
{
    PyDocString DS("UnderlayDefinition");
    class_<PyDbUnderlayDefinition, bases<PyDbObject>>("UnderlayDefinition", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("setSourceFileName", &PyDbUnderlayDefinition::setSourceFileName, DS.ARGS({ "file : str" }))
        .def("getSourceFileName", &PyDbUnderlayDefinition::getSourceFileName, DS.ARGS())
        .def("getActiveFileName", &PyDbUnderlayDefinition::getActiveFileName, DS.ARGS())
        .def("setItemName", &PyDbUnderlayDefinition::setItemName, DS.ARGS({ "item : str" }))
        .def("getItemName", &PyDbUnderlayDefinition::getItemName, DS.ARGS())
        .def("load", &PyDbUnderlayDefinition::load1)
        .def("load", &PyDbUnderlayDefinition::load2, DS.ARGS({ "passwd : str=None" }))
        .def("unload", &PyDbUnderlayDefinition::unload, DS.ARGS())
        .def("isLoaded", &PyDbUnderlayDefinition::isLoaded, DS.ARGS())
        .def("dictionaryKey", &PyDbUnderlayDefinition::dictionaryKey, DS.SARGS({ "underlayDefinitionType: PyRx.RxClass" })).staticmethod("dictionaryKey")
        .def("className", &PyDbUnderlayDefinition::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbUnderlayDefinition::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbUnderlayDefinition::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbUnderlayDefinition::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbUnderlayDefinition::PyDbUnderlayDefinition(AcDbUnderlayDefinition* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbUnderlayDefinition::PyDbUnderlayDefinition(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbUnderlayDefinition>(id, mode), false)
{
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
    PyThrowBadEs(impObj()->getActiveFileName(file));
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbUnderlayDefinition*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbUnderlayReference
void makePyDbUnderlayReferenceWrapper()
{
    PyDocString DS("UnderlayReference");
    class_<PyDbUnderlayReference, bases<PyDbEntity>>("UnderlayReference", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode,bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("position", &PyDbUnderlayReference::position, DS.ARGS())
        .def("setPosition", &PyDbUnderlayReference::setPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("scaleFactors", &PyDbUnderlayReference::scaleFactors, DS.ARGS())
        .def("setScaleFactors", &PyDbUnderlayReference::setScaleFactors, DS.ARGS({ "val : PyGe.Scale3d" }))
        .def("rotation", &PyDbUnderlayReference::rotation, DS.ARGS())
        .def("setRotation", &PyDbUnderlayReference::setRotation, DS.ARGS({ "val : float" }))
        .def("normal", &PyDbUnderlayReference::normal, DS.ARGS())
        .def("setNormal", &PyDbUnderlayReference::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("transform", &PyDbUnderlayReference::transform, DS.ARGS())
        .def("setTransform", &PyDbUnderlayReference::setTransform, DS.ARGS({ "val : PyGe.Matrix3d" }))
        .def("definitionId", &PyDbUnderlayReference::definitionId, DS.ARGS())
        .def("setDefinitionId", &PyDbUnderlayReference::setDefinitionId, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("setWidth", &PyDbUnderlayReference::setWidth, DS.ARGS({ "val : float" }))
        .def("width", &PyDbUnderlayReference::width, DS.ARGS())
        .def("setHeight", &PyDbUnderlayReference::setHeight, DS.ARGS({ "val : float" }))
        .def("height", &PyDbUnderlayReference::height, DS.ARGS())
        .def("clipBoundary", &PyDbUnderlayReference::clipBoundary, DS.ARGS())
        .def("setClipBoundary", &PyDbUnderlayReference::setClipBoundary, DS.ARGS({ "pnts : List[PyGe.Point2d]" }))
        .def("isClipped", &PyDbUnderlayReference::isClipped, DS.ARGS())
        .def("setIsClipped", &PyDbUnderlayReference::setIsClipped, DS.ARGS({ "val : bool" }))
        .def("contrast", &PyDbUnderlayReference::contrast, DS.ARGS())
        .def("setContrast", &PyDbUnderlayReference::setContrast, DS.ARGS({ "val : int" }))
        .def("fade", &PyDbUnderlayReference::fade, DS.ARGS())
        .def("setFade", &PyDbUnderlayReference::setFade, DS.ARGS({ "val : int" }))
        .def("isOn", &PyDbUnderlayReference::isOn, DS.ARGS())
        .def("setIsOn", &PyDbUnderlayReference::setIsOn, DS.ARGS({ "val : bool" }))
        .def("isMonochrome", &PyDbUnderlayReference::isMonochrome, DS.ARGS())
        .def("setIsMonochrome", &PyDbUnderlayReference::setIsMonochrome, DS.ARGS({ "val : bool" }))
        .def("isAdjustedForBackground", &PyDbUnderlayReference::isAdjustedForBackground, DS.ARGS())
        .def("setIsAdjustedForBackground", &PyDbUnderlayReference::setIsAdjustedForBackground, DS.ARGS({ "val : bool" }))
        .def("isFrameVisible", &PyDbUnderlayReference::isFrameVisible, DS.ARGS())
        .def("isFramePlottable", &PyDbUnderlayReference::isFramePlottable, DS.ARGS())
        .def("underlayLayerCount", &PyDbUnderlayReference::underlayLayerCount, DS.ARGS())
        .def("getUnderlayLayer", &PyDbUnderlayReference::getUnderlayLayer, DS.ARGS({ "val : int" }))
        .def("setUnderlayLayer", &PyDbUnderlayReference::setUnderlayLayer, DS.ARGS({ "val : int","layer : PyDb.UnderlayLayer" }))
        .def("isClipInverted", &PyDbUnderlayReference::isClipInverted, DS.ARGS())
        .def("setClipInverted", &PyDbUnderlayReference::setClipInverted, DS.ARGS({ "val : bool" }))
        .def("generateClipBoundaryFromPline", &PyDbUnderlayReference::generateClipBoundaryFromPline, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("contrastLowerLimit", &PyDbUnderlayReference::contrastLowerLimit, DS.SARGS()).staticmethod("contrastLowerLimit")
        .def("contrastDefault", &PyDbUnderlayReference::contrastDefault, DS.SARGS()).staticmethod("contrastDefault")
        .def("fadeLowerLimit", &PyDbUnderlayReference::fadeLowerLimit, DS.SARGS()).staticmethod("fadeLowerLimit")
        .def("fadeUpperLimit", &PyDbUnderlayReference::fadeUpperLimit, DS.SARGS()).staticmethod("fadeUpperLimit")
        .def("fadeDefault", &PyDbUnderlayReference::fadeDefault, DS.SARGS()).staticmethod("fadeDefault")
        .def("className", &PyDbUnderlayReference::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbUnderlayReference::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbUnderlayReference::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbUnderlayReference::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbUnderlayReference::PyDbUnderlayReference(AcDbUnderlayReference* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbUnderlayReference::PyDbUnderlayReference(const PyDbObjectId& id)
    : PyDbUnderlayReference(id, AcDb::OpenMode::kForRead)
{
}

PyDbUnderlayReference::PyDbUnderlayReference(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbUnderlayReference>(id, mode), false)
{
}

PyDbUnderlayReference::PyDbUnderlayReference(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbUnderlayReference>(id, mode, erased), false)
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setWidth(width));
#endif
}

double PyDbUnderlayReference::width() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    double val = 0;
    PyThrowBadEs(impObj()->width(val));
    return val;
#endif
}

void PyDbUnderlayReference::setHeight(double width)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setHeight(width));
#endif
}

double PyDbUnderlayReference::height() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    double val = 0;
    PyThrowBadEs(impObj()->height(val));
    return val;
#endif
}

boost::python::list PyDbUnderlayReference::clipBoundary() const
{
    return Point2dArrayToPyList(impObj()->clipBoundary());
}

void PyDbUnderlayReference::setClipBoundary(const boost::python::list& clip)
{
    return PyThrowBadEs(impObj()->setClipBoundary(PyListToPoint2dArray(clip)));
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
    return impObj()->underlayLayerCount();
}

PyUnderlayLayer PyDbUnderlayReference::getUnderlayLayer(int index) const
{
    AcUnderlayLayer val;
    PyThrowBadEs(impObj()->getUnderlayLayer(index, val));
    return PyUnderlayLayer(val);
}

void PyDbUnderlayReference::setUnderlayLayer(int index, const PyUnderlayLayer& layer)
{
    return PyThrowBadEs(impObj()->setUnderlayLayer(index, layer.imp));
}

bool PyDbUnderlayReference::isClipInverted() const
{
    return impObj()->isClipInverted();
}

void PyDbUnderlayReference::setClipInverted(bool value)
{
    return PyThrowBadEs(impObj()->setClipInverted(value));
}

void PyDbUnderlayReference::generateClipBoundaryFromPline(PyDbObjectId& polyId)
{
    return PyThrowBadEs(impObj()->generateClipBoundaryFromPline(polyId.m_id));
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
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

static AcDbPdfDefinition* openAcDbPdfDefinition(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    AcDbPdfDefinition* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPdfDefinition>(pobj, id.m_id, mode); es != eOk) [[unlikely]]
        throw PyAcadErrorStatus(es);
        return pobj;
}

PyDbPdfDefinition::PyDbPdfDefinition()
    : PyDbUnderlayDefinition(new AcDbPdfDefinition(), true)
{
}

PyDbPdfDefinition::PyDbPdfDefinition(AcDbPdfDefinition* ptr, bool autoDelete)
    : PyDbUnderlayDefinition(ptr, autoDelete)
{
}

PyDbPdfDefinition::PyDbPdfDefinition(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbUnderlayDefinition(openAcDbObject<AcDbPdfDefinition>(id, mode), false)
{
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
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
    : PyDbUnderlayReference(openAcDbObject<AcDbPdfReference>(id, mode), false)
{
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPdfReference*>(m_pyImp.get());
}
