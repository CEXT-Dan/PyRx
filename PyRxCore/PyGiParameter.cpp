#include "stdafx.h"
#include "PyGiParameter.h"
#include "PyGiCommonDraw.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
// PyGiParameter
void makePyGiParameterWrapper()
{
    PyDocString DS("Parameter");
    class_<PyGiParameter, bases<PyRxCopyOnWriteObject>>("Parameter", no_init)
        .def("cast", &PyGiParameter::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiParameter::className).staticmethod("className")
        .def("desc", &PyGiParameter::desc).staticmethod("desc")
        ;
}

PyGiParameter::PyGiParameter(AcGiParameter* ptr, bool autoDelete)
    : PyRxCopyOnWriteObject(ptr, autoDelete)
{
}

PyRxClass PyGiParameter::desc()
{
    return PyRxClass(AcGiParameter::desc(), false);
}

std::string PyGiParameter::className()
{
    return "AcGiParameter";
}

PyGiParameter PyGiParameter::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiParameter>(src);
}

AcGiParameter* PyGiParameter::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiParameter*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiEdgeData
void makePyGiEdgeDataWrapper()
{
    PyDocString DS("EdgeData");
    class_<PyGiEdgeData, bases<PyGiParameter>>("EdgeData")
        .def(init<>())
        .def("cast", &PyGiEdgeData::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiEdgeData::className).staticmethod("className")
        .def("desc", &PyGiEdgeData::desc).staticmethod("desc")
        ;
}

PyGiEdgeData::PyGiEdgeData()
    : PyGiEdgeData(new AcGiEdgeData(), true)
{
}

PyGiEdgeData::PyGiEdgeData(AcGiEdgeData* ptr, bool autoDelete)
    : PyGiParameter(ptr, autoDelete)
{
}

PyRxClass PyGiEdgeData::desc()
{
    return PyRxClass(AcGiEdgeData::desc(), false);
}

std::string PyGiEdgeData::className()
{
    return "AcGiEdgeData";
}

PyGiEdgeData PyGiEdgeData::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiEdgeData>(src);
}

AcGiEdgeData* PyGiEdgeData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiEdgeData*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiFaceData
void makePyGiFaceDataWrapper()
{
    PyDocString DS("FaceData");
    class_<PyGiFaceData, bases<PyGiParameter>>("FaceData")
        .def(init<>())
        .def("cast", &PyGiFaceData::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiFaceData::className).staticmethod("className")
        .def("desc", &PyGiFaceData::desc).staticmethod("desc")
        ;
}

PyGiFaceData::PyGiFaceData()
    : PyGiParameter(new AcGiFaceData(), true)
{
}

PyGiFaceData::PyGiFaceData(AcGiFaceData* ptr, bool autoDelete)
    : PyGiParameter(ptr, autoDelete)
{
}

PyRxClass PyGiFaceData::desc()
{
    return PyRxClass(AcGiFaceData::desc(), false);
}

std::string PyGiFaceData::className()
{
    return "AcGiFaceData";
}

PyGiFaceData PyGiFaceData::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiFaceData>(src);
}

AcGiFaceData* PyGiFaceData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiFaceData*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiMapper
void makePyGiMapperWrapper()
{
    PyDocString DS("Mapper");
    class_<PyGiMapper, bases<PyGiParameter>>("Mapper")
        .def(init<>())
        .def("cast", &PyGiMapper::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiMapper::className).staticmethod("className")
        .def("desc", &PyGiMapper::desc).staticmethod("desc")
        ;
}

PyGiMapper::PyGiMapper()
    : PyGiMapper(new AcGiMapper(), true)
{
}

PyGiMapper::PyGiMapper(AcGiMapper* ptr, bool autoDelete)
    : PyGiParameter(ptr, autoDelete)
{
}

PyRxClass PyGiMapper::desc()
{
    return PyRxClass(AcGiMapper::desc(), false);
}

std::string PyGiMapper::className()
{
    return "AcGiMapper";
}

PyGiMapper PyGiMapper::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiMapper>(src);
}

AcGiMapper* PyGiMapper::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiMapper*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiPolyline
void makePyGiPolylineWrapper()
{
    PyDocString DS("Polyline");
#if defined(_BRXTARGET270)
    class_<PyGiPolyline, bases<PyGiParameter>>("Polyline")
#else
    class_<PyGiPolyline, bases<PyRxObject>>("Polyline")
#endif
        .def(init<>())
        .def("cast", &PyGiPolyline::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiPolyline::className).staticmethod("className")
        .def("desc", &PyGiPolyline::desc).staticmethod("desc")
        ;
}

