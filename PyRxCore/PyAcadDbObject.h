#pragma once

#include "PyAcAxCommon.h"

#pragma pack (push, 8)
class PyDbObjectId;
class PyIAcadObjectImpl;
class PyAcadDatabase;
class PyAcadDocument;
class PyAcadDictionary;
class PyIAcadBlockImpl;
class PyIAcadBlockImpl;
class PyIAcadModelSpaceImpl;
class PyIAcadPaperSpaceImpl;
class PyAcadBlock;
class PyAcadAcCmColor;
class PyIAcadPlotConfigurationImpl;
class PyIAcadLayoutImpl;
class PyIAcadSectionSettingsImpl;
class PyIAcadViewImpl;
class PyIAcadViewsImpl;
class PyIAcadGroupImpl;
class PyIAcadGroupsImpl;
class PyIAcadDimStyleImpl;
class PyIAcadDimStylesImpl;
class PyIAcadLayerImpl;
class PyIAcadLayersImpl;
class PyIAcadLineTypeImpl;
class PyIAcadLineTypesImpl;
class PyIAcadXRecordImpl;
class PyIAcadDictionaryImpl;
class PyIAcadDictionariesImpl;
class PyIAcadRegisteredApplicationImpl;
class PyIAcadRegisteredApplicationsImpl;
class PyIAcadTextStyleImpl;
class PyIAcadTextStylesImpl;
class PyIAcadUCSImpl;
class PyIAcadUCSsImpl;
class PyIAcadViewportImpl;
class PyIAcadViewportsImpl;
class PyIAcadPlotConfigurationsImpl;
class PyIAcadSectionManagerImpl;
class PyIAcadMaterialImpl;
class PyIAcadMaterialsImpl;
class PyIAcadTableStyleImpl;
class PyIAcadMLeaderStyleImpl;
class PyIAcadLayoutsImpl;
class PyIAcadSortentsTableImpl;
class PyAcadSectionTypeSettings;
class PyAcadEntity;
using PyAcadEntityArray = std::vector<PyAcadEntity>;


//----------------------------------------------------------------------------------------
//PyAcadObject
void makePyAcadObjectWrapper();

class PyAcadObject
{
public:
    PyAcadObject() = default;
    PyAcadObject(std::shared_ptr<PyIAcadObjectImpl> ptr);
    PyAcadObject(const AcDbObjectId& id);
    virtual ~PyAcadObject() = default;
    bool operator==(const PyAcadObject& rhs) const;
    bool operator!=(const PyAcadObject& rhs) const;
    std::size_t         hash() const;
    PyDbHandle          handle() const;
    std::string         objectName() const;
    PyDbObjectId        objectId() const;
    PyDbObjectId        ownerId() const;
    boost::python::list xdata(const std::string& appName) const;
    void                setXdata(const boost::python::list& pylist) const;
    void                clear() const;
    PyAcadDatabase      database() const;
    bool                hasExtensionDictionary() const;
    PyAcadDictionary    extensionDictionary() const;
    PyAcadDocument      document() const;
    void                erase() const;
    bool                isEqualTo(const PyAcadObject& other) const;
    bool                isNull() const;

    static PyAcadObject cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadObjectImpl* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<PyIAcadObjectImpl> m_pyImp;
};

template<typename T>
inline T PyAcadObjectCast(const PyAcadObject& src)
{
    T dest{};
    PyAcadObject tdbo = src;
    std::swap(tdbo.m_pyImp, dest.m_pyImp);
    return dest;
}

//----------------------------------------------------------------------------------------
//PyAcadPlotConfiguration
void makePyAcadPlotConfigurationWrapper();

class PyAcadPlotConfiguration : public PyAcadObject
{
public:
    PyAcadPlotConfiguration() = default;
    PyAcadPlotConfiguration(std::shared_ptr<PyIAcadPlotConfigurationImpl> ptr);
    virtual ~PyAcadPlotConfiguration() override = default;

