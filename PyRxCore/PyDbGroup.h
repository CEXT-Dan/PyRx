#pragma once
#include "PyDbObject.h"

#pragma pack (push, 8)
class PyDbEntity;

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
    PyDbGroup(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbGroup() override = default;

    boost::python::list objectIds() const;
    std::string         description() const;
    void                setDescription(const std::string& grpDesc) const;
    bool                isSelectable() const;
    void                setSelectable(bool selectable) const;
    std::string         getName() const;
    void                setName(const std::string& name) const;
    bool                isNotAccessible() const;
    bool                isAnonymous() const;
    void                setAnonymous() const;
    void                append1(const PyDbObjectId& id) const;
    void                append2(const boost::python::list& ids) const;
    void                prepend1(const PyDbObjectId& id) const;
    void                prepend2(const boost::python::list& ids) const;
    void                insertAt1(Adesk::UInt32 idx, const PyDbObjectId& id) const;
    void                insertAt2(Adesk::UInt32 idx, const boost::python::list& ids) const;
    void                remove1(const PyDbObjectId& id) const;
    void                remove2(const boost::python::list& ids) const;
    void                removeAt1(Adesk::UInt32 idx) const;
    void                removeAt2(Adesk::UInt32 idx, const boost::python::list& ids) const;
    void                replace(const AcDbObjectId& oldId, const AcDbObjectId& newId) const;
    void                transfer(Adesk::UInt32 fromIndex, Adesk::UInt32 toIndex, Adesk::UInt32 numItems) const;
    void                clear() const;
    Adesk::UInt32       numEntities() const;
    bool                has(const PyDbEntity& pEntity) const;
    boost::python::list allEntityIds() const;
    Adesk::UInt32       getIndex(const PyDbObjectId& id) const;
    void                reverse() const;

    void                setColor(const AcCmColor& color) const;
    void                setColorIndex(Adesk::UInt16 color) const;
    void                setLayer1(const std::string& newVal) const;
    void                setLayer2(const PyDbObjectId& newVal) const;
    void                setLinetype1(const std::string& newVal) const;
    void                setLinetype2(const PyDbObjectId& newVal) const;
    void                setLinetypeScale(double newval) const;
    void                setVisibility(AcDb::Visibility newVal) const;
    void                setHighlight(bool newVal) const;
    void                setMaterial1(const std::string& newVal) const;
    void                setMaterial2(const PyDbObjectId& newVal) const;

public:
    static PyRxClass    desc();
    static std::string  className();
    static PyDbGroup    cloneFrom(const PyRxObject& src);
    static PyDbGroup    cast(const PyRxObject& src);
public:
    AcDbGroup* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)
