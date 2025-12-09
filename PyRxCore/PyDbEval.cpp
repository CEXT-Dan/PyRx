#include "stdafx.h"
#include "PyDbEval.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyDbEvalVariant
void makePyDbEvalVariantWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- bval: bool\n"
        "- ival: int\n"
        "- ival: int, isInt16: bool\n"
        "- fval: float\n"
        "- sval: str\n"
        "- idval: PyDb.ObjectId\n"
        "- pnt2dval: PyGe.Point2d\n"
        "- pnt3dval: PyGe.Point3d\n";

    PyDocString DS("PyDb.EvalVariant");
    class_<PyDbEvalVariant, bases<PyRxObject>>("EvalVariant")
        .def(init<>())
        .def(init<double>())
        .def(init<Adesk::Int32>())
        .def(init<Adesk::Int32, bool>())
        .def(init<const std::string&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const AcGePoint2d&>())
        .def(init<const AcGePoint3d&>(DS.CTOR(ctords, 4506)))
        .def("setDouble", &PyDbEvalVariant::setDouble, DS.ARGS({ "code: PyDb.DxfCode", "val: float" }))
        .def("setInt16", &PyDbEvalVariant::setInt16, DS.ARGS({ "code: PyDb.DxfCode", "val: int" }))
        .def("setInt32", &PyDbEvalVariant::setInt32, DS.ARGS({ "code: PyDb.DxfCode", "val: int" }))
        .def("setString", &PyDbEvalVariant::setString, DS.ARGS({ "code: PyDb.DxfCode", "val: str" }))
        .def("setObjectId", &PyDbEvalVariant::setObjectId, DS.ARGS({ "code: PyDb.DxfCode", "id: PyDb.ObjectId" }))
        .def("setPoint3d", &PyDbEvalVariant::setPoint3d, DS.ARGS({ "code: PyDb.DxfCode", "pt: PyGe.Point3d" }))
        .def("setPoint2d", &PyDbEvalVariant::setPoint2d, DS.ARGS({ "code: PyDb.DxfCode", "pt: PyGe.Point2d" }))
        .def("getDouble", &PyDbEvalVariant::getDouble, DS.ARGS())
        .def("getInt16", &PyDbEvalVariant::getInt16, DS.ARGS())
        .def("getInt32", &PyDbEvalVariant::getInt32, DS.ARGS())
        .def("getString", &PyDbEvalVariant::getString, DS.ARGS())
        .def("getObjectId", &PyDbEvalVariant::getObjectId, DS.ARGS())
        .def("getPoint2d", &PyDbEvalVariant::getPoint2d, DS.ARGS())
        .def("getPoint3d", &PyDbEvalVariant::getPoint3d, DS.ARGS())
        .def("clear", &PyDbEvalVariant::clear, DS.ARGS(4509))
        .def("copyFrom", &PyDbEvalVariant::copyFrom, DS.ARGS({ "otherObject: PyRx.RxObject" }))
        .def("getType", &PyDbEvalVariant::getType, DS.ARGS())
        .def("getRbType", &PyDbEvalVariant::getRbType, DS.ARGS())
        .def("toString", &PyDbEvalVariant::toString, DS.ARGS())

        //operators
        .def("__eq__", &PyDbEvalVariant::operator==, DS.ARGS({ "other: PyDb.EvalVariant" }))
        .def("__ne__", &PyDbEvalVariant::operator!=, DS.ARGS({ "other: PyDb.EvalVariant" }))
        .def("__lt__", &PyDbEvalVariant::operator<, DS.ARGS({ "other: PyDb.EvalVariant" }))
        .def("__gt__", &PyDbEvalVariant::operator>, DS.ARGS({ "other: PyDb.EvalVariant" }))
        .def("__le__", &PyDbEvalVariant::operator<=, DS.ARGS({ "other: PyDb.EvalVariant" }))
        .def("__ge__", &PyDbEvalVariant::operator>=, DS.ARGS({ "other: PyDb.EvalVariant" }))

        // to string
        .def("__str__", &PyDbEvalVariant::toString, DS.ARGS())
        .def("__repr__", &PyDbEvalVariant::toString, DS.ARGS())
        //static
        .def("className", &PyDbEvalVariant::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbEvalVariant::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyDbEvalVariant::PyDbEvalVariant()
    :PyRxObject(new AcDbEvalVariant(), true, false)
{
}

PyDbEvalVariant::PyDbEvalVariant(double dVal)
    : PyRxObject(new AcDbEvalVariant(dVal), true, false)
{
}

PyDbEvalVariant::PyDbEvalVariant(const std::string& szVal)
    : PyRxObject(new AcDbEvalVariant(utf8_to_wstr(szVal).c_str()), true, false)
{
}

PyDbEvalVariant::PyDbEvalVariant(Adesk::Int32 lVal)
    : PyRxObject(new AcDbEvalVariant(lVal), true, false)
{
}

PyDbEvalVariant::PyDbEvalVariant(Adesk::Int32 lVal, bool isShort)
    : PyRxObject(new AcDbEvalVariant(lVal), true, false)
{
    if (isShort)
    {
        impObj()->clear();
        impObj()->restype = AcDb::kDxfInt16;
        impObj()->resval.rint = Adesk::Int16(lVal);
    }
}

PyDbEvalVariant::PyDbEvalVariant(const PyDbObjectId& id)
    : PyRxObject(new AcDbEvalVariant(id.m_id), true, false)
{
}

PyDbEvalVariant::PyDbEvalVariant(const AcGePoint2d& pt)
    : PyRxObject(new AcDbEvalVariant(pt), true, false)
{
}

PyDbEvalVariant::PyDbEvalVariant(const AcGePoint3d& pt)
    : PyRxObject(new AcDbEvalVariant(pt), true, false)
{
}

//TODO:!
PyDbEvalVariant::PyDbEvalVariant(const boost::python::tuple& rb)
    : PyRxObject(nullptr, false, false)
{
    throw PyErrorStatusException(eNotImplementedYet);
}

PyDbEvalVariant::PyDbEvalVariant(const AcDbEvalVariant& ptr)
    : PyRxObject(new AcDbEvalVariant(ptr), true, false)
{
}

PyDbEvalVariant::PyDbEvalVariant(AcDbEvalVariant* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

bool PyDbEvalVariant::operator<(const PyDbEvalVariant& val) const
{
    return *impObj() < *val.impObj();
}

bool PyDbEvalVariant::operator>(const PyDbEvalVariant& val) const
{
    return *impObj() > *val.impObj();
}

bool PyDbEvalVariant::operator<=(const PyDbEvalVariant& val) const
{
    return *impObj() <= *val.impObj();
}

bool PyDbEvalVariant::operator>=(const PyDbEvalVariant& val) const
{
    return *impObj() >= *val.impObj();
}

bool PyDbEvalVariant::operator==(const PyDbEvalVariant& val) const
{
    return *impObj() == *val.impObj();
}

bool PyDbEvalVariant::operator!=(const PyDbEvalVariant& val) const
{
    return *impObj() != *val.impObj();
}

void PyDbEvalVariant::setDouble(AcDb::DxfCode groupcode, double value) const
{
    impObj()->clear();
    impObj()->restype = groupcode;
    impObj()->resval.rreal = value;
}

void PyDbEvalVariant::setInt16(AcDb::DxfCode groupcode, short value) const
{
    impObj()->clear();
    impObj()->restype = groupcode;
    impObj()->resval.rint = value;
}

void PyDbEvalVariant::setInt32(AcDb::DxfCode groupcode, Adesk::Int32 value) const
{
    impObj()->clear();
    impObj()->restype = groupcode;
    impObj()->resval.rlong = value;
}

void PyDbEvalVariant::setString(AcDb::DxfCode groupcode, const std::string& value) const
{
    impObj()->clear();
    impObj()->restype = groupcode;
    impObj()->resval.rstring = _wcsdup(utf8_to_wstr(value).c_str());
}

void PyDbEvalVariant::setObjectId(AcDb::DxfCode groupcode, const PyDbObjectId& value) const
{
    impObj()->clear();
    impObj()->restype = groupcode;
    PyThrowBadEs(acdbGetAdsName(impObj()->resval.rlname, value.m_id));
}

void PyDbEvalVariant::setPoint3d(AcDb::DxfCode groupcode, const AcGePoint3d& value) const
{
    impObj()->clear();
    impObj()->restype = groupcode;
    impObj()->resval.rpoint[0] = value[0];
    impObj()->resval.rpoint[1] = value[1];
    impObj()->resval.rpoint[2] = value[2];
}

void PyDbEvalVariant::setPoint2d(AcDb::DxfCode groupcode, const AcGePoint2d& value) const
{
    impObj()->clear();
    impObj()->restype = groupcode;
    impObj()->resval.rpoint[0] = value[0];
    impObj()->resval.rpoint[1] = value[1];
    impObj()->resval.rpoint[2] = 0.0;
}

double PyDbEvalVariant::getDouble() const
{
    double val = 0;
    PyThrowBadEs(impObj()->getValue(val));
    return val;
}

short PyDbEvalVariant::getInt16() const
{
    short val = 0;
    PyThrowBadEs(impObj()->getValue(val));
    return val;
}

Int32 PyDbEvalVariant::getInt32() const
{
    Int32 val = 0;
    PyThrowBadEs(impObj()->getValue(val));
    return val;
}

std::string PyDbEvalVariant::getString() const
{
    AcString val;
    PyThrowBadEs(impObj()->getValue(val));
    return wstr_to_utf8(val);
}

PyDbObjectId PyDbEvalVariant::getObjectId() const
{
    PyDbObjectId val;
    if (impObj()->restype == RTENAME)
    {
        PyThrowBadEs(acdbGetObjectId(val.m_id, impObj()->resval.rlname));
        return val;
    }
    switch (impObj()->getType())
    {
        case AcDb::kDwgHardOwnershipId:
        case AcDb::kDwgSoftOwnershipId:
        case AcDb::kDwgHardPointerId:
        case AcDb::kDwgSoftPointerId:
            PyThrowBadEs(acdbGetObjectId(val.m_id, impObj()->resval.rlname));
            break;
        default:
            throw PyErrorStatusException(eInvalidInput);
    }
    return val;
}

AcGePoint2d PyDbEvalVariant::getPoint2d() const
{
    AcGePoint2d val;
    if (impObj()->restype == RTPOINT)
    {
        val[0] = impObj()->resval.rpoint[0];
        val[1] = impObj()->resval.rpoint[1];
        return val;
    }
    throw PyErrorStatusException(eInvalidInput);
}

AcGePoint3d PyDbEvalVariant::getPoint3d() const
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->getValue(val));
    return val;
}

