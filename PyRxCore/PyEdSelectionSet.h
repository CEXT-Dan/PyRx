#pragma once

#include "PyDbObjectId.h"
#pragma pack (push, 8)

class PyRxClass;
class AdsName;
typedef std::array<int64_t, 2> PySSName;
typedef std::vector<PyDbObjectId> PyDbObjectIdArray;

void makePyEdSelectionSetWrapper();

class PyEdSelectionSet
{
public:
    PyEdSelectionSet();
    PyEdSelectionSet(const ads_name& ss);
    PyEdSelectionSet(const ads_name& ss, bool autoDelete);
    ~PyEdSelectionSet() = default;
    bool			    isInitialized() const;
    size_t              size() const;
    void                clear();
    void                add(const PyDbObjectId& objId) const;
    void                remove(const PyDbObjectId& objId) const;
    bool                hasMember(const PyDbObjectId& objId) const;
    AdsName             adsname() const;
    bool                ssSetFirst() const;
    Acad::PromptStatus  ssXform(const AcGeMatrix3d& xform) const;
    boost::python::list ssNameX1() const;
    boost::python::list ssNameX2(int ind) const;
    boost::python::list objectIds() const;
    boost::python::list objectIdsOfType(const PyRxClass& _class) const;
    boost::python::list objectIdsOfTypeList(const boost::python::list& _classes) const;//must be list

    PyDbObjectIdArray   objectIdArray1() const;
    PyDbObjectIdArray   objectIdArray2(const PyRxClass& _class) const;
    PyDbObjectIdArray   objectIdArray3(const boost::python::list& _classes) const;

    void                forceKeepAlive(bool keepIt) const;
    AcDbObjectIdArray   objectIdsImpl() const;
public:
    void filliterator();
    std::vector<PyDbObjectId>::iterator begin();
    std::vector<PyDbObjectId>::iterator end();
    std::vector<PyDbObjectId> m_iterable{ 0 };
public:
    PySSName* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PySSName> m_pSet;
};

#pragma pack (pop)
