#pragma once
#pragma pack (push, 8)

class PyPlDSDData;
class PyPlPlotConfig;

void makePyPlCoreWrapper();

class PlCore
{
public:
    static ProcessPlotState processPlotState();
    static void publishExecute(const PyPlDSDData& dsdDataObj, const PyPlPlotConfig& pConfig, bool bShowPlotProgress);
    static std::string className();
};

#pragma pack (pop)