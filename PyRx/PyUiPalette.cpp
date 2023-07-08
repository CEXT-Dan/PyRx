#include "stdafx.h"
#include "PyUiPalette.h"

using namespace boost::python;

//---------------------------------------------------------------------
//PyCAdUiPaletteSetImpl

IMPLEMENT_DYNCREATE(PyCAdUiPaletteSetImpl, CAdUiPaletteSet)

BEGIN_MESSAGE_MAP(PyCAdUiPaletteSetImpl, CAdUiPaletteSet)
    ON_WM_CREATE()
    ON_WM_DESTROY()
END_MESSAGE_MAP()

PyCAdUiPaletteSetImpl::PyCAdUiPaletteSetImpl()
{
}

PyCAdUiPaletteSetImpl::PyCAdUiPaletteSetImpl(PyCAdUiPaletteSet* bckPtr)
    : m_bckPtr(bckPtr)
{
}

int PyCAdUiPaletteSetImpl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CAdUiPaletteSet::OnCreate(lpCreateStruct) == -1)
        return -1;
    return 0;
}

void PyCAdUiPaletteSetImpl::OnDestroy()
{
    CAdUiPaletteSet::OnDestroy();
}

PyCAdUiPaletteSet* PyCAdUiPaletteSetImpl::bckptr(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_bckPtr == nullptr)
        throw PyNullObject(src);
    return m_bckPtr;
}

//---------------------------------------------------------------------
//PyCAdUiPaletteSet
void makePyCAdUiPaletteSetWrapper()
{
    class_<PyCAdUiPaletteSet>("PaletteSet", no_init)
        .def(init<const std::string&>())
        .def(init<const std::string&, const std::string&>())
        .def("add", &PyCAdUiPaletteSet::add)
        .def("setVisible", &PyCAdUiPaletteSet::setVisible)
        .def("getPaletteSetStyle", &PyCAdUiPaletteSet::getPaletteSetStyle)
        .def("setPaletteSetStyle", &PyCAdUiPaletteSet::setPaletteSetStyle)
        .def("autoRollupStyle", &PyCAdUiPaletteSet::autoRollupStyle)
        .def("propertiesMenuStyle", &PyCAdUiPaletteSet::propertiesMenuStyle)
        .def("closeButtonStyle", &PyCAdUiPaletteSet::closeButtonStyle)
        .def("singlePaletteTabStyle", &PyCAdUiPaletteSet::singlePaletteTabStyle)
        .def("useSinglePaletteTabNameStyle", &PyCAdUiPaletteSet::useSinglePaletteTabNameStyle)
        .def("editNameStyle", &PyCAdUiPaletteSet::editNameStyle)
        .def("snapStyle", &PyCAdUiPaletteSet::snapStyle)
        .def("showRollupButtonStyle", &PyCAdUiPaletteSet::showRollupButtonStyle)
        .def("showIconStyle", &PyCAdUiPaletteSet::showIconStyle)
        .def("getName", &PyCAdUiPaletteSet::getName)
        .def("setName", &PyCAdUiPaletteSet::setName)
        .def("getOpacity", &PyCAdUiPaletteSet::getOpacity)
        .def("setOpacity", &PyCAdUiPaletteSet::setOpacity)
        .def("getRolloverOpacity", &PyCAdUiPaletteSet::getRolloverOpacity)
        .def("setRolloverOpacity", &PyCAdUiPaletteSet::setRolloverOpacity)
        .def("getActivePaletteTabIndex", &PyCAdUiPaletteSet::getActivePaletteTabIndex)
        .def("setActivePalette", &PyCAdUiPaletteSet::setActivePalette)
        .def("setAutoRollup", &PyCAdUiPaletteSet::setAutoRollup)
        .def("getAutoRollup", &PyCAdUiPaletteSet::getAutoRollup)
        .def("rollOut", &PyCAdUiPaletteSet::rollOut1)
        .def("rollOut", &PyCAdUiPaletteSet::rollOut2)
        .def("rollUp", &PyCAdUiPaletteSet::rollUp)
        .def("removePalette", &PyCAdUiPaletteSet::removePalette)
        .def("getPaletteCount", &PyCAdUiPaletteSet::getPaletteCount)
        .def("getFullRect", &PyCAdUiPaletteSet::getFullRect)
        .def("rolledUp", &PyCAdUiPaletteSet::rolledUp)
        .def("titleBarLocation", &PyCAdUiPaletteSet::titleBarLocation)
        .def("setTitleBarLocation", &PyCAdUiPaletteSet::setTitleBarLocation)
        .def("updateTabs", &PyCAdUiPaletteSet::updateTabs)
        ;
    enum_<CAdUiPaletteSet::AdUiTitleBarLocation>("AdUiTitleBarLocation")
        .value("kLeft", CAdUiPaletteSet::AdUiTitleBarLocation::kLeft)
        .value("kRight", CAdUiPaletteSet::AdUiTitleBarLocation::kRight)
        .export_values()
        ;
}

