#include "stdafx.h"
#include "PyAcGs.h"
#include "GsCore.h"
#include "PyGsManager.h"
#include "PyGsView.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyGs)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

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
