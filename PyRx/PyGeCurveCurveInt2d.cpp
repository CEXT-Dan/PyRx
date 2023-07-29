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
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
        .def(init<const AcGeCurve2d&, const AcGeCurve2d&>())
        .def(init<const AcGeCurve2d&, const AcGeCurve2d&, const AcGeTol&>())
        .def(init<const AcGeCurve2d&, const AcGeCurve2d&, const PyGeInterval&, const PyGeInterval&>())
        .def(init<const AcGeCurve2d&, const AcGeCurve2d&, const PyGeInterval&, const PyGeInterval&, const AcGeTol&>())
#endif
        .def("className", &PyGeEntity2d::className).staticmethod("className")
        ;
}

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d()
    : PyGeEntity2d(new AcGeCurveCurveInt2d())
{
}
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(curve1, curve2))
{
}
#endif // !BRXAPP
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2, const AcGeTol& tol)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(curve1, curve2, tol))
{
}
#endif // !BRXAPP
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2, const PyGeInterval& range1, const PyGeInterval& range2)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(curve1, curve2, range1.imp, range2.imp))
{
}
#endif // !BRXAPP
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurve2d& curve1, const AcGeCurve2d& curve2, const PyGeInterval& range1, const PyGeInterval& range2, const AcGeTol& tol)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(curve1, curve2, range1.imp, range2.imp, tol))
{
}
#endif // !BRXAPP
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(const AcGeCurveCurveInt2d& src)
    : PyGeEntity2d(new AcGeCurveCurveInt2d(src))
{
}
#endif // !BRXAPP

PyGeCurveCurveInt2d::PyGeCurveCurveInt2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

std::string PyGeCurveCurveInt2d::className()
{
    return "AcGeCurveCurveInt2d";
}

AcGeCurveCurveInt2d* PyGeCurveCurveInt2d::impObj() const
{
    return static_cast<AcGeCurveCurveInt2d*>(m_imp.get());
}
