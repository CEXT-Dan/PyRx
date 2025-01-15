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

   
    //virtual HRESULT __stdcall get_PickfirstSelectionSet(
    //    /*[out,retval]*/ struct IAcadSelectionSet** pSelSet) = 0;
    //virtual HRESULT __stdcall get_Active(
    //    /*[out,retval]*/ VARIANT_BOOL* pvbActive) = 0;
    //virtual HRESULT __stdcall Activate() = 0;
    //virtual HRESULT __stdcall Close(
    //    /*[in]*/ VARIANT SaveChanges = vtMissing,
    //    /*[in]*/ VARIANT FileName = vtMissing) = 0;
    //virtual HRESULT __stdcall put_WindowState(
    //    /*[in]*/ enum AcWindowState pWinState) = 0;
    //virtual HRESULT __stdcall get_WindowState(
    //    /*[out,retval]*/ enum AcWindowState* pWinState) = 0;
    //virtual HRESULT __stdcall put_Width(
    //    /*[in]*/ int pWidth) = 0;
    //virtual HRESULT __stdcall get_Width(
    //    /*[out,retval]*/ int* pWidth) = 0;
    //virtual HRESULT __stdcall put_Height(
    //    /*[in]*/ int pHeight) = 0;
    //virtual HRESULT __stdcall get_Height(
    //    /*[out,retval]*/ int* pHeight) = 0;
    //virtual HRESULT __stdcall put_ActiveLayout(
    //    /*[in]*/ struct IAcadLayout* pLayout) = 0;
    //virtual HRESULT __stdcall get_ActiveLayout(
    //    /*[out,retval]*/ struct IAcadLayout** pLayout) = 0;
    //virtual HRESULT __stdcall SendCommand(
    //    /*[in]*/ BSTR Command) = 0;
    //virtual HRESULT __stdcall get_HWND(
    //    /*[out,retval]*/ LONG_PTR* HWND) = 0;
    //virtual HRESULT __stdcall get_WindowTitle(
    //    /*[out,retval]*/ BSTR* Title) = 0;
    //virtual HRESULT __stdcall get_Application(
    //    /*[out,retval]*/ struct IAcadApplication** pAppObj) = 0;
    //virtual HRESULT __stdcall get_Database(
    //    /*[out,retval]*/ struct IAcadDatabase** pDatabase) = 0;
    //virtual HRESULT __stdcall StartUndoMark() = 0;
    //virtual HRESULT __stdcall EndUndoMark() = 0;
    //virtual HRESULT __stdcall get_ActiveMaterial(
    //    /*[out,retval]*/ struct IAcadMaterial** pActMaterial) = 0;
    //virtual HRESULT __stdcall put_ActiveMaterial(
    //    /*[in]*/ struct IAcadMaterial* pActMaterial) = 0;
    //virtual HRESULT __stdcall PostCommand(
    //    /*[in]*/ BSTR Command) = 0;
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
    //void                    Zoom(int ...);
    void                    ZoomAll();
    void                    ZoomCenter(const AcGePoint3d& pnt, double magnify);
    void                    ZoomExtents();
    void                    ZoomPickWindow();
    void                    ZoomPrevious();
    void                    ZoomScaled(double magnify, PyAcZoomScaleType scaletype);
    //--properties
    PyIAcadDocumentPtr      GetActiveDocument() const;
    void                    SetActiveDocument(const PyIAcadDocumentImpl& val) const;
    CString                 GetCaption() const;
    PyIAcadDocumentsPtr     GetDocuments() const;//
    CString                 GetFullName() const;
    int                     GetHeight() const;
    void                    SetHeight(int val);
    LONG_PTR                GetHWND() const;
    long                    GetLocaleId() const;
    //MenuBar
    //MenuGroups
    CString                 GetName() const;
    CString                 GetPath() const;
    //Preferences
    //StatusId();
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
