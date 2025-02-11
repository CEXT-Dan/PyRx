#pragma once

#pragma pack (push, 8)
class PyDbObjectId;
class PyIAcadObjectImpl;
class PyAcadDatabase;
class PyAcadDocument;
class PyAcadDictionary;
class PyIAcadBlockImpl;
class PyAcadEntity;
class PyIAcadBlockImpl;
class PyIAcadModelSpaceImpl;
class PyIAcadPaperSpaceImpl;

class PyIAcadPlotConfigurationImpl;
class PyIAcadLayoutImpl;
class PyIAcadSectionSettingsImpl;
class PyIAcadViewImpl;
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
    boost::python::list getXData(const std::string& appName);
    void                setXdata(const boost::python::list& pylist);
    void                clear();
    PyAcadDatabase      database() const;
    bool                hasExtensionDictionary() const;
    //PyAcadDictionary    extensionDictionary() const;
    PyAcadDocument      document() const;
    void                erase();
    bool                isEqualTo(const PyAcadObject& other);
    bool                isNull();

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
    T dest;
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
    static PyAcadPlotConfiguration cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPlotConfigurationImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadLayout
void makePyAcadLayoutWrapper();

class PyAcadLayout : public PyAcadObject
{
public:
    PyAcadLayout() = default;
    PyAcadLayout(std::shared_ptr<PyIAcadLayoutImpl> ptr);
    virtual ~PyAcadLayout() override = default;
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
    static PyAcadView cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadViewImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadGroup
void makePyAcadGroupWrapper();

class PyAcadGroup : public PyAcadObject
{
public:
    PyAcadGroup() = default;
    PyAcadGroup(std::shared_ptr<PyIAcadGroupImpl> ptr);
    virtual ~PyAcadGroup() override = default;
    static PyAcadGroup cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadGroupImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadGroups
void makePyAcadGroupsWrapper();

class PyAcadGroups : public PyAcadObject
{
public:
    PyAcadGroups() = default;
    PyAcadGroups(std::shared_ptr<PyIAcadGroupsImpl> ptr);
    virtual ~PyAcadGroups() override = default;
    static PyAcadGroups cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadGroupsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadDimStyles cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimStylesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadLayers cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLayersImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadLineTypes cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLineTypesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadDictionaries cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDictionariesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadRegisteredApplications cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadRegisteredApplicationsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadTextStyles cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadTextStylesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadUCSs cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadUCSsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadViewports cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadViewportsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadPlotConfigurations cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPlotConfigurationsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadMaterials cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadMaterialsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadLayouts cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLayoutsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
