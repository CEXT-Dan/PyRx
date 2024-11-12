#pragma once
#include "PyDbEntity.h"

#pragma pack (push, 8)

//-----------------------------------------------------------------------------------------
// PyBrTraverser
void makePyBrTraverserWrapper();

class PyBrTraverser : public PyRxObject
{
public:
    PyBrTraverser(const AcRxObject* ptr);
    PyBrTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrepComplexTraverser
void makePyBrepComplexTraverserWrapper();

class PyBrepComplexTraverser : public PyBrTraverser
{
public:
    PyBrepComplexTraverser(const AcRxObject* ptr);
    PyBrepComplexTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrepComplexTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrBrepComplexTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
// PyBrepEdgeTraverser
void makePyBrepEdgeTraverserWrapper();

class PyBrepEdgeTraverser : public PyBrTraverser
{
public:
    PyBrepEdgeTraverser(const AcRxObject* ptr);
    PyBrepEdgeTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrepEdgeTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrBrepEdgeTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
// PyBrepFaceTraverser
void makePyBrepFaceTraverserWrapper();

class PyBrepFaceTraverser : public PyBrTraverser
{
public:
    PyBrepFaceTraverser(const AcRxObject* ptr);
    PyBrepFaceTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrepFaceTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrBrepFaceTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrepShellTraverser
void makePyBrepShellTraverserWrapper();

class PyBrepShellTraverser : public PyBrTraverser
{
public:
    PyBrepShellTraverser(const AcRxObject* ptr);
    PyBrepShellTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrepShellTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrBrepShellTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrepVertexTraverser
void makePyBrepVertexTraverserWrapper();

class PyBrepVertexTraverser : public PyBrTraverser
{
public:
    PyBrepVertexTraverser(const AcRxObject* ptr);
    PyBrepVertexTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrepVertexTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrBrepVertexTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrComplexShellTraverser
void makePyBrComplexShellTraverserWrapper();

class PyBrComplexShellTraverser : public PyBrTraverser
{
public:
    PyBrComplexShellTraverser(const AcRxObject* ptr);
    PyBrComplexShellTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrComplexShellTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrComplexShellTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrEdgeLoopTraverser
void makePyBrEdgeLoopTraverserWrapper();

class PyBrEdgeLoopTraverser : public PyBrTraverser
{
public:
    PyBrEdgeLoopTraverser(const AcRxObject* ptr);
    PyBrEdgeLoopTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrEdgeLoopTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrEdgeLoopTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrElement2dNodeTraverser
void makePyBrElement2dNodeTraverserWrapper();

class PyBrElement2dNodeTraverser : public PyBrTraverser
{
public:
    PyBrElement2dNodeTraverser(const AcRxObject* ptr);
    PyBrElement2dNodeTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrElement2dNodeTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrElement2dNodeTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrFaceLoopTraverser
void makePyBrFaceLoopTraverserWrapper();

class PyBrFaceLoopTraverser : public PyBrTraverser
{
public:
    PyBrFaceLoopTraverser(const AcRxObject* ptr);
    PyBrFaceLoopTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrFaceLoopTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrFaceLoopTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrLoopEdgeTraverser
void makePyBrLoopEdgeTraverserWrapper();

class PyBrLoopEdgeTraverser : public PyBrTraverser
{
public:
    PyBrLoopEdgeTraverser(const AcRxObject* ptr);
    PyBrLoopEdgeTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrLoopEdgeTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrLoopEdgeTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrLoopVertexTraverser
void makePyBrLoopVertexTraverserWrapper();

class PyBrLoopVertexTraverser : public PyBrTraverser
{
public:
    PyBrLoopVertexTraverser(const AcRxObject* ptr);
    PyBrLoopVertexTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrLoopVertexTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrLoopVertexTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrMesh2dElement2dTraverser
void makePyBrMesh2dElement2dTraverserWrapper();

class PyBrMesh2dElement2dTraverser : public PyBrTraverser
{
public:
    PyBrMesh2dElement2dTraverser(const AcRxObject* ptr);
    PyBrMesh2dElement2dTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrMesh2dElement2dTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrMesh2dElement2dTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
// PyBrShellFaceTraverser
void makePyBrShellFaceTraverserWrapper();

class PyBrShellFaceTraverser : public PyBrTraverser
{
public:
    PyBrShellFaceTraverser(const AcRxObject* ptr);
    PyBrShellFaceTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrShellFaceTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrShellFaceTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
// PyBrVertexEdgeTraverser
void makePyBrVertexEdgeTraverserWrapper();

class PyBrVertexEdgeTraverser : public PyBrTraverser
{
public:
    PyBrVertexEdgeTraverser(const AcRxObject* ptr);
    PyBrVertexEdgeTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrVertexEdgeTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrVertexEdgeTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyBrVertexLoopTraverser
void makePyBrVertexLoopTraverserWrapper();

class PyBrVertexLoopTraverser : public PyBrTraverser
{
public:
    PyBrVertexLoopTraverser(const AcRxObject* ptr);
    PyBrVertexLoopTraverser(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrVertexLoopTraverser() = default;
    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrVertexLoopTraverser* impObj(const std::source_location& src = std::source_location::current()) const;
};














#pragma pack (pop)