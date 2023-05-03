#pragma once
#include "PyDbEntity.h"

class PyDbObjectId;
//-----------------------------------------------------------------------------------
//PyDbRegion
void makePyDbDimensionWrapper();

class PyDbDimension : public PyDbEntity
{
public:
    PyDbDimension(AcDbDimension* ptr, bool autoDelete);
    PyDbDimension(const PyDbObjectId& id, AcDb::OpenMode mode);

    boost::python::tuple textDefinedSize() const;
    void setTextDefinedSize(double width, double height);
    void resetTextDefinedSize();

    AcGePoint3d textPosition() const;
    Acad::ErrorStatus setTextPosition(const AcGePoint3d& val);

    Adesk::Boolean isUsingDefaultTextPosition() const;

    Acad::ErrorStatus   useSetTextPosition();
    Acad::ErrorStatus   useDefaultTextPosition();
    Acad::ErrorStatus   setUsingDefaultTextPosition(bool);

    AcGeVector3d        normal() const;
    Acad::ErrorStatus   setNormal(const AcGeVector3d&);

    double              elevation() const;
    Acad::ErrorStatus   setElevation(double val);

    std::string          dimensionText() const;
    Acad::ErrorStatus    setDimensionText(const  std::string& val);

    double              textRotation() const;
    Acad::ErrorStatus   setTextRotation(double val);

    PyDbObjectId        dimensionStyle() const;
    Acad::ErrorStatus   setDimensionStyle(const PyDbObjectId& val);

    AcDbMText::AttachmentPoint textAttachment() const;
    Acad::ErrorStatus   setTextAttachment(AcDbMText::AttachmentPoint eAtt);

    AcDb::LineSpacingStyle textLineSpacingStyle() const;
    Acad::ErrorStatus   setTextLineSpacingStyle(AcDb::LineSpacingStyle eStyle);

    double              textLineSpacingFactor() const;
    Acad::ErrorStatus   setTextLineSpacingFactor(double dFactor);

    //Acad::ErrorStatus   getDimstyleData(AcDbDimStyleTableRecord*& pRecord) const;
    //Acad::ErrorStatus   setDimstyleData(AcDbDimStyleTableRecord* pNewData);
    Acad::ErrorStatus   setDimstyleData(const PyDbObjectId& newDataId);

    double              horizontalRotation() const;
    Acad::ErrorStatus   setHorizontalRotation(double newVal);

    PyDbObjectId        dimBlockId() const;
    Acad::ErrorStatus   setDimBlockId(const PyDbObjectId& val);
    AcGePoint3d         dimBlockPosition() const;
    Acad::ErrorStatus   setDimBlockPosition(const AcGePoint3d& val);
    Acad::ErrorStatus   recomputeDimBlock1();
    Acad::ErrorStatus   recomputeDimBlock2(bool forceUpdate);
    Acad::ErrorStatus   generateLayout();
    double              measurement();


    static std::string className();
public:
    AcDbDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyDb2LineAngularDimension
void makePyDb2LineAngularDimensionWrapper();

class PyDb2LineAngularDimension : public PyDbDimension
{
public:
    PyDb2LineAngularDimension();
    PyDb2LineAngularDimension(AcDb2LineAngularDimension* ptr, bool autoDelete);
    PyDb2LineAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDb2LineAngularDimension* impObj() const;
};


//-----------------------------------------------------------------------------------
//AcDb3PointAngularDimension
void makeAcDb3PointAngularDimensionWrapper();

class PyDb3PointAngularDimension : public PyDbDimension
{
public:
    PyDb3PointAngularDimension();
    PyDb3PointAngularDimension(AcDb3PointAngularDimension* ptr, bool autoDelete);
    PyDb3PointAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDb3PointAngularDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcDbAlignedDimension
void makeAlignedDimensionWrapper();

class PyDbAlignedDimension : public PyDbDimension
{
public:
    PyDbAlignedDimension();
    PyDbAlignedDimension(AcDbAlignedDimension* ptr, bool autoDelete);
    PyDbAlignedDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbAlignedDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcDbArcDimension
void makeArcDimensionWrapper();

class PyDbArcDimension : public PyDbDimension
{
public:
    PyDbArcDimension();
    PyDbArcDimension(AcDbArcDimension* ptr, bool autoDelete);
    PyDbArcDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbArcDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcDbDiametricDimension
void makeDiametricDimensionWrapper();

class PyDbDiametricDimension : public PyDbDimension
{
public:
    PyDbDiametricDimension();
    PyDbDiametricDimension(AcDbDiametricDimension* ptr, bool autoDelete);
    PyDbDiametricDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbDiametricDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcDbOrdinateDimension
void makeOrdinateDimensionWrapper();

class PyDbOrdinateDimension : public PyDbDimension
{
public:
    PyDbOrdinateDimension();
    PyDbOrdinateDimension(AcDbOrdinateDimension* ptr, bool autoDelete);
    PyDbOrdinateDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbOrdinateDimension* impObj() const;
};


//-----------------------------------------------------------------------------------
//AcDbRadialDimension
void makeRadialDimensionWrapper();

class PyDbRadialDimension : public PyDbDimension
{
public:
    PyDbRadialDimension();
    PyDbRadialDimension(AcDbRadialDimension* ptr, bool autoDelete);
    PyDbRadialDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbRadialDimension* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcDbRadialDimensionLarge
void makeRadialDimensionLargeWrapper();

class PyDbRadialDimensionLarge : public PyDbDimension
{
public:
    PyDbRadialDimensionLarge();
    PyDbRadialDimensionLarge(AcDbRadialDimensionLarge* ptr, bool autoDelete);
    PyDbRadialDimensionLarge(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbRadialDimensionLarge* impObj() const;
};


//-----------------------------------------------------------------------------------
//AcDbRotatedDimension
void makeRotatedDimensionWrapper();

class PyDbRotatedDimension : public PyDbDimension
{
public:
    PyDbRotatedDimension();
    PyDbRotatedDimension(AcDbRotatedDimension* ptr, bool autoDelete);
    PyDbRotatedDimension(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbRotatedDimension* impObj() const;
};
