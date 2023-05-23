#pragma once
#include "PyRxObject.h"
#include "PyGiCommonDraw.h"

class PyGiDrawable;

//-----------------------------------------------------------------------------------------
//PyGiCommonDraw
void makePyGiCommonDrawWrapper();

class PyGiCommonDraw : public PyRxObject
{
public:
	PyGiCommonDraw(AcGiCommonDraw* ptr, bool autoDelete);
	virtual ~PyGiCommonDraw() override = default;
public:
	static std::string className();
	static PyRxClass desc();
public:
	AcGiCommonDraw* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGiWorldDraw 
void makePyGiWorldDrawWrapper();

class PyGiWorldDraw : public PyGiCommonDraw
{
public:
	PyGiWorldDraw(AcGiWorldDraw* ptr, bool autoDelete);
	virtual ~PyGiWorldDraw() override = default;
public:
	bool draw(PyGiDrawable& drawable);
	static std::string className();
	static PyRxClass desc();
public:
	AcGiWorldDraw* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PyGiViewportDraw
void makeAcGiViewportDrawWrapper();

class PyGiViewportDraw : public PyGiCommonDraw
{
public:
	PyGiViewportDraw(AcGiViewportDraw* ptr, bool autoDelete);
	virtual ~PyGiViewportDraw() override = default;
public:
	bool draw(PyGiDrawable& drawable);
	static std::string className();
	static PyRxClass desc();
public:
	AcGiViewportDraw* impObj(const std::source_location& src = std::source_location::current()) const;
};




