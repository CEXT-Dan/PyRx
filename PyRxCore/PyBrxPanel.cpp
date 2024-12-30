#include "stdafx.h"
#include "PyBrxPanel.h"

#ifdef BRXAPP

using namespace boost::python;
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
void makePyBrxPanelWrapper()
{
    constexpr const std::string_view restoreControlBarOverloads = "Overloads:\n"
        "- None: Any\n"
        "- style: PyAp.PaletteDockStyle, rect: tuple[int,int,int,int]\n";

    PyDocString DS("PyBrxPanel");
    class_<PyBrxPanel>("PyBrxPanel", no_init)
        .def(init<const std::string&>())
        .def(init<const std::string&, const std::string&>(DS.ARGS({ "name : str", "configKey : str=None" })))
        .def("create", &PyBrxPanel::create, DS.ARGS({ "name : str","panel: wx.Panel" }))
        ;
}

PyBrxPanel::PyBrxPanel(const std::string& name)
{
    m_name = utf8_to_wstr(name).c_str();
    m_pyImp.reset(new PyBrxPanelImpl(this, utf8_to_wstr(name).c_str(), nullptr));
}

PyBrxPanel::PyBrxPanel(const std::string& name, const std::string& configKey)
{
    m_name = utf8_to_wstr(name).c_str();
    m_pyImp.reset(new PyBrxPanelImpl(this, utf8_to_wstr(name).c_str(), utf8_to_wstr(configKey).c_str()));
}

bool PyBrxPanel::create(boost::python::object& panel)
{
    if (m_created)
        return true;

    if (wxPyConvertWrappedPtr(panel.ptr(), (void**)&m_panel, wxT("wxPanel")))
    {
        m_thisFrame = new wxTopLevelWindow();
        m_thisFrame->SetHWND((WXHWND)impObj()->GetSafeHwnd());
        m_thisFrame->AdoptAttributesFromHWND();
        m_thisFrame->SetName((const wchar_t*)m_name);
        m_thisFrame->AddChild(m_panel);
        m_panel->SetParent(m_thisFrame);
        return impObj()->Create() == TRUE;
    }
    return false;
}

PyBrxPanelImpl* PyBrxPanel::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyBrxPanelImpl*>(m_pyImp.get());
}

#endif
