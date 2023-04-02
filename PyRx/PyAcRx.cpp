#include "stdafx.h"
#include "PyAcRx.h"
#include "PyRxObject.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyRx)
{
#ifndef  PyRxDebug
    docstring_options local_docstring_options(false, true, false);
#endif // ! PyRxDebug
   
    makeAcRxObjectWrapper();
    makeAcRxClassWrapper();
};

void initPyRxModule()
{
    PyImport_AppendInittab(PyRxNamespace, &PyInit_PyRx);
}
