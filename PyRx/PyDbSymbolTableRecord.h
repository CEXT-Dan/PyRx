#pragma once
#include "PyDbObject.h"


void makeAcDbSymbolTableRecordWrapper();

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
class PyDbSymbolTableRecord : public PyDbObject
{
public:
    PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete);
    PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbSymbolTableRecord() override = default;
    std::string         getName();
    Acad::ErrorStatus   setName(const std::string name);
    bool                isDependent() const;
    bool                isResolved() const;
    bool                isRenamable() const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSymbolTableRecord cloneFrom(const PyRxObject& src);
    static PyDbSymbolTableRecord cast(const PyRxObject& src);
public:
    AcDbSymbolTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbDimStyleTableRecord 
void makeAcDbDimStyleTableRecordWrapper();
class PyDbDimStyleTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbDimStyleTableRecord();
    PyDbDimStyleTableRecord(AcDbDimStyleTableRecord* ptr, bool autoDelete);
    PyDbDimStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
public:
    static std::string className();
    static PyRxClass desc();
    static PyDbDimStyleTableRecord cloneFrom(const PyRxObject& src);
    static PyDbDimStyleTableRecord cast(const PyRxObject& src);
public:
    AcDbDimStyleTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbAbstractViewTableRecord
void makePyDbAbstractViewTableRecordWrapper();

class PyDbAbstractViewTableRecord : public PyDbSymbolTableRecord
{
public:
#ifdef NEVER
    PyDbAbstractViewTableRecord();
#endif
    PyDbAbstractViewTableRecord(AcDbAbstractViewTableRecord* ptr, bool autoDelete);
    PyDbAbstractViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
public:
    static std::string className();
    static PyRxClass desc();
    static PyDbAbstractViewTableRecord cloneFrom(const PyRxObject& src);
    static PyDbAbstractViewTableRecord cast(const PyRxObject& src);
public:
    AcDbAbstractViewTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbViewportTableRecord
void makePyDbViewportTableRecordWrapper();

class PyDbViewportTableRecord : public PyDbAbstractViewTableRecord
{
public:
    PyDbViewportTableRecord();
    PyDbViewportTableRecord(AcDbViewportTableRecord* ptr, bool autoDelete);
    PyDbViewportTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
public:
    static std::string className();
    static PyRxClass desc();
    static PyDbViewportTableRecord cloneFrom(const PyRxObject& src);
    static PyDbViewportTableRecord cast(const PyRxObject& src);
public:
    AcDbViewportTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbViewTableRecord
void makePyDbViewTableRecordWrapper();

class PyDbViewTableRecord : public PyDbAbstractViewTableRecord
{
public:
    PyDbViewTableRecord();
    PyDbViewTableRecord(AcDbViewTableRecord* ptr, bool autoDelete);
    PyDbViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);

    PyDbObjectId getLayout() const;
    Acad::ErrorStatus setLayout(const PyDbObjectId& layoutId);

public:
    static std::string className();
    static PyRxClass desc();
    static PyDbViewTableRecord cloneFrom(const PyRxObject& src);
    static PyDbViewTableRecord cast(const PyRxObject& src);
public:
    AcDbViewTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};