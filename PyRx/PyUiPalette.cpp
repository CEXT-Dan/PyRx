#include "stdafx.h"
#include "PyUiPalette.h"

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
PyCAdUiPaletteSet::PyCAdUiPaletteSet(const std::string& name)
    : m_pyImp(nullptr)
{
    m_pyImp.reset(new PyCAdUiPaletteSetImpl(this));
    impObj()->SetName(utf8_to_wstr(name).c_str());

    GUID id;
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

void PyCAdUiPaletteSet::Add(const std::string& name, UINT_PTR panel)
{
    m_children.push_back(PyCAdUiPalette(name, panel));
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
END_MESSAGE_MAP()

PyCAdUiPaletteImpl::PyCAdUiPaletteImpl()
{
}

PyCAdUiPaletteImpl::PyCAdUiPaletteImpl(PyCAdUiPalette* bckPtr)
    : m_bckPtr(bckPtr)
{
}

int PyCAdUiPaletteImpl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CAdUiPalette::OnCreate(lpCreateStruct) == -1)
        return -1;
    return 0;
}

PyCAdUiPalette* PyCAdUiPaletteImpl::bckptr(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_bckPtr == nullptr)
        throw PyNullObject(src);
    return m_bckPtr;
}

//---------------------------------------------------------------------
//PyCAdUiPalette
PyCAdUiPalette::PyCAdUiPalette(const std::string& name, UINT_PTR panel)
    :m_pyImp(nullptr), m_panel((HWND)panel)
{
    m_pyImp.reset(new PyCAdUiPaletteImpl(this));
    impObj()->SetName(utf8_to_wstr(name).c_str());
    impWnd()->SetParent(impObj());
}

CWnd* PyCAdUiPalette::impWnd(const std::source_location& src /*= std::source_location::current()*/)
{
    if (m_panel == 0)
        throw PyNullObject(src);
    CWnd* wnd = CWnd::FromHandle(m_panel);
    if(wnd == nullptr)
        throw PyNullObject(src);
    return wnd;
}

PyCAdUiPaletteImpl* PyCAdUiPalette::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<PyCAdUiPaletteImpl*>(m_pyImp.get());
}

HWND PyCAdUiPalette::panel() const
{
    return m_panel;
}
