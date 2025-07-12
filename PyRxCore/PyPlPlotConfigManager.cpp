#include "stdafx.h"
#include "PyPlPlotConfigManager.h"
#include "PyPlObject.h"

using namespace boost::python;


#if defined(_BRXTARGET260)
// dead
#else
void makePyPlPlotConfigManagerWrapper()
{
    PyDocString DS("PlotConfigManager");
    class_<PyPlPlotConfigManager>("PlotConfigManager")
        .def("getDevicesList", &PyPlPlotConfigManager::getDevicesList, DS.ARGS())
        .def("getStyleList", &PyPlPlotConfigManager::getStyleList, DS.ARGS())
        .def("refreshList", &PyPlPlotConfigManager::refreshList1)
        .def("refreshList", &PyPlPlotConfigManager::refreshList2, DS.ARGS({"refreshCode:PyPl.RefreshCode= PyPl.RefreshCode.kAll"}))
        .def("getCurrentConfig", &PyPlPlotConfigManager::getCurrentConfig)
        .def("setCurrentConfig", &PyPlPlotConfigManager::setCurrentConfig, DS.ARGS({ "deviceName: str" }))
        .def("getStdConfigName", &PyPlPlotConfigManager::getStdConfigName)
        .def("className", &PyPlPlotConfigManager::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<DeviceType>("DeviceType")
        .value("kSystemPrinter", DeviceType::kSystemPrinter)
        .value("kPC3File", DeviceType::kPC3File)
        .value("kOneOffConfig", DeviceType::kOneOffConfig)
        .value("kUninitialized", DeviceType::kUninitialized)
        .export_values()
        ;

    enum_<AcPlPlotConfigManager::RefreshCode>("RefreshCode")
        .value("kAll", AcPlPlotConfigManager::RefreshCode::kAll)
        .value("kRefreshDevicesList", AcPlPlotConfigManager::RefreshCode::kRefreshDevicesList)
        .value("kRefreshStyleList", AcPlPlotConfigManager::RefreshCode::kRefreshStyleList)
        .value("kRefreshSystemDevicesList", AcPlPlotConfigManager::RefreshCode::kRefreshSystemDevicesList)
        .value("kRefreshPC3DevicesList", AcPlPlotConfigManager::RefreshCode::kRefreshPC3DevicesList)
        .export_values()
        ;

    enum_<AcPlPlotConfigManager::StyTypes>("StyTypes")
        .value("kUndefined", AcPlPlotConfigManager::StyTypes::kUndefined)
        .value("kRegular", AcPlPlotConfigManager::StyTypes::kRegular)
        .value("kTranslation", AcPlPlotConfigManager::StyTypes::kTranslation)
        .value("kColorDep", AcPlPlotConfigManager::StyTypes::kColorDep)
        .value("kAllTypes", AcPlPlotConfigManager::StyTypes::kAllTypes)
        .export_values()
        ;

    enum_<AcPlPlotConfigManager::StdConfigs>("StdConfigs")
        .value("kNoneDevice", AcPlPlotConfigManager::StdConfigs::kNoneDevice)
        .value("kDefaultWindowsSysPrinter", AcPlPlotConfigManager::StdConfigs::kDefaultWindowsSysPrinter)
        .value("kDWF6ePlot", AcPlPlotConfigManager::StdConfigs::kDWF6ePlot)
        .value("kDWFePlotOptForPlotting", AcPlPlotConfigManager::StdConfigs::kDWFePlotOptForPlotting)
        .value("kDWFePlotOptForViewing", AcPlPlotConfigManager::StdConfigs::kDWFePlotOptForViewing)
        .value("kPublishToWebDWF", AcPlPlotConfigManager::StdConfigs::kPublishToWebDWF)
        .value("kPublishToWebJPG", AcPlPlotConfigManager::StdConfigs::kPublishToWebJPG)
        .value("kPublishToWebPNG", AcPlPlotConfigManager::StdConfigs::kPublishToWebPNG)
        .value("kDWFxePlot", AcPlPlotConfigManager::StdConfigs::kDWFxePlot)
        .value("kPublishToWebDWFx", AcPlPlotConfigManager::StdConfigs::kPublishToWebDWFx)
        .value("kPDFePlot", AcPlPlotConfigManager::StdConfigs::kPDFePlot)
        .value("kPDFePlotGeneralDocs", AcPlPlotConfigManager::StdConfigs::kPDFePlotGeneralDocs)
        .value("kPDFePlotHighQuality", AcPlPlotConfigManager::StdConfigs::kPDFePlotHighQuality)
        .value("kPDFePlotSmallerFile", AcPlPlotConfigManager::StdConfigs::kPDFePlotSmallerFile)
        .value("kPDFePlotWebMobile", AcPlPlotConfigManager::StdConfigs::kPDFePlotWebMobile)
        .value("kSVFePlot", AcPlPlotConfigManager::StdConfigs::kSVFePlot)
        .export_values()
        ;
}

PyPlPlotConfigManager::PyPlPlotConfigManager()
    : m_imp(acplPlotConfigManagerPtr())
{
}

boost::python::list PyPlPlotConfigManager::getDevicesList() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcArray<AcPlPlotConfigInfo, AcArrayObjectCopyReallocator <AcPlPlotConfigInfo>> deviceList;
    impObj()->getDevicesList(deviceList);
    for (const auto& item : deviceList)
        pyList.append(PyPlPlotConfigInfo(item));
    return pyList;
}

boost::python::list PyPlPlotConfigManager::getStyleList() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcArray<ACHAR*> stypeList;
    impObj()->getStyleList(stypeList);
    for (auto item : stypeList)
    {
        pyList.append(wstr_to_utf8(item).c_str());
        acutDelString(item);
    }
    return pyList;
}

void PyPlPlotConfigManager::refreshList1() const
{
    impObj()->refreshList();
}

void PyPlPlotConfigManager::refreshList2(AcPlPlotConfigManager::RefreshCode refreshCode) const
{
    impObj()->refreshList(refreshCode);
}

PyPlPlotConfig PyPlPlotConfigManager::getCurrentConfig() const
{
    AcPlPlotConfig* pConfig = nullptr;
    PyThrowBadEs(impObj()->getCurrentConfig(pConfig));
    return PyPlPlotConfig(pConfig, false);
}

//TODO: should be deleted? but the app crashes if it is, the C++ sample does not delete
PyPlPlotConfig PyPlPlotConfigManager::setCurrentConfig(const std::string& pDeviceName) const
{
    AcPlPlotConfig* pConfig = nullptr;
    PyThrowBadEs(impObj()->setCurrentConfig(pConfig, utf8_to_wstr(pDeviceName).c_str()));
    return PyPlPlotConfig(pConfig, false);
}

std::string PyPlPlotConfigManager::getStdConfigName(AcPlPlotConfigManager::StdConfigs stdConfig) const
{
    return wstr_to_utf8(impObj()->getStdConfigName(stdConfig));
}

std::string PyPlPlotConfigManager::className()
{
    return "AcPlPlotConfigManager";
}

AcPlPlotConfigManager* PyPlPlotConfigManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_imp;
}
#endif