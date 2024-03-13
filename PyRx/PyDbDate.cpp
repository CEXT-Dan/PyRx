#include "stdafx.h"
#include "PyDbDate.h"

using namespace boost::python;

void makePyDbDateWrapper()
{
    PyDocString DS("PyDb.Date");
    class_<PyDbDate>("Date")
        .def(init<>())
        .def("getDate", &PyDbDate::getDate, DS.ARGS())
        .def("setDate", &PyDbDate::setDate, DS.ARGS({ "month : int","day : int","year : int" }))
        .def("getLocalDisplayString", &PyDbDate::getLocalDisplayString, DS.ARGS())
        .def("month", &PyDbDate::month, DS.ARGS())
        .def("day", &PyDbDate::day, DS.ARGS())
        .def("year", &PyDbDate::year, DS.ARGS())
        .def("setMonth", &PyDbDate::setMonth, DS.ARGS({ "month : int" }))
        .def("setDay", &PyDbDate::setDay, DS.ARGS({ "day : int" }))
        .def("setYear", &PyDbDate::setYear, DS.ARGS({ "year : int" }))
        .def("getTime", &PyDbDate::getTime, DS.ARGS())
        .def("setTime", &PyDbDate::setTime, DS.ARGS({ "hour : int","min : int","sec : int","msec : int" }))
        .def("hour", &PyDbDate::hour, DS.ARGS())
        .def("minute", &PyDbDate::minute, DS.ARGS())
        .def("second", &PyDbDate::second, DS.ARGS())
        .def("millisecond", &PyDbDate::millisecond, DS.ARGS())
        .def("microsecond", &PyDbDate::microsecond, DS.ARGS())
        .def("setHour", &PyDbDate::setHour, DS.ARGS({ "hour : int" }))
        .def("setMinute", &PyDbDate::setMinute, DS.ARGS({ "min : int" }))
        .def("setSecond", &PyDbDate::setSecond, DS.ARGS({ "sec : int" }))
        .def("setMillisecond", &PyDbDate::setMillisecond, DS.ARGS({ "msec : int" }))
        .def("setToZero", &PyDbDate::setToZero, DS.ARGS())
        .def("getLocalTime", &PyDbDate::getLocalTime, DS.ARGS())
        .def("getUniversalTime", &PyDbDate::getUniversalTime, DS.ARGS())
        .def("localToUniversal", &PyDbDate::localToUniversal, DS.ARGS())
        .def("universalToLocal", &PyDbDate::universalToLocal, DS.ARGS())
        .def("julianDay", &PyDbDate::julianDay, DS.ARGS())
        .def("msecsPastMidnight", &PyDbDate::msecsPastMidnight, DS.ARGS())
        .def("setJulianDay", &PyDbDate::setJulianDay, DS.ARGS({ "day : int" }))
        .def("setMsecsPastMidnight", &PyDbDate::setMsecsPastMidnight, DS.ARGS({ "msec : int" }))
        .def("setJulianDate", &PyDbDate::setJulianDate, DS.ARGS({ "julianDay : int", "msec : int" }))
        .def("julianFraction", &PyDbDate::julianFraction, DS.ARGS())
        .def("setJulianFraction", &PyDbDate::setJulianFraction, DS.ARGS({ "val : float" }))
        .def("timestamp", &PyDbDate::timestamp, DS.ARGS())

        //operators
        .def("__eq__", &PyDbDate::operator==)
        .def("__lt__", &PyDbDate::operator<)
        .def("__gt__", &PyDbDate::operator>)
        .def("__le__", &PyDbDate::operator<=)
        .def("__ge__", &PyDbDate::operator>=)
        .def("__add__", &PyDbDate::operator+)
        .def("__iadd__", &PyDbDate::operator+=)
        .def("__sub__", &PyDbDate::operator-)
        .def("__isub__", &PyDbDate::operator-=)

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

void PyDbDate::setDate(int month, int day, int year)
{
    impObj()->setDate(month, day, year);
}

std::string PyDbDate::getLocalDisplayString() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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

void PyDbDate::setMonth(int val)
{
    impObj()->setMonth(val);
}

void PyDbDate::setDay(int val)
{
    impObj()->setDay(val);
}

void PyDbDate::setYear(int val)
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

void PyDbDate::setTime(int hour, int min, int sec, int msec)
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
    return impObj()->millisecond() * 1000;
}

void PyDbDate::setHour(int val)
{
    impObj()->setHour(val);
}

void PyDbDate::setMinute(int val)
{
    impObj()->setMinute(val);
}

void PyDbDate::setSecond(int val)
{
    impObj()->setSecond(val);
}

void PyDbDate::setMillisecond(int val)
{
    impObj()->setMillisecond(val);
}

void PyDbDate::setToZero()
{
    impObj()->setToZero();
}

void PyDbDate::getLocalTime()
{
    impObj()->getLocalTime();
}

void PyDbDate::getUniversalTime()
{
    impObj()->getUniversalTime();
}

void PyDbDate::localToUniversal()
{
    impObj()->localToUniversal();
}

void PyDbDate::universalToLocal()
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

void PyDbDate::setJulianDay(Adesk::Int32 julianDay)
{
    impObj()->setJulianDay(julianDay);
}

void PyDbDate::setMsecsPastMidnight(Adesk::Int32 msec)
{
    impObj()->setMsecsPastMidnight(msec);
}

void PyDbDate::setJulianDate(Adesk::Int32 julianDay, Adesk::Int32 msec)
{
    impObj()->setJulianDate(julianDay, msec);
}

double PyDbDate::julianFraction() const
{
    return impObj()->julianFraction();
}

void PyDbDate::setJulianFraction(double val)
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

    LARGE_INTEGER li;
    li.LowPart = filetime.dwLowDateTime;
    li.HighPart = filetime.dwHighDateTime;

    return (li.QuadPart - UNIX_TIME_START) / TICKS_PER_SECOND;
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
