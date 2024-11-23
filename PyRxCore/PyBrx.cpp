#include "stdafx.h"
#include "PyBrx.h"
#include "PyBrxDbProperties.h"
#include "PyBrxCore.h"

#ifdef BRXAPP

using namespace boost::python;

BOOST_PYTHON_MODULE(PyBrx)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    makePyBrxCoreWrapper();
#ifndef _BRXTARGET240
    makePyBrxDbPropertiesWrapper();
#endif
    enum_<BricsCAD::LicensedFeature>("LicensedFeature")
        .value("eCore", BricsCAD::LicensedFeature::eCore)
        .value("eCommunicator", BricsCAD::LicensedFeature::eCommunicator)
        .value("eBim", BricsCAD::LicensedFeature::eBim)
        .value("eMechanical", BricsCAD::LicensedFeature::eMechanical)
        .export_values()
        ;
}

void initPyBrxModule()
{
    PyImport_AppendInittab(PyBrxNamespace, &PyInit_PyBrx);
}
#endif
