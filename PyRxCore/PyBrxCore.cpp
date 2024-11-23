#include "stdafx.h"
#include "PyBrxCore.h"

#ifdef BRXAPP

using namespace boost::python;
void makePyBrxCoreWrapper()
{
    PyDocString DS("Core");
    class_<PyBrxCore>("Core", boost::python::no_init)
        .def("isLicenseAvailable", &PyBrxCore::isLicenseAvailable, DS.SARGS({ "val: PyBrx.LicensedFeature" })).staticmethod("isLicenseAvailable")
        ;
}

bool PyBrxCore::isLicenseAvailable(BricsCAD::LicensedFeature feature)
{
    return ::isLicenseAvailable(feature);
}


#endif
