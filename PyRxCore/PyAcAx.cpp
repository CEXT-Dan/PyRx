#include "stdafx.h"
#include "PyAcAx.h"

#ifdef PYRX_IN_PROGRESS_PYAX
using namespace boost::python;

BOOST_PYTHON_MODULE(PyAx)
{
}
void initPyAxModule()
{
    PyImport_AppendInittab(PyAxNamespace, &PyInit_PyAx);
}

#endif