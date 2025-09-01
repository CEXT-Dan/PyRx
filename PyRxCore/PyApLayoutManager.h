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
    virtual ~PyApLayoutManager() override = default;

    int                 pageSetup1() const;
    int                 pageSetup2(const PyDbObjectId& lid) const;
    int                 pageSetup3(const PyDbObjectId& lid, UINT_PTR hwnd, Adesk::Boolean  isPageSetupDlg) const;
    void                updateCurrentPaper1() const;
    void                updateCurrentPaper2(Adesk::Boolean zoomToPaper) const;
    void                updateLayoutTabs() const;
    std::string         getActiveTab() const;
    Adesk::Boolean      showTabs() const;
    void                setShowTabs(Adesk::Boolean showTabs) const;
    Adesk::Boolean      showPageSetup() const;
    void                setShowPageSetup(Adesk::Boolean showPageSetupDlg) const;
    Adesk::Boolean      createViewports() const;
    void                setCreateViewports(Adesk::Boolean createViewports) const;
    Adesk::Boolean      showPaperBackground() const;
    void                setShowPaperBackground(Adesk::Boolean showPaperBackground) const;
    Adesk::Boolean      showPaperMargins() const;
    void                setShowPaperMargins(Adesk::Boolean showPaperMargins) const;
    Adesk::Boolean      showPrintBorder() const;
    void                setShowPrintBorder(Adesk::Boolean showPrintBorder) const;
    std::string         generateNextNewLayoutName1() const;
    std::string         generateNextNewLayoutName2(PyDbDatabase& useDb) const;
    void                setDefaultPlotConfig(PyDbObjectId& layoutBTRId) const;
    boost::python::list getClipBoundaryElabration(const PyDbObjectId& clipId) const;
    boost::python::list pointInViewports(const AcGePoint3d& pickPt) const;
    void                setCaptureOnLayoutSwitch(bool bCaptureOnLayout) const;
    PyDbObjectId        createLayoutFromTemplate1(const std::string& newLayoutName, const std::string& templatePath, const std::string& layoutName) const;
    PyDbObjectId        createLayoutFromTemplate2(const std::string& newLayoutName, const std::string& templatePath, const std::string& layoutName, PyDbDatabase& pDb) const;

public:
    static PyRxClass    desc();
    static std::string  className();
public:
    AcApLayoutManager* impObj(const std::source_location& src = std::source_location::current()) const;

};

#pragma pack (pop)
