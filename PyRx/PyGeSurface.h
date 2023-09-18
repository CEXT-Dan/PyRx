#pragma once
#include "PyGeEntity3d.h"
class PyGeInterval;
class PyGePointOnSurface;
class PyGeLinearEnt3d;
//-----------------------------------------------------------------------------------------
//AcGeSurface wrapper
void makePyGeSurfaceWrapper();
class PyGeSurface : public PyGeEntity3d
{
protected:
    PyGeSurface() = default;
public:
    PyGeSurface(AcGeEntity3d* pEnt);
    PyGeSurface(AcGeSurface* pEnt);
    PyGeSurface(const AcGeSurface* pEnt);

    ~PyGeSurface() = default;
    AcGePoint2d         paramOf(const AcGePoint3d& pnt) const;
    AcGePoint2d         paramOfTol(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    Adesk::Boolean      isOn1(const AcGePoint3d& pnt) const;
    Adesk::Boolean      isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    Adesk::Boolean      isOn3(const AcGePoint3d& pnt, AcGePoint2d& paramPoint) const;
    Adesk::Boolean      isOn4(const AcGePoint3d& pnt, AcGePoint2d& paramPoint, const AcGeTol& tol) const;
    AcGePoint3d         closestPointTo1(const AcGePoint3d& pnt) const;
    AcGePoint3d         closestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    PyGePointOnSurface  getClosestPointTo1(const AcGePoint3d& pnt) const;
    PyGePointOnSurface  getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    double              distanceTo1(const AcGePoint3d& pnt) const;
    double              distanceTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    Adesk::Boolean      isNormalReversed() const;
    void                reverseNormal();
    void                getEnvelope(PyGeInterval& intrvlX, PyGeInterval& intrvlY) const;
    Adesk::Boolean      isClosedInU1() const;
    Adesk::Boolean      isClosedInU2(const AcGeTol& tol) const;
    Adesk::Boolean      isClosedInV1() const;
    Adesk::Boolean      isClosedInV2(const AcGeTol& tol) const;
    AcGePoint3d         evalPoint1(const AcGePoint2d& param) const;
    AcGePoint3d         evalPoint2(const AcGePoint2d& param, int derivOrd, boost::python::list& derivatives) const;
    AcGePoint3d         evalPoint3(const AcGePoint2d& param, int derivOrd, boost::python::list& derivatives, AcGeVector3d& normal) const;
    static PyGeSurface  cast(const PyGeEntity3d& src);
    static PyGeSurface  copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeCone wrapper
void makePyGeConeWrapper();
class PyGeCone : public PyGeSurface
{
public:
    PyGeCone();
    PyGeCone(AcGeEntity3d* src);
    PyGeCone(AcGeCone* src);
    PyGeCone(const AcGeCone& src);
    ~PyGeCone() = default;
    static PyGeCone     cast(const PyGeEntity3d& src);
    static PyGeCone     copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeCone* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeCylinder wrapper
void makePyGeCylinderWrapper();
class PyGeCylinder : public PyGeSurface
{
public:
    PyGeCylinder();

    PyGeCylinder(double radius, const AcGePoint3d& origin,
        const AcGeVector3d& axisOfSymmetry);


    PyGeCylinder(double radius, const AcGePoint3d& origin,
        const AcGeVector3d& axisOfSymmetry,
        const AcGeVector3d& refAxis,
        const PyGeInterval& height,
        double startAngle, double endAngle);

    PyGeCylinder(AcGeEntity3d* src);
    PyGeCylinder(AcGeCylinder* src);
    PyGeCylinder(const AcGeCylinder& src);
    ~PyGeCylinder() = default;

    double               radius() const;
    AcGePoint3d          origin() const;
    boost::python::tuple getAngles() const;
    PyGeInterval         getHeight() const;
    double               heightAt(double u) const;
    AcGeVector3d         axisOfSymmetry() const;
    AcGeVector3d         refAxis() const;
    Adesk::Boolean       isOuterNormal() const;
    Adesk::Boolean       isClosed1() const;
    Adesk::Boolean       isClosed2(const AcGeTol& tol) const;

    void                 setRadius(double radius);
    void                 setAngles(double start, double end);
    void                 setHeight(const PyGeInterval& height);

    void                 set1(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSym);

    void                 set2(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSym,
        const AcGeVector3d& refAxis, const PyGeInterval& height, double startAngle, double endAngle);

    boost::python::tuple intersectWith1(const PyGeLinearEnt3d& linEntconst) const;
    boost::python::tuple intersectWith2(const PyGeLinearEnt3d& linEntconst, AcGeTol& tol) const;


    static PyGeCylinder cast(const PyGeEntity3d& src);
    static PyGeCylinder copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeCylinder* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeExternalBoundedSurface wrapper
void makePyGeExternalBoundedSurfaceWrapper();
class PyGeExternalBoundedSurface : public PyGeSurface
{
public:
    PyGeExternalBoundedSurface();
    PyGeExternalBoundedSurface(AcGeEntity3d* src);
    PyGeExternalBoundedSurface(AcGeExternalBoundedSurface* src);
    PyGeExternalBoundedSurface(const AcGeExternalBoundedSurface& src);
    ~PyGeExternalBoundedSurface() = default;
    static PyGeExternalBoundedSurface cast(const PyGeEntity3d& src);
    static PyGeExternalBoundedSurface copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeExternalBoundedSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeExternalSurface wrapper
void makePyGeExternalSurfaceWrapper();
class PyGeExternalSurface : public PyGeSurface
{
public:
    PyGeExternalSurface();
    PyGeExternalSurface(AcGeEntity3d* src);
    PyGeExternalSurface(AcGeExternalSurface* src);
    PyGeExternalSurface(const AcGeExternalSurface& src);
    ~PyGeExternalSurface() = default;
    static PyGeExternalSurface cast(const PyGeEntity3d& src);
    static PyGeExternalSurface copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeExternalSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeNurbSurface wrapper
void makePyGeNurbSurfaceWrapper();
class PyGeNurbSurface : public PyGeSurface
{
public:
    PyGeNurbSurface();
    PyGeNurbSurface(AcGeEntity3d* src);
    PyGeNurbSurface(AcGeNurbSurface* src);
    PyGeNurbSurface(const AcGeNurbSurface& src);
    ~PyGeNurbSurface() = default;
    static PyGeNurbSurface cast(const PyGeEntity3d& src);
    static PyGeNurbSurface copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeNurbSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeOffsetSurface wrapper
void makePyGeOffsetSurfaceWrapper();
class PyGeOffsetSurface : public PyGeSurface
{
public:
    PyGeOffsetSurface();
    PyGeOffsetSurface(AcGeOffsetSurface* src);
    PyGeOffsetSurface(AcGeEntity3d* src);
    PyGeOffsetSurface(const AcGeOffsetSurface& src);
    ~PyGeOffsetSurface() = default;
    static PyGeOffsetSurface cast(const PyGeEntity3d& src);
    static PyGeOffsetSurface copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeOffsetSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeSphere wrapper
void makePyGeSphereWrapper();
class PyGeSphere : public PyGeSurface
{
public:
    PyGeSphere();
    PyGeSphere(double radius, const AcGePoint3d& center);

    PyGeSphere(double radius, const AcGePoint3d& center,
        const AcGeVector3d& northAxis, const AcGeVector3d& refAxis,
        double startAngleU, double endAngleU,
        double startAngleV, double endAngleV);

    PyGeSphere(AcGeSphere* src);
    PyGeSphere(AcGeEntity3d* src);
    PyGeSphere(const AcGeSphere& src);
    ~PyGeSphere() = default;

    double         radius() const;
    AcGePoint3d    center() const;
    boost::python::tuple getAnglesInU() const;
    boost::python::tuple getAnglesInV() const;
    AcGeVector3d   northAxis() const;
    AcGeVector3d   refAxis() const;
    AcGePoint3d    northPole() const;
    AcGePoint3d    southPole() const;
    Adesk::Boolean isOuterNormal() const;
    Adesk::Boolean isClosed1() const;
    Adesk::Boolean isClosed2(const AcGeTol& to) const;

    void            setRadius(double val);
    void            setAnglesInU(double start, double end);
    void            setAnglesInV(double start, double end);
    void            set1(double radius, const AcGePoint3d& center);
    void            set2(double radius, const AcGePoint3d& center,
        const AcGeVector3d& northAxis,const AcGeVector3d& refAxis,
        double startAngleU,double endAngleU,
        double startAngleV, double endAngleV);

    Adesk::Boolean intersectWith1(const PyGeLinearEnt3d& ent) const;
    Adesk::Boolean intersectWith2(const PyGeLinearEnt3d&, const AcGeTol& tol) const;

    static PyGeSphere cast(const PyGeEntity3d& src);
    static PyGeSphere copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeSphere* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeTorus wrapper
void makePyGeTorusWrapper();
class PyGeTorus : public PyGeSurface
{
public:
    PyGeTorus();
    PyGeTorus(AcGeEntity3d* src);
    PyGeTorus(AcGeTorus* src);
    PyGeTorus(const AcGeTorus& src);
    ~PyGeTorus() = default;
    static PyGeTorus cast(const PyGeEntity3d& src);
    static PyGeTorus copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeTorus* impObj(const std::source_location& src = std::source_location::current()) const;
};