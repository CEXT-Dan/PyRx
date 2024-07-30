#include "stdafx.h"
#include "PyBrxBimImportExport.h"

#ifdef BRXAPP
#include "PyDbDatabase.h"
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

#endif

