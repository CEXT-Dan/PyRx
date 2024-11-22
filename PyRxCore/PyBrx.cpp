#include "stdafx.h"
#include "PyBrx.h"
#include "PyBrxDbProperties.h"

#ifdef BRXAPP

using namespace boost::python;

BOOST_PYTHON_MODULE(PyBrx)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

#ifndef _BRXTARGET240
    makePyBrxDbPropertiesWrapper();
#endif
}

void initPyBrxModule()
{
    PyImport_AppendInittab(PyBrxNamespace, &PyInit_PyBrx);
}
#endif
