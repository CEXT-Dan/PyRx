#pragma once

#pragma pack (push, 8)

//-----------------------------------------------------------------------------------
// AutoCmdEcho
class AutoCmdEcho
{
public:
    AutoCmdEcho(int mode = 0) noexcept;
    ~AutoCmdEcho() noexcept;
    Adesk::Int16 old() const noexcept;
    bool set(Adesk::Int16 mode) const noexcept;
    bool get(Adesk::Int16& mode) const noexcept;
private:
    inline static constexpr auto _cmdecho{ L"CMDECHO" };
    Adesk::Int16 m_old = 0;
};

//---------------------------------------------------------------------------------------- -
//AutoWorkingDatabase
class AutoWorkingDatabase
{
public:
    explicit AutoWorkingDatabase(AcDbDatabase* pDb) noexcept;
    ~AutoWorkingDatabase() noexcept;
    AcDbDatabase* db() const noexcept;
private:
    AcDbDatabase* m_pDb = acdbHostApplicationServices()->workingDatabase();
};

//---------------------------------------------------------------------------------------- -
//Auto Working directory
class AutoCWD
{
public:
    AutoCWD();
    AutoCWD(const std::filesystem::path& pathToSet);
    ~AutoCWD();
    void reset(const std::filesystem::path& pathToSet);
private:
    std::error_code _Ec;
    std::filesystem::path pathToRestore = std::filesystem::current_path(_Ec);
};

//-----------------------------------------------------------------------------
// LifeTime for testing;
struct LifeTime
{
    LifeTime() noexcept;
    LifeTime(int value) noexcept;
    LifeTime(const LifeTime& other) noexcept;
    LifeTime(LifeTime&& other) noexcept;
    ~LifeTime() noexcept;
    LifeTime& operator=(const LifeTime& other) noexcept;
    LifeTime& operator=(LifeTime&& other) noexcept;
    int data = 0;
};

//-----------------------------------------------------------------------------
// PerfTimer
class PerfTimer
{
    std::wstring m_funcName;
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
public:
    PerfTimer(const wchar_t* funcName);
    ~PerfTimer() = default;
    void end(const wchar_t* msg);
};

#pragma pack (pop)
