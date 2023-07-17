#include "stdafx.h"
#include "PyGeLinearEnt2d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//AcGeLinearEnt2d wrapper
void makePyGeLinearEnt2dWrapper()
{
    class_<PyGeLinearEnt2d, bases<PyGeCurve2d>>("LinearEnt2d", boost::python::no_init)
        .def("intersectWith", &PyGeLinearEnt2d::intersectWith1)
        .def("intersectWith", &PyGeLinearEnt2d::intersectWith2)
        .def("overlap", &PyGeLinearEnt2d::overlap1)
        .def("overlap", &PyGeLinearEnt2d::overlap2)
        .def("isParallelTo", &PyGeLinearEnt2d::isParallelTo1)
        .def("isParallelTo", &PyGeLinearEnt2d::isParallelTo2)
        .def("isPerpendicularTo", &PyGeLinearEnt2d::isPerpendicularTo1)
        .def("isPerpendicularTo", &PyGeLinearEnt2d::isPerpendicularTo2)
        .def("isColinearTo", &PyGeLinearEnt2d::isColinearTo1)
        .def("isColinearTo", &PyGeLinearEnt2d::isColinearTo2)
        .def("getPerpLine", &PyGeLinearEnt2d::getPerpLine)
        .def("getLine", &PyGeLinearEnt2d::getLine)
        .def("pointOnLine", &PyGeLinearEnt2d::pointOnLine)
        .def("direction", &PyGeLinearEnt2d::direction)
        .def("className", &PyGeLinearEnt2d::className).staticmethod("className")
        ;
}

PyGeLinearEnt2d::PyGeLinearEnt2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

boost::python::tuple PyGeLinearEnt2d::intersectWith1(const PyGeLinearEnt2d& line)
{
    PyAutoLockGIL lock;
    AcGePoint2d p1;
    bool flag = impObj()->intersectWith(*line.impObj(), p1);
    return make_tuple(flag, p1);
}

boost::python::tuple PyGeLinearEnt2d::intersectWith2(const PyGeLinearEnt2d& line, const AcGeTol& tol)
{
    PyAutoLockGIL lock;
    AcGePoint2d p1;
    bool flag = impObj()->intersectWith(*line.impObj(), p1, tol);
    return make_tuple(flag, p1);
}

boost::python::tuple PyGeLinearEnt2d::overlap1(const PyGeLinearEnt2d& line) const
{
    PyAutoLockGIL lock;
    AcGeLinearEnt2d* poverlap = nullptr;
    bool flag = impObj()->overlap(*line.impObj(), poverlap);
    return make_tuple(flag, PyGeLinearEnt2d(poverlap));
}

boost::python::tuple PyGeLinearEnt2d::overlap2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    PyAutoLockGIL lock;
    AcGeLinearEnt2d* poverlap = nullptr;
    bool flag = impObj()->overlap(*line.impObj(), poverlap, tol);
    return make_tuple(flag, PyGeLinearEnt2d(poverlap));
}

Adesk::Boolean PyGeLinearEnt2d::isParallelTo1(const PyGeLinearEnt2d& line) const
{
    return impObj()->isParallelTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt2d::isParallelTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    return impObj()->isParallelTo(*line.impObj(), tol);
}

Adesk::Boolean PyGeLinearEnt2d::isPerpendicularTo1(const PyGeLinearEnt2d& line) const
{
    return impObj()->isPerpendicularTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt2d::isPerpendicularTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    return impObj()->isPerpendicularTo(*line.impObj(), tol);
}

Adesk::Boolean PyGeLinearEnt2d::isColinearTo1(const PyGeLinearEnt2d& line) const
{
    return impObj()->isColinearTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt2d::isColinearTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    return impObj()->isColinearTo(*line.impObj(), tol);
}

PyGeLine2d PyGeLinearEnt2d::getPerpLine(const AcGePoint2d& pnt) const
{
    AcGeLine2d perpLine;
    impObj()->getPerpLine(pnt, perpLine);
    return PyGeLine2d(perpLine);
}

