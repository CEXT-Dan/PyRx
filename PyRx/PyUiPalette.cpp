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
        ;
}

PyCAdUiPaletteSet::PyCAdUiPaletteSet(const std::string& name)
    : m_pyImp(nullptr)
{
    GUID id;
    m_pyImp.reset(new PyCAdUiPaletteSetImpl(this));
    impObj()->SetName(utf8_to_wstr(name).c_str());
    HRESULT hr = CoCreateGuid(&id);
    impObj()->SetToolID(&id);
}

PyCAdUiPaletteSet::PyCAdUiPaletteSet(const std::string& name, const std::string& guid)
{
    m_pyImp.reset(new PyCAdUiPaletteSetImpl(this));
    impObj()->SetName(utf8_to_wstr(name).c_str());

    GUID id;
    CString sguid = utf8_to_wstr(guid).c_str();
    HRESULT hr = CLSIDFromString(sguid, (LPCLSID)&id);
    if (hr != S_OK)
        acutPrintf(_T("BAD GUID"));
    impObj()->SetToolID(&id);
}

int PyCAdUiPaletteSet::add(const std::string& name, boost::python::object& panel)
{
    if (wxPyWrappedPtr_TypeCheck(panel.ptr(), _T("wxPanel")))
    {
        wxPanel* pPanel = nullptr;
        wxPyConvertWrappedPtr(panel.ptr(), (void**)&pPanel, wxT("wxPanel"));
        if (pPanel != nullptr)
            m_children.push_back(PyCAdUiPalette(name, pPanel));
    }
    return 0;
}

void PyCAdUiPaletteSet::setVisible(bool show)
{
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

    if (impObj() != nullptr)
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
        child.impObj()->Create(WS_CHILD | WS_VISIBLE, impObj()->GetName(), impObj());
        if (impObj()->AddPalette(m_children.back().impObj()) == -1)
            acutPrintf(_T("Failed to add palette: "));
    }
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
    wxWindow* win = new wxWindow();//memleak?
    win->SetHWND((WXHWND)this->GetSafeHwnd());
    win->AdoptAttributesFromHWND();
    m_panel->Create(win);
    return 0;
}

void PyCAdUiPaletteImpl::OnSize(UINT nType, int cx, int cy)
{
    CAdUiPalette::OnSize(nType, cx, cy);
    CRect rect;
    GetClientRect(rect);
    CAcModuleResourceOverride resourceOverride;
    m_panel->SetSize(cx, cy);
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


