#include "stdafx.h"
#include "PyDbEnts.h"
#include "PyDbObjectId.h"
using namespace boost::python;

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
