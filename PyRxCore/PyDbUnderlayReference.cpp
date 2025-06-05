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
        .def(init<>(DS.ARGS(16373)))
        .def("name", &PyUnderlayLayer::name, DS.ARGS(16376))
        .def("state", &PyUnderlayLayer::state, DS.ARGS(16379))
        .def("setName", &PyUnderlayLayer::setName, DS.ARGS({ "name : str" }, 16377))
        .def("setState", &PyUnderlayLayer::setState, DS.ARGS({ "state : bool" }, 16378))
        ;
}

PyUnderlayLayer::PyUnderlayLayer()
{
}

PyUnderlayLayer::PyUnderlayLayer(const AcUnderlayLayer& layer)
    : imp(layer)
{
}

std::string PyUnderlayLayer::name() const
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead" }, 9833)))
        .def("setSourceFileName", &PyDbUnderlayDefinition::setSourceFileName, DS.ARGS({ "file : str" }, 9844))
        .def("getSourceFileName", &PyDbUnderlayDefinition::getSourceFileName, DS.ARGS(9839))
        .def("getActiveFileName", &PyDbUnderlayDefinition::getActiveFileName, DS.ARGS(9836))
        .def("setItemName", &PyDbUnderlayDefinition::setItemName, DS.ARGS({ "item : str" }, 9843))
        .def("getItemName", &PyDbUnderlayDefinition::getItemName, DS.ARGS(9837))
        .def("load", &PyDbUnderlayDefinition::load1)
        .def("load", &PyDbUnderlayDefinition::load2, DS.ARGS({ "passwd : str = ..." }, 9842))
        .def("unload", &PyDbUnderlayDefinition::unload, DS.ARGS(9846))
        .def("isLoaded", &PyDbUnderlayDefinition::isLoaded, DS.ARGS(9841))
        .def("dictionaryKey", &PyDbUnderlayDefinition::dictionaryKey, DS.SARGS({ "underlayDefinitionType: PyRx.RxClass" }, 9835)).staticmethod("dictionaryKey")
        .def("className", &PyDbUnderlayDefinition::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbUnderlayDefinition::desc, DS.SARGS(15560)).staticmethod("desc")
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

void PyDbUnderlayDefinition::setSourceFileName(const std::string& file) const
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

void PyDbUnderlayDefinition::setItemName(const std::string& item) const
{
    return PyThrowBadEs(impObj()->setItemName(utf8_to_wstr(item).c_str()));
}

std::string PyDbUnderlayDefinition::getItemName() const
{
    return wstr_to_utf8(impObj()->getItemName());
}

void PyDbUnderlayDefinition::load1() const
{
    return PyThrowBadEs(impObj()->load(nullptr));
}

void PyDbUnderlayDefinition::load2(const std::string& password) const
{
    return PyThrowBadEs(impObj()->load(utf8_to_wstr(password).c_str()));
}

void PyDbUnderlayDefinition::unload() const
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
    return PyDbObjectCloneFrom<PyDbUnderlayDefinition, AcDbUnderlayDefinition>(src);
}