    std::string             name() const;
    void                    setName(const std::string& val) const;
    std::string             configName() const;
    void                    setConfigName(const std::string& val) const;
    std::string             canonicalMediaName() const;
    void                    setCanonicalMediaName(const std::string& val) const;
    PyAcPlotPaperUnits      paperUnits() const;
    void                    setPaperUnits(PyAcPlotPaperUnits val) const;
    bool                    plotViewportBorders() const;
    void                    setPlotViewportBorders(bool val) const;
    bool                    showPlotStyles() const;
    void                    setShowPlotStyles(bool val) const;
    PyAcPlotRotation        plotRotation() const;
    void                    setPlotRotation(PyAcPlotRotation val) const;
    bool                    centerPlot() const;
    void                    setCenterPlot(bool val) const;
    bool                    plotHidden() const;
    void                    setPlotHidden(bool val) const;
    PyAcPlotType            plotType() const;
    void                    setPlotType(PyAcPlotType val) const;
    std::string             viewToPlot() const;
    void                    setViewToPlot(const std::string& val) const;
    bool                    useStandardScale() const;
    void                    setUseStandardScale(bool val) const;
    PyAcPlotScale           standardScale() const;
    void                    setStandardScale(PyAcPlotScale val) const;
    boost::python::tuple    customScale() const;
    void                    setCustomScale(double numerator, double denominator) const;
    bool                    scaleLineweights() const;
    void                    setScaleLineweights(bool val) const;
    bool                    plotWithLineweights() const;
    void                    setPlotWithLineweights(bool val) const;
    bool                    plotViewportsFirst() const;
    void                    setPlotViewportsFirst(bool val) const;
    std::string             styleSheet() const;
    void                    setStyleSheet(const std::string& val) const;
    boost::python::tuple    paperMargins() const;
    boost::python::tuple    paperSize() const;
    AcGePoint2d             plotOrigin() const;
    void                    setPlotOrigin(const AcGePoint2d& orgin) const;
    boost::python::tuple    windowToPlot() const;
    void                    setWindowToPlot(const AcGePoint2d& lowerLeft, const AcGePoint2d& upperRight) const;
    bool                    plotWithPlotStyles() const;
    void                    setPlotWithPlotStyles(bool val) const;
    bool                    modelType() const;
    void                    copyFrom(const PyAcadPlotConfiguration& val) const;
    boost::python::list     canonicalMediaNames() const;
    boost::python::list     plotDeviceNames() const;
    boost::python::list     plotStyleTableNames() const;
    void                    refreshPlotDeviceInfo() const;
    std::string             localeMediaName(const std::string& name) const;

    static PyAcadPlotConfiguration cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPlotConfigurationImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadLayout
void makePyAcadLayoutWrapper();

class PyAcadLayout : public PyAcadPlotConfiguration
{
public:
    PyAcadLayout() = default;
    PyAcadLayout(std::shared_ptr<PyIAcadLayoutImpl> ptr);
    virtual ~PyAcadLayout() override = default;

    PyAcadBlock     block() const;
    long            tabOrder() const;
    void            setTabOrder(long val) const;

    static PyAcadLayout cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLayoutImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadSectionSettings
void makePyAcadSectionSettingsWrapper();

class PyAcadSectionSettings : public PyAcadObject
{
public:
    PyAcadSectionSettings() = default;
    PyAcadSectionSettings(std::shared_ptr<PyIAcadSectionSettingsImpl> ptr);
    virtual ~PyAcadSectionSettings() override = default;

    PyAcSectionType             currentSectionType() const;
    void                        setCurrentSectionType(PyAcSectionType val) const;
    PyAcadSectionTypeSettings   sectionTypeSettings(PyAcSectionType secType) const;

    static PyAcadSectionSettings cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadSectionSettingsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadView
void makePyAcadViewWrapper();

class PyAcadView : public PyAcadObject
{
public:
    PyAcadView() = default;
    PyAcadView(std::shared_ptr<PyIAcadViewImpl> ptr);
    virtual ~PyAcadView() override = default;

