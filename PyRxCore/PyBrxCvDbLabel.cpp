#include "stdafx.h"


#ifdef BRXAPP
#if !defined(_BRXTARGET240)

#include "PyBrxCvDbLabel.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyBrxCvDbStylePartDisplaySettings
void makePyBrxCvDbStylePartDisplaySettingsWrapper()
{
    PyDocString DS("CvDbStylePartDisplaySettings");
    class_<PyBrxCvDbStylePartDisplaySettings, bases<PyBrxCvDbSubObject>>("CvDbStylePartDisplaySettings", boost::python::no_init)
        .def("displaySetting", &PyBrxCvDbStylePartDisplaySettings::isVisible, DS.ARGS())
        .def("setVisible", &PyBrxCvDbStylePartDisplaySettings::setVisible, DS.ARGS({ "val: bool" }))
        .def("color", &PyBrxCvDbStylePartDisplaySettings::color, DS.ARGS())
        .def("setColor", &PyBrxCvDbStylePartDisplaySettings::setColor, DS.ARGS({ "clr: PyDb.Color" }))
        .def("layer", &PyBrxCvDbStylePartDisplaySettings::layer, DS.ARGS())
        .def("setLayer", &PyBrxCvDbStylePartDisplaySettings::setLayer, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("lineType", &PyBrxCvDbStylePartDisplaySettings::lineType, DS.ARGS())
        .def("setLineType", &PyBrxCvDbStylePartDisplaySettings::setLineType, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("lineTypeScale", &PyBrxCvDbStylePartDisplaySettings::lineTypeScale, DS.ARGS())
        .def("setLineTypeScale", &PyBrxCvDbStylePartDisplaySettings::setLineTypeScale, DS.ARGS({ "val: float" }))
        .def("lineWeight", &PyBrxCvDbStylePartDisplaySettings::lineWeight, DS.ARGS())
        .def("setLineWeight", &PyBrxCvDbStylePartDisplaySettings::setLineWeight, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("plotStyleNameType", &PyBrxCvDbStylePartDisplaySettings::plotStyleNameType, DS.ARGS())
        .def("setPlotStyleNameType", &PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameType, DS.ARGS({ "val: PyDb.PlotStyleNameType" }))
        .def("plotStyleNameId", &PyBrxCvDbStylePartDisplaySettings::plotStyleNameId, DS.ARGS())
        .def("setPlotStyleNameId", &PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameId, DS.ARGS({ "id: PyDb.ObjectId" }))
        ;
}

PyBrxCvDbStylePartDisplaySettings::PyBrxCvDbStylePartDisplaySettings(BrxCvDbStylePartDisplaySettings* ptr, bool autoDelete)
    : PyBrxCvDbSubObject(ptr, autoDelete)
{
}

bool PyBrxCvDbStylePartDisplaySettings::isVisible() const
{
    return impObj()->isVisible();
}

void PyBrxCvDbStylePartDisplaySettings::setVisible(bool value) const
{
    PyThrowBadEs(impObj()->setVisible(value));
}

AcCmColor PyBrxCvDbStylePartDisplaySettings::color() const
{
    return impObj()->color();
}

void PyBrxCvDbStylePartDisplaySettings::setColor(const AcCmColor& value) const
{
    PyThrowBadEs(impObj()->setColor(value));
}

PyDbObjectId PyBrxCvDbStylePartDisplaySettings::layer() const
{
    return PyDbObjectId{ impObj()->layer() };
}

void PyBrxCvDbStylePartDisplaySettings::setLayer(const PyDbObjectId& value) const
{
    PyThrowBadEs(impObj()->setLayer(value.m_id));
}

PyDbObjectId PyBrxCvDbStylePartDisplaySettings::lineType() const
{
    return PyDbObjectId{ impObj()->lineType() };
}

void PyBrxCvDbStylePartDisplaySettings::setLineType(const PyDbObjectId& value) const
{
    PyThrowBadEs(impObj()->setLineType(value.m_id));
}

double PyBrxCvDbStylePartDisplaySettings::lineTypeScale() const
{
    return impObj()->lineTypeScale();
}

void PyBrxCvDbStylePartDisplaySettings::setLineTypeScale(double value) const
{
    PyThrowBadEs(impObj()->setLineTypeScale(value));
}

AcDb::LineWeight PyBrxCvDbStylePartDisplaySettings::lineWeight() const
{
    return impObj()->lineWeight();
}

void PyBrxCvDbStylePartDisplaySettings::setLineWeight(AcDb::LineWeight value) const
{
    PyThrowBadEs(impObj()->setLineWeight(value));
}

AcDb::PlotStyleNameType PyBrxCvDbStylePartDisplaySettings::plotStyleNameType() const
{
    return impObj()->plotStyleNameType();
}

void PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameType(AcDb::PlotStyleNameType value) const
{
    PyThrowBadEs(impObj()->setPlotStyleNameType(value));
}

PyDbObjectId PyBrxCvDbStylePartDisplaySettings::plotStyleNameId() const
{
    return PyDbObjectId{ impObj()->plotStyleNameId() };
}

void PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameId(const PyDbObjectId& value) const
{
    PyThrowBadEs(impObj()->setPlotStyleNameId(value.m_id));
}

BrxCvDbStylePartDisplaySettings* PyBrxCvDbStylePartDisplaySettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbStylePartDisplaySettings*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbStyle
void makePyBrxCvDbStyleWrapper()
{
    PyDocString DS("CvDbStyle");
    class_<PyBrxCvDbStyle, bases<PyBrxCvDbObject>>("CvDbStyle", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("displaySetting", &PyBrxCvDbStyle::displaySetting, DS.ARGS({ "orientation: PyBrxCv.DisplayOrientation", "partName: str" }))
        .def("displaySettings", &PyBrxCvDbStyle::displaySettings, DS.ARGS({ "orientation: PyBrxCv.DisplayOrientation" }))
        .def("createdDate", &PyBrxCvDbStyle::createdDate, DS.ARGS())
        .def("createdBy", &PyBrxCvDbStyle::createdBy, DS.ARGS())
        .def("lastEditedDate", &PyBrxCvDbStyle::lastEditedDate, DS.ARGS())
        .def("lastEditedBy", &PyBrxCvDbStyle::lastEditedBy, DS.ARGS())
        .def("setCreatedBy", &PyBrxCvDbStyle::setCreatedBy, DS.ARGS({ "filter : str" }))
        .def("className", &PyBrxCvDbStyle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbStyle::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbStyle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id, mode), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id, mode, erased), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(BrxCvDbStyle* ptr, bool autoDelete)
    : PyBrxCvDbObject(ptr, autoDelete)
{
}

PyBrxCvDbStylePartDisplaySettings PyBrxCvDbStyle::displaySetting(DisplayOrientation orientation, const std::string& partName) const
{
    auto ptr = impObj()->displaySetting(orientation, utf8_to_wstr(partName).c_str());
    if (ptr.refCount() == 1)
        return PyBrxCvDbStylePartDisplaySettings(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

boost::python::list PyBrxCvDbStyle::displaySettings(BrxCvDbLabelStyle::DisplayOrientation orientation) const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto item : impObj()->displaySettings(orientation))
    {
        if (item.refCount() == 1)
            _pylist.append(PyBrxCvDbStylePartDisplaySettings(item.detach(), true));
        else
            throw PyErrorStatusException(Acad::eInvalidOpenState);
    }
    return _pylist;
}

PyDbDate PyBrxCvDbStyle::createdDate() const
{
    return PyDbDate(impObj()->createdDate());
}

const std::string PyBrxCvDbStyle::createdBy() const
{
    return wstr_to_utf8(impObj()->createdBy());
}

PyDbDate PyBrxCvDbStyle::lastEditedDate() const
{
    return PyDbDate();
}

const std::string PyBrxCvDbStyle::lastEditedBy() const
{
    return wstr_to_utf8(impObj()->lastEditedBy());
}

void PyBrxCvDbStyle::setCreatedBy(const std::string& value) const
{
    PyThrowBadEs(impObj()->setCreatedBy(utf8_to_wstr(value).c_str()));
}

std::string PyBrxCvDbStyle::className()
{
    return std::string{ "BrxCvDbStyle" };
}

PyRxClass PyBrxCvDbStyle::desc()
{
    return PyRxClass{ BrxCvDbStyle::desc(),false };
}

PyBrxCvDbStyle PyBrxCvDbStyle::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbStyle>(src);
}

BrxCvDbStyle* PyBrxCvDbStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbStyle*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleComponentWrapper
void makeBrxCvDbLabelStyleComponentWrapper()
{
    PyDocString DS("CvDbLabelStyleComponent");
    class_<PyBrxCvDbLabelStyleComponent, bases<PyBrxCvDbSubObject>>("CvDbLabelStyleComponent", boost::python::no_init)
        .def("displaySetting", &PyBrxCvDbLabelStyleComponent::isVisible, DS.ARGS())
        .def("setVisible", &PyBrxCvDbLabelStyleComponent::setVisible, DS.ARGS({ "val: bool" }))
        .def("color", &PyBrxCvDbLabelStyleComponent::color, DS.ARGS())
        .def("setColor", &PyBrxCvDbLabelStyleComponent::setColor, DS.ARGS({ "clr: PyDb.Color" }))
        .def("anchorIndex", &PyBrxCvDbLabelStyleComponent::anchorIndex, DS.ARGS())
        .def("setAnchorIndex", &PyBrxCvDbLabelStyleComponent::setAnchorIndex, DS.ARGS({ "val : int" }))
        .def("anchorPoint", &PyBrxCvDbLabelStyleComponent::anchorPoint, DS.ARGS())
        .def("setAnchorPoint", &PyBrxCvDbLabelStyleComponent::setAnchorPoint, DS.ARGS({ "val : PyBrxCv.LabelAnchor" }))
        ;
}

PyBrxCvDbLabelStyleComponent::PyBrxCvDbLabelStyleComponent(BrxCvDbLabelStyleComponent* ptr, bool autoDelete)
    : PyBrxCvDbSubObject(ptr, autoDelete)
{
}

bool PyBrxCvDbLabelStyleComponent::isVisible() const
{
    return impObj()->isVisible();
}

void PyBrxCvDbLabelStyleComponent::setVisible(bool isVisible) const
{
    PyThrowBadEs(impObj()->setVisible(isVisible));
}

AcCmColor PyBrxCvDbLabelStyleComponent::color() const
{
    return impObj()->color();
}

void PyBrxCvDbLabelStyleComponent::setColor(const AcCmColor& value) const
{
    PyThrowBadEs(impObj()->setColor(value));
}

Adesk::UInt32 PyBrxCvDbLabelStyleComponent::anchorIndex() const
{
    return impObj()->anchorIndex();
}

void PyBrxCvDbLabelStyleComponent::setAnchorIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setAnchorIndex(index));
}

BrxCvDbLabelStyleComponent::LabelAnchor PyBrxCvDbLabelStyleComponent::anchorPoint() const
{
    return impObj()->anchorPoint();
}

void PyBrxCvDbLabelStyleComponent::setAnchorPoint(LabelAnchor anchor) const
{
    PyThrowBadEs(impObj()->setAnchorPoint(anchor));
}

BrxCvDbLabelStyleComponent* PyBrxCvDbLabelStyleComponent::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbLabelStyleComponent*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//makeBrxCvDbSymbolStyleWrapper
void makeBrxCvDbSymbolStyleWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- metric: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("CvDbSymbolStyle");
    class_<PyBrxCvDbSymbolStyle, bases<PyBrxCvDbStyle>>("CvDbSymbolStyle")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<bool>(DS.CTOR(ctords)))
        .def("symbolType", &PyBrxCvDbSymbolStyle::symbolType, DS.ARGS())
        .def("setSymbolType", &PyBrxCvDbSymbolStyle::setSymbolType, DS.ARGS({ "val: PyBrxCv.SymbolType" }))
        .def("customSymbol", &PyBrxCvDbSymbolStyle::customSymbol, DS.ARGS())
        .def("setCustomSymbol", &PyBrxCvDbSymbolStyle::setCustomSymbol, DS.ARGS({ "val: PyBrxCv.CustomSymbol" }))
        .def("squareFrame", &PyBrxCvDbSymbolStyle::squareFrame, DS.ARGS())
        .def("setSquareFrame", &PyBrxCvDbSymbolStyle::setSquareFrame, DS.ARGS({ "val: bool" }))
        .def("circleFrame", &PyBrxCvDbSymbolStyle::circleFrame, DS.ARGS())
        .def("setCircleFrame", &PyBrxCvDbSymbolStyle::setCircleFrame, DS.ARGS({ "val: bool" }))
        .def("symbolBlockId", &PyBrxCvDbSymbolStyle::symbolBlockId, DS.ARGS())
        .def("setSymbolBlockId", &PyBrxCvDbSymbolStyle::setSymbolBlockId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("size", &PyBrxCvDbSymbolStyle::size, DS.ARGS())
        .def("setSize", &PyBrxCvDbSymbolStyle::setSize, DS.ARGS({ "val: float" }))
        .def("rotationAngle", &PyBrxCvDbSymbolStyle::rotationAngle, DS.ARGS())
        .def("setRotationAngle", &PyBrxCvDbSymbolStyle::setRotationAngle, DS.ARGS({ "val: float" }))
        .def("scalingType", &PyBrxCvDbSymbolStyle::scalingType, DS.ARGS())
        .def("setScalingType", &PyBrxCvDbSymbolStyle::setScalingType, DS.ARGS({ "val: PyBrxCv.ScalingType" }))
        .def("fixedScale", &PyBrxCvDbSymbolStyle::fixedScale, DS.ARGS())
        .def("setFixedScale", &PyBrxCvDbSymbolStyle::setFixedScale, DS.ARGS({ "scale: PyGe.Scale3d" }))
        .def("orientationReference", &PyBrxCvDbSymbolStyle::orientationReference, DS.ARGS())
        .def("setOrientationReference", &PyBrxCvDbSymbolStyle::setOrientationReference, DS.ARGS({ "val: PyBrxCv.OrientationRef" }))
        .def("maximumSize", &PyBrxCvDbSymbolStyle::maximumSize, DS.ARGS())
        .def("setMaximumSize", &PyBrxCvDbSymbolStyle::setMaximumSize, DS.ARGS({ "val: float" }))
        .def("asPDMODE", &PyBrxCvDbSymbolStyle::asPDMODE, DS.ARGS())
        .def("setPDMODE", &PyBrxCvDbSymbolStyle::setPDMODE, DS.ARGS({ "val: int" }))
        .def("className", &PyBrxCvDbSymbolStyle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbSymbolStyle::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbSymbolStyle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbSymbolStyle::PyBrxCvDbSymbolStyle()
    : PyBrxCvDbSymbolStyle(new BrxCvDbSymbolStyle(), false)
{
}

PyBrxCvDbSymbolStyle::PyBrxCvDbSymbolStyle(bool metric)
    : PyBrxCvDbSymbolStyle(new BrxCvDbSymbolStyle(metric), false)
{
}

PyBrxCvDbSymbolStyle::PyBrxCvDbSymbolStyle(const PyDbObjectId& id)
    : PyBrxCvDbSymbolStyle(openAcDbObject<BrxCvDbSymbolStyle>(id), false)
{
}

PyBrxCvDbSymbolStyle::PyBrxCvDbSymbolStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbSymbolStyle(openAcDbObject<BrxCvDbSymbolStyle>(id, mode), false)
{
}

PyBrxCvDbSymbolStyle::PyBrxCvDbSymbolStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbSymbolStyle(openAcDbObject<BrxCvDbSymbolStyle>(id, mode, erased), false)
{
}

PyBrxCvDbSymbolStyle::PyBrxCvDbSymbolStyle(BrxCvDbSymbolStyle* ptr, bool autoDelete)
    : PyBrxCvDbStyle(ptr, autoDelete)
{
}

PyBrxCvDbSymbolStyle::SymbolType PyBrxCvDbSymbolStyle::symbolType() const
{
    return impObj()->symbolType();
}

void PyBrxCvDbSymbolStyle::setSymbolType(SymbolType type) const
{
    PyThrowBadEs(impObj()->setSymbolType(type));
}

PyBrxCvDbSymbolStyle::CustomSymbol PyBrxCvDbSymbolStyle::customSymbol() const
{
    return impObj()->customSymbol();
}

void PyBrxCvDbSymbolStyle::setCustomSymbol(CustomSymbol symbol) const
{
    PyThrowBadEs(impObj()->setCustomSymbol(symbol));
}

bool PyBrxCvDbSymbolStyle::squareFrame() const
{
    return impObj()->squareFrame();
}

void PyBrxCvDbSymbolStyle::setSquareFrame(bool useSquareFrame) const
{
    PyThrowBadEs(impObj()->setSquareFrame(useSquareFrame));
}

bool PyBrxCvDbSymbolStyle::circleFrame() const
{
    return impObj()->circleFrame();
}

void PyBrxCvDbSymbolStyle::setCircleFrame(bool useCircleFrame) const
{
    PyThrowBadEs(impObj()->setCircleFrame(useCircleFrame));
}

PyDbObjectId PyBrxCvDbSymbolStyle::symbolBlockId() const
{
    return PyDbObjectId{ impObj()->symbolBlockId() };
}

void PyBrxCvDbSymbolStyle::setSymbolBlockId(const PyDbObjectId& blockId) const
{
    PyThrowBadEs(impObj()->setSymbolBlockId(blockId.m_id));
}

double PyBrxCvDbSymbolStyle::size() const
{
    return impObj()->size();
}

void PyBrxCvDbSymbolStyle::setSize(double size) const
{
    PyThrowBadEs(impObj()->setSize(size));
}

double PyBrxCvDbSymbolStyle::rotationAngle() const
{
    return impObj()->rotationAngle();
}

void PyBrxCvDbSymbolStyle::setRotationAngle(double angle) const
{
    PyThrowBadEs(impObj()->setRotationAngle(angle));
}

PyBrxCvDbSymbolStyle::ScalingType PyBrxCvDbSymbolStyle::scalingType() const
{
    return impObj()->scalingType();
}

void PyBrxCvDbSymbolStyle::setScalingType(ScalingType type) const
{
    PyThrowBadEs(impObj()->setScalingType(type));
}

AcGeScale3d PyBrxCvDbSymbolStyle::fixedScale() const
{
    return impObj()->fixedScale();
}

void PyBrxCvDbSymbolStyle::setFixedScale(const AcGeScale3d& scale) const
{
    PyThrowBadEs(impObj()->setFixedScale(scale));
}

PyBrxCvDbSymbolStyle::OrientationRef PyBrxCvDbSymbolStyle::orientationReference() const
{
    return impObj()->orientationReference();
}

void PyBrxCvDbSymbolStyle::setOrientationReference(OrientationRef _ref) const
{
    PyThrowBadEs(impObj()->setOrientationReference(_ref));
}

double PyBrxCvDbSymbolStyle::maximumSize() const
{
    return impObj()->maximumSize();
}

void PyBrxCvDbSymbolStyle::setMaximumSize(double size) const
{
    PyThrowBadEs(impObj()->setMaximumSize(size));
}

Adesk::UInt32 PyBrxCvDbSymbolStyle::asPDMODE() const
{
    return impObj()->maximumSize();
}

void PyBrxCvDbSymbolStyle::setPDMODE(Adesk::UInt32 flags) const
{
    PyThrowBadEs(impObj()->setPDMODE(flags));
}

std::string PyBrxCvDbSymbolStyle::className()
{
    return std::string{ "BrxCvDbSymbolStyle" };
}

PyRxClass PyBrxCvDbSymbolStyle::desc()
{
    return PyRxClass{ BrxCvDbSymbolStyle::desc(),false };
}

PyBrxCvDbSymbolStyle PyBrxCvDbSymbolStyle::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbSymbolStyle>(src);
}

BrxCvDbSymbolStyle* PyBrxCvDbSymbolStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbSymbolStyle*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleWrapper
void makeBrxCvDbLabelStyleWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- metric: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("CvDbLabelStyle");
    class_<PyBrxCvDbLabelStyle, bases<PyBrxCvDbStyle>>("CvDbLabelStyle")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<bool>(DS.CTOR(ctords)))
        .def("components", &PyBrxCvDbLabelStyle::components, DS.ARGS())
        .def("componentAt", &PyBrxCvDbLabelStyle::componentAt, DS.ARGS({ "index: int" }))
        .def("componentCount", &PyBrxCvDbLabelStyle::componentCount, DS.ARGS())
        .def("addComponent", &PyBrxCvDbLabelStyle::addComponent, DS.ARGS({ "val: PyBrxCv.CvDbLabelStyleComponent" }))
        .def("removeComponent", &PyBrxCvDbLabelStyle::removeComponent_1)
        .def("removeComponent", &PyBrxCvDbLabelStyle::removeComponent_2, DS.ARGS({ "val: int|PyBrxCv.CvDbLabelStyleComponent" }))
        .def("moveComponent", &PyBrxCvDbLabelStyle::moveComponent, DS.ARGS({ "_from: int, _to:int" }))
        .def("textStyle", &PyBrxCvDbLabelStyle::textStyle, DS.ARGS())
        .def("setTextStyle", &PyBrxCvDbLabelStyle::setTextStyle, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("isVisible", &PyBrxCvDbLabelStyle::isVisible, DS.ARGS())
        .def("setVisibility", &PyBrxCvDbLabelStyle::setVisibility, DS.ARGS({ "val: bool" }))
        .def("layer", &PyBrxCvDbLabelStyle::layer, DS.ARGS())
        .def("setLayer", &PyBrxCvDbLabelStyle::setLayer, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("orientationReference", &PyBrxCvDbLabelStyle::orientationReference, DS.ARGS())
        .def("setOrientationReference", &PyBrxCvDbLabelStyle::setOrientationReference, DS.ARGS({ "val: PyBrxCv.OrientationRef" }))
        .def("forcedInsertion", &PyBrxCvDbLabelStyle::forcedInsertion, DS.ARGS())
        .def("setForcedInsertion", &PyBrxCvDbLabelStyle::setForcedInsertion, DS.ARGS({ "val: ForcedInsertion" }))
        .def("readabilityBias", &PyBrxCvDbLabelStyle::readabilityBias, DS.ARGS())
        .def("setReadabilityBias", &PyBrxCvDbLabelStyle::setReadabilityBias, DS.ARGS({ "radAngle: float" }))
        .def("planReadable", &PyBrxCvDbLabelStyle::planReadable, DS.ARGS())
        .def("setPlanReadable", &PyBrxCvDbLabelStyle::setPlanReadable, DS.ARGS({ "val: bool" }))
        .def("flipAnchorsWithText", &PyBrxCvDbLabelStyle::flipAnchorsWithText, DS.ARGS())
        .def("setFlipAnchorsWithText", &PyBrxCvDbLabelStyle::setFlipAnchorsWithText, DS.ARGS({ "val: bool" }))
        .def("forceInsideCurve", &PyBrxCvDbLabelStyle::forceInsideCurve, DS.ARGS())
        .def("setForceInsideCurve", &PyBrxCvDbLabelStyle::setForceInsideCurve, DS.ARGS({ "val: bool" }))
        .def("expressionCount", &PyBrxCvDbLabelStyle::expressionCount, DS.ARGS())
        .def("expressionAt", &PyBrxCvDbLabelStyle::expressionAt, DS.ARGS({ "index: int" }))
        .def("setExpressionAt", &PyBrxCvDbLabelStyle::setExpressionAt, DS.ARGS({ "index: int, name: str, expr:str, val: PyBrxCv.DataType" }))
        .def("draggedStateLeaderArrowHeadStyle", &PyBrxCvDbLabelStyle::draggedStateLeaderArrowHeadStyle, DS.ARGS())
        .def("setDraggedStateLeaderArrowHeadStyle", &PyBrxCvDbLabelStyle::setDraggedStateLeaderArrowHeadStyle, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("draggedStateLeaderArrowHeadSize", &PyBrxCvDbLabelStyle::draggedStateLeaderArrowHeadSize, DS.ARGS())
        .def("setDraggedStateLeaderArrowHeadSize", &PyBrxCvDbLabelStyle::setDraggedStateLeaderArrowHeadSize, DS.ARGS({ "val: float" }))
        .def("draggedStateLeaderArrowHeadSizeExprIndex", &PyBrxCvDbLabelStyle::draggedStateLeaderArrowHeadSizeExprIndex, DS.ARGS())
        .def("setDraggedStateLeaderArrowHeadSizeExprIndex", &PyBrxCvDbLabelStyle::setDraggedStateLeaderArrowHeadSizeExprIndex, DS.ARGS({ "val: int" }))
        .def("draggedStateLeaderIsVisible", &PyBrxCvDbLabelStyle::draggedStateLeaderIsVisible, DS.ARGS())
        .def("setDraggedStateLeaderVisibility", &PyBrxCvDbLabelStyle::setDraggedStateLeaderVisibility, DS.ARGS({ "val: bool" }))
        .def("draggedStateLeaderType", &PyBrxCvDbLabelStyle::draggedStateLeaderType, DS.ARGS())
        .def("setDraggedStateLeaderType", &PyBrxCvDbLabelStyle::setDraggedStateLeaderType, DS.ARGS({ "val: LeaderType" }))
        .def("draggedStateLeaderColor", &PyBrxCvDbLabelStyle::draggedStateLeaderColor, DS.ARGS())
        .def("setDraggedStateLeaderColor", &PyBrxCvDbLabelStyle::setDraggedStateLeaderColor, DS.ARGS({ "val: PyDb.Color" }))
        .def("draggedStateLeaderLinetype", &PyBrxCvDbLabelStyle::draggedStateLeaderLinetype, DS.ARGS())
        .def("setDraggedStateLeaderLinetype", &PyBrxCvDbLabelStyle::setDraggedStateLeaderLinetype, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("draggedStateLeaderLineweight", &PyBrxCvDbLabelStyle::draggedStateLeaderLineweight, DS.ARGS())
        .def("setDraggedStateLeaderLineweight", &PyBrxCvDbLabelStyle::setDraggedStateLeaderLineweight, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("draggedStateLeaderAttachment", &PyBrxCvDbLabelStyle::draggedStateLeaderAttachment, DS.ARGS())
        .def("setDraggedStateLeaderAttachment", &PyBrxCvDbLabelStyle::setDraggedStateLeaderAttachment, DS.ARGS({ "val: LeaderAttachment" }))
        .def("draggedStateLeaderJustification", &PyBrxCvDbLabelStyle::draggedStateLeaderJustification, DS.ARGS())
        .def("setDraggedStateLeaderJustification", &PyBrxCvDbLabelStyle::setDraggedStateLeaderJustification, DS.ARGS({ "val: bool" }))
        .def("draggedStateLeaderTail", &PyBrxCvDbLabelStyle::draggedStateLeaderTail, DS.ARGS())
        .def("setDraggedStateLeaderTail", &PyBrxCvDbLabelStyle::setDraggedStateLeaderTail, DS.ARGS({ "val: bool" }))
        .def("draggedStateDisplayMode", &PyBrxCvDbLabelStyle::draggedStateDisplayMode, DS.ARGS())
        .def("setDraggedStateDisplayMode", &PyBrxCvDbLabelStyle::setDraggedStateDisplayMode, DS.ARGS({ "val: DisplayMode" }))
        .def("draggedStateBorderIsVisible", &PyBrxCvDbLabelStyle::draggedStateBorderIsVisible, DS.ARGS())
        .def("setDraggedStateBorderVisibility", &PyBrxCvDbLabelStyle::setDraggedStateBorderVisibility, DS.ARGS({ "val: bool" }))
        .def("draggedStateBorderType", &PyBrxCvDbLabelStyle::draggedStateBorderType, DS.ARGS())
        .def("setDraggedStateBorderType", &PyBrxCvDbLabelStyle::setDraggedStateBorderType, DS.ARGS({ "val: BorderType" }))
        .def("draggedStateBackgroundMask", &PyBrxCvDbLabelStyle::draggedStateBackgroundMask, DS.ARGS())
        .def("setDraggedStateBackgroundMask", &PyBrxCvDbLabelStyle::setDraggedStateBackgroundMask, DS.ARGS({ "val: bool" }))
        .def("draggedStateBorderAndLeaderGap", &PyBrxCvDbLabelStyle::draggedStateBorderAndLeaderGap, DS.ARGS())
        .def("setDraggedStateBorderAndLeaderGap", &PyBrxCvDbLabelStyle::setDraggedStateBorderAndLeaderGap, DS.ARGS({ "val: float" }))
        .def("draggedStateBorderAndLeaderGapExprIndex", &PyBrxCvDbLabelStyle::draggedStateBorderAndLeaderGapExprIndex, DS.ARGS())
        .def("setDraggedStateBorderAndLeaderGapExprIndex", &PyBrxCvDbLabelStyle::setDraggedStateBorderAndLeaderGapExprIndex, DS.ARGS({ "val: int" }))
        .def("draggedStateTextHeight", &PyBrxCvDbLabelStyle::draggedStateTextHeight, DS.ARGS())
        .def("setDraggedStateTextHeight", &PyBrxCvDbLabelStyle::setDraggedStateTextHeight, DS.ARGS({ "val: float" }))
        .def("draggedStateTextHeightExprIndex", &PyBrxCvDbLabelStyle::draggedStateTextHeightExprIndex, DS.ARGS())
        .def("setDraggedStateTextHeightExprIndex", &PyBrxCvDbLabelStyle::setDraggedStateTextHeightExprIndex, DS.ARGS({ "val: int" }))
        .def("draggedStateTagDisplayMode", &PyBrxCvDbLabelStyle::draggedStateTagDisplayMode, DS.ARGS())
        .def("setDraggedStateTagDisplayMode", &PyBrxCvDbLabelStyle::setDraggedStateTagDisplayMode, DS.ARGS({ "val: bool" }))
        .def("draggedStateColor", &PyBrxCvDbLabelStyle::draggedStateColor, DS.ARGS())
        .def("setDraggedStateColor", &PyBrxCvDbLabelStyle::setDraggedStateColor, DS.ARGS({ "val: PyDb.Color" }))
        .def("draggedStateLinetype", &PyBrxCvDbLabelStyle::draggedStateLinetype, DS.ARGS())
        .def("setDraggedStateLinetype", &PyBrxCvDbLabelStyle::setDraggedStateLinetype, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("draggedStateLineweight", &PyBrxCvDbLabelStyle::draggedStateLineweight, DS.ARGS())
        .def("setDraggedStateLineweight", &PyBrxCvDbLabelStyle::setDraggedStateLineweight, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("draggedStateMaximumTextWidth", &PyBrxCvDbLabelStyle::draggedStateMaximumTextWidth, DS.ARGS())
        .def("setDraggedStateMaximumTextWidth", &PyBrxCvDbLabelStyle::setDraggedStateMaximumTextWidth, DS.ARGS({ "val: float" }))
        .def("draggedStateMaximumTextWidthExprIndex", &PyBrxCvDbLabelStyle::draggedStateMaximumTextWidthExprIndex, DS.ARGS())
        .def("setDraggedStateMaximumTextWidthExprIndex", &PyBrxCvDbLabelStyle::setDraggedStateMaximumTextWidthExprIndex, DS.ARGS({ "val: int" }))

        .def("className", &PyBrxCvDbLabelStyle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbLabelStyle::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbLabelStyle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbLabelStyle::PyBrxCvDbLabelStyle()
    : PyBrxCvDbLabelStyle(new BrxCvDbLabelStyle(), true)
{
}

PyBrxCvDbLabelStyle::PyBrxCvDbLabelStyle(bool metric)
    : PyBrxCvDbLabelStyle(new BrxCvDbLabelStyle(metric), true)
{
}

PyBrxCvDbLabelStyle::PyBrxCvDbLabelStyle(const PyDbObjectId& id)
    : PyBrxCvDbLabelStyle(openAcDbObject<BrxCvDbLabelStyle>(id), false)
{
}

PyBrxCvDbLabelStyle::PyBrxCvDbLabelStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbLabelStyle(openAcDbObject<BrxCvDbLabelStyle>(id, mode), false)
{
}

PyBrxCvDbLabelStyle::PyBrxCvDbLabelStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbLabelStyle(openAcDbObject<BrxCvDbLabelStyle>(id, mode, erased), false)
{
}

PyBrxCvDbLabelStyle::PyBrxCvDbLabelStyle(BrxCvDbLabelStyle* ptr, bool autoDelete)
    : PyBrxCvDbStyle(ptr, autoDelete)
{
}

boost::python::list PyBrxCvDbLabelStyle::components() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto& _ptr : impObj()->components())
    {
        if (_ptr.refCount() == 1)
            _pylist.append(PyBrxCvDbLabelStyleComponent{ _ptr.detach(), true });
        else
            PyThrowBadEs(eInvalidOpenState);
    }
    return _pylist;
}

PyBrxCvDbLabelStyleComponent PyBrxCvDbLabelStyle::componentAt(Adesk::UInt32 index) const
{
    //TODO: write test
    auto ptr = impObj()->componentAt(index);
    if (ptr.refCount() == 1)
        return PyBrxCvDbLabelStyleComponent{ ptr.detach(),true };
    throw PyErrorStatusException(eInvalidOpenState);
}

PyBrxCvDbLabelStyleComponent PyBrxCvDbLabelStyle::component(const std::string& name) const
{
    //TODO: write test
    auto ptr = impObj()->component(utf8_to_wstr(name).c_str());
    if (ptr.refCount() == 1)
        return PyBrxCvDbLabelStyleComponent{ ptr.detach(),true };
    throw PyErrorStatusException(eInvalidOpenState);
}

Adesk::UInt32 PyBrxCvDbLabelStyle::componentCount() const
{
    return impObj()->componentCount();
}

void PyBrxCvDbLabelStyle::addComponent(const PyBrxCvDbLabelStyleComponent& pComponent) const
{
    //TODO: write test;
    BrxCvDbLabelStyleComponentPtr ptr(pComponent.impObj());
    PyThrowBadEs(impObj()->addComponent(ptr));
    if (ptr.refCount() == 1)
        ptr.detach();
    else
        PyThrowBadEs(eInvalidOpenState);
    pComponent.forceKeepAlive(true); //PyBrxCvDbLabelStyle is now the owner
}

void PyBrxCvDbLabelStyle::removeComponent_1(const PyBrxCvDbLabelStyleComponent& pComponent) const
{
    //TODO: write test;
    BrxCvDbLabelStyleComponentPtr ptr(pComponent.impObj());
    PyThrowBadEs(impObj()->removeComponent(ptr));
    if (ptr.refCount() == 1)
        ptr.detach();
    else
        PyThrowBadEs(eInvalidOpenState);
}

void PyBrxCvDbLabelStyle::removeComponent_2(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->removeComponent(index));
}

void PyBrxCvDbLabelStyle::moveComponent(Adesk::UInt32 fromIndex, Adesk::UInt32 toIndex) const
{
    PyThrowBadEs(impObj()->moveComponent(fromIndex, toIndex));
}

PyDbObjectId PyBrxCvDbLabelStyle::textStyle() const
{
    return impObj()->textStyle();
}

void PyBrxCvDbLabelStyle::setTextStyle(const PyDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setTextStyle(objId.m_id));
}

bool PyBrxCvDbLabelStyle::isVisible() const
{
    return impObj()->isVisible();
}

void PyBrxCvDbLabelStyle::setVisibility(bool isVisible) const
{
    PyThrowBadEs(impObj()->setVisibility(isVisible));
}

PyDbObjectId PyBrxCvDbLabelStyle::layer() const
{
    return impObj()->layer();
}

void PyBrxCvDbLabelStyle::setLayer(const PyDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setLayer(objId.m_id));
}

BrxCvDbStyle::OrientationRef PyBrxCvDbLabelStyle::orientationReference() const
{
    return impObj()->orientationReference();
}

void PyBrxCvDbLabelStyle::setOrientationReference(BrxCvDbStyle::OrientationRef ref) const
{
    PyThrowBadEs(impObj()->setOrientationReference(ref));
}

PyBrxCvDbLabelStyle::ForcedInsertion PyBrxCvDbLabelStyle::forcedInsertion() const
{
    return impObj()->forcedInsertion();
}

void PyBrxCvDbLabelStyle::setForcedInsertion(ForcedInsertion value) const
{
    PyThrowBadEs(impObj()->setForcedInsertion(value));
}

double PyBrxCvDbLabelStyle::readabilityBias() const
{
    return impObj()->readabilityBias();
}

void PyBrxCvDbLabelStyle::setReadabilityBias(double radAngle) const
{
    PyThrowBadEs(impObj()->setReadabilityBias(radAngle));
}

bool PyBrxCvDbLabelStyle::planReadable() const
{
    return impObj()->planReadable();
}

void PyBrxCvDbLabelStyle::setPlanReadable(bool isPlanReadable) const
{
    PyThrowBadEs(impObj()->setPlanReadable(isPlanReadable));
}

bool PyBrxCvDbLabelStyle::flipAnchorsWithText() const
{
    return impObj()->flipAnchorsWithText();
}

void PyBrxCvDbLabelStyle::setFlipAnchorsWithText(bool flipAnchors) const
{
    PyThrowBadEs(impObj()->setFlipAnchorsWithText(flipAnchors));
}

bool PyBrxCvDbLabelStyle::forceInsideCurve() const
{
    return impObj()->forceInsideCurve();
}

void PyBrxCvDbLabelStyle::setForceInsideCurve(bool forceInside) const
{
    PyThrowBadEs(impObj()->setForceInsideCurve(forceInside));
}

Adesk::UInt32 PyBrxCvDbLabelStyle::expressionCount() const
{
    return impObj()->expressionCount();
}

boost::python::tuple PyBrxCvDbLabelStyle::expressionAt(Adesk::UInt32 index) const
{
    AcString name;
    AcString expr;
    BrxCvDataType type = BrxCvDataType::eBrxCvDataTypeNone;
    PyThrowBadEs(impObj()->expressionAt(index, name, expr, type));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(wstr_to_utf8(name), wstr_to_utf8(expr), type);
}

void PyBrxCvDbLabelStyle::setExpressionAt(Adesk::UInt32 index, const std::string& name, const std::string& expr, BrxCvDataType type) const
{
    PyThrowBadEs(impObj()->setExpressionAt(index, utf8_to_wstr(name).c_str(), utf8_to_wstr(expr).c_str(), type));
}

PyDbObjectId PyBrxCvDbLabelStyle::draggedStateLeaderArrowHeadStyle() const
{
    return impObj()->draggedStateLeaderArrowHeadStyle();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderArrowHeadStyle(const PyDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderArrowHeadStyle(objId.m_id));
}

double PyBrxCvDbLabelStyle::draggedStateLeaderArrowHeadSize() const
{
    return impObj()->draggedStateLeaderArrowHeadSize();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderArrowHeadSize(double size) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderArrowHeadSize(size));
}

Adesk::UInt32 PyBrxCvDbLabelStyle::draggedStateLeaderArrowHeadSizeExprIndex() const
{
    return impObj()->draggedStateLeaderArrowHeadSizeExprIndex();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderArrowHeadSizeExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderArrowHeadSizeExprIndex(index));
}

bool PyBrxCvDbLabelStyle::draggedStateLeaderIsVisible() const
{
    return impObj()->draggedStateLeaderIsVisible();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderVisibility(bool isVisible) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderVisibility(isVisible));
}