void PyDbEvalVariant::clear() const
{
    impObj()->clear();
}

void PyDbEvalVariant::copyFrom(const PyRxObject& pOther) const
{
    return PyThrowBadEs(impObj()->copyFrom(pOther.impObj()));
}

AcDb::DwgDataType PyDbEvalVariant::getType() const
{
    return impObj()->getType();
}

int PyDbEvalVariant::getRbType() const
{
    return impObj()->restype;
}

std::string PyDbEvalVariant::toString() const
{
    std::string outstr;
    switch (impObj()->getType())
    {
        case AcDb::kDwgNull:
        {
            outstr = "kDwgNull";
            break;
        }
        case AcDb::kDwgReal:
        {
            double val = 0.0;
            PyThrowBadEs(impObj()->getValue(val));
            outstr = std::format("{}", val);
            break;
        }
        case AcDb::kDwgInt64:
        {
            Adesk::Int64 val = 0;
            outstr = std::format("{}", impObj()->resval.mnInt64);
            break;
        }
        case AcDb::kDwgInt32:
        {
            Adesk::Int32 val = 0;
            PyThrowBadEs(impObj()->getValue(val));
            outstr = std::format("{}", val);
            break;
        }
        case AcDb::kDwgInt16:
        {
            Adesk::Int16 val = 0;
            PyThrowBadEs(impObj()->getValue(val));
            outstr = std::format("{}", val);
            break;
        }
        case AcDb::kDwgInt8:
        {
            Adesk::Int8 val = 0;
            outstr = std::format("{}", impObj()->resval.rint);
            break;
        }
        case AcDb::kDwgText:
        {
            AcString val;
            PyThrowBadEs(impObj()->getValue(val));
            outstr = std::format("{}", wstr_to_utf8(val).c_str());
            break;
        }
        case AcDb::kDwgBChunk:
        {
            outstr = "kDwgBChunk";
            break;
        }
        case AcDb::kDwgHandle:
#ifdef never
        {
            //docs kDwgHandle  ads_name in a resbuf
            AcDbHandle hwnd;
            hwnd.copyFromOldType(impObj()->resval.ihandle);
            wchar_t buf[AcDbHandle::kStrSiz] = { 0 };
            if (hwnd.getIntoAsciiBuffer(buf, AcDbHandle::kStrSiz) != true)
                throw PyErrorStatusException(eBrokenHandle);
            outstr = wstr_to_utf8(buf);
            break;
        }
#endif
        case AcDb::kDwgHardOwnershipId:
        case AcDb::kDwgSoftOwnershipId:
        case AcDb::kDwgHardPointerId:
        case AcDb::kDwgSoftPointerId:
        {
            AcDbObjectId id;
            PyThrowBadEs(acdbGetObjectId(id, impObj()->resval.rlname));
            outstr = std::format("{:x}", (INT_PTR)(AcDbStub*)id);
            break;
        }
        case AcDb::kDwg3Real:
        {
            AcGePoint3d val;
            PyThrowBadEs(impObj()->getValue(val));
            outstr = std::format("({},{},{})", val.x, val.y, val.z);
            break;
        }
        default:
            break;
    }
    return outstr;
}

