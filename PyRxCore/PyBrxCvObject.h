#pragma once


#ifdef BRXAPP

#include "PyDbCurve.h"
#include "BrxCvDbObject.h"
#include "BrxCvDbEntity.h"
#include "BrxCvDbCurve.h"
#include "BrxCvDbSubObject.h"

#if defined(_BRXTARGET) && (_BRXTARGET >= 270)
#include "BrxCvDbStringLine.h"
#endif

class PyDbObjectId;
class PyDbDatabase;
class PyGeInterval;

//-----------------------------------------------------------------------------------
//PyBrxCvDbSubObject
void makePyBrxCvDbSubObjectWrapper();

class PyBrxCvDbSubObject : public PyRxObject
{
public:

    PyBrxCvDbSubObject(BrxCvDbSubObject* ptr, bool autoDelete);
    virtual ~PyBrxCvDbSubObject() override = default;

    std::string             name() const;
    bool                    setName(const std::string& szName) const;
    std::string             description() const;
    bool                    setDescription(const std::string& szDescription) const;
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbSubObject  cast(const PyRxObject& src);

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
    bool                        setName(const std::string& szName) const;
    std::string                 description() const;
    bool                        setDescription(const std::string& szDescription) const;

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
    bool                    setName(const std::string& szName) const;
    std::string             description() const;
    bool                    setDescription(const std::string& szDescription) const;

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
    bool                        setName(const std::string& szName) const;
    std::string                 description() const;
    bool                        setDescription(const std::string& szDescription) const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbCurve       cloneFrom(const PyRxObject& src);
    static PyBrxCvDbCurve       cast(const PyRxObject& src);

public:
    inline BrxCvDbCurve* impObj(const std::source_location& src = std::source_location::current()) const;
};

#if defined(_BRXTARGET) && (_BRXTARGET >= 270)
//-----------------------------------------------------------------------------------
//PyBrxCvDbStringLine

void makePyBrxCvDbStringLineWrapper();
class PyBrxCvDbStringLine : public PyBrxCvDbCurve
{
public:
    PyBrxCvDbStringLine();
    PyBrxCvDbStringLine(const PyDbObjectId& id);
    PyBrxCvDbStringLine(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbStringLine(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbStringLine(BrxCvDbStringLine* ptr, bool autoDelete);
    virtual ~PyBrxCvDbStringLine() override = default;

    Adesk::UInt32 numberOfPoints1() const;
    Adesk::UInt32 numberOfPoints2(BrxCvDbStringLine::PointType type) const;

    boost::python::tuple getPoint(Adesk::UInt32 index) const;
    boost::python::tuple findPoint1(const AcGePoint2d& pointLocation) const;
    boost::python::tuple findPoint2(const AcGePoint2d& pointLocation, const PyGeInterval& pInterval) const;

    double getBulge(Adesk::UInt32 index) const;
    double getRadius(Adesk::UInt32 index) const;

    PyDbObjectId surfaceId() const;
    BrxCvDbStringLine::CreationSource creationSource() const;
    double maxGrade() const;
    double minGrade() const;
    double maxElevation() const;
    double minElevation() const;
    double length2d() const;
    double length3d() const;
    bool   isRelativeToSurface(Adesk::UInt32 index) const;
    double getRelativeElevation(Adesk::UInt32 index) const;

    boost::python::tuple getPoints1() const;
    boost::python::tuple getPoints2(BrxCvDbStringLine::PointType type) const;


    double get3dDistanceAtPoint(const AcGePoint3d& point) const;
    double get2dDistanceAtPoint(const AcGePoint2d& point) const;
    double get2dDistanceAtParam(double param) const;
    boost::python::list get2dDistancesAtPoints(const boost::python::list& points);

    double getGradeInAtPoint(const AcGePoint2d& pointOnCurve) const;
    double getGradeInAtParam(double param) const;
    double getGradeOutAtPoint(const AcGePoint2d& pointOnCurve) const;
    double getGradeOutAtParam(double param) const;
    double getElevationAtPoint(const AcGePoint2d& pointOnCurve) const;
    boost::python::list getElevationsAt2dIntersections(const PyBrxCvDbStringLine& stringline) const;

    // Point modification
    void addPI1(const AcGePoint3d& point) const;
    void addPI2(const AcGePoint3d& point, double bulge) const;

    Adesk::UInt32 insertElevationPoint(double param, double elevation) const;

    void insertPI1(Adesk::UInt32 index, const AcGePoint3d& point) const;
    void insertPI2(Adesk::UInt32 index, const AcGePoint3d& point, double bulge) const;
    void insertCurve(Adesk::UInt32 index, double radius) const;
    void deletePoint(Adesk::UInt32 index) const;
    void deletePI1(const AcGePoint3d& point) const;
    void deletePI2(Adesk::UInt32 index) const;
    void deleteElevationPoint1(const AcGePoint3d& point) const;
    void deleteElevationPoint(Adesk::UInt32 index) const;
    void setLocation(Adesk::UInt32 index, const AcGePoint2d& location) const;
    void setElevation(Adesk::UInt32 index, double elevation) const;
    void setBulge(Adesk::UInt32 index, double bulge) const;
    void setRadius(Adesk::UInt32 piIndex, double radius, bool isClockwise) const;
    void setRelativeToSurface(Adesk::UInt32 index, bool isRelative) const;
    void setRelativeElevation(Adesk::UInt32 index, bool isInputRelative, double elevation) const;
    void setSurfaceId(const PyDbObjectId& surfaceId) const;
    void setGradeIn(Adesk::UInt32 index, double grade) const;
    void setGradeOut(Adesk::UInt32 index, double grade) const;
    void update1()  const;
    void update2(bool forceUpdate)  const;

    static std::string              className();
    static PyRxClass                desc();
    static PyBrxCvDbStringLine      cloneFrom(const PyRxObject& src);
    static PyBrxCvDbStringLine      cast(const PyRxObject& src);

    inline BrxCvDbStringLine* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif

#endif//BRXAPP
