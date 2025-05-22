#pragma once
#ifdef BRXAPP

class PyIfcModel;
class PyIfcEntity;
class PyDbEntity;
class PyDbDatabase;
class PyDbObjectId;
class PyApDocument;
class PyDb3dSolid;

#include "IfcImportReactor.h"
#include "IfcExportReactor.h"

//---------------------------------------------------------------------------------------- -
//PyBrxIfcImportOptions
void makePyBrxIfcImportOptionsWrapper();

class PyBrxIfcImportOptions
{
public:
    PyBrxIfcImportOptions();
    PyBrxIfcImportOptions(const BimApi::BrxIfcImportOptions* pObject);
    PyBrxIfcImportOptions(BimApi::BrxIfcImportOptions* pObject, bool autoDelete);
    virtual ~PyBrxIfcImportOptions() = default;
    bool importBimData() const;
    void setImportBimData(bool bOn) const;
    bool importIfcSpace() const;
    void setImportIfcSpace(bool bOn) const;
    bool importParametricComponents() const;
    void setImportParametricComponents(bool bOn) const;
    bool importIfcProjectStructureAsXrefs() const;
    void setImportIfcProjectStructureAsXrefs(bool bOn) const;
    bool importBrepGeometryAsMeshes() const;
    void setImportBrepGeometryAsMeshes(bool bOn) const;
    BimApi::EIfcImportModelOrigin importModelOrigin() const;
    void setImportModelOrigin(BimApi::EIfcImportModelOrigin mode) const;
    static void importIfcFile1(PyDbDatabase& pDb, const std::string szFilename);
    static void importIfcFile2(PyDbDatabase& pDb, const std::string szFilename, const PyBrxIfcImportOptions& pOptions);
    static std::string   className();
public:
    BimApi::BrxIfcImportOptions* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr< BimApi::BrxIfcImportOptions> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBrxBimIfcImportInfo
void makePyBrxBimIfcImportInfoWrapper();

class PyBrxBimIfcImportInfo
{
public:
    PyBrxBimIfcImportInfo();
    PyBrxBimIfcImportInfo(BrxIfcTranslatorOptions* opts, Ice::IfcApi::Header* header);
    PyBrxBimIfcImportInfo(const BimIfcImportInfo* pObject);
    PyBrxBimIfcImportInfo(BimIfcImportInfo* pObject, bool autoDelete);
    virtual ~PyBrxBimIfcImportInfo() = default;
    std::string fileName() const;
    std::string timeStamp() const;
    std::string author() const;
    std::string organization() const;
    std::string preprocessorVersion() const;
    std::string originatingSystem() const;
    std::string authorization() const;
    bool importBimData() const;
    bool importIfcSpace() const;
    bool importParametricComponents() const;
    bool importIfcProjectStructureAsXrefs() const;
    bool importBrepGeometryAsMeshes() const;
    static std::string   className();
public:
    BimIfcImportInfo* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BimIfcImportInfo> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//BrxBimIfcImportContext
void makePyBrxBimIfcImportContextWrapper();

using IfcImportContext = BimIfcImportReactorInstance::Context;

class PyBrxBimIfcImportContext
{
public:
    PyBrxBimIfcImportContext(const IfcImportContext* pObject);
    PyBrxBimIfcImportContext(IfcImportContext* pObject, bool autoDelete);
    virtual ~PyBrxBimIfcImportContext() = default;

    PyIfcModel          ifcModel() const;
    PyDbDatabase        database() const;
    PyDbEntity          createDefaultRepresentation(const PyIfcEntity& entity, bool isParent, const PyIfcEntity& parent) const;
    PyDbEntity          createRepresentationFromItem(const PyIfcEntity& entity) const;
    AcGePoint3d         createPoint(const PyIfcEntity& point) const;
    AcGeMatrix3d        getLocalPlacement(const PyIfcEntity& point) const;
    boost::python::list createSweptArea(const PyIfcEntity& sweptArea) const;
    PyDbEntity          getEntity(const PyIfcEntity& IfcEntity);
    PyDbObjectId        getEntityId(const PyIfcEntity& IfcEntity);
    double              angleConversionFactor() const;
    double              areaConversionFactor() const;
    double              lengthConversionFactor() const;
    double              volumeConversionFactor() const;
    double              precision() const;
    static std::string  className();
public:
    IfcImportContext* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<IfcImportContext> m_pyImp;
};


//---------------------------------------------------------------------------------------- -
//PyBimIfcImportReactorImpl
class PyBimIfcImportReactor;

class PyBimIfcImportReactorImpl : public BimIfcImportReactorInstance, public BimIfcImportReactor
{
public:
    PyBimIfcImportReactorImpl(PyBimIfcImportReactor* ptr, const AcString& displayName, const AcString& guid);

