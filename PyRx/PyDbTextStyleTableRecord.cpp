#include "stdafx.h"
#include "PyDbTextStyleTableRecord.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makeTextStyleTableRecordWrapper()
{
    class_<PyDbTextStyleTableRecord, bases<PyDbSymbolTableRecord>>("TextStyleTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("isShapeFile", &PyDbTextStyleTableRecord::isShapeFile)
        .def("setIsShapeFile", &PyDbTextStyleTableRecord::setIsShapeFile)
        .def("isVertical", &PyDbTextStyleTableRecord::isVertical)
        .def("setIsVertical", &PyDbTextStyleTableRecord::setIsVertical)
        .def("textSize", &PyDbTextStyleTableRecord::textSize)
        .def("setTextSize", &PyDbTextStyleTableRecord::setTextSize)
        .def("xScale", &PyDbTextStyleTableRecord::xScale)
        .def("setXScale", &PyDbTextStyleTableRecord::setXScale)
        .def("obliquingAngle", &PyDbTextStyleTableRecord::obliquingAngle)
        .def("setObliquingAngle", &PyDbTextStyleTableRecord::setObliquingAngle)
        .def("flagBits", &PyDbTextStyleTableRecord::flagBits)
        .def("setFlagBits", &PyDbTextStyleTableRecord::setFlagBits)
        .def("priorSize", &PyDbTextStyleTableRecord::priorSize)
        .def("setPriorSize", &PyDbTextStyleTableRecord::setPriorSize)
        .def("fileName", &PyDbTextStyleTableRecord::fileName)
        .def("setFileName", &PyDbTextStyleTableRecord::setFileName)
        .def("bigFontFileName", &PyDbTextStyleTableRecord::bigFontFileName)
        .def("setBigFontFileName", &PyDbTextStyleTableRecord::setBigFontFileName)
        .def("setFont", &PyDbTextStyleTableRecord::setFont)
        .def("font", &PyDbTextStyleTableRecord::font)
        .def("className", &PyDbTextStyleTableRecord::className).staticmethod("className")
        ;
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord(AcDbTextStyleTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbTextStyleTableRecord::PyDbTextStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(nullptr, false)
{
    AcDbTextStyleTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbTextStyleTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

Adesk::Boolean PyDbTextStyleTableRecord::isShapeFile() const
{
    return impObj()->isShapeFile();
}

void PyDbTextStyleTableRecord::setIsShapeFile(Adesk::Boolean shape)
{
    return impObj()->setIsShapeFile(shape);
}

Adesk::Boolean PyDbTextStyleTableRecord::isVertical() const
{
    return impObj()->isVertical();
}

void PyDbTextStyleTableRecord::setIsVertical(Adesk::Boolean vertical)
{
    return impObj()->setIsVertical(vertical);
}

double PyDbTextStyleTableRecord::textSize() const
{
    return impObj()->textSize();
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setTextSize(double size)
{
    return impObj()->setTextSize(size);
}

double PyDbTextStyleTableRecord::xScale() const
{
    return impObj()->xScale();
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setXScale(double xScale)
{
    return impObj()->setXScale(xScale);
}

double PyDbTextStyleTableRecord::obliquingAngle() const
{
    return impObj()->obliquingAngle();
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setObliquingAngle(double obliquingAngle)
{
    return impObj()->setObliquingAngle(obliquingAngle);
}

Adesk::UInt8 PyDbTextStyleTableRecord::flagBits() const
{
    return impObj()->flagBits();
}

void PyDbTextStyleTableRecord::setFlagBits(Adesk::UInt8 flagBits)
{
    return impObj()->setFlagBits(flagBits);
}

double PyDbTextStyleTableRecord::priorSize() const
{
    return impObj()->priorSize();
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setPriorSize(double priorSize)
{
    return impObj()->setPriorSize(priorSize);
}

std::string PyDbTextStyleTableRecord::fileName()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcString path;
    if (auto es = impObj()->fileName(path); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(path);
#endif
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setFileName(const std::string& path)
{
    return impObj()->setFileName(utf8_to_wstr(path).c_str());
}

std::string PyDbTextStyleTableRecord::bigFontFileName()
{
    AcString path;
    if (auto es = impObj()->bigFontFileName(path); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(path);
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setBigFontFileName(const std::string& path)
{
    return impObj()->setBigFontFileName(utf8_to_wstr(path).c_str());
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setFont(const std::string& pTypeface, bool bold, bool italic, int charset, int pitch, int family, bool bAllowMissingFont)
{
    return impObj()->setFont(
        utf8_to_wstr(pTypeface).c_str(),
        bold,
        italic,
        (Charset)charset,
        (Autodesk::AutoCAD::PAL::FontUtils::FontPitch)pitch,
        (Autodesk::AutoCAD::PAL::FontUtils::FontFamily)family, bAllowMissingFont);
}

boost::python::tuple PyDbTextStyleTableRecord::font()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    bool bold = false;
    bool italic = false;
    Charset charset = kAnsiCharset;
    AcString sTypeface;
    Autodesk::AutoCAD::PAL::FontUtils::FontPitch pitch = Autodesk::AutoCAD::PAL::FontUtils::FontPitch::kDefault;
    Autodesk::AutoCAD::PAL::FontUtils::FontFamily family = Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kDoNotCare;
    if (auto es = impObj()->font(sTypeface, bold, italic, charset, pitch, family); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string tf = wstr_to_utf8(sTypeface);
    return boost::python::make_tuple(tf, bold, italic, (int)charset, (int)pitch, (int)family);
#endif
}

std::string PyDbTextStyleTableRecord::className()
{
    return "AcDbTextStyleTableRecord";
}

AcDbTextStyleTableRecord* PyDbTextStyleTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbTextStyleTableRecord*>(m_pImp.get());
}
