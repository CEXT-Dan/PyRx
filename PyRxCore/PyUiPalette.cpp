#include "stdafx.h"
#include "PyUiPalette.h"

#if defined(_BRXTARGET)
#include "MFC/CAdUi/CAdUiPaletteSetDockFrame.h"
#endif

using namespace boost::python;

//---------------------------------------------------------------------
// Helpers
static uint paletteDockStyleToOrientation(PaletteDockStyle dwDockStyle)
{
    switch (dwDockStyle)
    {
        case PaletteDockStyle::kLeft:
            return AFX_IDW_DOCKBAR_LEFT;
        case PaletteDockStyle::kRight:
            return AFX_IDW_DOCKBAR_RIGHT;
        case PaletteDockStyle::kTop:
            return AFX_IDW_DOCKBAR_TOP;
        case PaletteDockStyle::kBottom:
            return AFX_IDW_DOCKBAR_BOTTOM;
        case PaletteDockStyle::kAny:
            return AFX_IDW_DOCKBAR_FLOAT;
    }
    return AFX_IDW_DOCKBAR_FLOAT;
}

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
    constexpr const std::string_view restoreControlBarOverloads = "Overloads:\n"
        "- None: Any\n"
        "- style: PyAp.PaletteDockStyle, rect: tuple[int,int,int,int]\n";

    PyDocString DS("PaletteSet");
    class_<PyCAdUiPaletteSet>("PaletteSet", no_init)
        .def(init<const std::string&>())
        .def(init<const std::string&, const std::string&>(DS.ARGS({ "name : str", "guid : str=None" })))
        .def("add", &PyCAdUiPaletteSet::add, DS.ARGS({ "name : str" }))
        .def("setVisible", &PyCAdUiPaletteSet::setVisible, DS.ARGS({ "val : bool" }))
        .def("enableDocking", &PyCAdUiPaletteSet::enableDocking, DS.ARGS({ "style : PyAp.PaletteDockStyle" }))
        .def("setDockState", &PyCAdUiPaletteSet::setDockState, DS.ARGS({ "style : PyAp.PaletteDockStyle" }))
        .def("getDockState", &PyCAdUiPaletteSet::getDockState, DS.ARGS())
        .def("getPaletteSetStyle", &PyCAdUiPaletteSet::getPaletteSetStyle, DS.ARGS(18147))
        .def("setPaletteSetStyle", &PyCAdUiPaletteSet::setPaletteSetStyle, DS.ARGS({ "val : int" }, 18205))
        .def("autoRollupStyle", &PyCAdUiPaletteSet::autoRollupStyle, DS.ARGS(18123))
        .def("propertiesMenuStyle", &PyCAdUiPaletteSet::propertiesMenuStyle, DS.ARGS(18190))
        .def("closeButtonStyle", &PyCAdUiPaletteSet::closeButtonStyle, DS.ARGS(18126))
        .def("singlePaletteTabStyle", &PyCAdUiPaletteSet::singlePaletteTabStyle, DS.ARGS(18212))
        .def("useSinglePaletteTabNameStyle", &PyCAdUiPaletteSet::useSinglePaletteTabNameStyle, DS.ARGS(18218))
        .def("editNameStyle", &PyCAdUiPaletteSet::editNameStyle, DS.ARGS(18224))
        .def("snapStyle", &PyCAdUiPaletteSet::snapStyle, DS.ARGS(18213))
        .def("showRollupButtonStyle", &PyCAdUiPaletteSet::showRollupButtonStyle, DS.ARGS(18211))
        .def("showIconStyle", &PyCAdUiPaletteSet::showIconStyle, DS.ARGS(18210))
        .def("getName", &PyCAdUiPaletteSet::getName, DS.ARGS(18142))
        .def("setName", &PyCAdUiPaletteSet::setName, DS.ARGS({ "name : str" }, 18203))
        .def("setToolId", &PyCAdUiPaletteSet::setToolId, DS.ARGS({ "guid : str" }, 17823))
        .def("getOpacity", &PyCAdUiPaletteSet::getOpacity, DS.ARGS(18144))
        .def("setOpacity", &PyCAdUiPaletteSet::setOpacity, DS.ARGS({ "val : int" }, 18204))
        .def("getRolloverOpacity", &PyCAdUiPaletteSet::getRolloverOpacity, DS.ARGS(18148))
        .def("setRolloverOpacity", &PyCAdUiPaletteSet::setRolloverOpacity, DS.ARGS({ "val : int" }, 18206))
        .def("getActivePaletteTabIndex", &PyCAdUiPaletteSet::getActivePaletteTabIndex, DS.ARGS(18132))
        .def("setActivePalette", &PyCAdUiPaletteSet::setActivePalette, DS.ARGS({ "val : int" }, 18197))
        .def("setLocation", &PyCAdUiPaletteSet::setLocation, DS.ARGS({ "x : int","y : int" }))
        .def("setSize", &PyCAdUiPaletteSet::setSize, DS.ARGS({ "x : int","y : int" }))
        .def("setAutoRollup", &PyCAdUiPaletteSet::setAutoRollup, DS.ARGS({ "val : bool" }, 18199))
        .def("getAutoRollup", &PyCAdUiPaletteSet::getAutoRollup, DS.ARGS(18134))
        .def("rollOut", &PyCAdUiPaletteSet::rollOut1)
        .def("rollOut", &PyCAdUiPaletteSet::rollOut2, DS.ARGS({ "delay : bool=False" }, 18193))
        .def("rollUp", &PyCAdUiPaletteSet::rollUp, DS.ARGS(18194))
        .def("removePalette", &PyCAdUiPaletteSet::removePalette, DS.ARGS({ "val : int" }, 18191))
        .def("getPaletteCount", &PyCAdUiPaletteSet::getPaletteCount, DS.ARGS(18146))
        .def("getFullRect", &PyCAdUiPaletteSet::getFullRect, DS.ARGS(18136))
        .def("rolledUp", &PyCAdUiPaletteSet::rolledUp, DS.ARGS(18192))
        .def("titleBarLocation", &PyCAdUiPaletteSet::titleBarLocation, DS.ARGS(18215))
        .def("setTitleBarLocation", &PyCAdUiPaletteSet::setTitleBarLocation, DS.ARGS({ "val : PyAp.PaletteTitleBarLocation" }, 18209))
        .def("updateTabs", &PyCAdUiPaletteSet::updateTabs, DS.ARGS(18217))
        .def("paletteBackgroundColor", &PyCAdUiPaletteSet::paletteBackgroundColor, DS.ARGS())
        .def("paletteTabTextColor", &PyCAdUiPaletteSet::paletteTabTextColor, DS.ARGS())
        .def("getWxWindow", &PyCAdUiPaletteSet::getPyWxWindow, DS.ARGS())
        .def("isFloating", &PyCAdUiPaletteSet::isFloating, DS.ARGS())
        .def("restoreControlBar", &PyCAdUiPaletteSet::restoreControlBar1)
        .def("restoreControlBar", &PyCAdUiPaletteSet::restoreControlBar2, DS.OVRL(restoreControlBarOverloads))
        ;
    enum_<CAdUiPaletteSet::AdUiTitleBarLocation>("PaletteTitleBarLocation")
        .value("kLeft", CAdUiPaletteSet::AdUiTitleBarLocation::kLeft)
        .value("kRight", CAdUiPaletteSet::AdUiTitleBarLocation::kRight)
        .export_values()
        ;
    enum_<PaletteDockStyle>("PaletteDockStyle")
        .value("kNone", PaletteDockStyle::kNone)
        .value("kLeft", PaletteDockStyle::kLeft)
        .value("kRight", PaletteDockStyle::kRight)
        .value("kTop", PaletteDockStyle::kTop)
        .value("kBottom", PaletteDockStyle::kBottom)
        .value("kAny", PaletteDockStyle::kAny)
        .export_values()
        ;
}

