#pragma once
#include "PyDbObject.h"

//----------------------------------------------------------------------------------------
//PyDbGroup
void makePyDbGroupWrapper();
class PyDbGroup : public PyDbObject
{
public:
    PyDbGroup();
    PyDbGroup(const std::string& grpDesc);
    PyDbGroup(const std::string& grpDesc, bool selectable);
    PyDbGroup(AcDbGroup* ptr, bool autoDelete);
    PyDbGroup(const PyDbObjectId&);
    PyDbGroup(const PyDbObjectId& id, AcDb::OpenMode mode);
    inline virtual ~PyDbGroup() override = default;

    boost::python::list objectIds() const;
    std::string         description() const;
    void                setDescription(const std::string& grpDesc);
    bool                isSelectable() const;
    void                setSelectable(bool selectable);
    std::string         getName() const;
    void                setName(const std::string& name);
    bool                isNotAccessible() const;
    bool                isAnonymous() const;
    void                setAnonymous();
    void                append1(const PyDbObjectId& id);
    void                append2(const boost::python::list& ids);
    void                prepend1(const PyDbObjectId& id);
    void                prepend2(const boost::python::list& ids);
    void                insertAt1(Adesk::UInt32 idx, const PyDbObjectId& id);
    void                insertAt2(Adesk::UInt32 idx, const boost::python::list& ids);
    void                remove1(const PyDbObjectId& id);
    void                remove2(const boost::python::list& ids);
    void                removeAt1(Adesk::UInt32 idx);
    void                removeAt2(Adesk::UInt32 idx, const boost::python::list& ids);
    void                replace(const AcDbObjectId& oldId,const AcDbObjectId& newId);
    void                transfer(Adesk::UInt32 fromIndex, Adesk::UInt32 toIndex, Adesk::UInt32 numItems);

public:
    static PyRxClass    desc();
    static std::string  className();
    static PyDbGroup    cloneFrom(const PyRxObject& src);
    static PyDbGroup    cast(const PyRxObject& src);
public:
    inline AcDbGroup* impObj(const std::source_location& src = std::source_location::current()) const;
};
