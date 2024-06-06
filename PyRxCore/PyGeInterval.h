#pragma once
#pragma pack (push, 8)

//-------------------------------------------------------------------------------------------------------
//PyGeInterval
void makePyGeIntervalWrapper();

class PyGeInterval
{
public:
    PyGeInterval();
    PyGeInterval(double lower, double upper);
    PyGeInterval(Adesk::Boolean boundedBelow, double bound);
    PyGeInterval(const AcGeInterval& src);

    double               lowerBound() const;
    double               upperBound() const;
    double               element() const;
    boost::python::tuple getBounds() const;
    double               length() const;
    double               tolerance() const;

    void                 set1(double lower, double upper);
    void                 set2(Adesk::Boolean boundedBelow, double bound);
    void                 set3();
    void                 setUpper(double upper);
    void                 setLower(double lower);
    void                 setTolerance(double tol);
    void                 getMerge(const PyGeInterval& otherInterval, PyGeInterval& result) const;
    int                  subtract(const PyGeInterval& otherInterval, PyGeInterval& lInterval, PyGeInterval& rInterval) const;
    Adesk::Boolean       intersectWith(const PyGeInterval& otherInterval, PyGeInterval& result) const;
    Adesk::Boolean       isBounded() const;
    Adesk::Boolean       isBoundedAbove() const;
    Adesk::Boolean       isBoundedBelow() const;
    Adesk::Boolean       isUnBounded() const;
    Adesk::Boolean       isSingleton() const;
    Adesk::Boolean       isDisjoint(const PyGeInterval& otherInterval) const;
    Adesk::Boolean       contains1(const PyGeInterval& otherInterval) const;
    Adesk::Boolean       contains2(double val) const;
    Adesk::Boolean       isContinuousAtUpper(const PyGeInterval& otherInterval) const;
    Adesk::Boolean       isOverlapAtUpper(const PyGeInterval& otherInterval, PyGeInterval& overlap) const;
    Adesk::Boolean       isEqualAtUpper1(const PyGeInterval& otherInterval) const;
    Adesk::Boolean       isEqualAtUpper2(double value) const;
    Adesk::Boolean       isEqualAtLower1(const PyGeInterval& otherInterval) const;
    Adesk::Boolean       isEqualAtLower2(double value) const;
    boost::python::tuple isPeriodicallyOn(double period);

    bool                 isGreater1(double val);
    bool                 isGreater2(const PyGeInterval& otherInterval);
    bool                 isGreaterOrEqual1(double val);
    bool                 isGreaterOrEqual2(const PyGeInterval& otherInterval);

    bool                 isLess1(double val);
    bool                 isLess2(const PyGeInterval& otherInterval);
    bool                 isLessOrEqual1(double val);
    bool                 isLessOrEqual2(const PyGeInterval& otherInterval);


    Adesk::Boolean       operator ==      (const PyGeInterval& otherInterval) const;
    Adesk::Boolean       operator !=      (const PyGeInterval& otherInterval) const;

    static std::string   className();

public:
    AcGeInterval imp;
};
#pragma pack (pop)


