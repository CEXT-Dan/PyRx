#pragma once

#ifdef BRXAPP
#include "PyDbCurve.h"
#include "BrxCvDbObject.h"
#include "BrxCvDbEntity.h"
#include "BrxCvDbCurve.h"
#include "BrxCvCivil3dConverter.h"
#include "BrxCvDbAlignments.h"

class PyDbObjectId;
class PyDbDatabase;
class PyBrxCvDbHAlignment;
class PyBrxCvDbHAlignmentElement;
class PyBrxCvDbHAlignmentPI;

//-----------------------------------------------------------------------------------
//PyBrxCvDbSubObject
void makePyBrxCvDbSubObjectWrapper();

class PyBrxCvDbSubObject : public PyRxObject
{
public:

    PyBrxCvDbSubObject(BrxCvDbSubObject* ptr, bool autoDelete);
    virtual ~PyBrxCvDbSubObject() override = default;

    std::string             name() const;
    bool                    setName(const std::string& szName);
    std::string             description() const;
    bool                    setDescription(const std::string& szDescription);
    static std::string      className();
    static PyRxClass        desc();

public:
    inline BrxCvDbSubObject* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbObject
void makePyBrxCvDbObjectWrapper();

class PyBrxCvDbObject : public PyDbObject
{
public:
    PyBrxCvDbObject(const PyDbObjectId& id);
    PyBrxCvDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbObject(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbObject(BrxCvDbObject* ptr, bool autoDelete);
    virtual ~PyBrxCvDbObject() override = default;

    std::string                 name() const;
    bool                        setName(const std::string& szName);
    std::string                 description() const;
    bool                        setDescription(const std::string& szDescription);

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbObject      cloneFrom(const PyRxObject& src);
    static PyBrxCvDbObject      cast(const PyRxObject& src);

public:
    inline BrxCvDbObject* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbEntity
void makePyBrxCvDbEntityWrapper();

class PyBrxCvDbEntity : public PyDbEntity
{
public:
    PyBrxCvDbEntity(const PyDbObjectId& id);
    PyBrxCvDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbEntity(BrxCvDbEntity* ptr, bool autoDelete);
    virtual ~PyBrxCvDbEntity() override = default;

    std::string             name() const;
    bool                    setName(const std::string& szName);
    std::string             description() const;
    bool                    setDescription(const std::string& szDescription);

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbEntity  cloneFrom(const PyRxObject& src);
    static PyBrxCvDbEntity  cast(const PyRxObject& src);
public:
    inline BrxCvDbEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbCurve
void makePyBrxCvDbCurveWrapper();

class PyBrxCvDbCurve : public PyDbCurve
{
public:
    PyBrxCvDbCurve(const PyDbObjectId& id);
    PyBrxCvDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbCurve(BrxCvDbCurve* ptr, bool autoDelete);
    virtual ~PyBrxCvDbCurve() override = default;

    std::string                 name() const;
    bool                        setName(const std::string& szName);
    std::string                 description() const;
    bool                        setDescription(const std::string& szDescription);

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbCurve       cloneFrom(const PyRxObject& src);
    static PyBrxCvDbCurve       cast(const PyRxObject& src);

public:
    inline BrxCvDbCurve* impObj(const std::source_location& src = std::source_location::current()) const;
};


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
    boost::python::list         convert(const boost::python::list& entitiesToConvert);
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
    bool                    removeGraph(const PyDbObjectId& idGraph);
    PyDbObjectId            baseHAlignment() const;
    bool                    setBaseHAlignment(const PyDbObjectId& id);
    AcGePoint2d             origin() const;
    bool                    setOrigin(const AcGePoint2d& pnt);
    double                  baseElevation() const;
    bool                    setBaseElevation(double elevation);
    double                  verticalScale() const;
    bool                    setVerticalScale(double vScale);
    double                  horizontalScale() const;
    bool                    setHorizontalScale(double hScale);
    double                  length() const;
    bool                    setLength(double viewLength);
    double                  height() const;
    bool                    setHeight(double viewHeight);
    bool                    addGraph(const PyDbObjectId& idGraph);
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

    bool                    update1();
    bool                    update2(bool bUpdateDependencies, bool updateOrigin);
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
    bool                    setRawStation(double rawStation);
    bool                    setStationForward(double stationForward);
    bool                    setType(EStationEquationType type);

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
    double              getStationBack(Adesk::UInt64 idx);
    boost::python::list getRawStation(double station) const;
    PyBrxCvStationEquation getStationEquation(Adesk::UInt64 idx) const;
    bool                setRefStartingLength(double startingStation);
    bool                setRefRawStartingStation(double rawStartingStation);
    bool                addStationEquation(const PyBrxCvStationEquation& equation);
    bool                removeStationEquation(Adesk::UInt64 idx);
    bool                removeAllStationEquations();
    bool                update();

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
    boost::python::tuple    getPointAtStation(const double station) const;

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
    bool                    update();
    double                  getRadius(double param) const;

    Adesk::UInt64           addLineFixed1(Adesk::UInt64 prevId, double length);
    Adesk::UInt64           addLineFixed2(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint);
    Adesk::UInt64           addLineTo1(Adesk::UInt64 nextId, const AcGePoint2d& point);
    Adesk::UInt64           addLineFrom1(Adesk::UInt64 prevId, const AcGePoint2d& point);
    Adesk::UInt64           addLineTo2(Adesk::UInt64 nextId, double length);
    Adesk::UInt64           addLineFrom2(Adesk::UInt64 prevId, double length);
    Adesk::UInt64           addLineBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId);
    Adesk::UInt64           insertLineFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, Adesk::UInt64 prevId);
    Adesk::UInt64           addArcAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId);
    Adesk::UInt64           addArcFixed1(const AcGePoint2d& center, double radius, bool isClockwise);
    Adesk::UInt64           addArcFixed2(const AcGePoint2d& startPoint, const AcGePoint2d& midPoint, const AcGePoint2d& endPoint);
    Adesk::UInt64           addArcTo1(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint);
    Adesk::UInt64           addArcFrom1(Adesk::UInt64 prevId, const AcGePoint2d& passThroughPoint);
    Adesk::UInt64           addArcTo2(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint, const AcGeVector2d& direction);
    Adesk::UInt64           addArcFrom2(Adesk::UInt64 prevId, const AcGePoint2d& passThroughPoint, const AcGeVector2d& direction);

