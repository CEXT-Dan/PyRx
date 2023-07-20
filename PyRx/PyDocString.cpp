#include "stdafx.h"
#include "PyDocString.h"

PyDocString::PyDocString(const std::string& val)
    : m_className(val)
{
}

const char* PyDocString::CLASSARGS()
{
    outstr = m_argBegin;
    outstr += std::format("self: {}", m_className);
    outstr += m_argEnd;
    return outstr.c_str();
}

const char* PyDocString::CLASSARGS(std::initializer_list<std::string> pyargs)
{
    outstr = m_argBegin;
    outstr += std::format("self: {}", m_className);
    for (auto& arg : pyargs)
    {
        outstr += ",";
        outstr += std::format("{}", arg);
    }
    trim(outstr, ',');
    outstr += m_argEnd;
    return outstr.c_str();
}

const char* PyDocString::CLASSARGS(std::initializer_list<std::initializer_list<std::string>> pyargs)
{
    outstr.clear();
    for (auto& args : pyargs)
    {
        outstr += m_argBegin;
        outstr += std::format("self: {}", m_className);
        for (auto& arg : args)
        {
            outstr += ",";
            outstr += std::format("{}", arg);
        }
        trim(outstr, ',');
        outstr += m_argEnd;
    }
    return outstr.c_str();
}

const char* PyDocString::CLASSARGSSTATIC()
{
    outstr = m_argBegin;
    outstr += m_argEnd;
    return outstr.c_str();
}

const char* PyDocString::CLASSARGSSTATIC(std::initializer_list<std::string> pyargs)
{
    outstr = m_argBegin;
    for (auto& arg : pyargs)
    {
        outstr += std::format("{},", arg);
    }
    trim(outstr, ',');
    outstr += m_argEnd;
    return outstr.c_str();
}
