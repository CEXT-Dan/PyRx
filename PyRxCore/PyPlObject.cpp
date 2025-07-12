#include "stdafx.h"
#include "PyPlObject.h"
#include "PyDbLayout.h"
#include "PyDbObjectId.h"
#include "PyPlPlotProgressDialog.h"
#include "PyGeBoundBlock2d.h"

using namespace boost::python;

#if defined(_BRXTARGET260)
//
#else
//-----------------------------------------------------------------------------------------
//AcPlPlotFactory
void makeAcPlPlotFactoryWrapper()
{
    PyDocString DS("PlotFactory");
    class_<PyPlPlotFactory>("PlotFactory", boost::python::no_init)
        .def("createPreviewEngine", &PyPlPlotFactory::createPreviewEngine1)
        .def("createPreviewEngine", &PyPlPlotFactory::createPreviewEngine2, DS.SARGS({ "flags : int = 1" })).staticmethod("createPreviewEngine")
        .def("createPublishEngine", &PyPlPlotFactory::createPublishEngine, DS.SARGS()).staticmethod("createPublishEngine")
        .def("processPlotState", &PyPlPlotFactory::processPlotState, DS.SARGS()).staticmethod("processPlotState")
        .def("className", &PyPlPlotFactory::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<ProcessPlotState>("ProcessPlotState")
        .value("kNotPlotting", ProcessPlotState::kNotPlotting)
        .value("kForegroundPlotting", ProcessPlotState::kForegroundPlotting)
        .value("kBackgroundPlotting", ProcessPlotState::kBackgroundPlotting)
        .export_values()
        ;
}

PyPlPlotEngine PyPlPlotFactory::createPreviewEngine1()
{
    AcPlPlotEngine* ptr = nullptr;
    PyThrowBadEs(AcPlPlotFactory::createPreviewEngine(ptr));
    return PyPlPlotEngine(ptr);
}

PyPlPlotEngine PyPlPlotFactory::createPreviewEngine2(long flags)
{
    AcPlPlotEngine* ptr = nullptr;
    PyThrowBadEs(AcPlPlotFactory::createPreviewEngine(ptr, flags));
    return PyPlPlotEngine(ptr);
}

PyPlPlotEngine PyPlPlotFactory::createPublishEngine()
{
    AcPlPlotEngine* ptr = nullptr;
    PyThrowBadEs(AcPlPlotFactory::createPublishEngine(ptr));
    return PyPlPlotEngine(ptr);
}

ProcessPlotState PyPlPlotFactory::processPlotState()
{
    return acplProcessPlotState();
}

std::string PyPlPlotFactory::className()
{
    return "AcPlPlotFactory";
}

//-----------------------------------------------------------------------------------------
//PyPlPlotEngine
void makePyPlPlotEngineWrapper()
{
    PyDocString DS("PlotEngine");
    class_<PyPlPlotEngine>("PlotEngine", boost::python::no_init)
        .def("beginPlot", &PyPlPlotEngine::beginPlot, DS.ARGS({ "dlgRef: PyPl.PlotProgressDialog" }))
        .def("endPlot", &PyPlPlotEngine::endPlot, DS.ARGS())
        .def("beginDocument", &PyPlPlotEngine::beginDocument, DS.ARGS({ "plotInfo:PyPl.PlotInfo", "docName:str", "plotToFile:bool", "fileName:str" }))
        .def("endDocument", &PyPlPlotEngine::endDocument, DS.ARGS())
        .def("beginPage", &PyPlPlotEngine::beginPage, DS.ARGS({ "pageInfo:PyPl.PlotPageInfo","plotInfo:PyPl.PlotInfo","lastPage:bool" }))
        .def("endPage", &PyPlPlotEngine::endPage, DS.ARGS())
        .def("beginGenerateGraphics", &PyPlPlotEngine::beginGenerateGraphics, DS.ARGS())
        .def("endGenerateGraphics", &PyPlPlotEngine::endGenerateGraphics, DS.ARGS())
        .def("destroy", &PyPlPlotEngine::destroy, DS.ARGS())
        .def("isBackgroundPackaging", &PyPlPlotEngine::isBackgroundPackaging, DS.ARGS())
        .def("className", &PyPlPlotEngine::className, DS.SARGS()).staticmethod("className")
        ;
}

struct PyPlPlotEngineDeleter
{
    inline void operator()(AcPlPlotEngine* p) const
    {
        if (p == nullptr) [[unlikely]] {
            return;
        }
        p->destroy();
    };
};

PyPlPlotEngine::PyPlPlotEngine(AcPlPlotEngine* ptr)
    : m_imp(ptr, PyPlPlotEngineDeleter())
{
}

void PyPlPlotEngine::beginPlot(PyPlPlotProgressDialog& pPlotProgress) const
{
    PyThrowBadEs(impObj()->beginPlot(pPlotProgress.impObj()));
}

void PyPlPlotEngine::endPlot() const
{
    PyThrowBadEs(impObj()->endPlot());
}

void PyPlPlotEngine::beginDocument(PyPlPlotInfo& plotInfo, const std::string& pDocname, Adesk::Int32 nCopies, bool bPlotToFile, const std::string& pFileName) const
{
    PyThrowBadEs(impObj()->beginDocument(*plotInfo.impObj(), utf8_to_wstr(pDocname).c_str(), NULL, nCopies, bPlotToFile, utf8_to_wstr(pFileName).c_str()));
}

void PyPlPlotEngine::endDocument() const
{
    PyThrowBadEs(impObj()->endDocument());
}

void PyPlPlotEngine::beginPage(PyPlPlotPageInfo& pageInfo, PyPlPlotInfo& plotInfo, bool bLastPage) const
{
    PyThrowBadEs(impObj()->beginPage(*pageInfo.impObj(), *plotInfo.impObj(), bLastPage));
}

void PyPlPlotEngine::endPage() const
{
    PyThrowBadEs(impObj()->endPage());
}

void PyPlPlotEngine::beginGenerateGraphics() const
{
    PyThrowBadEs(impObj()->beginGenerateGraphics());
}

void PyPlPlotEngine::endGenerateGraphics() const
{
    PyThrowBadEs(impObj()->endGenerateGraphics());
}

void PyPlPlotEngine::destroy()
{
    m_imp.reset();
}

bool PyPlPlotEngine::isBackgroundPackaging() const
{
    return impObj()->isBackgroundPackaging();
}

std::string PyPlPlotEngine::className()
{
    return "AcPlPlotEngine";
}

AcPlPlotEngine* PyPlPlotEngine::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcPlPlotEngine*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//PyRxObject
void makePyPlObjectWrapper()
{
    PyDocString DS("PlObject");
    class_<PyPlObject, bases<PyRxObject>>("PlObject", boost::python::no_init)
        .def("className", &PyPlObject::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlObject::PyPlObject(const AcPlObject* ptr)
    :PyRxObject(ptr)
{
}

PyPlObject::PyPlObject(AcPlObject* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

std::string PyPlObject::className()
{
    return std::string{ "AcPlObject" };
}

AcPlObject* PyPlObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcPlObject*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlDSDData
void makePyPlDSDDataWrapper()
{
    PyDocString DS("DSDData");
    class_<PyPlDSDData, bases<PyPlObject>>("DSDData")
        .def(init<>(DS.ARGS(14764)))
        .def("projectPath", &PyPlDSDData::projectPath, DS.ARGS())
        .def("setProjectPath", &PyPlDSDData::setProjectPath, DS.ARGS({ "path: str" }))
        .def("destinationName", &PyPlDSDData::destinationName, DS.ARGS())
        .def("setDestinationName", &PyPlDSDData::setDestinationName, DS.ARGS({ "val: str" }))
        .def("getDSDEntries", &PyPlDSDData::getDSDEntries, DS.ARGS())
        .def("setDSDEntries", &PyPlDSDData::setDSDEntries, DS.ARGS({ "entries: list[PyPl.DSDEntry]" }))
        .def("getPrecisionEntries", &PyPlDSDData::getPrecisionEntries, DS.ARGS())
        .def("setPrecisionEntries", &PyPlDSDData::setPrecisionEntries, DS.ARGS({ "val:list[PyPl.PrecisionEntry]" }))
        .def("numberOfDSDEntries", &PyPlDSDData::numberOfDSDEntries, DS.ARGS())
        .def("sheetType", &PyPlDSDData::sheetType, DS.ARGS())
        .def("setSheetType", &PyPlDSDData::setSheetType, DS.ARGS({ "val:PyPl.SheetType" }))
        .def("password", &PyPlDSDData::password, DS.ARGS())
        .def("setPassword", &PyPlDSDData::setPassword, DS.ARGS({ "val:str" }))
        .def("getUnrecognizedData", &PyPlDSDData::getUnrecognizedData, DS.ARGS())
        .def("setUnrecognizedData", &PyPlDSDData::setUnrecognizedData1, DS.ARGS({ "sectionName:str","sectionData:str" }))
        .def("setUnrecognizedData", &PyPlDSDData::setUnrecognizedData2, DS.ARGS({ "sectionName:list[str]","sectionData:list[str]" }))
        .def("majorVersion", &PyPlDSDData::majorVersion, DS.ARGS())
        .def("setMajorVersion", &PyPlDSDData::setMajorVersion, DS.ARGS({ "val:int" }))
        .def("minorVersion", &PyPlDSDData::minorVersion, DS.ARGS())
        .def("setMinorVersion", &PyPlDSDData::setMinorVersion, DS.ARGS({ "val:int" }))
        .def("sheetSetName", &PyPlDSDData::sheetSetName, DS.ARGS())
        .def("setSheetSetName", &PyPlDSDData::setSheetSetName, DS.ARGS({ "val:str" }))
        .def("noOfCopies", &PyPlDSDData::noOfCopies, DS.ARGS())
        .def("setNoOfCopies", &PyPlDSDData::setNoOfCopies, DS.ARGS({ "val:int" }))
        .def("setIsSheetSet", &PyPlDSDData::setIsSheetSet, DS.ARGS({ "val:bool" }))
        .def("isSheetSet", &PyPlDSDData::isSheetSet, DS.ARGS())
        .def("isHomogeneous", &PyPlDSDData::isHomogeneous, DS.ARGS())
        .def("setIsHomogeneous", &PyPlDSDData::setIsHomogeneous, DS.ARGS({ "val:bool" }))
        .def("plotStampOn", &PyPlDSDData::plotStampOn, DS.ARGS())
        .def("setPlotStampOn", &PyPlDSDData::setPlotStampOn, DS.ARGS({ "val:bool" }))
        .def("viewFile", &PyPlDSDData::viewFile, DS.ARGS())
        .def("setViewFile", &PyPlDSDData::setViewFile, DS.ARGS({ "val:bool" }))
        .def("selectionSetName", &PyPlDSDData::selectionSetName, DS.ARGS())
        .def("setSelectionSetName", &PyPlDSDData::setSelectionSetName, DS.ARGS({ "val:str" }))
        .def("categoryName", &PyPlDSDData::categoryName, DS.ARGS())
        .def("setCategoryName", &PyPlDSDData::setCategoryName, DS.ARGS({ "val:str" }))
        .def("logFilePath", &PyPlDSDData::logFilePath, DS.ARGS())
        .def("setLogFilePath", &PyPlDSDData::setLogFilePath, DS.ARGS({ "val:str" }))
        .def("get3dDwfOptions", &PyPlDSDData::get3dDwfOptions, DS.ARGS())
        .def("set3dDwfOptions", &PyPlDSDData::set3dDwfOptions, DS.ARGS({ "groupByXrefHierarchy:bool", "publishWithMaterials:bool" }))
        .def("includeLayerInfo", &PyPlDSDData::includeLayerInfo, DS.ARGS())
        .def("setIncludeLayerInfo", &PyPlDSDData::setIncludeLayerInfo, DS.ARGS({ "val:bool" }))
        .def("lineMerge", &PyPlDSDData::lineMerge, DS.ARGS())
        .def("setLineMerge", &PyPlDSDData::setLineMerge, DS.ARGS({ "val:bool" }))
        .def("currentPrecision", &PyPlDSDData::currentPrecision, DS.ARGS())
        .def("setCurrentPrecision", &PyPlDSDData::setCurrentPrecision, DS.ARGS({ "val:str" }))
        .def("promptForDwfName", &PyPlDSDData::promptForDwfName, DS.ARGS())
        .def("setPromptForDwfName", &PyPlDSDData::setPromptForDwfName, DS.ARGS({ "val:bool" }))
        .def("pwdProtectPublishedDWF", &PyPlDSDData::pwdProtectPublishedDWF, DS.ARGS())
        .def("setPwdProtectPublishedDWF", &PyPlDSDData::setPwdProtectPublishedDWF, DS.ARGS({ "val:bool" }))
        .def("promptForPassword", &PyPlDSDData::promptForPassword, DS.ARGS())
        .def("setPromptForPassword", &PyPlDSDData::setPromptForPassword, DS.ARGS({ "val:bool" }))
        .def("initializeLayouts", &PyPlDSDData::initializeLayouts, DS.ARGS())
        .def("setInitializeLayouts", &PyPlDSDData::setInitializeLayouts, DS.ARGS({ "val:bool" }))
        .def("desc", &PyPlDSDData::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyPlDSDData::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlDSDData::PyPlDSDData()
    : PyPlDSDData(new AcPlDSDData(), true)
{
}

PyPlDSDData::PyPlDSDData(AcPlDSDData* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

std::string PyPlDSDData::projectPath() const
{
    return wstr_to_utf8(impObj()->projectPath());
}

void PyPlDSDData::setProjectPath(const std::string& pVal) const
{
    impObj()->setProjectPath(utf8_to_wstr(pVal).c_str());
}

std::string PyPlDSDData::destinationName() const
{
    return wstr_to_utf8(impObj()->destinationName());
}

void PyPlDSDData::setDestinationName(const std::string& pVal) const
{
    impObj()->setDestinationName(utf8_to_wstr(pVal).c_str());
}

boost::python::list PyPlDSDData::getDSDEntries() const
{
    PyAutoLockGIL lock;
    AcPlDSDEntries arr;
    boost::python::list pyList;
    impObj()->getDSDEntries(arr);
    for (const auto& item : arr)
        pyList.append(PyPlDSDEntry(item));
    return pyList;
}

void PyPlDSDData::setDSDEntries(const boost::python::list& val) const
{
    AcPlDSDEntries arr;
    const auto& vec = py_list_to_std_vector<PyPlDSDEntry>(val);
    for (auto& item : vec)
        arr.append(AcPlDSDEntry(*item.impObj()));
    impObj()->setDSDEntries(arr);
}

boost::python::list PyPlDSDData::getPrecisionEntries() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcPlPrecisionEntries entries;
    impObj()->getPrecisionEntries(entries);
    for (const auto& entry : entries)
        pyList.append(PyPlPrecisionEntry(entry));
    return pyList;
}

void PyPlDSDData::setPrecisionEntries(const boost::python::list& val) const
{
    AcPlPrecisionEntries entries;
    const auto& vec = py_list_to_std_vector<PyPlPrecisionEntry>(val);
    for (const auto& entry : vec)
        entries.append(*entry.impObj());
    impObj()->setPrecisionEntries(entries);
}

int PyPlDSDData::numberOfDSDEntries() const
{
    return impObj()->numberOfDSDEntries();
}

PyPlDSDEntry PyPlDSDData::DSDEntryAt(int idx) const
{
    return PyPlDSDEntry(impObj()->DSDEntryAt(idx));
}

AcPlDSDEntry::SheetType PyPlDSDData::sheetType() const
{
    return impObj()->sheetType();
}

void PyPlDSDData::setSheetType(AcPlDSDEntry::SheetType val) const
{
    return impObj()->setSheetType(val);
}

std::string PyPlDSDData::password() const
{
    return wstr_to_utf8(impObj()->password());
}

void PyPlDSDData::setPassword(const std::string& pVal) const
{
    impObj()->setPassword(utf8_to_wstr(pVal).c_str());
}

boost::python::tuple PyPlDSDData::getUnrecognizedData() const
{
    PyAutoLockGIL lock;
    AcStringArray _sectionArray;
    AcStringArray _dataArray;
    boost::python::list sectionArray;
    boost::python::list dataArray;
    impObj()->getUnrecognizedData(_sectionArray, _dataArray);
    for (const auto& item : _sectionArray)
        sectionArray.append(wstr_to_utf8(item));
    for (const auto& item : _dataArray)
        dataArray.append(wstr_to_utf8(item));
    return boost::python::make_tuple(sectionArray, dataArray);
}

void PyPlDSDData::setUnrecognizedData1(const std::string& pSectionName, const std::string& pSectionData) const
{
    impObj()->setUnrecognizedData(utf8_to_wstr(pSectionName).c_str(), utf8_to_wstr(pSectionData).c_str());
}

void PyPlDSDData::setUnrecognizedData2(const boost::python::list& sectionArray, const boost::python::list& dataArray) const
{
    impObj()->setUnrecognizedData(PyListToAcStringArray(sectionArray), PyListToAcStringArray(dataArray));
}

unsigned int PyPlDSDData::majorVersion() const
{
    return impObj()->majorVersion();
}

void PyPlDSDData::setMajorVersion(unsigned int majorVersion) const
{
    return impObj()->setMajorVersion(majorVersion);
}

unsigned int PyPlDSDData::minorVersion() const
{
    return impObj()->minorVersion();
}

void PyPlDSDData::setMinorVersion(unsigned int minorVersion) const
{
    return impObj()->setMinorVersion(minorVersion);
}

std::string PyPlDSDData::sheetSetName() const
{
    return wstr_to_utf8(impObj()->sheetSetName());
}

void PyPlDSDData::setSheetSetName(const std::string& pSheetSetName) const
{
    return impObj()->setSheetSetName(utf8_to_wstr(pSheetSetName).c_str());
}

unsigned int PyPlDSDData::noOfCopies() const
{
    return impObj()->noOfCopies();
}

void PyPlDSDData::setNoOfCopies(unsigned int copies) const
{
    return impObj()->setNoOfCopies(copies);
}

void PyPlDSDData::setIsSheetSet(bool bSheetSet) const
{
    return impObj()->setIsSheetSet(bSheetSet);
}

bool PyPlDSDData::isSheetSet() const
{
    return impObj()->isSheetSet();
}

bool PyPlDSDData::isHomogeneous() const
{
    return impObj()->isHomogeneous();
}

void PyPlDSDData::setIsHomogeneous(bool bHomogeneous) const
{
    return impObj()->setIsHomogeneous(bHomogeneous);
}

bool PyPlDSDData::plotStampOn() const
{
    return impObj()->plotStampOn();
}

void PyPlDSDData::setPlotStampOn(bool bOn) const
{
    return impObj()->setPlotStampOn(bOn);
}

bool PyPlDSDData::viewFile() const
{
    return impObj()->viewFile();
}

void PyPlDSDData::setViewFile(bool bViewFile) const
{
    return impObj()->setViewFile(bViewFile);
}

std::string PyPlDSDData::selectionSetName() const
{
    return wstr_to_utf8(impObj()->selectionSetName());
}

void PyPlDSDData::setSelectionSetName(const std::string& pSelSetName) const
{
    return impObj()->setSelectionSetName(utf8_to_wstr(pSelSetName).c_str());
}

std::string PyPlDSDData::categoryName() const
{
    return wstr_to_utf8(impObj()->categoryName());
}

void PyPlDSDData::setCategoryName(const std::string& pCategoryName) const
{
    return impObj()->setCategoryName(utf8_to_wstr(pCategoryName).c_str());
}

std::string PyPlDSDData::logFilePath() const
{
    return wstr_to_utf8(impObj()->logFilePath());
}

void PyPlDSDData::setLogFilePath(const std::string& pLogFilePath) const
{
    return impObj()->setLogFilePath(utf8_to_wstr(pLogFilePath).c_str());
}

boost::python::tuple PyPlDSDData::get3dDwfOptions() const
{
    PyAutoLockGIL lock;
    const AcPl3dDwfOptions& opt = impObj()->get3dDwfOptions();
    return boost::python::make_tuple(opt.bGroupByXrefHierarchy, opt.bPublishWithMaterials);
}

void PyPlDSDData::set3dDwfOptions(bool bGroupByXrefHierarchy, bool bPublishWithMaterials) const
{
    AcPl3dDwfOptions opt = { bGroupByXrefHierarchy ,bPublishWithMaterials };
    impObj()->set3dDwfOptions(opt);
}

bool PyPlDSDData::includeLayerInfo() const
{
    return impObj()->includeLayerInfo();
}

void PyPlDSDData::setIncludeLayerInfo(bool bOn) const
{
    return impObj()->setIncludeLayerInfo(bOn);
}

bool PyPlDSDData::lineMerge() const
{
    return impObj()->lineMerge();
}

void PyPlDSDData::setLineMerge(bool bOn) const
{
    return impObj()->setLineMerge(bOn);
}

std::string PyPlDSDData::currentPrecision() const
{
    return wstr_to_utf8(impObj()->currentPrecision());
}

void PyPlDSDData::setCurrentPrecision(const std::string& pCurrentPrecision) const
{
    return impObj()->setCurrentPrecision(utf8_to_wstr(pCurrentPrecision).c_str());
}

bool PyPlDSDData::promptForDwfName() const
{
    return impObj()->promptForDwfName();
}

void PyPlDSDData::setPromptForDwfName(bool bPromptForDwfName) const
{
    return impObj()->setPromptForDwfName(bPromptForDwfName);
}

bool PyPlDSDData::pwdProtectPublishedDWF() const
{
    return impObj()->pwdProtectPublishedDWF();
}

void PyPlDSDData::setPwdProtectPublishedDWF(bool bPwdProtectPublishedDWF) const
{
    return impObj()->setPwdProtectPublishedDWF(bPwdProtectPublishedDWF);
}

bool PyPlDSDData::promptForPassword() const
{
    return impObj()->promptForPassword();
}

void PyPlDSDData::setPromptForPassword(bool bPromptForPassword) const
{
    return impObj()->setPromptForPassword(bPromptForPassword);
}

bool PyPlDSDData::initializeLayouts() const
{
#if _ZRXTARGET <= 260 || _GRXTARGET == 240
    throw PyNotimplementedByHost();
#endif

#ifdef _ARXTARGET
#if _ARXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->initializeLayouts();
#endif
#endif
}

void PyPlDSDData::setInitializeLayouts(bool initLayouts) const
{
#if _ZRXTARGET <= 250 || _GRXTARGET == 240
    throw PyNotimplementedByHost();
#endif

#ifdef _ARXTARGET
#if _ARXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->setInitializeLayouts(initLayouts);
#endif
#endif
}

PyRxClass PyPlDSDData::desc()
{
    return PyRxClass(AcPlDSDData::desc(), false);
}

std::string PyPlDSDData::className()
{
    return "AcPlDSDData";
}

AcPlDSDData* PyPlDSDData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcPlDSDData*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlDSDEntry
void makePyPlDSDEntryWrapper()
{
    PyDocString DS("DSDEntry");
    class_<PyPlDSDEntry, bases<PyPlObject>>("DSDEntry")
        .def(init<>(DS.ARGS(14816)))
        .def("dwgName", &PyPlDSDEntry::dwgName, DS.ARGS())
        .def("setDwgName", &PyPlDSDEntry::setDwgName, DS.ARGS({ "val:str" }))
        .def("layout", &PyPlDSDEntry::layout, DS.ARGS())
        .def("setLayout", &PyPlDSDEntry::setLayout, DS.ARGS({ "val:str" }))
        .def("title", &PyPlDSDEntry::title, DS.ARGS())
        .def("setTitle", &PyPlDSDEntry::setTitle, DS.ARGS({ "val:str" }))
        .def("NPS", &PyPlDSDEntry::NPS, DS.ARGS())
        .def("setNPS", &PyPlDSDEntry::setNPS, DS.ARGS({ "val:str" }))
        .def("NPSSourceDWG", &PyPlDSDEntry::NPSSourceDWG, DS.ARGS())
        .def("setNPSSourceDWG", &PyPlDSDEntry::setNPSSourceDWG, DS.ARGS({ "val:str" }))
        .def("has3dDwfSetup", &PyPlDSDEntry::has3dDwfSetup, DS.ARGS())
        .def("setHas3dDwfSetup", &PyPlDSDEntry::setHas3dDwfSetup, DS.ARGS({ "val:bool" }))
        .def("setupType", &PyPlDSDEntry::setupType, DS.ARGS())
        .def("setSetupType", &PyPlDSDEntry::setSetupType, DS.ARGS({ "val:PyPl.SetupType" }))
        .def("orgSheetPath", &PyPlDSDEntry::orgSheetPath, DS.ARGS())
        .def("traceSession", &PyPlDSDEntry::traceSession, DS.ARGS())
        .def("setTraceSession", &PyPlDSDEntry::setTraceSession, DS.ARGS({ "val:str" }))
        .def("desc", &PyPlDSDEntry::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyPlDSDEntry::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<AcPlDSDEntry::SheetType>("SheetType")
        .value("kSingleDWF", AcPlDSDEntry::SheetType::kSingleDWF)
        .value("kMultiDWF", AcPlDSDEntry::SheetType::kMultiDWF)
        .value("kOriginalDevice", AcPlDSDEntry::SheetType::kOriginalDevice)
        .value("kSingleDWFx", AcPlDSDEntry::SheetType::kSingleDWFx)
        .value("kMultiDWFx", AcPlDSDEntry::SheetType::kMultiDWFx)
        .value("kSinglePDF", AcPlDSDEntry::SheetType::kSinglePDF)
        .value("kMultiPDF", AcPlDSDEntry::SheetType::kMultiPDF)
        .value("kSingleSVF", AcPlDSDEntry::SheetType::kSingleSVF)
        .value("kMultiSVF", AcPlDSDEntry::SheetType::kMultiSVF)
        .export_values()
        ;

    enum_<AcPlDSDEntry::SetupType>("SetupType")
        .value("kOriginalPS", AcPlDSDEntry::SetupType::kOriginalPS)
        .value("kNPSSameDWG", AcPlDSDEntry::SetupType::kNPSSameDWG)
        .value("kNPSOtherDWG", AcPlDSDEntry::SetupType::kNPSOtherDWG)
        .value("k3dDwf", AcPlDSDEntry::SetupType::k3dDwf)
        .value("kOverridePS", AcPlDSDEntry::SetupType::kOverridePS)
        .export_values()
        ;
}

PyPlDSDEntry::PyPlDSDEntry()
    : PyPlDSDEntry(new AcPlDSDEntry(), true)
{
}

PyPlDSDEntry::PyPlDSDEntry(AcPlDSDEntry* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

PyPlDSDEntry::PyPlDSDEntry(const AcPlDSDEntry& entry)
    : PyPlDSDEntry(new AcPlDSDEntry(entry), true)
{
}

std::string PyPlDSDEntry::dwgName() const
{
    return wstr_to_utf8(impObj()->dwgName());
}

void PyPlDSDEntry::setDwgName(const std::string& pName) const
{
    impObj()->setDwgName(utf8_to_wstr(pName).c_str());
}

std::string PyPlDSDEntry::layout() const
{
    return wstr_to_utf8(impObj()->layout());
}

void PyPlDSDEntry::setLayout(const std::string& pLayoutName) const
{
    impObj()->setLayout(utf8_to_wstr(pLayoutName).c_str());
}

std::string PyPlDSDEntry::title() const
{
    return wstr_to_utf8(impObj()->title());
}

void PyPlDSDEntry::setTitle(const std::string& pTitle) const
{
    impObj()->setLayout(utf8_to_wstr(pTitle).c_str());
}

std::string PyPlDSDEntry::NPS() const
{
    return wstr_to_utf8(impObj()->NPS());
}

void PyPlDSDEntry::setNPS(const std::string& pNPSName) const
{
    impObj()->setNPS(utf8_to_wstr(pNPSName).c_str());
}

std::string PyPlDSDEntry::NPSSourceDWG() const
{
    return wstr_to_utf8(impObj()->NPSSourceDWG());
}

void PyPlDSDEntry::setNPSSourceDWG(const std::string& pNPWDWGName) const
{
    impObj()->setNPSSourceDWG(utf8_to_wstr(pNPWDWGName).c_str());
}

bool PyPlDSDEntry::has3dDwfSetup() const
{
    return impObj()->has3dDwfSetup();
}

void PyPlDSDEntry::setHas3dDwfSetup(bool b3dDwfSetup) const
{
    return impObj()->setHas3dDwfSetup(b3dDwfSetup);
}

AcPlDSDEntry::SetupType PyPlDSDEntry::setupType() const
{
    return impObj()->setupType();
}

void PyPlDSDEntry::setSetupType(AcPlDSDEntry::SetupType eType) const
{
    return impObj()->setSetupType(eType);
}

std::string PyPlDSDEntry::orgSheetPath() const
{
#if defined(_GRXTARGET) && (_GRXTARGET <= 260)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->orgSheetPath());
#endif
}

std::string PyPlDSDEntry::traceSession() const
{
#if _ZRXTARGET <= 260 || _GRXTARGET == 260
    throw PyNotimplementedByHost();
#endif

#ifdef _ARXTARGET
#if _ARXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->traceSession());
#endif
#endif
}

void PyPlDSDEntry::setTraceSession(const std::string& pTraceSession) const
{
    impObj()->setNPSSourceDWG(utf8_to_wstr(pTraceSession).c_str());
}

PyRxClass PyPlDSDEntry::desc()
{
    return PyRxClass(AcPlDSDEntry::desc(), false);
}

std::string PyPlDSDEntry::className()
{
    return "AcPlDSDEntry";
}

AcPlDSDEntry* PyPlDSDEntry::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcPlDSDEntry*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlPlotInfo
void makePyPlPlotInfoWrapper()
{
    PyDocString DS("PlotInfo");
    class_<PyPlPlotInfo, bases<PyPlObject>>("PlotInfo")
        .def(init<>(DS.ARGS(14949)))
        .def("copyFrom", &PyPlPlotInfo::copyFrom, DS.ARGS({ "otherObject: PyRx.RxObject" }))
        .def("setLayout", &PyPlPlotInfo::setLayout, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("layout", &PyPlPlotInfo::layout, DS.ARGS())
        .def("setOverrideSettings", &PyPlPlotInfo::setOverrideSettings, DS.ARGS({ "val:PyDb.PlotSettings" }))
        .def("overrideSettings", &PyPlPlotInfo::overrideSettings, DS.ARGS())
        .def("setDeviceOverride", &PyPlPlotInfo::setDeviceOverride, DS.ARGS({ "val:PyPl.PlotConfig" }))
        .def("validatedSettings", &PyPlPlotInfo::validatedSettings, DS.ARGS())
        .def("setValidatedSettings", &PyPlPlotInfo::setValidatedSettings, DS.ARGS({ "val:PyDb.PlotSettings" }))
        .def("validatedConfig", &PyPlPlotInfo::validatedConfig, DS.ARGS())
        .def("setValidatedConfig", &PyPlPlotInfo::setValidatedConfig, DS.ARGS({ "val:PyPl.PlotConfig" }))
        .def("deviceOverride", &PyPlPlotInfo::deviceOverride, DS.ARGS())
        .def("isCompatibleDocument", &PyPlPlotInfo::isCompatibleDocument, DS.ARGS({ "val:PyPl.PlotInfo" }))
        .def("isValidated", &PyPlPlotInfo::isValidated, DS.ARGS())
        .def("mergeStatus", &PyPlPlotInfo::mergeStatus, DS.ARGS())
        .def("OrgFilePath", &PyPlPlotInfo::OrgFilePath, DS.ARGS())
        .def("desc", &PyPlPlotInfo::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyPlPlotInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlPlotInfo::PyPlPlotInfo()
    : PyPlPlotInfo(new AcPlPlotInfo(), true)
{
}

PyPlPlotInfo::PyPlPlotInfo(AcPlPlotInfo* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

PyPlPlotInfo::PyPlPlotInfo(const AcPlPlotInfo& entry)
    : PyPlPlotInfo(new AcPlPlotInfo(entry), true)
{
}

void PyPlPlotInfo::copyFrom(const PyRxObject& pOther) const
{
    PyThrowBadEs(impObj()->copyFrom(pOther.impObj()));
}

void PyPlPlotInfo::setLayout(PyDbObjectId& layoutId) const
{
    impObj()->setLayout(layoutId.m_id);
}

PyDbObjectId PyPlPlotInfo::layout() const
{
    return PyDbObjectId(impObj()->layout());
}

void PyPlPlotInfo::setOverrideSettings(const PyDbPlotSettings& pOverrides) const
{
    impObj()->setOverrideSettings(pOverrides.impObj());
}

PyDbPlotSettings PyPlPlotInfo::overrideSettings() const
{
    return PyDbPlotSettings(impObj()->overrideSettings());
}

void PyPlPlotInfo::setDeviceOverride(const PyPlPlotConfig& pconf) const
{
    impObj()->setDeviceOverride(pconf.impObj());
}

PyDbPlotSettings PyPlPlotInfo::validatedSettings() const
{
    return PyDbPlotSettings(impObj()->validatedSettings());
}

void PyPlPlotInfo::setValidatedSettings(const PyDbPlotSettings& pValidatedSettings) const
{
    impObj()->setOverrideSettings(pValidatedSettings.impObj());
}

PyPlPlotConfig PyPlPlotInfo::validatedConfig() const
{
    return PyPlPlotConfig(impObj()->validatedConfig());
}

void PyPlPlotInfo::setValidatedConfig(const PyPlPlotConfig& pConfig) const
{
    impObj()->setValidatedConfig(pConfig.impObj());
}

PyPlPlotConfig PyPlPlotInfo::deviceOverride() const
{
    return PyPlPlotConfig(impObj()->deviceOverride());
}

bool PyPlPlotInfo::isCompatibleDocument(const PyPlPlotInfo& pOtherInfo) const
{
    return impObj()->isCompatibleDocument(pOtherInfo.impObj());
}

bool PyPlPlotInfo::isValidated() const
{
    return impObj()->isValidated();
}

unsigned long PyPlPlotInfo::mergeStatus() const
{
    return impObj()->mergeStatus();
}

std::string PyPlPlotInfo::OrgFilePath() const
{
    AcString str = impObj()->OrgFilePath();
    return wstr_to_utf8(str);
}

PyRxClass PyPlPlotInfo::desc()
{
    return PyRxClass(AcPlPlotInfo::desc(), false);
}

std::string PyPlPlotInfo::className()
{
    return "AcPlPlotInfo";
}

AcPlPlotInfo* PyPlPlotInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcPlPlotInfo*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlPlotConfig
void makePyPlPlotConfigWrapper()
{
    PyDocString DS("PlotConfig");
    class_<PyPlPlotConfig, bases<PyPlObject>>("PlotConfig", boost::python::no_init)
        .def("getDescriptionFields", &PyPlPlotConfig::getDescriptionFields, DS.ARGS())
        .def("deviceName", &PyPlPlotConfig::deviceName, DS.ARGS())
        .def("fullPath", &PyPlPlotConfig::fullPath, DS.ARGS())
        .def("maxDeviceDPI", &PyPlPlotConfig::maxDeviceDPI, DS.ARGS())
        .def("deviceType", &PyPlPlotConfig::deviceType, DS.ARGS())
        .def("getCanonicalMediaNameList", &PyPlPlotConfig::getCanonicalMediaNameList, DS.ARGS())
        .def("getLocalMediaName", &PyPlPlotConfig::getLocalMediaName, DS.ARGS({ "canonicalMediaName:str" }))
        .def("getMediaBounds", &PyPlPlotConfig::getMediaBounds, DS.ARGS({ "canonicalMediaName:str" }))
        .def("refreshMediaNameList", &PyPlPlotConfig::refreshMediaNameList, DS.ARGS())
        .def("isPlotToFile", &PyPlPlotConfig::isPlotToFile, DS.ARGS())
        .def("setPlotToFile", &PyPlPlotConfig::setPlotToFile, DS.ARGS({ "val:bool" }))
        .def("getDefaultFileExtension", &PyPlPlotConfig::getDefaultFileExtension, DS.ARGS())
        .def("plotToFileCapability", &PyPlPlotConfig::plotToFileCapability, DS.ARGS())
        .def("saveToPC3", &PyPlPlotConfig::saveToPC3, DS.ARGS({ "val:str" }))
        .def("desc", &PyPlPlotConfig::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyPlPlotConfig::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<AcPlPlotConfig::PlotToFileCapability>("PlotToFileCapability")
        .value("kNoPlotToFile", AcPlPlotConfig::PlotToFileCapability::kNoPlotToFile)
        .value("kPlotToFileAllowed", AcPlPlotConfig::PlotToFileCapability::kPlotToFileAllowed)
        .value("kMustPlotToFile", AcPlPlotConfig::PlotToFileCapability::kMustPlotToFile)
        .export_values()
        ;
}

PyPlPlotConfig::PyPlPlotConfig(const AcPlPlotConfig* ptr)
    : PyPlObject(ptr)
{
}

PyPlPlotConfig::PyPlPlotConfig(AcPlPlotConfig* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

boost::python::tuple PyPlPlotConfig::getDescriptionFields() const
{
    PyAutoLockGIL lock;
    RxAutoOutStr pDriverName;
    RxAutoOutStr pLocationName;
    RxAutoOutStr pComment;
    RxAutoOutStr pPortName;
    RxAutoOutStr pServerName;
    RxAutoOutStr pTagLine;
    impObj()->getDescriptionFields(pDriverName.buf, pLocationName.buf, pComment.buf, pPortName.buf, pServerName.buf, pTagLine.buf);
    return boost::python::make_tuple(pDriverName.str(), pLocationName.str(), pComment.str(), pPortName.str(), pServerName.str(), pTagLine.str());
}

std::string PyPlPlotConfig::deviceName() const
{
    return wstr_to_utf8(impObj()->deviceName());
}

std::string PyPlPlotConfig::fullPath() const
{
    return wstr_to_utf8(impObj()->fullPath());
}

unsigned int PyPlPlotConfig::maxDeviceDPI() const
{
    return impObj()->maxDeviceDPI();
}

unsigned long PyPlPlotConfig::deviceType() const
{
    return impObj()->deviceType();
}

boost::python::list PyPlPlotConfig::getCanonicalMediaNameList() const
{
    PyAutoLockGIL lock;
    AcArray<ACHAR*>mediaList;
    impObj()->getCanonicalMediaNameList(mediaList);
    boost::python::list pyList;
    for (auto ptr : mediaList)
    {
        pyList.append(wstr_to_utf8(ptr));
        acutDelString(ptr);
    }
    return pyList;
}

std::string PyPlPlotConfig::getLocalMediaName(const std::string& pCanonicalMediaName) const
{
    RxAutoOutStr pstr;
    impObj()->getLocalMediaName(utf8_to_wstr(pCanonicalMediaName).c_str(), pstr.buf);
    return pstr.str();
}

boost::python::tuple PyPlPlotConfig::getMediaBounds(const std::string& pCanonicalMediaName) const
{
    PyAutoLockGIL lock;
    AcGePoint2d pageSize;
    AcGeBoundBlock2d printableArea;
    impObj()->getMediaBounds(utf8_to_wstr(pCanonicalMediaName).c_str(), pageSize, printableArea);
    return boost::python::make_tuple(pageSize, PyGeBoundBlock2d(printableArea));
}

void PyPlPlotConfig::refreshMediaNameList() const
{
    impObj()->refreshMediaNameList();
}

bool PyPlPlotConfig::isPlotToFile() const
{
    return impObj()->isPlotToFile();
}

void PyPlPlotConfig::setPlotToFile(bool bPlotToFile) const
{
    PyThrowBadEs(impObj()->setPlotToFile(bPlotToFile));
}

std::string PyPlPlotConfig::getDefaultFileExtension() const
{
    const ACHAR* pPC3Name = nullptr;
    PyThrowBadEs(impObj()->getDefaultFileExtension(pPC3Name));
    return wstr_to_utf8(pPC3Name);
}

AcPlPlotConfig::PlotToFileCapability PyPlPlotConfig::plotToFileCapability() const
{
    return impObj()->plotToFileCapability();
}

bool PyPlPlotConfig::saveToPC3(const std::string& pPC3Name) const
{
    return impObj()->saveToPC3(utf8_to_wstr(pPC3Name).c_str());
}

PyRxClass PyPlPlotConfig::desc()
{
    return PyRxClass(AcPlPlotConfig::desc(), false);
}

std::string PyPlPlotConfig::className()
{
    return "AcPlPlotConfig";
}

AcPlPlotConfig* PyPlPlotConfig::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcPlPlotConfig*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlPlotPageInfo
void makePyPlPlotPageInfoWrapper()
{
    PyDocString DS("PlotPageInfo");
    class_<PyPlPlotPageInfo, bases<PyPlObject>>("PlotPageInfo")
        .def(init<>(DS.ARGS(15021)))
        .def("entityCount", &PyPlPlotPageInfo::entityCount, DS.SARGS()).staticmethod("entityCount")
        .def("rasterCount", &PyPlPlotPageInfo::rasterCount, DS.SARGS()).staticmethod("rasterCount")
        .def("oleObjectCount", &PyPlPlotPageInfo::oleObjectCount, DS.SARGS()).staticmethod("oleObjectCount")
        .def("gradientCount", &PyPlPlotPageInfo::gradientCount, DS.SARGS()).staticmethod("gradientCount")
        .def("shadedViewportType", &PyPlPlotPageInfo::shadedViewportType, DS.SARGS()).staticmethod("shadedViewportType")
        .def("desc", &PyPlPlotPageInfo::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyPlPlotPageInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlPlotPageInfo::PyPlPlotPageInfo()
    : PyPlObject(new AcPlPlotPageInfo(), true)
{
}

PyPlPlotPageInfo::PyPlPlotPageInfo(const AcPlPlotPageInfo* ptr)
    : PyPlObject(ptr)
{
}

PyPlPlotPageInfo::PyPlPlotPageInfo(AcPlPlotPageInfo* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

Adesk::Int32 PyPlPlotPageInfo::entityCount() const
{
    return impObj()->entityCount();
}

Adesk::Int32 PyPlPlotPageInfo::rasterCount() const
{
    return impObj()->rasterCount();
}

Adesk::Int32 PyPlPlotPageInfo::oleObjectCount() const
{
    return impObj()->oleObjectCount();
}

Adesk::Int32 PyPlPlotPageInfo::gradientCount() const
{
    return impObj()->gradientCount();
}

Adesk::Int32 PyPlPlotPageInfo::shadedViewportType() const
{
    return impObj()->shadedViewportType();
}

PyRxClass PyPlPlotPageInfo::desc()
{
    return PyRxClass(AcPlPlotPageInfo::desc(), false);
}

std::string PyPlPlotPageInfo::className()
{
    return "AcPlPlotPageInfo";
}

AcPlPlotPageInfo* PyPlPlotPageInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcPlPlotPageInfo*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlPlotInfoValidator
void makePyPlPlotInfoValidatorWrapper()
{
    PyDocString DS("PlotInfoValidator");
    class_<PyPlPlotInfoValidator, bases<PyPlObject>>("PlotInfoValidator")
        .def(init<>(DS.ARGS(14950)))
        .def("validate", &PyPlPlotInfoValidator::validate, DS.ARGS({ "valByRef:PyPl.PlotInfo" }))
        .def("isCustomPossible", &PyPlPlotInfoValidator::isCustomPossible, DS.ARGS({ "valByRef:PyPl.PlotInfo" }))
        .def("matchingPolicy", &PyPlPlotInfoValidator::matchingPolicy, DS.ARGS())
        .def("setMediaMatchingPolicy", &PyPlPlotInfoValidator::setMediaMatchingPolicy, DS.ARGS({ "val:PyPl.MatchingPolicy" }))
        .def("setMediaGroupWeight", &PyPlPlotInfoValidator::setMediaGroupWeight, DS.ARGS({ "val:int" }))
        .def("setDefMediaGroupWeight", &PyPlPlotInfoValidator::setDefMediaGroupWeight, DS.ARGS({ "val:int" }))
        .def("mediaGroupWeight", &PyPlPlotInfoValidator::mediaGroupWeight, DS.ARGS())
        .def("setSheetMediaGroupWeight", &PyPlPlotInfoValidator::setSheetMediaGroupWeight, DS.ARGS({ "val:int" }))
        .def("setDefSheetMediaGroupWeight", &PyPlPlotInfoValidator::setDefSheetMediaGroupWeight, DS.ARGS())
        .def("sheetMediaGroupWeight", &PyPlPlotInfoValidator::sheetMediaGroupWeight, DS.ARGS())
        .def("setMediaBoundsWeight", &PyPlPlotInfoValidator::setMediaBoundsWeight, DS.ARGS({ "val:int" }))
        .def("setDefMediaBoundsWeight", &PyPlPlotInfoValidator::setDefMediaBoundsWeight, DS.ARGS())
        .def("mediaBoundsWeight", &PyPlPlotInfoValidator::mediaBoundsWeight, DS.ARGS({ "val:int" }))
        .def("setPrintableBoundsWeight", &PyPlPlotInfoValidator::setPrintableBoundsWeight, DS.ARGS({ "val:int" }))
        .def("setDefPrintableBoundsWeight", &PyPlPlotInfoValidator::setDefPrintableBoundsWeight, DS.ARGS())
        .def("printableBoundsWeight", &PyPlPlotInfoValidator::printableBoundsWeight, DS.ARGS())
        .def("setDimensionalWeight", &PyPlPlotInfoValidator::setDimensionalWeight, DS.ARGS({ "val:int" }))
        .def("setDefDimensionalWeight", &PyPlPlotInfoValidator::setDefDimensionalWeight, DS.ARGS())
        .def("dimensionalWeight", &PyPlPlotInfoValidator::dimensionalWeight, DS.ARGS())
        .def("setSheetDimensionalWeight", &PyPlPlotInfoValidator::setSheetDimensionalWeight, DS.ARGS({ "val:int" }))
        .def("setDefSheetDimensionalWeight", &PyPlPlotInfoValidator::setDefSheetDimensionalWeight, DS.ARGS())
        .def("sheetDimensionalWeight", &PyPlPlotInfoValidator::sheetDimensionalWeight, DS.ARGS())
        .def("setMediaMatchingThreshold", &PyPlPlotInfoValidator::setMediaMatchingThreshold, DS.ARGS({ "val:int" }))
        .def("setDefMediaMatchingThreshold", &PyPlPlotInfoValidator::setDefMediaMatchingThreshold, DS.ARGS())
        .def("mediaMatchingThreshold", &PyPlPlotInfoValidator::mediaMatchingThreshold, DS.ARGS())
        .def("desc", &PyPlPlotInfoValidator::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyPlPlotInfoValidator::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<AcPlPlotInfoValidator::MatchingPolicy>("MatchingPolicy")
        .value("kMatchDisabled", AcPlPlotInfoValidator::MatchingPolicy::kMatchDisabled)
        .value("kMatchEnabled", AcPlPlotInfoValidator::MatchingPolicy::kMatchEnabled)
        .value("kMatchEnabledCustom", AcPlPlotInfoValidator::MatchingPolicy::kMatchEnabledCustom)
        .value("kMatchEnabledTmpCustom", AcPlPlotInfoValidator::MatchingPolicy::kMatchEnabledTmpCustom)
        .export_values()
        ;

    enum_<AcPlPlotInfoValidator::eCustomSizeResult>("CustomSizeResult")
        .value("ePossible", AcPlPlotInfoValidator::eCustomSizeResult::ePossible)
        .value("eMustCreatePC3", AcPlPlotInfoValidator::eCustomSizeResult::eMustCreatePC3)
        .value("eRotationRequired", AcPlPlotInfoValidator::eCustomSizeResult::eRotationRequired)
        .value("ePC3DirReadOnly", AcPlPlotInfoValidator::eCustomSizeResult::ePC3DirReadOnly)
        .value("ePMPDirReadOnly", AcPlPlotInfoValidator::eCustomSizeResult::ePMPDirReadOnly)
        .value("ePMPDirMissing", AcPlPlotInfoValidator::eCustomSizeResult::ePMPDirMissing)
        .value("eUnknownErrPMPDir", AcPlPlotInfoValidator::eCustomSizeResult::eUnknownErrPMPDir)
        .value("ePC3FileReadOnly", AcPlPlotInfoValidator::eCustomSizeResult::ePC3FileReadOnly)
        .value("eSizeTooBig", AcPlPlotInfoValidator::eCustomSizeResult::eSizeTooBig)
        .value("eException", AcPlPlotInfoValidator::eCustomSizeResult::eException)
        .value("eUnknownErrPC3File", AcPlPlotInfoValidator::eCustomSizeResult::eUnknownErrPC3File)
        .value("eUnknownErrPMPFile", AcPlPlotInfoValidator::eCustomSizeResult::eUnknownErrPMPFile)
        .value("ePMPFileReadOnly", AcPlPlotInfoValidator::eCustomSizeResult::ePMPFileReadOnly)
        .value("eWidthAndHeightMustBePositive", AcPlPlotInfoValidator::eCustomSizeResult::eWidthAndHeightMustBePositive)
        .value("eDeviceLoadFailed", AcPlPlotInfoValidator::eCustomSizeResult::eDeviceLoadFailed)
        .export_values()
        ;
}

PyPlPlotInfoValidator::PyPlPlotInfoValidator()
    : PyPlObject(new AcPlPlotInfoValidator(), true)
{
}

PyPlPlotInfoValidator::PyPlPlotInfoValidator(AcPlPlotInfoValidator* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

PyPlPlotInfoValidator::PyPlPlotInfoValidator(const AcPlPlotInfoValidator* ptr)
    : PyPlObject(ptr)
{
}

void PyPlPlotInfoValidator::validate(PyPlPlotInfo& info) const
{
    PyThrowBadEs(impObj()->validate(*info.impObj()));
}

AcPlPlotInfoValidator::eCustomSizeResult PyPlPlotInfoValidator::isCustomPossible(PyPlPlotInfo& info) const
{
    return (AcPlPlotInfoValidator::eCustomSizeResult)impObj()->isCustomPossible(*info.impObj());
}

AcPlPlotInfoValidator::MatchingPolicy PyPlPlotInfoValidator::matchingPolicy() const
{
    return impObj()->matchingPolicy();
}

void PyPlPlotInfoValidator::setMediaMatchingPolicy(AcPlPlotInfoValidator::MatchingPolicy policy) const
{
    impObj()->setMediaMatchingPolicy(policy);
}

void PyPlPlotInfoValidator::setMediaGroupWeight(unsigned int weight) const
{
    impObj()->setMediaGroupWeight(weight);
}

void PyPlPlotInfoValidator::setDefMediaGroupWeight() const
{
    impObj()->setMediaGroupWeight();
}

unsigned int PyPlPlotInfoValidator::mediaGroupWeight() const
{
    return impObj()->mediaGroupWeight();
}

void PyPlPlotInfoValidator::setSheetMediaGroupWeight(unsigned int weight) const
{
    impObj()->setSheetMediaGroupWeight(weight);
}

void PyPlPlotInfoValidator::setDefSheetMediaGroupWeight() const
{
    impObj()->setSheetMediaGroupWeight();
}

unsigned int PyPlPlotInfoValidator::sheetMediaGroupWeight() const
{
    return impObj()->sheetMediaGroupWeight();
}

void PyPlPlotInfoValidator::setMediaBoundsWeight(unsigned int weight) const
{
    return impObj()->setMediaBoundsWeight(weight);
}

void PyPlPlotInfoValidator::setDefMediaBoundsWeight() const
{
    return impObj()->setMediaBoundsWeight();
}

unsigned int PyPlPlotInfoValidator::mediaBoundsWeight() const
{
    return impObj()->mediaBoundsWeight();
}

void PyPlPlotInfoValidator::setPrintableBoundsWeight(unsigned int weight) const
{
    return impObj()->setPrintableBoundsWeight(weight);
}

void PyPlPlotInfoValidator::setDefPrintableBoundsWeight() const
{
    return impObj()->setPrintableBoundsWeight();
}

unsigned int PyPlPlotInfoValidator::printableBoundsWeight() const
{
    return impObj()->printableBoundsWeight();
}

void PyPlPlotInfoValidator::setDimensionalWeight(unsigned int weight) const
{
    return impObj()->setDimensionalWeight(weight);
}

void PyPlPlotInfoValidator::setDefDimensionalWeight() const
{
    return impObj()->setDimensionalWeight();
}

unsigned int PyPlPlotInfoValidator::dimensionalWeight() const
{
    return impObj()->dimensionalWeight();
}

void PyPlPlotInfoValidator::setSheetDimensionalWeight(unsigned int weight) const
{
    return impObj()->setSheetDimensionalWeight(weight);
}

void PyPlPlotInfoValidator::setDefSheetDimensionalWeight() const
{
    return impObj()->setSheetDimensionalWeight();
}

unsigned int PyPlPlotInfoValidator::sheetDimensionalWeight() const
{
    return impObj()->sheetDimensionalWeight();
}

void PyPlPlotInfoValidator::setDefMediaMatchingThreshold() const
{
    return impObj()->setMediaMatchingThreshold();
}

unsigned int PyPlPlotInfoValidator::mediaMatchingThreshold() const
{
    return impObj()->mediaMatchingThreshold();
}

void PyPlPlotInfoValidator::setMediaMatchingThreshold(unsigned int threshold) const
{
    return impObj()->setMediaMatchingThreshold(threshold);
}

PyRxClass PyPlPlotInfoValidator::desc()
{
    return PyRxClass(AcPlPlotInfoValidator::desc(), false);
}

std::string PyPlPlotInfoValidator::className()
{
    return "AcPlPlotInfoValidator";
}

AcPlPlotInfoValidator* PyPlPlotInfoValidator::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcPlPlotInfoValidator*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyPlPrecisionEntry
void makePyPlPrecisionEntryWrapper()
{
    PyDocString DS("PrecisionEntry");
    class_<PyPlPrecisionEntry, bases<PyPlObject>>("PrecisionEntry")
        .def(init<>(DS.ARGS()))
        .def("title", &PyPlPrecisionEntry::title,DS.ARGS())
        .def("setTitle", &PyPlPrecisionEntry::setTitle, DS.ARGS({ "val:str" }))
        .def("description", &PyPlPrecisionEntry::description,DS.ARGS())
        .def("setDescription", &PyPlPrecisionEntry::setDescription, DS.ARGS({ "val:str" }))
        .def("unitType", &PyPlPrecisionEntry::unitType,DS.ARGS())
        .def("setUnitType", &PyPlPrecisionEntry::setUnitType, DS.ARGS({ "val:str" }))
        .def("unitScale", &PyPlPrecisionEntry::unitScale,DS.ARGS())
        .def("setUnitScale", &PyPlPrecisionEntry::setUnitScale, DS.ARGS({ "val:str" }))
        .def("desiredPrecision", &PyPlPrecisionEntry::desiredPrecision,DS.ARGS())
        .def("setDesiredPrecision", &PyPlPrecisionEntry::setDesiredPrecision, DS.ARGS({ "val:float" }))
        .def("gradientResolution", &PyPlPrecisionEntry::gradientResolution,DS.ARGS())
        .def("setGradientResolution", &PyPlPrecisionEntry::setGradientResolution, DS.ARGS({ "val:int" }))
        .def("colorResolution", &PyPlPrecisionEntry::colorResolution,DS.ARGS())
        .def("setColorResolution", &PyPlPrecisionEntry::setColorResolution, DS.ARGS({ "val:int" }))
        .def("monoResolution", &PyPlPrecisionEntry::monoResolution,DS.ARGS())
        .def("setMonoResolution", &PyPlPrecisionEntry::setMonoResolution, DS.ARGS({ "val:type" }))
        .def("desc", &PyPlPrecisionEntry::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyPlPrecisionEntry::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlPrecisionEntry::PyPlPrecisionEntry()
    : PyPlObject(new AcPlPrecisionEntry(), true)
{
}

PyPlPrecisionEntry::PyPlPrecisionEntry(AcPlPrecisionEntry* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

PyPlPrecisionEntry::PyPlPrecisionEntry(const AcPlPrecisionEntry& entry)
    : PyPlObject(new AcPlPrecisionEntry(entry), true)
{
}

const std::string PyPlPrecisionEntry::title() const
{
    return wstr_to_utf8(impObj()->title());
}

void PyPlPrecisionEntry::setTitle(const std::string& pTitle) const
{
    impObj()->setTitle(utf8_to_wstr(pTitle).c_str());
}

const std::string PyPlPrecisionEntry::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyPlPrecisionEntry::setDescription(const std::string& pDescription) const
{
    impObj()->setDescription(utf8_to_wstr(pDescription).c_str());
}

const std::string PyPlPrecisionEntry::unitType() const
{
    return wstr_to_utf8(impObj()->unitType());
}

void PyPlPrecisionEntry::setUnitType(const std::string& pUnitType) const
{
    impObj()->setUnitType(utf8_to_wstr(pUnitType).c_str());
}

const std::string PyPlPrecisionEntry::unitScale() const
{
    return wstr_to_utf8(impObj()->unitScale());
}

void PyPlPrecisionEntry::setUnitScale(const std::string& pUnitScale) const
{
    impObj()->setUnitScale(utf8_to_wstr(pUnitScale).c_str());
}

double PyPlPrecisionEntry::desiredPrecision() const
{
    return impObj()->desiredPrecision();
}

void PyPlPrecisionEntry::setDesiredPrecision(double dDesiredPrecision) const
{
    return impObj()->setDesiredPrecision(dDesiredPrecision);
}

int PyPlPrecisionEntry::gradientResolution() const
{
    return impObj()->gradientResolution();
}

void PyPlPrecisionEntry::setGradientResolution(int nGradientResolution) const
{
    return impObj()->setGradientResolution(nGradientResolution);
}

int PyPlPrecisionEntry::colorResolution() const
{
    return impObj()->colorResolution();
}

void PyPlPrecisionEntry::setColorResolution(int nColorResolution) const
{
    return impObj()->setColorResolution(nColorResolution);
}

int PyPlPrecisionEntry::monoResolution() const
{
    return impObj()->monoResolution();
}

void PyPlPrecisionEntry::setMonoResolution(int nMonoResolution) const
{
    return impObj()->setMonoResolution(nMonoResolution);
}

PyRxClass PyPlPrecisionEntry::desc()
{
    return PyRxClass(AcPlPrecisionEntry::desc(), false);
}

std::string PyPlPrecisionEntry::className()
{
    return "AcPlPrecisionEntry";
}

AcPlPrecisionEntry* PyPlPrecisionEntry::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcPlPrecisionEntry*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PylPlotConfigInfo
void makePyPlPlotConfigInfoWrapper()
{
    PyDocString DS("PlotConfigInfo");
    class_<PyPlPlotConfigInfo, bases<PyPlObject>>("PlotConfigInfo")
        .def(init<>())
        .def(init<const std::string&, const std::string&, DeviceType>())
        .def("fullPath", &PyPlPlotConfigInfo::fullPath,DS.ARGS())
        .def("setFullPath", &PyPlPlotConfigInfo::setFullPath, DS.ARGS({ "val:str" }))
        .def("deviceName", &PyPlPlotConfigInfo::deviceName,DS.ARGS())
        .def("setDeviceName", &PyPlPlotConfigInfo::setDeviceName, DS.ARGS({ "val:str" }))
        .def("deviceType", &PyPlPlotConfigInfo::deviceType,DS.ARGS())
        .def("setDeviceType", &PyPlPlotConfigInfo::setDeviceType, DS.ARGS({ "val:PyPl.DeviceType" }))
        .def("deviceId", &PyPlPlotConfigInfo::deviceId,DS.ARGS())
        .def("setDeviceId", &PyPlPlotConfigInfo::setDeviceId, DS.ARGS({ "val:type" }))
        .def("desc", &PyPlPlotConfigInfo::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyPlPlotConfigInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyPlPlotConfigInfo::PyPlPlotConfigInfo()
    : PyPlObject(new AcPlPlotConfigInfo(), true)
{
}

PyPlPlotConfigInfo::PyPlPlotConfigInfo(const std::string& pDevName, const std::string& pFullPath, DeviceType devType)
    : PyPlObject(new AcPlPlotConfigInfo(utf8_to_wstr(pDevName).c_str(), utf8_to_wstr(pFullPath).c_str(), devType), true)
{
}

PyPlPlotConfigInfo::PyPlPlotConfigInfo(AcPlPlotInfoValidator* ptr, bool autoDelete)
    : PyPlObject(ptr, autoDelete)
{
}

PyPlPlotConfigInfo::PyPlPlotConfigInfo(const AcPlPlotConfigInfo& copy)
    : PyPlObject(new AcPlPlotConfigInfo(copy), true)
{
}

std::string PyPlPlotConfigInfo::fullPath() const
{
    return wstr_to_utf8(impObj()->fullPath());
}

void PyPlPlotConfigInfo::setFullPath(const std::string& pPath) const
{
    impObj()->setFullPath(utf8_to_wstr(pPath).c_str());
}

std::string PyPlPlotConfigInfo::deviceName() const
{
    return wstr_to_utf8(impObj()->deviceName());
}

void PyPlPlotConfigInfo::setDeviceName(const std::string& pDevName) const
{
    impObj()->setDeviceName(utf8_to_wstr(pDevName).c_str());
}

DeviceType PyPlPlotConfigInfo::deviceType() const
{
    return impObj()->deviceType();
}

void PyPlPlotConfigInfo::setDeviceType(DeviceType devType) const
{
    impObj()->setDeviceType(devType);
}

std::string PyPlPlotConfigInfo::deviceId() const
{
#if defined(_GRXTARGET) && (_GRXTARGET <= 260)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->deviceId());
#endif
}

void PyPlPlotConfigInfo::setDeviceId(const std::string& pDevId) const
{
#if defined(_GRXTARGET) && (_GRXTARGET <= 260)
    throw PyNotimplementedByHost();
#else
    impObj()->setDeviceId(utf8_to_wstr(pDevId).c_str());
#endif
}

PyRxClass PyPlPlotConfigInfo::desc()
{
    return PyRxClass(AcPlPlotConfigInfo::desc(), false);
}

std::string PyPlPlotConfigInfo::className()
{
    return "AcPlPlotConfigInfo";
}

AcPlPlotConfigInfo* PyPlPlotConfigInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcPlPlotConfigInfo*>(m_pyImp.get());
}
#endif