#pragma once

#pragma pack (push, 8)
class PyCAdUiPalette;
class PyCAdUiPaletteSet;

enum class PaletteDockStyle : int
{
    kNone = 0,
    kLeft = CBRS_ALIGN_LEFT,
    kRight = CBRS_ALIGN_RIGHT,
    kTop = CBRS_ALIGN_TOP,
    kBottom = CBRS_ALIGN_BOTTOM,
    kAny = CBRS_ALIGN_ANY,
};

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

    bool             anchored();
    void             enableDocking(PaletteDockStyle dwDockStyle);
    void             setDockState(PaletteDockStyle dwDockStyle);
    PaletteDockStyle getDockState();

    void        setSize(int x, int y);
    void        setLocation(int x, int y);
    bool        isFloating();
    void        initFloatingPosition(boost::python::tuple& pyrect);
    boost::python::tuple getFloatingRect();
    void        dockControlBar(PaletteDockStyle dwDockStyle, boost::python::tuple& pyrect);
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
    void        restoreControlBar1();
    void        restoreControlBar2(PaletteDockStyle dwDockStyle, boost::python::tuple& pyrect);
    int         getPaletteCount();
    PyObject* getFullRect();
    bool        rolledUp();
    CAdUiPaletteSet::AdUiTitleBarLocation titleBarLocation();
    void        setTitleBarLocation(CAdUiPaletteSet::AdUiTitleBarLocation loc);
    void        updateTabs();
    COLORREF    paletteBackgroundColor() const;
    COLORREF    paletteTabTextColor() const;
    wxTopLevelWindow* getWxWindow();
    PyObject* getPyWxWindow();

    static      bool showPalettes();
    static      bool hidePalettes();

public: //INTERNAL
    PyCAdUiPaletteSetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<PyCAdUiPaletteSetImpl> m_pyImp;
    std::vector<PyCAdUiPalette> m_children;
    CString m_name;
    GUID m_guid = { GUID_NULL };
    PaletteDockStyle m_docStyle = PaletteDockStyle::kAny;
    wxTopLevelWindow* m_thisFrame = nullptr;
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
    void setPyPaletteSet(PyCAdUiPaletteSet* paletteSet);
private:
    friend PyCAdUiPalette;

    wxPanel* m_panel = nullptr;
    wxWindow* m_thiswin = nullptr;
    PyCAdUiPalette* m_bckPtr = nullptr;
    PyCAdUiPaletteSet* m_paletteSet = nullptr;
};

//---------------------------------------------------------------------
//PyCAdUiPalette
void makePyCAdUiPaletteWrapper();
class PyCAdUiPalette
{
public:
    PyCAdUiPalette(const std::string& name, wxPanel* panel);
    virtual ~PyCAdUiPalette() = default;
    void setPyPaletteSet(PyCAdUiPaletteSet* paletteSet);
    PyObject* getPyWxWindow() const;
    PyCAdUiPaletteImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<PyCAdUiPaletteImpl> m_pyImp;
};

#pragma pack (pop)
