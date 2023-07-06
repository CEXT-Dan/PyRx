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
    afx_msg void OnDestroy();

public:
    PyCAdUiPaletteSet* bckptr(const std::source_location& src = std::source_location::current()) const;

public:
    CString m_USRGUID;
private:
    PyCAdUiPaletteSet* m_bckPtr = nullptr;
};

//---------------------------------------------------------------------
//PyCAdUiPaletteSet
class PyCAdUiPaletteSet
{
public:
    PyCAdUiPaletteSet(const std::string& name);
    PyCAdUiPaletteSet(const std::string& name, const std::string& guid);

    void Add(const std::string& name, UINT_PTR panel);

    PyCAdUiPaletteSetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<PyCAdUiPaletteSetImpl> m_pyImp;
    std::vector< PyCAdUiPalette> m_children;
};


//---------------------------------------------------------------------
//PyCAdUiPaletteImpl
class PyCAdUiPaletteImpl : public CAdUiPalette
{
    DECLARE_DYNAMIC(PyCAdUiPaletteImpl);

public:
    PyCAdUiPaletteImpl();
    PyCAdUiPaletteImpl(PyCAdUiPalette* bckPtr);
    virtual ~PyCAdUiPaletteImpl() override = default;
    DECLARE_MESSAGE_MAP();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    PyCAdUiPalette* bckptr(const std::source_location& src = std::source_location::current()) const;

private:
    PyCAdUiPalette* m_bckPtr = nullptr;
};


//---------------------------------------------------------------------
//PyCAdUiPalette
class PyCAdUiPalette
{
public:
    PyCAdUiPalette(const std::string& name, UINT_PTR panel);

public:
    CWnd* impWnd(const std::source_location& src = std::source_location::current());
    PyCAdUiPaletteImpl* impObj(const std::source_location& src = std::source_location::current()) const;

    HWND panel() const;
private:
    HWND m_panel = 0;
    std::shared_ptr<PyCAdUiPaletteImpl> m_pyImp;
};