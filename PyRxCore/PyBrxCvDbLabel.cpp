#include "stdafx.h"


#ifdef BRXAPP
#if !defined(_BRXTARGET240)

#include "PyBrxCvDbLabel.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyBrxCvDbStylePartDisplaySettings
void makeBrxCvDbStylePartDisplaySettingsWrapper()
{
    PyDocString DS("CvDbStylePartDisplaySettings");
    class_<PyBrxCvDbStylePartDisplaySettings, bases<PyBrxCvDbSubObject>>("CvDbStylePartDisplaySettings", boost::python::no_init)
        .def("displaySetting", &PyBrxCvDbStylePartDisplaySettings::isVisible, DS.ARGS())
        .def("setVisible", &PyBrxCvDbStylePartDisplaySettings::setVisible, DS.ARGS({ "val: bool" }))
        .def("color", &PyBrxCvDbStylePartDisplaySettings::color, DS.ARGS())
        .def("setColor", &PyBrxCvDbStylePartDisplaySettings::setColor, DS.ARGS({ "clr: PyDb.Color" }))
        .def("layer", &PyBrxCvDbStylePartDisplaySettings::layer, DS.ARGS())
        .def("setLayer", &PyBrxCvDbStylePartDisplaySettings::setLayer, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("lineType", &PyBrxCvDbStylePartDisplaySettings::lineType, DS.ARGS())
        .def("setLineType", &PyBrxCvDbStylePartDisplaySettings::setLineType, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("lineTypeScale", &PyBrxCvDbStylePartDisplaySettings::lineTypeScale, DS.ARGS())
        .def("setLineTypeScale", &PyBrxCvDbStylePartDisplaySettings::setLineTypeScale, DS.ARGS({ "val: float" }))
        .def("lineWeight", &PyBrxCvDbStylePartDisplaySettings::lineWeight, DS.ARGS())
        .def("setLineWeight", &PyBrxCvDbStylePartDisplaySettings::setLineWeight, DS.ARGS({ "val: PyDb.LineWeight" }))
        .def("plotStyleNameType", &PyBrxCvDbStylePartDisplaySettings::plotStyleNameType, DS.ARGS())
        .def("setPlotStyleNameType", &PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameType, DS.ARGS({ "val: PyDb.PlotStyleNameType" }))
        .def("plotStyleNameId", &PyBrxCvDbStylePartDisplaySettings::plotStyleNameId, DS.ARGS())
        .def("setPlotStyleNameId", &PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameId, DS.ARGS({ "id: PyDb.ObjectId" }))
        ;
}

PyBrxCvDbStylePartDisplaySettings::PyBrxCvDbStylePartDisplaySettings(BrxCvDbStylePartDisplaySettings* ptr, bool autoDelete)
    : PyBrxCvDbSubObject(ptr, autoDelete)
{
}

bool PyBrxCvDbStylePartDisplaySettings::isVisible() const
{
    return impObj()->isVisible();
}

void PyBrxCvDbStylePartDisplaySettings::setVisible(bool value)
{
    PyThrowBadEs(impObj()->setVisible(value));
}

AcCmColor PyBrxCvDbStylePartDisplaySettings::color() const
{
    return impObj()->color();
}

void PyBrxCvDbStylePartDisplaySettings::setColor(const AcCmColor& value)
{
    PyThrowBadEs(impObj()->setColor(value));
}

PyDbObjectId PyBrxCvDbStylePartDisplaySettings::layer() const
{
    return PyDbObjectId{ impObj()->layer() };
}

void PyBrxCvDbStylePartDisplaySettings::setLayer(const PyDbObjectId& value)
{
    PyThrowBadEs(impObj()->setLayer(value.m_id));
}

PyDbObjectId PyBrxCvDbStylePartDisplaySettings::lineType() const
{
    return PyDbObjectId{ impObj()->lineType() };
}

void PyBrxCvDbStylePartDisplaySettings::setLineType(const PyDbObjectId& value)
{
    PyThrowBadEs(impObj()->setLineType(value.m_id));
}

double PyBrxCvDbStylePartDisplaySettings::lineTypeScale() const
{
    return impObj()->lineTypeScale();
}

void PyBrxCvDbStylePartDisplaySettings::setLineTypeScale(double value)
{
    PyThrowBadEs(impObj()->setLineTypeScale(value));
}

AcDb::LineWeight PyBrxCvDbStylePartDisplaySettings::lineWeight() const
{
    return impObj()->lineWeight();
}

void PyBrxCvDbStylePartDisplaySettings::setLineWeight(AcDb::LineWeight value)
{
    PyThrowBadEs(impObj()->setLineWeight(value));
}

AcDb::PlotStyleNameType PyBrxCvDbStylePartDisplaySettings::plotStyleNameType() const
{
    return impObj()->plotStyleNameType();
}

void PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameType(AcDb::PlotStyleNameType value)
{
    PyThrowBadEs(impObj()->setPlotStyleNameType(value));
}

PyDbObjectId PyBrxCvDbStylePartDisplaySettings::plotStyleNameId() const
{
    return PyDbObjectId{ impObj()->plotStyleNameId() };
}

void PyBrxCvDbStylePartDisplaySettings::setPlotStyleNameId(const PyDbObjectId& value)
{
    PyThrowBadEs(impObj()->setPlotStyleNameId(value.m_id));
}

BrxCvDbStylePartDisplaySettings* PyBrxCvDbStylePartDisplaySettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbStylePartDisplaySettings*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyBrxCvDbStyle
void makePyBrxCvDbStyleWrapper()
{

    PyDocString DS("CvDbStyle");
    class_<PyBrxCvDbStyle, bases<PyBrxCvDbObject>>("CvDbStyle", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("displaySetting", &PyBrxCvDbStyle::displaySetting, DS.ARGS())
        .def("displaySettings", &PyBrxCvDbStyle::displaySettings, DS.ARGS())
        .def("createdDate", &PyBrxCvDbStyle::createdDate, DS.ARGS())
        .def("createdBy", &PyBrxCvDbStyle::createdBy, DS.ARGS())
        .def("lastEditedDate", &PyBrxCvDbStyle::lastEditedDate, DS.ARGS())
        .def("lastEditedBy", &PyBrxCvDbStyle::lastEditedBy, DS.ARGS())
        .def("setCreatedBy", &PyBrxCvDbStyle::setCreatedBy, DS.ARGS({ "filter : str" }))

        .def("className", &PyBrxCvDbStyle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrxCvDbStyle::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyBrxCvDbStyle::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyBrxCvDbStyle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id, mode), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id, mode, erased), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(BrxCvDbStyle* ptr, bool autoDelete)
    : PyBrxCvDbObject(ptr, autoDelete)
{
}

PyBrxCvDbStylePartDisplaySettings PyBrxCvDbStyle::displaySetting(DisplayOrientation orientation, const std::string& partName) const
{
    auto ptr = impObj()->displaySetting(orientation, utf8_to_wstr(partName).c_str());
    if (ptr.refCount() == 1)
        return PyBrxCvDbStylePartDisplaySettings(ptr.detach(), true);
    throw PyErrorStatusException(Acad::eInvalidOpenState);
}

boost::python::list PyBrxCvDbStyle::displaySettings(BrxCvDbLabelStyle::DisplayOrientation orientation) const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto item : impObj()->displaySettings(orientation))
    {
        if (item.refCount() == 1)
            _pylist.append(PyBrxCvDbStylePartDisplaySettings(item.detach(), true));
        else
            throw PyErrorStatusException(Acad::eInvalidOpenState);
    }
    return _pylist;
}

PyDbDate PyBrxCvDbStyle::createdDate() const
{
    return PyDbDate(impObj()->createdDate());
}

const std::string PyBrxCvDbStyle::createdBy() const
{
    return wstr_to_utf8(impObj()->createdBy());
}

PyDbDate PyBrxCvDbStyle::lastEditedDate() const
{
    return PyDbDate();
}

const std::string PyBrxCvDbStyle::lastEditedBy() const
{
    return wstr_to_utf8(impObj()->lastEditedBy());
}

void PyBrxCvDbStyle::setCreatedBy(const std::string& value)
{
    PyThrowBadEs(impObj()->setCreatedBy(utf8_to_wstr(value).c_str()));
}

BrxCvDbStyle* PyBrxCvDbStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbStyle*>(m_pyImp.get());
}

#endif

#endif//BRXAPP