#include "stdafx.h"
#include "PyBrxCvAttribVariant.h"
#if defined(_BRXTARGET) && (_BRXTARGET == 260)

using namespace boost::python;

void makePyBrxCvDbAttribVariantWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- val: str\n"
        "- val: PyBrxCv.CvDataType\n";

    PyDocString DS("CvAttribVariant");
    class_<PyBrxCvAttribVariant>("CvAttribVariant")
        .def(init<>())
        .def(init<BrxCvDataType>())
        .def(init<const std::string&>(DS.CTOR(ctor)))
        .def("isValid", &PyBrxCvAttribVariant::isValid, DS.ARGS())
        .def("type", &PyBrxCvAttribVariant::type, DS.ARGS())
        .def("getDouble", &PyBrxCvAttribVariant::getDouble, DS.ARGS())
        .def("getLinear", &PyBrxCvAttribVariant::getLinear, DS.ARGS())
        .def("getStation", &PyBrxCvAttribVariant::getStation, DS.ARGS())
        .def("getAngle", &PyBrxCvAttribVariant::getAngle, DS.ARGS())
        .def("getRatio", &PyBrxCvAttribVariant::getRatio, DS.ARGS())
        .def("getArea", &PyBrxCvAttribVariant::getArea, DS.ARGS())
        .def("getAzimuth", &PyBrxCvAttribVariant::getAzimuth, DS.ARGS())
        .def("getDirection", &PyBrxCvAttribVariant::getDirection, DS.ARGS())
        .def("getDistance", &PyBrxCvAttribVariant::getDistance, DS.ARGS())
        .def("getElevation", &PyBrxCvAttribVariant::getElevation, DS.ARGS())
        .def("getSlope", &PyBrxCvAttribVariant::getSlope, DS.ARGS())
        .def("getLatitude", &PyBrxCvAttribVariant::getLatitude, DS.ARGS())
        .def("getLongitude", &PyBrxCvAttribVariant::getLongitude, DS.ARGS())
        .def("getRotation", &PyBrxCvAttribVariant::getRotation, DS.ARGS())
        .def("getVolume", &PyBrxCvAttribVariant::getVolume, DS.ARGS())
        .def("getSpeed", &PyBrxCvAttribVariant::getSpeed, DS.ARGS())
        .def("getBool", &PyBrxCvAttribVariant::getBool, DS.ARGS())
        .def("getString", &PyBrxCvAttribVariant::getString, DS.ARGS())
        .def("getInteger", &PyBrxCvAttribVariant::getInteger, DS.ARGS())
        .def("setLinear", &PyBrxCvAttribVariant::setLinear, DS.ARGS({"val : float"}))
        .def("setStation", &PyBrxCvAttribVariant::setStation, DS.ARGS({ "val : float" }))
        .def("setAngle", &PyBrxCvAttribVariant::setAngle, DS.ARGS({ "val : float" }))
        .def("setRatio", &PyBrxCvAttribVariant::setRatio, DS.ARGS({ "val : float" }))
        .def("setArea", &PyBrxCvAttribVariant::setArea, DS.ARGS({ "val : float" }))
        .def("setAzimuth", &PyBrxCvAttribVariant::setAzimuth, DS.ARGS({ "val : float" }))
        .def("setDirection", &PyBrxCvAttribVariant::setDirection, DS.ARGS({ "val : float" }))
        .def("setDistance", &PyBrxCvAttribVariant::setDistance, DS.ARGS({ "val : float" }))
        .def("setElevation", &PyBrxCvAttribVariant::setElevation, DS.ARGS({ "val : float" }))
        .def("setSlope", &PyBrxCvAttribVariant::setSlope, DS.ARGS({ "val : float" }))
        .def("setLatitude", &PyBrxCvAttribVariant::setLatitude, DS.ARGS({ "val : float" }))
        .def("setLongitude", &PyBrxCvAttribVariant::setLongitude, DS.ARGS({ "val : float" }))
        .def("setRotation", &PyBrxCvAttribVariant::setRotation, DS.ARGS({ "val : float" }))
        .def("setVolume", &PyBrxCvAttribVariant::setVolume, DS.ARGS({ "val : float" }))
        .def("setSpeed", &PyBrxCvAttribVariant::setSpeed, DS.ARGS({ "val : float" }))
        .def("setBool", &PyBrxCvAttribVariant::setBool, DS.ARGS({ "val : bool" }))
        .def("setString", &PyBrxCvAttribVariant::setString, DS.ARGS({ "val : str" }))
        .def("setInteger", &PyBrxCvAttribVariant::setInteger, DS.ARGS({ "val : int" }))
        .def("className", &PyBrxCvAttribVariant::className, DS.SARGS()).staticmethod("className")
        ;
}


