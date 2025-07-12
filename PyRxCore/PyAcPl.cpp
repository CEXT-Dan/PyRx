#include "stdafx.h"
#include "PyAcPl.h"
#include "PyPlObject.h"
#include "PyPlPlotProgressDialog.h"
#include "PyPlPlotConfigManager.h"
#include "PlCore.h"

using namespace boost::python;

static BOOST_PYTHON_MODULE(PyPl)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);
#if defined(_BRXTARGET260)
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
