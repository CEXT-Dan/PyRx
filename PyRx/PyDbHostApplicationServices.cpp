#include "stdafx.h"
#include "PyDbHostApplicationServices.h"
#include "PyDbDatabase.h"
#include "PyDbLayout.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyDbHostApplicationServices
void makeAcDbHostApplicationServicesWrapper()
{
    class_<PyDbHostApplicationServices, boost::noncopyable>("HostApplicationServices")
        .def(init<>())
        .def("workingDatabase", &PyDbHostApplicationServices::workingDatabase)
        .def("setWorkingDatabase", &PyDbHostApplicationServices::setWorkingDatabase)
        .def("findFile", &PyDbHostApplicationServices::findFile1)
        .def("findFile", &PyDbHostApplicationServices::findFile2)
        .def("findFile", &PyDbHostApplicationServices::findFile3)
        .def("product", &PyDbHostApplicationServices::product)
        .def("LayoutManager", &PyDbHostApplicationServices::dbLayoutManager)
        ;

    enum_<AcDbHostApplicationServices::FindFileHint>("FindFileHint")
        .value("kDefault", AcDbHostApplicationServices::FindFileHint::kDefault)
        .value("kFontFile", AcDbHostApplicationServices::FindFileHint::kFontFile)
        .value("kCompiledShapeFile", AcDbHostApplicationServices::FindFileHint::kCompiledShapeFile)
        .value("kTrueTypeFontFile", AcDbHostApplicationServices::FindFileHint::kTrueTypeFontFile)
        .value("kEmbeddedImageFile", AcDbHostApplicationServices::FindFileHint::kEmbeddedImageFile)
        .value("kXRefDrawing", AcDbHostApplicationServices::FindFileHint::kXRefDrawing)
        .value("kPatternFile", AcDbHostApplicationServices::FindFileHint::kPatternFile)
        .value("kARXApplication", AcDbHostApplicationServices::FindFileHint::kARXApplication)
        .value("kFontMapFile", AcDbHostApplicationServices::FindFileHint::kFontMapFile)
        .value("kUnderlayFile", AcDbHostApplicationServices::FindFileHint::kUnderlayFile)
        .value("kDataLinkFile", AcDbHostApplicationServices::FindFileHint::kDataLinkFile)
        .value("kPhotometricWebFile", AcDbHostApplicationServices::FindFileHint::kPhotometricWebFile)
        .value("kMaterialMapFile", AcDbHostApplicationServices::FindFileHint::kMaterialMapFile)
        .value("kCloudOrProjectFile", AcDbHostApplicationServices::FindFileHint::kCloudOrProjectFile)
        .export_values()
        ;

    enum_<AcDbHostApplicationServices::RemapFileContext>("RemapFileContext")
        .value("kDrawingOpen", AcDbHostApplicationServices::RemapFileContext::kDrawingOpen)
        .value("kXrefResolution", AcDbHostApplicationServices::RemapFileContext::kXrefResolution)
        .value("kRasterResolution", AcDbHostApplicationServices::RemapFileContext::kRasterResolution)
        .value("kAfterXrefResolution", AcDbHostApplicationServices::RemapFileContext::kAfterXrefResolution)
        .export_values()
        ;
}

PyDbDatabase PyDbHostApplicationServices::workingDatabase() const
{
    return PyDbDatabase(pDbHostApp->workingDatabase());
}

void PyDbHostApplicationServices::setWorkingDatabase(PyDbDatabase& pDatabase)
{
    pDbHostApp->setWorkingDatabase(pDatabase.impObj());
}