PyBrxCvDbLabelStyle::LeaderType PyBrxCvDbLabelStyle::draggedStateLeaderType() const
{
    return impObj()->draggedStateLeaderType();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderType(LeaderType type) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderType(type));
}

AcCmColor PyBrxCvDbLabelStyle::draggedStateLeaderColor() const
{
    return impObj()->draggedStateLeaderColor();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderColor(const AcCmColor& color) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderColor(color));
}

PyDbObjectId PyBrxCvDbLabelStyle::draggedStateLeaderLinetype() const
{
    return impObj()->draggedStateLeaderLinetype();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderLinetype(const PyDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderLinetype(objId.m_id));
}

AcDb::LineWeight PyBrxCvDbLabelStyle::draggedStateLeaderLineweight() const
{
    return impObj()->draggedStateLeaderLineweight();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderLineweight(AcDb::LineWeight lineweight) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderLineweight(lineweight));
}

PyBrxCvDbLabelStyle::LeaderAttachment PyBrxCvDbLabelStyle::draggedStateLeaderAttachment() const
{
    return impObj()->draggedStateLeaderAttachment();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderAttachment(LeaderAttachment value) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderAttachment(value));
}

bool PyBrxCvDbLabelStyle::draggedStateLeaderJustification() const
{
    return impObj()->draggedStateLeaderJustification();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderJustification(bool justifyLeader) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderJustification(justifyLeader));
}

