#include "stdafx.h"
#include "PyAcEditor.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
#include "acedCmdNF.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
// PyAcEditor wrapper

void makeAcEditorWrapper()
{
    static auto wrapper = class_<PyAcEditor>("AcEditor")
        .def("className", &PyAcEditor::className).staticmethod("className")

        .def("alert", &PyAcEditor::alert)
        .def("arxLoad", &PyAcEditor::arxLoad)
        .def("arxUnload", &PyAcEditor::arxUnload)
        .def("arxLoaded", &PyAcEditor::arxLoaded)
        .def("audit", &PyAcEditor::audit)
        .def("cmdS", &PyAcEditor::cmdS)
        .def("findFile", &PyAcEditor::findFile)
        .def("findTrustedFile", &PyAcEditor::findTrustedFile)

        .def("getInt", &PyAcEditor::getInteger)
        .def("getDouble", &PyAcEditor::getDouble)
        .def("getReal", &PyAcEditor::getDouble)
        .def("getAngle", &PyAcEditor::getAngle)
        .def("getString", &PyAcEditor::getString)

        .def<boost::python::tuple(PyAcEditor::*)(const std::string&)>("getPoint", &PyAcEditor::getPoint)
        .def<boost::python::tuple(PyAcEditor::*)(const AcGePoint3d& ,const std::string&)>("getPoint", &PyAcEditor::getPoint)

        .def<boost::python::tuple(PyAcEditor::*)(const std::string&)>("getDist", &PyAcEditor::getDist)
        .def<boost::python::tuple(PyAcEditor::*)(const AcGePoint3d&, const std::string&)>("getDist", &PyAcEditor::getDist)

        .def("entsel", &PyAcEditor::entsel)
        .def("getCurrentUCS", &PyAcEditor::curUCS)
        .def("setCurrentUCS", &PyAcEditor::setCurUCS)

        .def("activeViewportId", &PyAcEditor::activeViewportId)


        .def<boost::python::tuple(PyAcEditor::*)(void)>("selectAll", &PyAcEditor::selectAll)
        .def<boost::python::tuple(PyAcEditor::*)(const boost::python::list&)>("selectAll", &PyAcEditor::selectAll)
        ;
}

//-----------------------------------------------------------------------------------------
// PyAcEditor
void PyAcEditor::alert(const std::string& prompt)
{
    acedAlert(utf8_to_wstr(prompt).c_str());
}

bool PyAcEditor::arxLoad(const std::string& path)
{
    return acedArxLoad(utf8_to_wstr(path).c_str()) == RTNORM;
}

bool PyAcEditor::arxUnload(const std::string& app)
{
    return acedArxUnload(utf8_to_wstr(app).c_str()) == RTNORM;
}

Acad::ErrorStatus PyAcEditor::audit(const PyDbDatabase& db, bool bFixErrors, bool bCmdLnEcho)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return acedAudit(db.impObj(), bFixErrors, bCmdLnEcho);
#endif
}

bool PyAcEditor::cmdS(const boost::python::list& lst)
{
    AcResBufPtr pcmd(listToResbuf(lst));
    return acedCmdS(pcmd.get()) == RTNORM;
}

std::string PyAcEditor::findFile(const std::string& file)
{
    std::array<wchar_t, MAX_PATH> data;
    acedFindFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.data());
}

std::string PyAcEditor::findTrustedFile(const std::string& file)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    std::array<wchar_t, MAX_PATH> data;
    acedFindTrustedFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.data());
#endif
}

boost::python::list PyAcEditor::arxLoaded()
{
    AcResBufPtr pLoaded(acedArxLoaded());
    return resbufToList(pLoaded.get());
}

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

boost::python::tuple PyAcEditor::getAngle(const AcGePoint3d& basePt,const std::string& prompt)
{
    std::pair<double, Acad::PromptStatus> res;
    res.second = static_cast<Acad::PromptStatus>(acedGetAngle(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), &res.first));
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

boost::python::tuple PyAcEditor::getPoint(const AcGePoint3d& basePt, const std::string& prompt)
{
    ads_point pnt;
    std::pair<AcGePoint3d, Acad::PromptStatus> res;
    res.second = static_cast<Acad::PromptStatus>(acedGetPoint(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), pnt));
    res.first = asPnt3d(pnt);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getDist(const std::string& prompt)
{
    ads_point pnt;
    std::pair<AcGePoint3d, Acad::PromptStatus> res;
    res.second = static_cast<Acad::PromptStatus>(acedGetDist(nullptr, utf8_to_wstr(prompt).c_str(), pnt));
    res.first = asPnt3d(pnt);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getDist(const AcGePoint3d& basePt, const std::string& prompt)
{
    ads_point pnt;
    std::pair<AcGePoint3d, Acad::PromptStatus> res;
    res.second = static_cast<Acad::PromptStatus>(acedGetDist(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), pnt));
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

AcGeMatrix3d PyAcEditor::curUCS()
{
    AcGeMatrix3d mat;
    if (auto es = acedGetCurrentUCS(mat); es != eOk)
        throw PyAcadErrorStatus(es);
    return mat;
}

Acad::ErrorStatus PyAcEditor::setCurUCS(const AcGeMatrix3d& mat)
{
    return acedSetCurrentUCS(mat);
}

PyDbObjectId PyAcEditor::activeViewportId()
{
    return PyDbObjectId(acedActiveViewportId());
}

std::string PyAcEditor::className()
{
    return std::string{ "AcEditor" };
}
