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
        .def("setXdata", &PyAcadObject::setXdata, DS.ARGS({ "xdata:Collection[tuple[int,Any]]" }))
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

void PyAcadObject::setXdata(const boost::python::object& pylist) const
{
    TypedVariants tvs;
    for (size_t idx = 0, listSize = boost::python::len(pylist); idx < listSize; idx++)
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
        .def("setName", &PyAcadPlotConfiguration::setName, DS.ARGS({ "plot_config_name : str" }))
        .def("configName", &PyAcadPlotConfiguration::configName, DS.ARGS())
        .def("setConfigName", &PyAcadPlotConfiguration::setConfigName, DS.ARGS({ "config_name : str" }))
        .def("canonicalMediaName", &PyAcadPlotConfiguration::canonicalMediaName, DS.ARGS())
        .def("setCanonicalMediaName", &PyAcadPlotConfiguration::setCanonicalMediaName, DS.ARGS({ "media_name : str" }))
        .def("paperUnits", &PyAcadPlotConfiguration::paperUnits, DS.ARGS())
        .def("setPaperUnits", &PyAcadPlotConfiguration::setPaperUnits, DS.ARGS({ "units : PyAx.AcPlotPaperUnits" }))
        .def("plotViewportBorders", &PyAcadPlotConfiguration::plotViewportBorders, DS.ARGS())
        .def("setPlotViewportBorders", &PyAcadPlotConfiguration::setPlotViewportBorders, DS.ARGS({ "plot_borders : bool" }))
        .def("showPlotStyles", &PyAcadPlotConfiguration::showPlotStyles, DS.ARGS())
        .def("setShowPlotStyles", &PyAcadPlotConfiguration::setShowPlotStyles, DS.ARGS({ "show_styles : bool" }))
        .def("plotRotation", &PyAcadPlotConfiguration::plotRotation, DS.ARGS())
        .def("setPlotRotation", &PyAcadPlotConfiguration::setPlotRotation, DS.ARGS({ "rotation : PyAx.AcPlotRotation" }))
        .def("centerPlot", &PyAcadPlotConfiguration::centerPlot, DS.ARGS())
        .def("setCenterPlot", &PyAcadPlotConfiguration::setCenterPlot, DS.ARGS({ "center : bool" }))
        .def("plotHidden", &PyAcadPlotConfiguration::plotHidden, DS.ARGS())
        .def("setPlotHidden", &PyAcadPlotConfiguration::setPlotHidden, DS.ARGS({ "plot_hidden : bool" }))
        .def("plotType", &PyAcadPlotConfiguration::plotType, DS.ARGS())
        .def("setPlotType", &PyAcadPlotConfiguration::setPlotType, DS.ARGS({ "plot_type : PyAx.AcPlotType" }))
        .def("viewToPlot", &PyAcadPlotConfiguration::viewToPlot, DS.ARGS())
        .def("setViewToPlot", &PyAcadPlotConfiguration::setViewToPlot, DS.ARGS({ "view_name : str" }))
        .def("useStandardScale", &PyAcadPlotConfiguration::useStandardScale, DS.ARGS())
        .def("setUseStandardScale", &PyAcadPlotConfiguration::setUseStandardScale, DS.ARGS({ "use_standard : bool" }))
        .def("standardScale", &PyAcadPlotConfiguration::standardScale, DS.ARGS())
        .def("setStandardScale", &PyAcadPlotConfiguration::setStandardScale, DS.ARGS({ "scale : PyAx.AcPlotScale" }))
        .def("customScale", &PyAcadPlotConfiguration::customScale, DS.ARGS())
        .def("setCustomScale", &PyAcadPlotConfiguration::setCustomScale, DS.ARGS({ "numerator : float", "denominator : float" }))
        .def("scaleLineweights", &PyAcadPlotConfiguration::scaleLineweights, DS.ARGS())
        .def("setScaleLineweights", &PyAcadPlotConfiguration::setScaleLineweights, DS.ARGS({ "scale_weights : bool" }))
        .def("plotWithLineweights", &PyAcadPlotConfiguration::plotWithLineweights, DS.ARGS())
        .def("setPlotWithLineweights", &PyAcadPlotConfiguration::setPlotWithLineweights, DS.ARGS({ "plot_weights : bool" }))
        .def("plotViewportsFirst", &PyAcadPlotConfiguration::plotViewportsFirst, DS.ARGS())
        .def("setPlotViewportsFirst", &PyAcadPlotConfiguration::setPlotViewportsFirst, DS.ARGS({ "viewports_first : bool" }))
        .def("styleSheet", &PyAcadPlotConfiguration::styleSheet, DS.ARGS())
        .def("setStyleSheet", &PyAcadPlotConfiguration::setStyleSheet, DS.ARGS({ "style_sheet : str" }))
        .def("paperMargins", &PyAcadPlotConfiguration::paperMargins, DS.ARGS())
        .def("paperSize", &PyAcadPlotConfiguration::paperSize, DS.ARGS())
        .def("plotOrigin", &PyAcadPlotConfiguration::plotOrigin, DS.ARGS())
        .def("setPlotOrigin", &PyAcadPlotConfiguration::setPlotOrigin, DS.ARGS({ "origin : PyGe.Point2d" }))
        .def("windowToPlot", &PyAcadPlotConfiguration::windowToPlot, DS.ARGS())
        .def("setWindowToPlot", &PyAcadPlotConfiguration::setWindowToPlot, DS.ARGS({ "lower_left : PyGe.Point2d", "upper_right : PyGe.Point2d" }))
        .def("plotWithPlotStyles", &PyAcadPlotConfiguration::plotWithPlotStyles, DS.ARGS())
        .def("setPlotWithPlotStyles", &PyAcadPlotConfiguration::setPlotWithPlotStyles, DS.ARGS({ "plot_styles : bool" }))
        .def("modelType", &PyAcadPlotConfiguration::modelType, DS.ARGS())
        .def("copyFrom", &PyAcadPlotConfiguration::copyFrom, DS.ARGS({ "source_config : PyAx.AcadPlotConfiguration" }))
        .def("canonicalMediaNames", &PyAcadPlotConfiguration::canonicalMediaNames, DS.ARGS())
        .def("plotDeviceNames", &PyAcadPlotConfiguration::plotDeviceNames, DS.ARGS())
        .def("plotStyleTableNames", &PyAcadPlotConfiguration::plotStyleTableNames, DS.ARGS())
        .def("refreshPlotDeviceInfo", &PyAcadPlotConfiguration::refreshPlotDeviceInfo, DS.ARGS())
        .def("localeMediaName", &PyAcadPlotConfiguration::localeMediaName, DS.ARGS({ "media_name : str" }))
        .def("cast", &PyAcadPlotConfiguration::cast, DS.SARGS({ "other_object : PyAx.AcadObject" })).staticmethod("cast")
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
        .def("setTabOrder", &PyAcadLayout::setTabOrder, DS.ARGS({ "index:int" }))
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
        .def("setCenter", &PyAcadView::setCenter, DS.ARGS({ "point: PyGe.Point3d" }))
        .def("height", &PyAcadView::height, DS.ARGS())
        .def("setHeight", &PyAcadView::setHeight, DS.ARGS({ "height_value: float" }))
        .def("width", &PyAcadView::width, DS.ARGS())
        .def("setWidth", &PyAcadView::setWidth, DS.ARGS({ "width_value: float" }))
        .def("target", &PyAcadView::target, DS.ARGS())
        .def("setTarget", &PyAcadView::setTarget, DS.ARGS({ "point: PyGe.Point3d" }))
        .def("direction", &PyAcadView::direction, DS.ARGS())
        .def("setDirection", &PyAcadView::setDirection, DS.ARGS({ "vector: PyGe.Vector3d" }))
        .def("name", &PyAcadView::name, DS.ARGS())
        .def("setName", &PyAcadView::setName, DS.ARGS({ "view_name: str" }))
        .def("categoryName", &PyAcadView::categoryName, DS.ARGS())
        .def("setCategoryName", &PyAcadView::setCategoryName, DS.ARGS({ "category_name: str" }))
        .def("layoutId", &PyAcadView::layoutId, DS.ARGS())
        .def("setLayoutId", &PyAcadView::setLayoutId, DS.ARGS({ "layout_id: PyDb.ObjectId" }))
        .def("layerState", &PyAcadView::layerState, DS.ARGS())
        .def("setLayerState", &PyAcadView::setLayerState, DS.ARGS({ "state_name:str" }))
        .def("hasVpAssociation", &PyAcadView::hasVpAssociation, DS.ARGS())
        .def("setHasVpAssociation", &PyAcadView::setHasVpAssociation, DS.ARGS({ "association_state:str" }))
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
        .def("name", &PyAcadDimStyle::name, DS.ARGS())
        .def("setName", &PyAcadDimStyle::setName, DS.ARGS({ "name: str" }))
        .def("copyFrom", &PyAcadDimStyle::copyFrom, DS.ARGS({ "otherObject: PyAx.AcadObject" }))
        .def("cast", &PyAcadDimStyle::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimStyle::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimStyle::PyAcadDimStyle(std::shared_ptr<PyIAcadDimStyleImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadDimStyle::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadDimStyle::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

void PyAcadDimStyle::copyFrom(const PyAcadObject& other) const
{
    impObj()->CopyFrom(*other.impObj());
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
        .def("color", &PyAcadLayer::color, DS.ARGS())
        .def("setColor", &PyAcadLayer::setColor, DS.ARGS({ "color:PyAx.AcColor" }))
        .def("trueColor", &PyAcadLayer::trueColor, DS.ARGS())
        .def("setTrueColor", &PyAcadLayer::setTrueColor, DS.ARGS({ "true_color:PyAx.AcadAcCmColor" }))
        .def("freeze", &PyAcadLayer::freeze, DS.ARGS())
        .def("setFreeze", &PyAcadLayer::setFreeze, DS.ARGS({ "is_frozen:bool" }))
        .def("layerOn", &PyAcadLayer::layerOn, DS.ARGS())
        .def("setLayerOn", &PyAcadLayer::setLayerOn, DS.ARGS({ "is_on:bool" }))
        .def("linetype", &PyAcadLayer::linetype, DS.ARGS())
        .def("setLinetype", &PyAcadLayer::setLinetype, DS.ARGS({ "linetype_name:str" }))
        .def("lock", &PyAcadLayer::lock, DS.ARGS())
        .def("setLock", &PyAcadLayer::setLock, DS.ARGS({ "is_locked:bool" }))
        .def("name", &PyAcadLayer::name, DS.ARGS())
        .def("setName", &PyAcadLayer::setName, DS.ARGS({ "layer_name:str" }))
        .def("plottable", &PyAcadLayer::plottable, DS.ARGS())
        .def("setPlottable", &PyAcadLayer::setPlottable, DS.ARGS({ "is_plottable:bool" }))
        .def("viewportDefault", &PyAcadLayer::viewportDefault, DS.ARGS())
        .def("setViewportDefault", &PyAcadLayer::setViewportDefault, DS.ARGS({ "is_default:bool" }))
        .def("plotStyleName", &PyAcadLayer::plotStyleName, DS.ARGS())
        .def("setPlotStyleName", &PyAcadLayer::setPlotStyleName, DS.ARGS({ "plot_style_name:str" }))
        .def("lineweight", &PyAcadLayer::lineweight, DS.ARGS())
        .def("setLineWeight", &PyAcadLayer::setLineWeight, DS.ARGS({ "line_weight:PyAx.AcLineWeight" }))
        .def("description", &PyAcadLayer::description, DS.ARGS())
        .def("setDescription", &PyAcadLayer::setDescription, DS.ARGS({ "description_text:str" }))
        .def("used", &PyAcadLayer::used, DS.ARGS())
        .def("material", &PyAcadLayer::material, DS.ARGS())
        .def("setMaterial", &PyAcadLayer::setMaterial, DS.ARGS({ "material_name:str" }))
        .def("cast", &PyAcadLayer::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLayer::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLayer::PyAcadLayer(std::shared_ptr<PyIAcadLayerImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcColor PyAcadLayer::color() const
{
    return impObj()->GetColor();
}

void PyAcadLayer::setColor(PyAcColor val) const
{
    impObj()->SetColor(val);
}

PyAcadAcCmColor PyAcadLayer::trueColor() const
{
    return PyAcadAcCmColor{ impObj()->GetTrueColor() };
}

void PyAcadLayer::setTrueColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetTrueColor(*val.impObj());
}

bool PyAcadLayer::freeze() const
{
    return impObj()->GetFreeze();
}

void PyAcadLayer::setFreeze(bool val) const
{
    impObj()->SetFreeze(val);
}

bool PyAcadLayer::layerOn() const
{
    return impObj()->GetLayerOn();
}

void PyAcadLayer::setLayerOn(bool val) const
{
    impObj()->SetLayerOn(val);
}

std::string PyAcadLayer::linetype() const
{
    return wstr_to_utf8(impObj()->GetLinetype());
}

void PyAcadLayer::setLinetype(const std::string& val) const
{
    impObj()->SetLinetype(utf8_to_wstr(val).c_str());
}

bool PyAcadLayer::lock() const
{
    return impObj()->GetLock();
}

void PyAcadLayer::setLock(bool val) const
{
    impObj()->SetLock(val);
}

std::string PyAcadLayer::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadLayer::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

bool PyAcadLayer::plottable() const
{
    return impObj()->GetPlottable();
}

void PyAcadLayer::setPlottable(bool val) const
{
    impObj()->SetPlottable(val);
}

bool PyAcadLayer::viewportDefault() const
{
    return impObj()->GetViewportDefault();
}

void PyAcadLayer::setViewportDefault(bool val) const
{
    impObj()->SetViewportDefault(val);
}

std::string PyAcadLayer::plotStyleName() const
{
    return wstr_to_utf8(impObj()->GetPlotStyleName());
}

void PyAcadLayer::setPlotStyleName(const std::string& val) const
{
    impObj()->SetPlotStyleName(utf8_to_wstr(val).c_str());
}

PyAcLineWeight PyAcadLayer::lineweight() const
{
    return impObj()->GetLineweight();
}

void PyAcadLayer::setLineWeight(PyAcLineWeight val) const
{
    impObj()->SetLineWeight(val);
}

std::string PyAcadLayer::description() const
{
    return wstr_to_utf8(impObj()->GetDescription());
}

void PyAcadLayer::setDescription(const std::string& val) const
{
    impObj()->SetDescription(utf8_to_wstr(val).c_str());
}

bool PyAcadLayer::used() const
{
    return impObj()->GetUsed();
}

std::string PyAcadLayer::material() const
{
    return wstr_to_utf8(impObj()->GetMaterial());
}

void PyAcadLayer::setMaterial(const std::string& val) const
{
    impObj()->SetMaterial(utf8_to_wstr(val).c_str());
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
        .def("name", &PyAcadLineType::name, DS.ARGS())
        .def("setName", &PyAcadLineType::setName, DS.ARGS({ "name:str" }))
        .def("description", &PyAcadLineType::description, DS.ARGS())
        .def("setDescription", &PyAcadLineType::setDescription, DS.ARGS({ "otherObject:str" }))
        .def("cast", &PyAcadLineType::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadLineType::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadLineType::PyAcadLineType(std::shared_ptr<PyIAcadLineTypeImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadLineType::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadLineType::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

std::string PyAcadLineType::description() const
{
    return wstr_to_utf8(impObj()->GetDescription());
}

void PyAcadLineType::setDescription(const std::string& val) const
{
    impObj()->SetDescription(utf8_to_wstr(val).c_str());
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
        .def("name", &PyAcadXRecord::name, DS.ARGS())
        .def("setName", &PyAcadXRecord::setName, DS.ARGS({ "name:str" }))
        .def("xrecordData", &PyAcadXRecord::xrecordData, DS.ARGS())
        .def("setXRecordData", &PyAcadXRecord::setXRecordData, DS.ARGS({ "xrecordData:Collection[tuple[int,Any]]" }))
        .def("translateIDs", &PyAcadXRecord::translateIDs, DS.ARGS())
        .def("setTranslateIDs", &PyAcadXRecord::setTranslateIDs, DS.ARGS({ "flag:bool" }))
        .def("cast", &PyAcadXRecord::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadXRecord::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadXRecord::PyAcadXRecord(std::shared_ptr<PyIAcadXRecordImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadXRecord::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadXRecord::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

boost::python::list PyAcadXRecord::xrecordData() const
{
    //TODO: same ad xdata and selection set
    PyAutoLockGIL lock;
    const auto& tvs = impObj()->GetXRecordData();
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

void PyAcadXRecord::setXRecordData(const boost::python::object& pylist) const
{
    //TODO: same ad xdata and selection set
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
    impObj()->SetXRecordData(tvs);
}

bool PyAcadXRecord::translateIDs() const
{
    return impObj()->GetTranslateIDs();
}

void PyAcadXRecord::setTranslateIDs(bool val) const
{
    impObj()->SetTranslateIDs(val);
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
        .def("name", &PyAcadDictionary::name, DS.ARGS())
        .def("setName", &PyAcadDictionary::setName, DS.ARGS({ "name:str" }))
        .def("addObject", &PyAcadDictionary::addObject, DS.ARGS({ "keyword:str", "objectName:str" }))
        .def("objName", &PyAcadDictionary::objName, DS.ARGS({ "val:PyAx.AcadObject" }))
        .def("object", &PyAcadDictionary::object, DS.ARGS({ "objectName:str" }))
        .def("remove", &PyAcadDictionary::remove, DS.ARGS({ "objectName:str" }))
        .def("rename", &PyAcadDictionary::remove, DS.ARGS({ "oldName:str", "newName:str" }))
        .def("replace", &PyAcadDictionary::replace, DS.ARGS({ "oldName:str", "obj:PyAx.AcadObject" }))
        .def("item", &PyAcadDictionary::item, DS.ARGS({ "idx:int" }))
        .def("items", &PyAcadDictionary::items, DS.ARGS())
        .def("count", &PyAcadDictionary::count, DS.ARGS())
        .def("addXRecord", &PyAcadDictionary::addXRecord, DS.ARGS({ "keyword:str" }))
        .def("cast", &PyAcadDictionary::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDictionary::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDictionary::PyAcadDictionary(std::shared_ptr<PyIAcadDictionaryImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadDictionary::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadDictionary::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

PyAcadObject PyAcadDictionary::addObject(const std::string& keyword, const std::string& objectName) const
{
    return PyAcadObject{ impObj()->AddObject(utf8_to_wstr(keyword).c_str(), utf8_to_wstr(objectName).c_str()) };
}

std::string PyAcadDictionary::objName(const PyAcadObject& src) const
{
    return wstr_to_utf8(impObj()->GetName(*src.impObj()));
}

PyAcadObject PyAcadDictionary::object(const std::string& objectName) const
{
    return PyAcadObject{ impObj()->GetObject(utf8_to_wstr(objectName).c_str()) };
}

PyAcadObject PyAcadDictionary::remove(const std::string& objectName) const
{
    return PyAcadObject{ impObj()->Remove(utf8_to_wstr(objectName).c_str()) };
}

void PyAcadDictionary::rename(const std::string& oldName, const std::string& newName) const
{
    impObj()->Rename(utf8_to_wstr(oldName).c_str(), utf8_to_wstr(newName).c_str());
}

void PyAcadDictionary::replace(const std::string& oldName, const PyAcadObject& src) const
{
    impObj()->Replace(utf8_to_wstr(oldName).c_str(), *src.impObj());
}

PyAcadObject PyAcadDictionary::item(long idx) const
{
    if (idx >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadObject{ impObj()->GetItem(idx) };
}

boost::python::list PyAcadDictionary::items() const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetIter())
        _pylist.append(PyAcadObject{ item });
    return _pylist;
}

long PyAcadDictionary::count() const
{
    return impObj()->GetCount();
}

PyAcadXRecord PyAcadDictionary::addXRecord(const std::string& keyword) const
{
    return PyAcadXRecord{ impObj()->AddXRecord(utf8_to_wstr(keyword).c_str()) };
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
        .def("bigFontFile", &PyAcadTextStyle::bigFontFile, DS.ARGS())
        .def("setBigFontFile", &PyAcadTextStyle::setBigFontFile, DS.ARGS({ "font_file: str" }))
        .def("fontFile", &PyAcadTextStyle::fontFile, DS.ARGS())
        .def("setFontFile", &PyAcadTextStyle::setFontFile, DS.ARGS({ "font_file: str" }))
        .def("height", &PyAcadTextStyle::height, DS.ARGS())
        .def("setHeight", &PyAcadTextStyle::setHeight, DS.ARGS({ "text_height: float" }))
        .def("lastHeight", &PyAcadTextStyle::lastHeight, DS.ARGS())
        .def("setLastHeight", &PyAcadTextStyle::setLastHeight, DS.ARGS({ "last_height: float" }))
        .def("name", &PyAcadTextStyle::name, DS.ARGS())
        .def("obliqueAngle", &PyAcadTextStyle::obliqueAngle, DS.ARGS())
        .def("setObliqueAngle", &PyAcadTextStyle::setObliqueAngle, DS.ARGS({ "angle: float" }))
        .def("textGenerationFlag", &PyAcadTextStyle::textGenerationFlag, DS.ARGS())
        .def("setTextGenerationFlag", &PyAcadTextStyle::setTextGenerationFlag, DS.ARGS({ "flag: int" }))
        .def("width", &PyAcadTextStyle::width, DS.ARGS())
        .def("setWidth", &PyAcadTextStyle::setWidth, DS.ARGS({ "width_factor: float" }))
        .def("font", &PyAcadTextStyle::font, DS.ARGS())
        .def("setFont", &PyAcadTextStyle::setFont, DS.ARGS({ "typeFace: str","bold: bool" ,"italic: bool","charset: int","pitchAndFamily: int" }))
        .def("cast", &PyAcadTextStyle::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTextStyle::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTextStyle::PyAcadTextStyle(std::shared_ptr<PyIAcadTextStyleImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadTextStyle::bigFontFile() const
{
    return wstr_to_utf8(impObj()->GetBigFontFile());
}

void PyAcadTextStyle::setBigFontFile(const std::string& val) const
{
    impObj()->SetBigFontFile(utf8_to_wstr(val).c_str());
}

std::string PyAcadTextStyle::fontFile() const
{
    return wstr_to_utf8(impObj()->GetFontFile());
}

void PyAcadTextStyle::setFontFile(const std::string& val) const
{
    impObj()->SetFontFile(utf8_to_wstr(val).c_str());
}

double PyAcadTextStyle::height() const
{
    return impObj()->GetHeight();
}

void PyAcadTextStyle::setHeight(double val) const
{
    impObj()->SetHeight(val);
}

double PyAcadTextStyle::lastHeight() const
{
    return impObj()->GetLastHeight();
}

void PyAcadTextStyle::setLastHeight(double val) const
{
    impObj()->SetLastHeight(val);
}

std::string PyAcadTextStyle::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

double PyAcadTextStyle::obliqueAngle() const
{
    return impObj()->GetObliqueAngle();
}

void PyAcadTextStyle::setObliqueAngle(double val) const
{
    impObj()->SetObliqueAngle(val);
}

long PyAcadTextStyle::textGenerationFlag() const
{
    return impObj()->GetTextGenerationFlag();
}

void PyAcadTextStyle::setTextGenerationFlag(long val) const
{
    impObj()->SetTextGenerationFlag(val);
}

double PyAcadTextStyle::width() const
{
    return impObj()->GetWidth();
}

void PyAcadTextStyle::setWidth(double val) const
{
    impObj()->SetWidth(val);
}

boost::python::tuple PyAcadTextStyle::font() const
{
    return impObj()->GetFont();
}

void PyAcadTextStyle::setFont(const std::string& typeFace, bool bold, bool italic, long charset, long pitchAndFamily) const
{
    impObj()->SetFont(utf8_to_wstr(typeFace).c_str(), bold, italic, charset, pitchAndFamily);
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
        .def("name", &PyAcadUCS::name, DS.ARGS())
        .def("setName", &PyAcadUCS::setName, DS.ARGS({ "ucs_name: str" }))
        .def("origin", &PyAcadUCS::origin, DS.ARGS())
        .def("setOrigin", &PyAcadUCS::setOrigin, DS.ARGS({ "origin_point: PyGe.Point3d" }))
        .def("xVector", &PyAcadUCS::xVector, DS.ARGS())
        .def("setXVector", &PyAcadUCS::setXVector, DS.ARGS({ "x_axis_vector: PyGe.Vector3d" }))
        .def("yVector", &PyAcadUCS::yVector, DS.ARGS())
        .def("setYVector", &PyAcadUCS::setYVector, DS.ARGS({ "y_axis_vector: PyGe.Vector3d" }))
        .def("ucsMatrix", &PyAcadUCS::ucsMatrix, DS.ARGS())
        .def("cast", &PyAcadUCS::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadUCS::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadUCS::PyAcadUCS(std::shared_ptr<PyIAcadUCSImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadUCS::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadUCS::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

AcGePoint3d PyAcadUCS::origin() const
{
    return impObj()->GetOrigin();
}

void PyAcadUCS::setOrigin(const AcGePoint3d& val) const
{
    impObj()->SetOrigin(val);
}

AcGeVector3d PyAcadUCS::xVector() const
{
    return impObj()->GetXVector();
}

void PyAcadUCS::setXVector(const AcGeVector3d& val) const
{
    impObj()->SetXVector(val);
}

AcGeVector3d PyAcadUCS::yVector() const
{
    return impObj()->GetYVector();
}

void PyAcadUCS::setYVector(const AcGeVector3d& val) const
{
    impObj()->SetYVector(val);
}

AcGeMatrix3d PyAcadUCS::ucsMatrix() const
{
    return impObj()->GetUCSMatrix();
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
        .def("center", &PyAcadViewport::center, DS.ARGS())
        .def("setCenter", &PyAcadViewport::setCenter, DS.ARGS({ "center_point: PyGe.Point3d" }))
        .def("height", &PyAcadViewport::height, DS.ARGS())
        .def("setHeight", &PyAcadViewport::setHeight, DS.ARGS({ "height_value: float" }))
        .def("width", &PyAcadViewport::width, DS.ARGS())
        .def("setWidth", &PyAcadViewport::setWidth, DS.ARGS({ "width_value: float" }))
        .def("target", &PyAcadViewport::target, DS.ARGS())
        .def("setTarget", &PyAcadViewport::setTarget, DS.ARGS({ "target_point: PyGe.Point3d" }))
        .def("direction", &PyAcadViewport::direction, DS.ARGS())
        .def("setDirection", &PyAcadViewport::setDirection, DS.ARGS({ "view_direction: PyGe.Vector3d" }))
        .def("name", &PyAcadViewport::name, DS.ARGS())
        .def("setName", &PyAcadViewport::setName, DS.ARGS({ "viewport_name: str" }))
        .def("gridOn", &PyAcadViewport::gridOn, DS.ARGS())
        .def("setGridOn", &PyAcadViewport::setGridOn, DS.ARGS({ "show_grid: bool" }))
        .def("orthoOn", &PyAcadViewport::orthoOn, DS.ARGS())
        .def("setOrthoOn", &PyAcadViewport::setOrthoOn, DS.ARGS({ "enable_ortho: bool" }))
        .def("snapBasePoint", &PyAcadViewport::snapBasePoint, DS.ARGS())
        .def("setSnapBasePoint", &PyAcadViewport::setSnapBasePoint, DS.ARGS({ "snap_point: PyGe.Point3d" }))
        .def("snapOn", &PyAcadViewport::snapOn, DS.ARGS())
        .def("setSnapOn", &PyAcadViewport::setSnapOn, DS.ARGS({ "enable_snap: bool" }))
        .def("snapRotationAngle", &PyAcadViewport::snapRotationAngle, DS.ARGS())
        .def("setSnapRotationAngle", &PyAcadViewport::setSnapRotationAngle, DS.ARGS({ "rotation_angle: float" }))
        .def("ucsIconOn", &PyAcadViewport::ucsIconOn, DS.ARGS())
        .def("setUCSIconOn", &PyAcadViewport::setUCSIconOn, DS.ARGS({ "show_ucs_icon: bool" }))
        .def("ucsIconAtOrigin", &PyAcadViewport::ucsIconAtOrigin, DS.ARGS())
        .def("setUCSIconAtOrigin", &PyAcadViewport::setUCSIconAtOrigin, DS.ARGS({ "ucs_at_origin: bool" }))
        .def("lowerLeftCorner", &PyAcadViewport::lowerLeftCorner, DS.ARGS())
        .def("upperRightCorner", &PyAcadViewport::upperRightCorner, DS.ARGS())
        .def("split", &PyAcadViewport::split, DS.ARGS({ "split_type: PyAx.AcviewportSplitType" }))
        .def("gridSpacing", &PyAcadViewport::gridSpacing, DS.ARGS())
        .def("setGridSpacing", &PyAcadViewport::setGridSpacing, DS.ARGS({ "XSpacing: float", "YSpacing: float" }))
        .def("snapSpacing", &PyAcadViewport::snapSpacing, DS.ARGS())
        .def("setSnapSpacing", &PyAcadViewport::setSnapSpacing, DS.ARGS({ "XSpacing: float", "YSpacing: float" }))
        .def("setView", &PyAcadViewport::setView, DS.ARGS({ "view_object: PyAx.AcadView" }))
        .def("arcSmoothness", &PyAcadViewport::arcSmoothness, DS.ARGS())
        .def("setArcSmoothness", &PyAcadViewport::setArcSmoothness, DS.ARGS({ "smoothness_value: int" }))
        .def("cast", &PyAcadViewport::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadViewport::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadViewport::PyAcadViewport(std::shared_ptr<PyIAcadViewportImpl> ptr)
    : PyAcadObject(ptr)
{
}

AcGePoint3d PyAcadViewport::center() const
{
    return impObj()->GetCenter();
}

void PyAcadViewport::setCenter(const AcGePoint3d& val) const
{
    impObj()->SetCenter(val);
}

double PyAcadViewport::height() const
{
    return impObj()->GetHeight();
}

void PyAcadViewport::setHeight(double val) const
{
    impObj()->SetHeight(val);
}

double PyAcadViewport::width() const
{
    return impObj()->GetWidth();
}

void PyAcadViewport::setWidth(double val) const
{
    impObj()->SetWidth(val);
}

AcGePoint3d PyAcadViewport::target() const
{
    return impObj()->GetTarget();
}

void PyAcadViewport::setTarget(const AcGePoint3d& val) const
{
    impObj()->SetTarget(val);
}

AcGeVector3d PyAcadViewport::direction() const
{
    return impObj()->GetDirection();
}

void PyAcadViewport::setDirection(const AcGeVector3d& val) const
{
    impObj()->SetDirection(val);
}

std::string PyAcadViewport::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadViewport::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

bool PyAcadViewport::gridOn() const
{
    return impObj()->GetGridOn();
}

void PyAcadViewport::setGridOn(bool val) const
{
    impObj()->SetGridOn(val);
}

bool PyAcadViewport::orthoOn() const
{
    return impObj()->GetOrthoOn();
}

void PyAcadViewport::setOrthoOn(bool val) const
{
    impObj()->SetOrthoOn(val);
}

AcGePoint3d PyAcadViewport::snapBasePoint() const
{
    return impObj()->GetSnapBasePoint();
}

void PyAcadViewport::setSnapBasePoint(const AcGePoint3d& val) const
{
    impObj()->SetSnapBasePoint(val);
}

bool PyAcadViewport::snapOn() const
{
    return impObj()->GetSnapOn();
}

void PyAcadViewport::setSnapOn(bool val) const
{
    impObj()->SetSnapOn(val);
}

double PyAcadViewport::snapRotationAngle() const
{
    return impObj()->GetSnapRotationAngle();
}

void PyAcadViewport::setSnapRotationAngle(double val) const
{
    impObj()->SetSnapRotationAngle(val);
}

bool PyAcadViewport::ucsIconOn() const
{
    return impObj()->GetUCSIconOn();
}

void PyAcadViewport::setUCSIconOn(bool val) const
{
    impObj()->SetUCSIconOn(val);
}

bool PyAcadViewport::ucsIconAtOrigin() const
{
    return impObj()->GetUCSIconAtOrigin();
}

void PyAcadViewport::setUCSIconAtOrigin(bool val) const
{
    impObj()->SetUCSIconAtOrigin(val);
}

AcGePoint2d PyAcadViewport::lowerLeftCorner() const
{
    return impObj()->GetLowerLeftCorner();
}

AcGePoint2d PyAcadViewport::upperRightCorner() const
{
    return impObj()->GetUpperRightCorner();
}

void PyAcadViewport::split(PyAcViewportSplitType val) const
{
    impObj()->Split(val);
}

boost::python::tuple PyAcadViewport::gridSpacing() const
{
    PyAutoLockGIL lock;
    double XSpacing = 0.0;
    double YSpacing = 0.0;
    impObj()->GetGridSpacing(XSpacing, YSpacing);
    return boost::python::make_tuple(XSpacing, YSpacing);
}

void PyAcadViewport::setGridSpacing(double XSpacing, double YSpacing) const
{
    impObj()->SetGridSpacing(XSpacing, YSpacing);
}

boost::python::tuple PyAcadViewport::snapSpacing() const
{
    PyAutoLockGIL lock;
    double XSpacing = 0.0;
    double YSpacing = 0.0;
    impObj()->GetSnapSpacing(XSpacing, YSpacing);
    return boost::python::make_tuple(XSpacing, YSpacing);
}

void PyAcadViewport::setSnapSpacing(double XSpacing, double YSpacing) const
{
    impObj()->SetSnapSpacing(XSpacing, YSpacing);
}

void PyAcadViewport::setView(const PyAcadView& scr) const
{
    impObj()->SetView(*scr.impObj());
}

long PyAcadViewport::arcSmoothness() const
{
    return impObj()->GetArcSmoothness();
}

void PyAcadViewport::setArcSmoothness(long val) const
{
    impObj()->SetArcSmoothness(val);
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
        .def("count", &PyAcadSectionManager::count, DS.ARGS())
        .def("item", &PyAcadSectionManager::item, DS.ARGS({ "index: int" }))
        .def("liveSection", &PyAcadSectionManager::liveSection, DS.ARGS())
        .def("uniqueSectionName", &PyAcadSectionManager::uniqueSectionName, DS.ARGS({ "baseName: str" }))
        .def("cast", &PyAcadSectionManager::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSectionManager::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSectionManager::PyAcadSectionManager(std::shared_ptr<PyIAcadSectionManagerImpl> ptr)
    : PyAcadObject(ptr)
{
}

PyAcadSection PyAcadSectionManager::item(long index) const
{
    if (index >= count())
        throw std::out_of_range{ "IndexError " };
    return PyAcadSection{ impObj()->GetItem(index) };
}

long PyAcadSectionManager::count() const
{
    return impObj()->GetCount();
}

PyAcadSection PyAcadSectionManager::liveSection() const
{
    return PyAcadSection{ impObj()->GetLiveSection() };
}

std::string PyAcadSectionManager::uniqueSectionName(const std::string& val) const
{
    return wstr_to_utf8(impObj()->GetUniqueSectionName(utf8_to_wstr(val).c_str()));
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
        .def("name", &PyAcadMaterial::name, DS.ARGS())
        .def("setName", &PyAcadMaterial::setName, DS.ARGS({ "name: str" }))
        .def("description", &PyAcadMaterial::description, DS.ARGS())
        .def("setDescription", &PyAcadMaterial::setDescription, DS.ARGS({ "description: str" }))
        .def("cast", &PyAcadMaterial::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMaterial::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMaterial::PyAcadMaterial(std::shared_ptr<PyIAcadMaterialImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadMaterial::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadMaterial::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

std::string PyAcadMaterial::description() const
{
    return wstr_to_utf8(impObj()->GetDescription());
}

void PyAcadMaterial::setDescription(const std::string& val) const
{
    impObj()->SetDescription(utf8_to_wstr(val).c_str());
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
        .def("name", &PyAcadTableStyle::name, DS.ARGS())
        .def("setName", &PyAcadTableStyle::setName, DS.ARGS({ "style_name: str" }))
        .def("description", &PyAcadTableStyle::description, DS.ARGS())
        .def("setDescription", &PyAcadTableStyle::setDescription, DS.ARGS({ "description_text: str" }))
        .def("bitFlags", &PyAcadTableStyle::bitFlags, DS.ARGS())
        .def("setBitFlags", &PyAcadTableStyle::setBitFlags, DS.ARGS({ "flags_value: int" }))
        .def("flowDirection", &PyAcadTableStyle::flowDirection, DS.ARGS())
        .def("setFlowDirections", &PyAcadTableStyle::setFlowDirections, DS.ARGS({ "direction: PyAx.AcTableDirection" }))
        .def("horzCellMargin", &PyAcadTableStyle::horzCellMargin, DS.ARGS())
        .def("setHorzCellMargin", &PyAcadTableStyle::setHorzCellMargin, DS.ARGS({ "margin_value: float" }))
        .def("vertCellMargin", &PyAcadTableStyle::vertCellMargin, DS.ARGS())
        .def("setVertCellMargin", &PyAcadTableStyle::setVertCellMargin, DS.ARGS({ "margin_value: float" }))
        .def("titleSuppressed", &PyAcadTableStyle::titleSuppressed, DS.ARGS())
        .def("setTitleSuppressed", &PyAcadTableStyle::setTitleSuppressed, DS.ARGS({ "suppress_flag: bool" }))
        .def("headerSuppressed", &PyAcadTableStyle::headerSuppressed, DS.ARGS())
        .def("setHeaderSuppressed", &PyAcadTableStyle::setHeaderSuppressed, DS.ARGS({ "suppress_flag: bool" }))
        .def("createCellStyle", &PyAcadTableStyle::createCellStyle, DS.ARGS({ "cell_style_name:str" }))
        .def("createCellStyleFromStyle", &PyAcadTableStyle::createCellStyleFromStyle, DS.ARGS({ "new_cell_style:str", "source_cell_style:str" }))
        .def("renameCellStyle", &PyAcadTableStyle::renameCellStyle, DS.ARGS({ "old_name:str", "new_name:str" }))
        .def("deleteCellStyle", &PyAcadTableStyle::deleteCellStyle, DS.ARGS({ "cell_style_name:str" }))
        .def("uniqueCellStyleName", &PyAcadTableStyle::uniqueCellStyleName, DS.ARGS({ "base_name:str" }))
        .def("isCellStyleInUse", &PyAcadTableStyle::isCellStyleInUse, DS.ARGS({ "cell_style_name:str" }))
        .def("numCellStyles", &PyAcadTableStyle::numCellStyles, DS.ARGS())
        .def("cellStyles", &PyAcadTableStyle::cellStyles, DS.ARGS())
        .def("textStyleId", &PyAcadTableStyle::textStyleId, DS.ARGS({ "cell_style_name:str" }))
        .def("setTextStyleId", &PyAcadTableStyle::setTextStyleId, DS.ARGS({ "cell_style_name:str", "text_style_id:PyDb.ObjectIdr" }))
        .def("textHeight", &PyAcadTableStyle::textHeight, DS.ARGS({ "cell_style_name:str" }))
        .def("setTextHeight", &PyAcadTableStyle::setTextHeight, DS.ARGS({ "cell_style_name:str", "height_value:float" }))
        .def("alignment", &PyAcadTableStyle::alignment, DS.ARGS({ "cell_style_name:str" }))
        .def("setAlignment", &PyAcadTableStyle::setAlignment, DS.ARGS({ "cell_style_name:str", "alignment_type:PyAx.AcCellAlignment" }))
        .def("color", &PyAcadTableStyle::color, DS.ARGS({ "cell_style_name:str" }))
        .def("setColor", &PyAcadTableStyle::setColor, DS.ARGS({ "cell_style_name:str", "color_value:PyAx.AcadAcCmColor" }))
        .def("backgroundColor", &PyAcadTableStyle::backgroundColor, DS.ARGS({ "cell_style_name:str" }))
        .def("setBackgroundColor", &PyAcadTableStyle::setBackgroundColor, DS.ARGS({ "cell_style_name:str", "color_value:PyAx.AcadAcCmColor" }))
        .def("dataType", &PyAcadTableStyle::dataType, DS.ARGS({ "cell_style_name:str" }))
        .def("setDataType", &PyAcadTableStyle::setDataType, DS.ARGS({ "cell_style_name:str", "data_type:PyAx.AcValueDataType","unit_type:PyAx.AcValueUnitType" }))
        .def("format", &PyAcadTableStyle::format, DS.ARGS({ "cell_style_name:str" }))
        .def("setFormat", &PyAcadTableStyle::setFormat, DS.ARGS({ "cell_style_name:str", "format_string:str" }))
        .def("cellClass", &PyAcadTableStyle::cellClass, DS.ARGS({ "cell_style_name:str" }))
        .def("setCellClass", &PyAcadTableStyle::setCellClass, DS.ARGS({ "cell_style_name:str", "class_value:int" }))
        .def("rotation", &PyAcadTableStyle::rotation, DS.ARGS({ "cell_style_name:str" }))
        .def("setRotation", &PyAcadTableStyle::setRotation, DS.ARGS({ "cell_style_name:str", "rotation_angle:int" }))
        .def("isMergeAllEnabled", &PyAcadTableStyle::isMergeAllEnabled, DS.ARGS({ "cell_style_name:str" }))
        .def("enableMergeAll", &PyAcadTableStyle::enableMergeAll, DS.ARGS({ "cell_style_name:str", "enable_flag:bool" }))
        .def("gridLineWeight", &PyAcadTableStyle::gridLineWeight, DS.ARGS({ "cell_style_name:str","grid_line_type:PyAx.AcGridLineType" }))
        .def("setGridLineWeight", &PyAcadTableStyle::setGridLineWeight, DS.ARGS({ "cell_style_name:str", "grid_line_type:PyAx.AcGridLineType",  "line_weight:PyAx.AcLineWeight" }))
        .def("gridColor", &PyAcadTableStyle::gridColor, DS.ARGS({ "cell_style_name:str","grid_line_type:PyAx.AcGridLineType" }))
        .def("setGridColor", &PyAcadTableStyle::setGridColor, DS.ARGS({ "cell_style_name:str", "grid_line_type:PyAx.AcGridLineType",  "color_value:PyAx.AcadAcCmColor" }))
        .def("gridVisibility", &PyAcadTableStyle::gridVisibility, DS.ARGS({ "cell_style_name:str","grid_line_type:PyAx.AcGridLineType" }))
        .def("setGridVisibility", &PyAcadTableStyle::setGridVisibility, DS.ARGS({ "cell_style_name:str", "grid_line_type:PyAx.AcGridLineType", "visibility_flag:bool" }))
        .def("templateId", &PyAcadTableStyle::templateId, DS.ARGS())
        .def("setTemplateId", &PyAcadTableStyle::setTemplateId1)
        .def("setTemplateId", &PyAcadTableStyle::setTemplateId2, DS.ARGS({ "id:PyDb.ObjectId", "option:PyAx.AcMergeCellStyleOption = PyAx.AcMergeCellStyleOption.acMergeCellStyleNone" }))
        .def("cast", &PyAcadTableStyle::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadTableStyle::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadTableStyle::PyAcadTableStyle(std::shared_ptr<PyIAcadTableStyleImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadTableStyle::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadTableStyle::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

std::string PyAcadTableStyle::description() const
{
    return wstr_to_utf8(impObj()->GetDescription());
}

void PyAcadTableStyle::setDescription(const std::string& val) const
{
    impObj()->SetDescription(utf8_to_wstr(val).c_str());
}

long PyAcadTableStyle::bitFlags() const
{
    return impObj()->GetBitFlags();
}

void PyAcadTableStyle::setBitFlags(long val) const
{
    impObj()->SetBitFlags(val);
}

PyAcTableDirection PyAcadTableStyle::flowDirection() const
{
    return impObj()->GetFlowDirection();
}

void PyAcadTableStyle::setFlowDirections(PyAcTableDirection val) const
{
    impObj()->SetFlowDirections(val);
}

double PyAcadTableStyle::horzCellMargin() const
{
    return impObj()->GetHorzCellMargin();
}

void PyAcadTableStyle::setHorzCellMargin(double val) const
{
    impObj()->SetHorzCellMargin(val);
}

double PyAcadTableStyle::vertCellMargin() const
{
    return impObj()->GetVertCellMargin();
}

void PyAcadTableStyle::setVertCellMargin(double val) const
{
    impObj()->SetVertCellMargin(val);
}

bool PyAcadTableStyle::titleSuppressed() const
{
    return impObj()->GetTitleSuppressed();
}

void PyAcadTableStyle::setTitleSuppressed(bool val) const
{
    impObj()->SetTitleSuppressed(val);
}

bool PyAcadTableStyle::headerSuppressed() const
{
    return impObj()->GetHeaderSuppressed();
}

void PyAcadTableStyle::setHeaderSuppressed(bool val) const
{
    impObj()->SetHeaderSuppressed(val);
}

void PyAcadTableStyle::createCellStyle(const std::string& cellStyle) const
{
    impObj()->CreateCellStyle(utf8_to_wstr(cellStyle).c_str());
}

void PyAcadTableStyle::createCellStyleFromStyle(const std::string& cellStyle, const std::string& sourceCellStyle) const
{
    impObj()->CreateCellStyleFromStyle(utf8_to_wstr(cellStyle).c_str(), utf8_to_wstr(sourceCellStyle).c_str());
}

void PyAcadTableStyle::renameCellStyle(const std::string& oldName, const std::string& newName) const
{
    impObj()->RenameCellStyle(utf8_to_wstr(oldName).c_str(), utf8_to_wstr(newName).c_str());
}

void PyAcadTableStyle::deleteCellStyle(const std::string& cellStyle) const
{
    impObj()->DeleteCellStyle(utf8_to_wstr(cellStyle).c_str());
}

std::string PyAcadTableStyle::uniqueCellStyleName(const std::string& basename) const
{
    return wstr_to_utf8(impObj()->GetUniqueCellStyleName(utf8_to_wstr(basename).c_str()));
}

bool PyAcadTableStyle::isCellStyleInUse(const std::string& cellStyle) const
{
    return impObj()->GetIsCellStyleInUse(utf8_to_wstr(cellStyle).c_str());
}

long PyAcadTableStyle::numCellStyles() const
{
    return impObj()->GetNumCellStyles();
}

boost::python::list PyAcadTableStyle::cellStyles() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->GetCellStyles())
        pylist.append(wstr_to_utf8(item));
    return pylist;
}

PyDbObjectId PyAcadTableStyle::textStyleId(const std::string& cellStyle) const
{
    return impObj()->GetTextStyleId(utf8_to_wstr(cellStyle).c_str());
}

void PyAcadTableStyle::setTextStyleId(const std::string& cellStyle, const PyDbObjectId& oid) const
{
    impObj()->SetTextStyleId(utf8_to_wstr(cellStyle).c_str(), oid.m_id);
}

double PyAcadTableStyle::textHeight(const std::string& cellStyle) const
{
    return impObj()->GetTextHeight2(utf8_to_wstr(cellStyle).c_str());
}

void PyAcadTableStyle::setTextHeight(const std::string& cellStyle, double height) const
{
    impObj()->SetTextHeight2(utf8_to_wstr(cellStyle).c_str(), height);
}

PyAcCellAlignment PyAcadTableStyle::alignment(const std::string& cellStyle) const
{
    return impObj()->GetAlignment2(utf8_to_wstr(cellStyle).c_str());
}

void PyAcadTableStyle::setAlignment(const std::string& cellStyle, PyAcCellAlignment val) const
{
    impObj()->SetAlignment2(utf8_to_wstr(cellStyle).c_str(), val);
}

PyAcadAcCmColor PyAcadTableStyle::color(const std::string& cellStyle) const
{
    return PyAcadAcCmColor{ impObj()->GetColor2(utf8_to_wstr(cellStyle).c_str()) };
}

void PyAcadTableStyle::setColor(const std::string& cellStyle, const PyAcadAcCmColor& val) const
{
    impObj()->SetColor2(utf8_to_wstr(cellStyle).c_str(), *val.impObj());
}

PyAcadAcCmColor PyAcadTableStyle::backgroundColor(const std::string& cellStyle) const
{
    return PyAcadAcCmColor{ impObj()->GetBackgroundColor2(utf8_to_wstr(cellStyle).c_str()) };
}

void PyAcadTableStyle::setBackgroundColor(const std::string& cellStyle, const PyAcadAcCmColor& val) const
{
    impObj()->SetBackgroundColor2(utf8_to_wstr(cellStyle).c_str(), *val.impObj());
}

boost::python::tuple PyAcadTableStyle::dataType(const std::string& cellStyle) const
{
    return impObj()->GetDataType2(utf8_to_wstr(cellStyle).c_str());
}

void PyAcadTableStyle::setDataType(const std::string& cellStyle, PyAcValueDataType nDataType, PyAcValueUnitType nUnitType) const
{
    impObj()->SetDataType2(utf8_to_wstr(cellStyle).c_str(), nDataType, nUnitType);
}

std::string PyAcadTableStyle::format(const std::string& cellStyle) const
{
    return wstr_to_utf8(impObj()->GetFormat2(utf8_to_wstr(cellStyle).c_str()));
}

void PyAcadTableStyle::setFormat(const std::string& cellStyle, const std::string& val) const
{
    impObj()->SetFormat2(utf8_to_wstr(cellStyle).c_str(), utf8_to_wstr(val).c_str());
}

int PyAcadTableStyle::cellClass(const std::string& cellStyle) const
{
    return impObj()->GetCellClass(utf8_to_wstr(cellStyle).c_str());
}

void PyAcadTableStyle::setCellClass(const std::string& cellStyle, int val) const
{
    impObj()->SetCellClass(utf8_to_wstr(cellStyle).c_str(), val);
}

double PyAcadTableStyle::rotation(const std::string& cellStyle) const
{
    return impObj()->GetRotation(utf8_to_wstr(cellStyle).c_str());
}

void PyAcadTableStyle::setRotation(const std::string& cellStyle, double val) const
{
    impObj()->SetRotation(utf8_to_wstr(cellStyle).c_str(), val);
}

bool PyAcadTableStyle::isMergeAllEnabled(const std::string& cellStyle) const
{
    return impObj()->GetIsMergeAllEnabled(utf8_to_wstr(cellStyle).c_str());
}

void PyAcadTableStyle::enableMergeAll(const std::string& cellStyle, bool val) const
{
    impObj()->EnableMergeAll(utf8_to_wstr(cellStyle).c_str(), val);
}

PyAcLineWeight PyAcadTableStyle::gridLineWeight(const std::string& cellStyle, PyAcGridLineType gridLineType) const
{
    return impObj()->GetGridLineWeight2(utf8_to_wstr(cellStyle).c_str(), gridLineType);
}

void PyAcadTableStyle::setGridLineWeight(const std::string& cellStyle, PyAcGridLineType gridLineType, PyAcLineWeight val) const
{
    impObj()->SetGridLineWeight2(utf8_to_wstr(cellStyle).c_str(), gridLineType, val);
}

PyAcadAcCmColor PyAcadTableStyle::gridColor(const std::string& cellStyle, PyAcGridLineType gridLineType) const
{
    return PyAcadAcCmColor{ impObj()->GetGridColor2(utf8_to_wstr(cellStyle).c_str(), gridLineType) };
}

void PyAcadTableStyle::setGridColor(const std::string& cellStyle, PyAcGridLineType gridLineType, const PyAcadAcCmColor& val) const
{
    impObj()->SetGridColor2(utf8_to_wstr(cellStyle).c_str(), gridLineType, *val.impObj());
}

bool PyAcadTableStyle::gridVisibility(const std::string& cellStyle, PyAcGridLineType gridLineType) const
{
    return impObj()->GetGridVisibility2(utf8_to_wstr(cellStyle).c_str(), gridLineType);
}

void PyAcadTableStyle::setGridVisibility(const std::string& cellStyle, PyAcGridLineType gridLineType, bool val) const
{
    impObj()->SetGridVisibility2(utf8_to_wstr(cellStyle).c_str(), gridLineType, val);
}

PyDbObjectId PyAcadTableStyle::templateId() const
{
    return PyDbObjectId{ impObj()->GetTemplateId() };
}

void PyAcadTableStyle::setTemplateId1(const PyDbObjectId& val) const
{
    impObj()->SetTemplateId(val.m_id);
}

void PyAcadTableStyle::setTemplateId2(const PyDbObjectId& val, PyAcMergeCellStyleOption option) const
{
    impObj()->SetTemplateId(val.m_id, option);
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
        .def("name", &PyAcadMLeaderStyle::name, DS.ARGS())
        .def("setName", &PyAcadMLeaderStyle::setName, DS.ARGS({ "style_name: str" }))
        .def("description", &PyAcadMLeaderStyle::description, DS.ARGS())
        .def("setDescription", &PyAcadMLeaderStyle::setDescription, DS.ARGS({ "description_text: str" }))
        .def("bitFlags", &PyAcadMLeaderStyle::bitFlags, DS.ARGS())
        .def("setBitFlags", &PyAcadMLeaderStyle::setBitFlags, DS.ARGS({ "flags: int" }))
        .def("contentType", &PyAcadMLeaderStyle::contentType, DS.ARGS())
        .def("setContentType", &PyAcadMLeaderStyle::setContentType, DS.ARGS({ "content_type: PyAx.AcMLeaderContentType" }))
        .def("drawMLeaderOrderType", &PyAcadMLeaderStyle::drawMLeaderOrderType, DS.ARGS())
        .def("setDrawMLeaderOrderType", &PyAcadMLeaderStyle::setDrawMLeaderOrderType, DS.ARGS({ "order_type: PyAx.AcMLeaderContentType" }))
        .def("drawLeaderOrderType", &PyAcadMLeaderStyle::drawLeaderOrderType, DS.ARGS())
        .def("setDrawLeaderOrderType", &PyAcadMLeaderStyle::setDrawLeaderOrderType, DS.ARGS({ "order_type: PyAx.AcDrawLeaderOrderType" }))
        .def("maxLeaderSegmentsPoints", &PyAcadMLeaderStyle::maxLeaderSegmentsPoints, DS.ARGS())
        .def("setMaxLeaderSegmentsPoints", &PyAcadMLeaderStyle::setMaxLeaderSegmentsPoints, DS.ARGS({ "point_count: int" }))
        .def("firstSegmentAngleConstraint", &PyAcadMLeaderStyle::firstSegmentAngleConstraint, DS.ARGS())
        .def("setFirstSegmentAngleConstraint", &PyAcadMLeaderStyle::setFirstSegmentAngleConstraint, DS.ARGS({ "angle_type: PyAx.AcSegmentAngleType" }))
        .def("secondSegmentAngleConstraint", &PyAcadMLeaderStyle::secondSegmentAngleConstraint, DS.ARGS())
        .def("setSecondSegmentAngleConstraint", &PyAcadMLeaderStyle::setSecondSegmentAngleConstraint, DS.ARGS({ "angle_type: PyAx.AcSegmentAngleType" }))
        .def("leaderLineType", &PyAcadMLeaderStyle::leaderLineType, DS.ARGS())
        .def("setLeaderLineType", &PyAcadMLeaderStyle::setLeaderLineType, DS.ARGS({ "line_type: PyAx.AcMLeaderType" }))
        .def("leaderLineColor", &PyAcadMLeaderStyle::leaderLineColor, DS.ARGS())
        .def("setLeaderLineColor", &PyAcadMLeaderStyle::setLeaderLineColor, DS.ARGS({ "color: PyAx.AcadAcCmColor" }))
        .def("leaderLineTypeId", &PyAcadMLeaderStyle::leaderLineTypeId, DS.ARGS())
        .def("setLeaderLineTypeId", &PyAcadMLeaderStyle::setLeaderLineTypeId, DS.ARGS({ "line_type_id:str" }))
        .def("leaderLineWeight", &PyAcadMLeaderStyle::leaderLineWeight, DS.ARGS())
        .def("setLeaderLineWeight", &PyAcadMLeaderStyle::setLeaderLineWeight, DS.ARGS({ "weight: AcLineWeight" }))
        .def("enableLanding", &PyAcadMLeaderStyle::enableLanding, DS.ARGS())
        .def("setEnableLanding", &PyAcadMLeaderStyle::setEnableLanding, DS.ARGS({ "enabled: bool" }))
        .def("landingGap", &PyAcadMLeaderStyle::landingGap, DS.ARGS())
        .def("setLandingGap", &PyAcadMLeaderStyle::setLandingGap, DS.ARGS({ "gap_distance: float" }))
        .def("enableDogleg", &PyAcadMLeaderStyle::enableDogleg, DS.ARGS())
        .def("setEnableDogleg", &PyAcadMLeaderStyle::setEnableDogleg, DS.ARGS({ "enabled: bool" }))
        .def("doglegLength", &PyAcadMLeaderStyle::doglegLength, DS.ARGS())
        .def("setDoglegLength", &PyAcadMLeaderStyle::setDoglegLength, DS.ARGS({ "length: float" }))
        .def("arrowSymbol", &PyAcadMLeaderStyle::arrowSymbol, DS.ARGS())
        .def("setArrowSymbol", &PyAcadMLeaderStyle::setArrowSymbol, DS.ARGS({ "symbol_name: str" }))
        .def("arrowSize", &PyAcadMLeaderStyle::arrowSize, DS.ARGS())
        .def("setArrowSize", &PyAcadMLeaderStyle::setArrowSize, DS.ARGS({ "size: float" }))
        .def("textStyle", &PyAcadMLeaderStyle::textStyle, DS.ARGS())
        .def("setTextStyle", &PyAcadMLeaderStyle::setTextStyle, DS.ARGS({ "style_name: str" }))
        .def("textAttachmentDirection", &PyAcadMLeaderStyle::textAttachmentDirection, DS.ARGS())
        .def("setTextAttachmentDirection", &PyAcadMLeaderStyle::setTextAttachmentDirection, DS.ARGS({ "direction: PyAx.AcTextAttachmentDirection" }))
        .def("textLeftAttachmentType", &PyAcadMLeaderStyle::textLeftAttachmentType, DS.ARGS())
        .def("setTextLeftAttachmentType", &PyAcadMLeaderStyle::setTextLeftAttachmentType, DS.ARGS({ "attachment_type: PyAx.AcTextAttachmentType" }))
        .def("textRightAttachmentType", &PyAcadMLeaderStyle::textRightAttachmentType, DS.ARGS())
        .def("setTextRightAttachmentType", &PyAcadMLeaderStyle::setTextRightAttachmentType, DS.ARGS({ "attachment_type: PyAx.AcTextAttachmentType" }))
        .def("textTopAttachmentType", &PyAcadMLeaderStyle::textTopAttachmentType, DS.ARGS())
        .def("setTextTopAttachmentType", &PyAcadMLeaderStyle::setTextTopAttachmentType, DS.ARGS({ "attachment_type: PyAx.AcVerticalTextAttachmentType" }))
        .def("textBottomAttachmentType", &PyAcadMLeaderStyle::textBottomAttachmentType, DS.ARGS())
        .def("setTextBottomAttachmentType", &PyAcadMLeaderStyle::setTextBottomAttachmentType, DS.ARGS({ "attachment_type: PyAx.AcVerticalTextAttachmentType" }))
        .def("textColor", &PyAcadMLeaderStyle::textColor, DS.ARGS())
        .def("setTextColor", &PyAcadMLeaderStyle::setTextColor, DS.ARGS({ "color: PyAx.AcadAcCmColor" }))
        .def("textHeight", &PyAcadMLeaderStyle::textHeight, DS.ARGS())
        .def("setTextHeight", &PyAcadMLeaderStyle::setTextHeight, DS.ARGS({ "height: float" }))
        .def("enableFrameText", &PyAcadMLeaderStyle::enableFrameText, DS.ARGS())
        .def("setEnableFrameText", &PyAcadMLeaderStyle::setEnableFrameText, DS.ARGS({ "enabled: bool" }))
        .def("alignSpace", &PyAcadMLeaderStyle::alignSpace, DS.ARGS())
        .def("setAlignSpace", &PyAcadMLeaderStyle::setAlignSpace, DS.ARGS({ "space: float" }))
        .def("block", &PyAcadMLeaderStyle::block, DS.ARGS())
        .def("setBlock", &PyAcadMLeaderStyle::setBlock, DS.ARGS({ "block_name: PyAx.AcadAcCmColor" }))
        .def("enableBlockScale", &PyAcadMLeaderStyle::enableBlockScale, DS.ARGS())
        .def("setEnableBlockScale", &PyAcadMLeaderStyle::setEnableBlockScale, DS.ARGS({ "enabled: bool" }))
        .def("blockScale", &PyAcadMLeaderStyle::blockScale, DS.ARGS())
        .def("setBlockScale", &PyAcadMLeaderStyle::setBlockScale, DS.ARGS({ "scale: float" }))
        .def("enableBlockRotation", &PyAcadMLeaderStyle::enableBlockRotation, DS.ARGS())
        .def("setEnableBlockRotation", &PyAcadMLeaderStyle::setEnableBlockRotation, DS.ARGS({ "enabled: bool" }))
        .def("BlockRotation", &PyAcadMLeaderStyle::BlockRotation, DS.ARGS())
        .def("setBlockRotation", &PyAcadMLeaderStyle::setBlockRotation, DS.ARGS({ "rotation: float" }))
        .def("blockConnectionType", &PyAcadMLeaderStyle::blockConnectionType, DS.ARGS())
        .def("setBlockConnectionType", &PyAcadMLeaderStyle::setBlockConnectionType, DS.ARGS({ "connection_type: PyAx.AcBlockConnectionType" }))
        .def("scaleFactor", &PyAcadMLeaderStyle::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyAcadMLeaderStyle::setScaleFactor, DS.ARGS({ "factor: float" }))
        .def("overwritePropChanged", &PyAcadMLeaderStyle::overwritePropChanged, DS.ARGS())
        .def("annotative", &PyAcadMLeaderStyle::annotative, DS.ARGS())
        .def("setAnnotative", &PyAcadMLeaderStyle::setAnnotative, DS.ARGS({ "enabled: bool" }))
        .def("breakSize", &PyAcadMLeaderStyle::breakSize, DS.ARGS())
        .def("setBreakSize", &PyAcadMLeaderStyle::setBreakSize, DS.ARGS({ "size: float" }))
        .def("textString", &PyAcadMLeaderStyle::textString, DS.ARGS())
        .def("setTextString", &PyAcadMLeaderStyle::setTextString, DS.ARGS({ "text: str" }))
        .def("textAngleType", &PyAcadMLeaderStyle::textAngleType, DS.ARGS())
        .def("setTextAngleType", &PyAcadMLeaderStyle::setTextAngleType, DS.ARGS({ "angle_type: PyAx.AcTextAngleType" }))
        .def("textAlignmentType", &PyAcadMLeaderStyle::textAlignmentType, DS.ARGS())
        .def("setTextAlignmentType", &PyAcadMLeaderStyle::setTextAlignmentType, DS.ARGS({ "alignment_type: PyAx.AcTextAlignmentType" }))
        .def("cast", &PyAcadMLeaderStyle::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadMLeaderStyle::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadMLeaderStyle::PyAcadMLeaderStyle(std::shared_ptr<PyIAcadMLeaderStyleImpl> ptr)
    : PyAcadObject(ptr)
{
}

std::string PyAcadMLeaderStyle::name() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PyAcadMLeaderStyle::setName(const std::string& val) const
{
    impObj()->SetName(utf8_to_wstr(val).c_str());
}

std::string PyAcadMLeaderStyle::description() const
{
    return wstr_to_utf8(impObj()->GetDescription());
}

void PyAcadMLeaderStyle::setDescription(const std::string& val) const
{
    impObj()->SetDescription(utf8_to_wstr(val).c_str());
}

long PyAcadMLeaderStyle::bitFlags() const
{
    return impObj()->GetBitFlags();
}

void PyAcadMLeaderStyle::setBitFlags(long val) const
{
    impObj()->SetBitFlags(val);
}

PyAcMLeaderContentType PyAcadMLeaderStyle::contentType() const
{
    return impObj()->GetContentType();
}

void PyAcadMLeaderStyle::setContentType(PyAcMLeaderContentType val) const
{
    impObj()->SetContentType(val);
}

PyAcDrawMLeaderOrderType PyAcadMLeaderStyle::drawMLeaderOrderType() const
{
    return impObj()->GetDrawMLeaderOrderType();
}

void PyAcadMLeaderStyle::setDrawMLeaderOrderType(PyAcMLeaderContentType val) const
{
    impObj()->SetDrawMLeaderOrderType(val);
}

PyAcDrawLeaderOrderType PyAcadMLeaderStyle::drawLeaderOrderType() const
{
    return impObj()->GetDrawLeaderOrderType();
}

void PyAcadMLeaderStyle::setDrawLeaderOrderType(PyAcDrawLeaderOrderType val) const
{
    impObj()->SetDrawLeaderOrderType(val);
}

int PyAcadMLeaderStyle::maxLeaderSegmentsPoints() const
{
    return impObj()->GetMaxLeaderSegmentsPoints();
}

void PyAcadMLeaderStyle::setMaxLeaderSegmentsPoints(int val) const
{
    impObj()->SetMaxLeaderSegmentsPoints(val);
}

PyAcSegmentAngleType PyAcadMLeaderStyle::firstSegmentAngleConstraint() const
{
    return impObj()->GetFirstSegmentAngleConstraint();
}

void PyAcadMLeaderStyle::setFirstSegmentAngleConstraint(PyAcSegmentAngleType val) const
{
    impObj()->SetFirstSegmentAngleConstraint(val);
}

PyAcSegmentAngleType PyAcadMLeaderStyle::secondSegmentAngleConstraint() const
{
    return impObj()->GetSecondSegmentAngleConstraint();
}

void PyAcadMLeaderStyle::setSecondSegmentAngleConstraint(PyAcSegmentAngleType val) const
{
    impObj()->SetSecondSegmentAngleConstraint(val);
}

PyAcMLeaderType PyAcadMLeaderStyle::leaderLineType() const
{
    return impObj()->GetLeaderLineType();
}

void PyAcadMLeaderStyle::setLeaderLineType(PyAcMLeaderType val) const
{
    impObj()->SetLeaderLineType(val);
}

PyAcadAcCmColor PyAcadMLeaderStyle::leaderLineColor() const
{
    return PyAcadAcCmColor{ impObj()->GetLeaderLineColor() };
}

void PyAcadMLeaderStyle::setLeaderLineColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetLeaderLineColor(*val.impObj());
}

std::string PyAcadMLeaderStyle::leaderLineTypeId() const
{
    return wstr_to_utf8(impObj()->GetLeaderLineTypeId());
}

void PyAcadMLeaderStyle::setLeaderLineTypeId(const std::string& val) const
{
    impObj()->SetLeaderLineTypeId(utf8_to_wstr(val).c_str());
}

PyAcLineWeight PyAcadMLeaderStyle::leaderLineWeight() const
{
    return impObj()->GetLeaderLineWeight();
}

void PyAcadMLeaderStyle::setLeaderLineWeight(PyAcLineWeight val) const
{
    impObj()->SetLeaderLineWeight(val);
}

bool PyAcadMLeaderStyle::enableLanding() const
{
    return impObj()->GetEnableLanding();
}

void PyAcadMLeaderStyle::setEnableLanding(bool val) const
{
    impObj()->SetEnableLanding(val);
}

double PyAcadMLeaderStyle::landingGap() const
{
    return impObj()->GetLandingGap();
}

void PyAcadMLeaderStyle::setLandingGap(double val) const
{
    impObj()->SetLandingGap(val);
}

bool PyAcadMLeaderStyle::enableDogleg() const
{
    return impObj()->GetEnableDogleg();
}

void PyAcadMLeaderStyle::setEnableDogleg(bool val) const
{
    impObj()->SetEnableDogleg(val);
}

double PyAcadMLeaderStyle::doglegLength() const
{
    return impObj()->GetDoglegLength();
}

void PyAcadMLeaderStyle::setDoglegLength(double val) const
{
    impObj()->SetDoglegLength(val);
}

std::string PyAcadMLeaderStyle::arrowSymbol() const
{
    return wstr_to_utf8(impObj()->GetArrowSymbol());
}

void PyAcadMLeaderStyle::setArrowSymbol(const std::string& val) const
{
    impObj()->SetArrowSymbol(utf8_to_wstr(val).c_str());
}

double PyAcadMLeaderStyle::arrowSize() const
{
    return impObj()->GetArrowSize();
}

void PyAcadMLeaderStyle::setArrowSize(double val) const
{
    impObj()->SetArrowSize(val);
}

std::string PyAcadMLeaderStyle::textStyle() const
{
    return wstr_to_utf8(impObj()->GetTextStyle());
}

void PyAcadMLeaderStyle::setTextStyle(const std::string& val) const
{
    impObj()->SetTextStyle(utf8_to_wstr(val).c_str());
}

PyAcTextAttachmentDirection PyAcadMLeaderStyle::textAttachmentDirection() const
{
    return impObj()->GetTextAttachmentDirection();
}

void PyAcadMLeaderStyle::setTextAttachmentDirection(PyAcTextAttachmentDirection val) const
{
    impObj()->SetTextAttachmentDirection(val);
}

PyAcTextAttachmentType PyAcadMLeaderStyle::textLeftAttachmentType() const
{
    return impObj()->GetTextLeftAttachmentType();
}

void PyAcadMLeaderStyle::setTextLeftAttachmentType(PyAcTextAttachmentType val) const
{
    impObj()->SetTextLeftAttachmentType(val);
}

PyAcTextAttachmentType PyAcadMLeaderStyle::textRightAttachmentType() const
{
    return impObj()->GetTextRightAttachmentType();
}

void PyAcadMLeaderStyle::setTextRightAttachmentType(PyAcTextAttachmentType val) const
{
    impObj()->SetTextRightAttachmentType(val);
}

PyAcVerticalTextAttachmentType PyAcadMLeaderStyle::textTopAttachmentType() const
{
    return impObj()->GetTextTopAttachmentType();
}

void PyAcadMLeaderStyle::setTextTopAttachmentType(PyAcVerticalTextAttachmentType val) const
{
    impObj()->SetTextTopAttachmentType(val);
}

PyAcVerticalTextAttachmentType PyAcadMLeaderStyle::textBottomAttachmentType() const
{
    return impObj()->GetTextBottomAttachmentType();
}

void PyAcadMLeaderStyle::setTextBottomAttachmentType(PyAcVerticalTextAttachmentType val) const
{
    impObj()->SetTextBottomAttachmentType(val);
}

PyAcadAcCmColor PyAcadMLeaderStyle::textColor() const
{
    return PyAcadAcCmColor{ impObj()->GetTextColor() };
}

void PyAcadMLeaderStyle::setTextColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetTextColor(*val.impObj());
}

double PyAcadMLeaderStyle::textHeight() const
{
    return impObj()->GetTextHeight();
}

void PyAcadMLeaderStyle::setTextHeight(double val) const
{
    impObj()->SetTextHeight(val);
}

bool PyAcadMLeaderStyle::enableFrameText() const
{
    return impObj()->GetEnableFrameText();
}

void PyAcadMLeaderStyle::setEnableFrameText(bool val) const
{
    impObj()->SetEnableFrameText(val);
}

double PyAcadMLeaderStyle::alignSpace() const
{
    return impObj()->GetAlignSpace();
}

void PyAcadMLeaderStyle::setAlignSpace(double val) const
{
    impObj()->SetAlignSpace(val);
}

std::string PyAcadMLeaderStyle::block() const
{
    return wstr_to_utf8(impObj()->GetBlock());
}

void PyAcadMLeaderStyle::setBlock(const std::string& val) const
{
    impObj()->SetBlock(utf8_to_wstr(val).c_str());
}

PyAcadAcCmColor PyAcadMLeaderStyle::blockColor() const
{
    return PyAcadAcCmColor{ impObj()->GetBlockColor() };
}

void PyAcadMLeaderStyle::setBlockColor(const PyAcadAcCmColor& val) const
{
    impObj()->SetBlockColor(*val.impObj());
}

bool PyAcadMLeaderStyle::enableBlockScale() const
{
    return impObj()->GetEnableBlockScale();
}

void PyAcadMLeaderStyle::setEnableBlockScale(bool val) const
{
    impObj()->SetEnableBlockScale(val);
}

double PyAcadMLeaderStyle::blockScale() const
{
    return impObj()->GetBlockScale();
}

void PyAcadMLeaderStyle::setBlockScale(double val) const
{
    impObj()->SetBlockScale(val);
}

bool PyAcadMLeaderStyle::enableBlockRotation() const
{
    return impObj()->GetEnableBlockRotation();
}

void PyAcadMLeaderStyle::setEnableBlockRotation(bool val) const
{
    impObj()->SetEnableBlockRotation(val);
}

double PyAcadMLeaderStyle::BlockRotation() const
{
    return impObj()->GetBlockRotation();
}

void PyAcadMLeaderStyle::setBlockRotation(double val) const
{
    impObj()->SetBlockRotation(val);
}

PyAcBlockConnectionType PyAcadMLeaderStyle::blockConnectionType() const
{
    return impObj()->GetBlockConnectionType();
}

void PyAcadMLeaderStyle::setBlockConnectionType(PyAcBlockConnectionType val) const
{
    impObj()->SetBlockConnectionType(val);
}

double PyAcadMLeaderStyle::scaleFactor() const
{
    return impObj()->GetScaleFactor();
}

void PyAcadMLeaderStyle::setScaleFactor(double val) const
{
    impObj()->SetScaleFactor(val);
}

bool PyAcadMLeaderStyle::overwritePropChanged() const
{
    return impObj()->GetOverwritePropChanged();
}

bool PyAcadMLeaderStyle::annotative() const
{
    return impObj()->GetAnnotative();
}

void PyAcadMLeaderStyle::setAnnotative(bool val) const
{
    impObj()->SetAnnotative(val);
}

double PyAcadMLeaderStyle::breakSize() const
{
    return impObj()->GetBreakSize();
}

void PyAcadMLeaderStyle::setBreakSize(double val) const
{
    impObj()->SetBreakSize(val);
}

std::string PyAcadMLeaderStyle::textString() const
{
    return wstr_to_utf8(impObj()->GetTextString());
}

void PyAcadMLeaderStyle::setTextString(const std::string& val) const
{
    impObj()->SetTextString(utf8_to_wstr(val).c_str());
}

PyAcTextAngleType PyAcadMLeaderStyle::textAngleType() const
{
    return impObj()->GetTextAngleType();
}

void PyAcadMLeaderStyle::setTextAngleType(PyAcTextAngleType val) const
{
    impObj()->SetTextAngleType(val);
}

PyAcTextAlignmentType PyAcadMLeaderStyle::textAlignmentType() const
{
    return impObj()->GetTextAlignmentType();
}

void PyAcadMLeaderStyle::setTextAlignmentType(PyAcTextAlignmentType val) const
{
    impObj()->SetTextAlignmentType(val);
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
        .def("moveToBottom", &PyAcadSortentsTable::moveToBottom, DS.ARGS({ "pyents: Collection[PyAx.AcadEntity]" }))
        .def("moveToTop", &PyAcadSortentsTable::moveToTop, DS.ARGS({ "pyents: Collection[PyAx.AcadEntity]" }))
        .def("moveBelow", &PyAcadSortentsTable::moveBelow, DS.ARGS({ "pyents: Collection[PyAx.AcadEntity]","target:PyAx.AcadEntity" }))
        .def("moveAbove", &PyAcadSortentsTable::moveAbove, DS.ARGS({ "pyents: Collection[PyAx.AcadEntity]","target:PyAx.AcadEntity" }))
        .def("swapOrder", &PyAcadSortentsTable::swapOrder, DS.ARGS({ "left:PyAx.AcadEntity","right:PyAx.AcadEntity" }))
        .def("block", &PyAcadSortentsTable::block, DS.ARGS())
        .def("fullDrawOrder", &PyAcadSortentsTable::fullDrawOrder, DS.ARGS({ "honorSortentsSysvar:bool" }))
        .def("relativeDrawOrder", &PyAcadSortentsTable::relativeDrawOrder, DS.ARGS({ "honorSortentsSysvar:bool" }))
        .def("setRelativeDrawOrder", &PyAcadSortentsTable::setRelativeDrawOrder, DS.ARGS({ "pyents: Collection[PyAx.AcadEntity]" }))
        .def("cast", &PyAcadSortentsTable::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadSortentsTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadSortentsTable::PyAcadSortentsTable(std::shared_ptr<PyIAcadSortentsTableImpl> ptr)
    : PyAcadObject(ptr)
{
}

void PyAcadSortentsTable::moveToBottom(const boost::python::object& pyents) const
{
    PyAutoLockGIL lock;
    std::vector<PyIAcadEntityImpl> ents;
    for (const auto& item : py_list_to_std_vector<PyAcadEntity>(pyents))
        ents.push_back(*item.impObj());
    impObj()->MoveToBottom(ents);
}

void PyAcadSortentsTable::moveToTop(const boost::python::object& pyents) const
{
    PyAutoLockGIL lock;
    std::vector<PyIAcadEntityImpl> ents;
    for (const auto& item : py_list_to_std_vector<PyAcadEntity>(pyents))
        ents.push_back(*item.impObj());
    impObj()->MoveToTop(ents);
}

void PyAcadSortentsTable::moveBelow(const boost::python::object& pyents, const PyAcadEntity& target) const
{
    PyAutoLockGIL lock;
    std::vector<PyIAcadEntityImpl> ents;
    for (const auto& item : py_list_to_std_vector<PyAcadEntity>(pyents))
        ents.push_back(*item.impObj());
    impObj()->MoveBelow(ents, *target.impObj());
}

void PyAcadSortentsTable::moveAbove(const boost::python::object& pyents, const PyAcadEntity& target) const
{
    PyAutoLockGIL lock;
    std::vector<PyIAcadEntityImpl> ents;
    for (const auto& item : py_list_to_std_vector<PyAcadEntity>(pyents))
        ents.push_back(*item.impObj());
    impObj()->MoveAbove(ents, *target.impObj());
}

void PyAcadSortentsTable::swapOrder(const PyAcadEntity& left, const PyAcadEntity& right) const
{
    impObj()->SwapOrder(*left.impObj(), *right.impObj());
}

PyAcadBlock PyAcadSortentsTable::block() const
{
    return PyAcadBlock{ impObj()->Block() };
}

boost::python::list PyAcadSortentsTable::fullDrawOrder(bool honorSortentsSysvar) const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetFullDrawOrder(honorSortentsSysvar))
        _pylist.append(PyAcadEntity{ item });
    return _pylist;
}

boost::python::list PyAcadSortentsTable::relativeDrawOrder(bool honorSortentsSysvar) const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (const auto& item : impObj()->GetRelativeDrawOrder(honorSortentsSysvar))
        _pylist.append(PyAcadEntity{ item });
    return _pylist;
}

void PyAcadSortentsTable::setRelativeDrawOrder(const boost::python::object& pyents) const
{
    PyAutoLockGIL lock;
    std::vector<PyIAcadEntityImpl> ents;
    for (const auto& item : py_list_to_std_vector<PyAcadEntity>(pyents))
        ents.push_back(*item.impObj());
    impObj()->SetRelativeDrawOrder(ents);
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