#include "stdafx.h"
#include "PyPlObject.h"
#include "PyDbLayout.h"
#include "PyDbObjectId.h"
#include "PyPlPlotProgressDialog.h"
#include "PyGeBoundBlock2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//AcPlPlotFactory
void makeAcPlPlotFactoryWrapper()
{
    PyDocString DS("PlotFactory");
    class_<PyPlPlotFactory>("PlotFactory", boost::python::no_init)
        .def("createPreviewEngine", &PyPlPlotFactory::createPreviewEngine1)
        .def("createPreviewEngine", &PyPlPlotFactory::createPreviewEngine2, DS.SARGS({ "flags : int = default" })).staticmethod("createPreviewEngine")
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
        .def("beginPlot", &PyPlPlotEngine::beginPlot)
        .def("endPlot", &PyPlPlotEngine::endPlot)
        .def("beginDocument", &PyPlPlotEngine::beginDocument)
        .def("endDocument", &PyPlPlotEngine::endDocument)
        .def("beginPage", &PyPlPlotEngine::beginPage)
        .def("endPage", &PyPlPlotEngine::endPage)
        .def("beginGenerateGraphics", &PyPlPlotEngine::beginGenerateGraphics)
        .def("endGenerateGraphics", &PyPlPlotEngine::endGenerateGraphics)
        .def("destroy", &PyPlPlotEngine::destroy)
        .def("isBackgroundPackaging", &PyPlPlotEngine::isBackgroundPackaging)
        .def("className", &PyPlPlotEngine::className, DS.SARGS()).staticmethod("className")
        ;
}

struct PyPlPlotEngineDeleter
{
    inline void operator()(AcPlPlotEngine* p) const
    {
        if (p == nullptr) [[unlikely]]
            return;
            p->destroy();
    };
};

PyPlPlotEngine::PyPlPlotEngine(AcPlPlotEngine* ptr)
    : m_imp(ptr, PyPlPlotEngineDeleter())
{
}

void PyPlPlotEngine::beginPlot(PyPlPlotProgressDialog& pPlotProgress)
{
    PyThrowBadEs(impObj()->beginPlot(pPlotProgress.impObj()));
}

void PyPlPlotEngine::endPlot()
{
    PyThrowBadEs(impObj()->endPlot());
}

void PyPlPlotEngine::beginDocument(PyPlPlotInfo& plotInfo, const std::string& pDocname, Adesk::Int32 nCopies, bool bPlotToFile, const std::string& pFileName)
{
    PyThrowBadEs(impObj()->beginDocument(*plotInfo.impObj(), utf8_to_wstr(pDocname).c_str(), NULL, nCopies, bPlotToFile, utf8_to_wstr(pFileName).c_str()));
}

void PyPlPlotEngine::endDocument()
{
    PyThrowBadEs(impObj()->endDocument());
}

void PyPlPlotEngine::beginPage(PyPlPlotPageInfo& pageInfo, PyPlPlotInfo& plotInfo, bool bLastPage)
{
    PyThrowBadEs(impObj()->beginPage(*pageInfo.impObj(), *plotInfo.impObj(), bLastPage));
}

void PyPlPlotEngine::endPage()
{
    PyThrowBadEs(impObj()->endPage());
}

void PyPlPlotEngine::beginGenerateGraphics()
{
    PyThrowBadEs(impObj()->beginGenerateGraphics());
}

