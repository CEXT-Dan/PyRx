#pragma once
#include "PyDbObject.h"
void makePyDbFieldtWrapper();
//---------------------------------------------------------------------------------------- -
//PyDbField
class PyDbField : public PyDbObject
{
public:
    PyDbField();
    PyDbField(const std::string& pszFieldCode);
    PyDbField(const std::string& pszFieldCode, bool bTextField);
    PyDbField(AcDbField* ptr, bool autoDelete);
    PyDbField(const PyDbObjectId& id);
    PyDbField(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbField() override = default;
    void                setInObject(PyDbObject& pObj, const std::string& pszPropName);
    void                postInDatabase(PyDbDatabase& pDb);
    AcDbField::State    state(void) const;
    AcDbField::EvalStatus evaluationStatus() const;
    AcDbField::EvalOption evaluationOption(void) const;
    void                setEvaluationOption(AcDbField::EvalOption nEvalOption);
    std::string         evaluatorId(void) const;
    void                setEvaluatorId(const std::string& pszEvaluatorId);
    bool                isTextField(void) const;
    void                convertToTextField(void);
    int                 childCount(void) const;
    std::string         getFormat(void) const;
    void                setFormat(const std::string& pszFormat);
    std::string         getValue(void) const;
    void                evaluate1();
    void                evaluate2(AcDbField::EvalContext nContext);
    void                evaluate3(AcDbField::EvalContext nContext, PyDbDatabase& db);
    std::string         getFieldCode1(AcDbField::FieldCodeFlag nFlag);
    std::string         getFieldCode2(AcDbField::FieldCodeFlag nFlag, boost::python::list, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbField    cloneFrom(const PyRxObject& src);
    static PyDbField    cast(const PyRxObject& src);
public:
    AcDbField* impObj(const std::source_location& src = std::source_location::current()) const;
};
