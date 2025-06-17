#pragma once
#include "PyDbObject.h"

#pragma pack (push, 8)
class PyDbAcValue;

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
    void                    setInObject(PyDbObject& pObj, const std::string& pszPropName) const;
    void                    postInDatabase(PyDbDatabase& pDb) const;
    AcDbField::State        state(void) const;
    AcDbField::EvalStatus   evaluationStatus() const;
    AcDbField::EvalOption   evaluationOption(void) const;
    void                    setEvaluationOption(AcDbField::EvalOption nEvalOption) const;
    std::string             evaluatorId(void) const;
    void                    setEvaluatorId(const std::string& pszEvaluatorId) const;
    bool                    isTextField(void) const;
    void                    convertToTextField(void) const;
    int                     childCount(void) const;
    PyDbField               getChild(int, AcDb::OpenMode mode) const;

    std::string             getFormat(void) const;
    void                    setFormat(const std::string& pszFormat) const;
    std::string             getValue(void) const;

    boost::python::tuple    evaluate1() const;
    boost::python::tuple    evaluate2(AcDbField::EvalContext nContext) const;
    boost::python::tuple    evaluate3(AcDbField::EvalContext nContext, PyDbDatabase& db) const;

    std::string             getFieldCode1(AcDbField::FieldCodeFlag nFlag) const;
    std::string             getFieldCode2(AcDbField::FieldCodeFlag nFlag, const boost::python::list&, AcDb::OpenMode mode) const;

    void                    setData1(const std::string& key, const PyDbAcValue& value) const;
    void                    setData2(const std::string& key, const PyDbAcValue& value, bool bRecursive) const;
    PyDbAcValue             getData(const std::string& key) const;
    bool                    hasData(const std::string& key) const;

    static std::string      className();
    static PyRxClass        desc();
    static PyDbField        cloneFrom(const PyRxObject& src);
    static PyDbField        cast(const PyRxObject& src);
public:
    AcDbField* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDdFieldEvaluator
void makePyDdFieldEvaluatorWrapper();

class PyDdFieldEvaluator : public AcFdFieldEvaluator, public boost::python::wrapper<PyDdFieldEvaluator>
{
public:
    PyDdFieldEvaluator(const std::string& name, const std::string& evalName);
    virtual ~PyDdFieldEvaluator() override = default;

    virtual const ACHAR*            evaluatorId(void) const override;
    virtual const ACHAR*            evaluatorId(AcDbField* pField) override;

    virtual Acad::ErrorStatus       initialize(AcDbField* pField) override;
    virtual Acad::ErrorStatus       initializeWr(const PyDbField& pField);

    virtual Acad::ErrorStatus       compile(AcDbField* pField, AcDbDatabase* pDb, AcFdFieldResult* pResult) override;
    virtual AcDbField::EvalStatus   compileWr(const PyDbField& pField, const PyDbDatabase& pDb, PyDbAcValue& pResult);

    virtual Acad::ErrorStatus       evaluate(AcDbField* pField, int nContext, AcDbDatabase* pDb, AcFdFieldResult* pResult) override;
    virtual AcDbField::EvalStatus   evaluateWr(const PyDbField& pField, int nContext, const PyDbDatabase& pDb, PyDbAcValue& pResult);

    virtual Acad::ErrorStatus       format(AcDbField* pField, AcString& sValue) override;
    virtual std::string             formatWr(const PyDbField& pField);

    virtual void                    beginEvaluateFieldsWr(int nContext, const PyDbDatabase& pDb);
    virtual void                    endEvaluateFieldsWr(int nContext, const PyDbDatabase& pDb);

    std::string                     getName() const { return wstr_to_utf8(getNameW()); }
    std::string                     getEvalName() const { return wstr_to_utf8(getEvalNameW()); }

    AcString                        getNameW() const { return m_name; }
    AcString                        getEvalNameW() const { return m_evalName; }

    static std::string              className();

public:
    AcString m_name;
    AcString m_evalName;
    bool reg_evaluate = true;
    bool reg_beginEvaluateFields = true;
    bool reg_endEvaluateFields = true;
    bool reg_initialize = true;
    bool reg_compile = true;
    bool reg_format = true;
};

//---------------------------------------------------------------------------------------- -
//PyRxFieldEvaluatorLoader
class PyRxFieldEvaluatorLoader : public AcFdFieldEvaluatorLoader
{
public:
    PyRxFieldEvaluatorLoader() = default;
    virtual ~PyRxFieldEvaluatorLoader() override = default;
    virtual AcFdFieldEvaluator* getEvaluator(const ACHAR* pszEvalId) override;
    virtual AcFdFieldEvaluator* findEvaluator(AcDbField* pField, const ACHAR*& pszEvalId) override;

