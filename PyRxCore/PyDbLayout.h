#pragma once
#include "PyDbObject.h"

#pragma pack (push, 8)
class PyDbObjectId;
class PyDbDatabase;

//---------------------------------------------------------------------------------------- -
//PyDbPlotSettings
void makePyDbPlotSettingsWrapper();

class PyDbPlotSettings : public PyDbObject
{
public:
    PyDbPlotSettings();
    PyDbPlotSettings(bool ModelType);
    PyDbPlotSettings(AcDbPlotSettings* ptr, bool autoDelete);
    PyDbPlotSettings(const PyDbObjectId& id);
    PyDbPlotSettings(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbPlotSettings(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbPlotSettings() override = default;
    void                    addToPlotSettingsDict(PyDbDatabase& towhichDb) const;
    std::string             getPlotSettingsName() const;
    void                    setPlotSettingsName(const  std::string& plotSettingsName) const;
    std::string             getPlotCfgName() const;
    boost::python::tuple    getPlotPaperMargins() const;
    boost::python::tuple    getPlotPaperSize() const;
    std::string             getCanonicalMediaName() const;
    boost::python::tuple    getPlotOrigin() const;
    AcDbPlotSettings::PlotPaperUnits plotPaperUnits() const;
    Adesk::Boolean          plotViewportBorders() const;
    void                    setPlotViewportBorders(Adesk::Boolean plotViewportBorders) const;
    Adesk::Boolean          plotTransparency() const;
    void                    setPlotTransparency(Adesk::Boolean plotTransparency) const;
    Adesk::Boolean          plotPlotStyles() const;
    void                    setPlotPlotStyles(Adesk::Boolean plotPlotStyles) const;
    Adesk::Boolean          showPlotStyles() const;
    void                    setShowPlotStyles(Adesk::Boolean showPlotStyles) const;
    AcDbPlotSettings::PlotRotation plotRotation() const;
    Adesk::Boolean          plotCentered() const;
    Adesk::Boolean          plotHidden() const;
    void                    setPlotHidden(Adesk::Boolean plotHidden) const;
    AcDbPlotSettings::ShadePlotType shadePlot() const;
    PyDbObjectId            shadePlotId() const;
    void                    setShadePlot2(AcDbPlotSettings::ShadePlotType type, const PyDbObjectId& shadePlotId) const;
    void                    setShadePlot1(AcDbPlotSettings::ShadePlotType shadePlot) const;
    AcDbPlotSettings::ShadePlotResLevel shadePlotResLevel() const;
    void                    setShadePlotResLevel(AcDbPlotSettings::ShadePlotResLevel resLevel) const;
    Adesk::Int16            shadePlotCustomDPI() const;
    void                    setShadePlotCustomDPI(Adesk::Int16 val) const;
    AcDbPlotSettings::PlotType plotType() const;
    boost::python::tuple    getPlotWindowArea() const;
    std::string             getPlotViewName() const;
    Adesk::Boolean          useStandardScale() const;
    boost::python::tuple    getCustomPrintScale() const;
    std::string             getCurrentStyleSheet() const;
    AcDbPlotSettings::StdScaleType  stdScaleType() const;
    double                  getStdScale() const;
    Adesk::Boolean          scaleLineweights() const;
    void                    setScaleLineweights(Adesk::Boolean scaleLineweights) const;
    Adesk::Boolean          printLineweights() const;
    void                    setPrintLineweights(Adesk::Boolean printLineweights) const;
    Adesk::Boolean          drawViewportsFirst() const;
    void                    setDrawViewportsFirst(Adesk::Boolean drawViewportsFirst) const;
    Adesk::Boolean          modelType() const;
    bool                    plotWireframe() const;
    bool                    plotAsRaster() const;

public:
    static std::string      className();
    static PyRxClass        desc();
    static PyDbPlotSettings cloneFrom(const PyRxObject& src);
    static PyDbPlotSettings cast(const PyRxObject& src);
public:
    AcDbPlotSettings* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbLayout
void makePyDbLayoutWrapper();

class PyDbLayout : public PyDbPlotSettings
{
public:
    PyDbLayout();
    PyDbLayout(AcDbLayout* ptr, bool autoDelete);
    PyDbLayout(const PyDbObjectId& id);
    PyDbLayout(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbLayout(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbLayout() override = default;

    PyDbObjectId            getBlockTableRecordId() const;
    void                    setBlockTableRecordId(PyDbObjectId& BlockTableRecordId) const;
    void                    addToLayoutDict(PyDbDatabase& towhichDb, PyDbObjectId BlockTableRecordId) const;
    std::string             getLayoutName() const;
    void                    setLayoutName(const std::string& layoutName) const;
    int                     getTabOrder() const;
    void                    setTabOrder(int newOrder) const;
    bool                    getTabSelected() const;
    void                    setTabSelected(Adesk::Boolean tabSelected) const;
    boost::python::list     getViewportArray() const;
    boost::python::tuple    getLimits() const;
    boost::python::tuple    getExtents() const;
    void                    initialize1() const;
    void                    initialize2(PyDbObjectId& paperVportId) const;
    bool                    annoAllVisible() const;
    void                    setAnnoAllVisible(bool newVal) const;

public:
    static std::string      className();
    static PyRxClass        desc();
    static PyDbLayout       cloneFrom(const PyRxObject& src);
    static PyDbLayout       cast(const PyRxObject& src);
public:
    AcDbLayout* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyDbLayoutManager
void makePyDbLayoutManagerWrapper();

class PyDbLayoutManager : public PyRxObject
{
public:
    PyDbLayoutManager();
    PyDbLayoutManager(AcDbLayoutManager* ptr, bool autoDelete);
    virtual ~PyDbLayoutManager() override = default;
    void                    setCurrentLayout1(const std::string& newname);
    void                    setCurrentLayout2(const std::string& newname, PyDbDatabase& pDb);
    void                    setCurrentLayoutId(const PyDbObjectId& layoutId);
    std::string             getActiveLayoutName1(bool allowModel);
    std::string             getActiveLayoutName2(bool allowModel, PyDbDatabase& pDb);
    PyDbObjectId            getActiveLayoutBTRId1();
    PyDbObjectId            getActiveLayoutBTRId2(const PyDbDatabase& pDb);
    PyDbObjectId            findLayoutNamed1(const std::string& name);
    PyDbObjectId            findLayoutNamed2(const std::string& name, const PyDbDatabase& pDb);
    bool                    layoutExists1(const std::string& name);
    bool                    layoutExists2(const std::string& name, const PyDbDatabase& pDb);
    void                    copyLayout1(const std::string& copyname, const std::string& newname);
    void                    copyLayout2(const std::string& copyname, const std::string& newname, const PyDbDatabase& pDb);
    void                    deleteLayout1(const std::string& delname);
    void                    deleteLayout2(const std::string& delname, PyDbDatabase& pDb);
    boost::python::tuple    createLayout1(const std::string& newname);
    boost::python::tuple    createLayout2(const std::string& newname, PyDbDatabase& pDb);
    void                    renameLayout1(const std::string& oldname, const std::string& newname);
    void                    renameLayout2(const std::string& oldname, const std::string& newname, PyDbDatabase& pDb);
    void                    cloneLayout1(PyDbLayout& pLBTR, const std::string& newname);
    void                    cloneLayout2(PyDbLayout& pLBTR, const std::string& newname, int newTabOrder, PyDbDatabase& pDb);
    PyDbObjectId            getNonRectVPIdFromClipId(PyDbObjectId& clipId);
    bool                    isVpnumClipped1(int index);
    bool                    isVpnumClipped2(int index, const PyDbDatabase& pDb);
    int                     countLayouts1();
    int                     countLayouts2(PyDbDatabase& pDb);

    boost::python::dict     getLayouts1();
    boost::python::dict     getLayouts2(PyDbDatabase& pDb);

    //TODO:
    //void              addReactor(AcDbLayoutManagerReactor* newObj);
    //void              removeReactor(AcDbLayoutManagerReactor* delObj)

    static Adesk::ULongPtr  setupForLayouts(PyDbDatabase& pDb);
    static void             clearSetupForLayouts(Adesk::ULongPtr contextHandle);
    static PyRxClass        desc();
    static std::string      className();
public:
    AcDbLayoutManager* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)