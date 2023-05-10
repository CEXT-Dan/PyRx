#include "stdafx.h"
#include "PyAcGi.h"
#include "PyGiDrawable.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyGi)
{
#ifndef  PyRxDebug
    docstring_options local_docstring_options(false, true, true);
#endif // ! PyRxDebug


    makeAcGiObjectWrapper();
}

void initPyGiModule()
{
    PyImport_AppendInittab(PyGiNamespace, &PyInit_PyGi);
}