bool PyBrxCvDbLabelStyle::draggedStateLeaderTail() const
{
    return impObj()->draggedStateLeaderTail();
}

void PyBrxCvDbLabelStyle::setDraggedStateLeaderTail(bool useTail) const
{
    PyThrowBadEs(impObj()->setDraggedStateLeaderTail(useTail));
}

PyBrxCvDbLabelStyle::DisplayMode PyBrxCvDbLabelStyle::draggedStateDisplayMode() const
{
    return impObj()->draggedStateDisplayMode();
}

void PyBrxCvDbLabelStyle::setDraggedStateDisplayMode(DisplayMode mode) const
{
    PyThrowBadEs(impObj()->setDraggedStateDisplayMode(mode));
}

bool PyBrxCvDbLabelStyle::draggedStateBorderIsVisible() const
{
    return impObj()->draggedStateBorderIsVisible();
}

void PyBrxCvDbLabelStyle::setDraggedStateBorderVisibility(bool isVisible) const
{
    PyThrowBadEs(impObj()->setDraggedStateBorderVisibility(isVisible));
}

PyBrxCvDbLabelStyle::BorderType PyBrxCvDbLabelStyle::draggedStateBorderType() const
{
    return impObj()->draggedStateBorderType();
}

void PyBrxCvDbLabelStyle::setDraggedStateBorderType(BorderType type) const
{
    PyThrowBadEs(impObj()->setDraggedStateBorderType(type));
}

