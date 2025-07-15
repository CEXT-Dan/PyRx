#pragma once
#pragma pack (push, 8)
//-----------------------------------------------------------------------------------------
//PyGeKnotVector wrapper
void makePyGeKnotVectorWrapper();

class PyGeKnotVector
{
#if !defined(_BRXTARGET260)
public:
    PyGeKnotVector();
    PyGeKnotVector(int size, int growSize);
    PyGeKnotVector(const AcGeKnotVector& src);
    PyGeKnotVector(const boost::python::list& dbls);
    PyGeKnotVector(int plusMult, const PyGeKnotVector& src);
    ~PyGeKnotVector() = default;
    Adesk::Boolean          isEqualTo(const PyGeKnotVector& other) const;
    double                  startParam() const;
    double                  endParam() const;
    int                     multiplicityAt(int i) const;
    int                     multiplicityAtParam(double param) const;
    int                     numIntervals() const;
    boost::python::tuple    getInterval(int ord, double par) const;
    boost::python::list     getDistinctKnots() const;
    Adesk::Boolean          contains(double param) const;
    Adesk::Boolean          isOn(double knot) const;
    void                    reverse();
    void                    removeAt(int index);
    void                    removeSubVector(int startIndex, int endIndex);
    void                    insertAt1(int indx, double u);
    void                    insertAt2(int indx, double u, int multiplicity);
    void                    insert(double u);
    int                     append1(double val);
    void                    append2(PyGeKnotVector& tail);
    void                    append3(PyGeKnotVector& tail, double knotRatio);
    boost::python::tuple    split(double par, int multLast, int multFirst) const;
    void                    setRange(double lower, double upper);
    double                  tolerance() const;
    void                    setTolerance(double tol);
    int                     length() const;
    Adesk::Boolean          isEmpty() const;
    int                     logicalLength() const;
    void                    setLogicalLength(int len);
    int                     physicalLength() const;
    void                    setPhysicalLength(int len);
    int                     growLength() const;
    void                    setGrowLength(int len);
    static std::string      className();
#endif
public:
    AcGeKnotVector m_imp;
};

#pragma pack (pop)