#include "stdafx.h"
#include "PyDbField.h"
#include "PyDbObjectId.h"
#include "PyDbEval.h"

using namespace boost::python;
void makePyDbFieldWrapper()
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 4616)))
        .def("setInObject", &PyDbField::setInObject, DS.ARGS({ "db: PyDb.DbObject","pszPropName: str" }, 4652))
        .def("postInDatabase", &PyDbField::postInDatabase, DS.ARGS({ "db: PyDb.Database" }, 4643))
        .def("state", &PyDbField::state, DS.ARGS(4653))
        .def("evaluationStatus", &PyDbField::evaluationStatus, DS.ARGS(4630))
        .def("evaluationOption", &PyDbField::evaluationOption, DS.ARGS(4629))
        .def("setEvaluationOption", &PyDbField::setEvaluationOption, DS.ARGS({ "val : PyDb.FieldEvalOption" }, 4646))
        .def("evaluatorId", &PyDbField::evaluatorId, DS.ARGS(4631))
        .def("setEvaluatorId", &PyDbField::setEvaluatorId, DS.ARGS({ "pszEvaluatorId : str" }, 4647))
        .def("isTextField", &PyDbField::isTextField, DS.ARGS(4642))
        .def("convertToTextField", &PyDbField::convertToTextField, DS.ARGS(4619))
        .def("childCount", &PyDbField::childCount, DS.ARGS(4618))
        .def("getChild", &PyDbField::getChild, DS.ARGS({ "index:int","mode: PyDb.OpenMode" }, 4635))
        .def("getFormat", &PyDbField::getFormat, DS.ARGS(4638))
        .def("setFormat", &PyDbField::setFormat, DS.ARGS({ "pszFormat : str" }, 4650))
        .def("getValue", &PyDbField::getValue, DS.ARGS(4640))
        .def("evaluate", &PyDbField::evaluate1)
        .def("evaluate", &PyDbField::evaluate2)
        .def("evaluate", &PyDbField::evaluate3, DS.OVRL(evaluateOverloads, 4628))
        .def("getFieldCode", &PyDbField::getFieldCode1)
        .def("getFieldCode", &PyDbField::getFieldCode2, DS.OVRL(getFieldCodeOverloads, 4637))
        .def("getData", &PyDbField::getData, DS.ARGS({ "key: str" }))
        .def("hasData", &PyDbField::hasData, DS.ARGS({ "key: str" }))
        .def("setData", &PyDbField::setData1)
        .def("setData", &PyDbField::setData2, DS.ARGS({ "key: str","value: PyDb.AcValue","bRecursive:bool=False" }))
        .def("className", &PyDbField::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbField::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbField::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbField::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
    enum_<AcDbField::State>("FieldState")
        .value("kInitialized", AcDbField::State::kInitialized)
        .value("kCompiled", AcDbField::State::kCompiled)
        .value("kModified", AcDbField::State::kModified)
        .value("kEvaluated", AcDbField::State::kEvaluated)
        .value("kHasCache", AcDbField::State::kHasCache)
#if !defined(_BRXTARGET250)
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
#if !defined (_BRXTARGET250)
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

PyDbField::PyDbField(const PyDbObjectId& id)
    : PyDbObject(openAcDbObject<AcDbField>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbField::PyDbField(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbField>(id, mode), false)
{
}

PyDbField::PyDbField(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbField>(id, mode, erased), false)
{
}

PyDbField::PyDbField(AcDbField* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

void PyDbField::setInObject(PyDbObject& pObj, const std::string& pszPropName) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInObject(pObj.impObj(), utf8_to_wstr(pszPropName).c_str()));
#endif
}

void PyDbField::postInDatabase(PyDbDatabase& pDb) const
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

void PyDbField::setEvaluationOption(AcDbField::EvalOption nEvalOption) const
{
    return PyThrowBadEs(impObj()->setEvaluationOption(nEvalOption));
}

std::string PyDbField::evaluatorId(void) const
{
    return wstr_to_utf8(impObj()->evaluatorId());
}

void PyDbField::setEvaluatorId(const std::string& pszEvaluatorId) const
{
    return PyThrowBadEs(impObj()->setEvaluatorId(utf8_to_wstr(pszEvaluatorId).c_str()));
}

bool PyDbField::isTextField(void) const
{
    return impObj()->isTextField();
}

void PyDbField::convertToTextField(void) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->convertToTextField());
#endif
}

