#include "stdafx.h"
#include "PyDbCurve.h"
#include "PyDbObjectId.h"
#include "PyGeCurve3d.h"
#include "PyDbSpline.h"
#include "PyGePlane.h"

using namespace boost::python;

void makePyDbCurveWrapper()
{
    PyDocString DS("PyDb.Curve");
    class_<PyDbCurve, bases<PyDbEntity>>("Curve", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("isClosed", &PyDbCurve::isClosed, DS.ARGS())
        .def("isPeriodic", &PyDbCurve::isPeriodic, DS.ARGS())
        .def("getStartParam", &PyDbCurve::getStartParam, DS.ARGS())
        .def("getEndParam", &PyDbCurve::getEndParam, DS.ARGS())
        .def("getStartPoint", &PyDbCurve::getStartPoint, DS.ARGS())
        .def("getEndPoint", &PyDbCurve::getEndPoint, DS.ARGS())
        .def("getPointAtParam", &PyDbCurve::getPointAtParam, DS.ARGS({ "param: float" }))
        .def("getParamAtPoint", &PyDbCurve::getParamAtPoint, DS.ARGS({ "point3d: PyGe.Point3d" }))
        .def("getDistAtParam", &PyDbCurve::getDistAtParam, DS.ARGS({ "param: float" }))
        .def("getParamAtDist", &PyDbCurve::getParamAtDist, DS.ARGS({ "dist: float" }))
        .def("getDistAtPoint", &PyDbCurve::getDistAtPoint, DS.ARGS({ "point3d: PyGe.Point3d" }))
        .def("getPointAtDist", &PyDbCurve::getPointAtDist, DS.ARGS({ "dist: float" }))
        .def("getFirstDeriv", &PyDbCurve::getFirstDeriv1)
        .def("getFirstDeriv", &PyDbCurve::getFirstDeriv2, DS.ARGS({ "param: float|PyGe.Point3d" }))
        .def("getSecondDeriv", &PyDbCurve::getSecondDeriv1)
        .def("getSecondDeriv", &PyDbCurve::getSecondDeriv2, DS.ARGS({ "param: float|PyGe.Point3d" }))
        .def("getClosestPointTo", &PyDbCurve::getClosestPointTo1)
        .def("getClosestPointTo", &PyDbCurve::getClosestPointTo2)
        .def("getClosestPointTo", &PyDbCurve::getClosestPointTo3, DS.ARGS({ "point3d: PyGe.Point3d","direction: PyGe.Vector3d=None","extend: bool=False" }))
        .def("getOffsetCurves", &PyDbCurve::getOffsetCurves, DS.ARGS({ "dist: float" }))
        .def("getOffsetCurvesGivenPlaneNormal", &PyDbCurve::getOffsetCurvesGivenPlaneNormal, DS.ARGS({ "normal: PyGe.Vector3d", "dist: float" }))
        .def("getSplitCurves", &PyDbCurve::getSplitCurves, DS.ARGS({ "paramsOrPoints: list" }))
        .def("getSplitCurvesAtParam", &PyDbCurve::getSplitCurvesAtParam, DS.ARGS({ "param: float" }))
        .def("getSplitCurvesAtParams", &PyDbCurve::getSplitCurvesAtParams, DS.ARGS({ "params: list" }))
        .def("getSplitCurvesAtPoint", &PyDbCurve::getSplitCurvesAtPoint, DS.ARGS({ "point: PyGe.Point3d" }))
        .def("getSplitCurvesAtPoints", &PyDbCurve::getSplitCurvesAtPoints, DS.ARGS({ "points: list" }))
        .def("getOrthoProjectedCurve", &PyDbCurve::getOrthoProjectedCurve, DS.ARGS({ "plane: PyGe.Plane" }))
        .def("getProjectedCurve", &PyDbCurve::getProjectedCurve, DS.ARGS({ "plane: PyGe.Plane","projDir: PyGe.Vector3d" }))
        .def("getSpline", &PyDbCurve::getSpline, DS.ARGS())
        .def("extend", &PyDbCurve::extend1)
        .def("extend", &PyDbCurve::extend2)
        .def("getArea", &PyDbCurve::getArea, DS.ARGS())
        .def("reverseCurve", &PyDbCurve::reverseCurve, DS.ARGS())
        .def("getAcGeCurve", &PyDbCurve::getAcGeCurve1)
        .def("getAcGeCurve", &PyDbCurve::getAcGeCurve2, DS.ARGS({ "tol: PyGe.Tol = 'default'" }))
        .def("setFromAcGeCurve", &PyDbCurve::setFromAcGeCurve1)
        .def("setFromAcGeCurve", &PyDbCurve::setFromAcGeCurve2)
        .def("setFromAcGeCurve", &PyDbCurve::setFromAcGeCurve3, DS.ARGS({ "curve: PyGe.Curve3d","normal: PyGe.Vector3d = kZAxis","tol: PyGe.Tol = 'default'" }))
        .def("createFromAcGeCurve", &PyDbCurve::createFromAcGeCurve1)
        .def("createFromAcGeCurve", &PyDbCurve::createFromAcGeCurve2)
        .def("createFromAcGeCurve", &PyDbCurve::createFromAcGeCurve3, DS.SARGS({ "curve: PyGe.Curve3d","normal: PyGe.Vector3d = kZAxis","tol: PyGe.Tol = 'default'" })).staticmethod("createFromAcGeCurve")
        .def("className", &PyDbCurve::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbCurve::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbCurve::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbCurve::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbCurve::PyDbCurve(AcDbCurve* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbCurve::PyDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbCurve>(id, mode), false)
{
}

PyDbCurve::PyDbCurve(const PyDbObjectId& id)
    : PyDbEntity(openAcDbObject<AcDbCurve>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbCurve::PyDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbCurve>(id, mode, erased), false)
{
}

Adesk::Boolean PyDbCurve::isClosed() const
{
    return impObj()->isClosed();
}

Adesk::Boolean PyDbCurve::isPeriodic() const
{
    return impObj()->isPeriodic();
}

double PyDbCurve::getStartParam() const
{
    double param = 0;
    PyThrowBadEs(impObj()->getStartParam(param));
    return param;
}

double PyDbCurve::getEndParam() const
{
    double param = 0;
    PyThrowBadEs(impObj()->getEndParam(param));
    return param;
}

AcGePoint3d PyDbCurve::getStartPoint() const
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->getStartPoint(val));
    return val;
}

AcGePoint3d PyDbCurve::getEndPoint() const
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->getEndPoint(val));
    return val;
}

