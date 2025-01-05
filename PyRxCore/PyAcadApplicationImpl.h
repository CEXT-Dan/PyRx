#pragma once

#ifdef PYRXDEBUG

#include "PyAcad.h" 

using wstringArray = std::vector<std::wstring>;

//------------------------------------------------------------------------------------
//PyAcadStateImpl
class PyAcadStateImpl
{
public:
    explicit PyAcadStateImpl(IAcadState* ptr);
    ~PyAcadStateImpl() = default;
    bool getIsQuiescent() const;
    IAcadState* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadStatePtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadDocumentImpl
class PyIAcadDocumentImpl
{
public:
    explicit PyIAcadDocumentImpl(IAcadDocument* ptr);
    ~PyIAcadDocumentImpl() = default;
    IAcadDocument* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDocumentPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadDocumentsImpl
class PyIAcadDocumentsImpl
{
public:
    explicit PyIAcadDocumentsImpl(IAcadDocuments* ptr);
    ~PyIAcadDocumentsImpl() = default;
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
    PyAcadStateImpl         GetAcadState();
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
    PyIAcadDocumentsImpl    getDocuments() const;
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
    static bool             runTest();
public:
    IAcadApplication* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadApplicationPtr m_pimpl;
};



#endif