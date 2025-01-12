#pragma once

#ifdef PYRX_IN_PROGRESS_PYAX

class PyAcadApplicationImpl;


//----------------------------------------------------------------------------------------
//PyAcadApplication
void makePyAcadApplicationWrapper();

class PyAcadApplication
{
public:
    PyAcadApplication();
    virtual ~PyAcadApplication() = default;

    void                    eval(const std::string& sval) const;
    //PyAcadStateImpl         GetAcadState();
    boost::python::list     listArx() const;
    void                    loadArx(const std::string& sval);
    void                    loadDVB(const std::string& sval);
    void                    quit();
    void                    runMacro(const std::string& sval);

    void                    unloadArx(const std::string& sval);
    void                    unloadDVB(const std::string& sval);
    void                    update();
    //void                    Zoom(int ...);
    void                    zoomAll();
    void                    zoomCenter(const AcGePoint3d& pnt, double magnify);
    void                    zoomExtents();
    void                    zoomPickWindow();
    void                    zoomPrevious();
    //void                    zoomScaled(double magnify, AcZoomScaleType scaletype);
    //--properties
    //PyIAcadDocumentImpl     GetActiveDocument() const;
    //void                    SetActiveDocument(const PyIAcadDocumentImpl& val) const;
    //CString                 GetCaption() const;
    //PyIAcadDocumentsImpl    getDocuments() const;
    //CString                 GetFullName() const;
    //int                     GetHeight() const;
    //void                    SetHeight(int val);
    //LONG_PTR                GetHWND() const;
    //long                    GetLocaleId() const;
    //MenuBar
    //MenuGroups
    //CString                 GetName() const;
    //CString                 GetPath() const;
    //Preferences
    //StatusId();
    //CString                 GetVersion() const;
    //bool                    GetVisible() const;
    //void                    SetVisible(bool val);
    //int                     GetWidth() const;
    //void                    SetWidth(int val);
    //int                     GetWindowLeft() const;
    //void                    SetWindowLeft(int val);
    //AcWindowState           GetWindowState() const;
    //void                    SetWindowState(AcWindowState val);
    //int                     GetWindowTop() const;
    //void                    SetWindowTop(int val);
  
    static std::string      className();

    //internal 
    static bool             runTest(const AcDbObjectId& id);
public:

    PyAcadApplicationImpl*  impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<PyAcadApplicationImpl> m_pyImp;
};


#endif
