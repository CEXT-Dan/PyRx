#pragma once

#include "PyDbEntity.h"
#pragma pack (push, 8)

class PyGeBoundBlock3d;
class PyGeLinearEnt3d;

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
    boost::python::tuple        getLineContainment(const PyGeLinearEnt3d& line, const Adesk::UInt32 numHitsWanted);

    //AcBr::ErrorStatus   getBrep(AcBrBrep& brep) const;

    void	                    setValidationLevel(const AcBr::ValidationLevel level);
    AcBr::ValidationLevel	    getValidationLevel() const;

    Adesk::Boolean		        brepChanged() const;
    boost::python::tuple        getMassProps1();
    boost::python::tuple        getMassProps2(double density, double tolRequired);

    //AcBr::ErrorStatus	getMassProps(AcBrMassProps& massProps,
    //    const double& density = *(double*)NULL,
    //    const double& tolRequired = *(double*)NULL,
    //    double& tolAchieved = *(double*)NULL) const;
    //AcBr::ErrorStatus	getVolume(double& volume,
    //    const double& tolRequired = *(double*)NULL,
    //    double& tolAchieved = *(double*)NULL) const;
    //AcBr::ErrorStatus	getSurfaceArea(double& area,
    //    const double& tolRequired = *(double*)NULL,
    //    double& tolAchieved = *(double*)NULL) const;
    //AcBr::ErrorStatus	getPerimeterLength(double& length,
    //    const double& tolRequired = *(double*)NULL,
    //    double& tolAchieved = *(double*)NULL) const;


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
    PyBrBrep(const AcRxObject* ptr);
    PyBrBrep(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrBrep() = default;

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