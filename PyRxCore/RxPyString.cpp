#include "stdafx.h"
#include "RxPyString.h"

std::wstring utf8_to_wstr(const std::string& str)
{
    if (str.empty())
        return {};
    const int count = MultiByteToWideChar(CP_UTF8, 0, str.data(), static_cast<int>(str.size()), nullptr, 0);
    if (count <= 0)
        return {};
    std::wstring wstr(count, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, str.data(), static_cast<int>(str.size()), wstr.data(), count);
    return wstr;
}

std::wstring utf8_to_wstr(const char* str8)
{
    if (str8 == nullptr)
        return {};
    return utf8_to_wstr(std::string{ str8 });
}

std::string wstr_to_utf8(const std::wstring& wstr)
{
    if (wstr.empty())
        return {};
    const int count = WideCharToMultiByte(CP_UTF8, 0, wstr.data(), static_cast<int>(wstr.size()), nullptr, 0, nullptr, nullptr);
    if (count <= 0)
        return {};
    std::string str(count, '\0');
    WideCharToMultiByte(CP_UTF8, 0, wstr.data(), static_cast<int>(wstr.size()), str.data(), count, nullptr, nullptr);
    return str;
}

std::string wstr_to_utf8(const wchar_t* utf16wc)
{
    if (utf16wc == nullptr)
        return {};
    return wstr_to_utf8(std::wstring{ utf16wc });
}

bool icompare(const std::wstring& l, const std::wstring& r)
{
    return CompareStringEx(
        LOCALE_NAME_USER_DEFAULT,
        LINGUISTIC_IGNORECASE,
        l.c_str(), static_cast<int>(l.size()),
        r.c_str(), static_cast<int>(r.size()),
        nullptr, nullptr, 0
    ) == CSTR_EQUAL;
}

bool icompare(const std::string& l, const std::string& r)
{
    constexpr int MAX_PATH_BUFFER = 260 + 32;

    const int l_len = static_cast<int>(l.size());
    const int r_len = static_cast<int>(r.size());

    if (l_len >= MAX_PATH_BUFFER)
    {
        return icompare(utf8_to_wstr(l), utf8_to_wstr(r));
    }

    std::array<wchar_t, MAX_PATH_BUFFER> l_buf{};
    std::array<wchar_t, MAX_PATH_BUFFER> r_buf{};

    const int l_count = MultiByteToWideChar(CP_UTF8, 0, l.data(), l_len, l_buf.data(), MAX_PATH_BUFFER);
    const int r_count = MultiByteToWideChar(CP_UTF8, 0, r.data(), r_len, r_buf.data(), MAX_PATH_BUFFER);

    if (l_count <= 0 || r_count <= 0)
        return false;

    return CompareStringEx(
        LOCALE_NAME_USER_DEFAULT,
        LINGUISTIC_IGNORECASE,
        l_buf.data(), l_count,
        r_buf.data(), r_count,
        nullptr, nullptr, 0
    ) == CSTR_EQUAL;
}

std::string expandPercents(const std::string& input) noexcept
{
    std::string result;

    if (!input.empty())
        result.reserve(static_cast<size_t>(input.size() * 1.25));

    for (char c : input) {
        result.push_back(c);
        if (c == '%') {
            result.push_back('%');
        }
    }
    return result;
}
