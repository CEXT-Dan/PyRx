#include "stdafx.h"
#include "PyDbHostApplicationServices.h"
#include "PyDbDatabase.h"
#include "PyDbLayout.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyDbHostApplicationServices
void makePyDbHostApplicationServicesWrapper()
{
    class_<PyDbHostApplicationServices>("HostApplicationServices")
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
void makePyDbSymUtilServicesWrapper()
{
    class_<PyDbSymUtilServices>("SymUtilServices")
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
    std::size_t found = name.find("|");
    return found != std::string::npos;
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

//---------------------------------------------------------------------------------------- -
//PyDbDatabaseSummaryInfo
void makePyDbDatabaseSummaryInfoWrapper()
{
    PyDocString DS("DatabaseSummaryInfo");
    class_<PyDbDatabaseSummaryInfo, bases<PyRxObject>>("DatabaseSummaryInfo", boost::python::no_init)
        .def("getTitle", &PyDbDatabaseSummaryInfo::getTitle)
        .def("setTitle", &PyDbDatabaseSummaryInfo::setTitle)
        .def("getSubject", &PyDbDatabaseSummaryInfo::getSubject)
        .def("setSubject", &PyDbDatabaseSummaryInfo::setSubject)
        .def("getAuthor", &PyDbDatabaseSummaryInfo::getAuthor)
        .def("setAuthor", &PyDbDatabaseSummaryInfo::setAuthor)
        .def("getKeywords", &PyDbDatabaseSummaryInfo::getKeywords)
        .def("setKeywords", &PyDbDatabaseSummaryInfo::setKeywords)
        .def("getComments", &PyDbDatabaseSummaryInfo::getComments)
        .def("setComments", &PyDbDatabaseSummaryInfo::setComments)
        .def("getLastSavedBy", &PyDbDatabaseSummaryInfo::getLastSavedBy)
        .def("setLastSavedBy", &PyDbDatabaseSummaryInfo::setLastSavedBy)
        .def("getRevisionNumber", &PyDbDatabaseSummaryInfo::getRevisionNumber)
        .def("setRevisionNumber", &PyDbDatabaseSummaryInfo::setRevisionNumber)
        .def("getHyperlinkBase", &PyDbDatabaseSummaryInfo::getHyperlinkBase)
        .def("setHyperlinkBase", &PyDbDatabaseSummaryInfo::setHyperlinkBase)
        .def("numCustomInfo", &PyDbDatabaseSummaryInfo::numCustomInfo)
        .def("addCustomSummaryInfo", &PyDbDatabaseSummaryInfo::addCustomSummaryInfo)
        .def("deleteCustomSummaryInfo", &PyDbDatabaseSummaryInfo::deleteCustomSummaryInfo1)
        .def("deleteCustomSummaryInfo", &PyDbDatabaseSummaryInfo::deleteCustomSummaryInfo2)
        .def("getCustomSummaryInfo", &PyDbDatabaseSummaryInfo::getCustomSummaryInfo1)
        .def("getCustomSummaryInfo", &PyDbDatabaseSummaryInfo::getCustomSummaryInfo2)
        .def("setCustomSummaryInfo", &PyDbDatabaseSummaryInfo::setCustomSummaryInfo1)
        .def("setCustomSummaryInfo", &PyDbDatabaseSummaryInfo::setCustomSummaryInfo2)
        .def("asDict", &PyDbDatabaseSummaryInfo::asDict)
        .def("className", &PyDbDatabaseSummaryInfo::className, DS.CLASSARGSSTATIC()).staticmethod("className")
        ;
}

PyDbDatabaseSummaryInfo::PyDbDatabaseSummaryInfo(AcDbDatabaseSummaryInfo* ptr)
    : PyRxObject(ptr,false,false)
{
}

std::string PyDbDatabaseSummaryInfo::getTitle() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    ACHAR* _achar = nullptr;
    PyThrowBadEs(impObj()->getTitle(_achar));
    std::string str = wstr_to_utf8(_achar);
    acutDelString(_achar);
    return str;
#else
    AcString str;
    PyThrowBadEs(impObj()->getTitle(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setTitle(const std::string& title)
{
    PyThrowBadEs(impObj()->setTitle(utf8_to_wstr(title).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getSubject() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    ACHAR* _achar = nullptr;
    PyThrowBadEs(impObj()->getSubject(_achar));
    std::string str = wstr_to_utf8(_achar);
    acutDelString(_achar);
    return str;
#else
    AcString str;
    PyThrowBadEs(impObj()->getSubject(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setSubject(const std::string& subject)
{
    PyThrowBadEs(impObj()->setSubject(utf8_to_wstr(subject).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getAuthor() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    ACHAR* _achar = nullptr;
    PyThrowBadEs(impObj()->getAuthor(_achar));
    std::string str = wstr_to_utf8(_achar);
    acutDelString(_achar);
    return str;
#else
    AcString str;
    PyThrowBadEs(impObj()->getAuthor(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setAuthor(const std::string& author)
{
    PyThrowBadEs(impObj()->setAuthor(utf8_to_wstr(author).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getKeywords() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    ACHAR* _achar = nullptr;
    PyThrowBadEs(impObj()->getKeywords(_achar));
    std::string str = wstr_to_utf8(_achar);
    acutDelString(_achar);
    return str;
#else
    AcString str;
    PyThrowBadEs(impObj()->getKeywords(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setKeywords(const std::string& keywordlist)
{
    PyThrowBadEs(impObj()->setKeywords(utf8_to_wstr(keywordlist).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getComments() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    ACHAR* _achar = nullptr;
    PyThrowBadEs(impObj()->getComments(_achar));
    std::string str = wstr_to_utf8(_achar);
    acutDelString(_achar);
    return str;
#else
    AcString str;
    PyThrowBadEs(impObj()->getComments(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setComments(const std::string& comments)
{
    PyThrowBadEs(impObj()->setComments(utf8_to_wstr(comments).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getLastSavedBy() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    ACHAR* _achar = nullptr;
    PyThrowBadEs(impObj()->getLastSavedBy(_achar));
    std::string str = wstr_to_utf8(_achar);
    acutDelString(_achar);
    return str;
#else
    AcString str;
    PyThrowBadEs(impObj()->getLastSavedBy(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setLastSavedBy(const std::string& lastSavedBy)
{
    PyThrowBadEs(impObj()->setLastSavedBy(utf8_to_wstr(lastSavedBy).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getRevisionNumber() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    ACHAR* _achar = nullptr;
    PyThrowBadEs(impObj()->getRevisionNumber(_achar));
    std::string str = wstr_to_utf8(_achar);
    acutDelString(_achar);
    return str;
#else
    AcString str;
    PyThrowBadEs(impObj()->getRevisionNumber(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setRevisionNumber(const std::string& revisionNumber)
{
    PyThrowBadEs(impObj()->setRevisionNumber(utf8_to_wstr(revisionNumber).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getHyperlinkBase() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    ACHAR* _achar = nullptr;
    PyThrowBadEs(impObj()->getHyperlinkBase(_achar));
    std::string str = wstr_to_utf8(_achar);
    acutDelString(_achar);
    return str;
#else
    AcString str;
    PyThrowBadEs(impObj()->getHyperlinkBase(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setHyperlinkBase(const std::string& HyperlinkBase)
{
    PyThrowBadEs(impObj()->setHyperlinkBase(utf8_to_wstr(HyperlinkBase).c_str()));
}

int PyDbDatabaseSummaryInfo::numCustomInfo() const
{
    return impObj()->numCustomInfo();
}

void PyDbDatabaseSummaryInfo::addCustomSummaryInfo(const std::string& key, const std::string& value)
{
    PyThrowBadEs(impObj()->addCustomSummaryInfo(utf8_to_wstr(key).c_str(), utf8_to_wstr(value).c_str()));
}

void PyDbDatabaseSummaryInfo::deleteCustomSummaryInfo1(int index)
{
    PyThrowBadEs(impObj()->deleteCustomSummaryInfo(index));
}

void PyDbDatabaseSummaryInfo::deleteCustomSummaryInfo2(const std::string& key)
{
    PyThrowBadEs(impObj()->deleteCustomSummaryInfo(utf8_to_wstr(key).c_str()));
}

boost::python::tuple PyDbDatabaseSummaryInfo::getCustomSummaryInfo1(const std::string& customInfoKey) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    ACHAR* _achar = nullptr;
    PyThrowBadEs(impObj()->getCustomSummaryInfo(utf8_to_wstr(customInfoKey).c_str(), _achar));
    std::string str = wstr_to_utf8(_achar);
    acutDelString(_achar);
    return boost::python::make_tuple(customInfoKey, str);
#else
    AcString value;
    PyThrowBadEs(impObj()->getCustomSummaryInfo(utf8_to_wstr(customInfoKey).c_str(), value));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(customInfoKey, wstr_to_utf8(value));
#endif
}

boost::python::tuple PyDbDatabaseSummaryInfo::getCustomSummaryInfo2(int index) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    ACHAR* _acharKey = nullptr;
    ACHAR* _acharValue = nullptr;
    PyThrowBadEs(impObj()->getCustomSummaryInfo(index, _acharKey, _acharValue));
    std::string strKey = wstr_to_utf8(_acharKey);
    std::string strVal = wstr_to_utf8(_acharValue);
    acutDelString(_acharKey);
    acutDelString(_acharValue);
    return boost::python::make_tuple(strKey, strVal);
#else
    AcString key;
    AcString value;
    PyThrowBadEs(impObj()->getCustomSummaryInfo(index, key, value));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(wstr_to_utf8(key), wstr_to_utf8(value));
#endif
}

void PyDbDatabaseSummaryInfo::setCustomSummaryInfo1(const std::string& customInfoKey, const std::string& value)
{
    PyThrowBadEs(impObj()->setCustomSummaryInfo(utf8_to_wstr(customInfoKey).c_str(), utf8_to_wstr(value).c_str()));
}

void PyDbDatabaseSummaryInfo::setCustomSummaryInfo2(int index, const std::string& key, const std::string& value)
{
    PyThrowBadEs(impObj()->setCustomSummaryInfo(index,utf8_to_wstr(key).c_str(), utf8_to_wstr(value).c_str()));
}

boost::python::dict PyDbDatabaseSummaryInfo::asDict() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    boost::python::dict sinfoDict;
    for (int idx = 0; idx < this->numCustomInfo(); idx++)
    {
        AcString key;
        AcString value;
        if (impObj()->getCustomSummaryInfo(idx, key, value) == eOk)
        {
            std::string sdtkey = wstr_to_utf8(key);
            std::string stdvalue = wstr_to_utf8(value);
            sinfoDict[sdtkey] = stdvalue;
        }
    }
    return sinfoDict;
#endif
}

std::string PyDbDatabaseSummaryInfo::className()
{
    return "AcDbDatabaseSummaryInfo";
}

AcDbDatabaseSummaryInfo* PyDbDatabaseSummaryInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbDatabaseSummaryInfo*>(m_pyImp.get());
}
