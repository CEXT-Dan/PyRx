#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
class AcRxValue;
class PyDbObjectId;
//-----------------------------------------------------------------------------------------
//PyDbEvalVariant

//AcDb::DwgDataType doesn't have a point2d option
//-----------------------------------------------------------------------------------------
//PyDbEvalVariant
void makePyDbEvalVariantWrapper();

class PyDbEvalVariant : public PyRxObject
{
public:
    PyDbEvalVariant();
    PyDbEvalVariant(double dVal);
    PyDbEvalVariant(const std::string& szVal);
    PyDbEvalVariant(Adesk::Int32 lVal);
    PyDbEvalVariant(Adesk::Int32 lVal, bool isShort);
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

    //TODO: overload with default groupcodes;
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
    int               getRbType() const;

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

//-----------------------------------------------------------------------------------------
//PyDbAcValue
void makePyDbAcValueWrapper();

class PyDbAcValue : public PyRxObject
{
public:
    PyDbAcValue();
    PyDbAcValue(double fValue);
    PyDbAcValue(Adesk::Int32 lValue);
    PyDbAcValue(const std::string& pszValue);
    PyDbAcValue(const PyDbObjectId& id);
    PyDbAcValue(const AcGePoint2d& pt);
    PyDbAcValue(const AcGePoint3d& pt);
    PyDbAcValue(const AcValue& pt);
    PyDbAcValue(AcValue* ptr, bool autoDelete);
    ~PyDbAcValue() = default;

    bool                reset1(void);
    bool                reset2(AcValue::DataType nDataType);
    bool                resetValue(void);
    AcValue::DataType   dataType(void) const;
    AcValue::UnitType   unitType(void) const;
    bool                setUnitType(AcValue::UnitType nUnitType);
    std::string         getFormat(void) const;
    bool                setFormat(const std::string& pszFormat);
    bool                isValid(void) const;

    void                setDouble(double value);
    void                setInt32(Adesk::Int32 value);
    void                setString(const std::string& value);
    void                setObjectId(const PyDbObjectId& value);
    void                setPoint3d(const AcGePoint3d& value);
    void                setPoint2d(const AcGePoint2d& value);

    double              getDouble();
    Int32               getInt32();
    std::string         getString();
    PyDbObjectId        getObjectId();
    AcGePoint2d         getPoint2d();
    AcGePoint3d         getPoint3d();

    std::string         format1();
    std::string         format2(AcValue::FormatOption nOption);
    bool                convertTo(AcValue::DataType nDataType, AcValue::UnitType nUnitType);

    static PyRxClass    desc();
    static std::string  className();
public:
    AcValue* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)