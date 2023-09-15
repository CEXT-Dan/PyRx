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
    PyThrowBadEs(pDbHostApp->findFile(fileOut, utf8_to_wstr(fileName).c_str()));
    return wstr_to_utf8(fileOut);
}

std::string PyDbHostApplicationServices::findFile2(const std::string& fileName, const PyDbDatabase& db)
{
    AcString fileOut;
    PyThrowBadEs(pDbHostApp->findFile(fileOut, utf8_to_wstr(fileName).c_str(), db.impObj()));
    return wstr_to_utf8(fileOut);
}

std::string PyDbHostApplicationServices::findFile3(const std::string& fileName, const PyDbDatabase& db, AcDbHostApplicationServices::FindFileHint hint)
{
    AcString fileOut;
    PyThrowBadEs(pDbHostApp->findFile(fileOut, utf8_to_wstr(fileName).c_str(), db.impObj(), hint));
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
    return imp->hasVerticalBar(utf8_to_wstr(name).c_str());
}

std::string PyDbSymUtilServices::makeDependentName(const std::string& dwgName, const std::string& symbolName) const
{
    ACHAR* pNewName = nullptr;
    PyThrowBadEs(imp->makeDependentName(pNewName, utf8_to_wstr(dwgName).c_str(), utf8_to_wstr(symbolName).c_str()));
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

std::string PyDbSymUtilServices::repairPreExtendedSymbolName(const std::string& oldName, bool allowVerticalBar) const
{
    ACHAR* pNewName = nullptr;
    PyThrowBadEs(imp->repairPreExtendedSymbolName(pNewName, utf8_to_wstr(oldName).c_str(), allowVerticalBar));
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

std::string PyDbSymUtilServices::repairSymbolName(const std::string& oldName, bool allowVerticalBar) const
{
    ACHAR* pNewName = nullptr;
    PyThrowBadEs(imp->repairSymbolName(pNewName, utf8_to_wstr(oldName).c_str(), allowVerticalBar));
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
    PyThrowBadEs(imp->getBlockNameFromInsertPathName(pNewName, utf8_to_wstr(pathName).c_str()));
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

std::string PyDbSymUtilServices::getInsertPathNameFromBlockName(const std::string& pathName) const
{
    ACHAR* pNewName = nullptr;
    PyThrowBadEs(imp->getInsertPathNameFromBlockName(pNewName, utf8_to_wstr(pathName).c_str()));
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

std::string PyDbSymUtilServices::getPathNameFromSymbolName(const std::string& symbolName, const std::string& extensions) const
{
    ACHAR* pNewName = nullptr;
    PyThrowBadEs(imp->getPathNameFromSymbolName(pNewName, utf8_to_wstr(symbolName).c_str(), utf8_to_wstr(extensions).c_str()));
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
    return val;
}

std::string PyDbSymUtilServices::getSymbolNameFromPathName(const std::string& symbolName, const std::string& extensions) const
{
    ACHAR* pNewName = nullptr;
    PyThrowBadEs(imp->getSymbolNameFromPathName(pNewName, utf8_to_wstr(symbolName).c_str(), utf8_to_wstr(extensions).c_str()));
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
        .def("setCustomSummaryFromDict", &PyDbDatabaseSummaryInfo::setCustomSummaryFromDict)
        .def("asDict", &PyDbDatabaseSummaryInfo::asDict)
        .def("className", &PyDbDatabaseSummaryInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbDatabaseSummaryInfo::PyDbDatabaseSummaryInfo(AcDbDatabaseSummaryInfo* ptr)
    : PyRxObject(ptr, true, false)
{
}

std::string PyDbDatabaseSummaryInfo::getTitle() const
{
    AcString str;
    PyThrowBadEs(impObj()->getTitle(str));
    return wstr_to_utf8(str);
}

void PyDbDatabaseSummaryInfo::setTitle(const std::string& title)
{
    PyThrowBadEs(impObj()->setTitle(utf8_to_wstr(title).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getSubject() const
{
    AcString str;
    PyThrowBadEs(impObj()->getSubject(str));
    return wstr_to_utf8(str);
}

void PyDbDatabaseSummaryInfo::setSubject(const std::string& subject)
{
    PyThrowBadEs(impObj()->setSubject(utf8_to_wstr(subject).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getAuthor() const
{
    AcString str;
    PyThrowBadEs(impObj()->getAuthor(str));
    return wstr_to_utf8(str);
}

void PyDbDatabaseSummaryInfo::setAuthor(const std::string& author)
{
    PyThrowBadEs(impObj()->setAuthor(utf8_to_wstr(author).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getKeywords() const
{
    AcString str;
    PyThrowBadEs(impObj()->getKeywords(str));
    return wstr_to_utf8(str);
}

void PyDbDatabaseSummaryInfo::setKeywords(const std::string& keywordlist)
{
    PyThrowBadEs(impObj()->setKeywords(utf8_to_wstr(keywordlist).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getComments() const
{
    AcString str;
    PyThrowBadEs(impObj()->getComments(str));
    return wstr_to_utf8(str);
}

void PyDbDatabaseSummaryInfo::setComments(const std::string& comments)
{
    PyThrowBadEs(impObj()->setComments(utf8_to_wstr(comments).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getLastSavedBy() const
{
    AcString str;
    PyThrowBadEs(impObj()->getLastSavedBy(str));
    return wstr_to_utf8(str);
}

void PyDbDatabaseSummaryInfo::setLastSavedBy(const std::string& lastSavedBy)
{
    PyThrowBadEs(impObj()->setLastSavedBy(utf8_to_wstr(lastSavedBy).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getRevisionNumber() const
{
    AcString str;
    PyThrowBadEs(impObj()->getRevisionNumber(str));
    return wstr_to_utf8(str);
}

void PyDbDatabaseSummaryInfo::setRevisionNumber(const std::string& revisionNumber)
{
    PyThrowBadEs(impObj()->setRevisionNumber(utf8_to_wstr(revisionNumber).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getHyperlinkBase() const
{
    AcString str;
    PyThrowBadEs(impObj()->getHyperlinkBase(str));
    return wstr_to_utf8(str);
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
    AcString value;
    PyThrowBadEs(impObj()->getCustomSummaryInfo(utf8_to_wstr(customInfoKey).c_str(), value));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(customInfoKey, wstr_to_utf8(value));
}

boost::python::tuple PyDbDatabaseSummaryInfo::getCustomSummaryInfo2(int index) const
{
    AcString key;
    AcString value;
    PyThrowBadEs(impObj()->getCustomSummaryInfo(index, key, value));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(wstr_to_utf8(key), wstr_to_utf8(value));
}

void PyDbDatabaseSummaryInfo::setCustomSummaryInfo1(const std::string& customInfoKey, const std::string& value)
{
    PyThrowBadEs(impObj()->setCustomSummaryInfo(utf8_to_wstr(customInfoKey).c_str(), utf8_to_wstr(value).c_str()));
}

void PyDbDatabaseSummaryInfo::setCustomSummaryInfo2(int index, const std::string& key, const std::string& value)
{
    PyThrowBadEs(impObj()->setCustomSummaryInfo(index, utf8_to_wstr(key).c_str(), utf8_to_wstr(value).c_str()));
}

static bool hasKey(AcDbDatabaseSummaryInfo* imp, const TCHAR* key)
{
    AcString dummy;
    return imp->getCustomSummaryInfo(key, dummy) == eOk;
}

void PyDbDatabaseSummaryInfo::setCustomSummaryFromDict(boost::python::dict& pydict)
{
    PyAutoLockGIL lock;
    boost::python::list keys = boost::python::list(pydict.keys());
    for (int i = 0; i < len(keys); ++i)
    {
        boost::python::extract<std::string> keyExtractor(keys[i]);
        if (keyExtractor.check())
        {
            std::string key = keyExtractor();
            boost::python::extract<std::string> valExtractor(pydict[key]);
            std::string val = valExtractor();
            if (hasKey(impObj(), utf8_to_wstr(key).c_str()))
                setCustomSummaryInfo1(key, val);
            else
                addCustomSummaryInfo(key, val);
        }
    }
}

boost::python::dict PyDbDatabaseSummaryInfo::asDict() const
{
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
}

std::string PyDbDatabaseSummaryInfo::className()
{
    return "AcDbDatabaseSummaryInfo";
}

AcDbDatabaseSummaryInfo* PyDbDatabaseSummaryInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDatabaseSummaryInfo*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbPlotSettingsValidator
void makePyDbPlotSettingsValidatorWrapper()
{
    PyDocString DS("PlotSettingsValidator");
    class_<PyDbPlotSettingsValidator>("PlotSettingsValidator")
        .def("setPlotCfgName", &PyDbPlotSettingsValidator::setPlotCfgName1)
        .def("setPlotCfgName", &PyDbPlotSettingsValidator::setPlotCfgName2)
        .def("setCanonicalMediaName", &PyDbPlotSettingsValidator::setCanonicalMediaName)
        .def("setPlotOrigin", &PyDbPlotSettingsValidator::setPlotOrigin)
        .def("setPlotPaperUnits", &PyDbPlotSettingsValidator::setPlotPaperUnits)
        .def("setPlotRotation", &PyDbPlotSettingsValidator::setPlotRotation)
        .def("setPlotCentered", &PyDbPlotSettingsValidator::setPlotCentered)
        .def("setPlotType", &PyDbPlotSettingsValidator::setPlotType)
        .def("setPlotWindowArea", &PyDbPlotSettingsValidator::setPlotWindowArea1)
        .def("setPlotWindowArea", &PyDbPlotSettingsValidator::setPlotWindowArea2)
        .def("setPlotViewName", &PyDbPlotSettingsValidator::setPlotViewName)
        .def("setUseStandardScale", &PyDbPlotSettingsValidator::setUseStandardScale)
        .def("setCustomPrintScale", &PyDbPlotSettingsValidator::setCustomPrintScale)
        .def("setCurrentStyleSheet", &PyDbPlotSettingsValidator::setCurrentStyleSheet)
        .def("setStdScaleType", &PyDbPlotSettingsValidator::setStdScaleType)
        .def("setStdScale", &PyDbPlotSettingsValidator::setStdScale)
        .def("plotDeviceList", &PyDbPlotSettingsValidator::plotDeviceList)
        .def("canonicalMediaNameList", &PyDbPlotSettingsValidator::canonicalMediaNameList)
        .def("getLocaleMediaName", &PyDbPlotSettingsValidator::getLocaleMediaName1)
        .def("getLocaleMediaName", &PyDbPlotSettingsValidator::getLocaleMediaName2)
        .def("setClosestMediaName", &PyDbPlotSettingsValidator::setClosestMediaName)
        .def("plotStyleSheetList", &PyDbPlotSettingsValidator::plotStyleSheetList)
        .def("setZoomToPaperOnUpdate", &PyDbPlotSettingsValidator::setZoomToPaperOnUpdate)
        .def("setDefaultPlotConfig", &PyDbPlotSettingsValidator::setDefaultPlotConfig)
        .def("className", &PyDbPlotSettingsValidator::className, DS.SARGS()).staticmethod("className")
        ;
}

void PyDbPlotSettingsValidator::setPlotCfgName1(PyDbPlotSettings& settings, const std::string& plotDeviceName)
{
    PyThrowBadEs(impObj()->setPlotCfgName(settings.impObj(), utf8_to_wstr(plotDeviceName).c_str()));
}

void PyDbPlotSettingsValidator::setPlotCfgName2(PyDbPlotSettings& settings, const std::string& plotDeviceName, const std::string& mediaName)
{
    PyThrowBadEs(impObj()->setPlotCfgName(settings.impObj(), utf8_to_wstr(plotDeviceName).c_str(), utf8_to_wstr(mediaName).c_str()));
}

void PyDbPlotSettingsValidator::setCanonicalMediaName(PyDbPlotSettings& settings, const std::string& mediaName)
{
    PyThrowBadEs(impObj()->setCanonicalMediaName(settings.impObj(), utf8_to_wstr(mediaName).c_str()));
}

void PyDbPlotSettingsValidator::setPlotOrigin(PyDbPlotSettings& settings, const double xCoordinate, const double yCoordinate)
{
    PyThrowBadEs(impObj()->setPlotOrigin(settings.impObj(), xCoordinate, yCoordinate));
}

void PyDbPlotSettingsValidator::setPlotPaperUnits(PyDbPlotSettings& pPlotSet, const PlotPaperUnits units)
{
    PyThrowBadEs(impObj()->setPlotPaperUnits(pPlotSet.impObj(), units));
}

void PyDbPlotSettingsValidator::setPlotRotation(PyDbPlotSettings& pPlotSet, const PlotRotation rotationType)
{
    PyThrowBadEs(impObj()->setPlotRotation(pPlotSet.impObj(), rotationType));
}

void PyDbPlotSettingsValidator::setPlotCentered(PyDbPlotSettings& pPlotSet, Adesk::Boolean isCentered)
{
    PyThrowBadEs(impObj()->setPlotCentered(pPlotSet.impObj(), isCentered));
}

void PyDbPlotSettingsValidator::setPlotType(PyDbPlotSettings& pPlotSet, const PlotType plotAreaType)
{
    PyThrowBadEs(impObj()->setPlotType(pPlotSet.impObj(), plotAreaType));
}

void PyDbPlotSettingsValidator::setPlotWindowArea1(PyDbPlotSettings& pPlotSet, const double xmin, const double ymin, const double xmax, const double ymax)
{
    PyThrowBadEs(impObj()->setPlotWindowArea(pPlotSet.impObj(), xmin, ymin, xmax, ymax));
}

void PyDbPlotSettingsValidator::setPlotWindowArea2(PyDbPlotSettings& pPlotSet, AcDbExtents2d& ex)
{
    PyThrowBadEs(impObj()->setPlotWindowArea(pPlotSet.impObj(), ex.minPoint().x, ex.minPoint().y, ex.maxPoint().x, ex.maxPoint().y));
}

void PyDbPlotSettingsValidator::setPlotViewName(PyDbPlotSettings& pPlotSet, const std::string& viewName)
{
    PyThrowBadEs(impObj()->setPlotViewName(pPlotSet.impObj(), utf8_to_wstr(viewName).c_str()));
}

void PyDbPlotSettingsValidator::setUseStandardScale(PyDbPlotSettings& pPlotSet, Adesk::Boolean useStandard)
{
    PyThrowBadEs(impObj()->setUseStandardScale(pPlotSet.impObj(), useStandard));
}

void PyDbPlotSettingsValidator::setCustomPrintScale(PyDbPlotSettings& pPlotSet, const double numerator, const double denominator)
{
    PyThrowBadEs(impObj()->setCustomPrintScale(pPlotSet.impObj(), numerator, denominator));
}

void PyDbPlotSettingsValidator::setCurrentStyleSheet(PyDbPlotSettings& pPlotSet, const std::string& styleSheetName)
{
    PyThrowBadEs(impObj()->setCurrentStyleSheet(pPlotSet.impObj(), utf8_to_wstr(styleSheetName).c_str()));
}

void PyDbPlotSettingsValidator::setStdScaleType(PyDbPlotSettings& pPlotSet, const StdScaleType scaleType)
{
    PyThrowBadEs(impObj()->setStdScaleType(pPlotSet.impObj(), scaleType));
}

void PyDbPlotSettingsValidator::setStdScale(PyDbPlotSettings& pPlotSet, const double standardScale)
{
    PyThrowBadEs(impObj()->setStdScale(pPlotSet.impObj(), standardScale));
}

boost::python::list PyDbPlotSettingsValidator::plotDeviceList()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcArray<const ACHAR*> deviceList;
    PyThrowBadEs(impObj()->plotDeviceList(deviceList));
    for (const auto& chrs : deviceList)
        pylist.append(wstr_to_utf8(chrs));
    return pylist;
}

boost::python::list PyDbPlotSettingsValidator::canonicalMediaNameList(PyDbPlotSettings& pPlotSet)
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcArray<const ACHAR*> mediaList;
    PyThrowBadEs(impObj()->canonicalMediaNameList(pPlotSet.impObj(), mediaList));
    for (const auto& chrs : mediaList)
        pylist.append(wstr_to_utf8(chrs));
    return pylist;
}

std::string PyDbPlotSettingsValidator::getLocaleMediaName1(PyDbPlotSettings& pPlotSet, const std::string& canonicalName)
{
    const ACHAR* localeName = nullptr;
    PyThrowBadEs(impObj()->getLocaleMediaName(pPlotSet.impObj(), utf8_to_wstr(canonicalName).c_str(), localeName));
    return wstr_to_utf8(localeName);
}

std::string PyDbPlotSettingsValidator::getLocaleMediaName2(PyDbPlotSettings& pPlotSet, int index)
{
    const ACHAR* localeName = nullptr;
    PyThrowBadEs(impObj()->getLocaleMediaName(pPlotSet.impObj(), index, localeName));
    return wstr_to_utf8(localeName);
}

void PyDbPlotSettingsValidator::setClosestMediaName(PyDbPlotSettings& pPlotSet, double paperWidth, double paperHeight, PlotPaperUnits units, Adesk::Boolean matchPrintableArea)
{
    PyThrowBadEs(impObj()->setClosestMediaName(pPlotSet.impObj(), paperWidth, paperHeight, units, matchPrintableArea));
}

boost::python::list PyDbPlotSettingsValidator::plotStyleSheetList()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcArray<const ACHAR*> styleList;
    PyThrowBadEs(impObj()->plotStyleSheetList(styleList));
    for (const auto& chrs : styleList)
        pylist.append(wstr_to_utf8(chrs));
    return pylist;
}

void PyDbPlotSettingsValidator::refreshLists(PyDbPlotSettings& pPlotSet)
{
    impObj()->refreshLists(pPlotSet.impObj());
}

void PyDbPlotSettingsValidator::setZoomToPaperOnUpdate(PyDbPlotSettings& pPlotSet, Adesk::Boolean doZoom)
{
    impObj()->setZoomToPaperOnUpdate(pPlotSet.impObj(), doZoom);
}

void PyDbPlotSettingsValidator::setDefaultPlotConfig(PyDbPlotSettings& pPlotSet)
{
    impObj()->setDefaultPlotConfig(pPlotSet.impObj());
}

std::string PyDbPlotSettingsValidator::className()
{
    return "AcDbPlotSettingsValidator";
}

AcDbPlotSettingsValidator* PyDbPlotSettingsValidator::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_impl == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return m_impl;
}
