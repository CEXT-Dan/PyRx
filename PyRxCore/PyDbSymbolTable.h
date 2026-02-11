#pragma once

#include "PyDbObject.h"
#include "PyDbObjectId.h"

#pragma pack (push, 8)

class PyDbSymbolTableRecord;
class PyDbDimStyleTableRecord;
class PyDbBlockTableRecord;
class PyDbTextStyleTableRecord;
class PyDbLinetypeTableRecord;
class PyDbRegAppTableRecord;
class PyDbUCSTableRecord;
class PyDbLayerTableRecord;
class PyDbAbstractViewTableRecord;
class PyDbViewportTableRecord;
class PyDbViewTableRecord;

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable
void makePyDbSymbolTableWrapper();

class PyDbSymbolTable : public PyDbObject
{
public:
    PyDbSymbolTable(AcDbSymbolTable* ptr, bool autoDelete);
    PyDbSymbolTable(const PyDbObjectId& id);
    PyDbSymbolTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSymbolTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbSymbolTable() override = default;
    PyDbObjectId        getAt(const std::string& entryName) const;
    PyDbObjectId        getAtEx(const std::string& entryName) const;
    bool                has1(const std::string& entryName) const;
    bool                has2(const PyDbObjectId& entryid) const;
    PyDbObjectId        add(const PyDbSymbolTableRecord& pRecord) const;
    boost::python::list recordIds() const;
    boost::python::dict toDict() const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSymbolTable cloneFrom(const PyRxObject& src);
    static PyDbSymbolTable cast(const PyRxObject& src);

public:
    AcDbSymbolTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//AcDbDimStyleTable
void makePyDbDimStyleTableWrapper();

class PyDbDimStyleTable : public PyDbSymbolTable
{
public:
    PyDbDimStyleTable(AcDbDimStyleTable* ptr, bool autoDelete);
    PyDbDimStyleTable(const PyDbObjectId& id);
    PyDbDimStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbDimStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);

    virtual ~PyDbDimStyleTable() override = default;
    PyDbObjectId        add(const PyDbDimStyleTableRecord& entry) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbDimStyleTable cloneFrom(const PyRxObject& src);
    static PyDbDimStyleTable cast(const PyRxObject& src);

public:
    AcDbDimStyleTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbBlockTable
void makePyDbBlockTableWrapper();

class PyDbBlockTable : public PyDbSymbolTable
{
public:
    PyDbBlockTable(AcDbBlockTable* ptr, bool autoDelete);
    PyDbBlockTable(const PyDbObjectId& id);
    PyDbBlockTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbBlockTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);

    virtual ~PyDbBlockTable() override = default;
    PyDbObjectId        add(const PyDbBlockTableRecord& entry) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbBlockTable cloneFrom(const PyRxObject& src);
    static PyDbBlockTable cast(const PyRxObject& src);

public:
    AcDbBlockTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbTextStyleTable
void makePyDbTextStyleTableWrapper();

class PyDbTextStyleTable : public PyDbSymbolTable
{
public:
    PyDbTextStyleTable(AcDbTextStyleTable* ptr, bool autoDelete);
    PyDbTextStyleTable(const PyDbObjectId& id);
    PyDbTextStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbTextStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);

    virtual ~PyDbTextStyleTable() override = default;
    PyDbObjectId        add(const PyDbTextStyleTableRecord& entry) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbTextStyleTable cloneFrom(const PyRxObject& src);
    static PyDbTextStyleTable cast(const PyRxObject& src);

public:
    AcDbTextStyleTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbLinetypeTable
void makePyDbLinetypeTableWrapper();

class PyDbLinetypeTable : public PyDbSymbolTable
{
public:
    PyDbLinetypeTable(AcDbLinetypeTable* ptr, bool autoDelete);
    PyDbLinetypeTable(const PyDbObjectId& id);
    PyDbLinetypeTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbLinetypeTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);

