#include "stdafx.h"
#include "PyBrxCore.h"

#ifdef BRXAPP

#include "AcConstraints3d.h"
#include "brxDevHelper.h"
#include "PyDbObject.h"
#include "PyBrxConstraints3d.h"

using namespace boost::python;

//---------------------------------------------------------------------
//PyBrxCore
void makePyBrxCoreWrapper()
{
    PyDocString DS("Core");
    class_<PyBrxCore>("Core", boost::python::no_init)
        .def("isLicenseAvailable", &PyBrxCore::isLicenseAvailable, DS.SARGS({ "val: PyBrx.LicensedFeature" })).staticmethod("isLicenseAvailable")
        .def("getOpenObjects", &PyBrxCore::getOpenObjects, DS.SARGS()).staticmethod("getOpenObjects")
        .def("getConstraintsGroup", &PyBrxCore::getConstraintsGroup1)
        .def("getConstraintsGroup", &PyBrxCore::getConstraintsGroup2, DS.SARGS({ "blockRefId: PyDb.ObjectId" , "createIfNotExist:bool = False" })).staticmethod("getConstraintsGroup")
        .def("getAllConstraintsGroups", &PyBrxCore::getAllConstraintsGroups, DS.SARGS({ "db:PyDb.Database" })).staticmethod("getAllConstraintsGroups")
        .def("getBlockParametersNames", &PyBrxCore::getBlockParametersNames, DS.SARGS({ "blockRefId: PyDb.ObjectId" })).staticmethod("getBlockParametersNames")
        .def("setBlockParameterExpression", &PyBrxCore::setBlockParameterExpression, DS.SARGS({ "blockRefId:PyDb.ObjectId","name:str","expr:str" })).staticmethod("setBlockParameterExpression")
        .def("getBlockParameterExpression", &PyBrxCore::getBlockParameterExpression, DS.SARGS({ "blockRefId:PyDb.ObjectId","name:str" })).staticmethod("getBlockParameterExpression")
        .def("getBlockParameterValue", &PyBrxCore::getBlockParameterValue, DS.SARGS({ "blockRefId:PyDb.ObjectId","name:str" })).staticmethod("getBlockParameterValue")
        .def("getEntityGuiName", &PyBrxCore::getEntityGuiName, DS.SARGS({ "entId:PyDb.ObjectId" })).staticmethod("getEntityGuiName")
        .def("setEntityGuiName", &PyBrxCore::setEntityGuiName, DS.SARGS({ "entId:PyDb.ObjectId","name:str" })).staticmethod("setEntityGuiName")
        .def("blockParameterHasStringValue", &PyBrxCore::blockParameterHasStringValue, DS.SARGS({ "blockRefId:PyDb.ObjectId","name:str" })).staticmethod("blockParameterHasStringValue")
        .def("getBlockParameterStringValue", &PyBrxCore::getBlockParameterStringValue, DS.SARGS({ "blockRefId:PyDb.ObjectId","name:str" })).staticmethod("getBlockParameterStringValue")
        .def("effectiveBlockRefName", &PyBrxCore::effectiveBlockRefName, DS.SARGS({ "blockRefId:PyDb.ObjectId" })).staticmethod("effectiveBlockRefName")
        .def("effectiveBlockTableRecord", &PyBrxCore::effectiveBlockTableRecord, DS.SARGS({ "blockRefId:PyDb.ObjectId" })).staticmethod("effectiveBlockTableRecord")
        .def("removeConstraints", &PyBrxCore::removeConstraints, DS.SARGS({ "id:PyDb.ObjectId" })).staticmethod("removeConstraints")
        .def("removeConstraintsFromDatabase", &PyBrxCore::removeConstraintsFromDatabase, DS.SARGS({ "db:PyDb.Database" })).staticmethod("removeConstraintsFromDatabase")
        .def("getBlockParameter", &PyBrxCore::getBlockParameter, DS.SARGS({ "blockRefId:PyDb.ObjectId","name:str" })).staticmethod("getBlockParameter")
        ;
}

bool PyBrxCore::isLicenseAvailable(BricsCAD::LicensedFeature feature)
{
    return ::isLicenseAvailable(feature);
}

