#pragma once

#include "PyDbEntity.h"
#pragma pack (push, 8)

class PyGeBoundBlock3d;
class PyGeLinearEnt3d;
class PyGeCurve3d;
class PyGeExternalCurve3d;
class PyDb3dSolid;
class PyDbSurface;
class PyGeSurface;
class PyBrEntity;
class PyBrComplex;
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
    virtual ~PyBrHit() = default;
    Adesk::Boolean          isEqualTo(const PyRxObject& other) const;
    Adesk::Boolean          isNull() const;
    PyBrEntity              getEntityHit() const;
    PyBrEntity              getEntityEntered() const;
    PyBrEntity              getEntityAssociated() const;
    AcGePoint3d             getPoint() const;
    void	                setValidationLevel(const AcBr::ValidationLevel& validationLevel);
    AcBr::ValidationLevel   getValidationLevel() const;
    Adesk::Boolean		    brepChanged() const;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcBrHit* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrEntity
void makePyBrEntityWrapper();

class PyBrEntity : public PyRxObject
{
public:
    PyBrEntity(const AcRxObject* ptr);
    PyBrEntity(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrEntity() = default;
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
    AcBrEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrBrep
void makePyBrBrepWrapper();

class PyBrBrep : public PyBrEntity
{
public:
    PyBrBrep();
    PyBrBrep(const PyDbEntity& ent);
    PyBrBrep(const AcBrBrep& src);
    PyBrBrep(const AcRxObject* ptr);
    PyBrBrep(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrBrep() = default;
    void	            set(const PyDbEntity& entity);
    PyDb3dSolid         getSolid();
    PyDbSurface	        getSurface() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrBrep* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PyBrComplex() = default;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrComplex* impObj(const std::source_location& src = std::source_location::current()) const;
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
    ~PyBrEdge() = default;
    AcGe::EntityId  getCurveType() const;
    PyGeExternalCurve3d getCurve() const;
    Adesk::Boolean  getOrientToCurve() const;
    PyBrVertex      getVertex1() const;
    PyBrVertex      getVertex2() const;

    //TODO requires AcGeNurbCurve3d wrapper
    //AcBr::ErrorStatus getCurveAsNurb(AcGeNurbCurve3d& nurb, const double* fitTolRequired = NULL,  double* fitTolAchieved = NULL) const;

    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrEdge* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PyBrFace() = default;
    AcGe::EntityId          getSurfaceType() const;
    PyGeSurface             getSurface() const;
    Adesk::Boolean          getOrientToSurface() const;
    double                  getArea();
    boost::python::tuple    getAreaWithTol(double tolRequired);
    PyBrShell               getShell() const;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcBrFace* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PyBrLoop() = default;
    PyBrFace            getFace() const;
    AcBr::LoopType      getType() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrLoop* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PyBrShell() = default;
    PyBrComplex         getComplex() const;
    AcBr::ShellType     getType() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrShell* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PyBrVertex() = default;
    AcGePoint3d         getPoint() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrVertex* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrMeshEntity
void makePyBrMeshEntityWrapper();

class PyBrMeshEntity : public PyRxObject
{
public:
    PyBrMeshEntity(const AcRxObject* ptr);
    PyBrMeshEntity(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrMeshEntity() = default;
    Adesk::Boolean          isEqualTo(const PyRxObject& other) const;
    Adesk::Boolean          isNull() const;
    PyBrEntity              getEntityAssociated() const;
    void	                setValidationLevel(const AcBr::ValidationLevel& validationLevel);
    AcBr::ValidationLevel   getValidationLevel() const;
    Adesk::Boolean		    brepChanged() const;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcBrMeshEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrElement
void makePyBrElementWrapper();

class PyBrElement : public PyBrMeshEntity
{
public:
    PyBrElement(const AcRxObject* ptr);
    PyBrElement(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrElement() = default;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrElement* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrElement2d
void makePyBrElement2dWrapper();

class PyBrElement2d : public PyBrElement
{
public:
    PyBrElement2d(const AcRxObject* ptr);
    PyBrElement2d(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrElement2d() = default;
    AcGeVector3d        getNormal() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrElement2d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrMesh
void makePyBrMeshWrapper();

class PyBrMesh : public PyBrMeshEntity
{
public:
    PyBrMesh(const AcRxObject* ptr);
    PyBrMesh(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrMesh() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrMesh* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrMesh2d
void makePyBrMesh2dWrapper();

class PyBrMesh2d : public PyBrMesh
{
public:
    PyBrMesh2d(const AcRxObject* ptr);
    PyBrMesh2d(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrMesh2d() = default;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcBrMesh2d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrNode
void makePyBrNodeWrapper();

class PyBrNode : public PyBrMeshEntity
{
public:
    PyBrNode();
    PyBrNode(const AcBrNode& src);
    PyBrNode(const AcRxObject* ptr);
    PyBrNode(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrNode() = default;
    AcGePoint3d         getPoint() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrNode* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)