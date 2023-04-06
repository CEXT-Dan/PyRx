#include "stdafx.h"
#include "PyDbCurve.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbCurveWrapper()
{
    static auto wrapper = class_<PyDbCurve, bases<PyDbEntity>>("DbCurve", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("isClosed", &PyDbCurve::isClosed)
        .def("isPeriodic", &PyDbCurve::isPeriodic)
        .def("getStartParam", &PyDbCurve::getStartParam)
        .def("getEndParam", &PyDbCurve::getEndParam)
        .def("getStartPoint", &PyDbCurve::getStartPoint)
        .def("getEndPoint", &PyDbCurve::getEndPoint)
        .def("getPointAtParam", &PyDbCurve::getPointAtParam)
        .def("getParamAtPoint", &PyDbCurve::getParamAtPoint)
        .def("getDistAtParam", &PyDbCurve::getDistAtParam)
        .def("getParamAtDist", &PyDbCurve::getParamAtDist)
        .def("getDistAtPoint", &PyDbCurve::getDistAtPoint)
        .def("getPointAtDist", &PyDbCurve::getPointAtDist)

        .def<AcGeVector3d(PyDbCurve::*)(double)const>("getFirstDeriv", &PyDbCurve::getFirstDeriv)
        .def<AcGeVector3d(PyDbCurve::*)(const AcGePoint3d&)const>("getFirstDeriv", &PyDbCurve::getFirstDeriv)

        .def<AcGeVector3d(PyDbCurve::*)(double)const>("getSecondDeriv", &PyDbCurve::getSecondDeriv)
        .def<AcGeVector3d(PyDbCurve::*)(const AcGePoint3d&)const>("getSecondDeriv", &PyDbCurve::getSecondDeriv)

        .def<AcGePoint3d(PyDbCurve::*)(const AcGePoint3d&, Adesk::Boolean)const>("getClosestPointTo", &PyDbCurve::getClosestPointTo)
        .def<AcGePoint3d(PyDbCurve::*)(const AcGePoint3d& givenPnt, const AcGeVector3d& direction, Adesk::Boolean extend)const>("getClosestPointTo", &PyDbCurve::getClosestPointTo)

        .def("getOffsetCurves", &PyDbCurve::getOffsetCurves)
        .def("getOffsetCurvesGivenPlaneNormal", &PyDbCurve::getOffsetCurvesGivenPlaneNormal)
        .def("getSplitCurves", &PyDbCurve::getSplitCurves)
        .def("getSplitCurvesAtParams", &PyDbCurve::getSplitCurvesAtParams)
        .def("getSplitCurvesAtPoints", &PyDbCurve::getSplitCurvesAtPoints)

        .def<Acad::ErrorStatus(PyDbCurve::*)(double)>("extend", &PyDbCurve::extend)
        .def<Acad::ErrorStatus(PyDbCurve::*)(Adesk::Boolean, const AcGePoint3d&)>("extend", &PyDbCurve::extend)

        .def("getArea", &PyDbCurve::getArea)
        .def("reverseCurve", &PyDbCurve::reverseCurve)
        .def("className", &PyDbCurve::className).staticmethod("className")
        ;
}

PyDbCurve::PyDbCurve(AcDbCurve* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbCurve::PyDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbCurve* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbCurve>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

Adesk::Boolean PyDbCurve::isClosed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isClosed();
}

Adesk::Boolean PyDbCurve::isPeriodic() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isPeriodic();
}

double PyDbCurve::getStartParam() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double param = 0;
    if (auto es = imp->getStartParam(param); es != eOk)
        throw PyAcadErrorStatus(es);
    return param;
}

double PyDbCurve::getEndParam() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double param = 0;
    if (auto es = imp->getEndParam(param); es != eOk)
        throw PyAcadErrorStatus(es);
    return param;
}

AcGePoint3d PyDbCurve::getStartPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d val;
    if (auto es = imp->getStartPoint(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

AcGePoint3d PyDbCurve::getEndPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d val;
    if (auto es = imp->getEndPoint(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

AcGePoint3d PyDbCurve::getPointAtParam(double val) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d p;
    if (auto es = imp->getPointAtParam(val, p); es != eOk)
        throw PyAcadErrorStatus(es);
    return p;
}

double PyDbCurve::getParamAtPoint(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double param = 0;
    if (auto es = imp->getParamAtPoint(pnt, param); es != eOk)
        throw PyAcadErrorStatus(es);
    return param;
}

double PyDbCurve::getDistAtParam(double param) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double dist = 0;
    if (auto es = imp->getDistAtParam(param, dist); es != eOk)
        throw PyAcadErrorStatus(es);
    return param;
}

double PyDbCurve::getParamAtDist(double dist) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double param = 0;
    if (auto es = imp->getParamAtDist(dist, param); es != eOk)
        throw PyAcadErrorStatus(es);
    return param;
}

double PyDbCurve::getDistAtPoint(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double dist = 0;
    if (auto es = imp->getDistAtPoint(pnt, dist); es != eOk)
        throw PyAcadErrorStatus(es);
    return dist;
}

AcGePoint3d PyDbCurve::getPointAtDist(double dist) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d p;
    if (auto es = imp->getPointAtDist(dist, p); es != eOk)
        throw PyAcadErrorStatus(es);
    return p;
}

AcGeVector3d PyDbCurve::getFirstDeriv(double param) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeVector3d p;
    if (auto es = imp->getFirstDeriv(param, p); es != eOk)
        throw PyAcadErrorStatus(es);
    return p;
}