PyGeLine2d PyGeLinearEnt2d::getLine() const
{
    AcGeLine2d perpLine;
    impObj()->getLine(perpLine);
    return PyGeLine2d(perpLine);
}

AcGePoint2d PyGeLinearEnt2d::pointOnLine() const
{
    return impObj()->pointOnLine();
}

AcGeVector2d PyGeLinearEnt2d::direction() const
{
    return impObj()->direction();
}

std::string PyGeLinearEnt2d::className()
{
    return "AcGeLinearEnt2d";
}

AcGeLinearEnt2d* PyGeLinearEnt2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeLinearEnt2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeLine2d  wrapper
void makePyGeLine2dWrapper()
{
    class_<PyGeLine2d, bases<PyGeLinearEnt2d>>("Line2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .add_static_property("kXAxis", PyGeLine2d::kXAxis)
        .add_static_property("kYAxis", PyGeLine2d::kYAxis)
        .def("set", &PyGeLine2d::set1, return_self<>())
        .def("set", &PyGeLine2d::set2, return_self<>())
        .def("className", &PyGeLine2d::className).staticmethod("className")
        ;
}

PyGeLine2d::PyGeLine2d()
    : PyGeLinearEnt2d(new AcGeLine2d())
{
}

PyGeLine2d::PyGeLine2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

PyGeLine2d::PyGeLine2d(const AcGeLine2d& pEnt)
    : PyGeLinearEnt2d(new AcGeLine2d(pEnt))
{
}

PyGeLine2d::PyGeLine2d(const AcGePoint2d& pnt, const AcGeVector2d& vec)
    : PyGeLinearEnt2d(new AcGeLine2d(pnt, vec))
{
}

PyGeLine2d::PyGeLine2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2)
    : PyGeLinearEnt2d(new AcGeLine2d(pnt1, pnt2))
{
}

PyGeLine2d PyGeLine2d::kXAxis()
{
    return PyGeLine2d(AcGeLine2d::kXAxis);
}

PyGeLine2d PyGeLine2d::kYAxis()
{
    return PyGeLine2d(AcGeLine2d::kYAxis);
}

PyGeLine2d& PyGeLine2d::set1(const AcGePoint2d& pnt, const AcGeVector2d& vec)
{
    impObj()->set(pnt, vec);
    return *this;
}

PyGeLine2d& PyGeLine2d::set2(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2)
{
    impObj()->set(pnt1, pnt2);
    return *this;
}

std::string PyGeLine2d::className()
{
    return "AcGeLine2d";
}

AcGeLine2d* PyGeLine2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeLine2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeLine2d  wrapper
void makePyGeLineSeg2dWrapper()
{
    class_<PyGeLineSeg2d, bases<PyGeLinearEnt2d>>("LineSeg2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def("set", &PyGeLineSeg2d::set1, return_self<>())
        .def("set", &PyGeLineSeg2d::set2, return_self<>())
        .def("set", &PyGeLineSeg2d::set3, return_self<>())
        .def("set", &PyGeLineSeg2d::set4, return_self<>())
        .def("getBisector", &PyGeLineSeg2d::getBisector)
        .def("baryComb", &PyGeLineSeg2d::baryComb)
        .def("startPoint", &PyGeLineSeg2d::startPoint)
        .def("midPoint", &PyGeLineSeg2d::midPoint)
        .def("endPoint", &PyGeLineSeg2d::endPoint)
        .def("length", &PyGeLineSeg2d::length1)
        .def("length", &PyGeLineSeg2d::length2)
        .def("length", &PyGeLineSeg2d::length3)
        .def("className", &PyGeLineSeg2d::className).staticmethod("className")
        ;
}

PyGeLineSeg2d::PyGeLineSeg2d()
    : PyGeLinearEnt2d(new AcGeLineSeg2d())
{
}

PyGeLineSeg2d::PyGeLineSeg2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

PyGeLineSeg2d::PyGeLineSeg2d(const AcGeLineSeg2d& src)
    : PyGeLinearEnt2d(new AcGeLineSeg2d(src))
{
}

PyGeLineSeg2d::PyGeLineSeg2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2)
    : PyGeLinearEnt2d(new AcGeLineSeg2d(pnt1, pnt2))
{
}

