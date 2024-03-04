#include "stdafx.h"
#include "PyBrxCv.h"
#include "PyBrxCvBase.h"

#ifdef BRXAPP

using namespace boost::python;

BOOST_PYTHON_MODULE(PyBrxCv)
{
    docstring_options local_docstring_options(true, true, true);
    makePyBrxCvDbObjectWrapper();
    makePyBrxCvDbEntityWrapper();
    makePyBrxCvDbCurveWrapper();
};

void initPyBrxCvModule()
{
    PyImport_AppendInittab(PyBrxCvNamespace, &PyInit_PyBrxCv);
}

#endif