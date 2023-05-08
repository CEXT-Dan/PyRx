#include "stdafx.h"
#include "PyDbMtext.h"
#include "PyDbObjectId.h"
using namespace boost::python;
void makePyDbMTextWrapper()
{
    scope MText = class_<PyDbMText, bases<PyDbEntity>>("MText")
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
    enum_<AcDbMText::ColumnType>("MtextColumnType")
        .value("kLtoR", AcDbMText::ColumnType::kNoColumns)
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

Acad::ErrorStatus PyDbMText::setLocation(const AcGePoint3d& val)
{
    return impObj()->setLocation(val);
}

AcGeVector3d PyDbMText::normal() const
{
    return impObj()->normal();
}

Acad::ErrorStatus PyDbMText::setNormal(const AcGeVector3d& val)
{
    return impObj()->setNormal(val);
}

AcGeVector3d PyDbMText::direction() const
{
    return impObj()->direction();
}

Acad::ErrorStatus PyDbMText::setDirection(const AcGeVector3d& val)
{
    return impObj()->setDirection(val);
}

double PyDbMText::rotation() const
{
    return impObj()->rotation();
}

Acad::ErrorStatus PyDbMText::setRotation(double val)
{
    return impObj()->setRotation(val);
}

double PyDbMText::width() const
{
    return impObj()->width();
}

Acad::ErrorStatus PyDbMText::setWidth(double val)
{
    return impObj()->setWidth(val);
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

Acad::ErrorStatus PyDbMText::setTextStyle(const PyDbObjectId& val)
{
    return impObj()->setTextStyle(val.m_id);
}

double PyDbMText::textHeight() const
{
    return impObj()->textHeight();
}

Acad::ErrorStatus PyDbMText::setTextHeight(double val)
{
    return impObj()->setTextHeight(val);
}

AcDbMText::AttachmentPoint PyDbMText::attachment() const
{
    return impObj()->attachment();
}

Acad::ErrorStatus PyDbMText::setAttachment(AcDbMText::AttachmentPoint val)
{
    return impObj()->setAttachment(val);
}

Acad::ErrorStatus PyDbMText::setAttachmentMovingLocation(AcDbMText::AttachmentPoint val)
{
    return impObj()->setAttachmentMovingLocation(val);
}

AcDbMText::FlowDirection PyDbMText::flowDirection() const
{
    return impObj()->flowDirection();
}

Acad::ErrorStatus PyDbMText::setFlowDirection(AcDbMText::FlowDirection val)
{
    return impObj()->setFlowDirection(val);
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
#ifdef BRXAPP
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

Acad::ErrorStatus PyDbMText::setLineSpacingStyle(AcDb::LineSpacingStyle eStyle)
{
    return impObj()->setLineSpacingStyle(eStyle);
}

AcDb::LineSpacingStyle PyDbMText::lineSpacingStyle() const
{
    return impObj()->lineSpacingStyle();
}

Acad::ErrorStatus PyDbMText::setLineSpacingFactor(double dFactor)
{
    return impObj()->setLineSpacingFactor(dFactor);
}

double PyDbMText::lineSpacingFactor() const
{
    return impObj()->lineSpacingFactor();
}

bool PyDbMText::backgroundFillOn() const
{
    return impObj()->backgroundFillOn();
}

Acad::ErrorStatus PyDbMText::setBackgroundFill(bool enable)
{
    return impObj()->setBackgroundFill(enable);
}

AcCmColor PyDbMText::getBackgroundFillColor() const
{
    AcCmColor clr;
    if (auto es = impObj()->getBackgroundFillColor(clr); es != eOk)
        throw PyAcadErrorStatus(es);
    return clr;
}

Acad::ErrorStatus PyDbMText::setBackgroundFillColor(const AcCmColor& color)
{
    return impObj()->setBackgroundFillColor(color);
}

double PyDbMText::getBackgroundScaleFactor() const
{
    double val;
    if (auto es = impObj()->getBackgroundScaleFactor(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setBackgroundScaleFactor(const double scale)
{
    return impObj()->setBackgroundScaleFactor(scale);
}

AcCmTransparency PyDbMText::getBackgroundTransparency() const
{
    AcCmTransparency val;
    if (auto es = impObj()->getBackgroundTransparency(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setBackgroundTransparency(const AcCmTransparency& transp)
{
    return impObj()->setBackgroundTransparency(transp);
}

bool PyDbMText::useBackgroundColorOn() const
{
    return impObj()->useBackgroundColorOn();
}

Acad::ErrorStatus PyDbMText::setUseBackgroundColor(bool enable)
{
    return impObj()->setUseBackgroundColor(enable);
}

Acad::ErrorStatus PyDbMText::setDynamicColumns(double width, double gutter, bool auto_height)
{
    return impObj()->setDynamicColumns(width, gutter, auto_height);
}

Acad::ErrorStatus PyDbMText::setStaticColumns(double width, double gutter, int count)
{
    return impObj()->setStaticColumns(width, gutter, count);
}

AcDbMText::ColumnType PyDbMText::getColumnType() const
{
    AcDbMText::ColumnType  val;
    if (auto es = impObj()->getColumnType(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnType(AcDbMText::ColumnType val)
{
    return impObj()->setUseBackgroundColor(val);
}

bool PyDbMText::getColumnAutoHeight() const
{
    bool  val;
    if (auto es = impObj()->getColumnAutoHeight(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnAutoHeight(bool val)
{
    return impObj()->setColumnAutoHeight(val);
}

int PyDbMText::getColumnCount() const
{
    int  val;
    if (auto es = impObj()->getColumnCount(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnCount(int val)
{
    return impObj()->setColumnCount(val);
}

double PyDbMText::getColumnWidth() const
{
    double  val;
    if (auto es = impObj()->getColumnWidth(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnWidth(double val)
{
    return impObj()->setColumnWidth(val);
}

double PyDbMText::getColumnGutterWidth() const
{
    double  val;
    if (auto es = impObj()->getColumnGutterWidth(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnGutterWidth(double val)
{
    return impObj()->setColumnGutterWidth(val);
}

bool PyDbMText::getColumnFlowReversed() const
{
    bool  val;
    if (auto es = impObj()->getColumnFlowReversed(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnFlowReversed(bool val)
{
    return impObj()->setColumnFlowReversed(val);
}

double PyDbMText::getColumnHeight(int idx) const
{
    double  val;
    if (auto es = impObj()->getColumnHeight(idx, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnHeight(int idx, double val)
{
    return impObj()->setColumnHeight(idx,val);
}

Acad::ErrorStatus PyDbMText::convertFieldToText()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->convertFieldToText();
#endif
}

double PyDbMText::height() const
{
    return impObj()->height();
}

Acad::ErrorStatus PyDbMText::setHeight(double val)
{
    return impObj()->setHeight(val);
}

std::string PyDbMText::className()
{
    return "AcDbMText";
}

AcDbMText* PyDbMText::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbMText*>(m_pImp.get());
}

