#include "stdafx.h"
#include "PyDbDate.h"

using namespace boost::python;

void makePyDbDateWrapper()
{
    PyDocString DS("Date");
    class_<PyDbDate>("Date")
        .def(init<>(DS.ARGS(3512)))
        .def("getDate", &PyDbDate::getDate, DS.ARGS(3525))
        .def("setDate", &PyDbDate::setDate, DS.ARGS({ "month : int","day : int","year : int" }, 3541))
        .def("getLocalDisplayString", &PyDbDate::getLocalDisplayString, DS.ARGS(3526))
        .def("month", &PyDbDate::month, DS.ARGS(3537))
        .def("day", &PyDbDate::day, DS.ARGS(3521))
        .def("year", &PyDbDate::year, DS.ARGS(3557))
        .def("setMonth", &PyDbDate::setMonth, DS.ARGS({ "month : int" }, 3549))
        .def("setDay", &PyDbDate::setDay, DS.ARGS({ "day : int" }, 3542))
        .def("setYear", &PyDbDate::setYear, DS.ARGS({ "year : int" }, 3554))
        .def("getTime", &PyDbDate::getTime, DS.ARGS(3528))
        .def("setTime", &PyDbDate::setTime, DS.ARGS({ "hour : int","min : int","sec : int","msec : int" }, 3552))
        .def("hour", &PyDbDate::hour, DS.ARGS(3530))
        .def("minute", &PyDbDate::minute, DS.ARGS(3536))
        .def("second", &PyDbDate::second, DS.ARGS(3539))
        .def("millisecond", &PyDbDate::millisecond, DS.ARGS(3535))
        .def("microsecond", &PyDbDate::microsecond, DS.ARGS())
        .def("setHour", &PyDbDate::setHour, DS.ARGS({ "hour : int" }, 3543))
        .def("setMinute", &PyDbDate::setMinute, DS.ARGS({ "min : int" }, 3548))
        .def("setSecond", &PyDbDate::setSecond, DS.ARGS({ "sec : int" }, 3551))
        .def("setMillisecond", &PyDbDate::setMillisecond, DS.ARGS({ "msec : int" }, 3547))
        .def("setToZero", &PyDbDate::setToZero, DS.ARGS(3553))
        .def("getLocalTime", &PyDbDate::getLocalTime, DS.ARGS(3527))
        .def("getUniversalTime", &PyDbDate::getUniversalTime, DS.ARGS(3529))
        .def("localToUniversal", &PyDbDate::localToUniversal, DS.ARGS(3534))
        .def("universalToLocal", &PyDbDate::universalToLocal, DS.ARGS(3556))
        .def("julianDay", &PyDbDate::julianDay, DS.ARGS(3532))
        .def("msecsPastMidnight", &PyDbDate::msecsPastMidnight, DS.ARGS(3538))
        .def("setJulianDay", &PyDbDate::setJulianDay, DS.ARGS({ "day : int" }, 3545))
        .def("setMsecsPastMidnight", &PyDbDate::setMsecsPastMidnight, DS.ARGS({ "msec : int" }, 3550))
        .def("setJulianDate", &PyDbDate::setJulianDate, DS.ARGS({ "julianDay : int", "msec : int" }, 3544))
        .def("julianFraction", &PyDbDate::julianFraction, DS.ARGS(3533))
        .def("setJulianFraction", &PyDbDate::setJulianFraction, DS.ARGS({ "val : float" }, 3546))
        .def("timestamp", &PyDbDate::timestamp, DS.ARGS())

        //operators
        .def("__eq__", &PyDbDate::operator==, DS.ARGS({ "val: PyDb.Date" }))
        .def("__lt__", &PyDbDate::operator<, DS.ARGS({ "val: PyDb.Date" }))
        .def("__gt__", &PyDbDate::operator>, DS.ARGS({ "val: PyDb.Date" }))
        .def("__le__", &PyDbDate::operator<=, DS.ARGS({ "val: PyDb.Date" }))
        .def("__ge__", &PyDbDate::operator>=, DS.ARGS({ "val: PyDb.Date" }))
        .def("__add__", &PyDbDate::operator+, DS.ARGS({ "val: PyDb.Date" }))
        .def("__iadd__", &PyDbDate::operator+=, DS.ARGS({ "val: PyDb.Date" }))
        .def("__sub__", &PyDbDate::operator-, DS.ARGS({ "val: PyDb.Date" }))
        .def("__isub__", &PyDbDate::operator-=, DS.ARGS({ "val: PyDb.Date" }))

        .def("className", &PyDbDate::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbDate::PyDbDate()
    : m_pyImp(new AcDbDate())
{
}

PyDbDate::PyDbDate(const AcDbDate& date)
    : m_pyImp(new AcDbDate(date))
{
}

boost::python::tuple PyDbDate::getDate() const
{
    short month = 0;
    short day = 0;
    short year = 0;
    PyAutoLockGIL lock;
    impObj()->getDate(month, day, year);
    return boost::python::make_tuple(month, day, year);
}

void PyDbDate::setDate(int month, int day, int year) const
{
    impObj()->setDate(month, day, year);
}

std::string PyDbDate::getLocalDisplayString() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->getLocalDisplayString());
#endif
}

