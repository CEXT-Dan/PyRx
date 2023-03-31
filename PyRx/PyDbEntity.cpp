#include "stdafx.h"
#include "PyDbEntity.h"
#include "PyDbObjectId.h"
using namespace boost::python;

//----------------------------------------------------------------------------------------------------
//wrapper
void makeAcDbEntityWrapper()
{
    static auto wrapper = class_<PyDbEntity, bases<PyDbObject>>("DbEntity", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("blockId", &PyDbEntity::blockId)
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
    acdbOpenObject<AcDbEntity>(pobj, id.m_id, mode);
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

std::string PyDbEntity::className()
{
    return "AcDbEntity";
}

AcDbEntity* PyDbEntity::impObj() const
{
    return static_cast<AcDbEntity*>(m_pImp);
}
