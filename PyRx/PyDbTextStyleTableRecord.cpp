#include "stdafx.h"
#include "PyDbTextStyleTableRecord.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makeTextStyleTableRecordWrapper()
{
    static auto wrapper = class_<PyDbTextStyleTableRecord, bases<PyDbSymbolTableRecord>>("TextStyleTableRecord", boost::python::no_init)
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

Adesk::Boolean PyDbTextStyleTableRecord::isShapeFile() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isShapeFile();
}

void PyDbTextStyleTableRecord::setIsShapeFile(Adesk::Boolean shape)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setIsShapeFile(shape);
}

Adesk::Boolean PyDbTextStyleTableRecord::isVertical() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isVertical();
}

void PyDbTextStyleTableRecord::setIsVertical(Adesk::Boolean vertical)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setIsVertical(vertical);
}

double PyDbTextStyleTableRecord::textSize() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textSize();
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setTextSize(double size)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextSize(size);
}

double PyDbTextStyleTableRecord::xScale() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->xScale();
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setXScale(double xScale)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setXScale(xScale);
}

double PyDbTextStyleTableRecord::obliquingAngle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->obliquingAngle();
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setObliquingAngle(double obliquingAngle)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setObliquingAngle(obliquingAngle);
}

Adesk::UInt8 PyDbTextStyleTableRecord::flagBits() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->flagBits();
}

void PyDbTextStyleTableRecord::setFlagBits(Adesk::UInt8 flagBits)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFlagBits(flagBits);
}

double PyDbTextStyleTableRecord::priorSize() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->priorSize();
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setPriorSize(double priorSize)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPriorSize(priorSize);
}

std::string PyDbTextStyleTableRecord::fileName()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString path;
    if (auto es = imp->fileName(path); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(path);
#endif
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setFileName(const std::string& path)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFileName(utf8_to_wstr(path).c_str());
}

std::string PyDbTextStyleTableRecord::bigFontFileName()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcString path;
    if (auto es = imp->bigFontFileName(path); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(path);
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setBigFontFileName(const std::string& path)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBigFontFileName(utf8_to_wstr(path).c_str());
}

Acad::ErrorStatus PyDbTextStyleTableRecord::setFont(const std::string& pTypeface, bool bold, bool italic, int charset, int pitch, int family, bool bAllowMissingFont)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFont(
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
   
    bool bold = false;
    bool italic = false;
    Charset charset = kAnsiCharset;
    AcString sTypeface;
    Autodesk::AutoCAD::PAL::FontUtils::FontPitch pitch = Autodesk::AutoCAD::PAL::FontUtils::FontPitch::kDefault;
    Autodesk::AutoCAD::PAL::FontUtils::FontFamily family = Autodesk::AutoCAD::PAL::FontUtils::FontFamily::kDoNotCare;
    if (auto es = imp->font(sTypeface, bold, italic, charset, pitch, family); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string tf = wstr_to_utf8(sTypeface);
    return boost::python::make_tuple(tf, bold, italic, (int)charset, (int)pitch, (int)family);
#endif
}

std::string PyDbTextStyleTableRecord::className()
{
    return "AcDbTextStyleTableRecord";
}

AcDbTextStyleTableRecord* PyDbTextStyleTableRecord::impObj() const
{
    return static_cast<AcDbTextStyleTableRecord*>(m_pImp.get());
}
