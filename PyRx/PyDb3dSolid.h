#pragma once
#include "PyDbEntity.h"

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
    Acad::ErrorStatus   createBox(double xLen, double yLen, double zLen);
    Acad::ErrorStatus   createFrustum(double height, double xRadius, double yRadius, double topXRadius);
    Acad::ErrorStatus   createSphere(double radius);
    Acad::ErrorStatus   createTorus(double majorRadius, double minorRadius);
    Acad::ErrorStatus   createPyramid1(double height, int sides, double radius);
    Acad::ErrorStatus   createPyramid2(double height, int sides, double radius, double topRadius);
    Acad::ErrorStatus   createWedge(double xLen, double yLen, double zLen);
    Acad::ErrorStatus   extrude1(const PyDbRegion& region, double height);
    Acad::ErrorStatus   extrude2(const PyDbRegion& region, double height, double taperAngle);
    Acad::ErrorStatus   extrudeAlongPath1(const PyDbRegion& region, const PyDbCurve& path);
    Acad::ErrorStatus   extrudeAlongPath2(const PyDbRegion& region, const PyDbCurve& path, double taperAngle);
    Acad::ErrorStatus   createRevolvedSolid1(PyDbEntity& pRevEnt, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& revolveOptions);
    Acad::ErrorStatus   createRevolvedSolid2(PyDbEntity& pRevEnt, const PyDbSubentId& faceSubentId, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& revolveOptions);
    Acad::ErrorStatus   createSweptSolid1(PyDbEntity& pSweepEnt, PyDbEntity& pPathEnt, PyDbSweepOptions& sweepOptions);
    Acad::ErrorStatus   createSweptSolid2(PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, PyDbEntity& pPathEnt, PyDbSweepOptions& sweepOptions);
    Acad::ErrorStatus   createExtrudedSolid1(PyDbEntity& pSweepEnt, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions);
    Acad::ErrorStatus   createExtrudedSolid2(PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions);
    Acad::ErrorStatus   createExtrudedSolid3(PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, double height, PyDbSweepOptions& sweepOptions);
    Acad::ErrorStatus   createFrom(const PyDbEntity& pFromEntity);
    double              getArea() const;
    boost::python::tuple checkInterference(const PyDb3dSolid& otherSolid, Adesk::Boolean createNewSolid);
    boost::python::tuple getMassProp();
    Adesk::Boolean      isNull() const;
    PyDbRegion          getSection(const PyGePlane& plane);
    Acad::ErrorStatus   stlOut1(const std::string& fileName, Adesk::Boolean asciiFormat) const;
    Acad::ErrorStatus   stlOut2(const std::string& fileName, Adesk::Boolean asciiFormat, double maxSurfaceDeviation) const;
    Acad::ErrorStatus   booleanOper(AcDb::BoolOperType operation, PyDb3dSolid& solid);
    PyDb3dSolid         getSlice1(const PyGePlane& plane, Adesk::Boolean getNegHalfToo);
    PyDb3dSolid         getSlice2(const PyDbSurface& plane, Adesk::Boolean getNegHalfToo);
    Adesk::UInt32       numChanges() const;
    PyDbEntity          copyEdge(const PyDbSubentId& subentId);
    PyDbEntity          copyFace(const PyDbSubentId& subentId);
    Acad::ErrorStatus   extrudeFaces(const boost::python::list& faceSubentIds, double height, double taper);
    Acad::ErrorStatus   extrudeFacesAlongPath(boost::python::list& faceSubentIds, const PyDbCurve& path);
    Acad::ErrorStatus   imprintEntity(const PyDbEntity& pEntity);
    Acad::ErrorStatus   cleanBody();
    Acad::ErrorStatus   offsetBody(double offsetDistance);
    Acad::ErrorStatus   offsetFaces(const boost::python::list& faceSubentIds, double offsetDistance);
    Acad::ErrorStatus   removeFaces(const boost::python::list& faceSubentIds);
    boost::python::list separateBody();
    Acad::ErrorStatus   shellBody(const boost::python::list& faceSubentIds, double offsetDistance);
    Acad::ErrorStatus   taperFaces(const boost::python::list& faceSubentIds, const AcGePoint3d& basePoint, const AcGeVector3d& draftVector, double draftAngle);
    Acad::ErrorStatus   transformFaces(const boost::python::list& faceSubentIds, const AcGeMatrix3d& matrix);
    Acad::ErrorStatus   setSubentColor(const PyDbSubentId& subentId, const AcCmColor& color);
    AcCmColor           getSubentColor(const PyDbSubentId& subentId) const;
    Acad::ErrorStatus   setSubentMaterial(const PyDbSubentId& subentId, PyDbObjectId& matId);
    PyDbObjectId        getSubentMaterial(const PyDbSubentId& subentId) const;
    bool                recordHistory() const;
    Acad::ErrorStatus   setRecordHistory(bool bRecord);
    bool                showHistory() const;
    Acad::ErrorStatus   setShowHistory(bool bShow);
    Acad::ErrorStatus   chamferEdges(const boost::python::list& edgeSubentIds, const PyDbSubentId& baseFaceSubentId, double baseDist, double otherDist);
    Acad::ErrorStatus   filletEdges(const boost::python::list& edgeSubentIds, boost::python::list& radius, boost::python::list& startSetback, boost::python::list& endSetback);
    bool                usesGraphicsCache();
    Acad::ErrorStatus   createSculptedSolid(const boost::python::list& limitingBodies, const boost::python::list& limitingFlags);
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
    Adesk::Boolean    isNull() const;


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
void makeAcDbBodyWrapper();

