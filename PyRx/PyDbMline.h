#pragma once
#include "PyDbEntity.h"

class PyGePlane;
class PyDbObjectId;

//-----------------------------------------------------------------------------------
//PyDbMline
void makPyDbMlineWrapper();
class PyDbMline : public PyDbEntity
{
public:
    PyDbMline();
    PyDbMline(AcDbMline* ptr, bool autoDelete);
    PyDbMline(const PyDbObjectId& id, AcDb::OpenMode mode);
    Acad::ErrorStatus setStyle(const PyDbObjectId& newStyleId);
    PyDbObjectId      style() const;
    Acad::ErrorStatus setJustification(Mline::MlineJustification newJust);
    Mline::MlineJustification justification() const;
    Acad::ErrorStatus setScale(double newScale);
    double            scale() const;
    AcGeVector3d      normal() const;
    Acad::ErrorStatus setNormal(const AcGeVector3d& newNormal);
    Acad::ErrorStatus appendSeg(const AcGePoint3d& newVertex);
    Acad::ErrorStatus removeLastSeg(AcGePoint3d& lastVertex);
    Acad::ErrorStatus moveVertexAt(int index, const AcGePoint3d& newPosition);
    Acad::ErrorStatus setClosedMline(bool closed);
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
void makPyDbMlineStyleWrapper();

class PyDbMlineStyle : public PyDbObject
{
public:
    PyDbMlineStyle();
    PyDbMlineStyle(AcDbMlineStyle* ptr, bool autoDelete);
    PyDbMlineStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    void              initMlineStyle();
    void              set1(const PyDbMlineStyle& src);
    void              set2(const PyDbMlineStyle& src, bool checkIfReferenced);
    Acad::ErrorStatus setDescription(const std::string& description);
    std::string		  description() const;
    Acad::ErrorStatus setName(const std::string& name);
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
    Acad::ErrorStatus setFillColor(const AcCmColor& color);
    AcCmColor		  fillColor() const;
    void              setFilled(bool onOff);
    bool              filled() const;
    Acad::ErrorStatus setStartAngle(double ang);
    double            startAngle() const;
    Acad::ErrorStatus setEndAngle(double ang);
    double            endAngle() const;
    int				  addElement1(double offset, const AcCmColor& color, PyDbObjectId& linetypeId);
    int				  addElement2(double offset, const AcCmColor& color, PyDbObjectId& linetypeId, bool checkIfReferenced);
    Acad::ErrorStatus removeElementAt(int elem);
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
