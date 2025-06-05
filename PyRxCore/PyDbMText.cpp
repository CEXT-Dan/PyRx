#include "stdafx.h"
#include "PyDbMtext.h"
#include "PyDbObjectId.h"
using namespace boost::python;

int AcDbMTextFragmentCallBack(AcDbMTextFragment* frag, void* param);

enum class PyRxMTextFragmentType
{
    kLocation,
    kNormal,
    kDirection,
    kTextValue,
    kFont,
    kBigFont,
    kExtents,
    kCapsHeight,
    kWidthFactor,
    kObliqueAngle,
    kTrackingFactor,
    kColor,
    kStackTop,
    kStackBottom,
    kUnderlined,
    kOverlined,
    kStrikethrough,
    kUnderPoints,
    kOverPoints,
    kStrikePoints,
    kFontname,
    kBold,
    kItalic,
    kEndFragmentTypes,
};

void makePyDbMTextWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("MText");
    class_<PyDbMText, bases<PyDbEntity>>("MText")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 6840)))
        .def("location", &PyDbMText::location, DS.ARGS(6885))
        .def("setLocation", &PyDbMText::setLocation, DS.ARGS({ "val : PyGe.Point3d" }, 6916))
        .def("normal", &PyDbMText::normal, DS.ARGS(6887))
        .def("setNormal", &PyDbMText::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }, 6917))
        .def("direction", &PyDbMText::direction, DS.ARGS(6859))
        .def("setDirection", &PyDbMText::setDirection, DS.ARGS({ "val : PyGe.Vector3d" }, 6909))
        .def("rotation", &PyDbMText::rotation, DS.ARGS(6893))
        .def("setRotation", &PyDbMText::setRotation, DS.ARGS({ "val : float" }, 6918))
        .def("width", &PyDbMText::width, DS.ARGS(6939))
        .def("setWidth", &PyDbMText::setWidth, DS.ARGS({ "val : float" }, 6925))
        .def("ascent", &PyDbMText::ascent, DS.ARGS(6846))
        .def("descent", &PyDbMText::descent, DS.ARGS(6858))
        .def("textStyle", &PyDbMText::textStyle, DS.ARGS(6933))
        .def("setTextStyle", &PyDbMText::setTextStyle, DS.ARGS({ "val : PyDb.ObjectId" }, 6922))
        .def("textHeight", &PyDbMText::textHeight, DS.ARGS(6932))
        .def("setTextHeight", &PyDbMText::setTextHeight, DS.ARGS({ "val : float" }, 6921))
        .def("attachment", &PyDbMText::attachment, DS.ARGS(6847))
        .def("setAttachment", &PyDbMText::setAttachment, DS.ARGS({ "val : PyDb.MTextAttachmentPoint" }, 6894))
        .def("setAttachmentMovingLocation", &PyDbMText::setAttachmentMovingLocation, DS.ARGS({ "val: PyDb.MTextAttachmentPoint" }, 6895))
        .def("flowDirection", &PyDbMText::flowDirection, DS.ARGS(6861))
        .def("setFlowDirection", &PyDbMText::setFlowDirection, DS.ARGS({ "val : PyDb.MTextFlowDirection" }, 6912))
        .def("contents", &PyDbMText::contents, DS.ARGS(6854))
        .def("setContents", &PyDbMText::setContents, DS.ARGS({ "val : str" }, 6907))
        .def("contentsRTF", &PyDbMText::contentsRTF, DS.ARGS(6855))
        .def("setContentsRTF", &PyDbMText::setContentsRTF, DS.ARGS({ "val : str" }, 6908))
        .def("text", &PyDbMText::text, DS.ARGS(6931))
        .def("actualHeight", &PyDbMText::actualHeight, DS.ARGS(6843))
        .def("actualWidth", &PyDbMText::actualWidth, DS.ARGS(6844))
        .def("correctSpelling", &PyDbMText::correctSpelling, DS.ARGS(6857))
        .def("getBoundingPoints", &PyDbMText::getBoundingPoints, DS.ARGS(6867))
        .def("getBoundingPointsByLine", &PyDbMText::getBoundingPointsByLine, DS.ARGS(6868))
        .def("hitTest", &PyDbMText::hitTest, DS.ARGS({ "val : PyGe.Point3d" }, 6880))
        .def("setLineSpacingStyle", &PyDbMText::setLineSpacingStyle, DS.ARGS({ "val : PyDb.LineSpacingStyle" }, 6915))
        .def("lineSpacingStyle", &PyDbMText::lineSpacingStyle, DS.ARGS(6884))
        .def("setLineSpacingFactor", &PyDbMText::setLineSpacingFactor, DS.ARGS({ "val : float" }, 6914))
        .def("lineSpacingFactor", &PyDbMText::lineSpacingFactor, DS.ARGS(6883))
        .def("backgroundFillOn", &PyDbMText::backgroundFillOn, DS.ARGS(6849))
        .def("setBackgroundFill", &PyDbMText::setBackgroundFill, DS.ARGS({ "val : bool" }, 6896))
        .def("getBackgroundFillColor", &PyDbMText::getBackgroundFillColor, DS.ARGS(6864))
        .def("setBackgroundFillColor", &PyDbMText::setBackgroundFillColor, DS.ARGS({ "val : PyDb.AcCmColor" }, 6897))
        .def("getBackgroundScaleFactor", &PyDbMText::getBackgroundScaleFactor, DS.ARGS(6865))
        .def("setBackgroundScaleFactor", &PyDbMText::setBackgroundScaleFactor, DS.ARGS({ "val : float" }, 6898))
        .def("getBackgroundTransparency", &PyDbMText::getBackgroundTransparency, DS.ARGS(6866))
        .def("setBackgroundTransparency", &PyDbMText::setBackgroundTransparency, DS.ARGS({ "val : PyDb.AcCmTransparency" }, 6899))
        .def("useBackgroundColorOn", &PyDbMText::useBackgroundColorOn, DS.ARGS(6937))
        .def("setUseBackgroundColor", &PyDbMText::setUseBackgroundColor, DS.ARGS({ "val : bool" }, 6923))
        .def("setDynamicColumns", &PyDbMText::setDynamicColumns, DS.ARGS({ "width : float","gutter : float","autoHeight : bool" }, 6910))
        .def("setStaticColumns", &PyDbMText::setStaticColumns, DS.ARGS({ "width : float","gutter : float","count : int" }, 6920))
        .def("getColumnType", &PyDbMText::getColumnType, DS.ARGS(6874))
        .def("setColumnType", &PyDbMText::setColumnType, DS.ARGS({ "val : PyDb.MTextColumnType" }, 6905))
        .def("getColumnAutoHeight", &PyDbMText::getColumnAutoHeight, DS.ARGS(6869))
        .def("setColumnAutoHeight", &PyDbMText::setColumnAutoHeight, DS.ARGS({ "val : bool" }, 6900))
        .def("getColumnCount", &PyDbMText::getColumnCount, DS.ARGS(6900))
        .def("setColumnCount", &PyDbMText::setColumnCount, DS.ARGS({ "val : int" }, 6901))
        .def("getColumnWidth", &PyDbMText::getColumnWidth, DS.ARGS(6875))
        .def("setColumnWidth", &PyDbMText::setColumnWidth, DS.ARGS({ "val : float" }, 6906))
        .def("getColumnGutterWidth", &PyDbMText::getColumnGutterWidth, DS.ARGS(6872))
        .def("setColumnGutterWidth", &PyDbMText::setColumnGutterWidth, DS.ARGS({ "val : float" }, 6903))
        .def("getColumnFlowReversed", &PyDbMText::getColumnFlowReversed, DS.ARGS(6871))
        .def("setColumnFlowReversed", &PyDbMText::setColumnFlowReversed, DS.ARGS({ "val : bool" }, 6902))
        .def("getColumnHeight", &PyDbMText::getColumnHeight, DS.ARGS({ "idx : int" }, 6873))
        .def("setColumnHeight", &PyDbMText::setColumnHeight, DS.ARGS({ "idx : int", "val : float" }, 6904))
        .def("convertFieldToText", &PyDbMText::convertFieldToText, DS.ARGS(6856))
        .def("height", &PyDbMText::height, DS.ARGS(6878))
        .def("setHeight", &PyDbMText::setHeight, DS.ARGS({ "val : float" }, 6913))
        .def("getFragments", &PyDbMText::getFragments, DS.ARGS(6860))
        .def("className", &PyDbMText::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbMText::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbMText::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbMText::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

    enum_<PyRxMTextFragmentType>("MTextFragmentType")
        .value("kLocation", PyRxMTextFragmentType::kLocation)
        .value("kNormal", PyRxMTextFragmentType::kNormal)
        .value("kDirection", PyRxMTextFragmentType::kDirection)
        .value("kTextValue", PyRxMTextFragmentType::kTextValue)
        .value("kFont", PyRxMTextFragmentType::kFont)
        .value("kBigFont", PyRxMTextFragmentType::kBigFont)
        .value("kExtents", PyRxMTextFragmentType::kExtents)
        .value("kCapsHeight", PyRxMTextFragmentType::kCapsHeight)
        .value("kWidthFactor", PyRxMTextFragmentType::kWidthFactor)
        .value("kObliqueAngle", PyRxMTextFragmentType::kObliqueAngle)
        .value("kTrackingFactor", PyRxMTextFragmentType::kTrackingFactor)
        .value("kColor", PyRxMTextFragmentType::kColor)
        .value("kStackTop", PyRxMTextFragmentType::kStackTop)
        .value("kStackBottom", PyRxMTextFragmentType::kStackBottom)
        .value("kUnderlined", PyRxMTextFragmentType::kUnderlined)
        .value("kOverlined", PyRxMTextFragmentType::kOverlined)
        .value("kStrikethrough", PyRxMTextFragmentType::kStrikethrough)
        .value("kUnderPoints", PyRxMTextFragmentType::kUnderPoints)
        .value("kOverPoints", PyRxMTextFragmentType::kOverPoints)
        .value("kStrikePoints", PyRxMTextFragmentType::kStrikePoints)
        .value("kFontname", PyRxMTextFragmentType::kFontname)
        .value("kBold", PyRxMTextFragmentType::kBold)
        .value("kItalic", PyRxMTextFragmentType::kItalic)
        .value("kEndFragmentTypes", PyRxMTextFragmentType::kEndFragmentTypes)
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

PyDbMText::PyDbMText(const PyDbObjectId& id)
    : PyDbMText(openAcDbObject<AcDbMText>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbMText::PyDbMText(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbMText>(id, mode), false)
{
}

PyDbMText::PyDbMText(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbMText>(id, mode), erased)
{
}

AcGePoint3d PyDbMText::location() const
{
    return impObj()->location();
}

void PyDbMText::setLocation(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setLocation(val));
}

AcGeVector3d PyDbMText::normal() const
{
    return impObj()->normal();
}

void PyDbMText::setNormal(const AcGeVector3d& val) const
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

AcGeVector3d PyDbMText::direction() const
{
    return impObj()->direction();
}

void PyDbMText::setDirection(const AcGeVector3d& val) const
{
    return PyThrowBadEs(impObj()->setDirection(val));
}

double PyDbMText::rotation() const
{
    return impObj()->rotation();
}

void PyDbMText::setRotation(double val) const
{
    return PyThrowBadEs(impObj()->setRotation(val));
}

double PyDbMText::width() const
{
    return impObj()->width();
}

void PyDbMText::setWidth(double val) const
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

void PyDbMText::setTextStyle(const PyDbObjectId& val) const
{
    return PyThrowBadEs(impObj()->setTextStyle(val.m_id));
}

double PyDbMText::textHeight() const
{
    return impObj()->textHeight();
}

void PyDbMText::setTextHeight(double val) const
{
    return PyThrowBadEs(impObj()->setTextHeight(val));
}

AcDbMText::AttachmentPoint PyDbMText::attachment() const
{
    return impObj()->attachment();
}

void PyDbMText::setAttachment(AcDbMText::AttachmentPoint val) const
{
    return PyThrowBadEs(impObj()->setAttachment(val));
}

void PyDbMText::setAttachmentMovingLocation(AcDbMText::AttachmentPoint val) const
{
    return PyThrowBadEs(impObj()->setAttachmentMovingLocation(val));
}

AcDbMText::FlowDirection PyDbMText::flowDirection() const
{
    return impObj()->flowDirection();
}

void PyDbMText::setFlowDirection(AcDbMText::FlowDirection val) const
{
    return PyThrowBadEs(impObj()->setFlowDirection(val));
}

std::string PyDbMText::contents() const
{
    AcString str;
    PyThrowBadEs(impObj()->contents(str));
    return wstr_to_utf8(str);
}

int PyDbMText::setContents(const std::string& str) const
{
    return impObj()->setContents(utf8_to_wstr(str).c_str());
}

std::string PyDbMText::contentsRTF() const
{
    AcString str;
    PyThrowBadEs(impObj()->contentsRTF(str));
    return wstr_to_utf8(str);
}

int PyDbMText::setContentsRTF(const std::string& str) const
{
    return impObj()->setContentsRTF(utf8_to_wstr(str).c_str());
}

std::string PyDbMText::text() const
{
    AcString str;
    PyThrowBadEs(impObj()->text(str));
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

int PyDbMText::correctSpelling() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->correctSpelling();
#endif
}

boost::python::list PyDbMText::getBoundingPoints() const
{
    AcGePoint3dArray arr;
    impObj()->getBoundingPoints(arr);
    return Point3dArrayToPyList(arr);
}

boost::python::list PyDbMText::getBoundingPointsByLine() const
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcArray<AcGePoint3dArray> data;
    impObj()->getBoundingPointsByLine(data);
    boost::python::list pylist;
    for (const auto& item : data)
        pylist.append(Point3dArrayToPyList(item));
    return pylist;
#endif
}

