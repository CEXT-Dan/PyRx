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
        .def("enableDocking", &PyCAdUiPaletteSet::enableDocking, DS.ARGS({ "style : PyAp.PaletteDockStyle" }))
        .def("dock", &PyCAdUiPaletteSet::dock, DS.ARGS({ "style : PyAp.PaletteDockStyle" }))
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
    if(HRESULT hr = CLSIDFromString(sguid, (LPCLSID)&m_guid); hr != S_OK)
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
    impObj()->EnableDocking((DWORD)m_docStyle);
    impObj()->SetName(m_name);
    impObj()->SetToolID(&m_guid);
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

void PyCAdUiPaletteSet::dock(PaletteDockStyle dwDockStyle)
{
    if (dwDockStyle != PaletteDockStyle::kNone)
    {
        uint side = 0;
        CRect crect;
        impObj()->GetClientRect(crect);
        switch (dwDockStyle)
        {
            case PaletteDockStyle::kLeft:
                side = AFX_IDW_DOCKBAR_LEFT;
                break;
            case PaletteDockStyle::kRight:
                side = AFX_IDW_DOCKBAR_RIGHT;
                break;
            case PaletteDockStyle::kTop:
                side = AFX_IDW_DOCKBAR_TOP;
                break;
            case PaletteDockStyle::kBottom:
                side = AFX_IDW_DOCKBAR_BOTTOM;
                break;
            case PaletteDockStyle::kAny:
                side = AFX_IDW_DOCKBAR_LEFT;
                break;
        }
        impObj()->DockControlBar(side, crect);
    }
    else
    {
        PyThrowBadEs(eNotImplementedYet);
    }
}

void PyCAdUiPaletteSet::setSize(int x, int y)
{
    CRect crect;
    impObj()->GetClientRect(crect);
    crect.right= x;
    crect.bottom = y;
    impObj()->MoveWindow(crect);
}

void PyCAdUiPaletteSet::setLocation(int x, int y)
{
    PyThrowBadEs(eNotImplementedYet);
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
    : m_panel(panel), m_bckPtr(bckPtr)
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