bool PyBrxCvDbLabelStyle::draggedStateBackgroundMask() const
{
    return impObj()->draggedStateBackgroundMask();
}

void PyBrxCvDbLabelStyle::setDraggedStateBackgroundMask(bool useMask) const
{
    PyThrowBadEs(impObj()->setDraggedStateBackgroundMask(useMask));
}

double PyBrxCvDbLabelStyle::draggedStateBorderAndLeaderGap() const
{
    return impObj()->draggedStateBorderAndLeaderGap();
}

void PyBrxCvDbLabelStyle::setDraggedStateBorderAndLeaderGap(double value) const
{
    PyThrowBadEs(impObj()->setDraggedStateBorderAndLeaderGap(value));
}

Adesk::UInt32 PyBrxCvDbLabelStyle::draggedStateBorderAndLeaderGapExprIndex() const
{
    return impObj()->draggedStateBorderAndLeaderGapExprIndex();
}

void PyBrxCvDbLabelStyle::setDraggedStateBorderAndLeaderGapExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setDraggedStateBorderAndLeaderGapExprIndex(index));
}

double PyBrxCvDbLabelStyle::draggedStateTextHeight() const
{
    return impObj()->draggedStateTextHeight();
}

void PyBrxCvDbLabelStyle::setDraggedStateTextHeight(double height) const
{
    PyThrowBadEs(impObj()->setDraggedStateTextHeight(height));
}

