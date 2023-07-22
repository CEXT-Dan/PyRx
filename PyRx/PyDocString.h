#pragma once
class PyDocString
{
public:
    explicit PyDocString(const std::string& val);
    ~PyDocString() = default;

    const char* CLASSARGS();
    const char* CLASSARGS(std::initializer_list<std::string> pyargs);
    const char* CLASSARGSSTATIC();
    const char* CLASSARGSSTATIC(std::initializer_list<std::string> pyargs);

public:
    std::string outstr;
    std::string m_className;
    inline static std::string m_argBegin = "![(";
    inline static std::string m_argEnd = ")]!";
};

