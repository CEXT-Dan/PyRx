#include "stdafx.h"
#include "PyDbField.h"
#include "PyDbObjectId.h"
using namespace boost::python;
void makeAcDbFieldtWrapper()
{
    class_<PyDbField, bases<PyDbObject>>("Field")
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
        ;
    enum_<AcDbField::State>("State")
        .value("kInitialized", AcDbField::State::kInitialized)
        .value("kCompiled", AcDbField::State::kCompiled)
        .value("kModified", AcDbField::State::kModified)
        .value("kEvaluated", AcDbField::State::kEvaluated)
        .value("kHasCache", AcDbField::State::kHasCache)
#ifndef BRXAPP
        .value("kHasFormattedString", AcDbField::State::kHasFormattedString)
#endif // BRXAPP
        ;
    enum_<AcDbField::EvalOption>("EvalOption")
        .value("kDisable", AcDbField::EvalOption::kDisable)
        .value("kOnOpen", AcDbField::EvalOption::kOnOpen)
        .value("kOnSave", AcDbField::EvalOption::kOnSave)
        .value("kOnPlot", AcDbField::EvalOption::kOnPlot)
        .value("kOnEtransmit", AcDbField::EvalOption::kOnEtransmit)
        .value("kOnRegen", AcDbField::EvalOption::kOnRegen)
        .value("kOnDemand", AcDbField::EvalOption::kOnDemand)
        .value("kAutomatic", AcDbField::EvalOption::kAutomatic)
        ;
    enum_<AcDbField::EvalContext>("EvalContext")
        .value("kOpen", AcDbField::EvalContext::kOpen)
        .value("kSave", AcDbField::EvalContext::kSave)
        .value("kPlot", AcDbField::EvalContext::kPlot)
        .value("kEtransmit", AcDbField::EvalContext::kEtransmit)
        .value("kRegen", AcDbField::EvalContext::kRegen)
        .value("kDemand", AcDbField::EvalContext::kDemand)
        .value("kPreview", AcDbField::EvalContext::kPreview)
        .value("kPlotPreview", AcDbField::EvalContext::kPlotPreview)
        ;
    enum_<AcDbField::EvalStatus>("EvalStatus")
        .value("kNotYetEvaluated", AcDbField::EvalStatus::kNotYetEvaluated)
        .value("kSuccess", AcDbField::EvalStatus::kSuccess)
        .value("kEvaluatorNotFound", AcDbField::EvalStatus::kEvaluatorNotFound)
        .value("kSyntaxError", AcDbField::EvalStatus::kSyntaxError)
        .value("kInvalidCode", AcDbField::EvalStatus::kInvalidCode)
        .value("kInvalidContext", AcDbField::EvalStatus::kInvalidContext)
        .value("kOtherError", AcDbField::EvalStatus::kOtherError)
        ;
    enum_<AcDbField::FieldCodeFlag>("FieldCodeFlag")
        .value("kFieldCode", AcDbField::FieldCodeFlag::kFieldCode)
        .value("kEvaluatedText", AcDbField::FieldCodeFlag::kEvaluatedText)
        .value("kEvaluatedChildren", AcDbField::FieldCodeFlag::kEvaluatedChildren)
        .value("kObjectReference", AcDbField::FieldCodeFlag::kObjectReference)
        .value("kAddMarkers", AcDbField::FieldCodeFlag::kAddMarkers)
        .value("kEscapeBackslash", AcDbField::FieldCodeFlag::kEscapeBackslash)
        .value("kStripOptions", AcDbField::FieldCodeFlag::kStripOptions)
        .value("kPreserveFields", AcDbField::FieldCodeFlag::kPreserveFields)
        .value("kTextField", AcDbField::FieldCodeFlag::kTextField)
#ifndef BRXAPP
        .value("kPreserveOptions", AcDbField::FieldCodeFlag::kPreserveOptions)
        .value("kDetachChildren", AcDbField::FieldCodeFlag::kDetachChildren)
        .value("kChildObjectReference", AcDbField::FieldCodeFlag::kChildObjectReference)
        .value("kForExpression", AcDbField::FieldCodeFlag::kForExpression)
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

AcDbField::State PyDbField::state(void) const
{
    return impObj()->state();
}

AcDbField::EvalStatus PyDbField::evaluationStatus() const
{
    return impObj()->evaluationStatus();
}

AcDbField::EvalOption PyDbField::evaluationOption(void) const
{
    return impObj()->evaluationOption();
}

Acad::ErrorStatus PyDbField::setEvaluationOption(AcDbField::EvalOption nEvalOption)
{
    return impObj()->setEvaluationOption(nEvalOption);
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

AcDbField* PyDbField::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbField*>(m_pImp.get());
}

