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

    static std::string className();
public:
    AcGeKnotVector m_imp;
};

