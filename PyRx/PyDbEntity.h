#pragma once
#include "PyDbObject.h"
class PyCmColor;
class PyGePlane;

//-------------------------------------------------------------------------------------------------------------
//PyDbEntity
void makePyDbEntityWrapper();
class PyDbEntity : public PyDbObject
{
public:
    PyDbEntity(AcDbEntity* ptr, bool autoDelete);
    PyDbEntity(const PyDbObjectId& id);
    PyDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
    inline virtual ~PyDbEntity() override = default;
    PyDbObjectId        blockId() const;
    AcCmColor           color() const;
    void                setColor1(const AcCmColor& color);
    void                setColor2(const AcCmColor& color, bool doSubents);
    void                setColor3(const AcCmColor& color, bool doSubents, PyDbDatabase& db);
    Adesk::UInt16       colorIndex() const;
    void                setColorIndex1(Adesk::UInt16 color);
    void                setColorIndex2(Adesk::UInt16 color, Adesk::Boolean doSubents);
    AcCmEntityColor     entityColor() const;
    AcCmTransparency    transparency() const;
    void                setTransparency(const AcCmTransparency& trans, Adesk::Boolean doSubents);
    std::string         layer() const;
    PyDbObjectId        layerId() const;
    void                setLayer1(const std::string& newVal);
    void                setLayer2(const std::string& newVal, bool doSubents);
    void                setLayer3(const std::string& newVal, bool doSubents, bool allowHiddenLayer);
    void                setLayer4(const PyDbObjectId& newVal);
    void                setLayer5(const PyDbObjectId& newVal, bool doSubents);
    void                setLayer6(const PyDbObjectId& newVal, bool doSubents, bool allowHiddenLayer);
    std::string         plotStyleName() const;
    PyDbObjectId        getPlotStyleNameId() const;
    void                setPlotStyleName1(const std::string&, Adesk::Boolean doSubents);
    void                setPlotStyleName2(AcDb::PlotStyleNameType, Adesk::Boolean doSubents);
    void                setPlotStyleName3(AcDb::PlotStyleNameType, const PyDbObjectId& newId, Adesk::Boolean doSubents);
    std::string         linetype() const;
    PyDbObjectId        linetypeId() const;
    void                setLinetype1(const std::string& newVal);
    void                setLinetype2(const std::string&, Adesk::Boolean doSubents);
    void                setLinetype3(const PyDbObjectId& newVal);
    void                setLinetype4(const PyDbObjectId& newVal, Adesk::Boolean doSubents);
    std::string         material() const;
    PyDbObjectId        materialId() const;
    void                setMaterial1(const std::string& newVal);
    void                setMaterial2(const std::string&, Adesk::Boolean doSubents);
    void                setMaterial3(const PyDbObjectId& newVal);
    void                setMaterial4(const PyDbObjectId& newVal, Adesk::Boolean doSubents);
    double              linetypeScale() const;
    void                setLinetypeScale1(double newval);
    void                setLinetypeScale2(double newval, Adesk::Boolean doSubents);
    AcDb::Visibility    visibility() const;
    void                setVisibility1(AcDb::Visibility newVal);
    void                setVisibility2(AcDb::Visibility newVal, Adesk::Boolean doSubents);
    AcDb::LineWeight    lineWeight() const;
    void                setLineWeight1(AcDb::LineWeight newVal);
    void                setLineWeight2(AcDb::LineWeight newVal, Adesk::Boolean doSubents);
    AcDb::CollisionType collisionType() const;
    bool                castShadows() const;
    void                setCastShadows(bool newVal);
    bool                receiveShadows() const;
    void                setReceiveShadows(bool newVal);
    void                setPropertiesFrom1(const PyDbEntity& pEntity);
    void                setPropertiesFrom2(const PyDbEntity& pEntity, Adesk::Boolean doSubents);
    Adesk::Boolean      isPlanar() const;
    PyGePlane           getPlane() const;
    AcGeMatrix3d        getEcs() const;
    void                list() const;
    void                transformBy(const AcGeMatrix3d& xform);
    void                recordGraphicsModified();
    void                draw();
    void                setDatabaseDefaults1();
    void                setDatabaseDefaults2(const PyDbDatabase& pDb);
    AcGeMatrix3d        getCompoundObjectTransform() const;
    AcDbExtents         getGeomExtents() const;
    boost::python::list intersectWith1(const PyDbEntity&, AcDb::Intersect) const;
    boost::python::list intersectWith2(const PyDbEntity&, AcDb::Intersect, Adesk::GsMarker, Adesk::GsMarker) const;
    boost::python::list intersectWith3(const PyDbEntity&, AcDb::Intersect, const PyGePlane&) const;
    boost::python::list intersectWith4(const PyDbEntity&, AcDb::Intersect, const PyGePlane&, Adesk::GsMarker, Adesk::GsMarker) const;
    boost::python::list explode() const;
    PyDbEntity          getTransformedCopy(const AcGeMatrix3d& xform) const;
    void                addReactor(PyDbEntityReactor& pReactor) const;
    void                removeReactor(PyDbEntityReactor& pReactor) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbEntity   cloneFrom(const PyRxObject& src);
    static PyDbEntity   cast(const PyRxObject& src);
public:
    inline  AcDbEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-------------------------------------------------------------------------------------------------------------
//PyDbBlockBegin
void makePyDbBlockBeginWrapper();
class PyDbBlockBegin : public PyDbEntity
{
public:
    PyDbBlockBegin(AcDbBlockBegin* ptr, bool autoDelete);
    PyDbBlockBegin(const PyDbObjectId& id);
    PyDbBlockBegin(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockBegin() = default;
    static std::string      className();
    static PyRxClass        desc();
    static PyDbBlockBegin   cloneFrom(const PyRxObject& src);
    static PyDbBlockBegin   cast(const PyRxObject& src);
public:
    inline AcDbBlockBegin* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-------------------------------------------------------------------------------------------------------------
//PyDbBlockEnd
void makePyDbBlockEndWrapper();
class PyDbBlockEnd : public PyDbEntity
{
public:
    PyDbBlockEnd(AcDbBlockEnd* ptr, bool autoDelete);
    PyDbBlockEnd(const PyDbObjectId& id);
    PyDbBlockEnd(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockEnd() = default;
    static std::string      className();
    static PyRxClass        desc();
    static PyDbBlockEnd     cloneFrom(const PyRxObject& src);
    static PyDbBlockEnd     cast(const PyRxObject& src);
public:
    inline AcDbBlockEnd* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-------------------------------------------------------------------------------------------------------------
//PyDbSequenceEnd
void makePyDbSequenceEndWrapper();
class PyDbSequenceEnd : public PyDbEntity
{
public:
    PyDbSequenceEnd(AcDbSequenceEnd* ptr, bool autoDelete);
    PyDbSequenceEnd(const PyDbObjectId& id);
    PyDbSequenceEnd(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbSequenceEnd() = default;
    static std::string      className();
    static PyRxClass        desc();
    static PyDbSequenceEnd  cloneFrom(const PyRxObject& src);
    static PyDbSequenceEnd  cast(const PyRxObject& src);
public:
    inline AcDbSequenceEnd* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//PyDbSubentId
void makePyDbSubentIdWrapper();

class PyDbSubentId
{
public:
    PyDbSubentId();
    PyDbSubentId(AcDb::SubentType type, Adesk::GsMarker index);
    PyDbSubentId(PyRxClass& pTypeClass, Adesk::GsMarker index);
    bool        operator ==(const PyDbSubentId& id) const;
    bool        operator !=(const PyDbSubentId& id) const;
    AcDb::SubentType   type() const;
    void               setType(AcDb::SubentType et);
    PyRxClass          typeClass() const;
    void               setTypeClass(PyRxClass& pClass);
    Adesk::GsMarker    index() const;
    void               setIndex(Adesk::GsMarker ind);
    static const PyDbSubentId kNull();
public:
    inline AcDbSubentId* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<AcDbSubentId> m_pyImp;

};