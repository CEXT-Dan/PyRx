#include "stdafx.h"
#include "PyDocString.h"

PyDocString::PyDocString(const std::string& val)
    : m_className(val)
{
}

const char* PyDocString::ARGS()
{
    outstr = m_argBegin;
    outstr += "self";
    outstr += m_argEnd;
    return outstr.c_str();
}

const char* PyDocString::ARGS(std::initializer_list<std::string> pyargs)
{
    outstr = m_argBegin;
    outstr += "self";
    for (auto& arg : pyargs)
    {
        outstr += ", ";
        outstr += std::format("{}", arg);
    }
    trim(outstr, ',');
    outstr += m_argEnd;
    return outstr.c_str();
}

const char* PyDocString::CTOR(const std::string_view overloads)
{
    outstr = m_argBegin;
    outstr += "self";
    outstr += m_argEnd;
    outstr += m_commentBegin;
    outstr += overloads;
    outstr += m_commenEnd;
    return outstr.c_str();
}

const char* PyDocString::ARGS(const std::string_view arguments, const std::string_view overloads)
{
    outstr = m_argBegin;
    outstr +=  "self, ";
    outstr += arguments;
    outstr += m_argEnd;
    outstr += m_commentBegin;
    outstr += overloads;
    outstr += m_commenEnd;
    return outstr.c_str();
}

const char* PyDocString::SARGS()
{
    outstr = m_argBegin;
    outstr += m_argEnd;
    return outstr.c_str();
}

const char* PyDocString::SARGS(std::initializer_list<std::string> pyargs)
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

const char* PyDocString::SARGS(std::initializer_list<std::string> pyargs, const std::string& comment)
{
    outstr = SARGS(pyargs);
    outstr += m_commentBegin;
    outstr += comment;
    outstr += m_commenEnd;
    return outstr.c_str();
}

const char* PyDocString::SARGS(std::initializer_list<std::string> pyargs, const std::string_view comment)
{
    outstr = SARGS(pyargs);
    outstr += m_commentBegin;
    outstr += comment;
    outstr += m_commenEnd;
    return outstr.c_str();
}
