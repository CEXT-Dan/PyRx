#pragma once

#include "PyBrxCvObject.h"
#include "BrxCvDbTinSurfaceDefinition.h"

#ifdef BRXAPP

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinition
void makePyBrxCvDbTinSurfaceDefinitionWrapper();

class PyBrxCvDbTinSurfaceDefinition : public PyBrxCvDbSubObject
{
    using EType = BrxCvDbTinSurfaceDefinition::EType;
public:
    PyBrxCvDbTinSurfaceDefinition(BrxCvDbTinSurfaceDefinition* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinition() override = default;
    std::string             name() const;
    bool                    setName(const std::string& szName);
    std::string             description() const;
    bool                    setDescription(const std::string& szDescription);
    EType                   type() const;
    bool                    isUpdateNeeded() const;
    bool                    isSubDefinition() const;
    bool                    isValid() const;
    bool                    isEnabled() const;
    bool                    setEnabled(const bool enabled);
    bool                    isReadOnly() const;
    bool                    setReadOnly(const bool readOnly);
    Adesk::UInt64           id() const;
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinition cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinition* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionGroupDefs
void makePyBrxCvDbTinSurfaceDefinitionGroupDefsWrapper();

class PyBrxCvDbTinSurfaceDefinitionGroupDefs : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionGroupDefs();
    PyBrxCvDbTinSurfaceDefinitionGroupDefs(BrxCvDbTinSurfaceDefinitionGroupDefs* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionGroupDefs() override = default;
    Adesk::UInt32           numSubDefinitions() const;
    Adesk::UInt32           findSubDefinition(const Adesk::UInt64 definitionId) const;
    Adesk::UInt32           addSubDefinition(const PyBrxCvDbTinSurfaceDefinition& subDefinition);
    PyBrxCvDbTinSurfaceDefinition getSubDefinitionAt(const Adesk::UInt32 index) const;
    bool                    removeSubDefinitionAt(const Adesk::UInt32 index);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionGroupDefs cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionGroupDefs* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionTransform
void makePyBrxCvDbTinSurfaceDefinitionTransformWrapper();

class PyBrxCvDbTinSurfaceDefinitionTransform : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionTransform();
    PyBrxCvDbTinSurfaceDefinitionTransform(const AcGeMatrix3d& mtx);
    PyBrxCvDbTinSurfaceDefinitionTransform(BrxCvDbTinSurfaceDefinitionTransform* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionTransform() override = default;
    AcGeMatrix3d            transformationMatrix() const;
    bool                    setTransformationMatrix(const AcGeMatrix3d& mtx);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionTransform cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionTransform* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddPoint
void makePyBrxCvDbTinSurfaceDefinitionAddPointWrapper();

class PyBrxCvDbTinSurfaceDefinitionAddPoint : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionAddPoint();
    PyBrxCvDbTinSurfaceDefinitionAddPoint(const AcGePoint3d& mtx);
    PyBrxCvDbTinSurfaceDefinitionAddPoint(BrxCvDbTinSurfaceDefinitionAddPoint* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionAddPoint() override = default;
    AcGePoint3d             position() const;
    bool                    setPosition(const AcGePoint3d& position);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionAddPoint cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionAddPoint* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddPoint
void makePyBrxCvDbTinSurfaceDefinitionAddPointsWrapper();

class PyBrxCvDbTinSurfaceDefinitionAddPoints : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionAddPoints();
    PyBrxCvDbTinSurfaceDefinitionAddPoints(const boost::python::list& positions);
    PyBrxCvDbTinSurfaceDefinitionAddPoints(BrxCvDbTinSurfaceDefinitionAddPoints* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionAddPoints() override = default;
    boost::python::list     positions() const;
    bool                    setPositions(const boost::python::list& positions);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionAddPoints cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionAddPoints* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionDeletePoint
void makePyBrxCvDbTinSurfaceDefinitionDeletePointWrapper();

class PyBrxCvDbTinSurfaceDefinitionDeletePoint : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionDeletePoint();
    PyBrxCvDbTinSurfaceDefinitionDeletePoint(const AcGePoint2d& mtx);
    PyBrxCvDbTinSurfaceDefinitionDeletePoint(BrxCvDbTinSurfaceDefinitionDeletePoint* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionDeletePoint() override = default;
    AcGePoint2d             position() const;
    bool                    setPosition(const AcGePoint2d& position);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionDeletePoint cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionDeletePoint* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionDeletePoint
void makePyBrxCvDbTinSurfaceDefinitionDeletePointsWrapper();

class PyBrxCvDbTinSurfaceDefinitionDeletePoints : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionDeletePoints();
    PyBrxCvDbTinSurfaceDefinitionDeletePoints(const boost::python::list& positions);
    PyBrxCvDbTinSurfaceDefinitionDeletePoints(BrxCvDbTinSurfaceDefinitionDeletePoints* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionDeletePoints() override = default;
    boost::python::list     positions() const;
    bool                    setPositions(const boost::python::list& positions);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionDeletePoints cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionDeletePoints* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionSwapEdge
void makePyBrxCvDbTinSurfaceDefinitionSwapEdgeWrapper();

class PyBrxCvDbTinSurfaceDefinitionSwapEdge : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionSwapEdge();
    PyBrxCvDbTinSurfaceDefinitionSwapEdge(const AcGePoint2d& mtx);
    PyBrxCvDbTinSurfaceDefinitionSwapEdge(BrxCvDbTinSurfaceDefinitionSwapEdge* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionSwapEdge() override = default;
    AcGePoint2d             position() const;
    bool                    setPosition(const AcGePoint2d& position);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionSwapEdge cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionSwapEdge* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionMovePoint
void makePyBrxCvDbTinSurfaceDefinitionMovePointWrapper();

class PyBrxCvDbTinSurfaceDefinitionMovePoint : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionMovePoint();
    PyBrxCvDbTinSurfaceDefinitionMovePoint(const AcGePoint2d& from, const AcGePoint2d& to);
    PyBrxCvDbTinSurfaceDefinitionMovePoint(BrxCvDbTinSurfaceDefinitionMovePoint* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionMovePoint() override = default;

    AcGePoint2d             fromPosition() const;
    bool                    setFromPosition(const AcGePoint2d& fromPoint);
    AcGePoint2d             toPosition() const;
    bool                    setToPosition(const AcGePoint2d& toPoint);

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionMovePoint cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionMovePoint* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionMovePoints
void makePyBrxCvDbTinSurfaceDefinitionMovePointsWrapper();

class PyBrxCvDbTinSurfaceDefinitionMovePoints : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionMovePoints();
    PyBrxCvDbTinSurfaceDefinitionMovePoints(const boost::python::list& from, const AcGeVector2d& displacement);
    PyBrxCvDbTinSurfaceDefinitionMovePoints(BrxCvDbTinSurfaceDefinitionMovePoints* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionMovePoints() override = default;

    boost::python::list fromPoints() const;
    bool                setFromPoints(const boost::python::list& fromPoints);
    AcGeVector2d        displacement() const;
    bool                setDisplacement(const AcGeVector2d& displacement);

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionMovePoints cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionMovePoints* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif //BRXAPP