int PyDbField::childCount(void) const
{
    return impObj()->childCount();
}

PyDbField PyDbField::getChild(int idx, AcDb::OpenMode mode) const
{
    AcDbField* pfield = nullptr;
    PyThrowBadEs(impObj()->getChild(idx, pfield, mode));
    return PyDbField(pfield, false);
}

std::string PyDbField::getFormat(void) const
{
    return wstr_to_utf8(impObj()->getFormat());
}

void PyDbField::setFormat(const std::string& pszFormat) const
{
    return PyThrowBadEs(impObj()->setFormat(utf8_to_wstr(pszFormat).c_str()));
}

std::string PyDbField::getValue(void) const
{
    return wstr_to_utf8(impObj()->getValue());
}

boost::python::tuple PyDbField::evaluate1() const
{
    PyAutoLockGIL lock;
    int pNumFound = 0;
    int pNumEvaluated = 0;
    AcDbDatabase* pDb = impObj()->database();
    if (pDb == nullptr)
        pDb = acdbHostApplicationServices()->workingDatabase();
    PyThrowBadEs(impObj()->evaluate(32, pDb, &pNumFound, &pNumEvaluated));
    return boost::python::make_tuple(pNumFound, pNumEvaluated);
}

boost::python::tuple PyDbField::evaluate2(AcDbField::EvalContext nContext) const
{
    PyAutoLockGIL lock;
    int pNumFound = 0;
    int pNumEvaluated = 0;
    AcDbDatabase* pDb = impObj()->database();
    if (pDb == nullptr)
        pDb = acdbHostApplicationServices()->workingDatabase();
    PyThrowBadEs(impObj()->evaluate(nContext, pDb, &pNumFound, &pNumEvaluated));
    return boost::python::make_tuple(pNumFound, pNumEvaluated);
}

boost::python::tuple PyDbField::evaluate3(AcDbField::EvalContext nContext, PyDbDatabase& db) const
{
    PyAutoLockGIL lock;
    int pNumFound = 0;
    int pNumEvaluated = 0;
    PyThrowBadEs(impObj()->evaluate(nContext, db.impObj(), &pNumFound, &pNumEvaluated));
    return boost::python::make_tuple(pNumFound, pNumEvaluated);
}

std::string PyDbField::getFieldCode1(AcDbField::FieldCodeFlag nFlag) const
{
    return wstr_to_utf8(impObj()->getFieldCode(nFlag));
}

std::string PyDbField::getFieldCode2(AcDbField::FieldCodeFlag nFlag, const boost::python::list& pyfields, AcDb::OpenMode mode) const
{
    PyAutoLockGIL lock;
    AcArray<AcDbField*> pChildFields;
    auto PyList = py_list_to_std_vector<PyDbField>(pyfields);
    for (const auto& item : PyList)
        pChildFields.append(item.impObj());
    return wstr_to_utf8(impObj()->getFieldCode(nFlag, &pChildFields, mode));
}

void PyDbField::setData1(const std::string& key, const PyDbAcValue& value) const
{
    PyThrowBadEs(impObj()->setData(utf8_to_wstr(key).c_str(), value.impObj()));
}

void PyDbField::setData2(const std::string& key, const PyDbAcValue& value, bool bRecursive) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setData(utf8_to_wstr(key).c_str(), value.impObj(), bRecursive));
#endif
}

PyDbAcValue PyDbField::getData(const std::string& key) const
{
    PyDbAcValue val{};
    PyThrowBadEs(impObj()->getData(utf8_to_wstr(key).c_str(), val.impObj()));
    return val;
}

