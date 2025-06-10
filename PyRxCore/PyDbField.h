#pragma once
#include "PyDbObject.h"

#pragma pack (push, 8)
//---------------------------------------------------------------------------------------- -
//PyDbField
void makePyDbFieldWrapper();

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

//---------------------------------------------------------------------------------------- -
//PyDdFieldEvaluator
void makePyDdFieldEvaluatorWrapper();

class PyDdFieldEvaluator : public AcFdFieldEvaluator, public boost::python::wrapper<PyDdFieldEvaluator>
{
public:
    PyDdFieldEvaluator() = default;
    virtual ~PyDdFieldEvaluator() override = default;

    //virtual const ACHAR* evaluatorId(void) const;
    //virtual const ACHAR* evaluatorId(AcDbField* pField);
    //virtual Acad::ErrorStatus initialize(AcDbField* pField);
    //virtual Acad::ErrorStatus compile(AcDbField* pField, AcDbDatabase* pDb, AcFdFieldResult* pResult);
    //virtual Acad::ErrorStatus evaluate(AcDbField* pField, int nContext, AcDbDatabase* pDb, AcFdFieldResult* pResult);
    //virtual Acad::ErrorStatus format(AcDbField* pField, AcString& sValue);

    static std::string  className();
};


//do these need to be wrapped or have one in pyrx?
//---------------------------------------------------------------------------------------- -
//PyRxFieldEvaluatorLoader
class PyRxFieldEvaluatorLoader : public AcFdFieldEvaluatorLoader
{
public:
    PyRxFieldEvaluatorLoader() = default;
    virtual ~PyRxFieldEvaluatorLoader() override = default;
    //virtual AcFdFieldEvaluator* getEvaluator(const ACHAR* pszEvalId) override;
    //virtual AcFdFieldEvaluator* findEvaluator(AcDbField* pField, const ACHAR*& pszEvalId) override;
    //inline static std::map <AcString, AcFdFieldEvaluator>
public:

    //AcFdFieldEvaluator
    //AcString m_name;// = _T("XLSX File Field");
    //AcString m_evalName;// = _T("XLSXfile");
    //int      m_fieldId;// = 10;
};
//---------------------------------------------------------------------------------------- -
//PyDbFieldEvaluatorLoader
void makePyDbFieldEvaluatorLoaderWrapper();

class PyDbFieldEvaluatorLoader : public AcFdFieldEvaluatorLoader, public boost::python::wrapper<PyDbFieldEvaluatorLoader>
{
public:
    PyDbFieldEvaluatorLoader() = default;
    virtual ~PyDbFieldEvaluatorLoader() override = default;
    //virtual AcFdFieldEvaluator* getEvaluator(const ACHAR* pszEvalId) override;
    //virtual AcFdFieldEvaluator* findEvaluator(AcDbField* pField, const ACHAR*& pszEvalId) override;
    static std::string  className();
};

//---------------------------------------------------------------------------------------- -
//PyDbFieldEngine
void makePyDbFieldEngineWrapper();

class PyDbFieldEngine
{
public:
    PyDbFieldEngine() = default;
    ~PyDbFieldEngine() = default;



    //Acad::ErrorStatus           registerEvaluatorLoader(AcFdFieldEvaluatorLoader* pLoader);
    //Acad::ErrorStatus           unregisterEvaluatorLoader(AcFdFieldEvaluatorLoader* pLoader);
    //int                         evaluatorLoaderCount(void) const;
    //AcFdFieldEvaluatorLoader*   getEvaluatorLoader(int iIndex);
    //AcFdFieldEvaluator*         getEvaluator(const ACHAR* pszEvalId);
    //AcFdFieldEvaluator*         findEvaluator(AcDbField* pField, const ACHAR*& pszEvalId);
    //AcDbField::EvalOption       evaluationOption(void) const;
    //Acad::ErrorStatus           setEvaluationOption(AcDbField::EvalOption nEvalOption);

    static std::string  className();

public:
    AcFdFieldEngine* impObj(const std::source_location& src = std::source_location::current()) const;
    AcFdFieldEngine* pimp = acdbGetFieldEngine();
};

#pragma pack (pop)