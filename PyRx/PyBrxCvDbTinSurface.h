#pragma once

#include "BrxCvDbTinSurface.h"
#include "PyBrxCvObject.h"

class PyDbObjectId;
class PyBrxCvTinTriangle;

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

class PyBrxCvDbTinSurface :  public PyBrxCvDbEntity
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
    bool                findTinPointAt(BrxCvTinPoint& tinPoint, const AcGePoint3d& pnt) const;
    boost::python::list triangles(bool visibleOnly) const;
    boost::python::list tinTriangles() const;
    boost::python::list findTinTrianglesAt(const AcGePoint3d& pnt) const;
    size_t              pointsCount(bool visibleOnly) const;
    size_t              trianglesCount(bool visibleOnly) const;
    double              area2d(bool visibleOnly) const;
    double              area3d(bool visibleOnly) const;
    double              minElevation(bool visibleOnly) const;
    double              maxElevation(bool visibleOnly) const;

    static PyBrxCvDbTinSurface  mergeSurfaces(const PyBrxCvDbTinSurface& theOne, const PyBrxCvDbTinSurface& theOther);
    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbTinSurface  cloneFrom(const PyRxObject& src);
    static PyBrxCvDbTinSurface  cast(const PyRxObject& src);
public:
    inline BrxCvDbTinSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};