    AcGePoint3d     center() const;
    void            setCenter(const AcGePoint3d& val) const;
    double          height() const;
    void            setHeight(double val) const;
    double          width() const;
    void            setWidth(double val) const;
    AcGePoint3d     target() const;
    void            setTarget(const AcGePoint3d& val) const;
    AcGeVector3d    direction() const;
    void            setDirection(const AcGeVector3d& val) const;
    std::string     name() const;
    void            setName(const std::string& val) const;
    std::string     categoryName() const;
    void            setCategoryName(const std::string& val) const;
    PyDbObjectId    layoutId() const;
    void            setLayoutId(const PyDbObjectId& val) const;
    std::string     layerState() const;
    void            setLayerState(const std::string& val) const;
    bool            hasVpAssociation() const;
    void            setHasVpAssociation(bool val) const;

    static PyAcadView cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadViewImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadViews
void makePyAcadViewsWrapper();

class PyAcadViews : public PyAcadObject
{
public:
    PyAcadViews() = default;
    PyAcadViews(std::shared_ptr<PyIAcadViewsImpl> ptr);
    virtual ~PyAcadViews() override = default;
    long                count() const;
    PyAcadView          item(long index) const;
    PyAcadView          add(const std::string& name) const;
    boost::python::list items() const;
    static PyAcadViews  cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadViewsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadView>::iterator begin();
    std::vector<PyAcadView>::iterator end();
    std::vector<PyAcadView> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadDimStyle
void makePyAcadDimStyleWrapper();

class PyAcadDimStyle : public PyAcadObject
{
public:
    PyAcadDimStyle() = default;
    PyAcadDimStyle(std::shared_ptr<PyIAcadDimStyleImpl> ptr);
    virtual ~PyAcadDimStyle() override = default;
    std::string     name() const;
    void            setName(const std::string& val) const;
    void            copyFrom(const PyAcadObject& other) const;
    static PyAcadDimStyle cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimStyleImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimStyles
void makePyAcadDimStylesWrapper();

class PyAcadDimStyles : public PyAcadObject
{
public:
    PyAcadDimStyles() = default;
    PyAcadDimStyles(std::shared_ptr<PyIAcadDimStylesImpl> ptr);
    virtual ~PyAcadDimStyles() override = default;
    long                count() const;
    PyAcadDimStyle      item(long index) const;
    PyAcadDimStyle      add(const std::string& name) const;
    boost::python::list items() const;
    static PyAcadDimStyles cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimStylesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadDimStyle>::iterator begin();
    std::vector<PyAcadDimStyle>::iterator end();
    std::vector<PyAcadDimStyle> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadLayer
void makePyAcadLayerWrapper();

class PyAcadLayer : public PyAcadObject
{
public:
    PyAcadLayer() = default;
    PyAcadLayer(std::shared_ptr<PyIAcadLayerImpl> ptr);
    virtual ~PyAcadLayer() override = default;

    PyAcColor           color() const;
    void                setColor(PyAcColor val) const;
    PyAcadAcCmColor     trueColor() const;
    void                setTrueColor(const PyAcadAcCmColor& val) const;
    bool                freeze() const;
    void                setFreeze(bool val) const;
    bool                layerOn() const;
    void                setLayerOn(bool val) const;
    std::string         linetype() const;
    void                setLinetype(const std::string& val) const;
    bool                lock() const;
    void                setLock(bool val) const;
    std::string         name() const;
    void                setName(const std::string& val) const;
    bool                plottable() const;
    void                setPlottable(bool val) const;
    bool                viewportDefault() const;
    void                setViewportDefault(bool val) const;
    std::string         plotStyleName() const;
    void                setPlotStyleName(const std::string& val) const;
    PyAcLineWeight      lineweight() const;
    void                setLineWeight(PyAcLineWeight val) const;
    std::string         description() const;
    void                setDescription(const std::string& val) const;
    bool                used() const;
    std::string         material() const;
    void                setMaterial(const std::string& val) const;

