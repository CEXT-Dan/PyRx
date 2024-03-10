#pragma once

#include "BrxCvDbTinSurface.h"
#include "PyBrxCvObject.h"

class PyDbCurve;
class PyDbObjectId;
class PyBrxCvGradingRule;
class PyBrxCvDbTinSurfaceDefinition;

//-----------------------------------------------------------------------------------
//helpers
inline boost::python::list TinPointArrayToPyList(const BrxCvTinPointArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

inline BrxCvTinPointArray PyListToTinPointArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<BrxCvTinPoint>(iterable);
    BrxCvTinPointArray arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item);
    return arr;
}

inline boost::python::list TriangleArrayToPyList(const BrxCvTinTriangleArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

inline BrxCvTinTriangleArray PyListToTriangleArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<BrxCvTinTriangle>(iterable);
    BrxCvTinTriangleArray arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item);
    return arr;
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceConstraint
void makePyBrxCvDbTinSurfaceConstraintWrapper();

class PyBrxCvDbTinSurfaceConstraint
{
public:
    PyBrxCvDbTinSurfaceConstraint();
    PyBrxCvDbTinSurfaceConstraint(BrxCvDbTinSurfaceConstraint::ETinConstraintType type);
    PyBrxCvDbTinSurfaceConstraint(const BrxCvDbTinSurfaceConstraint& other);
    PyBrxCvDbTinSurfaceConstraint(BrxCvDbTinSurfaceConstraint* ptr);
    virtual ~PyBrxCvDbTinSurfaceConstraint() = default;

    BrxCvDbTinSurfaceConstraint::ETinConstraintType constraintType() const;
    void                setData1(Adesk::UInt64 id, const boost::python::list& points);
    void                setData2(const PyDbObjectId& id, double midOrdinateDist);
    boost::python::list data() const;
    Adesk::UInt64       id() const;
    void                setMidOrdinateDistance(double midOrdinateDist);
    double              midOrdinateDistance() const;
    void                setIsDbResident(bool isResident);
    bool                isDbResident() const;

    static std::string  className();
public:
    inline BrxCvDbTinSurfaceConstraint* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxCvDbTinSurfaceConstraint> m_pyImp;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceBreakline
void makePyBrxCvDbTinSurfaceBreaklineWrapper();

class PyBrxCvDbTinSurfaceBreakline : public PyBrxCvDbTinSurfaceConstraint
{
public:
    PyBrxCvDbTinSurfaceBreakline(BrxCvDbTinSurfaceBreakline::ETinBreaklineType type);
    BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation intersectionElevation() const;
    void setIntersectionElevation(const BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation elevationType);
    static std::string  className();
public:
    inline BrxCvDbTinSurfaceBreakline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceWall
void makePyBrxCvDbTinSurfaceWallWrapper();

class PyBrxCvDbTinSurfaceWall : public PyBrxCvDbTinSurfaceConstraint
{
public:
    PyBrxCvDbTinSurfaceWall(BrxCvDbTinSurfaceWall::ETinWallType wallType);
    virtual ~PyBrxCvDbTinSurfaceWall() override = default;
    BrxCvDbTinSurfaceWall::ETinWallType wallType() const;
    BrxCvDbTinSurfaceWall::ETinWallSide wallSide() const;
    double              height() const;
    void                setHeight(double height);
    void                setWallSide(BrxCvDbTinSurfaceWall::ETinWallSide side);
    static std::string  className();
public:
    inline BrxCvDbTinSurfaceWall* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceBoundary
void makePyBrxCvDbTinSurfaceBoundaryWrapper();

class PyBrxCvDbTinSurfaceBoundary : public PyBrxCvDbTinSurfaceConstraint
{
public:
    PyBrxCvDbTinSurfaceBoundary(BrxCvDbTinSurfaceBoundary::ETinBoundaryType boundaryType);
    virtual ~PyBrxCvDbTinSurfaceBoundary() override = default;
    BrxCvDbTinSurfaceBoundary::ETinBoundaryType boundaryType() const;
    static std::string  className();
public:
    inline BrxCvDbTinSurfaceBoundary* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurface
void makePyBrxCvDbTinSurfaceWrapper();

class PyBrxCvDbTinSurface : public PyBrxCvDbEntity
{
public:
    PyBrxCvDbTinSurface();
    PyBrxCvDbTinSurface(const PyDbObjectId& id);
    PyBrxCvDbTinSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbTinSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbTinSurface(BrxCvDbTinSurface* ptr, bool autoDelete);
    virtual ~PyBrxCvDbTinSurface() override = default;

