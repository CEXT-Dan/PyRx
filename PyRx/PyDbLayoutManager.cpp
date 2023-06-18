#include "stdafx.h"
#include "PyDbLayoutManager.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "PyDbLayout.h"

using namespace boost::python;

void makePyDbLayoutManagerWrapper()
{
    class_<PyDbLayoutManager, bases<PyRxObject>>("LayoutManager")
        .def("setCurrentLayout", &PyDbLayoutManager::setCurrentLayout1)
        .def("setCurrentLayout", &PyDbLayoutManager::setCurrentLayout2)
        .def("setCurrentLayoutId", &PyDbLayoutManager::setCurrentLayoutId)
        .def("getActiveLayoutName", &PyDbLayoutManager::getActiveLayoutName1)
        .def("getActiveLayoutName", &PyDbLayoutManager::getActiveLayoutName2)
        .def("getActiveLayoutBTRId", &PyDbLayoutManager::getActiveLayoutBTRId1)
        .def("getActiveLayoutBTRId", &PyDbLayoutManager::getActiveLayoutBTRId2)
        .def("findLayoutNamed", &PyDbLayoutManager::findLayoutNamed1)
        .def("findLayoutNamed", &PyDbLayoutManager::findLayoutNamed2)
        .def("layoutExists", &PyDbLayoutManager::layoutExists1)
        .def("layoutExists", &PyDbLayoutManager::layoutExists2)
        .def("copyLayout", &PyDbLayoutManager::copyLayout1)
        .def("copyLayout", &PyDbLayoutManager::copyLayout2)
        .def("deleteLayout", &PyDbLayoutManager::deleteLayout1)
        .def("deleteLayout", &PyDbLayoutManager::deleteLayout2)
        .def("createLayout", &PyDbLayoutManager::createLayout1)
        .def("createLayout", &PyDbLayoutManager::createLayout2)
        .def("renameLayout", &PyDbLayoutManager::renameLayout1)
        .def("renameLayout", &PyDbLayoutManager::renameLayout2)
        .def("cloneLayout", &PyDbLayoutManager::cloneLayout1)
        .def("cloneLayout", &PyDbLayoutManager::cloneLayout2)
        .def("getNonRectVPIdFromClipId", &PyDbLayoutManager::getNonRectVPIdFromClipId)
        .def("isVpnumClipped", &PyDbLayoutManager::isVpnumClipped1)
        .def("isVpnumClipped", &PyDbLayoutManager::isVpnumClipped2)
        .def("countLayouts", &PyDbLayoutManager::countLayouts1)
        .def("countLayouts", &PyDbLayoutManager::countLayouts2)
        .def("setupForLayouts", &PyDbLayoutManager::setupForLayouts).staticmethod("setupForLayouts")
        .def("clearSetupForLayouts", &PyDbLayoutManager::clearSetupForLayouts).staticmethod("clearSetupForLayouts")
        .def("desc", &PyDbLayoutManager::desc).staticmethod("desc")
        .def("className", &PyDbLayoutManager::className).staticmethod("className")
        ;
}

PyDbLayoutManager::PyDbLayoutManager()
    : PyDbLayoutManager(acdbHostApplicationServices()->layoutManager(), false)
{
}

