#include "stdafx.h"
#include "PyEdUserInteraction.h"
#include "PyRxObject.h"
#include "PyDbObjectId.h"
#include "PyRxApp.h"
#include "PyApDocument.h"


using namespace boost::python;
//-----------------------------------------------------------------------------------------
// PyEdUserInteraction

void makePyEdUserInteractionWrapper()
{
    class_<PyEdUserInteraction>("UserInteraction")
        .def(init<>())
        .def(init<PyApDocument&, bool>())
        ;
}

PyEdUserInteraction::PyEdUserInteraction()
{
    userInteraction(acDocManagerPtr()->curDocument(), true);
}

PyEdUserInteraction::PyEdUserInteraction(AcApDocument* pDocument, bool prompting)
{
    userInteraction(pDocument, prompting);
}

PyEdUserInteraction::PyEdUserInteraction(PyApDocument& pDocument, bool prompting)
{
    userInteraction(pDocument.impObj(), prompting);
}

PyEdUserInteraction::~PyEdUserInteraction(void)
{
    undoUserInteraction();
}

void PyEdUserInteraction::userInteraction(AcApDocument* pDocument, bool prompting)
{
    AcApDocManager* pDocMan = acDocManagerPtr();
    if (pDocMan->curDocument() == pDocument)
    {
        pDocMan->disableDocumentActivation();
        if (!prompting)
            return;

        HWND hwMainWnd = adsw_acadMainWnd();
        if (::IsWindowEnabled(hwMainWnd) == TRUE)
            return;

        m_activeWindow = GetFocus();
        for (HWND window = ::GetActiveWindow(); window != NULL; window = ::GetWindow(window, GW_OWNER))
        {
            if (window == hwMainWnd)
                break;
            m_wnds.push_back(window);
        }
        ::EnableWindow(hwMainWnd, TRUE);
        ::SetFocus(hwMainWnd);
        for (size_t idx = 0; idx < m_wnds.size(); idx++)
        {
            ::ShowWindow(m_wnds[idx], SW_HIDE);
        }
    }
}

void PyEdUserInteraction::undoUserInteraction()
{
    acDocManagerPtr()->enableDocumentActivation();
    if (m_wnds.size() > 0)
    {
        for (std::vector<HWND>::reverse_iterator it = m_wnds.rbegin(); it != m_wnds.rend(); ++it)
            ::ShowWindow(*it, SW_SHOW);
        ::EnableWindow(adsw_acadMainWnd(), FALSE);
        ::SetFocus(m_activeWindow);
    }
}

//-----------------------------------------------------------------------------------------
// PyEdUIContext
void makePyEdUIContextWrapper()
{
    class_<PyEdUIContext>("UIContext")
        .def("getMenuContext", &PyEdUIContext::getMenuContextWr)
        .def("onCommand", &PyEdUIContext::onCommandWr)
        .def("OnUpdateMenu", &PyEdUIContext::OnUpdateMenuWr)
        .def("hitPoint", &PyEdUIContext::hitPoint)
        .def("addObjectContextMenu", &PyEdUIContext::addObjectContextMenu).staticmethod("addObjectContextMenu")
        .def("removeObjectContextMenu", &PyEdUIContext::removeObjectContextMenu).staticmethod("removeObjectContextMenu")
        .def("addDefaultContextMenu", &PyEdUIContext::addDefaultContextMenu1)
        .def("addDefaultContextMenu", &PyEdUIContext::addDefaultContextMenu2).staticmethod("addDefaultContextMenu")
        .def("removeDefaultContextMenu", &PyEdUIContext::removeDefaultContextMenu).staticmethod("removeDefaultContextMenu")
        ;
}

PyEdUIContext::PyEdUIContext()
{
}

PyEdUIContext::~PyEdUIContext()
{
    if (m_isAlive)
    {
        acutPrintf(_T("PyEdUIContext was not removed"));
    }
}

