#pragma once
#ifdef BRXAPP

class PyDbDatabase;

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
#endif