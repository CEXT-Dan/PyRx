#include "stdafx.h"
#include "PyUiPalette.h"

using namespace boost::python;

//---------------------------------------------------------------------
//PyCAdUiPaletteSetImpl

IMPLEMENT_DYNCREATE(PyCAdUiPaletteSetImpl, CAdUiPaletteSet)

BEGIN_MESSAGE_MAP(PyCAdUiPaletteSetImpl, CAdUiPaletteSet)
    ON_WM_CREATE()
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

PyCAdUiPaletteSet* PyCAdUiPaletteSetImpl::bckptr(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_bckPtr == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_bckPtr;
}

//---------------------------------------------------------------------
//PyCAdUiPaletteSet
void makePyCAdUiPaletteSetWrapper()
{
    PyDocString DS("PaletteSet");
    class_<PyCAdUiPaletteSet>("PaletteSet", no_init)
        .def(init<const std::string&>())
        .def(init<const std::string&, const std::string&>(DS.ARGS({ "name : str", "guid : str=None" })))
        .def("add", &PyCAdUiPaletteSet::add, DS.ARGS({ "name : str" }))
        .def("setVisible", &PyCAdUiPaletteSet::setVisible, DS.ARGS({ "val : bool" }))
        .def("getPaletteSetStyle", &PyCAdUiPaletteSet::getPaletteSetStyle, DS.ARGS())
        .def("setPaletteSetStyle", &PyCAdUiPaletteSet::setPaletteSetStyle, DS.ARGS({ "val : int" }))
        .def("autoRollupStyle", &PyCAdUiPaletteSet::autoRollupStyle, DS.ARGS())
        .def("propertiesMenuStyle", &PyCAdUiPaletteSet::propertiesMenuStyle, DS.ARGS())
        .def("closeButtonStyle", &PyCAdUiPaletteSet::closeButtonStyle, DS.ARGS())
        .def("singlePaletteTabStyle", &PyCAdUiPaletteSet::singlePaletteTabStyle, DS.ARGS())
        .def("useSinglePaletteTabNameStyle", &PyCAdUiPaletteSet::useSinglePaletteTabNameStyle, DS.ARGS())
        .def("editNameStyle", &PyCAdUiPaletteSet::editNameStyle, DS.ARGS())
        .def("snapStyle", &PyCAdUiPaletteSet::snapStyle, DS.ARGS())
        .def("showRollupButtonStyle", &PyCAdUiPaletteSet::showRollupButtonStyle, DS.ARGS())
        .def("showIconStyle", &PyCAdUiPaletteSet::showIconStyle, DS.ARGS())
        .def("getName", &PyCAdUiPaletteSet::getName, DS.ARGS())
        .def("setName", &PyCAdUiPaletteSet::setName, DS.ARGS({ "val : str" }))
        .def("getOpacity", &PyCAdUiPaletteSet::getOpacity, DS.ARGS())
        .def("setOpacity", &PyCAdUiPaletteSet::setOpacity, DS.ARGS({ "val : int" }))
        .def("getRolloverOpacity", &PyCAdUiPaletteSet::getRolloverOpacity, DS.ARGS())
        .def("setRolloverOpacity", &PyCAdUiPaletteSet::setRolloverOpacity, DS.ARGS({ "val : int" }))
        .def("getActivePaletteTabIndex", &PyCAdUiPaletteSet::getActivePaletteTabIndex, DS.ARGS())
        .def("setActivePalette", &PyCAdUiPaletteSet::setActivePalette, DS.ARGS({ "val : int" }))
        .def("setAutoRollup", &PyCAdUiPaletteSet::setAutoRollup, DS.ARGS({ "val : bool" }))
        .def("getAutoRollup", &PyCAdUiPaletteSet::getAutoRollup, DS.ARGS())
        .def("rollOut", &PyCAdUiPaletteSet::rollOut1)
        .def("rollOut", &PyCAdUiPaletteSet::rollOut2, DS.ARGS({ "delay : bool=False" }))
        .def("rollUp", &PyCAdUiPaletteSet::rollUp, DS.ARGS())
        .def("removePalette", &PyCAdUiPaletteSet::removePalette, DS.ARGS({ "val : int" }))
        .def("getPaletteCount", &PyCAdUiPaletteSet::getPaletteCount, DS.ARGS())
        .def("getFullRect", &PyCAdUiPaletteSet::getFullRect, DS.ARGS())
        .def("rolledUp", &PyCAdUiPaletteSet::rolledUp, DS.ARGS())
        .def("titleBarLocation", &PyCAdUiPaletteSet::titleBarLocation, DS.ARGS())
        .def("setTitleBarLocation", &PyCAdUiPaletteSet::setTitleBarLocation, DS.ARGS({ "val : AdUiTitleBarLocation" }))
        .def("updateTabs", &PyCAdUiPaletteSet::updateTabs, DS.ARGS())
        .def("paletteBackgroundColor", &PyCAdUiPaletteSet::paletteBackgroundColor, DS.ARGS())
        .def("paletteTabTextColor", &PyCAdUiPaletteSet::paletteTabTextColor, DS.ARGS())
        ;
    enum_<CAdUiPaletteSet::AdUiTitleBarLocation>("AdUiTitleBarLocation")
        .value("kLeft", CAdUiPaletteSet::AdUiTitleBarLocation::kLeft)
        .value("kRight", CAdUiPaletteSet::AdUiTitleBarLocation::kRight)
        .export_values()
        ;
}