class PyDbBody : public PyDbEntity
{
public:
    PyDbBody();
    PyDbBody(AcDbBody* ptr, bool autoDelete);
    PyDbBody(const PyDbObjectId& id);
    PyDbBody(const PyDbObjectId& id, AcDb::OpenMode mode);
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
    double      draftAngle() const;
    void        setDraftAngle(double ang);
    double      twistAngle() const;
    void        setTwistAngle(double ang);
    bool        closeToAxis() const;
    void        setCloseToAxis(bool val);
    boost::python::tuple checkRevolveCurve1(PyDbEntity& ent, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir);
    boost::python::tuple checkRevolveCurve2(PyDbEntity& ent, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, bool displayErrorMessages);
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
    double              draftAngle() const;
    void                setDraftAngle(double ang);
    double              startDraftDist() const;
    void                setStartDraftDist(double val);
    double              endDraftDist() const;
    void                setEndDraftDist(double val);
    double              twistAngle() const;
    void                setTwistAngle(double ang);
    double              scaleFactor() const;
    void                setScaleFactor(double val);
    double              alignAngle() const;
    void                setAlignAngle(double ang);
    AcDbSweepOptions::AlignOption align() const;
    void                setAlign(AcDbSweepOptions::AlignOption val);
    AcDbSweepOptions::MiterOption miterOption() const;
    void                setMiterOption(AcDbSweepOptions::MiterOption val);
    bool                alignStart() const;
    void                setAlignStart(bool val);
    AcGePoint3d         basePoint() const;
    void                setBasePoint(AcGePoint3d& pnt);
    bool                bank() const;
    void                setBank(bool val);
    bool                checkIntersections() const;
    void                setCheckIntersections(bool val);
    AcGeVector3d        twistRefVec() const;
    void                setTwistRefVec(const AcGeVector3d& vec);
    bool                getSweepEntityTransform(AcGeMatrix3d& mat);
    void                setSweepEntityTransform1(AcGeMatrix3d& mat);
    Acad::ErrorStatus   setSweepEntityTransform2(boost::python::list& sweepEntities);
    Acad::ErrorStatus   setSweepEntityTransform3(boost::python::list& sweepEntities, bool displayErrorMessages);
    bool                getPathEntityTransform(AcGeMatrix3d& mat);
    void                setPathEntityTransform1(AcGeMatrix3d& mat);
    Acad::ErrorStatus   setPathEntityTransform2(PyDbEntity& pPathEnt);
    Acad::ErrorStatus   setPathEntityTransform3(PyDbEntity& pPathEnt, bool displayErrorMessages);
    boost::python::tuple checkSweepCurve1(PyDbEntity& pSweepEnt);
    boost::python::tuple checkSweepCurve2(PyDbEntity& pSweepEnt, bool displayErrorMessages);
    Acad::ErrorStatus   checkPathCurve1(PyDbEntity& pPathEnt);
    Acad::ErrorStatus   checkPathCurve2(PyDbEntity& pPathEnt, bool displayErrorMessages);
public:
    AcDbSweepOptions* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<AcDbSweepOptions> m_pyImp;
};