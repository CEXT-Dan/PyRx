#include "stdafx.h"
#include "PyAcAx.h"
#include "PyAcadObject.h"
#include "PyAcadEntity.h"
#include "PyAcadApplication.h"
using namespace boost::python;

BOOST_PYTHON_MODULE(PyAx)
{
    makePyAcadStateWrapper();
    makePyAcadObjectWrapper();
    makePyAcadEntityWrapper();
    makePyAcadDatabaseWrapper();
    makePyAcadDocumentWrapper();
    makePyAcadDocumentsWrapper();
    makePyAcadApplicationWrapper();


    //PyAcSectionGeneration
    //PyAcWindowState
    //PyAcColorMethod
    //PyAcColor
    //AcZoomScaleType
}
void initPyAxModule()
{
    PyImport_AppendInittab(PyAxNamespace, &PyInit_PyAx);
}