PyRxClass PyDbEvalVariant::desc()
{
    return PyRxClass(AcDbEvalVariant::desc(), false);
}

std::string PyDbEvalVariant::className()
{
    return "AcDbEvalVariant";
}

AcDbEvalVariant* PyDbEvalVariant::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbEvalVariant*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyDbDynBlockReferenceProperty
void makePyDbDynBlockReferencePropertyWrapper()
{
    PyDocString DS("PyDb.DynBlockReferenceProperty");
    class_<PyDbDynBlockReferenceProperty>("DynBlockReferenceProperty")
        .def(init<>(DS.ARGS(4193)))
        .def("blockId", &PyDbDynBlockReferenceProperty::blockId, DS.ARGS(4197))
        .def("propertyName", &PyDbDynBlockReferenceProperty::propertyName, DS.ARGS(4200))
        .def("propertyType", &PyDbDynBlockReferenceProperty::propertyType, DS.ARGS(4201))
        .def("readOnly", &PyDbDynBlockReferenceProperty::readOnly, DS.ARGS(4202))
        .def("show", &PyDbDynBlockReferenceProperty::show, DS.ARGS(4204))
        .def("visibleInCurrentVisibilityState", &PyDbDynBlockReferenceProperty::visibleInCurrentVisibilityState, DS.ARGS(4208))
        .def("description", &PyDbDynBlockReferenceProperty::description, DS.ARGS(4198))
        .def("unitsType", &PyDbDynBlockReferenceProperty::unitsType, DS.ARGS(4205))
        .def("getAllowedValues", &PyDbDynBlockReferenceProperty::getAllowedValues, DS.ARGS(4199))
        .def("value", &PyDbDynBlockReferenceProperty::value, DS.ARGS(4207))
        .def("setValue", &PyDbDynBlockReferenceProperty::setValue, DS.ARGS({ "val: PyDb.EvalVariant" }, 4203))
        //operators
        .def("__eq__", &PyDbDynBlockReferenceProperty::operator==, DS.ARGS({ "other: PyDb.DynBlockReferenceProperty" }, 4194))
        //static
        .def("className", &PyDbDynBlockReferenceProperty::className, DS.SARGS()).staticmethod("className")
        ;
    enum_<AcDbDynBlockReferenceProperty::UnitsType>("DynUnitsType")
        .value("kNoUnits", AcDbDynBlockReferenceProperty::UnitsType::kNoUnits)
        .value("kAngular", AcDbDynBlockReferenceProperty::UnitsType::kAngular)
        .value("kDistance", AcDbDynBlockReferenceProperty::UnitsType::kDistance)
        .value("kArea", AcDbDynBlockReferenceProperty::UnitsType::kArea)
        .export_values()
        ;
}

