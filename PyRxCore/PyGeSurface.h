#pragma once
#include "PyGeEntity3d.h"

#pragma pack (push, 8)
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
    virtual ~PyGeSurface() override = default;

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
    void                reverseNormal() const;
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
#if !defined(_BRXTARGET260)
public:
    PyGeCone();

    PyGeCone(double cosineAngle, double sineAngle,
        const  AcGePoint3d& baseOrigin, double baseRadius,
        const  AcGeVector3d& axisOfSymmetry);

    PyGeCone(double cosineAngle, double sineAngle,
        const  AcGePoint3d& baseOrigin, double baseRadius,
        const  AcGeVector3d& axisOfSymmetry,
        const  AcGeVector3d& refAxis, const  PyGeInterval& height,
        double startAngle, double endAngle);

    PyGeCone(AcGeEntity3d* src);
    PyGeCone(AcGeCone* src);
    PyGeCone(const AcGeCone& src);
    virtual ~PyGeCone() override = default;

    double              baseRadius() const;
    AcGePoint3d         baseCenter() const;
    boost::python::tuple getAngles() const;
    double              halfAngle() const;
    boost::python::tuple  getHalfAngle()const;
    PyGeInterval        getHeight() const;
    double              heightAt(double u) const;
    AcGeVector3d        axisOfSymmetry() const;
    AcGeVector3d        refAxis() const;
    AcGePoint3d         apex() const;
    Adesk::Boolean      isClosed1() const;
    Adesk::Boolean      isClosed2(const AcGeTol& tol) const;
    Adesk::Boolean      isOuterNormal() const;

    void                setBaseRadius(double radius) const;
    void                setAngles(double startAngle, double endAngle) const;
    void                setHeight(const PyGeInterval& height) const;

    void                set1(double cosineAngle, double sineAngle,
        const  AcGePoint3d& baseCenter, double baseRadius,
        const  AcGeVector3d& axisOfSymmetry) const;

    void                set2(double cosineAngle, double sineAngle,
        const  AcGePoint3d& baseCenter,
        double baseRadius,
        const  AcGeVector3d& axisOfSymmetry,
        const  AcGeVector3d& refAxis,
        const  PyGeInterval& height,
        double startAngle, double endAngle) const;

    boost::python::tuple intersectWith1(const PyGeLinearEnt3d& linEnt) const;
    boost::python::tuple intersectWith2(const PyGeLinearEnt3d& linEnt, AcGeTol& tol) const;

    static PyGeCone     cast(const PyGeEntity3d& src);
    static PyGeCone     copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeCone* impObj(const std::source_location& src = std::source_location::current()) const;
#endif

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
    virtual ~PyGeCylinder() override = default;

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

    void                 setRadius(double radius) const;
    void                 setAngles(double start, double end) const;
    void                 setHeight(const PyGeInterval& height) const;

    void                 set1(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSym) const;

    void                 set2(double radius, const AcGePoint3d& origin, const AcGeVector3d& axisOfSym,
        const AcGeVector3d& refAxis, const PyGeInterval& height, double startAngle, double endAngle) const;

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
#if !defined(_BRXTARGET260)
public:
    PyGeExternalBoundedSurface();
    PyGeExternalBoundedSurface(AcGeEntity3d* src);
    PyGeExternalBoundedSurface(AcGeExternalBoundedSurface* src);
    PyGeExternalBoundedSurface(const AcGeExternalBoundedSurface& src);
    virtual ~PyGeExternalBoundedSurface() override = default;
    static PyGeExternalBoundedSurface cast(const PyGeEntity3d& src);
    static PyGeExternalBoundedSurface copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeExternalBoundedSurface* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//AcGeExternalSurface wrapper
void makePyGeExternalSurfaceWrapper();
class PyGeExternalSurface : public PyGeSurface
{
#if !defined(_BRXTARGET260)
public:
    PyGeExternalSurface();
    PyGeExternalSurface(AcGeEntity3d* src);
    PyGeExternalSurface(AcGeExternalSurface* src);
    PyGeExternalSurface(const AcGeExternalSurface& src);
    virtual ~PyGeExternalSurface() override = default;
    static PyGeExternalSurface cast(const PyGeEntity3d& src);
    static PyGeExternalSurface copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeExternalSurface* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//AcGeNurbSurface wrapper
void makePyGeNurbSurfaceWrapper();
class PyGeNurbSurface : public PyGeSurface
{
#if !defined(_BRXTARGET260)
public:
    PyGeNurbSurface();
    PyGeNurbSurface(AcGeEntity3d* src);
    PyGeNurbSurface(AcGeNurbSurface* src);
    PyGeNurbSurface(const AcGeNurbSurface& src);
    virtual ~PyGeNurbSurface() override = default;
    static PyGeNurbSurface cast(const PyGeEntity3d& src);
    static PyGeNurbSurface copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeNurbSurface* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//AcGeOffsetSurface wrapper
void makePyGeOffsetSurfaceWrapper();
class PyGeOffsetSurface : public PyGeSurface
{
#if !defined(_BRXTARGET260)
public:
    PyGeOffsetSurface();
    PyGeOffsetSurface(AcGeOffsetSurface* src);
    PyGeOffsetSurface(AcGeEntity3d* src);
    PyGeOffsetSurface(const AcGeOffsetSurface& src);
    virtual ~PyGeOffsetSurface() override = default;
    static PyGeOffsetSurface cast(const PyGeEntity3d& src);
    static PyGeOffsetSurface copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeOffsetSurface* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
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
    virtual ~PyGeSphere() override = default;

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

    void            setRadius(double val) const;
    void            setAnglesInU(double start, double end) const;
    void            setAnglesInV(double start, double end) const;
    void            set1(double radius, const AcGePoint3d& center) const;
    void            set2(double radius, const AcGePoint3d& center,
        const AcGeVector3d& northAxis, const AcGeVector3d& refAxis,
        double startAngleU, double endAngleU,
        double startAngleV, double endAngleV) const;

    boost::python::tuple intersectWith1(const PyGeLinearEnt3d& ent) const;
    boost::python::tuple intersectWith2(const PyGeLinearEnt3d&, const AcGeTol& tol) const;

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
#if !defined(_BRXTARGET260)
public:
    PyGeTorus();
    PyGeTorus(AcGeEntity3d* src);
    PyGeTorus(AcGeTorus* src);
    PyGeTorus(const AcGeTorus& src);
    virtual ~PyGeTorus() override = default;
    static PyGeTorus cast(const PyGeEntity3d& src);
    static PyGeTorus copycast(const PyGeEntity3d& src);
    static std::string  className();
public:
    AcGeTorus* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

#pragma pack (pop)