#include "stdafx.h"
#include "PyBrxBimImportExport.h"

#ifdef BRXAPP
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"
#include "PyBrxIFC.h"

using namespace boost::python;

void makePyBrxIfcImportOptionsWrapper()
{
    PyDocString DS("IfcImportOptions");
    class_<PyBrxIfcImportOptions>("IfcImportOptions")
        .def("importBimData", &PyBrxIfcImportOptions::importBimData, DS.ARGS())
        .def("setImportBimData", &PyBrxIfcImportOptions::setImportBimData, DS.ARGS({ "val: bool" }))
        .def("importIfcSpace", &PyBrxIfcImportOptions::importIfcSpace, DS.ARGS())
        .def("setImportIfcSpace", &PyBrxIfcImportOptions::setImportIfcSpace, DS.ARGS({ "val: bool" }))
        .def("importParametricComponents", &PyBrxIfcImportOptions::importParametricComponents, DS.ARGS())
        .def("setImportParametricComponents", &PyBrxIfcImportOptions::setImportParametricComponents, DS.ARGS({ "val: bool" }))
        .def("importIfcProjectStructureAsXrefs", &PyBrxIfcImportOptions::importIfcProjectStructureAsXrefs, DS.ARGS())
        .def("setImportIfcProjectStructureAsXrefs", &PyBrxIfcImportOptions::setImportIfcProjectStructureAsXrefs, DS.ARGS({ "val: bool" }))
        .def("importBrepGeometryAsMeshes", &PyBrxIfcImportOptions::importBrepGeometryAsMeshes, DS.ARGS())
        .def("setImportBrepGeometryAsMeshes", &PyBrxIfcImportOptions::setImportBrepGeometryAsMeshes, DS.ARGS({ "val: bool" }))
        .def("importModelOrigin", &PyBrxIfcImportOptions::importModelOrigin, DS.ARGS())
        .def("setImportModelOrigin", &PyBrxIfcImportOptions::setImportModelOrigin, DS.ARGS({ "val: PyBrxBim.IfcImportModelOrigin" }))
        .def("importIfcFile", &PyBrxIfcImportOptions::importIfcFile1, DS.SARGS())
        .def("importIfcFile", &PyBrxIfcImportOptions::importIfcFile2, DS.SARGS({ "db: PyDb.Database", "filename: str", "options: PyBrxIfc.ImportOptions=None" })).staticmethod("importIfcFile")
        .def("className", &PyBrxIfcImportOptions::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxIfcImportOptions::PyBrxIfcImportOptions()
    :PyBrxIfcImportOptions(new BimApi::BrxIfcImportOptions(), true)
{
}

PyBrxIfcImportOptions::PyBrxIfcImportOptions(const BimApi::BrxIfcImportOptions* pObject)
    :PyBrxIfcImportOptions(const_cast<BimApi::BrxIfcImportOptions*>(pObject), false)
{
}

PyBrxIfcImportOptions::PyBrxIfcImportOptions(BimApi::BrxIfcImportOptions* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BimApi::BrxIfcImportOptions>(autoDelete))
{
}

bool PyBrxIfcImportOptions::importBimData() const
{
    return impObj()->importBimData();
}

void PyBrxIfcImportOptions::setImportBimData(bool bOn)
{
    impObj()->setImportBimData(bOn);
}

bool PyBrxIfcImportOptions::importIfcSpace() const
{
    return impObj()->importIfcSpace();
}

void PyBrxIfcImportOptions::setImportIfcSpace(bool bOn)
{
    impObj()->setImportIfcSpace(bOn);
}

bool PyBrxIfcImportOptions::importParametricComponents() const
{
    return impObj()->importParametricComponents();
}

void PyBrxIfcImportOptions::setImportParametricComponents(bool bOn)
{
    impObj()->setImportParametricComponents(bOn);
}

bool PyBrxIfcImportOptions::importIfcProjectStructureAsXrefs() const
{
    return impObj()->importIfcProjectStructureAsXrefs();
}

void PyBrxIfcImportOptions::setImportIfcProjectStructureAsXrefs(bool bOn)
{
    impObj()->setImportIfcProjectStructureAsXrefs(bOn);
}

bool PyBrxIfcImportOptions::importBrepGeometryAsMeshes() const
{
    return impObj()->importBrepGeometryAsMeshes();
}

void PyBrxIfcImportOptions::setImportBrepGeometryAsMeshes(bool bOn)
{
    impObj()->setImportBrepGeometryAsMeshes(bOn);
}

BimApi::EIfcImportModelOrigin PyBrxIfcImportOptions::importModelOrigin() const
{
    return impObj()->importModelOrigin();
}

void PyBrxIfcImportOptions::setImportModelOrigin(BimApi::EIfcImportModelOrigin mode)
{
    impObj()->setImportModelOrigin(mode);
}

void PyBrxIfcImportOptions::importIfcFile1(PyDbDatabase& pDb, const std::string szFilename)
{
    PyThrowBadBim(BimApi::importIfcFile(pDb.impObj(), utf8_to_wstr(szFilename).c_str()));
}

void PyBrxIfcImportOptions::importIfcFile2(PyDbDatabase& pDb, const std::string szFilename, const PyBrxIfcImportOptions& pOptions)
{
    PyThrowBadBim(BimApi::importIfcFile(pDb.impObj(), utf8_to_wstr(szFilename).c_str(), pOptions.impObj()));
}

std::string PyBrxIfcImportOptions::className()
{
    return "BrxIfcImportOptions";
}

BimApi::BrxIfcImportOptions* PyBrxIfcImportOptions::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BimApi::BrxIfcImportOptions*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyBrxBimIfcImportInfo
void makePyBrxBimIfcImportInfoWrapper()
{
    PyDocString DS("IfcImportInfo");
    class_<PyBrxBimIfcImportInfo>("IfcImportInfo")
        .def("className", &PyBrxBimIfcImportInfo::fileName, DS.ARGS())
        .def("timeStamp", &PyBrxBimIfcImportInfo::timeStamp, DS.ARGS())
        .def("author", &PyBrxBimIfcImportInfo::author, DS.ARGS())
        .def("organization", &PyBrxBimIfcImportInfo::organization, DS.ARGS())
        .def("preprocessorVersion", &PyBrxBimIfcImportInfo::preprocessorVersion, DS.ARGS())
        .def("originatingSystem", &PyBrxBimIfcImportInfo::originatingSystem, DS.ARGS())
        .def("authorization", &PyBrxBimIfcImportInfo::authorization, DS.ARGS())
        .def("importBimData", &PyBrxBimIfcImportInfo::importBimData, DS.ARGS())
        .def("importIfcSpace", &PyBrxBimIfcImportInfo::importIfcSpace, DS.ARGS())
        .def("importParametricComponents", &PyBrxBimIfcImportInfo::importParametricComponents, DS.ARGS())
        .def("importIfcProjectStructureAsXrefs", &PyBrxBimIfcImportInfo::importIfcProjectStructureAsXrefs, DS.ARGS())
        .def("importBrepGeometryAsMeshes", &PyBrxBimIfcImportInfo::importBrepGeometryAsMeshes, DS.ARGS())
        .def("className", &PyBrxBimIfcImportInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimIfcImportInfo::PyBrxBimIfcImportInfo()
    :PyBrxBimIfcImportInfo(new BimIfcImportInfo(), true)
{
}

PyBrxBimIfcImportInfo::PyBrxBimIfcImportInfo(BrxIfcTranslatorOptions* opts, Ice::IfcApi::Header* header)
    :PyBrxBimIfcImportInfo(new BimIfcImportInfo(opts, header), true)
{
}

PyBrxBimIfcImportInfo::PyBrxBimIfcImportInfo(const BimIfcImportInfo* pObject)
    :PyBrxBimIfcImportInfo(const_cast<BimIfcImportInfo*>(pObject), false)
{
}

PyBrxBimIfcImportInfo::PyBrxBimIfcImportInfo(BimIfcImportInfo* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<BimIfcImportInfo>(autoDelete))
{
}

std::string PyBrxBimIfcImportInfo::fileName() const
{
    return wstr_to_utf8(impObj()->fileName());
}

std::string PyBrxBimIfcImportInfo::timeStamp() const
{
    return wstr_to_utf8(impObj()->timeStamp());
}

std::string PyBrxBimIfcImportInfo::author() const
{
    return wstr_to_utf8(impObj()->author());
}

std::string PyBrxBimIfcImportInfo::organization() const
{
    return wstr_to_utf8(impObj()->organization());
}

std::string PyBrxBimIfcImportInfo::preprocessorVersion() const
{
    return wstr_to_utf8(impObj()->preprocessorVersion());
}

std::string PyBrxBimIfcImportInfo::originatingSystem() const
{
    return wstr_to_utf8(impObj()->originatingSystem());
}

std::string PyBrxBimIfcImportInfo::authorization() const
{
    return wstr_to_utf8(impObj()->authorization());
}

bool PyBrxBimIfcImportInfo::importBimData() const
{
    return impObj()->importBimData();
}

bool PyBrxBimIfcImportInfo::importIfcSpace() const
{
    return impObj()->importIfcSpace();
}

bool PyBrxBimIfcImportInfo::importParametricComponents() const
{
    return impObj()->importParametricComponents();
}

bool PyBrxBimIfcImportInfo::importIfcProjectStructureAsXrefs() const
{
    return impObj()->importIfcProjectStructureAsXrefs();
}

bool PyBrxBimIfcImportInfo::importBrepGeometryAsMeshes() const
{
    return impObj()->importBrepGeometryAsMeshes();
}

std::string PyBrxBimIfcImportInfo::className()
{
    return "BimIfcImportInfo";
}

BimIfcImportInfo* PyBrxBimIfcImportInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<BimIfcImportInfo*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//BrxBimIfcImportContext
void makePyBrxBimIfcImportContextWrapper()
{
    PyDocString DS("IfcImportContext");
    class_<PyBrxBimIfcImportContext>("IfcImportContext", boost::python::no_init)
        .def("ifcModel", &PyBrxBimIfcImportContext::ifcModel, DS.ARGS())
        .def("database", &PyBrxBimIfcImportContext::database, DS.ARGS())
        .def("createDefaultRepresentation", &PyBrxBimIfcImportContext::createDefaultRepresentation, DS.ARGS({ "entity: PyBrxBim.IFCEntity","isParent: bool" , "parent: PyBrxBim.IFCEntity" }))
        .def("createRepresentationFromItem", &PyBrxBimIfcImportContext::createRepresentationFromItem, DS.ARGS({ "entity: PyBrxBim.IFCEntity" }))
        .def("createPoint", &PyBrxBimIfcImportContext::createPoint, DS.ARGS({ "entity: PyBrxBim.IFCEntity" }))
        .def("getLocalPlacement", &PyBrxBimIfcImportContext::getLocalPlacement, DS.ARGS({ "entity: PyBrxBim.IFCEntity" }))
        .def("createSweptArea", &PyBrxBimIfcImportContext::createSweptArea, DS.ARGS({ "entity: PyBrxBim.IFCEntity" }))
        .def("getEntity", &PyBrxBimIfcImportContext::getEntity, DS.ARGS({ "entity: PyBrxBim.IFCEntity" }))
        .def("getEntityId", &PyBrxBimIfcImportContext::getEntityId, DS.ARGS({ "entity: PyBrxBim.IFCEntity" }))
        .def("angleConversionFactor", &PyBrxBimIfcImportContext::angleConversionFactor, DS.ARGS())
        .def("areaConversionFactor", &PyBrxBimIfcImportContext::areaConversionFactor, DS.ARGS())
        .def("lengthConversionFactor", &PyBrxBimIfcImportContext::lengthConversionFactor, DS.ARGS())
        .def("volumeConversionFactor", &PyBrxBimIfcImportContext::volumeConversionFactor, DS.ARGS())
        .def("precision", &PyBrxBimIfcImportContext::precision, DS.ARGS())
        .def("className", &PyBrxBimIfcImportContext::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxBimIfcImportContext::PyBrxBimIfcImportContext(const IfcImportContext* pObject)
    :PyBrxBimIfcImportContext(const_cast<IfcImportContext*>(pObject), false)
{
}

PyBrxBimIfcImportContext::PyBrxBimIfcImportContext(IfcImportContext* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<IfcImportContext>(autoDelete))
{
}

PyIFCModel PyBrxBimIfcImportContext::ifcModel()
{
    return PyIFCModel(impObj()->ifcModel(), false);
}

PyDbDatabase PyBrxBimIfcImportContext::database()
{
    return PyDbDatabase(impObj()->database());
}

PyDbEntity PyBrxBimIfcImportContext::createDefaultRepresentation(const PyIFCEntity& entity, bool isParent, const PyIFCEntity& parent)
{
    return PyDbEntity(impObj()->createDefaultRepresentation(*entity.impObj(), isParent, *parent.impObj()),true);
}

PyDbEntity PyBrxBimIfcImportContext::createRepresentationFromItem(const PyIFCEntity& entity)
{
    return PyDbEntity(impObj()->createRepresentationFromItem(*entity.impObj()), true);
}

AcGePoint3d PyBrxBimIfcImportContext::createPoint(const PyIFCEntity& point)
{
    return impObj()->createPoint(*point.impObj());
}

AcGeMatrix3d PyBrxBimIfcImportContext::getLocalPlacement(const PyIFCEntity& point)
{
    return impObj()->getLocalPlacement(*point.impObj());
}

boost::python::list PyBrxBimIfcImportContext::createSweptArea(const PyIFCEntity& sweptArea)
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto ptr : impObj()->createSweptArea(*sweptArea.impObj()))
        pylist.append(PyDbEntity(ptr, true));
    return pylist;
}

PyDbEntity PyBrxBimIfcImportContext::getEntity(const PyIFCEntity& ifcEntity)
{
    AcDbEntity* pEnt = nullptr;
    if (bool flag = impObj()->getEntity(pEnt, *ifcEntity.impObj()); flag == false)
        PyThrowBadBim(BimApi::eInvalidInput);
    return PyDbEntity(pEnt, true);
}

PyDbObjectId PyBrxBimIfcImportContext::getEntityId(const PyIFCEntity& ifcEntity)
{
    PyDbObjectId id;
    if (bool flag = impObj()->getEntity(id.m_id, *ifcEntity.impObj()); flag == false)
        PyThrowBadBim(BimApi::eInvalidInput);
    return id;
}

double PyBrxBimIfcImportContext::angleConversionFactor()
{
    return impObj()->angleConversionFactor();
}

double PyBrxBimIfcImportContext::areaConversionFactor()
{
    return impObj()->areaConversionFactor();
}

double PyBrxBimIfcImportContext::lengthConversionFactor()
{
    return impObj()->lengthConversionFactor();
}

double PyBrxBimIfcImportContext::volumeConversionFactor()
{
    return impObj()->volumeConversionFactor();
}

double PyBrxBimIfcImportContext::precision()
{
    return impObj()->precision();
}

std::string PyBrxBimIfcImportContext::className()
{
    return "BimIfcImportContext";
}

IfcImportContext* PyBrxBimIfcImportContext::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IfcImportContext*>(m_pyImp.get());
}

#endif
