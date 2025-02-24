#pragma once
#include "PyAcadEntity.h"

//----------------------------------------------------------------------------------------
//PyAcadDimension
void makePyAcadDimensionWrapper();

class PyAcadDimension : public PyAcadEntity
{
public:
    PyAcadDimension() = default;
    PyAcadDimension(std::shared_ptr<PyIAcadDimensionImpl> ptr);
    virtual ~PyAcadDimension() override = default;
    static PyAcadDimension cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimensionImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimAligned
void makePyAcadDimAlignedWrapper();

class PyAcadDimAligned : public PyAcadDimension
{
public:
    PyAcadDimAligned() = default;
    PyAcadDimAligned(std::shared_ptr<PyIAcadDimAlignedImpl> ptr);
    virtual ~PyAcadDimAligned() override = default;
    static PyAcadDimAligned cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimAlignedImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimAngular
void makePyAcadDimAngularWrapper();

class PyAcadDimAngular : public PyAcadDimension
{
public:
    PyAcadDimAngular() = default;
    PyAcadDimAngular(std::shared_ptr<PyIAcadDimAngularImpl> ptr);
    virtual ~PyAcadDimAngular() override = default;
    static PyAcadDimAngular cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimAngularImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimDiametric
void makePyAcadDimDiametricWrapper();

class PyAcadDimDiametric : public PyAcadDimension
{
public:
    PyAcadDimDiametric() = default;
    PyAcadDimDiametric(std::shared_ptr<PyIAcadDimDiametricImpl> ptr);
    virtual ~PyAcadDimDiametric() override = default;
    static PyAcadDimDiametric cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimDiametricImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRotated
void makePyAcadDimRotatedWrapper();

class PyAcadDimRotated : public PyAcadDimension
{
public:
    PyAcadDimRotated() = default;
    PyAcadDimRotated(std::shared_ptr<PyIAcadDimRotatedImpl> ptr);
    virtual ~PyAcadDimRotated() override = default;
    static PyAcadDimRotated cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRotatedImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimOrdinate
void makePyAcadDimOrdinateWrapper();

class PyAcadDimOrdinate : public PyAcadDimension
{
public:
    PyAcadDimOrdinate() = default;
    PyAcadDimOrdinate(std::shared_ptr<PyIAcadDimOrdinateImpl> ptr);
    virtual ~PyAcadDimOrdinate() override = default;
    static PyAcadDimOrdinate cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimOrdinateImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRadial
void makePyAcadDimRadialWrapper();

class PyAcadDimRadial : public PyAcadDimension
{
public:
    PyAcadDimRadial() = default;
    PyAcadDimRadial(std::shared_ptr<PyIAcadDimRadialImpl> ptr);
    virtual ~PyAcadDimRadial() override = default;
    static PyAcadDimRadial cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRadialImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDim3PointAngular
void makePyAcadDim3PointAngularWrapper();

class PyAcadDim3PointAngular : public PyAcadDimension
{
public:
    PyAcadDim3PointAngular() = default;
    PyAcadDim3PointAngular(std::shared_ptr<PyIAcadDim3PointAngularImpl> ptr);
    virtual ~PyAcadDim3PointAngular() override = default;
    static PyAcadDim3PointAngular cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDim3PointAngularImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimArcLength
void makePyAcadDimArcLengthWrapper();

class PyAcadDimArcLength : public PyAcadDimension
{
public:
    PyAcadDimArcLength() = default;
    PyAcadDimArcLength(std::shared_ptr<PyIAcadDimArcLengthImpl> ptr);
    virtual ~PyAcadDimArcLength() override = default;
    static PyAcadDimArcLength cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimArcLengthImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRadialLarge
void makePyAcadDimRadialLargeWrapper();

class PyAcadDimRadialLarge : public PyAcadDimension
{
public:
    PyAcadDimRadialLarge() = default;
    PyAcadDimRadialLarge(std::shared_ptr<PyIAcadDimRadialLargeImpl> ptr);
    virtual ~PyAcadDimRadialLarge() override = default;
    static PyAcadDimRadialLarge cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRadialLargeImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};