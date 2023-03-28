#include "stdafx.h"
#include "PyDbBlockTableRecord.h"
#include "PyDbEntity.h"


using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord wrapper
void makeAcDbBlockTableRecordWrapper()
{
    static auto wrapper = class_<PyDbBlockTableRecord, bases<PyDbSymbolTableRecord>>("DbBlockTableRecord", boost::python::no_init)
        .def("className", &PyDbBlockTableRecord::className)
        .def("appendAcDbEntity", &PyDbBlockTableRecord::appendAcDbEntity)
        .def("objectIds", &PyDbBlockTableRecord::objectIds)
        .def("fromDbObject", &PyDbBlockTableRecord::fromDbObject)
        ;
}

//---------------------------------------------------------------------------------------- -
//PyDbBlockTableRecord
PyDbBlockTableRecord::PyDbBlockTableRecord(AcDbBlockTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{

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

PyDbBlockTableRecord PyDbBlockTableRecord::fromDbObject(const PyDbObject& obj)
{
    if (obj.impObj() != nullptr && obj.impObj()->isA()->isDerivedFrom(AcDbBlockTableRecord::desc()))
        return PyDbBlockTableRecord(static_cast<AcDbBlockTableRecord*>(obj.impObj()), true);
    throw PyNotThatKindOfClass();
}

std::string PyDbBlockTableRecord::className()
{
    return  "AcDbBlockTableRecord";
}

AcDbBlockTableRecord* PyDbBlockTableRecord::impObj() const
{
    return static_cast<AcDbBlockTableRecord*>(m_pImp);
}