    virtual ~PyBimIfcImportReactorImpl() override = default;

    virtual void onStart(
        BimIfcImportReactorInstance::Context& context,
        const Ice::IfcApi::Entity& project,
        const BimIfcImportInfo& info
    ) override;

    virtual bool onIfcProduct(
        BimIfcImportReactorInstance::Context& context,
        const Ice::IfcApi::Entity& entity,
        bool isParent,
        const Ice::IfcApi::Entity& parentEntity
    ) override;

    virtual void beforeCompletion(
        BimIfcImportReactorInstance::Context& context,
        bool success
    ) override;

    virtual void onIfcProductImported(
        const Ice::IfcApi::Entity& sourceEntity,
        bool isParent,
        const Ice::IfcApi::Entity& sourceParentEntity,
        AcDbEntityPtrArray& createdAcEntites,
        const AcGeMatrix3d* constructedAcEntityTransformation
    ) override;

    virtual BimIfcImportReactorInstance* getIfcReactorInstance(Ice::EIfcSchemaId schema) override;
    virtual const ACHAR* GUID() const override;
    virtual const ACHAR* displayName() const override;

    PyBimIfcImportReactor* impObj(const std::source_location& src = std::source_location::current()) const;

    PyBimIfcImportReactor* m_pyBackPtr = nullptr;

public:
    PyBimIfcImportReactorImpl* m_instance = nullptr;
    AcString m_guid;
    AcString m_displayName;
};

//---------------------------------------------------------------------------------------- -
//BimIfcImportReactor
void makePyBimIfcImportReactorWrapper();

class PyBimIfcImportReactor : public boost::python::wrapper<PyBimIfcImportReactor>
{
public:
    PyBimIfcImportReactor(const std::string& displayName, const std::string& GUID);
    PyBimIfcImportReactor(const PyBimIfcImportReactorImpl* pObject);
    PyBimIfcImportReactor(PyBimIfcImportReactorImpl* pObject, bool autoDelete);
    virtual ~PyBimIfcImportReactor() = default;

    virtual void onStart(PyBrxBimIfcImportContext& context, const PyIfcEntity& project, const PyBrxBimIfcImportInfo& info);
    virtual bool onIfcProduct(PyBrxBimIfcImportContext& context, const PyIfcEntity& entity, bool isParent, const PyIfcEntity& parentEntity);
    virtual void beforeCompletion(PyBrxBimIfcImportContext& context, bool success);
    virtual void onIfcProductImported(const PyIfcEntity& sourceEntity, bool isParent, const PyIfcEntity& sourceParentEntity, boost::python::list& createdAcEntites, const AcGeMatrix3d& xfrom);

    bool         attachReactor() const;
    bool         detachReactor() const;

