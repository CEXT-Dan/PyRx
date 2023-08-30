#include "stdafx.h"
#include "PyAcPl.h"
#include "PyPlObject.h"
#include "PyPlPlotProgressDialog.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyPl)
{
    docstring_options local_docstring_options(true, true, true);

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
}

void initPyPlModule()
{
    PyImport_AppendInittab(PyPlNamespace, &PyInit_PyPl);
}
