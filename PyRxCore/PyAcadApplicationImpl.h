#pragma once
#include "PyAcadDatabaseImpl.h"

using wstringArray = std::vector<std::wstring>;

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
    CString         GetName() const;
    IAcadDocument*  impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDocumentsImpl
class PyIAcadDocumentsImpl;
using PyIAcadDocumentsPtr = std::unique_ptr<PyIAcadDocumentsImpl>;
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
    IAcadDocuments*     impObj(const std::source_location& src = std::source_location::current()) const;
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
    void                    ZoomScaled(double magnify, AcZoomScaleType scaletype);
    //--properties
    PyIAcadDocumentImpl     GetActiveDocument() const;
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
    AcWindowState           GetWindowState() const;
    void                    SetWindowState(AcWindowState val);
    int                     GetWindowTop() const;
    void                    SetWindowTop(int val);

    //inernal
    static bool             runTest(const AcDbObjectId& id);
public:
    IAcadApplication* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadApplicationPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//IAcadUtilityImpl
class PyIAcadUtility
{
public:
    explicit PyIAcadUtility(IAcadUtility* ptr);
    virtual ~PyIAcadUtility() = default;
    IAcadUtility* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadUtilityPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadSecurityParamsImpl
class PyIAcadSecurityParams
{
public:
    explicit PyIAcadSecurityParams(IAcadSecurityParams* ptr);
    virtual ~PyIAcadSecurityParams() = default;
    IAcadSecurityParams* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSecurityParamsPtr m_pimpl;
};
