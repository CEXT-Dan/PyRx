#include "stdafx.h"
#include "PyDbDbLayerStateManager.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"

using namespace boost::python;
//---------------------------------------------------------------------------------------- -
//PyDbDbLayerStateManager
void makePyDbDbLayerStateManagerWrapper()
{
    PyDocString DS("LayerStateManager");
    class_<PyDbDbLayerStateManager, bases<PyRxObject>>("LayerStateManager")
        .def(init<>())
        .def(init<const PyDbDatabase&>(DS.ARGS({ "db: PyDb.Database = ..." }, 5724)))
        .def("layerStatesDictionaryId", &PyDbDbLayerStateManager::layerStatesDictionaryId1)
        .def("layerStatesDictionaryId", &PyDbDbLayerStateManager::layerStatesDictionaryId2, DS.ARGS({ "bCreateIfNotPresent: bool=False" }, 5756))
        .def("hasLayerState", &PyDbDbLayerStateManager::hasLayerState, DS.ARGS({ "sName: str" }, 5750))
        .def("saveLayerState", &PyDbDbLayerStateManager::saveLayerState1)
        .def("saveLayerState", &PyDbDbLayerStateManager::saveLayerState2, DS.ARGS({ "sName: str", "mask: PyDb.LayerStateMask","id: PyDb.ObjectId = ..." }, 5761))
        .def("restoreLayerState", &PyDbDbLayerStateManager::restoreLayerState1)
        .def("restoreLayerState", &PyDbDbLayerStateManager::restoreLayerState2, DS.ARGS({ "sName: str", "vpId: PyDb.ObjectId", "flags: int = 0", "mask: PyDb.LayerStateMask = ..." }, 5760))
        .def("setLayerStateMask", &PyDbDbLayerStateManager::setLayerStateMask, DS.ARGS({ "sName: str", "mask: PyDb.LayerStateMask" }, 5763))
        .def("getLayerStateMask", &PyDbDbLayerStateManager::getLayerStateMask, DS.ARGS({ "sName: str" }, 5748))
        .def("deleteLayerState", &PyDbDbLayerStateManager::deleteLayerState, DS.ARGS({ "sName: str" }, 5742))
        .def("renameLayerState", &PyDbDbLayerStateManager::renameLayerState, DS.ARGS({ "sName: str","newsName: str" }, 5759))
        .def("importLayerState", &PyDbDbLayerStateManager::importLayerState, DS.ARGS({ "fName: str" }, 5751))
        .def("exportLayerState", &PyDbDbLayerStateManager::exportLayerState, DS.ARGS({ "sName: str","fName: str" }, 5743))
        .def("setLayerStateDescription", &PyDbDbLayerStateManager::setLayerStateDescription, DS.ARGS({ "sName: str","desc: str" }, 5762))
        .def("getLayerStateDescription", &PyDbDbLayerStateManager::getLayerStateDescription, DS.ARGS({ "sName: str" }, 5746))
        .def("layerStateHasViewportData", &PyDbDbLayerStateManager::layerStateHasViewportData, DS.ARGS({ "sName: str" }, 5754))
        .def("importLayerStateFromDb", &PyDbDbLayerStateManager::importLayerStateFromDb, DS.ARGS({ "sName: str","db: PyDb.Database" }, 5752))
        .def("getLayerStateNames", &PyDbDbLayerStateManager::getLayerStateNames, DS.ARGS({ "bIncludeHidden: bool","bIncludeXref: bool" }, 5749))
        .def("getLastRestoredLayerState", &PyDbDbLayerStateManager::getLastRestoredLayerState, DS.ARGS(5745))
        .def("getLayerStateLayers", &PyDbDbLayerStateManager::getLayerStateLayers, DS.ARGS({ "sName: str","invert: bool" }, 5747))
        .def("compareLayerStateToDb", &PyDbDbLayerStateManager::compareLayerStateToDb, DS.ARGS({ "sName: str","vpId: PyDb.ObjectId" }, 5741))
        .def("addLayerStateLayers", &PyDbDbLayerStateManager::addLayerStateLayers, DS.ARGS({ "sName: str","layerIds: list[PyDb.ObjectId]" }, 5739))
        .def("removeLayerStateLayers", &PyDbDbLayerStateManager::removeLayerStateLayers, DS.ARGS({ "sName: str","layerNames: list[str]" }, 5757))
        .def("isDependentLayerState", &PyDbDbLayerStateManager::isDependentLayerState, DS.ARGS({ "sName: str" }, 5753))
        .def("getDatabase", &PyDbDbLayerStateManager::getDatabase, DS.ARGS(5744))
        .def("desc", &PyDbDbLayerStateManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbDbLayerStateManager::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbDbLayerStateManager::PyDbDbLayerStateManager()
    :PyDbDbLayerStateManager(new AcDbLayerStateManager(), true)
{
}

PyDbDbLayerStateManager::PyDbDbLayerStateManager(const PyDbDatabase& db)
    :PyDbDbLayerStateManager(new AcDbLayerStateManager(db.impObj()), true)
{
}

PyDbDbLayerStateManager::PyDbDbLayerStateManager(AcDbLayerStateManager* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

PyDbObjectId PyDbDbLayerStateManager::layerStatesDictionaryId1() const
{
    return PyDbObjectId(impObj()->layerStatesDictionaryId());
}

PyDbObjectId PyDbDbLayerStateManager::layerStatesDictionaryId2(bool bCreateIfNotPresent) const
{
    return PyDbObjectId(impObj()->layerStatesDictionaryId(bCreateIfNotPresent));
}

bool PyDbDbLayerStateManager::hasLayerState(const std::string& sName) const
{
    return impObj()->hasLayerState(utf8_to_wstr(sName).c_str());
}

void PyDbDbLayerStateManager::saveLayerState1(const std::string& sName, AcDbLayerStateManager::LayerStateMask mask) const
{
    PyThrowBadEs(impObj()->saveLayerState(utf8_to_wstr(sName).c_str(), mask));
}

void PyDbDbLayerStateManager::saveLayerState2(const std::string& sName, AcDbLayerStateManager::LayerStateMask mask, const PyDbObjectId& idVp) const
{
    PyThrowBadEs(impObj()->saveLayerState(utf8_to_wstr(sName).c_str(), mask, idVp.m_id));
}

void PyDbDbLayerStateManager::restoreLayerState1(const std::string& sName) const
{
    PyThrowBadEs(impObj()->restoreLayerState(utf8_to_wstr(sName).c_str()));
}

void PyDbDbLayerStateManager::restoreLayerState2(const std::string& sName, const PyDbObjectId& idVp, int nRestoreFlags, AcDbLayerStateManager::LayerStateMask pClientMask) const
{
    const auto mask = pClientMask;
    PyThrowBadEs(impObj()->restoreLayerState(utf8_to_wstr(sName).c_str(), idVp.m_id, nRestoreFlags, &mask));
}

void PyDbDbLayerStateManager::setLayerStateMask(const std::string& sName, AcDbLayerStateManager::LayerStateMask mask) const
{
    PyThrowBadEs(impObj()->saveLayerState(utf8_to_wstr(sName).c_str(), mask));
}

AcDbLayerStateManager::LayerStateMask PyDbDbLayerStateManager::getLayerStateMask(const std::string& sName) const
{
    AcDbLayerStateManager::LayerStateMask returnMask = AcDbLayerStateManager::LayerStateMask::kNone;
    PyThrowBadEs(impObj()->getLayerStateMask(utf8_to_wstr(sName).c_str(), returnMask));
    return returnMask;
}

void PyDbDbLayerStateManager::deleteLayerState(const std::string& sName) const
{
    PyThrowBadEs(impObj()->deleteLayerState(utf8_to_wstr(sName).c_str()));
}

void PyDbDbLayerStateManager::renameLayerState(const std::string& sName, const std::string& sNewName) const
{
    PyThrowBadEs(impObj()->renameLayerState(utf8_to_wstr(sName).c_str(), utf8_to_wstr(sNewName).c_str()));
}

std::string PyDbDbLayerStateManager::importLayerState(const std::string& sFilename) const
{
    AcString sName;
    PyThrowBadEs(impObj()->importLayerState(utf8_to_wstr(sFilename).c_str(), sName));
    return wstr_to_utf8(sName);
}

void PyDbDbLayerStateManager::exportLayerState(const std::string& sNameToExport, const std::string& sFilename) const
{
    PyThrowBadEs(impObj()->exportLayerState(utf8_to_wstr(sNameToExport).c_str(), utf8_to_wstr(sFilename).c_str()));
}

void PyDbDbLayerStateManager::setLayerStateDescription(const std::string& sName, const std::string& sDesc) const
{
    PyThrowBadEs(impObj()->setLayerStateDescription(utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDesc).c_str()));
}

std::string PyDbDbLayerStateManager::getLayerStateDescription(const std::string& sName) const
{
#if defined(_ARXTARGET) && (_ARXTARGET >= 250)
    AcString sDesc;
    PyThrowBadEs(impObj()->getLayerStateDescription(utf8_to_wstr(sName).c_str(), sDesc));
    return wstr_to_utf8(sDesc);
#else
    RxAutoOutStr sDesc;
    PyThrowBadEs(impObj()->getLayerStateDescription(utf8_to_wstr(sName).c_str(), sDesc.buf));
    return sDesc.str();
#endif
}

bool PyDbDbLayerStateManager::layerStateHasViewportData(const std::string& sName) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->layerStateHasViewportData(utf8_to_wstr(sName).c_str());
#endif
}

void PyDbDbLayerStateManager::importLayerStateFromDb(const std::string& pStateName, PyDbDatabase& pDb) const
{
    PyThrowBadEs(impObj()->importLayerStateFromDb(utf8_to_wstr(pStateName).c_str(), pDb.impObj()));
}

boost::python::list PyDbDbLayerStateManager::getLayerStateNames(bool bIncludeHidden, bool bIncludeXref) const
{
    AcStringArray lsArray;
    PyThrowBadEs(impObj()->getLayerStateNames(lsArray, bIncludeHidden, bIncludeXref));
    return AcStringArrayToPyList(lsArray);
}

boost::python::tuple PyDbDbLayerStateManager::getLastRestoredLayerState() const
{
    AcString sName;
    PyDbObjectId restoredLSId;
    PyThrowBadEs(impObj()->getLastRestoredLayerState(sName, restoredLSId.m_id));
    return boost::python::make_tuple(wstr_to_utf8(sName), restoredLSId);
}

boost::python::list PyDbDbLayerStateManager::getLayerStateLayers(const std::string& sName, bool bInvert) const
{
    AcStringArray layerArray;
    PyThrowBadEs(impObj()->getLayerStateLayers(layerArray, utf8_to_wstr(sName).c_str(), bInvert));
    return AcStringArrayToPyList(layerArray);
}

bool PyDbDbLayerStateManager::compareLayerStateToDb(const std::string& sName, const PyDbObjectId& idVp) const
{
    return impObj()->compareLayerStateToDb(utf8_to_wstr(sName).c_str(), idVp.m_id);
}

void PyDbDbLayerStateManager::addLayerStateLayers(const std::string& sName, const boost::python::list& layerIds) const
{
    PyThrowBadEs(impObj()->addLayerStateLayers(utf8_to_wstr(sName).c_str(), PyListToObjectIdArray(layerIds)));
}

void PyDbDbLayerStateManager::removeLayerStateLayers(const std::string& sName, const boost::python::list& layerNames) const
{
    PyThrowBadEs(impObj()->removeLayerStateLayers(utf8_to_wstr(sName).c_str(), PyListToAcStringArray(layerNames)));
}

bool PyDbDbLayerStateManager::isDependentLayerState(const std::string& sName) const
{
    return impObj()->isDependentLayerState(utf8_to_wstr(sName).c_str());
}

PyDbDatabase PyDbDbLayerStateManager::getDatabase() const
{
    return PyDbDatabase(impObj()->getDatabase());
}

PyRxClass PyDbDbLayerStateManager::desc()
{
    return PyRxClass(AcDbLayerStateManager::desc(), false);
}

std::string PyDbDbLayerStateManager::className()
{
    return "AcDbLayerStateManager";
}

AcDbLayerStateManager* PyDbDbLayerStateManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbLayerStateManager*>(m_pyImp.get());
}