    virtual ~PyDbLinetypeTable() override = default;
    PyDbObjectId        add(const PyDbLinetypeTableRecord& entry) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbLinetypeTable cloneFrom(const PyRxObject& src);
    static PyDbLinetypeTable cast(const PyRxObject& src);

public:
    AcDbLinetypeTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbRegAppTable
void makePyDbRegAppTableWrapper();

class PyDbRegAppTable : public PyDbSymbolTable
{
public:
    PyDbRegAppTable(AcDbRegAppTable* ptr, bool autoDelete);
    PyDbRegAppTable(const PyDbObjectId& id);
    PyDbRegAppTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbRegAppTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbRegAppTable() override = default;
    PyDbObjectId        add(const PyDbRegAppTableRecord& entry) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRegAppTable cloneFrom(const PyRxObject& src);
    static PyDbRegAppTable cast(const PyRxObject& src);

public:
    AcDbRegAppTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbUCSTable
void makePyDbUCSTableWrapper();

class PyDbUCSTable : public PyDbSymbolTable
{
public:
    PyDbUCSTable(AcDbUCSTable* ptr, bool autoDelete);
    PyDbUCSTable(const PyDbObjectId& id);
    PyDbUCSTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbUCSTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbUCSTable() override = default;
    PyDbObjectId        add(const PyDbUCSTableRecord& entry) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbUCSTable cloneFrom(const PyRxObject& src);
    static PyDbUCSTable cast(const PyRxObject& src);

public:
    AcDbUCSTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbLayerTable
void makePyDbLayerTableWrapper();

class PyDbLayerTable : public PyDbSymbolTable
{
public:
    PyDbLayerTable(AcDbLayerTable* ptr, bool autoDelete);
    PyDbLayerTable(const PyDbObjectId& id);
    PyDbLayerTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbLayerTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbLayerTable() override = default;
    PyDbObjectId        add(const PyDbLayerTableRecord& entry) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbLayerTable cloneFrom(const PyRxObject& src);
    static PyDbLayerTable cast(const PyRxObject& src);

public:
    AcDbLayerTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbAbstractViewTable 
void makePyDbAbstractViewTableWrapper();

class PyDbAbstractViewTable : public PyDbSymbolTable
{
public:
    PyDbAbstractViewTable(AcDbAbstractViewTable* ptr, bool autoDelete);
    PyDbAbstractViewTable(const PyDbObjectId& id);
    PyDbAbstractViewTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbAbstractViewTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbAbstractViewTable() override = default;
    PyDbObjectId        add(const PyDbAbstractViewTableRecord& entry);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbAbstractViewTable cloneFrom(const PyRxObject& src);
    static PyDbAbstractViewTable cast(const PyRxObject& src);

public:
    AcDbAbstractViewTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbViewportTable 
void makePyDbViewportTableWrapper();

class PyDbViewportTable : public PyDbAbstractViewTable
{
public:
    PyDbViewportTable();
    PyDbViewportTable(AcDbViewportTable* ptr, bool autoDelete);
    PyDbViewportTable(const PyDbObjectId& id);
    PyDbViewportTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbViewportTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbViewportTable() override = default;
    PyDbObjectId        add(const PyDbViewportTableRecord& entry);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbViewportTable cloneFrom(const PyRxObject& src);
    static PyDbViewportTable cast(const PyRxObject& src);

public:
    AcDbViewportTable* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbViewTable 
void makePyDbViewTableWrapper();

class PyDbViewTable : public PyDbAbstractViewTable
{
public:
    PyDbViewTable();
    PyDbViewTable(const PyDbObjectId& id);
    PyDbViewTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbViewTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbViewTable(AcDbViewTable* ptr, bool autoDelete);
    virtual ~PyDbViewTable() override = default;
    PyDbObjectId        add(const PyDbViewTableRecord& entry);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbViewTable cloneFrom(const PyRxObject& src);
    static PyDbViewTable cast(const PyRxObject& src);

public:
    AcDbViewTable* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)
