#pragma once

#ifdef BRXAPP
void makePyBrxCoreWrapper();

class PyBrxCore
{
public:
    static bool isLicenseAvailable(BricsCAD::LicensedFeature feature);
};


#endif