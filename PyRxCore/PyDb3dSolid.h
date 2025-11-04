#pragma once
#include "PyDbEntity.h"

#pragma pack (push, 8)
class PyDbObjectId;
class PyDbRegion;
class PyDbCurve;
class PyDbSurface;
class PyDbRevolveOptions;
class PyDbSweepOptions;
//-----------------------------------------------------------------------------------
//PyDb3dSolid
void makePyDb3dSolidWrapper();

class PyDb3dSolid : public PyDbEntity
{
public:
    PyDb3dSolid();
    PyDb3dSolid(AcDb3dSolid* ptr, bool autoDelete);
    PyDb3dSolid(const PyDbObjectId& id);
    PyDb3dSolid(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDb3dSolid(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);

    virtual ~PyDb3dSolid() override = default;
    void                createBox(double xLen, double yLen, double zLen) const;
    void                createFrustum(double height, double xRadius, double yRadius, double topXRadius) const;
    void                createSphere(double radius) const;
    void                createTorus(double majorRadius, double minorRadius) const;
    void                createPyramid1(double height, int sides, double radius) const;
    void                createPyramid2(double height, int sides, double radius, double topRadius) const;
    void                createWedge(double xLen, double yLen, double zLen) const;
    void                extrude1(const PyDbRegion& region, double height) const;
    void                extrude2(const PyDbRegion& region, double height, double taperAngle) const;
    void                extrudeAlongPath1(const PyDbRegion& region, const PyDbCurve& path) const;
    void                extrudeAlongPath2(const PyDbRegion& region, const PyDbCurve& path, double taperAngle) const;
    void                createRevolvedSolid1(const PyDbEntity& pRevEnt, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& revolveOptions) const;
    void                createRevolvedSolid2(const PyDbEntity& pRevEnt, const PyDbSubentId& faceSubentId, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& revolveOptions) const;
    void                createSweptSolid1(const PyDbEntity& pSweepEnt, const PyDbEntity& pPathEnt, PyDbSweepOptions& sweepOptions) const;
    void                createSweptSolid2(const PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, PyDbEntity& pPathEnt, PyDbSweepOptions& sweepOptions) const;
    void                createExtrudedSolid1(const PyDbEntity& pSweepEnt, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions) const;
    void                createExtrudedSolid2(const PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions) const;
    void                createExtrudedSolid3(const PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, double height, PyDbSweepOptions& sweepOptions) const;
    void                createFrom(const PyDbEntity& pFromEntity) const;
    double              getArea() const;
    boost::python::tuple checkInterference(const PyDb3dSolid& otherSolid, Adesk::Boolean createNewSolid) const;
    boost::python::tuple getMassProp() const;
    Adesk::Boolean      isNull() const;
    PyDbRegion          getSection(const PyGePlane& plane) const;
    void                stlOut1(const std::string& fileName, Adesk::Boolean asciiFormat) const;
    void                stlOut2(const std::string& fileName, Adesk::Boolean asciiFormat, double maxSurfaceDeviation) const;
    void                booleanOper(AcDb::BoolOperType operation, PyDb3dSolid& solid) const;
    PyDb3dSolid         getSlice1(const PyGePlane& plane, Adesk::Boolean getNegHalfToo) const;
    PyDb3dSolid         getSlice2(const PyDbSurface& plane, Adesk::Boolean getNegHalfToo) const;
    Adesk::UInt32       numChanges() const;
    PyDbEntity          copyEdge(const PyDbSubentId& subentId) const;
    PyDbEntity          copyFace(const PyDbSubentId& subentId) const;
    void                extrudeFaces(const boost::python::list& faceSubentIds, double height, double taper) const;
    void                extrudeFacesAlongPath(boost::python::list& faceSubentIds, const PyDbCurve& path) const;
    void                imprintEntity(const PyDbEntity& pEntity) const;
    void                cleanBody() const;
    void                offsetBody(double offsetDistance) const;
    void                offsetFaces(const boost::python::list& faceSubentIds, double offsetDistance) const;
    void                removeFaces(const boost::python::list& faceSubentIds) const;
    boost::python::list separateBody() const;
    void                shellBody(const boost::python::list& faceSubentIds, double offsetDistance) const;
    void                taperFaces(const boost::python::list& faceSubentIds, const AcGePoint3d& basePoint, const AcGeVector3d& draftVector, double draftAngle) const;
    void                transformFaces(const boost::python::list& faceSubentIds, const AcGeMatrix3d& matrix) const;
    void                setSubentColor(const PyDbSubentId& subentId, const AcCmColor& color) const;
    AcCmColor           getSubentColor(const PyDbSubentId& subentId) const;
    void                setSubentMaterial(const PyDbSubentId& subentId, const PyDbObjectId& matId) const;
    PyDbObjectId        getSubentMaterial(const PyDbSubentId& subentId) const;
    bool                recordHistory() const;
    void                setRecordHistory(bool bRecord) const;
    bool                showHistory() const;
    void                setShowHistory(bool bShow) const;
    void                chamferEdges(const boost::python::list& edgeSubentIds, const PyDbSubentId& baseFaceSubentId, double baseDist, double otherDist) const;
    void                filletEdges(const boost::python::list& edgeSubentIds, const boost::python::list& radius, const boost::python::list& startSetback, const boost::python::list& endSetback) const;
    bool                usesGraphicsCache() const;
    void                createSculptedSolid(const boost::python::list& limitingBodies, const boost::python::list& limitingFlags) const;
    boost::python::list projectOnToSolid(const PyDbEntity& pEntityToProject, const AcGeVector3d& projectionDirection) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDb3dSolid  cloneFrom(const PyRxObject& src);
    static PyDb3dSolid  cast(const PyRxObject& src);

public:
    AcDb3dSolid* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbRegion
void makePyDbRegionWrapper();

class PyDbRegion : public PyDbEntity
{
public:
    PyDbRegion();
    PyDbRegion(AcDbRegion* ptr, bool autoDelete);
    PyDbRegion(const PyDbObjectId& id);
    PyDbRegion(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbRegion() override = default;

    double              getPerimeter() const;
    double              getArea() const;
    AcGeVector3d        getNormal() const;
    void                booleanOper(AcDb::BoolOperType operation, PyDbRegion& otherRegion) const;
    Adesk::UInt32       numChanges() const;
    Adesk::Boolean      isNull() const;

    static boost::python::list createFromCurves(const boost::python::list& curveSegments);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRegion   cloneFrom(const PyRxObject& src);
    static PyDbRegion   cast(const PyRxObject& src);
public:
    AcDbRegion* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbBody
void makePyDbBodyWrapper();

class PyDbBody : public PyDbEntity
{
public:
    PyDbBody();
    PyDbBody(AcDbBody* ptr, bool autoDelete);
    PyDbBody(const PyDbObjectId& id);
    PyDbBody(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBody() override = default;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbBody     cloneFrom(const PyRxObject& src);
    static PyDbBody     cast(const PyRxObject& src);
public:
    AcDbBody* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
//PyDbRevolveOptions
void makePyDbRevolveOptionsWrapper();
class PyDbRevolveOptions
{
public:
    PyDbRevolveOptions();
    PyDbRevolveOptions(const AcDbRevolveOptions& src);
    ~PyDbRevolveOptions() = default;
    double      draftAngle() const;
    void        setDraftAngle(double ang) const;
    double      twistAngle() const;
    void        setTwistAngle(double ang) const;
    bool        closeToAxis() const;
    void        setCloseToAxis(bool val) const;
    boost::python::tuple checkRevolveCurve1(PyDbEntity& ent, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir) const;
    boost::python::tuple checkRevolveCurve2(PyDbEntity& ent, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, bool displayErrorMessages) const;
public:
    AcDbRevolveOptions* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<AcDbRevolveOptions> m_pyImp;
};

//-----------------------------------------------------------------------------------
//PyDbSweepOptions
void makePyDbSweepOptionsWrapper();
class PyDbSweepOptions
{
public:
    PyDbSweepOptions();
    PyDbSweepOptions(const AcDbSweepOptions& src);
    ~PyDbSweepOptions() = default;

    double              draftAngle() const;
    void                setDraftAngle(double ang) const;
    double              startDraftDist() const;
    void                setStartDraftDist(double val) const;
    double              endDraftDist() const;
    void                setEndDraftDist(double val) const;
    double              twistAngle() const;
    void                setTwistAngle(double ang) const;
    double              scaleFactor() const;
    void                setScaleFactor(double val) const;
    double              alignAngle() const;
    void                setAlignAngle(double ang) const;
    AcDbSweepOptions::AlignOption align() const;
    void                setAlign(AcDbSweepOptions::AlignOption val) const;
    AcDbSweepOptions::MiterOption miterOption() const;
    void                setMiterOption(AcDbSweepOptions::MiterOption val) const;
    bool                alignStart() const;
    void                setAlignStart(bool val) const;
    AcGePoint3d         basePoint() const;
    void                setBasePoint(AcGePoint3d& pnt) const;
    bool                bank() const;
    void                setBank(bool val) const;
    bool                checkIntersections() const;
    void                setCheckIntersections(bool val) const;
    AcGeVector3d        twistRefVec() const;
    void                setTwistRefVec(const AcGeVector3d& vec) const;
    bool                getSweepEntityTransform(AcGeMatrix3d& mat) const;
    void                setSweepEntityTransform1(AcGeMatrix3d& mat) const;
    void                setSweepEntityTransform2(boost::python::list& sweepEntities) const;
    void                setSweepEntityTransform3(boost::python::list& sweepEntities, bool displayErrorMessages) const;
    bool                getPathEntityTransform(AcGeMatrix3d& mat) const;
    void                setPathEntityTransform1(AcGeMatrix3d& mat) const;
    void                setPathEntityTransform2(PyDbEntity& pPathEnt) const;
    void                setPathEntityTransform3(PyDbEntity& pPathEnt, bool displayErrorMessages) const;
    boost::python::tuple checkSweepCurve1(PyDbEntity& pSweepEnt) const;
    boost::python::tuple checkSweepCurve2(PyDbEntity& pSweepEnt, bool displayErrorMessages) const;
    void                checkPathCurve1(PyDbEntity& pPathEnt) const;
    void                checkPathCurve2(PyDbEntity& pPathEnt, bool displayErrorMessages) const;
public:
    AcDbSweepOptions* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<AcDbSweepOptions> m_pyImp;
};
#pragma pack (pop)
