#pragma once

#include "PyRxObject.h"
#include "PyRxOverrule.h"

#ifdef PYRXDEBUG

class PyDbObjectId;
class PyDbDimension;
class PyDbDimStyleTableRecord;
class PyDbDimensionStyleOverrule;

class PyDbDimensionStyleOverrule : public PyRxOverrule, public AcDbDimensionStyleOverrule, public boost::python::wrapper<PyDbDimensionStyleOverrule>
{
public:
    explicit PyDbDimensionStyleOverrule();
    virtual ~PyDbDimensionStyleOverrule() override = default;
    virtual bool			    isApplicable(const AcRxObject* pOverruledSubject) const override;
    virtual AcDbObjectId        dimensionStyle(const AcDbDimension* pSubject) override;
    virtual Acad::ErrorStatus   setDimensionStyle(AcDbDimension* pSubject, AcDbObjectId dimStyleId) override;
    virtual Acad::ErrorStatus   getDimstyleData(const AcDbDimension* pSubject, AcDbDimStyleTableRecord*& pRecord) override;
    virtual Acad::ErrorStatus   setDimstyleData(AcDbDimension* pSubject, AcDbDimStyleTableRecord* pRecord) override;
    virtual Acad::ErrorStatus   setDimstyleData(AcDbDimension* pSubject, AcDbObjectId dimstyleId) override;

public:
    PyDbDimensionStyleOverrule* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    mutable bool reg_isApplicable = true;
    mutable bool reg_dimensionStyle = true;
    mutable bool reg_setDimensionStyle = true;
    mutable bool reg_getDimstyleData = true;
    mutable bool reg_setDimstyleData = true;
    mutable bool reg_setDimstyleDataId = true;
};



#endif
