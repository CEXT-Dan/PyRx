#pragma once

#ifdef BRXAPP

#include "PyBrxCvObject.h"
#include "BrxCvDbTinSurfaceDefinition.h"

class PyGeLineSeg2d;
class PyDbEntity;
class PyDbObjectId;


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

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionDeleteEdge
void makePyBrxCvDbTinSurfaceDefinitionDeleteEdgeWrapper();

class PyBrxCvDbTinSurfaceDefinitionDeleteEdge : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionDeleteEdge();
    PyBrxCvDbTinSurfaceDefinitionDeleteEdge(const AcGePoint2d& mtx);
    PyBrxCvDbTinSurfaceDefinitionDeleteEdge(BrxCvDbTinSurfaceDefinitionDeleteEdge* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionDeleteEdge() override = default;
    AcGePoint2d             position() const;
    bool                    setPosition(const AcGePoint2d& position);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionDeleteEdge cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionDeleteEdge* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionDeleteEdges
void makePyBrxCvDbTinSurfaceDefinitionDeleteEdgesWrapper();

class PyBrxCvDbTinSurfaceDefinitionDeleteEdges : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionDeleteEdges();
    PyBrxCvDbTinSurfaceDefinitionDeleteEdges(BrxCvDbTinSurfaceDefinitionDeleteEdges* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionDeleteEdges() override = default;

    Adesk::UInt32        polygonsCount() const;
    boost::python::tuple polygonAt(const Adesk::UInt32 index) const;
    bool                 addPolygon(const boost::python::list& edgePolygon, bool includeIntersected);
    bool                 removePolygonAt(const Adesk::UInt32 index);
    bool                 removeAllPolygons();

    static std::string  className();
    static PyRxClass    desc();
    static PyBrxCvDbTinSurfaceDefinitionDeleteEdges cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionDeleteEdges* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddLine
void makePyBrxCvDbTinSurfaceDefinitionAddLineWrapper();

class PyBrxCvDbTinSurfaceDefinitionAddLine : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionAddLine();
    PyBrxCvDbTinSurfaceDefinitionAddLine(const AcGeLineSeg2d& mtx);
    PyBrxCvDbTinSurfaceDefinitionAddLine(BrxCvDbTinSurfaceDefinitionAddLine* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionAddLine() override = default;
    PyGeLineSeg2d           line() const;
    bool                    setLine(const PyGeLineSeg2d& line);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionAddLine cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionAddLine* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddLines
void makePyBrxCvDbTinSurfaceDefinitionAddLinesWrapper();

class PyBrxCvDbTinSurfaceDefinitionAddLines : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionAddLines();
    PyBrxCvDbTinSurfaceDefinitionAddLines(const boost::python::list& mtx);
    PyBrxCvDbTinSurfaceDefinitionAddLines(BrxCvDbTinSurfaceDefinitionAddLines* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionAddLines() override = default;
    boost::python::list lines() const;
    bool                setLines(const boost::python::list& line);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionAddLines cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionAddLines* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionModifyPointElevation
void makePyBrxCvDbTinSurfaceDefinitionModifyPointElevationWrapper();

class PyBrxCvDbTinSurfaceDefinitionModifyPointElevation : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionModifyPointElevation();
    PyBrxCvDbTinSurfaceDefinitionModifyPointElevation(const AcGePoint2d& pt, double elevation, bool isDeltaElevation);
    PyBrxCvDbTinSurfaceDefinitionModifyPointElevation(BrxCvDbTinSurfaceDefinitionModifyPointElevation* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionModifyPointElevation() override = default;
    AcGePoint2d             position() const;
    bool                    setPosition(const AcGePoint2d& position);
    double                  elevation() const;
    bool                    setElevation(double elevation);
    bool                    isDeltaElevation() const;
    bool                    setIsDeltaElevation(const bool isDeltaElevation);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionModifyPointElevation cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionModifyPointElevation* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation
void makePyBrxCvDbTinSurfaceDefinitionModifyPointsElevationWrapper();

class PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation();
    PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation(const boost::python::list& pos, double elevation, bool isDeltaElevation);
    PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation(BrxCvDbTinSurfaceDefinitionModifyPointsElevation* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation() override = default;
    boost::python::list     positions() const;
    bool                    setPositions(const boost::python::list& position);
    double                  elevation() const;
    bool                    setElevation(double elevation);
    bool                    isDeltaElevation() const;
    bool                    setIsDeltaElevation(bool isDeltaElevation);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionModifyPointsElevation cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionModifyPointsElevation* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations
void makePyBrxCvDbTinSurfaceDefinitionModifyPointsElevationsWrapper();

class PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations();
    PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations(BrxCvDbTinSurfaceDefinitionModifyPointsElevations* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations() override = default;

    Adesk::UInt32           pointElevationsCount() const;
    boost::python::tuple    pointElevationAt(const Adesk::UInt32 index) const;
    bool                    addPointElevation(const AcGePoint2d& position, double elevation);
    bool                    removePointElevationAt(const Adesk::UInt32 index);
    bool                    removeAllPointElevations();

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionModifyPointsElevations cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionModifyPointsElevations* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionCreateFromFaces
void makePyBrxCvDbTinSurfaceDefinitionCreateFromFacesWrapper();

class PyBrxCvDbTinSurfaceDefinitionCreateFromFaces : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionCreateFromFaces();
    PyBrxCvDbTinSurfaceDefinitionCreateFromFaces(const boost::python::list& pnt, bool applyEdgesVisibility);
    PyBrxCvDbTinSurfaceDefinitionCreateFromFaces(BrxCvDbTinSurfaceDefinitionCreateFromFaces* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionCreateFromFaces() override = default;

    Adesk::UInt32           facesCount() const;
    boost::python::tuple    faceAt(const Adesk::UInt32 index) const;
    boost::python::list     points() const;
    bool                    isApplyEdgesVisibility() const;
    bool                    setIsApplyEdgesVisibility(bool isApplyEdges);

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionCreateFromFaces cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionCreateFromFaces* impObj(const std::source_location& src = std::source_location::current()) const;
};

//PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects
void makePyBrxCvDbTinSurfaceDefinitionAddDrawingObjectsWrapper();

class PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects : public PyBrxCvDbTinSurfaceDefinition
{
    using EDrawingObjectType = BrxCvDbTinSurfaceDefinitionAddDrawingObjects::EDrawingObjectType;
    using ETinIntersectionElevation = BrxCvDbTinSurfaceDefinitionAddDrawingObjects::ETinIntersectionElevation;
public:
    PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects();
    PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects(const boost::python::list& ents, double midOrdinateDistance, bool applyEdges, ETinIntersectionElevation crossingsElevation);
    PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects(BrxCvDbTinSurfaceDefinitionAddDrawingObjects* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects() override = default;

    bool                 addEntity(const PyDbEntity& pEntity);
    bool                 addEntityId(const PyDbObjectId& entityId);
    Adesk::UInt32        drawingObjectsCount() const;
    boost::python::tuple drawingObjectAt(const Adesk::UInt32 index) const;
    ETinIntersectionElevation crossingsElevation() const;
    bool                 setCrossingsElevation(const ETinIntersectionElevation crossingsElevation);
    bool                 isApplyEdges() const;
    bool                 setIsApplyEdges(bool isApplyEdges);
    bool                 removeDrawingObjectAt(const Adesk::UInt32 index);
    bool                 removeAllDrawingObjects();

    static std::string   className();
    static PyRxClass     desc();
    static PyBrxCvDbTinSurfaceDefinitionAddDrawingObjects cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionAddDrawingObjects* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionRiseLower
void makePyBrxCvDbTinSurfaceDefinitionRiseLowerWrapper();

class PyBrxCvDbTinSurfaceDefinitionRiseLower : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionRiseLower();
    PyBrxCvDbTinSurfaceDefinitionRiseLower(double mtx);
    PyBrxCvDbTinSurfaceDefinitionRiseLower(BrxCvDbTinSurfaceDefinitionRiseLower* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionRiseLower() override = default;
    double                  offset() const;
    bool                    setOffset(double offset);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionRiseLower cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionRiseLower* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML
void makePyBrxCvDbTinSurfaceDefinitionCreateFromLandXMLWrapper();

class PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML();
    PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML(const std::string& path, const std::string& name, AcDb::UnitsValue dwgUnits, bool scaleToDwgUnits);
    PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML(BrxCvDbTinSurfaceDefinitionCreateFromLandXML* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML() override = default;

    std::string         filePath() const;
    bool                setFilePath(const std::string& filePath);
    std::string         surfaceName() const;
    bool                setSurfaceName(const std::string& surfaceName);
    bool                scaleToDwgUnits() const;
    bool                setScaleToDwgUnits(bool scaleToDwgUnits);
    AcDb::UnitsValue    dwgUnits() const;
    bool                setDwgUnits(const AcDb::UnitsValue dwgUnits);

    static std::string  className();
    static PyRxClass    desc();
    static PyBrxCvDbTinSurfaceDefinitionCreateFromLandXML cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionCreateFromLandXML* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddFromFiles
void makePyBrxCvDbTinSurfaceDefinitionAddFromFilesWrapper();

class PyBrxCvDbTinSurfaceDefinitionAddFromFiles : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionAddFromFiles();
    PyBrxCvDbTinSurfaceDefinitionAddFromFiles(const boost::python::list& paths, const PyDbObjectId& fileFormatId);
    PyBrxCvDbTinSurfaceDefinitionAddFromFiles(BrxCvDbTinSurfaceDefinitionAddFromFiles* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionAddFromFiles() override = default;

    boost::python::list filesPaths() const;
    bool                setFilesPaths(const boost::python::list& filesPaths);

    PyDbObjectId        fileFormatId() const;
    bool                setFileFormatId(const PyDbObjectId& fileFormatId);

    //BrxCvSurfaceDensifyPtr densify();
    //BrxCvSurfaceSimplifyPtr simplify();

    static std::string  className();
    static PyRxClass    desc();
    static PyBrxCvDbTinSurfaceDefinitionAddFromFiles cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionAddFromFiles* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds
void makePyBrxCvDbTinSurfaceDefinitionAddFromPointCloudsWrapper();

class PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds();
    PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds(const boost::python::list& ids);
    PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds(BrxCvDbTinSurfaceDefinitionAddFromPointClouds* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds() override = default;

    boost::python::list pcObjectIds() const;
    bool                setPcObjectIds(const boost::python::list& pcObjectIds);

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionAddFromPointClouds cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionAddFromPointClouds* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionAddPointGroups
void makePyBrxCvDbTinSurfaceDefinitionAddPointGroupsWrapper();

class PyBrxCvDbTinSurfaceDefinitionAddPointGroups : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionAddPointGroups();
    PyBrxCvDbTinSurfaceDefinitionAddPointGroups(const boost::python::list& ids);
    PyBrxCvDbTinSurfaceDefinitionAddPointGroups(BrxCvDbTinSurfaceDefinitionAddPointGroups* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionAddPointGroups() override = default;
    boost::python::list     pointGroupsIds() const;
    bool                    setPointGroupsIds(const boost::python::list& pointGroupsIds);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbTinSurfaceDefinitionAddPointGroups cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionAddPointGroups* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionCreateFromC3D
void makePyBrxCvDbTinSurfaceDefinitionCreateFromC3DWrapper();

class PyBrxCvDbTinSurfaceDefinitionCreateFromC3D : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionCreateFromC3D();
    PyBrxCvDbTinSurfaceDefinitionCreateFromC3D(const std::string& path, const std::string& name);
    PyBrxCvDbTinSurfaceDefinitionCreateFromC3D(BrxCvDbTinSurfaceDefinitionCreateFromC3D* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionCreateFromC3D() override = default;
    std::string        filePath() const;
    bool               setFilePath(const std::string& filePath);
    std::string        surfaceName() const;
    bool               setSurfaceName(const std::string& surfaceName);
    static std::string className();
    static PyRxClass   desc();
    static PyBrxCvDbTinSurfaceDefinitionCreateFromC3D cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionCreateFromC3D* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges
void makePyBrxCvDbTinSurfaceDefinitionRemoveOuterEdgesWrapper();

class PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges();
    PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges(bool useMinLength, double minLength, bool useMaxLength, double maxLength, bool useMaxAdjAngle, double maxAdjAngle);
    PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges(BrxCvDbTinSurfaceDefinitionRemoveOuterEdges* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges() override = default;

    bool                useMaxEdgeLength() const;
    bool                setUseMaxEdgeLength(bool useMaxEdgeLength);
    double              maxEdgeLength() const;
    bool                setMaxEdgeLength(double maxEdgeLength);
    bool                useMinEdgeLength() const;
    bool                setUseMinEdgeLength(bool useMinEdgeLength);
    double              minEdgeLength() const;
    bool                setMinEdgeLength(double minEdgeLength);
    bool                useMaxAdjAngle() const;
    bool                setUseMaxAdjAngle(bool useMaxAdjAngle);
    double              maxAdjAngle() const;
    bool                setMaxAdjAngle(double maxAdjAngle);

    static std::string  className();
    static PyRxClass    desc();
    static PyBrxCvDbTinSurfaceDefinitionRemoveOuterEdges cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionRemoveOuterEdges* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility
void makePyBrxCvDbTinSurfaceDefinitionTrianglesVisibilityWrapper();

class PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility();
    PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility(const boost::python::list& positions, bool visible);
    PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility(BrxCvDbTinSurfaceDefinitionTrianglesVisibility* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility() override = default;

    boost::python::list positions() const;
    bool                setPositions(const boost::python::list& positions);
    bool                visible() const;
    bool                setVisible(bool visible);

    static std::string  className();
    static PyRxClass    desc();
    static PyBrxCvDbTinSurfaceDefinitionTrianglesVisibility cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionTrianglesVisibility* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceDefinitionRemoveElevations
void makePyBrxCvDbTinSurfaceDefinitionRemoveElevationsWrapper();

class PyBrxCvDbTinSurfaceDefinitionRemoveElevations : public PyBrxCvDbTinSurfaceDefinition
{
public:
    PyBrxCvDbTinSurfaceDefinitionRemoveElevations();
    PyBrxCvDbTinSurfaceDefinitionRemoveElevations(bool removeBelow, double removeBelowElevation, bool removeAbove, double removeAboveElevation);
    PyBrxCvDbTinSurfaceDefinitionRemoveElevations(BrxCvDbTinSurfaceDefinitionRemoveElevations* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurfaceDefinitionRemoveElevations() override = default;
    bool                removeBelow() const;
    bool                setRemoveBelow(bool removeBelow);
    double              removeBelowElevation() const;
    bool                setRemoveBelowElevation(double removeBelowElevation);
    bool                removeAbove() const;
    bool                setRemoveAbove(bool removeAbove);
    double              removeAboveElevation() const;
    bool                setRemoveAboveElevation(double removeAboveElevation);
    Adesk::UInt32       removedPointsCount() const;
    static std::string  className();
    static PyRxClass    desc();
    static PyBrxCvDbTinSurfaceDefinitionRemoveElevations cast(const PyRxObject& src);

public:
    inline BrxCvDbTinSurfaceDefinitionRemoveElevations* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif //BRXAPP
