#include "stdafx.h"
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
        .def("xdata", &PyAcadObject::xdata, DS.ARGS({ "appName: str" }))
        .def("setXdata", &PyAcadObject::setXdata, DS.ARGS({ "xdata:Iterable[tuple[int,Any]]" }))
        .def("clear", &PyAcadObject::clear, DS.ARGS())
        .def("database", &PyAcadObject::database, DS.ARGS())
        .def("extensionDictionary", &PyAcadObject::extensionDictionary, DS.ARGS())
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
boost::python::list PyAcadObject::xdata(const std::string& appName) const
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

void PyAcadObject::setXdata(const boost::python::list& pylist) const
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

void PyAcadObject::clear() const
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

PyAcadDictionary PyAcadObject::extensionDictionary() const
{
    return PyAcadDictionary{ impObj()->GetExtensionDictionary() };
}

PyAcadDocument PyAcadObject::document() const
{
    return PyAcadDocument{ impObj()->GetDocument() };
}

void PyAcadObject::erase() const
{
    return impObj()->Erase();
}

bool PyAcadObject::isEqualTo(const PyAcadObject& other) const
{
    return impObj()->IsEqualTo(*other.impObj());
}

bool PyAcadObject::isNull() const
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

        .def("name", &PyAcadPlotConfiguration::name, DS.ARGS())
        .def("setName", &PyAcadPlotConfiguration::setName, DS.ARGS({ "val:str" }))
        .def("configName", &PyAcadPlotConfiguration::configName, DS.ARGS())
        .def("setConfigName", &PyAcadPlotConfiguration::setConfigName, DS.ARGS({ "val:str" }))
        .def("canonicalMediaName", &PyAcadPlotConfiguration::canonicalMediaName, DS.ARGS())
        .def("setCanonicalMediaName", &PyAcadPlotConfiguration::setCanonicalMediaName, DS.ARGS({ "val:str" }))
        .def("paperUnits", &PyAcadPlotConfiguration::paperUnits, DS.ARGS())
        .def("setPaperUnits", &PyAcadPlotConfiguration::setPaperUnits, DS.ARGS({ "val:PyAx.AcPlotPaperUnits" }))
        .def("plotViewportBorders", &PyAcadPlotConfiguration::plotViewportBorders, DS.ARGS())
        .def("setPlotViewportBorders", &PyAcadPlotConfiguration::setPlotViewportBorders, DS.ARGS({ "val:bool" }))
        .def("showPlotStyles", &PyAcadPlotConfiguration::showPlotStyles, DS.ARGS())
        .def("setShowPlotStyles", &PyAcadPlotConfiguration::setShowPlotStyles, DS.ARGS({ "val:bool" }))
        .def("plotRotation", &PyAcadPlotConfiguration::plotRotation, DS.ARGS())
        .def("setPlotRotation", &PyAcadPlotConfiguration::setPlotRotation, DS.ARGS({ "val:PyAx.AcPlotRotation" }))
        .def("centerPlot", &PyAcadPlotConfiguration::centerPlot, DS.ARGS())
        .def("setCenterPlot", &PyAcadPlotConfiguration::setCenterPlot, DS.ARGS({ "val:bool" }))
        .def("plotHidden", &PyAcadPlotConfiguration::plotHidden, DS.ARGS())
        .def("setPlotHidden", &PyAcadPlotConfiguration::setPlotHidden, DS.ARGS({ "val:bool" }))
        .def("plotType", &PyAcadPlotConfiguration::plotType, DS.ARGS())
        .def("setPlotType", &PyAcadPlotConfiguration::setPlotType, DS.ARGS({ "val:PyAx.AcPlotType" }))
        .def("viewToPlot", &PyAcadPlotConfiguration::viewToPlot, DS.ARGS())
        .def("setViewToPlot", &PyAcadPlotConfiguration::setViewToPlot, DS.ARGS({ "val:str" }))
        .def("useStandardScale", &PyAcadPlotConfiguration::useStandardScale, DS.ARGS())
        .def("setUseStandardScale", &PyAcadPlotConfiguration::setUseStandardScale, DS.ARGS({ "val:bool" }))
        .def("standardScale", &PyAcadPlotConfiguration::standardScale, DS.ARGS())
        .def("setStandardScale", &PyAcadPlotConfiguration::setStandardScale, DS.ARGS({ "val:PyAx.AcPlotScale" }))
        .def("customScale", &PyAcadPlotConfiguration::customScale, DS.ARGS())
        .def("setCustomScale", &PyAcadPlotConfiguration::setCustomScale, DS.ARGS({ "numerator:float" ,  "denominator:float" }))
        .def("scaleLineweights", &PyAcadPlotConfiguration::scaleLineweights, DS.ARGS())
        .def("setScaleLineweights", &PyAcadPlotConfiguration::setScaleLineweights, DS.ARGS({ "val:bool" }))
        .def("plotWithLineweights", &PyAcadPlotConfiguration::plotWithLineweights, DS.ARGS())
        .def("setPlotWithLineweights", &PyAcadPlotConfiguration::setPlotWithLineweights, DS.ARGS({ "val:bool" }))
        .def("plotViewportsFirst", &PyAcadPlotConfiguration::plotViewportsFirst, DS.ARGS())
        .def("setPlotViewportsFirst", &PyAcadPlotConfiguration::setPlotViewportsFirst, DS.ARGS({ "val:bool" }))
        .def("styleSheet", &PyAcadPlotConfiguration::styleSheet, DS.ARGS())
        .def("setStyleSheet", &PyAcadPlotConfiguration::setStyleSheet, DS.ARGS({ "val:str" }))
        .def("paperMargins", &PyAcadPlotConfiguration::paperMargins, DS.ARGS())
        .def("paperSize", &PyAcadPlotConfiguration::paperSize, DS.ARGS())
        .def("plotOrigin", &PyAcadPlotConfiguration::plotOrigin, DS.ARGS())
        .def("setPlotOrigin", &PyAcadPlotConfiguration::setPlotOrigin, DS.ARGS({ "orgin:PyGe.Point2d" }))
        .def("windowToPlot", &PyAcadPlotConfiguration::windowToPlot, DS.ARGS())
        .def("setWindowToPlot", &PyAcadPlotConfiguration::setWindowToPlot, DS.ARGS({ "lowerLeft:PyGe.Point2d" ,  "upperRight:PyGe.Point2d" }))
        .def("plotWithPlotStyles", &PyAcadPlotConfiguration::plotWithPlotStyles, DS.ARGS())
        .def("setPlotWithPlotStyles", &PyAcadPlotConfiguration::setPlotWithPlotStyles, DS.ARGS({ "val:bool" }))
        .def("modelType", &PyAcadPlotConfiguration::modelType, DS.ARGS())
        .def("copyFrom", &PyAcadPlotConfiguration::copyFrom, DS.ARGS({ "val:PyAx.AcadPlotConfiguration" }))
        .def("canonicalMediaNames", &PyAcadPlotConfiguration::canonicalMediaNames, DS.ARGS())
        .def("plotDeviceNames", &PyAcadPlotConfiguration::plotDeviceNames, DS.ARGS())
        .def("plotStyleTableNames", &PyAcadPlotConfiguration::plotStyleTableNames, DS.ARGS())
        .def("refreshPlotDeviceInfo", &PyAcadPlotConfiguration::refreshPlotDeviceInfo, DS.ARGS())
        .def("localeMediaName", &PyAcadPlotConfiguration::localeMediaName, DS.ARGS({ "val:str" }))
        .def("cast", &PyAcadPlotConfiguration::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPlotConfiguration::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPlotConfiguration::PyAcadPlotConfiguration(std::shared_ptr<PyIAcadPlotConfigurationImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadPlotConfiguration::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadPlotConfiguration::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

std::string PyAcadPlotConfiguration::configName() const
{
    return wstr_to_utf8(impObj()->GetConfigName());
}

void PyAcadPlotConfiguration::setConfigName(const std::string& val) const
{
    impObj()->SetConfigName(utf8_to_wstr(val).c_str());
}

std::string PyAcadPlotConfiguration::canonicalMediaName() const
{
    return wstr_to_utf8(impObj()->GetCanonicalMediaName());
}

void PyAcadPlotConfiguration::setCanonicalMediaName(const std::string& val) const
{
    impObj()->SetCanonicalMediaName(utf8_to_wstr(val).c_str());
}

PyAcPlotPaperUnits PyAcadPlotConfiguration::paperUnits() const
{
    return impObj()->GetPaperUnits();
}

void PyAcadPlotConfiguration::setPaperUnits(PyAcPlotPaperUnits val) const
{
    impObj()->SetPaperUnits(val);
}

bool PyAcadPlotConfiguration::plotViewportBorders() const
{
    return impObj()->GetPlotViewportBorders();
}

void PyAcadPlotConfiguration::setPlotViewportBorders(bool val) const
{
    impObj()->SetPlotViewportBorders(val);
}

bool PyAcadPlotConfiguration::showPlotStyles() const
{
    return impObj()->GetShowPlotStyles();
}

void PyAcadPlotConfiguration::setShowPlotStyles(bool val) const
{
    impObj()->SetShowPlotStyles(val);
}

PyAcPlotRotation PyAcadPlotConfiguration::plotRotation() const
{
    return impObj()->GetPlotRotation();
}

void PyAcadPlotConfiguration::setPlotRotation(PyAcPlotRotation val) const
{
    impObj()->SetPlotRotation(val);
}

bool PyAcadPlotConfiguration::centerPlot() const
{
    return impObj()->GetCenterPlot();
}

void PyAcadPlotConfiguration::setCenterPlot(bool val) const
{
    impObj()->SetCenterPlot(val);
}

bool PyAcadPlotConfiguration::plotHidden() const
{
    return impObj()->GetPlotHidden();
}

void PyAcadPlotConfiguration::setPlotHidden(bool val) const
{
    impObj()->SetPlotHidden(val);
}

PyAcPlotType PyAcadPlotConfiguration::plotType() const
{
    return impObj()->GetPlotType();
}

void PyAcadPlotConfiguration::setPlotType(PyAcPlotType val) const
{
    impObj()->SetPlotType(val);
}

std::string PyAcadPlotConfiguration::viewToPlot() const
{
    return wstr_to_utf8(impObj()->GetViewToPlot());
}

void PyAcadPlotConfiguration::setViewToPlot(const std::string& val) const
{
    impObj()->SetViewToPlot(utf8_to_wstr(val).c_str());
}

bool PyAcadPlotConfiguration::useStandardScale() const
{
    return impObj()->GetUseStandardScale();
}

void PyAcadPlotConfiguration::setUseStandardScale(bool val) const
{
    impObj()->SetUseStandardScale(val);
}

PyAcPlotScale PyAcadPlotConfiguration::standardScale() const
{
    return impObj()->GetStandardScale();
}

void PyAcadPlotConfiguration::setStandardScale(PyAcPlotScale val) const
{
    impObj()->SetStandardScale(val);
}

boost::python::tuple PyAcadPlotConfiguration::customScale() const
{
    PyAutoLockGIL lock;
    double numerator = 0.0;
    double denominator = 0.0;
    impObj()->GetCustomScale(numerator, denominator);
    return boost::python::make_tuple(numerator, denominator);
}

void PyAcadPlotConfiguration::setCustomScale(double numerator, double denominator) const
{
    impObj()->SetCustomScale(numerator, denominator);
}

bool PyAcadPlotConfiguration::scaleLineweights() const
{
    return impObj()->GetScaleLineweights();
}

void PyAcadPlotConfiguration::setScaleLineweights(bool val) const
{
    impObj()->SetScaleLineweights(val);
}

bool PyAcadPlotConfiguration::plotWithLineweights() const
{
    return impObj()->GetPlotWithLineweights();
}

void PyAcadPlotConfiguration::setPlotWithLineweights(bool val) const
{
    impObj()->SetPlotWithLineweights(val);
}

bool PyAcadPlotConfiguration::plotViewportsFirst() const
{
    return impObj()->GetPlotViewportsFirst();
}

void PyAcadPlotConfiguration::setPlotViewportsFirst(bool val) const
{
    impObj()->SetPlotViewportsFirst(val);
}

std::string PyAcadPlotConfiguration::styleSheet() const
{
    return wstr_to_utf8(impObj()->GetStyleSheet());
}

void PyAcadPlotConfiguration::setStyleSheet(const std::string& val) const
{
    impObj()->SetStyleSheet(utf8_to_wstr(val).c_str());
}

boost::python::tuple PyAcadPlotConfiguration::paperMargins() const
{
    PyAutoLockGIL lock;
    AcGePoint2d lowerLeft;
    AcGePoint2d upperRight;
    impObj()->GetPaperMargins(lowerLeft, upperRight);
    return boost::python::make_tuple(lowerLeft, upperRight);
}

boost::python::tuple PyAcadPlotConfiguration::paperSize() const
{
    PyAutoLockGIL lock;
    double width = 0.0;
    double height = 0.0;
    impObj()->GetPaperSize(width, height);
    return boost::python::make_tuple(width, height);
}

AcGePoint2d PyAcadPlotConfiguration::plotOrigin() const
{
    return impObj()->GetPlotOrigin();
}

void PyAcadPlotConfiguration::setPlotOrigin(const AcGePoint2d& orgin) const
{
    impObj()->SetPlotOrigin(orgin);
}

boost::python::tuple PyAcadPlotConfiguration::windowToPlot() const
{
    PyAutoLockGIL lock;
    AcGePoint2d lowerLeft;
    AcGePoint2d upperRight;
    impObj()->GetWindowToPlot(lowerLeft, upperRight);
    return boost::python::make_tuple(lowerLeft, upperRight);
}

void PyAcadPlotConfiguration::setWindowToPlot(const AcGePoint2d& lowerLeft, const AcGePoint2d& upperRight) const
{
    impObj()->SetWindowToPlot(lowerLeft, upperRight);
}

bool PyAcadPlotConfiguration::plotWithPlotStyles() const
{
    return impObj()->GetPlotWithPlotStyles();
}

void PyAcadPlotConfiguration::setPlotWithPlotStyles(bool val) const
{
    impObj()->SetPlotWithPlotStyles(val);
}

bool PyAcadPlotConfiguration::modelType() const
{
    return impObj()->GetModelType();
}

void PyAcadPlotConfiguration::copyFrom(const PyAcadPlotConfiguration& val) const
{
    impObj()->CopyFrom(*val.impObj());
}

boost::python::list PyAcadPlotConfiguration::canonicalMediaNames() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->GetCanonicalMediaNames())
        pylist.append(wstr_to_utf8(item));
    return pylist;
}