PyDbDynBlockReferenceProperty::PyDbDynBlockReferenceProperty()
    : m_pyImp(new AcDbDynBlockReferenceProperty())
{
}

PyDbDynBlockReferenceProperty::PyDbDynBlockReferenceProperty(const AcDbDynBlockReferenceProperty& other)
    : m_pyImp(new AcDbDynBlockReferenceProperty(other))
{
}

bool PyDbDynBlockReferenceProperty::operator==(const PyDbDynBlockReferenceProperty& other)
{
    return impObj()->blockId() == other.impObj()->blockId();
}

PyDbObjectId PyDbDynBlockReferenceProperty::blockId() const
{
    return PyDbObjectId(impObj()->blockId());
}

std::string PyDbDynBlockReferenceProperty::propertyName() const
{
    return wstr_to_utf8(impObj()->propertyName());
}

AcDb::DwgDataType PyDbDynBlockReferenceProperty::propertyType() const
{
    return impObj()->propertyType();
}

bool PyDbDynBlockReferenceProperty::readOnly() const
{
    return impObj()->readOnly();
}

bool PyDbDynBlockReferenceProperty::show() const
{
    return impObj()->show();
}

bool PyDbDynBlockReferenceProperty::visibleInCurrentVisibilityState() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return impObj()->visibleInCurrentVisibilityState();
#endif
}

