#include "stdafx.h"
#include "PyAcGe.h"
#include "PyGeEntity3d.h"
#include "PyGePointEnt3d.h"
#include "PyAcGeSurface.h"
#include "PyGePlanarEnt.h"
#include "PyGePlane.h"
#include "PyGeInterval.h"
#include "PyGeEntity2d.h"
#include "PyGeBoundBlock2d.h"
#include "PyGeCurve2d.h"
#include "PyGeCurveCurveInt2d.h"
#include "PyGePointEnt2d.h"
#include "PyGeClipBoundary2d.h"
#include "PyGeLinearEnt2d.h"
#include "PyGeSplineEnt2d.h"
#include "PyGeBoundBlock3d.h"
#include "PyGeLinearEnt3d.h"
#include "PyGeSplineEnt3d.h"
#include "PyGeCurveCurveInt3d.h"
#include "PyGeCurveSurfInt.h"
#include "PyGeSurfSurfInt.h"
#include "PyGeKnotVector.h"

#include <boost/functional/hash.hpp>

using namespace boost::python;

//---------------------------------------------------------------------------------------------------------------
//AcGeScale3d
std::string AcGeScale2dToString(const AcGeScale2d& s)
{
    return std::format("({:.14f},{:.14f})", s.sx, s.sy);
}

std::string AcGeScale2dToStringRepr(const AcGeScale2d& s)
{
    return std::format("<{}.Scale2d({:.14f},{:.14f})>", PyGeNamespace, s.sx, s.sy);
}

void makeAcGeScale2dWrapper()
{
    class_<AcGeScale2d>("Scale2d")
        .def(init<>())
        .def(init<double>())
        .def(init<double, double>())
        .def(init<const AcGeScale2d&>())
#ifndef BRXAPP
        .def("preMultBy", &AcGeScale2d::preMultBy, return_self<>())
        .def("postMultBy", &AcGeScale2d::postMultBy, return_self<>())
        .def<AcGeScale2d& (AcGeScale2d::*)(const AcGeScale2d&, double)>("setToProduct", &AcGeScale2d::setToProduct, return_self<>())
        .def<AcGeScale2d& (AcGeScale2d::*)(const AcGeScale2d&, const AcGeScale2d&)>("setToProduct", &AcGeScale2d::setToProduct, return_self<>())
#endif
        .def_readwrite("sx", &AcGeScale2d::sx)
        .def_readwrite("sy", &AcGeScale2d::sy)
        .def("__eq__", &AcGeScale2d::operator==)
        .def("__ne__", &AcGeScale2d::operator!=)
        .def<AcGeScale2d(AcGeScale2d::*)(double)const>("__mul__", &AcGeScale2d::operator*)
        .def<AcGeScale2d& (AcGeScale2d::*)(double)>("__imul__", &AcGeScale2d::operator*=, return_self<>())
        .def<AcGeScale2d(AcGeScale2d::*)(const AcGeScale2d&)const>("__mul__", &AcGeScale2d::operator*)
        .def<AcGeScale2d& (AcGeScale2d::*)(const AcGeScale2d&)>("__imul__", &AcGeScale2d::operator*=, return_self<>())
        .def("toString", &AcGeScale2dToString)
        .def("__str__", &AcGeScale2dToString)
        .def("__repr__", &AcGeScale2dToStringRepr)
        ;
}

//---------------------------------------------------------------------------------------------------------------
//AcGeTol
static AcGeTol getTol()
{
    return AcGeContext::gTol;
}

void makeAcGeTolWrapper()
{
    class_<AcGeTol>("Tol")
        .def(init<>())
        .def("equalPoint", &AcGeTol::equalPoint)
        .def("equalVector", &AcGeTol::equalVector)
        .def("setEqualPoint", &AcGeTol::setEqualPoint)
        .def("setEqualVector", &AcGeTol::setEqualVector)
        .add_static_property("current", &getTol)
        ;
}

//---------------------------------------------------------------------------------------------------------------
//AcGePoint2d
boost::python::tuple AcGePoint2dToTuple(const AcGePoint2d& p)
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple(p.x, p.y);
}

boost::python::list AcGePoint2dToList(const AcGePoint2d& p)
{
    PyAutoLockGIL lock;
    boost::python::list l;
    l.append(p.x);
    l.append(p.y);
    return l;
}

std::string AcGePoint2dToString(const AcGePoint2d& p)
{
    return std::format("({:.14f},{:.14f})", p.x, p.y);
}

std::string AcGePoint2dToStringRepr(const AcGePoint2d& s)
{
    return std::format("<{}.Point2d({:.14f},{:.14f})>", PyGeNamespace, s.x, s.y);
}

static AcGePoint2d AcGePoint2dkOrigin()
{
    return AcGePoint2d::kOrigin;
}

std::size_t AcGePoint2dHash(const AcGePoint2d& p)
{
    std::size_t seed = 0;
    boost::hash_combine(seed, p.x);
    boost::hash_combine(seed, p.y);
    return seed;
}

double AcGePoint2dGetItem(const AcGePoint2d& p, int idx)
{
    switch (idx)
    {
        case 0:
            return p.x;
        case 1:
            return p.y;
        default:
            throw PyAcadErrorStatus(eOutOfRange);
    }
}

void AcGePoint2dSetItem(AcGePoint2d& p, int idx, double val)
{
    switch (idx)
    {
        case 0:
            p.x = val;
            break;
        case 1:
            p.y = val;
            break;
        default:
            throw PyAcadErrorStatus(eOutOfRange);
    }
}

void makeAcGePoint2dWrapper()
{
    class_<AcGePoint2d>("Point2d")
        .def(init<>())
        .def(init<const AcGePoint2d&>())
        .def(init<double, double>())
        .def("setToProduct", &AcGePoint2d::setToProduct, return_self<>())
        .def("transformBy", &AcGePoint2d::transformBy, return_self<>())
        .def("rotateBy", &AcGePoint2d::rotateBy, arg("AcGePoint2d") = AcGePoint2dkOrigin(), return_self<>())
        .def("mirror", &AcGePoint2d::mirror, return_self<>())
        .def("scaleBy", &AcGePoint2d::scaleBy, arg("AcGePoint2d") = AcGePoint2dkOrigin(), return_self<>())
        .def("setToSum", &AcGePoint2d::setToSum, return_self<>())
        .def("set", &AcGePoint2d::set, return_self<>())
        .def("asVector", &AcGePoint2d::asVector)
        .def("distanceTo", &AcGePoint2d::distanceTo)
        .def("isEqualTo", &AcGePoint2d::isEqualTo, arg("AcGeTol") = getTol())
        .def_readwrite("x", &AcGePoint2d::x)
        .def_readwrite("y", &AcGePoint2d::y)
        .add_static_property("kOrigin", &AcGePoint2dkOrigin)
        .def("__eq__", &AcGePoint2d::operator==)
        .def("__ne__", &AcGePoint2d::operator!=)
        .def<AcGePoint2d(AcGePoint2d::*)(double)const>("__mul__", &AcGePoint2d::operator*)
        .def<AcGePoint2d& (AcGePoint2d::*)(double)>("__imul__", &AcGePoint2d::operator*=, return_self<>())
        .def<AcGePoint2d(AcGePoint2d::*)(double)const>("__truediv__", &AcGePoint2d::operator/)
        .def<AcGePoint2d& (AcGePoint2d::*)(double)>("__itruediv__", &AcGePoint2d::operator/=, return_self<>())
        .def<AcGePoint2d(AcGePoint2d::*)(const AcGeVector2d&)const>("__add__", &AcGePoint2d::operator+)
        .def<AcGePoint2d& (AcGePoint2d::*)(const AcGeVector2d&)>("__iadd__", &AcGePoint2d::operator+=, return_self<>())
        .def<AcGePoint2d(AcGePoint2d::*)(const AcGeVector2d&)const>("__sub__", &AcGePoint2d::operator-)
        .def<AcGePoint2d& (AcGePoint2d::*)(const AcGeVector2d&)>("__isub__", &AcGePoint2d::operator-=, return_self<>())
        .def<AcGeVector2d(AcGePoint2d::*)(const AcGePoint2d&)const>("__sub__", &AcGePoint2d::operator-)
        .def("toString", &AcGePoint2dToString)
        .def("toTuple", &AcGePoint2dToTuple)
        .def("toList", &AcGePoint2dToList)
        .def("__str__", &AcGePoint2dToString)
        .def("__repr__", &AcGePoint2dToStringRepr)
        .def("__hash__", &AcGePoint2dHash)
        .def("__getitem__", &AcGePoint2dGetItem)
        .def("__setitem__", &AcGePoint2dSetItem)
        ;
}

