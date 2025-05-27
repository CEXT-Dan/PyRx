#pragma once

#pragma pack (push, 8)
void makePyDbDateWrapper();

class PyDbDate
{
public:
    PyDbDate();
    PyDbDate(const AcDbDate& date);
    ~PyDbDate() = default;

    boost::python::tuple    getDate() const;
    void                    setDate(int month, int day, int year) const;
    std::string             getLocalDisplayString() const;
    short                   month() const;
    short                   day() const;
    short                   year() const;
    void                    setMonth(int val) const;
    void                    setDay(int val) const;
    void                    setYear(int val) const;
    boost::python::tuple    getTime() const;
    void                    setTime(int hour, int min, int sec, int msec) const;
    short                   hour() const;
    short                   minute() const;
    short                   second() const;
    short                   millisecond() const;
    int64_t                 microsecond() const;
    void                    setHour(int val) const;
    void                    setMinute(int val) const;
    void                    setSecond(int val) const;
    void                    setMillisecond(int val) const;
    void                    setToZero() const;
    void                    getLocalTime() const;
    void                    getUniversalTime() const;
    void                    localToUniversal() const;
    void                    universalToLocal() const;
    Adesk::Int32            julianDay() const;
    Adesk::Int32            msecsPastMidnight() const;
    void                    setJulianDay(Adesk::Int32 julianDay) const;
    void                    setMsecsPastMidnight(Adesk::Int32 msec) const;
    void                    setJulianDate(Adesk::Int32 julianDay, Adesk::Int32 msec) const;
    double                  julianFraction() const;
    void                    setJulianFraction(double) const;
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
    AcDbDate* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbDate> m_pyImp;
};

#pragma pack (pop)