void PyPlPlotEngine::endGenerateGraphics()
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
        .def("projectPath", &PyPlDSDData::projectPath)
        .def("setProjectPath", &PyPlDSDData::setProjectPath)
        .def("destinationName", &PyPlDSDData::destinationName)
        .def("setDestinationName", &PyPlDSDData::setDestinationName)
        .def("getDSDEntries", &PyPlDSDData::getDSDEntries)
        .def("setDSDEntries", &PyPlDSDData::setDSDEntries)
        .def("getPrecisionEntries", &PyPlDSDData::getPrecisionEntries)
        .def("setPrecisionEntries", &PyPlDSDData::setPrecisionEntries)
        .def("numberOfDSDEntries", &PyPlDSDData::numberOfDSDEntries)
        .def("sheetType", &PyPlDSDData::sheetType)
        .def("setSheetType", &PyPlDSDData::setSheetType)
        .def("password", &PyPlDSDData::password)
        .def("setPassword", &PyPlDSDData::setPassword)
        .def("getUnrecognizedData", &PyPlDSDData::getUnrecognizedData)
        .def("setUnrecognizedData", &PyPlDSDData::setUnrecognizedData1)
        .def("setUnrecognizedData", &PyPlDSDData::setUnrecognizedData2)
        .def("majorVersion", &PyPlDSDData::majorVersion)
        .def("setMajorVersion", &PyPlDSDData::setMajorVersion)
        .def("minorVersion", &PyPlDSDData::minorVersion)
        .def("setMinorVersion", &PyPlDSDData::setMinorVersion)
        .def("sheetSetName", &PyPlDSDData::sheetSetName)
        .def("setSheetSetName", &PyPlDSDData::setSheetSetName)
        .def("noOfCopies", &PyPlDSDData::noOfCopies)
        .def("setNoOfCopies", &PyPlDSDData::setNoOfCopies)
        .def("setIsSheetSet", &PyPlDSDData::setIsSheetSet)
        .def("isSheetSet", &PyPlDSDData::isSheetSet)
        .def("isHomogeneous", &PyPlDSDData::isHomogeneous)
        .def("setIsHomogeneous", &PyPlDSDData::setIsHomogeneous)
        .def("plotStampOn", &PyPlDSDData::plotStampOn)
        .def("setPlotStampOn", &PyPlDSDData::setPlotStampOn)
        .def("viewFile", &PyPlDSDData::viewFile)
        .def("setViewFile", &PyPlDSDData::setViewFile)
        .def("selectionSetName", &PyPlDSDData::selectionSetName)
        .def("setSelectionSetName", &PyPlDSDData::setSelectionSetName)
        .def("categoryName", &PyPlDSDData::categoryName)
        .def("setCategoryName", &PyPlDSDData::setCategoryName)
        .def("logFilePath", &PyPlDSDData::logFilePath)
        .def("setLogFilePath", &PyPlDSDData::setLogFilePath)
        .def("get3dDwfOptions", &PyPlDSDData::get3dDwfOptions)
        .def("set3dDwfOptions", &PyPlDSDData::set3dDwfOptions)
        .def("includeLayerInfo", &PyPlDSDData::includeLayerInfo)
        .def("setIncludeLayerInfo", &PyPlDSDData::setIncludeLayerInfo)
        .def("lineMerge", &PyPlDSDData::lineMerge)
        .def("setLineMerge", &PyPlDSDData::setLineMerge)
        .def("currentPrecision", &PyPlDSDData::currentPrecision)
        .def("setCurrentPrecision", &PyPlDSDData::setCurrentPrecision)
        .def("promptForDwfName", &PyPlDSDData::promptForDwfName)
        .def("setPromptForDwfName", &PyPlDSDData::setPromptForDwfName)
        .def("pwdProtectPublishedDWF", &PyPlDSDData::pwdProtectPublishedDWF)
        .def("setPwdProtectPublishedDWF", &PyPlDSDData::setPwdProtectPublishedDWF)
        .def("promptForPassword", &PyPlDSDData::promptForPassword)
        .def("setPromptForPassword", &PyPlDSDData::setPromptForPassword)
        .def("initializeLayouts", &PyPlDSDData::initializeLayouts)
        .def("setInitializeLayouts", &PyPlDSDData::setInitializeLayouts)
        .def("desc", &PyPlDSDData::desc, DS.SARGS()).staticmethod("desc")
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

void PyPlDSDData::setProjectPath(const std::string& pVal)
{
    impObj()->setProjectPath(utf8_to_wstr(pVal).c_str());
}

std::string PyPlDSDData::destinationName() const
{
    return wstr_to_utf8(impObj()->destinationName());
}

void PyPlDSDData::setDestinationName(const std::string& pVal)
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

void PyPlDSDData::setDSDEntries(const boost::python::list& val)
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

void PyPlDSDData::setPrecisionEntries(const boost::python::list& val)
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

PyPlDSDEntry PyPlDSDData::DSDEntryAt(int idx)
{
    return PyPlDSDEntry(impObj()->DSDEntryAt(idx));
}

AcPlDSDEntry::SheetType PyPlDSDData::sheetType() const
{
    return impObj()->sheetType();
}

void PyPlDSDData::setSheetType(AcPlDSDEntry::SheetType val)
{
    return impObj()->setSheetType(val);
}

std::string PyPlDSDData::password() const
{
    return wstr_to_utf8(impObj()->password());
}

