#include "stdafx.h"
#include "PyDbField.h"
#include "PyDbObjectId.h"
using namespace boost::python;
void makePyDbFieldtWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pszFieldCode: str\n"
        "- pszFieldCode: str, bTextField: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view evaluateOverloads = "Overloads:\n"
        "- None: Any\n"
        "- nFlag: PyDb.FieldEvalContext\n"
        "- nFlag: PyDb.FieldEvalContext, db: PyDb.Database\n";

    constexpr const std::string_view getFieldCodeOverloads = "Overloads:\n"
        "- nContext: PyDb.FieldCodeFlag\n"
        "- nContext: PyDb.FieldCodeFlag, children: PyDb.Field, mode: PyDb.OpenMode\n";
        
    PyDocString DS("PyDb.Field");
    class_<PyDbField, bases<PyDbObject>>("Field")
        .def(init<>())
        .def(init<const std::string&>())
        .def(init<const std::string&, bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode,bool>(DS.CTOR(ctords)))
        .def("setInObject", &PyDbField::setInObject, DS.ARGS({ "db: PyDb.DbObject","pszPropName: str"}))
        .def("postInDatabase", &PyDbField::postInDatabase, DS.ARGS({ "db: PyDb.Database" }))
        .def("state", &PyDbField::state, DS.ARGS())
        .def("evaluationStatus", &PyDbField::evaluationStatus, DS.ARGS())
        .def("evaluationOption", &PyDbField::evaluationOption, DS.ARGS())
        .def("setEvaluationOption", &PyDbField::setEvaluationOption, DS.ARGS({ "val : PyDb.FieldEvalOption" }))
        .def("evaluatorId", &PyDbField::evaluatorId, DS.ARGS())
        .def("setEvaluatorId", &PyDbField::setEvaluatorId, DS.ARGS({ "pszEvaluatorId : str" }))
        .def("isTextField", &PyDbField::isTextField, DS.ARGS())
        .def("convertToTextField", &PyDbField::convertToTextField, DS.ARGS())
        .def("childCount", &PyDbField::childCount, DS.ARGS())
        .def("getFormat", &PyDbField::getFormat, DS.ARGS())
        .def("setFormat", &PyDbField::setFormat, DS.ARGS({ "pszFormat : str" }))
        .def("getValue", &PyDbField::getValue, DS.ARGS())
        .def("evaluate", &PyDbField::evaluate1)
        .def("evaluate", &PyDbField::evaluate2)
        .def("evaluate", &PyDbField::evaluate3,DS.OVRL(evaluateOverloads))
        .def("getFieldCode", &PyDbField::getFieldCode1)
        .def("getFieldCode", &PyDbField::getFieldCode2, DS.OVRL(getFieldCodeOverloads))
        .def("className", &PyDbField::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbField::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbField::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbField::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
    enum_<AcDbField::State>("FieldState")
        .value("kInitialized", AcDbField::State::kInitialized)
        .value("kCompiled", AcDbField::State::kCompiled)
        .value("kModified", AcDbField::State::kModified)
        .value("kEvaluated", AcDbField::State::kEvaluated)
        .value("kHasCache", AcDbField::State::kHasCache)
#if !defined(_BRXTARGET240)
        .value("kHasFormattedString", AcDbField::State::kHasFormattedString)
#endif
        .export_values()
        ;
    enum_<AcDbField::EvalOption>("FieldEvalOption")
        .value("kDisable", AcDbField::EvalOption::kDisable)
        .value("kOnOpen", AcDbField::EvalOption::kOnOpen)
        .value("kOnSave", AcDbField::EvalOption::kOnSave)
        .value("kOnPlot", AcDbField::EvalOption::kOnPlot)
        .value("kOnEtransmit", AcDbField::EvalOption::kOnEtransmit)
        .value("kOnRegen", AcDbField::EvalOption::kOnRegen)
        .value("kOnDemand", AcDbField::EvalOption::kOnDemand)
        .value("kAutomatic", AcDbField::EvalOption::kAutomatic)
        .export_values()
        ;
    enum_<AcDbField::EvalContext>("FieldEvalContext")
        .value("kOpen", AcDbField::EvalContext::kOpen)
        .value("kSave", AcDbField::EvalContext::kSave)
        .value("kPlot", AcDbField::EvalContext::kPlot)
        .value("kEtransmit", AcDbField::EvalContext::kEtransmit)
        .value("kRegen", AcDbField::EvalContext::kRegen)
        .value("kDemand", AcDbField::EvalContext::kDemand)
        .value("kPreview", AcDbField::EvalContext::kPreview)
        .value("kPlotPreview", AcDbField::EvalContext::kPlotPreview)
        .export_values()
        ;
    enum_<AcDbField::EvalStatus>("FieldEvalStatus")
        .value("kNotYetEvaluated", AcDbField::EvalStatus::kNotYetEvaluated)
        .value("kSuccess", AcDbField::EvalStatus::kSuccess)
        .value("kEvaluatorNotFound", AcDbField::EvalStatus::kEvaluatorNotFound)
        .value("kSyntaxError", AcDbField::EvalStatus::kSyntaxError)
        .value("kInvalidCode", AcDbField::EvalStatus::kInvalidCode)
        .value("kInvalidContext", AcDbField::EvalStatus::kInvalidContext)
        .value("kOtherError", AcDbField::EvalStatus::kOtherError)
        .export_values()
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
#if !defined(_BRXTARGET240)
        .value("kPreserveOptions", AcDbField::FieldCodeFlag::kPreserveOptions)
        .value("kDetachChildren", AcDbField::FieldCodeFlag::kDetachChildren)
        .value("kChildObjectReference", AcDbField::FieldCodeFlag::kChildObjectReference)
        .value("kForExpression", AcDbField::FieldCodeFlag::kForExpression)
#endif
        .export_values()
        ;
}