bool PyDbMText::hitTest(const AcGePoint3d& ptHit) const
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->hitTest(ptHit);
#endif
}

void PyDbMText::setLineSpacingStyle(AcDb::LineSpacingStyle eStyle) const
{
    return PyThrowBadEs(impObj()->setLineSpacingStyle(eStyle));
}

AcDb::LineSpacingStyle PyDbMText::lineSpacingStyle() const
{
    return impObj()->lineSpacingStyle();
}

void PyDbMText::setLineSpacingFactor(double dFactor) const
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

void PyDbMText::setBackgroundFill(bool enable) const
{
    return PyThrowBadEs(impObj()->setBackgroundFill(enable));
}

AcCmColor PyDbMText::getBackgroundFillColor() const
{
    AcCmColor clr;
    PyThrowBadEs(impObj()->getBackgroundFillColor(clr));
    return clr;
}

void PyDbMText::setBackgroundFillColor(const AcCmColor& color) const
{
    return PyThrowBadEs(impObj()->setBackgroundFillColor(color));
}

double PyDbMText::getBackgroundScaleFactor() const
{
    double val;
    PyThrowBadEs(impObj()->getBackgroundScaleFactor(val));
    return val;
}

void PyDbMText::setBackgroundScaleFactor(const double scale) const
{
    return PyThrowBadEs(impObj()->setBackgroundScaleFactor(scale));
}

