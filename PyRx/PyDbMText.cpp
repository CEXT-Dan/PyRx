#include "stdafx.h"
#include "PyDbMtext.h"
#include "PyDbObjectId.h"
using namespace boost::python;
void makePyDbMTextWrapper()
{
    class_<PyDbMText, bases<PyDbEntity>>("MText")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("location", &PyDbMText::location)
        .def("setLocation", &PyDbMText::setLocation)
        .def("normal", &PyDbMText::normal)
        .def("setNormal", &PyDbMText::setNormal)
        .def("direction", &PyDbMText::direction)
        .def("setDirection", &PyDbMText::setDirection)
        .def("rotation", &PyDbMText::rotation)
        .def("setRotation", &PyDbMText::setRotation)
        .def("width", &PyDbMText::width)
        .def("setWidth", &PyDbMText::setWidth)
        .def("ascent", &PyDbMText::ascent)
        .def("descent", &PyDbMText::descent)
        .def("textStyle", &PyDbMText::textStyle)
        .def("setTextStyle", &PyDbMText::setTextStyle)
        .def("textHeight", &PyDbMText::textHeight)
        .def("setTextHeight", &PyDbMText::setTextHeight)
        .def("attachment", &PyDbMText::attachment)
        .def("setAttachment", &PyDbMText::setAttachment)
        .def("setAttachmentMovingLocation", &PyDbMText::setAttachmentMovingLocation)
        .def("flowDirection", &PyDbMText::flowDirection)
        .def("setFlowDirection", &PyDbMText::setFlowDirection)
        .def("contents", &PyDbMText::contents)
        .def("setContents", &PyDbMText::setContents)
        .def("contentsRTF", &PyDbMText::contentsRTF)
        .def("setContentsRTF", &PyDbMText::setContentsRTF)
        .def("text", &PyDbMText::text)
        .def("actualHeight", &PyDbMText::actualHeight)
        .def("actualWidth", &PyDbMText::actualWidth)
        .def("correctSpelling", &PyDbMText::correctSpelling)
        .def("getBoundingPoints", &PyDbMText::getBoundingPoints)
        .def("hitTest", &PyDbMText::hitTest)
        .def("setLineSpacingStyle", &PyDbMText::setLineSpacingStyle)
        .def("lineSpacingStyle", &PyDbMText::lineSpacingStyle)
        .def("setLineSpacingFactor", &PyDbMText::setLineSpacingFactor)
        .def("lineSpacingFactor", &PyDbMText::lineSpacingFactor)
        .def("backgroundFillOn", &PyDbMText::backgroundFillOn)
        .def("setBackgroundFill", &PyDbMText::setBackgroundFill)
        .def("getBackgroundFillColor", &PyDbMText::getBackgroundFillColor)
        .def("setBackgroundFillColor", &PyDbMText::setBackgroundFillColor)
        .def("getBackgroundScaleFactor", &PyDbMText::getBackgroundScaleFactor)
        .def("setBackgroundScaleFactor", &PyDbMText::setBackgroundScaleFactor)
        .def("getBackgroundTransparency", &PyDbMText::getBackgroundTransparency)
        .def("setBackgroundTransparency", &PyDbMText::setBackgroundTransparency)
        .def("useBackgroundColorOn", &PyDbMText::useBackgroundColorOn)
        .def("setUseBackgroundColor", &PyDbMText::setUseBackgroundColor)
        .def("setDynamicColumns", &PyDbMText::setDynamicColumns)
        .def("setStaticColumns", &PyDbMText::setStaticColumns)
        .def("getColumnType", &PyDbMText::getColumnType)
        .def("setColumnType", &PyDbMText::setColumnType)
        .def("getColumnAutoHeight", &PyDbMText::getColumnAutoHeight)
        .def("setColumnAutoHeight", &PyDbMText::setColumnAutoHeight)
        .def("getColumnCount", &PyDbMText::getColumnCount)
        .def("setColumnCount", &PyDbMText::setColumnCount)
        .def("getColumnWidth", &PyDbMText::getColumnWidth)
        .def("setColumnWidth", &PyDbMText::setColumnWidth)
        .def("getColumnGutterWidth", &PyDbMText::getColumnGutterWidth)
        .def("setColumnGutterWidth", &PyDbMText::setColumnGutterWidth)
        .def("getColumnFlowReversed", &PyDbMText::getColumnFlowReversed)
        .def("setColumnFlowReversed", &PyDbMText::setColumnFlowReversed)
        .def("getColumnHeight", &PyDbMText::getColumnHeight)
        .def("setColumnHeight", &PyDbMText::setColumnHeight)
        .def("convertFieldToText", &PyDbMText::convertFieldToText)
        .def("height", &PyDbMText::height)
        .def("setHeight", &PyDbMText::setHeight)
        .def("className", &PyDbMText::className).staticmethod("className")
        .def("desc", &PyDbMText::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbMText::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbMText::cast).staticmethod("cast")
        ;

    enum_<AcDbMText::AttachmentPoint>("MTextAttachmentPoint")
        .value("kTopLeft", AcDbMText::AttachmentPoint::kTopLeft)
        .value("kTopCenter", AcDbMText::AttachmentPoint::kTopCenter)
        .value("kTopRight", AcDbMText::AttachmentPoint::kTopRight)
        .value("kMiddleLeft", AcDbMText::AttachmentPoint::kMiddleLeft)
        .value("kMiddleCenter", AcDbMText::AttachmentPoint::kMiddleCenter)
        .value("kMiddleRight", AcDbMText::AttachmentPoint::kMiddleRight)
        .value("kBottomLeft", AcDbMText::AttachmentPoint::kBottomLeft)
        .value("kBottomCenter", AcDbMText::AttachmentPoint::kBottomCenter)
        .value("kBottomRight", AcDbMText::AttachmentPoint::kBottomRight)
        .value("kBaseLeft", AcDbMText::AttachmentPoint::kBaseLeft)
        .value("kBaseCenter", AcDbMText::AttachmentPoint::kBaseCenter)
        .value("kBaseRight", AcDbMText::AttachmentPoint::kBaseRight)
        .value("kBaseAlign", AcDbMText::AttachmentPoint::kBaseAlign)
        .value("kBottomAlign", AcDbMText::AttachmentPoint::kBottomAlign)
        .value("kMiddleAlign", AcDbMText::AttachmentPoint::kMiddleAlign)
        .value("kTopAlign", AcDbMText::AttachmentPoint::kTopAlign)
        .value("kBaseFit", AcDbMText::AttachmentPoint::kBaseFit)
        .value("kBottomFit", AcDbMText::AttachmentPoint::kBottomFit)
        .value("kMiddleFit", AcDbMText::AttachmentPoint::kMiddleFit)
        .value("kTopFit", AcDbMText::AttachmentPoint::kTopFit)
        .value("kBaseMid", AcDbMText::AttachmentPoint::kBaseMid)
        .value("kBottomMid", AcDbMText::AttachmentPoint::kBottomMid)
        .value("kMiddleMid", AcDbMText::AttachmentPoint::kMiddleMid)
        .value("kTopMid", AcDbMText::AttachmentPoint::kTopMid)
        .export_values()
        ;
    enum_<AcDbMText::FlowDirection>("MTextFlowDirection")
        .value("kLtoR", AcDbMText::FlowDirection::kLtoR)
        .value("kRtoL", AcDbMText::FlowDirection::kRtoL)
        .value("kTtoB", AcDbMText::FlowDirection::kTtoB)
        .value("kBtoT", AcDbMText::FlowDirection::kBtoT)
        .value("kByStyle", AcDbMText::FlowDirection::kByStyle)
        .export_values()
        ;
    enum_<AcDbMText::ColumnType>("MTextColumnType")
        .value("kNoColumns", AcDbMText::ColumnType::kNoColumns)
        .value("kStaticColumns", AcDbMText::ColumnType::kStaticColumns)
        .value("kDynamicColumns", AcDbMText::ColumnType::kDynamicColumns)
        .export_values()
        ;
}

