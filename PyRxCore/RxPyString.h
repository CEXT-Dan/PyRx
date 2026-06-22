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

[[nodiscard]] inline std::wstring utf8_to_wstr(const std::string& str)
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

[[nodiscard]] inline std::wstring utf8_to_wstr(const char* str8)
{
    if (str8 == nullptr)
        return {};
    return utf8_to_wstr(std::string{ str8 });
}

[[nodiscard]] inline std::string wstr_to_utf8(const std::wstring& wstr)
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

[[nodiscard]] inline std::string wstr_to_utf8(const wchar_t* utf16wc)
{
    if (utf16wc == nullptr)
        return {};
    return wstr_to_utf8(std::wstring{ utf16wc });
}

inline bool icompare(const std::wstring& l, const std::wstring& r)
{
    return CompareStringEx(
        LOCALE_NAME_USER_DEFAULT,
        LINGUISTIC_IGNORECASE,
        l.c_str(), static_cast<int>(l.size()),
        r.c_str(), static_cast<int>(r.size()),
        nullptr, nullptr, 0
    ) == CSTR_EQUAL;
}

inline bool icompare(const std::string& l, const std::string& r)
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

inline std::string PyUnicode_AsString(PyObject* my_unicode_object)
{
    Py_ssize_t size = 0;
    const char* data = PyUnicode_AsUTF8AndSize(my_unicode_object, &size);
    if (data != NULL)
        return std::string(data, size);
    return std::string{};
}

inline std::string_view PyUnicode_AsStringView(PyObject* my_unicode_object)
{
    Py_ssize_t size = 0;
    const char* data = PyUnicode_AsUTF8AndSize(my_unicode_object, &size);
    if (data != NULL)
        return std::string_view(data, size);
    return std::string_view{};
}

inline AcString PyUnicode_AsAcString(PyObject* py_obj)
{
    Py_ssize_t size = 0;
    wchar_t* raw_ptr = PyUnicode_AsWideCharString(py_obj, &size);
    if (!raw_ptr) 
        return L"";
    std::unique_ptr<wchar_t, decltype(&PyMem_Free)> smart_ptr(raw_ptr, PyMem_Free);
    return AcString{ smart_ptr.get() };
}

inline std::wstring PyUnicode_AsWString(PyObject* py_obj)
{
    Py_ssize_t size = 0;
    wchar_t* raw_ptr = PyUnicode_AsWideCharString(py_obj, &size);
    if (!raw_ptr)
        return L"";
    std::unique_ptr<wchar_t, decltype(&PyMem_Free)> smart_ptr(raw_ptr, PyMem_Free);
    return std::wstring(smart_ptr.get(), static_cast<size_t>(size));
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

//-----------------------------------------------------------------------------------------
// CString toupper
inline CString& towupper(CString& s) noexcept 
{
    if (!s.IsEmpty()) {
        const size_t sizeInChars = static_cast<size_t>(s.GetLength()) + 1;
        _wcsupr_s_l(s.GetBuffer(), sizeInChars, pyrx_locale());
        s.ReleaseBuffer();
    }
    return s;
}

inline CString towupper(const CString& s) noexcept 
{
    CString buffer{ s };
    return towupper(buffer);
}

//-----------------------------------------------------------------------------------------
// CString tolower
inline CString& towlower(CString& s) noexcept 
{
    if (!s.IsEmpty()) 
    {
        const size_t sizeInChars = static_cast<size_t>(s.GetLength()) + 1;
        _wcslwr_s_l(s.GetBuffer(), sizeInChars, pyrx_locale());
        s.ReleaseBuffer();
    }
    return s;
}

inline CString towlower(const CString& s) noexcept 
{
    CString buffer{ s };
    return towlower(buffer);
}

//-----------------------------------------------------------------------------------------
// AcString toupper
inline AcString& towupper(AcString& s) noexcept 
{
    if (!s.isEmpty()) {
        const size_t sizeInChars = static_cast<size_t>(s.length()) + 1;
        _wcsupr_s_l(s.getBuffer(), sizeInChars, pyrx_locale());
        s.releaseBuffer();
    }
    return s;
}

inline AcString towupper(const AcString& s) noexcept 
{
    AcString buffer{ s };
    return towupper(buffer);
}

//-----------------------------------------------------------------------------------------
// AcString tolower
inline AcString& towlower(AcString& s) noexcept 
{
    if (!s.isEmpty()) {
        const size_t sizeInChars = static_cast<size_t>(s.length()) + 1;
        _wcslwr_s_l(s.getBuffer(), sizeInChars, pyrx_locale());
        s.releaseBuffer();
    }
    return s;
}

inline AcString towlower(const AcString& s) noexcept 
{
    AcString buffer{ s };
    return towlower(buffer);
}

//-----------------------------------------------------------------------------------------
// wstring toupper
inline std::wstring& towupper(std::wstring& s) noexcept 
{
    if (!s.empty()) {
        _wcsupr_s_l(s.data(), s.size() + 1, pyrx_locale());
    }
    return s;
}

inline std::wstring towupper(const std::wstring& s) noexcept 
{
    std::wstring buffer{ s };
    return towupper(buffer);
}

//-----------------------------------------------------------------------------------------
// wstring tolower
inline std::wstring& towlower(std::wstring& s) noexcept 
{
    if (!s.empty()) {
        _wcslwr_s_l(s.data(), s.size() + 1, pyrx_locale());
    }
    return s;
}

inline std::wstring towlower(const std::wstring& s) noexcept 
{
    std::wstring buffer{ s };
    return towlower(buffer);
}

inline std::filesystem::path towlower(const std::filesystem::path& s) noexcept 
{
    std::wstring buffer{ s.wstring() };
    return std::filesystem::path{ towlower(buffer) };
}

//-----------------------------------------------------------------------------------------
// UTF-8 string toupper
inline std::string& toupper(std::string& s) noexcept 
{
    if (!s.empty()) 
    {
        std::wstring wstr = utf8_to_wstr(s);
        towupper(wstr);
        s = wstr_to_utf8(wstr);
    }
    return s;
}

inline std::string toupper(const std::string& s) noexcept 
{
    std::string buffer{ s };
    return toupper(buffer);
}

//-----------------------------------------------------------------------------------------
// UTF-8 string tolower
inline std::string& tolower(std::string& s) noexcept 
{
    if (!s.empty()) 
    {
        std::wstring wstr = utf8_to_wstr(s);
        towlower(wstr);
        s = wstr_to_utf8(wstr);
    }
    return s;
}

inline std::string tolower(const std::string& s) noexcept 
{
    std::string buffer{ s };
    return tolower(buffer);
}

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

#if defined _ARXTARGET240 || ( _BRXTARGET )  || ( _GRXTARGET250 ) || ( _ZRXTARGET ) || (_IRXTARGET140)
template <>
struct std::hash<AcString>
{
    std::size_t operator()(const AcString& val) const noexcept
    {
        return std::hash<std::wstring_view>{}(std::wstring_view(static_cast<const wchar_t*>(val), val.length()));
    }
};
#endif
