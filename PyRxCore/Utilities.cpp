#include "stdafx.h"
#include "Utilities.h"

//-----------------------------------------------------------------------------------
// AutoCmdEcho
AutoCmdEcho::AutoCmdEcho(int mode /*= 0*/) noexcept
{
    get(m_old);
    set(mode);
}

AutoCmdEcho::~AutoCmdEcho() noexcept
{
    set(m_old);
}

Adesk::Int16 AutoCmdEcho::old() const noexcept
{
    return m_old;
}

bool AutoCmdEcho::set(Adesk::Int16 mode) const noexcept
{
    resbuf buf{};
    buf.restype = RTSHORT;
    buf.resval.rint = mode;
    return acedSetVar(_cmdecho, &buf) == RTNORM;
}

bool AutoCmdEcho::get(Adesk::Int16& mode) const noexcept
{
    resbuf buf;
    if (acedGetVar(_cmdecho, &buf) == RTNORM) [[likely]]
    {
        mode = buf.resval.rint;
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------------------- -
//AutoWorkingDatabase
AutoWorkingDatabase::AutoWorkingDatabase(AcDbDatabase* pDb) noexcept
{
    acdbHostApplicationServices()->setWorkingDatabase(pDb);
}

AutoWorkingDatabase::~AutoWorkingDatabase() noexcept
{
    acdbHostApplicationServices()->setWorkingDatabase(m_pDb);
}

AcDbDatabase* AutoWorkingDatabase::db() const noexcept
{
    return m_pDb;
}

//---------------------------------------------------------------------------------------- -
//Auto Working directory
AutoCWD::AutoCWD()
{
}

AutoCWD::AutoCWD(const std::filesystem::path& pathToSet)
{
    std::filesystem::current_path(pathToSet, _Ec);
}

AutoCWD::~AutoCWD()
{
    std::filesystem::current_path(pathToRestore, _Ec);
}

void AutoCWD::reset(const std::filesystem::path& pathToSet)
{
    std::filesystem::current_path(pathToSet, _Ec);
}

//-----------------------------------------------------------------------------
// LifeTime for testing;
LifeTime::LifeTime() noexcept
{
    acutPrintf(L"\nDefault constructor called");
}

LifeTime::LifeTime(int value) noexcept : data(value)
{
    acutPrintf(L"\nParameterized constructor called");
}

LifeTime::LifeTime(const LifeTime& other) noexcept : data(other.data)
{
    acutPrintf(L"\nCopy constructor called");
}

LifeTime::LifeTime(LifeTime&& other) noexcept : data(other.data)
{
    acutPrintf(L"\nMove constructor called");
}

LifeTime::~LifeTime() noexcept
{
    acutPrintf(L"\nDestructor called");
}

LifeTime& LifeTime::operator=(LifeTime&& other) noexcept
{
    acutPrintf(L"\nMove assignment operator called");
    if (&other == this)
        return *this;
    data = other.data;
    return *this;
}

LifeTime& LifeTime::operator=(const LifeTime& other) noexcept
{
    acutPrintf(L"\nCopy assignment operator called");
    if (&other == this)
        return *this;
    data = other.data;
    return *this;
}

//-----------------------------------------------------------------------------
// PerfTimer
PerfTimer::PerfTimer(const wchar_t* funcName)
    : m_funcName(funcName)
{
    t1 = std::chrono::high_resolution_clock::now();
}

void PerfTimer::end(const wchar_t* msg)
{
    t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = duration_cast<std::chrono::duration<double>>(t2 - t1);
    acutPrintf(_T("\n%ls %ls, %lf seconds"), m_funcName.c_str(), msg, elapsedTime.count());
}