PyDbUnderlayDefinition PyDbUnderlayDefinition::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbUnderlayDefinition>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("UnderlayReference");
    class_<PyDbUnderlayReference, bases<PyDbEntity>>("UnderlayReference", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 9869)))
        .def("position", &PyDbUnderlayReference::position, DS.ARGS(9891))
        .def("setPosition", &PyDbUnderlayReference::setPosition, DS.ARGS({ "val : PyGe.Point3d" }, 9905))
        .def("scaleFactors", &PyDbUnderlayReference::scaleFactors, DS.ARGS(9893))
        .def("setScaleFactors", &PyDbUnderlayReference::setScaleFactors, DS.ARGS({ "val : PyGe.Scale3d" }, 9907))
        .def("rotation", &PyDbUnderlayReference::rotation, DS.ARGS(9892))
        .def("setRotation", &PyDbUnderlayReference::setRotation, DS.ARGS({ "val : float" }, 9906))
        .def("normal", &PyDbUnderlayReference::normal, DS.ARGS(9890))
        .def("setNormal", &PyDbUnderlayReference::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }, 9904))
        .def("transform", &PyDbUnderlayReference::transform, DS.ARGS(9911))
        .def("setTransform", &PyDbUnderlayReference::setTransform, DS.ARGS({ "val : PyGe.Matrix3d" }, 9908))
        .def("definitionId", &PyDbUnderlayReference::definitionId, DS.ARGS(9875))
        .def("setDefinitionId", &PyDbUnderlayReference::setDefinitionId, DS.ARGS({ "val : PyDb.ObjectId" }, 9897))
        .def("setWidth", &PyDbUnderlayReference::setWidth, DS.ARGS({ "val : float" }, 9910))
        .def("width", &PyDbUnderlayReference::width, DS.ARGS(9913))
        .def("setHeight", &PyDbUnderlayReference::setHeight, DS.ARGS({ "val : float" }, 9899))
        .def("height", &PyDbUnderlayReference::height, DS.ARGS(9882))
        .def("clipBoundary", &PyDbUnderlayReference::clipBoundary, DS.ARGS(9870))
        .def("setClipBoundary", &PyDbUnderlayReference::setClipBoundary, DS.ARGS({ "pnts : list[PyGe.Point2d]" }, 9894))
        .def("isClipped", &PyDbUnderlayReference::isClipped, DS.ARGS(9885))
        .def("setIsClipped", &PyDbUnderlayReference::setIsClipped, DS.ARGS({ "val : bool" }, 9901))
        .def("contrast", &PyDbUnderlayReference::contrast, DS.ARGS(9871))
        .def("setContrast", &PyDbUnderlayReference::setContrast, DS.ARGS({ "val : int" }, 9896))
        .def("fade", &PyDbUnderlayReference::fade, DS.ARGS(9876))
        .def("setFade", &PyDbUnderlayReference::setFade, DS.ARGS({ "val : int" }, 9898))
        .def("isOn", &PyDbUnderlayReference::isOn, DS.ARGS(9889))
        .def("setIsOn", &PyDbUnderlayReference::setIsOn, DS.ARGS({ "val : bool" }, 9903))
        .def("isMonochrome", &PyDbUnderlayReference::isMonochrome, DS.ARGS(9888))
        .def("setIsMonochrome", &PyDbUnderlayReference::setIsMonochrome, DS.ARGS({ "val : bool" }, 9902))
        .def("isAdjustedForBackground", &PyDbUnderlayReference::isAdjustedForBackground, DS.ARGS(9883))
        .def("setIsAdjustedForBackground", &PyDbUnderlayReference::setIsAdjustedForBackground, DS.ARGS({ "val : bool" }, 9900))
        .def("isFrameVisible", &PyDbUnderlayReference::isFrameVisible, DS.ARGS(9887))
        .def("isFramePlottable", &PyDbUnderlayReference::isFramePlottable, DS.ARGS(9886))
        .def("underlayLayerCount", &PyDbUnderlayReference::underlayLayerCount, DS.ARGS(9912))
        .def("getUnderlayLayer", &PyDbUnderlayReference::getUnderlayLayer, DS.ARGS({ "val : int" }, 9881))
        .def("setUnderlayLayer", &PyDbUnderlayReference::setUnderlayLayer, DS.ARGS({ "val : int","layer : PyDb.UnderlayLayer" }, 9909))
        .def("isClipInverted", &PyDbUnderlayReference::isClipInverted, DS.ARGS(9884))
        .def("setClipInverted", &PyDbUnderlayReference::setClipInverted, DS.ARGS({ "val : bool" }, 9895))
        .def("generateClipBoundaryFromPline", &PyDbUnderlayReference::generateClipBoundaryFromPline, DS.ARGS({ "val : PyDb.ObjectId" }, 9880))
        .def("contrastLowerLimit", &PyDbUnderlayReference::contrastLowerLimit, DS.SARGS(9873)).staticmethod("contrastLowerLimit")
        .def("contrastDefault", &PyDbUnderlayReference::contrastDefault, DS.SARGS(9872)).staticmethod("contrastDefault")
        .def("fadeLowerLimit", &PyDbUnderlayReference::fadeLowerLimit, DS.SARGS(9878)).staticmethod("fadeLowerLimit")
        .def("fadeUpperLimit", &PyDbUnderlayReference::fadeUpperLimit, DS.SARGS(9879)).staticmethod("fadeUpperLimit")
        .def("fadeDefault", &PyDbUnderlayReference::fadeDefault, DS.SARGS(9877)).staticmethod("fadeDefault")
        .def("className", &PyDbUnderlayReference::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbUnderlayReference::desc, DS.SARGS(15560)).staticmethod("desc")
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

void PyDbUnderlayReference::setPosition(const AcGePoint3d& position) const
{
    return PyThrowBadEs(impObj()->setPosition(position));
}

AcGeScale3d PyDbUnderlayReference::scaleFactors() const
{
    return impObj()->scaleFactors();
}

void PyDbUnderlayReference::setScaleFactors(const AcGeScale3d& scale) const
{
    return PyThrowBadEs(impObj()->setScaleFactors(scale));
}

double PyDbUnderlayReference::rotation() const
{
    return impObj()->rotation();
}

void PyDbUnderlayReference::setRotation(double rotation) const
{
    return PyThrowBadEs(impObj()->setRotation(rotation));
}

AcGeVector3d PyDbUnderlayReference::normal() const
{
    return impObj()->normal();
}

void PyDbUnderlayReference::setNormal(const AcGeVector3d& normal) const
{
    return PyThrowBadEs(impObj()->setNormal(normal));
}