//---------------------------------------------------------------------------------------------------------------
//AcGeVector2d
std::string AcGeVector2ToString(const AcGeVector2d& p)
{
    return std::format("({:.14f},{:.14f})", p.x, p.y);
}

std::string AcGeVector2dToStringRepr(const AcGePoint2d& s)
{
    return std::format("<{}.Vector2d({:.14f},{:.14f})>", PyGeNamespace, s.x, s.y);
}

static AcGeVector2d AcGeVector2dkIdentity()
{
    return AcGeVector2d::kIdentity;
}

static AcGeVector2d AcGeVector2dkXAxis()
{
    return AcGeVector2d::kXAxis;
}

static AcGeVector2d AcGeVector2dkYAxis()
{
    return AcGeVector2d::kYAxis;
}

static AcGeVector2d rmul_double_AcGeVector2d(const AcGeVector2d& vec, double scl)
{
    return scl * vec;
}

static AcGeVector2d rmul_AcGeMatrix2d_AcGeVector2d(const AcGeVector2d& vec, const AcGeMatrix2d& mat)
{
    return mat * vec;
}

double AcGeVector2dGetItem(const AcGeVector2d& p, int idx)
{
    switch (idx)
    {
        case 0:
            return p.x;
        case 1:
            return p.y;
        default:
            throw PyAcadErrorStatus(eOutOfRange);
    }
}

void AcGeVector2dSetItem(AcGeVector2d& p, int idx, double val)
{
    switch (idx)
    {
        case 0:
            p.x = val;
            break;
        case 1:
            p.y = val;
            break;
        default:
            throw PyAcadErrorStatus(eOutOfRange);
    }
}

void makeAcGeVector2dWrapper()
{
    class_<AcGeVector2d>("Vector2d")
        .def(init<>())
        .def(init<const AcGeVector2d&>())
        .def(init<double, double>())
        .def_readwrite("x", &AcGeVector2d::x)
        .def_readwrite("y", &AcGeVector2d::y)
        .add_static_property("kIdentity", &AcGeVector2dkIdentity)
        .add_static_property("kXAxis", &AcGeVector2dkXAxis)
        .add_static_property("kYAxis", &AcGeVector2dkYAxis)
        .def<AcGeVector2d& (AcGeVector2d::*)(const AcGeVector2d&, double)>("setToProduct", &AcGeVector2d::setToProduct, return_self<>())
        .def<AcGeVector2d& (AcGeVector2d::*)(const AcGeMatrix2d&, const AcGeVector2d&)>("setToProduct", &AcGeVector2d::setToProduct, return_self<>())
        .def("transformBy", &AcGeVector2d::transformBy, return_self<>())
        .def("rotateBy", &AcGeVector2d::rotateBy, return_self<>())
        .def("mirror", &AcGeVector2d::mirror, return_self<>())
        .def("setToSum", &AcGeVector2d::setToSum, return_self<>())
        .def("negate", &AcGeVector2d::negate, return_self<>())
        .def("angle", &AcGeVector2d::angle)
        .def("angleTo", &AcGeVector2d::angleTo)
        .def("normal", &AcGeVector2d::normal, arg("AcGeTol") = getTol())
        .def<AcGeVector2d& (AcGeVector2d::*)(const AcGeTol&)>("normalize", &AcGeVector2d::normalize, arg("AcGeTol") = getTol(), return_self<>())
        .def("length", &AcGeVector2d::length)
        .def("lengthSqrd", &AcGeVector2d::lengthSqrd)
        .def("isUnitLength", &AcGeVector2d::isUnitLength, arg("AcGeTol") = getTol())
        .def("isZeroLength", &AcGeVector2d::isZeroLength, arg("AcGeTol") = getTol())
        .def<Adesk::Boolean(AcGeVector2d::*)(const AcGeVector2d&, const AcGeTol&)const>("isParallelTo", &AcGeVector2d::isParallelTo, arg("AcGeTol") = getTol())
        .def<Adesk::Boolean(AcGeVector2d::*)(const AcGeVector2d&, const AcGeTol&)const>("isCodirectionalTo", &AcGeVector2d::isCodirectionalTo, arg("AcGeTol") = getTol())
        .def<Adesk::Boolean(AcGeVector2d::*)(const AcGeVector2d&, const AcGeTol&)const>("isPerpendicularTo", &AcGeVector2d::isPerpendicularTo, arg("AcGeTol") = getTol())
        .def("dotProduct", &AcGeVector2d::dotProduct)
        .def("isEqualTo", &AcGeVector2d::isEqualTo, arg("AcGeTol") = getTol())
        .def("set", &AcGeVector2d::set, return_self<>())
        .def("__eq__", &AcGeVector2d::operator==)
        .def("__ne__", &AcGeVector2d::operator!=)
        .def<AcGeVector2d(AcGeVector2d::*)(double) const>("__mul__", &AcGeVector2d::operator*)
        .def<AcGeVector2d& (AcGeVector2d::*)(double)>("__imul__", &AcGeVector2d::operator*=, return_self<>())
        .def("__rmul__", &rmul_double_AcGeVector2d)
        .def("__rmul__", &rmul_AcGeMatrix2d_AcGeVector2d)
        .def<AcGeVector2d(AcGeVector2d::*)(double)const>("__truediv__", &AcGeVector2d::operator/)
        .def<AcGeVector2d& (AcGeVector2d::*)(double)>("__itruediv__", &AcGeVector2d::operator/=, return_self<>())
        .def<AcGeVector2d(AcGeVector2d::*)(const AcGeVector2d&)const>("__add__", &AcGeVector2d::operator+)
        .def<AcGeVector2d& (AcGeVector2d::*)(const AcGeVector2d&)>("__iadd__", &AcGeVector2d::operator+=, return_self<>())
        .def<AcGeVector2d(AcGeVector2d::*)()const>("__sub__", &AcGeVector2d::operator-)
        .def<AcGeVector2d(AcGeVector2d::*)(const AcGeVector2d&)const>("__sub__", &AcGeVector2d::operator-)
        .def<AcGeVector2d& (AcGeVector2d::*)(const AcGeVector2d&)>("__isub__", &AcGeVector2d::operator-=, return_self<>())
        .def("toString", &AcGeVector2ToString)
        .def("__str__", &AcGeVector2ToString)
        .def("__repr__", &AcGeVector2dToStringRepr)
        .def("__getitem__", &AcGeVector2dGetItem)
        .def("__setitem__", &AcGeVector2dSetItem)
        ;
}

//---------------------------------------------------------------------------------------------------------------
//AcGeMatrix2d
static AcGeMatrix2d AcGeMatrix2dkIdentity()
{
    return AcGeMatrix2d::kIdentity;
}

