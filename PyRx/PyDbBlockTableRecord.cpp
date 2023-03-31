#include "stdafx.h"
#include "PyDbBlockTableRecord.h"
#include "PyDbEntity.h"


using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord wrapper
void makeAcDbBlockTableRecordWrapper()
{
    static auto wrapper = class_<PyDbBlockTableRecord, bases<PyDbSymbolTableRecord>>("DbBlockTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBlockTableRecord::className)
        .def("appendAcDbEntity", &PyDbBlockTableRecord::appendAcDbEntity)
        .def("objectIds", &PyDbBlockTableRecord::objectIds)
        ;
}

//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord
PyDbBlockTableRecord::PyDbBlockTableRecord(AcDbBlockTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{

}

PyDbBlockTableRecord::PyDbBlockTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(nullptr, false)
{
    AcDbBlockTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbBlockTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObjectId PyDbBlockTableRecord::appendAcDbEntity(const PyDbEntity& ent)
{
    PyDbObjectId id;
    auto imp = impObj();
    if (imp != nullptr)
        imp->appendAcDbEntity(id.m_id, ent.impObj());
    return id;
}

boost::python::list PyDbBlockTableRecord::objectIds()
{
    boost::python::list pyList;
    auto imp = impObj();
    if (imp != nullptr)
    {
        auto [es, iter] = makeBlockTableRecordIterator(*imp);
        if (es == eOk)
        {
            for (iter->start(); !iter->done(); iter->step())
            {
                PyDbObjectId id;
                if (iter->getEntityId(id.m_id) == eOk)
                    pyList.append(id);
            }
        }
    }
    return pyList;
}

std::string PyDbBlockTableRecord::className()
{
    return  "AcDbBlockTableRecord";
}

AcDbBlockTableRecord* PyDbBlockTableRecord::impObj() const
{
    return static_cast<AcDbBlockTableRecord*>(m_pImp);
}