AcGeMatrix3d PyDbUnderlayReference::transform() const
{
    return impObj()->transform();
}

void PyDbUnderlayReference::setTransform(const AcGeMatrix3d& transform) const
{
    return PyThrowBadEs(impObj()->setTransform(transform));
}

PyDbObjectId PyDbUnderlayReference::definitionId() const
{
    return PyDbObjectId(impObj()->definitionId());
}

void PyDbUnderlayReference::setDefinitionId(const PyDbObjectId& id) const
{
    return PyThrowBadEs(impObj()->setDefinitionId(id.m_id));
}

void PyDbUnderlayReference::setWidth(double width) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setWidth(width));
#endif
}

double PyDbUnderlayReference::width() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    double val = 0;
    PyThrowBadEs(impObj()->width(val));
    return val;
#endif
}

void PyDbUnderlayReference::setHeight(double width) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setHeight(width));
#endif
}

double PyDbUnderlayReference::height() const
{
#if defined(_BRXTARGET250)
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

void PyDbUnderlayReference::setClipBoundary(const boost::python::list& clip) const
{
    return PyThrowBadEs(impObj()->setClipBoundary(PyListToPoint2dArray(clip)));
}

bool PyDbUnderlayReference::isClipped() const
{
    return impObj()->isClipped();
}

void PyDbUnderlayReference::setIsClipped(bool value) const
{
    return PyThrowBadEs(impObj()->setIsClipped(value));
}

Adesk::UInt8 PyDbUnderlayReference::contrast() const
{
    return impObj()->contrast();
}

void PyDbUnderlayReference::setContrast(Adesk::UInt8 value) const
{
    return PyThrowBadEs(impObj()->setContrast(value));
}

Adesk::UInt8 PyDbUnderlayReference::fade() const
{
    return impObj()->fade();
}

void PyDbUnderlayReference::setFade(Adesk::UInt8 value) const
{
    return PyThrowBadEs(impObj()->setFade(value));
}

bool PyDbUnderlayReference::isOn() const
{
    return impObj()->isOn();
}

void PyDbUnderlayReference::setIsOn(bool value) const
{
    return PyThrowBadEs(impObj()->setIsOn(value));
}

bool PyDbUnderlayReference::isMonochrome() const
{
    return impObj()->isMonochrome();
}

void PyDbUnderlayReference::setIsMonochrome(bool value) const
{
    return PyThrowBadEs(impObj()->setIsMonochrome(value));
}

bool PyDbUnderlayReference::isAdjustedForBackground() const
{
    return impObj()->isAdjustedForBackground();
}

void PyDbUnderlayReference::setIsAdjustedForBackground(bool value) const
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

void PyDbUnderlayReference::setUnderlayLayer(int index, const PyUnderlayLayer& layer) const
{
    return PyThrowBadEs(impObj()->setUnderlayLayer(index, layer.imp));
}

bool PyDbUnderlayReference::isClipInverted() const
{
    return impObj()->isClipInverted();
}

void PyDbUnderlayReference::setClipInverted(bool value) const
{
    return PyThrowBadEs(impObj()->setClipInverted(value));
}

void PyDbUnderlayReference::generateClipBoundaryFromPline(PyDbObjectId& polyId) const
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
    return PyDbObjectCloneFrom<PyDbUnderlayReference, AcDbUnderlayReference>(src);
}

PyDbUnderlayReference PyDbUnderlayReference::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbUnderlayReference>(src);
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
    PyDocString DS("PdfDefinition");
    class_<PyDbPdfDefinition, bases<PyDbUnderlayDefinition>>("PdfDefinition")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead" }, 7392)))
        .def("className", &PyDbPdfDefinition::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPdfDefinition::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPdfDefinition::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPdfDefinition::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

static AcDbPdfDefinition* openAcDbPdfDefinition(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    AcDbPdfDefinition* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPdfDefinition>(pobj, id.m_id, mode); es != eOk) [[unlikely]] {
        throw PyErrorStatusException(es);
    }
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
    return PyDbObjectCloneFrom<PyDbPdfDefinition, AcDbPdfDefinition>(src);
}

PyDbPdfDefinition PyDbPdfDefinition::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPdfDefinition>(src);
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
    PyDocString DS("PdfReference");
    class_<PyDbPdfReference, bases<PyDbUnderlayReference>>("PdfReference")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead" }, 7395)))
        .def("className", &PyDbPdfReference::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPdfReference::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPdfReference::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPdfReference::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    return PyDbObjectCloneFrom<PyDbPdfReference, AcDbPdfReference>(src);
}

PyDbPdfReference PyDbPdfReference::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPdfReference>(src);
}

AcDbPdfReference* PyDbPdfReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPdfReference*>(m_pyImp.get());
}