AcGePoint3d PyDbCurve::getPointAtParam(double val) const
{
    AcGePoint3d p;
    PyThrowBadEs(impObj()->getPointAtParam(val, p));
    return p;
}

double PyDbCurve::getParamAtPoint(const AcGePoint3d& pnt) const
{
    double param = 0;
    PyThrowBadEs(impObj()->getParamAtPoint(pnt, param));
    return param;
}

double PyDbCurve::getDistAtParam(double param) const
{
    double dist = 0;
    PyThrowBadEs(impObj()->getDistAtParam(param, dist));
    return dist;
}

double PyDbCurve::getParamAtDist(double dist) const
{
    double param = 0;
    PyThrowBadEs(impObj()->getParamAtDist(dist, param));
    return param;
}

double PyDbCurve::getDistAtPoint(const AcGePoint3d& pnt) const
{
    double dist = 0;
    PyThrowBadEs(impObj()->getDistAtPoint(pnt, dist));
    return dist;
}

AcGePoint3d PyDbCurve::getPointAtDist(double dist) const
{
    AcGePoint3d p;
    PyThrowBadEs(impObj()->getPointAtDist(dist, p));
    return p;
}

AcGeVector3d PyDbCurve::getFirstDeriv1(double param) const
{
    AcGeVector3d p;
    PyThrowBadEs(impObj()->getFirstDeriv(param, p));
    return p;
}

AcGeVector3d PyDbCurve::getFirstDeriv2(const AcGePoint3d& pnt) const
{
    AcGeVector3d p;
    PyThrowBadEs(impObj()->getFirstDeriv(pnt, p));
    return p;
}

AcGeVector3d PyDbCurve::getSecondDeriv1(double param) const
{
    AcGeVector3d p;
    PyThrowBadEs(impObj()->getSecondDeriv(param, p));
    return p;
}

AcGeVector3d PyDbCurve::getSecondDeriv2(const AcGePoint3d& pnt) const
{
    AcGeVector3d p;
    PyThrowBadEs(impObj()->getSecondDeriv(pnt, p));
    return p;
}

AcGePoint3d PyDbCurve::getClosestPointTo1(const AcGePoint3d& givenPnt) const
{
    AcGePoint3d p;
    PyThrowBadEs(impObj()->getClosestPointTo(givenPnt, p));
    return p;
}

