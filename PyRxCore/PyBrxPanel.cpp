#include "stdafx.h"
#include "PyBrxPanel.h"

#ifdef BRXAPP

//---------------------------------------------------------------------
//PyBrxPanelImpl
IMPLEMENT_DYNCREATE(PyBrxPanelImpl, BcUiPanelMFC)

BEGIN_MESSAGE_MAP(PyBrxPanelImpl, BcUiPanelMFC)
    ON_WM_CREATE()
END_MESSAGE_MAP()

PyBrxPanelImpl::PyBrxPanelImpl()
    : m_bckPtr(nullptr), BcUiPanelMFC(nullptr, nullptr)
{
}

PyBrxPanelImpl::PyBrxPanelImpl(PyBrxPanel* bckPtr, const ACHAR* name, const ACHAR* configKey)
    : m_bckPtr(bckPtr), BcUiPanelMFC(name, configKey)
{
}

int PyBrxPanelImpl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (BcUiPanelMFC::OnCreate(lpCreateStruct) == -1)
        return -1;
    return 0;
}

PyBrxPanel* PyBrxPanelImpl::bckptr(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_bckPtr == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_bckPtr;
}


//---------------------------------------------------------------------
//PyBrxPanel
PyBrxPanel::PyBrxPanel(const std::string& name, const std::string& configKey)
{
    m_name = utf8_to_wstr(name).c_str();
    m_pyImp.reset(new PyBrxPanelImpl(this, utf8_to_wstr(name).c_str(), utf8_to_wstr(configKey).c_str()));
}

bool PyBrxPanel::create()
{
    if (m_created)
        return true;

    m_thisFrame = new wxTopLevelWindow();
    m_thisFrame->SetHWND((WXHWND)impObj()->GetSafeHwnd());
    m_thisFrame->AdoptAttributesFromHWND();
    m_thisFrame->SetName((const wchar_t*)m_name);
}

PyBrxPanelImpl* PyBrxPanel::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyBrxPanelImpl*>(m_pyImp.get());
}

#endif

