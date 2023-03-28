#include "stdafx.h"
#include "PyAcGe.h"

using namespace boost::python;

static auto makeAcGePoint3dWrapper()
{
    static auto wrapper = class_<AcGePoint3d>("Point3d")
        .def(init<>())
        .def(init<double, double, double>())
        .def("distanceTo", &AcGePoint3d::distanceTo)
        .def("transformBy", &AcGePoint3d::transformBy, return_value_policy<reference_existing_object>())
        .def_readwrite("x", &AcGePoint3d::x)
        .def_readwrite("y", &AcGePoint3d::y)
        .def_readwrite("z", &AcGePoint3d::z)
        .def_readonly("kOrigin", &AcGePoint3d::kOrigin)
        ;
    return wrapper;
}

static auto makeAcGeMatrix3dWrapper()
{
    static auto wrapper = class_<AcGeMatrix3d>("Matrix3d")
        .def("scale", &AcGeMatrix3d::scale)
        .def("setToScaling", &AcGeMatrix3d::setToScaling, return_value_policy<reference_existing_object>())
        .def("setToRotation", &AcGeMatrix3d::setToRotation, return_value_policy<reference_existing_object>())
        ;
    return wrapper;
}

static auto makeAcGeVector3dWrapper()
{
    static auto wrapper = class_<AcGeVector3d>("Vector3d")
        .def(init<>())
        .def(init<double, double, double>())
        .def_readonly("kXAxis", &AcGeVector3d::kXAxis)
        .def_readonly("kYAxis", &AcGeVector3d::kYAxis)
        .def_readonly("kZAxis", &AcGeVector3d::kZAxis)
        ;
    return wrapper;
}

BOOST_PYTHON_MODULE(PyGe)
{
    makeAcGePoint3dWrapper();
    makeAcGeMatrix3dWrapper();
    makeAcGeVector3dWrapper();
};

void initPyGeModule()
{
    PyImport_AppendInittab(PyGeNamespace, &PyInit_PyGe);
}