std::string PyDbDynBlockReferenceProperty::description() const
{
    return wstr_to_utf8(impObj()->description());
}

AcDbDynBlockReferenceProperty::UnitsType PyDbDynBlockReferenceProperty::unitsType() const
{
    return impObj()->unitsType();
}

boost::python::list PyDbDynBlockReferenceProperty::getAllowedValues() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcDbEvalVariantArray values;
    PyThrowBadEs(impObj()->getAllowedValues(values));
    for (const auto& item : values)
        pyList.append(PyDbEvalVariant(item));
    return pyList;
}

PyDbEvalVariant PyDbDynBlockReferenceProperty::value() const
{
    return PyDbEvalVariant(impObj()->value());
}

void PyDbDynBlockReferenceProperty::setValue(const PyDbEvalVariant& value) const
{
    return PyThrowBadEs(impObj()->setValue(*value.impObj()));
}

std::string PyDbDynBlockReferenceProperty::className()
{
    return "AcDbDynBlockReferenceProperty";
}

AcDbDynBlockReferenceProperty* PyDbDynBlockReferenceProperty::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDynBlockReferenceProperty*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyDbAcValue
constexpr const std::string_view ctords = "Overloads:\n"
"- None: Any\n"
"- ival: int\n"
"- fval: float\n"
"- sval: str\n"
"- idval: PyDb.ObjectId\n"
"- pnt2dval: PyGe.Point2d\n"
"- pnt3dval: PyGe.Point3d\n";

