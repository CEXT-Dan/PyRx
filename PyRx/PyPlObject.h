#pragma once
#include "PyRxObject.h"

//-----------------------------------------------------------------------------------------
//PyRxObject
void makePyPlObjectWrapper();
class PyPlObject : public PyRxObject
{
public:
    PyPlObject(AcPlObject* ptr, bool autoDelete);
    virtual ~PyPlObject() override = default;
    static std::string      className();
public:
    inline AcPlObject*      impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PyPlDSDData
void makePyPlDSDDataWrapper();
class PyPlDSDData : public PyPlObject
{
public:
    PyPlDSDData();
    PyPlDSDData(AcPlDSDData* ptr, bool autoDelete);
    virtual ~PyPlDSDData() override = default;

    std::string             projectPath() const;
    void                    setProjectPath(const std::string& pVal);
    std::string             destinationName() const;
    void                    setDestinationName(const std::string& pVal);
    boost::python::list     getDSDEntries() const;
    void                    setDSDEntries(const  boost::python::list& val);
    boost::python::list     getPrecisionEntries() const;
    void                    setPrecisionEntries(const boost::python::list& val);
    int                     numberOfDSDEntries() const;
    //PyPlDSDEntry            DSDEntryAt(int idx);

    AcPlDSDEntry::SheetType sheetType() const;
    void                    setSheetType(AcPlDSDEntry::SheetType val);

    std::string             password() const;
    void                    setPassword(const std::string& pVal);
    void                    getUnrecognizedData(boost::python::list& sectionArray, boost::python::list& dataArray) const;
    void                    setUnrecognizedData1(const std::string& pSectionName, const std::string& pSectionData);
    void                    setUnrecognizedData2(const boost::python::list& sectionArray,const  boost::python::list& dataArray);


    static PyRxClass        desc();
    static std::string      className();
public:
    inline AcPlDSDData*     impObj(const std::source_location& src = std::source_location::current()) const;
};