boost::python::list PyAcadPlotConfiguration::plotDeviceNames() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->GetPlotDeviceNames())
        pylist.append(wstr_to_utf8(item));
    return pylist;
}

boost::python::list PyAcadPlotConfiguration::plotStyleTableNames() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->GetPlotStyleTableNames())
        pylist.append(wstr_to_utf8(item));
    return pylist;
}

void PyAcadPlotConfiguration::refreshPlotDeviceInfo() const
{
    impObj()->RefreshPlotDeviceInfo();
}

std::string PyAcadPlotConfiguration::localeMediaName(const std::string& name) const
{
    return wstr_to_utf8(impObj()->GetLocaleMediaName(utf8_to_wstr(name).c_str()));
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
    class_<PyAcadLayout, bases<PyAcadPlotConfiguration>>("AcadLayout", boost::python::no_init)
        .def("block", &PyAcadLayout::block, DS.ARGS())
        .def("tabOrder", &PyAcadLayout::tabOrder, DS.ARGS())
        .def("setTabOrder", &PyAcadLayout::setTabOrder, DS.ARGS({ "val:int" }))
        .def("cast", &PyAcadLayout::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLayout::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLayout::PyAcadLayout(std::shared_ptr<PyIAcadLayoutImpl> ptr)
    : PyAcadPlotConfiguration(ptr)
{
}

PyAcadBlock PyAcadLayout::block() const
{
    return PyAcadBlock{ impObj()->GetBlock() };
}

long PyAcadLayout::tabOrder() const
{
    return impObj()->GetTabOrder();
}

void PyAcadLayout::setTabOrder(long val) const
{
    impObj()->SetTabOrder(val);
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
        .def("currentSectionType", &PyAcadSectionSettings::currentSectionType, DS.ARGS())
        .def("setCurrentSectionType", &PyAcadSectionSettings::currentSectionType, DS.ARGS({ "secType: PyAx.AcSectionType" }))
        .def("sectionTypeSettings", &PyAcadSectionSettings::sectionTypeSettings, DS.ARGS({ "secType: PyAx.AcSectionType" }))
        .def("cast", &PyAcadSectionSettings::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSectionSettings::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSectionSettings::PyAcadSectionSettings(std::shared_ptr<PyIAcadSectionSettingsImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcSectionType PyAcadSectionSettings::currentSectionType() const
{
    return impObj()->GetCurrentSectionType();
}

void PyAcadSectionSettings::setCurrentSectionType(PyAcSectionType val) const
{
    impObj()->SetCurrentSectionType(val);
}

PyAcadSectionTypeSettings PyAcadSectionSettings::sectionTypeSettings(PyAcSectionType secType) const
{
    return PyAcadSectionTypeSettings{ impObj()->GetSectionTypeSettings(secType) };
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
        .def("center", &PyAcadView::center, DS.ARGS())
        .def("setCenter", &PyAcadView::setCenter, DS.ARGS({ "val: PyGe.Point3d" }))
        .def("height", &PyAcadView::height, DS.ARGS())
        .def("setHeight", &PyAcadView::setHeight, DS.ARGS({ "val: float" }))
        .def("width", &PyAcadView::width, DS.ARGS())
        .def("setWidth", &PyAcadView::setWidth, DS.ARGS({ "val: float" }))
        .def("target", &PyAcadView::target, DS.ARGS())
        .def("setTarget", &PyAcadView::setTarget, DS.ARGS({ "val: PyGe.Point3d" }))
        .def("direction", &PyAcadView::direction, DS.ARGS())
        .def("setDirection", &PyAcadView::setDirection, DS.ARGS({ "val: PyGe.Vector3d" }))
        .def("name", &PyAcadView::name, DS.ARGS())
        .def("setName", &PyAcadView::setName, DS.ARGS({ "val: str" }))
        .def("categoryName", &PyAcadView::categoryName, DS.ARGS())
        .def("setCategoryName", &PyAcadView::setCategoryName, DS.ARGS({ "val: str" }))
        .def("layoutId", &PyAcadView::layoutId, DS.ARGS())
        .def("setLayoutId", &PyAcadView::setLayoutId, DS.ARGS({ "val: PyDb.ObjectId" }))
        .def("layerState", &PyAcadView::layerState, DS.ARGS())
        .def("setLayerState", &PyAcadView::setLayerState, DS.ARGS({ "val:str" }))
        .def("hasVpAssociation", &PyAcadView::hasVpAssociation, DS.ARGS())
        .def("setHasVpAssociation", &PyAcadView::setHasVpAssociation, DS.ARGS({ "val:str" }))
        .def("cast", &PyAcadView::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadView::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadView::PyAcadView(std::shared_ptr<PyIAcadViewImpl> ptr)
    : PyAcadObject(ptr)
{
}

AcGePoint3d PyAcadView::center() const
{
    return impObj()->GetCenter();
}

void PyAcadView::setCenter(const AcGePoint3d& val) const
{
    impObj()->SetCenter(val);
}

double PyAcadView::height() const
{
    return impObj()->GetHeight();
}

void PyAcadView::setHeight(double val) const
{
    impObj()->SetHeight(val);
}

double PyAcadView::width() const
{
    return impObj()->GetWidth();
}

void PyAcadView::setWidth(double val) const
{
    impObj()->SetWidth(val);
}

AcGePoint3d PyAcadView::target() const
{
    return impObj()->GetTarget();
}

void PyAcadView::setTarget(const AcGePoint3d& val) const
{
    impObj()->SetTarget(val);
}

AcGeVector3d PyAcadView::direction() const
{
    return impObj()->GetDirection();
}

void PyAcadView::setDirection(const AcGeVector3d& val) const
{
    impObj()->SetDirection(val);
}

std::string PyAcadView::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadView::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

std::string PyAcadView::categoryName() const
{
    return wstr_to_utf8(impObj()->GetCategoryName());
}

void PyAcadView::setCategoryName(const std::string& val) const
{
    impObj()->SetCategoryName(utf8_to_wstr(val).c_str());
}

PyDbObjectId PyAcadView::layoutId() const
{
    return PyDbObjectId{ impObj()->GetLayoutId() };
}

void PyAcadView::setLayoutId(const PyDbObjectId& val) const
{
    impObj()->SetLayoutId(val.m_id);
}

std::string PyAcadView::layerState() const
{
    return wstr_to_utf8(impObj()->GetLayerState());
}

void PyAcadView::setLayerState(const std::string& val) const
{
    impObj()->SetLayerState(utf8_to_wstr(val).c_str());
}

bool PyAcadView::hasVpAssociation() const
{
    return impObj()->GetHasVpAssociation();
}

void PyAcadView::setHasVpAssociation(bool val) const
{
    impObj()->SetHasVpAssociation(val);
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
//PyAcadViews
void makePyAcadViewsWrapper()
{
    PyDocString DS("AcadViews");
    class_<PyAcadViews, bases<PyAcadObject>>("AcadViews", boost::python::no_init)
        .def("count", &PyAcadViews::count, DS.ARGS())
        .def("add", &PyAcadViews::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadViews::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadViews::items, DS.ARGS())
        .def("cast", &PyAcadViews::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadViews::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadViews::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadViews::begin, &PyAcadViews::end))
        ;
}

PyAcadViews::PyAcadViews(std::shared_ptr<PyIAcadViewsImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadViews::count() const
{
    return impObj()->GetCount();
}

PyAcadView PyAcadViews::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadView{ impObj()->GetItem(index) };
}

PyAcadView PyAcadViews::add(const std::string& name) const
{
    return PyAcadView{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadViews::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadView{ item });
    return _pylist;
}

PyAcadViews PyAcadViews::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadViews>(src);
}

std::string PyAcadViews::className()
{
    return "AcadViews";
}

PyIAcadViewsImpl* PyAcadViews::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadViewsImpl*>(m_pyImp.get());
}

void PyAcadViews::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadView{ item });
}

std::vector<PyAcadView>::iterator PyAcadViews::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadView>::iterator PyAcadViews::end()
{
    filliterator();
    return m_iterable.end();
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
        .def("count", &PyAcadDimStyles::count, DS.ARGS())
        .def("add", &PyAcadDimStyles::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadDimStyles::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadDimStyles::items, DS.ARGS())
        .def("cast", &PyAcadDimStyles::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimStyles::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadDimStyles::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadDimStyles::begin, &PyAcadDimStyles::end))
        ;
}

PyAcadDimStyles::PyAcadDimStyles(std::shared_ptr<PyIAcadDimStylesImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadDimStyles::count() const
{
    return impObj()->GetCount();
}

PyAcadDimStyle PyAcadDimStyles::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadDimStyle{ impObj()->GetItem(index) };
}

PyAcadDimStyle PyAcadDimStyles::add(const std::string& name) const
{
    return PyAcadDimStyle{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadDimStyles::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadDimStyle{ item });
    return _pylist;
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

void PyAcadDimStyles::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadDimStyle{ item });
}

std::vector<PyAcadDimStyle>::iterator PyAcadDimStyles::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadDimStyle>::iterator PyAcadDimStyles::end()
{
    filliterator();
    return m_iterable.end();
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
        .def("count", &PyAcadLayers::count, DS.ARGS())
        .def("add", &PyAcadLayers::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadLayers::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadLayers::items, DS.ARGS())
        .def("cast", &PyAcadLayers::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLayers::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadLayers::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadLayers::begin, &PyAcadLayers::end))
        ;
}

