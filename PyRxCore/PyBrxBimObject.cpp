#include "stdafx.h"
#include "PyBrxBimObject.h"


#ifdef BRXAPP
using namespace boost::python;

void makePyBrxBimPoliciesWrapper()
{
    PyDocString DS("Application");
    class_<BrxBimPolicies>("BimPolicies")
        .def("getPolicy", &PyBrxBimPolicies::getPolicy, DS.SARGS({ "option: PyBrxBim.BimPolicyOptions" })).staticmethod("getPolicy")
        .def("setPolicy", &PyBrxBimPolicies::setPolicy, DS.SARGS({ "option: PyBrxBim.BimPolicyOptions", "enable: bool"})).staticmethod("setPolicy")
        .def("className", &PyBrxBimPolicies::className, DS.SARGS()).staticmethod("className")
        ;
}

void PyBrxBimPolicies::setPolicy(BrxBimPolicies::EPolicyOptions option, bool enable)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    BrxBimPolicies::setPolicy(option, enable);
#endif
}

bool PyBrxBimPolicies::getPolicy(BrxBimPolicies::EPolicyOptions option)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return BrxBimPolicies::getPolicy(option);
#endif
}

std::string PyBrxBimPolicies::className()
{
    return "BrxBimPolicies";
}
#endif//BRXAPP