PyGiPolyline::PyGiPolyline()
    : PyGiPolyline(new AcGiPolyline(), true)
{
}

PyGiPolyline::PyGiPolyline(AcGiPolyline* ptr, bool autoDelete)
#if defined(_BRXTARGET270)
    : PyRxObject(ptr, autoDelete, false)
#else
    : PyGiParameter(ptr, autoDelete)
#endif
{
}

PyRxClass PyGiPolyline::desc()
{
    return PyRxClass(AcGiPolyline::desc(), false);
}

std::string PyGiPolyline::className()
{
    return "AcGiPolyline";
}

PyGiPolyline PyGiPolyline::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiPolyline>(src);
}

AcGiPolyline* PyGiPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiPolyline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiTextStyle
void makePyGiTextStyleWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- db: PyDb.Database\n"
        "- fontName:str, bigFontName:str, textSize:float, xScale:float, obliqueAngle:float, trPercent:float, isBackward:bool, isUpsideDown:bool, isVertical:bool, isOverlined:bool, isUnderlined:bool\n"
        "- fontName:str, bigFontName:str, textSize:float, xScale:float, obliqueAngle:float, trPercent:float, isBackward:bool, isUpsideDown:bool, isVertical:bool, isOverlined:bool, isUnderlined:bool, isStrikethrough:bool, styleName:str\n";

    PyDocString DS("TextStyle");
    class_<PyGiTextStyle, bases<PyGiParameter>>("TextStyle")
        .def(init<>())
        .def(init<const PyDbDatabase&>())
        .def(init< const std::string&, const std::string&, const double, const double, const double, const double,
            const Adesk::Boolean, const Adesk::Boolean, const Adesk::Boolean, const Adesk::Boolean, const Adesk::Boolean >())
        .def(init<const std::string&, const std::string&, const double, const double, const double, const double,
            const Adesk::Boolean, const Adesk::Boolean, const Adesk::Boolean, const Adesk::Boolean, const Adesk::Boolean, const Adesk::Boolean, const std::string&>(DS.CTOR(ctords)))
        .def("loadStyleRec", &PyGiTextStyle::loadStyleRec1)
        .def("loadStyleRec", &PyGiTextStyle::loadStyleRec2, DS.ARGS({ "db: PyDb.Database" }))
        .def("setTextSize", &PyGiTextStyle::setTextSize, DS.ARGS({ "size: float" }))
        .def("setXScale", &PyGiTextStyle::setXScale, DS.ARGS({ "xScale: float" }))
        .def("setObliquingAngle", &PyGiTextStyle::setObliquingAngle, DS.ARGS({ "obliquingAngle: float" }))
        .def("setTrackingPercent", &PyGiTextStyle::setTrackingPercent, DS.ARGS({ "trPercent: float" }))
        .def("setBackward", &PyGiTextStyle::setBackward, DS.ARGS({ "isBackward: bool" }))
        .def("setUpsideDown", &PyGiTextStyle::setUpsideDown, DS.ARGS({ "isUpsideDown: bool" }))
        .def("setVertical", &PyGiTextStyle::setVertical, DS.ARGS({ "isVertical: bool" }))
        .def("setUnderlined", &PyGiTextStyle::setUnderlined, DS.ARGS({ "isUnderlined: bool" }))
        .def("setOverlined", &PyGiTextStyle::setOverlined, DS.ARGS({ "isOverlined: bool" }))
        .def("setStrikethrough", &PyGiTextStyle::setStrikethrough, DS.ARGS({ "isStrikethrough: bool" }))
        .def("setFileName", &PyGiTextStyle::setFileName, DS.ARGS({ "fontName: str" }))
        .def("setBigFontFileName", &PyGiTextStyle::setBigFontFileName, DS.ARGS({ "bigFontFileName: str" }))
        .def("setStyleName", &PyGiTextStyle::setStyleName, DS.ARGS({ "val: str" }))
        .def("setPreLoaded", &PyGiTextStyle::setPreLoaded, DS.ARGS({ "val: bool" }))
        .def("setTrackKerning", &PyGiTextStyle::setTrackKerning, DS.ARGS({ "trackPercent: float" }))
        .def("textSize", &PyGiTextStyle::textSize, DS.ARGS())
        .def("xScale", &PyGiTextStyle::xScale, DS.ARGS())
        .def("obliquingAngle", &PyGiTextStyle::obliquingAngle, DS.ARGS())
        .def("trackingPercent", &PyGiTextStyle::trackingPercent, DS.ARGS())
        .def("isBackward", &PyGiTextStyle::isBackward, DS.ARGS())
        .def("isUpsideDown", &PyGiTextStyle::isUpsideDown, DS.ARGS())
        .def("isVertical", &PyGiTextStyle::isVertical, DS.ARGS())
        .def("isUnderlined", &PyGiTextStyle::isUnderlined, DS.ARGS())
        .def("isOverlined", &PyGiTextStyle::isOverlined, DS.ARGS())
        .def("isStrikethrough", &PyGiTextStyle::isStrikethrough, DS.ARGS())
        .def("preLoaded", &PyGiTextStyle::preLoaded, DS.ARGS())
        .def("fileName", &PyGiTextStyle::fileName, DS.ARGS())
        .def("bigFontFileName", &PyGiTextStyle::bigFontFileName, DS.ARGS())
        .def("styleName", &PyGiTextStyle::styleName, DS.ARGS())
        .def("extents", &PyGiTextStyle::extents1, DS.ARGS({ "pStr: str", "penups: bool", "len: int", "raw: bool" }))
        .def("extents", &PyGiTextStyle::extents2, DS.ARGS({ "pStr: str", "penups: bool", "len: int", "raw: bool", "ctxt: PyGi.WorldDraw" }))
        .def("setFont", &PyGiTextStyle::setFont, DS.ARGS({ "pTypeface: str", "bold: bool", "italic: bool", "charset: PyGi.Charset", "pitch: PyGi.FontPitch", "family: PyGi.FontFamily" }))
        .def("font", &PyGiTextStyle::font, DS.ARGS())
        .def("extentsBox", &PyGiTextStyle::extentsBox1, DS.ARGS({ "pStr: str", "penups: bool", "len: int", "raw: bool" }))
        .def("extentsBox", &PyGiTextStyle::extentsBox2, DS.ARGS({ "pStr: str", "penups: bool", "len: int", "raw: bool", "ctxt: PyGi.WorldDraw" }))
        .def("cast", &PyGiTextStyle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiTextStyle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyGiTextStyle::desc, DS.SARGS()).staticmethod("desc")
        ;
}

