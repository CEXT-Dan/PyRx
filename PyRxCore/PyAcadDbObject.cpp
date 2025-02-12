#include "stdafx.h"
#include "PyAcadDbObject.h"
#include "PyAcadDbObjectImpl.h"
#include "PyAcadEntity.h"
#include "PyAcadEntityimpl.h"
#include "PyAcadApplication.h"
#include "PyAcadApplicationimpl.h"
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
        .def("database", &PyAcadObject::database, DS.ARGS())
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

PyAcadObject::PyAcadObject(std::shared_ptr<PyIAcadObjectImpl> ptr)
    : m_pyImp(ptr)
{
}

PyAcadObject::PyAcadObject(const AcDbObjectId& id)
    : PyAcadObject(std::make_shared<PyIAcadObjectImpl>(GetIAcadObjectFromAcDbObjectId(id)))
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

        int16_t code = static_cast<int16_t>(extract<int>(tpl[0]));
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

PyAcadDatabase PyAcadObject::database() const
{
    return PyAcadDatabase{ impObj()->GetDatabase() };
}

bool PyAcadObject::hasExtensionDictionary() const
{
    return impObj()->GetHasExtensionDictionary();
}

PyAcadDocument PyAcadObject::document() const
{
    return PyAcadDocument{ impObj()->GetDocument() };
}

//PyAcadDictionary PyAcadObject::extensionDictionary() const
//{
//    return PyAcadDictionary{ impObj()->GetExtensionDictionary() };
//}

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