AcCmTransparency PyDbMText::getBackgroundTransparency() const
{
    AcCmTransparency val;
    PyThrowBadEs(impObj()->getBackgroundTransparency(val));
    return val;
}

void PyDbMText::setBackgroundTransparency(const AcCmTransparency& transp) const
{
    return PyThrowBadEs(impObj()->setBackgroundTransparency(transp));
}

bool PyDbMText::useBackgroundColorOn() const
{
    return impObj()->useBackgroundColorOn();
}

void PyDbMText::setUseBackgroundColor(bool enable) const
{
    return PyThrowBadEs(impObj()->setUseBackgroundColor(enable));
}

void PyDbMText::setDynamicColumns(double width, double gutter, bool auto_height) const
{
    return PyThrowBadEs(impObj()->setDynamicColumns(width, gutter, auto_height));
}

void PyDbMText::setStaticColumns(double width, double gutter, int count) const
{
    return PyThrowBadEs(impObj()->setStaticColumns(width, gutter, count));
}

AcDbMText::ColumnType PyDbMText::getColumnType() const
{
    AcDbMText::ColumnType  val;
    PyThrowBadEs(impObj()->getColumnType(val));
    return val;
}

void PyDbMText::setColumnType(AcDbMText::ColumnType val) const
{
    return PyThrowBadEs(impObj()->setUseBackgroundColor(val));
}

bool PyDbMText::getColumnAutoHeight() const
{
    bool  val;
    PyThrowBadEs(impObj()->getColumnAutoHeight(val));
    return val;
}

void PyDbMText::setColumnAutoHeight(bool val) const
{
    return PyThrowBadEs(impObj()->setColumnAutoHeight(val));
}

int PyDbMText::getColumnCount() const
{
    int  val;
    PyThrowBadEs(impObj()->getColumnCount(val));
    return val;
}

void PyDbMText::setColumnCount(int val) const
{
    return PyThrowBadEs(impObj()->setColumnCount(val));
}

double PyDbMText::getColumnWidth() const
{
    double  val;
    PyThrowBadEs(impObj()->getColumnWidth(val));
    return val;
}

void PyDbMText::setColumnWidth(double val) const
{
    return PyThrowBadEs(impObj()->setColumnWidth(val));
}

double PyDbMText::getColumnGutterWidth() const
{
    double  val;
    PyThrowBadEs(impObj()->getColumnGutterWidth(val));
    return val;
}

void PyDbMText::setColumnGutterWidth(double val) const
{
    return PyThrowBadEs(impObj()->setColumnGutterWidth(val));
}

bool PyDbMText::getColumnFlowReversed() const
{
    bool  val;
    PyThrowBadEs(impObj()->getColumnFlowReversed(val));
    return val;
}

void PyDbMText::setColumnFlowReversed(bool val) const
{
    return PyThrowBadEs(impObj()->setColumnFlowReversed(val));
}

double PyDbMText::getColumnHeight(int idx) const
{
    double  val;
    PyThrowBadEs(impObj()->getColumnHeight(idx, val));
    return val;
}

void PyDbMText::setColumnHeight(int idx, double val) const
{
    return PyThrowBadEs(impObj()->setColumnHeight(idx, val));
}

