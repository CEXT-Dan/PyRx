#pragma once
#include "PyRxObject.h"
#include "PyRxOverrule.h"

class PyGiWorldDraw;
class PyGiViewportDraw;

//-----------------------------------------------------------------------------------------
//PyGiDrawable
void makeAcGiObjectWrapper();

class PyGiDrawable : public PyRxObject
{
public:
    PyGiDrawable(AcGiDrawable* ptr, bool autoDelete, bool isDbObject);
    virtual ~PyGiDrawable() override = default;
    static std::string className();
    static PyRxClass desc();

public:
    AcGiDrawable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGiDrawable
void makeAcGiDrawableOverruleWrapper();

class PyGiDrawableOverrule : public PyRxOverrule, public AcGiDrawableOverrule, public boost::python::wrapper<PyGiDrawableOverrule>
{
public:
	PyGiDrawableOverrule();
	PyGiDrawableOverrule(AcGiDrawableOverrule* ptr, bool autoDelete);
	virtual ~PyGiDrawableOverrule() override = default;

	bool isApplicableWr(PyRxObject& pOverruledSubject) const;
	//Adesk::UInt32 setAttributes(AcGiDrawable* pSubject, AcGiDrawableTraits* traits);
	Adesk::Boolean  worldDrawWr(PyGiDrawable& pSubject, PyGiWorldDraw& wd);
	void            viewportDrawWr(PyGiDrawable& pSubject, PyGiViewportDraw& vd);
	Adesk::UInt32   viewportDrawLogicalFlagsWr(PyGiDrawable& pSubject, PyGiViewportDraw& vd);



	Adesk::Boolean baseWorldDraw(PyGiDrawable& pSubject, PyGiWorldDraw& wd);

	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const override;
	virtual Adesk::Boolean  worldDraw(AcGiDrawable* pSubject, AcGiWorldDraw* wd) override;

	static std::string className();
	static PyRxClass desc();

public:
	AcGiDrawableOverrule* impObj(const std::source_location& src = std::source_location::current()) const;
};