PyBrxCvAttribVariant::PyBrxCvAttribVariant()
{
}

PyBrxCvAttribVariant::PyBrxCvAttribVariant(const BrxCvAttribVariant& other)
    : impl(other)
{
}

PyBrxCvAttribVariant::PyBrxCvAttribVariant(const std::string& val)
    : impl(utf8_to_wstr(val).c_str())
{
}

PyBrxCvAttribVariant::PyBrxCvAttribVariant(BrxCvDataType val)
    : impl(val)
{
}

bool PyBrxCvAttribVariant::isValid() const
{
    return impl.isValid();
}

BrxCvDataType PyBrxCvAttribVariant::type() const
{
    return impl.type();
}

double PyBrxCvAttribVariant::getDouble() const
{
    return impl.getDouble();
}

double PyBrxCvAttribVariant::getLinear() const
{
    return impl.getLinear();
}

double PyBrxCvAttribVariant::getStation() const
{
    return impl.getStation();
}

double PyBrxCvAttribVariant::getAngle() const
{
    return impl.getAngle();
}

double PyBrxCvAttribVariant::getRatio() const
{
    return impl.getRatio();
}

double PyBrxCvAttribVariant::getArea() const
{
    return impl.getArea();
}

double PyBrxCvAttribVariant::getAzimuth() const
{
    return impl.getAzimuth();
}

double PyBrxCvAttribVariant::getDirection() const
{
    return impl.getDirection();
}

double PyBrxCvAttribVariant::getDistance() const
{
    return impl.getDistance();
}

double PyBrxCvAttribVariant::getElevation() const
{
    return impl.getElevation();
}

double PyBrxCvAttribVariant::getSlope() const
{
    return impl.getSlope();
}

double PyBrxCvAttribVariant::getLatitude() const
{
    return impl.getLatitude();
}

double PyBrxCvAttribVariant::getLongitude() const
{
    return impl.getLongitude();
}

double PyBrxCvAttribVariant::getRotation() const
{
    return impl.getRotation();
}

double PyBrxCvAttribVariant::getVolume() const
{
    return impl.getVolume();
}

double PyBrxCvAttribVariant::getSpeed() const
{
    return impl.getSpeed();
}

bool PyBrxCvAttribVariant::getBool() const
{
    return impl.getBool();
}

std::string PyBrxCvAttribVariant::getString() const
{
    return wstr_to_utf8(impl.getString());
}

Adesk::Int64 PyBrxCvAttribVariant::getInteger() const
{
    return impl.getInteger();
}

void PyBrxCvAttribVariant::setLinear(double value)
{
    impl.setLinear(value);
}

void PyBrxCvAttribVariant::setStation(double value)
{
    impl.setStation(value);
}

void PyBrxCvAttribVariant::setAngle(double value)
{
    impl.setAngle(value);
}

void PyBrxCvAttribVariant::setRatio(double value)
{
    impl.setRatio(value);
}

void PyBrxCvAttribVariant::setArea(double value)
{
    impl.setArea(value);
}

void PyBrxCvAttribVariant::setAzimuth(double value)
{
    impl.setAzimuth(value);
}

void PyBrxCvAttribVariant::setDirection(double value)
{
    impl.setDirection(value);
}

void PyBrxCvAttribVariant::setDistance(double value)
{
    impl.setDistance(value);
}

void PyBrxCvAttribVariant::setElevation(double value)
{
    impl.setElevation(value);
}

void PyBrxCvAttribVariant::setSlope(double value)
{
    impl.setSlope(value);
}

void PyBrxCvAttribVariant::setLatitude(double value)
{
    impl.setLatitude(value);
}

void PyBrxCvAttribVariant::setLongitude(double value)
{
    impl.setLongitude(value);
}

void PyBrxCvAttribVariant::setRotation(double value)
{
    impl.setRotation(value);
}

void PyBrxCvAttribVariant::setVolume(double value)
{
    impl.setVolume(value);
}

void PyBrxCvAttribVariant::setSpeed(double value)
{
    impl.setSpeed(value);
}

void PyBrxCvAttribVariant::setBool(bool value)
{
    impl.setBool(value);
}

void PyBrxCvAttribVariant::setString(const std::string& value)
{
    impl.setString(utf8_to_wstr(value).c_str());
}

void PyBrxCvAttribVariant::setInteger(Adesk::Int64 value)
{
    impl.setInteger(value);
}

std::string PyBrxCvAttribVariant::className()
{
    return "BrxCvAttribVariant";
}

#endif

