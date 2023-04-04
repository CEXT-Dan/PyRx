#include "stdafx.h"
#include "PyDbEnts.h"
#include "PyDbObjectId.h"
using namespace boost::python;





//-----------------------------------------------------------------------------------
//PyDbText
void makePyDbTextWrapper()
{
    static auto wrapper = class_<PyDbText, bases<PyDbEntity>>("DbPoint")
        .def(init<>())
        .def(init<AcGePoint3d&, const std::string&>())
        .def(init<AcGePoint3d&, const std::string&, PyDbObjectId&, double, double>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbText::position)
        .def("setPosition", &PyDbText::setPosition)
        .def("alignmentPoint", &PyDbText::alignmentPoint)
        .def("setAlignmentPoint", &PyDbText::setAlignmentPoint)
        .def("isDefaultAlignment", &PyDbText::isDefaultAlignment)
        .def("normal", &PyDbText::normal)
        .def("setNormal", &PyDbText::setNormal)
        .def("isPlanar", &PyDbText::isPlanar)
        .def("thickness", &PyDbText::thickness)
        .def("setThickness", &PyDbText::setThickness)
        .def("oblique", &PyDbText::oblique)
        .def("setOblique", &PyDbText::setOblique)
        .def("rotation", &PyDbText::rotation)
        .def("setRotation", &PyDbText::setRotation)
        .def("height", &PyDbText::height)
        .def("setHeight", &PyDbText::setHeight)
        .def("widthFactor", &PyDbText::widthFactor)
        .def("setWidthFactor", &PyDbText::setWidthFactor)
        .def("textString", &PyDbText::textString)
        .def("setTextString", &PyDbText::setTextString)
        .def("textStyle", &PyDbText::textStyle)
        .def("setTextStyle", &PyDbText::setTextStyle)
        .def("isMirroredInX", &PyDbText::isMirroredInX)
        .def("mirrorInX", &PyDbText::mirrorInX)
        .def("isMirroredInY", &PyDbText::isMirroredInY)
        .def("mirrorInY", &PyDbText::mirrorInY)
        .def("horizontalMode", &PyDbText::horizontalMode)
        .def("setHorizontalMode", &PyDbText::setHorizontalMode)
        .def("verticalMode", &PyDbText::verticalMode)
        .def("setVerticalMode", &PyDbText::setVerticalMode)
        .def("correctSpelling", &PyDbText::correctSpelling)
        .def("adjustAlignment", &PyDbText::adjustAlignment)
        .def("className", &PyDbText::className).staticmethod("className")
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

PyDbText::PyDbText(AcDbText* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbText::PyDbText(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbText* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbText>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbText::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbText::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

AcGePoint3d PyDbText::alignmentPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->alignmentPoint();
}

Acad::ErrorStatus PyDbText::setAlignmentPoint(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAlignmentPoint(val);
}

Adesk::Boolean PyDbText::isDefaultAlignment() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isDefaultAlignment();
}

AcGeVector3d PyDbText::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbText::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

double PyDbText::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

Acad::ErrorStatus PyDbText::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

double PyDbText::oblique() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->oblique();
}

Acad::ErrorStatus PyDbText::setOblique(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setOblique(val);
}

double PyDbText::rotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rotation();
}

Acad::ErrorStatus PyDbText::setRotation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRotation(val);
}

double PyDbText::height() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->height();
}

Acad::ErrorStatus PyDbText::setHeight(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHeight(val);
}

double PyDbText::widthFactor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->widthFactor();
}

Acad::ErrorStatus PyDbText::setWidthFactor(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setWidthFactor(val);
}

std::string PyDbText::textString() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->textStringConst());
}

Acad::ErrorStatus PyDbText::setTextString(std::string& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextString(utf8_to_wstr(val).c_str());
}

PyDbObjectId PyDbText::textStyle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle());
}

Acad::ErrorStatus PyDbText::setTextStyle(const PyDbObjectId& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(val.m_id);
}

Adesk::Boolean PyDbText::isMirroredInX() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMirroredInX();
}

Acad::ErrorStatus PyDbText::mirrorInX(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->mirrorInX(val);
}

Adesk::Boolean PyDbText::isMirroredInY() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMirroredInY();
}

Acad::ErrorStatus PyDbText::mirrorInY(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->mirrorInY(val);
}

AcDb::TextHorzMode PyDbText::horizontalMode() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->horizontalMode();
}

Acad::ErrorStatus PyDbText::setHorizontalMode(AcDb::TextHorzMode val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHorizontalMode(val);
}

AcDb::TextVertMode PyDbText::verticalMode() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->verticalMode();
}

Acad::ErrorStatus PyDbText::setVerticalMode(AcDb::TextVertMode val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVerticalMode(val);
}

int PyDbText::correctSpelling()
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

Acad::ErrorStatus PyDbText::adjustAlignment(const PyDbDatabase& pDb)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->adjustAlignment(pDb.impObj());
#endif
}

std::string PyDbText::className()
{
    return "AcDbText";
}

AcDbText* PyDbText::impObj() const
{
    return static_cast<AcDbText*>(m_pImp);
}

//-----------------------------------------------------------------------------------
//PyDbPoint
void makePyDbPointWrapper()
{
    static auto wrapper = class_<PyDbPoint, bases<PyDbEntity>>("DbPoint")
        .def(init<>())
        .def(init<AcGePoint3d&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbPoint::position)
        .def("setPosition", &PyDbPoint::setPosition)
        .def("thickness", &PyDbPoint::thickness)
        .def("setThickness", &PyDbPoint::setThickness)
        .def("normal", &PyDbPoint::normal)
        .def("setNormal", &PyDbPoint::setNormal)
        .def("ecsRotation", &PyDbPoint::ecsRotation)
        .def("setEcsRotation", &PyDbPoint::setEcsRotation)
        .def("isPlanar", &PyDbPoint::isPlanar)
        .def("className", &PyDbPoint::className).staticmethod("className")
        ;
}

PyDbPoint::PyDbPoint()
    : PyDbPoint::PyDbPoint(new AcDbPoint(), true)
{
}

PyDbPoint::PyDbPoint(const AcGePoint3d& point)
    : PyDbPoint::PyDbPoint(new AcDbPoint(point), true)
{
}

PyDbPoint::PyDbPoint(AcDbPoint* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbPoint::PyDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbPoint* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPoint>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbPoint::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbPoint::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

double PyDbPoint::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

Acad::ErrorStatus PyDbPoint::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

AcGeVector3d PyDbPoint::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbPoint::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

double PyDbPoint::ecsRotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->ecsRotation();
}

Acad::ErrorStatus PyDbPoint::setEcsRotation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setEcsRotation(val);
}

Adesk::Boolean PyDbPoint::isPlanar() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isPlanar();
}

std::string PyDbPoint::className()
{
    return "AcDbPoint";
}

AcDbPoint* PyDbPoint::impObj() const
{
    return static_cast<AcDbPoint*>(m_pImp);
}
