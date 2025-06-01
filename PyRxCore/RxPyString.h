#pragma once

//- Declare it as an extern here so that it becomes available in all modules
// PyRxAppSettings.cpp;
_locale_t& pyrx_locale();


#if defined (_MSC_PLATFORM_TOOLSET) && _MSC_PLATFORM_TOOLSET <= 142
template <class... _Args>
using ac_Fmt_string = std::_Basic_format_string<wchar_t, std::type_identity_t<_Args>...>;

template <class... _Types>
constexpr void acprint(const ac_Fmt_string<_Types...> _Fmt, _Types&&... _Args)
{
    acutPrintf(std::vformat(_Fmt._Str, std::make_wformat_args(_Args...)).c_str());
}
template <class... _Types>
constexpr void acprintnl(const ac_Fmt_string<_Types...> _Fmt, _Types&&... _Args)
{
    acutPrintf((_T("\n") + std::vformat(_Fmt._Str, std::make_wformat_args(_Args...))).c_str());
}
#else
template <class... _Types>
constexpr void acprint(const std::wformat_string<_Types...> _Fmt, _Types&&... _Args)
{
    acutPrintf(std::vformat(_Fmt.get(), std::make_wformat_args(_Args...)).c_str());
}
template <class... _Types>
constexpr void acprintnl(const std::wformat_string<_Types...> _Fmt, _Types&&... _Args)
{
    acutPrintf((_T("\n") + std::vformat(_Fmt.get(), std::make_wformat_args(_Args...))).c_str());
}
#endif

//-----------------------------------------------------------------------------------------
//CString toupper
inline CString& towupper(CString& s) noexcept {
    for (size_t idx = 0; idx < s.GetLength(); idx++)
        s.SetAt(idx, _towupper_l(s.GetAt(idx), pyrx_locale()));
    return s;
}

inline CString towupper(const CString& s) noexcept {
    CString buffer{ s };
    for (size_t idx = 0; idx < buffer.GetLength(); idx++)
        buffer.SetAt(idx, _towupper_l(buffer.GetAt(idx), pyrx_locale()));
    return buffer;
}

//-----------------------------------------------------------------------------------------
//CString tolower
inline CString& towlower(CString& s) noexcept {
    for (size_t idx = 0; idx < s.GetLength(); idx++)
        s.SetAt(idx, _towlower_l(s.GetAt(idx), pyrx_locale()));
    return s;
}

inline CString towlower(const CString& s) noexcept {
    CString buffer{ s };
    for (size_t idx = 0; idx < buffer.GetLength(); idx++)
        buffer.SetAt(idx, _towlower_l(buffer.GetAt(idx), pyrx_locale()));
    return buffer;
}

//-----------------------------------------------------------------------------------------
//AcString toupper
inline AcString& towupper(AcString& s) noexcept {
    for (size_t idx = 0; idx < s.length(); idx++)
        s.setAt(idx, _towupper_l(s.getAt(idx), pyrx_locale()));
    return s;
}

inline AcString towupper(const AcString& s) noexcept {

    AcString buffer{ s };
    for (size_t idx = 0; idx < buffer.length(); idx++)
        buffer.setAt(idx, _towupper_l(buffer.getAt(idx), pyrx_locale()));
    return buffer;
}

//-----------------------------------------------------------------------------------------
//AcString tolower
inline AcString& towlower(AcString& s) noexcept {
    for (size_t idx = 0; idx < s.length(); idx++)
        s.setAt(idx, _towlower_l(s.getAt(idx), pyrx_locale()));
    return s;
}

inline AcString towlower(const AcString& s) noexcept {

    AcString buffer{ s };
    for (size_t idx = 0; idx < buffer.length(); idx++)
        buffer.setAt(idx, _towlower_l(buffer.getAt(idx), pyrx_locale()));
    return buffer;
}

//-----------------------------------------------------------------------------------------
//wstring toupper
inline std::wstring& towupper(std::wstring& s) noexcept {
    std::transform(s.begin(), s.end(), s.begin(),
        [&](wchar_t c) { return _towupper_l(c, pyrx_locale()); });
    return s;
}

inline std::wstring towupper(const std::wstring& s) noexcept {

    std::wstring buffer{ s };
    std::transform(buffer.begin(), buffer.end(), buffer.begin(),
        [&](wchar_t c) { return _towupper_l(c, pyrx_locale()); });
    return buffer;
}

//-----------------------------------------------------------------------------------------
//wstring tolower
inline std::wstring& towlower(std::wstring& s) noexcept {
    std::transform(s.begin(), s.end(), s.begin(),
        [&](wchar_t c) { return _towlower_l(c, pyrx_locale()); });
    return s;
}

