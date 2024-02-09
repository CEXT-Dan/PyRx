#pragma once
#include "PyDbObject.h"

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
    void                append2(const boost::python::object& ids);
    void                prepend1(const PyDbObjectId& id);
    void                prepend2(const boost::python::object& ids);
    void                insertAt1(Adesk::UInt32 idx, const PyDbObjectId& id);
    void                insertAt2(Adesk::UInt32 idx, const boost::python::object& ids);
    void                remove1(const PyDbObjectId& id);
    void                remove2(const boost::python::object& ids);
    void                removeAt1(Adesk::UInt32 idx);
    void                removeAt2(Adesk::UInt32 idx, const boost::python::object& ids);
    void                replace(const AcDbObjectId& oldId, const AcDbObjectId& newId);
    void                transfer(Adesk::UInt32 fromIndex, Adesk::UInt32 toIndex, Adesk::UInt32 numItems);
    void                clear();
    Adesk::UInt32       numEntities() const;
    bool                has(const PyDbEntity& pEntity) const;
    boost::python::list allEntityIds() const;
    Adesk::UInt32       getIndex(const PyDbObjectId& id) const;
    void                reverse();

    void                setColor(const AcCmColor& color);
    void                setColorIndex(Adesk::UInt16 color);
    void                setLayer1(const std::string& newVal);
    void                setLayer2(const PyDbObjectId& newVal);
    void                setLinetype1(const std::string& newVal);
    void                setLinetype2(const PyDbObjectId& newVal);
    void                setLinetypeScale(double newval);
    void                setVisibility(AcDb::Visibility newVal);
    void                setHighlight(bool newVal);
    void                setMaterial1(const std::string& newVal);
    void                setMaterial2(const PyDbObjectId& newVal);

public:
    static PyRxClass    desc();
    static std::string  className();
    static PyDbGroup    cloneFrom(const PyRxObject& src);
    static PyDbGroup    cast(const PyRxObject& src);
public:
    inline AcDbGroup* impObj(const std::source_location& src = std::source_location::current()) const;
};
