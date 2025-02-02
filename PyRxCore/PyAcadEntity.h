#pragma once

#include "PyAcadDbObject.h"
#pragma pack (push, 8)

class PyIAcadEntityImpl;
//----------------------------------------------------------------------------------------
//PyAcadEntity
void makePyAcadEntityWrapper();

class PyAcadEntity : public PyAcadObject
{
public:
    PyAcadEntity() = default;
    PyAcadEntity(std::shared_ptr<PyIAcadEntityImpl> ptr);
    virtual ~PyAcadEntity() override = default;

    void    transformBy(const AcGeMatrix3d& xform);
    
    static PyAcadEntity cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadEntityImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadBlock
void makePyAcadBlockWrapper();

class PyAcadBlock : public PyAcadObject
{
public:
    PyAcadBlock() = default;
    PyAcadBlock(std::shared_ptr<PyIAcadBlockImpl> ptr);
    virtual ~PyAcadBlock() = default;
    long            count() const;
    PyAcadEntity    item(long ind) const;
    boost::python::list entities();
    static PyAcadBlock cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadBlockImpl* impObj(const std::source_location& src = std::source_location::current()) const;

    void filliterator();
    std::vector<PyAcadEntity>::iterator begin();
    std::vector<PyAcadEntity>::iterator end();
    std::vector<PyAcadEntity> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyModelSpace
void makePyModelSpaceWrapper();

class PyAcadModelSpace : public PyAcadBlock
{
public:
    PyAcadModelSpace() = default;
    PyAcadModelSpace(std::shared_ptr<PyIAcadModelSpaceImpl> ptr);
    virtual ~PyAcadModelSpace() override = default;
    static PyAcadModelSpace cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadModelSpaceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyPaperSpace
void makePyPaperSpaceWrapper();

class PyAcadPaperSpace : public PyAcadBlock
{
public:
    PyAcadPaperSpace() = default;
    PyAcadPaperSpace(std::shared_ptr<PyIAcadPaperSpaceImpl> ptr);
    virtual ~PyAcadPaperSpace() override = default;
    static PyAcadPaperSpace cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPaperSpaceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};


#pragma pack (pop)