    void                initialize(const AcGePoint3d& minPt, const AcGePoint3d& maxPt, const size_t numOfPoints);
    void                updateObjectData();
    bool                addPoint(const AcGePoint3d& point);
    bool                addPoints(const boost::python::list& points);
    bool                removePoint(const AcGePoint3d& point);
    bool                removePoints(const boost::python::list& points);
    bool                movePoint(const AcGePoint3d& from, const AcGePoint3d& to);
    bool                movePoints(const boost::python::list& from, const boost::python::list& to);
    bool                swapEdge(const AcGePoint3d& atPoint);
    bool                setStyle(const BrxCvDbTinSurface::ETinSurfaceStyle style);
    bool                setAssociative(bool isAssociative);
    bool                raiseSurface(double offset);
    bool                setSurfaceElevation(double elevation);
    bool                changePointsElevations(const boost::python::list& points, const boost::python::list& newZValues);
    bool                setMinorContoursInterval(double interval);
    bool                setMajorContoursInterval(double interval);
    bool                setMinorContoursColor(Adesk::UInt16 colorIndex);
    bool                setMajorContoursColor(Adesk::UInt16 colorIndex);
    bool                merge(const PyBrxCvDbTinSurface& theOther);
    boost::python::list getPoints(bool visibleOnly) const;
    boost::python::list getTinPoints() const;
    boost::python::tuple findTinPointAt(const AcGePoint3d& pnt) const;
    boost::python::list triangles(bool visibleOnly) const;
    boost::python::list tinTriangles() const;
    boost::python::list findTinTrianglesAt(const AcGePoint3d& pnt) const;
    size_t              pointsCount(bool visibleOnly) const;
    size_t              trianglesCount(bool visibleOnly) const;
    double              area2d(bool visibleOnly) const;
    double              area3d(bool visibleOnly) const;
    double              minElevation(bool visibleOnly) const;
    double              maxElevation(bool visibleOnly) const;
    bool                contains(const AcGePoint3d& point) const;
    boost::python::tuple elevationAtPoint(const AcGePoint3d& point) const;
    AcGePoint3d         closestPointTo(const AcGePoint3d& point) const;
    boost::python::tuple boundingBox() const;
    boost::python::list getPointsInsidePolygon(const boost::python::list& polygon, bool includeOnEdge) const;
    BrxCvDbTinSurface::ETinSurfaceStyle style() const;
    bool                isAssociative() const;
    boost::python::list getBorders() const;
    boost::python::tuple minorContoursInterval();
    boost::python::tuple majorContoursInterval();
    boost::python::tuple minorContoursColor() const;
    boost::python::tuple majorContoursColor() const;
    boost::python::list  minorContours() const;
    boost::python::list  majorContours() const;
    boost::python::list  contoursAtElevation(double elevation) const;

    //AcDbSubDMesh* subDMesh(const ETinSurfaceMeshType surfaceType, const double depthOrElevation) const;
    //AcDbSubDMesh* subDMesh(const BrxCvDbTinSurface* other) const;
    //AcDbSubDMesh* subDMesh() const;
    //AcDb3dSolid* solid3d(const ETinSurfaceSolidType solidType, const double thickness) const;
    //AcDb3dSolid* solid3d(const BrxCvDbTinSurface* other) const;

    boost::python::list drapePoint(const AcGePoint3dArray& points) const;
    boost::python::list drapeId(const PyDbObjectId& entId) const;
    boost::python::tuple intersectionsWithLine(const AcGePoint3d& ptLineStart, const AcGePoint3d& ptLineEnd, BrxCvDbTinSurface::ETinSurfaceIntersectType type, bool visibleOnly) const;

    //TODO: test ownership
    boost::python::list getConstraints() const;
    PyBrxCvDbTinSurfaceConstraint getConstraint1(const Adesk::UInt64 id) const;
    PyBrxCvDbTinSurfaceConstraint getConstraint2(const PyDbObjectId& id) const;

    bool                addConstraint(const PyBrxCvDbTinSurfaceConstraint& constraint, bool addReactor);
    bool                addConstraints(const boost::python::list& constraints, bool addReactor);
    bool                updateConstraint(const PyBrxCvDbTinSurfaceConstraint& constraint);
    bool                eraseConstraint1(const Adesk::UInt64 id, bool removeReactor);
    bool                eraseConstraint2(const PyDbObjectId& entityId, bool removeReactor);
    bool                eraseConstraints(const boost::python::list& ids, bool removeReactor);
    bool                eraseConstraintsIds(const boost::python::list& ids, bool removeReactor);
    bool                hasSnapshot() const;
    bool                isSnapshotUpdateNeeded() const;
    Adesk::UInt32       createSnapshot();
    bool                rebuildSnapshot();
    bool                removeSnapshot();
    bool                isUpdateNeeded() const;
    bool                isRebuildPossible() const;
    bool                rebuild(bool rebuildSnapshotIfNeeded);
    bool                isAutoUpdate() const;
    bool                setIsAutoUpdate(bool autoUpdateOn);

