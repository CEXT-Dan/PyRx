#pragma once
#pragma pack (push, 8)
#if defined(_BRXTARGET) && _BRXTARGET <= 240
// dead
#else

class PyPlPlotConfig;

//-----------------------------------------------------------------------------------------
//PyPlPlotConfigManager
void makePyPlPlotConfigManagerWrapper();


class PyPlPlotConfigManager
{
public:
    PyPlPlotConfigManager();
    ~PyPlPlotConfigManager() = default;
    boost::python::list getDevicesList();
    boost::python::list getStyleList();
    void                refreshList1();
    void                refreshList2(AcPlPlotConfigManager::RefreshCode refreshCode);
    PyPlPlotConfig      getCurrentConfig();
    PyPlPlotConfig      setCurrentConfig(const std::string& pDeviceName);
    std::string         getStdConfigName(AcPlPlotConfigManager::StdConfigs stdConfig);
    static std::string  className();
public:
    inline AcPlPlotConfigManager* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    AcPlPlotConfigManager* m_imp = nullptr;
};

#endif
#pragma pack (pop)
