#pragma once
#include "PyDbLayout.h"

#pragma pack (push, 8)
//-----------------------------------------------------------------------------------------
//PyApLayoutManager
void makePyApLayoutManagerWrapper();

class PyApLayoutManager : public PyDbLayoutManager
{
public:
    PyApLayoutManager();
    PyApLayoutManager(AcApLayoutManager* ptr, bool autoDelete);
    int                 pageSetup1();
    int                 pageSetup2(const PyDbObjectId &lid);
    int                 pageSetup3(const PyDbObjectId& lid, UINT_PTR hwnd, Adesk::Boolean  isPageSetupDlg);
    void                updateCurrentPaper1();
    void                updateCurrentPaper2(Adesk::Boolean zoomToPaper);
    void                updateLayoutTabs();
    std::string         getActiveTab();
    Adesk::Boolean      showTabs();
    void                setShowTabs(Adesk::Boolean showTabs);
    Adesk::Boolean      showPageSetup();
    void                setShowPageSetup(Adesk::Boolean showPageSetupDlg);
    Adesk::Boolean      createViewports();
    void                setCreateViewports(Adesk::Boolean createViewports);
    Adesk::Boolean      showPaperBackground();
    void                setShowPaperBackground(Adesk::Boolean showPaperBackground);
    Adesk::Boolean      showPaperMargins();
    void                setShowPaperMargins(Adesk::Boolean showPaperMargins);
    Adesk::Boolean      showPrintBorder();
    void                setShowPrintBorder(Adesk::Boolean showPrintBorder);
    std::string         generateNextNewLayoutName1();
    std::string         generateNextNewLayoutName2(PyDbDatabase& useDb);
    void                setDefaultPlotConfig(PyDbObjectId& layoutBTRId);
    boost::python::list getClipBoundaryElabration(const PyDbObjectId& clipId);
    boost::python::list pointInViewports(const AcGePoint3d& pickPt);
    void                setCaptureOnLayoutSwitch(bool bCaptureOnLayout);
    PyDbObjectId        createLayoutFromTemplate1(const std::string& newLayoutName, const std::string& templatePath, const std::string& layoutName);
    PyDbObjectId        createLayoutFromTemplate2(const std::string& newLayoutName, const std::string& templatePath, const std::string& layoutName, PyDbDatabase& pDb);

public:
    static PyRxClass            desc();
    static std::string          className();
public:
    AcApLayoutManager* impObj(const std::source_location& src = std::source_location::current()) const;

};

#pragma pack (pop)