PyAcadLayers::PyAcadLayers(std::shared_ptr<PyIAcadLayersImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadLayers::count() const
{
    return impObj()->GetCount();
}

PyAcadLayer PyAcadLayers::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadLayer{ impObj()->GetItem(index) };
}

PyAcadLayer PyAcadLayers::add(const std::string& name) const
{
    return PyAcadLayer{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadLayers::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadLayer{ item });
    return _pylist;
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

void PyAcadLayers::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadLayer{ item });
}

std::vector<PyAcadLayer>::iterator PyAcadLayers::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadLayer>::iterator PyAcadLayers::end()
{
    filliterator();
    return m_iterable.end();
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
        .def("count", &PyAcadLineTypes::count, DS.ARGS())
        .def("add", &PyAcadLineTypes::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadLineTypes::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadLineTypes::items, DS.ARGS())
        .def("cast", &PyAcadLineTypes::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLineTypes::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadLineTypes::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadLineTypes::begin, &PyAcadLineTypes::end))
        ;
}

PyAcadLineTypes::PyAcadLineTypes(std::shared_ptr<PyIAcadLineTypesImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadLineTypes::count() const
{
    return impObj()->GetCount();
}

PyAcadLineType PyAcadLineTypes::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadLineType{ impObj()->GetItem(index) };
}

