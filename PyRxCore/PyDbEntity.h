#pragma once
#include "PyDbObject.h"

#pragma pack (push, 8)
class PyCmColor;
class PyGePlane;
class PyDbFullSubentPath;

//-------------------------------------------------------------------------------------------------------------
//PyDbEntity
void makePyDbEntityWrapper();
class PyDbEntity : public PyDbObject
{
protected:
    inline PyDbEntity() = default;
public:
    PyDbEntity(AcDbEntity* ptr, bool autoDelete);
    PyDbEntity(const PyDbObjectId& id);
    PyDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbEntity() override = default;
    PyDbObjectId        blockId() const;
    AcCmColor           color() const;
    void                setColor1(const AcCmColor& color) const;
    void                setColor2(const AcCmColor& color, bool doSubents) const;
    void                setColor3(const AcCmColor& color, bool doSubents, PyDbDatabase& db) const;
    Adesk::UInt16       colorIndex() const;
    void                setColorIndex1(Adesk::UInt16 color) const;
    void                setColorIndex2(Adesk::UInt16 color, Adesk::Boolean doSubents) const;
    AcCmEntityColor     entityColor() const;
    AcCmTransparency    transparency() const;
    void                setTransparency1(const AcCmTransparency& trans) const;
    void                setTransparency2(const AcCmTransparency& trans, Adesk::Boolean doSubents) const;
    std::string         layer() const;
    PyDbObjectId        layerId() const;
    void                setLayer1(const std::string& newVal) const;
    void                setLayer2(const std::string& newVal, bool doSubents) const;
    void                setLayer3(const std::string& newVal, bool doSubents, bool allowHiddenLayer) const;
    void                setLayer4(const PyDbObjectId& newVal) const;
    void                setLayer5(const PyDbObjectId& newVal, bool doSubents) const;
    void                setLayer6(const PyDbObjectId& newVal, bool doSubents, bool allowHiddenLayer) const;
    std::string         plotStyleName() const;
    PyDbObjectId        getPlotStyleNameId() const;
    void                setPlotStyleName1(const std::string&, Adesk::Boolean doSubents) const;
    void                setPlotStyleName2(AcDb::PlotStyleNameType, Adesk::Boolean doSubents) const;
    void                setPlotStyleName3(AcDb::PlotStyleNameType, const PyDbObjectId& newId, Adesk::Boolean doSubents) const;
    std::string         linetype() const;
    PyDbObjectId        linetypeId() const;
    void                setLinetype1(const std::string& newVal) const;
    void                setLinetype2(const std::string&, Adesk::Boolean doSubents) const;
    void                setLinetype3(const PyDbObjectId& newVal) const;
    void                setLinetype4(const PyDbObjectId& newVal, Adesk::Boolean doSubents) const;
    std::string         material() const;
    PyDbObjectId        materialId() const;
    void                setMaterial1(const std::string& newVal) const;
    void                setMaterial2(const std::string&, Adesk::Boolean doSubents) const;
    void                setMaterial3(const PyDbObjectId& newVal) const;
    void                setMaterial4(const PyDbObjectId& newVal, Adesk::Boolean doSubents) const;
    double              linetypeScale() const;
    void                setLinetypeScale1(double newval) const;
    void                setLinetypeScale2(double newval, Adesk::Boolean doSubents) const;
    AcDb::Visibility    visibility() const;
    void                setVisibility1(AcDb::Visibility newVal) const;
    void                setVisibility2(AcDb::Visibility newVal, Adesk::Boolean doSubents) const;
    AcDb::LineWeight    lineWeight() const;
    void                setLineWeight1(AcDb::LineWeight newVal) const;
    void                setLineWeight2(AcDb::LineWeight newVal, Adesk::Boolean doSubents) const;
    AcDb::CollisionType collisionType() const;
    bool                castShadows() const;
    void                setCastShadows(bool newVal) const;
    bool                receiveShadows() const;
    void                setReceiveShadows(bool newVal) const;
    void                setPropertiesFrom1(const PyDbEntity& pEntity) const;
    void                setPropertiesFrom2(const PyDbEntity& pEntity, Adesk::Boolean doSubents) const;
    Adesk::Boolean      isPlanar() const;
    PyGePlane           getPlane() const;
    AcGeMatrix3d        getEcs() const;
    void                list() const;
    void                transformBy(const AcGeMatrix3d& xform) const;
    void                recordGraphicsModified() const;
    void                draw() const;
    void                setDatabaseDefaults1() const;
    void                setDatabaseDefaults2(const PyDbDatabase& pDb) const;
    AcGeMatrix3d        getCompoundObjectTransform() const;
    AcDbExtents         getGeomExtents() const;
    AcDbExtents2d       getGeomExtents2d() const;
    boost::python::list intersectWith1(const PyDbEntity&, AcDb::Intersect) const;
    boost::python::list intersectWith2(const PyDbEntity&, AcDb::Intersect, Adesk::GsMarker, Adesk::GsMarker) const;
    boost::python::list intersectWith3(const PyDbEntity&, AcDb::Intersect, const PyGePlane&) const;
    boost::python::list intersectWith4(const PyDbEntity&, AcDb::Intersect, const PyGePlane&, Adesk::GsMarker, Adesk::GsMarker) const;
    boost::python::list explode() const;
    PyDbEntity          getTransformedCopy(const AcGeMatrix3d& xform) const;
    void                addReactor(PyDbEntityReactor& pReactor) const;
    void                removeReactor(PyDbEntityReactor& pReactor) const;
    boost::python::list getStretchPoints() const;
    boost::python::tuple getGripPoints1()const;
    boost::python::list  getGripPoints2(double curViewUnitSize, int gripSize, const AcGeVector3d& curViewDir, int bitflags) const;
    void                addSubentPaths(const boost::python::list& newPaths) const;
    boost::python::list getSubentPathsAtGsMarker1(AcDb::SubentType type, Adesk::GsMarker gsMark, const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform) const;
    boost::python::list getSubentPathsAtGsMarker2(AcDb::SubentType type, Adesk::GsMarker gsMark, const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform, int numInserts, PyDbObjectId& entAndInsertStack) const;
    void                highlight1() const;
    void                highlight2(const PyDbFullSubentPath& subId, const Adesk::Boolean highlightAll)const;
    PyDbEntity          subentPtr(const PyDbFullSubentPath& subId) const;
    static std::string  className();
    static PyRxClass    desc();
    static PyDbEntity   cloneFrom(const PyRxObject& src);
    static PyDbEntity   cast(const PyRxObject& src);
public:
    AcDbEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};

