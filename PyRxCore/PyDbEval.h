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
    virtual ~PyDbEvalVariant() override = default;

    bool operator < (const PyDbEvalVariant& val) const;
    bool operator > (const PyDbEvalVariant& val) const;
    bool operator <= (const PyDbEvalVariant& val) const;
    bool operator >= (const PyDbEvalVariant& val) const;
    bool operator == (const PyDbEvalVariant& val) const;
    bool operator != (const PyDbEvalVariant& val) const;

    //TODO: overload with default groupcodes;
    void            setDouble(AcDb::DxfCode groupcode, double value) const;
    void            setInt16(AcDb::DxfCode groupcode, short value) const;
    void            setInt32(AcDb::DxfCode groupcode, Adesk::Int32 value) const;
    void            setString(AcDb::DxfCode groupcode, const std::string& value) const;
    void            setObjectId(AcDb::DxfCode groupcode, const PyDbObjectId& value) const;
    void            setPoint3d(AcDb::DxfCode groupcode, const AcGePoint3d& value) const;
    void            setPoint2d(AcDb::DxfCode groupcode, const AcGePoint2d& value) const;

    double          getDouble() const;
    short           getInt16() const;
    Int32           getInt32() const;
    std::string     getString() const;
    PyDbObjectId    getObjectId() const;
    AcGePoint2d     getPoint2d() const;
    AcGePoint3d     getPoint3d() const;


    //Acad::ErrorStatus toAcRxValue(const AcRxValueType& type, AcRxValue& value) const;
    //Acad::ErrorStatus fromAcRxValue(const AcRxValue& value);

    void clear() const;
    void copyFrom(const PyRxObject& pOther) const;
    AcDb::DwgDataType getType() const;
    int               getRbType() const;
    std::string       toString() const;

    static PyRxClass desc();
    static std::string className();
public:
    AcDbEvalVariant* impObj(const std::source_location& src = std::source_location::current()) const;
};

inline AcArray<AcDbEvalVariant> PyListToAcDbEvalVariantArray(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    auto vec{ py_list_to_std_vector<PyDbEvalVariant>(iterable) };
    AcArray<AcDbEvalVariant> arr;
    arr.setPhysicalLength(vec.size());
    for (auto& item : vec)
        arr.append(*item.impObj());
    return arr;
}

//-----------------------------------------------------------------------------------------
//PyDbDynBlockReferenceProperty
void makePyDbDynBlockReferencePropertyWrapper();

class PyDbDynBlockReferenceProperty
{
public:
    PyDbDynBlockReferenceProperty();
    PyDbDynBlockReferenceProperty(const AcDbDynBlockReferenceProperty& other);
    ~PyDbDynBlockReferenceProperty() = default;

    bool operator==(const PyDbDynBlockReferenceProperty& other);

    PyDbObjectId          blockId() const;
    std::string           propertyName() const;
    AcDb::DwgDataType     propertyType() const;
    bool                  readOnly() const;
    bool                  show() const;
    bool                  visibleInCurrentVisibilityState() const;
    std::string           description()    const;
    AcDbDynBlockReferenceProperty::UnitsType unitsType() const;
    boost::python::list   getAllowedValues() const;
    PyDbEvalVariant       value() const;
    void                  setValue(const PyDbEvalVariant& value) const;

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
    virtual ~PyDbAcValue() override = default;

    bool                reset1(void) const;
    bool                reset2(AcValue::DataType nDataType) const;
    bool                resetValue(void) const;
    AcValue::DataType   dataType(void) const;
    AcValue::UnitType   unitType(void) const;
    bool                setUnitType(AcValue::UnitType nUnitType) const;
    std::string         getFormat(void) const;
    bool                setFormat(const std::string& pszFormat) const;
    bool                isValid(void) const;

    void                setDouble(double value) const;
    void                setInt32(Adesk::Int32 value) const;
    void                setString(const std::string& value) const;
    void                setObjectId(const PyDbObjectId& value) const;
    void                setPoint3d(const AcGePoint3d& value) const;
    void                setPoint2d(const AcGePoint2d& value) const;

    double              getDouble() const;
    Int32               getInt32() const;
    std::string         getString() const;
    PyDbObjectId        getObjectId() const;
    AcGePoint2d         getPoint2d() const;
    AcGePoint3d         getPoint3d() const;

    std::string         format1() const;
    std::string         format2(AcValue::FormatOption nOption) const;
    bool                convertTo(AcValue::DataType nDataType, AcValue::UnitType nUnitType) const;

    static PyRxClass    desc();
    static std::string  className();
public:
    AcValue* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)