    void registerEvaluator(const PyDdFieldEvaluator& evaluator);
    void unregisterEvaluator(const PyDdFieldEvaluator& evaluator);

public:
    std::map <AcString, PyDdFieldEvaluator*> m_evaluators;
};

//---------------------------------------------------------------------------------------- -
//PyDbFieldEngine
void makePyDbFieldEngineWrapper();

#ifdef _BRXTARGET250
class PyDbFieldEngine
#else
class PyDbFieldEngine : public AcFdFieldReactor
#endif // !_BRXTARGET250
{
    PyDbFieldEngine();
public:
    ~PyDbFieldEngine();

    void                        registerEvaluator(const PyDdFieldEvaluator& evaluator) const;
    void                        unregisterEvaluator(const PyDdFieldEvaluator& evaluator) const;

#ifndef _BRXTARGET250
    virtual Acad::ErrorStatus   beginEvaluateFields(int nContext, AcDbDatabase* pDb) override;
    virtual Acad::ErrorStatus   endEvaluateFields(int nContext, AcDbDatabase* pDb) override;
#endif // !_BRXTARGET250

    int                         evaluatorLoaderCount(void) const;
    bool                        isEvaluatorLoaded(const std::string& pszEvalId);
    AcDbField::EvalOption       evaluationOption(void) const;
    void                        setEvaluationOption(AcDbField::EvalOption nEvalOption);

    static PyDbFieldEngine&     getEngine();
    static std::string          className();
public:
    AcFdFieldEngine* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PyRxFieldEvaluatorLoader> mloader;
};

//#define FIELDHOOK 1

#ifdef FIELDHOOK
#if defined(_ARXTARGET)

class PyDbFieldDialogHook
{
    //callbacks
};

//---------------------------------------------------------------------------------------- -
//PyRxFdUiFieldDialogHook
class PyRxFdUiFieldDialogHook : public CAcFdUiFieldDialogHook
{
public:
    PyRxFdUiFieldDialogHook(void) = default;
    virtual ~PyRxFdUiFieldDialogHook(void) override = default;

    virtual int     GetEvaluatorIds(CStringArray& evalIds) override;
    virtual BOOL    BeginFieldDialog(CAcFdUiFieldDialog* pFieldDlg, AcDbDatabase* pDb, int nContext) override;
    virtual BOOL    EndFieldDialog(int nRet) override;
    virtual BOOL    SetFieldToEdit(AcDbField* pField) override;
    // 
    virtual BOOL    GetCategoryNames(UINT uMinUnusedCatId, CStringArray& catNames, CUIntArray& catIds) override;
    virtual BOOL    GetFieldNames(UINT uCatId, UINT uMinUnusedFieldId, CStringArray& fieldNames, CUIntArray& fieldIds, BOOL& bSort) override;
    // 
    //virtual BOOL    GetOptionDialog(UINT uFieldId, CAcFdUiFieldOptionDialog*& pOptionDlg) override;
    //virtual CString GetPreview(LPCTSTR pszFormatType, LPCTSTR pszFormat) override;
    //virtual BOOL    UpdateFieldCode(void) override;
    //virtual BOOL    OnFieldSelected(UINT uFieldId) override;
    //virtual BOOL    CreateField(UINT uFieldId, AcDbField*& pField)override;

    static  void    registerHook(std::string name, PyDbFieldDialogHook& hook, wxPanel* panel);
    static  void    registerInternalHook();
    static  void    unRegisterInternalHook();
    static PyRxFdUiFieldDialogHook& instance();

private:

    std::map<int, AcString> m_catid_evalid;//?
    std::map<AcString, int> m_evalid_catid;//?

};

class PyRxFieldOptionDialog : public CAcFdUiFieldOptionDialog
{
    friend PyRxFdUiFieldDialogHook;

    DECLARE_DYNAMIC(PyRxFieldOptionDialog)

public:
    PyRxFieldOptionDialog(CAcFdUiFieldDialogHook* pDialogHook, CAcFdUiFieldDialog* pFieldDlg);
    virtual ~PyRxFieldOptionDialog();

    enum { IDD = 200 };

    CAcFdUiFieldDialogHook* GetFieldDialogHook(void) const;
    CAcFdUiFieldDialog*/* */GetFieldDialog(void) const;

    virtual LRESULT         OnInitDialog(WPARAM, LPARAM);
    virtual BOOL	        Create(CWnd* pParent)override;

    virtual BOOL            OnSetActive(void);
    virtual BOOL            OnKillActive(void);
    virtual BOOL            OnFieldSelected(UINT uNewFieldId);

    BOOL			        SetFieldToEdit(AcDbField* pDbField);
    BOOL			        UpdateFieldCode(void);

    void                    OnOK() override;
    void                    OnCancel() override;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

};


#endif //_ARXTARGET
#endif //FIELDHOOK


#pragma pack (pop)