PyAcadLineType PyAcadLineTypes::add(const std::string& name) const
{
    return PyAcadLineType{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadLineTypes::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadLineType{ item });
    return _pylist;
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

void PyAcadLineTypes::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadLineType{ item });
}

std::vector<PyAcadLineType>::iterator PyAcadLineTypes::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadLineType>::iterator PyAcadLineTypes::end()
{
    filliterator();
    return m_iterable.end();
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
        .def("count", &PyAcadDictionaries::count, DS.ARGS())
        .def("add", &PyAcadDictionaries::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadDictionaries::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadDictionaries::items, DS.ARGS())
        .def("cast", &PyAcadDictionaries::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDictionaries::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadDictionaries::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadDictionaries::begin, &PyAcadDictionaries::end))
        ;
}

PyAcadDictionaries::PyAcadDictionaries(std::shared_ptr<PyIAcadDictionariesImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadDictionaries::count() const
{
    return impObj()->GetCount();
}

PyAcadDictionary PyAcadDictionaries::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadDictionary{ impObj()->GetItem(index) };
}

PyAcadDictionary PyAcadDictionaries::add(const std::string& name) const
{
    return PyAcadDictionary{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadDictionaries::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadDictionary{ item });
    return _pylist;
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

void PyAcadDictionaries::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadDictionary{ item });
}

