#pragma once
#include "PyDbObject.h"

class PyCmColor;

void makeAcDbEntityWrapper();

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



    static std::string className();

public:
    AcDbEntity* impObj() const;
};

