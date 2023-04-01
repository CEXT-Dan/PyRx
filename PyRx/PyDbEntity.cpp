#include "stdafx.h"
#include "PyDbEntity.h"
#include "PyDbObjectId.h"
#include "PyCmColorBase.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------------------
//wrapper
void makeAcDbEntityWrapper()
{
    static auto wrapper = class_<PyDbEntity, bases<PyDbObject>>("DbEntity", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("blockId", &PyDbEntity::blockId)
     
        .def("color", &PyDbEntity::color)
        .def("setColor", &PyDbEntity::setColor)

        .def("colorIndex", &PyDbEntity::colorIndex)
        .def("setColorIndex", &PyDbEntity::setColorIndex)

        .def("entityColor", &PyDbEntity::entityColor)

        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&)>("setLayer", &PyDbEntity::setLayer)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&, bool)>("setLayer", &PyDbEntity::setLayer)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const std::string&, bool, bool)>("setLayer", &PyDbEntity::setLayer)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbObjectId&)>("setLayer", &PyDbEntity::setLayer)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbObjectId&, bool)>("setLayer", &PyDbEntity::setLayer)
        .def<Acad::ErrorStatus(PyDbEntity::*)(const PyDbObjectId&, bool, bool)>("setLayer", &PyDbEntity::setLayer)

        .def("className", &PyDbEntity::className)
        ;
}

//----------------------------------------------------------------------------------------------------
//PyDbEntity
PyDbEntity::PyDbEntity(AcDbEntity* ptr, bool autoDelete)
    : PyDbObject (ptr, autoDelete)
{
}

PyDbEntity::PyDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbEntity* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbEntity>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObjectId PyDbEntity::blockId() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->blockId());
}

AcCmColor PyDbEntity::color() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->color();
}

Acad::ErrorStatus PyDbEntity::setLayer(const std::string& newVal)
{
    return this->setLayer(newVal, true, false);
}

Acad::ErrorStatus PyDbEntity::setLayer(const std::string& newVal, bool doSubents)
{
    return this->setLayer(newVal, doSubents, false);
}

Acad::ErrorStatus PyDbEntity::setLayer(const std::string& newVal, bool doSubents, bool allowHiddenLayer)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setLayer(utf8_to_wstr(newVal).c_str(), doSubents, allowHiddenLayer);
}

Acad::ErrorStatus PyDbEntity::setLayer(const PyDbObjectId& newVal)
{
    return this->setLayer(newVal, true, false);
}

Acad::ErrorStatus PyDbEntity::setLayer(const PyDbObjectId& newVal, bool doSubents)
{
    return this->setLayer(newVal, true, false);
}

Acad::ErrorStatus PyDbEntity::setLayer(const PyDbObjectId& newVal, bool doSubents, bool allowHiddenLayer)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setLayer(newVal.m_id, doSubents, allowHiddenLayer);
}

Acad::ErrorStatus PyDbEntity::setColor(const AcCmColor& color, bool doSubents, PyDbDatabase& db)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setColor(color, doSubents, db.impObj());
}

Adesk::UInt16 PyDbEntity::colorIndex() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->colorIndex();
}

Acad::ErrorStatus PyDbEntity::setColorIndex(Adesk::UInt16 color, Adesk::Boolean doSubents /*= true*/)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setColorIndex(color,doSubents);
}

AcCmEntityColor PyDbEntity::entityColor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->entityColor();
}

AcCmTransparency PyDbEntity::transparency() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->transparency();
}

Acad::ErrorStatus PyDbEntity::setTransparency(const AcCmTransparency& trans, Adesk::Boolean doSubents /*= true*/)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return impObj()->setTransparency(trans, doSubents);
}

std::string PyDbEntity::className()
{
    return "AcDbEntity";
}

AcDbEntity* PyDbEntity::impObj() const
{
    return static_cast<AcDbEntity*>(m_pImp);
}