AcGeVector3d PyDbCurve::getFirstDeriv(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeVector3d p;
    if (auto es = imp->getFirstDeriv(pnt, p); es != eOk)
        throw PyAcadErrorStatus(es);
    return p;
}

AcGeVector3d PyDbCurve::getSecondDeriv(double param) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeVector3d p;
    if (auto es = imp->getSecondDeriv(param, p); es != eOk)
        throw PyAcadErrorStatus(es);
    return p;
}

AcGeVector3d PyDbCurve::getSecondDeriv(const AcGePoint3d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeVector3d p;
    if (auto es = imp->getSecondDeriv(pnt, p); es != eOk)
        throw PyAcadErrorStatus(es);
    return p;
}

AcGePoint3d PyDbCurve::getClosestPointTo(const AcGePoint3d& givenPnt, Adesk::Boolean extend) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d p;
    if (auto es = imp->getClosestPointTo(givenPnt, p, extend); es != eOk)
        throw PyAcadErrorStatus(es);
    return p;
}

AcGePoint3d PyDbCurve::getClosestPointTo(const AcGePoint3d& givenPnt, const AcGeVector3d& direction, Adesk::Boolean extend) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGePoint3d p;
    if (auto es = imp->getClosestPointTo(givenPnt, direction, p, extend); es != eOk)
        throw PyAcadErrorStatus(es);
    return p;
}

boost::python::list PyDbCurve::getOffsetCurves(double offsetDist) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list curves;
    AcDbVoidPtrArray offsetCurves;

    if (auto es = imp->getOffsetCurves(offsetDist, offsetCurves); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto ptr : offsetCurves)
        curves.append(PyDbEntity(static_cast<AcDbEntity*>(ptr), false));
    return curves;
}

boost::python::list PyDbCurve::getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list curves;
    AcDbVoidPtrArray offsetCurves;
    if (auto es = imp->getOffsetCurvesGivenPlaneNormal(normal, offsetDist, offsetCurves); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto ptr : offsetCurves)
    {
        PyDbEntity ent(static_cast<AcDbEntity*>(ptr), true);
        curves.append(ent);
        ent.addRef();
    }
    return curves;
}

boost::python::list PyDbCurve::getSplitCurves(const boost::python::list& params) const
{
    try
    {
        if (len(params) == 0)
            throw PyAcadErrorStatus(eInvalidInput);
        extract<double> get_double(params[0]);
        if (get_double.check())
            return getSplitCurvesAtParams(params);
        extract<AcGePoint3d> get_point(params[0]);
        if (get_point.check())
            return getSplitCurvesAtPoints(params);
        throw PyAcadErrorStatus(eInvalidInput);
    }
    catch (...)
    {
        throw PyAcadErrorStatus(eInvalidInput);
    }
}

boost::python::list PyDbCurve::getSplitCurvesAtParams(const boost::python::list& params) const
{
    try
    {
        auto imp = impObj();
        if (imp == nullptr)
            throw PyNullObject();
        const auto doublesVector = py_list_to_std_vector<double>(params);
        AcGeDoubleArray doublesArray;
        for (const auto& item : doublesVector)
            doublesArray.append(item);

        boost::python::list curves;
        AcDbVoidPtrArray offsetCurves;
        if (auto es = imp->getSplitCurves(doublesArray, offsetCurves); es != eOk)
            throw PyAcadErrorStatus(es);
        for (auto ptr : offsetCurves)
        {
            PyDbEntity ent(static_cast<AcDbEntity*>(ptr), true);
            curves.append(ent);
            ent.addRef();
        }
        return curves;
    }
    catch (...)
    {
        throw PyAcadErrorStatus(eInvalidInput);
    }
}

boost::python::list PyDbCurve::getSplitCurvesAtPoints(const boost::python::list& params) const
{
    try
    {
        auto imp = impObj();
        if (imp == nullptr)
            throw PyNullObject();
        const auto pointsVector = py_list_to_std_vector<AcGePoint3d>(params);
        AcGePoint3dArray pointsArray;
        for (const auto& item : pointsVector)
            pointsArray.append(item);

        boost::python::list curves;
        AcDbVoidPtrArray offsetCurves;
        if (auto es = imp->getSplitCurves(pointsArray, offsetCurves); es != eOk)
            throw PyAcadErrorStatus(es);
        for (auto ptr : offsetCurves)
        {
            PyDbEntity ent(static_cast<AcDbEntity*>(ptr), true);
            curves.append(ent);
            ent.addRef();
        }
        return curves;
    }
    catch (...)
    {
        throw PyAcadErrorStatus(eInvalidInput);
    }
}

Acad::ErrorStatus PyDbCurve::extend(double newParam)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->extend(newParam);
}

Acad::ErrorStatus PyDbCurve::extend(Adesk::Boolean extendStart, const AcGePoint3d& toPoint)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->extend(extendStart, toPoint);
}

double PyDbCurve::getArea() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    double area = 0;
    if (auto es = imp->getArea(area); es != eOk)
        throw PyAcadErrorStatus(es);
    return area;
}

Acad::ErrorStatus PyDbCurve::reverseCurve()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->reverseCurve();
}

std::string PyDbCurve::className()
{
    return "AcDbCurve";
}

AcDbCurve* PyDbCurve::impObj() const
{
    return static_cast<AcDbCurve*>(m_pImp);
}