std::string AcGeMatrix2dToString(const AcGeMatrix2d& x)
{
    return  std::format("(({0},{1},{2}),({3},{4},{5}),({6},{7},{8}))",
        x.entry[0][0], x.entry[0][1], x.entry[0][2],
        x.entry[1][0], x.entry[1][1], x.entry[1][2],
        x.entry[2][0], x.entry[2][1], x.entry[2][2]);
}

std::string AcGeMatrix2dToStringRepr(const AcGeMatrix2d& x)
{
    return std::format("<{0}.Matrix2d(({1},{2},{3}),({4},{5},{6}),({7},{8},{9}))>",
        PyGeNamespace,
        x.entry[0][0], x.entry[0][1], x.entry[0][2],
        x.entry[1][0], x.entry[1][1], x.entry[1][2],
        x.entry[2][0], x.entry[2][1], x.entry[2][2]);
}

static AcGeMatrix2d AcGeMatrix2dtranslation(const AcGeVector2d& vec)
{
    return AcGeMatrix2d::translation(vec);
}

static AcGeMatrix2d AcGeMatrix2drotation(double angle, const AcGePoint2d& center)
{
    return AcGeMatrix2d::rotation(angle, center);
}

static AcGeMatrix2d AcGeMatrix2scaling(double scaleAll, const AcGePoint2d& center)
{
    return AcGeMatrix2d::scaling(scaleAll, center);
}

static AcGeMatrix2d AcGeMatrix2mirroring1(const AcGePoint2d& pnt)
{
    return AcGeMatrix2d::mirroring(pnt);
}

static AcGeMatrix2d AcGeMatrix2mirroring2(const AcGeLine2d& line)
{
    return AcGeMatrix2d::mirroring(line);
}

static AcGeMatrix2d AcGeMatrix2alignCoordSys
(const AcGePoint2d& fromOrigin,
    const AcGeVector2d& fromE0,
    const AcGeVector2d& fromE1,
    const AcGePoint2d& toOrigin,
    const AcGeVector2d& toE0,
    const AcGeVector2d& toE1)
{
    return AcGeMatrix2d::alignCoordSys(fromOrigin, fromE0, fromE1, toOrigin, toE0, toE1);
}

static void makeAcGeMatrix2dWrapper()
{
    class_<AcGeMatrix2d>("Matrix2d")
        .add_static_property("kIdentity", &AcGeMatrix2dkIdentity)
        .def("setToIdentity", &AcGeMatrix2d::setToIdentity, return_self<>())
        .def("preMultBy", &AcGeMatrix2d::preMultBy, return_self<>())
        .def("postMultBy", &AcGeMatrix2d::postMultBy, return_self<>())
        .def("setToProduct", &AcGeMatrix2d::setToProduct, return_self<>())
        .def("invert", &AcGeMatrix2d::invert, return_self<>())
        .def("inverse", &AcGeMatrix2d::inverse)
        .def("isSingular", &AcGeMatrix2d::isSingular)
        .def("transposeIt", &AcGeMatrix2d::transposeIt, return_self<>())
        .def("transpose", &AcGeMatrix2d::transpose)
        .def("isEqualTo", &AcGeMatrix2d::isEqualTo, arg("AcGeTol") = getTol())
        .def("isUniScaledOrtho", &AcGeMatrix2d::isUniScaledOrtho, arg("AcGeTol") = getTol())
        .def("isScaledOrtho", &AcGeMatrix2d::isScaledOrtho, arg("AcGeTol") = getTol())
        .def("scale", &AcGeMatrix2d::scale)
        .def("det", &AcGeMatrix2d::det)
        .def("setTranslation", &AcGeMatrix2d::setTranslation, return_self<>())
        .def<AcGeVector2d(AcGeMatrix2d::*)(void)const>("translation", &AcGeMatrix2d::translation)
        .def("isConformal", &AcGeMatrix2d::isConformal)
        .def("setCoordSystem", &AcGeMatrix2d::setCoordSystem, return_self<>())
        .def("getCoordSystem", &AcGeMatrix2d::getCoordSystem)
        .def("setToTranslation", &AcGeMatrix2d::setToTranslation, return_self<>())
        .def("setToRotation", &AcGeMatrix2d::setToRotation, arg("AcGePoint2d") = AcGePoint2dkOrigin(), return_self<>())
        .def("setToScaling", &AcGeMatrix2d::setToScaling, return_self<>())
        .def<AcGeMatrix2d& (AcGeMatrix2d::*)(const AcGePoint2d&)>("setToMirroring", &AcGeMatrix2d::setToMirroring, return_self<>())
        .def<AcGeMatrix2d& (AcGeMatrix2d::*)(const AcGeLine2d&)>("setToMirroring", &AcGeMatrix2d::setToMirroring, return_self<>())
        .def("setToAlignCoordSys", &AcGeMatrix2d::setToAlignCoordSys, return_self<>())
        .def("translation", &AcGeMatrix2dtranslation).staticmethod("translation")
        .def("rotation", &AcGeMatrix2drotation).staticmethod("rotation")
        .def("scaling", &AcGeMatrix2scaling).staticmethod("scaling")
        .def("mirroring", &AcGeMatrix2mirroring1).staticmethod("scaling")
        .def("mirroring", &AcGeMatrix2mirroring2).staticmethod("mirroring")
        .def("alignCoordSys", &AcGeMatrix2alignCoordSys).staticmethod("alignCoordSys")
        .def<double(AcGeMatrix2d::*)(unsigned int, unsigned int)const>("elementAt", &AcGeMatrix2d::operator())
        .def("__eq__", &AcGeMatrix2d::operator==)
        .def("__ne__", &AcGeMatrix2d::operator!=)
        .def<AcGeMatrix2d(AcGeMatrix2d::*)(const AcGeMatrix2d&) const>("__mul__", &AcGeMatrix2d::operator*)
        .def<AcGeMatrix2d& (AcGeMatrix2d::*)(const AcGeMatrix2d&)>("__imul__", &AcGeMatrix2d::operator*=, return_self<>())
        .def("toString", &AcGeMatrix2dToString)
        .def("__str__", &AcGeMatrix2dToString)
        .def("__repr__", &AcGeMatrix2dToStringRepr)
        ;
}


//---------------------------------------------------------------------------------------------------------------
//AcGeScale3d
std::string AcGeScale3dToString(const AcGeScale3d& s)
{
    return std::format("({:.14f},{:.14f},{:.14f})", s.sx, s.sy, s.sz);
}

std::string AcGeScale3dToStringRepr(const AcGeScale3d& s)
{
    return std::format("<{}.Scale3d({:.14f},{:.14f},{:.14f})>", PyGeNamespace, s.sx, s.sy, s.sz);
}

void makeAcGeScale3dWrapper()
{
    class_<AcGeScale3d>("Scale3d")
        .def_readwrite("sx", &AcGeScale3d::sx)
        .def_readwrite("sy", &AcGeScale3d::sy)
        .def_readwrite("sz", &AcGeScale3d::sz)
        .def<AcGeScale3d(AcGeScale3d::*)(double)const>("__mul__", &AcGeScale3d::operator*)
        .def<AcGeScale3d& (AcGeScale3d::*)(double)>("__imul__", &AcGeScale3d::operator*=, return_self<>())
        .def<AcGeScale3d(AcGeScale3d::*)(const AcGeScale3d&)const>("__mul__", &AcGeScale3d::operator*)
        .def<AcGeScale3d& (AcGeScale3d::*)(const AcGeScale3d&)>("__imul__", &AcGeScale3d::operator*=, return_self<>())
#ifndef BRXAPP
        .def("preMultBy", &AcGeScale3d::preMultBy, return_self<>())
        .def("postMultBy", &AcGeScale3d::postMultBy, return_self<>())
        .def<AcGeScale3d& (AcGeScale3d::*)(const AcGeScale3d&, double)>("setToProduct", &AcGeScale3d::setToProduct, return_self<>())
        .def<AcGeScale3d& (AcGeScale3d::*)(const AcGeScale3d&, const AcGeScale3d&)>("setToProduct", &AcGeScale3d::setToProduct, return_self<>())
#endif
        .def("__eq__", &AcGeScale3d::operator==)
        .def("__ne__", &AcGeScale3d::operator!=)
        .def("toString", &AcGeScale3dToString)
        .def("__str__", &AcGeScale3dToString)
        .def("__repr__", &AcGeScale3dToStringRepr)
        ;
}

