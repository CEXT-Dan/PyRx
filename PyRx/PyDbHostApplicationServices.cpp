#include "stdafx.h"
#include "PyDbHostApplicationServices.h"

using namespace boost::python;

void makeAcDbHostApplicationServicesWrapper()
{
    static auto wrapper = class_<PyDbHostApplicationServices, boost::noncopyable>("HostApplicationServices")
        .def(init<>())
        .def("workingDatabase", &PyDbHostApplicationServices::workingDatabase)
        ;
}

PyDbDatabase PyDbHostApplicationServices::workingDatabase() const
{
   return PyDbDatabase(pDbHostApp->workingDatabase());
}
