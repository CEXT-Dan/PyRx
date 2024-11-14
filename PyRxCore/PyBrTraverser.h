#pragma once
#include "PyDbEntity.h"

#pragma pack (push, 8)

class PyBrBrep;
class PyBrEdge;
class PyBrFace;
class PyBrComplex;

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

    void        setBrepAndComplex(const PyBrComplex& complex);
    void        setBrep(const PyBrBrep& brep);
    PyBrBrep    getBrep() const;
    void        setComplex(const PyBrComplex& complex);
    PyBrComplex getComplex() const;
    boost::python::list getComplexs();

    static PyRxClass            desc();
    static std::string          className();
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

    void        setBrepAndEdge(const PyBrEdge& edge);
    void        setBrep(const PyBrBrep& brep);
    PyBrBrep    getBrep() const;
    void        setEdge(const PyBrEdge& edge);
    PyBrEdge    getEdge() const;
    boost::python::list getEdges();

    static PyRxClass            desc();
    static std::string          className();
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
    PyBrepFaceTraverser(const AcBrBrepFaceTraverser& src);
    PyBrepFaceTraverser(const AcRxObject* ptr);
    PyBrepFaceTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrepFaceTraverser() = default;

    PyBrBrep    getBrep() const;
    void        setBrep(const PyBrBrep& brep);
    PyBrFace    getFace() const;
    void        setFace(const PyBrFace& face);
    void        setBrepAndFace(const PyBrFace& face);

    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrBrepFaceTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrepShellTraverser
void makePyBrepShellTraverserWrapper();

class PyBrepShellTraverser : public PyBrTraverser
{
public:
    PyBrepShellTraverser(const AcRxObject* ptr);
    PyBrepShellTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrepShellTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrBrepShellTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrepVertexTraverser
void makePyBrepVertexTraverserWrapper();

class PyBrepVertexTraverser : public PyBrTraverser
{
public:
    PyBrepVertexTraverser(const AcRxObject* ptr);
    PyBrepVertexTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrepVertexTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrBrepVertexTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrComplexShellTraverser
void makePyBrComplexShellTraverserWrapper();

class PyBrComplexShellTraverser : public PyBrTraverser
{
public:
    PyBrComplexShellTraverser(const AcRxObject* ptr);
    PyBrComplexShellTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrComplexShellTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrComplexShellTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrEdgeLoopTraverser
void makePyBrEdgeLoopTraverserWrapper();

class PyBrEdgeLoopTraverser : public PyBrTraverser
{
public:
    PyBrEdgeLoopTraverser(const AcRxObject* ptr);
    PyBrEdgeLoopTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrEdgeLoopTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrEdgeLoopTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrElement2dNodeTraverser
void makePyBrElement2dNodeTraverserWrapper();

class PyBrElement2dNodeTraverser : public PyBrTraverser
{
public:
    PyBrElement2dNodeTraverser(const AcRxObject* ptr);
    PyBrElement2dNodeTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrElement2dNodeTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrElement2dNodeTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrFaceLoopTraverser
void makePyBrFaceLoopTraverserWrapper();

class PyBrFaceLoopTraverser : public PyBrTraverser
{
public:
    PyBrFaceLoopTraverser(const AcRxObject* ptr);
    PyBrFaceLoopTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrFaceLoopTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrFaceLoopTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrLoopEdgeTraverser
void makePyBrLoopEdgeTraverserWrapper();

class PyBrLoopEdgeTraverser : public PyBrTraverser
{
public:
    PyBrLoopEdgeTraverser(const AcRxObject* ptr);
    PyBrLoopEdgeTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrLoopEdgeTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrLoopEdgeTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrLoopVertexTraverser
void makePyBrLoopVertexTraverserWrapper();

class PyBrLoopVertexTraverser : public PyBrTraverser
{
public:
    PyBrLoopVertexTraverser(const AcRxObject* ptr);
    PyBrLoopVertexTraverser(AcRxObject* ptr, bool autoDelete);
    virtual ~PyBrLoopVertexTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
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
    static PyRxClass            desc();
    static std::string          className();
public:
    AcBrVertexLoopTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)