//----------------------------------------------------------------------------------------
//PyAcadPlotConfiguration
void makePyAcadPlotConfigurationWrapper()
{
    PyDocString DS("AcadPlotConfiguration");
    class_<PyAcadPlotConfiguration, bases<PyAcadObject>>("AcadPlotConfiguration", boost::python::no_init)
        .def("cast", &PyAcadPlotConfiguration::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPlotConfiguration::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPlotConfiguration::PyAcadPlotConfiguration(std::shared_ptr<PyIAcadPlotConfigurationImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadPlotConfiguration PyAcadPlotConfiguration::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPlotConfiguration>(src);
}

std::string PyAcadPlotConfiguration::className()
{
    return "AcadPlotConfiguration";
}

PyIAcadPlotConfigurationImpl* PyAcadPlotConfiguration::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPlotConfigurationImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadLayout
void makePyAcadLayoutWrapper()
{
    PyDocString DS("AcadLayout");
    class_<PyAcadLayout, bases<PyAcadObject>>("AcadLayout", boost::python::no_init)
        .def("cast", &PyAcadLayout::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLayout::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLayout::PyAcadLayout(std::shared_ptr<PyIAcadLayoutImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadLayout PyAcadLayout::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadLayout>(src);
}

std::string PyAcadLayout::className()
{
    return "AcadLayout";
}

PyIAcadLayoutImpl* PyAcadLayout::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadLayoutImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadSectionSettings
void makePyAcadSectionSettingsWrapper()
{
    PyDocString DS("AcadSectionSettings");
    class_<PyAcadSectionSettings, bases<PyAcadObject>>("AcadSectionSettings", boost::python::no_init)
        .def("cast", &PyAcadSectionSettings::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSectionSettings::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSectionSettings::PyAcadSectionSettings(std::shared_ptr<PyIAcadSectionSettingsImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadSectionSettings PyAcadSectionSettings::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadSectionSettings>(src);
}

std::string PyAcadSectionSettings::className()
{
    return "AcadSectionSettings";
}

PyIAcadSectionSettingsImpl* PyAcadSectionSettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadSectionSettingsImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadView
void makePyAcadViewWrapper()
{
    PyDocString DS("AcadView");
    class_<PyAcadView, bases<PyAcadObject>>("AcadView", boost::python::no_init)
        .def("cast", &PyAcadView::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadView::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadView::PyAcadView(std::shared_ptr<PyIAcadViewImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadView PyAcadView::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadView>(src);
}

std::string PyAcadView::className()
{
    return "AcadView";
}

PyIAcadViewImpl* PyAcadView::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadViewImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadGroup
void makePyAcadGroupWrapper()
{
    PyDocString DS("AcadGroup");
    class_<PyAcadGroup, bases<PyAcadObject>>("AcadGroup", boost::python::no_init)
        .def("cast", &PyAcadGroup::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadGroup::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadGroup::PyAcadGroup(std::shared_ptr<PyIAcadGroupImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadGroup PyAcadGroup::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadGroup>(src);
}

std::string PyAcadGroup::className()
{
    return "AcadGroup";
}

PyIAcadGroupImpl* PyAcadGroup::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadGroupImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadGroups
void makePyAcadGroupsWrapper()
{
    PyDocString DS("AcadGroups");
    class_<PyAcadGroups, bases<PyAcadObject>>("AcadGroups", boost::python::no_init)
        .def("cast", &PyAcadGroups::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadGroups::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadGroups::PyAcadGroups(std::shared_ptr<PyIAcadGroupsImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadGroups PyAcadGroups::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadGroups>(src);
}

std::string PyAcadGroups::className()
{
    return "AcadGroups";
}

PyIAcadGroupsImpl* PyAcadGroups::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadGroupsImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimStyle
void makePyAcadDimStyleWrapper()
{
    PyDocString DS("AcadDimStyle");
    class_<PyAcadDimStyle, bases<PyAcadObject>>("AcadDimStyle", boost::python::no_init)
        .def("cast", &PyAcadDimStyle::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimStyle::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimStyle::PyAcadDimStyle(std::shared_ptr<PyIAcadDimStyleImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadDimStyle PyAcadDimStyle::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimStyle>(src);
}

std::string PyAcadDimStyle::className()
{
    return "AcadDimStyle";
}

PyIAcadDimStyleImpl* PyAcadDimStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimStyleImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimStyles
void makePyAcadDimStylesWrapper()
{
    PyDocString DS("AcadDimStyles");
    class_<PyAcadDimStyles, bases<PyAcadObject>>("AcadDimStyles", boost::python::no_init)
        .def("cast", &PyAcadDimStyles::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimStyles::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimStyles::PyAcadDimStyles(std::shared_ptr<PyIAcadDimStylesImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadDimStyles PyAcadDimStyles::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimStyles>(src);
}

std::string PyAcadDimStyles::className()
{
    return "AcadDimStyles";
}

PyIAcadDimStylesImpl* PyAcadDimStyles::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimStylesImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadLayer
void makePyAcadLayerWrapper()
{
    PyDocString DS("AcadLayer");
    class_<PyAcadLayer, bases<PyAcadObject>>("AcadLayer", boost::python::no_init)
        .def("cast", &PyAcadLayer::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLayer::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLayer::PyAcadLayer(std::shared_ptr<PyIAcadLayerImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadLayer PyAcadLayer::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadLayer>(src);
}

std::string PyAcadLayer::className()
{
    return "AcadLayer";
}

PyIAcadLayerImpl* PyAcadLayer::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadLayerImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadLayers
void makePyAcadLayersWrapper()
{
    PyDocString DS("AcadLayers");
    class_<PyAcadLayers, bases<PyAcadObject>>("AcadLayers", boost::python::no_init)
        .def("cast", &PyAcadLayers::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLayers::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLayers::PyAcadLayers(std::shared_ptr<PyIAcadLayersImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadLayers PyAcadLayers::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadLayers>(src);
}

std::string PyAcadLayers::className()
{
    return "AcadLayers";
}

PyIAcadLayersImpl* PyAcadLayers::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadLayersImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadLineType
void makePyAcadLineTypeWrapper()
{
    PyDocString DS("AcadLineType");
    class_<PyAcadLineType, bases<PyAcadObject>>("AcadLineType", boost::python::no_init)
        .def("cast", &PyAcadLineType::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLineType::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLineType::PyAcadLineType(std::shared_ptr<PyIAcadLineTypeImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadLineType PyAcadLineType::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadLineType>(src);
}

std::string PyAcadLineType::className()
{
    return "AcadLineType";
}

PyIAcadLineTypeImpl* PyAcadLineType::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadLineTypeImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadLineTypes
void makePyAcadLineTypesWrapper()
{
    PyDocString DS("AcadLineTypes");
    class_<PyAcadLineTypes, bases<PyAcadObject>>("AcadLineTypes", boost::python::no_init)
        .def("cast", &PyAcadLineTypes::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLineTypes::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLineTypes::PyAcadLineTypes(std::shared_ptr<PyIAcadLineTypesImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadLineTypes PyAcadLineTypes::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadLineTypes>(src);
}

std::string PyAcadLineTypes::className()
{
    return "AcadLineTypes";
}

PyIAcadLineTypesImpl* PyAcadLineTypes::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadLineTypesImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadXRecord
void makePyAcadXRecordWrapper()
{
    PyDocString DS("AcadXRecord");
    class_<PyAcadXRecord, bases<PyAcadObject>>("AcadXRecord", boost::python::no_init)
        .def("cast", &PyAcadXRecord::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadXRecord::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadXRecord::PyAcadXRecord(std::shared_ptr<PyIAcadXRecordImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadXRecord PyAcadXRecord::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadXRecord>(src);
}

std::string PyAcadXRecord::className()
{
    return "AcadXRecord";
}

PyIAcadXRecordImpl* PyAcadXRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadXRecordImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDictionary
void makePyAcadDictionaryWrapper()
{
    PyDocString DS("AcadDictionary");
    class_<PyAcadDictionary, bases<PyAcadObject>>("AcadDictionary", boost::python::no_init)
        .def("cast", &PyAcadDictionary::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDictionary::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDictionary::PyAcadDictionary(std::shared_ptr<PyIAcadDictionaryImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadDictionary PyAcadDictionary::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDictionary>(src);
}

std::string PyAcadDictionary::className()
{
    return "AcadDictionary";
}

PyIAcadDictionaryImpl* PyAcadDictionary::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDictionaryImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDictionaries
void makePyAcadDictionariesWrapper()
{
    PyDocString DS("AcadDictionaries");
    class_<PyAcadDictionaries, bases<PyAcadObject>>("AcadDictionaries", boost::python::no_init)
        .def("cast", &PyAcadDictionaries::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDictionaries::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDictionaries::PyAcadDictionaries(std::shared_ptr<PyIAcadDictionariesImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadDictionaries PyAcadDictionaries::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDictionaries>(src);
}

std::string PyAcadDictionaries::className()
{
    return "AcadDictionaries";
}

PyIAcadDictionariesImpl* PyAcadDictionaries::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDictionariesImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadRegisteredApplication
void makePyAcadRegisteredApplicationWrapper()
{
    PyDocString DS("AcadRegisteredApplication");
    class_<PyAcadRegisteredApplication, bases<PyAcadObject>>("AcadRegisteredApplication", boost::python::no_init)
        .def("name", &PyAcadRegisteredApplication::name, DS.ARGS())
        .def("setName", &PyAcadRegisteredApplication::setName, DS.ARGS({ "name:str" }))
        .def("cast", &PyAcadRegisteredApplication::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadRegisteredApplication::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadRegisteredApplication::PyAcadRegisteredApplication(std::shared_ptr<PyIAcadRegisteredApplicationImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadRegisteredApplication::name() const
{
   return wstr_to_utf8(impObj()->GetName());
}

void PyAcadRegisteredApplication::setName(const std::string& val)
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

PyAcadRegisteredApplication PyAcadRegisteredApplication::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadRegisteredApplication>(src);
}

std::string PyAcadRegisteredApplication::className()
{
    return "AcadRegisteredApplication";
}

PyIAcadRegisteredApplicationImpl* PyAcadRegisteredApplication::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadRegisteredApplicationImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadRegisteredApplications
void makePyAcadRegisteredApplicationsWrapper()
{
    PyDocString DS("AcadRegisteredApplications");
    class_<PyAcadRegisteredApplications, bases<PyAcadObject>>("AcadRegisteredApplications", boost::python::no_init)
        .def("count", &PyAcadRegisteredApplications::count, DS.ARGS())
        .def("add", &PyAcadRegisteredApplications::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadRegisteredApplications::item, DS.ARGS({ "index: int" }))
        .def("cast", &PyAcadRegisteredApplications::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadRegisteredApplications::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadRegisteredApplications::PyAcadRegisteredApplications(std::shared_ptr<PyIAcadRegisteredApplicationsImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadRegisteredApplications::count() const
{
    return impObj()->GetCount();
}

PyAcadRegisteredApplication PyAcadRegisteredApplications::item(long index)
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadRegisteredApplication{ impObj()->GetItem(index) };
}

PyAcadRegisteredApplication PyAcadRegisteredApplications::add(const std::string& name)
{
    return PyAcadRegisteredApplication{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

PyAcadRegisteredApplications PyAcadRegisteredApplications::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadRegisteredApplications>(src);
}

std::string PyAcadRegisteredApplications::className()
{
    return "AcadRegisteredApplications";
}

PyIAcadRegisteredApplicationsImpl* PyAcadRegisteredApplications::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadRegisteredApplicationsImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadTextStyle
void makePyAcadTextStyleWrapper()
{
    PyDocString DS("AcadTextStyle");
    class_<PyAcadTextStyle, bases<PyAcadObject>>("AcadTextStyle", boost::python::no_init)
        .def("cast", &PyAcadTextStyle::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTextStyle::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTextStyle::PyAcadTextStyle(std::shared_ptr<PyIAcadTextStyleImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadTextStyle PyAcadTextStyle::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadTextStyle>(src);
}

std::string PyAcadTextStyle::className()
{
    return "AcadTextStyle";
}

PyIAcadTextStyleImpl* PyAcadTextStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadTextStyleImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadTextStyles
void makePyAcadTextStylesWrapper()
{
    PyDocString DS("AcadTextStyles");
    class_<PyAcadTextStyles, bases<PyAcadObject>>("AcadTextStyles", boost::python::no_init)
        .def("cast", &PyAcadTextStyles::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTextStyles::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTextStyles::PyAcadTextStyles(std::shared_ptr<PyIAcadTextStylesImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadTextStyles PyAcadTextStyles::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadTextStyles>(src);
}

std::string PyAcadTextStyles::className()
{
    return "AcadTextStyles";
}

PyIAcadTextStylesImpl* PyAcadTextStyles::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadTextStylesImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadUCS
void makePyAcadUCSWrapper()
{
    PyDocString DS("AcadUCS");
    class_<PyAcadUCS, bases<PyAcadObject>>("AcadUCS", boost::python::no_init)
        .def("cast", &PyAcadUCS::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadUCS::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadUCS::PyAcadUCS(std::shared_ptr<PyIAcadUCSImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadUCS PyAcadUCS::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadUCS>(src);
}

std::string PyAcadUCS::className()
{
    return "AcadUCS";
}

PyIAcadUCSImpl* PyAcadUCS::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadUCSImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadUCSs
void makePyAcadUCSsWrapper()
{
    PyDocString DS("AcadUCSs");
    class_<PyAcadUCSs, bases<PyAcadObject>>("AcadUCSs", boost::python::no_init)
        .def("cast", &PyAcadUCSs::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadUCSs::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadUCSs::PyAcadUCSs(std::shared_ptr<PyIAcadUCSsImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadUCSs PyAcadUCSs::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadUCSs>(src);
}

std::string PyAcadUCSs::className()
{
    return "AcadUCSs";
}

PyIAcadUCSsImpl* PyAcadUCSs::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadUCSsImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadViewport
void makePyAcadViewportWrapper()
{
    PyDocString DS("AcadViewport");
    class_<PyAcadViewport, bases<PyAcadObject>>("AcadViewport", boost::python::no_init)
        .def("cast", &PyAcadViewport::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadViewport::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadViewport::PyAcadViewport(std::shared_ptr<PyIAcadViewportImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadViewport PyAcadViewport::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadViewport>(src);
}

std::string PyAcadViewport::className()
{
    return "AcadViewport";
}

PyIAcadViewportImpl* PyAcadViewport::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadViewportImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadViewports
void makePyAcadViewportsWrapper()
{
    PyDocString DS("AcadViewports");
    class_<PyAcadViewports, bases<PyAcadObject>>("AcadViewports", boost::python::no_init)
        .def("cast", &PyAcadViewports::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadViewports::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadViewports::PyAcadViewports(std::shared_ptr<PyIAcadViewportsImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadViewports PyAcadViewports::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadViewports>(src);
}

std::string PyAcadViewports::className()
{
    return "AcadViewports";
}

PyIAcadViewportsImpl* PyAcadViewports::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadViewportsImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadPlotConfigurations
void makePyAcadPlotConfigurationsWrapper()
{
    PyDocString DS("AcadPlotConfigurations");
    class_<PyAcadPlotConfigurations, bases<PyAcadObject>>("AcadPlotConfigurations", boost::python::no_init)
        .def("cast", &PyAcadPlotConfigurations::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPlotConfigurations::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPlotConfigurations::PyAcadPlotConfigurations(std::shared_ptr<PyIAcadPlotConfigurationsImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadPlotConfigurations PyAcadPlotConfigurations::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPlotConfigurations>(src);
}

std::string PyAcadPlotConfigurations::className()
{
    return "AcadPlotConfigurations";
}

PyIAcadPlotConfigurationsImpl* PyAcadPlotConfigurations::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPlotConfigurationsImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadSectionManager
void makePyAcadSectionManagerWrapper()
{
    PyDocString DS("AcadSectionManager");
    class_<PyAcadSectionManager, bases<PyAcadObject>>("AcadSectionManager", boost::python::no_init)
        .def("cast", &PyAcadSectionManager::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSectionManager::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSectionManager::PyAcadSectionManager(std::shared_ptr<PyIAcadSectionManagerImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadSectionManager PyAcadSectionManager::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadSectionManager>(src);
}

std::string PyAcadSectionManager::className()
{
    return "AcadSectionManager";
}

PyIAcadSectionManagerImpl* PyAcadSectionManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadSectionManagerImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadMaterial
void makePyAcadMaterialWrapper()
{
    PyDocString DS("AcadMaterial");
    class_<PyAcadMaterial, bases<PyAcadObject>>("AcadMaterial", boost::python::no_init)
        .def("cast", &PyAcadMaterial::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMaterial::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMaterial::PyAcadMaterial(std::shared_ptr<PyIAcadMaterialImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadMaterial PyAcadMaterial::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadMaterial>(src);
}

std::string PyAcadMaterial::className()
{
    return "AcadMaterial";
}

PyIAcadMaterialImpl* PyAcadMaterial::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadMaterialImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadMaterials
void makePyAcadMaterialsWrapper()
{
    PyDocString DS("AcadMaterials");
    class_<PyAcadMaterials, bases<PyAcadObject>>("AcadMaterials", boost::python::no_init)
        .def("cast", &PyAcadMaterials::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMaterials::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMaterials::PyAcadMaterials(std::shared_ptr<PyIAcadMaterialsImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadMaterials PyAcadMaterials::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadMaterials>(src);
}

std::string PyAcadMaterials::className()
{
    return "AcadMaterials";
}

PyIAcadMaterialsImpl* PyAcadMaterials::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadMaterialsImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadTableStyle
void makePyAcadTableStyleWrapper()
{
    PyDocString DS("AcadTableStyle");
    class_<PyAcadTableStyle, bases<PyAcadObject>>("AcadTableStyle", boost::python::no_init)
        .def("cast", &PyAcadTableStyle::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTableStyle::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTableStyle::PyAcadTableStyle(std::shared_ptr<PyIAcadTableStyleImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadTableStyle PyAcadTableStyle::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadTableStyle>(src);
}

std::string PyAcadTableStyle::className()
{
    return "AcadTableStyle";
}

PyIAcadTableStyleImpl* PyAcadTableStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadTableStyleImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadMLeaderStyle
void makePyAcadMLeaderStyleWrapper()
{
    PyDocString DS("AcadMLeaderStyle");
    class_<PyAcadMLeaderStyle, bases<PyAcadObject>>("AcadMLeaderStyle", boost::python::no_init)
        .def("cast", &PyAcadMLeaderStyle::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMLeaderStyle::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMLeaderStyle::PyAcadMLeaderStyle(std::shared_ptr<PyIAcadMLeaderStyleImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadMLeaderStyle PyAcadMLeaderStyle::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadMLeaderStyle>(src);
}

std::string PyAcadMLeaderStyle::className()
{
    return "AcadMLeaderStyle";
}

PyIAcadMLeaderStyleImpl* PyAcadMLeaderStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadMLeaderStyleImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadLayouts
void makePyAcadLayoutsWrapper()
{
    PyDocString DS("AcadLayouts");
    class_<PyAcadLayouts, bases<PyAcadObject>>("AcadLayouts", boost::python::no_init)
        .def("cast", &PyAcadLayouts::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLayouts::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLayouts::PyAcadLayouts(std::shared_ptr<PyIAcadLayoutsImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadLayouts PyAcadLayouts::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadLayouts>(src);
}

std::string PyAcadLayouts::className()
{
    return "AcadLayouts";
}

PyIAcadLayoutsImpl* PyAcadLayouts::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadLayoutsImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadSortentsTable
void makePyAcadSortentsTableWrapper()
{
    PyDocString DS("AcadSortentsTable");
    class_<PyAcadSortentsTable, bases<PyAcadObject>>("AcadSortentsTable", boost::python::no_init)
        .def("cast", &PyAcadSortentsTable::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSortentsTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSortentsTable::PyAcadSortentsTable(std::shared_ptr<PyIAcadSortentsTableImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadSortentsTable PyAcadSortentsTable::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadSortentsTable>(src);
}

std::string PyAcadSortentsTable::className()
{
    return "AcadSortentsTable";
}

PyIAcadSortentsTableImpl* PyAcadSortentsTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadSortentsTableImpl*>(m_pyImp.get());
}