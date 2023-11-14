#pragma once

class PyDbObjectId;
class PyDbDatabase;

//----------------------------------------------------------------------------------------
//PyIdPair
void makePyIdPairWrapper();

class PyIdPair
{
public:
    PyIdPair();
    PyIdPair(const AcDbIdPair& idpair);
    PyIdPair(const PyDbObjectId& key, const PyDbObjectId& value, bool isCloned);
    PyIdPair(const PyDbObjectId& key, const PyDbObjectId& value, bool isCloned, bool isPrimary, bool isOwnerXlated);

    PyDbObjectId   key() const;
    PyDbObjectId   value() const;
    bool           isCloned() const;
    bool           isPrimary() const;
    bool           isOwnerXlated() const;

    void           setKey(const PyDbObjectId& _key);
    void           setValue(const PyDbObjectId& _value);
    void           setIsCloned(bool isCloned);
    void           setIsPrimary(bool isPrimary);
    void           setIsOwnerXlated(bool isOwnerXlated);

public:
    AcDbIdPair m_imp;
};

//----------------------------------------------------------------------------------------
//PyDbIdMapping

//TODO copy?
void makePyDbIdMappingWrapper();

class PyDbIdMapping
{
public:
    PyDbIdMapping();
    PyDbIdMapping(const AcDbIdMapping& mapping);

    void            assign(const PyIdPair& idpair);
    bool            compute(PyIdPair& idpair) const;
    bool            change(const PyIdPair& idpair) const;
    bool            del(const PyDbObjectId& key);
    PyDbDatabase    destDb() const;
    PyDbDatabase    origDb() const;
    void            setDestDb(const PyDbDatabase& db);

    AcDb::DeepCloneType deepCloneContext() const;
    AcDb::DuplicateRecordCloning duplicateRecordCloning() const;

    boost::python::list idPairs();

    AcDbIdMapping* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbIdMapping> m_pyImp;
};

