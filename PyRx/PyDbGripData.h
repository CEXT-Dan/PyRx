#pragma once


//-----------------------------------------------------------------------------------------
//PyDbGripData wrapper
void makePyDbGripDataWrapper();

class PyDbGripData
{
public:
    PyDbGripData();
    PyDbGripData(AcDbGripData* ptr);
    ~PyDbGripData() = default;

    AcGePoint3d gripPoint() const;
    void        setGripPoint(const AcGePoint3d& pt);

public:
    static std::string  className();
public:
    AcDbGripData* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbGripData> m_imp;
};

