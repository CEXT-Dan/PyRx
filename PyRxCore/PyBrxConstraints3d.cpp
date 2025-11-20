#include "stdafx.h"
#include "PyBrxConstraints3d.h"

#ifdef BRXAPP

using namespace boost::python;

//---------------------------------------------------------------------
//PyBrxConstraintArgument
void makePyBrxConstraintArgument()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- path: PyDb.AcDbFullSubentPath\n"
        "- cs: PyBrx.ConstraintArgCoordSysObj\n"
        "- path: PyDb.AcDbFullSubentPath, cs: PyBrx.ConstraintArgCoordSysObj\n";

    PyDocString DS("PyBrx.ConstraintArgument");
    class_<PyBrxConstraintArgument>("ConstraintArgument")
        .def(init<>())
        .def(init<AcConstraintArgument::CoordinateSystemObject>())
        .def(init<PyDbFullSubentPath>())
        .def(init<PyDbFullSubentPath, AcConstraintArgument::CoordinateSystemObject>(DS.CTOR(ctords)))
        .def("path", &PyBrxConstraintArgument::path, DS.ARGS())
        .def("isCoordinateSystemObject", &PyBrxConstraintArgument::isCoordinateSystemObject, DS.ARGS())
        .def("coordinateSystemObject", &PyBrxConstraintArgument::coordinateSystemObject, DS.ARGS())
        .def("className", &PyBrxConstraintArgument::className, DS.SARGS()).staticmethod("className")
        ;
}

PyBrxConstraintArgument::PyBrxConstraintArgument()
    : m_imp()
{
}

PyBrxConstraintArgument::PyBrxConstraintArgument(const PyDbFullSubentPath& path)
    : m_imp(path.pyImp)
{
}

PyBrxConstraintArgument::PyBrxConstraintArgument(AcConstraintArgument::CoordinateSystemObject cs)
    : m_imp(cs)
{
}

PyBrxConstraintArgument::PyBrxConstraintArgument(const PyDbFullSubentPath& path, AcConstraintArgument::CoordinateSystemObject cs)
    : m_imp(path.pyImp, cs)
{
}

PyDbFullSubentPath PyBrxConstraintArgument::path() const
{
    return PyDbFullSubentPath(m_imp.path());
}

bool PyBrxConstraintArgument::isCoordinateSystemObject() const
{
    return m_imp.isCoordinateSystemObject();
}

AcConstraintArgument::CoordinateSystemObject PyBrxConstraintArgument::coordinateSystemObject() const
{
    return m_imp.coordinateSystemObject();
}

std::string PyBrxConstraintArgument::className()
{
    return "AcConstraintArgument";
}

#endif