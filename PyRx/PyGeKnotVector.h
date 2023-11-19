#pragma once

//-----------------------------------------------------------------------------------------
//PyGeKnotVector wrapper
void makePyGeKnotVectorWrapper();

class PyGeKnotVector
{
public:
    PyGeKnotVector();
    PyGeKnotVector(const AcGeKnotVector& src);
    ~PyGeKnotVector() = default;
    int                 append(double val);

    static std::string className();
public:
    AcGeKnotVector m_imp;
};

