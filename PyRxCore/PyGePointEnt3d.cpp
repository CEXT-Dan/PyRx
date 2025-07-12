#include "stdafx.h"
#include "PyGePointEnt3d.h"
#include "PyGeCurve3d.h"
#include "PyGeSurface.h"

using namespace boost::python;

//-------------------------------------------------------------------------------------------------------
//PyGePointEnt3d
void makePyGePointEnt3dWrapper()
{
    PyDocString DS("PointEnt3d");
    class_<PyGePointEnt3d, bases<PyGeEntity3d>>("PointEnt3d", boost::python::no_init)
        .def("point3d", &PyGePointEnt3d::point3d, DS.ARGS())
        .def("cast", &PyGePointEnt3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGePointEnt3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGePointEnt3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGePointEnt3d::PyGePointEnt3d(AcGeEntity3d* src)
    : PyGeEntity3d(src)
{
}

AcGePoint3d PyGePointEnt3d::point3d() const
{
    return impObj()->point3d();
}

PyGePointEnt3d PyGePointEnt3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGePointEnt3d, AcGePointEnt3d>(src);
}

PyGePointEnt3d PyGePointEnt3d::copycast(const PyGeEntity3d& src)
{
    return PyGePointEnt3d(static_cast<AcGePointEnt3d*>(src.impObj()->copy()));
}

std::string PyGePointEnt3d::className()
{
    return "AcGePointEnt3d";
}

AcGePointEnt3d* PyGePointEnt3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGePointEnt3d*>(m_imp.get());
}

//-------------------------------------------------------------------------------------------------------
//PyGePointOnCurve3d
void makePyGePointOnCurve3dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- curve: PyGe.Curve3d\n"
        "- curve: PyGe.Curve3d, param: float\n";

    constexpr const std::string_view pointOverloads = "Overloads:\n"
        "- None: Any\n"
        "- param: float\n"
        "- curve: PyGe.Curve3d, param: float\n";

    constexpr const std::string_view derivOverloads = "Overloads:\n"
        "- order: int\n"
        "- order: int, param: float\n"
        "- order: int, curve: PyGe.Curve3d, param: float\n";

    PyDocString DS("PointOnCurve3d");
    class_<PyGePointOnCurve3d, bases<PyGePointEnt3d>>("PointOnCurve3d")
        .def(init<>())
        .def(init<const PyGeCurve3d&>())
        .def(init<const PyGeCurve3d&, double>(DS.CTOR(ctor, 12622)))
        .def("curve", &PyGePointOnCurve3d::curve, DS.ARGS())
        .def("parameter", &PyGePointOnCurve3d::parameter, DS.ARGS())
        .def("point", &PyGePointOnCurve3d::point1)
        .def("point", &PyGePointOnCurve3d::point2)
        .def("point", &PyGePointOnCurve3d::point3, DS.OVRL(pointOverloads))
        .def("deriv", &PyGePointOnCurve3d::deriv1)
        .def("deriv", &PyGePointOnCurve3d::deriv2)
        .def("deriv", &PyGePointOnCurve3d::deriv3, DS.OVRL(derivOverloads))
        .def("isSingular", &PyGePointOnCurve3d::isSingular, DS.ARGS())
        .def("curvature", &PyGePointOnCurve3d::curvature1)
        .def("curvature", &PyGePointOnCurve3d::curvature2, DS.ARGS({ "param: float = ..." }))
        .def("setCurve", &PyGePointOnCurve3d::setCurve, DS.ARGS({ "curve: PyGe.Curve3d" }))
        .def("setParameter", &PyGePointOnCurve3d::setParameter, DS.ARGS({ "param: float" }))
        .def("cast", &PyGePointOnCurve3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGePointOnCurve3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGePointOnCurve3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGePointOnCurve3d::PyGePointOnCurve3d()
    : PyGePointEnt3d(new AcGePointOnCurve3d())
{
}

PyGePointOnCurve3d::PyGePointOnCurve3d(const PyGeCurve3d& crv)
    : PyGePointEnt3d(new AcGePointOnCurve3d(*crv.impObj()))
{
}

PyGePointOnCurve3d::PyGePointOnCurve3d(const PyGeCurve3d& crv, double param)
    : PyGePointEnt3d(new AcGePointOnCurve3d(*crv.impObj(), param))
{
}

PyGePointOnCurve3d::PyGePointOnCurve3d(const AcGePointOnCurve3d& src)
    : PyGePointEnt3d(new AcGePointOnCurve3d(src))
{
}

PyGePointOnCurve3d::PyGePointOnCurve3d(AcGeEntity3d* src)
    : PyGePointEnt3d(src)
{
}

PyGeCurve3d PyGePointOnCurve3d::curve() const
{
    return PyGeCurve3d(impObj()->curve());
}

double PyGePointOnCurve3d::parameter() const
{
    return impObj()->parameter();
}

AcGePoint3d PyGePointOnCurve3d::point1() const
{
    return impObj()->point();
}

AcGePoint3d PyGePointOnCurve3d::point2(double param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->point(param);
#endif
}

AcGePoint3d PyGePointOnCurve3d::point3(const PyGeCurve3d& crv, double param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->point(*crv.impObj(), param);
#endif
}

AcGeVector3d PyGePointOnCurve3d::deriv1(int order) const
{
    return impObj()->deriv(order);
}

AcGeVector3d PyGePointOnCurve3d::deriv2(int order, double param) const
{
    return impObj()->deriv(order, param);
}

AcGeVector3d PyGePointOnCurve3d::deriv3(int order, const PyGeCurve3d& crv, double param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->deriv(order, *crv.impObj(), param);
#endif
}

Adesk::Boolean PyGePointOnCurve3d::isSingular() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->isSingular();
#endif
}