PyCAdUiPaletteSet::PyCAdUiPaletteSet(const std::string& name)
    : m_pyImp(nullptr)
{
    CAcModuleResourceOverride resourceOverride;
    m_pyImp.reset(new PyCAdUiPaletteSetImpl(this));
    impObj()->SetName(utf8_to_wstr(name).c_str());

#ifdef NEVER  //TODO, test if this is the case!
    GUID id;
    HRESULT hr = CoCreateGuid(&id);
    impObj()->SetToolID(&id);
#endif
}

PyCAdUiPaletteSet::PyCAdUiPaletteSet(const std::string& name, const std::string& guid)
{
    CAcModuleResourceOverride resourceOverride;
    m_pyImp.reset(new PyCAdUiPaletteSetImpl(this));
    impObj()->SetName(utf8_to_wstr(name).c_str());

    GUID id;
    CString sguid = utf8_to_wstr(guid).c_str();
    HRESULT hr = CLSIDFromString(sguid, (LPCLSID)&id);
    if (hr != S_OK)
    {
        acutPrintf(_T("BAD GUID"));
        return;
    }
    impObj()->SetToolID(&id);
}

int PyCAdUiPaletteSet::add(const std::string& name, boost::python::object& panel)
{
    CAcModuleResourceOverride resourceOverride;
    if (wxPyWrappedPtr_TypeCheck(panel.ptr(), _T("wxPanel")))
    {
        wxPanel* pPanel = nullptr;
        wxPyConvertWrappedPtr(panel.ptr(), (void**)&pPanel, wxT("wxPanel"));
        if (pPanel != nullptr)
            m_children.push_back(PyCAdUiPalette(name, pPanel));
    }
    return 0;
}

bool PyCAdUiPaletteSet::create()
{
    if (m_created)
        return true;
    CAcModuleResourceOverride resourceOverride;
    CRect rect(0, 0, 275, 500);
    impObj()->Create(
        impObj()->GetName(),
        WS_OVERLAPPED | WS_DLGFRAME,
        rect,
        acedGetAcadFrame(),
        PSS_AUTO_ROLLUP | PSS_CLOSE_BUTTON
    );
    impObj()->EnableDocking(CBRS_ALIGN_LEFT | CBRS_ALIGN_RIGHT);
    createChildren();
    m_created = true;
    return m_created;
}

void PyCAdUiPaletteSet::setVisible(bool show)
{
    if (impObj() != nullptr && create())
    {
        CMDIFrameWnd* pAcadFrame = acedGetAcadFrame();
        impObj()->RestoreControlBar();
        pAcadFrame->ShowControlBar(impObj(), show, FALSE);
    }
}

void PyCAdUiPaletteSet::createChildren()
{
    for (auto& child : m_children)
    {
        if(child.impObj()->Create(WS_CHILD | WS_VISIBLE, child.impObj()->GetName(), impObj()) == FALSE)
            acutPrintf(_T("Failed to Create palette: "));
        if (impObj()->AddPalette(child.impObj()) == -1)
            acutPrintf(_T("Failed to add palette: "));
    }
}

DWORD PyCAdUiPaletteSet::getPaletteSetStyle()
{
    return impObj()->GetPaletteSetStyle();
}

void PyCAdUiPaletteSet::setPaletteSetStyle(DWORD dwStyle)
{
    return impObj()->SetPaletteSetStyle(dwStyle);
}

bool PyCAdUiPaletteSet::autoRollupStyle()
{
    return impObj()->AutoRollupStyle() == TRUE;
}

bool PyCAdUiPaletteSet::propertiesMenuStyle()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->PropertiesMenuStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::closeButtonStyle()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->CloseButtonStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::singlePaletteTabStyle()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->SinglePaletteTabStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::useSinglePaletteTabNameStyle()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->UseSinglePaletteTabNameStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::editNameStyle()
{
    return impObj()->EditNameStyle() == TRUE;
}

bool PyCAdUiPaletteSet::snapStyle()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->SnapStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::showRollupButtonStyle()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->ShowRollupButtonStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::showIconStyle()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->ShowIconStyle() == TRUE;
#endif
}

std::string PyCAdUiPaletteSet::getName()
{
    return wstr_to_utf8(impObj()->GetName());
}

bool PyCAdUiPaletteSet::setName(const std::string& name)
{
    return impObj()->SetName(utf8_to_wstr(name).c_str()) == TRUE;
}

int PyCAdUiPaletteSet::getOpacity() const
{
    return impObj()->GetOpacity();
}

bool PyCAdUiPaletteSet::setOpacity(int nOpacity)
{
    return impObj()->SetOpacity(nOpacity) == TRUE;
}

int PyCAdUiPaletteSet::getRolloverOpacity() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->GetRolloverOpacity();
#endif
}

bool PyCAdUiPaletteSet::setRolloverOpacity(int nOpacity)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->SetRolloverOpacity(nOpacity) == TRUE;
#endif
}

