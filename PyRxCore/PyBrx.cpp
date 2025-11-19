#include "stdafx.h"
#include "PyBrx.h"
#include "PyBrxDbProperties.h"
#include "PyBrxCore.h"
#include "PyBrxPanel.h"
#include "PyBrxComponents.h"

#ifdef BRXAPP

using namespace boost::python;

static BOOST_PYTHON_MODULE(PyBrx)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    makePyBrxCoreWrapper();
#ifndef _BRXTARGET240
    makePyBrxDbPropertiesWrapper();
#endif
    makePyBrxPanelWrapper();
    makePyBrxMechanicalPropertySet();
    makePyBrxMechanicalPropertyDefinition();

    enum_<BricsCAD::LicensedFeature>("LicensedFeature")
        .value("eCore", BricsCAD::LicensedFeature::eCore)
        .value("eCommunicator", BricsCAD::LicensedFeature::eCommunicator)
        .value("eBim", BricsCAD::LicensedFeature::eBim)
        .value("eMechanical", BricsCAD::LicensedFeature::eMechanical)
        .export_values()
        ;

    enum_<BrxMechanicalPropertyType>("MechanicalPropertyType")
        .value("eUndefined", BrxMechanicalPropertyType::eUndefined)
        .value("eInteger", BrxMechanicalPropertyType::eInteger)
        .value("eReal", BrxMechanicalPropertyType::eReal)
        .value("eBoolean", BrxMechanicalPropertyType::eBoolean)
        .value("eString", BrxMechanicalPropertyType::eString)
        .export_values()
        ;
}


void initPyBrxModule()
{
    PyImport_AppendInittab(PyBrxNamespace, &PyInit_PyBrx);
}
#endif
