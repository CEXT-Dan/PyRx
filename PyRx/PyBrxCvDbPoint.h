#pragma once
#include "PyBrxCvObject.h"

#ifdef BRXAPP

class BrxCvDbPoint;
class BrxCvDbPointReferencedEntity;
class BrxCvDbPointGroup;

class PyBrxCvDbPointReferencedEntity;
class PyDbObjectId;

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
    bool                    setNumber(const Adesk::UInt32 number);
    const std::string       rawDescription() const;
    bool                    setRawDescription(const std::string& szDescription);
    const std::string       fullDescription() const;
    double                  easting() const;
    bool                    setEasting(double easting);
    double                  northing() const;
    bool                    setNorthing(double northing);
    double                  elevation() const;
    bool                    setElevation(double elevation);
    AcGePoint3d             position() const;
    bool                    setPosition(const AcGePoint3d& value);
    boost::python::list     pointGroupsIds() const;
    boost::python::list     pointGroupsNames() const;
    PyDbObjectId            symbolId() const;
    bool                    setSymbolId(const PyDbObjectId& symbolId);
    PyDbObjectId            labelId() const;
    bool                    setLabelId(const PyDbObjectId& labelId);
    AcGePoint3d             labelPosition() const;
    bool                    setLabelPosition(const AcGePoint3d& position);
    double                  symbolRotation() const;
    bool                    setSymbolRotation(double rotation);
    double                  labelRotation() const;
    bool                    setLabelRotation(double rotation);
    bool                    isLabelPinned() const;
    bool                    setLabelPinned(bool value);
    bool                    isLabelDragged() const;
    boost::python::list     labelLeaderVertices() const;
    bool                    setLabelLeaderVertices(const boost::python::list& vertices);
    bool                    resetLabel();
    Adesk::UInt32           referencedEntityCount() const;
    PyBrxCvDbPointReferencedEntity referencedEntityAt(Adesk::UInt32 index) const;
    bool                    update();

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbPoint   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbPoint   cast(const PyRxObject& src);
public:
    inline BrxCvDbPoint* impObj(const std::source_location& src = std::source_location::current()) const;
};


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
    bool                    setId(const PyDbObjectId& value);
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

    bool                hasPoint(const Adesk::UInt32 number) const;
    bool                hasPoint(const Adesk::UInt32 number, PyDbObjectId& pointId) const;
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
    bool                setIncludeNumbers(const std::string& szFilter);
    bool                setExcludeNumbers(const std::string& szFilter);
    bool                setIncludeElevations(const std::string& szFilter);
    bool                setExcludeElevations(const std::string& szFilter);
    bool                setIncludeRawDescriptions(const std::string& szFilter);
    bool                setExcludeRawDescriptions(const std::string& szFilter);
    bool                setIncludeFullDescriptions(const std::string& szFilter);
    bool                setExcludeFullDescriptions(const std::string& szFilter);
    bool                setIncludeNames(const std::string& szFilter);
    bool                setExcludeNames(const std::string& szFilter);
    bool                setIncludeUserAttributesKeys(const std::string& szFilter);
    bool                setExcludeUserAttributesKeys(const std::string& szFilter);
    bool                setIncludeUserAttributesValues(const std::string& szFilter);
    bool                setExcludeUserAttributesValues(const std::string& szFilter);
    bool                updateNeeded() const;
    bool                update();


    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbPointGroup  cloneFrom(const PyRxObject& src);
    static PyBrxCvDbPointGroup  cast(const PyRxObject& src);

public:
    inline BrxCvDbPointGroup* impObj(const std::source_location& src = std::source_location::current()) const;

};



#endif //BRXAPP