    Adesk::UInt32       definitionCount() const;
    Adesk::UInt32       addDefinition(const PyBrxCvDbTinSurfaceDefinition& surfaceDefinition);
    Adesk::UInt32       insertDefinitionAt(Adesk::UInt32 index, const PyBrxCvDbTinSurfaceDefinition& surfaceDefinition);
    boost::python::tuple definitionIndex(const PyBrxCvDbTinSurfaceDefinition& surfaceDefinition) const;
    PyBrxCvDbTinSurfaceDefinition definitionAt(Adesk::UInt32 index) const;
    PyBrxCvDbTinSurfaceDefinition findDefinition(Adesk::UInt64 definitionId) const;
    Adesk::UInt32       moveDefinition(const Adesk::UInt32 fromIndex, const Adesk::UInt32 toIndex);
    bool                removeDefinitionAt(const Adesk::UInt32 index);
    Adesk::UInt32       removeAllDefinitions();


    static PyBrxCvDbTinSurface  mergeSurfaces(const PyBrxCvDbTinSurface& theOne, const PyBrxCvDbTinSurface& theOther);
    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbTinSurface  cloneFrom(const PyRxObject& src);
    static PyBrxCvDbTinSurface  cast(const PyRxObject& src);
public:
    inline BrxCvDbTinSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbVolumeSurface
void makePyBrxCvDbVolumeSurfaceWrapper();

class PyBrxCvDbVolumeSurface : public PyBrxCvDbTinSurface
{
public:
    PyBrxCvDbVolumeSurface();
    PyBrxCvDbVolumeSurface(const PyDbObjectId& id);
    PyBrxCvDbVolumeSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbVolumeSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbVolumeSurface(BrxCvDbVolumeSurface* ptr, bool autoDelete);
    virtual ~PyBrxCvDbVolumeSurface() override = default;

    bool initialize1(const PyBrxCvDbTinSurface& baseSurface,
        const PyBrxCvDbTinSurface& compSurface,
        const boost::python::list& boundingPolygon);

    bool initialize2(const PyBrxCvDbTinSurface& baseSurface,
        const PyBrxCvDbTinSurface& compSurface,
        const PyDbObjectId& boundingPolygonId,
        double midOrdinateDist);

    bool initialize3(const PyBrxCvDbTinSurface& baseSurface,
        double referenceElevation, BrxCvDbVolumeSurface::EVolumeSurfaceType type,
        const  boost::python::list& boundingPolygon);

    bool initialize4(const PyBrxCvDbTinSurface& baseSurface,
        double referenceElevation, BrxCvDbVolumeSurface::EVolumeSurfaceType type,
        const PyDbObjectId& boundingPolygonId,
        double midOrdinateDist);

    BrxCvDbVolumeSurface::EVolumeSurfaceType type() const;

    PyDbObjectId        baseSurfaceObjectId() const;
    PyDbObjectId        comparisonSurfaceObjectId() const;
    PyDbObjectId        boundingPolygonObjectId() const;
    boost::python::list boundingPolygon() const;

