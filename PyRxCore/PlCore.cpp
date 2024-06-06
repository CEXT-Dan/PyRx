#include "stdafx.h"
#include "PlCore.h"
#include "PyPlObject.h"
#include "acplmisc.h"

using namespace boost::python;

#if defined(_BRXTARGET) && _BRXTARGET <= 240
//
#else
void makePyPlCoreWrapper()
{
    PyDocString DS("Core");
    class_<PlCore>("Core")
        .def("processPlotState", &PlCore::processPlotState).staticmethod("processPlotState")
        .def("publishExecute", &PlCore::publishExecute).staticmethod("publishExecute")
        .def("className", &PlCore::className, DS.SARGS()).staticmethod("className")
        ;
}

ProcessPlotState PlCore::processPlotState()
{
    return acplProcessPlotState();
}

void PlCore::publishExecute(const PyPlDSDData& dsdDataObj, const PyPlPlotConfig& pConfig, bool bShowPlotProgress)
{
    acplPublishExecute(*dsdDataObj.impObj(), pConfig.impObj(), bShowPlotProgress);
}

std::string PlCore::className()
{
    return "PlCore";
}
#endif
