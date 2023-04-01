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

    virtual Acad::ErrorStatus setLayer(const std::string& newVal);
    virtual Acad::ErrorStatus setLayer(const std::string& newVal, bool doSubents);
    virtual Acad::ErrorStatus setLayer(const std::string& newVal, bool doSubents, bool allowHiddenLayer);

    virtual Acad::ErrorStatus setLayer(const PyDbObjectId& newVal);
    virtual Acad::ErrorStatus setLayer(const PyDbObjectId& newVal, bool doSubents);
    virtual Acad::ErrorStatus setLayer(const PyDbObjectId& newVal, bool doSubents, bool allowHiddenLayer);

    //std::string& plotStyleName() const;
    //virtual Acad::ErrorStatus  setPlotStyleName(std::string&, Adesk::Boolean doSubents);
    //virtual Acad::ErrorStatus  setPlotStyleName(AcDb::PlotStyleNameType, AcDbObjectId newId = AcDbObjectId::kNull, Adesk::Boolean doSubents = true);





    static std::string className();

public:
    AcDbEntity* impObj() const;
};

