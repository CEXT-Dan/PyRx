#include "stdafx.h"
#include "PyAcPl.h"


using namespace boost::python;

BOOST_PYTHON_MODULE(PyPl)
{
    docstring_options local_docstring_options(true, true, true);

}

void initPyPlModule()
{
    PyImport_AppendInittab(PyApNamespace, &PyInit_PyPl);
}
