#pragma once
#include "PyAcadDatabaseImpl.h"

using wstringArray = std::vector<std::wstring>;

class PyIAcadDocumentsImpl;
using PyIAcadDocumentsPtr = std::unique_ptr<PyIAcadDocumentsImpl>;
class PyIAcadSelectionSetImpl;
using PyIAcadSelectionSetPtr = std::unique_ptr<PyIAcadSelectionSetImpl>;
class PyIAcadSelectionSetsImpl;
using PyIAcadSelectionSetsPtr = std::unique_ptr<PyIAcadSelectionSetsImpl>;
class PyIAcadUtilityImpl;
using PyIAcadUtilityPtr = std::unique_ptr<PyIAcadUtilityImpl>;
class PyIAcadSecurityParamsImpl;
using PyIAcadSecurityParamsPtr = std::unique_ptr<PyIAcadSecurityParamsImpl>;
class PyIAcadMenuBarImpl;
using PyIAcadMenuBarPtr = std::unique_ptr<PyIAcadMenuBarImpl>;
class PyIAcadMenuGroupsImpl;
using PyIAcadMenuGroupsPtr = std::unique_ptr<PyIAcadMenuGroupsImpl>;
class PyIAcadPreferencesImpl;
using PyIAcadPreferencesPtr = std::unique_ptr<PyIAcadPreferencesImpl>;


//------------------------------------------------------------------------------------
//PyAcadStateImpl
class PyIAcadStateImpl;
using PyIAcadStateImplPtr = std::unique_ptr<PyIAcadStateImpl>;
class PyIAcadStateImpl
{
public:
    explicit PyIAcadStateImpl(IAcadState* ptr);
    ~PyIAcadStateImpl() = default;
    bool getIsQuiescent() const;
    IAcadState* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadStatePtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadDatabaseImpl
class PyIAcadDatabaseImpl;
using  PyIAcadDatabasePtr = std::unique_ptr<PyIAcadDatabaseImpl>;
class PyIAcadDatabaseImpl
{
public:
    explicit PyIAcadDatabaseImpl(IAcadDatabase* ptr);
    virtual ~PyIAcadDatabaseImpl() = default;
    IAcadDatabase* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDatabasePtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadDocumentImpl
class PyIAcadDocumentImpl;
using PyIAcadDocumentPtr = std::unique_ptr<PyIAcadDocumentImpl>;
class PyIAcadDocumentImpl : public PyIAcadDatabaseImpl
{
public:
    explicit PyIAcadDocumentImpl(IAcadDocument* ptr);
    virtual ~PyIAcadDocumentImpl() override = default;

