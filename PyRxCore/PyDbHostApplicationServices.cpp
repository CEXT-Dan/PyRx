#include "stdafx.h"
#include "PyDbHostApplicationServices.h"
#include "PyDbDatabase.h"
#include "PyDbLayout.h"
#include "PyDbObjectId.h"

using namespace boost::python;


//---------------------------------------------------------------------------------------- -
//OutputDisplayServiceImpl
OutputDisplayServiceImpl::OutputDisplayServiceImpl()
{
    ms_buffer.clear();
#if !defined(_BRXTARGET250)
    PyThrowBadEs(acdbSetHostApplicationServices(this));
    setWorkingGlobals(m_pOldHostServices->workingGlobals());
    setWorkingDatabase(m_pOldHostServices->workingDatabase());
#endif
}

OutputDisplayServiceImpl::~OutputDisplayServiceImpl()
{
    ms_buffer.clear();
#if !defined(_BRXTARGET250)
    acdbSetHostApplicationServices(m_pOldHostServices);
    setWorkingGlobals(m_pOldHostServices->workingGlobals());
    setWorkingDatabase(m_pOldHostServices->workingDatabase());
#endif
}

Acad::ErrorStatus OutputDisplayServiceImpl::findFile(ACHAR* pthOut, int nBufLength, const ACHAR* pcFname, AcDbDatabase* pDb /*= NULL*/, AcDbHostApplicationServices::FindFileHint hint /*= kDefault*/)
{
    return Acad::ErrorStatus::eNotImplemented;
}

#if !defined(_BRXTARGET250)
AcadInternalServices* OutputDisplayServiceImpl::acadInternalServices()
{
    return m_pOldHostServices->acadInternalServices();
}
#endif

const ProdIdCode OutputDisplayServiceImpl::prodcode()
{
    return m_pOldHostServices->prodcode();
}

void OutputDisplayServiceImpl::displayChar(ACHAR c) const
{
    if (c != 0)
    {
        CString tmp;
        tmp.Format(L"%c", c);
        ms_buffer += (const TCHAR*)tmp;
        if (!m_muteCmdLine)
            m_pOldHostServices->displayChar(c);
    }
}

void OutputDisplayServiceImpl::displayString(const ACHAR* string, int count) const
{
    CString tmp(string);
    ms_buffer += (const TCHAR*)tmp.Left(count);
    if (!m_muteCmdLine)
        m_pOldHostServices->displayString(string, count);
}

std::wstring OutputDisplayServiceImpl::getOutput() const
{
    return ms_buffer;
}


//---------------------------------------------------------------------------------------- -
//PyOutputDisplayService
void makePyOutputDisplayServiceWrapper()
{
    PyDocString DS("PyDb.OutputDisplayService");
    class_<PyOutputDisplayService>("OutputDisplayService")
        .def(init<>(DS.ARGS()))
        .def("getMuteCmdLine", &PyOutputDisplayService::getMuteCmdLine, DS.ARGS())
        .def("setMuteCmdLine", &PyOutputDisplayService::setMuteCmdLine, DS.ARGS({ "forward:bool" }))
        .def("output", &PyOutputDisplayService::output, DS.ARGS())
        .def("className", &PyOutputDisplayService::className, DS.SARGS()).staticmethod("className")
        ;
}

PyOutputDisplayService::PyOutputDisplayService()
    : m_pyImp(std::make_unique<OutputDisplayServiceImpl>())
{
}

std::string PyOutputDisplayService::output() const
{
    return wstr_to_utf8(impObj()->getOutput());
}

bool PyOutputDisplayService::getMuteCmdLine() const
{
    return impObj()->getMuteCmdLine();
}

void PyOutputDisplayService::setMuteCmdLine(bool val) const
{
    impObj()->setMuteCmdLine(val);
}

std::string PyOutputDisplayService::className()
{
    return "OutputDisplayService";
}

OutputDisplayServiceImpl* PyOutputDisplayService::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//---------------------------------------------------------------------------------------- -
//PyDbHostApplicationServices
void makePyDbHostApplicationServicesWrapper()
{
    constexpr const std::string_view findFileOverloads = "Overloads:\n"
        "- fileName: str\n"
        "- fileName: str, db: PyDb.Database\n"
        "- fileName: str, db: PyDb.Database, hint: PyDb.FindFileHint\n";

    PyDocString DS("HostApplicationServices");
    class_<PyDbHostApplicationServices>("HostApplicationServices")
        .def(init<>(DS.ARGS()))
        .def("workingDatabase", &PyDbHostApplicationServices::workingDatabase, DS.ARGS(5517))
        .def("setWorkingDatabase", &PyDbHostApplicationServices::setWorkingDatabase, DS.ARGS({ "val : PyDb.Database" }, 5506))
        .def("findFile", &PyDbHostApplicationServices::findFile1)
        .def("findFile", &PyDbHostApplicationServices::findFile2)
        .def("findFile", &PyDbHostApplicationServices::findFile3, DS.OVRL(findFileOverloads, 5442))
        .def("product", &PyDbHostApplicationServices::product, DS.ARGS(5486))
        .def("program", &PyDbHostApplicationServices::program, DS.ARGS(5487))
        .def("companyName", &PyDbHostApplicationServices::companyName, DS.ARGS(5433))
        .def("releaseMajorMinorString", &PyDbHostApplicationServices::releaseMajorMinorString, DS.ARGS(5493))
        .def("versionString", &PyDbHostApplicationServices::versionString, DS.ARGS(5515))
        .def("getMachineRegistryProductRootKey", &PyDbHostApplicationServices::getMachineRegistryProductRootKey, DS.ARGS(5453))
        .def("getUserRegistryProductRootKey", &PyDbHostApplicationServices::getUserRegistryProductRootKey, DS.ARGS(5466))
        .def("releaseMarketVersion", &PyDbHostApplicationServices::releaseMarketVersion, DS.ARGS(5495))
        .def("LayoutManager", &PyDbHostApplicationServices::dbLayoutManager, DS.ARGS(5470))
        .def("plotSettingsValidator", &PyDbHostApplicationServices::plotSettingsValidator, DS.ARGS())
        .def("createOutputCapture", &PyDbHostApplicationServices::createOutputCapture, DS.SARGS()).staticmethod("createOutputCapture")
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

std::string PyDbHostApplicationServices::getRoamableRootFolder()
{
    const TCHAR* val = nullptr;
    PyThrowBadEs(pDbHostApp->getRoamableRootFolder(val));
    return wstr_to_utf8(val);
}

std::string PyDbHostApplicationServices::getLocalRootFolder()
{
    const TCHAR* val = nullptr;
    PyThrowBadEs(pDbHostApp->getLocalRootFolder(val));
    return wstr_to_utf8(val);
}

std::string PyDbHostApplicationServices::getAllUsersRootFolder()
{
    const TCHAR* val = nullptr;
    PyThrowBadEs(pDbHostApp->getAllUsersRootFolder(val));
    return wstr_to_utf8(val);
}

int PyDbHostApplicationServices::releaseMajorVersion()
{
    return pDbHostApp->releaseMajorVersion();
}

int PyDbHostApplicationServices::releaseMinorVersion()
{
    return pDbHostApp->releaseMinorVersion();
}

std::string PyDbHostApplicationServices::product() const
{
    return  wstr_to_utf8(pDbHostApp->product());
}

std::string PyDbHostApplicationServices::program()
{
    return  wstr_to_utf8(pDbHostApp->program());
}

std::string PyDbHostApplicationServices::companyName()
{
    return  wstr_to_utf8(pDbHostApp->companyName());
}

std::string PyDbHostApplicationServices::releaseMajorMinorString()
{
    return  wstr_to_utf8(pDbHostApp->releaseMajorMinorString());
}

std::string PyDbHostApplicationServices::versionString()
{
    return  wstr_to_utf8(pDbHostApp->versionString());
}

std::string PyDbHostApplicationServices::getMachineRegistryProductRootKey()
{
    return  wstr_to_utf8(pDbHostApp->getMachineRegistryProductRootKey());
}

std::string PyDbHostApplicationServices::getUserRegistryProductRootKey()
{
    return  wstr_to_utf8(pDbHostApp->getUserRegistryProductRootKey());
}

std::string PyDbHostApplicationServices::releaseMarketVersion()
{
    return  wstr_to_utf8(pDbHostApp->getUserRegistryProductRootKey());
}

PyDbPlotSettingsValidator PyDbHostApplicationServices::plotSettingsValidator()
{
    return PyDbPlotSettingsValidator{ pDbHostApp->plotSettingsValidator() };
}

PyDbLayoutManager PyDbHostApplicationServices::dbLayoutManager()
{
    return PyDbLayoutManager(pDbHostApp->layoutManager(), false);
}

PyOutputDisplayService PyDbHostApplicationServices::createOutputCapture()
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyOutputDisplayService{};
#endif
}

