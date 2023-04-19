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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbMText::location() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->location();
}

Acad::ErrorStatus PyDbMText::setLocation(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLocation(val);
}

AcGeVector3d PyDbMText::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbMText::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

AcGeVector3d PyDbMText::direction() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->direction();
}

Acad::ErrorStatus PyDbMText::setDirection(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDirection(val);
}

double PyDbMText::rotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rotation();
}

Acad::ErrorStatus PyDbMText::setRotation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRotation(val);
}

double PyDbMText::width() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->width();
}

Acad::ErrorStatus PyDbMText::setWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setWidth(val);
}

double PyDbMText::ascent() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->ascent();
}

double PyDbMText::descent() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->descent();
}

PyDbObjectId PyDbMText::textStyle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle());
}

Acad::ErrorStatus PyDbMText::setTextStyle(const PyDbObjectId& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(val.m_id);
}

double PyDbMText::textHeight() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textHeight();
}

Acad::ErrorStatus PyDbMText::setTextHeight(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextHeight(val);
}

AcDbMText::AttachmentPoint PyDbMText::attachment() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->attachment();
}

Acad::ErrorStatus PyDbMText::setAttachment(AcDbMText::AttachmentPoint val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAttachment(val);
}

Acad::ErrorStatus PyDbMText::setAttachmentMovingLocation(AcDbMText::AttachmentPoint val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAttachmentMovingLocation(val);
}

AcDbMText::FlowDirection PyDbMText::flowDirection() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->flowDirection();
}

Acad::ErrorStatus PyDbMText::setFlowDirection(AcDbMText::FlowDirection val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFlowDirection(val);
}

std::string PyDbMText::contents() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    if (auto es = imp->contents(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

int PyDbMText::setContents(const std::string& str)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setContents(utf8_to_wstr(str).c_str());
}

std::string PyDbMText::contentsRTF() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    if (auto es = imp->contentsRTF(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

int PyDbMText::setContentsRTF(const std::string& str)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setContentsRTF(utf8_to_wstr(str).c_str());
}

std::string PyDbMText::text() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString str;
    if (auto es = imp->text(str); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(str);
}

double PyDbMText::actualHeight() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->actualHeight();
}

double PyDbMText::actualWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->actualWidth();
}

int PyDbMText::correctSpelling()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->correctSpelling();
#endif
}

boost::python::list PyDbMText::getBoundingPoints() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list l;
    AcGePoint3dArray arr;
    imp->getBoundingPoints(arr);
    for (const auto& item : arr)
        l.append(item);
    return l;
}

bool PyDbMText::hitTest(const AcGePoint3d& ptHit) const
{
#ifdef ARXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hitTest(ptHit);
#else
    throw PyNotimplementedByHost();
#endif // ARXAPP
}

Acad::ErrorStatus PyDbMText::setLineSpacingStyle(AcDb::LineSpacingStyle eStyle)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLineSpacingStyle(eStyle);
}

AcDb::LineSpacingStyle PyDbMText::lineSpacingStyle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->lineSpacingStyle();
}

Acad::ErrorStatus PyDbMText::setLineSpacingFactor(double dFactor)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLineSpacingFactor(dFactor);
}

double PyDbMText::lineSpacingFactor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->lineSpacingFactor();
}

bool PyDbMText::backgroundFillOn() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->backgroundFillOn();
}

Acad::ErrorStatus PyDbMText::setBackgroundFill(bool enable)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundFill(enable);
}

AcCmColor PyDbMText::getBackgroundFillColor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcCmColor clr;
    if (auto es = imp->getBackgroundFillColor(clr); es != eOk)
        throw PyAcadErrorStatus(es);
    return clr;
}

Acad::ErrorStatus PyDbMText::setBackgroundFillColor(const AcCmColor& color)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundFillColor(color);
}

double PyDbMText::getBackgroundScaleFactor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double val;
    if (auto es = imp->getBackgroundScaleFactor(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setBackgroundScaleFactor(const double scale)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundScaleFactor(scale);
}

AcCmTransparency PyDbMText::getBackgroundTransparency() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcCmTransparency val;
    if (auto es = imp->getBackgroundTransparency(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setBackgroundTransparency(const AcCmTransparency& transp)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBackgroundTransparency(transp);
}

bool PyDbMText::useBackgroundColorOn() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->useBackgroundColorOn();
}

Acad::ErrorStatus PyDbMText::setUseBackgroundColor(bool enable)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setUseBackgroundColor(enable);
}

Acad::ErrorStatus PyDbMText::setDynamicColumns(double width, double gutter, bool auto_height)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDynamicColumns(width, gutter, auto_height);
}

Acad::ErrorStatus PyDbMText::setStaticColumns(double width, double gutter, int count)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setStaticColumns(width, gutter, count);
}

AcDbMText::ColumnType PyDbMText::getColumnType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbMText::ColumnType  val;
    if (auto es = imp->getColumnType(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnType(AcDbMText::ColumnType val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setUseBackgroundColor(val);
}

bool PyDbMText::getColumnAutoHeight() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    bool  val;
    if (auto es = imp->getColumnAutoHeight(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnAutoHeight(bool val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnAutoHeight(val);
}

int PyDbMText::getColumnCount() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    int  val;
    if (auto es = imp->getColumnCount(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnCount(int val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnCount(val);
}

double PyDbMText::getColumnWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double  val;
    if (auto es = imp->getColumnWidth(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnWidth(val);
}

double PyDbMText::getColumnGutterWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double  val;
    if (auto es = imp->getColumnGutterWidth(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnGutterWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnGutterWidth(val);
}

bool PyDbMText::getColumnFlowReversed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    bool  val;
    if (auto es = imp->getColumnFlowReversed(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnFlowReversed(bool val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnFlowReversed(val);
}

double PyDbMText::getColumnHeight(int idx) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double  val;
    if (auto es = imp->getColumnHeight(idx, val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Acad::ErrorStatus PyDbMText::setColumnHeight(int idx, double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnHeight(idx,val);
}

Acad::ErrorStatus PyDbMText::convertFieldToText()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->convertFieldToText();
#endif
}

double PyDbMText::height() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->height();
}

Acad::ErrorStatus PyDbMText::setHeight(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHeight(val);
}

std::string PyDbMText::className()
{
    return "AcDbMText";
}

AcDbMText* PyDbMText::impObj() const
{
    return static_cast<AcDbMText*>(m_pImp.get());
}