double PyGePointOnCurve3d::curvature1() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    double res = 0;
    if (!impObj()->curvature(res))
        throw PyErrorStatusException(Acad::eNotApplicable);
    return res;
#endif
}

double PyGePointOnCurve3d::curvature2(double param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    double res = 0;
    if (!impObj()->curvature(param, res))
        throw PyErrorStatusException(Acad::eNotApplicable);
    return res;
#endif
}

void PyGePointOnCurve3d::setCurve(const PyGeCurve3d& crv) const
{
    impObj()->setCurve(*crv.impObj());
}

void PyGePointOnCurve3d::setParameter(double param) const
{
    impObj()->setParameter(param);
}

PyGePointOnCurve3d PyGePointOnCurve3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGePointOnCurve3d, AcGePointOnCurve3d>(src);
}

PyGePointOnCurve3d PyGePointOnCurve3d::copycast(const PyGeEntity3d& src)
{
    return PyGePointOnCurve3d(static_cast<AcGePointOnCurve3d*>(src.impObj()->copy()));
}

std::string PyGePointOnCurve3d::className()
{
    return "AcGePointOnCurve3d";
}

AcGePointOnCurve3d* PyGePointOnCurve3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGePointOnCurve3d*>(m_imp.get());
}

//-------------------------------------------------------------------------------------------------------
//PyGePointOnSurface
void makePyGePointOnSurfaceWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- surface: PyGe.Surface\n"
        "- surface: PyGe.Surface, pnt: PyGe.Point2d\n\n";

    constexpr const std::string_view pointOverloads = "Overloads:\n"
        "- None: Any\n"
        "- param: PyGe.Point2d\n"
        "- surface: PyGe.Surface, param: PyGe.Point2d\n";

    constexpr const std::string_view normalOverloads = "Overloads:\n"
        "- None: Any\n"
        "- param: PyGe.Point2d\n"
        "- surface: PyGe.Surface, param: PyGe.Point2d\n";

    constexpr const std::string_view uderivOverloads = "Overloads:\n"
        "- order: int\n"
        "- order: int, param: PyGe.Point2d\n"
        "- order: int, surface: PyGe.Surface, param: PyGe.Point2d\n";

    constexpr const std::string_view vderivOverloads = "Overloads:\n"
        "- order: int\n"
        "- order: int, param: PyGe.Point2d\n"
        "- order: int, surface: PyGe.Surface, param: PyGe.Point2d\n";

    constexpr const std::string_view mixedPartialOverloads = "Overloads:\n"
        "- None: Any\n"
        "- param: PyGe.Point2d\n"
        "- surface: PyGe.Surface, param: PyGe.Point2d\n";

    constexpr const std::string_view tangentVectorOverloads = "Overloads:\n"
        "- vec: PyGe.Vector2d\n"
        "- vec: PyGe.Vector2d, param: PyGe.Vector2d\n"
        "- vec: PyGe.Vector2d, surface: PyGe.Surface, param: PyGe.Vector2d\n";

    constexpr const std::string_view inverseTangentVectorOverloads = "Overloads:\n"
        "- vec: PyGe.Vector2d\n"
        "- vec: PyGe.Vector2d, param: PyGe.Vector2d\n"
        "- vec: PyGe.Vector2d, surface: PyGe.Surface, param: PyGe.Vector2d\n";


    PyDocString DS("PointOnSurface");
    class_<PyGePointOnSurface, bases<PyGePointEnt3d>>("PointOnSurface")
        .def(init<>())
        .def(init<const PyGeSurface&>())
        .def(init<const PyGeSurface&, const AcGePoint2d&>(DS.CTOR(ctor, 12633)))
        .def("surface", &PyGePointOnSurface::surface, DS.ARGS())
        .def("parameter", &PyGePointOnSurface::parameter, DS.ARGS())
        .def("point", &PyGePointOnSurface::point1)
        .def("point", &PyGePointOnSurface::point2)
        .def("point", &PyGePointOnSurface::point3, DS.OVRL(pointOverloads))
        .def("normal", &PyGePointOnSurface::normal1)
        .def("normal", &PyGePointOnSurface::normal2)
        .def("normal", &PyGePointOnSurface::normal3, DS.OVRL(normalOverloads))
        .def("uDeriv", &PyGePointOnSurface::uDeriv1)
        .def("uDeriv", &PyGePointOnSurface::uDeriv2)
        .def("uDeriv", &PyGePointOnSurface::uDeriv3, DS.OVRL(uderivOverloads))
        .def("vDeriv", &PyGePointOnSurface::vDeriv1)
        .def("vDeriv", &PyGePointOnSurface::vDeriv2)
        .def("vDeriv", &PyGePointOnSurface::vDeriv3, DS.OVRL(vderivOverloads))
        .def("mixedPartial", &PyGePointOnSurface::mixedPartial1)
        .def("mixedPartial", &PyGePointOnSurface::mixedPartial2)
        .def("mixedPartial", &PyGePointOnSurface::mixedPartial3, DS.OVRL(mixedPartialOverloads))
        .def("tangentVector", &PyGePointOnSurface::tangentVector1)
        .def("tangentVector", &PyGePointOnSurface::tangentVector2)
        .def("tangentVector", &PyGePointOnSurface::tangentVector3, DS.OVRL(tangentVectorOverloads))
        .def("inverseTangentVector", &PyGePointOnSurface::inverseTangentVector1)
        .def("inverseTangentVector", &PyGePointOnSurface::inverseTangentVector2)
        .def("inverseTangentVector", &PyGePointOnSurface::inverseTangentVector3, DS.OVRL(inverseTangentVectorOverloads))
        .def("setSurface", &PyGePointOnSurface::setSurface, DS.ARGS({ "val: PyGe.Surface" }))
        .def("setParameter", &PyGePointOnSurface::setParameter, DS.ARGS({ "param: PyGe.Point2d" }))
        .def("cast", &PyGePointOnSurface::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGePointOnSurface::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGePointOnSurface::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGePointOnSurface::PyGePointOnSurface()
    : PyGePointEnt3d(new AcGePointOnSurface())
{
}

PyGePointOnSurface::PyGePointOnSurface(const PyGeSurface& surf)
    : PyGePointEnt3d(new AcGePointOnSurface(*surf.impObj()))
{
}

PyGePointOnSurface::PyGePointOnSurface(const PyGeSurface& surf, const AcGePoint2d& param)
    : PyGePointEnt3d(new AcGePointOnSurface(*surf.impObj(), param))
{
}

PyGePointOnSurface::PyGePointOnSurface(AcGeEntity3d* src)
    : PyGePointEnt3d(src)
{
}

PyGePointOnSurface::PyGePointOnSurface(const AcGePointOnSurface& src)
    : PyGePointEnt3d(new AcGePointOnSurface(src))
{
}

PyGeSurface PyGePointOnSurface::surface() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyGeSurface(impObj()->surface());
#endif
}

