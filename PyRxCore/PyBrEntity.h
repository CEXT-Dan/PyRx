#pragma once

#include "PyDbEntity.h"
#pragma pack (push, 8)

class PyGeBoundBlock3d;
class PyGeLinearEnt3d;
class PyDb3dSolid;
class PyBrEntity;
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
    boost::python::tuple        getVolume2(double density, double tolRequired);

    boost::python::tuple        getSurfaceArea1();
    boost::python::tuple        getSurfaceArea2(double density, double tolRequired);

    boost::python::tuple        getPerimeterLength1();
    boost::python::tuple        getPerimeterLength2(double density, double tolRequired);

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



    static PyRxClass            desc();
    static std::string          className();
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
    PyBrEdge(const AcRxObject* ptr);
    PyBrEdge(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrEdge() = default;

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
    PyBrFace(const AcRxObject* ptr);
    PyBrFace(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrFace() = default;

    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrFace* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrLoop
void makePyBrLoopWrapper();

class PyBrLoop : public PyBrEntity
{
public:
    PyBrLoop(const AcRxObject* ptr);
    PyBrLoop(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrLoop() = default;

    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrLoop* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrShell
void makePyBrShellWrapper();

class PyBrShell : public PyBrEntity
{
public:
    PyBrShell(const AcRxObject* ptr);
    PyBrShell(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrShell() = default;

    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrShell* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrVertex
void makePyBrVertexWrapper();

class PyBrVertex : public PyBrEntity
{
public:
    PyBrVertex(const AcRxObject* ptr);
    PyBrVertex(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrVertex() = default;

    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrVertex* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)