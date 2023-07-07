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
private:
    PyCAdUiPaletteSet* m_bckPtr = nullptr;
};

//---------------------------------------------------------------------
//PyCAdUiPaletteSet
void makePyCAdUiPaletteSetWrapper();
class PyCAdUiPaletteSet
{
public:
    PyCAdUiPaletteSet(const std::string& name);
    PyCAdUiPaletteSet(const std::string& name, const std::string& guid);

    int add(const std::string& name, boost::python::object& panel);
    bool create();
    void setVisible(bool show);
    void createChildren();

    PyCAdUiPaletteSetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<PyCAdUiPaletteSetImpl> m_pyImp;
    std::vector<PyCAdUiPalette> m_children;
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
    PyCAdUiPalette* bckptr(const std::source_location& src = std::source_location::current()) const;
private:
    wxPanel* m_panel = nullptr;
    PyCAdUiPalette* m_bckPtr = nullptr;
};


//---------------------------------------------------------------------
//PyCAdUiPalette
void makePyCAdUiPaletteWrapper();
class PyCAdUiPalette
{
public:
    PyCAdUiPalette(const std::string& name, wxPanel* panel);
    PyCAdUiPaletteImpl* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<PyCAdUiPaletteImpl> m_pyImp;
};