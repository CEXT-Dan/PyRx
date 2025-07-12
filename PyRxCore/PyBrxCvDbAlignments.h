#pragma once

#ifdef BRXAPP
#include "PyBrxCvObject.h"
#include "BrxCvCivil3dConverter.h"
#include "BrxCvDbAlignments.h"

class PyDbObjectId;
class PyDbDatabase;
class PyBrxCvDbHAlignment;
class PyBrxCvDbHAlignmentElement;
class PyBrxCvDbHAlignmentPI;
class PyBrxCvDbVAlignmentElement;
class PyBrxCvDbVAlignmentPVI;
class PyBrxCvDbVAlignmentCurve;

//-----------------------------------------------------------------------------------
//PyBrxCvCivil3dEntityInfo
void makePyBrxCvCivil3dEntityInfoWrapper();

class PyBrxCvCivil3dEntityInfo
{
    using Civil3dEntityType = BrxCvCivil3dEntityInfo::Civil3dEntityType;
    using Civil3dAlignmentType = BrxCvCivil3dEntityInfo::Civil3dAlignmentType;
    using Civil3dProfileType = BrxCvCivil3dEntityInfo::Civil3dProfileType;
public:
    PyBrxCvCivil3dEntityInfo();
    PyBrxCvCivil3dEntityInfo(const BrxCvCivil3dEntityInfo& info);
    ~PyBrxCvCivil3dEntityInfo() = default;

    bool                      isNull() const;
    std::string               name() const;
    std::string               description() const;
    PyDbObjectId              objectId() const;

    Civil3dEntityType         type() const;
    Civil3dAlignmentType      alignmentType() const;
    Civil3dProfileType        profileType() const;

    PyBrxCvCivil3dEntityInfo  baseAlignment() const;
    PyBrxCvCivil3dEntityInfo  baseSurface() const;
    boost::python::list       profiles() const;
    static std::string        className();

    inline BrxCvCivil3dEntityInfo* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr <BrxCvCivil3dEntityInfo> pimpl;
};

//-----------------------------------------------------------------------------------
//PyBrxCvCivil3dConverter
void makePyBrxCvCivil3dConverterWrapper();