AcGePoint3d PyDbCurve::getClosestPointTo2(const AcGePoint3d& givenPnt, Adesk::Boolean extend) const
{
    AcGePoint3d p;
    PyThrowBadEs(impObj()->getClosestPointTo(givenPnt, p, extend));
    return p;
}

AcGePoint3d PyDbCurve::getClosestPointTo3(const AcGePoint3d& givenPnt, const AcGeVector3d& direction, Adesk::Boolean extend) const
{
    AcGePoint3d p;
    PyThrowBadEs(impObj()->getClosestPointTo(givenPnt, direction, p, extend));
    return p;
}

boost::python::list PyDbCurve::getOffsetCurves(double offsetDist) const
{
    PyAutoLockGIL lock;
    boost::python::list curves;
    AcDbVoidPtrArray offsetCurves;
    PyThrowBadEs(impObj()->getOffsetCurves(offsetDist, offsetCurves));
    for (auto ptr : offsetCurves)
        curves.append(PyDbCurve(static_cast<AcDbCurve*>(ptr), true));
    return curves;
}

boost::python::list PyDbCurve::getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist) const
{
    PyAutoLockGIL lock;
    boost::python::list curves;
    AcDbVoidPtrArray offsetCurves;
    PyThrowBadEs(impObj()->getOffsetCurvesGivenPlaneNormal(normal, offsetDist, offsetCurves));
    for (auto ptr : offsetCurves)
        curves.append(PyDbCurve(static_cast<AcDbCurve*>(ptr), true));
    return curves;
}

boost::python::list PyDbCurve::getSplitCurves(const boost::python::list& params) const
{
    PyAutoLockGIL lock;
    if (boost::python::len(params) == 0)
        throw PyAcadErrorStatus(eInvalidInput);
    extract<double> get_double(params[0]);
    if (get_double.check())
        return getSplitCurvesAtParams(params);
    extract<AcGePoint3d> get_point(params[0]);
    if (get_point.check())
        return getSplitCurvesAtPoints(params);
    throw PyAcadErrorStatus(eInvalidInput);
}

boost::python::list PyDbCurve::getSplitCurvesAtParam(double param) const
{
    PyAutoLockGIL lock;
    AcGeDoubleArray doublesArray;
    doublesArray.append(param);
    boost::python::list curves;
    AcDbVoidPtrArray offsetCurves;
    PyThrowBadEs(impObj()->getSplitCurves(doublesArray, offsetCurves));
    for (auto ptr : offsetCurves)
        curves.append(PyDbCurve(static_cast<AcDbCurve*>(ptr), true));
    return curves;
}

boost::python::list PyDbCurve::getSplitCurvesAtParams(const boost::python::list& params) const
{
    PyAutoLockGIL lock;
    const auto doublesVector = py_list_to_std_vector<double>(params);
    AcGeDoubleArray doublesArray;
    for (const auto& item : doublesVector)
        doublesArray.append(item);
    boost::python::list curves;
    AcDbVoidPtrArray offsetCurves;
    PyThrowBadEs(impObj()->getSplitCurves(doublesArray, offsetCurves));
    for (auto ptr : offsetCurves)
        curves.append(PyDbCurve(static_cast<AcDbCurve*>(ptr), true));
    return curves;
}

boost::python::list PyDbCurve::getSplitCurvesAtPoint(const AcGePoint3d& givenPnt) const
{
    PyAutoLockGIL lock;
    AcGePoint3dArray pointsArray;
    pointsArray.append(givenPnt);
    boost::python::list curves;
    AcDbVoidPtrArray offsetCurves;
    PyThrowBadEs(impObj()->getSplitCurves(pointsArray, offsetCurves));
    for (auto ptr : offsetCurves)
        curves.append(PyDbCurve(static_cast<AcDbCurve*>(ptr), true));
    return curves;
}

boost::python::list PyDbCurve::getSplitCurvesAtPoints(const boost::python::list& params) const
{
    PyAutoLockGIL lock;
    const auto pointsVector = py_list_to_std_vector<AcGePoint3d>(params);
    AcGePoint3dArray pointsArray;
    for (const auto& item : pointsVector)
        pointsArray.append(item);

    boost::python::list curves;
    AcDbVoidPtrArray offsetCurves;
    PyThrowBadEs(impObj()->getSplitCurves(pointsArray, offsetCurves));
    for (auto ptr : offsetCurves)
        curves.append(PyDbCurve(static_cast<AcDbCurve*>(ptr), true));
    return curves;
}

