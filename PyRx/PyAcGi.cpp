#include "stdafx.h"
#include "PyAcGi.h"
#include "PyGiDrawable.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyGi)
{
    makeAcGiObjectWrapper();
}

void initPyGiModule()
{
    PyImport_AppendInittab(PyGiNamespace, &PyInit_PyGi);
}