void PyDbMText::convertFieldToText() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->convertFieldToText());
#endif
}

double PyDbMText::height() const
{
    return impObj()->height();
}

void PyDbMText::setHeight(double val) const
{
    return PyThrowBadEs(impObj()->setHeight(val));
}

boost::python::list PyDbMText::getFragments() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    impObj()->explodeFragments(AcDbMTextFragmentCallBack, &pylist, nullptr);
    return pylist;
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
    return PyDbObjectCloneFrom<PyDbMText, AcDbMText>(src);
}

PyDbMText PyDbMText::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbMText>(src);
}

AcDbMText* PyDbMText::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbMText*>(m_pyImp.get());
}

// preserve order!
int AcDbMTextFragmentCallBack(AcDbMTextFragment* frag, void* param)
{
    if (frag != nullptr && param != nullptr)
    {
        PyAutoLockGIL lock;
        boost::python::list* pylist = reinterpret_cast<boost::python::list*>(param);
        boost::python::list pysublist;

        pysublist.append(frag->location);
        pysublist.append(frag->normal);
        pysublist.append(frag->direction);

#if _GRXTARGET > 0 || _ZRXTARGET  > 0 || _BRXTARGET > 0
        if (frag->text != nullptr)
            pysublist.append(wstr_to_utf8(frag->text));
        else
            pysublist.append(boost::python::object());

        if (frag->font != nullptr)
            pysublist.append(wstr_to_utf8(frag->font));
        else
            pysublist.append(boost::python::object());

        if (frag->bigfont != nullptr)
            pysublist.append(wstr_to_utf8(frag->bigfont));
        else
            pysublist.append(boost::python::object());
#else
        if (!frag->msText.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msText));
        else
            pysublist.append(boost::python::object());

        if (!frag->msFont.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msFont));
        else
            pysublist.append(boost::python::object());

        if (!frag->msBigFont.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msBigFont));
        else
            pysublist.append(boost::python::object());
#endif

        pysublist.append(frag->extents);
        pysublist.append(frag->capsHeight);
        pysublist.append(frag->widthFactor);
        pysublist.append(frag->obliqueAngle);
        pysublist.append(frag->trackingFactor);
        pysublist.append(frag->color);
        pysublist.append(frag->stackTop);
        pysublist.append(frag->stackBottom);
        pysublist.append(frag->underlined);
        pysublist.append(frag->overlined);
        pysublist.append(frag->strikethrough);

        boost::python::list underPoints;
        underPoints.append(frag->underPoints[0]);
        underPoints.append(frag->underPoints[1]);
        pysublist.append(underPoints);

        boost::python::list overPoints;
        overPoints.append(frag->overPoints[0]);
        overPoints.append(frag->overPoints[1]);
        pysublist.append(overPoints);

        boost::python::list strikePoints;
        strikePoints.append(frag->strikePoints[0]);
        strikePoints.append(frag->strikePoints[1]);
        pysublist.append(strikePoints);

#if _GRXTARGET > 0 ||_ZRXTARGET > 0 || _BRXTARGET > 0
        if (frag->fontname != nullptr)
            pysublist.append(wstr_to_utf8(frag->fontname));
        else
            pysublist.append(boost::python::object());
#else
        if (!frag->msFontName.isEmpty())
            pysublist.append(wstr_to_utf8(frag->msFontName));
        else
            pysublist.append(boost::python::object());
#endif

        pysublist.append(frag->bold);
        pysublist.append(frag->italic);

        //
        pylist->append(pysublist);
    }
    return 1;
}