    static std::string  className();
public:
    PyBimIfcImportReactorImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyBimIfcImportReactorImpl> m_pyImp;

public:
    bool reg_onStart = true;
    bool reg_onIfcProduct = true;
    bool reg_beforeCompletion = true;
    bool reg_onIfcProductImported = true;
};


//---------------------------------------------------------------------------------------- -
//PyBimIfcProjectData
void makePyBimIfcProjectDataWrapper();

class PyBimIfcProjectData
{
public:
    PyBimIfcProjectData() = default;
    ~PyBimIfcProjectData() = default;
    std::string getProjectName() const;
    void        setProjectName(const std::string& val);
    std::string getProjectDescription() const;
    void        setProjectDescription(const std::string& val);
    std::string getProjectPhase() const;
    void        setProjectPhase(const std::string& val);
    double      getProjectNorthAngle() const;
    void        setProjectNorthAngle(double val);
    std::string getAuthorGivenName() const;
    void        setAuthorGivenName(const std::string& val);
    std::string getAuthorFamilyName() const;
    void        setAuthorFamilyName(const std::string& val);
    std::string getAuthorOrganization() const;
    void        setAuthorOrganization(const std::string& val);
    std::string getApplicationFullName() const;
    void        setApplicationFullName(const std::string& val);
    std::string getApplicationIdentifier() const;
    void        setApplicationIdentifier(const std::string& val);
    std::string getApplicationVersion() const;
    void        setApplicationVersion(const std::string& val);
    std::string getSiteName() const;
    void        setSiteName(const std::string& val);
    std::string getSiteDescription() const;
    void        setSiteDescription(const std::string& val);
    double      getSiteLatitude() const;
    void        setSiteLatitude(double val);
    double      getSiteLongitude() const;
    void        setSitelongitude(double val);
    double      getSiteElevation() const;
    void        setSiteElevation(double val);
    std::string getSiteLandTitleNumber() const;
    void        setSiteLandTitleNumber(const std::string& val);
    std::string getSiteInternalLocation() const;
    void        setSiteInternalLocation(const std::string& val);
    std::string getSitePostalBox() const;
    void        setSitePostalBox(const std::string& val);
    std::string getSiteTown() const;
    void        setSiteTown(const std::string& val);
    std::string getSiteRegion() const;
    void        setSiteRegion(const std::string& val);
    std::string getSitePostalCode() const;
    void        setSitePostalCode(const std::string& val);
    std::string getSiteCountry() const;
    void        setSiteCountry(const std::string& val);
    std::string getSiteAddressLines() const;
    void        setSiteAddressLines(const std::string& val);
    double      getSiteBuildableArea() const;
    void        setSiteBuildableArea(double val);
    double      getSiteTotalArea() const;
    void        setSiteTotalArea(double val);
    double      getSiteBuildingHeightLimit() const;
    void        setSiteBuildingHeightLimit(double val);
    static std::string  className();

public:
    BimApi::BimIfcProjectData impl;
};

//---------------------------------------------------------------------------------------- -
//BrxBimIfcExportContext
void makePyBrxBimIfcExportContextWrapper();

using IfcExportContext = BimIfcExportReactorInstance::Context;

class PyBrxBimIfcExportContext
{
public:
    PyBrxBimIfcExportContext(const IfcExportContext* pObject);
    PyBrxBimIfcExportContext(IfcExportContext* pObject, bool autoDelete);
    virtual ~PyBrxBimIfcExportContext() = default;

    PyIfcModel      ifcModel() const;
    PyDbDatabase    database() const;
    PyIfcEntity     getProduct1(const PyDbObjectId& id) const;
    PyIfcEntity     getProduct2(const PyDbFullSubentPath& idSubent) const;

    bool            setIfcRootData1(const PyIfcEntity& ifcObject) const;
    bool            setIfcRootData2(const PyIfcEntity& ifcObject, const std::string& name, const std::string& description, const std::string& guid, const PyIfcEntity& pHist) const;
    bool            setLocationRelToWCS(const PyIfcEntity& ifcProduct, const AcGeMatrix3d& relativeCoordSys) const;
    bool            setLocationRelToAssignedSpatialLocation(const PyIfcEntity& ifcElement, const PyDbEntity& correspondingEntity, const AcGeMatrix3d& relativeCoordSys) const;
    bool            setLocationRelToBuilding(const PyIfcEntity& ifcElement, const std::string& buildingName,const AcGeMatrix3d& relativeCoordSys) const;
    bool            setLocationRelToStory(const PyIfcEntity& ifcElement, const std::string& buildingName, const std::string& storyName, const AcGeMatrix3d& relativeCoordSys) const;
    bool            setRepresentationAsExtrudedAreaSolid(const PyIfcEntity& ifcProduct, const PyDb3dSolid& correspondingSolid, const AcGeVector3d& preferredSweepingDirections) const;
    bool            setRepresentationAsClippedExtrudedAreaSolid(const PyIfcEntity& ifcProduct, const PyDb3dSolid& correspondingSolid, const AcGeVector3d& extrusionDirection) const;
    bool            setRepresentationAsBrep(PyIfcEntity& ifcProduct, const PyDbEntity& correspondingEntity) const;
    bool            setMaterialToAssignedComposition(const PyIfcEntity& ifcObject, const PyDbEntity& correspondingEntity, double thicknessVariableLayer) const;
    bool            setMaterialToComposition(const PyIfcEntity& ifcObject, const std::string& compositionName, double thicknessVariableLayer) const;

    PyIfcEntity     getAxis2Placement2D(const AcGeMatrix2d& coordSystem) const;
    PyIfcEntity     getAxis2Placement3D(const AcGeMatrix3d& coordSystem) const;
    PyIfcEntity     getCartesianPoint2D(const AcGePoint2d& pt) const;
    PyIfcEntity     getCartesianPoint3D(const AcGePoint3d& pt) const;
    PyIfcEntity     getDirection2D(const AcGeVector2d& vec) const;
    PyIfcEntity     getDirection3D(const AcGeVector3d& vec) const;

