#pragma once

#ifdef BRXAPP

#include "BcUiPanelMFC.h"

class PyBrxPanel;
class PyBrxChild;

//---------------------------------------------------------------------
//PyBrxPanelImpl
class PyBrxPanelImpl : public BcUiPanelMFC
{
public:
    DECLARE_DYNCREATE(PyBrxPanelImpl);
    PyBrxPanelImpl();
    PyBrxPanelImpl(const ACHAR* name, const ACHAR* configKey);
    virtual ~PyBrxPanelImpl() override = default;
    bool setWxPanel(wxPanel* panel);
    wxTopLevelWindow* getWxWindow();

    virtual BOOL CreateControlBar(LPCREATESTRUCT lpCreateStruct) override;

    DECLARE_MESSAGE_MAP();
    afx_msg void OnSize(UINT nType, int cx, int cy);

private:
    std::unique_ptr<PyBrxChild> m_child;
    wxTopLevelWindow* m_thisFrame = nullptr;
    DLGTEMPLATE dlgt = { 0 };
};

//---------------------------------------------------------------------
//PyBrxChild
class PyBrxChild : public CDialog
{
public:
    PyBrxChild() = default;
    virtual ~PyBrxChild() override = default;
    DECLARE_DYNCREATE(PyBrxChild);

    bool setWxPanel(wxPanel* panel);
    bool setPyBrxPanelImpl(PyBrxPanelImpl* pBrxPanel);
    wxWindow* thiswindow(const std::source_location& src = std::source_location::current()) const;
    wxWindow* ownerwin(const std::source_location& src = std::source_location::current()) const;
    wxPanel* panel(const std::source_location& src = std::source_location::current()) const;

    DECLARE_MESSAGE_MAP();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);
private:
    wxPanel* m_panel = nullptr;
    wxWindow* m_thiswin = nullptr;
    PyBrxPanelImpl* m_pBrxPanel = nullptr;
    bool m_created = false;
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
    bool        create(const boost::python::object& panel);
    COLORREF    backgroundColor() const;
    COLORREF    tabTextColor() const;
    void        setIcon(const std::string& path);

public: //INTERNAL
    PyBrxPanelImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    boost::python::object m_wxpanel;
    std::shared_ptr<PyBrxPanelImpl> m_pyImp;
    CString m_name;
    CString m_configKey;
    BcImageSourcePtr m_fileSource;
    bool m_created = false;
};

#endif