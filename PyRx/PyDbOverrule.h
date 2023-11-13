#pragma once

#include "PyRxObject.h"
#include "PyRxOverrule.h"

#ifdef PYRXDEBUG

class PyDbObjectId;
class PyDbDimension;
class PyDbDimStyleTableRecord;
class PyDbDimensionStyleOverrule;

class PyDbDimensionStyleOverruleImpl : public AcDbDimensionStyleOverrule
{
public:
    explicit PyDbDimensionStyleOverruleImpl(PyDbDimensionStyleOverrule* backPtr);
    virtual bool			    isApplicable(const AcRxObject* pOverruledSubject) const override;
    virtual AcDbObjectId        dimensionStyle(const AcDbDimension* pSubject) override;
    virtual Acad::ErrorStatus   setDimensionStyle(AcDbDimension* pSubject, AcDbObjectId dimStyleId) override;
    virtual Acad::ErrorStatus   getDimstyleData(const AcDbDimension* pSubject, AcDbDimStyleTableRecord*& pRecord) override;
    virtual Acad::ErrorStatus   setDimstyleData(AcDbDimension* pSubject, AcDbDimStyleTableRecord* pRecord) override;
    virtual Acad::ErrorStatus   setDimstyleData(AcDbDimension* pSubject, AcDbObjectId dimstyleId) override;

public:
    PyDbDimensionStyleOverrule* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    PyDbDimensionStyleOverrule* m_backPtr = nullptr;
};


class PyDbDimensionStyleOverrule : public PyRxOverrule, public boost::python::wrapper<PyDbDimensionStyleOverrule>
{
public:
    PyDbDimensionStyleOverrule();
    PyDbDimensionStyleOverrule(PyDbDimensionStyleOverruleImpl* ptr, bool autoDelete);
    virtual ~PyDbDimensionStyleOverrule() override = default;

    bool			         isApplicable(PyRxObject& pOverruledSubject) const;
    PyDbObjectId             dimensionStyle(PyDbDimension& pSubject);
    void                     setDimensionStyle(PyDbDimension& pSubject, const PyDbObjectId& dimStyleId);
    PyDbDimStyleTableRecord  getDimstyleData(const PyDbDimension& pSubject);
    void                     setDimstyleData(PyDbDimension& pSubject, const PyDbDimStyleTableRecord& pRecord);
    void                     setDimstyleDataId(PyDbDimension& pSubject, const PyDbObjectId& dimstyleId);

public:
    PyDbDimensionStyleOverruleImpl* impObj(const std::source_location& src = std::source_location::current());

public:
    mutable bool reg_isApplicableOverride = true;
    mutable bool reg_dimensionStyle = true;
    mutable bool reg_setDimensionStyle = true;
    mutable bool reg_getDimstyleData = true;
    mutable bool reg_setDimstyleData = true;
    mutable bool reg_setDimstyleDataId = true;
};

#endif