std::vector<PyAcadDictionary>::iterator PyAcadDictionaries::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadDictionary>::iterator PyAcadDictionaries::end()
{
    filliterator();
    return m_iterable.end();
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

void PyAcadRegisteredApplication::setName(const std::string& val) const
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
        .def("items", &PyAcadRegisteredApplications::items, DS.ARGS())
        .def("cast", &PyAcadRegisteredApplications::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadRegisteredApplications::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadRegisteredApplications::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadRegisteredApplications::begin, &PyAcadRegisteredApplications::end))
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

PyAcadRegisteredApplication PyAcadRegisteredApplications::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadRegisteredApplication{ impObj()->GetItem(index) };
}

PyAcadRegisteredApplication PyAcadRegisteredApplications::add(const std::string& name) const
{
    return PyAcadRegisteredApplication{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadRegisteredApplications::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadRegisteredApplication{ item });
    return _pylist;
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

void PyAcadRegisteredApplications::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadRegisteredApplication{ item });
}

std::vector<PyAcadRegisteredApplication>::iterator PyAcadRegisteredApplications::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadRegisteredApplication>::iterator PyAcadRegisteredApplications::end()
{
    filliterator();
    return m_iterable.end();
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
        .def("count", &PyAcadTextStyles::count, DS.ARGS())
        .def("add", &PyAcadTextStyles::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadTextStyles::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadTextStyles::items, DS.ARGS())
        .def("cast", &PyAcadTextStyles::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTextStyles::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadTextStyles::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadTextStyles::begin, &PyAcadTextStyles::end))
        ;
}