    static PyAcadLayer cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLayerImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadLayers
void makePyAcadLayersWrapper();

class PyAcadLayers : public PyAcadObject
{
public:
    PyAcadLayers() = default;
    PyAcadLayers(std::shared_ptr<PyIAcadLayersImpl> ptr);
    virtual ~PyAcadLayers() override = default;
    long                count() const;
    PyAcadLayer         item(long index) const;
    PyAcadLayer         add(const std::string& name) const;
    boost::python::list items() const;
    static PyAcadLayers cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLayersImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadLayer>::iterator begin();
    std::vector<PyAcadLayer>::iterator end();
    std::vector<PyAcadLayer> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadLineType
void makePyAcadLineTypeWrapper();

class PyAcadLineType : public PyAcadObject
{
public:
    PyAcadLineType() = default;
    PyAcadLineType(std::shared_ptr<PyIAcadLineTypeImpl> ptr);
    virtual ~PyAcadLineType() override = default;
    std::string         name() const;
    void                setName(const std::string& val) const;
    std::string         description() const;
    void                setDescription(const std::string& val) const;
    static PyAcadLineType cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLineTypeImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadLineTypes
void makePyAcadLineTypesWrapper();

class PyAcadLineTypes : public PyAcadObject
{
public:
    PyAcadLineTypes() = default;
    PyAcadLineTypes(std::shared_ptr<PyIAcadLineTypesImpl> ptr);
    virtual ~PyAcadLineTypes() override = default;
    long                count() const;
    PyAcadLineType      item(long index) const;
    PyAcadLineType      add(const std::string& name) const;
    boost::python::list items() const;
    static PyAcadLineTypes cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLineTypesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadLineType>::iterator begin();
    std::vector<PyAcadLineType>::iterator end();
    std::vector<PyAcadLineType> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadXRecord
void makePyAcadXRecordWrapper();

class PyAcadXRecord : public PyAcadObject
{
public:
    PyAcadXRecord() = default;
    PyAcadXRecord(std::shared_ptr<PyIAcadXRecordImpl> ptr);
    virtual ~PyAcadXRecord() override = default;
    static PyAcadXRecord cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadXRecordImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDictionary
void makePyAcadDictionaryWrapper();

class PyAcadDictionary : public PyAcadObject
{
public:
    PyAcadDictionary() = default;
    PyAcadDictionary(std::shared_ptr<PyIAcadDictionaryImpl> ptr);
    virtual ~PyAcadDictionary() override = default;
    static PyAcadDictionary cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDictionaryImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDictionaries
void makePyAcadDictionariesWrapper();

class PyAcadDictionaries : public PyAcadObject
{
public:
    PyAcadDictionaries() = default;
    PyAcadDictionaries(std::shared_ptr<PyIAcadDictionariesImpl> ptr);
    virtual ~PyAcadDictionaries() override = default;
    long                count() const;
    PyAcadDictionary    item(long index) const;
    PyAcadDictionary    add(const std::string& name) const;
    boost::python::list items() const;
    static PyAcadDictionaries cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDictionariesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadDictionary>::iterator begin();
    std::vector<PyAcadDictionary>::iterator end();
    std::vector<PyAcadDictionary> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadRegisteredApplication
void makePyAcadRegisteredApplicationWrapper();

class PyAcadRegisteredApplication : public PyAcadObject
{
public:
    PyAcadRegisteredApplication() = default;
    PyAcadRegisteredApplication(std::shared_ptr<PyIAcadRegisteredApplicationImpl> ptr);
    virtual ~PyAcadRegisteredApplication() override = default;
    std::string             name() const;
    void                    setName(const std::string& val) const;
    static PyAcadRegisteredApplication cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadRegisteredApplicationImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadRegisteredApplications
void makePyAcadRegisteredApplicationsWrapper();

class PyAcadRegisteredApplications : public PyAcadObject
{
public:
    PyAcadRegisteredApplications() = default;
    PyAcadRegisteredApplications(std::shared_ptr<PyIAcadRegisteredApplicationsImpl> ptr);
    virtual ~PyAcadRegisteredApplications() override = default;
    long                        count() const;
    PyAcadRegisteredApplication item(long index) const;
    PyAcadRegisteredApplication add(const std::string& name) const;
    boost::python::list         items() const;
    static PyAcadRegisteredApplications cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadRegisteredApplicationsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadRegisteredApplication>::iterator begin();
    std::vector<PyAcadRegisteredApplication>::iterator end();
    std::vector<PyAcadRegisteredApplication> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadTextStyle
void makePyAcadTextStyleWrapper();

class PyAcadTextStyle : public PyAcadObject
{
public:
    PyAcadTextStyle() = default;
    PyAcadTextStyle(std::shared_ptr<PyIAcadTextStyleImpl> ptr);
    virtual ~PyAcadTextStyle() override = default;

