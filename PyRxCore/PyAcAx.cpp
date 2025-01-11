#include "stdafx.h"
#include "PyAcAx.h"

#ifdef PYRX_IN_PROGRESS_PYAX

#include "PyAcadObject.h"
using namespace boost::python;

BOOST_PYTHON_MODULE(PyAx)
{
    makePyAcadObjectWrapper();
}
void initPyAxModule()
{
    PyImport_AppendInittab(PyAxNamespace, &PyInit_PyAx);
}

#endif