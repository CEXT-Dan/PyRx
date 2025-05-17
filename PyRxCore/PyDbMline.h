#pragma once
#include "PyDbEntity.h"

#pragma pack (push, 8)
class PyGePlane;
class PyDbObjectId;

//-----------------------------------------------------------------------------------
//PyDbMline
void makePyDbMlineWrapper();
class PyDbMline : public PyDbEntity
{
public:
    PyDbMline();
    PyDbMline(AcDbMline* ptr, bool autoDelete);
    PyDbMline(const PyDbObjectId& id);
    PyDbMline(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbMline(const PyDbObjectId& id, AcDb::OpenMode mode, bool);
    virtual ~PyDbMline() override = default;
    void              setStyle(const PyDbObjectId& newStyleId) const;
    PyDbObjectId      style() const;
    void              setJustification(Mline::MlineJustification newJust) const;
    Mline::MlineJustification justification() const;
    void              setScale(double newScale) const;
    double            scale() const;
    AcGeVector3d      normal() const;
    void              setNormal(const AcGeVector3d& newNormal) const;
    void              appendSeg(const AcGePoint3d& newVertex) const;
    void              removeLastSeg(AcGePoint3d& lastVertex) const;
    void              moveVertexAt(int index, const AcGePoint3d& newPosition) const;
    void              setClosedMline(bool closed) const;
    bool              closedMline() const;
    void              setSupressStartCaps(bool supressIt) const;
    bool              supressStartCaps() const;
    void              setSupressEndCaps(bool supressIt) const;
    bool              supressEndCaps() const;
    int               numVertices() const;
    int               element(const AcGePoint3d& pt) const;
    AcGePoint3d       vertexAt(int index) const;
    AcGeVector3d      axisAt(int index) const;
    AcGeVector3d      miterAt(int index) const;
    AcGePoint3d	      getClosestPointTo1(const AcGePoint3d& givenPoint, bool extend) const;
    AcGePoint3d       getClosestPointTo2(const AcGePoint3d& givenPoint, bool extend, bool excludeCaps) const;
    AcGePoint3d       getClosestPointTo3(const AcGePoint3d& givenPoint, const AcGeVector3d& normal, bool extend) const;
    AcGePoint3d       getClosestPointTo4(const AcGePoint3d& givenPoint, const AcGeVector3d& normal, bool extend, bool excludeCaps) const;
    PyGePlane		  getPlane() const;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbMline	cloneFrom(const PyRxObject& src);
    static PyDbMline    cast(const PyRxObject& src);
public:
    AcDbMline* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
//PyDbMlineStyle
void makePyDbMlineStyleWrapper();

class PyDbMlineStyle : public PyDbObject
{
public:
    PyDbMlineStyle();
    PyDbMlineStyle(AcDbMlineStyle* ptr, bool autoDelete);
    PyDbMlineStyle(const PyDbObjectId& id);
    PyDbMlineStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbMlineStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool);
    virtual ~PyDbMlineStyle() override = default;
    void              initMlineStyle() const;
    void              set1(const PyDbMlineStyle& src) const;
    void              set2(const PyDbMlineStyle& src, bool checkIfReferenced) const;
    void              setDescription(const std::string& description) const;
    std::string		  description() const;
    void              setName(const std::string& name) const;
    std::string		  name() const;
    void              setShowMiters(bool showThem) const;
    bool              showMiters() const;
    void              setStartSquareCap(bool showIt) const;
    bool              startSquareCap() const;
    void              setStartRoundCap(bool showIt) const;
    bool              startRoundCap() const;
    void              setStartInnerArcs(bool showThem) const;
    bool              startInnerArcs() const;
    void              setEndSquareCap(bool showIt) const;
    bool              endSquareCap() const;
    void              setEndRoundCap(bool showIt) const;
    bool              endRoundCap() const;
    void              setEndInnerArcs(bool showThem) const;
    bool              endInnerArcs() const;
    void              setFillColor(const AcCmColor& color) const;
    AcCmColor		  fillColor() const;
    void              setFilled(bool onOff) const;
    bool              filled() const;
    void              setStartAngle(double ang) const;
    double            startAngle() const;
    void              setEndAngle(double ang) const;
    double            endAngle() const;
    int				  addElement1(double offset, const AcCmColor& color, PyDbObjectId& linetypeId) const;
    int				  addElement2(double offset, const AcCmColor& color, PyDbObjectId& linetypeId, bool checkIfReferenced) const;
    void              removeElementAt(int elem) const;
    int				  numElements() const;
    int				  setElement(double offset, const AcCmColor& color, PyDbObjectId& linetypeId) const;
    boost::python::tuple getElementAt(int elem) const;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbMlineStyle cloneFrom(const PyRxObject& src);
    static PyDbMlineStyle cast(const PyRxObject& src);
public:
    AcDbMlineStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)