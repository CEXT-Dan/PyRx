#include "stdafx.h"
#include "PyAcRx.h"
#include "PyRxObject.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyRx)
{
    docstring_options local_docstring_options(false, true, false);

    makeAcRxObjectWrapper();
    makeAcRxClassWrapper();
};

void initPyRxModule()
{
    PyImport_AppendInittab(PyRxNamespace, &PyInit_PyRx);
}