boost::python::list PyBrxCore::getOpenObjects()
{
    AcArray<AcDbObject*> objs;
    BRX::getOpenObjects(objs);
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto item : objs)
        _pylist.append(PyDbObject(item, false));
    return _pylist;
}

PyBrxConstraintsGroup PyBrxCore::getConstraintsGroup1(const PyDbObjectId& blockId)
{
    return getConstraintsGroup2(blockId, false);
}

PyBrxConstraintsGroup PyBrxCore::getConstraintsGroup2(const PyDbObjectId& blockId, bool createIfNotExist)
{
    auto item = acdbGetConstraintsGroup(blockId.m_id, createIfNotExist);
    if (item.refCount() != 1)
        PyThrowBadEs(eInvalidOpenState);
    return PyBrxConstraintsGroup(item.detach());
}

boost::python::list PyBrxCore::getAllConstraintsGroups(const PyDbDatabase& db)
{
    auto arr = acdbGetAllConstraintsGroups(db.impObj());
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto& item : arr)
    {
        if (item.refCount() != 1)
            PyThrowBadEs(eInvalidOpenState);
        _pylist.append(PyBrxConstraintsGroup(item.detach()));
    }
    return _pylist;
}

boost::python::list PyBrxCore::getBlockParametersNames(const PyDbObjectId& blockRefId)
{
    const auto arr = acdbGetBlockParametersNames(blockRefId.m_id);
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : arr)
        _pylist.append(wstr_to_utf8(item));
    return _pylist;
}

void PyBrxCore::setBlockParameterExpression(const PyDbObjectId& blockRefId, const std::string& name, const std::string& expr)
{
    PyThrowBadEs(acdbSetBlockParameterExpression(blockRefId.m_id, utf8_to_wstr(name).c_str(), utf8_to_wstr(expr).c_str()));
}

std::string PyBrxCore::getBlockParameterExpression(const PyDbObjectId& blockRefId, const std::string& name)
{
    return wstr_to_utf8(acdbGetBlockParameterExpression(blockRefId.m_id, utf8_to_wstr(name).c_str()));
}

double PyBrxCore::getBlockParameterValue(const PyDbObjectId& blockRefId, const std::string& name)
{
    double resValue = 0.0;
    PyThrowBadEs(acdbGetBlockParameterValue(blockRefId.m_id, utf8_to_wstr(name).c_str(), resValue));
    return resValue;
}

std::string PyBrxCore::getEntityGuiName(const PyDbObjectId& entId)
{
    return wstr_to_utf8(acdbGetEntityGuiName(entId.m_id));
}

void PyBrxCore::setEntityGuiName(const PyDbObjectId& entId, const std::string& name)
{
    PyThrowBadEs(acdbSetEntityGuiName(entId.m_id, utf8_to_wstr(name).c_str()));
}

bool PyBrxCore::blockParameterHasStringValue(const PyDbObjectId& blockRefId, const std::string& name)
{
    return acdbBlockParameterHasStringValue(blockRefId.m_id, utf8_to_wstr(name).c_str());
}

std::string PyBrxCore::getBlockParameterStringValue(const PyDbObjectId& blockRefId, const std::string& name)
{
    return wstr_to_utf8(acdbGetBlockParameterStringValue(blockRefId.m_id, utf8_to_wstr(name).c_str()));
}

std::string PyBrxCore::effectiveBlockRefName(const PyDbObjectId& blockRefId)
{
    return wstr_to_utf8(acdbEffectiveBlockRefName(blockRefId.m_id));
}

PyDbObjectId PyBrxCore::effectiveBlockTableRecord(const PyDbObjectId& blockRefId)
{
    return PyDbObjectId(acdbEffectiveBlockTableRecord(blockRefId.m_id));
}

bool PyBrxCore::removeConstraints(const PyDbObjectId& id)
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost{};
#else
    return acdbRemoveConstraints(id.m_id);
#endif
}

bool PyBrxCore::removeConstraintsFromDatabase(const PyDbDatabase& db)
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost{};
#else
    return acdbRemoveConstraints(db.impObj());
#endif
}

PyBrxBlockParameter PyBrxCore::getBlockParameter(const PyDbObjectId& blockRefId, const std::string& name)
{
    return PyBrxBlockParameter(blockRefId, name);
}

#endif
