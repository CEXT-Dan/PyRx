#pragma once

#include "PyRxObject.h"
#include "PyRxOverrule.h"
#include "dbobjectoverrule.h"

#ifdef PYRXDEBUG

class PyDbObjectId;
class PyDbDimension;
class PyDbDimStyleTableRecord;
class PyDbObjectOverrule;

class PyDbObjectOverrule : public PyRxOverrule, public AcDbObjectOverrule, public boost::python::wrapper<PyDbObjectOverrule>
{
public:
    explicit PyDbObjectOverrule();
    virtual ~PyDbObjectOverrule() override = default;

    virtual bool			    isApplicable(const AcRxObject* pOverruledSubject) const override;
    virtual Acad::ErrorStatus   open(AcDbObject* pSubject, AcDb::OpenMode mode) override;
    virtual Acad::ErrorStatus   close(AcDbObject* pSubject) override;
    virtual Acad::ErrorStatus   cancel(AcDbObject* pSubject) override;
    virtual Acad::ErrorStatus   erase(AcDbObject* pSubject, Adesk::Boolean erasing) override;
    virtual Acad::ErrorStatus   deepClone(const AcDbObject* pSubject,AcDbObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary) override;
    virtual Acad::ErrorStatus   wblockClone(const AcDbObject* pSubject, AcRxObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary) override;


    bool			    isApplicableWr(const AcRxObject* pOverruledSubject) const;
    Acad::ErrorStatus   openWr(AcDbObject* pSubject, AcDb::OpenMode mode);
    Acad::ErrorStatus   closeWr(AcDbObject* pSubject);
    Acad::ErrorStatus   cancelWr(AcDbObject* pSubject);
    Acad::ErrorStatus   eraseWr(AcDbObject* pSubject, Adesk::Boolean erasing);
    Acad::ErrorStatus   deepCloneWr(const AcDbObject* pSubject, AcDbObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary);
    Acad::ErrorStatus   wblockCloneWr(const AcDbObject* pSubject, AcRxObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary);

    Acad::ErrorStatus   baseOpen(AcDbObject* pSubject, AcDb::OpenMode mode);
    Acad::ErrorStatus   baseClose(AcDbObject* pSubject);
    Acad::ErrorStatus   baseCancel(AcDbObject* pSubject);
    Acad::ErrorStatus   baseErase(AcDbObject* pSubject, Adesk::Boolean erasing);
    Acad::ErrorStatus   baseDeepClone(const AcDbObject* pSubject, AcDbObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary);
    Acad::ErrorStatus   baseWblockClone(const AcDbObject* pSubject, AcRxObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary);

public:
    AcDbObjectOverrule* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    mutable bool reg_isApplicable = true;
    mutable bool reg_open = true;
    mutable bool reg_close = true;
    mutable bool reg_cancel = true;
    mutable bool reg_erase = true;
    mutable bool reg_deepClone = true;
    mutable bool reg_wblockClone = true;
};

#endif
