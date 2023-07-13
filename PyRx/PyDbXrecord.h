#pragma once

#include "PyDbObject.h"

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
    virtual ~PyDbXrecord() override = default;

    boost::python::list rbChain1() const;
    boost::python::list rbChain2(PyDbDatabase& auxDb) const;
    void	            setFromRbChain1(const boost::python::list& pRb);
    void	            setFromRbChain2(const boost::python::list& pRb, PyDbDatabase& auxDb);
    bool				isXlateReferences() const;
    void				setXlateReferences(bool translate);
    AcDb::DuplicateRecordCloning mergeStyle() const;
    void				setMergeStyle(AcDb::DuplicateRecordCloning style);
public:
    static std::string	className();
    static PyRxClass	desc();
    static PyDbXrecord  cloneFrom(const PyRxObject& src);
    static PyDbXrecord  cast(const PyRxObject& src);
public:
    AcDbXrecord* impObj(const std::source_location& src = std::source_location::current()) const;
};


#ifdef NEVER
//---------------------------------------------------------------------------------------- -
//makePyDbXrecordIteratorWrapper
void makePyDbXrecordIteratorWrapper();

class PyDbXrecordIterator
{

};
#endif