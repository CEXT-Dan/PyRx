#include "stdafx.h"
#include "PyGeCurveCurveInt3d.h"

using namespace boost::python;

void makePyGeCurveCurveInt3dWrapper()
{
    class_<PyGeCurveCurveInt3d, bases<PyGeEntity3d>>("CurveCurveInt3d")
        .def(init<>())
        .def("className", &PyGeEntity3d::className).staticmethod("className")
        ;
}

PyGeCurveCurveInt3d::PyGeCurveCurveInt3d()
    : PyGeEntity3d(new AcGeCurveCurveInt3d())
{
}

PyGeCurveCurveInt3d::PyGeCurveCurveInt3d(AcGeEntity3d* pEnt)
    : PyGeEntity3d(pEnt)
{
}

std::string PyGeCurveCurveInt3d::className()
{
    return "AcGeCurveCurveInt3d";
}

AcGeCurveCurveInt3d* PyGeCurveCurveInt3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeCurveCurveInt3d*>(m_imp.get());
}