void PyPlDSDData::setPassword(const std::string& pVal)
{
    impObj()->setPassword(utf8_to_wstr(pVal).c_str());
}

void PyPlDSDData::getUnrecognizedData(boost::python::list& sectionArray, boost::python::list& dataArray) const
{
    AcStringArray _sectionArray;
    AcStringArray _dataArray;
    impObj()->getUnrecognizedData(_sectionArray, _dataArray);
    for (const auto& item : _sectionArray)
        sectionArray.append(wstr_to_utf8(item));
    for (const auto& item : _dataArray)
        dataArray.append(wstr_to_utf8(item));
}

void PyPlDSDData::setUnrecognizedData1(const std::string& pSectionName, const std::string& pSectionData)
{
    impObj()->setUnrecognizedData(utf8_to_wstr(pSectionName).c_str(), utf8_to_wstr(pSectionData).c_str());
}

void PyPlDSDData::setUnrecognizedData2(const boost::python::list& sectionArray, const boost::python::list& dataArray)
{
    impObj()->setUnrecognizedData(PyListAcStringArray(sectionArray), PyListAcStringArray(dataArray));
}

unsigned int PyPlDSDData::majorVersion() const
{
    return impObj()->majorVersion();
}

void PyPlDSDData::setMajorVersion(unsigned int majorVersion)
{
    return impObj()->setMajorVersion(majorVersion);
}

unsigned int PyPlDSDData::minorVersion() const
{
    return impObj()->minorVersion();
}

void PyPlDSDData::setMinorVersion(unsigned int minorVersion)
{
    return impObj()->setMinorVersion(minorVersion);
}

std::string PyPlDSDData::sheetSetName() const
{
    return wstr_to_utf8(impObj()->sheetSetName());
}

void PyPlDSDData::setSheetSetName(const std::string& pSheetSetName)
{
    return impObj()->setSheetSetName(utf8_to_wstr(pSheetSetName).c_str());
}

unsigned int PyPlDSDData::noOfCopies() const
{
    return impObj()->noOfCopies();
}

void PyPlDSDData::setNoOfCopies(unsigned int copies)
{
    return impObj()->setNoOfCopies(copies);
}

void PyPlDSDData::setIsSheetSet(bool bSheetSet)
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

void PyPlDSDData::setIsHomogeneous(bool bHomogeneous)
{
    return impObj()->setIsHomogeneous(bHomogeneous);
}

bool PyPlDSDData::plotStampOn() const
{
    return impObj()->plotStampOn();
}

void PyPlDSDData::setPlotStampOn(bool bOn)
{
    return impObj()->setPlotStampOn(bOn);
}

bool PyPlDSDData::viewFile() const
{
    return impObj()->viewFile();
}

void PyPlDSDData::setViewFile(bool bViewFile)
{
    return impObj()->setViewFile(bViewFile);
}

std::string PyPlDSDData::selectionSetName() const
{
    return wstr_to_utf8(impObj()->selectionSetName());
}

void PyPlDSDData::setSelectionSetName(const std::string& pSelSetName)
{
    return impObj()->setSelectionSetName(utf8_to_wstr(pSelSetName).c_str());
}

std::string PyPlDSDData::categoryName() const
{
    return wstr_to_utf8(impObj()->categoryName());
}

void PyPlDSDData::setCategoryName(const std::string& pCategoryName)
{
    return impObj()->setCategoryName(utf8_to_wstr(pCategoryName).c_str());
}

std::string PyPlDSDData::logFilePath() const
{
    return wstr_to_utf8(impObj()->logFilePath());
}

void PyPlDSDData::setLogFilePath(const std::string& pLogFilePath)
{
    return impObj()->setLogFilePath(utf8_to_wstr(pLogFilePath).c_str());
}

boost::python::tuple PyPlDSDData::get3dDwfOptions() const
{
    PyAutoLockGIL lock;
    const AcPl3dDwfOptions& opt = impObj()->get3dDwfOptions();
    return boost::python::make_tuple(opt.bGroupByXrefHierarchy, opt.bPublishWithMaterials);
}

void PyPlDSDData::set3dDwfOptions(bool bGroupByXrefHierarchy, bool bPublishWithMaterials)
{
    AcPl3dDwfOptions opt = { bGroupByXrefHierarchy ,bPublishWithMaterials };
    impObj()->set3dDwfOptions(opt);
}

bool PyPlDSDData::includeLayerInfo() const
{
    return impObj()->includeLayerInfo();
}

