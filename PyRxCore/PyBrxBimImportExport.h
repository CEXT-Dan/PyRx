#pragma once
#ifdef BRXAPP

class PyIFCModel;
class PyIFCEntity;
class PyDbEntity;
class PyDbDatabase;
class PyDbObjectId;

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
    void setImportBimData(bool bOn);
    bool importIfcSpace() const;
    void setImportIfcSpace(bool bOn);
    bool importParametricComponents() const;
    void setImportParametricComponents(bool bOn);
    bool importIfcProjectStructureAsXrefs() const;
    void setImportIfcProjectStructureAsXrefs(bool bOn);
    bool importBrepGeometryAsMeshes() const;
    void setImportBrepGeometryAsMeshes(bool bOn);
    BimApi::EIfcImportModelOrigin importModelOrigin() const;
    void setImportModelOrigin(BimApi::EIfcImportModelOrigin mode);
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

    PyIFCModel          ifcModel();
    PyDbDatabase        database();
    PyDbEntity          createDefaultRepresentation(const PyIFCEntity& entity, bool isParent, const PyIFCEntity& parent);
    PyDbEntity          createRepresentationFromItem(const PyIFCEntity& entity);
    AcGePoint3d         createPoint(const PyIFCEntity& point);
    AcGeMatrix3d        getLocalPlacement(const PyIFCEntity& point);
    boost::python::list createSweptArea(const PyIFCEntity& sweptArea);
    PyDbEntity          getEntity(const PyIFCEntity& ifcEntity);
    PyDbObjectId        getEntityId(const PyIFCEntity& ifcEntity);
    double              angleConversionFactor();
    double              areaConversionFactor();
    double              lengthConversionFactor();
    double              volumeConversionFactor();
    double              precision();
    static std::string  className();
public:
    IfcImportContext*   impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<IfcImportContext> m_pyImp;
};


//---------------------------------------------------------------------------------------- -
//PyBimIfcImportReactorImpl
class PyBimIfcImportReactor;

class PyBimIfcImportReactorImpl : public BimIfcImportReactorInstance, public BimIfcImportReactor
{
public:
    explicit PyBimIfcImportReactorImpl(PyBimIfcImportReactor* ptr);

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
};

//---------------------------------------------------------------------------------------- -
//BimIfcImportReactor
void makePyBimIfcImportReactorWrapper();

class PyBimIfcImportReactor
{
public:
    PyBimIfcImportReactor(const PyBimIfcImportReactorImpl* pObject);
    PyBimIfcImportReactor(PyBimIfcImportReactorImpl* pObject, bool autoDelete);
    virtual ~PyBimIfcImportReactor() = default;

  
    static std::string  className();
public:
    PyBimIfcImportReactorImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyBimIfcImportReactorImpl> m_pyImp;
};





#endif