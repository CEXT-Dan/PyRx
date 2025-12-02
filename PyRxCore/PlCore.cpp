#include "stdafx.h"
#include "PlCore.h"
#include "PyPlObject.h"
#include "acplmisc.h"

using namespace boost::python;


void makePyPlCoreWrapper()
{
    PyDocString DS("Core");
    class_<PlCore>("Core")
        .def(init<>(DS.ARGS()))
        .def("processPlotState", &PlCore::processPlotState, DS.SARGS()).staticmethod("processPlotState")
        .def("publishExecute", &PlCore::publishExecute, DS.SARGS({ "dsdDataObj: PyPl.DSDData","pConfig: PyPl.PlotConfig","bShowPlotProgress: bool" })).staticmethod("publishExecute")
        .def("className", &PlCore::className, DS.SARGS()).staticmethod("className")
        ;
}

ProcessPlotState PlCore::processPlotState()
{
    return acplProcessPlotState();
}

void PlCore::publishExecute(const PyPlDSDData& dsdDataObj, const PyPlPlotConfig& pConfig, bool bShowPlotProgress)
{
#if defined(_IRXTARGET140)
    throw PyNotimplementedByHost{};
#else
    acplPublishExecute(*dsdDataObj.impObj(), pConfig.impObj(), bShowPlotProgress);
#endif
}

std::string PlCore::className()
{
    return "PlCore";
}
