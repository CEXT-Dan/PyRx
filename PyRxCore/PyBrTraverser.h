#pragma once
#include "PyDbEntity.h"

#pragma pack (push, 8)

class PyGeCurve2d;
class PyGeCurve3d;

class PyBrBrep;
class PyBrEdge;
class PyBrFace;
class PyBrComplex;
class PyBrShell;
class PyBrVertex;
class PyBrLoop;
class PyBrNode;
class PyBrElement2d;

class PyBrFaceLoopTraverser;
class PyBrLoopEdgeTraverser;
class PyBrShellFaceTraverser;
class PyBrVertexEdgeTraverser;
class PyBrVertexLoopTraverser;
class PyBrMesh2dElement2dTraverser;

//-----------------------------------------------------------------------------------------
// PyBrTraverser
void makePyBrTraverserWrapper();

class PyBrTraverser : public PyRxObject
{
public:
    PyBrTraverser(const AcRxObject* ptr);
    PyBrTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrTraverser() = default;
    Adesk::Boolean          isEqualTo(const PyRxObject& other) const;
    Adesk::Boolean          isNull() const;
    bool                    done();
    void                    next();
    void                    restart();
    void	                setValidationLevel(const AcBr::ValidationLevel& validationLevel);
    AcBr::ValidationLevel   getValidationLevel() const;
    Adesk::Boolean		    brepChanged() const;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcBrTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrepComplexTraverser
void makePyBrepComplexTraverserWrapper();

class PyBrepComplexTraverser : public PyBrTraverser
{
public:
    PyBrepComplexTraverser();
    PyBrepComplexTraverser(const PyBrBrep& brep);
    PyBrepComplexTraverser(const AcBrBrepComplexTraverser& src);
    PyBrepComplexTraverser(const AcRxObject* ptr);
    PyBrepComplexTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrepComplexTraverser() = default;
    void                setBrepAndComplex(const PyBrComplex& complex);
    void                setBrep(const PyBrBrep& brep);
    PyBrBrep            getBrep() const;
    void                setComplex(const PyBrComplex& complex);
    PyBrComplex         getComplex() const;
    boost::python::list getComplexs();
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrBrepComplexTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrepEdgeTraverser
void makePyBrepEdgeTraverserWrapper();

class PyBrepEdgeTraverser : public PyBrTraverser
{
public:
    PyBrepEdgeTraverser();
    PyBrepEdgeTraverser(const PyBrBrep& brep);
    PyBrepEdgeTraverser(const AcBrBrepEdgeTraverser& src);
    PyBrepEdgeTraverser(const AcRxObject* ptr);
    PyBrepEdgeTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrepEdgeTraverser() = default;
    void                setBrepAndEdge(const PyBrEdge& edge);
    void                setBrep(const PyBrBrep& brep);
    PyBrBrep            getBrep() const;
    void                setEdge(const PyBrEdge& edge);
    PyBrEdge            getEdge() const;
    boost::python::list getEdges();
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrBrepEdgeTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrepFaceTraverser
void makePyBrepFaceTraverserWrapper();

class PyBrepFaceTraverser : public PyBrTraverser
{
public:
    PyBrepFaceTraverser();
    PyBrepFaceTraverser(const PyBrBrep& brep);
    PyBrepFaceTraverser(const AcBrBrepFaceTraverser& src);
    PyBrepFaceTraverser(const AcRxObject* ptr);
    PyBrepFaceTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrepFaceTraverser() = default;
    PyBrBrep            getBrep() const;
    void                setBrep(const PyBrBrep& brep);
    PyBrFace            getFace() const;
    void                setFace(const PyBrFace& face);
    void                setBrepAndFace(const PyBrFace& face);
    boost::python::list getFaces();
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrBrepFaceTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrepShellTraverser
void makePyBrepShellTraverserWrapper();

class PyBrepShellTraverser : public PyBrTraverser
{
public:
    PyBrepShellTraverser();
    PyBrepShellTraverser(const PyBrBrep& brep);
    PyBrepShellTraverser(const AcBrBrepShellTraverser& src);
    PyBrepShellTraverser(const AcRxObject* ptr);
    PyBrepShellTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrepShellTraverser() = default;
    void                setBrepAndShell(const PyBrShell& shell);
    void                setBrep(const PyBrBrep& brep);
    void                setShell(const PyBrShell& shell);
    PyBrBrep            getBrep() const;
    PyBrShell           getShell() const;
    boost::python::list getShells();
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrBrepShellTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrepVertexTraverser
void makePyBrepVertexTraverserWrapper();

class PyBrepVertexTraverser : public PyBrTraverser
{
public:
    PyBrepVertexTraverser();
    PyBrepVertexTraverser(const PyBrBrep& brep);
    PyBrepVertexTraverser(const AcBrBrepVertexTraverser& src);
    PyBrepVertexTraverser(const AcRxObject* ptr);
    PyBrepVertexTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrepVertexTraverser() = default;
    PyBrBrep            getBrep() const;
    PyBrVertex          getVertex() const;
    boost::python::list getVertexs();
    void                setBrepAndVertex(const PyBrVertex& vertex);
    void                setBrep(const PyBrBrep& brep);
    void                setVertex(const PyBrVertex& vertex);
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrBrepVertexTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrComplexShellTraverser
void makePyBrComplexShellTraverserWrapper();

class PyBrComplexShellTraverser : public PyBrTraverser
{
public:
    PyBrComplexShellTraverser();
    PyBrComplexShellTraverser(const AcBrComplexShellTraverser& src);
    PyBrComplexShellTraverser(const AcRxObject* ptr);
    PyBrComplexShellTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrComplexShellTraverser() = default;
    void                setComplexAndShell(const PyBrShell& shell);
    void                setComplexTraverser(const PyBrepComplexTraverser& brepcompshell);
    void                setComplex(const PyBrComplex& complex);
    PyBrComplex         getComplex() const;
    void                setShell(const PyBrShell& shell);
    PyBrShell           getShell() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrComplexShellTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrEdgeLoopTraverser
void makePyBrEdgeLoopTraverserWrapper();

class PyBrEdgeLoopTraverser : public PyBrTraverser
{
public:
    PyBrEdgeLoopTraverser();
    PyBrEdgeLoopTraverser(const AcBrEdgeLoopTraverser& src);
    PyBrEdgeLoopTraverser(const AcRxObject* ptr);
    PyBrEdgeLoopTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrEdgeLoopTraverser() = default;
    PyBrEdge            getEdge() const;
    PyBrLoop            getLoop() const;
    void                setEdgeAndLoop(const PyBrLoopEdgeTraverser& loopEdge);
    void                setVertexAndEdge(const PyBrVertexEdgeTraverser& vertexEdge);
    void                setEdge(const PyBrEdge& edge);
    void                setLoop(const PyBrLoop& loop);
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrEdgeLoopTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrElement2dNodeTraverser
void makePyBrElement2dNodeTraverserWrapper();

class PyBrElement2dNodeTraverser : public PyBrTraverser
{
public:
    PyBrElement2dNodeTraverser();
    PyBrElement2dNodeTraverser(const AcBrElement2dNodeTraverser& src);
    PyBrElement2dNodeTraverser(const AcRxObject* ptr);
    PyBrElement2dNodeTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrElement2dNodeTraverser() = default;
    void                setElementTraverser(const PyBrMesh2dElement2dTraverser& val);
    void                setElement(const PyBrElement2d& val);
    PyBrElement2d       getElement() const;
    void                setNode(const PyBrNode& val);
    PyBrNode            getNode() const;
    AcGeVector3d        getSurfaceNormal() const;
    AcGePoint2d         getParamPoint() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrElement2dNodeTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrFaceLoopTraverser
void makePyBrFaceLoopTraverserWrapper();

class PyBrFaceLoopTraverser : public PyBrTraverser
{
public:
    PyBrFaceLoopTraverser();
    PyBrFaceLoopTraverser(const AcBrFaceLoopTraverser& src);
    PyBrFaceLoopTraverser(const AcRxObject* ptr);
    PyBrFaceLoopTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrFaceLoopTraverser() = default;
    PyBrFace            getFace() const;
    PyBrLoop            getLoop() const;
    void                setFaceAndLoop(const PyBrLoop& loop);
    void                setFace(const PyBrFace& face);
    void                setLoop(const PyBrLoop& loop);
    void                setFaceTraverser(const PyBrShellFaceTraverser& shellFaceTrav);
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrFaceLoopTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrLoopEdgeTraverser
void makePyBrLoopEdgeTraverserWrapper();

class PyBrLoopEdgeTraverser : public PyBrTraverser
{
public:
    PyBrLoopEdgeTraverser();
    PyBrLoopEdgeTraverser(const AcBrLoopEdgeTraverser& src);
    PyBrLoopEdgeTraverser(const AcRxObject* ptr);
    PyBrLoopEdgeTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrLoopEdgeTraverser() = default;

