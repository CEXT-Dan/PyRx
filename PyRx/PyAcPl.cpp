#include "stdafx.h"
#include "PyAcPl.h"
#include "PyPlObject.h"
#include "PyPlPlotProgressDialog.h"
#include "PyPlPlotConfigManager.h"
#include "PlCore.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyPl)
{
    docstring_options local_docstring_options(true, true, true);
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    // dead
#else
    makePyPlObjectWrapper();
    makePyPlDSDDataWrapper();
    makePyPlDSDEntryWrapper();
    makePyPlPlotInfoWrapper();
    makePyPlPlotConfigWrapper();
    makePyPlPlotPageInfoWrapper();
    makeAcPlPlotFactoryWrapper();
    makePyPlPlotEngineWrapper();
    makePyPlPlotInfoValidatorWrapper();
    makePyPlPlotProgressDialogWrapper();
    makePyPlPlotConfigInfoWrapper();
    makePyPlPrecisionEntryWrapper();
    makePyPlPlotConfigManagerWrapper();
    makePyPlCoreWrapper();
#endif
}

void initPyPlModule()
{
    PyImport_AppendInittab(PyPlNamespace, &PyInit_PyPl);
}