PyGeLineSeg2d::PyGeLineSeg2d(const AcGePoint2d& pnt, const AcGeVector2d& vec)
    : PyGeLinearEnt2d(new AcGeLineSeg2d(pnt, vec))
{
}

PyGeLineSeg2d& PyGeLineSeg2d::set1(const AcGePoint2d& pnt, const AcGeVector2d& vec)
{
    impObj()->set(pnt, vec);
    return *this;
}

PyGeLineSeg2d& PyGeLineSeg2d::set2(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2)
{
    impObj()->set(pnt1, pnt2);
    return *this;
}

PyGeLineSeg2d& PyGeLineSeg2d::set3(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    double param1, param2;
    Adesk::Boolean success;
    impObj()->set(*curve1.impObj(), *curve2.impObj(), param1, param2, success);
    if (!success)
        throw PyAcadErrorStatus(eInvalidInput);
    return *this;
#endif
}

PyGeLineSeg2d& PyGeLineSeg2d::set4(const PyGeCurve2d& curve, const AcGePoint2d& point)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    double param1;
    Adesk::Boolean success;
    impObj()->set(*curve.impObj(), point, param1, success);
    if (!success)
        throw PyAcadErrorStatus(eInvalidInput);
    return *this;
#endif
}

PyGeLine2d PyGeLineSeg2d::getBisector() const
{
    AcGeLine2d line;
    impObj()->getBisector(line);
    return PyGeLine2d(line);
}

AcGePoint2d PyGeLineSeg2d::baryComb(double blendCoeff) const
{
    return impObj()->baryComb(blendCoeff);
}

AcGePoint2d PyGeLineSeg2d::startPoint() const
{
    return impObj()->startPoint();
}

AcGePoint2d PyGeLineSeg2d::midPoint() const
{
    return impObj()->midPoint();
}

AcGePoint2d PyGeLineSeg2d::endPoint() const
{
    return impObj()->endPoint();
}

double PyGeLineSeg2d::length1() const
{
    return impObj()->length();
}

double PyGeLineSeg2d::length2(double fromParam, double toParam) const
{
    return impObj()->length(fromParam, toParam);
}

double PyGeLineSeg2d::length3(double fromParam, double toParam, double tol) const
{
    return impObj()->length(fromParam, toParam, tol);
}

std::string PyGeLineSeg2d::className()
{
    return "AcGeLineSeg2d";
}

AcGeLineSeg2d* PyGeLineSeg2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeLineSeg2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeRay2d  wrapper
void makePyGeRay2dWrapper()
{
    class_<PyGeRay2d, bases<PyGeLinearEnt2d>>("Ray2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def("set", &PyGeRay2d::set1, return_self<>())
        .def("set", &PyGeRay2d::set2, return_self<>())
        .def("className", &PyGeRay2d::className).staticmethod("className")
        ;
}

PyGeRay2d::PyGeRay2d()
    : PyGeLinearEnt2d(new AcGeRay2d())
{
}

PyGeRay2d::PyGeRay2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

PyGeRay2d::PyGeRay2d(const AcGeRay2d& line)
    : PyGeLinearEnt2d(new AcGeRay2d(line))
{
}

PyGeRay2d::PyGeRay2d(const AcGePoint2d& pnt, const AcGeVector2d& vec)
    : PyGeLinearEnt2d(new AcGeRay2d(pnt, vec))
{
}

PyGeRay2d::PyGeRay2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2)
    : PyGeLinearEnt2d(new AcGeRay2d(pnt1, pnt2))
{
}

PyGeRay2d& PyGeRay2d::set1(const AcGePoint2d& pnt, const AcGeVector2d& vec)
{
    impObj()->set(pnt, vec);
    return *this;
}

PyGeRay2d& PyGeRay2d::set2(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2)
{
    impObj()->set(pnt1, pnt2);
    return *this;
}

std::string PyGeRay2d::className()
{
    return "AcGeRay2d";
}

AcGeRay2d* PyGeRay2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcGeRay2d*>(m_imp.get());
}