//---------------------------------------------------------------------------------------------------------------
//AcGePoint3d
boost::python::tuple AcGePoint3dToTuple(const AcGePoint3d& p)
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple(p.x, p.y, p.z);
}

boost::python::list AcGePoint3dToList(const AcGePoint3d& p)
{
    PyAutoLockGIL lock;
    boost::python::list l;
    l.append(p.x);
    l.append(p.y);
    l.append(p.z);
    return l;
}

std::string AcGePoint3dToString(const AcGePoint3d& p)
{
    return std::format("({:.14f},{:.14f},{:.14f})", p.x, p.y, p.z);
}

std::string AcGePoint3dToStringRepr(const AcGePoint3d& p)
{
    return std::format("<{}.Point3d({:.14f},{:.14f},{:.14f})>", PyGeNamespace, p.x, p.y, p.z);
}

static AcGePoint3d AcGePoint3dkOrigin()
{
    return AcGePoint3d::kOrigin;
}

AcGePoint3d rmul_AcGePoint3d_AcGeMatrix3d(const AcGePoint3d& pnt, const AcGeMatrix3d& mat)
{
    return mat * pnt;
}

AcGePoint3d rmul_double_AcGepoint3d(const AcGePoint3d& pnt, double val)
{
    return val * pnt;
}

std::size_t AcGePoint3dHash(const AcGePoint3d& p)
{
    std::size_t seed = 0;
    boost::hash_combine(seed, p.x);
    boost::hash_combine(seed, p.y);
    boost::hash_combine(seed, p.z);
    return seed;
}

double AcGePoint3dGetItem(const AcGePoint3d& p, int idx)
{
    switch (idx)
    {
        case 0:
            return p.x;
        case 1:
            return p.y;
        case 2:
            return p.z;
        default:
            throw PyAcadErrorStatus(eOutOfRange);
    }
}

void AcGePoint3dSetItem(AcGePoint3d& p, int idx, double val)
{
    switch (idx)
    {
        case 0:
            p.x = val;
            break;
        case 1:
            p.y = val;
            break;
        case 2:
            p.z = val;
            break;
        default:
            throw PyAcadErrorStatus(eOutOfRange);
    }
}

void makeAcGePoint3dWrapper()
{
    PyDocString DS("Point3d");
    class_<AcGePoint3d>("Point3d")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<double, double, double>(DS.CLASSARGS({ "x: float","y: float","z: float" })))
        .def(init<const AcGePlanarEnt&, const AcGePoint2d&>())
        .def_readwrite("x", &AcGePoint3d::x)
        .def_readwrite("y", &AcGePoint3d::y)
        .def_readwrite("z", &AcGePoint3d::z)
        .add_static_property("kOrigin", &AcGePoint3dkOrigin)
        .def("setToProduct", &AcGePoint3d::setToProduct, return_self<>(), DS.CLASSARGS({ "mat: Matrix3d","pnt: Point3d" }))
        .def("transformBy", &AcGePoint3d::transformBy, return_self<>(), DS.CLASSARGS({ "mat: Matrix3d" }))
        .def("rotateBy", &AcGePoint3d::rotateBy, arg("AcGePoint3d") = AcGePoint3dkOrigin(), return_self<>(), DS.CLASSARGS({ "angle: float","vec: Vector3d","wrtPoint: Point3d=Point3d.kOrigin" }))
        .def("mirror", &AcGePoint3d::mirror, return_self<>(), DS.CLASSARGS({ "pln: Plane" }))
        .def("scaleBy", &AcGePoint3d::scaleBy, arg("AcGePoint3d") = AcGePoint3dkOrigin(), return_self<>())
        .def("convert2d", &AcGePoint3d::convert2d)
        .def("setToSum", &AcGePoint3d::setToSum, return_self<>())
        .def("asVector", &AcGePoint3d::asVector)
        .def("distanceTo", &AcGePoint3d::distanceTo)
        .def("project", &AcGePoint3d::project)
        .def("orthoProject", &AcGePoint3d::orthoProject)
        .def("isEqualTo", &AcGePoint3d::isEqualTo, arg("AcGeTol") = getTol())
        .def<AcGePoint3d& (AcGePoint3d::*)(double, double, double)>("set", &AcGePoint3d::set, return_self<>())
        .def<AcGePoint3d& (AcGePoint3d::*)(const AcGePlanarEnt&, const AcGePoint2d&)>("set", &AcGePoint3d::set, return_self<>())
        .def("__eq__", &AcGePoint3d::operator==)
        .def("__ne__", &AcGePoint3d::operator!=)
        .def<AcGePoint3d(AcGePoint3d::*)(double)const>("__mul__", &AcGePoint3d::operator*)
        .def<AcGePoint3d& (AcGePoint3d::*)(double)>("__imul__", &AcGePoint3d::operator*=, return_self<>())
        .def("__rmul__", &rmul_double_AcGepoint3d)
        .def("__rmul__", &rmul_AcGePoint3d_AcGeMatrix3d)
        .def<AcGePoint3d(AcGePoint3d::*)(double)const>("__truediv__", &AcGePoint3d::operator/)
        .def<AcGePoint3d& (AcGePoint3d::*)(double)>("__itruediv__", &AcGePoint3d::operator/=, return_self<>())
        .def<AcGePoint3d(AcGePoint3d::*)(const AcGeVector3d&)const>("__add__", &AcGePoint3d::operator+)
        .def<AcGePoint3d& (AcGePoint3d::*)(const AcGeVector3d&)>("__iadd__", &AcGePoint3d::operator+=, return_self<>())
        .def<AcGePoint3d(AcGePoint3d::*)(const AcGeVector3d&)const>("__sub__", &AcGePoint3d::operator-)
        .def<AcGePoint3d& (AcGePoint3d::*)(const AcGeVector3d&)>("__isub__", &AcGePoint3d::operator-=, return_self<>())
        .def<AcGeVector3d(AcGePoint3d::*)(const AcGePoint3d&)const>("__sub__", &AcGePoint3d::operator-)
        .def("toList", &AcGePoint3dToList)
        .def("toTuple", &AcGePoint3dToTuple)
        .def("toString", &AcGePoint3dToString)
        .def("__str__", &AcGePoint3dToString)
        .def("__repr__", &AcGePoint3dToStringRepr)
        .def("__hash__", &AcGePoint3dHash)
        .def("__getitem__", &AcGePoint3dGetItem)
        .def("__setitem__", &AcGePoint3dSetItem)
        ;
}

//---------------------------------------------------------------------------------------------------------------
//AcGeVector3d
static AcGeVector3d AcGeVector3dkIdentity()
{
    return AcGeVector3d::kIdentity;
}

static AcGeVector3d AcGeVector3dkXAxis()
{
    return AcGeVector3d::kXAxis;
}

static AcGeVector3d AcGeVector3dkYAxis()
{
    return AcGeVector3d::kYAxis;
}

static AcGeVector3d AcGeVector3dkZAxis()
{
    return AcGeVector3d::kZAxis;
}

std::string AcGeVector3dToString(const AcGeVector3d& p)
{
    return std::format("({:.14f},{:.14f},{:.14f})", p.x, p.y, p.z);
}