PyAcadTextStyles::PyAcadTextStyles(std::shared_ptr<PyIAcadTextStylesImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadTextStyles::count() const
{
    return impObj()->GetCount();
}

PyAcadTextStyle PyAcadTextStyles::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadTextStyle{ impObj()->GetItem(index) };
}

PyAcadTextStyle PyAcadTextStyles::add(const std::string& name) const
{
    return PyAcadTextStyle{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadTextStyles::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadTextStyle{ item });
    return _pylist;
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

void PyAcadTextStyles::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadTextStyle{ item });
}

std::vector<PyAcadTextStyle>::iterator PyAcadTextStyles::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadTextStyle>::iterator PyAcadTextStyles::end()
{
    filliterator();
    return m_iterable.end();
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
        .def("count", &PyAcadUCSs::count, DS.ARGS())
        .def("add", &PyAcadUCSs::add, DS.ARGS({ "origin: PyGe.Point3d","XDir: PyGe.Vector3d","YDir: PyGe.Vector3d","name: str" }))
        .def("item", &PyAcadUCSs::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadUCSs::items, DS.ARGS())
        .def("cast", &PyAcadUCSs::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadUCSs::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadUCSs::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadUCSs::begin, &PyAcadUCSs::end))
        ;
}

PyAcadUCSs::PyAcadUCSs(std::shared_ptr<PyIAcadUCSsImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadUCSs::count() const
{
    return impObj()->GetCount();
}

PyAcadUCS PyAcadUCSs::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadUCS{ impObj()->GetItem(index) };
}