PyCAdUiPaletteSet::PyCAdUiPaletteSet(const std::string& name)
{
    CAcModuleResourceOverride resourceOverride;
    m_pyImp.reset(new PyCAdUiPaletteSetImpl(this));
    m_name = utf8_to_wstr(name).c_str();
}

PyCAdUiPaletteSet::PyCAdUiPaletteSet(const std::string& name, const std::string& guid)
{
    CAcModuleResourceOverride resourceOverride;
    m_pyImp.reset(new PyCAdUiPaletteSetImpl(this));
    m_name = utf8_to_wstr(name).c_str();
    const CString sguid = utf8_to_wstr(guid).c_str();
    if (HRESULT hr = CLSIDFromString(sguid, (LPCLSID)&m_guid); hr != S_OK)
    {
        acutPrintf(_T("BAD GUID"));
    }
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
            m_children.back().setPyPaletteSet(this);
            return m_children.size() - 1;
        }
    }
    return -1;
}

bool PyCAdUiPaletteSet::create()
{
    constexpr auto paletteStyleFlags = PSS_AUTO_ROLLUP | PSS_PROPERTIES_MENU | PSS_CLOSE_BUTTON | PSS_SNAP;

    if (m_created)
        return true;
    CAcModuleResourceOverride resourceOverride;
    CRect rect(0, 0, 275, 500);
    impObj()->Create(
        impObj()->GetName(),
        WS_OVERLAPPED | WS_DLGFRAME,
        rect,
        acedGetAcadFrame(),
        paletteStyleFlags
    );
    impObj()->EnableDocking((DWORD)m_docStyle);
    impObj()->SetName(m_name);
    if (m_guid != GUID_NULL)
        impObj()->SetToolID(&m_guid);

    m_thisFrame = new wxTopLevelWindow();
    m_thisFrame->SetHWND((WXHWND)impObj()->GetSafeHwnd());
    m_thisFrame->AdoptAttributesFromHWND();
    m_thisFrame->SetName((const wchar_t*)m_name);

    createChildren();
    m_created = true;
    return m_created;
}