void PyPlDSDData::setIncludeLayerInfo(bool bOn)
{
    return impObj()->setIncludeLayerInfo(bOn);
}

bool PyPlDSDData::lineMerge() const
{
    return impObj()->lineMerge();
}

void PyPlDSDData::setLineMerge(bool bOn)
{
    return impObj()->setLineMerge(bOn);
}

std::string PyPlDSDData::currentPrecision() const
{
    return wstr_to_utf8(impObj()->currentPrecision());
}

void PyPlDSDData::setCurrentPrecision(const std::string& pCurrentPrecision)
{
    return impObj()->setCurrentPrecision(utf8_to_wstr(pCurrentPrecision).c_str());
}

bool PyPlDSDData::promptForDwfName() const
{
    return impObj()->promptForDwfName();
}

void PyPlDSDData::setPromptForDwfName(bool bPromptForDwfName)
{
    return impObj()->setPromptForDwfName(bPromptForDwfName);
}

bool PyPlDSDData::pwdProtectPublishedDWF() const
{
    return impObj()->pwdProtectPublishedDWF();
}

void PyPlDSDData::setPwdProtectPublishedDWF(bool bPwdProtectPublishedDWF)
{
    return impObj()->setPwdProtectPublishedDWF(bPwdProtectPublishedDWF);
}

bool PyPlDSDData::promptForPassword() const
{
    return impObj()->promptForPassword();
}

void PyPlDSDData::setPromptForPassword(bool bPromptForPassword)
{
    return impObj()->setPromptForPassword(bPromptForPassword);
}

