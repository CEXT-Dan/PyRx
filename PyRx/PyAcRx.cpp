#include "stdafx.h"
#include "PyAcRx.h"
#include "PyRxObject.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyRx)
{
    makeAcRxObjectWrapper();
    makeAcRxClassWrapper();
};

void initPyRxModule()
{
    PyImport_AppendInittab(PyRxNamespace, &PyInit_PyRx);
}
