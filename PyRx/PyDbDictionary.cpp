#include "stdafx.h"
#include "PyDbDictionary.h"
#include "PyDbObjectId.h"


using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//PyDbDictionary wrapper
void makePyDbDictionaryWrapper()
{
	class_<PyDbDictionary, bases<PyDbObject>>("Dictionary")
		.def(init<>())
		.def(init<const PyDbObjectId&>())
		.def(init<const PyDbObjectId&, AcDb::OpenMode>())
		.def("getAt", &PyDbDictionary::getAt)
		.def("has", &PyDbDictionary::has1)
		.def("has", &PyDbDictionary::has2)
		.def("nameAt", &PyDbDictionary::nameAt)
		.def("numEntries", &PyDbDictionary::numEntries)
		.def("setAt", &PyDbDictionary::setAt)
		.def("remove", &PyDbDictionary::remove1)
		.def("remove", &PyDbDictionary::remove2)
		.def("remove", &PyDbDictionary::remove3)
		.def("setName", &PyDbDictionary::setName)
		.def("asDict", &PyDbDictionary::asDict)
		.def("className", &PyDbDictionary::className).staticmethod("className")
		.def("desc", &PyDbDictionary::desc).staticmethod("desc")
		.def("cloneFrom", &PyDbDictionary::cloneFrom).staticmethod("cloneFrom")
		.def("cast", &PyDbDictionary::cast).staticmethod("cast")
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

PyDbObjectId PyDbDictionary::getAt(const std::string& entryName)
{
	AcDbObjectId id;
	PyThrowBadEs(impObj()->getAt(utf8_to_wstr(entryName).c_str(), id));
	return PyDbObjectId(id);
}

bool PyDbDictionary::has1(const std::string& entryName)
{
	return impObj()->has(utf8_to_wstr(entryName).c_str());
}

bool PyDbDictionary::has2(const PyDbObjectId& id)
{
	return impObj()->has(id.m_id);
}

std::string PyDbDictionary::nameAt(const PyDbObjectId& id)
{
	AcString name;
	PyThrowBadEs(impObj()->nameAt(id.m_id, name));
	return wstr_to_utf8(name);
}

Adesk::UInt32 PyDbDictionary::numEntries() const
{
	return impObj()->numEntries();
}

PyDbObjectId PyDbDictionary::setAt(const std::string& srchKey, PyDbObject& newValue)
{
	PyDbObjectId id;
	PyThrowBadEs(impObj()->setAt(utf8_to_wstr(srchKey).c_str(), newValue.impObj(), id.m_id));
	return id;
}

void PyDbDictionary::remove1(const std::string& key)
{
	return PyThrowBadEs(impObj()->remove(utf8_to_wstr(key).c_str()));
}

void PyDbDictionary::remove2(const std::string& key, PyDbObjectId& returnId)
{
	return PyThrowBadEs(impObj()->remove(utf8_to_wstr(key).c_str(), returnId.m_id));
}

void PyDbDictionary::remove3(PyDbObjectId& objId)
{
	return PyThrowBadEs(impObj()->remove(objId.m_id));
}

bool PyDbDictionary::setName(const std::string& oldName, const std::string& newName)
{
	return impObj()->setName(utf8_to_wstr(oldName).c_str(), utf8_to_wstr(newName).c_str());
}

boost::python::dict PyDbDictionary::asDict()
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
	if (!src.impObj()->isKindOf(AcDbDictionary::desc()))
		throw PyAcadErrorStatus(eNotThatKindOfClass);
	return PyDbDictionary(static_cast<AcDbDictionary*>(src.impObj()->clone()), true);
}

PyDbDictionary PyDbDictionary::cast(const PyRxObject& src)
{
	PyDbDictionary dest(nullptr, false);
	PyRxObject rxo = src;
	std::swap(rxo.m_pyImp, dest.m_pyImp);
	return dest;
}

AcDbDictionary* PyDbDictionary::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
	if (m_pyImp == nullptr) [[unlikely]]
		throw PyNullObject(src);
		return static_cast<AcDbDictionary*>(m_pyImp.get());
}
