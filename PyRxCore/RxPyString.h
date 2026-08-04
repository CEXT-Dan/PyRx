#pragma once

// PyRxAppSettings.cpp;
_locale_t& pyrx_locale();

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

[[nodiscard]] std::wstring utf8_to_wstr(const char* str8);
[[nodiscard]] std::wstring utf8_to_wstr(const std::string& str);
[[nodiscard]] std::wstring utf8_to_wstr(std::string_view utf8_str);

[[nodiscard]] std::string wstr_to_utf8(const std::wstring& wstr);
[[nodiscard]] std::string wstr_to_utf8(const std::filesystem::path& path);
[[nodiscard]] std::string wstr_to_utf8(std::wstring_view wstr);
[[nodiscard]] std::string wstr_to_utf8(const wchar_t* utf16wc);

// This is for passing (const std::string&) arguments to ARX
// if in doubt, use utf8_to_wstr that creates a new buffer
template <size_t StackBufferSize = 256>
class PyUtf8ToWchar {
public:
    explicit PyUtf8ToWchar(const std::string& str) noexcept {
        init(str.data(), static_cast<int>(str.size()));
    }

    explicit PyUtf8ToWchar(std::string_view utf8_str) noexcept {
        init(utf8_str.data(), static_cast<int>(utf8_str.size()));
    }

    template<size_t N>
    explicit PyUtf8ToWchar(const char(&str)[N]) noexcept {
        init(str, static_cast<int>(N - 1));
    }

    template<typename T> explicit PyUtf8ToWchar(T&&) = delete;

    ~PyUtf8ToWchar() noexcept = default;

    [[nodiscard]] operator const wchar_t* () const noexcept { return ptr_; }

    PyUtf8ToWchar(const PyUtf8ToWchar&) = delete;
    PyUtf8ToWchar(PyUtf8ToWchar&&) = delete;
    PyUtf8ToWchar& operator=(const PyUtf8ToWchar&) = delete;
    PyUtf8ToWchar& operator=(PyUtf8ToWchar&&) = delete;

private:
    void init(const char* data, int utf8_len) noexcept 
    {
        if (utf8_len <= 0) [[unlikely]] 
        {
            ptr_ = L"";
            return;
        }

        // --- OPTIMISTIC STACK PASS ---
        int converted = MultiByteToWideChar(
            CP_UTF8,
            0,
            data,
            utf8_len,
            stack_buf_.data(),
            static_cast<int>(StackBufferSize - 1)
        );
        if (converted > 0) [[likely]]
        {
            stack_buf_[converted] = L'\0';
            ptr_ = stack_buf_.data();
            return;
        }

        // --- HEAP FALLBACK PATHWAY ---
        const int req_size = MultiByteToWideChar(CP_UTF8, 0, data, utf8_len, nullptr, 0);
        if (req_size > 0) [[likely]]
        {
            heap_buf_.resize(req_size + 1);
            MultiByteToWideChar(CP_UTF8, 0, data, utf8_len, heap_buf_.data(), req_size);
            heap_buf_[req_size] = L'\0';
            ptr_ = heap_buf_.data();
            return;
        }
        ptr_ = L"";
    }

    const wchar_t* ptr_ = nullptr;
    std::array<wchar_t, StackBufferSize> stack_buf_;
    std::vector<wchar_t> heap_buf_;
};

using AsWStr = PyUtf8ToWchar<256>;

//
bool icompare(const std::wstring& l, const std::wstring& r);
bool icompare(const std::string& l, const std::string& r);

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

std::string expandPercents(const std::string& input) noexcept;


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

#if defined _ARXTARGET240 || _BRXTARGET260  || _GRXTARGET250 || _ZRXTARGET270
template <>
struct std::hash<AcString>
{
    std::size_t operator()(const AcString& val) const noexcept
    {
        return std::hash<std::wstring_view>{}(std::wstring_view(static_cast<const wchar_t*>(val), val.length()));
    }
};
#endif