PyDbField::PyDbField()
    : PyDbObject(new AcDbField(), true)
{
}

PyDbField::PyDbField(const std::string& pszFieldCode)
    : PyDbObject(new AcDbField(utf8_to_wstr(pszFieldCode).c_str(), true), true)
{
}

PyDbField::PyDbField(const std::string& pszFieldCode, bool bTextField)
    : PyDbObject(new AcDbField(utf8_to_wstr(pszFieldCode).c_str(), bTextField), true)
{
}

PyDbField::PyDbField(AcDbField* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbField::PyDbField(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbField>(id, mode), false)
{
}

PyDbField::PyDbField(const PyDbObjectId& id)
    : PyDbField(id, AcDb::OpenMode::kForRead)
{
}

PyDbField::PyDbField(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbField>(id, mode, erased), false)
{
}

void PyDbField::setInObject(PyDbObject& pObj, const std::string& pszPropName)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInObject(pObj.impObj(), utf8_to_wstr(pszPropName).c_str()));
#endif
}

void PyDbField::postInDatabase(PyDbDatabase& pDb)
{
    return PyThrowBadEs(impObj()->postInDatabase(pDb.impObj()));
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

void PyDbField::setEvaluationOption(AcDbField::EvalOption nEvalOption)
{
    return PyThrowBadEs(impObj()->setEvaluationOption(nEvalOption));
}

std::string PyDbField::evaluatorId(void) const
{
    return wstr_to_utf8(impObj()->evaluatorId());
}

void PyDbField::setEvaluatorId(const std::string& pszEvaluatorId)
{
    return PyThrowBadEs(impObj()->setEvaluatorId(utf8_to_wstr(pszEvaluatorId).c_str()));
}

bool PyDbField::isTextField(void) const
{
    return impObj()->isTextField();
}

void PyDbField::convertToTextField(void)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->convertToTextField());
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

void PyDbField::setFormat(const std::string& pszFormat)
{
    return PyThrowBadEs(impObj()->setFormat(utf8_to_wstr(pszFormat).c_str()));
}

std::string PyDbField::getValue(void) const
{
    return wstr_to_utf8(impObj()->getValue());
}

void PyDbField::evaluate1()
{
    return PyThrowBadEs(impObj()->evaluate(32, acdbHostApplicationServices()->workingDatabase()));
}

void PyDbField::evaluate2(AcDbField::EvalContext nContext)
{
    return PyThrowBadEs(impObj()->evaluate(nContext, acdbHostApplicationServices()->workingDatabase()));
}

void PyDbField::evaluate3(AcDbField::EvalContext nContext, PyDbDatabase& db)
{
    return PyThrowBadEs(impObj()->evaluate(nContext, db.impObj()));
}

std::string PyDbField::getFieldCode1(AcDbField::FieldCodeFlag nFlag)
{
    return wstr_to_utf8(impObj()->getFieldCode(nFlag));
}

std::string PyDbField::getFieldCode2(AcDbField::FieldCodeFlag nFlag,const boost::python::list& pyfields, AcDb::OpenMode mode)
{
    PyAutoLockGIL lock;
    AcArray<AcDbField*> pChildFields;
    auto PyList = py_list_to_std_vector<PyDbField>(pyfields);
    for (const auto& item : PyList)
        pChildFields.append(item.impObj());
    return wstr_to_utf8(impObj()->getFieldCode(nFlag, &pChildFields, mode));
}

std::string PyDbField::className()
{
    return "AcDbField";
}

PyRxClass PyDbField::desc()
{
    return PyRxClass(AcDbField::desc(), false);
}

PyDbField PyDbField::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbField::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbField(static_cast<AcDbField*>(src.impObj()->clone()), true);
}

PyDbField PyDbField::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbField>(src);
}

AcDbField* PyDbField::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbField*>(m_pyImp.get());
}

