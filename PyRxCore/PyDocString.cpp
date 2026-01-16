#include "stdafx.h"
#include "PyDocString.h"

PyDocString::PyDocString(const std::string& className)
    : m_className(className)
{
}

const char* PyDocString::ARGS(int helpkey /*= -1*/)
{
    outstr = m_argBegin;
    outstr += "self";
    outstr += m_argEnd;
    outstr += std::format("{}{}{}", m_docstringBegin, helpkey, m_docstringEnd);
    return outstr.c_str();
}

const char* PyDocString::ARGS(std::initializer_list<std::string_view> pyargs, int helpkey /*= -1*/)
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
    outstr += std::format("{}{}{}", m_docstringBegin, helpkey, m_docstringEnd);
    return outstr.c_str();
}

const char* PyDocString::CTOR(const std::string_view overloads, int helpkey /*= -1*/)
{
    outstr = m_argBegin;
    outstr += "self";
    outstr += m_argEnd;
    outstr += m_overloadBegin;
    outstr += overloads;
    outstr += m_overloadEnd;
    outstr += std::format("{}{}{}", m_docstringBegin, helpkey, m_docstringEnd);
    return outstr.c_str();
}

const char* PyDocString::OVRL(const std::string_view overloads, int helpkey /*= -1*/)
{
    outstr = m_argBegin;
    outstr += "self, ";
    outstr += m_argEnd;
    outstr += m_overloadBegin;
    outstr += overloads;
    outstr += m_overloadEnd;
    outstr += std::format("{}{}{}", m_docstringBegin, helpkey, m_docstringEnd);
    return outstr.c_str();
}

const char* PyDocString::SOVRL(const std::string_view overloads, int helpkey /*= -1*/)
{
    outstr = m_argBegin;
    outstr += "/";
    outstr += m_argEnd;
    outstr += m_overloadBegin;
    outstr += overloads;
    outstr += m_overloadEnd;
    outstr += std::format("{}{}{}", m_docstringBegin, helpkey, m_docstringEnd);
    return outstr.c_str();
}

const char* PyDocString::SARGS(int val /*= -1*/)
{
    outstr = m_argBegin;
    outstr += m_argEnd;
    outstr += std::format("{}{}{}", m_docstringBegin, val, m_docstringEnd);
    return outstr.c_str();
}

const char* PyDocString::SARGS(std::initializer_list<std::string_view> pyargs, int helpkey /*= -1*/)
{
    outstr = m_argBegin;
    for (auto& arg : pyargs)
    {
        outstr += std::format("{},", arg);
    }
    trim(outstr, ',');
    outstr += m_argEnd;
    outstr += std::format("{}{}{}", m_docstringBegin, helpkey, m_docstringEnd);
    return outstr.c_str();
}