    PyIAcadPlotPtr              GetPlot() const;
    PyIAcadLayerPtr             GetActiveLayer() const;
    void                        SetActiveLayer(const PyIAcadLayerImpl& obj);
    PyIAcadLineTypePtr          GetActiveLinetype() const;
    void                        SetActiveLinetype(const PyIAcadLineTypeImpl& obj);
    PyIAcadDimStylePtr          GetActiveDimStyle() const;
    void                        SetActiveDimStyle(const PyIAcadDimStyleImpl& obj);
    PyIAcadTextStylePtr         GetActiveTextStyle() const;
    void                        SetActiveTextStyle(const PyIAcadTextStyleImpl& obj);
    PyIAcadUCSPtr               GetActiveUCS() const;
    void                        SetActiveUCS(const PyIAcadUCSImpl& obj);
    PyIAcadViewportPtr          GetActiveViewport() const;
    void                        SetActiveViewport(const PyIAcadViewportImpl& obj);
    PyIAcadPViewportPtr         GetActivePViewport() const;
    void                        SetActivePViewport(const PyIAcadPViewportImpl& obj);
    PyAcActiveSpace             GetActiveSpace() const;
    void                        SetActiveSpace(PyAcActiveSpace sp) const;
    PyIAcadSelectionSetsPtr     GetSelectionSets() const;
    PyIAcadSelectionSetPtr      GetActiveSelectionSet() const;
    CString                     GetName() const;
    CString                     GetFullName() const;
    CString                     GetPath() const;
    bool                        GetObjectSnapMode() const;
    void                        SetObjectSnapMode(bool flag);
    bool                        GetReadOnly() const;
    bool                        GetSaved() const;
    bool                        GetMSpace() const;
    void                        SetMSpace(bool flag);
    PyIAcadUtilityPtr           GetUtility() const;
    PyIAcadDocumentPtr          Open(const CString& path);
    void                        AuditInfo(bool flag);
    PyIAcadBlockReferencePtr    Import(const CString& path, const AcGePoint3d& InsertionPoint, double ScaleFactor);
    void                        Export(const CString& fileName, const CString& extension, const PyIAcadSelectionSetImpl& sset);
    PyIAcadDocumentPtr          New(const CString& path);
    void                        Save();
    void                        SaveAs(const CString& fileName);
    void                        SaveAs(const CString& fileName, PyAcSaveAsType saType);
    void                        SaveAs(const CString& fileName, PyAcSaveAsType saType, const PyIAcadSecurityParamsImpl& pr);
    void                        Wblock(const CString& fileName, const PyIAcadSelectionSetImpl& sset);
    void                        PurgeAll();
    TypedVariant                GetVariable(const CString& name);
    void                        SetVariable(const CString& name, const TypedVariant& tv);
    void                        LoadShapeFile(const CString& name);
    void                        Regen(PyAcRegenType rt);
    PyIAcadSelectionSetPtr      GetPickfirstSelectionSet() const;
    bool                        IsActive();
    void                        Activate();
    void                        Close();
    void                        Close(bool SaveChanges);
    void                        Close(bool SaveChanges, const CString& fileName);
    PyAcWindowState             GetWindowState() const;
    void                        SetWindowState(PyAcWindowState val);
    int                         GetWidth() const;
    void                        SetWidth(int val);
    int                         GetHeight() const;
    void                        SetHeight(int val);
    PyIAcadLayoutPtr            GetActiveLayout() const;
    void                        SetActiveLayout(const PyIAcadLayoutImpl& val);
    void                        SendCommand(const CString& cmd);
    void                        PostCommand(const CString& cmd);
    LONG_PTR                    GetHWND() const;
    CString                     GetWindowTitle() const;
    void                        StartUndoMark();
    void                        EndUndoMark();
    PyIAcadDatabasePtr          GetDatabase() const;
    PyIAcadMaterialPtr          GetActiveMaterial() const;
    void                        SetActiveMaterial(const PyIAcadMaterialImpl& val);
    IAcadDocument* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDocumentsImpl
class PyIAcadDocumentsImpl
{
public:
    explicit PyIAcadDocumentsImpl(IAcadDocuments* ptr);
    ~PyIAcadDocumentsImpl() = default;
    long                GetCount() const;
    PyIAcadDocumentPtr  Add();
    PyIAcadDocumentPtr  Add(const CString& _template);
    void                Close();
    PyIAcadDocumentPtr  GetItem(long index);
    PyIAcadDocumentPtr  Open(const CString& path, bool readOnly);
    IAcadDocuments* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDocumentsPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyAcadApplicationImpl
class PyAcadApplicationImpl
{
public:
    PyAcadApplicationImpl();
    PyAcadApplicationImpl(IAcadApplication* ptr);
    ~PyAcadApplicationImpl() = default;
    void                    Eval(const CString& csVal) const;
    PyIAcadStateImplPtr     GetAcadState();
    wstringArray            ListArx();
    void                    LoadArx(const CString& csVal);
    void                    LoadDVB(const CString& csVal);
    void                    Quit();
    void                    RunMacro(const CString& csVal);
    void                    UnloadArx(const CString& csVal);
    void                    UnloadDVB(const CString& csVal);
    void                    Update();
    void                    ZoomAll();
    void                    ZoomCenter(const AcGePoint3d& pnt, double magnify);
    void                    ZoomExtents();
    void                    ZoomPickWindow();
    void                    ZoomPrevious();
    void                    ZoomScaled(double magnify, PyAcZoomScaleType scaletype);
    PyIAcadDocumentPtr      GetActiveDocument() const;
    void                    SetActiveDocument(const PyIAcadDocumentImpl& val) const;
    CString                 GetCaption() const;
    PyIAcadDocumentsPtr     GetDocuments() const;//
    CString                 GetFullName() const;
    int                     GetHeight() const;
    void                    SetHeight(int val);
    LONG_PTR                GetHWND() const;
    long                    GetLocaleId() const;
    PyIAcadMenuBarPtr       GetMenuBar() const;
    PyIAcadMenuGroupsPtr    GetMenuGroups() const;
    CString                 GetName() const;
    CString                 GetPath() const;
    PyIAcadPreferencesPtr   GetPreferences();
    CString                 GetVersion() const;
    bool                    GetVisible() const;
    void                    SetVisible(bool val);
    int                     GetWidth() const;
    void                    SetWidth(int val);
    int                     GetWindowLeft() const;
    void                    SetWindowLeft(int val);
    PyAcWindowState         GetWindowState() const;
    void                    SetWindowState(PyAcWindowState val);
    int                     GetWindowTop() const;
    void                    SetWindowTop(int val);

    //internal
    static bool             runTest(const AcDbObjectId& id);
public:
    IAcadApplication* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadApplicationPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//IAcadUtilityImpl
class PyIAcadUtilityImpl
{
public:
    explicit PyIAcadUtilityImpl(IAcadUtility* ptr);
    virtual ~PyIAcadUtilityImpl() = default;
    IAcadUtility* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadUtilityPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadSecurityParamsImpl
class PyIAcadSecurityParamsImpl
{
public:
    explicit PyIAcadSecurityParamsImpl(IAcadSecurityParams* ptr);
    virtual ~PyIAcadSecurityParamsImpl() = default;
    IAcadSecurityParams* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSecurityParamsPtr m_pimpl;
};


//------------------------------------------------------------------------------------
//PyIAcadSelectionSetsImpl
class PyIAcadSelectionSetsImpl
{
public:
    explicit PyIAcadSelectionSetsImpl(IAcadSelectionSets* ptr);
    virtual ~PyIAcadSelectionSetsImpl() = default;
    IAcadSelectionSets* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSelectionSetsPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadSelectionSetImpl
class PyIAcadSelectionSetImpl
{
public:
    explicit PyIAcadSelectionSetImpl(IAcadSelectionSet* ptr);
    virtual ~PyIAcadSelectionSetImpl() = default;
    IAcadSelectionSet* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSelectionSetPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadMenuBarImpl
class PyIAcadMenuBarImpl
{
public:
    explicit PyIAcadMenuBarImpl(IAcadMenuBar* ptr);
    virtual ~PyIAcadMenuBarImpl() = default;
    IAcadMenuBar* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadMenuBarPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadMenuGroupsImpl
class PyIAcadMenuGroupsImpl
{
public:
    explicit PyIAcadMenuGroupsImpl(IAcadMenuGroups* ptr);
    virtual ~PyIAcadMenuGroupsImpl() = default;
    IAcadMenuGroups* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadMenuGroupsPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadPreferencesImpl
class PyIAcadPreferencesImpl
{
public:
    explicit PyIAcadPreferencesImpl(IAcadPreferences* ptr);
    virtual ~PyIAcadPreferencesImpl() = default;
    IAcadPreferences* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesPtr m_pimpl;
};
