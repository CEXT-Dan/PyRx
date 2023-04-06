#include "stdafx.h"
#include "PyAcEditor.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------------
// PyAcEditor wrapper
void makeAcEditorWrapper()
{
    static auto wrapper = class_<PyAcEditor>("AcEditor")
        .def("className", &PyAcEditor::className).staticmethod("className")
        .def("getInteger", &PyAcEditor::getInteger)
        .def("getDouble", &PyAcEditor::getDouble)
        .def("getString", &PyAcEditor::getString)
        .def("getPoint", &PyAcEditor::getPoint)
        .def("entsel", &PyAcEditor::entsel)
        .def<boost::python::tuple(PyAcEditor::*)(void)>("selectAll", &PyAcEditor::selectAll)
        .def<boost::python::tuple(PyAcEditor::*)(const boost::python::list&)>("selectAll", &PyAcEditor::selectAll)
        ;
}

//-----------------------------------------------------------------------------------------
// PyAcEditor
boost::python::tuple PyAcEditor::getInteger(const std::string& prompt)
{
    std::pair<int, Acad::PromptStatus> res;
    res.second = static_cast<Acad::PromptStatus>(acedGetInt(utf8_to_wstr(prompt).c_str(), &res.first));
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getDouble(const std::string& prompt)
{
    std::pair<double, Acad::PromptStatus> res;
    res.second = static_cast<Acad::PromptStatus>(acedGetReal(utf8_to_wstr(prompt).c_str(), &res.first));
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getPoint(const std::string& prompt)
{
    ads_point pnt;
    std::pair<AcGePoint3d, Acad::PromptStatus> res;
    res.second = static_cast<Acad::PromptStatus>(acedGetPoint(nullptr, utf8_to_wstr(prompt).c_str(), pnt));
    res.first = asPnt3d(pnt);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getString(int cronly, const std::string& prompt)
{
    AcString str;
    std::pair<std::string, Acad::PromptStatus> res;
    res.second = static_cast<Acad::PromptStatus>(acedGetString(cronly, utf8_to_wstr(prompt).c_str(), str));
    res.first = wstr_to_utf8(str);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::entsel(const std::string& prompt)
{
    ads_point pnt;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedEntSel(utf8_to_wstr(prompt).c_str(), name, pnt));
    PyDbObjectId id;
    acdbGetObjectId(id.m_id, name);
    return boost::python::make_tuple<PyDbObjectId, AcGePoint3d, Acad::PromptStatus>(id, asPnt3d(pnt), stat);
}

boost::python::tuple PyAcEditor::selectAll()
{
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("A"), nullptr, nullptr, nullptr, name));
    AcDbObjectIdArray ids;
    boost::python::list pyList;
    if (acedGetCurrentSelectionSet(ids) == eOk)
    {
        for (const auto& id : ids)
            pyList.append(PyDbObjectId{ id });
    }
    acedSSFree(name);
    return boost::python::make_tuple<boost::python::list, Acad::PromptStatus>(pyList, stat);
}

boost::python::tuple PyAcEditor::selectAll(const boost::python::list& filter)
{
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("A"), nullptr, nullptr, pFilter.get(), name));
    AcDbObjectIdArray ids;
    boost::python::list pyList;
    if (acedGetCurrentSelectionSet(ids) == eOk)
    {
        for (const auto& id : ids)
            pyList.append(PyDbObjectId{ id });
    }
    acedSSFree(name);
    return boost::python::make_tuple<boost::python::list, Acad::PromptStatus>(pyList, stat);
}

std::string PyAcEditor::className()
{
    return std::string{ "AcEditor" };
}
