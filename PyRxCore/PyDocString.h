#pragma once
class PyDocString
{
public:
    explicit PyDocString(const std::string& className);
    ~PyDocString() = default;

    const char* ARGS(int helpkey = -1);
    const char* ARGS(std::initializer_list<std::string_view> pyargs, int helpkey = -1);

    const char* OVRL(const std::string_view overloads, int helpkey = -1);
    const char* SOVRL(const std::string_view overloads, int helpkey = -1);
    const char* CTOR(const std::string_view overloads, int helpkey = -1);

    const char* SARGS(int helpkey = -1);
    const char* SARGS(std::initializer_list<std::string_view> pyargs, int helpkey = -1);

public:
    std::string outstr;
    std::string m_className;
    inline static std::string m_argBegin = "![(";
    inline static std::string m_argEnd = ")]!";

    inline static std::string m_overloadBegin = "<[(";
    inline static std::string m_overloadEnd = ")]>";

    inline static std::string m_docstringBegin = "<[{";
    inline static std::string m_docstringEnd = "}]>";
};