void PyCAdUiPaletteSet::setVisible(bool show)
{
    if (impObj() != nullptr && create())
    {
        impObj()->RestoreControlBar();
        CMDIFrameWnd* pAcadFrame = acedGetAcadFrame();
        pAcadFrame->ShowControlBar(impObj(), show, FALSE);
    }
}

void PyCAdUiPaletteSet::enableDocking(PaletteDockStyle dwDockStyle)
{
    m_docStyle = dwDockStyle;
}

void PyCAdUiPaletteSet::setDockState(PaletteDockStyle dwDockStyle)
{
    CRect crect;
    impObj()->GetClientRect(crect);
    uint side = paletteDockStyleToOrientation(dwDockStyle);
    if (dwDockStyle != PaletteDockStyle::kNone)
    {
        impObj()->DockControlBar(side, &crect);
    }
    else
    {
        impObj()->PostMessage(WM_COMMAND, ID_ADUI_ALLOWDOCK, 0);
    }
}

PaletteDockStyle PyCAdUiPaletteSet::getDockState()
{
    if (impObj()->IsFloating())
    {
        return PaletteDockStyle::kNone;
    }

    CDockState state;
    CMDIFrameWnd* pAcadFrame = acedGetAcadFrame();
    pAcadFrame->GetDockState(state);

    CControlBarInfo thisbar;
    impObj()->GetBarInfo(&thisbar);

    for (INT_PTR i = 0; i < state.m_arrBarInfo.GetSize(); i++)
    {
        const CControlBarInfo* pInfo = static_cast<CControlBarInfo*>(state.m_arrBarInfo[i]);
        if (pInfo == nullptr)
            continue;
        for (INT_PTR j = 0; j < pInfo->m_arrBarID.GetSize(); j++)
        {
            if (pInfo->m_arrBarID[j] == thisbar.m_nBarID)
            {
                switch (pInfo->m_nBarID)
                {
                    case AFX_IDW_DOCKBAR_LEFT:
                        return PaletteDockStyle::kLeft;
                    case AFX_IDW_DOCKBAR_RIGHT:
                        return PaletteDockStyle::kRight;
                    case AFX_IDW_DOCKBAR_TOP:
                        return PaletteDockStyle::kTop;
                    case AFX_IDW_DOCKBAR_BOTTOM:
                        return PaletteDockStyle::kBottom;
                }
            }
        }
    }
    return PaletteDockStyle::kNone;
}

