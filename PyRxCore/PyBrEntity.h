#pragma once

#include "PyDbEntity.h"
#pragma pack (push, 8)

class PyGeBoundBlock3d;
class PyGeLinearEnt3d;
class PyGeCurve3d;
class PyDb3dSolid;
class PyDbSurface;
class PyGeSurface;
class PyBrEntity;
class PyBrVertex;
class PyBrShell;
class PyBrBrep;
class PyBrHit;

//-----------------------------------------------------------------------------------------
// PyBrHit
void makePyBrHitWrapper();

class PyBrHit : public PyRxObject
{
public:
    PyBrHit();
    PyBrHit(const AcBrHit src);
    PyBrHit(const AcRxObject* ptr);
    PyBrHit(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrHit() = default;

    Adesk::Boolean              isEqualTo(const PyRxObject& other) const;
    Adesk::Boolean              isNull() const;

    PyBrEntity                  getEntityHit() const;
    PyBrEntity                  getEntityEntered() const;
    PyBrEntity                  getEntityAssociated() const;
    AcGePoint3d                 getPoint() const;
    void	                    setValidationLevel(const AcBr::ValidationLevel& validationLevel);
    AcBr::ValidationLevel       getValidationLevel() const;
    Adesk::Boolean		        brepChanged() const;

    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrHit* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
// PyBrEntity
void makePyBrEntityWrapper();

class PyBrEntity : public PyRxObject
{
public:
    PyBrEntity(const AcRxObject* ptr);
    PyBrEntity(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrEntity() = default;

    Adesk::Boolean              isEqualTo(const PyRxObject& other) const;
    Adesk::Boolean              isNull() const;

    PyDbFullSubentPath          getSubentPath() const;
    void                        setSubentPath(PyDbFullSubentPath& subpath);

    Adesk::Boolean		        checkEntity() const;
    PyGeBoundBlock3d            getBoundBlock() const;

    boost::python::tuple        getPointContainment(const AcGePoint3d& point);
    boost::python::list         getLineContainment(const PyGeLinearEnt3d& line, const Adesk::UInt32 numHitsWanted);

    PyBrBrep                    getBrep();

    void	                    setValidationLevel(const AcBr::ValidationLevel level);
    AcBr::ValidationLevel	    getValidationLevel() const;

    Adesk::Boolean		        brepChanged() const;
    boost::python::tuple        getMassProps1();
    boost::python::tuple        getMassProps2(double density, double tolRequired);

    boost::python::tuple        getVolume1();
    boost::python::tuple        getVolume2(double tolRequired);

    boost::python::tuple        getSurfaceArea1();
    boost::python::tuple        getSurfaceArea2(double tolRequired);

    boost::python::tuple        getPerimeterLength1();
    boost::python::tuple        getPerimeterLength2(double tolRequired);

    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
// PyBrBrep
void makePyBrBrepWrapper();

class PyBrBrep : public PyBrEntity
{
public:
    PyBrBrep();
    PyBrBrep(const AcBrBrep& src);
    PyBrBrep(const AcRxObject* ptr);
    PyBrBrep(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrBrep() = default;

    AcBr::Relation      getPointRelationToBrep(const AcGePoint3d& point) const;
    AcBr::Relation      getCurveRelationToBrep(const AcGeCurve3d& curve) const;
    void	            set(const PyDbEntity& entity);
    PyDb3dSolid         getSolid();
    PyDbSurface	        getSurface() const;

    static PyRxClass    desc();
    static std::string  className();
public:
    inline AcBrBrep* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrComplex
void makePyBrComplexWrapper();

class PyBrComplex : public PyBrEntity
{
public:
    PyBrComplex();
    PyBrComplex(const AcBrComplex& src);
    PyBrComplex(const AcRxObject* ptr);
    PyBrComplex(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrComplex() = default;

    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrComplex* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
// PyBrEdge
void makePyBrEdgeWrapper();

class PyBrEdge : public PyBrEntity
{
public:
    PyBrEdge();
    PyBrEdge(const AcBrEdge& srx);
    PyBrEdge(const AcRxObject* ptr);
    PyBrEdge(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrEdge() = default;

    AcGe::EntityId  getCurveType() const;
    PyGeCurve3d     getCurve() const;
    Adesk::Boolean  getOrientToCurve() const;

    PyBrVertex      getVertex1() const;
    PyBrVertex      getVertex2() const;

    AcBr::Relation  getPointRelationToEdge(const AcGePoint3d& point) const;
    AcBr::Relation  getCurveRelationToEdge(const PyGeCurve3d& curve) const;

    //TODO requires AcGeNurbCurve3d wrapper
    //AcBr::ErrorStatus getCurveAsNurb(AcGeNurbCurve3d& nurb, const double* fitTolRequired = NULL,  double* fitTolAchieved = NULL) const;

    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrEdge* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrFace
void makePyBrFaceWrapper();

class PyBrFace : public PyBrEntity
{
public:
    PyBrFace();
    PyBrFace(const AcBrFace& src);
    PyBrFace(const AcRxObject* ptr);
    PyBrFace(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrFace() = default;

    AcGe::EntityId          getSurfaceType() const;
    PyGeSurface             getSurface() const;
    Adesk::Boolean          getOrientToSurface() const;
    boost::python::tuple    getArea1();
    boost::python::tuple    getArea2(double tolRequired);
    AcBr::Relation          getPointRelationToFace(const AcGePoint3d& point) const;
    AcBr::Relation          getCurveRelationToFace(const PyGeCurve3d& curve) const;
    PyBrShell               getShell() const;

    static PyRxClass        desc();
    static std::string      className();
public:
    inline AcBrFace* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrLoop
void makePyBrLoopWrapper();

class PyBrLoop : public PyBrEntity
{
public:
    PyBrLoop();
    PyBrLoop(const AcBrLoop& src);
    PyBrLoop(const AcRxObject* ptr);
    PyBrLoop(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrLoop() = default;

    PyBrFace            getFace() const;
    AcBr::LoopType      getType() const;

    static PyRxClass    desc();
    static std::string  className();
public:
    inline AcBrLoop* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrShell
void makePyBrShellWrapper();

class PyBrShell : public PyBrEntity
{
public:
    PyBrShell();
    PyBrShell(const AcBrShell& src);
    PyBrShell(const AcRxObject* ptr);
    PyBrShell(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrShell() = default;

    PyBrComplex         getComplex() const;
    AcBr::ShellType     getType() const;

    static PyRxClass    desc();
    static std::string  className();
public:
    inline AcBrShell* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrVertex
void makePyBrVertexWrapper();

class PyBrVertex : public PyBrEntity
{
public:
    PyBrVertex();
    PyBrVertex(const AcBrVertex& src);
    PyBrVertex(const AcRxObject* ptr);
    PyBrVertex(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrVertex() = default;

    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrVertex* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)