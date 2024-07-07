#pragma once

#ifdef BRXAPP
#include "BuildingElements.h"

void makePyBrxBimPoliciesWrapper();

class PyBrxBimPolicies
{
public:
    static void setPolicy(BrxBimPolicies::EPolicyOptions option, bool enable);
    static bool getPolicy(BrxBimPolicies::EPolicyOptions option);
    static std::string className();
};

#endif//BRXAPP