//-----------------------------------------------------------------------------------
//PyDbText
void makePyDbTextWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- position: PyGe.Point3d, text: str\n"
        "- position: PyGe.Point3d, text: str, height: float, rotation: float\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Text");
    class_<PyDbText, bases<PyDbEntity>>("Text")
        .def(init<>())
        .def(init<AcGePoint3d&, const std::string&>())
        .def(init<AcGePoint3d&, const std::string&, PyDbObjectId&, double, double>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("position", &PyDbText::position, DS.ARGS(9744))
        .def("setPosition", &PyDbText::setPosition, DS.ARGS({ "pos : PyGe.Point3d" }, 9754))
        .def("alignmentPoint", &PyDbText::alignmentPoint, DS.ARGS(9727))
        .def("setAlignmentPoint", &PyDbText::setAlignmentPoint, DS.ARGS({ "val : PyGe.Point3d" }, 9747))
        .def("isDefaultAlignment", &PyDbText::isDefaultAlignment, DS.ARGS(9735))
        .def("normal", &PyDbText::normal, DS.ARGS(9742))
        .def("setNormal", &PyDbText::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }, 9752))
        .def("direction", &PyDbText::direction, DS.ARGS(6859))
        .def("thickness", &PyDbText::thickness, DS.ARGS(9765))
        .def("setThickness", &PyDbText::setThickness, DS.ARGS({ "val : float" }, 9758))
        .def("oblique", &PyDbText::oblique, DS.ARGS(9743))
        .def("setOblique", &PyDbText::setOblique, DS.ARGS({ "val : float" }, 9753))
        .def("rotation", &PyDbText::rotation, DS.ARGS(9746))
        .def("setRotation", &PyDbText::setRotation, DS.ARGS({ "val : float" }, 9755))
        .def("height", &PyDbText::height, DS.ARGS(9732))
        .def("setHeight", &PyDbText::setHeight, DS.ARGS({ "val : float" }, 9749))
        .def("widthFactor", &PyDbText::widthFactor, DS.ARGS(9767))
        .def("setWidthFactor", &PyDbText::setWidthFactor, DS.ARGS({ "val : float" }, 9760))
        .def("textString", &PyDbText::textString, DS.ARGS(9762))
        .def("setTextString", &PyDbText::setTextString, DS.ARGS({ "val : str" }, 9756))
        .def("textStyle", &PyDbText::textStyle, DS.ARGS(9764))
        .def("setTextStyle", &PyDbText::setTextStyle, DS.ARGS({ "val : ObjectId" }, 9757))
        .def("isMirroredInX", &PyDbText::isMirroredInX, DS.ARGS(9736))
        .def("mirrorInX", &PyDbText::mirrorInX, DS.ARGS({ "val : bool" }, 9740))
        .def("isMirroredInY", &PyDbText::isMirroredInY, DS.ARGS(9737))
        .def("mirrorInY", &PyDbText::mirrorInY, DS.ARGS({ "val : bool" }, 9741))
        .def("horizontalMode", &PyDbText::horizontalMode, DS.ARGS(9734))
        .def("setHorizontalMode", &PyDbText::setHorizontalMode, DS.ARGS({ "val : PyDb.TextHorzMode" }, 9750))
        .def("verticalMode", &PyDbText::verticalMode, DS.ARGS(9766))
        .def("setVerticalMode", &PyDbText::setVerticalMode, DS.ARGS({ "val : PyDb.TextVertMode" }, 9759))
        .def("correctSpelling", &PyDbText::correctSpelling, DS.ARGS(9729))
        .def("adjustAlignment", &PyDbText::adjustAlignment, DS.ARGS({ "val : Database" }, 9726))
        .def("convertFieldToText", &PyDbText::convertFieldToText, DS.ARGS(9728))
        .def("hitTest", &PyDbText::hitTest, DS.ARGS({ "val : PyGe.Point3d" }, 9733))
        .def("getBoundingPoints", &PyDbText::getBoundingPoints, DS.ARGS(9730))
        .def("justification", &PyDbText::justification, DS.ARGS(9739))
        .def("setJustification", &PyDbText::setJustification, DS.ARGS({ "val : PyDb.TextAlignment" }, 9751))
        .def("className", &PyDbText::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbText::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbText::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbText::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbText::AcTextAlignment>("TextAlignment")
        .value("kTextAlignmentLeft", AcDbText::AcTextAlignment::kTextAlignmentLeft)
        .value("kTextAlignmentCenter", AcDbText::AcTextAlignment::kTextAlignmentCenter)
        .value("kTextAlignmentRight", AcDbText::AcTextAlignment::kTextAlignmentRight)
        .value("kTextAlignmentAligned", AcDbText::AcTextAlignment::kTextAlignmentAligned)
        .value("kTextAlignmentMiddle", AcDbText::AcTextAlignment::kTextAlignmentMiddle)
        .value("kTextAlignmentFit", AcDbText::AcTextAlignment::kTextAlignmentFit)
        .value("kTextAlignmentTopLeft", AcDbText::AcTextAlignment::kTextAlignmentTopLeft)
        .value("kTextAlignmentTopCenter", AcDbText::AcTextAlignment::kTextAlignmentTopCenter)
        .value("kTextAlignmentTopRight", AcDbText::AcTextAlignment::kTextAlignmentTopRight)
        .value("kTextAlignmentMiddleLeft", AcDbText::AcTextAlignment::kTextAlignmentMiddleLeft)
        .value("kTextAlignmentMiddleCenter", AcDbText::AcTextAlignment::kTextAlignmentMiddleCenter)
        .value("kTextAlignmentMiddleRight", AcDbText::AcTextAlignment::kTextAlignmentMiddleRight)
        .value("kTextAlignmentBottomLeft", AcDbText::AcTextAlignment::kTextAlignmentBottomLeft)
        .value("kTextAlignmentBottomCenter", AcDbText::AcTextAlignment::kTextAlignmentBottomCenter)
        .value("kTextAlignmentBottomRight", AcDbText::AcTextAlignment::kTextAlignmentBottomRight)
        .export_values()
        ;
}

PyDbText::PyDbText()
    : PyDbText::PyDbText(new AcDbText(), true)
{
}

PyDbText::PyDbText(const AcGePoint3d& position, const std::string& text)
    : PyDbText::PyDbText(new AcDbText(position, utf8_to_wstr(text).c_str()), true)
{
}

PyDbText::PyDbText(const AcGePoint3d& position, const std::string& text, PyDbObjectId& style, double height, double rotation)
    : PyDbText::PyDbText(new AcDbText(position, utf8_to_wstr(text).c_str(), style.m_id, height, rotation), true)
{
}

PyDbText::PyDbText(const PyDbObjectId& id)
    : PyDbText(id, AcDb::OpenMode::kForRead)
{
}

PyDbText::PyDbText(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbText>(id, mode), false)
{
}

PyDbText::PyDbText(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbText(openAcDbObject<AcDbText>(id, mode, erased), false)
{
}

PyDbText::PyDbText(AcDbText* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

AcGePoint3d PyDbText::position() const
{
    return impObj()->position();
}

void PyDbText::setPosition(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

AcGePoint3d PyDbText::alignmentPoint() const
{
    return impObj()->alignmentPoint();
}

void PyDbText::setAlignmentPoint(const AcGePoint3d& val) const
{
    return PyThrowBadEs(impObj()->setAlignmentPoint(val));
}

Adesk::Boolean PyDbText::isDefaultAlignment() const
{
    return impObj()->isDefaultAlignment();
}

AcGeVector3d PyDbText::normal() const
{
    return impObj()->normal();
}

void PyDbText::setNormal(const AcGeVector3d& val) const
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

AcGeVector3d PyDbText::direction() const
{
    AcGeVector3d v = AcGeVector3d::kXAxis;
    return v.rotateBy(impObj()->rotation(), impObj()->normal());
}

double PyDbText::thickness() const
{
    return impObj()->thickness();
}

void PyDbText::setThickness(double val) const
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

double PyDbText::oblique() const
{
    return impObj()->oblique();
}

void PyDbText::setOblique(double val) const
{
    return PyThrowBadEs(impObj()->setOblique(val));
}

double PyDbText::rotation() const
{
    return impObj()->rotation();
}

void PyDbText::setRotation(double val) const
{
    return PyThrowBadEs(impObj()->setRotation(val));
}

double PyDbText::height() const
{
    return impObj()->height();
}

void PyDbText::setHeight(double val) const
{
    return PyThrowBadEs(impObj()->setHeight(val));
}

double PyDbText::widthFactor() const
{
    return impObj()->widthFactor();
}

void PyDbText::setWidthFactor(double val) const
{
    return PyThrowBadEs(impObj()->setWidthFactor(val));
}

std::string PyDbText::textString() const
{
    return wstr_to_utf8(impObj()->textStringConst());
}

void PyDbText::setTextString(const std::string& val) const
{
    return PyThrowBadEs(impObj()->setTextString(utf8_to_wstr(val).c_str()));
}

PyDbObjectId PyDbText::textStyle() const
{
    return PyDbObjectId(impObj()->textStyle());
}

void PyDbText::setTextStyle(const PyDbObjectId& val) const
{
    return PyThrowBadEs(impObj()->setTextStyle(val.m_id));
}

Adesk::Boolean PyDbText::isMirroredInX() const
{
    return impObj()->isMirroredInX();
}

void PyDbText::mirrorInX(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->mirrorInX(val));
}

Adesk::Boolean PyDbText::isMirroredInY() const
{
    return impObj()->isMirroredInY();
}

void PyDbText::mirrorInY(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->mirrorInY(val));
}

AcDb::TextHorzMode PyDbText::horizontalMode() const
{
    return impObj()->horizontalMode();
}

void PyDbText::setHorizontalMode(AcDb::TextHorzMode val) const
{
    return PyThrowBadEs(impObj()->setHorizontalMode(val));
}

AcDb::TextVertMode PyDbText::verticalMode() const
{
    return impObj()->verticalMode();
}

void PyDbText::setVerticalMode(AcDb::TextVertMode val) const
{
    return PyThrowBadEs(impObj()->setVerticalMode(val));
}

int PyDbText::correctSpelling() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->correctSpelling();
#endif
}

