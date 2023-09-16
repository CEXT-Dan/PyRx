#include "stdafx.h"
#include "PyGeCurveCurveInt2d.h"
#include "PyGeInterval.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeCurveCurveInt2d wrapper
void makePyGeCurveCurveInt2dWrapper()
{
    class_<PyGeCurveCurveInt2d, bases<PyGeEntity2d>>("CurveCurveInt2d")
        .def(init<>())
        .def(init<const AcGeCurve2d&, const AcGeCurve2d&>())
        .def(init<const AcGeCurve2d&, const AcGeCurve2d&, const AcGeTol&>())
        .def(init<const AcGeCurve2d&, const AcGeCurve2d&, const PyGeInterval&, const PyGeInterval&>())
        .def(init<const AcGeCurve2d&, const AcGeCurve2d&, const PyGeInterval&, const PyGeInterval&, const AcGeTol&>())
        .def("copycast", &PyGeCurveCurveInt2d::copycast).staticmethod("copycast")
        .def("className", &PyGeCurveCurveInt2d::className).staticmethod("className")
        ;
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d()
    : PyGeEntity2d(new AcGeCurveCurveInt2d())
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(curve1, curve2))
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2, const AcGeTol& tol)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(curve1, curve2, tol))
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2, const PyGeInterval& range1, const PyGeInterval& range2)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(curve1, curve2, range1.imp, range2.imp))
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2, const PyGeInterval& range1, const PyGeInterval& range2, const AcGeTol& tol)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(curve1, curve2, range1.imp, range2.imp, tol))
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurveCurveInt2d& src)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(src))
{
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeCurveCurveInt2d PyGeCurveCurveInt2d::copycast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kCurveCurveInt2d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeCurveCurveInt2d(src.impObj()->copy());
}

std::string PyGeCurveCurveInt2d::className()
{
    return "AcGeCurveCurveInt2d";
}

AcGeCurveCurveInt2d* PyGeCurveCurveInt2d::impObj() const
{
    return static_cast<AcGeCurveCurveInt2d*>(m_imp.get());
}