    bool                    deleteElement(Adesk::UInt64 id);
    Adesk::UInt32           style() const;
    bool                    setStyle(const Adesk::UInt32 style);

    Adesk::UInt32           elementExtensionColor() const;
    Adesk::UInt32           tangentExtensionColor() const;
    Adesk::UInt32           lineElementColor() const;
    Adesk::UInt32           curveElementColor() const;
    Adesk::UInt32           spiralElementColor() const;
    //
    bool                    setElementExtensionColor(const Adesk::UInt32 color);
    bool                    setTangentExtensionColor(const Adesk::UInt32 color);
    bool                    setLineElementColor(const Adesk::UInt32 color);
    bool                    setCurveElementColor(const Adesk::UInt32 color);
    bool                    setSpiralElementColor(const Adesk::UInt32 color);

    PyBrxCvStationEquations stationEquations() const;
    bool                    setStationEquations(const PyBrxCvStationEquations& stationEquations);

    Adesk::UInt64 addArcTo3(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint,
        double radius, bool isGreaterThan180, BrxCvDbHAlignment::EArcType arcType);

    Adesk::UInt64 addArcFrom3(Adesk::UInt64 previous, const AcGePoint2d& passThroughPoint,
        double radius, bool isGreaterThan180, BrxCvDbHAlignment::EArcType arcType);

    Adesk::UInt64 addArcTo4(Adesk::UInt64 nextId, double radius, double paramValue,
        BrxCvDbHAlignment::EArcParameterType paramType, bool isClockwise);

    Adesk::UInt64 addArcFrom4(Adesk::UInt64 prevId, double radius,
        double paramValue, BrxCvDbHAlignment::EArcParameterType paramType, bool isClockwise);

    Adesk::UInt64 addArcBetween1(Adesk::UInt64 prevId, Adesk::UInt64 nextId, const AcGePoint2d& passThrough);

    Adesk::UInt64 addArcBetween2(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
        double parameter, BrxCvDbHAlignment::EArcParameterType paramType,
        bool isGreaterThan180, BrxCvDbHAlignment::EArcType arcType);

