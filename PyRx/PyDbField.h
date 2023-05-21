#pragma once
#include "PyDbObject.h"

void makeAcDbFieldtWrapper();
//---------------------------------------------------------------------------------------- -
//PyDbField
class PyDbField : public PyDbObject
{
public:
    PyDbField();
    PyDbField(const std::string& pszFieldCode, bool bTextField);
    PyDbField(AcDbField* ptr, bool autoDelete);
    PyDbField(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbField() override = default;

    Acad::ErrorStatus setInObject(PyDbObject& pObj,const std::string& pszPropName);
    Acad::ErrorStatus postInDatabase(PyDbDatabase& pDb);
    AcDbField::State state(void) const;

    AcDbField::EvalStatus evaluationStatus() const;
    AcDbField::EvalOption evaluationOption(void) const;
    Acad::ErrorStatus setEvaluationOption(AcDbField::EvalOption nEvalOption);

    std::string evaluatorId(void) const;
    Acad::ErrorStatus setEvaluatorId(const std::string& pszEvaluatorId);

    bool            isTextField(void) const;
    Acad::ErrorStatus convertToTextField(void);

    int  childCount(void) const;
    std::string getFormat(void) const;
    Acad::ErrorStatus setFormat(const std::string& pszFormat);

    std::string getValue(void) const;

	Acad::ErrorStatus evaluate1();
    Acad::ErrorStatus evaluate2(AcDbField::EvalContext nContext);
    Acad::ErrorStatus evaluate3(AcDbField::EvalContext nContext, PyDbDatabase& db);

    static std::string className();
    static PyRxClass desc();
public:
    AcDbField* impObj(const std::source_location& src = std::source_location::current()) const;
};

