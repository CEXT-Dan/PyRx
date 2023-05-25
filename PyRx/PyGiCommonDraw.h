#pragma once
#include "PyRxObject.h"
#include "PyGiCommonDraw.h"

class PyGiDrawable;
class PyGiWorldGeometry;
class PyGiViewportGeometry;

//-----------------------------------------------------------------------------------------
//PyGiCommonDraw
void makePyGiCommonDrawWrapper();

class PyGiCommonDraw : public PyRxObject
{
public:
    PyGiCommonDraw(AcGiCommonDraw* ptr, bool autoDelete);
    virtual ~PyGiCommonDraw() override = default;
public:
    static std::string  className();
    static PyRxClass    desc();
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
    PyGiWorldGeometry   geometry() const;
    static std::string  className();
    static PyRxClass    desc();
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
    PyGiViewportGeometry geometry() const;
    static std::string  className();
    static PyRxClass    desc();
public:
    AcGiViewportDraw* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PyGiGeometry
void makeAcGiGeometryWrapper();

class PyGiGeometry : public PyRxObject
{
public:
    PyGiGeometry(AcGiGeometry* ptr, bool autoDelete);
    virtual ~PyGiGeometry() override = default;
public:
    AcGeMatrix3d		getModelToWorldTransform() const;
    AcGeMatrix3d		getWorldToModelTransform() const;
    Adesk::Boolean		pushModelTransform1(const AcGeVector3d& vNormal);
    Adesk::Boolean		pushModelTransform2(const AcGeMatrix3d& xMat);
    Adesk::Boolean		popModelTransform();
    Adesk::Boolean		draw(PyGiDrawable& drawable);
    static std::string	className();
    static PyRxClass	desc();
public:
    AcGiGeometry* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGiWorldGeometry
void makeAcGiWorldGeometryWrapper();

class PyGiWorldGeometry : public PyGiGeometry
{
public:
    PyGiWorldGeometry(AcGiWorldGeometry* ptr, bool autoDelete);
    virtual ~PyGiWorldGeometry() override = default;
public:
    static std::string className();
    static PyRxClass    desc();
public:
    AcGiWorldGeometry* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGiViewportGeometry
void makeAcGiViewportGeometryWrapper();

class PyGiViewportGeometry : public PyGiGeometry
{
public:
    PyGiViewportGeometry(AcGiViewportGeometry* ptr, bool autoDelete);
    virtual ~PyGiViewportGeometry() override = default;
public:
    static std::string  className();
    static PyRxClass    desc();
public:
    AcGiViewportGeometry* impObj(const std::source_location& src = std::source_location::current()) const;
};