    std::string             bigFontFile() const;
    void                    setBigFontFile(const std::string& val) const;
    std::string             fontFile() const;
    void                    setFontFile(const std::string& val) const;
    double                  height() const;
    void                    setHeight(double val) const;
    double                  lastHeight() const;
    void                    setLastHeight(double val) const;
    std::string             name() const;
    double                  obliqueAngle() const;
    void                    setObliqueAngle(double val) const;
    long                    textGenerationFlag() const;
    void                    setTextGenerationFlag(long val) const;
    double                  width() const;
    void                    setWidth(double val) const;
    boost::python::tuple    font() const;
    void                    setFont(const std::string& typeFace, bool bold, bool italic, long charset, long pitchAndFamily) const;

    static PyAcadTextStyle cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadTextStyleImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadTextStyles
void makePyAcadTextStylesWrapper();

class PyAcadTextStyles : public PyAcadObject
{
public:
    PyAcadTextStyles() = default;
    PyAcadTextStyles(std::shared_ptr<PyIAcadTextStylesImpl> ptr);
    virtual ~PyAcadTextStyles() override = default;
    long                count() const;
    PyAcadTextStyle     item(long index) const;
    PyAcadTextStyle     add(const std::string& name) const;
    boost::python::list items() const;
    static PyAcadTextStyles cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadTextStylesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadTextStyle>::iterator begin();
    std::vector<PyAcadTextStyle>::iterator end();
    std::vector<PyAcadTextStyle> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadUCS
void makePyAcadUCSWrapper();

class PyAcadUCS : public PyAcadObject
{
public:
    PyAcadUCS() = default;
    PyAcadUCS(std::shared_ptr<PyIAcadUCSImpl> ptr);
    virtual ~PyAcadUCS() override = default;
    static PyAcadUCS cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadUCSImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadUCSs
void makePyAcadUCSsWrapper();

class PyAcadUCSs : public PyAcadObject
{
public:
    PyAcadUCSs() = default;
    PyAcadUCSs(std::shared_ptr<PyIAcadUCSsImpl> ptr);
    virtual ~PyAcadUCSs() override = default;
    long                count() const;
    PyAcadUCS           item(long index) const;
    PyAcadUCS           add(const AcGePoint3d& origin, const AcGeVector3d& xDir, const AcGeVector3d& yDir, const std::string& name) const;
    boost::python::list items() const;
    static PyAcadUCSs   cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadUCSsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadUCS>::iterator begin();
    std::vector<PyAcadUCS>::iterator end();
    std::vector<PyAcadUCS> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadViewport
void makePyAcadViewportWrapper();

class PyAcadViewport : public PyAcadObject
{
public:
    PyAcadViewport() = default;
    PyAcadViewport(std::shared_ptr<PyIAcadViewportImpl> ptr);
    virtual ~PyAcadViewport() override = default;
    static PyAcadViewport cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadViewportImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadViewports
void makePyAcadViewportsWrapper();

class PyAcadViewports : public PyAcadObject
{
public:
    PyAcadViewports() = default;
    PyAcadViewports(std::shared_ptr<PyIAcadViewportsImpl> ptr);
    virtual ~PyAcadViewports() override = default;
    long                count() const;
    PyAcadViewport      item(long index) const;
    PyAcadViewport      add(const std::string& name) const;
    boost::python::list items() const;
    static PyAcadViewports cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadViewportsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadViewport>::iterator begin();
    std::vector<PyAcadViewport>::iterator end();
    std::vector<PyAcadViewport> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadPlotConfigurations
void makePyAcadPlotConfigurationsWrapper();

class PyAcadPlotConfigurations : public PyAcadObject
{
public:
    PyAcadPlotConfigurations() = default;
    PyAcadPlotConfigurations(std::shared_ptr<PyIAcadPlotConfigurationsImpl> ptr);
    virtual ~PyAcadPlotConfigurations() override = default;
    long                    count() const;
    PyAcadPlotConfiguration item(long index) const;
    PyAcadPlotConfiguration add(const std::string& name) const;
    boost::python::list     items() const;
    static PyAcadPlotConfigurations cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPlotConfigurationsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadPlotConfiguration>::iterator begin();
    std::vector<PyAcadPlotConfiguration>::iterator end();
    std::vector<PyAcadPlotConfiguration> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadSectionManager
void makePyAcadSectionManagerWrapper();

class PyAcadSectionManager : public PyAcadObject
{
public:
    PyAcadSectionManager() = default;
    PyAcadSectionManager(std::shared_ptr<PyIAcadSectionManagerImpl> ptr);
    virtual ~PyAcadSectionManager() override = default;
    static PyAcadSectionManager cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadSectionManagerImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadMaterial
void makePyAcadMaterialWrapper();

class PyAcadMaterial : public PyAcadObject
{
public:
    PyAcadMaterial() = default;
    PyAcadMaterial(std::shared_ptr<PyIAcadMaterialImpl> ptr);
    virtual ~PyAcadMaterial() override = default;
    static PyAcadMaterial cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadMaterialImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadMaterials
void makePyAcadMaterialsWrapper();

class PyAcadMaterials : public PyAcadObject
{
public:
    PyAcadMaterials() = default;
    PyAcadMaterials(std::shared_ptr<PyIAcadMaterialsImpl> ptr);
    virtual ~PyAcadMaterials() override = default;
    long                count() const;
    PyAcadMaterial      item(long index) const;
    PyAcadMaterial      add(const std::string& name) const;
    boost::python::list items() const;
    static PyAcadMaterials cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadMaterialsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadMaterial>::iterator begin();
    std::vector<PyAcadMaterial>::iterator end();
    std::vector<PyAcadMaterial> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadTableStyle
void makePyAcadTableStyleWrapper();

class PyAcadTableStyle : public PyAcadObject
{
public:
    PyAcadTableStyle() = default;
    PyAcadTableStyle(std::shared_ptr<PyIAcadTableStyleImpl> ptr);
    virtual ~PyAcadTableStyle() override = default;
    static PyAcadTableStyle cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadTableStyleImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadMLeaderStyle
void makePyAcadMLeaderStyleWrapper();

class PyAcadMLeaderStyle : public PyAcadObject
{
public:
    PyAcadMLeaderStyle() = default;
    PyAcadMLeaderStyle(std::shared_ptr<PyIAcadMLeaderStyleImpl> ptr);
    virtual ~PyAcadMLeaderStyle() override = default;
    static PyAcadMLeaderStyle cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadMLeaderStyleImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadLayouts
void makePyAcadLayoutsWrapper();

class PyAcadLayouts : public PyAcadObject
{
public:
    PyAcadLayouts() = default;
    PyAcadLayouts(std::shared_ptr<PyIAcadLayoutsImpl> ptr);
    virtual ~PyAcadLayouts() override = default;
    long                count() const;
    PyAcadLayout        item(long index) const;
    PyAcadLayout        add(const std::string& name);
    boost::python::list items() const;
    static PyAcadLayouts cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLayoutsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadLayout>::iterator begin();
    std::vector<PyAcadLayout>::iterator end();
    std::vector<PyAcadLayout> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadSortentsTable
void makePyAcadSortentsTableWrapper();

class PyAcadSortentsTable : public PyAcadObject
{
public:
    PyAcadSortentsTable() = default;
    PyAcadSortentsTable(std::shared_ptr<PyIAcadSortentsTableImpl> ptr);
    virtual ~PyAcadSortentsTable() override = default;
    static PyAcadSortentsTable cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadSortentsTableImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};


#pragma pack (pop)
