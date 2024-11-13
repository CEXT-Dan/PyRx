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
    inline virtual ~PyDbMline() override = default;
    void              setStyle(const PyDbObjectId& newStyleId);
    PyDbObjectId      style() const;
    void              setJustification(Mline::MlineJustification newJust);
    Mline::MlineJustification justification() const;
    void              setScale(double newScale);
    double            scale() const;
    AcGeVector3d      normal() const;
    void              setNormal(const AcGeVector3d& newNormal);
    void              appendSeg(const AcGePoint3d& newVertex);
    void              removeLastSeg(AcGePoint3d& lastVertex);
    void              moveVertexAt(int index, const AcGePoint3d& newPosition);
    void              setClosedMline(bool closed);
    bool              closedMline() const;
    void              setSupressStartCaps(bool supressIt);
    bool              supressStartCaps() const;
    void              setSupressEndCaps(bool supressIt);
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
    inline virtual ~PyDbMlineStyle() override = default;
    void              initMlineStyle();
    void              set1(const PyDbMlineStyle& src);
    void              set2(const PyDbMlineStyle& src, bool checkIfReferenced);
    void              setDescription(const std::string& description);
    std::string		  description() const;
    void              setName(const std::string& name);
    std::string		  name() const;
    void              setShowMiters(bool showThem);
    bool              showMiters() const;
    void              setStartSquareCap(bool showIt);
    bool              startSquareCap() const;
    void              setStartRoundCap(bool showIt);
    bool              startRoundCap() const;
    void              setStartInnerArcs(bool showThem);
    bool              startInnerArcs() const;
    void              setEndSquareCap(bool showIt);
    bool              endSquareCap() const;
    void              setEndRoundCap(bool showIt);
    bool              endRoundCap() const;
    void              setEndInnerArcs(bool showThem);
    bool              endInnerArcs() const;
    void              setFillColor(const AcCmColor& color);
    AcCmColor		  fillColor() const;
    void              setFilled(bool onOff);
    bool              filled() const;
    void              setStartAngle(double ang);
    double            startAngle() const;
    void              setEndAngle(double ang);
    double            endAngle() const;
    int				  addElement1(double offset, const AcCmColor& color, PyDbObjectId& linetypeId);
    int				  addElement2(double offset, const AcCmColor& color, PyDbObjectId& linetypeId, bool checkIfReferenced);
    void              removeElementAt(int elem);
    int				  numElements() const;
    int				  setElement(double offset, const AcCmColor& color, PyDbObjectId& linetypeId);
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