PyCAdUiPaletteSet::PyCAdUiPaletteSet(const std::string& name)
{
    CAcModuleResourceOverride resourceOverride;
    m_pyImp.reset(new PyCAdUiPaletteSetImpl(this));
#if defined(_GRXTARGET) && (_GRXTARGET == 240)
    return;
#endif
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
#if defined(_GRXTARGET) && (_GRXTARGET == 240)
    return;
#endif
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
        {
            m_children.push_back(PyCAdUiPalette(name, pPanel));
            return m_children.size() - 1;
        }
    }
    return -1;
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
        if (child.impObj()->Create(WS_CHILD | WS_VISIBLE, child.impObj()->GetName(), impObj()) == FALSE)
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
    return impObj()->PropertiesMenuStyle() == TRUE;
}

bool PyCAdUiPaletteSet::closeButtonStyle()
{
    return impObj()->CloseButtonStyle() == TRUE;
}

bool PyCAdUiPaletteSet::singlePaletteTabStyle()
{
    return impObj()->SinglePaletteTabStyle() == TRUE;
}

bool PyCAdUiPaletteSet::useSinglePaletteTabNameStyle()
{
    return impObj()->UseSinglePaletteTabNameStyle() == TRUE;
}

bool PyCAdUiPaletteSet::editNameStyle()
{
    return impObj()->EditNameStyle() == TRUE;
}

bool PyCAdUiPaletteSet::snapStyle()
{
    return impObj()->SnapStyle() == TRUE;
}

bool PyCAdUiPaletteSet::showRollupButtonStyle()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 240)
    throw PyNotimplementedByHost();
#else
    return impObj()->ShowRollupButtonStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::showIconStyle()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 240)
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 240)
    throw PyNotimplementedByHost();
#else
    return impObj()->GetRolloverOpacity();
#endif
}

bool PyCAdUiPaletteSet::setRolloverOpacity(int nOpacity)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 240)
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
    return wxPyConstructObject(&_wxRect, wxT("wxRect"));
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

COLORREF PyCAdUiPaletteSet::paletteBackgroundColor() const
{

#ifndef _ARXTARGET
    return RGB(49, 56, 66);
#else
    auto theme = impObj()->GetTheme();
    if (theme == nullptr) [[unlikely]] {
        throw PyNullObject();
    }
    return theme->GetColor(kPaletteBackground);
#endif
}

COLORREF PyCAdUiPaletteSet::paletteTabTextColor() const
{
#ifndef _ARXTARGET
    return 0xFFBEC0C5;
#else
    auto theme = impObj()->GetTheme();
    if (theme == nullptr) [[unlikely]] {
        throw PyNullObject();
    }
    return theme->GetColor(kPaletteTabText);
#endif
}

PyCAdUiPaletteSetImpl* PyCAdUiPaletteSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
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

    auto mcfParent = this->GetParent();
    if (mcfParent == nullptr)
        return -1;
    {
        m_ownerwin = new wxTopLevelWindow();
        ownerwin()->SetHWND((WXHWND)mcfParent->GetSafeHwnd());
        ownerwin()->AdoptAttributesFromHWND();
    }
    {
        m_thiswin = new wxPanel();
        thiswindow()->SetHWND((WXHWND)this->GetSafeHwnd());
        thiswindow()->AdoptAttributesFromHWND();
        thiswindow()->Reparent(ownerwin());
    }
    panel()->Create(thiswindow());
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
    if (m_thiswin == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return m_thiswin;
}

wxWindow* PyCAdUiPaletteImpl::ownerwin(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_ownerwin == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return m_ownerwin;
}

wxPanel* PyCAdUiPaletteImpl::panel(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_panel == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return m_panel;
}

PyCAdUiPalette* PyCAdUiPaletteImpl::bckptr(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_bckPtr == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_bckPtr;
}

//---------------------------------------------------------------------
//PyCAdUiPalette
void makePyCAdUiPaletteWrapper()
{
    //TODO: ?
}

PyCAdUiPalette::PyCAdUiPalette(const std::string& name, wxPanel* panel)
    :m_pyImp(nullptr)
{
    m_pyImp.reset(new PyCAdUiPaletteImpl(this, panel));
    impObj()->SetName(utf8_to_wstr(name).c_str());
}

PyCAdUiPaletteImpl* PyCAdUiPalette::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyCAdUiPaletteImpl*>(m_pyImp.get());
}


