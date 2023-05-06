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
        ;
}

//-----------------------------------------------------------------------------------------
//PyApApplication  Wrapper
PyApDocManager PyApApplication::docManager()
{
   return PyApDocManager(acDocManager, false);
}

std::string PyApApplication::className()
{
    return std::string{ "AcApApplication" };
}