PyDbMText::PyDbMText()
    : PyDbMText::PyDbMText(new AcDbMText(), true)
{
}

PyDbMText::PyDbMText(AcDbMText* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbMText::PyDbMText(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbMText* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbMText>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

AcGePoint3d PyDbMText::location() const
{
    return impObj()->location();
}

void PyDbMText::setLocation(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setLocation(val));
}

AcGeVector3d PyDbMText::normal() const
{
    return impObj()->normal();
}

void PyDbMText::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

AcGeVector3d PyDbMText::direction() const
{
    return impObj()->direction();
}

void PyDbMText::setDirection(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setDirection(val));
}

double PyDbMText::rotation() const
{
    return impObj()->rotation();
}

void PyDbMText::setRotation(double val)
{
    return PyThrowBadEs(impObj()->setRotation(val));
}

double PyDbMText::width() const
{
    return impObj()->width();
}

void PyDbMText::setWidth(double val)
{
    return PyThrowBadEs(impObj()->setWidth(val));
}

double PyDbMText::ascent() const
{
    return impObj()->ascent();
}

double PyDbMText::descent() const
{
    return impObj()->descent();
}

PyDbObjectId PyDbMText::textStyle() const
{
    return PyDbObjectId(impObj()->textStyle());
}

void PyDbMText::setTextStyle(const PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setTextStyle(val.m_id));
}