void PyDbText::adjustAlignment(const PyDbDatabase& pDb) const
{
    return PyThrowBadEs(impObj()->adjustAlignment(pDb.impObj()));
}

void PyDbText::convertFieldToText() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->convertFieldToText());
#endif
}

bool PyDbText::hitTest(const AcGePoint3d& ptHit) const
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)    
    throw PyNotimplementedByHost();
#else
    return impObj()->hitTest(ptHit);
#endif
}

boost::python::list PyDbText::getBoundingPoints() const
{
#if defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcGePoint3dArray boundingPoints;
    impObj()->getBoundingPoints(boundingPoints);
    if (boundingPoints.length() == 0)
    {
        PyThrowBadEs(impObj()->draw());
        impObj()->getBoundingPoints(boundingPoints);
    }
    return Point3dArrayToPyList(boundingPoints);
#endif
}

AcDbText::AcTextAlignment PyDbText::justification() const
{
    return impObj()->justification();
}

void PyDbText::setJustification(AcDbText::AcTextAlignment val) const
{
    return PyThrowBadEs(impObj()->setJustification(val));
}

std::string PyDbText::className()
{
    return "AcDbText";
}

PyRxClass PyDbText::desc()
{
    return PyRxClass(AcDbText::desc(), false);
}

PyDbText PyDbText::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbText, AcDbText>(src);
}

PyDbText PyDbText::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbText>(src);
}

AcDbText* PyDbText::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbText*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbAttributeDefinition
void makePyDbAttributeDefinitionWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- position: PyGe.Point3d, text: str, tag: str, prompt: str, styleid: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.AttributeDefinition");
    class_<PyDbAttributeDefinition, bases<PyDbText>>("AttributeDefinition")
        .def(init<>())
        .def(init<const AcGePoint3d&, const std::string&, const std::string&, const std::string&, const PyDbObjectId&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("prompt", &PyDbAttributeDefinition::prompt, DS.ARGS(2395))
        .def("setPrompt", &PyDbAttributeDefinition::setPrompt, DS.ARGS({ "val : str" }, 2404))
        .def("tag", &PyDbAttributeDefinition::tag, DS.ARGS(2408))
        .def("setTag", &PyDbAttributeDefinition::setTag, DS.ARGS({ "val : str" }, 2405))
        .def("isInvisible", &PyDbAttributeDefinition::isInvisible, DS.ARGS(2390))
        .def("setInvisible", &PyDbAttributeDefinition::setInvisible, DS.ARGS({ "val : bool" }, 2399))
        .def("isConstant", &PyDbAttributeDefinition::isConstant, DS.ARGS(2389))
        .def("setConstant", &PyDbAttributeDefinition::setConstant, DS.ARGS({ "val : bool" }, 2397))
        .def("isVerifiable", &PyDbAttributeDefinition::isVerifiable, DS.ARGS(2393))
        .def("setVerifiable", &PyDbAttributeDefinition::setVerifiable, DS.ARGS({ "val : bool" }, 2406))
        .def("isPreset", &PyDbAttributeDefinition::isPreset, DS.ARGS(2392))
        .def("setPreset", &PyDbAttributeDefinition::setPreset, DS.ARGS({ "val : bool" }, 2403))
        .def("fieldLength", &PyDbAttributeDefinition::fieldLength, DS.ARGS(2386))
        .def("setFieldLength", &PyDbAttributeDefinition::setFieldLength, DS.ARGS({ "val : int" }, 2398))
        .def("adjustAlignment", &PyDbAttributeDefinition::adjustAlignment, DS.ARGS({ "val : Database" }, 2384))
        .def("lockPositionInBlock", &PyDbAttributeDefinition::lockPositionInBlock, DS.ARGS(2394))
        .def("setLockPositionInBlock", &PyDbAttributeDefinition::setLockPositionInBlock, DS.ARGS({ "val : bool" }, 2400))
        .def("isMTextAttributeDefinition", &PyDbAttributeDefinition::isMTextAttributeDefinition, DS.ARGS(2391))
        .def("convertIntoMTextAttributeDefinition", &PyDbAttributeDefinition::convertIntoMTextAttributeDefinition, DS.ARGS({ "val : bool" }, 2385))
        .def("updateMTextAttributeDefinition", &PyDbAttributeDefinition::updateMTextAttributeDefinition, DS.ARGS(2410))
        .def("getMTextAttributeDefinition", &PyDbAttributeDefinition::getMTextAttributeDefinition, DS.ARGS(2387))
        .def("setMTextAttributeDefinition", &PyDbAttributeDefinition::setMTextAttributeDefinition, DS.ARGS({ "val : MText" }, 2401))
        .def("className", &PyDbAttributeDefinition::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAttributeDefinition::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbAttributeDefinition::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAttributeDefinition::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbAttributeDefinition::PyDbAttributeDefinition()
    : PyDbText(new AcDbAttributeDefinition(), true)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(const AcGePoint3d& position, const std::string& text, const std::string& tag, const std::string& prompt, const PyDbObjectId& style)
    : PyDbText(new AcDbAttributeDefinition(position, utf8_to_wstr(text).c_str(), utf8_to_wstr(tag).c_str(), utf8_to_wstr(prompt).c_str(), style.m_id), true)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(AcDbAttributeDefinition* ptr, bool autoDelete)
    : PyDbText(ptr, autoDelete)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbText(openAcDbObject<AcDbAttributeDefinition>(id, mode), false)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(const PyDbObjectId& id)
    : PyDbAttributeDefinition(id, AcDb::OpenMode::kForRead)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbText(openAcDbObject<AcDbAttributeDefinition>(id, mode, erased), false)
{

}

std::string PyDbAttributeDefinition::prompt() const
{
    return wstr_to_utf8(impObj()->promptConst());
}

void PyDbAttributeDefinition::setPrompt(const std::string& val) const
{
    return PyThrowBadEs(impObj()->setPrompt(utf8_to_wstr(val).c_str()));
}

std::string PyDbAttributeDefinition::tag() const
{
    return wstr_to_utf8(impObj()->tagConst());
}

void PyDbAttributeDefinition::setTag(const std::string& val) const
{
    return PyThrowBadEs(impObj()->setTag(utf8_to_wstr(val).c_str()));
}

Adesk::Boolean PyDbAttributeDefinition::isInvisible() const
{
    return impObj()->isInvisible();
}

void PyDbAttributeDefinition::setInvisible(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->setInvisible(val));
}

Adesk::Boolean PyDbAttributeDefinition::isConstant() const
{
    return impObj()->isConstant();
}

void PyDbAttributeDefinition::setConstant(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->setConstant(val));
}

