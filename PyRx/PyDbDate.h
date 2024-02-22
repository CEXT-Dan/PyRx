#pragma once

void makePyDbDateWrapper();

class PyDbDate
{
public:
    PyDbDate();
    PyDbDate(const AcDbDate& date);

    boost::python::tuple    getDate() const;
    void                    setDate(int month, int day, int year);
    std::string             getLocalDisplayString() const;
    short                   month() const;
    short                   day() const;
    short                   year() const;
    void                    setMonth(int val);
    void                    setDay(int val);
    void                    setYear(int val);
    boost::python::tuple    getTime() const;
    void                    setTime(int hour, int min, int sec, int msec);
    short                   hour() const;
    short                   minute() const;
    short                   second() const;
    short                   millisecond() const;
    int64_t                 microsecond() const;
    void                    setHour(int val);
    void                    setMinute(int val);
    void                    setSecond(int val);
    void                    setMillisecond(int val);
    void                    setToZero();
    void                    getLocalTime();
    void                    getUniversalTime();
    void                    localToUniversal();
    void                    universalToLocal();
    Adesk::Int32            julianDay() const;
    Adesk::Int32            msecsPastMidnight() const;
    void                    setJulianDay(Adesk::Int32 julianDay);
    void                    setMsecsPastMidnight(Adesk::Int32 msec);
    void                    setJulianDate(Adesk::Int32 julianDay, Adesk::Int32 msec);
    double                  julianFraction() const;
    void                    setJulianFraction(double);
    double                  timestamp() const;

    bool operator == (const PyDbDate& other) const;
    bool operator > (const PyDbDate& other) const;
    bool operator >= (const PyDbDate& other) const;
    bool operator < (const PyDbDate& other) const;
    bool operator <= (const PyDbDate& other) const;

    PyDbDate operator + (const PyDbDate& date) const;
    PyDbDate operator - (const PyDbDate& date) const;
    PyDbDate operator += (const PyDbDate& date);
    PyDbDate operator -= (const PyDbDate& date);

    static std::string_view className();
public:
    inline AcDbDate* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbDate> m_pyImp;
};

