#include "stdafx.h"
#include "PyAcGe.h"

using namespace boost::python;


std::string AcGeVector2ToString(const AcGeVector2d& p)
{
    return std::format("({},{})", p.x, p.y);
}

std::string AcGePoint2dToString(const AcGePoint2d& p)
{
    return std::format("({},{})", p.x, p.y);
}

std::string AcGeVector3dToString(const AcGeVector3d& p)
{
    return std::format("({},{},{})", p.x, p.y, p.z);
}

std::string AcGePoint3dToString(const AcGePoint3d& p)
{
   return std::format("({},{},{})", p.x, p.y, p.z);
}

static auto makeAcGePoint2dWrapper()
{
    static auto wrapper = class_<AcGePoint2d>("Point2d")
        .def(init<>())
        .def(init<double, double>())
        .def("distanceTo", &AcGePoint2d::distanceTo)
        .def("transformBy", &AcGePoint2d::transformBy, return_value_policy<reference_existing_object>())
        .def_readwrite("x", &AcGePoint2d::x)
        .def_readwrite("y", &AcGePoint2d::y)
        .def_readonly("kOrigin", &AcGePoint2d::kOrigin)
        .def("toString", &AcGePoint2dToString)
        ;
    return wrapper;
}

static auto makeAcGeVector2dWrapper()
{
    static auto wrapper = class_<AcGeVector2d>("Vector2d")
        .def(init<>())
        .def(init<double, double>())
        .def_readonly("kXAxis", &AcGeVector2d::kXAxis)
        .def_readonly("kYAxis", &AcGeVector2d::kYAxis)
        .def("toString", &AcGeVector2ToString)
        ;
    return wrapper;
}

static auto makeAcGeMatrix2dWrapper()
{
    static auto wrapper = class_<AcGeMatrix2d>("Matrix2d")
        .def("scale", &AcGeMatrix2d::scale)
        .def("setToScaling", &AcGeMatrix2d::setToScaling, return_value_policy<reference_existing_object>())
        .def("setToRotation", &AcGeMatrix2d::setToRotation, return_value_policy<reference_existing_object>())
        ;
    return wrapper;
}

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
        .def("toString", &AcGePoint3dToString)
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
        .def("toString", &AcGeVector3dToString)
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

BOOST_PYTHON_MODULE(PyGe)
{
    makeAcGePoint2dWrapper();
    makeAcGeVector2dWrapper();
    makeAcGeMatrix2dWrapper();

    makeAcGePoint3dWrapper();
    makeAcGeVector3dWrapper();
    makeAcGeMatrix3dWrapper();
};

void initPyGeModule()
{
    PyImport_AppendInittab(PyGeNamespace, &PyInit_PyGe);
}