AcGePoint2d PyGePointOnSurface::parameter() const
{
    return impObj()->parameter();
}

AcGePoint3d PyGePointOnSurface::point1() const
{
    return impObj()->point();
}

AcGePoint3d PyGePointOnSurface::point2(const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->point(param);
#endif
}

AcGePoint3d PyGePointOnSurface::point3(const PyGeSurface& surf, const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->point(*surf.impObj(), param);
#endif
}

AcGeVector3d PyGePointOnSurface::normal1() const
{
    return impObj()->normal();
}

AcGeVector3d PyGePointOnSurface::normal2(const AcGePoint2d& param) const
{
    return impObj()->normal(param);
}

AcGeVector3d PyGePointOnSurface::normal3(const PyGeSurface& surf, const AcGePoint2d& param) const
{
    return impObj()->normal(*surf.impObj(), param);
}

AcGeVector3d PyGePointOnSurface::uDeriv1(int order) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->uDeriv(order);
#endif

}

AcGeVector3d PyGePointOnSurface::uDeriv2(int order, const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->uDeriv(order, param);
#endif
}

AcGeVector3d PyGePointOnSurface::uDeriv3(int order, const PyGeSurface& surf, const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->uDeriv(order, *surf.impObj(), param);
#endif
}

AcGeVector3d PyGePointOnSurface::vDeriv1(int order) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->vDeriv(order);
#endif
}

