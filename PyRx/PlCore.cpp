#include "stdafx.h"
#include "PlCore.h"
#include "PyPlObject.h"
#include "acplmisc.h"

using namespace boost::python;


void makePyPlCoreWrapper()
{
    PyDocString DS("Core");
    class_<PlCore>("Core")

        .def("className", &PlCore::className, DS.SARGS()).staticmethod("className")
        ;
}

void PlCore::publishExecute(const PyPlDSDData& dsdDataObj, const PyPlPlotConfig& pConfig, bool bShowPlotProgress)
{
    acplPublishExecute(*dsdDataObj.impObj(), pConfig.impObj(), bShowPlotProgress);
}

std::string PlCore::className()
{
    return "PlCore";
}
