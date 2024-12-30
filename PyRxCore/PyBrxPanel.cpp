#include "stdafx.h"
#include "PyBrxPanel.h"

#ifdef BRXAPP

using namespace boost::python;
//---------------------------------------------------------------------
//PyBrxPanelImpl
IMPLEMENT_DYNCREATE(PyBrxPanelImpl, BcUiPanelMFC)

BEGIN_MESSAGE_MAP(PyBrxPanelImpl, BcUiPanelMFC)
END_MESSAGE_MAP()

PyBrxPanelImpl::PyBrxPanelImpl()
    : m_child(new PyBrxChild()), BcUiPanelMFC(nullptr, nullptr)
{
}

PyBrxPanelImpl::PyBrxPanelImpl(const ACHAR* name, const ACHAR* configKey)
    : m_child(new PyBrxChild()), BcUiPanelMFC(name, configKey)
{
}

bool PyBrxPanelImpl::setWxPanel(wxPanel* panel)
{
   return m_child->setWxPanel(panel);
}

wxTopLevelWindow* PyBrxPanelImpl::getWxWindow()
{
    return m_thisFrame;
}

BOOL PyBrxPanelImpl::CreateControlBar(LPCREATESTRUCT lpCreateStruct)
{
    if (!BcUiPanelMFC::CreateControlBar(lpCreateStruct))
        return FALSE;

    CAcModuleResourceOverride resourceOverride;


    m_child->setPyBrxPanelImpl(this);
    m_thisFrame = new wxTopLevelWindow();
    m_thisFrame->SetHWND((WXHWND)this->GetSafeHwnd());
    m_thisFrame->AdoptAttributesFromHWND();

    CRect rcClient;
    GetClientRect(&rcClient);

    dlgt.style = WS_CHILD | WS_VISIBLE;
    dlgt.x = rcClient.left;
    dlgt.y = rcClient.top;
    dlgt.cx = rcClient.right;
    dlgt.cy = rcClient.bottom;
    //dlgt.cdit = 9999; //TODO:

    if (m_child->CreateIndirect(&dlgt, this) == -1)
        return -1;

    return TRUE;
}

//---------------------------------------------------------------------
//PyBrxChild
IMPLEMENT_DYNCREATE(PyBrxChild, CDialog)

BEGIN_MESSAGE_MAP(PyBrxChild, CDialog)
    ON_WM_CREATE()
END_MESSAGE_MAP()

int PyBrxChild::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
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

bool PyBrxChild::setWxPanel(wxPanel* panel)
{
    m_panel = panel;
    return panel != nullptr;
}

bool PyBrxChild::setPyBrxPanelImpl(PyBrxPanelImpl* pBrxPanel)
{
    m_pBrxPanel = pBrxPanel;
    return pBrxPanel != nullptr;
}

wxWindow* PyBrxChild::thiswindow(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_thiswin == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_thiswin;
}

wxWindow* PyBrxChild::ownerwin(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pBrxPanel == nullptr || m_pBrxPanel->getWxWindow() == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pBrxPanel->getWxWindow();
}

wxPanel* PyBrxChild::panel(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_panel == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_panel;
}

//---------------------------------------------------------------------
//PyBrxPanel
static std::shared_ptr<PyBrxPanel> gpanel;

void makePyBrxPanelWrapper()
{
    constexpr const std::string_view restoreControlBarOverloads = "Overloads:\n"
        "- None: Any\n"
        "- style: PyAp.PaletteDockStyle, rect: tuple[int,int,int,int]\n";

    PyDocString DS("PyBrxPanel");
    class_<PyBrxPanel>("PyBrxPanel", no_init)
        .def(init<const std::string&>())
        .def(init<const std::string&, const std::string&>(DS.ARGS({ "name : str", "configKey : str=None" })))
        .def("create", &PyBrxPanel::create, DS.ARGS({ "panel: wx.Panel" }))
        ;
}

PyBrxPanel::PyBrxPanel(const std::string& name)
{
    m_name = utf8_to_wstr(name).c_str();
}

PyBrxPanel::PyBrxPanel(const std::string& name, const std::string& configKey)
{
    m_name = utf8_to_wstr(name).c_str();
    m_configKey = utf8_to_wstr(configKey).c_str();
}

bool PyBrxPanel::create(boost::python::object& panel)
{
    if (m_created)
        return true;

    if (wxPyWrappedPtr_TypeCheck(panel.ptr(), _T("wxPanel")))
    {
        wxPanel* pPanel = nullptr;
        wxPyConvertWrappedPtr(panel.ptr(), (void**)&pPanel, wxT("wxPanel"));
        if (pPanel != nullptr)
        {
            m_pyImp.reset(new PyBrxPanelImpl(m_name, m_configKey));
            m_pyImp->setWxPanel(pPanel);
            if (m_pyImp->Create() == FALSE)
                return false;
        }
    }
    m_created = true;
    return true;
}

PyBrxPanelImpl* PyBrxPanel::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyBrxPanelImpl*>(m_pyImp.get());
}

#endif
