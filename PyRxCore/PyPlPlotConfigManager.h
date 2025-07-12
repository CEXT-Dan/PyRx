#pragma once
#pragma pack (push, 8)
#if defined(_BRXTARGET260)
// dead
#else

class PyPlPlotConfig;
class PyPlPlotConfig;

//-----------------------------------------------------------------------------------------
//PyPlPlotConfigManager
void makePyPlPlotConfigManagerWrapper();


class PyPlPlotConfigManager
{
public:
    PyPlPlotConfigManager();
    ~PyPlPlotConfigManager() = default;
    boost::python::list getDevicesList() const;
    boost::python::list getStyleList() const;
    void                refreshList1() const;
    void                refreshList2(AcPlPlotConfigManager::RefreshCode refreshCode) const;
    PyPlPlotConfig      getCurrentConfig() const;
    PyPlPlotConfig      setCurrentConfig(const std::string& pDeviceName) const;
    std::string         getStdConfigName(AcPlPlotConfigManager::StdConfigs stdConfig) const;
    static std::string  className();
public:
    AcPlPlotConfigManager* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    AcPlPlotConfigManager* m_imp = nullptr;
};

#endif
#pragma pack (pop)