PyDbCurve PyDbCurve::getOrthoProjectedCurve(const PyGePlane& plane)
{
    AcDbCurve* pCurve = nullptr;
    PyThrowBadEs(impObj()->getOrthoProjectedCurve(*plane.impObj(), pCurve));
    return PyDbCurve(pCurve, true);
}

PyDbCurve PyDbCurve::getProjectedCurve(const PyGePlane& plane, const AcGeVector3d& projDir)
{
    AcDbCurve* pCurve = nullptr;
    PyThrowBadEs(impObj()->getProjectedCurve(*plane.impObj(), projDir,pCurve));
    return PyDbCurve(pCurve, true);
}

PyDbSpline PyDbCurve::getSpline()
{
    AcDbSpline* _spline = nullptr;
    PyThrowBadEs(impObj()->getSpline(_spline));
    return PyDbSpline(_spline, true);
}

void PyDbCurve::extend1(double newParam)
{
    return PyThrowBadEs(impObj()->extend(newParam));
}

void PyDbCurve::extend2(Adesk::Boolean extendStart, const AcGePoint3d& toPoint)
{
    return PyThrowBadEs(impObj()->extend(extendStart, toPoint));
}

double PyDbCurve::getArea() const
{
    double area = 0;
    PyThrowBadEs(impObj()->getArea(area));
    return area;
}

void PyDbCurve::reverseCurve()
{
    return PyThrowBadEs(impObj()->reverseCurve());
}

PyGeCurve3d PyDbCurve::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeCurve3d(pGeCurve);
}

PyGeCurve3d PyDbCurve::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeCurve3d(pGeCurve);
}

void PyDbCurve::setFromAcGeCurve1(const PyGeCurve3d& geCurve)
{
    PyThrowBadEs(impObj()->setFromAcGeCurve(*geCurve.impObj()));
}

void PyDbCurve::setFromAcGeCurve2(const PyGeCurve3d& geCurve, AcGeVector3d& normal)
{
    PyThrowBadEs(impObj()->setFromAcGeCurve(*geCurve.impObj(), std::addressof(normal)));
}

void PyDbCurve::setFromAcGeCurve3(const PyGeCurve3d& geCurve, AcGeVector3d& normal, const AcGeTol& tol)
{
    PyThrowBadEs(impObj()->setFromAcGeCurve(*geCurve.impObj(), std::addressof(normal), tol));
}

PyDbCurve PyDbCurve::createFromAcGeCurve1(const PyGeCurve3d& geCurve)
{
#ifdef _ZRXTARGET 
    throw PyNotimplementedByHost();
#else
    AcDbCurve* pDbCurve = nullptr;
    PyThrowBadEs(AcDbCurve::createFromAcGeCurve(*geCurve.impObj(), pDbCurve));
    return PyDbCurve(pDbCurve, true);
#endif
}

PyDbCurve PyDbCurve::createFromAcGeCurve2(const PyGeCurve3d& geCurve, AcGeVector3d& normal)
{
#ifdef _ZRXTARGET 
    throw PyNotimplementedByHost();
#else
    AcDbCurve* pDbCurve = nullptr;
    PyThrowBadEs(AcDbCurve::createFromAcGeCurve(*geCurve.impObj(), pDbCurve, std::addressof(normal)));
    return PyDbCurve(pDbCurve, true);
#endif
}

PyDbCurve PyDbCurve::createFromAcGeCurve3(const PyGeCurve3d& geCurve, AcGeVector3d& normal, const AcGeTol& tol)
{
#ifdef _ZRXTARGET 
    throw PyNotimplementedByHost();
#else
    AcDbCurve* pDbCurve = nullptr;
    PyThrowBadEs(AcDbCurve::createFromAcGeCurve(*geCurve.impObj(), pDbCurve, std::addressof(normal), tol));
    return PyDbCurve(pDbCurve, true);
#endif
}

std::string PyDbCurve::className()
{
    return "AcDbCurve";
}

PyRxClass PyDbCurve::desc()
{
    return PyRxClass(AcDbCurve::desc(), false);
}

PyDbCurve PyDbCurve::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbCurve::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbCurve(static_cast<AcDbCurve*>(src.impObj()->clone()), true);
}

PyDbCurve PyDbCurve::cast(const PyRxObject& src)
{
    PyDbCurve dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbCurve* PyDbCurve::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbCurve*>(m_pyImp.get());
}