void makePyDbAcValueWrapper()
{
    PyDocString DS("PyDb.AcValue");
    class_<PyDbAcValue, bases<PyRxObject>>("AcValue")
        .def(init<>())
        .def(init<double>())
        .def(init<Adesk::Int32>())
        .def(init<const std::string&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const AcGePoint2d&>())
        .def(init<const AcGePoint3d&>(DS.CTOR(ctords)))
        .def("reset", &PyDbAcValue::reset1)
        .def("reset", &PyDbAcValue::reset2, DS.ARGS({ "nDataType: PyDb.ValueDataType=PyDb.ValueDataType.kUnknown" }))
        .def("resetValue", &PyDbAcValue::resetValue, DS.ARGS())
        .def("dataType", &PyDbAcValue::dataType, DS.ARGS())
        .def("unitType", &PyDbAcValue::unitType, DS.ARGS())
        .def("setUnitType", &PyDbAcValue::setUnitType, DS.ARGS({ "val: PyDb.ValueUnitType" }))
        .def("getFormat", &PyDbAcValue::getFormat, DS.ARGS())
        .def("setFormat", &PyDbAcValue::setFormat, DS.ARGS({ "val: str" }))
        .def("isValid", &PyDbAcValue::isValid, DS.ARGS())
        .def("setDouble", &PyDbAcValue::setDouble, DS.ARGS({ "val: float" }))
        .def("setInt32", &PyDbAcValue::setInt32, DS.ARGS({ "val: int" }))
        .def("setString", &PyDbAcValue::setString, DS.ARGS({ "val: str" }))
        .def("setObjectId", &PyDbAcValue::setObjectId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("setPoint3d", &PyDbAcValue::setPoint3d, DS.ARGS({ "pt: PyGe.Point2d" }))
        .def("setPoint2d", &PyDbAcValue::setPoint2d, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("getDouble", &PyDbAcValue::getDouble, DS.ARGS())
        .def("getInt32", &PyDbAcValue::getInt32, DS.ARGS())
        .def("getString", &PyDbAcValue::getString, DS.ARGS())
        .def("getObjectId", &PyDbAcValue::getObjectId, DS.ARGS())
        .def("getPoint2d", &PyDbAcValue::getPoint2d, DS.ARGS())
        .def("getPoint3d", &PyDbAcValue::getPoint3d, DS.ARGS())
        .def("format", &PyDbAcValue::format1)
        .def("format", &PyDbAcValue::format2, DS.ARGS({ "val: PyDb.ValueFormatOption=PyDb.ValueFormatOption.kFormatOptionNone" }))
        .def("convertTo", &PyDbAcValue::convertTo, DS.ARGS({ "dt: PyDb.ValueDataType", "vt: PyDb.ValueUnitType" }))
        .def("className", &PyDbAcValue::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAcValue::desc, DS.SARGS(15560)).staticmethod("desc")

        .def("__str__", &PyDbAcValue::format1, DS.ARGS())
        .def("__repr__", &PyDbAcValue::format1, DS.ARGS())
        ;
}

PyDbAcValue::PyDbAcValue()
    : PyDbAcValue(new AcValue(), true)
{
}

PyDbAcValue::PyDbAcValue(Adesk::Int32 lValue)
    : PyDbAcValue(new AcValue(lValue), true)
{
}

PyDbAcValue::PyDbAcValue(double fValue)
    : PyDbAcValue(new AcValue(fValue), true)
{
}

PyDbAcValue::PyDbAcValue(const std::string& pszValue)
    : PyDbAcValue(new AcValue(utf8_to_wstr(pszValue).c_str()), true)
{
}

PyDbAcValue::PyDbAcValue(const PyDbObjectId& id)
    : PyDbAcValue(new AcValue(id.m_id), true)
{
}

PyDbAcValue::PyDbAcValue(const AcGePoint2d& pt)
    : PyDbAcValue(new AcValue(pt), true)
{
}

PyDbAcValue::PyDbAcValue(const AcGePoint3d& pt)
    : PyDbAcValue(new AcValue(pt), true)
{
}

PyDbAcValue::PyDbAcValue(AcValue* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

PyDbAcValue::PyDbAcValue(const AcValue& pt)
    : PyDbAcValue(new AcValue(pt), true)
{
}

bool PyDbAcValue::reset1(void) const
{
    return impObj()->reset();
}

bool PyDbAcValue::reset2(AcValue::DataType nDataType) const
{
    return impObj()->reset(nDataType);
}

bool PyDbAcValue::resetValue(void) const
{
    return impObj()->resetValue();
}

AcValue::DataType PyDbAcValue::dataType(void) const
{
    return impObj()->dataType();
}

AcValue::UnitType PyDbAcValue::unitType(void) const
{
    return impObj()->unitType();
}

bool PyDbAcValue::setUnitType(AcValue::UnitType nUnitType) const
{
    return impObj()->setUnitType(nUnitType);
}

std::string PyDbAcValue::getFormat(void) const
{
    return wstr_to_utf8(impObj()->getFormat());
}

bool PyDbAcValue::setFormat(const std::string& pszFormat) const
{
    return impObj()->setFormat(utf8_to_wstr(pszFormat).c_str());
}

bool PyDbAcValue::isValid(void) const
{
    return impObj()->isValid();
}

void PyDbAcValue::setDouble(double value) const
{
    PyThrowFalse(impObj()->set(value));
}

void PyDbAcValue::setInt32(Adesk::Int32 value) const
{
    PyThrowFalse(impObj()->set(value));
}

void PyDbAcValue::setString(const std::string& value) const
{
    PyThrowFalse(impObj()->set(utf8_to_wstr(value).c_str()));
}

void PyDbAcValue::setObjectId(const PyDbObjectId& value) const
{
    PyThrowFalse(impObj()->set(value.m_id));
}

void PyDbAcValue::setPoint3d(const AcGePoint3d& value) const
{
    PyThrowFalse(impObj()->set(value));
}

void PyDbAcValue::setPoint2d(const AcGePoint2d& value) const
{
    PyThrowFalse(impObj()->set(value));
}

double PyDbAcValue::getDouble() const
{
    double value;
    PyThrowFalse(impObj()->get(value));
    return value;
}

Int32 PyDbAcValue::getInt32() const
{
    Int32 value;
    PyThrowFalse(impObj()->get(value));
    return value;
}

std::string PyDbAcValue::getString() const
{
    RxAutoOutStr value;
    PyThrowFalse(impObj()->get(value.buf));
    return value.str();
}

PyDbObjectId PyDbAcValue::getObjectId() const
{
    PyDbObjectId value;
    PyThrowFalse(impObj()->get(value.m_id));
    return value;
}

AcGePoint2d PyDbAcValue::getPoint2d() const
{
    AcGePoint2d value;
    PyThrowFalse(impObj()->get(value));
    return value;
}

AcGePoint3d PyDbAcValue::getPoint3d() const
{
    AcGePoint3d value;
    PyThrowFalse(impObj()->get(value));
    return value;
}

std::string PyDbAcValue::format1() const
{
    return wstr_to_utf8(impObj()->format());
}

std::string PyDbAcValue::format2(AcValue::FormatOption nOption) const
{
    return wstr_to_utf8(impObj()->format(nOption));
}

bool PyDbAcValue::convertTo(AcValue::DataType nDataType, AcValue::UnitType nUnitType) const
{
    return impObj()->convertTo(nDataType, nUnitType);
}

PyRxClass PyDbAcValue::desc()
{
    return PyRxClass(AcValue::desc(), false);
}

std::string PyDbAcValue::className()
{
    return "AcValue";
}

AcValue* PyDbAcValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcValue*>(m_pyImp.get());
}
