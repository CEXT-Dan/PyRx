#include "stdafx.h"
#include "PyBrxCore.h"

#ifdef BRXAPP

#include "brxDevHelper.h"
#include "PyDbObject.h"

using namespace boost::python;
void makePyBrxCoreWrapper()
{
    PyDocString DS("Core");
    class_<PyBrxCore>("Core", boost::python::no_init)
        .def("isLicenseAvailable", &PyBrxCore::isLicenseAvailable, DS.SARGS({ "val: PyBrx.LicensedFeature" })).staticmethod("isLicenseAvailable")
        .def("getOpenObjects", &PyBrxCore::getOpenObjects, DS.SARGS()).staticmethod("getOpenObjects")
        ;
}

bool PyBrxCore::isLicenseAvailable(BricsCAD::LicensedFeature feature)
{
    return ::isLicenseAvailable(feature);
}


boost::python::list PyBrxCore::getOpenObjects()
{
    AcArray<AcDbObject*> objs;
    BRX::getOpenObjects(objs);
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto item : objs)
        _pylist.append(PyDbObject(item, false));
    return _pylist;
}

#endif