    Adesk::UInt64 addSCSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
        double spiral1, double spiral2, BrxCvDbHAlignment::ESpiralParameterType spiralType
        , double radius, BrxCvDbHAlignment::ESpiralDefinitionType spiralDef);

    Adesk::UInt64 addSTSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double spiral1Param,
        double spiral2Param, BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addSSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
        double spiralRatio, BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addSpiralFrom(Adesk::UInt64 prevId, double radius,
        double length, bool isClockwise, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addSpiralTo(Adesk::UInt64 nextId, double radius, double length,
        bool isClockwise, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addSpiralBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addSTFrom1(Adesk::UInt64 prevId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        const AcGePoint2d& passThroughPoint, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addTSTo1(Adesk::UInt64 nextId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        const AcGePoint2d& passThroughPoint, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addSTFrom2(Adesk::UInt64 prevId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double tangentLength, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addTSTo2(Adesk::UInt64 nextId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double tangentLength, BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addSCFrom1(Adesk::UInt64 prevId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, const AcGePoint2d& passThroughPoint,
        bool isGreaterThan180,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addCSTo1(Adesk::UInt64 nextId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, const AcGePoint2d& passThroughPoint,
        bool isGreaterThan180,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addSCFrom2(Adesk::UInt64 prevId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, double arcLength, bool isClockwise,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addCSTo2(Adesk::UInt64 nextId, double spiralParam,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, double arcLength, bool isClockwise,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addSSCFrom(Adesk::UInt64 prevId, double spiral1Param, double spiral2Param,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, const AcGePoint2d& passThroughPoint,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);

    Adesk::UInt64 addCSSTo(Adesk::UInt64 nextId, double spiral1Param, double spiral2Param,
        BrxCvDbHAlignment::ESpiralParameterType spiralParamType,
        double radius, const AcGePoint2d& passThroughPoint,
        BrxCvDbHAlignment::ESpiralDefinitionType spiralDefinition);


    Adesk::UInt64 addSCSAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId);

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
    PyBrxCvDbHAlignmentElement(const BrxCvDbHAlignmentElement& ref);
    PyBrxCvDbHAlignmentElement(BrxCvDbHAlignmentElement* ptr, bool autoDelete);
    virtual ~PyBrxCvDbHAlignmentElement() override = default;
    Adesk::UInt64           id() const;
    Adesk::UInt64           previousId() const;
    Adesk::UInt64           nextId() const;
    EElementType            type() const;
    ETangencyConstraint     tangencyConstraint() const;
    EParameterConstraint    parameterConstraint() const;
    bool                    isSubentity() const;
    bool                    setPreviousId(Adesk::UInt64 id);
    bool                    setNextId(Adesk::UInt64 id);
    bool                    setTangencyConstraint(ETangencyConstraint constraint);
    bool                    setParameterConstraint(EParameterConstraint constraint);
    static std::string      className();
    static PyRxClass        desc();
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

    AcGePoint2d             passThroughPoint1();
    AcGePoint2d             passThroughPoint2();
    double                  paramLength() const;
    bool                    setParamLength(double length);
    bool                    setPassThroughPoint1(const AcGePoint2d& point);
    bool                    setPassThroughPoint2(const AcGePoint2d& point);

    static std::string      className();
    static PyRxClass        desc();
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
    bool                    setRadius(double rad);
    bool                    setCenter(const AcGePoint2d& center);
    bool                    setClockwise(bool isClockwise);
    bool                    isLessThan180() const;
    bool                    setLessThan180(bool isLessThan180);
    bool                    isCompound() const;
    bool                    setCompound(bool isCompound);

    AcGePoint2d             passThroughPoint1() const;
    AcGePoint2d             passThroughPoint2() const;
    AcGePoint2d             passThroughPoint3() const;
    bool                    setPassThroughPoint1(const AcGePoint2d& point);
    bool                    setPassThroughPoint2(const AcGePoint2d& point);
    bool                    setPassThroughPoint3(const AcGePoint2d& point);

    double                  paramLength() const;
    bool                    setParamLength(double length);

    static std::string      className();
    static PyRxClass        desc();
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
    bool                    setRadiusIn(double rad);
    bool                    setRadiusOut(double rad);
    bool                    setCompound(bool isCompound);
    bool                    setClockwise(bool isClockwise);
    bool                    setSpiralCurveType(ESpiralCurveType spiralCurveType);
    bool                    setSpiralDefinition(ESpiralDefinitionType spiralCurveDefinition);
    bool                    setStartDirection(double direction);
    bool                    setEndDirection(double direction);
    bool                    setParamA(double paramA);
    bool                    setParamLength(double paramLength);

    static std::string      className();
    static PyRxClass        desc();
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
public:
    inline BrxCvDbHAlignmentSSCSS* impObj(const std::source_location& src = std::source_location::current()) const;
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
    bool                setPreviousId(Adesk::UInt64 id);
    bool                setNextId(Adesk::UInt64 id);
    bool                setTangencyConstraint(ETangencyConstraint constraint);
    bool                setParameterConstraint(EParameterConstraint constraint);

    static std::string          className();
    static PyRxClass            desc();
public:
    inline BrxCvDbVAlignmentElement* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif//BRXAPP

