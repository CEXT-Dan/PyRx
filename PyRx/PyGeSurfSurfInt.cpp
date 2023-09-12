#include "stdafx.h"
#include "PyGeSurfSurfInt.h"
#include "PyGeSurface.h"
#include "PyGeCurve2d.h"
#include "PyGeCurve3d.h"

using namespace boost::python;

void makePyGeSurfSurfIntWrapper()
{
    class_<PyGeSurfSurfInt, bases<PyGeEntity3d>>("SurfSurfInt")
        .def(init<>())
        .def(init<const PyGeSurface&, const PyGeSurface&>())
        .def(init<const PyGeSurface&, const PyGeSurface&, const AcGeTol&>())
        .def("surface1", &PyGeSurfSurfInt::surface1)
        .def("surface2", &PyGeSurfSurfInt::surface2)
        .def("tolerance", &PyGeSurfSurfInt::tolerance)
        .def("numResults", &PyGeSurfSurfInt::numResults)
        .def("intCurve", &PyGeSurfSurfInt::intCurve)
        .def("intParamCurve", &PyGeSurfSurfInt::intParamCurve)
        .def("intPoint", &PyGeSurfSurfInt::intPoint)
        .def("getIntPointParams", &PyGeSurfSurfInt::getIntPointParams)
        .def("getIntConfigs", &PyGeSurfSurfInt::getIntConfigs)
        .def("getDimension", &PyGeSurfSurfInt::getDimension)
        .def("getType", &PyGeSurfSurfInt::getType)
        .def("set", &PyGeSurfSurfInt::set1)
        .def("set", &PyGeSurfSurfInt::set2)
        .def("className", &PyGeSurfSurfInt::className).staticmethod("className")
        ;
}

PyGeSurfSurfInt::PyGeSurfSurfInt()
    : PyGeEntity3d(new AcGeSurfSurfInt())
{
}

PyGeSurfSurfInt::PyGeSurfSurfInt(AcGeSurfSurfInt* pEnt, bool autoDelete /*= false*/)
    : PyGeEntity3d(pEnt, autoDelete)
{
}

PyGeSurfSurfInt::PyGeSurfSurfInt(const PyGeSurface& srf1, const PyGeSurface& srf2)
    : PyGeEntity3d(new AcGeSurfSurfInt(*srf1.impObj(), *srf2.impObj()))
{
}

PyGeSurfSurfInt::PyGeSurfSurfInt(const PyGeSurface& srf1, const PyGeSurface& srf2, const AcGeTol& tol)
    : PyGeEntity3d(new AcGeSurfSurfInt(*srf1.impObj(), *srf2.impObj(), tol))
{
}

PyGeSurface PyGeSurfSurfInt::surface1() const
{
    return PyGeSurface(impObj()->surface1());
}

PyGeSurface PyGeSurfSurfInt::surface2() const
{
    return PyGeSurface(impObj()->surface2());
}

AcGeTol PyGeSurfSurfInt::tolerance() const
{
    return impObj()->tolerance();
}

int PyGeSurfSurfInt::numResults()
{
    AcGe::AcGeIntersectError err = AcGe::kXXOk;
    int result = impObj()->numResults(err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return result;
}

PyGeCurve3d PyGeSurfSurfInt::intCurve(int intNum, Adesk::Boolean isExternal) const
{
    AcGe::AcGeIntersectError err = AcGe::kXXOk;
    PyGeCurve3d result(impObj()->intCurve(intNum, isExternal, err));
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return result;
}

PyGeCurve2d PyGeSurfSurfInt::intParamCurve(int num, Adesk::Boolean isExternal, Adesk::Boolean isFirst) const
{
    AcGe::AcGeIntersectError err = AcGe::kXXOk;
    PyGeCurve2d result(impObj()->intParamCurve(num, isExternal, isFirst, err));
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return result;
}

AcGePoint3d PyGeSurfSurfInt::intPoint(int intNum) const
{
    AcGe::AcGeIntersectError err = AcGe::kXXOk;
    AcGePoint3d result(impObj()->intPoint(intNum, err));
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return result;
}

boost::python::tuple PyGeSurfSurfInt::getIntPointParams(int intNum) const
{
    PyAutoLockGIL lock;
    AcGePoint2d param1;
    AcGePoint2d param2;
    AcGe::AcGeIntersectError err = AcGe::kXXOk;
    impObj()->getIntPointParams(intNum, param1, param2, err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return boost::python::make_tuple(param1, param2);
}

boost::python::tuple PyGeSurfSurfInt::getIntConfigs(int intNum) const
{
    PyAutoLockGIL lock;
    AcGe::ssiConfig surf1Left = AcGe::ssiConfig::kSSIUnknown;
    AcGe::ssiConfig surf1Right = AcGe::ssiConfig::kSSIUnknown;
    AcGe::ssiConfig surf2Left = AcGe::ssiConfig::kSSIUnknown;
    AcGe::ssiConfig surf2Right = AcGe::ssiConfig::kSSIUnknown;
    AcGe::ssiType intType = AcGe::ssiType::kSSITransverse;
    int dim = 0;
    AcGe::AcGeIntersectError err = AcGe::kXXOk;
    impObj()->getIntConfigs(intNum, surf1Left, surf1Right, surf2Left, surf2Right, intType, dim, err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return boost::python::make_tuple((int)surf1Left, (int)surf1Right, (int)surf2Left, (int)surf2Right, dim);
}


int PyGeSurfSurfInt::getDimension(int intNum) const
{
    AcGe::AcGeIntersectError err = AcGe::kXXOk;
    int result = impObj()->getDimension(intNum, err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return result;
}

int PyGeSurfSurfInt::getType(int intNum) const
{
    AcGe::AcGeIntersectError err = AcGe::kXXOk;
    int result = impObj()->getType(intNum, err);
    if (err != AcGe::kXXOk)
        throw PyAcadErrorStatus(static_cast<Acad::ErrorStatus>(err));
    return result;
}

void PyGeSurfSurfInt::set1(const PyGeSurface& srf1, const PyGeSurface& srf2)
{
    impObj()->set(*srf1.impObj(), *srf2.impObj());
}

void PyGeSurfSurfInt::set2(const PyGeSurface& srf1, const PyGeSurface& srf2, const AcGeTol& tol)
{
    impObj()->set(*srf1.impObj(), *srf2.impObj(), tol);
}

std::string PyGeSurfSurfInt::className()
{
    return "AcGeSurfSurfInt";
}

AcGeSurfSurfInt* PyGeSurfSurfInt::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return static_cast<AcGeSurfSurfInt*>(m_imp.get());
}
