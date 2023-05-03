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