Adesk::Boolean PyDbAttributeDefinition::isVerifiable() const
{
    return impObj()->isVerifiable();
}

void PyDbAttributeDefinition::setVerifiable(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->setVerifiable(val));
}

Adesk::Boolean PyDbAttributeDefinition::isPreset() const
{
    return impObj()->isPreset();
}

void PyDbAttributeDefinition::setPreset(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->setPreset(val));
}

Adesk::UInt16 PyDbAttributeDefinition::fieldLength() const
{
    return impObj()->fieldLength();
}

void PyDbAttributeDefinition::setFieldLength(Adesk::UInt16 val) const
{
    return PyThrowBadEs(impObj()->setFieldLength(val));
}

void PyDbAttributeDefinition::adjustAlignment(const PyDbDatabase& pDb) const
{
    return PyThrowBadEs(impObj()->adjustAlignment(pDb.impObj()));
}

bool PyDbAttributeDefinition::lockPositionInBlock() const
{
    return impObj()->lockPositionInBlock();
}

void PyDbAttributeDefinition::setLockPositionInBlock(bool bValue) const
{
    return PyThrowBadEs(impObj()->setLockPositionInBlock(bValue));
}

bool PyDbAttributeDefinition::isMTextAttributeDefinition() const
{
    return impObj()->isMTextAttributeDefinition();
}

PyDbMText PyDbAttributeDefinition::getMTextAttributeDefinition() const
{
    // [BRX - SR 192611] this should be a clone and be deleted
    AcDbMText* ptr = impObj()->getMTextAttributeDefinition();
    if (ptr == nullptr)
        throw PyNullObject(std::source_location::current());
#if defined(_BRXTARGET250)
    return PyDbMText(static_cast<AcDbMText*>(ptr->clone()), true);
#else
    return PyDbMText(ptr, true);
#endif
}

void PyDbAttributeDefinition::setMTextAttributeDefinition(const PyDbMText& mt) const
{
    // clones are missing setMTextAttributeDefinitionConst
#if defined(_BRXTARGET250)
    // [BRX - SR 192611] this should crash BricsCAD
    PyThrowBadEs(impObj()->setMTextAttributeDefinition(mt.impObj()));
#elif defined(_GRXTARGET250) || defined(_ZRXTARGET260)  
    PyThrowBadEs(impObj()->setMTextAttributeDefinition(static_cast<AcDbMText*>(mt.impObj()->clone())));
#else
    PyThrowBadEs(impObj()->setMTextAttributeDefinitionConst(mt.impObj()));
#endif
}

void PyDbAttributeDefinition::convertIntoMTextAttributeDefinition(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->convertIntoMTextAttributeDefinition(val));
}

void PyDbAttributeDefinition::updateMTextAttributeDefinition() const
{
    return PyThrowBadEs(impObj()->updateMTextAttributeDefinition());
}

std::string PyDbAttributeDefinition::className()
{
    return "AcDbAttributeDefinition";
}

PyRxClass PyDbAttributeDefinition::desc()
{
    return PyRxClass(AcDbAttributeDefinition::desc(), false);
}

PyDbAttributeDefinition PyDbAttributeDefinition::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbAttributeDefinition, AcDbAttributeDefinition>(src);
}

PyDbAttributeDefinition PyDbAttributeDefinition::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbAttributeDefinition>(src);
}

