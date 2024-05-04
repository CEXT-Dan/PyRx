#pragma once
//CAdUiPaletteSet
//CAdUiPalette

class PyCAdUiPalette;
class PyCAdUiPaletteSet;


//---------------------------------------------------------------------
//PyCAdUiPaletteSetImpl
class PyCAdUiPaletteSetImpl : public CAdUiPaletteSet
{
public:
    DECLARE_DYNCREATE(PyCAdUiPaletteSetImpl);
    PyCAdUiPaletteSetImpl();
    PyCAdUiPaletteSetImpl(PyCAdUiPaletteSet* bckPtr);
    virtual ~PyCAdUiPaletteSetImpl() override = default;
    DECLARE_MESSAGE_MAP();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

public:
    PyCAdUiPaletteSet* bckptr(const std::source_location& src = std::source_location::current()) const;
private:
    PyCAdUiPaletteSet* m_bckPtr = nullptr;
};

//---------------------------------------------------------------------
//PyCAdUiPaletteSet
void makePyCAdUiPaletteSetWrapper();
class PyCAdUiPaletteSet : public boost::python::wrapper<PyCAdUiPaletteSet>
{
public:
    PyCAdUiPaletteSet(const std::string& name);
    PyCAdUiPaletteSet(const std::string& name, const std::string& guid);
    virtual ~PyCAdUiPaletteSet() = default;
public: //INTERNAL
    void        createChildren();
    bool        create();

public:
    int         add(const std::string& name, boost::python::object& panel);
    void        setVisible(bool show);
    DWORD       getPaletteSetStyle();
    void        setPaletteSetStyle(DWORD dwStyle);
    bool        autoRollupStyle();
    bool        propertiesMenuStyle();
    bool        closeButtonStyle();
    bool        singlePaletteTabStyle();
    bool        useSinglePaletteTabNameStyle();
    bool        editNameStyle();
    bool        snapStyle();
    bool        showRollupButtonStyle();
    bool        showIconStyle();
    std::string getName();
    bool        setName(const std::string& name);
    bool        setToolId(const std::string& guid);
    int         getOpacity() const;
    bool        setOpacity(int nOpacity);
    int         getRolloverOpacity() const;
    bool        setRolloverOpacity(int nOpacity);
    int         getActivePaletteTabIndex();
    bool        setActivePalette(int nPaletteIndex);
    bool        setAutoRollup(bool flag);
    bool        getAutoRollup();
    void        rollOut1();
    void        rollOut2(bool bDelay);
    void        rollUp();
    bool        removePalette(int nPaletteIndex);
    int         getPaletteCount();
    PyObject*   getFullRect();//TODO test:
    bool        rolledUp();
    CAdUiPaletteSet::AdUiTitleBarLocation titleBarLocation();
    void        setTitleBarLocation(CAdUiPaletteSet::AdUiTitleBarLocation loc);
    void        updateTabs();
    COLORREF    paletteBackgroundColor() const;
    COLORREF    paletteTabTextColor() const;

public: //INTERNAL
    PyCAdUiPaletteSetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<PyCAdUiPaletteSetImpl> m_pyImp;
    std::vector<PyCAdUiPalette> m_children;
#if defined(_BRXTARGET)
    CString m_name; //this is for _BRXTARGET SR176835
#endif
    bool m_created = false;
};


//---------------------------------------------------------------------
//PyCAdUiPaletteImpl
class PyCAdUiPaletteImpl : public CAdUiPalette
{
    DECLARE_DYNAMIC(PyCAdUiPaletteImpl);

public:
    PyCAdUiPaletteImpl();
    PyCAdUiPaletteImpl(PyCAdUiPalette* bckPtr, wxPanel* panel);
    virtual ~PyCAdUiPaletteImpl() override = default;
    DECLARE_MESSAGE_MAP();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    wxWindow* thiswindow(const std::source_location& src = std::source_location::current()) const;
    wxWindow* ownerwin(const std::source_location& src = std::source_location::current()) const;
    wxPanel* panel(const std::source_location& src = std::source_location::current()) const;
    PyCAdUiPalette* bckptr(const std::source_location& src = std::source_location::current()) const;
private:

    wxPanel* m_panel = nullptr;
    wxWindow* m_thiswin = nullptr;
    wxWindow* m_ownerwin = nullptr;
    PyCAdUiPalette* m_bckPtr = nullptr;
};


//---------------------------------------------------------------------
//PyCAdUiPalette
void makePyCAdUiPaletteWrapper();
class PyCAdUiPalette
{
public:
    PyCAdUiPalette(const std::string& name, wxPanel* panel);
    virtual ~PyCAdUiPalette() = default;
    PyCAdUiPaletteImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<PyCAdUiPaletteImpl> m_pyImp;
};