Adesk::UInt32 PyBrxCvDbLabelStyle::draggedStateTextHeightExprIndex() const
{
    return impObj()->draggedStateTextHeightExprIndex();
}

void PyBrxCvDbLabelStyle::setDraggedStateTextHeightExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setDraggedStateTextHeightExprIndex(index));
}

bool PyBrxCvDbLabelStyle::draggedStateTagDisplayMode() const
{
    return impObj()->draggedStateTagDisplayMode();
}

void PyBrxCvDbLabelStyle::setDraggedStateTagDisplayMode(bool displayTag) const
{
    PyThrowBadEs(impObj()->setDraggedStateTagDisplayMode(displayTag));
}

AcCmColor PyBrxCvDbLabelStyle::draggedStateColor() const
{
    return impObj()->draggedStateColor();
}

void PyBrxCvDbLabelStyle::setDraggedStateColor(const AcCmColor& color) const
{
    PyThrowBadEs(impObj()->setDraggedStateColor(color));
}

PyDbObjectId PyBrxCvDbLabelStyle::draggedStateLinetype() const
{
    return impObj()->draggedStateLinetype();
}

void PyBrxCvDbLabelStyle::setDraggedStateLinetype(const PyDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setDraggedStateLinetype(objId.m_id));
}

AcDb::LineWeight PyBrxCvDbLabelStyle::draggedStateLineweight() const
{
    return impObj()->draggedStateLineweight();
}

void PyBrxCvDbLabelStyle::setDraggedStateLineweight(AcDb::LineWeight lineweight) const
{
    PyThrowBadEs(impObj()->setDraggedStateLineweight(lineweight));
}

double PyBrxCvDbLabelStyle::draggedStateMaximumTextWidth() const
{
    return impObj()->draggedStateMaximumTextWidth();
}

void PyBrxCvDbLabelStyle::setDraggedStateMaximumTextWidth(double maxWidth) const
{
    PyThrowBadEs(impObj()->setDraggedStateMaximumTextWidth(maxWidth));
}

Adesk::UInt32 PyBrxCvDbLabelStyle::draggedStateMaximumTextWidthExprIndex() const
{
    return impObj()->draggedStateMaximumTextWidthExprIndex();
}

void PyBrxCvDbLabelStyle::setDraggedStateMaximumTextWidthExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setDraggedStateMaximumTextWidthExprIndex(index));
}

std::string PyBrxCvDbLabelStyle::className()
{
    return std::string{ "BrxCvDbLabelStyle" };
}

PyRxClass PyBrxCvDbLabelStyle::desc()
{
    return PyRxClass{ BrxCvDbLabelStyle::desc(),false };
}

PyBrxCvDbLabelStyle PyBrxCvDbLabelStyle::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbLabelStyle>(src);
}

BrxCvDbLabelStyle* PyBrxCvDbLabelStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbLabelStyle*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleArrowWrapper
void makeBrxCvDbLabelStyleArrowWrapper()
{
    PyDocString DS("CvDbLabelStyleArrow");
    class_<PyBrxCvDbLabelStyleArrow, bases<PyBrxCvDbLabelStyleComponent>>("CvDbLabelStyleArrow")
        .def(init<>(DS.ARGS()))
        .def("arrowHeadStyle", &PyBrxCvDbLabelStyleArrow::arrowHeadStyle, DS.ARGS())
        .def("setArrowHeadStyle", &PyBrxCvDbLabelStyleArrow::setArrowHeadStyle, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("arrowHeadSize", &PyBrxCvDbLabelStyleArrow::arrowHeadSize, DS.ARGS())
        .def("setArrowHeadSize", &PyBrxCvDbLabelStyleArrow::setArrowHeadSize, DS.ARGS({ "val: float" }))
        .def("setArrowHeadSizeExprIndex", &PyBrxCvDbLabelStyleArrow::setArrowHeadSizeExprIndex, DS.ARGS({ "val: int" }))
        .def("angle", &PyBrxCvDbLabelStyleArrow::angle, DS.ARGS())
        .def("setAngle", &PyBrxCvDbLabelStyleArrow::setAngle, DS.ARGS({ "val: float" }))
        .def("angleExprIndex", &PyBrxCvDbLabelStyleArrow::angleExprIndex, DS.ARGS())
        .def("setAngleExprIndex", &PyBrxCvDbLabelStyleArrow::setAngleExprIndex, DS.ARGS({ "val: int" }))
        .def("isFixedLength", &PyBrxCvDbLabelStyleArrow::isFixedLength, DS.ARGS())
        .def("setFixedLength", &PyBrxCvDbLabelStyleArrow::setFixedLength, DS.ARGS({ "val: bool" }))
        .def("length", &PyBrxCvDbLabelStyleArrow::length, DS.ARGS())
        .def("setLength", &PyBrxCvDbLabelStyleArrow::setLength, DS.ARGS({ "val: float" }))
        .def("lengthExprIndex", &PyBrxCvDbLabelStyleArrow::lengthExprIndex, DS.ARGS())
        .def("setLengthExprIndex", &PyBrxCvDbLabelStyleArrow::setLengthExprIndex, DS.ARGS({ "val: int" }))
        .def("offset", &PyBrxCvDbLabelStyleArrow::offset, DS.ARGS())
        .def("setOffset", &PyBrxCvDbLabelStyleArrow::setOffset, DS.ARGS({ "val: PyGe.Vector2d" }))
        .def("linetype", &PyBrxCvDbLabelStyleArrow::linetype, DS.ARGS())
        .def("setLinetype", &PyBrxCvDbLabelStyleArrow::setLinetype, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("lineweight", &PyBrxCvDbLabelStyleArrow::lineweight, DS.ARGS())
        .def("setLineweight", &PyBrxCvDbLabelStyleArrow::setLineweight, DS.ARGS({ "val: PyDb.LineWeight" }))

        .def("className", &PyBrxCvDbLabelStyleArrow::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbLabelStyleArrow::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbLabelStyleArrow::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbLabelStyleArrow::PyBrxCvDbLabelStyleArrow()
    :PyBrxCvDbLabelStyleArrow(new BrxCvDbLabelStyleArrow(), true)
{
}

PyBrxCvDbLabelStyleArrow::PyBrxCvDbLabelStyleArrow(BrxCvDbLabelStyleArrow* ptr, bool autoDelete)
    : PyBrxCvDbLabelStyleComponent(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbLabelStyleArrow::arrowHeadStyle() const
{
    return PyDbObjectId{ impObj()->arrowHeadStyle() };
}

void PyBrxCvDbLabelStyleArrow::setArrowHeadStyle(const PyDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setArrowHeadStyle(objId.m_id));
}

double PyBrxCvDbLabelStyleArrow::arrowHeadSize() const
{
    return impObj()->arrowHeadSize();
}

void PyBrxCvDbLabelStyleArrow::setArrowHeadSize(double size) const
{
    PyThrowBadEs(impObj()->setArrowHeadSize(size));
}

Adesk::UInt32 PyBrxCvDbLabelStyleArrow::arrowHeadSizeExprIndex() const
{
    return impObj()->arrowHeadSizeExprIndex();
}

void PyBrxCvDbLabelStyleArrow::setArrowHeadSizeExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setArrowHeadSizeExprIndex(index));
}

double PyBrxCvDbLabelStyleArrow::angle() const
{
    return impObj()->angle();
}

void PyBrxCvDbLabelStyleArrow::setAngle(double radAngle) const
{
    PyThrowBadEs(impObj()->setAngle(radAngle));
}

Adesk::UInt32 PyBrxCvDbLabelStyleArrow::angleExprIndex() const
{
    return impObj()->angleExprIndex();
}

void PyBrxCvDbLabelStyleArrow::setAngleExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setAngleExprIndex(index));
}