void PyCAdUiPaletteSet::setSize(int x, int y)
{
    CRect crect;
    impObj()->GetClientRect(crect);
    crect.right = x;
    crect.bottom = y;
    impObj()->MoveWindow(crect);
}

void PyCAdUiPaletteSet::setLocation(int x, int y)
{
    if (!m_created)
    {
        CRect frect;
        impObj()->GetFloatingRect(&frect);
        frect.MoveToXY(x, y);
        impObj()->InitFloatingPosition(&frect);
    }
    else
    {
        constexpr int flag = SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE;
#ifdef _GRXTARGET
        CWnd* wndPtr = impObj();
        constexpr const char* runtimeClassName = "CGdUiPaletteSetMiniFrame";
        while (wndPtr != nullptr)
        {
            const auto wndRtClass = wndPtr->GetRuntimeClass();
            if (wndRtClass != nullptr && strcmp(runtimeClassName, wndRtClass->m_lpszClassName) == 0)
                wndPtr->SetWindowPos(nullptr, x, y, 0, 0, flag);
            wndPtr = CWnd::FromHandle(GetParent(wndPtr->GetSafeHwnd()));
        }
#else
        CWnd* wndPtr = impObj();
        while (wndPtr != nullptr)
        {
            if (wndPtr->IsKindOf(CAdUiPaletteSetDockFrame::GetThisClass()))
                wndPtr->SetWindowPos(nullptr, x, y, 0, 0, flag);
            wndPtr = CWnd::FromHandle(GetParent(wndPtr->GetSafeHwnd()));
        }
#endif
    }
}

bool PyCAdUiPaletteSet::isFloating()
{
    return impObj()->IsFloating() == TRUE;
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
#if defined(_BRXTARGET) && _BRXTARGET <= 250
    throw PyNotimplementedByHost();
#else
    return impObj()->PropertiesMenuStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::closeButtonStyle()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 250
    throw PyNotimplementedByHost();
#else
    return impObj()->CloseButtonStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::singlePaletteTabStyle()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 250
    throw PyNotimplementedByHost();
#else
    return impObj()->SinglePaletteTabStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::useSinglePaletteTabNameStyle()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 250
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
#if defined(_BRXTARGET) && _BRXTARGET <= 250
    throw PyNotimplementedByHost();
#else
    return impObj()->SnapStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::showRollupButtonStyle()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 250
    throw PyNotimplementedByHost();
#else
    return impObj()->ShowRollupButtonStyle() == TRUE;
#endif
}

bool PyCAdUiPaletteSet::showIconStyle()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 250
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

bool PyCAdUiPaletteSet::setToolId(const std::string& guid)
{
    CString sguid = utf8_to_wstr(guid).c_str();
    HRESULT hr = CLSIDFromString(sguid, (LPCLSID)&m_guid);
    if (hr != S_OK)
    {
        acutPrintf(_T("BAD GUID"));
        return false;
    }
    impObj()->SetToolID(&m_guid);
    return true;
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
#if defined(_BRXTARGET) && _BRXTARGET <= 250
    throw PyNotimplementedByHost();
#else
    return impObj()->GetRolloverOpacity();
#endif
}