//---------------------------------------------------------------------------------------- -
//makePyAutoWorkingDatabase
void makePyAutoWorkingDatabase()
{
    PyDocString DS("AutoWorkingDatabase");
    class_<PyAutoWorkingDatabase>("AutoWorkingDatabase", no_init)
        .def(init<const PyDbDatabase&>(DS.ARGS({ "db: PyDb.Database" })))
        .def("wdb", &PyAutoWorkingDatabase::wdb, DS.ARGS())
        ;
}

PyAutoWorkingDatabase::PyAutoWorkingDatabase(const PyDbDatabase& db)
    : m_pyImp(new AutoWorkingDatabase(db.impObj()))
{
}

PyDbDatabase PyAutoWorkingDatabase::wdb()
{
    return PyDbDatabase(acdbHostApplicationServices()->workingDatabase(), false);
}

//---------------------------------------------------------------------------------------- -
//PyDbSymUtilServices
void makePyDbSymUtilServicesWrapper()
{
    PyDocString DS("SymUtilServices");
    class_<PyDbSymUtilServices>("SymUtilServices")
        .def(init<>(DS.ARGS()))
        .def("isBlockLayoutName", &PyDbSymUtilServices::isBlockLayoutName, DS.ARGS({ "val: str" }))
        .def("isBlockModelSpaceName", &PyDbSymUtilServices::isBlockModelSpaceName, DS.ARGS({ "val: str" }))
        .def("isBlockPaperSpaceName", &PyDbSymUtilServices::isBlockPaperSpaceName, DS.ARGS({ "val: str" }))
        .def("isLayerDefpointsName", &PyDbSymUtilServices::isLayerDefpointsName, DS.ARGS({ "val: str" }))
        .def("isLayerZeroName", &PyDbSymUtilServices::isLayerZeroName, DS.ARGS({ "val: str" }))
        .def("isLinetypeByBlockName", &PyDbSymUtilServices::isLinetypeByBlockName, DS.ARGS({ "val: str" }))
        .def("isLinetypeByLayerName", &PyDbSymUtilServices::isLinetypeByLayerName, DS.ARGS({ "val: str" }))
        .def("isLinetypeContinuousName", &PyDbSymUtilServices::isLinetypeContinuousName, DS.ARGS({ "val: str" }))
        .def("isRegAppAcadName", &PyDbSymUtilServices::isRegAppAcadName, DS.ARGS({ "val: str" }))
        .def("isTextStyleStandardName", &PyDbSymUtilServices::isTextStyleStandardName, DS.ARGS({ "val: str" }))
        .def("isViewportActiveName", &PyDbSymUtilServices::isViewportActiveName, DS.ARGS({ "val: str" }))
        .def("blockModelSpaceId", &PyDbSymUtilServices::blockModelSpaceId, DS.ARGS({ "db: PyDb.Database" }))
        .def("blockPaperSpaceId", &PyDbSymUtilServices::blockPaperSpaceId, DS.ARGS({ "db: PyDb.Database" }))
        .def("layerDefpointsId", &PyDbSymUtilServices::layerDefpointsId, DS.ARGS({ "db: PyDb.Database" }))
        .def("layerZeroId", &PyDbSymUtilServices::layerZeroId, DS.ARGS({ "db: PyDb.Database" }))
        .def("linetypeByBlockId", &PyDbSymUtilServices::linetypeByBlockId, DS.ARGS({ "db: PyDb.Database" }))
        .def("linetypeByLayerId", &PyDbSymUtilServices::linetypeByLayerId, DS.ARGS({ "db: PyDb.Database" }))
        .def("linetypeContinuousId", &PyDbSymUtilServices::linetypeContinuousId, DS.ARGS({ "db: PyDb.Database" }))
        .def("regAppAcadId", &PyDbSymUtilServices::regAppAcadId, DS.ARGS({ "db: PyDb.Database" }))
        .def("textStyleStandardId", &PyDbSymUtilServices::textStyleStandardId, DS.ARGS({ "db: PyDb.Database" }))
        .def("blockModelSpaceName", &PyDbSymUtilServices::blockModelSpaceName, DS.ARGS())
        .def("blockPaperSpaceName", &PyDbSymUtilServices::blockPaperSpaceName, DS.ARGS())
        .def("layerDefpointsName", &PyDbSymUtilServices::layerDefpointsName, DS.ARGS())
        .def("layerZeroName", &PyDbSymUtilServices::layerZeroName, DS.ARGS())
        .def("linetypeByBlockName", &PyDbSymUtilServices::linetypeByBlockName, DS.ARGS())
        .def("linetypeByLayerName", &PyDbSymUtilServices::linetypeByLayerName, DS.ARGS())
        .def("linetypeContinuousName", &PyDbSymUtilServices::linetypeContinuousName, DS.ARGS())
        .def("regAppAcadName", &PyDbSymUtilServices::regAppAcadName, DS.ARGS())
        .def("textStyleStandardName", &PyDbSymUtilServices::textStyleStandardName, DS.ARGS())
        .def("viewportActiveName", &PyDbSymUtilServices::viewportActiveName, DS.ARGS())
        .def("compareSymbolName", &PyDbSymUtilServices::compareSymbolName, DS.ARGS({ "thisName: str","otherName: str" }))
        .def("hasVerticalBar", &PyDbSymUtilServices::hasVerticalBar, DS.ARGS({ "val: str" }))
        .def("makeDependentName", &PyDbSymUtilServices::makeDependentName, DS.ARGS({ "dwgname: str","symbolName: str" }))
        .def("repairPreExtendedSymbolName", &PyDbSymUtilServices::repairPreExtendedSymbolName, DS.ARGS({ "oldname: str","allowVerticalBar: bool" }))
        .def("repairSymbolName", &PyDbSymUtilServices::repairSymbolName, DS.ARGS({ "oldname: str","allowVerticalBar: bool" }))
        .def("validatePreExtendedSymbolName", &PyDbSymUtilServices::validatePreExtendedSymbolName, DS.ARGS({ "oldname: str","allowVerticalBar: bool" }))
        .def("validateSymbolName", &PyDbSymUtilServices::validateSymbolName, DS.ARGS({ "name: str","allowVerticalBar: bool" }))
        .def("compatibilityMode", &PyDbSymUtilServices::compatibilityMode, DS.ARGS({ "db: PyDb.Database" }))
        .def("getBlockNameFromInsertPathName", &PyDbSymUtilServices::getBlockNameFromInsertPathName, DS.ARGS({ "pathname: str" }))
        .def("getInsertPathNameFromBlockName", &PyDbSymUtilServices::getInsertPathNameFromBlockName, DS.ARGS({ "pathname: str" }))
        .def("getPathNameFromSymbolName", &PyDbSymUtilServices::getPathNameFromSymbolName, DS.ARGS({ "symname: str","extensions: str" }))
        .def("getSymbolNameFromPathName", &PyDbSymUtilServices::getSymbolNameFromPathName, DS.ARGS({ "symname: str","extensions: str" }))
        .def("validateCompatibleSymbolName", &PyDbSymUtilServices::validateCompatibleSymbolName, DS.ARGS({ "name: str","isNewName: bool","allowVerticalBar: bool","compatibilityMode: bool" }))
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
#if defined(_GRXTARGET250) || defined(_BRXTARGET250)
    if (thisName == otherName)
        return 0;
    else if (thisName > otherName)
        return 1;
    else
        return -1;
#endif
    return imp->compareSymbolName(utf8_to_wstr(thisName).c_str(), utf8_to_wstr(otherName).c_str());
}

