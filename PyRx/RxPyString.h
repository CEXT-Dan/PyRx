#pragma once

constexpr inline void ltrim(std::wstring& s, wchar_t chr) noexcept {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [&](wchar_t ch) {
        return chr != ch;
    }));
}

constexpr inline void rtrim(std::wstring& s, wchar_t chr) noexcept {
    s.erase(std::find_if(s.rbegin(), s.rend(), [&](wchar_t ch) {
        return chr != ch;
    }).base(), s.end());
}

constexpr inline void trim(std::wstring& s, wchar_t chr) noexcept {
    ltrim(s, chr);
    rtrim(s, chr);
}

constexpr inline std::wstring ltrim_copy(std::wstring s, wchar_t chr) noexcept {
    ltrim(s, chr);
    return s;
}

constexpr inline std::wstring rtrim_copy(std::wstring s, wchar_t chr) noexcept {
    rtrim(s, chr);
    return s;
}

// trim from both ends (copying)
constexpr inline std::wstring trim_copy(std::wstring s, wchar_t chr) noexcept {
    trim(s, chr);
    return s;
}

constexpr inline bool iCompare(const std::string& a, const std::string& b) noexcept
{
    return std::equal(a.begin(), a.end(),
        b.begin(), b.end(),
        [](char a, char b) {
        return tolower(a) == tolower(b);
    });
}

constexpr inline bool iCompare(const std::wstring& a, const std::wstring& b) noexcept
{
    return std::equal(a.begin(), a.end(),
        b.begin(), b.end(),
        [](wchar_t a, wchar_t b) {
        return tolower(a) == tolower(b);
    });
}

inline std::wstring utf8_to_wstr(const char* str8) noexcept {
    if (str8 == nullptr)
        return std::wstring{};
    const std::string str{ str8 };
    const int count = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), NULL, 0);
    std::wstring wstr(count, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), &wstr[0], count);
    return wstr;
}

inline std::wstring utf8_to_wstr(const std::string& str) noexcept {
    const int count = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), NULL, 0);
    std::wstring wstr(count, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), &wstr[0], count);
    return wstr;
}

inline std::string wstr_to_utf8(const std::wstring& wstr) noexcept {
    const int count = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), wstr.length(), NULL, 0, NULL, NULL);
    std::string str(count, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], count, NULL, NULL);
    return str;
}

inline std::string wstr_to_utf8(const wchar_t* utf16wc) noexcept {
    if (utf16wc == nullptr)
        return std::string{};
    const std::wstring wstr{ utf16wc };
    const int count = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), wstr.length(), NULL, 0, NULL, NULL);
    std::string str(count, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], count, NULL, NULL);
    return str;
}

template <typename Out>
constexpr inline void splitA(const std::string& s, char delim, Out result) noexcept {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

constexpr inline void splitA(const std::string& s, char delim, std::vector<std::string>& elems) noexcept {
    splitA(s, delim, std::back_inserter(elems));
}

template <typename Out>
constexpr inline void splitW(const std::wstring& s, wchar_t delim, Out result) noexcept {
    std::wistringstream iss(s);
    std::wstring item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

constexpr inline void splitW(const std::wstring& s, wchar_t delim, std::vector<std::wstring>& elems) noexcept {
    splitW(s, delim, std::back_inserter(elems));
}

constexpr inline bool wstrReplace(std::wstring& str, const std::wstring& from, const std::wstring& to) noexcept {
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

constexpr inline void wEraseSubStr(std::wstring& mainStr, const std::wstring& toErase) noexcept
{
    size_t pos = mainStr.find(toErase);
    if (pos != std::wstring::npos)
        mainStr.erase(pos, toErase.length());
}

constexpr inline std::wstring cstr_to_wstr(const CString& cstr) noexcept
{
    return std::wstring(cstr, cstr.GetLength());
}

constexpr inline std::wstring_view cstr_to_wstrv(const CString& cstr) noexcept
{
    return std::wstring_view(cstr, cstr.GetLength());
}

constexpr inline std::wstring acstr_to_wstr(const AcString& cstr) noexcept
{
    return std::wstring(cstr, cstr.length());
}

inline PyObject* wstr_to_py(const std::wstring& str)
{
    return PyUnicode_FromWideChar(str.data(), str.size());
}

inline PyObject* acstr_to_py(const AcString& str)
{
    return PyUnicode_FromWideChar(str.constPtr(), str.length());
}