class PyBrxCvCivil3dConverter
{
public:
    PyBrxCvCivil3dConverter();
    PyBrxCvCivil3dConverter(const PyDbDatabase& sourceDb, PyDbDatabase& targetDb, BrxCvCivil3dConverter::Civil3dLabels doLabels);
    bool                        isValid() const;
    boost::python::list         getCivilEntities() const;
    boost::python::list         convert(const boost::python::list& entitiesToConvert) const;
    boost::python::list         attachedLabels(const PyBrxCvCivil3dEntityInfo& civilEntity) const;
    boost::python::list         unattachedLabels() const;
    boost::python::list         getInsertedEntities() const;
    static std::string          className();
public:
    inline BrxCvCivil3dConverter* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxCvCivil3dConverter> impl;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbView
void makePyBrxCvDbViewWrapper();

class PyBrxCvDbView : public PyBrxCvDbEntity
{
public:
    PyBrxCvDbView();
    PyBrxCvDbView(const PyDbObjectId& id);
    PyBrxCvDbView(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbView(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbView(BrxCvDbView* ptr, bool autoDelete);
    virtual ~PyBrxCvDbView() override = default;

    Adesk::UInt32           graphCount() const;
    PyDbObjectId            graphAt(Adesk::UInt32 idx) const;
    bool                    removeGraph(const PyDbObjectId& idGraph) const;
    PyDbObjectId            baseHAlignment() const;
    bool                    setBaseHAlignment(const PyDbObjectId& id) const;
    AcGePoint2d             origin() const;
    bool                    setOrigin(const AcGePoint2d& pnt) const;
    double                  baseElevation() const;
    bool                    setBaseElevation(double elevation) const;
    double                  verticalScale() const;
    bool                    setVerticalScale(double vScale) const;
    double                  horizontalScale() const;
    bool                    setHorizontalScale(double hScale) const;
    double                  length() const;
    bool                    setLength(double viewLength) const;
    double                  height() const;
    bool                    setHeight(double viewHeight) const;
    bool                    addGraph(const PyDbObjectId& idGraph) const;
    double                  toWCSX(double x) const;
    double                  toWCSY(double y) const;
    AcGePoint2d             toWCSPoint2d(const AcGePoint2d& point) const;
    double                  fromWCSX(double x) const;
    double                  fromWCSY(double y) const;
    AcGePoint2d             fromWCSPoint2d(const AcGePoint2d& point) const;

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbView    cloneFrom(const PyRxObject& src);
    static PyBrxCvDbView    cast(const PyRxObject& src);
public:
    inline BrxCvDbView* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentView
void makePyBrxCvDbVAlignmentViewWrapper();

class PyBrxCvDbVAlignmentView : public PyBrxCvDbView
{
public:
    PyBrxCvDbVAlignmentView();
    PyBrxCvDbVAlignmentView(const PyDbObjectId& id);
    PyBrxCvDbVAlignmentView(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbVAlignmentView(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbVAlignmentView(BrxCvDbVAlignmentView* ptr, bool autoDelete);
    virtual ~PyBrxCvDbVAlignmentView() override = default;

    bool                    update1() const;
    bool                    update2(bool bUpdateDependencies, bool updateOrigin) const;
    static std::string      className();
    static PyRxClass        desc();

    static PyBrxCvDbVAlignmentView  cloneFrom(const PyRxObject& src);
    static PyBrxCvDbVAlignmentView  cast(const PyRxObject& src);
public:
    inline BrxCvDbVAlignmentView* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvStationEquation
void makePyBrxCvStationEquationWrapper();

class PyBrxCvStationEquation
{
    using EStationEquationType = BrxCvStationEquation::EStationEquationType;
public:
    PyBrxCvStationEquation();
    PyBrxCvStationEquation(double rawStation, double stationForward, EStationEquationType type);
    PyBrxCvStationEquation(const BrxCvStationEquation& equation);
    ~PyBrxCvStationEquation() = default;

    bool                    isNull() const;
    double                  getRawStation() const;
    double                  getStationForward() const;
    EStationEquationType    getType() const;
    bool                    setRawStation(double rawStation) const;
    bool                    setStationForward(double stationForward) const;
    bool                    setType(EStationEquationType type) const;

    static std::string      className();
public:
    inline BrxCvStationEquation* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxCvStationEquation> m_pyImp;
};

//-----------------------------------------------------------------------------------
//PyBrxCvStationEquation
void makePyBrxCvStationEquationsWrapper();

class PyBrxCvStationEquations
{
public:
    PyBrxCvStationEquations();
    PyBrxCvStationEquations(const BrxCvStationEquations& other);
    PyBrxCvStationEquations(PyBrxCvDbHAlignment& alignmentPtr);
    ~PyBrxCvStationEquations() = default;

    Adesk::UInt64       stationEquationsCount() const;
    double              getRefStartingLength() const;
    double              getRefRawStartingStation() const;
    double              getStartingStation() const;
    double              getStation(double rawStation) const;
    double              getRawStationFromLength(double length) const;
    double              getLengthFromRawStation(double rawStation) const;
    double              getStationBack(Adesk::UInt64 idx) const;
    boost::python::list getRawStation(double station) const;
    PyBrxCvStationEquation getStationEquation(Adesk::UInt64 idx) const;
    bool                setRefStartingLength(double startingStation) const;
    bool                setRefRawStartingStation(double rawStartingStation) const;
    bool                addStationEquation(const PyBrxCvStationEquation& equation) const;
    bool                removeStationEquation(Adesk::UInt64 idx) const;
    bool                removeAllStationEquations() const;
    bool                update() const;

    static std::string            className();
public:
    inline BrxCvStationEquations* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxCvStationEquations> m_pyImp;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignment
void makePyBrxCvDbHAlignmentWrapper();

class PyBrxCvDbHAlignment : public PyBrxCvDbCurve
{
    using EArcType = BrxCvDbHAlignment::EArcType;
    using EArcParameterType = BrxCvDbHAlignment::EArcParameterType;
    using ESpiralParameterType = BrxCvDbHAlignment::ESpiralParameterType;
    using ESpiralDefinitionType = BrxCvDbHAlignment::ESpiralDefinitionType;

public:
    PyBrxCvDbHAlignment();
    PyBrxCvDbHAlignment(const PyDbObjectId& id);
    PyBrxCvDbHAlignment(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbHAlignment(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbHAlignment(BrxCvDbHAlignment* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignment() override = default;

    Adesk::UInt32           verticalAlignmentCount() const;
    PyDbObjectId            verticalAlignmentAt(Adesk::UInt32 index) const;
    Adesk::UInt32           alignment3dCount() const;
    PyDbObjectId            alignment3dAt(Adesk::UInt32 index) const;
    Adesk::UInt32           verticalAlignmentViewCount() const;
    PyDbObjectId            verticalAlignmentViewAt(Adesk::UInt32 index) const;
    double                  length() const;
    size_t                  elementCount() const;

    boost::python::tuple    getStationAtPoint1(const AcGePoint2d& point) const;
    boost::python::tuple    getStationAtPoint2(const AcGePoint2d& point, double fromStation, double toStation) const;
    boost::python::tuple    getPointAtStation(double station) const;

    Adesk::UInt64           firstElementId() const;
    Adesk::UInt64           lastElementId() const;
    Adesk::UInt64           firstLineElementId() const;
    Adesk::UInt64           nextLineElementId(Adesk::UInt64 id) const;
    Adesk::UInt64           previousLineElementId(Adesk::UInt64 id) const;

    PyBrxCvDbHAlignmentElement elementAtId(Adesk::UInt64 id) const;
    PyBrxCvDbHAlignmentElement elementAtStation(double station) const;
    Adesk::UInt64              curveAtPI(const PyBrxCvDbHAlignmentPI& pi) const;
    boost::python::list        getPIsArray() const;

    boost::python::list     getUnorderedElementIds() const;
    Adesk::UInt64           getElementId(Adesk::GsMarker gsMarker) const;
    bool                    update() const;
    double                  getRadius(double param) const;

    Adesk::UInt64           addLineFixed1(Adesk::UInt64 prevId, double length) const;
    Adesk::UInt64           addLineFixed2(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint) const;
    Adesk::UInt64           addLineTo1(Adesk::UInt64 nextId, const AcGePoint2d& point) const;
    Adesk::UInt64           addLineFrom1(Adesk::UInt64 prevId, const AcGePoint2d& point) const;
    Adesk::UInt64           addLineTo2(Adesk::UInt64 nextId, double length) const;
    Adesk::UInt64           addLineFrom2(Adesk::UInt64 prevId, double length) const;
    Adesk::UInt64           addLineBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId) const;
    Adesk::UInt64           insertLineFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, Adesk::UInt64 prevId) const;
    Adesk::UInt64           addArcAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId) const;
    Adesk::UInt64           addArcFixed1(const AcGePoint2d& center, double radius, bool isClockwise) const;
    Adesk::UInt64           addArcFixed2(const AcGePoint2d& startPoint, const AcGePoint2d& midPoint, const AcGePoint2d& endPoint) const;
    Adesk::UInt64           addArcTo1(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint) const;
    Adesk::UInt64           addArcFrom1(Adesk::UInt64 prevId, const AcGePoint2d& passThroughPoint) const;
    Adesk::UInt64           addArcTo2(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint, const AcGeVector2d& direction) const;
    Adesk::UInt64           addArcFrom2(Adesk::UInt64 prevId, const AcGePoint2d& passThroughPoint, const AcGeVector2d& direction) const;

    bool                    deleteElement(Adesk::UInt64 id) const;
    Adesk::UInt32           style() const;
    bool                    setStyle(const Adesk::UInt32 style) const;

    Adesk::UInt32           elementExtensionColor() const;
    Adesk::UInt32           tangentExtensionColor() const;
    Adesk::UInt32           lineElementColor() const;
    Adesk::UInt32           curveElementColor() const;
    Adesk::UInt32           spiralElementColor() const;
    //
    bool                    setElementExtensionColor(const Adesk::UInt32 color) const;
    bool                    setTangentExtensionColor(const Adesk::UInt32 color) const;
    bool                    setLineElementColor(const Adesk::UInt32 color) const;
    bool                    setCurveElementColor(const Adesk::UInt32 color) const;
    bool                    setSpiralElementColor(const Adesk::UInt32 color) const;

    PyBrxCvStationEquations stationEquations() const;
    bool                    setStationEquations(const PyBrxCvStationEquations& stationEquations) const;

    Adesk::UInt64 addArcTo3(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint,
        double radius, bool isGreaterThan180, BrxCvDbHAlignment::EArcType arcType) const;

    Adesk::UInt64 addArcFrom3(Adesk::UInt64 previous, const AcGePoint2d& passThroughPoint,
        double radius, bool isGreaterThan180, BrxCvDbHAlignment::EArcType arcType) const;

    Adesk::UInt64 addArcTo4(Adesk::UInt64 nextId, double radius, double paramValue,
        BrxCvDbHAlignment::EArcParameterType paramType, bool isClockwise) const;

    Adesk::UInt64 addArcFrom4(Adesk::UInt64 prevId, double radius,
        double paramValue, BrxCvDbHAlignment::EArcParameterType paramType, bool isClockwise) const;

    Adesk::UInt64 addArcBetween1(Adesk::UInt64 prevId, Adesk::UInt64 nextId, const AcGePoint2d& passThrough) const;

    Adesk::UInt64 addArcBetween2(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
        double parameter, BrxCvDbHAlignment::EArcParameterType paramType,
        bool isGreaterThan180, BrxCvDbHAlignment::EArcType arcType) const;

    Adesk::UInt64 addSCSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
        double spiral1, double spiral2, BrxCvDbHAlignment::ESpiralParameterType spiralType
        , double radius, BrxCvDbHAlignment::ESpiralDefinitionType spiralDef) const;

    Adesk::UInt64 addSTSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
        double spiral1Param, double spiral2Param, BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addSSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
        double spiralRatio, BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addSpiralFrom(Adesk::UInt64 prevId, double radius,
        double length, bool isClockwise, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addSpiralTo(Adesk::UInt64 nextId, double radius, double length,
        bool isClockwise, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addSpiralBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addSTFrom1(Adesk::UInt64 prevId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        const AcGePoint2d& passThroughPoint, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addTSTo1(Adesk::UInt64 nextId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        const AcGePoint2d& passThroughPoint, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addSTFrom2(Adesk::UInt64 prevId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double tangentLength, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addTSTo2(Adesk::UInt64 nextId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double tangentLength, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addSCFrom1(Adesk::UInt64 prevId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, const AcGePoint2d& passThroughPoint,
        bool isGreaterThan180,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addCSTo1(Adesk::UInt64 nextId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, const AcGePoint2d& passThroughPoint,
        bool isGreaterThan180,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addSCFrom2(Adesk::UInt64 prevId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, double arcLength, bool isClockwise,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addCSTo2(Adesk::UInt64 nextId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, double arcLength, bool isClockwise,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addSSCFrom(Adesk::UInt64 prevId, double spiral1Param, double spiral2Param,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, const AcGePoint2d& passThroughPoint,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;

    Adesk::UInt64 addCSSTo(Adesk::UInt64 nextId, double spiral1Param, double spiral2Param,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, const AcGePoint2d& passThroughPoint,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition) const;


    Adesk::UInt64 addSCSAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId) const;

    static std::string                className();
    static PyRxClass                  desc();
    static PyBrxCvDbHAlignment        cloneFrom(const PyRxObject& src);
    static PyBrxCvDbHAlignment        cast(const PyRxObject& src);
public:
    inline BrxCvDbHAlignment* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentElement
void makePyBrxCvDbHAlignmentElementWrapper();

class PyBrxCvDbHAlignmentElement : public PyBrxCvDbSubObject
{
    using EElementType = BrxCvDbHAlignmentElement::EElementType;
    using ETangencyConstraint = BrxCvDbHAlignmentElement::ETangencyConstraint;
    using EParameterConstraint = BrxCvDbHAlignmentElement::EParameterConstraint;

public:
    PyBrxCvDbHAlignmentElement(BrxCvDbHAlignmentElement* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignmentElement() override = default;
    Adesk::UInt64           id() const;
    Adesk::UInt64           previousId() const;
    Adesk::UInt64           nextId() const;
    EElementType            type() const;
    ETangencyConstraint     tangencyConstraint() const;
    EParameterConstraint    parameterConstraint() const;
    bool                    isSubentity() const;
    bool                    setPreviousId(Adesk::UInt64 id) const;
    bool                    setNextId(Adesk::UInt64 id) const;
    bool                    setTangencyConstraint(ETangencyConstraint constraint) const;
    bool                    setParameterConstraint(EParameterConstraint constraint) const;
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbHAlignmentElement  cast(const PyRxObject& src);
public:
    inline BrxCvDbHAlignmentElement* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentPI
void makePyBrxCvDbHAlignmentPIWrapper();

class PyBrxCvDbHAlignmentPI : public PyBrxCvDbHAlignmentElement
{
public:
    PyBrxCvDbHAlignmentPI();
    PyBrxCvDbHAlignmentPI(BrxCvDbHAlignmentPI* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignmentPI() override = default;
    AcGePoint2d                 location() const;
    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbHAlignmentPI  cast(const PyRxObject& src);
public:
    inline BrxCvDbHAlignmentPI* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentCurve
void makePyBrxCvDbHAlignmentCurveWrapper();

class PyBrxCvDbHAlignmentCurve : public PyBrxCvDbHAlignmentElement
{
public:
    PyBrxCvDbHAlignmentCurve(BrxCvDbHAlignmentCurve* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignmentCurve() override = default;

    AcGePoint2d             startPoint() const;
    AcGePoint2d             endPoint() const;
    double                  startStation() const;
    double                  endStation() const;
    double                  length() const;

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbHAlignmentCurve  cast(const PyRxObject& src);
public:
    inline BrxCvDbHAlignmentCurve* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentLine
void makePyBrxCvDbHAlignmentLineWrapper();

class PyBrxCvDbHAlignmentLine : public PyBrxCvDbHAlignmentCurve
{
public:
    PyBrxCvDbHAlignmentLine();
    PyBrxCvDbHAlignmentLine(BrxCvDbHAlignmentLine* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignmentLine() override = default;

    AcGePoint2d             passThroughPoint1() const;
    AcGePoint2d             passThroughPoint2() const;
    double                  paramLength() const;
    bool                    setParamLength(double length) const;
    bool                    setPassThroughPoint1(const AcGePoint2d& point) const;
    bool                    setPassThroughPoint2(const AcGePoint2d& point) const;

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbHAlignmentLine  cast(const PyRxObject& src);
public:
    inline BrxCvDbHAlignmentLine* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
// PyBrxCvDbHAlignmentArc
void makePyBrxCvDbHAlignmentArcWrapper();

class PyBrxCvDbHAlignmentArc : public PyBrxCvDbHAlignmentCurve
{
public:
    PyBrxCvDbHAlignmentArc();
    PyBrxCvDbHAlignmentArc(BrxCvDbHAlignmentArc* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignmentArc() override = default;

    double                  radius() const;
    AcGePoint2d             center() const;
    bool                    isClockwise() const;
    bool                    setRadius(double rad) const;
    bool                    setCenter(const AcGePoint2d& center) const;
    bool                    setClockwise(bool isClockwise) const;
    bool                    isLessThan180() const;
    bool                    setLessThan180(bool isLessThan180) const;
    bool                    isCompound() const;
    bool                    setCompound(bool isCompound) const;

    AcGePoint2d             passThroughPoint1() const;
    AcGePoint2d             passThroughPoint2() const;
    AcGePoint2d             passThroughPoint3() const;
    bool                    setPassThroughPoint1(const AcGePoint2d& point) const;
    bool                    setPassThroughPoint2(const AcGePoint2d& point) const;
    bool                    setPassThroughPoint3(const AcGePoint2d& point) const;

    double                  paramLength() const;
    bool                    setParamLength(double length) const;

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbHAlignmentArc  cast(const PyRxObject& src);
public:
    inline BrxCvDbHAlignmentArc* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentSpiral
void makePyBrxCvDbHAlignmentSpiralWrapper();

class PyBrxCvDbHAlignmentSpiral : public PyBrxCvDbHAlignmentCurve
{
    using ESpiralCurveType = BrxCvDbHAlignmentSpiral::ESpiralCurveType;
    using ESpiralDefinitionType = BrxCvDbHAlignmentSpiral::ESpiralDefinitionType;

public:
    PyBrxCvDbHAlignmentSpiral();
    PyBrxCvDbHAlignmentSpiral(BrxCvDbHAlignmentSpiral* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignmentSpiral() override = default;

    double                  radiusIn() const;
    double                  radiusOut() const;
    bool                    isCompound() const;
    ESpiralCurveType        spiralCurveType() const;
    bool                    isClockwise() const;
    ESpiralDefinitionType   spiralDefinition() const;
    double                  startDirection() const;
    double                  endDirection() const;
    double                  paramA() const;
    double                  paramLength() const;
    bool                    setRadiusIn(double rad) const;
    bool                    setRadiusOut(double rad) const;
    bool                    setCompound(bool isCompound) const;
    bool                    setClockwise(bool isClockwise) const;
    bool                    setSpiralCurveType(ESpiralCurveType spiralCurveType) const;
    bool                    setSpiralDefinition(ESpiralDefinitionType spiralCurveDefinition) const;
    bool                    setStartDirection(double direction) const;
    bool                    setEndDirection(double direction) const;
    bool                    setParamA(double paramA) const;
    bool                    setParamLength(double paramLength) const;

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbHAlignmentSpiral  cast(const PyRxObject& src);
public:
    inline BrxCvDbHAlignmentSpiral* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentSCS
void makePyBrxCvDbHAlignmentSCSWrapper();

class PyBrxCvDbHAlignmentSCS : public PyBrxCvDbHAlignmentCurve
{
public:
    PyBrxCvDbHAlignmentSCS();
    PyBrxCvDbHAlignmentSCS(BrxCvDbHAlignmentSCS* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignmentSCS() override = default;
    PyBrxCvDbHAlignmentArc      arc() const;
    PyBrxCvDbHAlignmentSpiral   spiralIn() const;
    PyBrxCvDbHAlignmentSpiral   spiralOut() const;
    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbHAlignmentSCS  cast(const PyRxObject& src);
public:
    inline BrxCvDbHAlignmentSCS* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentSTS
void makePyBrxCvDbHAlignmentSTSWrapper();

class PyBrxCvDbHAlignmentSTS : public PyBrxCvDbHAlignmentCurve
{
public:
    PyBrxCvDbHAlignmentSTS();
    PyBrxCvDbHAlignmentSTS(BrxCvDbHAlignmentSTS* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignmentSTS() override = default;

    PyBrxCvDbHAlignmentLine     line() const;
    PyBrxCvDbHAlignmentSpiral   spiralIn() const;
    PyBrxCvDbHAlignmentSpiral   spiralOut() const;
    double                      spiralRatio() const;
    ;
    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbHAlignmentSTS  cast(const PyRxObject& src);
public:
    inline BrxCvDbHAlignmentSTS* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbHAlignmentSSCSS
void makePyBrxCvDbHAlignmentSSCSSWrapper();

class PyBrxCvDbHAlignmentSSCSS : public PyBrxCvDbHAlignmentCurve
{
public:
    PyBrxCvDbHAlignmentSSCSS();
    PyBrxCvDbHAlignmentSSCSS(BrxCvDbHAlignmentSSCSS* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignmentSSCSS() override = default;

    PyBrxCvDbHAlignmentArc      arc() const;
    PyBrxCvDbHAlignmentSpiral   spiral1() const;
    PyBrxCvDbHAlignmentSpiral   spiral2() const;
    PyBrxCvDbHAlignmentSpiral   spiral3() const;
    PyBrxCvDbHAlignmentSpiral   spiral4() const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbHAlignmentSSCSS  cast(const PyRxObject& src);
public:
    inline BrxCvDbHAlignmentSSCSS* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignment
void makePyBrxCvDbVAlignmentWrapper();

class PyBrxCvDbVAlignment : public PyBrxCvDbCurve
{
public:
    PyBrxCvDbVAlignment();
    PyBrxCvDbVAlignment(const PyDbObjectId& id);
    PyBrxCvDbVAlignment(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbVAlignment(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbVAlignment(BrxCvDbVAlignment* ptr, bool autoDelete);
    virtual ~PyBrxCvDbVAlignment() override = default;

    PyDbObjectId                baseHAlignment() const;
    PyDbObjectId                baseSurface() const;
    double                      elevationMin() const;
    double                      elevationMax() const;
    boost::python::tuple        getElevationAt(double station) const;
    double                      length() const;
    size_t                      elementCount() const;
    BrxCvDbVAlignment::EVAlignmentType type() const;
    Adesk::UInt64               firstElementId() const;
    Adesk::UInt64               lastElementId() const;
    Adesk::UInt64               firstTangentElementId() const;
    Adesk::UInt64               nextTangentElementId(Adesk::UInt64 id) const;
    Adesk::UInt64               previousTangentElementId(Adesk::UInt64 id) const;
    PyBrxCvDbVAlignmentElement  elementAtId(Adesk::UInt64 id) const;
    Adesk::UInt64               curveAtPVI(const PyBrxCvDbVAlignmentPVI& pvi) const;
    PyBrxCvDbVAlignmentPVI      pviAtCurve(const PyBrxCvDbVAlignmentCurve& curve) const;
    boost::python::list         getPVIsArrays() const;
    boost::python::list         getUnorderedElementIds() const;
    Adesk::UInt64               getElementId(Adesk::GsMarker gsMarker) const;
    double                      getRadius(double param) const;
    boost::python::list         getElevations() const;
    Adesk::UInt32               style() const;
    Adesk::UInt32               tangentPolygonColor() const;
    Adesk::UInt32               lineElementColor() const;
    Adesk::UInt32               curveElementColor() const;
    bool                        setBaseHAlignment(const PyDbObjectId& id) const;
    bool                        setBaseSurface(const PyDbObjectId& id) const;
    bool                        setType(const BrxCvDbVAlignment::EVAlignmentType type) const;
    bool                        setStyle(Adesk::UInt32 style) const;
    bool                        setTangentPolygonColor(Adesk::UInt32 color) const;
    bool                        setLineElementColor(Adesk::UInt32 color) const;
    bool                        setCurveElementColor(Adesk::UInt32 color) const;
    Adesk::UInt64               addTangentFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint) const;
    Adesk::UInt64               insertTangentFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, Adesk::UInt64 prevId) const;
    Adesk::UInt64               addArcBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double radius) const;
    Adesk::UInt64               addArcAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId) const;
    Adesk::UInt64               addParabolaBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double radius) const;
    Adesk::UInt64               addParabolaAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId) const;
    bool                        deleteElement(Adesk::UInt64 id) const;
    bool                        update(bool updateDependencies) const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbVAlignment  cloneFrom(const PyRxObject& src);
    static PyBrxCvDbVAlignment  cast(const PyRxObject& src);
public:
    inline BrxCvDbVAlignment* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentElement
void makePyBrxCvDbVAlignmentElementWrapper();

class PyBrxCvDbVAlignmentElement : public PyBrxCvDbSubObject
{
protected:
    using EElementType = BrxCvDbVAlignmentElement::EElementType;
    using ETangencyConstraint = BrxCvDbVAlignmentElement::ETangencyConstraint;
    using EParameterConstraint = BrxCvDbVAlignmentElement::EParameterConstraint;
public:
    PyBrxCvDbVAlignmentElement(BrxCvDbVAlignmentElement* ptr, bool autoDelete);
    virtual ~PyBrxCvDbVAlignmentElement() override = default;

    Adesk::UInt64       id() const;
    Adesk::UInt64       previousId() const;
    Adesk::UInt64       nextId() const;
    EElementType        type() const;
    ETangencyConstraint tangencyConstraint() const;
    EParameterConstraint parameterConstraint() const;
    bool                setPreviousId(Adesk::UInt64 id) const;
    bool                setNextId(Adesk::UInt64 id) const;
    bool                setTangencyConstraint(ETangencyConstraint constraint) const;
    bool                setParameterConstraint(EParameterConstraint constraint) const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbVAlignmentElement  cast(const PyRxObject& src);
public:
    inline BrxCvDbVAlignmentElement* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentPVI
void makePyBrxCvDbVAlignmentPVIWrapper();

class PyBrxCvDbVAlignmentPVI : public PyBrxCvDbVAlignmentElement
{
public:
    PyBrxCvDbVAlignmentPVI();
    PyBrxCvDbVAlignmentPVI(BrxCvDbVAlignmentPVI* ptr, bool autoDelete);
    virtual ~PyBrxCvDbVAlignmentPVI() override = default;
    AcGePoint2d                 location() const;
    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbVAlignmentPVI  cast(const PyRxObject& src);
public:
    inline BrxCvDbVAlignmentPVI* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//BrxCvDbVAlignmentCurve
void makePyBrxCvDbVAlignmentCurveWrapper();

class PyBrxCvDbVAlignmentCurve : public PyBrxCvDbVAlignmentElement
{
public:
    PyBrxCvDbVAlignmentCurve(BrxCvDbVAlignmentCurve* ptr, bool autoDelete);
    virtual ~PyBrxCvDbVAlignmentCurve() override = default;

    AcGePoint2d     startPoint() const;
    AcGePoint2d     endPoint() const;
    double          length() const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbVAlignmentCurve  cast(const PyRxObject& src);
public:
    inline BrxCvDbVAlignmentCurve* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentTangent
void makePyBrxCvDbVAlignmentTangentWrapper();

class PyBrxCvDbVAlignmentTangent : public PyBrxCvDbVAlignmentCurve
{
public:
    PyBrxCvDbVAlignmentTangent();
    PyBrxCvDbVAlignmentTangent(BrxCvDbVAlignmentTangent* ptr, bool autoDelete);
    virtual ~PyBrxCvDbVAlignmentTangent() override = default;

    AcGePoint2d     passThroughPoint1() const;
    AcGePoint2d     passThroughPoint2() const;
    bool            setPassThroughPoint1(const AcGePoint2d& point) const;
    bool            setPassThroughPoint2(const AcGePoint2d& point) const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbVAlignmentTangent  cast(const PyRxObject& src);
public:
    inline BrxCvDbVAlignmentTangent* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentArc
void makePyBrxCvDbVAlignmentArcWrapper();

class PyBrxCvDbVAlignmentArc : public PyBrxCvDbVAlignmentCurve
{
public:
    PyBrxCvDbVAlignmentArc();
    PyBrxCvDbVAlignmentArc(BrxCvDbVAlignmentArc* ptr, bool autoDelete);
    virtual ~PyBrxCvDbVAlignmentArc() override = default;

    double          radius() const;
    double          gradeIn() const;
    double          gradeOut() const;
    AcGePoint2d     center() const;
    bool            isClockwise() const;
    bool            setRadius(double rad) const;
    bool            setCenter(const AcGePoint2d& center) const;
    bool            setClockwise(bool isClockwise) const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbVAlignmentArc  cast(const PyRxObject& src);
public:
    inline BrxCvDbVAlignmentArc* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbVAlignmentParabola
void makePyBrxCvDbVAlignmentParabolaWrapper();

class PyBrxCvDbVAlignmentParabola : public PyBrxCvDbVAlignmentCurve
{
public:
    PyBrxCvDbVAlignmentParabola();
    PyBrxCvDbVAlignmentParabola(BrxCvDbVAlignmentParabola* ptr, bool autoDelete);
    virtual ~PyBrxCvDbVAlignmentParabola() override = default;

    double  radius() const;
    double  gradeIn() const;
    double  gradeOut() const;
    bool    setRadius(double rad) const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbVAlignmentParabola  cast(const PyRxObject& src);
public:
    inline BrxCvDbVAlignmentParabola* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDb3dAlignment
void makePyBrxCvDb3dAlignmentWrapper();

class PyBrxCvDb3dAlignment : public PyBrxCvDbCurve
{
public:
    PyBrxCvDb3dAlignment();
    PyBrxCvDb3dAlignment(const PyDbObjectId& id);
    PyBrxCvDb3dAlignment(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDb3dAlignment(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDb3dAlignment(BrxCvDb3dAlignment* ptr, bool autoDelete);
    virtual ~PyBrxCvDb3dAlignment() override = default;

    PyDbObjectId                baseHAlignment() const;
    PyDbObjectId                vAlignment() const;
    double                      length() const;
    boost::python::list         getPointsArray() const;
    bool                        setBaseHAlignment(const PyDbObjectId& id) const;
    bool                        setVAlignment(const PyDbObjectId& id) const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDb3dAlignment cloneFrom(const PyRxObject& src);
    static PyBrxCvDb3dAlignment cast(const PyRxObject& src);

public:
    inline BrxCvDb3dAlignment* impObj(const std::source_location& src = std::source_location::current()) const;
};


#endif//BRXAPP