PyGiTextStyle::PyGiTextStyle()
    : PyGiTextStyle(new AcGiTextStyle(), true)
{
}

PyGiTextStyle::PyGiTextStyle(const PyDbDatabase& db)
#if defined(_BRXTARGET270)
    : PyGiTextStyle(new AcGiTextStyle(), true)
#else
    : PyGiTextStyle(new AcGiTextStyle(db.impObj()), true)
#endif
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#endif
}

PyGiTextStyle::PyGiTextStyle(
    const std::string& fontName,
    const std::string& bigFontName,
    const double textSize,
    const double xScale,
    const double obliqueAngle,
    const double trPercent,
    const Adesk::Boolean isBackward,
    const Adesk::Boolean isUpsideDown,
    const Adesk::Boolean isVertical,
    const Adesk::Boolean isOverlined,
    const Adesk::Boolean isUnderlined)
    : PyGiTextStyle(new AcGiTextStyle(
        utf8_to_wstr(fontName).c_str(),
        utf8_to_wstr(bigFontName).c_str(),
        textSize,
        xScale,
        obliqueAngle,
        trPercent,
        isBackward,
        isUpsideDown,
        isVertical,
        isOverlined,
        isUnderlined), true)
{
}

PyGiTextStyle::PyGiTextStyle(
    const std::string& fontName,
    const std::string& bigFontName,
    const double textSize,
    const double xScale,
    const double obliqueAngle,
    const double trPercent,
    const Adesk::Boolean isBackward,
    const Adesk::Boolean isUpsideDown,
    const Adesk::Boolean isVertical,
    const Adesk::Boolean isOverlined,
    const Adesk::Boolean isUnderlined,
    const Adesk::Boolean isStrikethrough,
    const std::string& styleName)
