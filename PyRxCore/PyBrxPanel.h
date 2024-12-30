#pragma once

#ifdef BRXAPP

#include "BcUiPanelMFC.h"

class PyBrxPanel;

//---------------------------------------------------------------------
//PyBrxPanelImpl
class PyBrxPanelImpl : public BcUiPanelMFC
{
public:
    DECLARE_DYNCREATE(PyBrxPanelImpl);
    PyBrxPanelImpl();
    PyBrxPanelImpl(PyBrxPanel* bckPtr, const ACHAR* name, const ACHAR* configKey);
    virtual ~PyBrxPanelImpl() override = default;
    DECLARE_MESSAGE_MAP();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
    PyBrxPanel* bckptr(const std::source_location& src = std::source_location::current()) const;
private:
    PyBrxPanel* m_bckPtr = nullptr;
};


//---------------------------------------------------------------------
//PyBrxPanel
void makePyBrxPanelWrapper();
class PyBrxPanel : public boost::python::wrapper<PyBrxPanel>
{
public:
    PyBrxPanel(const std::string& name);
    PyBrxPanel(const std::string& name, const std::string& configKey);
    virtual ~PyBrxPanel() = default;
    bool   create(boost::python::object& panel);
  
public: //INTERNAL
    PyBrxPanelImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<PyBrxPanelImpl> m_pyImp;
    wxTopLevelWindow* m_thisFrame = nullptr;
    wxPanel* m_panel = nullptr;
    CString m_name;
    bool m_created = false;
};

#endif