#include "stdafx.h"
#include "PyDbEval.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbEvalVariantWrapper()
{
    class_<PyDbEvalVariant, bases<PyRxObject>>("EvalVariant")
        .def(init<>())
        .def(init<double>())
        .def(init<Adesk::Int32>())
        .def(init<const std::string&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const AcGePoint2d&>())
        .def(init<const AcGePoint3d&>())
        .def("setDouble", &PyDbEvalVariant::setDouble)
        .def("setInt16", &PyDbEvalVariant::setInt16)
        .def("setInt32", &PyDbEvalVariant::setInt32)
        .def("setString", &PyDbEvalVariant::setString)
        .def("setObjectId", &PyDbEvalVariant::setObjectId)
        .def("setPoint3d", &PyDbEvalVariant::setPoint3d)
        .def("setPoint2d", &PyDbEvalVariant::setPoint2d)
        .def("getDouble", &PyDbEvalVariant::getDouble)
        .def("getInt16", &PyDbEvalVariant::getInt16)
        .def("getInt32", &PyDbEvalVariant::getInt32)
        .def("getString", &PyDbEvalVariant::getString)
        .def("getObjectId", &PyDbEvalVariant::getObjectId)
        .def("getPoint2d", &PyDbEvalVariant::getPoint2d)
        .def("getPoint3d", &PyDbEvalVariant::getPoint3d)
        .def("clear", &PyDbEvalVariant::clear)
        .def("copyFrom", &PyDbEvalVariant::copyFrom)
        .def("getType", &PyDbEvalVariant::getType)
        //operators
        .def("__eq__", &PyDbEvalVariant::operator==)
        .def("__ne__", &PyDbEvalVariant::operator!=)
        .def("__lt__", &PyDbEvalVariant::operator<)
        .def("__gt__", &PyDbEvalVariant::operator>)
        .def("__le__", &PyDbEvalVariant::operator<=)
        .def("__ge__", &PyDbEvalVariant::operator>=)
        //static
        .def("className", &PyDbEvalVariant::className).staticmethod("className")
        .def("desc", &PyDbEvalVariant::desc).staticmethod("desc")
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

PyDbEvalVariant::PyDbEvalVariant(const boost::python::tuple& rb)
    : PyRxObject(nullptr, false, false)
{
    throw PyAcadErrorStatus(eNotImplementedYet);
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

Acad::ErrorStatus PyDbEvalVariant::setDouble(AcDb::DxfCode groupcode, double value)
{
    impObj()->restype = groupcode;
    impObj()->resval.rreal = value;
    return eOk;
}

Acad::ErrorStatus PyDbEvalVariant::setInt16(AcDb::DxfCode groupcode, short value)
{
    impObj()->restype = groupcode;
    impObj()->resval.rint = value;
    return eOk;
}

Acad::ErrorStatus PyDbEvalVariant::setInt32(AcDb::DxfCode groupcode, Adesk::Int32 value)
{
    impObj()->restype = groupcode;
    impObj()->resval.rlong = value;
    return eOk;
}

Acad::ErrorStatus PyDbEvalVariant::setString(AcDb::DxfCode groupcode, const std::string& value)
{
    impObj()->restype = groupcode;
    impObj()->resval.rstring = _wcsdup(utf8_to_wstr(value).c_str());
    return eOk;
}

Acad::ErrorStatus PyDbEvalVariant::setObjectId(AcDb::DxfCode groupcode, const PyDbObjectId& value)
{
    impObj()->restype = groupcode;
    return acdbGetAdsName(impObj()->resval.rlname, value.m_id);
}

Acad::ErrorStatus PyDbEvalVariant::setPoint3d(AcDb::DxfCode groupcode, const AcGePoint3d& value)
{
    impObj()->restype = groupcode;
    impObj()->resval.rpoint[0] = value[0];
    impObj()->resval.rpoint[1] = value[1];
    impObj()->resval.rpoint[2] = value[2];
    return eOk;
}

Acad::ErrorStatus PyDbEvalVariant::setPoint2d(AcDb::DxfCode groupcode, const AcGePoint2d& value)
{
    impObj()->restype = groupcode;
    impObj()->resval.rpoint[0] = value[0];
    impObj()->resval.rpoint[1] = value[1];
    return eOk;
}

double PyDbEvalVariant::getDouble()
{
    double val = 0;
    if (auto es = impObj()->getValue(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

short PyDbEvalVariant::getInt16()
{
    short val = 0;
    if (auto es = impObj()->getValue(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

Int32 PyDbEvalVariant::getInt32()
{
    Int32 val = 0;
    if (auto es = impObj()->getValue(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

std::string PyDbEvalVariant::getString()
{
    AcString val;
    if (auto es = impObj()->getValue(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return wstr_to_utf8(val);
}

PyDbObjectId PyDbEvalVariant::getObjectId()
{
    PyDbObjectId val;
    switch (impObj()->getType())
    {
        case AcDb::kDwgHardOwnershipId:
        case AcDb::kDwgSoftOwnershipId:
        case AcDb::kDwgHardPointerId:
        case AcDb::kDwgSoftPointerId:
            if (auto es = acdbGetObjectId(val.m_id, impObj()->resval.rlname); es != eOk)
                throw PyAcadErrorStatus(es);
            break;
        default:
            throw PyAcadErrorStatus(eInvalidInput);
    }
    return val;
}

AcGePoint2d PyDbEvalVariant::getPoint2d()
{
    AcGePoint2d val;
    int restype = impObj()->restype;
    if (restype != RTPOINT)
        throw PyAcadErrorStatus(eInvalidInput);
    val[0] = impObj()->resval.rpoint[0];
    val[1] = impObj()->resval.rpoint[1];
    return val;
}

AcGePoint3d PyDbEvalVariant::getPoint3d()
{
    AcGePoint3d val;
    if (auto es = impObj()->getValue(val); es != eOk)
        throw PyAcadErrorStatus(es);
    return val;
}

void PyDbEvalVariant::clear()
{
    impObj()->clear();
}

Acad::ErrorStatus PyDbEvalVariant::copyFrom(const PyRxObject& pOther)
{
    return impObj()->copyFrom(pOther.impObj());
}

AcDb::DwgDataType PyDbEvalVariant::getType() const
{
    return impObj()->getType();
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

