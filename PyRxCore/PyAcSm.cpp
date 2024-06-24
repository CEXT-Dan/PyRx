#include "stdafx.h"
#include "PyAcSm.h"


using namespace boost::python;

BOOST_PYTHON_MODULE(PySm)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

}

void initPySmModule()
{
    PyImport_AppendInittab(PySmNamespace, &PyInit_PySm);
}
