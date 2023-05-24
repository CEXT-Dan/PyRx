#pragma once
#include "PyRxObject.h"

//-----------------------------------------------------------------------------------------
//PyRxOverruleBase
void makePyRxOverruleWrapper();

class PyRxOverrule :public PyRxObject
{
public:
	PyRxOverrule(AcRxOverrule* ptr, bool autoDelete);
	virtual ~PyRxOverrule() override = default;
public:
	static Acad::ErrorStatus addOverrule1(PyRxClass& pClass, PyRxOverrule& pOverrule);
	static Acad::ErrorStatus addOverrule2(PyRxClass& pClass, PyRxOverrule& pOverrule, bool bAddAtLast);
	static Acad::ErrorStatus removeOverrule(PyRxClass& pClass, PyRxOverrule& pOverrule);
	static void setIsOverruling(bool bIsOverruling);
	static bool isOverruling(void);
	static bool hasOverrule(PyRxObject& pSubject, PyRxClass& pOverruleClass);
	static std::string className();
	static PyRxClass desc();
public:
	AcRxOverrule* impObj(const std::source_location & src = std::source_location::current()) const;
};

