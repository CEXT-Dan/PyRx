#include "stdafx.h"
#include "PyDbTextStyleTableRecord.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makeTextStyleTableRecordWrapper()
{
    static auto wrapper = class_<PyDbTextStyleTableRecord, bases<PyDbSymbolTableRecord>>("TextStyleTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())

        .def("className", &PyDbSymbolTableRecord::className).staticmethod("className")
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

std::string PyDbTextStyleTableRecord::className()
{
    return "AcDbTextStyleTableRecord";
}

AcDbTextStyleTableRecord* PyDbTextStyleTableRecord::impObj() const
{
    return static_cast<AcDbTextStyleTableRecord*>(m_pImp.get());
}
