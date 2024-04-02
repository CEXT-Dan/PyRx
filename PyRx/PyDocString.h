#pragma once
class PyDocString
{
public:
    explicit PyDocString(const std::string& val);
    ~PyDocString() = default;

    const char* ARGS();
    const char* ARGS(std::initializer_list<std::string> pyargs);

    const char* OVRL(const std::string_view overloads);
    const char* SOVRL(const std::string_view overloads);
    const char* CTOR(const std::string_view overloads);



    const char* SARGS();
    const char* SARGS(std::initializer_list<std::string> pyargs);
    const char* SARGS(std::initializer_list<std::string> pyargs, const std::string& comment);
    const char* SARGS(std::initializer_list<std::string> pyargs, const std::string_view comment);

public:
    std::string outstr;
    std::string m_className;
    inline static std::string m_argBegin = "![(";
    inline static std::string m_argEnd = ")]!";

    inline static std::string m_commentBegin = "<[(";
    inline static std::string m_commenEnd = ")]>";
};