bool PyPlDSDData::initializeLayouts() const
{
#ifdef _ZRXTARGET 
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

void PyPlDSDData::setInitializeLayouts(bool initLayouts)
{
#ifdef _ZRXTARGET 
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
        .def("dwgName", &PyPlDSDEntry::dwgName)
        .def("setDwgName", &PyPlDSDEntry::setDwgName)
        .def("layout", &PyPlDSDEntry::layout)
        .def("setLayout", &PyPlDSDEntry::setLayout)
        .def("title", &PyPlDSDEntry::title)
        .def("setTitle", &PyPlDSDEntry::setTitle)
        .def("NPS", &PyPlDSDEntry::NPS)
        .def("setNPS", &PyPlDSDEntry::setNPS)
        .def("NPSSourceDWG", &PyPlDSDEntry::NPSSourceDWG)
        .def("setNPSSourceDWG", &PyPlDSDEntry::setNPSSourceDWG)
        .def("has3dDwfSetup", &PyPlDSDEntry::has3dDwfSetup)
        .def("setHas3dDwfSetup", &PyPlDSDEntry::setHas3dDwfSetup)
        .def("setupType", &PyPlDSDEntry::setupType)
        .def("setSetupType", &PyPlDSDEntry::setSetupType)
        .def("orgSheetPath", &PyPlDSDEntry::orgSheetPath)
        .def("traceSession", &PyPlDSDEntry::traceSession)
        .def("setTraceSession", &PyPlDSDEntry::setTraceSession)
        .def("desc", &PyPlDSDEntry::desc, DS.SARGS()).staticmethod("desc")
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

void PyPlDSDEntry::setDwgName(const std::string& pName)
{
    impObj()->setDwgName(utf8_to_wstr(pName).c_str());
}

std::string PyPlDSDEntry::layout() const
{
    return wstr_to_utf8(impObj()->layout());
}

void PyPlDSDEntry::setLayout(const std::string& pLayoutName)
{
    impObj()->setLayout(utf8_to_wstr(pLayoutName).c_str());
}

std::string PyPlDSDEntry::title() const
{
    return wstr_to_utf8(impObj()->title());
}

void PyPlDSDEntry::setTitle(const std::string& pTitle)
{
    impObj()->setLayout(utf8_to_wstr(pTitle).c_str());
}

std::string PyPlDSDEntry::NPS() const
{
    return wstr_to_utf8(impObj()->NPS());
}

void PyPlDSDEntry::setNPS(const std::string& pNPSName)
{
    impObj()->setNPS(utf8_to_wstr(pNPSName).c_str());
}

std::string PyPlDSDEntry::NPSSourceDWG() const
{
    return wstr_to_utf8(impObj()->NPSSourceDWG());
}

void PyPlDSDEntry::setNPSSourceDWG(const std::string& pNPWDWGName)
{
    impObj()->setNPSSourceDWG(utf8_to_wstr(pNPWDWGName).c_str());
}

bool PyPlDSDEntry::has3dDwfSetup() const
{
    return impObj()->has3dDwfSetup();
}

void PyPlDSDEntry::setHas3dDwfSetup(bool b3dDwfSetup)
{
    return impObj()->setHas3dDwfSetup(b3dDwfSetup);
}

AcPlDSDEntry::SetupType PyPlDSDEntry::setupType() const
{
    return impObj()->setupType();
}

void PyPlDSDEntry::setSetupType(AcPlDSDEntry::SetupType eType)
{
    return impObj()->setSetupType(eType);
}

std::string PyPlDSDEntry::orgSheetPath() const
{
    return wstr_to_utf8(impObj()->orgSheetPath());
}

std::string PyPlDSDEntry::traceSession() const
{
#ifdef _ZRXTARGET 
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

void PyPlDSDEntry::setTraceSession(const std::string& pTraceSession)
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
        .def("copyFrom", &PyPlPlotInfo::copyFrom)
        .def("setLayout", &PyPlPlotInfo::setLayout)
        .def("layout", &PyPlPlotInfo::layout)
        .def("setOverrideSettings", &PyPlPlotInfo::setOverrideSettings)
        .def("overrideSettings", &PyPlPlotInfo::overrideSettings)
        .def("setDeviceOverride", &PyPlPlotInfo::setDeviceOverride)
        .def("validatedSettings", &PyPlPlotInfo::validatedSettings)
        .def("setValidatedSettings", &PyPlPlotInfo::setValidatedSettings)
        .def("validatedConfig", &PyPlPlotInfo::validatedConfig)
        .def("setValidatedConfig", &PyPlPlotInfo::setValidatedConfig)
        .def("deviceOverride", &PyPlPlotInfo::deviceOverride)
        .def("isCompatibleDocument", &PyPlPlotInfo::isCompatibleDocument)
        .def("isValidated", &PyPlPlotInfo::isValidated)
        .def("mergeStatus", &PyPlPlotInfo::mergeStatus)
        .def("OrgFilePath", &PyPlPlotInfo::OrgFilePath)
        .def("desc", &PyPlPlotInfo::desc, DS.SARGS()).staticmethod("desc")
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

void PyPlPlotInfo::copyFrom(const PyRxObject& pOther)
{
    PyThrowBadEs(impObj()->copyFrom(pOther.impObj()));
}

void PyPlPlotInfo::setLayout(PyDbObjectId& layoutId)
{
    impObj()->setLayout(layoutId.m_id);
}

PyDbObjectId PyPlPlotInfo::layout() const
{
    return PyDbObjectId(impObj()->layout());
}

void PyPlPlotInfo::setOverrideSettings(const PyDbPlotSettings& pOverrides)
{
    impObj()->setOverrideSettings(pOverrides.impObj());
}

PyDbPlotSettings PyPlPlotInfo::overrideSettings() const
{
    return PyDbPlotSettings(impObj()->overrideSettings());
}

void PyPlPlotInfo::setDeviceOverride(const PyPlPlotConfig& pconf)
{
    impObj()->setDeviceOverride(pconf.impObj());
}

PyDbPlotSettings PyPlPlotInfo::validatedSettings() const
{
    return PyDbPlotSettings(impObj()->validatedSettings());
}

void PyPlPlotInfo::setValidatedSettings(const PyDbPlotSettings& pValidatedSettings)
{
    impObj()->setOverrideSettings(pValidatedSettings.impObj());
}

PyPlPlotConfig PyPlPlotInfo::validatedConfig() const
{
    return PyPlPlotConfig(impObj()->validatedConfig());
}

void PyPlPlotInfo::setValidatedConfig(const PyPlPlotConfig& pConfig)
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

std::string PyPlPlotInfo::OrgFilePath()
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
        .def("getDescriptionFields", &PyPlPlotConfig::getDescriptionFields)
        .def("deviceName", &PyPlPlotConfig::deviceName)
        .def("fullPath", &PyPlPlotConfig::fullPath)
        .def("maxDeviceDPI", &PyPlPlotConfig::maxDeviceDPI)
        .def("deviceType", &PyPlPlotConfig::deviceType)
        .def("getCanonicalMediaNameList", &PyPlPlotConfig::getCanonicalMediaNameList)
        .def("getLocalMediaName", &PyPlPlotConfig::getLocalMediaName)
        .def("getMediaBounds", &PyPlPlotConfig::getMediaBounds)
        .def("refreshMediaNameList", &PyPlPlotConfig::refreshMediaNameList)
        .def("isPlotToFile", &PyPlPlotConfig::isPlotToFile)
        .def("setPlotToFile", &PyPlPlotConfig::setPlotToFile)
        .def("getDefaultFileExtension", &PyPlPlotConfig::getDefaultFileExtension)
        .def("plotToFileCapability", &PyPlPlotConfig::plotToFileCapability)
        .def("saveToPC3", &PyPlPlotConfig::saveToPC3)
        .def("desc", &PyPlPlotConfig::desc, DS.SARGS()).staticmethod("desc")
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

void PyPlPlotConfig::getMediaBounds(const std::string& pCanonicalMediaName, AcGePoint2d& pageSize, PyGeBoundBlock2d& printableArea) const
{
    impObj()->getMediaBounds(utf8_to_wstr(pCanonicalMediaName).c_str(), pageSize, *printableArea.impObj());
}

void PyPlPlotConfig::refreshMediaNameList()
{
    impObj()->refreshMediaNameList();
}

bool PyPlPlotConfig::isPlotToFile() const
{
    return impObj()->isPlotToFile();
}

void PyPlPlotConfig::setPlotToFile(bool bPlotToFile)
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

bool PyPlPlotConfig::saveToPC3(const std::string& pPC3Name)
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
        .def("entityCount", &PyPlPlotPageInfo::entityCount, DS.SARGS())
        .def("rasterCount", &PyPlPlotPageInfo::rasterCount, DS.SARGS())
        .def("oleObjectCount", &PyPlPlotPageInfo::oleObjectCount, DS.SARGS())
        .def("gradientCount", &PyPlPlotPageInfo::gradientCount, DS.SARGS())
        .def("shadedViewportType", &PyPlPlotPageInfo::shadedViewportType, DS.SARGS())
        .def("desc", &PyPlPlotPageInfo::desc, DS.SARGS()).staticmethod("desc")
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
        .def("validate", &PyPlPlotInfoValidator::validate)
        .def("isCustomPossible", &PyPlPlotInfoValidator::isCustomPossible)
        .def("matchingPolicy", &PyPlPlotInfoValidator::matchingPolicy)
        .def("setMediaMatchingPolicy", &PyPlPlotInfoValidator::setMediaMatchingPolicy)
        .def("setMediaGroupWeight", &PyPlPlotInfoValidator::setMediaGroupWeight)
        .def("setDefMediaGroupWeight", &PyPlPlotInfoValidator::setDefMediaGroupWeight)
        .def("mediaGroupWeight", &PyPlPlotInfoValidator::mediaGroupWeight)
        .def("setSheetMediaGroupWeight", &PyPlPlotInfoValidator::setSheetMediaGroupWeight)
        .def("setDefSheetMediaGroupWeight", &PyPlPlotInfoValidator::setDefSheetMediaGroupWeight)
        .def("sheetMediaGroupWeight", &PyPlPlotInfoValidator::sheetMediaGroupWeight)
        .def("setMediaBoundsWeight", &PyPlPlotInfoValidator::setMediaBoundsWeight)
        .def("setDefMediaBoundsWeight", &PyPlPlotInfoValidator::setDefMediaBoundsWeight)
        .def("mediaBoundsWeight", &PyPlPlotInfoValidator::mediaBoundsWeight)
        .def("setPrintableBoundsWeight", &PyPlPlotInfoValidator::setPrintableBoundsWeight)
        .def("setDefPrintableBoundsWeight", &PyPlPlotInfoValidator::setDefPrintableBoundsWeight)
        .def("printableBoundsWeight", &PyPlPlotInfoValidator::printableBoundsWeight)
        .def("setDimensionalWeight", &PyPlPlotInfoValidator::setDimensionalWeight)
        .def("setDefDimensionalWeight", &PyPlPlotInfoValidator::setDefDimensionalWeight)
        .def("dimensionalWeight", &PyPlPlotInfoValidator::dimensionalWeight)
        .def("setSheetDimensionalWeight", &PyPlPlotInfoValidator::setSheetDimensionalWeight)
        .def("setDefSheetDimensionalWeight", &PyPlPlotInfoValidator::setDefSheetDimensionalWeight)
        .def("sheetDimensionalWeight", &PyPlPlotInfoValidator::sheetDimensionalWeight)
        .def("setMediaMatchingThreshold", &PyPlPlotInfoValidator::setMediaMatchingThreshold)
        .def("setDefMediaMatchingThreshold", &PyPlPlotInfoValidator::setDefMediaMatchingThreshold)
        .def("mediaMatchingThreshold", &PyPlPlotInfoValidator::mediaMatchingThreshold)
        .def("desc", &PyPlPlotInfoValidator::desc, DS.SARGS()).staticmethod("desc")
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

void PyPlPlotInfoValidator::validate(PyPlPlotInfo& info)
{
    PyThrowBadEs(impObj()->validate(*info.impObj()));
}

AcPlPlotInfoValidator::eCustomSizeResult PyPlPlotInfoValidator::isCustomPossible(PyPlPlotInfo& info)
{
    return (AcPlPlotInfoValidator::eCustomSizeResult)impObj()->isCustomPossible(*info.impObj());
}

AcPlPlotInfoValidator::MatchingPolicy PyPlPlotInfoValidator::matchingPolicy() const
{
    return impObj()->matchingPolicy();
}

void PyPlPlotInfoValidator::setMediaMatchingPolicy(AcPlPlotInfoValidator::MatchingPolicy policy)
{
    impObj()->setMediaMatchingPolicy(policy);
}

void PyPlPlotInfoValidator::setMediaGroupWeight(unsigned int weight)
{
    impObj()->setMediaGroupWeight(weight);
}

void PyPlPlotInfoValidator::setDefMediaGroupWeight()
{
    impObj()->setMediaGroupWeight();
}

unsigned int PyPlPlotInfoValidator::mediaGroupWeight() const
{
    return impObj()->mediaGroupWeight();
}

void PyPlPlotInfoValidator::setSheetMediaGroupWeight(unsigned int weight)
{
    impObj()->setSheetMediaGroupWeight(weight);
}

void PyPlPlotInfoValidator::setDefSheetMediaGroupWeight()
{
    impObj()->setSheetMediaGroupWeight();
}

unsigned int PyPlPlotInfoValidator::sheetMediaGroupWeight() const
{
    return impObj()->sheetMediaGroupWeight();
}

void PyPlPlotInfoValidator::setMediaBoundsWeight(unsigned int weight)
{
    return impObj()->setMediaBoundsWeight(weight);
}

void PyPlPlotInfoValidator::setDefMediaBoundsWeight()
{
    return impObj()->setMediaBoundsWeight();
}

unsigned int PyPlPlotInfoValidator::mediaBoundsWeight() const
{
    return impObj()->mediaBoundsWeight();
}

void PyPlPlotInfoValidator::setPrintableBoundsWeight(unsigned int weight)
{
    return impObj()->setPrintableBoundsWeight(weight);
}

void PyPlPlotInfoValidator::setDefPrintableBoundsWeight()
{
    return impObj()->setPrintableBoundsWeight();
}

unsigned int PyPlPlotInfoValidator::printableBoundsWeight() const
{
    return impObj()->printableBoundsWeight();
}

void PyPlPlotInfoValidator::setDimensionalWeight(unsigned int weight)
{
    return impObj()->setDimensionalWeight(weight);
}

void PyPlPlotInfoValidator::setDefDimensionalWeight()
{
    return impObj()->setDimensionalWeight();
}

unsigned int PyPlPlotInfoValidator::dimensionalWeight() const
{
    return impObj()->dimensionalWeight();
}

void PyPlPlotInfoValidator::setSheetDimensionalWeight(unsigned int weight)
{
    return impObj()->setSheetDimensionalWeight(weight);
}

void PyPlPlotInfoValidator::setDefSheetDimensionalWeight()
{
    return impObj()->setSheetDimensionalWeight();
}

unsigned int PyPlPlotInfoValidator::sheetDimensionalWeight() const
{
    return impObj()->sheetDimensionalWeight();
}

void PyPlPlotInfoValidator::setDefMediaMatchingThreshold()
{
    return impObj()->setMediaMatchingThreshold();
}

unsigned int PyPlPlotInfoValidator::mediaMatchingThreshold() const
{
    return impObj()->mediaMatchingThreshold();
}

void PyPlPlotInfoValidator::setMediaMatchingThreshold(unsigned int threshold)
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
        .def(init<>())
        .def("title", &PyPlPrecisionEntry::title)
        .def("setTitle", &PyPlPrecisionEntry::setTitle)
        .def("description", &PyPlPrecisionEntry::description)
        .def("setDescription", &PyPlPrecisionEntry::setDescription)
        .def("unitType", &PyPlPrecisionEntry::unitType)
        .def("setUnitType", &PyPlPrecisionEntry::setUnitType)
        .def("unitScale", &PyPlPrecisionEntry::unitScale)
        .def("setUnitScale", &PyPlPrecisionEntry::setUnitScale)
        .def("desiredPrecision", &PyPlPrecisionEntry::desiredPrecision)
        .def("setDesiredPrecision", &PyPlPrecisionEntry::setDesiredPrecision)
        .def("gradientResolution", &PyPlPrecisionEntry::gradientResolution)
        .def("setGradientResolution", &PyPlPrecisionEntry::setGradientResolution)
        .def("colorResolution", &PyPlPrecisionEntry::colorResolution)
        .def("setColorResolution", &PyPlPrecisionEntry::setColorResolution)
        .def("monoResolution", &PyPlPrecisionEntry::monoResolution)
        .def("setMonoResolution", &PyPlPrecisionEntry::setMonoResolution)
        .def("desc", &PyPlPrecisionEntry::desc, DS.SARGS()).staticmethod("desc")
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

void PyPlPrecisionEntry::setTitle(const std::string& pTitle)
{
    impObj()->setTitle(utf8_to_wstr(pTitle).c_str());
}

const std::string PyPlPrecisionEntry::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyPlPrecisionEntry::setDescription(const std::string& pDescription)
{
    impObj()->setDescription(utf8_to_wstr(pDescription).c_str());
}

const std::string PyPlPrecisionEntry::unitType() const
{
    return wstr_to_utf8(impObj()->unitType());
}

void PyPlPrecisionEntry::setUnitType(const std::string& pUnitType)
{
    impObj()->setUnitType(utf8_to_wstr(pUnitType).c_str());
}

const std::string PyPlPrecisionEntry::unitScale() const
{
    return wstr_to_utf8(impObj()->unitScale());
}

void PyPlPrecisionEntry::setUnitScale(const std::string& pUnitScale)
{
    impObj()->setUnitScale(utf8_to_wstr(pUnitScale).c_str());
}

double PyPlPrecisionEntry::desiredPrecision() const
{
    return impObj()->desiredPrecision();
}

void PyPlPrecisionEntry::setDesiredPrecision(double dDesiredPrecision)
{
    return impObj()->setDesiredPrecision(dDesiredPrecision);
}

int PyPlPrecisionEntry::gradientResolution() const
{
    return impObj()->gradientResolution();
}

void PyPlPrecisionEntry::setGradientResolution(int nGradientResolution)
{
    return impObj()->setGradientResolution(nGradientResolution);
}

int PyPlPrecisionEntry::colorResolution() const
{
    return impObj()->colorResolution();
}

void PyPlPrecisionEntry::setColorResolution(int nColorResolution)
{
    return impObj()->setColorResolution(nColorResolution);
}

int PyPlPrecisionEntry::monoResolution() const
{
    return impObj()->monoResolution();
}

void PyPlPrecisionEntry::setMonoResolution(int nMonoResolution)
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
        .def("fullPath", &PyPlPlotConfigInfo::fullPath)
        .def("setFullPath", &PyPlPlotConfigInfo::setFullPath)
        .def("deviceName", &PyPlPlotConfigInfo::deviceName)
        .def("setDeviceName", &PyPlPlotConfigInfo::setDeviceName)
        .def("deviceType", &PyPlPlotConfigInfo::deviceType)
        .def("setDeviceType", &PyPlPlotConfigInfo::setDeviceType)
        .def("deviceId", &PyPlPlotConfigInfo::deviceId)
        .def("setDeviceId", &PyPlPlotConfigInfo::setDeviceId)
        .def("desc", &PyPlPlotConfigInfo::desc, DS.SARGS()).staticmethod("desc")
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

void PyPlPlotConfigInfo::setFullPath(const std::string& pPath)
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

void PyPlPlotConfigInfo::setDeviceType(DeviceType devType)
{
    impObj()->setDeviceType(devType);
}

std::string PyPlPlotConfigInfo::deviceId() const
{
    return wstr_to_utf8(impObj()->deviceId());
}

void PyPlPlotConfigInfo::setDeviceId(const std::string& pDevId)
{
    impObj()->setDeviceId(utf8_to_wstr(pDevId).c_str());
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