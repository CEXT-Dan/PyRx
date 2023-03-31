#pragma once


struct TypedValue
{
    int code;
    boost::python::object obj;
};

resbuf* typedValueToResbuf(const TypedValue tv)
{
    return nullptr;
}

boost::python::list resbufToList(resbuf* pRb);


class ResultBuffer
{
};

