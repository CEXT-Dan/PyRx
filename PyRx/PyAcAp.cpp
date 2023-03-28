#include "stdafx.h"
#include "PyAcAp.h"

#include "PyApDocument.h"
#include "PyApDocManager.h"
#include "PyApApplication.h"

using namespace boost::python;


BOOST_PYTHON_MODULE(PyAp)
{
    register_exception_translator<PyNullObject>(PyNullObject::translator);
    register_exception_translator<PyNotThatKindOfClass>(PyNotThatKindOfClass::translator);

    makeAcApApplictionWrapper();
    makeAcApDocManagerWrapper();
    makeAcApDocumentWrapper();
};

void initPyApModule()
{
    PyImport_AppendInittab(PyApNamespace, &PyInit_PyAp);
}