bool PyCAdUiPaletteSet::setRolloverOpacity(int nOpacity)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 250
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

void PyCAdUiPaletteSet::restoreControlBar1()
{
    impObj()->RestoreControlBar();
}

void PyCAdUiPaletteSet::restoreControlBar2(PaletteDockStyle dwDockStyle, boost::python::tuple& pyrect)
{
    uint side = paletteDockStyleToOrientation(dwDockStyle);
    const auto& parts =  PyListToInt32Array(pyrect);
    if (parts.length() != 4)
        PyThrowBadEs(eInvalidInput);
    CRect rect{ parts[0], parts[1], parts[2],  parts[3] };
    impObj()->RestoreControlBar(side, &rect);
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
    wxRect* _wxRect = new wxRect(rect.left, rect.top, rect.right, rect.bottom);
    return wxPyConstructObject(_wxRect, wxT("wxRect"), true);
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

wxTopLevelWindow* PyCAdUiPaletteSet::getWxWindow()
{
    if (m_thisFrame == nullptr) [[unlikely]] {
        throw PyNullObject();
        }
    return m_thisFrame;
}

PyObject* PyCAdUiPaletteSet::getPyWxWindow()
{
    return wxPyConstructObject(getWxWindow(), wxT("wxTopLevelWindow"), false);
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
    : m_panel(panel)
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

    m_thiswin = new wxPanel();
    thiswindow()->SetHWND((WXHWND)this->GetSafeHwnd());
    thiswindow()->AdoptAttributesFromHWND();
    thiswindow()->Reparent(ownerwin());
    if (!panel()->Create(thiswindow()))
        return -1;
    return 0;
}

void PyCAdUiPaletteImpl::OnSize(UINT nType, int cx, int cy)
{
    CAdUiPalette::OnSize(nType, cx, cy);
    CAcModuleResourceOverride resourceOverride;
    CRect rect;
    GetClientRect(rect);
    panel()->SetSize(rect.left, rect.top, rect.right, rect.bottom);
}

wxWindow* PyCAdUiPaletteImpl::thiswindow(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_thiswin == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_thiswin;
}

wxWindow* PyCAdUiPaletteImpl::ownerwin(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_paletteSet == nullptr || m_paletteSet->getWxWindow() == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_paletteSet->getWxWindow();
}

wxPanel* PyCAdUiPaletteImpl::panel(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_panel == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_panel;
}

PyCAdUiPalette* PyCAdUiPaletteImpl::bckptr(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_bckPtr == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_bckPtr;
}

void PyCAdUiPaletteImpl::setPyPaletteSet(PyCAdUiPaletteSet* paletteSet)
{
    m_paletteSet = paletteSet;
}

//---------------------------------------------------------------------
//PyCAdUiPalette
void makePyCAdUiPaletteWrapper()
{
    PyDocString DS("Palette");
    class_<PyCAdUiPalette>("Palette", no_init)
        .def("getWxWindow", &PyCAdUiPalette::getPyWxWindow, DS.ARGS())
        ;
}

PyCAdUiPalette::PyCAdUiPalette(const std::string& name, wxPanel* panel)
    :m_pyImp(nullptr)
{
    m_pyImp.reset(new PyCAdUiPaletteImpl(this, panel));
    impObj()->SetName(utf8_to_wstr(name).c_str());
}

void PyCAdUiPalette::setPyPaletteSet(PyCAdUiPaletteSet* paletteSet)
{
    impObj()->setPyPaletteSet(paletteSet);
}

PyObject* PyCAdUiPalette::getPyWxWindow() const
{
    return wxPyConstructObject(impObj()->thiswindow(), wxT("wxWindow"), false);
}

PyCAdUiPaletteImpl* PyCAdUiPalette::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<PyCAdUiPaletteImpl*>(m_pyImp.get());
}
