#pragma once

#include "PyAcAxCommon.h"

class PyIAcadStateImpl;
class PyAcadState;
class PyAcadApplicationImpl;
class PyIAcadDocumentsImpl;
class PyAcadDocuments;
class PyIAcadDatabaseImpl;
class PyAcadDatabase;
class PyIAcadDocumentImpl;
class PyAcadDocument;
class PyAcadMenuBar;
class PyAcadMenuBar;
class PyAcadMenuGroups;
class PyAcadPreferences;

//------------------------------------------------------------------------------------
//PyAcadState
void makePyAcadStateWrapper();

class PyAcadState
{
public:
    explicit PyAcadState(std::shared_ptr<PyIAcadStateImpl> ptr);
    virtual ~PyAcadState() = default;
    bool                isQuiescent() const;
    static std::string  className();
public:
    PyIAcadStateImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyIAcadStateImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadApplication
void makePyAcadApplicationWrapper();

class PyAcadApplication
{
public:
    PyAcadApplication();
    virtual ~PyAcadApplication() = default;

    void                    eval(const std::string& sval) const;
    PyAcadState             acadState();
    boost::python::list     listArx() const;
    void                    loadArx(const std::string& sval);
    void                    loadDVB(const std::string& sval);
    void                    quit();
    void                    runMacro(const std::string& sval);
    void                    unloadArx(const std::string& sval);
    void                    unloadDVB(const std::string& sval);
    void                    update();
    void                    zoomAll();
    void                    zoomCenter(const AcGePoint3d& pnt, double magnify);
    void                    zoomExtents();
    void                    zoomPickWindow();
    void                    zoomPrevious();
    void                    zoomScaled(double magnify, PyAcZoomScaleType scaletype);
    PyAcadDocument          activeDocument() const;
    void                    setActiveDocument(const PyAcadDocument& val) const;
    std::string             caption() const;
    PyAcadDocuments         documents() const;
    std::string             fullName() const;
    int                     getHeight() const;
    void                    setHeight(int val);
    LONG_PTR                getHWND() const;
    long                    localeId() const;
    PyAcadMenuBar           menuBar() const;
    PyAcadMenuGroups        menuGroups() const;
    std::string             getName() const;
    std::string             getPath() const;
    PyAcadPreferences       preferences();
    //StatusId();
    std::string             version() const;
    bool                    isVisible() const;
    void                    setVisible(bool val);
    int                     getWidth() const;
    void                    setWidth(int val);
    int                     getWindowLeft() const;
    void                    setWindowLeft(int val);
    PyAcWindowState         getWindowState() const;
    void                    setWindowState(PyAcWindowState val);
    int                     getWindowTop() const;
    void                    setWindowTop(int val);
    static std::string      className();

    //internal 
    static bool             runTest(const AcDbObjectId& id);
public:
    PyAcadApplicationImpl*  impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyAcadApplicationImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadDocuments
void makePyAcadDocumentsWrapper();

class PyAcadDocuments
{
public:
    explicit PyAcadDocuments(std::shared_ptr<PyIAcadDocumentsImpl> ptr) noexcept;
    virtual ~PyAcadDocuments() = default;
    long                count() const;
    PyAcadDocument      add1();
    PyAcadDocument      add2(const std::string& _template);
    void                close();
    PyAcadDocument      item(long index);
    PyAcadDocument      open(const std::string& path, bool readOnly);
    static std::string  className();
public:
    PyIAcadDocumentsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyIAcadDocumentsImpl> m_pyImp;
};


//----------------------------------------------------------------------------------------
//PyAcadDatabase
void makePyAcadDatabaseWrapper();

class PyAcadDatabase
{
public:
    explicit PyAcadDatabase(std::shared_ptr<PyIAcadDatabaseImpl> ptr) noexcept;
    virtual ~PyAcadDatabase() = default;
    static std::string    className();
public:
    PyIAcadDatabaseImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyIAcadDatabaseImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadDocument
void makePyAcadDocumentWrapper();

class PyAcadDocument : public PyAcadDatabase
{
public:
    explicit PyAcadDocument(std::shared_ptr<PyIAcadDocumentImpl> ptr);
    virtual ~PyAcadDocument() = default;
    std::string     name() const;
    static std::string    className();
public:
    PyIAcadDocumentImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
};

