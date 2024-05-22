#pragma once
#pragma pack (push, 8)
#include "PyRxObject.h"

//-----------------------------------------------------------------------------------------
//PyRxOverruleBase
void makePyRxOverruleWrapper();

class PyRxOverrule :public PyRxObject
{
public:
	PyRxOverrule(AcRxOverrule* ptr);
	virtual ~PyRxOverrule() override = default;
public:
	static void addOverrule1(PyRxClass& pClass, PyRxOverrule& pOverrule);
	static void addOverrule2(PyRxClass& pClass, PyRxOverrule& pOverrule, bool bAddAtLast);
	static void removeOverrule(PyRxClass& pClass, PyRxOverrule& pOverrule);
	static void setIsOverruling(bool bIsOverruling);
	static bool isOverruling(void);
	static bool hasOverrule(PyRxObject& pSubject, PyRxClass& pOverruleClass);
	static std::string className();
	static PyRxClass desc();
public:
	AcRxOverrule* impObj(const std::source_location & src = std::source_location::current()) const;
};
#pragma pack (pop)