bool PyDbSymUtilServices::hasVerticalBar(const std::string& name) const
{
#if defined(_GRXTARGET250) || defined(_BRXTARGET250)
    return name.find('|') != std::string::npos;
#endif
    return imp->hasVerticalBar(utf8_to_wstr(name).c_str());
}

std::string PyDbSymUtilServices::makeDependentName(const std::string& dwgName, const std::string& symbolName) const
{
#if defined(_ARXTARGET) && (_ARXTARGET >= 250) || (_GRXTARGET == 260)
    AcString pNewName;
    PyThrowBadEs(imp->makeDependentName(pNewName, utf8_to_wstr(dwgName).c_str(), utf8_to_wstr(symbolName).c_str()));
    std::string val = wstr_to_utf8(pNewName);
#else
    ACHAR* pNewName = nullptr;
    PyThrowBadEs(imp->makeDependentName(pNewName, utf8_to_wstr(dwgName).c_str(), utf8_to_wstr(symbolName).c_str()));
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
#endif
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
#if defined(_ARXTARGET) && (_ARXTARGET >= 250) || (_GRXTARGET == 260) 
    AcString pNewName;
    PyThrowBadEs(imp->getInsertPathNameFromBlockName(pNewName, utf8_to_wstr(pathName).c_str()));
    std::string val = wstr_to_utf8(pNewName);
#else
    ACHAR* pNewName = nullptr;
    PyThrowBadEs(imp->getInsertPathNameFromBlockName(pNewName, utf8_to_wstr(pathName).c_str()));
    std::string val = wstr_to_utf8(pNewName);
    acutDelString(pNewName);
#endif
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
    constexpr const std::string_view deleteCustomSummaryInfoOverloads = "Overloads:\n"
        "- index: int\n"
        "- key: str\n";

    constexpr const std::string_view getCustomSummaryInfoOverloads = "Overloads:\n"
        "- index: int\n"
        "- key: str\n";

    constexpr const std::string_view setCustomSummaryInfoOverloads = "Overloads:\n"
        "- customInfoKey: str, value: str\n"
        "- index: int, key: str, value: str\n";

    PyDocString DS("DatabaseSummaryInfo");
    class_<PyDbDatabaseSummaryInfo, bases<PyRxObject>>("DatabaseSummaryInfo", boost::python::no_init)
        .def("getTitle", &PyDbDatabaseSummaryInfo::getTitle, DS.ARGS())
        .def("setTitle", &PyDbDatabaseSummaryInfo::setTitle, DS.ARGS({ "val: str" }))
        .def("getSubject", &PyDbDatabaseSummaryInfo::getSubject, DS.ARGS())
        .def("setSubject", &PyDbDatabaseSummaryInfo::setSubject, DS.ARGS({ "val: str" }))
        .def("getAuthor", &PyDbDatabaseSummaryInfo::getAuthor, DS.ARGS())
        .def("setAuthor", &PyDbDatabaseSummaryInfo::setAuthor, DS.ARGS({ "val: str" }))
        .def("getKeywords", &PyDbDatabaseSummaryInfo::getKeywords, DS.ARGS())
        .def("setKeywords", &PyDbDatabaseSummaryInfo::setKeywords, DS.ARGS({ "keywordlist: str" }))
        .def("getComments", &PyDbDatabaseSummaryInfo::getComments, DS.ARGS())
        .def("setComments", &PyDbDatabaseSummaryInfo::setComments, DS.ARGS({ "val: str" }))
        .def("getLastSavedBy", &PyDbDatabaseSummaryInfo::getLastSavedBy, DS.ARGS())
        .def("setLastSavedBy", &PyDbDatabaseSummaryInfo::setLastSavedBy, DS.ARGS({ "val: str" }))
        .def("getRevisionNumber", &PyDbDatabaseSummaryInfo::getRevisionNumber, DS.ARGS())
        .def("setRevisionNumber", &PyDbDatabaseSummaryInfo::setRevisionNumber, DS.ARGS({ "val: str" }))
        .def("getHyperlinkBase", &PyDbDatabaseSummaryInfo::getHyperlinkBase, DS.ARGS())
        .def("setHyperlinkBase", &PyDbDatabaseSummaryInfo::setHyperlinkBase, DS.ARGS({ "val: str" }))
        .def("numCustomInfo", &PyDbDatabaseSummaryInfo::numCustomInfo, DS.ARGS())
        .def("addCustomSummaryInfo", &PyDbDatabaseSummaryInfo::addCustomSummaryInfo, DS.ARGS({ "key: str","val: str" }))
        .def("deleteCustomSummaryInfo", &PyDbDatabaseSummaryInfo::deleteCustomSummaryInfo1)
        .def("deleteCustomSummaryInfo", &PyDbDatabaseSummaryInfo::deleteCustomSummaryInfo2, DS.OVRL(deleteCustomSummaryInfoOverloads))
        .def("getCustomSummaryInfo", &PyDbDatabaseSummaryInfo::getCustomSummaryInfo1)
        .def("getCustomSummaryInfo", &PyDbDatabaseSummaryInfo::getCustomSummaryInfo2, DS.OVRL(getCustomSummaryInfoOverloads))
        .def("setCustomSummaryInfo", &PyDbDatabaseSummaryInfo::setCustomSummaryInfo1)
        .def("setCustomSummaryInfo", &PyDbDatabaseSummaryInfo::setCustomSummaryInfo2, DS.OVRL(setCustomSummaryInfoOverloads))
        .def("setCustomSummaryFromDict", &PyDbDatabaseSummaryInfo::setCustomSummaryFromDict, DS.ARGS({ "keyValues: dict" }))
        .def("asDict", &PyDbDatabaseSummaryInfo::asDict, DS.ARGS())
        .def("__getitem__", &PyDbDatabaseSummaryInfo::getCustomSummaryInfo2, DS.ARGS({ "index: int" }))
        .def("className", &PyDbDatabaseSummaryInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbDatabaseSummaryInfo::PyDbDatabaseSummaryInfo(AcDbDatabaseSummaryInfo* ptr)
    : PyRxObject(ptr, true, false)
{
}

std::string PyDbDatabaseSummaryInfo::getTitle() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getTitle(str.buf));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(impObj()->getTitle(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setTitle(const std::string& title) const
{
    PyThrowBadEs(impObj()->setTitle(utf8_to_wstr(title).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getSubject() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getSubject(str.buf));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(impObj()->getSubject(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setSubject(const std::string& subject) const
{
    PyThrowBadEs(impObj()->setSubject(utf8_to_wstr(subject).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getAuthor() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getAuthor(str.buf));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(impObj()->getAuthor(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setAuthor(const std::string& author) const
{
    PyThrowBadEs(impObj()->setAuthor(utf8_to_wstr(author).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getKeywords() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getKeywords(str.buf));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(impObj()->getKeywords(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setKeywords(const std::string& keywordlist) const
{
    PyThrowBadEs(impObj()->setKeywords(utf8_to_wstr(keywordlist).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getComments() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getComments(str.buf));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(impObj()->getComments(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setComments(const std::string& comments) const
{
    PyThrowBadEs(impObj()->setComments(utf8_to_wstr(comments).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getLastSavedBy() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getLastSavedBy(str.buf));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(impObj()->getLastSavedBy(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setLastSavedBy(const std::string& lastSavedBy) const
{
    PyThrowBadEs(impObj()->setLastSavedBy(utf8_to_wstr(lastSavedBy).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getRevisionNumber() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getRevisionNumber(str.buf));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(impObj()->getRevisionNumber(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setRevisionNumber(const std::string& revisionNumber) const
{
    PyThrowBadEs(impObj()->setRevisionNumber(utf8_to_wstr(revisionNumber).c_str()));
}

std::string PyDbDatabaseSummaryInfo::getHyperlinkBase() const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(impObj()->getHyperlinkBase(str.buf));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(impObj()->getHyperlinkBase(str));
    return wstr_to_utf8(str);
#endif
}

void PyDbDatabaseSummaryInfo::setHyperlinkBase(const std::string& HyperlinkBase) const
{
    PyThrowBadEs(impObj()->setHyperlinkBase(utf8_to_wstr(HyperlinkBase).c_str()));
}

int PyDbDatabaseSummaryInfo::numCustomInfo() const
{
    return impObj()->numCustomInfo();
}

void PyDbDatabaseSummaryInfo::addCustomSummaryInfo(const std::string& key, const std::string& value) const
{
    PyThrowBadEs(impObj()->addCustomSummaryInfo(utf8_to_wstr(key).c_str(), utf8_to_wstr(value).c_str()));
}

void PyDbDatabaseSummaryInfo::deleteCustomSummaryInfo1(int index) const
{
    PyThrowBadEs(impObj()->deleteCustomSummaryInfo(index));
}

void PyDbDatabaseSummaryInfo::deleteCustomSummaryInfo2(const std::string& key) const
{
    PyThrowBadEs(impObj()->deleteCustomSummaryInfo(utf8_to_wstr(key).c_str()));
}

boost::python::tuple PyDbDatabaseSummaryInfo::getCustomSummaryInfo1(const std::string& customInfoKey) const
{
#if defined(_BRXTARGET250)
    RxAutoOutStr value;
    PyThrowBadEs(impObj()->getCustomSummaryInfo(utf8_to_wstr(customInfoKey).c_str(), value.buf));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(customInfoKey, wstr_to_utf8(value.buf));
#else
    AcString value;
    PyThrowBadEs(impObj()->getCustomSummaryInfo(utf8_to_wstr(customInfoKey).c_str(), value));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(customInfoKey, wstr_to_utf8(value));
#endif
}

boost::python::tuple PyDbDatabaseSummaryInfo::getCustomSummaryInfo2(int index) const
{
    if (index >= numCustomInfo())
        throw std::out_of_range{ "IndexError " };
#if defined(_BRXTARGET250)
    RxAutoOutStr key;
    RxAutoOutStr value;
    PyThrowBadEs(impObj()->getCustomSummaryInfo(index, key.buf, value.buf));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(wstr_to_utf8(key.buf), wstr_to_utf8(value.buf));
#else
    AcString key;
    AcString value;
    PyThrowBadEs(impObj()->getCustomSummaryInfo(index, key, value));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(wstr_to_utf8(key), wstr_to_utf8(value));
#endif
}

void PyDbDatabaseSummaryInfo::setCustomSummaryInfo1(const std::string& customInfoKey, const std::string& value) const
{
    PyThrowBadEs(impObj()->setCustomSummaryInfo(utf8_to_wstr(customInfoKey).c_str(), utf8_to_wstr(value).c_str()));
}

void PyDbDatabaseSummaryInfo::setCustomSummaryInfo2(int index, const std::string& key, const std::string& value) const
{
    PyThrowBadEs(impObj()->setCustomSummaryInfo(index, utf8_to_wstr(key).c_str(), utf8_to_wstr(value).c_str()));
}

static bool hasKey(AcDbDatabaseSummaryInfo* imp, const TCHAR* key)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr dummy;
    return imp->getCustomSummaryInfo(key, dummy.buf) == eOk;
#else
    AcString dummy;
    return imp->getCustomSummaryInfo(key, dummy) == eOk;
#endif
}

void PyDbDatabaseSummaryInfo::setCustomSummaryFromDict(boost::python::dict& pydict) const
{
    PyAutoLockGIL lock;
    boost::python::list keys = boost::python::list(pydict.keys());
    for (int i = 0; i < len(keys); ++i)
    {
        boost::python::extract<std::string> keyExtractor(keys[i]);
        if (keyExtractor.check())
        {
            const std::string& key = keyExtractor();
            boost::python::extract<std::string> valExtractor(pydict[key]);
            const std::string& val = valExtractor();
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
#if defined(_BRXTARGET250)
        RxAutoOutStr key;
        RxAutoOutStr value;
        if (impObj()->getCustomSummaryInfo(idx, key.buf, value.buf) == eOk)
        {
            std::string sdtkey = wstr_to_utf8(key.buf);
            std::string stdvalue = wstr_to_utf8(value.buf);
            sinfoDict[sdtkey] = stdvalue;
        }
#else
        AcString key;
        AcString value;
        if (impObj()->getCustomSummaryInfo(idx, key, value) == eOk)
        {
            std::string sdtkey = wstr_to_utf8(key);
            std::string stdvalue = wstr_to_utf8(value);
            sinfoDict[sdtkey] = stdvalue;
        }
#endif
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
    constexpr const std::string_view setPlotCfgNameOverloads = "Overloads:\n"
        "- settings: PyDb.PlotSettings, plotDeviceName: str\n"
        "- settings: PyDb.PlotSettings, plotDeviceName: str, mediaName: str\n";

    constexpr const std::string_view setPlotWindowAreaOverloads = "Overloads:\n"
        "- settings: PyDb.PlotSettings, ex: PyDb.Extents2d\n"
        "- settings: PyDb.PlotSettings, xmin: float, ymin: float, xmax: float, ymax: float\n";

    constexpr const std::string_view getLocaleMediaNameOverloads = "Overloads:\n"
        "- settings: PyDb.PlotSettings, canonicalName: str\n"
        "- settings: PyDb.PlotSettings, idx: int\n";

    PyDocString DS("PlotSettingsValidator");
    class_<PyDbPlotSettingsValidator>("PlotSettingsValidator")
        .def(init<>(DS.ARGS()))
        .def("setPlotCfgName", &PyDbPlotSettingsValidator::setPlotCfgName1)
        .def("setPlotCfgName", &PyDbPlotSettingsValidator::setPlotCfgName2, DS.OVRL(setPlotCfgNameOverloads))
        .def("setCanonicalMediaName", &PyDbPlotSettingsValidator::setCanonicalMediaName, DS.ARGS({ "settings: PyDb.PlotSettings","mediaName: str" }))
        .def("setPlotOrigin", &PyDbPlotSettingsValidator::setPlotOrigin, DS.ARGS({ "settings: PyDb.PlotSettings","xCoordinate: float","yCoordinate: float" }))
        .def("setPlotPaperUnits", &PyDbPlotSettingsValidator::setPlotPaperUnits, DS.ARGS({ "settings: PyDb.PlotSettings","units: PyDb.PlotPaperUnits" }))
        .def("setPlotRotation", &PyDbPlotSettingsValidator::setPlotRotation, DS.ARGS({ "settings: PyDb.PlotSettings","rotationType: PyDb.PlotRotation" }))
        .def("setPlotCentered", &PyDbPlotSettingsValidator::setPlotCentered, DS.ARGS({ "settings: PyDb.PlotSettings","isCentered: bool" }))
        .def("setPlotType", &PyDbPlotSettingsValidator::setPlotType, DS.ARGS({ "settings: PyDb.PlotSettings","plotAreaType: PyDb.PlotType" }))
        .def("setPlotWindowArea", &PyDbPlotSettingsValidator::setPlotWindowArea1)
        .def("setPlotWindowArea", &PyDbPlotSettingsValidator::setPlotWindowArea2, DS.OVRL(setPlotWindowAreaOverloads))
        .def("setPlotViewName", &PyDbPlotSettingsValidator::setPlotViewName, DS.ARGS({ "settings: PyDb.PlotSettings","viewName: str" }))
        .def("setUseStandardScale", &PyDbPlotSettingsValidator::setUseStandardScale, DS.ARGS({ "settings: PyDb.PlotSettings","useStandard: bool" }))
        .def("setCustomPrintScale", &PyDbPlotSettingsValidator::setCustomPrintScale, DS.ARGS({ "settings: PyDb.PlotSettings","numerator: float","denominator: float" }))
        .def("setCurrentStyleSheet", &PyDbPlotSettingsValidator::setCurrentStyleSheet, DS.ARGS({ "settings: PyDb.PlotSettings","styleSheetName: str" }))
        .def("setStdScaleType", &PyDbPlotSettingsValidator::setStdScaleType, DS.ARGS({ "settings: PyDb.PlotSettings","scaleType: PyDb.StdScaleType" }))
        .def("setStdScale", &PyDbPlotSettingsValidator::setStdScale, DS.ARGS({ "settings: PyDb.PlotSettings","scale: float" }))
        .def("plotDeviceList", &PyDbPlotSettingsValidator::plotDeviceList, DS.ARGS())
        .def("canonicalMediaNameList", &PyDbPlotSettingsValidator::canonicalMediaNameList, DS.ARGS({ "settings: PyDb.PlotSettings" }))
        .def("getLocaleMediaName", &PyDbPlotSettingsValidator::getLocaleMediaName1)
        .def("getLocaleMediaName", &PyDbPlotSettingsValidator::getLocaleMediaName2, DS.OVRL(getLocaleMediaNameOverloads))
        .def("setClosestMediaName", &PyDbPlotSettingsValidator::setClosestMediaName, DS.ARGS({ "settings: PyDb.PlotSettings", "paperWidth: float","paperHeight: float","units: PyDb.PlotPaperUnits","matchPrintableArea: bool" }))
        .def("plotStyleSheetList", &PyDbPlotSettingsValidator::plotStyleSheetList, DS.ARGS())
        .def("refreshLists", &PyDbPlotSettingsValidator::refreshLists, DS.ARGS({ "settings: PyDb.PlotSettings" }))
        .def("setZoomToPaperOnUpdate", &PyDbPlotSettingsValidator::setZoomToPaperOnUpdate, DS.ARGS({ "settings: PyDb.PlotSettings","doZoom: bool" }))
        .def("setDefaultPlotConfig", &PyDbPlotSettingsValidator::setDefaultPlotConfig, DS.ARGS({ "settings: PyDb.PlotSettings" }))
        .def("className", &PyDbPlotSettingsValidator::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbPlotSettingsValidator::PyDbPlotSettingsValidator(AcDbPlotSettingsValidator* ptr)
    : m_impl(ptr)
{
}

void PyDbPlotSettingsValidator::setPlotCfgName1(PyDbPlotSettings& settings, const std::string& plotDeviceName) const
{
    PyThrowBadEs(impObj()->setPlotCfgName(settings.impObj(), utf8_to_wstr(plotDeviceName).c_str()));
}

void PyDbPlotSettingsValidator::setPlotCfgName2(PyDbPlotSettings& settings, const std::string& plotDeviceName, const std::string& mediaName) const
{
    PyThrowBadEs(impObj()->setPlotCfgName(settings.impObj(), utf8_to_wstr(plotDeviceName).c_str(), utf8_to_wstr(mediaName).c_str()));
}

void PyDbPlotSettingsValidator::setCanonicalMediaName(PyDbPlotSettings& settings, const std::string& mediaName) const
{
    PyThrowBadEs(impObj()->setCanonicalMediaName(settings.impObj(), utf8_to_wstr(mediaName).c_str()));
}

void PyDbPlotSettingsValidator::setPlotOrigin(PyDbPlotSettings& settings, const double xCoordinate, const double yCoordinate) const
{
    PyThrowBadEs(impObj()->setPlotOrigin(settings.impObj(), xCoordinate, yCoordinate));
}

void PyDbPlotSettingsValidator::setPlotPaperUnits(PyDbPlotSettings& pPlotSet, const PlotPaperUnits units) const
{
    PyThrowBadEs(impObj()->setPlotPaperUnits(pPlotSet.impObj(), units));
}

void PyDbPlotSettingsValidator::setPlotRotation(PyDbPlotSettings& pPlotSet, const PlotRotation rotationType) const
{
    PyThrowBadEs(impObj()->setPlotRotation(pPlotSet.impObj(), rotationType));
}

void PyDbPlotSettingsValidator::setPlotCentered(PyDbPlotSettings& pPlotSet, Adesk::Boolean isCentered) const
{
    PyThrowBadEs(impObj()->setPlotCentered(pPlotSet.impObj(), isCentered));
}

void PyDbPlotSettingsValidator::setPlotType(PyDbPlotSettings& pPlotSet, const PlotType plotAreaType) const
{
    PyThrowBadEs(impObj()->setPlotType(pPlotSet.impObj(), plotAreaType));
}

void PyDbPlotSettingsValidator::setPlotWindowArea1(PyDbPlotSettings& pPlotSet, const double xmin, const double ymin, const double xmax, const double ymax) const
{
    PyThrowBadEs(impObj()->setPlotWindowArea(pPlotSet.impObj(), xmin, ymin, xmax, ymax));
}

void PyDbPlotSettingsValidator::setPlotWindowArea2(PyDbPlotSettings& pPlotSet, AcDbExtents2d& ex) const
{
    PyThrowBadEs(impObj()->setPlotWindowArea(pPlotSet.impObj(), ex.minPoint().x, ex.minPoint().y, ex.maxPoint().x, ex.maxPoint().y));
}

void PyDbPlotSettingsValidator::setPlotViewName(PyDbPlotSettings& pPlotSet, const std::string& viewName) const
{
    PyThrowBadEs(impObj()->setPlotViewName(pPlotSet.impObj(), utf8_to_wstr(viewName).c_str()));
}

void PyDbPlotSettingsValidator::setUseStandardScale(PyDbPlotSettings& pPlotSet, Adesk::Boolean useStandard) const
{
    PyThrowBadEs(impObj()->setUseStandardScale(pPlotSet.impObj(), useStandard));
}

void PyDbPlotSettingsValidator::setCustomPrintScale(PyDbPlotSettings& pPlotSet, const double numerator, const double denominator) const
{
    PyThrowBadEs(impObj()->setCustomPrintScale(pPlotSet.impObj(), numerator, denominator));
}

void PyDbPlotSettingsValidator::setCurrentStyleSheet(PyDbPlotSettings& pPlotSet, const std::string& styleSheetName) const
{
    PyThrowBadEs(impObj()->setCurrentStyleSheet(pPlotSet.impObj(), utf8_to_wstr(styleSheetName).c_str()));
}

void PyDbPlotSettingsValidator::setStdScaleType(PyDbPlotSettings& pPlotSet, const StdScaleType scaleType) const
{
    PyThrowBadEs(impObj()->setStdScaleType(pPlotSet.impObj(), scaleType));
}

void PyDbPlotSettingsValidator::setStdScale(PyDbPlotSettings& pPlotSet, const double standardScale) const
{
    PyThrowBadEs(impObj()->setStdScale(pPlotSet.impObj(), standardScale));
}

boost::python::list PyDbPlotSettingsValidator::plotDeviceList() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcArray<const ACHAR*> deviceList;
    PyThrowBadEs(impObj()->plotDeviceList(deviceList));
    for (const auto& chrs : deviceList)
        pylist.append(wstr_to_utf8(chrs));
    return pylist;
}

boost::python::list PyDbPlotSettingsValidator::canonicalMediaNameList(PyDbPlotSettings& pPlotSet) const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcArray<const ACHAR*> mediaList;
    PyThrowBadEs(impObj()->canonicalMediaNameList(pPlotSet.impObj(), mediaList));
    for (const auto& chrs : mediaList)
        pylist.append(wstr_to_utf8(chrs));
    return pylist;
}

std::string PyDbPlotSettingsValidator::getLocaleMediaName1(PyDbPlotSettings& pPlotSet, const std::string& canonicalName) const
{
    const ACHAR* localeName = nullptr;
    PyThrowBadEs(impObj()->getLocaleMediaName(pPlotSet.impObj(), utf8_to_wstr(canonicalName).c_str(), localeName));
    return wstr_to_utf8(localeName);
}

std::string PyDbPlotSettingsValidator::getLocaleMediaName2(PyDbPlotSettings& pPlotSet, int index) const
{
    const ACHAR* localeName = nullptr;
    PyThrowBadEs(impObj()->getLocaleMediaName(pPlotSet.impObj(), index, localeName));
    return wstr_to_utf8(localeName);
}

void PyDbPlotSettingsValidator::setClosestMediaName(PyDbPlotSettings& pPlotSet, double paperWidth, double paperHeight, PlotPaperUnits units, Adesk::Boolean matchPrintableArea) const
{
    PyThrowBadEs(impObj()->setClosestMediaName(pPlotSet.impObj(), paperWidth, paperHeight, units, matchPrintableArea));
}

boost::python::list PyDbPlotSettingsValidator::plotStyleSheetList() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcArray<const ACHAR*> styleList;
    PyThrowBadEs(impObj()->plotStyleSheetList(styleList));
    for (const auto& chrs : styleList)
        pylist.append(wstr_to_utf8(chrs));
    return pylist;
}

void PyDbPlotSettingsValidator::refreshLists(PyDbPlotSettings& pPlotSet) const
{
    impObj()->refreshLists(pPlotSet.impObj());
}

void PyDbPlotSettingsValidator::setZoomToPaperOnUpdate(PyDbPlotSettings& pPlotSet, Adesk::Boolean doZoom) const
{
    impObj()->setZoomToPaperOnUpdate(pPlotSet.impObj(), doZoom);
}

void PyDbPlotSettingsValidator::setDefaultPlotConfig(PyDbPlotSettings& pPlotSet) const
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

void makePyDbDictUtilWrapper()
{
    PyDocString DS("DictUtil");
    class_<PyDbDictUtil>("DictUtil")
        .def(init<>(DS.ARGS()))
        .def("dictionaryNameAt", &PyDbDictUtil::dictionaryNameAt1)
        .def("dictionaryNameAt", &PyDbDictUtil::dictionaryNameAt2, DS.SARGS({ "id: PyDb.ObjectId","owner: PyDb.ObjectId.kNull" })).staticmethod("dictionaryNameAt")
        .def("dictionaryGetAt", &PyDbDictUtil::dictionaryGetAt, DS.SARGS({ "name: str" ,"owner: PyDb.ObjectId" })).staticmethod("dictionaryGetAt")
        .def("getColorName", &PyDbDictUtil::getColorName, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getColorName")
        .def("getGroupId", &PyDbDictUtil::getGroupId, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("getGroupId")
        .def("getGroupName", &PyDbDictUtil::getGroupName, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getGroupName")
        .def("getLayoutId", &PyDbDictUtil::getLayoutId, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("getLayoutId")
        .def("getLayoutName", &PyDbDictUtil::getLayoutName, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getLayoutName")
        .def("getMaterialId", &PyDbDictUtil::getMaterialId, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("getMaterialId")
        .def("getMaterialName", &PyDbDictUtil::getMaterialName, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("getMaterialName")
        .def("getMLStyleId", &PyDbDictUtil::getMLStyleId, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("getMLStyleId")
        .def("getMLStyleName", &PyDbDictUtil::getMLStyleName, DS.SARGS({ "itemId: PyDb.ObjectId" })).staticmethod("getMLStyleName")
        .def("getPlotSettingsId", &PyDbDictUtil::getPlotSettingsId, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("getPlotSettingsId")
        .def("getPlotSettingsName", &PyDbDictUtil::getPlotSettingsName, DS.SARGS({ "itemId: PyDb.ObjectId" })).staticmethod("getPlotSettingsName")
        .def("getPlotStyleNameId", &PyDbDictUtil::getPlotStyleNameId, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("getPlotStyleNameId")
        .def("getPlotStyleNameName", &PyDbDictUtil::getPlotStyleNameName, DS.SARGS({ "itemId: PyDb.ObjectId" })).staticmethod("getPlotStyleNameName")
        .def("getTableStyleId", &PyDbDictUtil::getTableStyleId, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("getTableStyleId")
        .def("getTableStyleName", &PyDbDictUtil::getTableStyleName, DS.SARGS({ "itemId: PyDb.ObjectId" })).staticmethod("getTableStyleName")
        .def("getVisualStyleId", &PyDbDictUtil::getVisualStyleId, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("getVisualStyleId")
        .def("getVisualStyleName", &PyDbDictUtil::getVisualStyleName, DS.SARGS({ "itemId: PyDb.ObjectId" })).staticmethod("getVisualStyleName")
        .def("hasColor", &PyDbDictUtil::hasColor, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("hasColor")
        .def("hasGroup", &PyDbDictUtil::hasGroup, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("hasGroup")
        .def("hasLayout", &PyDbDictUtil::hasLayout, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("hasLayout")
        .def("hasMaterial", &PyDbDictUtil::hasMaterial, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("hasMaterial")
        .def("hasMLStyle", &PyDbDictUtil::hasMaterial, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("hasMLStyle")
        .def("hasPlotSettings", &PyDbDictUtil::hasPlotSettings, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("hasPlotSettings")
        .def("hasPlotStyleName", &PyDbDictUtil::hasPlotStyleName, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("hasPlotStyleName")
        .def("hasTableStyle", &PyDbDictUtil::hasTableStyle, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("hasTableStyle")
        .def("hasVisualStyle", &PyDbDictUtil::hasVisualStyle, DS.SARGS({ "val: str", "db: PyDb.Database" })).staticmethod("hasVisualStyle")
        ;
}

std::string PyDbDictUtil::dictionaryNameAt1(const PyDbObjectId& itemId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::dictionaryNameAt(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::dictionaryNameAt(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

std::string PyDbDictUtil::dictionaryNameAt2(const PyDbObjectId& itemId, const PyDbObjectId& ownerDictId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::dictionaryNameAt(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::dictionaryNameAt(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

PyDbObjectId PyDbDictUtil::dictionaryGetAt(const std::string& name, const PyDbObjectId& ownerDictId)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbDictUtil::dictionaryGetAt(id.m_id, utf8_to_wstr(name).c_str(), ownerDictId.m_id));
    return id;
}

std::string PyDbDictUtil::getColorName(const PyDbObjectId& itemId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::getColorName(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::getColorName(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

PyDbObjectId PyDbDictUtil::getGroupId(const std::string& name, const PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbDictUtil::getGroupId(id.m_id, utf8_to_wstr(name).c_str(), db.impObj()));
    return id;
}

std::string PyDbDictUtil::getGroupName(const PyDbObjectId& itemId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::getGroupName(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::getGroupName(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

PyDbObjectId PyDbDictUtil::getLayoutId(const std::string& name, const PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbDictUtil::getLayoutId(id.m_id, utf8_to_wstr(name).c_str(), db.impObj()));
    return id;
}

std::string PyDbDictUtil::getLayoutName(const PyDbObjectId& itemId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::getLayoutName(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::getLayoutName(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

PyDbObjectId PyDbDictUtil::getMaterialId(const std::string& name, const PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbDictUtil::getMaterialId(id.m_id, utf8_to_wstr(name).c_str(), db.impObj()));
    return id;
}

std::string PyDbDictUtil::getMaterialName(const PyDbObjectId& itemId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::getMaterialName(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::getMaterialName(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

PyDbObjectId PyDbDictUtil::getMLStyleId(const std::string& name, const PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbDictUtil::getMLStyleId(id.m_id, utf8_to_wstr(name).c_str(), db.impObj()));
    return id;
}

std::string PyDbDictUtil::getMLStyleName(const PyDbObjectId& itemId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::getMLStyleName(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::getMLStyleName(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

PyDbObjectId PyDbDictUtil::getPlotSettingsId(const std::string& name, const PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbDictUtil::getPlotSettingsId(id.m_id, utf8_to_wstr(name).c_str(), db.impObj()));
    return id;
}

std::string PyDbDictUtil::getPlotSettingsName(const PyDbObjectId& itemId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::getPlotSettingsName(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::getPlotSettingsName(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

PyDbObjectId PyDbDictUtil::getPlotStyleNameId(const std::string& name, const PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbDictUtil::getPlotStyleNameId(id.m_id, utf8_to_wstr(name).c_str(), db.impObj()));
    return id;
}

std::string PyDbDictUtil::getPlotStyleNameName(const PyDbObjectId& itemId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::getPlotStyleNameName(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::getPlotStyleNameName(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

PyDbObjectId PyDbDictUtil::getTableStyleId(const std::string& name, const PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbDictUtil::getTableStyleId(id.m_id, utf8_to_wstr(name).c_str(), db.impObj()));
    return id;
}

std::string PyDbDictUtil::getTableStyleName(const PyDbObjectId& itemId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::getTableStyleName(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::getTableStyleName(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

PyDbObjectId PyDbDictUtil::getVisualStyleId(const std::string& name, const PyDbDatabase& db)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbDictUtil::getVisualStyleId(id.m_id, utf8_to_wstr(name).c_str(), db.impObj()));
    return id;
}

std::string PyDbDictUtil::getVisualStyleName(const PyDbObjectId& itemId)
{
#if defined(_BRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(AcDbDictUtil::getVisualStyleName(str.buf, itemId.m_id));
    return wstr_to_utf8(str.buf);
#else
    AcString str;
    PyThrowBadEs(AcDbDictUtil::getVisualStyleName(str, itemId.m_id));
    return wstr_to_utf8(str);
#endif
}

bool PyDbDictUtil::hasColor(const std::string& name, const PyDbDatabase& db)
{
    return AcDbDictUtil::hasColor(utf8_to_wstr(name).c_str(), db.impObj());
}

bool PyDbDictUtil::hasGroup(const std::string& name, const PyDbDatabase& db)
{
    return AcDbDictUtil::hasGroup(utf8_to_wstr(name).c_str(), db.impObj());
}

bool PyDbDictUtil::hasLayout(const std::string& name, const PyDbDatabase& db)
{
    return AcDbDictUtil::hasLayout(utf8_to_wstr(name).c_str(), db.impObj());
}

bool PyDbDictUtil::hasMaterial(const std::string& name, const PyDbDatabase& db)
{
    return AcDbDictUtil::hasMaterial(utf8_to_wstr(name).c_str(), db.impObj());
}

bool PyDbDictUtil::hasMLStyle(const std::string& name, const PyDbDatabase& db)
{
    return AcDbDictUtil::hasMLStyle(utf8_to_wstr(name).c_str(), db.impObj());
}

bool PyDbDictUtil::hasPlotSettings(const std::string& name, const PyDbDatabase& db)
{
    return AcDbDictUtil::hasPlotSettings(utf8_to_wstr(name).c_str(), db.impObj());
}

bool PyDbDictUtil::hasPlotStyleName(const std::string& name, const PyDbDatabase& db)
{
    return AcDbDictUtil::hasPlotStyleName(utf8_to_wstr(name).c_str(), db.impObj());
}

bool PyDbDictUtil::hasTableStyle(const std::string& name, const PyDbDatabase& db)
{
    return AcDbDictUtil::hasTableStyle(utf8_to_wstr(name).c_str(), db.impObj());
}

bool PyDbDictUtil::hasVisualStyle(const std::string& name, const PyDbDatabase& db)
{
    return AcDbDictUtil::hasVisualStyle(utf8_to_wstr(name).c_str(), db.impObj());
}

