#include "stdafx.h"
#include "PyDbLayout.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbPlotSettingsWrapper()
{
    class_<PyDbPlotSettings, bases<PyDbObject>>("PlotSettings")
        .def(init<>())
        .def(init<bool>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbPlotSettings::className).staticmethod("className")
        .def("desc", &PyDbPlotSettings::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbPlotSettings::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbPlotSettings::cast).staticmethod("cast")
        ;
}

PyDbPlotSettings::PyDbPlotSettings()
    : PyDbObject(new AcDbPlotSettings(), true)
{
}

PyDbPlotSettings::PyDbPlotSettings(bool ModelType)
    : PyDbObject(new AcDbPlotSettings(ModelType), true)
{
}

PyDbPlotSettings::PyDbPlotSettings(AcDbPlotSettings* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbPlotSettings::PyDbPlotSettings(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbPlotSettings* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPlotSettings>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbPlotSettings::className()
{
    return "AcDbPlotSettings";
}

PyRxClass PyDbPlotSettings::desc()
{
    return PyRxClass(AcDbPlotSettings::desc(), false);
}

PyDbPlotSettings PyDbPlotSettings::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPlotSettings::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPlotSettings(static_cast<AcDbPlotSettings*>(src.impObj()->clone()), true);
}

PyDbPlotSettings PyDbPlotSettings::cast(const PyRxObject& src)
{
    PyDbPlotSettings dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPlotSettings* PyDbPlotSettings::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbPlotSettings*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbLayout
void makePyDbLayoutWrapper()
{
    class_<PyDbLayout, bases<PyDbPlotSettings>>("Layout")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbLayout::className).staticmethod("className")
        .def("desc", &PyDbLayout::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbLayout::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbLayout::cast).staticmethod("cast")
        ;
}

PyDbLayout::PyDbLayout()
    :PyDbPlotSettings(new AcDbLayout(), true)
{
}

PyDbLayout::PyDbLayout(AcDbLayout* ptr, bool autoDelete)
    : PyDbPlotSettings(ptr, autoDelete)
{
}

PyDbLayout::PyDbLayout(const PyDbObjectId& id, AcDb::OpenMode mode)
{
    AcDbLayout* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbLayout>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbLayout::className()
{
    return "AcDbLayout";
}

PyRxClass PyDbLayout::desc()
{
    return PyRxClass(AcDbLayout::desc(), false);
}

PyDbLayout PyDbLayout::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbLayout::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbLayout(static_cast<AcDbLayout*>(src.impObj()->clone()), true);
}

PyDbLayout PyDbLayout::cast(const PyRxObject& src)
{
    PyDbLayout dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbLayout* PyDbLayout::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbLayout*>(m_pyImp.get());
}
