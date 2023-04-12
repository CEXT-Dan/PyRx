#pragma once
#include "PyDbObject.h"

class PyCmColor;
class PyGePlane;

void makeAcDbEntityWrapper();
void makeAcDbBlockBeginWrapper();
void makeAcDbBlockEndWrapper();
void makeAcDbSequenceEndWrapper();
//-------------------------------------------------------------------------------------------------------------
//PyDbEntity
class PyDbEntity : public PyDbObject
{
public:
    PyDbEntity(AcDbEntity* ptr, bool autoDelete);
    PyDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbEntity() override = default;

    PyDbObjectId blockId() const;

    AcCmColor                 color() const;
    virtual Acad::ErrorStatus setColor(const AcCmColor& color, bool doSubents, PyDbDatabase& db);

    Adesk::UInt16             colorIndex() const;
    virtual Acad::ErrorStatus setColorIndex(Adesk::UInt16 color, Adesk::Boolean doSubents);

    AcCmEntityColor             entityColor() const;

    AcCmTransparency            transparency() const;
    virtual Acad::ErrorStatus   setTransparency(const AcCmTransparency& trans, Adesk::Boolean doSubents);

    std::string  layer() const;
    PyDbObjectId  layerId() const;

    virtual Acad::ErrorStatus setLayer(const std::string& newVal);
    virtual Acad::ErrorStatus setLayer(const std::string& newVal, bool doSubents);
    virtual Acad::ErrorStatus setLayer(const std::string& newVal, bool doSubents, bool allowHiddenLayer);

    virtual Acad::ErrorStatus setLayer(const PyDbObjectId& newVal);
    virtual Acad::ErrorStatus setLayer(const PyDbObjectId& newVal, bool doSubents);
    virtual Acad::ErrorStatus setLayer(const PyDbObjectId& newVal, bool doSubents, bool allowHiddenLayer);

    std::string plotStyleName() const;
    PyDbObjectId  getPlotStyleNameId() const;
    virtual Acad::ErrorStatus  setPlotStyleName(const std::string&, Adesk::Boolean doSubents);
    virtual Acad::ErrorStatus  setPlotStyleName(AcDb::PlotStyleNameType, Adesk::Boolean doSubents);
    virtual Acad::ErrorStatus  setPlotStyleName(AcDb::PlotStyleNameType, const PyDbObjectId& newId, Adesk::Boolean doSubents);

    std::string  linetype() const;
    PyDbObjectId linetypeId() const;
    virtual Acad::ErrorStatus setLinetype(const std::string& newVal);
    virtual Acad::ErrorStatus setLinetype(const std::string&, Adesk::Boolean doSubents);
    virtual Acad::ErrorStatus setLinetype(const PyDbObjectId& newVal);
    virtual Acad::ErrorStatus setLinetype(const PyDbObjectId& newVal, Adesk::Boolean doSubents);

    std::string  material() const;
    PyDbObjectId materialId() const;
    virtual Acad::ErrorStatus setMaterial(const std::string& newVal);
    virtual Acad::ErrorStatus setMaterial(const std::string&, Adesk::Boolean doSubents);
    virtual Acad::ErrorStatus setMaterial(const PyDbObjectId& newVal);
    virtual Acad::ErrorStatus setMaterial(const PyDbObjectId& newVal, Adesk::Boolean doSubents);

    double linetypeScale() const;
    Acad::ErrorStatus setLinetypeScale(double newval);
    Acad::ErrorStatus setLinetypeScale(double newval, Adesk::Boolean doSubents);

    AcDb::Visibility visibility() const;
    virtual Acad::ErrorStatus setVisibility(AcDb::Visibility newVal);
    virtual Acad::ErrorStatus setVisibility(AcDb::Visibility newVal, Adesk::Boolean doSubents);

    AcDb::LineWeight lineWeight() const;
    virtual Acad::ErrorStatus   setLineWeight(AcDb::LineWeight newVal);
    virtual Acad::ErrorStatus   setLineWeight(AcDb::LineWeight newVal, Adesk::Boolean doSubents);

    virtual AcDb::CollisionType collisionType() const;

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);

    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);

    Acad::ErrorStatus setPropertiesFrom(const PyDbEntity& pEntity);
    Acad::ErrorStatus setPropertiesFrom(const PyDbEntity& pEntity, Adesk::Boolean doSubents);

    virtual Adesk::Boolean isPlanar() const;
    virtual PyGePlane getPlane() const;

    virtual void getEcs(AcGeMatrix3d& retVal) const;

    virtual void  list() const;
    virtual Acad::ErrorStatus transformBy(const AcGeMatrix3d& xform);
    void recordGraphicsModified();
    Acad::ErrorStatus  draw();

    void  setDatabaseDefaults();
    void  setDatabaseDefaults(const PyDbDatabase& pDb);

    virtual Acad::ErrorStatus getCompoundObjectTransform(AcGeMatrix3d& xMat) const;
    virtual Acad::ErrorStatus getGeomExtents(AcDbExtents& extents) const;

    static std::string className();

public:
    AcDbEntity* impObj() const;
};


//-------------------------------------------------------------------------------------------------------------
//PyDbBlockBegin
class PyDbBlockBegin : public PyDbEntity
{
public:
    PyDbBlockBegin(AcDbBlockBegin* ptr, bool autoDelete);
    PyDbBlockBegin(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockBegin() = default;
    static std::string className();
public:
    AcDbBlockBegin* impObj() const;
};

//-------------------------------------------------------------------------------------------------------------
//PyDbBlockEnd
class PyDbBlockEnd : public PyDbEntity
{
public:
    PyDbBlockEnd(AcDbBlockEnd* ptr, bool autoDelete);
    PyDbBlockEnd(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockEnd() = default;
    static std::string className();
public:
    AcDbBlockEnd* impObj() const;
};


//-------------------------------------------------------------------------------------------------------------
//PyDbSequenceEnd
class PyDbSequenceEnd : public PyDbEntity
{
public:
    PyDbSequenceEnd(AcDbSequenceEnd* ptr, bool autoDelete);
    PyDbSequenceEnd(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbSequenceEnd() = default;
    static std::string className();
public:
    AcDbSequenceEnd* impObj() const;
};
