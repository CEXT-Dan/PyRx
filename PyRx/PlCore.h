#pragma once

#if defined(_BRXTARGET) && _BRXTARGET <= 240
// dead
#else
class PyPlDSDData;
class PyPlPlotConfig;

void makePyPlCoreWrapper();

class PlCore
{
public:
    static ProcessPlotState processPlotState();
    static void publishExecute(const PyPlDSDData& dsdDataObj, const PyPlPlotConfig& pConfig,bool bShowPlotProgress);
    static std::string className();
};

#endif