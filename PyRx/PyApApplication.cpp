#include "stdafx.h"
#include "PyApApplication.h"
#include "PyApDocManager.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
void makeAcApApplictionWrapper()
{
    class_<PyApApplication>("Application")
        .def("docManager", &PyApApplication::docManager)
        .def("className", &PyApApplication::className).staticmethod("className")
        .def("mainWnd", &PyApApplication::mainWnd).staticmethod("mainWnd")
        ;
}

PyApDocManager PyApApplication::docManager()
{
    return PyApDocManager(acDocManager, false);
}

int64_t PyApApplication::mainWnd()
{
    return reinterpret_cast<int64_t>(adsw_acadMainWnd());
}

std::string PyApApplication::className()
{
    return std::string{ "AcApApplication" };
}


//-----------------------------------------------------------------------------------------
//makeAPyApResourceOverrideWrapper  Wrapper
void makeAPyApResourceOverrideWrapper()
{
    class_<PyApResourceOverride>("ResourceOverride")
        ;
}
