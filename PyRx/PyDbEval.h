#pragma once
#include "PyRxObject.h"

class PyDbObjectId;
//-----------------------------------------------------------------------------------------
//PyDbEvalVariant
void makePyDbEvalVariantWrapper();

class PyDbEvalVariant : public PyRxObject
{
public:
    PyDbEvalVariant();
    PyDbEvalVariant(double       dVal);
    PyDbEvalVariant(short        iVal);
    PyDbEvalVariant(const std::string& szVal);
    PyDbEvalVariant(Adesk::Int32 lVal);
    PyDbEvalVariant(const PyDbObjectId& id);
    PyDbEvalVariant(const AcGePoint2d& pt);
    PyDbEvalVariant(const AcGePoint3d& pt);
    PyDbEvalVariant(const boost::python::tuple& rb);
    PyDbEvalVariant(const AcDbEvalVariant& ptr);
    PyDbEvalVariant(AcDbEvalVariant* ptr, bool autoDelete);
    ~PyDbEvalVariant() = default;
    bool operator < (const PyDbEvalVariant& val) const;
    bool operator > (const PyDbEvalVariant& val) const;
    bool operator <= (const PyDbEvalVariant& val) const;
    bool operator >= (const PyDbEvalVariant& val) const;
    bool operator == (const PyDbEvalVariant& val) const;
    bool operator != (const PyDbEvalVariant& val) const;

    Acad::ErrorStatus setValue1(AcDb::DxfCode groupcode, double value);
    Acad::ErrorStatus setValue2(AcDb::DxfCode groupcode, short value);
    Acad::ErrorStatus setValue3(AcDb::DxfCode groupcode, Adesk::Int32 value);
    Acad::ErrorStatus setValue4(AcDb::DxfCode groupcode, const std::string& value);
    Acad::ErrorStatus setValue5(AcDb::DxfCode groupcode, const PyDbObjectId& value);
    Acad::ErrorStatus setValue6(AcDb::DxfCode groupcode, const AcGePoint3d& value);
    Acad::ErrorStatus setValue7(AcDb::DxfCode groupcode, const AcGePoint2d& value);

    double          getDouble();
    short           getInt16();
    Int32           getInt32();
    std::string     getString();
    PyDbObjectId    getObjectId();
    AcGePoint2d     getPoint2d();
    AcGePoint3d     getPoint3d();

    //Acad::ErrorStatus toAcRxValue(const AcRxValueType& type, AcRxValue& value) const;
    //Acad::ErrorStatus fromAcRxValue(const AcRxValue& value);

    void clear();
    Acad::ErrorStatus copyFrom(const PyRxObject& pOther);

    static PyRxClass desc();
    static std::string className();
public:
    AcDbEvalVariant* impObj(const std::source_location& src = std::source_location::current()) const;
};

