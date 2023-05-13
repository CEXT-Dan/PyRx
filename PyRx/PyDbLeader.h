#pragma once
#include "PyDbCurve.h"

class PyDbObjectId;
class PyDbHardPointerId;
//----------------------------------------------------------------------------------
//PyDbLeader
void makePyDbLeaderWrapper();

class PyDbLeader : public PyDbCurve
{
public:
    PyDbLeader();
    virtual ~PyDbLeader() override = default;
    PyDbLeader(AcDbLeader* ptr, bool autoDelete);
    PyDbLeader(const PyDbObjectId& id, AcDb::OpenMode mode);
    void                setPlane(const PyGePlane& plane);
    AcGeVector3d        normal() const;
    int numVertices() const;
    Adesk::Boolean      appendVertex(const AcGePoint3d& val);
    void                removeLastVertex();
    AcGePoint3d         firstVertex() const;
    AcGePoint3d         lastVertex() const;
    AcGePoint3d         vertexAt(int idx) const;
    Adesk::Boolean      setVertexAt(int idx, const AcGePoint3d& val);
    Adesk::Boolean      hasArrowHead() const;
    void                enableArrowHead();
    void                disableArrowHead();
    void                setHasArrowHead(Adesk::Boolean bEnable);
    Adesk::Boolean      hasHookLine() const;
    void                setToSplineLeader();
    void                setToStraightLeader();
    Adesk::Boolean      isSplined() const;
    void                setSplined(Adesk::Boolean bSplined);
    PyDbHardPointerId   dimensionStyle() const;
    void                setDimensionStyle(const PyDbHardPointerId& val);
    Acad::ErrorStatus   setDimstyleData(const PyDbObjectId& newDataId);
    Acad::ErrorStatus   attachAnnotation(const PyDbObjectId& annoId);
    Acad::ErrorStatus   detachAnnotation();
    PyDbObjectId        annotationObjId() const;
    Acad::ErrorStatus   setAnnotationObjId(const PyDbObjectId& annoId);
    Acad::ErrorStatus   evaluateLeader();
    AcGeVector3d        annotationOffset() const;
    Acad::ErrorStatus   setAnnotationOffset(const AcGeVector3d& offset);
    AcDbLeader::AnnoType annoType()   const;
    double               annoHeight() const;
    double               annoWidth()  const;
    double               dimasz() const;
    AcCmColor            dimclrd() const;
    double               dimgap() const;
    AcDb::LineWeight     dimlwd() const;
    PyDbObjectId         dimldrblk() const;
    bool                 dimsah() const;
    double               dimscale() const;
    int                  dimtad() const;
    PyDbObjectId         dimtxsty() const;
    double               dimtxt() const;
    Acad::ErrorStatus    setDimasz(double         val);
    Acad::ErrorStatus    setDimclrd(AcCmColor& val);
    Acad::ErrorStatus    setDimgap(double         val);
    Acad::ErrorStatus    setDimldrblk1(const PyDbObjectId& val);
    Acad::ErrorStatus    setDimldrblk2(const std::string& val);
    Acad::ErrorStatus    setDimlwd(AcDb::LineWeight val);  // new to R15
    Acad::ErrorStatus    setDimsah(bool           val);
    Acad::ErrorStatus    setDimscale(double         val);
    Acad::ErrorStatus    setDimtad(int            val);
    Acad::ErrorStatus    setDimtxsty(const PyDbObjectId& val);
    Acad::ErrorStatus    setDimtxt(double         val);
    void                 modified(const PyDbObject& obj);
    void                 erased1(const PyDbObject& obj);
    void                 erased2(const PyDbObject& obj, Adesk::Boolean val);
    void                 goodbye(const PyDbObject& obj);
    void                 copied(const PyDbObject& objA, const PyDbObject& objB);
    Acad::ErrorStatus    setColorIndex1(Adesk::UInt16 val);
    Acad::ErrorStatus    setColorIndex2(Adesk::UInt16 val, Adesk::Boolean doSubents);

public:
    static std::string  className();
    static PyRxClass    desc();

public:
    AcDbLeader* impObj(const std::source_location& src = std::source_location::current()) const;
};

