#pragma once

#ifdef BRXAPP
#include "PyBrxCvObject.h"

#if !defined(_BRXTARGET240)
#include "BrxCvGlobal.h"
#endif

class BrxCvDbPoint;
class BrxCvDbPointReferencedEntity;
class BrxCvDbPointGroup;

class PyBrxCvDbPointReferencedEntity;
class PyDbObjectId;
class PyBrxCvAttribVariant;

//-----------------------------------------------------------------------------------
//PyBrxCvDbPoint
void makePyBrxCvDbPointWrapper();

class PyBrxCvDbPoint : public PyBrxCvDbEntity
{
public:
    PyBrxCvDbPoint();
    PyBrxCvDbPoint(const PyDbObjectId& id);
    PyBrxCvDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbPoint(BrxCvDbPoint* ptr, bool autoDelete);
    virtual ~PyBrxCvDbPoint() override = default;

    Adesk::UInt32           number() const;
    bool                    setNumber(const Adesk::UInt32 number) const;
    const std::string       rawDescription() const;
    bool                    setRawDescription(const std::string& szDescription) const;
    const std::string       fullDescription() const;
#if !defined(_BRXTARGET240)
    bool                    setFullDescription(const std::string& szDescription) const;
#endif
    double                  easting() const;
    bool                    setEasting(double easting) const;
    double                  northing() const;
    bool                    setNorthing(double northing) const;
    double                  elevation() const;
    bool                    setElevation(double elevation) const;
    AcGePoint3d             position() const;
    bool                    setPosition(const AcGePoint3d& value) const;
    boost::python::list     pointGroupsIds() const;
    boost::python::list     pointGroupsNames() const;
    PyDbObjectId            symbolId() const;
    bool                    setSymbolId(const PyDbObjectId& symbolId) const;
    PyDbObjectId            labelId() const;
    bool                    setLabelId(const PyDbObjectId& labelId) const;
    AcGePoint3d             labelPosition() const;
    bool                    setLabelPosition(const AcGePoint3d& position) const;
    double                  symbolRotation() const;
    bool                    setSymbolRotation(double rotation) const;
    double                  labelRotation() const;
    bool                    setLabelRotation(double rotation) const;
    bool                    isLabelPinned() const;
    bool                    setLabelPinned(bool value) const;
    bool                    isLabelDragged() const;
    boost::python::list     labelLeaderVertices() const;
    bool                    setLabelLeaderVertices(const boost::python::list& vertices) const;
    bool                    resetLabel() const;
    Adesk::UInt32           referencedEntityCount() const;
    PyBrxCvDbPointReferencedEntity referencedEntityAt(Adesk::UInt32 index) const;
    bool                    update() const;

    static boost::python::list  importPointsFromFile(const boost::python::list& pyfiles, const PyDbObjectId& formatId);
    static void                 assignPointToPointGroup(const PyBrxCvDbPoint& point, const PyDbObjectId& groupId);
    static void                 assignPointsToPointGroup(const boost::python::list& cvpoints, const PyDbObjectId& groupId);
    static void                 assignStylesToPoints(const boost::python::list& cvpoints,const PyDbObjectId& symbolStyleId, const PyDbObjectId& labelStyleId);

#if defined(_BRXTARGET) && (_BRXTARGET == 260)
    bool                    addUserAttribute(const std::string& name, const PyBrxCvAttribVariant& value) const;
    bool                    removeUserAttribute(const std::string& name, BrxCvDataType type) const;
    boost::python::list     userAttributes() const;
    PyBrxCvAttribVariant    userAttribute(const std::string& name, BrxCvDataType spec) const;
    boost::python::list     userAttributeNames() const;
    Adesk::UInt32           userAttributeCount() const;
    boost::python::tuple    userAttributeAt(Adesk::UInt32 index) const;
#endif

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbPoint   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbPoint   cast(const PyRxObject& src);
public:
    inline BrxCvDbPoint* impObj(const std::source_location& src = std::source_location::current()) const;
};

