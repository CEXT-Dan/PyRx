#include "stdafx.h"
#include "PyAcadDbObject.h"
#include "PyAcadDbObjectImpl.h"
#include "PyDbObjectId.h"
using namespace boost::python;

void makePyAcadObjectWrapper()
{
    PyDocString DS("AcadObject");
    class_<PyAcadObject>("AcadObject", boost::python::no_init)
        .def("handle", &PyAcadObject::handle, DS.ARGS())
        .def("objectName", &PyAcadObject::objectName, DS.ARGS())
        .def("objectId", &PyAcadObject::objectId, DS.ARGS())
        .def("ownerId", &PyAcadObject::ownerId, DS.ARGS())
        .def("getXData", &PyAcadObject::getXData, DS.ARGS({ "appName: str" }))
        .def("setXdata", &PyAcadObject::setXdata, DS.ARGS())
        .def("delete", &PyAcadObject::clear, DS.ARGS())
        //.def("application", &PyAcadObject::application, DS.ARGS())
        //.def("database", &PyAcadObject::database, DS.ARGS())
        //.def("extensionDictionary", &PyAcadObject::extensionDictionary, DS.ARGS())
        //.def("document", &PyAcadObject::document, DS.ARGS())
        .def("hasExtensionDictionary", &PyAcadObject::hasExtensionDictionary, DS.ARGS())
        .def("erase", &PyAcadObject::erase, DS.ARGS())
        .def("isEqualTo", &PyAcadObject::isEqualTo, DS.ARGS())
        .def("isNull", &PyAcadObject::isNull, DS.ARGS())
        .def("__eq__", &PyAcadObject::operator==, DS.ARGS({ "rhs: PyAx.AcadObject" }))
        .def("__ne__", &PyAcadObject::operator!=, DS.ARGS({ "rhs: PyAx.AcadObject" }))
        .def("__hash__", &PyAcadObject::hash)
        .def("className", &PyAcadObject::className, DS.SARGS()).staticmethod("className")
        .def("cast", &PyAcadObject::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        ;
}

PyAcadObject::PyAcadObject(PyIAcadObjectImpl* ptr)
: m_pyImp(ptr)
{
}

PyAcadObject::PyAcadObject(const AcDbObjectId& id)
 : PyAcadObject(new PyIAcadObjectImpl(GetIAcadObjectFromAcDbObjectId(id)))
{
}

bool PyAcadObject::operator==(const PyAcadObject& rhs) const
{
    return impObj()->IsEqualTo(*rhs.impObj());
}

bool PyAcadObject::operator!=(const PyAcadObject& rhs) const
{
    return !impObj()->IsEqualTo(*rhs.impObj());
}

std::size_t PyAcadObject::hash() const
{
    return impObj()->hash();
}

PyDbHandle PyAcadObject::handle() const
{
    return PyDbHandle{ wstr_to_utf8(impObj()->GetHandle()) };
}

std::string PyAcadObject::objectName() const
{
    return wstr_to_utf8(impObj()->GetObjectName());
}

PyDbObjectId PyAcadObject::objectId() const
{
    AcDbObjectId _id;
    _id.setFromOldId(impObj()->GetObjectId());
    return PyDbObjectId{ _id };
}

PyDbObjectId PyAcadObject::ownerId() const
{
    AcDbObjectId _id;
    _id.setFromOldId(impObj()->GetOwnerId());
    return PyDbObjectId{ _id };
}

//TODO: test handle
boost::python::list PyAcadObject::getXData(const std::string& appName)
{
    PyAutoLockGIL lock;
    const auto& tvs = impObj()->GetXData(utf8_to_wstr(appName).c_str());
    boost::python::list _pylist;
    for (const auto& tv : tvs)
    {
        TypedVariant::ETypeCode eType = static_cast<TypedVariant::ETypeCode>(tv.variant.index());
        switch (eType)
        {
            case TypedVariant::ETypeCode::kInt16:
            {
                const auto& val = std::get<TypedVariant::kInt16>(tv.variant);
                _pylist.append(boost::python::make_tuple(tv.code, val));
                break;
            }
            case TypedVariant::ETypeCode::kInt32:
            {
                const auto& val = std::get<TypedVariant::kInt32>(tv.variant);
                _pylist.append(boost::python::make_tuple(tv.code, val));
                break;
            }
            case TypedVariant::ETypeCode::kFloat:
            {
                const auto& val = std::get<TypedVariant::kFloat>(tv.variant);
                _pylist.append(boost::python::make_tuple(tv.code, val));
                break;
            }
            case TypedVariant::ETypeCode::kPoint3d:
            {
                const auto& val = std::get<TypedVariant::kPoint3d>(tv.variant);
                _pylist.append(boost::python::make_tuple(tv.code, val));
                break;
            }
            case TypedVariant::ETypeCode::kString:
            {
                const auto& val = std::get<TypedVariant::kString>(tv.variant);
                _pylist.append(boost::python::make_tuple(tv.code, wstr_to_utf8(val.c_str())));
                break;
            }
        }
    }
    return _pylist;
}

void PyAcadObject::setXdata(const boost::python::list& pylist)
{
    TypedVariants tvs;
    size_t listSize = boost::python::len(pylist);
    for (size_t idx = 0; idx < listSize; idx++)
    {
        tuple tpl = extract<tuple>(pylist[idx]);
        if (boost::python::len(tpl) != 2)
            throw PyErrorStatusException(Acad::eInvalidInput);

        int16_t code =  static_cast<int16_t>(extract<int>(tpl[0]));
        switch (acdbGroupCodeToType(code))
        {
            case AcDb::kDwgText:
            {
                tvs.emplace_back(TypedVariant{ code, utf8_to_wstr(extract<char*>(tpl[1])) });
                break;
            }
            case AcDb::kDwgInt16:
            {
                tvs.emplace_back(TypedVariant{ code,  static_cast<int16_t>(extract<int>(tpl[1])) });
                break;
            }
            case AcDb::kDwgInt32:
            {
                tvs.emplace_back(TypedVariant{ code,  static_cast<int32_t>(extract<int>(tpl[1])) });
                break;
            }
            case AcDb::kDwgReal:
            {
                tvs.emplace_back(TypedVariant{ code, extract<double>(tpl[1]) });
                break;
            }
            case AcDb::kDwg3Real:
            {
                tvs.emplace_back(TypedVariant{ code, extract<AcGePoint3d>(tpl[1]) });
                break;
            }
        }
    }
    impObj()->SetXData(tvs);
}

void PyAcadObject::clear()
{
    impObj()->Delete();
}

bool PyAcadObject::hasExtensionDictionary() const
{
    return impObj()->GetHasExtensionDictionary();
}

void PyAcadObject::erase()
{
    return impObj()->Erase();
}

bool PyAcadObject::isEqualTo(const PyAcadObject& other)
{
    return impObj()->IsEqualTo(*other.impObj());
}

bool PyAcadObject::isNull()
{
    if (m_pyImp == nullptr)
        return true;
    return impObj()->IsNull();
}

PyAcadObject PyAcadObject::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadObject>(src);
}

std::string PyAcadObject::className()
{
    return "AcDbObject";
}

PyIAcadObjectImpl* PyAcadObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadObjectImpl*>(m_pyImp.get());
}