short PyDbDate::month() const
{
    return impObj()->month();
}

short PyDbDate::day() const
{
    return impObj()->day();
}

short PyDbDate::year() const
{
    return impObj()->year();
}

void PyDbDate::setMonth(int val) const
{
    impObj()->setMonth(val);
}

void PyDbDate::setDay(int val) const
{
    impObj()->setDay(val);
}

void PyDbDate::setYear(int val) const
{
    impObj()->setYear(val);
}

boost::python::tuple PyDbDate::getTime() const
{
    short hour = 0;
    short min = 0;
    short sec = 0;
    short msec = 0;
    impObj()->getTime(hour, min, sec, msec);
    return boost::python::make_tuple(hour, min, sec, msec);
}

void PyDbDate::setTime(int hour, int min, int sec, int msec) const
{
    impObj()->setTime(hour, min, sec, msec);
}

short PyDbDate::hour() const
{
    return impObj()->hour();
}

short PyDbDate::minute() const
{
    return impObj()->minute();
}

short PyDbDate::second() const
{
    return impObj()->second();
}

short PyDbDate::millisecond() const
{
    return impObj()->millisecond();
}

int64_t PyDbDate::microsecond() const
{
    return int64_t(impObj()->millisecond()) * 1000;
}

void PyDbDate::setHour(int val) const
{
    impObj()->setHour(val);
}

void PyDbDate::setMinute(int val) const
{
    impObj()->setMinute(val);
}

void PyDbDate::setSecond(int val) const
{
    impObj()->setSecond(val);
}

void PyDbDate::setMillisecond(int val) const
{
    impObj()->setMillisecond(val);
}

void PyDbDate::setToZero() const
{
    impObj()->setToZero();
}

void PyDbDate::getLocalTime() const
{
    impObj()->getLocalTime();
}

void PyDbDate::getUniversalTime() const
{
    impObj()->getUniversalTime();
}

void PyDbDate::localToUniversal() const
{
    impObj()->localToUniversal();
}

void PyDbDate::universalToLocal() const
{
    impObj()->universalToLocal();
}

Adesk::Int32 PyDbDate::julianDay() const
{
    return impObj()->julianDay();
}

Adesk::Int32 PyDbDate::msecsPastMidnight() const
{
    return impObj()->msecsPastMidnight();
}

void PyDbDate::setJulianDay(Adesk::Int32 julianDay) const
{
    impObj()->setJulianDay(julianDay);
}

void PyDbDate::setMsecsPastMidnight(Adesk::Int32 msec) const
{
    impObj()->setMsecsPastMidnight(msec);
}

void PyDbDate::setJulianDate(Adesk::Int32 julianDay, Adesk::Int32 msec) const
{
    impObj()->setJulianDate(julianDay, msec);
}

double PyDbDate::julianFraction() const
{
    return impObj()->julianFraction();
}

void PyDbDate::setJulianFraction(double val) const
{
    impObj()->setJulianFraction(val);
}

double PyDbDate::timestamp() const
{
    constexpr int64_t UNIX_TIME_START = 0x019DB1DED53E8000;
    constexpr int64_t TICKS_PER_SECOND = 10000000;

    SYSTEMTIME systime = { 0 };
    impObj()->getTime(systime);

    FILETIME filetime = { 0 };
    SystemTimeToFileTime(&systime, &filetime);

    LARGE_INTEGER li{};
    li.LowPart = filetime.dwLowDateTime;
    li.HighPart = filetime.dwHighDateTime;

    return double(li.QuadPart - UNIX_TIME_START) / TICKS_PER_SECOND;
}

bool PyDbDate::operator<=(const PyDbDate& other) const
{
    return  *impObj() <= *other.impObj();
}

bool PyDbDate::operator<(const PyDbDate& other) const
{
    return  *impObj() < *other.impObj();
}

bool PyDbDate::operator>=(const PyDbDate& other) const
{
    return  *impObj() >= *other.impObj();
}

bool PyDbDate::operator>(const PyDbDate& other) const
{
    return *impObj() > *other.impObj();
}

bool PyDbDate::operator==(const PyDbDate& other) const
{
    return *impObj() == *other.impObj();
}

PyDbDate PyDbDate::operator+(const PyDbDate& date) const
{
    return PyDbDate(*impObj() + *date.impObj());
}

PyDbDate PyDbDate::operator-(const PyDbDate& date) const
{
    return PyDbDate(*impObj() - *date.impObj());
}

PyDbDate PyDbDate::operator+=(const PyDbDate& date)
{
    return PyDbDate(*impObj() += *date.impObj());
}

PyDbDate PyDbDate::operator-=(const PyDbDate& date)
{
    return PyDbDate(*impObj() -= *date.impObj());
}

std::string_view PyDbDate::className()
{
    return "AcDbDate";
}

AcDbDate* PyDbDate::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}