#if defined(_BRXTARGET270)
    : PyGiTextStyle(new AcGiTextStyle(
        utf8_to_wstr(fontName).c_str(),
        utf8_to_wstr(bigFontName).c_str(),
        textSize,
        xScale,
        obliqueAngle,
        trPercent,
        isBackward,
        isUpsideDown,
        isVertical,
        isOverlined,
        isUnderlined,
        utf8_to_wstr(styleName).c_str()), true)
#else
    : PyGiTextStyle(new AcGiTextStyle(
        utf8_to_wstr(fontName).c_str(),
        utf8_to_wstr(bigFontName).c_str(),
        textSize,
        xScale,
        obliqueAngle,
        trPercent,
        isBackward,
        isUpsideDown,
        isVertical,
        isOverlined,
        isUnderlined,
        isStrikethrough,
        utf8_to_wstr(styleName).c_str()), true)
#endif
{
#if defined(_BRXTARGET270)
    impObj()->setStrikethrough(isStrikethrough);
#endif
}

PyGiTextStyle::PyGiTextStyle(AcGiTextStyle* ptr, bool autoDelete)
    : PyGiParameter(ptr, autoDelete)
{
}

int PyGiTextStyle::loadStyleRec1() const
{
    return impObj()->loadStyleRec();
}

int PyGiTextStyle::loadStyleRec2(PyDbDatabase& pDb) const
{
    return impObj()->loadStyleRec(pDb.impObj());
}

void PyGiTextStyle::setTextSize(const double size) const
{
    impObj()->setTextSize(size);
}

void PyGiTextStyle::setXScale(const double xScale) const
{
    impObj()->setXScale(xScale);
}

void PyGiTextStyle::setObliquingAngle(const double obliquingAngle) const
{
    impObj()->setObliquingAngle(obliquingAngle);
}

void PyGiTextStyle::setTrackingPercent(const double trPercent) const
{
    impObj()->setTrackingPercent(trPercent);
}

void PyGiTextStyle::setBackward(const Adesk::Boolean isBackward) const
{
    impObj()->setBackward(isBackward);
}

void PyGiTextStyle::setUpsideDown(const Adesk::Boolean isUpsideDown) const
{
    impObj()->setUpsideDown(isUpsideDown);
}

void PyGiTextStyle::setVertical(const Adesk::Boolean isVertical) const
{
    impObj()->setVertical(isVertical);
}

void PyGiTextStyle::setUnderlined(const Adesk::Boolean isUnderlined) const
{
    impObj()->setUnderlined(isUnderlined);
}

void PyGiTextStyle::setOverlined(const Adesk::Boolean isOverlined) const
{
    impObj()->setOverlined(isOverlined);
}

void PyGiTextStyle::setStrikethrough(const Adesk::Boolean isStrikethrough) const
{
    impObj()->setStrikethrough(isStrikethrough);
}

void PyGiTextStyle::setFileName(const std::string& fontName) const
{
    impObj()->setFileName(AsWStr(fontName));
}

void PyGiTextStyle::setBigFontFileName(const std::string& bigFontFileName) const
{
    impObj()->setBigFontFileName(AsWStr(bigFontFileName));
}

void PyGiTextStyle::setStyleName(const std::string& val) const
{
    PyThrowBadEs(impObj()->setStyleName(AsWStr(val)));
}

double PyGiTextStyle::textSize() const
{
    return impObj()->textSize();
}

double PyGiTextStyle::xScale() const
{
    return impObj()->xScale();
}

double PyGiTextStyle::obliquingAngle() const
{
    return impObj()->obliquingAngle();
}

double PyGiTextStyle::trackingPercent() const
{
    return impObj()->trackingPercent();
}

Adesk::Boolean PyGiTextStyle::isBackward() const
{
    return impObj()->isBackward();
}

Adesk::Boolean PyGiTextStyle::isUpsideDown() const
{
    return impObj()->isUpsideDown();
}

Adesk::Boolean PyGiTextStyle::isVertical() const
{
    return impObj()->isVertical();
}

Adesk::Boolean PyGiTextStyle::isUnderlined() const
{
    return impObj()->isUnderlined();
}

Adesk::Boolean PyGiTextStyle::isOverlined() const
{
    return impObj()->isOverlined();
}

Adesk::Boolean PyGiTextStyle::isStrikethrough() const
{
    return impObj()->isStrikethrough();
}

bool PyGiTextStyle::preLoaded() const
{
    return impObj()->preLoaded();
}

std::string PyGiTextStyle::fileName() const
{
    return wstr_to_utf8(impObj()->fileName());
}