AcGeVector3d PyGePointOnSurface::vDeriv2(int order, const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->vDeriv(order, param);
#endif
}

AcGeVector3d PyGePointOnSurface::vDeriv3(int order, const PyGeSurface& surf, const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->vDeriv(order, *surf.impObj(), param);
#endif
}

AcGeVector3d PyGePointOnSurface::mixedPartial1() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->mixedPartial();
#endif
}

AcGeVector3d PyGePointOnSurface::mixedPartial2(const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->mixedPartial(param);
#endif
}

AcGeVector3d PyGePointOnSurface::mixedPartial3(const PyGeSurface& surf, const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->mixedPartial(*surf.impObj(), param);
#endif
}

AcGeVector3d PyGePointOnSurface::tangentVector1(const AcGeVector2d& vec) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->tangentVector(vec);
#endif
}

AcGeVector3d PyGePointOnSurface::tangentVector2(const AcGeVector2d& vec, const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->tangentVector(vec, param);
#endif
}

AcGeVector3d PyGePointOnSurface::tangentVector3(const AcGeVector2d& vec, const PyGeSurface& vecSurf, const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->tangentVector(vec, *vecSurf.impObj(), param);
#endif
}

AcGeVector2d PyGePointOnSurface::inverseTangentVector1(const AcGeVector3d& vec) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->inverseTangentVector(vec);
#endif
}

AcGeVector2d PyGePointOnSurface::inverseTangentVector2(const AcGeVector3d& vec, const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->inverseTangentVector(vec, param);
#endif
}

AcGeVector2d PyGePointOnSurface::inverseTangentVector3(const AcGeVector3d& vec, const PyGeSurface& surf, const AcGePoint2d& param) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->inverseTangentVector(vec, *surf.impObj(), param);
#endif
}

void PyGePointOnSurface::setSurface(const PyGeSurface& surf) const
{
    impObj()->setSurface(*surf.impObj());
}

void PyGePointOnSurface::setParameter(const AcGePoint2d& param) const
{
    impObj()->setParameter(param);
}

PyGePointOnSurface PyGePointOnSurface::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGePointOnSurface, AcGePointOnSurface>(src);
}

PyGePointOnSurface PyGePointOnSurface::copycast(const PyGeEntity3d& src)
{
    return PyGePointOnSurface(static_cast<AcGePointOnSurface*>(src.impObj()->copy()));
}

std::string PyGePointOnSurface::className()
{
    return "AcGePointOnSurface";
}

AcGePointOnSurface* PyGePointOnSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGePointOnSurface*>(m_imp.get());
}

//-------------------------------------------------------------------------------------------------------
//PyGePosition3d
void makePyGePosition3dWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- pnt: PyGe.Point3d\n"
        "- x: float, y: float, z: float\n";

    constexpr const std::string_view setOverloads = "Overloads:\n"
        "- pnt: PyGe.Point3d\n"
        "- x: float, y: float, z: float\n";

    PyDocString DS("Position3d");
    class_<PyGePosition3d, bases<PyGePointEnt3d>>("Position3d")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<double, double, double>(DS.CTOR(ctor, 12663)))
        .def("set", &PyGePosition3d::set1)
        .def("set", &PyGePosition3d::set2, DS.OVRL(setOverloads))
        .def("cast", &PyGePosition3d::cast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("cast")
        .def("copycast", &PyGePosition3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGePosition3d::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGePosition3d::PyGePosition3d()
    : PyGePointEnt3d(new AcGePosition3d())
{
}

PyGePosition3d::PyGePosition3d(AcGeEntity3d* src)
    : PyGePointEnt3d(src)
{
}

PyGePosition3d::PyGePosition3d(const AcGePoint3d& pnt)
    : PyGePointEnt3d(new AcGePosition3d(pnt))
{
}

PyGePosition3d::PyGePosition3d(double x, double y, double z)
    : PyGePointEnt3d(new AcGePosition3d(x, y, x))
{
}

void PyGePosition3d::set1(const AcGePoint3d& pnt) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(pnt);
#endif
}

void PyGePosition3d::set2(double x, double y, double z) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->set(x, y, x);
#endif
}

PyGePosition3d PyGePosition3d::cast(const PyGeEntity3d& src)
{
    return PyGeEntity3dCast<PyGePosition3d, AcGePosition3d>(src);
}

PyGePosition3d PyGePosition3d::copycast(const PyGeEntity3d& src)
{
    return PyGePosition3d(static_cast<AcGePosition3d*>(src.impObj()->copy()));
}

std::string PyGePosition3d::className()
{
    return "AcGePosition3d";
}

AcGePosition3d* PyGePosition3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGePosition3d*>(m_imp.get());
}