double PyDbMText::textHeight() const
{
    return impObj()->textHeight();
}

void PyDbMText::setTextHeight(double val)
{
    return PyThrowBadEs(impObj()->setTextHeight(val));
}

AcDbMText::AttachmentPoint PyDbMText::attachment() const
{
    return impObj()->attachment();
}

void PyDbMText::setAttachment(AcDbMText::AttachmentPoint val)
{
    return PyThrowBadEs(impObj()->setAttachment(val));
}

void PyDbMText::setAttachmentMovingLocation(AcDbMText::AttachmentPoint val)
{
    return PyThrowBadEs(impObj()->setAttachmentMovingLocation(val));
}

AcDbMText::FlowDirection PyDbMText::flowDirection() const
{
    return impObj()->flowDirection();
}

void PyDbMText::setFlowDirection(AcDbMText::FlowDirection val)
{
    return PyThrowBadEs(impObj()->setFlowDirection(val));
}

std::string PyDbMText::contents() const
{
    AcString str;
    if (auto es = impObj()->contents(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

int PyDbMText::setContents(const std::string& str)
{
    return impObj()->setContents(utf8_to_wstr(str).c_str());
}

std::string PyDbMText::contentsRTF() const
{
    AcString str;
    if (auto es = impObj()->contentsRTF(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

int PyDbMText::setContentsRTF(const std::string& str)
{
    return impObj()->setContentsRTF(utf8_to_wstr(str).c_str());
}

std::string PyDbMText::text() const
{
    AcString str;
    if (auto es = impObj()->text(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

double PyDbMText::actualHeight() const
{
    return impObj()->actualHeight();
}

double PyDbMText::actualWidth() const
{
    return impObj()->actualWidth();
}

int PyDbMText::correctSpelling()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return impObj()->correctSpelling();
#endif
}

boost::python::list PyDbMText::getBoundingPoints() const
{
    PyAutoLockGIL lock;
    boost::python::list l;
    AcGePoint3dArray arr;
    impObj()->getBoundingPoints(arr);
    for (const auto& item : arr)
        l.append(item);
    return l;
}

bool PyDbMText::hitTest(const AcGePoint3d& ptHit) const
{
#ifdef ARXAPP
    return impObj()->hitTest(ptHit);
#else
    throw PyNotimplementedByHost();
#endif // ARXAPP
}

void PyDbMText::setLineSpacingStyle(AcDb::LineSpacingStyle eStyle)
{
    return PyThrowBadEs(impObj()->setLineSpacingStyle(eStyle));
}

AcDb::LineSpacingStyle PyDbMText::lineSpacingStyle() const
{
    return impObj()->lineSpacingStyle();
}

void PyDbMText::setLineSpacingFactor(double dFactor)
{
    return PyThrowBadEs(impObj()->setLineSpacingFactor(dFactor));
}

double PyDbMText::lineSpacingFactor() const
{
    return impObj()->lineSpacingFactor();
}

bool PyDbMText::backgroundFillOn() const
{
    return impObj()->backgroundFillOn();
}

void PyDbMText::setBackgroundFill(bool enable)
{
    return PyThrowBadEs(impObj()->setBackgroundFill(enable));
}

AcCmColor PyDbMText::getBackgroundFillColor() const
{
    AcCmColor clr;
    if (auto es = impObj()->getBackgroundFillColor(clr); es != eOk)
        throw PyAcadErrorStatus(es);
    return clr;
}

void PyDbMText::setBackgroundFillColor(const AcCmColor& color)
{
    return PyThrowBadEs(impObj()->setBackgroundFillColor(color));
}

double PyDbMText::getBackgroundScaleFactor() const
{
    double val;
    if (auto es = impObj()->getBackgroundScaleFactor(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

void PyDbMText::setBackgroundScaleFactor(const double scale)
{
    return PyThrowBadEs(impObj()->setBackgroundScaleFactor(scale));
}

AcCmTransparency PyDbMText::getBackgroundTransparency() const
{
    AcCmTransparency val;
    if (auto es = impObj()->getBackgroundTransparency(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

void PyDbMText::setBackgroundTransparency(const AcCmTransparency& transp)
{
    return PyThrowBadEs(impObj()->setBackgroundTransparency(transp));
}

bool PyDbMText::useBackgroundColorOn() const
{
    return impObj()->useBackgroundColorOn();
}

void PyDbMText::setUseBackgroundColor(bool enable)
{
    return PyThrowBadEs(impObj()->setUseBackgroundColor(enable));
}

void PyDbMText::setDynamicColumns(double width, double gutter, bool auto_height)
{
    return PyThrowBadEs(impObj()->setDynamicColumns(width, gutter, auto_height));
}

void PyDbMText::setStaticColumns(double width, double gutter, int count)
{
    return PyThrowBadEs(impObj()->setStaticColumns(width, gutter, count));
}

AcDbMText::ColumnType PyDbMText::getColumnType() const
{
    AcDbMText::ColumnType  val;
    if (auto es = impObj()->getColumnType(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

void PyDbMText::setColumnType(AcDbMText::ColumnType val)
{
    return PyThrowBadEs(impObj()->setUseBackgroundColor(val));
}

bool PyDbMText::getColumnAutoHeight() const
{
    bool  val;
    if (auto es = impObj()->getColumnAutoHeight(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

void PyDbMText::setColumnAutoHeight(bool val)
{
    return PyThrowBadEs(impObj()->setColumnAutoHeight(val));
}

int PyDbMText::getColumnCount() const
{
    int  val;
    if (auto es = impObj()->getColumnCount(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

void PyDbMText::setColumnCount(int val)
{
    return PyThrowBadEs(impObj()->setColumnCount(val));
}

double PyDbMText::getColumnWidth() const
{
    double  val;
    if (auto es = impObj()->getColumnWidth(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

void PyDbMText::setColumnWidth(double val)
{
    return PyThrowBadEs(impObj()->setColumnWidth(val));
}

double PyDbMText::getColumnGutterWidth() const
{
    double  val;
    if (auto es = impObj()->getColumnGutterWidth(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

void PyDbMText::setColumnGutterWidth(double val)
{
    return PyThrowBadEs(impObj()->setColumnGutterWidth(val));
}

bool PyDbMText::getColumnFlowReversed() const
{
    bool  val;
    if (auto es = impObj()->getColumnFlowReversed(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

void PyDbMText::setColumnFlowReversed(bool val)
{
    return PyThrowBadEs(impObj()->setColumnFlowReversed(val));
}

double PyDbMText::getColumnHeight(int idx) const
{
    double  val;
    if (auto es = impObj()->getColumnHeight(idx, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

void PyDbMText::setColumnHeight(int idx, double val)
{
    return PyThrowBadEs(impObj()->setColumnHeight(idx, val));
}

void PyDbMText::convertFieldToText()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->convertFieldToText());
#endif
}

double PyDbMText::height() const
{
    return impObj()->height();
}

void PyDbMText::setHeight(double val)
{
    return PyThrowBadEs(impObj()->setHeight(val));
}

std::string PyDbMText::className()
{
    return "AcDbMText";
}

PyRxClass PyDbMText::desc()
{
    return PyRxClass(AcDbMText::desc(), false);
}

PyDbMText PyDbMText::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbMText::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbMText(static_cast<AcDbMText*>(src.impObj()->clone()), true);
}

PyDbMText PyDbMText::cast(const PyRxObject& src)
{
    PyDbMText dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbMText* PyDbMText::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbMText*>(m_pyImp.get());
}