bool PyBrxCvDbLabelStyleArrow::isFixedLength() const
{
    return impObj()->isFixedLength();
}

void PyBrxCvDbLabelStyleArrow::setFixedLength(bool isFixedLength) const
{
    PyThrowBadEs(impObj()->setFixedLength(isFixedLength));
}

double PyBrxCvDbLabelStyleArrow::length() const
{
    return impObj()->length();
}

void PyBrxCvDbLabelStyleArrow::setLength(double length) const
{
    PyThrowBadEs(impObj()->setLength(length));
}

Adesk::UInt32 PyBrxCvDbLabelStyleArrow::lengthExprIndex() const
{
    return impObj()->lengthExprIndex();
}

void PyBrxCvDbLabelStyleArrow::setLengthExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setLengthExprIndex(index));
}

AcGeVector2d PyBrxCvDbLabelStyleArrow::offset() const
{
    return impObj()->offset();
}

void PyBrxCvDbLabelStyleArrow::setOffset(const AcGeVector2d& offset) const
{
    PyThrowBadEs(impObj()->setOffset(offset));
}

PyDbObjectId PyBrxCvDbLabelStyleArrow::linetype() const
{
    return impObj()->linetype();
}

void PyBrxCvDbLabelStyleArrow::setLinetype(const PyDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setLinetype(objId.m_id));
}

AcDb::LineWeight PyBrxCvDbLabelStyleArrow::lineweight() const
{
    return impObj()->lineweight();
}

void PyBrxCvDbLabelStyleArrow::setLineweight(AcDb::LineWeight lineweight) const
{
    PyThrowBadEs(impObj()->setLineweight(lineweight));
}

std::string PyBrxCvDbLabelStyleArrow::className()
{
    return std::string{ "BrxCvDbLabelStyleArrow" };
}

PyRxClass PyBrxCvDbLabelStyleArrow::desc()
{
    return PyRxClass{ BrxCvDbLabelStyleArrow::desc(),false };
}

PyBrxCvDbLabelStyleArrow PyBrxCvDbLabelStyleArrow::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbLabelStyleArrow>(src);
}

BrxCvDbLabelStyleArrow* PyBrxCvDbLabelStyleArrow::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbLabelStyleArrow*>(m_pyImp.get());
}

