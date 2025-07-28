#pragma once
#if defined(_BRXTARGET) && (_BRXTARGET == 260)
#include "BrxCvDbAttribVariant.h"

//-----------------------------------------------------------------------------------
//BrxCvDbAttribVariant
void makePyBrxCvDbAttribVariantWrapper();

class PyBrxCvAttribVariant
{
public:
    PyBrxCvAttribVariant();
    PyBrxCvAttribVariant(const BrxCvAttribVariant& other);
    PyBrxCvAttribVariant(const std::string& val);
    PyBrxCvAttribVariant(BrxCvDataType val);

    bool            isValid() const;
    BrxCvDataType   type() const;
    double          getDouble() const;
    double          getLinear() const;
    double          getStation() const;
    double          getAngle() const;
    double          getRatio() const;
    double          getArea() const;
    double          getAzimuth() const;
    double          getDirection() const;
    double          getDistance() const;
    double          getElevation() const;
    double          getSlope() const;
    double          getLatitude() const;
    double          getLongitude() const;
    double          getRotation() const;
    double          getVolume() const;
    double          getSpeed() const;
    bool            getBool() const;
    std::string     getString() const;
    Adesk::Int64    getInteger() const;
    //AcDbDate getDate() const;

    void            setLinear(double value);
    void            setStation(double value);
    void            setAngle(double value);
    void            setRatio(double value);
    void            setArea(double value);
    void            setAzimuth(double value);
    void            setDirection(double value);
    void            setDistance(double value);
    void            setElevation(double value);
    void            setSlope(double value);
    void            setLatitude(double value);
    void            setLongitude(double value);
    void            setRotation(double value);
    void            setVolume(double value);
    void            setSpeed(double value);
    void            setBool(bool value);
    void            setString(const std::string& value);
    void            setInteger(Adesk::Int64 value);
    //void setDate(const AcDbDate& value);

    static std::string        className();

public:
    BrxCvAttribVariant impl;
};

#endif