std::string AcGeVector3dToStringRepr(const AcGeVector3d& p)
{
    return std::format("<{}.Vector3d({:.14f},{:.14f},{:.14f})>", PyGeNamespace, p.x, p.y, p.z);
}

AcGeVector3d rmul_double_AcGeVector3d(const AcGeVector3d& vec, double val)
{
    return val * vec;
}

AcGeVector3d rmul_AcGeMatrix3d_AcGeVector3d(const AcGeVector3d& vec, const AcGeMatrix3d& mat)
{
    return mat * vec;
}

std::size_t AcGeVector3dHash(const AcGeVector3d& p)
{
    std::size_t seed = 0;
    boost::hash_combine(seed, p.x);
    boost::hash_combine(seed, p.y);
    boost::hash_combine(seed, p.z);
    return seed;
}

double AcGeVector3dGetItem(const AcGeVector3d& p, int idx)
{
    switch (idx)
    {
        case 0:
            return p.x;
        case 1:
            return p.y;
        case 2:
            return p.z;
        default:
            throw PyAcadErrorStatus(eOutOfRange);
    }
}

void AcGeVector3dSetItem(AcGeVector3d& p, int idx, double val)
{
    switch (idx)
    {
        case 0:
            p.x = val;
            break;
        case 1:
            p.y = val;
            break;
        case 2:
            p.z = val;
            break;
        default:
            throw PyAcadErrorStatus(eOutOfRange);
    }
}

static void makeAcGeVector3dWrapper()
{
    class_<AcGeVector3d>("Vector3d")
        .def(init<>())
        .def(init<const AcGeVector3d&>())
        .def(init<double, double, double>())
        .def(init<const AcGePlanarEnt&, const AcGeVector2d&>())
        .def_readwrite("x", &AcGeVector3d::x)
        .def_readwrite("y", &AcGeVector3d::y)
        .def_readwrite("z", &AcGeVector3d::z)
        .add_static_property("kIdentity", &AcGeVector3dkIdentity)
        .add_static_property("kXAxis", &AcGeVector3dkXAxis)
        .add_static_property("kYAxis", &AcGeVector3dkYAxis)
        .add_static_property("kZAxis", &AcGeVector3dkZAxis)
        .def<AcGeVector3d& (AcGeVector3d::*)(const AcGeVector3d&, double)>("setToProduct", &AcGeVector3d::setToProduct, return_self<>())
        .def<AcGeVector3d& (AcGeVector3d::*)(const AcGeMatrix3d&, const AcGeVector3d&)>("setToProduct", &AcGeVector3d::setToProduct, return_self<>())
        .def("transformBy", &AcGeVector3d::transformBy, return_self<>())
        .def("rotateBy", &AcGeVector3d::rotateBy, return_self<>())
        .def("mirror", &AcGeVector3d::mirror, return_self<>())
        .def("convert2d", &AcGeVector3d::convert2d)
        .def("setToSum", &AcGeVector3d::setToSum, return_self<>())
        .def("negate", &AcGeVector3d::negate, return_self<>())
        .def("perpVector", &AcGeVector3d::perpVector)
        .def<double(AcGeVector3d::*)(const AcGeVector3d&) const>("angleTo", &AcGeVector3d::angleTo)
        .def<double(AcGeVector3d::*)(const AcGeVector3d&, const AcGeVector3d&) const>("angleTo", &AcGeVector3d::angleTo)
        .def<AcGeVector3d& (AcGeVector3d::*)(const AcGeTol& tol)>("normalize", &AcGeVector3d::normalize, arg("AcGeTol") = getTol(), return_self<>())
        .def<AcGeVector3d& (AcGeVector3d::*)(const AcGeTol& tol, AcGeError& flag)>("normalize", &AcGeVector3d::normalize, return_self<>())
        .def("angleOnPlane", &AcGeVector3d::angleOnPlane)
        .def("normal", &AcGeVector3d::normal, arg("AcGeTol") = getTol())
        .def("length", &AcGeVector3d::length)
        .def("lengthSqrd", &AcGeVector3d::lengthSqrd)
        .def("isUnitLength", &AcGeVector3d::isUnitLength, arg("AcGeTol") = getTol())
        .def("isZeroLength", &AcGeVector3d::isZeroLength, arg("AcGeTol") = getTol())
        .def<Adesk::Boolean(AcGeVector3d::*)(const AcGeVector3d&, const AcGeTol&) const>("isParallelTo", &AcGeVector3d::isParallelTo, arg("AcGeTol") = getTol())
        .def<Adesk::Boolean(AcGeVector3d::*)(const AcGeVector3d&, const AcGeTol&) const>("isCodirectionalTo", &AcGeVector3d::isCodirectionalTo, arg("AcGeTol") = getTol())
        .def<Adesk::Boolean(AcGeVector3d::*)(const AcGeVector3d&, const AcGeTol&) const>("isPerpendicularTo", &AcGeVector3d::isPerpendicularTo, arg("AcGeTol") = getTol())
        .def("dotProduct", &AcGeVector3d::dotProduct)
        .def("crossProduct", &AcGeVector3d::crossProduct)
        .def("rotateTo", &AcGeVector3d::rotateTo)
        .def<AcGeVector3d(AcGeVector3d::*)(const AcGeVector3d&, const AcGeVector3d&) const>("project", &AcGeVector3d::project)
        .def<AcGeVector3d(AcGeVector3d::*)(const AcGeVector3d&, const AcGeVector3d&, const AcGeTol&, AcGeError&) const>("project", &AcGeVector3d::project)
        .def<AcGeVector3d(AcGeVector3d::*)(const AcGeVector3d&) const>("orthoProject", &AcGeVector3d::orthoProject)
        .def<AcGeVector3d(AcGeVector3d::*)(const AcGeVector3d&, const AcGeTol&, AcGeError&) const>("orthoProject", &AcGeVector3d::orthoProject)
        .def("isEqualTo", &AcGeVector3d::isEqualTo, arg("AcGeTol") = getTol())
        .def("largestElement", &AcGeVector3d::largestElement)
        .def<AcGeVector3d& (AcGeVector3d::*)(double, double, double)>("set", &AcGeVector3d::set, return_self<>())
        .def<AcGeVector3d& (AcGeVector3d::*)(const AcGePlanarEnt&, const AcGeVector2d&)>("set", &AcGeVector3d::set, return_self<>())
        .def("__eq__", &AcGeVector3d::operator==)
        .def("__ne__", &AcGeVector3d::operator!=)
        .def<AcGeVector3d(AcGeVector3d::*)(double)const>("__mul__", &AcGeVector3d::operator*)
        .def<AcGeVector3d& (AcGeVector3d::*)(double)>("__imul__", &AcGeVector3d::operator*=, return_self<>())
        .def("__rmul__", &rmul_double_AcGeVector3d)
        .def("__rmul__", &rmul_AcGeMatrix3d_AcGeVector3d)
        .def<AcGeVector3d(AcGeVector3d::*)(double)const>("__truediv__", &AcGeVector3d::operator/)
        .def<AcGeVector3d& (AcGeVector3d::*)(double)>("__itruediv__", &AcGeVector3d::operator/=, return_self<>())
        .def<AcGeVector3d(AcGeVector3d::*)(const AcGeVector3d&)const>("__add__", &AcGeVector3d::operator+)
        .def<AcGeVector3d& (AcGeVector3d::*)(const AcGeVector3d&)>("__iadd__", &AcGeVector3d::operator+=, return_self<>())
        .def<AcGeVector3d(AcGeVector3d::*)(const AcGeVector3d&)const>("__sub__", &AcGeVector3d::operator-)
        .def<AcGeVector3d& (AcGeVector3d::*)(const AcGeVector3d&)>("__isub__", &AcGeVector3d::operator-=, return_self<>())
        .def("toString", &AcGeVector3dToString)
        .def("__str__", &AcGeVector3dToString)
        .def("__repr__", &AcGeVector3dToStringRepr)
        .def("__hash__", AcGeVector3dHash)
        .def("__getitem__", &AcGeVector3dGetItem)
        .def("__setitem__", &AcGeVector3dSetItem)
        ;
}

