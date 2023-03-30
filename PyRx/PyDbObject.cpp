#include "stdafx.h"
#include "PyDbObject.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makeAcDbObjectWrapper()
{
    static auto wrapper = class_<PyDbObject, bases<PyGiDrawable>>("DbObject", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("objectId", &PyDbObject::objectId)
        .def("ownerId", &PyDbObject::ownerId)
        .def("database", &PyDbObject::database)
        .def("upgradeOpen", &PyDbObject::upgradeOpen)
        .def("downgradeOpen", &PyDbObject::downgradeOpen)
        .def("erase", &PyDbObject::erase)
        .def("className", &PyDbObject::className)
        .def("close", &PyDbObject::close)
        ;
}

//-----------------------------------------------------------------------------------------
//PyDbObject
PyDbObject::PyDbObject(AcDbObject* ptr, bool autoDelete)
    : PyGiDrawable(ptr, autoDelete)
{
}

PyDbObject::PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyGiDrawable(nullptr, true)
{
    AcDbObject* pobj = nullptr;
    acdbOpenObject<AcDbObject>(pobj, id.m_id, mode);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObject::~PyDbObject()
{
    if (m_pImp != nullptr)
    {
        AcDbObject* pDbo = static_cast<AcDbObject*>(m_pImp);
        if (!pDbo->objectId().isNull())
        {
            pDbo->close();
            m_bAutoDelete = false;
        }
    }
}

PyDbObjectId PyDbObject::objectId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->objectId());
    throw PyNullObject();
}

PyDbObjectId PyDbObject::ownerId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->ownerId());
    throw PyNullObject();
}

PyDbDatabase PyDbObject::database() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbDatabase(imp->database());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::close()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->close();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::upgradeOpen()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->upgradeOpen();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::downgradeOpen()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->downgradeOpen();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::erase()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->erase();
    throw PyNullObject();
}

std::string PyDbObject::className()
{
    return "AcDbObject";
}

AcDbObject* PyDbObject::impObj() const
{
    return static_cast<AcDbObject*>(m_pImp);
}
