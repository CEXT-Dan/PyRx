#pragma once
#include "PyDbObject.h"

#pragma pack (push, 8)

class PyDbObjectId;
class PyDbDatabase;
//---------------------------------------------------------------------------------------- -
//makePyDbXrecordWrapper
void makePyDbXrecordWrapper();

class PyDbXrecord : public PyDbObject
{
public:
    PyDbXrecord();
    PyDbXrecord(AcDbObject* ptr, bool autoDelete);
    PyDbXrecord(const PyDbObjectId& id);
    PyDbXrecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbXrecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbXrecord() override = default;

    boost::python::list rbChain1() const;
    boost::python::list rbChain2(PyDbDatabase& auxDb) const;
    void	            setFromRbChain1(const boost::python::list& pRb) const;
    void	            setFromRbChain2(const boost::python::list& pRb, PyDbDatabase& auxDb) const;
    bool				isXlateReferences() const;
    void				setXlateReferences(bool translate) const;
    AcDb::DuplicateRecordCloning mergeStyle() const;
    void				setMergeStyle(AcDb::DuplicateRecordCloning style) const;
public:
    static std::string	className();
    static PyRxClass	desc();
    static PyDbXrecord  cloneFrom(const PyRxObject& src);
    static PyDbXrecord  cast(const PyRxObject& src);
public:
    AcDbXrecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
