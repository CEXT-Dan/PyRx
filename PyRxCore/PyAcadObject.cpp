#include "stdafx.h"
#include "PyAcadObject.h"
#include "PyAcadObjectImpl.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyAcadAcCmColor
void makePyAcadAcCmColorWrapper()
{
    PyDocString DS("AcadAcCmColor");
    class_<PyAcadAcCmColor>("AcadAcCmColor", boost::python::no_init)
        .def("className", &PyAcadAcCmColor::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadAcCmColor::PyAcadAcCmColor(PyIAcadAcCmColorImpl* ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadAcCmColor::className()
{
    return "AcadAcCmColor";
}

PyIAcadAcCmColorImpl* PyAcadAcCmColor::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadHyperlink
void makePyAcadHyperlinkWrapper()
{
    PyDocString DS("AcadHyperlink");
    class_<PyAcadHyperlink>("AcadHyperlink", boost::python::no_init)
        .def("className", &PyAcadHyperlink::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadHyperlink::PyAcadHyperlink(PyIAcadHyperlinkImpl* ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadHyperlink::className()
{
    return "AcadHyperlink";
}

PyIAcadHyperlinkImpl* PyAcadHyperlink::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadHyperlinks
void makePyAcadHyperlinksWrapper()
{
    PyDocString DS("AcadHyperlinks");
    class_<PyAcadHyperlinks>("AcadHyperlinks", boost::python::no_init)
        .def("className", &PyAcadHyperlinks::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadHyperlinks::PyAcadHyperlinks(PyIAcadHyperlinksImpl* ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadHyperlinks::className()
{
    return "AcadHyperlinks";
}

PyIAcadHyperlinksImpl* PyAcadHyperlinks::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadSectionTypeSettings
void makePyAcadSectionTypeSettingsWrapper()
{
    PyDocString DS("AcadSectionTypeSettings");
    class_<PyAcadSectionTypeSettings>("AcadSectionTypeSettings", boost::python::no_init)
        .def("className", &PyAcadSectionTypeSettings::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSectionTypeSettings::PyAcadSectionTypeSettings(std::shared_ptr<PyIAcadSectionTypeSettingsImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadSectionTypeSettings::className()
{
    return "AcadHyperlinks";
}

PyIAcadSectionTypeSettingsImpl* PyAcadSectionTypeSettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadDatabasePreferences
void makePyAcadDatabasePreferencesWrapper()
{
    PyDocString DS("AcadDatabasePreferences");
    class_<PyAcadDatabasePreferences>("AcadDatabasePreferences", boost::python::no_init)
        .def("className", &PyAcadDatabasePreferences::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDatabasePreferences::PyAcadDatabasePreferences(std::shared_ptr<PyIAcadDatabasePreferencesImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadDatabasePreferences::className()
{
    return "AcadDatabasePreferences";
}

PyIAcadDatabasePreferencesImpl* PyAcadDatabasePreferences::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesFiles
void makePyAcadPreferencesFilesWrapper()
{
    PyDocString DS("AcadPreferencesFiles");
    class_<PyAcadPreferencesFiles>("AcadPreferencesFiles", boost::python::no_init)
        .def("className", &PyAcadPreferencesFiles::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesFiles::PyAcadPreferencesFiles(std::shared_ptr<PyIAcadPreferencesFilesImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadPreferencesFiles::className()
{
    return "AcadPreferencesFiles";
}

PyIAcadPreferencesFilesImpl* PyAcadPreferencesFiles::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesDisplay
void makePyAcadPreferencesDisplayWrapper()
{
    PyDocString DS("AcadPreferencesDisplay");
    class_<PyAcadPreferencesDisplay>("AcadPreferencesDisplay", boost::python::no_init)
        .def("className", &PyAcadPreferencesDisplay::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesDisplay::PyAcadPreferencesDisplay(std::shared_ptr<PyIAcadPreferencesDisplayImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadPreferencesDisplay::className()
{
    return "AcadPreferencesDisplay";
}

PyIAcadPreferencesDisplayImpl* PyAcadPreferencesDisplay::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesOpenSave
void makePyAcadPreferencesOpenSaveWrapper()
{
    PyDocString DS("AcadPreferencesOpenSave");
    class_<PyAcadPreferencesOpenSave>("AcadPreferencesOpenSave", boost::python::no_init)
        .def("setSavePreviewThumbnail", &PyAcadPreferencesOpenSave::setSavePreviewThumbnail, DS.ARGS({ "val:bool" }))
        .def("savePreviewThumbnail", &PyAcadPreferencesOpenSave::savePreviewThumbnail, DS.ARGS())
        .def("setIncrementalSavePercent", &PyAcadPreferencesOpenSave::setIncrementalSavePercent, DS.ARGS({ "val:int" }))
        .def("incrementalSavePercent", &PyAcadPreferencesOpenSave::incrementalSavePercent, DS.ARGS())
        .def("setAutoSaveInterval", &PyAcadPreferencesOpenSave::setAutoSaveInterval, DS.ARGS({ "val:int" }))
        .def("autoSaveInterval", &PyAcadPreferencesOpenSave::autoSaveInterval, DS.ARGS())
        .def("setCreateBackup", &PyAcadPreferencesOpenSave::setCreateBackup, DS.ARGS({ "val:bool" }))
        .def("createBackup", &PyAcadPreferencesOpenSave::createBackup, DS.ARGS())
        .def("setFullCRCValidation", &PyAcadPreferencesOpenSave::setFullCRCValidation, DS.ARGS({ "val:bool" }))
        .def("fullCRCValidation", &PyAcadPreferencesOpenSave::fullCRCValidation, DS.ARGS())
        .def("setLogFileOn", &PyAcadPreferencesOpenSave::setLogFileOn, DS.ARGS({ "val:bool" }))
        .def("logFileOn", &PyAcadPreferencesOpenSave::logFileOn, DS.ARGS())
        .def("setTempFileExtension", &PyAcadPreferencesOpenSave::setTempFileExtension, DS.ARGS({ "val:str" }))
        .def("tempFileExtension", &PyAcadPreferencesOpenSave::tempFileExtension, DS.ARGS())
        .def("setXrefDemandLoad", &PyAcadPreferencesOpenSave::setXrefDemandLoad, DS.ARGS({ "val:PyAx.AcXRefDemandLoad" }))
        .def("xrefDemandLoad", &PyAcadPreferencesOpenSave::xrefDemandLoad, DS.ARGS())
        .def("setDemandLoadARXApp", &PyAcadPreferencesOpenSave::setDemandLoadARXApp, DS.ARGS({ "val:PyAx.AcARXDemandLoad" }))
        .def("demandLoadARXApp", &PyAcadPreferencesOpenSave::demandLoadARXApp, DS.ARGS())
        .def("setProxyImage", &PyAcadPreferencesOpenSave::setProxyImage, DS.ARGS({ "val:PyAx.AcProxyImage" }))
        .def("proxyImage", &PyAcadPreferencesOpenSave::proxyImage, DS.ARGS())
        .def("setShowProxyDialogBox", &PyAcadPreferencesOpenSave::setShowProxyDialogBox, DS.ARGS({ "val:bool" }))
        .def("showProxyDialogBox", &PyAcadPreferencesOpenSave::showProxyDialogBox, DS.ARGS())
        .def("setAutoAudit", &PyAcadPreferencesOpenSave::setAutoAudit, DS.ARGS({ "val:bool" }))
        .def("autoAudit", &PyAcadPreferencesOpenSave::autoAudit, DS.ARGS())
        .def("setSaveAsType", &PyAcadPreferencesOpenSave::setSaveAsType, DS.ARGS({ "val:PyAx.AcSaveAsType" }))
        .def("saveAsType", &PyAcadPreferencesOpenSave::saveAsType, DS.ARGS())
        .def("mruNumber", &PyAcadPreferencesOpenSave::mruNumber, DS.ARGS())
        .def("className", &PyAcadPreferencesOpenSave::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesOpenSave::PyAcadPreferencesOpenSave(std::shared_ptr<PyIAcadPreferencesOpenSaveImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesOpenSave::setSavePreviewThumbnail(bool val)
{
    impObj()->SetSavePreviewThumbnail(val);
}

bool PyAcadPreferencesOpenSave::savePreviewThumbnail() const
{
    return impObj()->GetSavePreviewThumbnail();
}

void PyAcadPreferencesOpenSave::setIncrementalSavePercent(int val)
{
    impObj()->SetIncrementalSavePercent(val);
}

int PyAcadPreferencesOpenSave::incrementalSavePercent() const
{
    return impObj()->GetIncrementalSavePercent();
}

void PyAcadPreferencesOpenSave::setAutoSaveInterval(int val)
{
    impObj()->SetAutoSaveInterval(val);
}

int PyAcadPreferencesOpenSave::autoSaveInterval() const
{
    return impObj()->GetAutoSaveInterval();
}

void PyAcadPreferencesOpenSave::setCreateBackup(bool val)
{
    impObj()->SetCreateBackup(val);
}

bool PyAcadPreferencesOpenSave::createBackup() const
{
    return impObj()->GetCreateBackup();
}

void PyAcadPreferencesOpenSave::setFullCRCValidation(bool val)
{
    impObj()->SetFullCRCValidation(val);
}

bool PyAcadPreferencesOpenSave::fullCRCValidation() const
{
    return impObj()->GetFullCRCValidation();
}

void PyAcadPreferencesOpenSave::setLogFileOn(bool val)
{
    impObj()->SetLogFileOn(val);
}

bool PyAcadPreferencesOpenSave::logFileOn() const
{
    return impObj()->GetLogFileOn();
}

void PyAcadPreferencesOpenSave::setTempFileExtension(const std::string& val)
{
    impObj()->SetTempFileExtension(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOpenSave::tempFileExtension() const
{
    return wstr_to_utf8(impObj()->GetTempFileExtension());
}

void PyAcadPreferencesOpenSave::setXrefDemandLoad(PyAcXRefDemandLoad val)
{
    impObj()->SetXrefDemandLoad(val);
}

PyAcXRefDemandLoad PyAcadPreferencesOpenSave::xrefDemandLoad() const
{
    return impObj()->GetXrefDemandLoad();
}

void PyAcadPreferencesOpenSave::setDemandLoadARXApp(PyAcARXDemandLoad val)
{
    impObj()->SetDemandLoadARXApp(val);
}

PyAcARXDemandLoad PyAcadPreferencesOpenSave::demandLoadARXApp() const
{
    return impObj()->GetDemandLoadARXApp();
}

void PyAcadPreferencesOpenSave::setProxyImage(PyAcProxyImage val)
{
    impObj()->SetProxyImage(val);
}

PyAcProxyImage PyAcadPreferencesOpenSave::proxyImage() const
{
    return impObj()->GetProxyImage();
}

void PyAcadPreferencesOpenSave::setShowProxyDialogBox(bool val)
{
    impObj()->SetShowProxyDialogBox(val);
}

bool PyAcadPreferencesOpenSave::showProxyDialogBox() const
{
    return impObj()->GetShowProxyDialogBox();
}

void PyAcadPreferencesOpenSave::setAutoAudit(bool val)
{
    impObj()->SetAutoAudit(val);
}

bool PyAcadPreferencesOpenSave::autoAudit() const
{
    return impObj()->GetAutoAudit();
}

void PyAcadPreferencesOpenSave::setSaveAsType(PyAcSaveAsType val)
{
    impObj()->SetSaveAsType(val);
}

PyAcSaveAsType PyAcadPreferencesOpenSave::saveAsType() const
{
    return impObj()->GetSaveAsType();
}

long PyAcadPreferencesOpenSave::mruNumber()
{
    return impObj()->GetMRUNumber();
}

std::string PyAcadPreferencesOpenSave::className()
{
    return "AcadPreferencesOpenSave";
}

PyIAcadPreferencesOpenSaveImpl* PyAcadPreferencesOpenSave::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesOutput
void makePyAcadPreferencesOutputWrapper()
{
    PyDocString DS("AcadPreferencesOutput");
    class_<PyAcadPreferencesOutput>("AcadPreferencesOutput", boost::python::no_init)
        .def("setDefaultOutputDevice", &PyAcadPreferencesOutput::setDefaultOutputDevice, DS.ARGS({ "val:str" }))
        .def("defaultOutputDevice", &PyAcadPreferencesOutput::defaultOutputDevice, DS.ARGS())
        .def("setPrinterSpoolAlert", &PyAcadPreferencesOutput::setPrinterSpoolAlert, DS.ARGS({ "val:PyAx.AcPrinterSpoolAlert" }))
        .def("printerSpoolAlert", &PyAcadPreferencesOutput::printerSpoolAlert, DS.ARGS())
        .def("setPrinterPaperSizeAlert", &PyAcadPreferencesOutput::setPrinterPaperSizeAlert, DS.ARGS({ "val:bool" }))
        .def("printerPaperSizeAlert", &PyAcadPreferencesOutput::printerPaperSizeAlert, DS.ARGS())
        .def("setPlotLegacy", &PyAcadPreferencesOutput::setPlotLegacy, DS.ARGS({ "val:bool" }))
        .def("plotLegacy", &PyAcadPreferencesOutput::plotLegacy, DS.ARGS())
        .def("setOLEQuality", &PyAcadPreferencesOutput::setOLEQuality, DS.ARGS({ "val:PyAx.AcOleQuality" }))
        .def("oleQuality", &PyAcadPreferencesOutput::oleQuality, DS.ARGS())
        .def("setUseLastPlotSettings", &PyAcadPreferencesOutput::setUseLastPlotSettings, DS.ARGS({ "val:bool" }))
        .def("useLastPlotSettings", &PyAcadPreferencesOutput::useLastPlotSettings, DS.ARGS())
        .def("setPlotPolicy", &PyAcadPreferencesOutput::setPlotPolicy, DS.ARGS({ "val:PyAx.AcPlotPolicy" }))
        .def("plotPolicy", &PyAcadPreferencesOutput::plotPolicy, DS.ARGS())
        .def("setDefaultPlotStyleTable", &PyAcadPreferencesOutput::setDefaultPlotStyleTable, DS.ARGS({ "val:str" }))
        .def("defaultPlotStyleTable", &PyAcadPreferencesOutput::defaultPlotStyleTable, DS.ARGS())
        .def("setDefaultPlotStyleForObjects", &PyAcadPreferencesOutput::setDefaultPlotStyleForObjects, DS.ARGS({ "val:str" }))
        .def("defaultPlotStyleForObjects", &PyAcadPreferencesOutput::defaultPlotStyleForObjects, DS.ARGS())
        .def("setDefaultPlotStyleForLayer", &PyAcadPreferencesOutput::setDefaultPlotStyleForLayer, DS.ARGS({ "val:str" }))
        .def("defaultPlotStyleForLayer", &PyAcadPreferencesOutput::defaultPlotStyleForLayer, DS.ARGS())
        .def("setContinuousPlotLog", &PyAcadPreferencesOutput::setContinuousPlotLog, DS.ARGS({ "val:bool" }))
        .def("continuousPlotLog", &PyAcadPreferencesOutput::continuousPlotLog, DS.ARGS())
        .def("setAutomaticPlotLog", &PyAcadPreferencesOutput::setAutomaticPlotLog, DS.ARGS({ "val:bool" }))
        .def("automaticPlotLog", &PyAcadPreferencesOutput::automaticPlotLog, DS.ARGS())
        .def("setDefaultPlotToFilePath", &PyAcadPreferencesOutput::setDefaultPlotToFilePath, DS.ARGS({ "val:str" }))
        .def("defaultPlotToFilePath", &PyAcadPreferencesOutput::defaultPlotToFilePath, DS.ARGS())
        .def("className", &PyAcadPreferencesOutput::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesOutput::PyAcadPreferencesOutput(std::shared_ptr<PyIAcadPreferencesOutputImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesOutput::setDefaultOutputDevice(const std::string& val)
{
    impObj()->SetDefaultOutputDevice(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOutput::defaultOutputDevice() const
{
    return wstr_to_utf8(impObj()->GetDefaultOutputDevice());
}

void PyAcadPreferencesOutput::setPrinterSpoolAlert(PyAcPrinterSpoolAlert val)
{
    impObj()->SetPrinterSpoolAlert(val);
}

PyAcPrinterSpoolAlert PyAcadPreferencesOutput::printerSpoolAlert() const
{
    return impObj()->GetPrinterSpoolAlert();
}

void PyAcadPreferencesOutput::setPrinterPaperSizeAlert(bool val)
{
    impObj()->SetPrinterPaperSizeAlert(val);
}

bool PyAcadPreferencesOutput::printerPaperSizeAlert() const
{
    return impObj()->GetPrinterPaperSizeAlert();
}

void PyAcadPreferencesOutput::setPlotLegacy(bool val)
{
    impObj()->SetPlotLegacy(val);
}

bool PyAcadPreferencesOutput::plotLegacy() const
{
    return impObj()->GetPlotLegacy();
}

void PyAcadPreferencesOutput::setOLEQuality(PyAcOleQuality val)
{
    impObj()->SetOLEQuality(val);
}

PyAcOleQuality PyAcadPreferencesOutput::oleQuality() const
{
    return impObj()->GetOLEQuality();
}

void PyAcadPreferencesOutput::setUseLastPlotSettings(bool val)
{
    impObj()->SetUseLastPlotSettings(val);
}

bool PyAcadPreferencesOutput::useLastPlotSettings() const
{
    return impObj()->GetUseLastPlotSettings();
}

void PyAcadPreferencesOutput::setPlotPolicy(PyAcPlotPolicy val)
{
    impObj()->SetPlotPolicy(val);
}

PyAcPlotPolicy PyAcadPreferencesOutput::plotPolicy() const
{
    return impObj()->GetPlotPolicy();
}

void PyAcadPreferencesOutput::setDefaultPlotStyleTable(const std::string& val)
{
    impObj()->SetDefaultPlotStyleTable(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOutput::defaultPlotStyleTable() const
{
    return wstr_to_utf8(impObj()->GetDefaultPlotStyleTable());
}

void PyAcadPreferencesOutput::setDefaultPlotStyleForObjects(const std::string& val)
{
    impObj()->SetDefaultPlotStyleForObjects(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOutput::defaultPlotStyleForObjects() const
{
    return wstr_to_utf8(impObj()->GetDefaultPlotStyleForObjects());
}

void PyAcadPreferencesOutput::setDefaultPlotStyleForLayer(const std::string& val)
{
    impObj()->SetDefaultPlotStyleForLayer(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOutput::defaultPlotStyleForLayer() const
{
    return wstr_to_utf8(impObj()->GetDefaultPlotStyleForLayer());
}

void PyAcadPreferencesOutput::setContinuousPlotLog(bool val)
{
    impObj()->SetContinuousPlotLog(val);
}

bool PyAcadPreferencesOutput::continuousPlotLog() const
{
    return impObj()->GetContinuousPlotLog();
}

void PyAcadPreferencesOutput::setAutomaticPlotLog(bool val)
{
    impObj()->SetAutomaticPlotLog(val);
}

bool PyAcadPreferencesOutput::automaticPlotLog() const
{
    return impObj()->GetAutomaticPlotLog();
}

void PyAcadPreferencesOutput::setDefaultPlotToFilePath(const std::string& val)
{
    impObj()->SetDefaultPlotToFilePath(utf8_to_wstr(val).c_str());
}

std::string PyAcadPreferencesOutput::defaultPlotToFilePath() const
{
    return wstr_to_utf8(impObj()->GetDefaultPlotToFilePath());
}

std::string PyAcadPreferencesOutput::className()
{
    return "AcadPreferencesOutput";
}

PyIAcadPreferencesOutputImpl* PyAcadPreferencesOutput::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesSystem
void makePyAcadPreferencesSystemWrapper()
{
    PyDocString DS("AcadPreferencesSystem");
    class_<PyAcadPreferencesSystem>("AcadPreferencesSystem", boost::python::no_init)
        .def("setSingleDocumentMode", &PyAcadPreferencesSystem::setSingleDocumentMode, DS.ARGS({ "val:bool" }))
        .def("singleDocumentMode", &PyAcadPreferencesSystem::singleDocumentMode, DS.ARGS())
        .def("setDisplayOLEScale", &PyAcadPreferencesSystem::setDisplayOLEScale, DS.ARGS({ "val:bool" }))
        .def("displayOLEScale", &PyAcadPreferencesSystem::displayOLEScale, DS.ARGS())
        .def("setStoreSQLIndex", &PyAcadPreferencesSystem::setStoreSQLIndex, DS.ARGS({ "val:bool" }))
        .def("storeSQLIndex", &PyAcadPreferencesSystem::storeSQLIndex, DS.ARGS())
        .def("setTablesReadOnly", &PyAcadPreferencesSystem::setTablesReadOnly, DS.ARGS({ "val:bool" }))
        .def("tablesReadOnly", &PyAcadPreferencesSystem::tablesReadOnly, DS.ARGS())
        .def("setEnableStartupDialog", &PyAcadPreferencesSystem::setEnableStartupDialog, DS.ARGS({ "val:bool" }))
        .def("enableStartupDialog", &PyAcadPreferencesSystem::enableStartupDialog, DS.ARGS())
        .def("setBeepOnError", &PyAcadPreferencesSystem::setBeepOnError, DS.ARGS({ "val:bool" }))
        .def("beepOnError", &PyAcadPreferencesSystem::beepOnError, DS.ARGS())
        .def("setShowWarningMessages", &PyAcadPreferencesSystem::setShowWarningMessages, DS.ARGS({ "val:bool" }))
        .def("showWarningMessages", &PyAcadPreferencesSystem::showWarningMessages, DS.ARGS())
        .def("setLoadAcadLspInAllDocuments", &PyAcadPreferencesSystem::setLoadAcadLspInAllDocuments, DS.ARGS({ "val:bool" }))
        .def("loadAcadLspInAllDocuments", &PyAcadPreferencesSystem::loadAcadLspInAllDocuments, DS.ARGS())
        .def("className", &PyAcadPreferencesSystem::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesSystem::PyAcadPreferencesSystem(std::shared_ptr<PyIAcadPreferencesSystemImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesSystem::setSingleDocumentMode(bool val)
{
    impObj()->SetSingleDocumentMode(val);
}

bool PyAcadPreferencesSystem::singleDocumentMode() const
{
    return impObj()->GetSingleDocumentMode();
}

void PyAcadPreferencesSystem::setDisplayOLEScale(bool val)
{
    impObj()->SetDisplayOLEScale(val);
}

bool PyAcadPreferencesSystem::displayOLEScale() const
{
    return impObj()->GetDisplayOLEScale();
}

void PyAcadPreferencesSystem::setStoreSQLIndex(bool val)
{
    impObj()->SetStoreSQLIndex(val);
}

bool PyAcadPreferencesSystem::storeSQLIndex() const
{
    return impObj()->GetStoreSQLIndex();
}

void PyAcadPreferencesSystem::setTablesReadOnly(bool val)
{
    impObj()->SetTablesReadOnly(val);
}

bool PyAcadPreferencesSystem::tablesReadOnly() const
{
    return impObj()->GetTablesReadOnly();
}

void PyAcadPreferencesSystem::setEnableStartupDialog(bool val)
{
    impObj()->SetEnableStartupDialog(val);
}

bool PyAcadPreferencesSystem::enableStartupDialog() const
{
    return impObj()->GetEnableStartupDialog();
}

void PyAcadPreferencesSystem::setBeepOnError(bool val)
{
    impObj()->SetBeepOnError(val);
}

bool PyAcadPreferencesSystem::beepOnError() const
{
    return impObj()->GetBeepOnError();
}

void PyAcadPreferencesSystem::setShowWarningMessages(bool val)
{
    impObj()->SetShowWarningMessages(val);
}

bool PyAcadPreferencesSystem::showWarningMessages() const
{
    return impObj()->GetShowWarningMessages();
}

void PyAcadPreferencesSystem::setLoadAcadLspInAllDocuments(bool val)
{
    impObj()->SetLoadAcadLspInAllDocuments(val);
}

bool PyAcadPreferencesSystem::loadAcadLspInAllDocuments() const
{
    return impObj()->GetLoadAcadLspInAllDocuments();
}

std::string PyAcadPreferencesSystem::className()
{
    return "AcadPreferencesSystem";
}

PyIAcadPreferencesSystemImpl* PyAcadPreferencesSystem::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesUser
void makePyAcadPreferencesUserWrapper()
{
    PyDocString DS("AcadPreferencesUser");
    class_<PyAcadPreferencesUser>("AcadPreferencesUser", boost::python::no_init)
        .def("setKeyboardAccelerator", &PyAcadPreferencesUser::setKeyboardAccelerator, DS.ARGS({ "val:PyAx.AcKeyboardAccelerator" }))
        .def("keyboardAccelerator", &PyAcadPreferencesUser::keyboardAccelerator, DS.ARGS())
        .def("setKeyboardPriority", &PyAcadPreferencesUser::setKeyboardPriority, DS.ARGS({ "val:PyAx.AcKeyboardPriority" }))
        .def("keyboardPriority", &PyAcadPreferencesUser::keyboardPriority, DS.ARGS())
        .def("setHyperlinkDisplayCursor", &PyAcadPreferencesUser::setHyperlinkDisplayCursor, DS.ARGS({ "val:bool" }))
        .def("hyperlinkDisplayCursor", &PyAcadPreferencesUser::hyperlinkDisplayCursor, DS.ARGS())
        .def("setADCInsertUnitsDefaultSource", &PyAcadPreferencesUser::setADCInsertUnitsDefaultSource, DS.ARGS({ "val:PyAx.AcInsertUnits" }))
        .def("adcInsertUnitsDefaultSource", &PyAcadPreferencesUser::adcInsertUnitsDefaultSource, DS.ARGS())
        .def("setADCInsertUnitsDefaultTarget", &PyAcadPreferencesUser::setADCInsertUnitsDefaultTarget, DS.ARGS({ "val:PyAx.AcInsertUnits" }))
        .def("adcInsertUnitsDefaultTarget", &PyAcadPreferencesUser::adcInsertUnitsDefaultTarget, DS.ARGS())
        .def("setShortCutMenuDisplay", &PyAcadPreferencesUser::setShortCutMenuDisplay, DS.ARGS({ "val:bool" }))
        .def("shortCutMenuDisplay", &PyAcadPreferencesUser::shortCutMenuDisplay, DS.ARGS())
        .def("setSCMDefaultMode", &PyAcadPreferencesUser::setSCMDefaultMode, DS.ARGS({ "val:PyAx.AcDrawingAreaSCMDefault" }))
        .def("scmDefaultMode", &PyAcadPreferencesUser::scmDefaultMode, DS.ARGS())
        .def("setSCMEditMode", &PyAcadPreferencesUser::setSCMEditMode, DS.ARGS({ "val:PyAx.AcDrawingAreaSCMEdit" }))
        .def("acmEditMode", &PyAcadPreferencesUser::acmEditMode, DS.ARGS())
        .def("setSCMCommandMode", &PyAcadPreferencesUser::setSCMCommandMode, DS.ARGS({ "val:PyAx.AcDrawingAreaSCMCommand" }))
        .def("scmCommandMode", &PyAcadPreferencesUser::scmCommandMode, DS.ARGS())
        .def("setSCMTimeMode", &PyAcadPreferencesUser::setSCMTimeMode, DS.ARGS({ "val:bool" }))
        .def("scmTimeMode", &PyAcadPreferencesUser::scmTimeMode, DS.ARGS())
        .def("setSCMTimeValue", &PyAcadPreferencesUser::setSCMTimeValue, DS.ARGS({ "val:int" }))
        .def("scmTimeValue", &PyAcadPreferencesUser::scmTimeValue, DS.ARGS())
        .def("className", &PyAcadPreferencesUser::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesUser::PyAcadPreferencesUser(std::shared_ptr<PyIAcadPreferencesUserImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesUser::setKeyboardAccelerator(PyAcKeyboardAccelerator val)
{
    impObj()->SetKeyboardAccelerator(val);
}

PyAcKeyboardAccelerator PyAcadPreferencesUser::keyboardAccelerator() const
{
    return impObj()->GetKeyboardAccelerator();
}

void PyAcadPreferencesUser::setKeyboardPriority(PyAcKeyboardPriority val)
{
    impObj()->SetKeyboardPriority(val);
}

PyAcKeyboardPriority PyAcadPreferencesUser::keyboardPriority() const
{
    return impObj()->GetKeyboardPriority();
}

void PyAcadPreferencesUser::setHyperlinkDisplayCursor(bool val)
{
    impObj()->SetHyperlinkDisplayCursor(val);
}

bool PyAcadPreferencesUser::hyperlinkDisplayCursor() const
{
    return impObj()->GetHyperlinkDisplayCursor();
}

void PyAcadPreferencesUser::setADCInsertUnitsDefaultSource(PyAcInsertUnits val)
{
    impObj()->SetADCInsertUnitsDefaultSource(val);
}

PyAcInsertUnits PyAcadPreferencesUser::adcInsertUnitsDefaultSource() const
{
    return impObj()->GetADCInsertUnitsDefaultSource();
}

void PyAcadPreferencesUser::setADCInsertUnitsDefaultTarget(PyAcInsertUnits val)
{
    impObj()->SetADCInsertUnitsDefaultTarget(val);
}

PyAcInsertUnits PyAcadPreferencesUser::adcInsertUnitsDefaultTarget() const
{
    return impObj()->GetADCInsertUnitsDefaultTarget();
}

void PyAcadPreferencesUser::setShortCutMenuDisplay(bool val)
{
    impObj()->SetShortCutMenuDisplay(val);
}

bool PyAcadPreferencesUser::shortCutMenuDisplay() const
{
    return impObj()->GetShortCutMenuDisplay();
}

void PyAcadPreferencesUser::setSCMDefaultMode(PyAcDrawingAreaSCMDefault val)
{
    impObj()->SetSCMDefaultMode(val);
}

PyAcDrawingAreaSCMDefault PyAcadPreferencesUser::scmDefaultMode() const
{
    return impObj()->GetSCMDefaultMode();
}

void PyAcadPreferencesUser::setSCMEditMode(PyAcDrawingAreaSCMEdit val)
{
    impObj()->SetSCMEditMode(val);
}

PyAcDrawingAreaSCMEdit PyAcadPreferencesUser::acmEditMode() const
{
    return impObj()->GetSCMEditMode();
}

void PyAcadPreferencesUser::setSCMCommandMode(PyAcDrawingAreaSCMCommand val)
{
    impObj()->SetSCMCommandMode(val);
}

PyAcDrawingAreaSCMCommand PyAcadPreferencesUser::scmCommandMode() const
{
    return impObj()->GetSCMCommandMode();
}

void PyAcadPreferencesUser::setSCMTimeMode(bool val)
{
    impObj()->SetSCMTimeMode(val);
}

bool PyAcadPreferencesUser::scmTimeMode() const
{
    return impObj()->GetSCMTimeMode();
}

void PyAcadPreferencesUser::setSCMTimeValue(int val)
{
    impObj()->SetSCMTimeValue(val);
}

int PyAcadPreferencesUser::scmTimeValue() const
{
    return impObj()->GetSCMTimeValue();
}

std::string PyAcadPreferencesUser::className()
{
    return "AcadPreferencesUser";
}

PyIAcadPreferencesUserImpl* PyAcadPreferencesUser::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesDrafting
void makePyAcadPreferencesDraftingWrapper()
{
    PyDocString DS("AcadPreferencesDrafting");
    class_<PyAcadPreferencesDrafting>("AcadPreferencesDrafting", boost::python::no_init)
        .def("setAutoSnapMarker", &PyAcadPreferencesDrafting::setAutoSnapMarker, DS.ARGS({ "flag:bool" }))
        .def("autoSnapMarker", &PyAcadPreferencesDrafting::autoSnapMarker, DS.ARGS())
        .def("setAutoSnapMagnet", &PyAcadPreferencesDrafting::setAutoSnapMagnet, DS.ARGS({ "flag:bool" }))
        .def("autoSnapMagnet", &PyAcadPreferencesDrafting::autoSnapMagnet, DS.ARGS())
        .def("setAutoSnapTooltip", &PyAcadPreferencesDrafting::setAutoSnapTooltip, DS.ARGS({ "flag:bool" }))
        .def("autoSnapTooltip", &PyAcadPreferencesDrafting::autoSnapTooltip, DS.ARGS())
        .def("setAutoSnapAperture", &PyAcadPreferencesDrafting::setAutoSnapAperture, DS.ARGS({ "flag:bool" }))
        .def("autoSnapAperture", &PyAcadPreferencesDrafting::autoSnapAperture, DS.ARGS())
        .def("setAutoSnapApertureSize", &PyAcadPreferencesDrafting::setAutoSnapApertureSize, DS.ARGS({ "flag:int" }))
        .def("autoSnapApertureSize", &PyAcadPreferencesDrafting::autoSnapApertureSize, DS.ARGS())
        .def("setAutoSnapMarkerColor", &PyAcadPreferencesDrafting::setAutoSnapMarkerColor, DS.ARGS({ "flag:PyAx.AcColor" }))
        .def("autoSnapMarkerColor", &PyAcadPreferencesDrafting::autoSnapMarkerColor, DS.ARGS())
        .def("setAutoSnapMarkerSize", &PyAcadPreferencesDrafting::setAutoSnapMarkerSize, DS.ARGS({ "flag:int" }))
        .def("autoSnapMarkerSize", &PyAcadPreferencesDrafting::autoSnapMarkerSize, DS.ARGS())
        .def("setPolarTrackingVector", &PyAcadPreferencesDrafting::setPolarTrackingVector, DS.ARGS({ "flag:bool" }))
        .def("polarTrackingVector", &PyAcadPreferencesDrafting::polarTrackingVector, DS.ARGS())
        .def("setFullScreenTrackingVector", &PyAcadPreferencesDrafting::setFullScreenTrackingVector, DS.ARGS({ "flag:bool" }))
        .def("fullScreenTrackingVector", &PyAcadPreferencesDrafting::fullScreenTrackingVector, DS.ARGS())
        .def("setAutoTrackTooltip", &PyAcadPreferencesDrafting::setAutoTrackTooltip, DS.ARGS({ "flag:bool" }))
        .def("autoTrackTooltip", &PyAcadPreferencesDrafting::autoTrackTooltip, DS.ARGS())
        .def("setAlignmentPointAcquisition", &PyAcadPreferencesDrafting::setAlignmentPointAcquisition, DS.ARGS({ "flag:PyAx.AcAlignmentPointAcquisition" }))
        .def("alignmentPointAcquisition", &PyAcadPreferencesDrafting::alignmentPointAcquisition, DS.ARGS())
        .def("className", &PyAcadPreferencesDrafting::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesDrafting::PyAcadPreferencesDrafting(std::shared_ptr<PyIAcadPreferencesDraftingImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesDrafting::setAutoSnapMarker(bool val)
{
    impObj()->SetAutoSnapMarker(val);
}

bool PyAcadPreferencesDrafting::autoSnapMarker() const
{
    return impObj()->GetAutoSnapMarker();
}

void PyAcadPreferencesDrafting::setAutoSnapMagnet(bool val)
{
    impObj()->SetAutoSnapMagnet(val);
}

bool PyAcadPreferencesDrafting::autoSnapMagnet() const
{
    return impObj()->GetAutoSnapMagnet();
}

void PyAcadPreferencesDrafting::setAutoSnapTooltip(bool val)
{
    impObj()->SetAutoSnapTooltip(val);
}

bool PyAcadPreferencesDrafting::autoSnapTooltip() const
{
    return impObj()->GetAutoSnapTooltip();
}

void PyAcadPreferencesDrafting::setAutoSnapAperture(bool val)
{
    impObj()->SetAutoSnapAperture(val);
}

bool PyAcadPreferencesDrafting::autoSnapAperture() const
{
    return impObj()->GetAutoSnapAperture();
}

void PyAcadPreferencesDrafting::setAutoSnapApertureSize(long val)
{
    impObj()->SetAutoSnapApertureSize(val);
}

long PyAcadPreferencesDrafting::autoSnapApertureSize() const
{
    return impObj()->GetAutoSnapApertureSize();
}

void PyAcadPreferencesDrafting::setAutoSnapMarkerColor(PyAcColor val)
{
    impObj()->SetAutoSnapMarkerColor(val);
}

PyAcColor PyAcadPreferencesDrafting::autoSnapMarkerColor() const
{
    return impObj()->GetAutoSnapMarkerColor();
}

void PyAcadPreferencesDrafting::setAutoSnapMarkerSize(long val)
{
    impObj()->SetAutoSnapMarkerSize(val);
}

long PyAcadPreferencesDrafting::autoSnapMarkerSize() const
{
    return impObj()->GetAutoSnapMarkerSize();
}

void PyAcadPreferencesDrafting::setPolarTrackingVector(bool val)
{
    impObj()->SetPolarTrackingVector(val);
}

bool PyAcadPreferencesDrafting::polarTrackingVector() const
{
    return impObj()->GetPolarTrackingVector();
}

void PyAcadPreferencesDrafting::setFullScreenTrackingVector(bool val)
{
    impObj()->SetFullScreenTrackingVector(val);
}

bool PyAcadPreferencesDrafting::fullScreenTrackingVector() const
{
    return impObj()->GetFullScreenTrackingVector();
}

void PyAcadPreferencesDrafting::setAutoTrackTooltip(bool val)
{
    impObj()->SetAutoTrackTooltip(val);
}

bool PyAcadPreferencesDrafting::autoTrackTooltip() const
{
    return impObj()->GetAutoTrackTooltip();
}

void PyAcadPreferencesDrafting::setAlignmentPointAcquisition(PyAcAlignmentPointAcquisition val)
{
    impObj()->SetAlignmentPointAcquisition(val);
}

PyAcAlignmentPointAcquisition PyAcadPreferencesDrafting::alignmentPointAcquisition() const
{
    return impObj()->GetAlignmentPointAcquisition();
}

std::string PyAcadPreferencesDrafting::className()
{
    return "AcadPreferencesDrafting";
}

PyIAcadPreferencesDraftingImpl* PyAcadPreferencesDrafting::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesSelection
void makePyAcadPreferencesSelectionWrapper()
{
    PyDocString DS("AcadPreferencesSelection");
    class_<PyAcadPreferencesSelection>("AcadPreferencesSelection", boost::python::no_init)
        .def("setPickFirst", &PyAcadPreferencesSelection::setPickFirst, DS.ARGS({ "flag:bool" }))
        .def("pickFirst", &PyAcadPreferencesSelection::pickFirst, DS.ARGS())
        .def("setPickAdd", &PyAcadPreferencesSelection::setPickAdd, DS.ARGS({ "flag:bool" }))
        .def("pickAdd", &PyAcadPreferencesSelection::pickAdd, DS.ARGS())
        .def("setPickDrag", &PyAcadPreferencesSelection::setPickDrag, DS.ARGS({ "flag:bool" }))
        .def("pickDrag", &PyAcadPreferencesSelection::pickDrag, DS.ARGS())
        .def("setPickAuto", &PyAcadPreferencesSelection::setPickAuto, DS.ARGS({ "flag:bool" }))
        .def("pickAuto", &PyAcadPreferencesSelection::pickAuto, DS.ARGS())
        .def("setPickBoxSize", &PyAcadPreferencesSelection::setPickBoxSize, DS.ARGS({ "flag:int" }))
        .def("pickBoxSize", &PyAcadPreferencesSelection::pickBoxSize, DS.ARGS())
        .def("setDisplayGrips", &PyAcadPreferencesSelection::setDisplayGrips, DS.ARGS({ "flag:bool" }))
        .def("displayGrips", &PyAcadPreferencesSelection::displayGrips, DS.ARGS())
        .def("setDisplayGripsWithinBlocks", &PyAcadPreferencesSelection::setDisplayGripsWithinBlocks, DS.ARGS({ "flag:bool" }))
        .def("displayGripsWithinBlocks", &PyAcadPreferencesSelection::displayGripsWithinBlocks, DS.ARGS())
        .def("setGripColorSelected", &PyAcadPreferencesSelection::setGripColorSelected, DS.ARGS({ "clr:PyAx.AcColor" }))
        .def("gripColorSelected", &PyAcadPreferencesSelection::gripColorSelected, DS.ARGS())
        .def("setGripColorUnselected", &PyAcadPreferencesSelection::setGripColorUnselected, DS.ARGS({ "clr:PyAx.AcColor" }))
        .def("gripColorUnselected", &PyAcadPreferencesSelection::gripColorUnselected, DS.ARGS())
        .def("setGripSize", &PyAcadPreferencesSelection::setGripSize, DS.ARGS({ "flag:int" }))
        .def("gripSize", &PyAcadPreferencesSelection::gripSize, DS.ARGS())
        .def("setPickGroup", &PyAcadPreferencesSelection::setPickGroup, DS.ARGS({ "flag:bool" }))
        .def("pickGroup", &PyAcadPreferencesSelection::pickGroup, DS.ARGS())
        .def("className", &PyAcadPreferencesSelection::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesSelection::PyAcadPreferencesSelection(std::shared_ptr<PyIAcadPreferencesSelectionImpl> ptr)
    : m_pyImp(ptr)
{
}

void PyAcadPreferencesSelection::setPickFirst(bool val)
{
    impObj()->SetPickFirst(val);
}

bool PyAcadPreferencesSelection::pickFirst() const
{
    return impObj()->GetPickFirst();
}

void PyAcadPreferencesSelection::setPickAdd(bool val)
{
    impObj()->SetPickAdd(val);
}

bool PyAcadPreferencesSelection::pickAdd() const
{
    return impObj()->GetPickAdd();
}

void PyAcadPreferencesSelection::setPickDrag(bool val)
{
    impObj()->SetPickDrag(val);
}

bool PyAcadPreferencesSelection::pickDrag() const
{
    return impObj()->GetPickDrag();
}

void PyAcadPreferencesSelection::setPickAuto(bool val)
{
    impObj()->SetPickAuto(val);
}

bool PyAcadPreferencesSelection::pickAuto() const
{
    return impObj()->GetPickAuto();
}

void PyAcadPreferencesSelection::setPickBoxSize(long val)
{
    impObj()->SetPickBoxSize(val);
}

long PyAcadPreferencesSelection::pickBoxSize() const
{
    return impObj()->GetPickBoxSize();
}

void PyAcadPreferencesSelection::setDisplayGrips(bool val)
{
    impObj()->SetDisplayGrips(val);
}

bool PyAcadPreferencesSelection::displayGrips() const
{
    return impObj()->GetDisplayGrips();
}

void PyAcadPreferencesSelection::setDisplayGripsWithinBlocks(bool val)
{
    impObj()->SetDisplayGripsWithinBlocks(val);
}

bool PyAcadPreferencesSelection::displayGripsWithinBlocks() const
{
    return impObj()->GetDisplayGripsWithinBlocks();
}

void PyAcadPreferencesSelection::setGripColorSelected(PyAcColor val)
{
    impObj()->SetGripColorSelected(val);
}

PyAcColor PyAcadPreferencesSelection::gripColorSelected() const
{
    return impObj()->GetGripColorSelected();
}

void PyAcadPreferencesSelection::setGripColorUnselected(PyAcColor val)
{
    impObj()->SetGripColorUnselected(val);
}

PyAcColor PyAcadPreferencesSelection::gripColorUnselected() const
{
    return impObj()->GetGripColorUnselected();
}

void PyAcadPreferencesSelection::setGripSize(long val)
{
    impObj()->SetGripSize(val);
}

long PyAcadPreferencesSelection::gripSize() const
{
    return impObj()->GetGripSize();
}

void PyAcadPreferencesSelection::setPickGroup(bool val)
{
    impObj()->SetPickGroup(val);
}

bool PyAcadPreferencesSelection::pickGroup() const
{
    return impObj()->GetPickGroup();
}

std::string PyAcadPreferencesSelection::className()
{
    return "AcadPreferencesSelection";
}

PyIAcadPreferencesSelectionImpl* PyAcadPreferencesSelection::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferencesProfiles
void makePyAcadPreferencesProfilesWrapper()
{
    PyDocString DS("AcadPreferencesProfiles");
    class_<PyAcadPreferencesProfiles>("AcadPreferencesProfiles", boost::python::no_init)
        .def("activeProfile", &PyAcadPreferencesProfiles::activeProfile, DS.ARGS())
        .def("setActiveProfile", &PyAcadPreferencesProfiles::setActiveProfile, DS.ARGS({ "activeProfile:str" }))
        .def("importProfile", &PyAcadPreferencesProfiles::importProfile, DS.ARGS({ "profileName:str","regFile:str","IncludePathInfo:bool" }))
        .def("exportProfile", &PyAcadPreferencesProfiles::exportProfile, DS.ARGS({ "profileName:str","regFile:str" }))
        .def("deleteProfile", &PyAcadPreferencesProfiles::deleteProfile, DS.ARGS({ "profileName:str" }))
        .def("resetProfile", &PyAcadPreferencesProfiles::resetProfile, DS.ARGS({ "profile:str" }))
        .def("renameProfile", &PyAcadPreferencesProfiles::renameProfile, DS.ARGS({ "origProfileName:str", "newProfileName:str" }))
        .def("copyProfile", &PyAcadPreferencesProfiles::copyProfile, DS.ARGS({ "oldProfileName:str", "newProfileName:str" }))
        .def("getAllProfileNames", &PyAcadPreferencesProfiles::getAllProfileNames, DS.ARGS())
        .def("className", &PyAcadPreferencesProfiles::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferencesProfiles::PyAcadPreferencesProfiles(std::shared_ptr<PyIAcadPreferencesProfilesImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadPreferencesProfiles::activeProfile() const
{
    return wstr_to_utf8(impObj()->GetActiveProfile());
}

void PyAcadPreferencesProfiles::setActiveProfile(const std::string& str)
{
    impObj()->SetActiveProfile(utf8_to_wstr(str).c_str());
}

void PyAcadPreferencesProfiles::importProfile(const std::string& ProfileName, const std::string& RegFile, bool IncludePathInfo)
{
    impObj()->ImportProfile(utf8_to_wstr(ProfileName).c_str(), utf8_to_wstr(RegFile).c_str(), IncludePathInfo);
}

void PyAcadPreferencesProfiles::exportProfile(const std::string& ProfileName, const std::string& RegFile)
{
    impObj()->ExportProfile(utf8_to_wstr(ProfileName).c_str(), utf8_to_wstr(RegFile).c_str());
}

void PyAcadPreferencesProfiles::deleteProfile(const std::string& ProfileName)
{
    impObj()->DeleteProfile(utf8_to_wstr(ProfileName).c_str());
}

void PyAcadPreferencesProfiles::resetProfile(const std::string& Profile)
{
    impObj()->ResetProfile(utf8_to_wstr(Profile).c_str());
}

void PyAcadPreferencesProfiles::renameProfile(const std::string& origProfileName, const std::string& newProfileName)
{
    impObj()->RenameProfile(utf8_to_wstr(origProfileName).c_str(), utf8_to_wstr(newProfileName).c_str());
}

void PyAcadPreferencesProfiles::copyProfile(const std::string& oldProfileName, const std::string& newProfileName)
{
    impObj()->CopyProfile(utf8_to_wstr(oldProfileName).c_str(), utf8_to_wstr(newProfileName).c_str());
}

boost::python::list PyAcadPreferencesProfiles::getAllProfileNames() const
{
    const auto& items = impObj()->GetAllProfileNames();
    PyAutoLockGIL lock;
    boost::python::list pyList;
    for (const auto& item : items)
        pyList.append(wstr_to_utf8(item));
    return pyList;
}

std::string PyAcadPreferencesProfiles::className()
{
    return "AcadPreferencesProfiles";
}

PyIAcadPreferencesProfilesImpl* PyAcadPreferencesProfiles::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPreferences
void makePyAcadPreferencesWrapper()
{
    PyDocString DS("AcadPreferences");
    class_<PyAcadPreferences>("AcadPreferences", boost::python::no_init)
        .def("files", &PyAcadPreferences::files, DS.ARGS())
        .def("display", &PyAcadPreferences::display, DS.ARGS())
        .def("openSave", &PyAcadPreferences::openSave, DS.ARGS())
        .def("output", &PyAcadPreferences::output, DS.ARGS())
        .def("system", &PyAcadPreferences::system, DS.ARGS())
        .def("user", &PyAcadPreferences::user, DS.ARGS())
        .def("drafting", &PyAcadPreferences::drafting, DS.ARGS())
        .def("selection", &PyAcadPreferences::selection, DS.ARGS())
        .def("profiles", &PyAcadPreferences::profiles, DS.ARGS())
        .def("className", &PyAcadPreferences::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPreferences::PyAcadPreferences(std::shared_ptr<PyIAcadPreferencesImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcadPreferencesFiles PyAcadPreferences::files() const
{
    return PyAcadPreferencesFiles{ impObj()->GetFiles() };
}

PyAcadPreferencesDisplay PyAcadPreferences::display() const
{
    return PyAcadPreferencesDisplay{ impObj()->GetDisplay() };
}

PyAcadPreferencesOpenSave PyAcadPreferences::openSave() const
{
    return PyAcadPreferencesOpenSave{ impObj()->GetOpenSave() };
}

PyAcadPreferencesOutput PyAcadPreferences::output() const
{
    return PyAcadPreferencesOutput{ impObj()->GetOutput() };
}

PyAcadPreferencesSystem PyAcadPreferences::system() const
{
    return PyAcadPreferencesSystem{ impObj()->GetSystem() };
}

PyAcadPreferencesUser PyAcadPreferences::user() const
{
    return PyAcadPreferencesUser{ impObj()->GetUser() };
}

PyAcadPreferencesDrafting PyAcadPreferences::drafting() const
{
    return PyAcadPreferencesDrafting{ impObj()->GetDrafting() };
}

PyAcadPreferencesSelection PyAcadPreferences::selection() const
{
    return PyAcadPreferencesSelection{ impObj()->GetSelection() };
}

PyAcadPreferencesProfiles PyAcadPreferences::profiles() const
{
    return PyAcadPreferencesProfiles{ impObj()->GetProfiles() };
}

std::string PyAcadPreferences::className()
{
    return "AcadPreferences";
}

PyIAcadPreferencesImpl* PyAcadPreferences::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadSummaryInfo
void makePyAcadSummaryInfoWrapper()
{
    PyDocString DS("AcadSummaryInfo");
    class_<PyAcadSummaryInfo>("AcadSummaryInfo", boost::python::no_init)
        .def("className", &PyAcadSummaryInfo::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSummaryInfo::PyAcadSummaryInfo(PyIAcadSummaryInfoImpl* ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadSummaryInfo::className()
{
    return "AcadSummaryInfo";
}

PyIAcadSummaryInfoImpl* PyAcadSummaryInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadDynamicBlockReferenceProperty
void makePyAcadDynamicBlockReferencePropertyWrapper()
{
    PyDocString DS("AcadDynamicBlockReferenceProperty");
    class_<PyAcadDynamicBlockReferenceProperty>("AcadDynamicBlockReferenceProperty", boost::python::no_init)
        .def("className", &PyAcadDynamicBlockReferenceProperty::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDynamicBlockReferenceProperty::PyAcadDynamicBlockReferenceProperty(PyIAcadDynamicBlockReferencePropertyImpl* ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadDynamicBlockReferenceProperty::className()
{
    return "AcadDynamicBlockReferenceProperty";
}

PyIAcadDynamicBlockReferencePropertyImpl* PyAcadDynamicBlockReferenceProperty::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadIdPair
void makePyAcadIdPairWrapper()
{
    PyDocString DS("AcadIdPair");
    class_<PyAcadIdPair>("AcadIdPair", boost::python::no_init)
        .def("className", &PyAcadIdPair::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadIdPair::PyAcadIdPair(PyIAcadIdPairImpl* ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadIdPair::className()
{
    return "AcadIdPair";
}

PyIAcadIdPairImpl* PyAcadIdPair::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadShadowDisplay
#ifndef _BRXTARGET
void makePyAcadShadowDisplayWrapper()
{
    PyDocString DS("AcadShadowDisplay");
    class_<PyAcadShadowDisplay>("AcadShadowDisplay", boost::python::no_init)
        .def("className", &PyAcadShadowDisplay::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadShadowDisplay::PyAcadShadowDisplay(PyIAcadShadowDisplayImpl* ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadShadowDisplay::className()
{
    return "AcadShadowDisplay";
}

PyIAcadShadowDisplayImpl* PyAcadShadowDisplay::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}
#endif

//----------------------------------------------------------------------------------------
//PyAcadPlot
void makePyAcadPlotWrapper()
{
    PyDocString DS("AcadPlot");
    class_<PyAcadPlot>("AcadPlot", boost::python::no_init)
        .def("className", &PyAcadPlot::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPlot::PyAcadPlot(std::shared_ptr<PyIAcadPlotImpl> ptr)
    : m_pyImp(ptr)
{
}

std::string PyAcadPlot::className()
{
    return "AcadPlot";
}

PyIAcadPlotImpl* PyAcadPlot::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadMenuBar
void makePyAcadMenuBarWrapper()
{
    PyDocString DS("AcadMenuBar");
    class_<PyAcadMenuBar>("AcadMenuBar", boost::python::no_init)
        .def("count", &PyAcadMenuBar::count, DS.ARGS())
        .def("item", &PyAcadMenuBar::item, DS.ARGS({ "index" }))
        .def("__getitem__", &PyAcadMenuBar::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadMenuBar::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMenuBar::PyAcadMenuBar(std::shared_ptr<PyIAcadMenuBarImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadMenuBar::count() const
{
    return impObj()->GetCount();
}

PyAcadPopupMenu PyAcadMenuBar::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadPopupMenu{ impObj()->GetItem(index) };
}

std::string PyAcadMenuBar::className()
{
    return "AcadMenuBar";
}

PyIAcadMenuBarImpl* PyAcadMenuBar::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadMenuGroup
void makePyAcadMenuGroupWrapper()
{
    PyDocString DS("AcadMenuGroup");
    class_<PyAcadMenuGroup>("AcadMenuGroup", boost::python::no_init)

        .def("parent", &PyAcadMenuGroup::parent, DS.ARGS())
        .def("name", &PyAcadMenuGroup::name, DS.ARGS())
        .def("menuType", &PyAcadMenuGroup::menuType, DS.ARGS())
        .def("fileName", &PyAcadMenuGroup::fileName, DS.ARGS())
        .def("menus", &PyAcadMenuGroup::menus, DS.ARGS())
        .def("toolbars", &PyAcadMenuGroup::toolbars, DS.ARGS())
        .def("save", &PyAcadMenuGroup::save, DS.ARGS({ "menuType: PyAx.AcadMenuGroup" }))
        .def("saveAs", &PyAcadMenuGroup::save, DS.ARGS({ "menuFileName: str", "menuType: PyAx.AcadMenuGroup" }))
        .def("unload", &PyAcadMenuGroup::unload, DS.ARGS())
        .def("className", &PyAcadMenuGroup::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMenuGroup::PyAcadMenuGroup(std::shared_ptr<PyIAcadMenuGroupImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcadMenuGroups PyAcadMenuGroup::parent() const
{
    return PyAcadMenuGroups{ impObj()->GetParent() };
}

std::string PyAcadMenuGroup::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

PyAcMenuGroupType PyAcadMenuGroup::menuType() const
{
    return impObj()->GetType();
}

std::string PyAcadMenuGroup::fileName() const
{
    return wstr_to_utf8(impObj()->GetMenuFileName());
}

PyAcadPopupMenus PyAcadMenuGroup::menus() const
{
    return PyAcadPopupMenus{ impObj()->GetMenus() };
}

PyAcadToolbars PyAcadMenuGroup::toolbars() const
{
    return PyAcadToolbars{ impObj()->GetToolbars() };
}

void PyAcadMenuGroup::save(PyAcMenuFileType menuType)
{
    impObj()->Save(menuType);
}

void PyAcadMenuGroup::saveAs(const std::string& menuFileName, PyAcMenuFileType menuType)
{
    impObj()->SaveAs(utf8_to_wstr(menuFileName).c_str(), menuType);
}

void PyAcadMenuGroup::unload()
{
    impObj()->Unload();
}

std::string PyAcadMenuGroup::className()
{
    return "AcadMenuGroup";
}

PyIAcadMenuGroupImpl* PyAcadMenuGroup::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadMenuGroups
void makePyAcadMenuGroupsWrapper()
{
    PyDocString DS("AcadMenuGroups");
    class_<PyAcadMenuGroups>("AcadMenuGroups", boost::python::no_init)
        .def("count", &PyAcadMenuGroups::count, DS.ARGS())
        .def("item", &PyAcadMenuGroups::item, DS.ARGS({ "idx : int" }))
        .def("load", &PyAcadMenuGroups::load1)
        .def("load", &PyAcadMenuGroups::load2, DS.ARGS({ "menuFileName : str","baseMenu : PyAx.AcadMenuGroup = None" }))
        .def("__getitem__", &PyAcadMenuGroups::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadMenuGroups::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMenuGroups::PyAcadMenuGroups(std::shared_ptr<PyIAcadMenuGroupsImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadMenuGroups::count() const
{
    return impObj()->GetCount();
}

PyAcadMenuGroup PyAcadMenuGroups::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadMenuGroup{ impObj()->GetItem(index) };
}

PyAcadMenuGroup PyAcadMenuGroups::load1(const std::string& menuFileName)
{
    return PyAcadMenuGroup{ impObj()->Load(utf8_to_wstr(menuFileName).c_str()) };
}

PyAcadMenuGroup PyAcadMenuGroups::load2(const std::string& menuFileName, const PyAcadMenuGroup& baseMenu)
{
    return PyAcadMenuGroup{ impObj()->Load(utf8_to_wstr(menuFileName).c_str(),*baseMenu.impObj()) };
}

std::string PyAcadMenuGroups::className()
{
    return "AcadMenuGroups";
}

PyIAcadMenuGroupsImpl* PyAcadMenuGroups::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPopupMenuItem
void makePyAcadPopupMenuItemWrapper()
{
    PyDocString DS("AcadPopupMenuItem");
    class_<PyAcadPopupMenuItem>("AcadPopupMenuItem", boost::python::no_init)
        .def("parent", &PyAcadPopupMenuItem::parent, DS.ARGS())
        .def("label", &PyAcadPopupMenuItem::label, DS.ARGS())
        .def("setLabel", &PyAcadPopupMenuItem::setLabel, DS.ARGS({ "label: str" }))
        .def("tagString", &PyAcadPopupMenuItem::tagString, DS.ARGS())
        .def("setTagString", &PyAcadPopupMenuItem::setTagString, DS.ARGS({ "tag: str" }))
        .def("enable", &PyAcadPopupMenuItem::enable, DS.ARGS())
        .def("setEnable", &PyAcadPopupMenuItem::setEnable, DS.ARGS({ "enable: bool" }))
        .def("check", &PyAcadPopupMenuItem::check, DS.ARGS())
        .def("setCheck", &PyAcadPopupMenuItem::setCheck, DS.ARGS({ "enable: bool" }))
        .def("getType", &PyAcadPopupMenuItem::getType, DS.ARGS())
        .def("subMenu", &PyAcadPopupMenuItem::subMenu, DS.ARGS())
        .def("macro", &PyAcadPopupMenuItem::macro, DS.ARGS())
        .def("setMacro", &PyAcadPopupMenuItem::setMacro, DS.ARGS({ "macro: str" }))
        .def("index", &PyAcadPopupMenuItem::index, DS.ARGS())
        .def("caption", &PyAcadPopupMenuItem::caption, DS.ARGS())
        .def("helpString", &PyAcadPopupMenuItem::helpString, DS.ARGS())
        .def("setHelpString", &PyAcadPopupMenuItem::setHelpString, DS.ARGS({ "helpString: str" }))
        .def("clear", &PyAcadPopupMenuItem::clear, DS.ARGS())
        .def("endSubMenuLevel", &PyAcadPopupMenuItem::endSubMenuLevel, DS.ARGS())
        .def("setEndSubMenuLevel", &PyAcadPopupMenuItem::setEndSubMenuLevel, DS.ARGS({ "val: int" }))
        .def("className", &PyAcadPopupMenuItem::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPopupMenuItem::PyAcadPopupMenuItem(std::shared_ptr<PyIAcadPopupMenuItemImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcadPopupMenu PyAcadPopupMenuItem::parent() const
{
    return PyAcadPopupMenu{ impObj()->GetParent() };
}

std::string PyAcadPopupMenuItem::label() const
{
    return wstr_to_utf8(impObj()->GetLabel());
}

void PyAcadPopupMenuItem::setLabel(const std::string& val)
{
    impObj()->SetLabel(utf8_to_wstr(val).c_str());
}

std::string PyAcadPopupMenuItem::tagString() const
{
    return wstr_to_utf8(impObj()->GetTagString());
}

void PyAcadPopupMenuItem::setTagString(const std::string& val)
{
    impObj()->SetTagString(utf8_to_wstr(val).c_str());
}

bool PyAcadPopupMenuItem::enable() const
{
    return impObj()->GetEnable();
}

void PyAcadPopupMenuItem::setEnable(bool val)
{
    impObj()->SetEnable(val);
}

bool PyAcadPopupMenuItem::check() const
{
    return impObj()->GetCheck();
}

void PyAcadPopupMenuItem::setCheck(bool val)
{
    impObj()->SetCheck(val);
}

PyAcMenuItemType PyAcadPopupMenuItem::getType() const
{
    return impObj()->GetType();
}

PyAcadPopupMenu PyAcadPopupMenuItem::subMenu() const
{
    return PyAcadPopupMenu{ impObj()->GetSubMenu() };
}

std::string PyAcadPopupMenuItem::macro() const
{
    return wstr_to_utf8(impObj()->GetMacro());
}

void PyAcadPopupMenuItem::setMacro(const std::string& val)
{
    impObj()->SetMacro(utf8_to_wstr(val).c_str());
}

int PyAcadPopupMenuItem::index() const
{
    return impObj()->GetIndex();
}

std::string PyAcadPopupMenuItem::caption() const
{
    return wstr_to_utf8(impObj()->GetCaption());
}

std::string PyAcadPopupMenuItem::helpString() const
{
    return wstr_to_utf8(impObj()->GetHelpString());
}

void PyAcadPopupMenuItem::setHelpString(const std::string& val)
{
    impObj()->SetHelpString(utf8_to_wstr(val).c_str());
}

void PyAcadPopupMenuItem::clear()
{
    impObj()->Delete();
}

int PyAcadPopupMenuItem::endSubMenuLevel() const
{
    return impObj()->GetEndSubMenuLevel();
}

void PyAcadPopupMenuItem::setEndSubMenuLevel(int idx) const
{
    impObj()->SetEndSubMenuLevel(idx);
}

std::string PyAcadPopupMenuItem::className()
{
    return "AcadPopupMenuItem";
}

PyIAcadPopupMenuItemImpl* PyAcadPopupMenuItem::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPopupMenu
void makePyAcadPopupMenuWrapper()
{
    PyDocString DS("AcadPopupMenu");
    class_<PyAcadPopupMenu>("AcadPopupMenu", boost::python::no_init)
        .def("count", &PyAcadPopupMenu::count, DS.ARGS())
        .def("item", &PyAcadPopupMenu::item, DS.ARGS({ "idx : int" }))
        .def("parent", &PyAcadPopupMenu::parent, DS.ARGS())
        .def("name", &PyAcadPopupMenu::name, DS.ARGS())
        .def("setName", &PyAcadPopupMenu::setName, DS.ARGS({ "name: str" }))
        .def("nameNoMnemonic", &PyAcadPopupMenu::nameNoMnemonic, DS.ARGS())
        .def("isShortcutMenu", &PyAcadPopupMenu::isShortcutMenu, DS.ARGS())
        .def("isOnMenuBar", &PyAcadPopupMenu::isOnMenuBar, DS.ARGS())
        .def("addMenuItem", &PyAcadPopupMenu::addMenuItem, DS.ARGS({ "idx : int","label : str","macro : str" }))
        .def("addSubMenu", &PyAcadPopupMenu::addMenuItem, DS.ARGS({ "idx : int","label : str" }))
        .def("addSeparator", &PyAcadPopupMenu::addSeparator, DS.ARGS({ "idx : int" }))
        .def("insertInMenuBar", &PyAcadPopupMenu::insertInMenuBar, DS.ARGS({ "idx : int" }))
        .def("removeFromMenuBar", &PyAcadPopupMenu::removeFromMenuBar, DS.ARGS())
        .def("tagString", &PyAcadPopupMenu::tagString, DS.ARGS())
        .def("__getitem__", &PyAcadPopupMenu::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadPopupMenu::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPopupMenu::PyAcadPopupMenu(std::shared_ptr<PyIAcadPopupMenuImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadPopupMenu::count() const
{
    return impObj()->GetCount();
}

PyAcadPopupMenuItem PyAcadPopupMenu::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadPopupMenuItem{ impObj()->GetItem(index) };
}

PyAcadPopupMenus PyAcadPopupMenu::parent() const
{
    return PyAcadPopupMenus{ impObj()->GetParent() };
}

std::string PyAcadPopupMenu::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadPopupMenu::setName(const std::string& val)
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

std::string PyAcadPopupMenu::nameNoMnemonic() const
{
    return wstr_to_utf8(impObj()->GetNameNoMnemonic());
}

bool PyAcadPopupMenu::isShortcutMenu() const
{
    return impObj()->GetShortcutMenu();
}

bool PyAcadPopupMenu::isOnMenuBar() const
{
    return impObj()->GetOnMenuBar();
}

PyAcadPopupMenuItem PyAcadPopupMenu::addMenuItem(long index, const std::string& label, const std::string& macro)
{
    return PyAcadPopupMenuItem{ impObj()->AddMenuItem(index, utf8_to_wstr(label).c_str(), utf8_to_wstr(macro).c_str()) };
}

PyAcadPopupMenu PyAcadPopupMenu::addSubMenu(long index, const std::string& label)
{
    return PyAcadPopupMenu{ impObj()->AddSubMenu(index, utf8_to_wstr(label).c_str()) };
}

PyAcadPopupMenuItem PyAcadPopupMenu::addSeparator(long index) const
{
    return PyAcadPopupMenuItem{ impObj()->AddSeparator(index) };
}

void PyAcadPopupMenu::insertInMenuBar(long index) const
{
    impObj()->InsertInMenuBar(index);
}

void PyAcadPopupMenu::removeFromMenuBar() const
{
    impObj()->RemoveFromMenuBar();
}

std::string PyAcadPopupMenu::tagString() const
{
    return wstr_to_utf8(impObj()->GetTagString());
}

std::string PyAcadPopupMenu::className()
{
    return "AcadPopupMenu";
}

PyIAcadPopupMenuImpl* PyAcadPopupMenu::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadPopupMenus
void makePyAcadPopupMenusWrapper()
{
    PyDocString DS("AcadPopupMenus");
    class_<PyAcadPopupMenus>("AcadPopupMenus", boost::python::no_init)
        .def("count", &PyAcadPopupMenus::count, DS.ARGS())
        .def("item", &PyAcadPopupMenus::item, DS.ARGS({ "idx : int" }))
        .def("parent", &PyAcadPopupMenus::parent, DS.ARGS())
        .def("add", &PyAcadPopupMenus::add, DS.ARGS({ "toolbarName: str" }))
        .def("insertMenuInMenuBar", &PyAcadPopupMenus::insertMenuInMenuBar, DS.ARGS({ "insertMenuInMenuBar: str","idx : int" }))
        .def("removeMenuFromMenuBar", &PyAcadPopupMenus::removeMenuFromMenuBar, DS.ARGS({ "idx : int" }))
        .def("__getitem__", &PyAcadPopupMenus::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadPopupMenus::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPopupMenus::PyAcadPopupMenus(std::shared_ptr<PyIAcadPopupMenusImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadPopupMenus::count() const
{
    return impObj()->GetCount();
}

PyAcadPopupMenu PyAcadPopupMenus::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadPopupMenu{ impObj()->GetItem(index) };
}

PyAcadMenuGroup PyAcadPopupMenus::parent() const
{
    return PyAcadMenuGroup{ impObj()->GetParent() };
}

PyAcadPopupMenu PyAcadPopupMenus::add(const std::string& toolbarName)
{
    return PyAcadPopupMenu{ impObj()->Add(utf8_to_wstr(toolbarName).c_str()) };
}

void PyAcadPopupMenus::insertMenuInMenuBar(const std::string& menuName, long index)
{
    impObj()->InsertMenuInMenuBar(utf8_to_wstr(menuName).c_str(), index);
}

void PyAcadPopupMenus::removeMenuFromMenuBar(long index)
{
    impObj()->RemoveMenuFromMenuBar(index);
}

std::string PyAcadPopupMenus::className()
{
    return "AcadPopupMenus";
}

PyIAcadPopupMenusImpl* PyAcadPopupMenus::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadToolbarItem
void makePyAcadToolbarItemWrapper()
{
    PyDocString DS("AcadToolbarItem");
    class_<PyAcadToolbarItem>("AcadToolbarItem", boost::python::no_init)
        .def("parent", &PyAcadToolbarItem::parent, DS.ARGS())
        .def("name", &PyAcadToolbarItem::name, DS.ARGS())
        .def("setName", &PyAcadToolbarItem::setName, DS.ARGS({ "name: str" }))
        .def("tagString", &PyAcadToolbarItem::tagString, DS.ARGS())
        .def("setTagString", &PyAcadToolbarItem::setTagString, DS.ARGS({ "tag: str" }))
        .def("getType", &PyAcadToolbarItem::getType, DS.ARGS())
        .def("macro", &PyAcadToolbarItem::macro, DS.ARGS())
        .def("setMacro", &PyAcadToolbarItem::setMacro, DS.ARGS({ "macro: str" }))
        .def("index", &PyAcadToolbarItem::index, DS.ARGS())
        .def("helpString", &PyAcadToolbarItem::helpString, DS.ARGS())
        .def("setHelpString", &PyAcadToolbarItem::setHelpString, DS.ARGS({ "helpString: str" }))
        .def("bitmaps", &PyAcadToolbarItem::bitmaps, DS.ARGS())
        .def("setBitmaps", &PyAcadToolbarItem::setBitmaps, DS.ARGS({ "smallIconName: str", "largeIconName: str" }))
        .def("attachToolbarToFlyout", &PyAcadToolbarItem::attachToolbarToFlyout, DS.ARGS({ "menuGroupName: str", "menuGroupName: str" }))
        .def("clear", &PyAcadToolbarItem::clear, DS.ARGS())
        .def("commandDisplayName", &PyAcadToolbarItem::commandDisplayName, DS.ARGS())
        .def("setCommandDisplayName", &PyAcadToolbarItem::setCommandDisplayName, DS.ARGS({ "commandDisplayName: str" }))
        .def("className", &PyAcadToolbarItem::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadToolbarItem::PyAcadToolbarItem(std::shared_ptr<PyIAcadToolbarItemImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcadToolbar PyAcadToolbarItem::parent() const
{
    return PyAcadToolbar{ impObj()->GetParent() };
}

std::string PyAcadToolbarItem::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadToolbarItem::setName(const std::string& val)
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

std::string PyAcadToolbarItem::tagString() const
{
    return wstr_to_utf8(impObj()->GetTagString());
}

void PyAcadToolbarItem::setTagString(const std::string& val)
{
    impObj()->SetTagString(utf8_to_wstr(val).c_str());
}

PyAcToolbarItemType PyAcadToolbarItem::getType() const
{
    return impObj()->GetType();
}

std::string PyAcadToolbarItem::macro() const
{
    return wstr_to_utf8(impObj()->GetMacro());
}

void PyAcadToolbarItem::setMacro(const std::string& val)
{
    impObj()->SetMacro(utf8_to_wstr(val).c_str());
}

int PyAcadToolbarItem::index() const
{
    return impObj()->GetIndex();
}

std::string PyAcadToolbarItem::helpString() const
{
    return wstr_to_utf8(impObj()->GetHelpString());
}

void PyAcadToolbarItem::setHelpString(const std::string& val) const
{
    impObj()->SetHelpString(utf8_to_wstr(val).c_str());
}

boost::python::tuple PyAcadToolbarItem::bitmaps() const
{
    PyAutoLockGIL lock;
    const auto& val = impObj()->GetBitmaps();
    return boost::python::make_tuple(wstr_to_utf8(val.first), wstr_to_utf8(val.second));
}

void PyAcadToolbarItem::setBitmaps(const std::string& smallIconName, const std::string& largeIconName)
{
    impObj()->SetBitmaps(utf8_to_wstr(smallIconName).c_str(), utf8_to_wstr(largeIconName).c_str());
}

void PyAcadToolbarItem::attachToolbarToFlyout(const std::string& menuGroupName, const std::string& toolbarName)
{
    impObj()->AttachToolbarToFlyout(utf8_to_wstr(menuGroupName).c_str(), utf8_to_wstr(toolbarName).c_str());
}

void PyAcadToolbarItem::clear()
{
    impObj()->Delete();
}

std::string PyAcadToolbarItem::commandDisplayName() const
{
    return wstr_to_utf8(impObj()->GetCommandDisplayName());
}

void PyAcadToolbarItem::setCommandDisplayName(const std::string& val)
{
    impObj()->SetCommandDisplayName(utf8_to_wstr(val).c_str());
}

std::string PyAcadToolbarItem::className()
{
    return "AcadToolbarItem";
}

PyIAcadToolbarItemImpl* PyAcadToolbarItem::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadToolbar
void makePyAcadToolbarWrapper()
{
    PyDocString DS("AcadToolbar");
    class_<PyAcadToolbar>("AcadToolbar", boost::python::no_init)
        .def("count", &PyAcadToolbar::count, DS.ARGS())
        .def("item", &PyAcadToolbar::item, DS.ARGS({ "idx : int" }))
        .def("parent", &PyAcadToolbar::parent, DS.ARGS())
        .def("name", &PyAcadToolbar::name, DS.ARGS())
        .def("setName", &PyAcadToolbar::setName, DS.ARGS({ "name:str" }))
        .def("isVisible", &PyAcadToolbar::isVisible, DS.ARGS())
        .def("setVisible", &PyAcadToolbar::setVisible, DS.ARGS({ "visible:bool" }))
        .def("dockStatus", &PyAcadToolbar::dockStatus, DS.ARGS())
        .def("largeButtons", &PyAcadToolbar::largeButtons, DS.ARGS())
        .def("left", &PyAcadToolbar::left, DS.ARGS())
        .def("setLeft", &PyAcadToolbar::setLeft, DS.ARGS({ "left:int" }))
        .def("top", &PyAcadToolbar::top, DS.ARGS())
        .def("setTop", &PyAcadToolbar::setTop, DS.ARGS({ "top:int" }))
        .def("width", &PyAcadToolbar::width, DS.ARGS())
        .def("height", &PyAcadToolbar::height, DS.ARGS())
        .def("floatingRows", &PyAcadToolbar::floatingRows, DS.ARGS())
        .def("setFloatingRows", &PyAcadToolbar::setFloatingRows, DS.ARGS({ "nRows:int" }))
        .def("helpString", &PyAcadToolbar::helpString, DS.ARGS())
        .def("setHelpString", &PyAcadToolbar::setHelpString, DS.ARGS({ "helpString: str" }))
        .def("addToolbarButton", &PyAcadToolbar::addToolbarButton, DS.ARGS({ "index: int", "name: str", "helpstr: str","macro: str","flyoutButton:bool" }))
        .def("dock", &PyAcadToolbar::dock, DS.ARGS({ "val: PyAx.AcToolbarDockStatus" }))
        .def("setFloat", &PyAcadToolbar::setFloat, DS.ARGS({ "top:int","left:int","numberFloatRows:int" }))
        .def("clear", &PyAcadToolbar::clear, DS.ARGS())
        .def("tagString", &PyAcadToolbar::tagString, DS.ARGS())
        .def("__getitem__", &PyAcadToolbar::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadToolbar::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadToolbar::PyAcadToolbar(std::shared_ptr<PyIAcadToolbarImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadToolbar::count() const
{
    return impObj()->GetCount();
}

PyAcadToolbarItem PyAcadToolbar::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadToolbarItem{ impObj()->GetItem(index) };
}

PyAcadToolbars PyAcadToolbar::parent() const
{
    return PyAcadToolbars{ impObj()->GetParent() };
}

std::string PyAcadToolbar::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadToolbar::setName(const std::string& name)
{
    impObj()->SetName(utf8_to_wstr(name).c_str());
}

bool PyAcadToolbar::isVisible() const
{
    return impObj()->GetVisible();
}

void PyAcadToolbar::setVisible(bool val)
{
    impObj()->SetVisible(val);
}

PyAcToolbarDockStatus PyAcadToolbar::dockStatus() const
{
    return impObj()->GetDockStatus();
}

bool PyAcadToolbar::largeButtons() const
{
    return impObj()->GetLargeButtons();
}

int PyAcadToolbar::left() const
{
    return impObj()->GetLeft();
}

void PyAcadToolbar::setLeft(int val)
{
    return impObj()->SetLeft(val);
}

int PyAcadToolbar::top() const
{
    return impObj()->GetTop();
}

void PyAcadToolbar::setTop(int val)
{
    return impObj()->SetTop(val);
}

int PyAcadToolbar::width() const
{
    return impObj()->GetWidth();
}

int PyAcadToolbar::height() const
{
    return impObj()->GetHeight();
}

int PyAcadToolbar::floatingRows() const
{
    return impObj()->GetFloatingRows();
}

void PyAcadToolbar::setFloatingRows(int val)
{
    return impObj()->SetFloatingRows(val);
}

std::string PyAcadToolbar::helpString() const
{
    return wstr_to_utf8(impObj()->GetHelpString());
}

void PyAcadToolbar::setHelpString(const std::string& val) const
{
    impObj()->SetHelpString(utf8_to_wstr(val).c_str());
}

PyAcadToolbarItem PyAcadToolbar::addToolbarButton(int index, const std::string& name, const std::string& helpstr, const std::string& macro, bool flyoutButton)
{
    return PyAcadToolbarItem{ impObj()->AddToolbarButton(index,utf8_to_wstr(name).c_str(),utf8_to_wstr(helpstr).c_str(),utf8_to_wstr(macro).c_str(), flyoutButton) };
}

void PyAcadToolbar::dock(PyAcToolbarDockStatus val)
{
    impObj()->Dock(val);
}

void PyAcadToolbar::setFloat(int itop, int ileft, int numberFloatRows)
{
    impObj()->Float(itop, ileft, numberFloatRows);
}

void PyAcadToolbar::clear()
{
    impObj()->Delete();
}

std::string PyAcadToolbar::tagString() const
{
    return wstr_to_utf8(impObj()->GetTagString());
}

std::string PyAcadToolbar::className()
{
    return "AcadToolbar";
}

PyIAcadToolbarImpl* PyAcadToolbar::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//----------------------------------------------------------------------------------------
//PyAcadToolbars
void makePyAcadToolbarsWrapper()
{
    PyDocString DS("AcadToolbars");
    class_<PyAcadToolbars>("AcadToolbars", boost::python::no_init)
        .def("count", &PyAcadToolbars::count, DS.ARGS())
        .def("item", &PyAcadToolbars::item, DS.ARGS({ "idx : int" }))
        .def("parent", &PyAcadToolbars::parent, DS.ARGS())
        .def("largeButtons", &PyAcadToolbars::largeButtons, DS.ARGS())
        .def("setLargeButtons", &PyAcadToolbars::setLargeButtons, DS.ARGS({ "largeButtons:bool" }))
        .def("add", &PyAcadToolbars::add, DS.ARGS({ "toolbarName:str" }))
        .def("__getitem__", &PyAcadToolbars::item, DS.ARGS({ "index: int" }))
        .def("className", &PyAcadToolbars::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadToolbars::PyAcadToolbars(std::shared_ptr<PyIAcadToolbarsImpl> ptr)
    : m_pyImp(ptr)
{
}

long PyAcadToolbars::count() const
{
    return impObj()->GetCount();
}

PyAcadToolbar PyAcadToolbars::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadToolbar{ impObj()->GetItem(index) };
}

PyAcadMenuGroup PyAcadToolbars::parent() const
{
    return PyAcadMenuGroup{ impObj()->GetParent() };
}

bool PyAcadToolbars::largeButtons() const
{
    return impObj()->GetLargeButtons();
}

void PyAcadToolbars::setLargeButtons(bool val) const
{
    impObj()->SetLargeButtons(val);
}

PyAcadToolbar PyAcadToolbars::add(const std::string& toolbarName)
{
    return  PyAcadToolbar{ impObj()->Add(utf8_to_wstr(toolbarName).c_str()) };
}

std::string PyAcadToolbars::className()
{
    return "AcadToolbars";
}

PyIAcadToolbarsImpl* PyAcadToolbars::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}