    double              fillVolume() const;
    double              cutVolume() const;
    double              depthElevation() const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbVolumeSurface  cloneFrom(const PyRxObject& src);
    static PyBrxCvDbVolumeSurface  cast(const PyRxObject& src);
public:
    inline BrxCvDbVolumeSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbGrading
void makePyBrxCvDbGradingWrapper();

class PyBrxCvDbGrading : public PyBrxCvDbTinSurface
{
public:
    PyBrxCvDbGrading();
    PyBrxCvDbGrading(const PyDbObjectId& id);
    PyBrxCvDbGrading(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbGrading(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbGrading(BrxCvDbGrading* ptr, bool autoDelete);
    virtual ~PyBrxCvDbGrading() override = default;

    BrxCvDbGrading::EGradingStatus update(bool forceUpdate);
    BrxCvDbGrading::EGradingStatus setInputDataId(const PyDbObjectId& id);
    BrxCvDbGrading::EGradingStatus setInputData(const PyDbCurve& pCurve);
    PyDbObjectId                getInputEntityId() const;
    PyBrxCvGradingRule          rule() const;
    BrxCvDbGrading::EGradingStatus  setRule(const PyBrxCvGradingRule& rule) const;
    bool                        isClosed() const;
    PyDbObjectId                targetSurface() const;
    boost::python::list         resultDayLight() const;
    PyGeCurve3d                 getCalculationCurve() const;

    BrxCvDbGrading::EGradingCalculationMethod getCalculationMethod() const;
    bool              setCalculationMethod(BrxCvDbGrading::EGradingCalculationMethod method);

    double            getRegionStart() const;
    BrxCvDbGrading::EGradingStatus    setRegionStart(double startParam);

    double            getRegionEnd() const;
    BrxCvDbGrading::EGradingStatus    setRegionEnd(double endParam);

    bool              getIsDrawInfill() const;
    BrxCvDbGrading::EGradingStatus    setDrawInfill(bool drawInfill);

    double            getSegmentMaxLength() const;
    BrxCvDbGrading::EGradingStatus    setSegmentMaxLength(double maxLength);

    double            getSegmentMaxAngle() const;
    BrxCvDbGrading::EGradingStatus    setSegmentMaxAngle(double maxAngle);

    double            getMidOrdinateDist() const;
    BrxCvDbGrading::EGradingStatus    setMidOrdinateDist(double midOrdinateDist);

    bool              getIsAssociative() const;
    bool              setIsAssociative(bool associative);

    BrxCvDbGrading::EGradingVisualStyle getGradingVisualStyle() const;
    bool              setGradingVisualStyle(BrxCvDbGrading::EGradingVisualStyle style);

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbGrading     cloneFrom(const PyRxObject& src);
    static PyBrxCvDbGrading     cast(const PyRxObject& src);
public:
    inline BrxCvDbGrading* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvGradingRule
void makePyBrxCvGradingRuleWrapper();

class PyBrxCvGradingRule
{
public:
    PyBrxCvGradingRule();
    PyBrxCvGradingRule(const BrxCvGradingRule& other);
    PyBrxCvGradingRule(BrxCvGradingRule* ptr);
    virtual ~PyBrxCvGradingRule() = default;
    bool                      release();
    bool                      isNull() const;
    BrxCvGradingRule::EGradingType type() const;
    BrxCvGradingRule::EGradingSlopeFormat slopeFormat() const;
    bool                      setSlopeFormat(BrxCvGradingRule::EGradingSlopeFormat format);
    BrxCvGradingRule::EGradingSide side() const;
    bool                      setSide(const BrxCvGradingRule::EGradingSide side);
    static double             convertSlopeToRad(BrxCvGradingRule::EGradingSlopeFormat format, double slope);
    static double             convertRadToSlope(BrxCvGradingRule::EGradingSlopeFormat format, double angle);
    static PyBrxCvGradingRule cast(const PyBrxCvGradingRule& src);
    static std::string        className();
public:
    inline BrxCvGradingRule* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxCvGradingRule> m_pyImp;
};

//-----------------------------------------------------------------------------------
//PyBrxCvGradingSlopeSurfaceRule
void makePyBrxCvGradingSlopeSurfaceRuleWrapper();

class PyBrxCvGradingSlopeSurfaceRule : public PyBrxCvGradingRule
{
public:
    PyBrxCvGradingSlopeSurfaceRule();
    PyBrxCvGradingSlopeSurfaceRule(const PyDbObjectId& surfId, double cutSlope, double fillSlope);
    PyBrxCvGradingSlopeSurfaceRule(BrxCvGradingSlopeSurfaceRule* ptr);
    virtual ~PyBrxCvGradingSlopeSurfaceRule() = default;
    PyDbObjectId        surfaceId() const;
    bool                setSurfaceId(const PyDbObjectId& surfId);
    double              cutSlope() const;
    bool                setCutSlope(double cutSlope);
    double              fillSlope() const;
    bool                setFillSlope(double fillSlope);
    static PyBrxCvGradingSlopeSurfaceRule cast(const PyBrxCvGradingRule& src);
    static std::string  className();
public:
    inline BrxCvGradingSlopeSurfaceRule* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvGradingSlopeOffsetRule
void makePyBrxCvGradingSlopeOffsetRule();

class PyBrxCvGradingSlopeOffsetRule : public PyBrxCvGradingRule
{
public:
    PyBrxCvGradingSlopeOffsetRule();
    PyBrxCvGradingSlopeOffsetRule(double slope, double offset);
    PyBrxCvGradingSlopeOffsetRule(BrxCvGradingSlopeOffsetRule* ptr);
    virtual ~PyBrxCvGradingSlopeOffsetRule() = default;
    double              slope() const;
    bool                setSlope(double slope);
    double              offset() const;
    bool                setOffset(double offset);
    static PyBrxCvGradingSlopeOffsetRule cast(const PyBrxCvGradingRule& src);
    static std::string  className();
public:
    inline BrxCvGradingSlopeOffsetRule* impObj(const std::source_location& src = std::source_location::current()) const;
};