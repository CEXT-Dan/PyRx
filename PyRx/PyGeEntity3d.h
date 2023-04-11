#pragma once
class  PyGePlane;

//-----------------------------------------------------------------------------------------
//PyGeEntity3d wrapper
void makePyGeEntity3dWrapper();
class PyGeEntity3d
{
protected:
    PyGeEntity3d() = default;
public:
    PyGeEntity3d(AcGeEntity3d* pEnt);
    ~PyGeEntity3d() = default;
    bool operator==(PyGeEntity3d const& rhs) const;
    bool operator!=(PyGeEntity3d const& rhs) const;

    Adesk::Boolean isKindOf(AcGe::EntityId entType) const;
    AcGe::EntityId type() const;
    PyGeEntity3d copy() const;
    Adesk::Boolean isEqualTo(const PyGeEntity3d& ent, const AcGeTol& tol) const;

    PyGeEntity3d& transformBy(const AcGeMatrix3d& xfm);
    PyGeEntity3d& translateBy(const AcGeVector3d& translateVec);

    PyGeEntity3d& rotateBy1(double angle, const AcGeVector3d& vec);
    PyGeEntity3d& rotateBy2(double angle, const AcGeVector3d& vec, const AcGePoint3d& wrtPoint);

    PyGeEntity3d& mirror(const PyGePlane& plane);

    PyGeEntity3d& scaleBy1(double scaleFactor);
    PyGeEntity3d& scaleBy2(double scaleFactor, const AcGePoint3d& wrtPoint);

    Adesk::Boolean isOn1(const AcGePoint3d& pnt) const;
    Adesk::Boolean isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const;

    bool isNull()const;
    static std::string className();
public:
    AcGeEntity3d* impObj() const;
public:
    std::shared_ptr<AcGeEntity3d> m_imp;
};


//-----------------------------------------------------------------------------------------
//AcGeSurface wrapper
void makeAcGeSurfaceWrapper();
class PyAcGeSurface : public PyGeEntity3d
{
protected:
    PyAcGeSurface() = default;
public:
    PyAcGeSurface(AcGeSurface* pEnt);
    PyAcGeSurface(AcGeEntity3d* pEnt);
    ~PyAcGeSurface() = default;
    static std::string className();
public:
    AcGeSurface* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeSurface wrapper
void makeAcGePlanarEntWrapper();
class PyGePlanarEnt : public PyAcGeSurface
{
protected:
    PyGePlanarEnt() = default;
public:
    PyGePlanarEnt(AcGePlanarEnt* pEnt);
    PyGePlanarEnt(AcGeEntity3d* pEnt);
    ~PyGePlanarEnt() = default;
    static std::string className();
public:
    AcGePlanarEnt* impObj() const;
};


//-----------------------------------------------------------------------------------------
//PyGePlane wrapper
void makePyGePlaneWrapper();
class PyGePlane : public PyGePlanarEnt
{
public:
    PyGePlane();
    PyGePlane(AcGePlane* pEnt);
    PyGePlane(const AcGePlane& ent);//TODO: which ctor? from AcGeEntity3d::copy() or copy ctor
    PyGePlane(AcGeEntity3d* pEnt);
    ~PyGePlane() = default;
    static std::string className();
public:
    AcGePlane* impObj() const;
};

