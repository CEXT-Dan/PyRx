#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
class AcRxValue;
class PyDbObjectId;
//-----------------------------------------------------------------------------------------
//PyDbEvalVariant

//AcDb::DwgDataType doesn't have a point2d option
void makePyDbEvalVariantWrapper();

class PyDbEvalVariant : public PyRxObject
{
public:
    PyDbEvalVariant();
    PyDbEvalVariant(double dVal);
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

    void            setDouble(AcDb::DxfCode groupcode, double value);
    void            setInt16(AcDb::DxfCode groupcode, short value);
    void            setInt32(AcDb::DxfCode groupcode, Adesk::Int32 value);
    void            setString(AcDb::DxfCode groupcode, const std::string& value);
    void            setObjectId(AcDb::DxfCode groupcode, const PyDbObjectId& value);
    void            setPoint3d(AcDb::DxfCode groupcode, const AcGePoint3d& value);
    void            setPoint2d(AcDb::DxfCode groupcode, const AcGePoint2d& value);

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
    void copyFrom(const PyRxObject& pOther);
    AcDb::DwgDataType getType() const;

    static PyRxClass desc();
    static std::string className();
public:
    AcDbEvalVariant* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyDbDynBlockReferenceProperty
void makePyDbDynBlockReferencePropertyWrapper();

class PyDbDynBlockReferenceProperty
{
public:
    PyDbDynBlockReferenceProperty();
    PyDbDynBlockReferenceProperty(const AcDbDynBlockReferenceProperty& other);

    bool operator==(const PyDbDynBlockReferenceProperty& other);

    PyDbObjectId          blockId() const;
    std::string           propertyName() const;
    AcDb::DwgDataType     propertyType() const;
    bool                  readOnly() const;
    bool                  show() const;
    bool                  visibleInCurrentVisibilityState() const;
    std::string           description()    const;
    AcDbDynBlockReferenceProperty::UnitsType unitsType() const;
    boost::python::list   getAllowedValues();
    PyDbEvalVariant       value() const;
    void                  setValue(const PyDbEvalVariant& value);

    static std::string className();
public:
    AcDbDynBlockReferenceProperty* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbDynBlockReferenceProperty> m_pyImp;
};

#pragma pack (pop)