    static std::string  className();
public:
    IfcExportContext* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<IfcExportContext> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBrxIfcExportOptions
void makePyBrxIfcExportOptionsWrapper();

class PyBrxIfcExportOptions
{
public:
    PyBrxIfcExportOptions();
    PyBrxIfcExportOptions(const BimApi::BrxIfcExportOptions& other);
    ~PyBrxIfcExportOptions() = default;

#if defined(_BRXTARGET) && (_BRXTARGET >= 250)
    Adesk::UInt32       optionFlags() const;
    void                setOptionFlags(Adesk::UInt32 options) const;
#endif

#if defined(_BRXTARGET) && (_BRXTARGET >= 250)
    bool                option(BimApi::BrxIfcExportOptions::EOptionFlags option) const;
    void                setOption(BimApi::BrxIfcExportOptions::EOptionFlags option, bool value) const;
#endif
    boost::python::list objectsToExport() const;
    void                setObjectsToExport(const  boost::python::list& arObjectsForExport) const;
    boost::python::list nestedObjectsToExport() const;
    void                setNestedObjectsToExport(const boost::python::list& arObjectsForExport) const;
    Ice::EIfcSchemaId   ifcVersion() const;
    void                setIfcVersion(Ice::EIfcSchemaId eSchemaId) const;
    BimApi::BrxIfcExportOptions::EModelViewDefType mvdType() const;
    void                setMvdType(BimApi::BrxIfcExportOptions::EModelViewDefType eType) const;

    static void         exportIfcFile1(const PyApDocument& pDoc, const std::string& filename);
    static void         exportIfcFile2(const PyApDocument& pDoc, const std::string& filename, const PyBrxIfcExportOptions& pOptions);

    static std::string  className();
public:
    BimApi::BrxIfcExportOptions* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BimApi::BrxIfcExportOptions> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyBimIfcExportReactorImpl
class PyBimIfcExportReactor;

class PyBimIfcExportReactorImpl : public BimIfcExportReactorInstance, public BimIfcExportReactor
{
public:
    PyBimIfcExportReactorImpl(PyBimIfcExportReactor* ptr, const AcString& displayName, const AcString& guid);
    virtual ~PyBimIfcExportReactorImpl() override = default;

    virtual void onBeginIfcModelSetup(Context& context) override;
    virtual Ice::IfcApi::Entity onEntity(Context& context, AcDbEntity* pEntity) override;
    virtual void onEndIfcModelSetup(Context& context) override;
    virtual void onEntityConstructed(Ice::IfcApi::Entity& contructedEntity, AcDbEntity* pSourceBCEntity) override;

    virtual BimIfcExportReactorInstance* getIfcReactorInstance(Ice::EIfcSchemaId schema) override;
    virtual const ACHAR* GUID() const override;
    virtual const ACHAR* displayName() const override;

    PyBimIfcExportReactor* impObj(const std::source_location& src = std::source_location::current()) const;

    PyBimIfcExportReactor* m_pyBackPtr = nullptr;
public:
    PyBimIfcExportReactorImpl* m_instance = nullptr;
    AcString m_guid;
    AcString m_displayName;
};

//---------------------------------------------------------------------------------------- -
//BimIfcExportReactor
void makePyBimIfcExportReactorWrapper();

class PyBimIfcExportReactor : public boost::python::wrapper<PyBimIfcExportReactor>
{
public:
    PyBimIfcExportReactor(const std::string& displayName, const std::string& GUID);
    PyBimIfcExportReactor(const PyBimIfcExportReactorImpl* pObject);
    PyBimIfcExportReactor(PyBimIfcExportReactorImpl* pObject, bool autoDelete);
    virtual ~PyBimIfcExportReactor() = default;

    bool                attachReactor() const;
    bool                detachReactor() const;
    void                adjustProjectData(PyBrxBimIfcExportContext& context, PyBimIfcProjectData& projectData) const;

    void                onBeginIfcModelSetup(PyBrxBimIfcExportContext& context);
    PyIfcEntity         onEntity(PyBrxBimIfcExportContext& context, PyDbEntity& pEntity);
    void                onEndIfcModelSetup(PyBrxBimIfcExportContext& context);
    void                onEntityConstructed(PyIfcEntity& contructedEntity, PyDbEntity& pSourceBCEntity);


    static std::string  className();
public:
    PyBimIfcExportReactorImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyBimIfcExportReactorImpl> m_pyImp;

public:
    bool reg_onBeginIfcModelSetup = true;
    bool reg_onEntity = true;
    bool reg_onEndIfcModelSetup = true;
    bool reg_onEntityConstructed = true;
};

#endif