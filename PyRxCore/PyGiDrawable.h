#pragma once
#include "PyRxObject.h"
#include "PyRxOverrule.h"

#pragma pack (push, 8)
class PyGiWorldDraw;
class PyGiViewportDraw;
class PyGiDrawableTraits;
class PyDbObjectId;
//-----------------------------------------------------------------------------------------
//PyGiDrawable
void makePyGiObjectWrapper();

class PyGiDrawable : public PyRxObject
{
public:
    PyGiDrawable(AcGiDrawable* ptr, bool autoDelete, bool isDbObject);
    inline virtual ~PyGiDrawable() override = default;
    Adesk::UInt32   setAttributes(PyGiDrawableTraits& traits) const;
    Adesk::Boolean  worldDraw(PyGiWorldDraw& wd) const;
    void            viewportDraw(PyGiViewportDraw& vd) const;
    Adesk::UInt32   viewportDrawLogicalFlags(PyGiViewportDraw& vd) const;
    Adesk::Boolean  isPersistent(void) const;
    PyDbObjectId    id(void) const;
    AcGiDrawable::DrawableType	drawableType(void) const;
    Adesk::Boolean  rolloverHit(Adesk::ULongPtr nSubentId, Adesk::ULongPtr nMouseFlags, Adesk::Boolean  bReset) const;
    bool			bounds(AcDbExtents& ext) const;
    static std::string	className();
    static PyRxClass	desc();
    static PyGiDrawable cast(const PyRxObject& src);
public:
    AcGiDrawable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGiDrawableOverrule
void makePyGiDrawableOverruleWrapper();

class PyGiDrawableOverrule : public PyRxOverrule, public AcGiDrawableOverrule, public boost::python::wrapper<PyGiDrawableOverrule>
{
public:
    PyGiDrawableOverrule();
    virtual ~PyGiDrawableOverrule() override = default;
#ifdef _BRXTARGET_COPY_CTOR
    PyGiDrawableOverrule(const PyGiDrawableOverrule&);
#endif

    Adesk::UInt32	setAttributes(PyGiDrawable& pSubject, PyGiDrawableTraits& traits) const;

    //python subclasses these
    bool		    isApplicableWr(PyRxObject& pOverruledSubject) const;
    Adesk::Boolean  worldDrawWr(PyGiDrawable& pSubject, PyGiWorldDraw& wd);
    void            viewportDrawWr(PyGiDrawable& pSubject, PyGiViewportDraw& vd);
    Adesk::UInt32   viewportDrawLogicalFlagsWr(PyGiDrawable& pSubject, PyGiViewportDraw& vd);

    //python can call these to access the true base classes
    Adesk::Boolean	baseWorldDraw(PyGiDrawable& pSubject, PyGiWorldDraw& wd);
    void            baseViewportDraw(PyGiDrawable& pSubject, PyGiViewportDraw& vd);
    Adesk::UInt32   baseViewportDrawLogicalFlags(PyGiDrawable& pSubject, PyGiViewportDraw& vd);

    //these call into their wrapper 'Wr' counterparts
    virtual bool            isApplicable(const AcRxObject* pOverruledSubject) const override;
    virtual Adesk::Boolean	worldDraw(AcGiDrawable* pSubject, AcGiWorldDraw* wd) override;
    virtual void            viewportDraw(AcGiDrawable* pSubject, AcGiViewportDraw* vd) override;
    virtual Adesk::UInt32   viewportDrawLogicalFlags(AcGiDrawable* pSubject, AcGiViewportDraw* vd);

    static std::string className();
    static PyRxClass desc();

public:
    AcGiDrawableOverrule* impObj(const std::source_location& src = std::source_location::current()) const;

private:
#ifdef BRXAPP
    inline static std::mutex PyGiDrawableOverruleMutex;
#endif // BRXAPP
    mutable bool isApplicableOverride = true;
    mutable bool isWorldDrawOverride = true;
    mutable bool isViewportDrawOverride = true;
    mutable bool isViewportDrawLogicalFlagsOverride = true;
};
#pragma pack (pop)