//---------------------------------------------------------------------------------------------------------------
//AcGeMatrix3d
static AcGeMatrix3d AcGeMatrix3dkIdentity()
{
    return AcGeMatrix3d::kIdentity;
}

static AcGeMatrix3d AcGeMatrix3dtranslation(const AcGeVector3d& vec)
{
    return AcGeMatrix3d::translation(vec);
}

static AcGeMatrix3d AcGeMatrix3drotation(double angle, const AcGeVector3d& axis, const AcGePoint3d& center)
{
    return AcGeMatrix3d::rotation(angle, axis, center);
}

static AcGeMatrix3d AcGeMatrix3dscaling(double scaleAll, const AcGePoint3d& center)
{
    return AcGeMatrix3d::scaling(scaleAll, center);
}

static AcGeMatrix3d AcGeMatrix3dmirroring1(const AcGePlane& pln)
{
    return AcGeMatrix3d::mirroring(pln);
}
static AcGeMatrix3d AcGeMatrix3dmirroring2(const AcGePoint3d& pnt)
{
    return AcGeMatrix3d::mirroring(pnt);
}
static AcGeMatrix3d AcGeMatrix3dmirroring3(const AcGeLine3d& line)
{
    return AcGeMatrix3d::mirroring(line);
}
static AcGeMatrix3d AcGeMatrix3dprojection(const AcGePlane& projectionPlane, const AcGeVector3d& projectDir)
{
    return AcGeMatrix3d::projection(projectionPlane, projectDir);
}
static AcGeMatrix3d AcGeMatrix3dalignCoordSys(const AcGePoint3d& fromOrigin,
    const AcGeVector3d& fromXAxis,
    const AcGeVector3d& fromYAxis,
    const AcGeVector3d& fromZAxis,
    const AcGePoint3d& toOrigin,
    const AcGeVector3d& toXAxis,
    const AcGeVector3d& toYAxis,
    const AcGeVector3d& toZAxis)
{
    return AcGeMatrix3d::alignCoordSys(fromOrigin, fromXAxis, fromYAxis, fromZAxis, toOrigin, toXAxis, toYAxis, toZAxis);
}

static AcGeMatrix3d AcGeMatrix3dworldToPlane1(const AcGeVector3d& normal)
{
    return AcGeMatrix3d::worldToPlane(normal);
}
static AcGeMatrix3d AcGeMatrix3dworldToPlane2(const AcGePlane& plane)
{
    return AcGeMatrix3d::worldToPlane(plane);
}
static AcGeMatrix3d AcGeMatrix3dplaneToWorld1(const AcGeVector3d& normal)
{
    return AcGeMatrix3d::planeToWorld(normal);
}
static AcGeMatrix3d AcGeMatrix3dplaneToWorld2(const AcGePlane& plane)
{
    return AcGeMatrix3d::planeToWorld(plane);
}

boost::python::list AcGeMatrix3dToList(const AcGeMatrix3d& x)
{
    PyAutoLockGIL lock;
    boost::python::list r0;
    r0.append(x.entry[0][0]);
    r0.append(x.entry[0][1]);
    r0.append(x.entry[0][2]);
    r0.append(x.entry[0][3]);
    boost::python::list r1;
    r1.append(x.entry[1][0]);
    r1.append(x.entry[1][1]);
    r1.append(x.entry[1][2]);
    r1.append(x.entry[1][3]);
    boost::python::list r2;
    r2.append(x.entry[2][0]);
    r2.append(x.entry[2][1]);
    r2.append(x.entry[2][2]);
    r2.append(x.entry[2][3]);
    boost::python::list r3;
    r3.append(x.entry[3][0]);
    r3.append(x.entry[3][1]);
    r3.append(x.entry[3][2]);
    r3.append(x.entry[3][3]);
    boost::python::list m;
    m.append(r0);
    m.append(r1);
    m.append(r2);
    m.append(r3);
    return m;
}

std::string AcGeMatrix3dToString(const AcGeMatrix3d& x)
{
    return std::format("(({0},{1},{2},{3}),({4},{5},{6},{7}),({8},{9},{10},{11}),({12},{13},{14},{15}))",
        x.entry[0][0], x.entry[0][1], x.entry[0][2], x.entry[0][3],
        x.entry[1][0], x.entry[1][1], x.entry[1][2], x.entry[1][3],
        x.entry[2][0], x.entry[2][1], x.entry[2][2], x.entry[2][3],
        x.entry[3][0], x.entry[3][1], x.entry[3][2], x.entry[3][3]);
}

std::string AcGeMatrix3dToStringRepr(const AcGeMatrix3d& x)
{
    return std::format("<{0}.Matrix3d(({1},{2},{3},{4}),({5},{6},{7},{8}),({9},{10},{11},{12}),({12},{14},{15},{16}))>",
        PyGeNamespace,
        x.entry[0][0], x.entry[0][1], x.entry[0][2], x.entry[0][3],
        x.entry[1][0], x.entry[1][1], x.entry[1][2], x.entry[1][3],
        x.entry[2][0], x.entry[2][1], x.entry[2][2], x.entry[2][3],
        x.entry[3][0], x.entry[3][1], x.entry[3][2], x.entry[3][3]);
}