PyAcadUCS PyAcadUCSs::add(const AcGePoint3d& origin, const AcGeVector3d& xDir, const AcGeVector3d& yDir, const std::string& name) const
{
    return PyAcadUCS{ impObj()->Add(origin,xDir,yDir, utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadUCSs::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadUCS{ item });
    return _pylist;
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

void PyAcadUCSs::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadUCS{ item });
}

std::vector<PyAcadUCS>::iterator PyAcadUCSs::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadUCS>::iterator PyAcadUCSs::end()
{
    filliterator();
    return m_iterable.end();
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
        .def("count", &PyAcadViewports::count, DS.ARGS())
        .def("add", &PyAcadViewports::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadViewports::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadViewports::items, DS.ARGS())
        .def("cast", &PyAcadViewports::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadViewports::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadViewports::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadViewports::begin, &PyAcadViewports::end))
        ;
}

PyAcadViewports::PyAcadViewports(std::shared_ptr<PyIAcadViewportsImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadViewports::count() const
{
    return impObj()->GetCount();
}

PyAcadViewport PyAcadViewports::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadViewport{ impObj()->GetItem(index) };
}

PyAcadViewport PyAcadViewports::add(const std::string& name) const
{
    return PyAcadViewport{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadViewports::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadViewport{ item });
    return _pylist;
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

void PyAcadViewports::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadViewport{ item });
}

std::vector<PyAcadViewport>::iterator PyAcadViewports::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadViewport>::iterator PyAcadViewports::end()
{
    filliterator();
    return m_iterable.end();
}

