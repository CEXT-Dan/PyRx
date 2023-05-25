#include "stdafx.h"
#include "PyDbDictionary.h"
#include "PyDbObjectId.h"


using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//PyDbDictionary wrapper
void makeAcDbDictionaryWrapper()
{
    class_<PyDbDictionary, bases<PyDbObject>>("Dictionary", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getAt", &PyDbDictionary::getAt)
        .def("has", &PyDbDictionary::has)
        .def("asdict", &PyDbDictionary::asDict)
        .def("className", &PyDbDictionary::className).staticmethod("className")
        .def("desc", &PyDbDictionary::desc).staticmethod("desc")
        ;
}
//---------------------------------------------------------------------------------------- -
//PyDbDictionary
PyDbDictionary::PyDbDictionary(AcDbDictionary* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbDictionary::PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, true)
{
    AcDbDictionary* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbDictionary>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbObjectId PyDbDictionary::getAt(const std::string& entryName)
{
    AcDbObjectId id;
    impObj()->getAt(utf8_to_wstr(entryName).c_str(), id);
    return PyDbObjectId(id);
}

bool PyDbDictionary::has(const std::string& entryName)
{
    return impObj()->has(utf8_to_wstr(entryName).c_str());
}

boost::python::dict PyDbDictionary::asDict()
{
    boost::python::dict _items;

    for (std::unique_ptr<AcDbDictionaryIterator> iter(impObj()->newIterator()); !iter->done(); iter->next())
        _items[wstr_to_utf8(iter->name()).c_str()] = PyDbObjectId(iter->objectId());
    return _items;
}

std::string PyDbDictionary::className()
{
    return "AcDbDictionary";
}

PyRxClass PyDbDictionary::desc()
{
    return PyRxClass(AcDbDictionary::desc(), false);
}

AcDbDictionary* PyDbDictionary::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbDictionary*>(m_pyImp.get());
}
