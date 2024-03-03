#include "stdafx.h"
#include "PyAcGs.h"
#include "GsCore.h"
#include "PyGsManager.h"
#include "PyGsView.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyGs)
{
    docstring_options local_docstring_options(true, true, true);

    makeGsCoreWrapper();
    makePyGsManagerWrapper();
    makePyGsViewWrapper();

#ifdef PYRX_IN_PROGRESS_GS_GI
    makePyGsKernelDescriptorWrapper();
    makePyGsGraphicsKernelWrapper();
#endif
}

void initPyGsModule()
{
    PyImport_AppendInittab(PyGsNamespace, &PyInit_PyGs);
}