    PyBrEdge            getEdge() const;
    PyBrLoop            getLoop() const;
    Adesk::Boolean      getEdgeOrientToLoop() const;
    PyGeCurve2d         getParamCurve() const;
    PyGeCurve3d	        getOrientedCurve() const;
    
    //TODO: 
    //AcBr::ErrorStatus   getParamCurveAsNurb(AcGeNurbCurve2d& nurb,
    //    const double& fitTolRequired = *(double*)NULL,
    //    double& fitTolAchieved = *(double*)NULL) const;
    
    //AcBr::ErrorStatus	getOrientedCurveAsNurb(AcGeNurbCurve3d& nurb,
    //    const double& fitTolRequired = *(double*)NULL,
    //    double& fitTolAchieved = *(double*)NULL) const;

    void                setLoopAndEdge(const PyBrEdgeLoopTraverser& edgeLoop);
    void                setLoopTraverser(const PyBrFaceLoopTraverser& faceLoop);
    void                setLoop(const PyBrLoop& loop);
    void                setEdge(const PyBrEdge& edge);

    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrLoopEdgeTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrLoopVertexTraverser
void makePyBrLoopVertexTraverserWrapper();

class PyBrLoopVertexTraverser : public PyBrTraverser
{
public:
    PyBrLoopVertexTraverser();
    PyBrLoopVertexTraverser(const AcBrLoopVertexTraverser& src);
    PyBrLoopVertexTraverser(const AcRxObject* ptr);
    PyBrLoopVertexTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrLoopVertexTraverser() = default;
    PyBrLoop            getLoop() const;
    PyBrVertex          getVertex() const;
    AcGePoint2d         getParamPoint() const;
    void	            setLoopAndVertex(const PyBrVertexLoopTraverser& vertexLoop);
    void                setLoopTraverser(const PyBrFaceLoopTraverser& faceLoop);
    void                setLoop(const PyBrLoop& loop);
    void                setVertex(const PyBrVertex& vertex);
    static PyRxClass    desc();
    static std::string  className();
public:
    AcBrLoopVertexTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrMesh2dElement2dTraverser
void makePyBrMesh2dElement2dTraverserWrapper();

class PyBrMesh2dElement2dTraverser : public PyBrTraverser
{
public:
    PyBrMesh2dElement2dTraverser(const AcRxObject* ptr);
    PyBrMesh2dElement2dTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrMesh2dElement2dTraverser() = default;

  
    //AcBr::ErrorStatus   setMeshAndElement(const AcBrElement2d& element2d);
    //AcBr::ErrorStatus   setMesh(const AcBrMesh2d& mesh2d);
    //AcBr::ErrorStatus   getMesh(AcBrMesh2d& mesh2d) const;
    //AcBr::ErrorStatus   setElement(const AcBrElement2d& element2d);
    //AcBr::ErrorStatus   getElement(AcBrElement2d& element2d) const;


    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrMesh2dElement2dTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
// PyBrShellFaceTraverser
void makePyBrShellFaceTraverserWrapper();

class PyBrShellFaceTraverser : public PyBrTraverser
{
public:
    PyBrShellFaceTraverser(const AcRxObject* ptr);
    PyBrShellFaceTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrShellFaceTraverser() = default;