bool PyDbField::hasData(const std::string& key) const
{
    PyDbAcValue val{};
    return impObj()->getData(utf8_to_wstr(key).c_str(), val.impObj()) == eOk;
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
    return PyDbObjectCloneFrom<PyDbField, AcDbField>(src);
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

//---------------------------------------------------------------------------------------- -
//PyDdFieldEvaluator
void makePyDdFieldEvaluatorWrapper()
{
    PyDocString DS("PyDb.FieldEvaluator");
    class_<PyDdFieldEvaluator>("FieldEvaluator", boost::python::no_init)
        .def(init<const std::string&, const std::string&>())
        .def("evaluate", &PyDdFieldEvaluator::evaluateWr, DS.ARGS({ "field:PyDb.Field","context:int","db:PyDb.Database","result:PyDb.AcValue" }, 11617))
        .def("beginEvaluateFields", &PyDdFieldEvaluator::beginEvaluateFieldsWr, DS.ARGS({ "context:int","db:PyDb.Database" }, 11623))
        .def("endEvaluateFields", &PyDdFieldEvaluator::endEvaluateFieldsWr, DS.ARGS({ "context:int","db:PyDb.Database" }, 11624))
        .def("initialize", &PyDdFieldEvaluator::initializeWr, DS.ARGS({ "field:PyDb.Field" }, 11620))
        .def("compile", &PyDdFieldEvaluator::compileWr, DS.ARGS({ "field:PyDb.Field","db:PyDb.Database","result:PyDb.AcValue" }, 11616))
        .def("format", &PyDdFieldEvaluator::formatWr, DS.ARGS({ "field:PyDb.Field" }, 11619))
        .def("getName", &PyDdFieldEvaluator::getName, DS.ARGS())
        .def("getEvalName", &PyDdFieldEvaluator::getEvalName, DS.ARGS())
        .def("className", &PyDdFieldEvaluator::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDdFieldEvaluator::PyDdFieldEvaluator(const std::string& name, const std::string& evalName)
    :m_name(utf8_to_wstr(name).c_str()), m_evalName(utf8_to_wstr(evalName).c_str())
{
}

const ACHAR* PyDdFieldEvaluator::evaluatorId(void) const
{
    return m_evalName;
}

const ACHAR* PyDdFieldEvaluator::evaluatorId(AcDbField* pField)
{
    return m_evalName;
}

Acad::ErrorStatus PyDdFieldEvaluator::initialize(AcDbField* pField)
{
    if (reg_initialize)
    {
        PyAutoLockGIL lock;
        PyDbField pyfield(pField, false);
        pyfield.forceKeepAlive(true);
        return initializeWr(pyfield);
    }
    return eNotImplemented;
}

Acad::ErrorStatus PyDdFieldEvaluator::initializeWr(const PyDbField& pField)
{
    try
    {
        if (override f = this->get_override("initialize"))
            return f(pField);
        else
            reg_initialize = false;
    }
    catch (...)
    {
        reg_initialize = false;
        printExceptionMsg();
    }
    return Acad::eOk;
}

Acad::ErrorStatus PyDdFieldEvaluator::compile(AcDbField* pField, AcDbDatabase* pDb, AcFdFieldResult* pResult)
{
    if (reg_compile)
    {
        PyAutoLockGIL lock;
        PyDbAcValue pyacVal;
        PyDbField pyfield(pField, false);
        pyfield.forceKeepAlive(true);
        PyDbDatabase pydatabase{ pDb };
        const auto evalstat = compileWr(pyfield, pydatabase, pyacVal);
        if (GETBIT(evalstat, AcDbField::kSuccess))
        {
            pResult->setFieldValue(pyacVal.impObj());
            pResult->setEvaluationStatus(AcDbField::kSuccess);
            return eOk;
        }
    }
    return eNotImplemented;
}

AcDbField::EvalStatus PyDdFieldEvaluator::compileWr(const PyDbField& pField, const PyDbDatabase& pDb, PyDbAcValue& pResult)
{
    try
    {
        if (override f = this->get_override("compile"))
            return f(pField, pDb, pResult);
        else
            reg_compile = false;
    }
    catch (...)
    {
        reg_compile = false;
        printExceptionMsg();
        return AcDbField::kOtherError;
    }
    return AcDbField::kNotYetEvaluated;
}

Acad::ErrorStatus PyDdFieldEvaluator::evaluate(AcDbField* pField, int nContext, AcDbDatabase* pDb, AcFdFieldResult* pResult)
{
    if (reg_evaluate)
    {
        PyAutoLockGIL lock;
        PyDbAcValue pyacVal;
        PyDbField pyfield(pField, false);
        pyfield.forceKeepAlive(true);
        PyDbDatabase pydatabase{ pDb };
        const auto evalstat = evaluateWr(pyfield, nContext, pydatabase, pyacVal);
        if (GETBIT(evalstat, AcDbField::kSuccess))
        {
            pResult->setFieldValue(pyacVal.impObj());
            pResult->setEvaluationStatus(AcDbField::kSuccess);
            return eOk;
        }
    }
    return eNotImplemented;
}

AcDbField::EvalStatus PyDdFieldEvaluator::evaluateWr(const PyDbField& pField, int nContext, const PyDbDatabase& pDb, PyDbAcValue& pResult)
{
    try
    {
        if (override f = this->get_override("evaluate"))
        {
            return f(pField, nContext, pDb, pResult);
        }
        else
        {
            reg_evaluate = false;
        }
    }
    catch (...)
    {
        reg_evaluate = false;
        printExceptionMsg();
        return AcDbField::kOtherError;
    }
    return AcDbField::kNotYetEvaluated;
}

Acad::ErrorStatus PyDdFieldEvaluator::format(AcDbField* pField, AcString& sValue)
{
    if (reg_format)
    {
        PyAutoLockGIL lock;
        PyDbField pyfield(pField, false);
        pyfield.forceKeepAlive(true);
        auto resut = formatWr(pyfield);
        if (resut.size())
        {
            sValue = utf8_to_wstr(formatWr(pyfield)).c_str();
            return eOk;
        }
        sValue = utf8_to_wstr(formatWr(pyfield)).c_str();
    }
    return eNotImplemented;
}

std::string PyDdFieldEvaluator::formatWr(const PyDbField& pField)
{
    try
    {
        if (override f = this->get_override("format"))
            return f(pField);
        else
            reg_format = false;
    }
    catch (...)
    {
        reg_format = false;
        printExceptionMsg();
    }
    return std::string{};
}

void PyDdFieldEvaluator::beginEvaluateFieldsWr(int nContext, const PyDbDatabase& pDb)
{
    try
    {
        if (override f = this->get_override("beginEvaluateFields"))
            f(nContext, pDb);
        else
            reg_beginEvaluateFields = false;
    }
    catch (...)
    {
        reg_beginEvaluateFields = false;
    }
}

void PyDdFieldEvaluator::endEvaluateFieldsWr(int nContext, const PyDbDatabase& pDb)
{
    try
    {
        if (override f = this->get_override("endEvaluateFields"))
            f(nContext, pDb);
        else
            reg_endEvaluateFields = false;
    }
    catch (...)
    {
        reg_endEvaluateFields = false;
    }
}

std::string PyDdFieldEvaluator::className()
{
    return "AcFdFieldEvaluator";
}

//---------------------------------------------------------------------------------------- -
//PyRxFieldEvaluatorLoader
AcFdFieldEvaluator* PyRxFieldEvaluatorLoader::getEvaluator(const ACHAR* pszEvalId)
{
    if (m_evaluators.contains(pszEvalId))
        return m_evaluators.at(pszEvalId);
    return nullptr;
}

AcFdFieldEvaluator* PyRxFieldEvaluatorLoader::findEvaluator(AcDbField* pField, const ACHAR*& pszEvalId)
{
    AcString fcode = pField->getFieldCode(AcDbField::kFieldCode);
    auto pos = fcode.find(' ');
    if (pos > 1)
    {
        pszEvalId = fcode.substr(1, pos - 1);
        if (m_evaluators.contains(pszEvalId))
            return m_evaluators.at(pszEvalId);
    }
    pszEvalId = L"";
    return nullptr;
}

void PyRxFieldEvaluatorLoader::registerEvaluator(const PyDdFieldEvaluator& evaluator)
{
    if (!m_evaluators.contains(evaluator.getEvalNameW()))
        m_evaluators[evaluator.getEvalNameW()] = const_cast<PyDdFieldEvaluator*>(std::addressof(evaluator));
    else
        acutPrintf(_T("Evaluator %ls already loaded"), (const TCHAR*)evaluator.getEvalNameW());
}

void PyRxFieldEvaluatorLoader::unregisterEvaluator(const PyDdFieldEvaluator& evaluator)
{
    if (m_evaluators.contains(evaluator.getEvalNameW()))
        m_evaluators.erase(evaluator.getEvalNameW());
    else
        acutPrintf(_T("Evaluator %ls was never loaded"), (const TCHAR*)evaluator.getEvalNameW());
}

//---------------------------------------------------------------------------------------- -
//PyDbFieldEngine
void makePyDbFieldEngineWrapper()
{
    PyDocString DS("PyDb.FieldEngine");
    class_<PyDbFieldEngine>("FieldEngine", boost::python::no_init)
        .def("registerEvaluator", &PyDbFieldEngine::registerEvaluator, DS.ARGS({ "evaluator:PyDb.FieldEvaluator" }))
        .def("unregisterEvaluator", &PyDbFieldEngine::unregisterEvaluator, DS.ARGS({ "evaluator:PyDb.FieldEvaluator" }))
        .def("evaluatorLoaderCount", &PyDbFieldEngine::evaluatorLoaderCount, DS.ARGS())
        .def("isEvaluatorLoaded", &PyDbFieldEngine::isEvaluatorLoaded, DS.ARGS({ "pszEvalId:str" }))
        .def("evaluationOption", &PyDbFieldEngine::evaluationOption, DS.ARGS())
        .def("setEvaluationOption", &PyDbFieldEngine::setEvaluationOption, DS.ARGS({ "opt:PyDb.FieldEvalOption" }))
        .def("getEngine", &PyDbFieldEngine::getEngine, DS.SARGS(), return_value_policy<reference_existing_object>()).staticmethod("getEngine")
        .def("className", &PyDbFieldEngine::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbFieldEngine::PyDbFieldEngine()
    : mloader(new PyRxFieldEvaluatorLoader())
{
    acdbGetFieldEngine()->registerEvaluatorLoader(mloader.get());
#ifndef _BRXTARGET250
    acdbAddFieldReactor(this);
#endif // !_BRXTARGET250
}

PyDbFieldEngine::~PyDbFieldEngine()
{
    acdbGetFieldEngine()->unregisterEvaluatorLoader(mloader.get());
#ifndef _BRXTARGET250
    acdbRemoveFieldReactor(this);
#endif // !_BRXTARGET250
}

PyDbFieldEngine& PyDbFieldEngine::getEngine()
{
    static PyDbFieldEngine mthis;
    return mthis;
}

void PyDbFieldEngine::registerEvaluator(const PyDdFieldEvaluator& evaluator) const
{
    if (mloader)
        mloader->registerEvaluator(evaluator);
}

void PyDbFieldEngine::unregisterEvaluator(const PyDdFieldEvaluator& evaluator) const
{
    if (mloader)
        mloader->unregisterEvaluator(evaluator);
}

#ifndef _BRXTARGET250
Acad::ErrorStatus PyDbFieldEngine::beginEvaluateFields(int nContext, AcDbDatabase* pDb)
{
    if (mloader)
    {
        PyAutoLockGIL lock;
        PyDbDatabase pydb(pDb);
        for (auto& item : mloader->m_evaluators)
        {
            if (item.second != nullptr && item.second->reg_beginEvaluateFields)
                item.second->beginEvaluateFieldsWr(nContext, pydb);
        }
    }
    return eOk;
}
#endif // !_BRXTARGET250

#ifndef _BRXTARGET250
Acad::ErrorStatus PyDbFieldEngine::endEvaluateFields(int nContext, AcDbDatabase* pDb)
{
    if (mloader)
    {
        PyAutoLockGIL lock;
        PyDbDatabase pydb(pDb);
        for (auto& item : mloader->m_evaluators)
        {
            if (item.second != nullptr && item.second->reg_endEvaluateFields)
                item.second->endEvaluateFieldsWr(nContext, pydb);
        }
    }
    return eOk;
}
#endif // !_BRXTARGET250

int PyDbFieldEngine::evaluatorLoaderCount(void) const
{
    return acdbGetFieldEngine()->evaluatorLoaderCount();
}

bool PyDbFieldEngine::isEvaluatorLoaded(const std::string& pszEvalId)
{
    return acdbGetFieldEngine()->getEvaluator(utf8_to_wstr(pszEvalId).c_str()) != nullptr;
}

AcDbField::EvalOption PyDbFieldEngine::evaluationOption(void) const
{
#if defined(_ZRXTARGET260) || defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acdbGetFieldEngine()->evaluationOption();
#endif
}

void PyDbFieldEngine::setEvaluationOption(AcDbField::EvalOption nEvalOption)
{
#if defined(_ZRXTARGET260) || defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(acdbGetFieldEngine()->setEvaluationOption(nEvalOption));
#endif
}

std::string PyDbFieldEngine::className()
{
    return "AcFdFieldEngine";
}

#ifdef FIELDHOOK
#if defined(_ARXTARGET)

//---------------------------------------------------------------------------------------- -
//PyRxFdUiFieldDialogHook

int PyRxFdUiFieldDialogHook::GetEvaluatorIds(CStringArray& evalIds)
{
    auto& engine = PyDbFieldEngine::getEngine();
    if (engine.mloader)
    {
        for (auto& item : engine.mloader->m_evaluators)
            evalIds.Add(item.first);
    }
    size_t size = evalIds.GetSize();
    ASSERT(size <= INT_MAX);
    return (int)size;
}

BOOL PyRxFdUiFieldDialogHook::BeginFieldDialog(CAcFdUiFieldDialog* pFieldDlg, AcDbDatabase* pDb, int nContext)
{
    CAcFdUiFieldDialogHook::BeginFieldDialog(pFieldDlg, pDb, nContext);
    return TRUE;
}

BOOL PyRxFdUiFieldDialogHook::EndFieldDialog(int nRet)
{
    CAcFdUiFieldDialogHook::EndFieldDialog(nRet);
    return TRUE;
}

BOOL PyRxFdUiFieldDialogHook::SetFieldToEdit(AcDbField* pField)
{
    if (!CAcFdUiFieldDialogHook::SetFieldToEdit(pField))
        return FALSE;
    return TRUE;
}

BOOL PyRxFdUiFieldDialogHook::GetCategoryNames(UINT uMinUnusedCatId, CStringArray& catNames, CUIntArray& catIds)
{
    CAcFdUiFieldDialogHook::GetCategoryNames(uMinUnusedCatId, catNames, catIds);
    return TRUE;
}

BOOL PyRxFdUiFieldDialogHook::GetFieldNames(UINT uCatId, UINT uMinUnusedFieldId, CStringArray& fieldNames, CUIntArray& fieldIds, BOOL& bSort)
{
    //if (uCatId == TFCATID)
    //{
    //    fieldNames.Add(TFFIELDNAME);
    //    fieldIds.Add(TFFIELDID);
    //    bSort = TRUE;
    //}
    return TRUE;
}

void PyRxFdUiFieldDialogHook::registerHook()
{
    AcFdUiGetFieldManager()->RegisterFieldDialogHook(&instance());
}

void PyRxFdUiFieldDialogHook::unRegisterHook()
{
    AcFdUiGetFieldManager()->UnregisterFieldDialogHook(&instance());
}

PyRxFdUiFieldDialogHook& PyRxFdUiFieldDialogHook::instance()
{
    static PyRxFdUiFieldDialogHook mthis;
    return mthis;
}

#endif //_ARXTARGET
#endif //FIELDHOOK