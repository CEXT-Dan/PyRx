#include "stdafx.h"
#include "PyDbField.h"
#include "PyDbObjectId.h"
using namespace boost::python;

void makeAcDbFieldtWrapper()
{
    static auto wrapper = class_<PyDbField, bases<PyDbObject>>("DbField")
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
        .value("Initialized", AcDbField::State::kInitialized)
        .value("Compiled", AcDbField::State::kCompiled)
        .value("Modified", AcDbField::State::kModified)
        .value("Evaluated", AcDbField::State::kEvaluated)
        .value("HasCache", AcDbField::State::kHasCache)
#ifndef BRXAPP
        .value("HasFormattedString", AcDbField::State::kHasFormattedString)
#endif // BRXAPP
        ;
    enum_<AcDbField::EvalOption>("EvalOption")
        .value("Disable", AcDbField::EvalOption::kDisable)
        .value("OnOpen", AcDbField::EvalOption::kOnOpen)
        .value("OnSave", AcDbField::EvalOption::kOnSave)
        .value("OnPlot", AcDbField::EvalOption::kOnPlot)
        .value("OnEtransmit", AcDbField::EvalOption::kOnEtransmit)
        .value("OnRegen", AcDbField::EvalOption::kOnRegen)
        .value("OnDemand", AcDbField::EvalOption::kOnDemand)
        .value("Automatic", AcDbField::EvalOption::kAutomatic)
        ;
    enum_<AcDbField::EvalContext>("EvalContext")
        .value("Open", AcDbField::EvalContext::kOpen)
        .value("Save", AcDbField::EvalContext::kSave)
        .value("Plot", AcDbField::EvalContext::kPlot)
        .value("Etransmit", AcDbField::EvalContext::kEtransmit)
        .value("Regen", AcDbField::EvalContext::kRegen)
        .value("Demand", AcDbField::EvalContext::kDemand)
        .value("Preview", AcDbField::EvalContext::kPreview)
        .value("PlotPreview", AcDbField::EvalContext::kPlotPreview)
        ;
    enum_<AcDbField::EvalStatus>("EvalStatus")
        .value("NotYetEvaluated", AcDbField::EvalStatus::kNotYetEvaluated)
        .value("Success", AcDbField::EvalStatus::kSuccess)
        .value("EvaluatorNotFound", AcDbField::EvalStatus::kEvaluatorNotFound)
        .value("SyntaxError", AcDbField::EvalStatus::kSyntaxError)
        .value("InvalidCode", AcDbField::EvalStatus::kInvalidCode)
        .value("InvalidContext", AcDbField::EvalStatus::kInvalidContext)
        .value("OtherError", AcDbField::EvalStatus::kOtherError)
        ;
    enum_<AcDbField::FieldCodeFlag>("FieldCodeFlag")
        .value("FieldCode", AcDbField::FieldCodeFlag::kFieldCode)
        .value("EvaluatedText", AcDbField::FieldCodeFlag::kEvaluatedText)
        .value("EvaluatedChildren", AcDbField::FieldCodeFlag::kEvaluatedChildren)
        .value("ObjectReference", AcDbField::FieldCodeFlag::kObjectReference)
        .value("AddMarkers", AcDbField::FieldCodeFlag::kAddMarkers)
        .value("EscapeBackslash", AcDbField::FieldCodeFlag::kEscapeBackslash)
        .value("StripOptions", AcDbField::FieldCodeFlag::kStripOptions)
        .value("PreserveFields", AcDbField::FieldCodeFlag::kPreserveFields)
        .value("TextField", AcDbField::FieldCodeFlag::kTextField)
#ifndef BRXAPP
        .value("PreserveOptions", AcDbField::FieldCodeFlag::kPreserveOptions)
        .value("DetachChildren", AcDbField::FieldCodeFlag::kDetachChildren)
        .value("ChildObjectReference", AcDbField::FieldCodeFlag::kChildObjectReference)
        .value("ForExpression", AcDbField::FieldCodeFlag::kForExpression)
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
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

Acad::ErrorStatus PyDbField::setInObject(PyDbObject& pObj, const std::string& pszPropName)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setInObject(pObj.impObj(), utf8_to_wstr(pszPropName).c_str());
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbField::postInDatabase(PyDbDatabase& pDb)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->postInDatabase(pDb.impObj());
    throw PyNullObject();
}

AcDbField::State PyDbField::state(void) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->state();
    throw PyNullObject();
}

AcDbField::EvalStatus PyDbField::evaluationStatus() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->evaluationStatus();
    throw PyNullObject();
}

AcDbField::EvalOption PyDbField::evaluationOption(void) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->evaluationOption();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbField::setEvaluationOption(AcDbField::EvalOption nEvalOption)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setEvaluationOption(nEvalOption);
    throw PyNullObject();
}

std::string PyDbField::evaluatorId(void) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->evaluatorId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbField::setEvaluatorId(const std::string& pszEvaluatorId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setEvaluatorId(utf8_to_wstr(pszEvaluatorId).c_str());
    throw PyNullObject();
}

bool PyDbField::isTextField(void) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isTextField();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbField::convertToTextField(void)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->convertToTextField();
    throw PyNullObject();
#endif
}

int PyDbField::childCount(void) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->childCount();
    throw PyNullObject();
}

std::string PyDbField::getFormat(void) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->getFormat());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbField::setFormat(const std::string& pszFormat)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setFormat(utf8_to_wstr(pszFormat).c_str());
    throw PyNullObject();
}


std::string PyDbField::getValue(void) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->getValue());
    throw PyNullObject();
}

std::string PyDbField::className()
{
    return "AcDbField";
}

AcDbField* PyDbField::impObj() const
{
    return static_cast<AcDbField*>(m_pImp);
}