void makeBrxCvDbLabelStyleBlockWrapper()
{
    PyDocString DS("CvDbLabelStyleBlock");
    class_<PyBrxCvDbLabelStyleBlock, bases<PyBrxCvDbLabelStyleComponent>>("CvDbLabelStyleBlock")
        .def(init<>(DS.ARGS()))
        .def("blockId", &PyBrxCvDbLabelStyleBlock::blockId, DS.ARGS())
        .def("setBlockId", &PyBrxCvDbLabelStyleBlock::setBlockId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("height", &PyBrxCvDbLabelStyleBlock::height, DS.ARGS())
        .def("setHeight", &PyBrxCvDbLabelStyleBlock::setHeight, DS.ARGS({ "val: float" }))
        .def("heightExprIndex", &PyBrxCvDbLabelStyleBlock::heightExprIndex, DS.ARGS())
        .def("setHeightExprIndex", &PyBrxCvDbLabelStyleBlock::setHeightExprIndex, DS.ARGS({ "val: int" }))
        .def("angle", &PyBrxCvDbLabelStyleBlock::angle, DS.ARGS())
        .def("setAngle", &PyBrxCvDbLabelStyleBlock::setAngle, DS.ARGS({ "val: float" }))
        .def("angleExprIndex", &PyBrxCvDbLabelStyleBlock::angleExprIndex, DS.ARGS())
        .def("setAngleExprIndex", &PyBrxCvDbLabelStyleBlock::setAngleExprIndex, DS.ARGS({ "val: int" }))
        .def("attachment", &PyBrxCvDbLabelStyleBlock::attachment, DS.ARGS())
        .def("setAttachment", &PyBrxCvDbLabelStyleBlock::setAttachment, DS.ARGS({ "attachment: PyBrxCv.BlockAttachment" }))
        .def("offset", &PyBrxCvDbLabelStyleBlock::offset, DS.ARGS())
        .def("setOffset", &PyBrxCvDbLabelStyleBlock::setOffset, DS.ARGS({ "val: PyGe.Vector2d" }))
        .def("linetype", &PyBrxCvDbLabelStyleBlock::linetype, DS.ARGS())
        .def("setLinetype", &PyBrxCvDbLabelStyleBlock::setLinetype, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("lineweight", &PyBrxCvDbLabelStyleBlock::lineweight, DS.ARGS())
        .def("setLineweight", &PyBrxCvDbLabelStyleBlock::setLineweight, DS.ARGS({ "lineWeight: PyDb.LineWeight" }))
        .def("className", &PyBrxCvDbLabelStyleBlock::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbLabelStyleBlock::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbLabelStyleBlock::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbLabelStyleBlock::PyBrxCvDbLabelStyleBlock()
    : PyBrxCvDbLabelStyleBlock(new BrxCvDbLabelStyleBlock(), true)
{
}

PyBrxCvDbLabelStyleBlock::PyBrxCvDbLabelStyleBlock(BrxCvDbLabelStyleBlock* ptr, bool autoDelete)
    : PyBrxCvDbLabelStyleComponent(ptr, autoDelete)
{
}

PyDbObjectId PyBrxCvDbLabelStyleBlock::blockId() const
{
    return impObj()->blockId();
}

void PyBrxCvDbLabelStyleBlock::setBlockId(const AcDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setBlockId(objId));
}

double PyBrxCvDbLabelStyleBlock::height() const
{
    return impObj()->height();
}

void PyBrxCvDbLabelStyleBlock::setHeight(double height) const
{
    PyThrowBadEs(impObj()->setHeight(height));
}

Adesk::UInt32 PyBrxCvDbLabelStyleBlock::heightExprIndex() const
{
    return impObj()->heightExprIndex();
}

void PyBrxCvDbLabelStyleBlock::setHeightExprIndex(Adesk::Int32 index) const
{
    PyThrowBadEs(impObj()->setHeightExprIndex(index));
}

double PyBrxCvDbLabelStyleBlock::angle() const
{
    return impObj()->angle();
}

void PyBrxCvDbLabelStyleBlock::setAngle(double radAngle) const
{
    PyThrowBadEs(impObj()->setAngle(radAngle));
}

Adesk::UInt32 PyBrxCvDbLabelStyleBlock::angleExprIndex() const
{
    return impObj()->angleExprIndex();
}

void PyBrxCvDbLabelStyleBlock::setAngleExprIndex(Adesk::Int32 index) const
{
    PyThrowBadEs(impObj()->setAngleExprIndex(index));
}

BrxCvDbLabelStyleBlock::BlockAttachment PyBrxCvDbLabelStyleBlock::attachment() const
{
    return impObj()->attachment();
}

void PyBrxCvDbLabelStyleBlock::setAttachment(BrxCvDbLabelStyleBlock::BlockAttachment attachment) const
{
    PyThrowBadEs(impObj()->setAttachment(attachment));
}

AcGeVector2d PyBrxCvDbLabelStyleBlock::offset() const
{
    return impObj()->offset();
}

void PyBrxCvDbLabelStyleBlock::setOffset(const AcGeVector2d& offset) const
{
    PyThrowBadEs(impObj()->setOffset(offset));
}

PyDbObjectId PyBrxCvDbLabelStyleBlock::linetype() const
{
    return impObj()->linetype();
}

void PyBrxCvDbLabelStyleBlock::setLinetype(const AcDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setLinetype(objId));
}

AcDb::LineWeight PyBrxCvDbLabelStyleBlock::lineweight() const
{
    return impObj()->lineweight();
}

void PyBrxCvDbLabelStyleBlock::setLineweight(AcDb::LineWeight lineweight) const
{
    PyThrowBadEs(impObj()->setLineweight(lineweight));
}

std::string PyBrxCvDbLabelStyleBlock::className()
{
    return std::string{ "BrxCvDbLabelStyleBlock" };
}

PyRxClass PyBrxCvDbLabelStyleBlock::desc()
{
    return PyRxClass{ BrxCvDbLabelStyleArrow::desc(),false };
}

PyBrxCvDbLabelStyleBlock PyBrxCvDbLabelStyleBlock::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbLabelStyleBlock>(src);
}

BrxCvDbLabelStyleBlock* PyBrxCvDbLabelStyleBlock::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbLabelStyleBlock*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbLabelStyleLine
void makeBrxCvDbLabelStyleLineWrapper()
{
    PyDocString DS("CvDbLabelStyleLine");
    class_<PyBrxCvDbLabelStyleLine, bases<PyBrxCvDbLabelStyleComponent>>("CvDbLabelStyleLine")
        .def(init<>(DS.ARGS()))
        .def("useEndPointAnchor", &PyBrxCvDbLabelStyleLine::useEndPointAnchor, DS.ARGS())
        .def("setUseEndPointAnchor", &PyBrxCvDbLabelStyleLine::setUseEndPointAnchor, DS.ARGS({ "val: bool" }))
        .def("endPointAnchorIndex", &PyBrxCvDbLabelStyleLine::endPointAnchorIndex, DS.ARGS())
        .def("setEndPointAnchorIndex", &PyBrxCvDbLabelStyleLine::setEndPointAnchorIndex, DS.ARGS({ "val: int" }))
        .def("endPointAnchorPoint", &PyBrxCvDbLabelStyleLine::endPointAnchorPoint, DS.ARGS())
        .def("setEndPointAnchorPoint", &PyBrxCvDbLabelStyleLine::setEndPointAnchorPoint, DS.ARGS({ " val : PyBrxCv.LabelAnchor" }))
        .def("angle", &PyBrxCvDbLabelStyleLine::angle, DS.ARGS())
        .def("setAngle", &PyBrxCvDbLabelStyleLine::setAngle, DS.ARGS({ "val: float" }))
        .def("angleExprIndex", &PyBrxCvDbLabelStyleLine::angleExprIndex, DS.ARGS())
        .def("setAngleExprIndex", &PyBrxCvDbLabelStyleLine::setAngleExprIndex, DS.ARGS({ "val: int" }))
        .def("length", &PyBrxCvDbLabelStyleLine::length, DS.ARGS())
        .def("setLength", &PyBrxCvDbLabelStyleLine::setLength, DS.ARGS({ "val: float" }))
        .def("lengthExprIndex", &PyBrxCvDbLabelStyleLine::lengthExprIndex, DS.ARGS())
        .def("setLengthExprIndex", &PyBrxCvDbLabelStyleLine::setLengthExprIndex, DS.ARGS({ "val: int" }))
        .def("startPointOffset", &PyBrxCvDbLabelStyleLine::startPointOffset, DS.ARGS())
        .def("setStartPointOffset", &PyBrxCvDbLabelStyleLine::setStartPointOffset, DS.ARGS({ "val: PyGe.Vector2d" }))
        .def("endPointOffset", &PyBrxCvDbLabelStyleLine::endPointOffset, DS.ARGS())
        .def("setEndPointOffset", &PyBrxCvDbLabelStyleLine::setEndPointOffset, DS.ARGS({ "val: PyGe.Vector2d" }))
        .def("lengthType", &PyBrxCvDbLabelStyleLine::lengthType, DS.ARGS())
        .def("setLengthType", &PyBrxCvDbLabelStyleLine::setLengthType, DS.ARGS({ " val : PyBrxCv.LengthType" }))
        .def("lengthPercentage", &PyBrxCvDbLabelStyleLine::lengthPercentage, DS.ARGS())
        .def("setLengthPercentage", &PyBrxCvDbLabelStyleLine::setLengthPercentage, DS.ARGS({ "val: float" }))
        .def("lengthPercentageExprIndex", &PyBrxCvDbLabelStyleLine::lengthPercentageExprIndex, DS.ARGS())
        .def("setLengthPercentageExprIndex", &PyBrxCvDbLabelStyleLine::setLengthPercentageExprIndex, DS.ARGS({ "val: int" }))
        .def("linetype", &PyBrxCvDbLabelStyleLine::linetype, DS.ARGS())
        .def("setLinetype", &PyBrxCvDbLabelStyleLine::setLinetype, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("lineweight", &PyBrxCvDbLabelStyleLine::lineweight, DS.ARGS())
        .def("setLineweight", &PyBrxCvDbLabelStyleLine::setLineweight, DS.ARGS({ "id: PyDb.LineWeight" }))

        .def("className", &PyBrxCvDbLabelStyleLine::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbLabelStyleLine::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbLabelStyleLine::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbLabelStyleLine::PyBrxCvDbLabelStyleLine()
    : PyBrxCvDbLabelStyleLine(new BrxCvDbLabelStyleLine(), true)
{
}

PyBrxCvDbLabelStyleLine::PyBrxCvDbLabelStyleLine(BrxCvDbLabelStyleLine* ptr, bool autoDelete)
    : PyBrxCvDbLabelStyleComponent(ptr, autoDelete)
{
}

bool PyBrxCvDbLabelStyleLine::useEndPointAnchor() const
{
    return impObj()->useEndPointAnchor();
}

void PyBrxCvDbLabelStyleLine::setUseEndPointAnchor(bool useEndPoint) const
{
    PyThrowBadEs(impObj()->setUseEndPointAnchor(useEndPoint));
}

Adesk::UInt32 PyBrxCvDbLabelStyleLine::endPointAnchorIndex() const
{
    return impObj()->endPointAnchorIndex();
}

void PyBrxCvDbLabelStyleLine::setEndPointAnchorIndex(Adesk::Int32 index) const
{
    PyThrowBadEs(impObj()->setEndPointAnchorIndex(index));
}

BrxCvDbLabelStyleLine::LabelAnchor PyBrxCvDbLabelStyleLine::endPointAnchorPoint() const
{
    return impObj()->endPointAnchorPoint();
}

void PyBrxCvDbLabelStyleLine::setEndPointAnchorPoint(BrxCvDbLabelStyleLine::LabelAnchor anchor) const
{
    PyThrowBadEs(impObj()->setEndPointAnchorPoint(anchor));
}

double PyBrxCvDbLabelStyleLine::angle() const
{
    return impObj()->angle();
}

void PyBrxCvDbLabelStyleLine::setAngle(double radAngle) const
{
    PyThrowBadEs(impObj()->setAngle(radAngle));
}

Adesk::UInt32 PyBrxCvDbLabelStyleLine::angleExprIndex() const
{
    return impObj()->angleExprIndex();
}

void PyBrxCvDbLabelStyleLine::setAngleExprIndex(Adesk::Int32 index) const
{
    PyThrowBadEs(impObj()->setAngleExprIndex(index));
}

double PyBrxCvDbLabelStyleLine::length() const
{
    return impObj()->length();
}

void PyBrxCvDbLabelStyleLine::setLength(double length) const
{
    PyThrowBadEs(impObj()->setLength(length));
}

Adesk::UInt32 PyBrxCvDbLabelStyleLine::lengthExprIndex() const
{
    return impObj()->lengthExprIndex();
}

void PyBrxCvDbLabelStyleLine::setLengthExprIndex(Adesk::Int32 index) const
{
    PyThrowBadEs(impObj()->setLengthExprIndex(index));
}

AcGeVector2d PyBrxCvDbLabelStyleLine::startPointOffset() const
{
    return impObj()->startPointOffset();
}

void PyBrxCvDbLabelStyleLine::setStartPointOffset(const AcGeVector2d& offset) const
{
    PyThrowBadEs(impObj()->setStartPointOffset(offset));
}

AcGeVector2d PyBrxCvDbLabelStyleLine::endPointOffset() const
{
    return impObj()->endPointOffset();
}

void PyBrxCvDbLabelStyleLine::setEndPointOffset(const AcGeVector2d& offset) const
{
    PyThrowBadEs(impObj()->setEndPointOffset(offset));
}

BrxCvDbLabelStyleLine::LengthType PyBrxCvDbLabelStyleLine::lengthType() const
{
    return impObj()->lengthType();
}

void PyBrxCvDbLabelStyleLine::setLengthType(BrxCvDbLabelStyleLine::LengthType type) const
{
    PyThrowBadEs(impObj()->setLengthType(type));
}

double PyBrxCvDbLabelStyleLine::lengthPercentage() const
{
    return impObj()->lengthPercentage();
}

void PyBrxCvDbLabelStyleLine::setLengthPercentage(double pct) const
{
    PyThrowBadEs(impObj()->setLengthPercentage(pct));
}

Adesk::UInt32 PyBrxCvDbLabelStyleLine::lengthPercentageExprIndex() const
{
    return impObj()->lengthPercentageExprIndex();
}

void PyBrxCvDbLabelStyleLine::setLengthPercentageExprIndex(Adesk::Int32 index) const
{
    PyThrowBadEs(impObj()->setLengthPercentageExprIndex(index));
}

PyDbObjectId PyBrxCvDbLabelStyleLine::linetype() const
{
    return impObj()->linetype();
}

void PyBrxCvDbLabelStyleLine::setLinetype(const PyDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setLinetype(objId.m_id));
}

AcDb::LineWeight PyBrxCvDbLabelStyleLine::lineweight() const
{
    return impObj()->lineweight();
}

void PyBrxCvDbLabelStyleLine::setLineweight(AcDb::LineWeight lineweight) const
{
    PyThrowBadEs(impObj()->setLineweight(lineweight));
}

std::string PyBrxCvDbLabelStyleLine::className()
{
    return std::string{ "BrxCvDbLabelStyleLine" };
}

PyRxClass PyBrxCvDbLabelStyleLine::desc()
{
    return PyRxClass{ BrxCvDbLabelStyleLine::desc(),false };
}

PyBrxCvDbLabelStyleLine PyBrxCvDbLabelStyleLine::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbLabelStyleLine>(src);
}

BrxCvDbLabelStyleLine* PyBrxCvDbLabelStyleLine::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbLabelStyleLine*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbLabelStyleText
void makeBrxCvDbLabelStyleTextWrapper()
{
    PyDocString DS("CvDbLabelStyleText");
    class_<PyBrxCvDbLabelStyleText, bases<PyBrxCvDbLabelStyleComponent>>("CvDbLabelStyleText")
        .def(init<>(DS.ARGS()))
        .def("contents", &PyBrxCvDbLabelStyleText::contents, DS.ARGS())
        .def("setContents", &PyBrxCvDbLabelStyleText::setContents, DS.ARGS({ "val: str" }))
        .def("textHeight", &PyBrxCvDbLabelStyleText::textHeight, DS.ARGS())
        .def("setTextHeight", &PyBrxCvDbLabelStyleText::setTextHeight, DS.ARGS({ "val: float" }))
        .def("textHeightExprIndex", &PyBrxCvDbLabelStyleText::textHeightExprIndex, DS.ARGS())
        .def("setTextHeightExprIndex", &PyBrxCvDbLabelStyleText::setTextHeightExprIndex, DS.ARGS({ "val: int" }))
        .def("textAngle", &PyBrxCvDbLabelStyleText::textAngle, DS.ARGS())
        .def("setTextAngle", &PyBrxCvDbLabelStyleText::setTextAngle, DS.ARGS({ "val: float" }))
        .def("textAngleExprIndex", &PyBrxCvDbLabelStyleText::textAngleExprIndex, DS.ARGS())
        .def("setTextAngleExprIndex", &PyBrxCvDbLabelStyleText::setTextAngleExprIndex, DS.ARGS({ "val: int" }))
        .def("textAttachment", &PyBrxCvDbLabelStyleText::textAttachment, DS.ARGS())
        .def("setTextAttachment", &PyBrxCvDbLabelStyleText::setTextAttachment, DS.ARGS({ "val: PyDb.MTextAttachmentPoint" }))
        .def("textOffset", &PyBrxCvDbLabelStyleText::textOffset, DS.ARGS())
        .def("setTextOffset", &PyBrxCvDbLabelStyleText::setTextOffset, DS.ARGS({ "val: PyGe.Vector2d" }))
        .def("textLinetype", &PyBrxCvDbLabelStyleText::textLinetype, DS.ARGS())
        .def("setTextLinetype", &PyBrxCvDbLabelStyleText::setTextLinetype, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("textLineweight", &PyBrxCvDbLabelStyleText::textLineweight, DS.ARGS())
        .def("setTextLineweight", &PyBrxCvDbLabelStyleText::setTextLineweight, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("textMaximumWidth", &PyBrxCvDbLabelStyleText::textMaximumWidth, DS.ARGS())
        .def("setTextMaximumWidth", &PyBrxCvDbLabelStyleText::setTextMaximumWidth, DS.ARGS({ "val: float" }))
        .def("textMaximumWidthExprIndex", &PyBrxCvDbLabelStyleText::textMaximumWidthExprIndex, DS.ARGS())
        .def("setTextMaximumWidthExprIndex", &PyBrxCvDbLabelStyleText::setTextMaximumWidthExprIndex, DS.ARGS({ "val: int" }))
        .def("allowCurvedText", &PyBrxCvDbLabelStyleText::allowCurvedText, DS.ARGS())
        .def("setAllowCurvedText", &PyBrxCvDbLabelStyleText::setAllowCurvedText, DS.ARGS({ "val: bool" }))
        .def("borderIsVisible", &PyBrxCvDbLabelStyleText::borderIsVisible, DS.ARGS())
        .def("setBorderVisibility", &PyBrxCvDbLabelStyleText::setBorderVisibility, DS.ARGS({ "val: bool" }))
        .def("borderType", &PyBrxCvDbLabelStyleText::borderType, DS.ARGS())
        .def("setBorderType", &PyBrxCvDbLabelStyleText::setBorderType, DS.ARGS({ "val: BorderType" }))
        .def("borderBackgroudMask", &PyBrxCvDbLabelStyleText::borderBackgroudMask, DS.ARGS())
        .def("setBorderBackgroudMask", &PyBrxCvDbLabelStyleText::setBorderBackgroudMask, DS.ARGS({ "val: bool" }))
        .def("borderGap", &PyBrxCvDbLabelStyleText::borderGap, DS.ARGS())
        .def("setBorderGap", &PyBrxCvDbLabelStyleText::setBorderGap, DS.ARGS({ "val: float" }))
        .def("borderGapExprIndex", &PyBrxCvDbLabelStyleText::borderGapExprIndex, DS.ARGS())
        .def("setBorderGapExprIndex", &PyBrxCvDbLabelStyleText::setBorderGapExprIndex, DS.ARGS({ "val: int" }))
        .def("borderColor", &PyBrxCvDbLabelStyleText::borderColor, DS.ARGS())
        .def("setBorderColor", &PyBrxCvDbLabelStyleText::setBorderColor, DS.ARGS({ "val: PyDb.Color" }))
        .def("borderLinetype", &PyBrxCvDbLabelStyleText::borderLinetype, DS.ARGS())
        .def("setBorderLinetype", &PyBrxCvDbLabelStyleText::setBorderLinetype, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("borderLineweight", &PyBrxCvDbLabelStyleText::borderLineweight, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("setBorderLineweight", &PyBrxCvDbLabelStyleText::setBorderLineweight, DS.ARGS())
        .def("textHorizontalAlignment", &PyBrxCvDbLabelStyleText::textHorizontalAlignment, DS.ARGS())
        .def("setTextHorizontalAlignment", &PyBrxCvDbLabelStyleText::setTextHorizontalAlignment, DS.ARGS({ "val: PyDb.TextHorzMode" }))

        .def("className", &PyBrxCvDbLabelStyleText::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbLabelStyleText::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyBrxCvDbLabelStyleText::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbLabelStyleText::PyBrxCvDbLabelStyleText()
    :PyBrxCvDbLabelStyleText(new BrxCvDbLabelStyleText(), true)
{
}

PyBrxCvDbLabelStyleText::PyBrxCvDbLabelStyleText(BrxCvDbLabelStyleText* ptr, bool autoDelete)
    : PyBrxCvDbLabelStyleComponent(ptr, autoDelete)
{
}

std::string PyBrxCvDbLabelStyleText::contents() const
{
    return wstr_to_utf8(impObj()->contents());
}

void PyBrxCvDbLabelStyleText::setContents(const std::string& contents) const
{
    PyThrowBadEs(impObj()->setContents(utf8_to_wstr(contents).c_str()));
}

double PyBrxCvDbLabelStyleText::textHeight() const
{
    return impObj()->textHeight();
}

void PyBrxCvDbLabelStyleText::setTextHeight(double height) const
{
    PyThrowBadEs(impObj()->setTextHeight(height));
}

Adesk::UInt32 PyBrxCvDbLabelStyleText::textHeightExprIndex() const
{
    return impObj()->textHeightExprIndex();
}

void PyBrxCvDbLabelStyleText::setTextHeightExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setTextHeightExprIndex(index));
}

double PyBrxCvDbLabelStyleText::textAngle() const
{
    return impObj()->textAngle();
}

void PyBrxCvDbLabelStyleText::setTextAngle(double radAngle) const
{
    PyThrowBadEs(impObj()->setTextAngle(radAngle));
}

Adesk::UInt32 PyBrxCvDbLabelStyleText::textAngleExprIndex() const
{
    return impObj()->textAngleExprIndex();
}

void PyBrxCvDbLabelStyleText::setTextAngleExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setTextAngleExprIndex(index));
}

AcDbMText::AttachmentPoint PyBrxCvDbLabelStyleText::textAttachment() const
{
    return impObj()->textAttachment();
}

void PyBrxCvDbLabelStyleText::setTextAttachment(AcDbMText::AttachmentPoint attachment) const
{
    PyThrowBadEs(impObj()->setTextAttachment(attachment));
}

AcGeVector2d PyBrxCvDbLabelStyleText::textOffset() const
{
    return impObj()->textOffset();
}

void PyBrxCvDbLabelStyleText::setTextOffset(const AcGeVector2d& offset) const
{
    PyThrowBadEs(impObj()->setTextOffset(offset));
}

PyDbObjectId PyBrxCvDbLabelStyleText::textLinetype() const
{
    return impObj()->textLinetype();
}

void PyBrxCvDbLabelStyleText::setTextLinetype(const PyDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setTextLinetype(objId.m_id));
}

AcDb::LineWeight PyBrxCvDbLabelStyleText::textLineweight() const
{
    return impObj()->textLineweight();
}

void PyBrxCvDbLabelStyleText::setTextLineweight(AcDb::LineWeight lineweight) const
{
    PyThrowBadEs(impObj()->setTextLineweight(lineweight));
}

double PyBrxCvDbLabelStyleText::textMaximumWidth() const
{
    return impObj()->textMaximumWidth();
}

void PyBrxCvDbLabelStyleText::setTextMaximumWidth(double maxWidth) const
{
    PyThrowBadEs(impObj()->setTextMaximumWidth(maxWidth));
}

Adesk::UInt32 PyBrxCvDbLabelStyleText::textMaximumWidthExprIndex() const
{
    return impObj()->textMaximumWidthExprIndex();
}

void PyBrxCvDbLabelStyleText::setTextMaximumWidthExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setTextMaximumWidthExprIndex(index));
}

bool PyBrxCvDbLabelStyleText::allowCurvedText() const
{
    return impObj()->allowCurvedText();
}

void PyBrxCvDbLabelStyleText::setAllowCurvedText(bool allowCurved) const
{
    PyThrowBadEs(impObj()->setAllowCurvedText(allowCurved));
}

bool PyBrxCvDbLabelStyleText::borderIsVisible() const
{
    return impObj()->borderIsVisible();
}

void PyBrxCvDbLabelStyleText::setBorderVisibility(bool isVisible) const
{
    PyThrowBadEs(impObj()->setBorderVisibility(isVisible));
}

BrxCvDbLabelStyle::BorderType PyBrxCvDbLabelStyleText::borderType() const
{
    return impObj()->borderType();
}

void PyBrxCvDbLabelStyleText::setBorderType(BrxCvDbLabelStyle::BorderType type) const
{
    PyThrowBadEs(impObj()->setBorderType(type));
}

bool PyBrxCvDbLabelStyleText::borderBackgroudMask() const
{
    return impObj()->borderBackgroudMask();
}

void PyBrxCvDbLabelStyleText::setBorderBackgroudMask(bool useMask) const
{
    PyThrowBadEs(impObj()->setBorderBackgroudMask(useMask));
}

double PyBrxCvDbLabelStyleText::borderGap() const
{
    return impObj()->borderGap();
}

void PyBrxCvDbLabelStyleText::setBorderGap(double value) const
{
    PyThrowBadEs(impObj()->setBorderGap(value));
}

Adesk::UInt32 PyBrxCvDbLabelStyleText::borderGapExprIndex() const
{
    return impObj()->borderGapExprIndex();
}

void PyBrxCvDbLabelStyleText::setBorderGapExprIndex(Adesk::UInt32 index) const
{
    PyThrowBadEs(impObj()->setBorderGapExprIndex(index));
}

AcCmColor PyBrxCvDbLabelStyleText::borderColor() const
{
    return impObj()->borderColor();
}

void PyBrxCvDbLabelStyleText::setBorderColor(const AcCmColor& color) const
{
    PyThrowBadEs(impObj()->setBorderColor(color));
}

PyDbObjectId PyBrxCvDbLabelStyleText::borderLinetype() const
{
    return impObj()->borderLinetype();
}

void PyBrxCvDbLabelStyleText::setBorderLinetype(const PyDbObjectId& objId) const
{
    PyThrowBadEs(impObj()->setBorderLinetype(objId.m_id));
}

AcDb::LineWeight PyBrxCvDbLabelStyleText::borderLineweight() const
{
    return impObj()->borderLineweight();
}

void PyBrxCvDbLabelStyleText::setBorderLineweight(AcDb::LineWeight lineweight) const
{
    PyThrowBadEs(impObj()->setBorderLineweight(lineweight));
}

AcDb::TextHorzMode PyBrxCvDbLabelStyleText::textHorizontalAlignment() const
{
    return impObj()->textHorizontalAlignment();
}

void PyBrxCvDbLabelStyleText::setTextHorizontalAlignment(AcDb::TextHorzMode alignment) const
{
    PyThrowBadEs(impObj()->setTextHorizontalAlignment(alignment));
}

std::string PyBrxCvDbLabelStyleText::className()
{
    return std::string{ "BrxCvDbLabelStyleText" };
}

PyRxClass PyBrxCvDbLabelStyleText::desc()
{
    return PyRxClass{ BrxCvDbLabelStyleText::desc(),false };
}

PyBrxCvDbLabelStyleText PyBrxCvDbLabelStyleText::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyBrxCvDbLabelStyleText>(src);
}

BrxCvDbLabelStyleText* PyBrxCvDbLabelStyleText::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbLabelStyleText*>(m_pyImp.get());
}

#endif

#endif//BRXAPP