std::string PyDbHostApplicationServices::findFile1(const std::string& fileName)
{
    AcString fileOut;
    if (auto es = pDbHostApp->findFile(fileOut, utf8_to_wstr(fileName).c_str()); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(fileOut);
}

std::string PyDbHostApplicationServices::findFile2(const std::string& fileName, const PyDbDatabase& db)
{
    AcString fileOut;
    if (auto es = pDbHostApp->findFile(fileOut, utf8_to_wstr(fileName).c_str(), db.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(fileOut);
}

std::string PyDbHostApplicationServices::findFile3(const std::string& fileName, const PyDbDatabase& db, AcDbHostApplicationServices::FindFileHint hint)
{
    AcString fileOut;
    if (auto es = pDbHostApp->findFile(fileOut, utf8_to_wstr(fileName).c_str(), db.impObj(), hint); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(fileOut);
}

std::string PyDbHostApplicationServices::product() const
{
    return  wstr_to_utf8(pDbHostApp->product());
}

PyDbLayoutManager PyDbHostApplicationServices::dbLayoutManager()
{
    return PyDbLayoutManager(pDbHostApp->layoutManager(), false);
}

//---------------------------------------------------------------------------------------- -
//PyDbSymUtilServices
void makeAPyDbSymUtilServicesWrapper()
{
    class_<PyDbSymUtilServices, boost::noncopyable>("SymUtilServices")
        .def(init<>())
        .def("isBlockLayoutName", &PyDbSymUtilServices::isBlockLayoutName)
        .def("isBlockModelSpaceName", &PyDbSymUtilServices::isBlockModelSpaceName)
        .def("isBlockPaperSpaceName", &PyDbSymUtilServices::isBlockPaperSpaceName)
        .def("isLayerDefpointsName", &PyDbSymUtilServices::isLayerDefpointsName)
        .def("isLayerZeroName", &PyDbSymUtilServices::isLayerZeroName)
        .def("isLinetypeByBlockName", &PyDbSymUtilServices::isLinetypeByBlockName)
        .def("isLinetypeByLayerName", &PyDbSymUtilServices::isLinetypeByLayerName)
        .def("isLinetypeContinuousName", &PyDbSymUtilServices::isLinetypeContinuousName)
        .def("isRegAppAcadName", &PyDbSymUtilServices::isRegAppAcadName)
        .def("isTextStyleStandardName", &PyDbSymUtilServices::isTextStyleStandardName)
        .def("isViewportActiveName", &PyDbSymUtilServices::isViewportActiveName)
        .def("blockModelSpaceId", &PyDbSymUtilServices::blockModelSpaceId)
        .def("blockPaperSpaceId", &PyDbSymUtilServices::blockPaperSpaceId)
        .def("layerDefpointsId", &PyDbSymUtilServices::layerDefpointsId)
        .def("layerZeroId", &PyDbSymUtilServices::layerZeroId)
        .def("linetypeByBlockId", &PyDbSymUtilServices::linetypeByBlockId)
        .def("linetypeByLayerId", &PyDbSymUtilServices::linetypeByLayerId)
        .def("linetypeContinuousId", &PyDbSymUtilServices::linetypeContinuousId)
        .def("regAppAcadId", &PyDbSymUtilServices::regAppAcadId)
        .def("textStyleStandardId", &PyDbSymUtilServices::textStyleStandardId)
        .def("blockModelSpaceName", &PyDbSymUtilServices::blockModelSpaceName)
        .def("blockPaperSpaceName", &PyDbSymUtilServices::blockPaperSpaceName)
        .def("layerDefpointsName", &PyDbSymUtilServices::layerDefpointsName)
        .def("layerZeroName", &PyDbSymUtilServices::layerZeroName)
        .def("linetypeByBlockName", &PyDbSymUtilServices::linetypeByBlockName)
        .def("linetypeByLayerName", &PyDbSymUtilServices::linetypeByLayerName)
        .def("linetypeContinuousName", &PyDbSymUtilServices::linetypeContinuousName)
        .def("regAppAcadName", &PyDbSymUtilServices::regAppAcadName)
        .def("textStyleStandardName", &PyDbSymUtilServices::textStyleStandardName)
        .def("viewportActiveName", &PyDbSymUtilServices::viewportActiveName)
        .def("compareSymbolName", &PyDbSymUtilServices::compareSymbolName)
        .def("hasVerticalBar", &PyDbSymUtilServices::hasVerticalBar)
        .def("makeDependentName", &PyDbSymUtilServices::makeDependentName)
        .def("repairPreExtendedSymbolName", &PyDbSymUtilServices::repairPreExtendedSymbolName)
        .def("repairSymbolName", &PyDbSymUtilServices::repairSymbolName)
        .def("validatePreExtendedSymbolName", &PyDbSymUtilServices::validatePreExtendedSymbolName)
        .def("validateSymbolName", &PyDbSymUtilServices::validateSymbolName)
        .def("compatibilityMode", &PyDbSymUtilServices::compatibilityMode)
        .def("getBlockNameFromInsertPathName", &PyDbSymUtilServices::getBlockNameFromInsertPathName)
        .def("getInsertPathNameFromBlockName", &PyDbSymUtilServices::getInsertPathNameFromBlockName)
        .def("getPathNameFromSymbolName", &PyDbSymUtilServices::getPathNameFromSymbolName)
        .def("getSymbolNameFromPathName", &PyDbSymUtilServices::getSymbolNameFromPathName)
        .def("validateCompatibleSymbolName", &PyDbSymUtilServices::validateCompatibleSymbolName)
        ;
}

bool PyDbSymUtilServices::isBlockLayoutName(const std::string& name) const
{
    return imp->isBlockLayoutName(utf8_to_wstr(name).c_str());
}

bool PyDbSymUtilServices::isBlockModelSpaceName(const std::string& name) const
{
    return imp->isBlockModelSpaceName(utf8_to_wstr(name).c_str());
}

bool PyDbSymUtilServices::isBlockPaperSpaceName(const std::string& name) const
{
    return imp->isBlockPaperSpaceName(utf8_to_wstr(name).c_str());
}

bool PyDbSymUtilServices::isLayerDefpointsName(const std::string& name) const
{
    return imp->isLayerDefpointsName(utf8_to_wstr(name).c_str());
}

bool PyDbSymUtilServices::isLayerZeroName(const std::string& name) const
{
    return imp->isLayerZeroName(utf8_to_wstr(name).c_str());
}

bool PyDbSymUtilServices::isLinetypeByBlockName(const std::string& name) const
{
    return imp->isLinetypeByBlockName(utf8_to_wstr(name).c_str());
}

bool PyDbSymUtilServices::isLinetypeByLayerName(const std::string& name) const
{
    return imp->isLinetypeByLayerName(utf8_to_wstr(name).c_str());
}

bool PyDbSymUtilServices::isLinetypeContinuousName(const std::string& name) const
{
    return imp->isLinetypeContinuousName(utf8_to_wstr(name).c_str());
}

bool PyDbSymUtilServices::isRegAppAcadName(const std::string& name) const
{
    return imp->isRegAppAcadName(utf8_to_wstr(name).c_str());
}

bool PyDbSymUtilServices::isTextStyleStandardName(const std::string& name) const
{
    return imp->isTextStyleStandardName(utf8_to_wstr(name).c_str());
}

bool PyDbSymUtilServices::isViewportActiveName(const std::string& name) const
{
    return imp->isViewportActiveName(utf8_to_wstr(name).c_str());
}

PyDbObjectId PyDbSymUtilServices::blockModelSpaceId(PyDbDatabase& pDb) const
{
   return PyDbObjectId(imp->blockModelSpaceId(pDb.impObj()));
}

PyDbObjectId PyDbSymUtilServices::blockPaperSpaceId(PyDbDatabase& pDb) const
{
    return PyDbObjectId(imp->blockPaperSpaceId(pDb.impObj()));
}

PyDbObjectId PyDbSymUtilServices::layerDefpointsId(PyDbDatabase& pDb) const
{
    return PyDbObjectId(imp->layerDefpointsId(pDb.impObj()));
}

PyDbObjectId PyDbSymUtilServices::layerZeroId(PyDbDatabase& pDb) const
{
    return PyDbObjectId(imp->layerZeroId(pDb.impObj()));
}

PyDbObjectId PyDbSymUtilServices::linetypeByBlockId(PyDbDatabase& pDb) const
{
    return PyDbObjectId(imp->linetypeByBlockId(pDb.impObj()));
}

PyDbObjectId PyDbSymUtilServices::linetypeByLayerId(PyDbDatabase& pDb) const
{
    return PyDbObjectId(imp->linetypeByLayerId(pDb.impObj()));
}

PyDbObjectId PyDbSymUtilServices::linetypeContinuousId(PyDbDatabase& pDb) const
{
    return PyDbObjectId(imp->linetypeContinuousId(pDb.impObj()));
}

PyDbObjectId PyDbSymUtilServices::regAppAcadId(PyDbDatabase& pDb) const
{
    return PyDbObjectId(imp->regAppAcadId(pDb.impObj()));
}

PyDbObjectId PyDbSymUtilServices::textStyleStandardId(PyDbDatabase& pDb) const
{
    return PyDbObjectId(imp->textStyleStandardId(pDb.impObj()));
}

std::string PyDbSymUtilServices::blockModelSpaceName() const
{
    return wstr_to_utf8(imp->blockModelSpaceName());
}

std::string PyDbSymUtilServices::blockPaperSpaceName() const
{
    return wstr_to_utf8(imp->blockPaperSpaceName());
}

std::string PyDbSymUtilServices::layerDefpointsName() const
{
    return wstr_to_utf8(imp->layerDefpointsName());
}

std::string PyDbSymUtilServices::layerZeroName() const
{
    return wstr_to_utf8(imp->layerZeroName());
}

std::string PyDbSymUtilServices::linetypeByBlockName() const
{
    return wstr_to_utf8(imp->linetypeByBlockName());
}

std::string PyDbSymUtilServices::linetypeByLayerName() const
{
    return wstr_to_utf8(imp->linetypeByLayerName());
}

std::string PyDbSymUtilServices::linetypeContinuousName() const
{
    return wstr_to_utf8(imp->linetypeContinuousName());
}

std::string PyDbSymUtilServices::regAppAcadName() const
{
    return wstr_to_utf8(imp->regAppAcadName());
}

std::string PyDbSymUtilServices::textStyleStandardName() const
{
    return wstr_to_utf8(imp->textStyleStandardName());
}

std::string PyDbSymUtilServices::viewportActiveName() const
{
    return wstr_to_utf8(imp->viewportActiveName());
}

int PyDbSymUtilServices::compareSymbolName(const std::string& thisName, const std::string& otherName) const
{
    return imp->compareSymbolName(utf8_to_wstr(thisName).c_str(), utf8_to_wstr(otherName).c_str());
}

bool PyDbSymUtilServices::hasVerticalBar(const std::string& name) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    return imp->hasVerticalBar(utf8_to_wstr(name).c_str());
#endif
}

std::string PyDbSymUtilServices::makeDependentName(const std::string& dwgName, const std::string& symbolName) const
{
    ACHAR* pNewName = nullptr;
    if (auto es = imp->makeDependentName(pNewName, utf8_to_wstr(dwgName).c_str(), utf8_to_wstr(symbolName).c_str()); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

std::string PyDbSymUtilServices::repairPreExtendedSymbolName(const std::string& oldName, bool allowVerticalBar) const
{
    ACHAR* pNewName = nullptr;
    if (auto es = imp->repairPreExtendedSymbolName(pNewName, utf8_to_wstr(oldName).c_str(), allowVerticalBar); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

std::string PyDbSymUtilServices::repairSymbolName(const std::string& oldName, bool allowVerticalBar) const
{
    ACHAR* pNewName = nullptr;
    if (auto es = imp->repairSymbolName(pNewName, utf8_to_wstr(oldName).c_str(), allowVerticalBar); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

Acad::ErrorStatus PyDbSymUtilServices::validatePreExtendedSymbolName(const std::string& name, bool allowVerticalBar) const
{
    return imp->validatePreExtendedSymbolName(utf8_to_wstr(name).c_str(), allowVerticalBar);
}

Acad::ErrorStatus PyDbSymUtilServices::validateSymbolName(const std::string& name, bool allowVerticalBar) const
{
    return imp->validateSymbolName(utf8_to_wstr(name).c_str(), allowVerticalBar);
}

bool PyDbSymUtilServices::compatibilityMode(PyDbDatabase& pDb) const
{
    return imp->compatibilityMode(pDb.impObj());
}

std::string PyDbSymUtilServices::getBlockNameFromInsertPathName(const std::string& pathName) const
{
    ACHAR* pNewName = nullptr;
    if (auto es = imp->getBlockNameFromInsertPathName(pNewName, utf8_to_wstr(pathName).c_str()); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

std::string PyDbSymUtilServices::getInsertPathNameFromBlockName(const std::string& pathName) const
{
    ACHAR* pNewName = nullptr;
    if (auto es = imp->getInsertPathNameFromBlockName(pNewName, utf8_to_wstr(pathName).c_str()); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

std::string PyDbSymUtilServices::getPathNameFromSymbolName(const std::string& symbolName, const std::string& extensions) const
{
    ACHAR* pNewName = nullptr;
    if (auto es = imp->getPathNameFromSymbolName(pNewName, utf8_to_wstr(symbolName).c_str(), utf8_to_wstr(extensions).c_str()); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

std::string PyDbSymUtilServices::getSymbolNameFromPathName(const std::string& symbolName, const std::string& extensions) const
{
    ACHAR* pNewName = nullptr;
    if (auto es = imp->getSymbolNameFromPathName(pNewName, utf8_to_wstr(symbolName).c_str(), utf8_to_wstr(extensions).c_str()); es != eOk)
        throw PyAcadErrorStatus(es);
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

Acad::ErrorStatus PyDbSymUtilServices::validateCompatibleSymbolName(const std::string& name, bool isNewName, bool allowVerticalBar, bool compatibilityMode) const
{
    return imp->validateCompatibleSymbolName(utf8_to_wstr(name).c_str(), isNewName, allowVerticalBar, compatibilityMode);
}