void makeAcGeMatrix3dWrapper()
{
    class_<AcGeMatrix3d>("Matrix3d")
        .def(init<>())
        .def(init<const AcGeMatrix3d&>())
        .add_static_property("kIdentity", &AcGeMatrix3dkIdentity)
        .def("setToIdentity", &AcGeMatrix3d::setToIdentity, return_self<>())
        .def("preMultBy", &AcGeMatrix3d::preMultBy, return_self<>())
        .def("postMultBy", &AcGeMatrix3d::postMultBy, return_self<>())
        .def("setToProduct", &AcGeMatrix3d::setToProduct, return_self<>())
        .def("invert", &AcGeMatrix3d::invert, return_self<>())
        .def<AcGeMatrix3d(AcGeMatrix3d::*)(void)const>("inverse", &AcGeMatrix3d::inverse)
#ifndef BRXAPP
        .def<AcGeMatrix3d(AcGeMatrix3d::*)(const AcGeTol&)const>("inverse", &AcGeMatrix3d::inverse)
#endif // !BRXAPP
        .def<Adesk::Boolean(AcGeMatrix3d::*)(AcGeMatrix3d&, double)const>("inverse", &AcGeMatrix3d::inverse)
        .def("isSingular", &AcGeMatrix3d::isSingular)
        .def("transposeIt", &AcGeMatrix3d::transposeIt, return_self<>())
        .def("transpose", &AcGeMatrix3d::transpose)
        .def("isEqualTo", &AcGeMatrix3d::isEqualTo)
        .def("isUniScaledOrtho", &AcGeMatrix3d::isUniScaledOrtho)
        .def("isScaledOrtho", &AcGeMatrix3d::isScaledOrtho)
        .def("det", &AcGeMatrix3d::det)
        .def("setTranslation", &AcGeMatrix3d::setTranslation, return_self<>())
        .def<AcGeVector3d(AcGeMatrix3d::*)(void)const>("translation", &AcGeMatrix3d::translation)
        .def("setCoordSystem", &AcGeMatrix3d::setCoordSystem, return_self<>())
        .def("getCoordSystem", &AcGeMatrix3d::getCoordSystem)
        .def("setToTranslation", &AcGeMatrix3d::setToTranslation, return_self<>())
        .def("setToRotation", &AcGeMatrix3d::setToRotation, return_self<>())
        .def("setToScaling", &AcGeMatrix3d::setToScaling, return_self<>())
        .def<AcGeMatrix3d& (AcGeMatrix3d::*)(const AcGePlane&)>("setToMirroring", &AcGeMatrix3d::setToMirroring, return_self<>())
        .def<AcGeMatrix3d& (AcGeMatrix3d::*)(const AcGeLine3d&)>("setToMirroring", &AcGeMatrix3d::setToMirroring, return_self<>())
        .def<AcGeMatrix3d& (AcGeMatrix3d::*)(const AcGePoint3d&)>("setToMirroring", &AcGeMatrix3d::setToMirroring, return_self<>())
        .def("setToProjection", &AcGeMatrix3d::setToProjection, return_self<>())
        .def("setToAlignCoordSys", &AcGeMatrix3d::setToAlignCoordSys, return_self<>())
        .def<AcGeMatrix3d& (AcGeMatrix3d::*)(const AcGePlane&)>("setToWorldToPlane", &AcGeMatrix3d::setToWorldToPlane, return_self<>())
        .def<AcGeMatrix3d& (AcGeMatrix3d::*)(const AcGeVector3d&)>("setToWorldToPlane", &AcGeMatrix3d::setToWorldToPlane, return_self<>())
        .def<AcGeMatrix3d& (AcGeMatrix3d::*)(const AcGePlane&)>("setToPlaneToWorld", &AcGeMatrix3d::setToPlaneToWorld, return_self<>())
        .def<AcGeMatrix3d& (AcGeMatrix3d::*)(const AcGeVector3d&)>("setToPlaneToWorld", &AcGeMatrix3d::setToPlaneToWorld, return_self<>())
        .def("scale", &AcGeMatrix3d::scale)
        .def("norm", &AcGeMatrix3d::norm)
        .def("convertToLocal", &AcGeMatrix3d::convertToLocal)
        .def("translation", &AcGeMatrix3dtranslation).staticmethod("translation")
        .def("rotation", &AcGeMatrix3drotation).staticmethod("rotation")
        .def("scaling", &AcGeMatrix3dscaling).staticmethod("scaling")
        .def("mirroring", &AcGeMatrix3dmirroring1)
        .def("mirroring", &AcGeMatrix3dmirroring2)
        .def("mirroring", &AcGeMatrix3dmirroring3).staticmethod("mirroring")
        .def("projection", &AcGeMatrix3dprojection).staticmethod("projection")
        .def("alignCoordSys", &AcGeMatrix3dalignCoordSys).staticmethod("alignCoordSys")
        .def("worldToPlane", &AcGeMatrix3dworldToPlane1)
        .def("worldToPlane", &AcGeMatrix3dworldToPlane2).staticmethod("worldToPlane")
        .def("planeToWorld", &AcGeMatrix3dplaneToWorld1)
        .def("planeToWorld", &AcGeMatrix3dplaneToWorld2).staticmethod("planeToWorld")
        .def("__eq__", &AcGeMatrix3d::operator==)
        .def("__ne__", &AcGeMatrix3d::operator!=)
        .def<AcGeMatrix3d(AcGeMatrix3d::*)(const AcGeMatrix3d&) const>("__mul__", &AcGeMatrix3d::operator*)
        .def<AcGeMatrix3d& (AcGeMatrix3d::*)(const AcGeMatrix3d&)>("__imul__", &AcGeMatrix3d::operator*=, return_self<>())
        .def<double(AcGeMatrix3d::*)(unsigned int, unsigned int)const>("elementAt", &AcGeMatrix3d::operator())
        .def("toString", &AcGeMatrix3dToString)
        .def("toList", &AcGeMatrix3dToList)
        .def("__str__", &AcGeMatrix3dToString)
        .def("__repr__", &AcGeMatrix3dToStringRepr)
        ;
}