std::string PyGiTextStyle::bigFontFileName() const
{
    return wstr_to_utf8(impObj()->bigFontFileName());
}

std::string PyGiTextStyle::styleName() const
{
    return wstr_to_utf8(impObj()->styleName());
}

AcGePoint2d PyGiTextStyle::extents1(const std::string& pStr, const Adesk::Boolean penups, const int len, const Adesk::Boolean raw) const
{
    return impObj()->extents(AsWStr(pStr), penups, len, raw);
}

AcGePoint2d PyGiTextStyle::extents2(const std::string& pStr, const Adesk::Boolean penups, const int len, const Adesk::Boolean raw, const PyGiWorldDraw& ctxt) const
{
    return impObj()->extents(AsWStr(pStr), penups, len, raw, ctxt.impObj());
}

void PyGiTextStyle::setFont(const std::string& pTypeface, Adesk::Boolean bold, Adesk::Boolean italic, Charset charset,
    Autodesk::AutoCAD::PAL::FontUtils::FontPitch pitch, Autodesk::AutoCAD::PAL::FontUtils::FontFamily family) const
{
    PyThrowBadEs(impObj()->setFont(AsWStr(pTypeface), bold, italic, charset, pitch, family));
}

boost::python::tuple PyGiTextStyle::font() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcString sTypeface;
    Adesk::Boolean bold;
    Adesk::Boolean italic;
    Charset charset;
    Autodesk::AutoCAD::PAL::FontUtils::FontPitch pitch;
    Autodesk::AutoCAD::PAL::FontUtils::FontFamily family;
    PyThrowBadEs(impObj()->font(sTypeface, bold, italic, charset, pitch, family));
    return boost::python::make_tuple(wstr_to_utf8(sTypeface), bold, italic, charset, pitch, family);
#endif
}

boost::python::tuple PyGiTextStyle::extentsBox1(const std::string& pStr, const Adesk::Boolean penups, const int len, const Adesk::Boolean raw) const
{
    AcGePoint2d _min;
    AcGePoint2d _max;
    PyThrowBadEs(impObj()->extentsBox(AsWStr(pStr), penups, len, raw, _min, _max));
    return boost::python::make_tuple(_min, _max);
}

boost::python::tuple PyGiTextStyle::extentsBox2(const std::string& pStr, const Adesk::Boolean penups, const int len, const Adesk::Boolean raw, PyGiWorldDraw& ctxt) const
{
    AcGePoint2d _min;
    AcGePoint2d _max;
    PyThrowBadEs(impObj()->extentsBox(AsWStr(pStr), penups, len, raw, _min, _max, ctxt.impObj()));
    return boost::python::make_tuple(_min, _max);
}

void PyGiTextStyle::setPreLoaded(bool val) const
{
    impObj()->setPreLoaded(val);
}

void PyGiTextStyle::setTrackKerning(double trackPercent) const
{
#if defined(_BRXTARGET270)
    throw PyNotimplementedByHost();
#else
    impObj()->setTrackKerning(trackPercent);
#endif
}

PyRxClass PyGiTextStyle::desc()
{
    return PyRxClass(AcGiTextStyle::desc(), false);
}

std::string PyGiTextStyle::className()
{
    return "AcGiTextStyle";
}

PyGiTextStyle PyGiTextStyle::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiTextStyle>(src);
}

AcGiTextStyle* PyGiTextStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiTextStyle*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiTextStyle
void makePyGiVertexDataWrapper()
{
    PyDocString DS("VertexData");
    class_<PyGiVertexData, bases<PyGiParameter>>("VertexData")
        .def(init<>())
        .def("cast", &PyGiVertexData::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiVertexData::className).staticmethod("className")
        .def("desc", &PyGiVertexData::desc).staticmethod("desc")
        ;
}

PyGiVertexData::PyGiVertexData()
    : PyGiVertexData(new AcGiVertexData(), true)
{
}

PyGiVertexData::PyGiVertexData(AcGiVertexData* ptr, bool autoDelete)
    : PyGiParameter(ptr, autoDelete)
{
}

PyRxClass PyGiVertexData::desc()
{
    return PyRxClass(AcGiVertexData::desc(), false);
}

std::string PyGiVertexData::className()
{
    return "AcGiVertexData";
}

PyGiVertexData PyGiVertexData::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiVertexData>(src);
}

AcGiVertexData* PyGiVertexData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiVertexData*>(m_pyImp.get());
}