inline std::wstring towlower(const std::wstring& s) noexcept {
    std::wstring buffer{ s };
    std::transform(buffer.begin(), buffer.end(), buffer.begin(),
        [&](wchar_t c) { return _towlower_l(c, pyrx_locale()); });
    return buffer;
}

inline std::filesystem::path towlower(const std::filesystem::path& s) noexcept {
    std::wstring buffer{ s };
    return std::filesystem::path{ towlower(buffer) };
}

constexpr inline void ltrim(std::string& s, char chr) noexcept {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [&](char ch) {
        return chr != ch;
        }));
}

constexpr inline void rtrim(std::string& s, char chr) noexcept {
    s.erase(std::find_if(s.rbegin(), s.rend(), [&](char ch) {
        return chr != ch;
        }).base(), s.end());
}

constexpr inline void trim(std::string& s, char chr) noexcept {
    ltrim(s, chr);
    rtrim(s, chr);
}

constexpr inline std::string ltrim_copy(std::string s, char chr) noexcept {
    ltrim(s, chr);
    return s;
}

constexpr inline std::string rtrim_copy(std::string s, char chr) noexcept {
    rtrim(s, chr);
    return s;
}

// trim from both ends (copying)
constexpr inline std::string trim_copy(std::string s, char chr) noexcept {
    trim(s, chr);
    return s;
}

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

inline bool iCompare(const std::wstring& a, const std::wstring& b) noexcept
{
    return _wcsicmp_l(towlower(a).c_str(), towlower(b).c_str(), pyrx_locale()) == 0;
}

[[nodiscard]] inline std::wstring utf8_to_wstr(const char* str8) noexcept {
    if (str8 == nullptr)
        return std::wstring{};
    const std::string str{ str8 };
    const int count = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), NULL, 0);
    std::wstring wstr(count, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), &wstr[0], count);
    return wstr;
}

[[nodiscard]] inline std::wstring utf8_to_wstr(const std::string& str) noexcept {
    const int count = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), NULL, 0);
    std::wstring wstr(count, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), &wstr[0], count);
    return wstr;
}

[[nodiscard]] inline std::string wstr_to_utf8(const std::wstring& wstr) noexcept {
    const int count = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), wstr.length(), NULL, 0, NULL, NULL);
    std::string str(count, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], count, NULL, NULL);
    return str;
}

[[nodiscard]] inline std::string wstr_to_utf8(const wchar_t* utf16wc) noexcept {
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

constexpr inline void eraseSubStr(std::string& mainStr, const std::string& toErase) noexcept
{
    size_t pos = mainStr.find(toErase);
    if (pos != std::wstring::npos)
        mainStr.erase(pos, toErase.length());
}

std::string removeAll(std::string str, const std::string& from)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from)) != std::string::npos)
    {
        str.erase(start_pos, from.length());
    }
    return str;
}

constexpr inline void remove_triple_spaces(std::string& str)
{
    for (auto r = std::search_n(str.begin(), str.end(), 3, ' '); r != str.end(); r = std::search_n(r, str.end(), 3, ' '))
        r = str.erase(r); ;
}

constexpr inline void remove_double_spaces(std::string& str)
{
    for (auto r = std::search_n(str.begin(), str.end(), 2, ' '); r != str.end(); r = std::search_n(r, str.end(), 2, ' '))
        r = str.erase(r); ;
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

//use for functions that have not been converted to AcString
class RxAutoOutStr
{
public:
    RxAutoOutStr() = default;
    inline ~RxAutoOutStr()
    {
        acutDelString(buf);
    }
    [[nodiscard]] inline std::string str() const
    {
        return wstr_to_utf8(buf);
    }
    RxAutoOutStr(RxAutoOutStr const&) = delete;
    RxAutoOutStr& operator=(RxAutoOutStr const&) = delete;
public:
    wchar_t* buf = nullptr;
};

#if defined (_MSC_PLATFORM_TOOLSET) && _MSC_PLATFORM_TOOLSET <= 142
template <>
struct std::hash<std::filesystem::path>
{
    std::size_t operator()(const std::filesystem::path& val) const noexcept
    {
        return std::hash<std::wstring>{}(val.wstring());
    }
};
#endif

#if defined _ARXTARGET240 || ( _BRXTARGET )  || ( _GRXTARGET250 ) || ( _ZRXTARGET )
template <>
struct std::hash<AcString>
{
    std::size_t operator()(const AcString& val) const noexcept
    {
        return std::hash<std::wstring_view>{}(std::wstring_view(static_cast<const wchar_t*>(val), val.length()));
    }
};
#endif