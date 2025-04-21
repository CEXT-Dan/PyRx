#pragma once
#include "PyDbObject.h"

#pragma pack (push, 8)
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
    PyDbField(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbField() override = default;
    void                setInObject(PyDbObject& pObj, const std::string& pszPropName) const;
    void                postInDatabase(PyDbDatabase& pDb) const;
    AcDbField::State    state(void) const;
    AcDbField::EvalStatus evaluationStatus() const;
    AcDbField::EvalOption evaluationOption(void) const;
    void                setEvaluationOption(AcDbField::EvalOption nEvalOption) const;
    std::string         evaluatorId(void) const;
    void                setEvaluatorId(const std::string& pszEvaluatorId) const;
    bool                isTextField(void) const;
    void                convertToTextField(void) const;
    int                 childCount(void) const;
    std::string         getFormat(void) const;
    void                setFormat(const std::string& pszFormat) const;
    std::string         getValue(void) const;

    boost::python::tuple evaluate1() const;
    boost::python::tuple evaluate2(AcDbField::EvalContext nContext) const;
    boost::python::tuple evaluate3(AcDbField::EvalContext nContext, PyDbDatabase& db) const;

    std::string         getFieldCode1(AcDbField::FieldCodeFlag nFlag) const;
    std::string         getFieldCode2(AcDbField::FieldCodeFlag nFlag, const boost::python::list&, AcDb::OpenMode mode) const;

    void                setData(const std::string& key, const std::string& value) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbField    cloneFrom(const PyRxObject& src);
    static PyDbField    cast(const PyRxObject& src);
public:
    AcDbField* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)