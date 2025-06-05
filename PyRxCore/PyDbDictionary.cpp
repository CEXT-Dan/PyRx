#include "stdafx.h"
#include "PyDbDictionary.h"
#include "PyDbObjectId.h"


using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//PyDbDictionary wrapper
void makePyDbDictionaryWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view removeOverload = "Overloads:\n"
        "- key: str\n"
        "- key: PyDb.ObjectId\n"
        "- key: str, returnId: PyDb.ObjectId\n";

    PyDocString DS("PyDb.Dictionary");
    class_<PyDbDictionary, bases<PyDbObject>>("Dictionary")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 3737)))
        .def("getAt", &PyDbDictionary::getAt, DS.ARGS({ "val : str" }, 3762))
        .def("has", &PyDbDictionary::has1)
        .def("has", &PyDbDictionary::has2, DS.ARGS({ "val : str|PyDb.ObjectId" }, 3764))
        .def("nameAt", &PyDbDictionary::nameAt, DS.ARGS({ "val : PyDb.ObjectId" }, 3767))
        .def("numEntries", &PyDbDictionary::numEntries, DS.ARGS(3769))
        .def("setAt", &PyDbDictionary::setAt, DS.ARGS(3771))
        .def("remove", &PyDbDictionary::remove1)
        .def("remove", &PyDbDictionary::remove2)
        .def("remove", &PyDbDictionary::remove3, DS.OVRL(removeOverload, 3770))
        .def("setName", &PyDbDictionary::setName, DS.ARGS({ "old : str","new : str" }, 3773))
        .def("asDict", &PyDbDictionary::toDict, DS.ARGS())
        .def("toDict", &PyDbDictionary::toDict, DS.ARGS())
        .def("className", &PyDbDictionary::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbDictionary::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbDictionary::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbDictionary::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("__getitem__", &PyDbDictionary::getAt, DS.ARGS({ "val : str" }, 3762))
        .def("__contains__", &PyDbDictionary::has1)
        .def("__contains__", &PyDbDictionary::has2, DS.ARGS({ "val : str|PyDb.ObjectId" }, 3764))
        ;
}

//---------------------------------------------------------------------------------------- -
//PyDbDictionary

PyDbDictionary::PyDbDictionary()
    : PyDbObject(new AcDbDictionary(), true)
{
}

PyDbDictionary::PyDbDictionary(AcDbDictionary* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbDictionary::PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbDictionary>(id, mode), true)
{
}

PyDbDictionary::PyDbDictionary(const PyDbObjectId& id)
    : PyDbDictionary(id, AcDb::OpenMode::kForRead)
{
}

PyDbDictionary::PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbDictionary>(id, mode, erased), true)
{
}

PyDbObjectId PyDbDictionary::getAt(const std::string& entryName) const
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->getAt(utf8_to_wstr(entryName).c_str(), id));
    return PyDbObjectId(id);
}

bool PyDbDictionary::has1(const std::string& entryName) const
{
    return impObj()->has(utf8_to_wstr(entryName).c_str());
}

bool PyDbDictionary::has2(const PyDbObjectId& id) const
{
    return impObj()->has(id.m_id);
}

std::string PyDbDictionary::nameAt(const PyDbObjectId& id) const
{
    AcString name;
    PyThrowBadEs(impObj()->nameAt(id.m_id, name));
    return wstr_to_utf8(name);
}

Adesk::UInt32 PyDbDictionary::numEntries() const
{
    return impObj()->numEntries();
}

PyDbObjectId PyDbDictionary::setAt(const std::string& srchKey, PyDbObject& newValue) const
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->setAt(utf8_to_wstr(srchKey).c_str(), newValue.impObj(), id.m_id));
    return id;
}

void PyDbDictionary::remove1(const std::string& key) const
{
    return PyThrowBadEs(impObj()->remove(utf8_to_wstr(key).c_str()));
}

void PyDbDictionary::remove2(const std::string& key, PyDbObjectId& returnId) const
{
    return PyThrowBadEs(impObj()->remove(utf8_to_wstr(key).c_str(), returnId.m_id));
}

void PyDbDictionary::remove3(const PyDbObjectId& objId) const
{
    return PyThrowBadEs(impObj()->remove(objId.m_id));
}

bool PyDbDictionary::setName(const std::string& oldName, const std::string& newName) const
{
    return impObj()->setName(utf8_to_wstr(oldName).c_str(), utf8_to_wstr(newName).c_str());
}

boost::python::dict PyDbDictionary::toDict() const
{
    PyAutoLockGIL lock;
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

PyDbDictionary PyDbDictionary::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbDictionary, AcDbDictionary>(src);
}

PyDbDictionary PyDbDictionary::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbDictionary>(src);
}

AcDbDictionary* PyDbDictionary::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDictionary*>(m_pyImp.get());
}