AcDbAttributeDefinition* PyDbAttributeDefinition::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAttributeDefinition*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbAttribute
void makePyDbAttributeWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- position: PyGe.Point3d, text: str, tag: str, styleid: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view setAttributeFromBlockOverloads = "Overloads:\n"
        "- blkXform: PyGe.Matrix3d\n"
        "- pAttdef: PyDb.AttributeDefinition, blkXform: PyGe.Matrix3d\n";

    PyDocString DS("PyDb.AttributeReference");
    class_<PyDbAttribute, bases<PyDbText>>("AttributeReference")
        .def(init<>())
        .def(init<const AcGePoint3d&, const std::string&, const std::string&, const PyDbObjectId&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("tag", &PyDbAttribute::tag, DS.ARGS(2432))
        .def("setTag", &PyDbAttribute::setTag, DS.ARGS({ "val : str" }, 2430))
        .def("isInvisible", &PyDbAttribute::isInvisible, DS.ARGS(2418))
        .def("setInvisible", &PyDbAttribute::setInvisible, DS.ARGS({ "val : bool" }, 2426))
        .def("isConstant", &PyDbAttribute::isConstant, DS.ARGS(2417))
        .def("isVerifiable", &PyDbAttribute::isVerifiable, DS.ARGS(2422))
        .def("isPreset", &PyDbAttribute::isPreset, DS.ARGS(2420))
        .def("fieldLength", &PyDbAttribute::fieldLength, DS.ARGS(2414))
        .def("setFieldLength", &PyDbAttribute::setFieldLength, DS.ARGS({ "val : int" }, 2425))
        .def("setAttributeFromBlock", &PyDbAttribute::setAttributeFromBlock1)
        .def("setAttributeFromBlock", &PyDbAttribute::setAttributeFromBlock2, DS.OVRL(setAttributeFromBlockOverloads, 2424))
        .def("lockPositionInBlock", &PyDbAttribute::lockPositionInBlock, DS.ARGS(2423))
        .def("setLockPositionInBlock", &PyDbAttribute::setLockPositionInBlock, DS.ARGS({ "val : bool" }, 2427))
        .def("isMTextAttribute", &PyDbAttribute::isMTextAttribute, DS.ARGS(2419))
        .def("getMTextAttribute", &PyDbAttribute::getMTextAttribute, DS.ARGS(2415))
        .def("setMTextAttribute", &PyDbAttribute::setMTextAttribute, DS.ARGS({ "val : MText" }, 2428))
        .def("convertIntoMTextAttribute", &PyDbAttribute::convertIntoMTextAttribute, DS.ARGS({ "val : bool" }, 2413))
        .def("updateMTextAttribute", &PyDbAttribute::updateMTextAttribute, DS.ARGS(2434))
        .def("isReallyLocked", &PyDbAttribute::isReallyLocked, DS.ARGS(2421))
        .def("className", &PyDbAttribute::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAttribute::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbAttribute::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAttribute::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbAttribute::PyDbAttribute()
    : PyDbText(new AcDbAttribute(), true)
{
}

PyDbAttribute::PyDbAttribute(const AcGePoint3d& position, const std::string& text, const std::string& tag, const PyDbObjectId& style)
    : PyDbText(new AcDbAttribute(position, utf8_to_wstr(text).c_str(), utf8_to_wstr(tag).c_str(), style.m_id), true)
{
}

PyDbAttribute::PyDbAttribute(AcDbAttribute* ptr, bool autoDelete)
    : PyDbText(ptr, autoDelete)
{
}

PyDbAttribute::PyDbAttribute(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbText(openAcDbObject<AcDbAttribute>(id, mode), false)
{
}

PyDbAttribute::PyDbAttribute(const PyDbObjectId& id)
    : PyDbAttribute(id, AcDb::OpenMode::kForRead)
{
}

PyDbAttribute::PyDbAttribute(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbText(openAcDbObject<AcDbAttribute>(id, mode, erased), false)
{
}

std::string PyDbAttribute::tag() const
{
    return wstr_to_utf8(impObj()->tagConst());
}

void PyDbAttribute::setTag(const std::string& val) const
{
    return PyThrowBadEs(impObj()->setTag(utf8_to_wstr(val).c_str()));
}

Adesk::Boolean PyDbAttribute::isInvisible() const
{
    return impObj()->isInvisible();
}

void PyDbAttribute::setInvisible(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->setInvisible(val));
}

Adesk::Boolean PyDbAttribute::isConstant() const
{
    return impObj()->isConstant();
}

Adesk::Boolean PyDbAttribute::isVerifiable() const
{
    return impObj()->isVerifiable();
}

Adesk::Boolean PyDbAttribute::isPreset() const
{
    return impObj()->isPreset();
}

Adesk::UInt16 PyDbAttribute::fieldLength() const
{
    return impObj()->isPreset();
}

void PyDbAttribute::setFieldLength(Adesk::UInt16 val) const
{
    return PyThrowBadEs(impObj()->setFieldLength(val));
}

void PyDbAttribute::setAttributeFromBlock1(const AcGeMatrix3d& blkXform) const
{
    return PyThrowBadEs(impObj()->setAttributeFromBlock(blkXform));
}

void PyDbAttribute::setAttributeFromBlock2(const PyDbAttributeDefinition& pAttdef, const AcGeMatrix3d& blkXform) const
{
    return PyThrowBadEs(impObj()->setAttributeFromBlock(pAttdef.impObj(), blkXform));
}

bool PyDbAttribute::lockPositionInBlock() const
{
    return impObj()->lockPositionInBlock();
}

void PyDbAttribute::setLockPositionInBlock(bool bValue) const
{
    return PyThrowBadEs(impObj()->setLockPositionInBlock(bValue));
}

bool PyDbAttribute::isMTextAttribute() const
{
    return impObj()->isMTextAttribute();
}

PyDbMText PyDbAttribute::getMTextAttribute() const
{
    return PyDbMText(impObj()->getMTextAttribute(), true);
}

void PyDbAttribute::setMTextAttribute(PyDbMText& mt) const
{
    return PyThrowBadEs(impObj()->setMTextAttribute(mt.impObj()));
}

void PyDbAttribute::convertIntoMTextAttribute(Adesk::Boolean val) const
{
    return PyThrowBadEs(impObj()->convertIntoMTextAttribute(val));
}

void PyDbAttribute::updateMTextAttribute() const
{
    return PyThrowBadEs(impObj()->updateMTextAttribute());
}

bool PyDbAttribute::isReallyLocked() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->isReallyLocked();
#endif
}

std::string PyDbAttribute::className()
{
    return "AcDbAttribute";
}

PyRxClass PyDbAttribute::desc()
{
    return PyRxClass(AcDbAttribute::desc(), false);
}

PyDbAttribute PyDbAttribute::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbAttribute, AcDbAttribute>(src);
}

PyDbAttribute PyDbAttribute::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbAttribute>(src);
}

AcDbAttribute* PyDbAttribute::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAttribute*>(m_pyImp.get());
}