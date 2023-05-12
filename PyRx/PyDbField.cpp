#include "stdafx.h"
#include "PyDbField.h"
#include "PyDbObjectId.h"
using namespace boost::python;
void makeAcDbFieldtWrapper()
{
    boost::python::scope scope = class_<PyDbField, bases<PyDbObject>>("Field")
        .def(init<>())
        .def(init<std::string&, bool>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("setInObject", &PyDbField::setInObject)
        .def("postInDatabase", &PyDbField::postInDatabase)
        .def("state", &PyDbField::state)
        .def("evaluationStatus", &PyDbField::evaluationStatus)
        .def("evaluationOption", &PyDbField::evaluationOption)
        .def("setEvaluationOption", &PyDbField::setEvaluationOption)
        .def("evaluatorId", &PyDbField::evaluatorId)
        .def("setEvaluatorId", &PyDbField::setEvaluatorId)
        .def("isTextField", &PyDbField::isTextField)
        .def("convertToTextField", &PyDbField::convertToTextField)
        .def("childCount", &PyDbField::childCount)
        .def("getFormat", &PyDbField::getFormat)
        .def("setFormat", &PyDbField::setFormat)
        .def("getValue", &PyDbField::getValue)
        .def("className", &PyDbField::className).staticmethod("className")
        .def("desc", &PyDbField::desc).staticmethod("desc")
        ;
    enum_<PyDbField::State>("State")
        .value("kInitialized", PyDbField::State::kInitialized)
        .value("kCompiled", PyDbField::State::kCompiled)
        .value("kModified", PyDbField::State::kModified)
        .value("kEvaluated", PyDbField::State::kEvaluated)
        .value("kHasCache", PyDbField::State::kHasCache)
#ifndef BRXAPP
        .value("kHasFormattedString", PyDbField::State::kHasFormattedString)
#endif // BRXAPP
        ;
    enum_<PyDbField::EvalOption>("EvalOption")
        .value("kDisable", PyDbField::EvalOption::kDisable)
        .value("kOnOpen", PyDbField::EvalOption::kOnOpen)
        .value("kOnSave", PyDbField::EvalOption::kOnSave)
        .value("kOnPlot", PyDbField::EvalOption::kOnPlot)
        .value("kOnEtransmit", PyDbField::EvalOption::kOnEtransmit)
        .value("kOnRegen", PyDbField::EvalOption::kOnRegen)
        .value("kOnDemand", PyDbField::EvalOption::kOnDemand)
        .value("kAutomatic", PyDbField::EvalOption::kAutomatic)
        ;
    enum_<PyDbField::EvalContext>("EvalContext")
        .value("kOpen", PyDbField::EvalContext::kOpen)
        .value("kSave", PyDbField::EvalContext::kSave)
        .value("kPlot", PyDbField::EvalContext::kPlot)
        .value("kEtransmit", PyDbField::EvalContext::kEtransmit)
        .value("kRegen", PyDbField::EvalContext::kRegen)
        .value("kDemand", PyDbField::EvalContext::kDemand)
        .value("kPreview", PyDbField::EvalContext::kPreview)
        .value("kPlotPreview", PyDbField::EvalContext::kPlotPreview)
        ;
    enum_<PyDbField::EvalStatus>("EvalStatus")
        .value("kNotYetEvaluated", PyDbField::EvalStatus::kNotYetEvaluated)
        .value("kSuccess", PyDbField::EvalStatus::kSuccess)
        .value("kEvaluatorNotFound", PyDbField::EvalStatus::kEvaluatorNotFound)
        .value("kSyntaxError", PyDbField::EvalStatus::kSyntaxError)
        .value("kInvalidCode", PyDbField::EvalStatus::kInvalidCode)
        .value("kInvalidContext", PyDbField::EvalStatus::kInvalidContext)
        .value("kOtherError", PyDbField::EvalStatus::kOtherError)
        ;
    enum_<PyDbField::FieldCodeFlag>("FieldCodeFlag")
        .value("kFieldCode", PyDbField::FieldCodeFlag::kFieldCode)
        .value("kEvaluatedText", PyDbField::FieldCodeFlag::kEvaluatedText)
        .value("kEvaluatedChildren", PyDbField::FieldCodeFlag::kEvaluatedChildren)
        .value("kObjectReference", PyDbField::FieldCodeFlag::kObjectReference)
        .value("kAddMarkers", PyDbField::FieldCodeFlag::kAddMarkers)
        .value("kEscapeBackslash", PyDbField::FieldCodeFlag::kEscapeBackslash)
        .value("kStripOptions", PyDbField::FieldCodeFlag::kStripOptions)
        .value("kPreserveFields", PyDbField::FieldCodeFlag::kPreserveFields)
        .value("kTextField", PyDbField::FieldCodeFlag::kTextField)
#ifndef BRXAPP
        .value("kPreserveOptions", PyDbField::FieldCodeFlag::kPreserveOptions)
        .value("kDetachChildren", PyDbField::FieldCodeFlag::kDetachChildren)
        .value("kChildObjectReference", PyDbField::FieldCodeFlag::kChildObjectReference)
        .value("kForExpression", PyDbField::FieldCodeFlag::kForExpression)
#endif
        ;
}

PyDbField::PyDbField()
    : PyDbField(new AcDbField(), true)
{
}

PyDbField::PyDbField(const std::string& pszFieldCode, bool bTextField)
    : PyDbField(new AcDbField(utf8_to_wstr(pszFieldCode).c_str(), bTextField), true)
{
}

PyDbField::PyDbField(AcDbField* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbField::PyDbField(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbField* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbField>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

Acad::ErrorStatus PyDbField::setInObject(PyDbObject& pObj, const std::string& pszPropName)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setInObject(pObj.impObj(), utf8_to_wstr(pszPropName).c_str());
#endif
}

Acad::ErrorStatus PyDbField::postInDatabase(PyDbDatabase& pDb)
{
    return impObj()->postInDatabase(pDb.impObj());
}

PyDbField::State PyDbField::state(void) const
{
    return static_cast<PyDbField::State>(impObj()->state());
}

PyDbField::EvalStatus PyDbField::evaluationStatus() const
{
    return static_cast<PyDbField::EvalStatus>(impObj()->evaluationStatus());
}

PyDbField::EvalOption PyDbField::evaluationOption(void) const
{
    return static_cast<PyDbField::EvalOption>(impObj()->evaluationOption());
}

Acad::ErrorStatus PyDbField::setEvaluationOption(PyDbField::EvalOption nEvalOption)
{
    return impObj()->setEvaluationOption(static_cast<AcDbField::EvalOption>( nEvalOption));
}

std::string PyDbField::evaluatorId(void) const
{
    return wstr_to_utf8(impObj()->evaluatorId());
}

Acad::ErrorStatus PyDbField::setEvaluatorId(const std::string& pszEvaluatorId)
{
    return impObj()->setEvaluatorId(utf8_to_wstr(pszEvaluatorId).c_str());
}

bool PyDbField::isTextField(void) const
{
    return impObj()->isTextField();
}

Acad::ErrorStatus PyDbField::convertToTextField(void)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->convertToTextField();
#endif
}

int PyDbField::childCount(void) const
{
    return impObj()->childCount();
}

std::string PyDbField::getFormat(void) const
{
    return wstr_to_utf8(impObj()->getFormat());
}

Acad::ErrorStatus PyDbField::setFormat(const std::string& pszFormat)
{
    return impObj()->setFormat(utf8_to_wstr(pszFormat).c_str());
}

std::string PyDbField::getValue(void) const
{
    return wstr_to_utf8(impObj()->getValue());
}

std::string PyDbField::className()
{
    return "AcDbField";
}

PyRxClass PyDbField::desc()
{
    return PyRxClass(AcDbField::desc(), false);
}

AcDbField* PyDbField::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbField*>(m_pImp.get());
}

