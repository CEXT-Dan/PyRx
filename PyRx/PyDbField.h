#pragma once
#include "PyDbObject.h"

void makeAcDbFieldtWrapper();
//---------------------------------------------------------------------------------------- -
//PyDbField
class PyDbField : public PyDbObject
{
public:
    enum class State
    {
        kInitialized= AcDbField::State::kInitialized,
        kCompiled= AcDbField::State::kCompiled,
        kModified= AcDbField::State::kModified,
        kEvaluated= AcDbField::State::kEvaluated,
        kHasCache= AcDbField::State::kHasCache,
#ifndef BRXAPP
        kHasFormattedString= AcDbField::State::kHasFormattedString,
#endif // BRXAPP
    };

    enum class EvalOption
    {
        kDisable = AcDbField::EvalOption::kDisable,
        kOnOpen = AcDbField::EvalOption::kOnOpen,
        kOnSave = AcDbField::EvalOption::kOnSave,
        kOnPlot = AcDbField::EvalOption::kOnPlot,
        kOnEtransmit = AcDbField::EvalOption::kOnEtransmit,
        kOnRegen = AcDbField::EvalOption::kOnRegen,
        kOnDemand = AcDbField::EvalOption::kOnDemand,
        kAutomatic = AcDbField::EvalOption::kAutomatic,
    };
        
    enum class EvalContext
    {   
        kOpen= AcDbField::EvalContext::kOpen,
        kSave= AcDbField::EvalContext::kSave,
        kPlot= AcDbField::EvalContext::kPlot,
        kEtransmit= AcDbField::EvalContext::kEtransmit,
        kRegen= AcDbField::EvalContext::kRegen,
        kDemand= AcDbField::EvalContext::kDemand,
        kPreview= AcDbField::EvalContext::kPreview,
        kPlotPreview= AcDbField::EvalContext::kPlotPreview,
    };  

    enum class EvalStatus
    {   
        kNotYetEvaluated= AcDbField::EvalStatus::kNotYetEvaluated,
        kSuccess= AcDbField::EvalStatus::kSuccess,
        kEvaluatorNotFound= AcDbField::EvalStatus::kEvaluatorNotFound,
        kSyntaxError= AcDbField::EvalStatus::kSyntaxError,
        kInvalidCode= AcDbField::EvalStatus::kInvalidCode,
        kInvalidContext= AcDbField::EvalStatus::kInvalidContext,
        kOtherError= AcDbField::EvalStatus::kOtherError,
    };

    enum class FieldCodeFlag
    {
       kFieldCode= AcDbField::FieldCodeFlag::kFieldCode,
       kEvaluatedText= AcDbField::FieldCodeFlag::kEvaluatedText,
       kEvaluatedChildren= AcDbField::FieldCodeFlag::kEvaluatedChildren,
       kObjectReference= AcDbField::FieldCodeFlag::kObjectReference,
       kAddMarkers= AcDbField::FieldCodeFlag::kAddMarkers,
       kEscapeBackslash= AcDbField::FieldCodeFlag::kEscapeBackslash,
       kStripOptions= AcDbField::FieldCodeFlag::kStripOptions,
       kPreserveFields= AcDbField::FieldCodeFlag::kPreserveFields,
       kTextField= AcDbField::FieldCodeFlag::kTextField,
#ifndef BRXAPP
       kPreserveOptions= AcDbField::FieldCodeFlag::kPreserveOptions,
       kDetachChildren= AcDbField::FieldCodeFlag::kDetachChildren,
       kChildObjectReference= AcDbField::FieldCodeFlag::kChildObjectReference,
       kForExpression= AcDbField::FieldCodeFlag::kForExpression,
#endif
    };


public:
    PyDbField();
    PyDbField(const std::string& pszFieldCode, bool bTextField);
    PyDbField(AcDbField* ptr, bool autoDelete);
    PyDbField(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbField() override = default;

    Acad::ErrorStatus setInObject(PyDbObject& pObj,const std::string& pszPropName);
    Acad::ErrorStatus postInDatabase(PyDbDatabase& pDb);
    PyDbField::State state(void) const;

    PyDbField::EvalStatus evaluationStatus() const;
    PyDbField::EvalOption evaluationOption(void) const;
    Acad::ErrorStatus setEvaluationOption(PyDbField::EvalOption nEvalOption);

    std::string evaluatorId(void) const;
    Acad::ErrorStatus setEvaluatorId(const std::string& pszEvaluatorId);

    bool            isTextField(void) const;
    Acad::ErrorStatus convertToTextField(void);

    int  childCount(void) const;
    std::string getFormat(void) const;
    Acad::ErrorStatus setFormat(const std::string& pszFormat);


    std::string getValue(void) const;

    static std::string className();
    static PyRxClass desc();
public:
    AcDbField* impObj(const std::source_location& src = std::source_location::current()) const;
};