    //// Queries & Initialisers
    //AcBr::ErrorStatus   setShellAndFace(const AcBrFace& face);
    //AcBr::ErrorStatus   setShell(const AcBrComplexShellTraverser& complexShellTraverser);
    //AcBr::ErrorStatus   setShell(const AcBrShell& shell);
    //AcBr::ErrorStatus   getShell(AcBrShell& shell) const;
    //AcBr::ErrorStatus   setFace(const AcBrFace& face);
    //AcBr::ErrorStatus   getFace(AcBrFace& face) const;

    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrShellFaceTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
// PyBrVertexEdgeTraverser
void makePyBrVertexEdgeTraverserWrapper();

class PyBrVertexEdgeTraverser : public PyBrTraverser
{
public:
    PyBrVertexEdgeTraverser(const AcRxObject* ptr);
    PyBrVertexEdgeTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrVertexEdgeTraverser() = default;

    //// Queries & Initialisers
    //AcBr::ErrorStatus   setVertex(const AcBrVertex& vertex);
    //AcBr::ErrorStatus   getVertex(AcBrVertex& vertex) const;
    //AcBr::ErrorStatus   setEdge(const AcBrEdge& edge);
    //AcBr::ErrorStatus   getEdge(AcBrEdge& edge) const;

    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrVertexEdgeTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrVertexLoopTraverser
void makePyBrVertexLoopTraverserWrapper();

class PyBrVertexLoopTraverser : public PyBrTraverser
{
public:
    PyBrVertexLoopTraverser(const AcRxObject* ptr);
    PyBrVertexLoopTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrVertexLoopTraverser() = default;

    //// Queries & Initialisers
    //AcBr::ErrorStatus   setVertexAndLoop(const AcBrLoopVertexTraverser& LoopVertexTraverser);
    //AcBr::ErrorStatus   setVertex(const AcBrVertex& vertex);
    //AcBr::ErrorStatus   getVertex(AcBrVertex& vertex) const;
    //AcBr::ErrorStatus   setLoop(const AcBrLoop& loop);
    //AcBr::ErrorStatus   getLoop(AcBrLoop& loop) const;


    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrVertexLoopTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)