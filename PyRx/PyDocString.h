#pragma once
class PyDocString
{
public:
    explicit PyDocString(const std::string& val);
    ~PyDocString() = default;

    const char* ARGS();
    const char* ARGS(std::initializer_list<std::string> pyargs);
    const char* SARGS();
    const char* SARGS(std::initializer_list<std::string> pyargs);

public:
    std::string outstr;
    std::string m_className;
    inline static std::string m_argBegin = "![(";
    inline static std::string m_argEnd = ")]!";
};

