#include "stdafx.h"
#include "PyEdUserInteraction.h"
#include "PyRxObject.h"
#include "PyDbObjectId.h"
#include "PyRxApp.h"
#include "PyApDocument.h"
#include "EdCore.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
// PySysVar
void makePySysVarWrapper()
{
    PyDocString DS("AutoSysVar");
    class_<PySysVar>("AutoSysVar", no_init)
        .def(init<const std::string&, const boost::python::object& >(DS.ARGS({ "varName:str","value" })))
        .def("detach", &PySysVar::detach, DS.ARGS({ "val: bool" }))
        ;
}

//-----------------------------------------------------------------------------------------
// PySysVarImpl
PySysVarImpl::PySysVarImpl(const std::string& name, const boost::python::object& obj)
    : m_name(name)
{
    set(name, obj);
}

PySysVarImpl::~PySysVarImpl(void)
{
    clear();
}

void PySysVarImpl::detach(bool flag)
{
    m_doit = !flag;
}

void PySysVarImpl::set(const std::string& name, const boost::python::object& obj)
{
    static constexpr const TCHAR* errmsg = _T("\nPySysVar::set failed!: ");
    try
    {
        m_oldobj = EdCore::getVar(name);
        if (!EdCore::setVar(name, obj))
        {
            m_doit = false;
            acutPrintf(errmsg);
        }
    }
    catch (...)
    {
        m_doit = false;
        acutPrintf(errmsg);
    }
}

void PySysVarImpl::clear() const
{
    try
    {
        if (m_doit)
        {
            EdCore::setVar(m_name, m_oldobj);
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nPySysVar::clear failed!: "));
    }
}

//-----------------------------------------------------------------------------------------
// PySysVarImpl
PySysVar::PySysVar(const std::string& name, const boost::python::object& obj)
    : m_impl(new PySysVarImpl(name, obj))
{
}

void PySysVar::detach(bool flag)
{
    if (m_impl != nullptr)
        m_impl->detach(flag);
}

//-----------------------------------------------------------------------------------------
// PyEdUserInteraction
void makePyEdUserInteractionWrapper()
{
    PyDocString DS("UserInteraction");
    class_<PyEdUserInteraction>("UserInteraction")
        .def(init<>())
        .def(init<PyApDocument&, bool>(DS.ARGS({ "doc:PyAp.Document='current'","isPrompting:bool=True" })))
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
    PyDocString DS("UIContext");
    class_<PyEdUIContext>("UIContext")
        .def(init<>(DS.ARGS()))
        .def("getMenuContext", &PyEdUIContext::getMenuContextWr, DS.ARGS({ "val: PyRx.RxClass","ids: list[PyDb.ObjectId]" }))
        .def("onCommand", &PyEdUIContext::onCommandWr, DS.ARGS({ "mnuCmd: int" }))
        .def("OnUpdateMenu", &PyEdUIContext::OnUpdateMenuWr, DS.ARGS())
        .def("hitPoint", &PyEdUIContext::hitPoint, DS.ARGS())
        .def("addObjectContextMenu", &PyEdUIContext::addObjectContextMenu, DS.SARGS({ "val: PyRx.RxClass","context: PyEd.UIContext" })).staticmethod("addObjectContextMenu")
        .def("removeObjectContextMenu", &PyEdUIContext::removeObjectContextMenu, DS.SARGS({ "val: PyRx.RxClass","context: PyEd.UIContext" })).staticmethod("removeObjectContextMenu")
        .def("addDefaultContextMenu", &PyEdUIContext::addDefaultContextMenu1)
        .def("addDefaultContextMenu", &PyEdUIContext::addDefaultContextMenu2, DS.SARGS({ "context: PyEd.UIContext","appName: str = ..." })).staticmethod("addDefaultContextMenu")
        .def("removeDefaultContextMenu", &PyEdUIContext::removeDefaultContextMenu, DS.SARGS({ "context: PyEd.UIContext" })).staticmethod("removeDefaultContextMenu")
        ;
}

PyEdUIContext::PyEdUIContext()
{
}

#ifdef _BRXTARGET_COPY_CTOR
PyEdUIContext::PyEdUIContext(const PyEdUIContext&)
    : AcEdUIContext()
{
    PyThrowBadEs(eNotApplicable);
}
#endif

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
    try
    {
        if (const override& f = this->get_override("getMenuContext"))
        {
            return f(pyclass, pyids);
        }
    }
    catch (...)
    {
        printExceptionMsg();
    }
    return boost::python::object();
}

void PyEdUIContext::onCommandWr(Adesk::UInt32 cmd)
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("onCommand"))
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
        if (const override& f = this->get_override("OnUpdateMenu"))
            f();
    }
    catch (...)
    {
        printExceptionMsg();
    }
}

void PyEdUIContext::calcHitPoint() const
{
    CPoint cursorPos;
    ::GetCursorPos(&cursorPos);
    ScreenToClient(adsw_acadDocWnd(), &cursorPos);

    acedDwgPoint cpt;
    acedCoordFromPixelToWorld(cursorPos, cpt);

    resbuf fromrb{};
    fromrb.restype = RTSHORT;
    fromrb.resval.rint = 2; // DCS

    resbuf torb{};
    torb.restype = RTSHORT;
    torb.resval.rint = 0; // WCS 

    acedTrans(cpt, &fromrb, &torb, FALSE, asDblArray(m_hitPoint));
}

bool PyEdUIContext::addObjectContextMenu(PyRxClass& pClass, PyEdUIContext& pContext)
{
    if (pContext.m_isAlive)
        throw PyErrorStatusException(Acad::eAlreadyActive);
    pContext.m_isAlive = acedAddObjectContextMenu(pClass.impObj(), std::addressof(pContext), PyRxApp::instance().appPkt);
    return pContext.m_isAlive;
}

bool PyEdUIContext::removeObjectContextMenu(PyRxClass& pClass, PyEdUIContext& pContext)
{
    if (!pContext.m_isAlive)
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    pContext.m_isAlive = !acedRemoveObjectContextMenu(pClass.impObj(), std::addressof(pContext));
    return  !pContext.m_isAlive;
}

bool PyEdUIContext::addDefaultContextMenu1(PyEdUIContext& pContext)
{
    if (pContext.m_isAlive)
        throw PyErrorStatusException(Acad::eAlreadyActive);
    pContext.m_isAlive = acedAddDefaultContextMenu(std::addressof(pContext), PyRxApp::instance().appPkt);
    return pContext.m_isAlive;
}

bool PyEdUIContext::addDefaultContextMenu2(PyEdUIContext& pContext, const std::string& appName)
{
    if (pContext.m_isAlive)
        throw PyErrorStatusException(Acad::eAlreadyActive);
    pContext.m_isAlive = acedAddDefaultContextMenu(std::addressof(pContext), PyRxApp::instance().appPkt, utf8_to_wstr(appName).c_str());
    return pContext.m_isAlive;
}

bool PyEdUIContext::removeDefaultContextMenu(PyEdUIContext& pContext)
{
    if (!pContext.m_isAlive)
        throw PyErrorStatusException(Acad::eNotInitializedYet);
    pContext.m_isAlive = !acedRemoveDefaultContextMenu(std::addressof(pContext));
    return !pContext.m_isAlive;
}