BOOST_PYTHON_MODULE(PyGe)
{
    docstring_options local_docstring_options(true, true, true);

    makeAcGeTolWrapper();
    //
    makePyGeKnotVectorWrapper();
    makeAcGePoint2dWrapper();
    makeAcGeVector2dWrapper();
    makeAcGeMatrix2dWrapper();
    //
    makeAcGePoint3dWrapper();
    makeAcGeVector3dWrapper();
    makeAcGeMatrix3dWrapper();
    //
    makeAcGeScale3dWrapper();
    makeAcGeScale2dWrapper();
    //
    makePyGeIntervalWrapper();
    //2D
    makePyGeEntity2dWrapper();
    makePyGeBoundBlock2dWrapper();
    makePyGeClipBoundary2dWrapper();
    makePyGeCurve2dWrapper();
    makeAcGeCircArc2dWrapper();
    makeAcGeEllipArc2Wrapper();
    makeAcGeExternalCurve2dWrapper();
    makeAcGeLinearEnt2dWrapper();
    makeAcGeLine2dWrapper();
    makePyGeLineSeg2dWrapper();
    makeAcGeRay2dWrapper();
    makeAcGeOffsetCurve2dWrapper();
    makePyGeCurveCurveInt2dWrapper();
    makePyGePointEnt2dWrapper();
    makePyGePointOnCurve2dWrapper();
    makeAcGePosition2dWrapper();
    makePyGeSplineEnt2dWrapper();
    makAcGeCubicSplineCurve2dWrapper();
    makAcGeNurbCurve2dWrapper();
    makAcGePolyline2dWrapper();
    makeAcGeCompositeCurve2dWrapper();
    //3D
    makePyGeEntity3dWrapper();
    makePyGeCurveSurfIntWrapper();
    makePyGeSurfSurfIntWrapper();
    makPyGeCurve3dWrapper();
    makePyGePointEnt3dWrapper();
    makePyGePointOnCurve3dWrapper();
    makePyGePointOnSurfaceWrapper();
    makePyGePosition3dWrapper();
    makPyGeBoundBlock3dWrapper();
    makPyGeLinearEnt3dWrapper();
    makPyGeLineSeg3dWrapper();
    makAcGeLine3dWrapper();
    makAcGeRay3ddWrapper();
    makeAcGeSurfaceWrapper();
    makeAcGePlanarEntWrapper();
    makePyGePlaneWrapper();
    makePyGeBoundedPlaneWrapper();
    makAcGeCircArc3dWrapper();
    makAcGeCompositeCurve3dWrapper();
    makeAcGeEllipArc3dWrapper();
    makeAcGeExternalCurve3dWrapper();
    makeAcGeOffsetCurve3dWrapper();
    makePyGeCurveCurveInt3dWrapper();
    makePyGeSplineEnt3dWrapper();
    makAcGeCubicSplineCurve3dWrapper();
    makAcGeNurbCurve3dWrapper();
    makAcGePolyline3dWrapper();

    enum_<AcGe::ErrorCondition>("AcGeError")
        .value("kOk", AcGe::ErrorCondition::kOk)
        .value("k0This", AcGe::ErrorCondition::k0This)
        .value("k0Arg1", AcGe::ErrorCondition::k0Arg1)
        .value("k0Arg2", AcGe::ErrorCondition::k0Arg2)
        .value("kPerpendicularArg1Arg2", AcGe::ErrorCondition::kPerpendicularArg1Arg2)
        .value("kEqualArg1Arg2", AcGe::ErrorCondition::kEqualArg1Arg2)
        .value("kEqualArg1Arg3", AcGe::ErrorCondition::kEqualArg1Arg3)
        .value("kEqualArg2Arg3", AcGe::ErrorCondition::kEqualArg2Arg3)
        .value("kLinearlyDependentArg1Arg2Arg3", AcGe::ErrorCondition::kLinearlyDependentArg1Arg2Arg3)
        .value("kArg1TooBig", AcGe::ErrorCondition::kArg1TooBig)
        .value("kArg1OnThis", AcGe::ErrorCondition::kArg1OnThis)
        .value("kArg1InsideThis", AcGe::ErrorCondition::kArg1InsideThis)
        .export_values()
        ;
    enum_<AcGe::OffsetCrvExtType>("OffsetCrvExtType")
        .value("kFillet", AcGe::OffsetCrvExtType::kFillet)
        .value("kChamfer", AcGe::OffsetCrvExtType::kChamfer)
        .value("kExtend", AcGe::OffsetCrvExtType::kExtend)
        .export_values()
        ;
    enum_<AcGe::EntityId>("EntityId")
        .value("kEntity2d", AcGe::EntityId::kEntity2d)
        .value("kEntity3d", AcGe::EntityId::kEntity3d)
        .value("kPointEnt2d", AcGe::EntityId::kPointEnt2d)
        .value("kPointEnt3d", AcGe::EntityId::kPointEnt3d)
        .value("kPosition2d", AcGe::EntityId::kPosition2d)
        .value("kPosition3d", AcGe::EntityId::kPosition3d)
        .value("kPointOnCurve2d", AcGe::EntityId::kPointOnCurve2d)
        .value("kPointOnCurve3d", AcGe::EntityId::kPointOnCurve3d)
        .value("kPointOnSurface", AcGe::EntityId::kPointOnSurface)
        .value("kBoundedPlane", AcGe::EntityId::kBoundedPlane)
        .value("kCircArc2d", AcGe::EntityId::kCircArc2d)
        .value("kCircArc3d", AcGe::EntityId::kCircArc3d)
        .value("kConic2d", AcGe::EntityId::kConic2d)
        .value("kConic3d", AcGe::EntityId::kConic3d)
        .value("kCurve2d", AcGe::EntityId::kCurve2d)
        .value("kCurve3d", AcGe::EntityId::kCurve3d)
        .value("kEllipArc2d", AcGe::EntityId::kEllipArc2d)
        .value("kEllipArc3d", AcGe::EntityId::kEllipArc3d)
        .value("kLine2d", AcGe::EntityId::kLine2d)
        .value("kLine3d", AcGe::EntityId::kLine3d)
        .value("kLinearEnt2d", AcGe::EntityId::kLinearEnt2d)
        .value("kLinearEnt3d", AcGe::EntityId::kLinearEnt3d)
        .value("kLineSeg2d", AcGe::EntityId::kLineSeg2d)
        .value("kLineSeg3d", AcGe::EntityId::kLineSeg3d)
        .value("kPlanarEnt", AcGe::EntityId::kPlanarEnt)
        .value("kPlane", AcGe::EntityId::kPlane)
        .value("kRay2d", AcGe::EntityId::kRay2d)
        .value("kRay3d", AcGe::EntityId::kRay3d)
        .value("kSurface", AcGe::EntityId::kSurface)
        .value("kSphere", AcGe::EntityId::kSphere)
        .value("kCylinder", AcGe::EntityId::kCylinder)
        .value("kTorus", AcGe::EntityId::kTorus)
        .value("kCone", AcGe::EntityId::kCone)
        .value("kSplineEnt2d", AcGe::EntityId::kSplineEnt2d)
        .value("kPolyline2d", AcGe::EntityId::kPolyline2d)
        .value("kAugPolyline2d", AcGe::EntityId::kAugPolyline2d)
        .value("kNurbCurve2d", AcGe::EntityId::kNurbCurve2d)
        .value("kDSpline2d", AcGe::EntityId::kDSpline2d)
        .value("kCubicSplineCurve2d", AcGe::EntityId::kCubicSplineCurve2d)
        .value("kSplineEnt3d", AcGe::EntityId::kSplineEnt3d)
        .value("kPolyline3d", AcGe::EntityId::kPolyline3d)
        .value("kAugPolyline3d", AcGe::EntityId::kAugPolyline3d)
        .value("kNurbCurve3d", AcGe::EntityId::kNurbCurve3d)
        .value("kDSpline3d", AcGe::EntityId::kDSpline3d)
        .value("kCubicSplineCurve3d", AcGe::EntityId::kCubicSplineCurve3d)
        .value("kTrimmedCrv2d", AcGe::EntityId::kTrimmedCrv2d)
        .value("kCompositeCrv2d", AcGe::EntityId::kCompositeCrv2d)
        .value("kCompositeCrv3d", AcGe::EntityId::kCompositeCrv3d)
        .value("kExternalSurface", AcGe::EntityId::kExternalSurface)
        .value("kNurbSurface", AcGe::EntityId::kNurbSurface)
        .value("kTrimmedSurface", AcGe::EntityId::kTrimmedSurface)
        .value("kOffsetSurface", AcGe::EntityId::kOffsetSurface)
        .value("kEnvelope2d", AcGe::EntityId::kEnvelope2d)
        .value("kCurveBoundedSurface", AcGe::EntityId::kCurveBoundedSurface)
        .value("kExternalCurve3d", AcGe::EntityId::kExternalCurve3d)
        .value("kExternalCurve2d", AcGe::EntityId::kExternalCurve2d)
        .value("kSurfaceCurve2dTo3d", AcGe::EntityId::kSurfaceCurve2dTo3d)
        .value("kSurfaceCurve3dTo2d", AcGe::EntityId::kSurfaceCurve3dTo2d)
        .value("kExternalBoundedSurface", AcGe::EntityId::kExternalBoundedSurface)
        .value("kCurveCurveInt2d", AcGe::EntityId::kCurveCurveInt2d)
        .value("kCurveCurveInt3d", AcGe::EntityId::kCurveCurveInt3d)
        .value("kBoundBlock2d", AcGe::EntityId::kBoundBlock2d)
        .value("kBoundBlock3d", AcGe::EntityId::kBoundBlock3d)
        .value("kOffsetCurve2d", AcGe::EntityId::kOffsetCurve2d)
        .value("kOffsetCurve3d", AcGe::EntityId::kOffsetCurve3d)
        .value("kPolynomCurve3d", AcGe::EntityId::kPolynomCurve3d)
        .value("kBezierCurve3d", AcGe::EntityId::kBezierCurve3d)
        .value("kObject", AcGe::EntityId::kObject)
        .value("kFitData3d", AcGe::EntityId::kFitData3d)
        .value("kHatch", AcGe::EntityId::kHatch)
        .value("kTrimmedCurve2d", AcGe::EntityId::kTrimmedCurve2d)
        .value("kTrimmedCurve3d", AcGe::EntityId::kTrimmedCurve3d)
        .value("kCurveSampleData", AcGe::EntityId::kCurveSampleData)
        .value("kEllipCone", AcGe::EntityId::kEllipCone)
        .value("kEllipCylinder", AcGe::EntityId::kEllipCylinder)
        .value("kIntervalBoundBlock", AcGe::EntityId::kIntervalBoundBlock)
        .value("kClipBoundary2d", AcGe::EntityId::kClipBoundary2d)
        .value("kExternalObject", AcGe::EntityId::kExternalObject)
        .value("kCurveSurfaceInt", AcGe::EntityId::kCurveSurfaceInt)
        .value("kSurfaceSurfaceInt", AcGe::EntityId::kSurfaceSurfaceInt)
#ifndef BRXAPP
        .value("Helix", AcGe::EntityId::kHelix)
#endif // !BRXAPP 
        .export_values()
        ;
};

void initPyGeModule()
{
    PyImport_AppendInittab(PyGeNamespace, &PyInit_PyGe);
}