//----------------------------------------------------------------------------------------
//PyAcadPlotConfigurations
void makePyAcadPlotConfigurationsWrapper()
{
    PyDocString DS("AcadPlotConfigurations");
    class_<PyAcadPlotConfigurations, bases<PyAcadObject>>("AcadPlotConfigurations", boost::python::no_init)
        .def("count", &PyAcadPlotConfigurations::count, DS.ARGS())
        .def("add", &PyAcadPlotConfigurations::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadPlotConfigurations::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadPlotConfigurations::items, DS.ARGS())
        .def("cast", &PyAcadPlotConfigurations::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPlotConfigurations::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadPlotConfigurations::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadPlotConfigurations::begin, &PyAcadPlotConfigurations::end))
        ;
}

PyAcadPlotConfigurations::PyAcadPlotConfigurations(std::shared_ptr<PyIAcadPlotConfigurationsImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadPlotConfigurations::count() const
{
    return impObj()->GetCount();
}

PyAcadPlotConfiguration PyAcadPlotConfigurations::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadPlotConfiguration{ impObj()->GetItem(index) };
}

PyAcadPlotConfiguration PyAcadPlotConfigurations::add(const std::string& name) const
{
    return PyAcadPlotConfiguration{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadPlotConfigurations::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadPlotConfiguration{ item });
    return _pylist;
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

void PyAcadPlotConfigurations::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadPlotConfiguration{ item });
}

std::vector<PyAcadPlotConfiguration>::iterator PyAcadPlotConfigurations::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadPlotConfiguration>::iterator PyAcadPlotConfigurations::end()
{
    filliterator();
    return m_iterable.end();
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
        .def("count", &PyAcadMaterials::count, DS.ARGS())
        .def("add", &PyAcadMaterials::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadMaterials::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadMaterials::items, DS.ARGS())
        .def("cast", &PyAcadMaterials::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMaterials::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadMaterials::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadMaterials::begin, &PyAcadMaterials::end))
        ;
}

PyAcadMaterials::PyAcadMaterials(std::shared_ptr<PyIAcadMaterialsImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadMaterials::count() const
{
    return impObj()->GetCount();
}

PyAcadMaterial PyAcadMaterials::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadMaterial{ impObj()->GetItem(index) };
}

PyAcadMaterial PyAcadMaterials::add(const std::string& name) const
{
    return PyAcadMaterial{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadMaterials::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadMaterial{ item });
    return _pylist;
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

void PyAcadMaterials::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadMaterial{ item });
}

std::vector<PyAcadMaterial>::iterator PyAcadMaterials::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadMaterial>::iterator PyAcadMaterials::end()
{
    filliterator();
    return m_iterable.end();
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
        .def("count", &PyAcadLayouts::count, DS.ARGS())
        .def("add", &PyAcadLayouts::add, DS.ARGS({ "name: str" }))
        .def("item", &PyAcadLayouts::item, DS.ARGS({ "index: int" }))
        .def("items", &PyAcadLayouts::items, DS.ARGS())
        .def("cast", &PyAcadLayouts::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLayouts::className, DS.SARGS()).staticmethod("className")
        .def("__getitem__", &PyAcadLayouts::item, DS.ARGS({ "index: int" }))
        .def("__iter__", range(&PyAcadLayouts::begin, &PyAcadLayouts::end))
        ;
}

PyAcadLayouts::PyAcadLayouts(std::shared_ptr<PyIAcadLayoutsImpl> ptr)
    : PyAcadObject(ptr)
{
}

long PyAcadLayouts::count() const
{
    return impObj()->GetCount();
}

PyAcadLayout PyAcadLayouts::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadLayout{ impObj()->GetItem(index) };
}

PyAcadLayout PyAcadLayouts::add(const std::string& name)
{
    return PyAcadLayout{ impObj()->Add(utf8_to_wstr(name).c_str()) };
}

boost::python::list PyAcadLayouts::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadLayout{ item });
    return _pylist;
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

void PyAcadLayouts::filliterator()
{
    const auto& items = impObj()->GetIter();
    m_iterable.clear();
    m_iterable.reserve(items.size());
    for (const auto& item : items)
        m_iterable.emplace_back(PyAcadLayout{ item });
}

std::vector<PyAcadLayout>::iterator PyAcadLayouts::begin()
{
    return m_iterable.begin();
}

std::vector<PyAcadLayout>::iterator PyAcadLayouts::end()
{
    filliterator();
    return m_iterable.end();
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