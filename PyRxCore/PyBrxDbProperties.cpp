#include "stdafx.h"
#include "PyBrxDbProperties.h"

#ifdef BRXAPP
#ifndef _BRXTARGET240

#include "PyDbObjectId.h"
#include "PyDbEval.h"

using namespace boost::python;

void makePyBrxDbPropertiesWrapper()
{
    PyDocString DS("DbProperties");
    class_<PyBrxDbProperties>("DbProperties", boost::python::no_init)
        .def("dumpAll", &PyBrxDbProperties::dumpAll, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("dumpAll")
        .def("listAll", &PyBrxDbProperties::listAll, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("listAll")
        .def("isValid", &PyBrxDbProperties::isValid, DS.SARGS({ "id: PyDb.ObjectId", "name: str"})).staticmethod("isValid")
        .def("isReadOnly", &PyBrxDbProperties::isReadOnly, DS.SARGS({ "id: PyDb.ObjectId", "name: str" })).staticmethod("isReadOnly")
        .def("getValue", &PyBrxDbProperties::getValue, DS.SARGS({ "id: PyDb.ObjectId", "name: str" })).staticmethod("getValue")
        .def("setValue", &PyBrxDbProperties::setValue, DS.SARGS({ "id: PyDb.ObjectId", "name: str",  "val: PyDb.AcValue" })).staticmethod("setValue")
        ;
}

bool PyBrxDbProperties::dumpAll(const PyDbObjectId& id)
{
    return BrxDbProperties::dumpAll(id.m_id);
}

boost::python::list PyBrxDbProperties::listAll(const PyDbObjectId& id)
{
    AcStringArray qualifiedPropertyNames;
    BrxDbProperties::listAll(id.m_id, qualifiedPropertyNames);
    return AcStringArrayToPyList(qualifiedPropertyNames);
}

boost::python::tuple PyBrxDbProperties::isValid(const PyDbObjectId& id, const std::string& propertyName)
{
    PyAutoLockGIL lock;
    AcString name = utf8_to_wstr(propertyName).c_str();
    bool flag = BrxDbProperties::isValid(id.m_id, name);
    return boost::python::make_tuple(flag, wstr_to_utf8(name));
}

boost::python::tuple PyBrxDbProperties::isReadOnly(const PyDbObjectId& id, const std::string& propertyName)
{
    PyAutoLockGIL lock;
    bool isReadonly = true;
    AcString name = utf8_to_wstr(propertyName).c_str();
    bool flag = BrxDbProperties::isReadOnly(id.m_id, name, isReadonly);
    return boost::python::make_tuple(flag, wstr_to_utf8(name), isReadonly);
}

PyDbAcValue PyBrxDbProperties::getValue(const PyDbObjectId& id, const std::string& propertyName)
{
    AcValue value;
    if (BrxDbProperties::getValue(id.m_id, utf8_to_wstr(propertyName).c_str(), value) != true)
        PyThrowBadEs(eInvalidInput);
    return PyDbAcValue{ value };
}

void PyBrxDbProperties::setValue(const PyDbObjectId& id, const std::string& propertyName, const PyDbAcValue& value)
{
    if (BrxDbProperties::setValue(id.m_id, utf8_to_wstr(propertyName).c_str(), *value.impObj()) != true)
        PyThrowBadEs(eInvalidInput);
}

#endif
#endif