int PyCAdUiPaletteSet::getActivePaletteTabIndex()
{
    return impObj()->GetActivePaletteTabIndex();
}

bool PyCAdUiPaletteSet::setActivePalette(int nPaletteIndex)
{
    return impObj()->SetActivePalette(nPaletteIndex) == TRUE;
}

bool PyCAdUiPaletteSet::setAutoRollup(bool flag)
{
    return impObj()->SetAutoRollup(flag ? 1 : 0) == TRUE;
}

bool PyCAdUiPaletteSet::getAutoRollup()
{
    return impObj()->GetAutoRollup() == TRUE;
}

void PyCAdUiPaletteSet::rollOut1()
{
    return impObj()->RollOut();
}
void PyCAdUiPaletteSet::rollOut2(bool bDelay)
{
    return impObj()->RollOut(bDelay);
}

void PyCAdUiPaletteSet::rollUp()
{
    return impObj()->RollUp();
}

bool PyCAdUiPaletteSet::removePalette(int nPaletteIndex)
{
    return impObj()->RemovePalette(nPaletteIndex) == TRUE;
}

int PyCAdUiPaletteSet::getPaletteCount()
{
    return impObj()->GetPaletteCount();
}

PyObject* PyCAdUiPaletteSet::getFullRect()
{
    PyAutoLockGIL lock;
    CRect rect;
    impObj()->GetFullRect(rect);
    wxRect _wxRect(rect.left, rect.top, rect.right, rect.bottom);
    return wxPyConstructObject(&_wxRect, "wxRect");
}

bool PyCAdUiPaletteSet::rolledUp()
{
    return impObj()->RolledUp() == TRUE;
}

CAdUiPaletteSet::AdUiTitleBarLocation PyCAdUiPaletteSet::titleBarLocation()
{
    return impObj()->TitleBarLocation();
}

void PyCAdUiPaletteSet::setTitleBarLocation(CAdUiPaletteSet::AdUiTitleBarLocation loc)
{
    return impObj()->SetTitleBarLocation(loc);
}

void PyCAdUiPaletteSet::updateTabs()
{
    return impObj()->UpdateTabs();
}

PyCAdUiPaletteSetImpl* PyCAdUiPaletteSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<PyCAdUiPaletteSetImpl*>(m_pyImp.get());
}


//---------------------------------------------------------------------
//PyCAdUiPaletteImpl
IMPLEMENT_DYNAMIC(PyCAdUiPaletteImpl, CAdUiPalette)

BEGIN_MESSAGE_MAP(PyCAdUiPaletteImpl, CAdUiPalette)
    ON_WM_CREATE()
    ON_WM_SIZE()
END_MESSAGE_MAP()

PyCAdUiPaletteImpl::PyCAdUiPaletteImpl()
{
}

PyCAdUiPaletteImpl::PyCAdUiPaletteImpl(PyCAdUiPalette* bckPtr, wxPanel* panel)
    : m_bckPtr(bckPtr), m_panel(panel)
{
}

int PyCAdUiPaletteImpl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CAdUiPalette::OnCreate(lpCreateStruct) == -1)
        return -1;
    CAcModuleResourceOverride resourceOverride;
    m_thiswin = new wxWindow();
    thiswindow()->SetHWND((WXHWND)this->GetSafeHwnd());
    thiswindow()->AdoptAttributesFromHWND();
    panel()->Create(thiswindow(), -1, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS | wxTAB_TRAVERSAL);
    return 0;
}

void PyCAdUiPaletteImpl::OnSize(UINT nType, int cx, int cy)
{
    CRect rect;
    CAdUiPalette::OnSize(nType, cx, cy);
    GetClientRect(rect);
    CAcModuleResourceOverride resourceOverride;
    panel()->SetSize(rect.left, rect.top, rect.right, rect.bottom);
}

wxWindow* PyCAdUiPaletteImpl::thiswindow(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_thiswin == nullptr)
        throw PyNullObject(src);
    return m_thiswin;
}

wxPanel* PyCAdUiPaletteImpl::panel(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_panel == nullptr)
        throw PyNullObject(src);
    return m_panel;
}

PyCAdUiPalette* PyCAdUiPaletteImpl::bckptr(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_bckPtr == nullptr)
        throw PyNullObject(src);
    return m_bckPtr;
}

//---------------------------------------------------------------------
//PyCAdUiPalette
void makePyCAdUiPaletteWrapper()
{

}

PyCAdUiPalette::PyCAdUiPalette(const std::string& name, wxPanel* panel)
    :m_pyImp(nullptr)
{
    m_pyImp.reset(new PyCAdUiPaletteImpl(this, panel));
    impObj()->SetName(utf8_to_wstr(name).c_str());
}


PyCAdUiPaletteImpl* PyCAdUiPalette::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<PyCAdUiPaletteImpl*>(m_pyImp.get());
}


