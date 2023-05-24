#include "stdafx.h"
#include "PyAcGi.h"
#include "PyGiDrawable.h"
#include "PyGiCommonDraw.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyGi)
{
#ifndef  PyRxDebug
    docstring_options local_docstring_options(false, true, true);
#endif // ! PyRxDebug

    makeAcGiObjectWrapper();
    makePyGiCommonDrawWrapper();
    makePyGiWorldDrawWrapper();
    makeAcGiViewportDrawWrapper();

    makeAcGiDrawableOverruleWrapper();

    makeAcGiGeometryWrapper();
    makeAcGiWorldGeometryWrapper();
    makeAcGiViewportGeometryWrapper();
}

void initPyGiModule()
{
    PyImport_AppendInittab(PyGiNamespace, &PyInit_PyGi);
}
