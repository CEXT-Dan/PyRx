#include "stdafx.h"
#include "PyAcGs.h"
BOOST_PYTHON_MODULE(PyGs)
{
}

void initPyGsModule()
{
    PyImport_AppendInittab(PyGiNamespace, &PyInit_PyGs);
}