PyDbLayoutManager::PyDbLayoutManager(AcDbLayoutManager* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

Acad::ErrorStatus PyDbLayoutManager::setCurrentLayout1(const std::string& newname)
{
    return impObj()->setCurrentLayout(utf8_to_wstr(newname).c_str());
}

Acad::ErrorStatus PyDbLayoutManager::setCurrentLayout2(const std::string& newname, PyDbDatabase& pDb)
{
    return impObj()->setCurrentLayout(utf8_to_wstr(newname).c_str(), pDb.impObj());
}

Acad::ErrorStatus PyDbLayoutManager::setCurrentLayoutId(const PyDbObjectId& layoutId)
{
    return impObj()->setCurrentLayoutId(layoutId.m_id);
}

std::string PyDbLayoutManager::getActiveLayoutName1(bool allowModel)
{
    AcString sName;
    if (auto es = impObj()->getActiveLayoutName(sName, allowModel); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(sName);
}

std::string PyDbLayoutManager::getActiveLayoutName2(bool allowModel, PyDbDatabase& pDb)
{
    AcString sName;
    if (auto es = impObj()->getActiveLayoutName(sName, allowModel, pDb.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(sName);
}

PyDbObjectId PyDbLayoutManager::getActiveLayoutBTRId1()
{
    return PyDbObjectId(impObj()->getActiveLayoutBTRId());
}

PyDbObjectId PyDbLayoutManager::getActiveLayoutBTRId2(const PyDbDatabase& pDb)
{
    return PyDbObjectId(impObj()->getActiveLayoutBTRId(pDb.impObj()));
}

PyDbObjectId PyDbLayoutManager::findLayoutNamed1(const std::string& name)
{
    return PyDbObjectId(impObj()->findLayoutNamed(utf8_to_wstr(name).c_str()));
}

PyDbObjectId PyDbLayoutManager::findLayoutNamed2(const std::string& name, const PyDbDatabase& pDb)
{
    return PyDbObjectId(impObj()->findLayoutNamed(utf8_to_wstr(name).c_str(), pDb.impObj()));
}

bool PyDbLayoutManager::layoutExists1(const std::string& name)
{
    return impObj()->layoutExists(utf8_to_wstr(name).c_str());
}

bool PyDbLayoutManager::layoutExists2(const std::string& name, const PyDbDatabase& pDb)
{
    return impObj()->layoutExists(utf8_to_wstr(name).c_str(),pDb.impObj());
}

Acad::ErrorStatus PyDbLayoutManager::copyLayout1(const std::string& copyname, const std::string& newname)
{
    return impObj()->copyLayout(utf8_to_wstr(copyname).c_str(), utf8_to_wstr(newname).c_str());
}

Acad::ErrorStatus PyDbLayoutManager::copyLayout2(const std::string& copyname, const std::string& newname, const PyDbDatabase& pDb)
{
    return impObj()->copyLayout(utf8_to_wstr(copyname).c_str(), utf8_to_wstr(newname).c_str(), pDb.impObj());
}

Acad::ErrorStatus PyDbLayoutManager::deleteLayout1(const std::string& delname)
{
    return impObj()->deleteLayout(utf8_to_wstr(delname).c_str());
}

Acad::ErrorStatus PyDbLayoutManager::deleteLayout2(const std::string& delname, PyDbDatabase& pDb)
{
    return impObj()->deleteLayout(utf8_to_wstr(delname).c_str(), pDb.impObj());
}

Acad::ErrorStatus PyDbLayoutManager::createLayout1(const std::string& newname, PyDbObjectId& layoutId, PyDbObjectId& blockTableRecId)
{
    return impObj()->createLayout(utf8_to_wstr(newname).c_str(), layoutId.m_id, blockTableRecId.m_id);
}

Acad::ErrorStatus PyDbLayoutManager::createLayout2(const std::string& newname, PyDbObjectId& layoutId, PyDbObjectId& blockTableRecId, PyDbDatabase& pDb)
{
    return impObj()->createLayout(utf8_to_wstr(newname).c_str(), layoutId.m_id, blockTableRecId.m_id, pDb.impObj());
}

Acad::ErrorStatus PyDbLayoutManager::renameLayout1(const std::string& oldname, const std::string& newname)
{
    return impObj()->renameLayout(utf8_to_wstr(oldname).c_str(), utf8_to_wstr(newname).c_str());
}

Acad::ErrorStatus PyDbLayoutManager::renameLayout2(const std::string& oldname, const std::string& newname, PyDbDatabase& pDb)
{
    return impObj()->renameLayout(utf8_to_wstr(oldname).c_str(), utf8_to_wstr(newname).c_str(), pDb.impObj());
}

Acad::ErrorStatus PyDbLayoutManager::cloneLayout1(PyDbLayout& pLBTR, const std::string& newname)
{
    return impObj()->cloneLayout(pLBTR.impObj(), utf8_to_wstr(newname).c_str());
}

Acad::ErrorStatus PyDbLayoutManager::cloneLayout2(PyDbLayout& pLBTR, const std::string& newname, int newTabOrder, PyDbDatabase& pDb)
{
    return impObj()->cloneLayout(pLBTR.impObj(), utf8_to_wstr(newname).c_str(), newTabOrder, pDb.impObj());
}

PyDbObjectId PyDbLayoutManager::getNonRectVPIdFromClipId(PyDbObjectId& clipId)
{
    return PyDbObjectId(impObj()->getNonRectVPIdFromClipId(clipId.m_id));
}

bool PyDbLayoutManager::isVpnumClipped1(int index)
{
    return impObj()->isVpnumClipped(index);
}

bool PyDbLayoutManager::isVpnumClipped2(int index, const PyDbDatabase& pDb)
{
    return impObj()->isVpnumClipped(index, pDb.impObj());
}

int PyDbLayoutManager::countLayouts1()
{
    return impObj()->countLayouts();
}

int PyDbLayoutManager::countLayouts2(PyDbDatabase& pDb)
{
    return impObj()->countLayouts(pDb.impObj());
}

Adesk::ULongPtr PyDbLayoutManager::setupForLayouts(PyDbDatabase& pDb)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    Adesk::ULongPtr contextHandle = 0;
    if (auto es = acdbDoSetupForLayouts(pDb.impObj(), contextHandle); es != eOk)
        throw PyAcadErrorStatus(es);
    return contextHandle;
#endif
}

Acad::ErrorStatus PyDbLayoutManager::clearSetupForLayouts(Adesk::ULongPtr contextHandle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return acdbClearSetupForLayouts(contextHandle);
#endif
}

PyRxClass PyDbLayoutManager::desc()
{
    return PyRxClass(AcDbLayoutManager::desc(), false);
}

std::string PyDbLayoutManager::className()
{
    return "AcDbLayoutManager";
}

AcDbLayoutManager* PyDbLayoutManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbLayoutManager*>(m_pyImp.get());
}
