#pragma once

//-----------------------------------------------------------------------------------------
//PyGeKnotVector wrapper
void makePyGeKnotVectorWrapper();

class PyGeKnotVector
{
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



    int                 append(double val);

    static std::string className();
public:
    AcGeKnotVector m_imp;
};

