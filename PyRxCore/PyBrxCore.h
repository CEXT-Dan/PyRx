#pragma once

#ifdef BRXAPP

class PyRxObject;

void makePyBrxCoreWrapper();

class PyBrxCore
{
public:
    static bool isLicenseAvailable(BricsCAD::LicensedFeature feature);
    static boost::python::list getOpenObjects();
};


#endif