inline AcDbEntityPtrArray PyListToPyBrxCvDbPointArray(const boost::python::object& iterable)
{
    AcDbEntityPtrArray arr;
    const auto& vec = py_list_to_std_vector<PyBrxCvDbPoint>(iterable);
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append((AcDbEntity*)item.impObj());
    return arr;
}


//-----------------------------------------------------------------------------------
//PyBrxCvDbPointReferencedEntity
void makePyBrxCvDbPointReferencedEntityWrapper();

class PyBrxCvDbPointReferencedEntity : public PyBrxCvDbSubObject
{
public:

    PyBrxCvDbPointReferencedEntity();
    PyBrxCvDbPointReferencedEntity(BrxCvDbPointReferencedEntity* ptr, bool autoDelete);
    virtual ~PyBrxCvDbPointReferencedEntity() override = default;

    PyDbObjectId            id() const;
    bool                    setId(const PyDbObjectId& value) const;
    PyRxClass               type() const;

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbPointReferencedEntity  cast(const PyRxObject& src);

public:
    inline BrxCvDbPointReferencedEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbPointGroup
void makePyBrxCvDbPointGroupWrapper();
class PyBrxCvDbPointGroup : public PyBrxCvDbObject
{
public:
    PyBrxCvDbPointGroup();
    PyBrxCvDbPointGroup(const PyDbObjectId& id);
    PyBrxCvDbPointGroup(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbPointGroup(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbPointGroup(BrxCvDbPointGroup* ptr, bool autoDelete);
    virtual ~PyBrxCvDbPointGroup() override = default;

    PyDbObjectId        hasPoint(Adesk::UInt32 number) const;
    Adesk::UInt32       pointCount() const;
    boost::python::list pointIds() const;
    bool                isEditable() const;
    bool                isApplicable(const PyBrxCvDbPoint& point) const;
    std::string         includeNumbers() const;
    std::string         excludeNumbers() const;
    std::string         includeElevations() const;
    std::string         excludeElevations() const;
    std::string         includeRawDescriptions() const;
    std::string         excludeRawDescriptions() const;
    std::string         includeFullDescriptions() const;
    std::string         excludeFullDescriptions() const;
    std::string         includeNames() const;
    std::string         excludeNames() const;
    std::string         includeUserAttributesKeys() const;
    std::string         excludeUserAttributesKeys() const;
    std::string         includeUserAttributesValues() const;
    std::string         excludeUserAttributesValues() const;
    bool                setIncludeNumbers(const std::string& szFilter) const;
    bool                setExcludeNumbers(const std::string& szFilter) const;
    bool                setIncludeElevations(const std::string& szFilter) const;
    bool                setExcludeElevations(const std::string& szFilter) const;
    bool                setIncludeRawDescriptions(const std::string& szFilter) const;
    bool                setExcludeRawDescriptions(const std::string& szFilter) const;
    bool                setIncludeFullDescriptions(const std::string& szFilter) const;
    bool                setExcludeFullDescriptions(const std::string& szFilter) const;
    bool                setIncludeNames(const std::string& szFilter) const;
    bool                setExcludeNames(const std::string& szFilter) const;
    bool                setIncludeUserAttributesKeys(const std::string& szFilter) const;
    bool                setExcludeUserAttributesKeys(const std::string& szFilter) const;
    bool                setIncludeUserAttributesValues(const std::string& szFilter) const;
    bool                setExcludeUserAttributesValues(const std::string& szFilter) const;
    bool                updateNeeded() const;
    bool                update() const;

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbPointGroup  cloneFrom(const PyRxObject& src);
    static PyBrxCvDbPointGroup  cast(const PyRxObject& src);

public:
    inline BrxCvDbPointGroup* impObj(const std::source_location& src = std::source_location::current()) const;

};

#endif //BRXAPP
