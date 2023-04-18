#include "stdafx.h"
#include "PyDbMtext.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbMTextWrapper()
{
    static auto wrapper = class_<PyDbMtext, bases<PyDbEntity>>("MText")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("location", &PyDbMtext::location)
        .def("setLocation", &PyDbMtext::setLocation)
        .def("normal", &PyDbMtext::normal)
        .def("setNormal", &PyDbMtext::setNormal)
        .def("direction", &PyDbMtext::direction)
        .def("setDirection", &PyDbMtext::setDirection)
        .def("rotation", &PyDbMtext::rotation)
        .def("setRotation", &PyDbMtext::setRotation)
        .def("width", &PyDbMtext::width)
        .def("setWidth", &PyDbMtext::setWidth)
        .def("ascent", &PyDbMtext::ascent)
        .def("descent", &PyDbMtext::descent)
        .def("textStyle", &PyDbMtext::textStyle)
        .def("setTextStyle", &PyDbMtext::setTextStyle)
        .def("textHeight", &PyDbMtext::textHeight)
        .def("setTextHeight", &PyDbMtext::setTextHeight)
        .def("attachment", &PyDbMtext::attachment)
        .def("setAttachment", &PyDbMtext::setAttachment)
        .def("setAttachmentMovingLocation", &PyDbMtext::setAttachmentMovingLocation)
        .def("className", &PyDbMtext::className).staticmethod("className")
        ;
    enum_<AcDbMText::AttachmentPoint>("AttachmentPoint")
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
    enum_<AcDbMText::FlowDirection>("FlowDirection")
        .value("kLtoR", AcDbMText::FlowDirection::kLtoR)
        .value("kRtoL", AcDbMText::FlowDirection::kRtoL)
        .value("kTtoB", AcDbMText::FlowDirection::kTtoB)
        .value("kBtoT", AcDbMText::FlowDirection::kBtoT)
        .value("kByStyle", AcDbMText::FlowDirection::kByStyle)
        .export_values()
        ;
}

PyDbMtext::PyDbMtext()
    : PyDbMtext::PyDbMtext(new AcDbMText(), true)
{
}

PyDbMtext::PyDbMtext(AcDbMText* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbMtext::PyDbMtext(const PyDbObjectId& id, AcDb::OpenMode mode)
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

AcGePoint3d PyDbMtext::location() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->location();
}

Acad::ErrorStatus PyDbMtext::setLocation(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLocation(val);
}

AcGeVector3d PyDbMtext::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbMtext::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

AcGeVector3d PyDbMtext::direction() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->direction();
}

Acad::ErrorStatus PyDbMtext::setDirection(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setDirection(val);
}

double PyDbMtext::rotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rotation();
}

Acad::ErrorStatus PyDbMtext::setRotation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRotation(val);
}

double PyDbMtext::width() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->width();
}

Acad::ErrorStatus PyDbMtext::setWidth(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setWidth(val);
}

double PyDbMtext::ascent() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->ascent();
}

double PyDbMtext::descent() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->descent();
}

PyDbObjectId PyDbMtext::textStyle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle());
}

Acad::ErrorStatus PyDbMtext::setTextStyle(const PyDbObjectId& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(val.m_id);
}

double PyDbMtext::textHeight() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->textHeight();
}

Acad::ErrorStatus PyDbMtext::setTextHeight(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextHeight(val);
}

AcDbMText::AttachmentPoint PyDbMtext::attachment() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->attachment();
}

Acad::ErrorStatus PyDbMtext::setAttachment(AcDbMText::AttachmentPoint val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAttachment(val);
}

Acad::ErrorStatus PyDbMtext::setAttachmentMovingLocation(AcDbMText::AttachmentPoint val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAttachmentMovingLocation(val);
}

std::string PyDbMtext::className()
{
    return "AcDbMText";
}

AcDbMText* PyDbMtext::impObj() const
{
    return static_cast<AcDbMText*>(m_pImp.get());
}