inline AcArray<AcDbEntity*> PyListToPyDbEntityPtrArray(const boost::python::object& iterable)
{
    AcArray<AcDbEntity*> arr;
    auto vec = py_list_to_std_vector<PyDbEntity>(iterable);
    for (const auto& item : vec)
        arr.append(item.impObj());
    return arr;
}

inline boost::python::list AcDbEntityArrayToPyList(const AcArray<AcDbEntity*>& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (auto item : arr)
        pyPyList.append(PyDbEntity(item, true));
    return pyPyList;
}

//-------------------------------------------------------------------------------------------------------------
//PyDbBlockBegin
void makePyDbBlockBeginWrapper();
class PyDbBlockBegin : public PyDbEntity
{
public:
    PyDbBlockBegin();
    PyDbBlockBegin(const PyDbObjectId& id);
    PyDbBlockBegin(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbBlockBegin(AcDbBlockBegin* ptr, bool autoDelete);
    virtual ~PyDbBlockBegin() = default;
    static std::string      className();
    static PyRxClass        desc();
    static PyDbBlockBegin   cloneFrom(const PyRxObject& src);
    static PyDbBlockBegin   cast(const PyRxObject& src);
public:
    AcDbBlockBegin* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//PyDbBlockEnd
void makePyDbBlockEndWrapper();
class PyDbBlockEnd : public PyDbEntity
{
public:
    PyDbBlockEnd();
    PyDbBlockEnd(const PyDbObjectId& id);
    PyDbBlockEnd(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbBlockEnd(AcDbBlockEnd* ptr, bool autoDelete);
    virtual ~PyDbBlockEnd() = default;
    static std::string      className();
    static PyRxClass        desc();
    static PyDbBlockEnd     cloneFrom(const PyRxObject& src);
    static PyDbBlockEnd     cast(const PyRxObject& src);
public:
    AcDbBlockEnd* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//PyDbSequenceEnd
void makePyDbSequenceEndWrapper();
class PyDbSequenceEnd : public PyDbEntity
{
public:
    PyDbSequenceEnd();
    PyDbSequenceEnd(const PyDbObjectId& id);
    PyDbSequenceEnd(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSequenceEnd(AcDbSequenceEnd* ptr, bool autoDelete);
    virtual ~PyDbSequenceEnd() = default;
    static std::string      className();
    static PyRxClass        desc();
    static PyDbSequenceEnd  cloneFrom(const PyRxObject& src);
    static PyDbSequenceEnd  cast(const PyRxObject& src);
public:
    AcDbSequenceEnd* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------------
//PyDbSubentId
void makePyDbSubentIdWrapper();

class PyDbSubentId
{
public:
    PyDbSubentId();
    PyDbSubentId(const AcDbSubentId& src);
    PyDbSubentId(AcDb::SubentType type, Adesk::GsMarker index);
    PyDbSubentId(PyRxClass& pTypeClass, Adesk::GsMarker index);
    bool        operator ==(const PyDbSubentId& id) const;
    bool        operator !=(const PyDbSubentId& id) const;
    AcDb::SubentType   type() const;
    void               setType(AcDb::SubentType et) const;
    PyRxClass          typeClass() const;
    void               setTypeClass(PyRxClass& pClass) const;
    Adesk::GsMarker    index() const;
    void               setIndex(Adesk::GsMarker ind) const;
    static const PyDbSubentId kNull();
public:
    inline AcDbSubentId* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<AcDbSubentId> m_pyImp;
};

inline AcArray<AcDbSubentId*> PyListToPyDbSubentIdPtrArray(const boost::python::object& iterable)
{
    AcArray<AcDbSubentId*> arr;
    const auto& vec = py_list_to_std_vector<PyDbSubentId>(iterable);
    for (const auto& item : vec)
        arr.append(item.impObj());
    return arr;
}

inline boost::python::list SubentIdArrayToPyList(const AcArray<AcDbSubentId>& subEntIds)
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : subEntIds)
        pylist.append(PyDbSubentId(item));
    return pylist;
}


//-------------------------------------------------------------------------------------------------------------
//PyDbFullSubentPath
void makePyDbFullSubentPathWrapper();
class PyDbFullSubentPath
{
public:
    PyDbFullSubentPath();
    PyDbFullSubentPath(const AcDbFullSubentPath& src);

    PyDbFullSubentPath(AcDb::SubentType type, Adesk::GsMarker index);
    PyDbFullSubentPath(const PyDbObjectId& entId, AcDb::SubentType type, Adesk::GsMarker index);
    PyDbFullSubentPath(const PyDbObjectId& entId, const PyDbSubentId& subId);
    PyDbFullSubentPath(const boost::python::list& objectIds, const PyDbSubentId& subId);

    bool        operator ==(const PyDbFullSubentPath& id) const;
    bool        operator !=(const PyDbFullSubentPath& id) const;

    void                setObjectIds(const boost::python::list& objectIds);
    boost::python::list objectIds() const;
    void                setSubentId(const PyDbSubentId& subentId);
    PyDbSubentId        subentId() const;

    static              PyDbFullSubentPath kNull();

public:
    AcDbFullSubentPath pyImp;
};

inline AcArray<AcDbFullSubentPath> PyListToPyDbFullSubentPathArray(const boost::python::object& iterable)
{
    AcArray<AcDbFullSubentPath> arr;
    const auto& vec = py_list_to_std_vector<PyDbFullSubentPath>(iterable);
    for (const auto& item : vec)
        arr.append(item.pyImp);
    return arr;
}

inline boost::python::list FullSubentPathArrayToPyList(const AcDbFullSubentPathArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(PyDbFullSubentPath(item));
    return pyPyList;
}

#pragma pack (pop)