void* PyEdUIContext::getMenuContext(const AcRxClass* pClass, const AcDbObjectIdArray& ids)
{
    calcHitPoint();
    PyAutoLockGIL lock;
    boost::python::list pyids;
    for (const auto& id : ids)
        pyids.append(PyDbObjectId(id));
    PyRxClass _pClass(const_cast<AcRxClass*>(pClass), false);
    const boost::python::object obj = this->getMenuContextWr(_pClass, pyids);
    if (wxPyWrappedPtr_TypeCheck(obj.ptr(), _T("wxMenu")))
    {
        wxMenu* pMenu = nullptr;
        wxPyConvertWrappedPtr(obj.ptr(), (void**)&pMenu, wxT("wxMenu"));
        if (pMenu != nullptr)
        {
            m_hmenu = pMenu->GetHMenu();
            return &m_hmenu;
        }
        else
        {
            m_hmenu = 0;
        }
    }
    return nullptr;
}

void PyEdUIContext::onCommand(Adesk::UInt32 cmd)
{
    this->onCommandWr(cmd);
}

void PyEdUIContext::OnUpdateMenu()
{
    this->OnUpdateMenuWr();
}

AcGePoint3d PyEdUIContext::hitPoint() const
{
    return m_hitPoint;
}

boost::python::object PyEdUIContext::getMenuContextWr(const PyRxClass& pyclass, const boost::python::list& pyids)
{
    PyAutoLockGIL lock;
    boost::python::object val;
    try
    {
        if (override f = this->get_override("getMenuContext"))
        {
            val = f(pyclass, pyids);
            return val;
        }
    }
    catch (...)
    {
        printExceptionMsg();
    }
    return val;
}

void PyEdUIContext::onCommandWr(Adesk::UInt32 cmd)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("onCommand"))
            f(cmd);
    }
    catch (...)
    {
        printExceptionMsg();
    }
}

void PyEdUIContext::OnUpdateMenuWr()
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("OnUpdateMenu"))
            f();
    }
    catch (...)
    {
        printExceptionMsg();
    }
}

void PyEdUIContext::calcHitPoint()
{
    CPoint cursorPos;
    ::GetCursorPos(&cursorPos);
    ScreenToClient(adsw_acadDocWnd(), &cursorPos);

    acedDwgPoint cpt;
    acedCoordFromPixelToWorld(cursorPos, cpt);

    resbuf fromrb;
    fromrb.restype = RTSHORT;
    fromrb.resval.rint = 2; // DCS

    resbuf torb;
    torb.restype = RTSHORT;
    torb.resval.rint = 0; // WCS 

    acedTrans(cpt, &fromrb, &torb, FALSE, asDblArray(m_hitPoint));
}

bool PyEdUIContext::addObjectContextMenu(PyRxClass& pClass, PyEdUIContext& pContext)
{
    if (pContext.m_isAlive)
        throw PyAcadErrorStatus(eInvalidInput);
    pContext.m_isAlive = acedAddObjectContextMenu(pClass.impObj(), std::addressof(pContext), PyRxApp::instance().appPkt);
    return pContext.m_isAlive;
}

bool PyEdUIContext::removeObjectContextMenu(PyRxClass& pClass, PyEdUIContext& pContext)
{
    if (!pContext.m_isAlive)
        throw PyAcadErrorStatus(eInvalidInput);
    pContext.m_isAlive = !acedRemoveObjectContextMenu(pClass.impObj(), std::addressof(pContext));
    return  !pContext.m_isAlive;
}

bool PyEdUIContext::addDefaultContextMenu1(PyEdUIContext& pContext)
{
    if (pContext.m_isAlive)
        throw PyAcadErrorStatus(eInvalidInput);
    pContext.m_isAlive = acedAddDefaultContextMenu(std::addressof(pContext), PyRxApp::instance().appPkt);
    return pContext.m_isAlive;
}

bool PyEdUIContext::addDefaultContextMenu2(PyEdUIContext& pContext, const std::string& appName)
{
    if (pContext.m_isAlive)
        throw PyAcadErrorStatus(eInvalidInput);
    pContext.m_isAlive = acedAddDefaultContextMenu(std::addressof(pContext), PyRxApp::instance().appPkt, utf8_to_wstr(appName).c_str());
    return pContext.m_isAlive;
}

bool PyEdUIContext::removeDefaultContextMenu(PyEdUIContext& pContext)
{
    if (!pContext.m_isAlive)
        throw PyAcadErrorStatus(eInvalidInput);
    pContext.m_isAlive = !acedRemoveDefaultContextMenu(std::addressof(pContext));
    return !pContext.m_isAlive;
}
