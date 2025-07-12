#pragma once
#include "PyGiDrawable.h"

#pragma pack (push, 8)
class PyDbEntity;
class PyDbObjectId;
class PyDbDatabase;
class PyDbField;
class PyDbHandle;
class PyDbObjectReactor;
class PyDbEntityReactor;
class PyDbSnoopDwgFiler;
class PyDbSnoopDxfFiler;
class PyDbIdMapping;
class PyDbObjectContext;

enum class AnnotativeStates
{
    kTrue,
    kFalse,
    kNotApplicable
};

//----------------------------------------------------------------------------------------
//PyDbObject
void makePyDbObjectWrapper();
class PyDbObject : public PyGiDrawable
{
public:
    PyDbObject(AcDbObject* ptr, bool autoDelete);
    PyDbObject(const PyDbObjectId& id);
    PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbObject() override = default;
    void                addContext(const PyDbObjectContext& ctx) const;
    void                removeContext(const PyDbObjectContext& ctx) const;
    AnnotativeStates    isAnnotative() const;
    void                setAnnotative(AnnotativeStates status) const;
    PyDbObjectId        objectId() const;
    PyDbObjectId        ownerId() const;
    void                setOwnerId(const PyDbObjectId&  constobjId) const;
    PyDbDatabase        database() const;
    PyDbDatabase        databaseToUse() const;
    void                createExtensionDictionary() const;
    PyDbObjectId        extensionDictionary() const;
    void                releaseExtensionDictionary() const;
    void                close() const;
    void                upgradeOpen() const;
    void                upgradeFromNotify(Adesk::Boolean& wasWritable) const;
    void                downgradeOpen() const;
    void                downgradeToNotify(Adesk::Boolean wasWritable) const;
    void                cancel() const;
    void                erase1() const;
    void                erase2(Adesk::Boolean erasing) const;
    void                handOverTo(PyDbObject& newObject, Adesk::Boolean keepXData, Adesk::Boolean keepExtDict) const;
    void                swapIdWith(PyDbObjectId& otherId, Adesk::Boolean swapXdata, Adesk::Boolean swapExtDict) const;
    bool                hasXData(const std::string& regappName) const;
    void                setXData(const boost::python::list& xdata) const;
    virtual boost::python::list xData1() const;
    virtual boost::python::list xData2(const std::string& regappName) const;
    void                xDataTransformBy(const AcGeMatrix3d& xform) const;
    Adesk::Boolean      isEraseStatusToggled() const;
    Adesk::Boolean      isErased() const;
    Adesk::Boolean      isReadEnabled() const;
    Adesk::Boolean      isWriteEnabled() const;
    Adesk::Boolean      isNotifyEnabled() const;
    Adesk::Boolean      isModified() const;
    Adesk::Boolean      isModifiedXData() const;
    Adesk::Boolean      isModifiedGraphics() const;
    Adesk::Boolean      isNewObject() const;
    Adesk::Boolean      isNotifying() const;
    Adesk::Boolean      isUndoing() const;
    Adesk::Boolean      isCancelling() const;
    Adesk::Boolean      isReallyClosing() const;
    Adesk::Boolean      isTransactionResident() const;
    Adesk::Boolean      isAProxy() const;
    void                assertReadEnabled() const;
    void                assertWriteEnabled() const;
    void                assertNotifyEnabled() const;
    bool                isUndoRecordingDisabled() const;
    void                disableUndoRecording(Adesk::Boolean disable) const;
    void                addPersistentReactor(const PyDbObjectId& objId) const;
    void                removePersistentReactor(const PyDbObjectId& objId) const;
    bool                hasPersistentReactor(const PyDbObjectId& objId) const;
    bool                hasFields(void) const;
    PyDbObjectId        getField1() const;
    PyDbObjectId        getField2(const std::string& propName) const;
    PyDbObjectId        setField1(PyDbField& pField) const;
    PyDbObjectId        setField2(const std::string& propName, PyDbField& pField) const;
    PyDbHandle          getHandle() const;
    void                removeField1(const PyDbObjectId& fieldId) const;
    void                removeField2(const std::string& propName) const;
    PyDbObjectId        getFieldDictionary(void) const;
    void                addReactor(PyDbObjectReactor& pReactor) const;
    void                removeReactor(PyDbObjectReactor& pReactor) const;
    void                snoop(PyDbSnoopDwgFiler& filer) const;
    void                snoopdxf(PyDbSnoopDxfFiler& filer) const;
    PyDbObject          deepClone1(PyDbObject& pOwnerObject, PyDbIdMapping& idMap) const;
    PyDbObject          deepClone2(PyDbObject& pOwnerObject, PyDbIdMapping& idMap, Adesk::Boolean isPrimary) const;
    PyDbObject          wblockClone1(PyRxObject& pOwnerObject, PyDbIdMapping& idMap) const;
    PyDbObject          wblockClone2(PyRxObject& pOwnerObject, PyDbIdMapping& idMap, Adesk::Boolean isPrimary) const;
    void                xmitPropagateModify() const;
    void                setAcDbObjectIdsInFlux() const;
    Adesk::Boolean      isAcDbObjectIdsInFlux() const;

    boost::python::object getBinaryData(const std::string& key) const;
    PyDbObjectId        setBinaryData(const std::string& key, const boost::python::object& inbuf) const;

    boost::python::object getXDBinaryData(const std::string& key) const;
    void                  setXDBinaryData(const std::string& key, const boost::python::object& inbuf) const;

    static PyRxClass    desc();
    static std::string  className();
    static PyDbObject   cloneFrom(const PyRxObject& src);
    static PyDbObject   cast(const PyRxObject& src);
public:
    AcDbObject* impObj(const std::source_location& src = std::source_location::current()) const;
};

inline AcArray<AcDbObject*> PyListToPyDbObjectArray(const boost::python::object& iterable)
{
    AcArray<AcDbObject*> arr;
    auto vec = py_list_to_std_vector<PyDbObject>(iterable);
    for (const auto& item : vec)
        arr.append(item.impObj());
    return arr;
}

inline boost::python::list AcDbObjectArrayToPyList(const AcArray<AcDbObject*>& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (auto item : arr)
        pyPyList.append(PyDbObject(item, true));
    return pyPyList;
}

template<typename T>
inline T PyDbObjectCast(const PyRxObject& src)
{
    T dest(nullptr, false);
    PyRxObject tdbo = src;
    std::swap(tdbo.m_pyImp, dest.m_pyImp);
    return dest;
}

template<typename T1, typename T2>
inline T1 PyDbObjectCloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(T2::desc()))
        throw PyErrorStatusException(eNotThatKindOfClass);
    return T1(static_cast<T2*>(src.impObj()->clone()), true);
}


// TODO: This could be done better 
// boost::python::wrapper<> causes issues with subclassing i couldn't solve
// just made two classes, one for AcDbObjectReactor, and AcDbEntityReactor
// the todo part is attempt to remove code duplication
//---------------------------------------------------------------------------------------- -
//PyDbObjectReactorImpl
class PyDbObjectReactorImpl : public AcDbObjectReactor
{
public:
    PyDbObjectReactorImpl() = default;
    PyDbObjectReactorImpl(PyDbObjectReactor* ptr);
    virtual ~PyDbObjectReactorImpl() override = default;
    virtual void    cancelled(const AcDbObject* pObj) override;
    virtual void    copied(const AcDbObject* src, const AcDbObject* newObj) override;
    virtual void    erased(const AcDbObject*, Adesk::Boolean bErasing) override;
    virtual void    goodbye(const AcDbObject* ptr) override;
    virtual void    openedForModify(const AcDbObject* ptr) override;
    virtual void    modified(const AcDbObject* ptr)override;
    virtual void    subObjModified(const AcDbObject* ptr, const AcDbObject* subObj) override;
    virtual void    modifyUndone(const AcDbObject* ptr) override;
    virtual void    modifiedXData(const AcDbObject* ptr) override;
    virtual void    unappended(const AcDbObject* ptr) override;
    virtual void    reappended(const AcDbObject* ptr) override;
    virtual void    objectClosed(const AcDbObjectId id) override;

public:
    PyDbObjectReactor* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    PyDbObjectReactor* m_backPtr = nullptr;
};

//---------------------------------------------------------------------------------------- -
//PyDbObjectReactor
void makePyDbObjectReactorWrapper();
class PyDbObjectReactor : public PyRxObject, public boost::python::wrapper<PyDbObjectReactor>
{
public:
    PyDbObjectReactor();
    virtual ~PyDbObjectReactor() = default;
    void        cancelled(const PyDbObject& pObj);
    void        copied(const PyDbObject& src, const PyDbObject& newObj);
    void        erased(const PyDbObject& src, Adesk::Boolean bErasing);
    void        goodbye(const PyDbObject& ptr);
    void        openedForModify(const PyDbObject& ptr);
    void        modified(const PyDbObject& ptr);
    void        subObjModified(const PyDbObject& ptr, const PyDbObject& subObj);
    void        modifyUndone(const PyDbObject& ptr);
    void        modifiedXData(const PyDbObject& ptr);
    void        unappended(const PyDbObject& ptr);
    void        reappended(const PyDbObject& ptr);
    void        objectClosed(const PyDbObjectId& id);
public:
    static PyRxClass    desc();
    static std::string  className();

public:
    AcDbObjectReactor* impObj(const std::source_location& src = std::source_location::current()) const;

public://prevent reentry on error
    bool reg_cancelled = true;
    bool reg_copied = true;
    bool reg_erased = true;
    bool reg_goodbye = true;
    bool reg_openedForModify = true;
    bool reg_modified = true;
    bool reg_subObjModified = true;
    bool reg_modifyUndone = true;
    bool reg_modifiedXData = true;
    bool reg_unappended = true;
    bool reg_reappended = true;
    bool reg_objectClosed = true;
};

//---------------------------------------------------------------------------------------- -
//AcDbEntityReactorImpl
class AcDbEntityReactorImpl : public AcDbEntityReactor
{
public:
    AcDbEntityReactorImpl() = default;
    AcDbEntityReactorImpl(PyDbEntityReactor* ptr);
    virtual ~AcDbEntityReactorImpl() override = default;
    virtual void        cancelled(const AcDbObject* pObj) override;
    virtual void        copied(const AcDbObject* src, const AcDbObject* newObj) override;
    virtual void        erased(const AcDbObject*, Adesk::Boolean bErasing) override;
    virtual void        goodbye(const AcDbObject* ptr) override;
    virtual void        openedForModify(const AcDbObject* ptr) override;
    virtual void        modified(const AcDbObject* ptr)override;
    virtual void        subObjModified(const AcDbObject* ptr, const AcDbObject* subObj) override;
    virtual void        modifyUndone(const AcDbObject* ptr) override;
    virtual void        modifiedXData(const AcDbObject* ptr) override;
    virtual void        unappended(const AcDbObject* ptr) override;
    virtual void        reappended(const AcDbObject* ptr) override;
    virtual void        objectClosed(const AcDbObjectId id) override;
    virtual void        modifiedGraphics(const AcDbEntity*) override;
    virtual void        dragCloneToBeDeleted(const AcDbEntity* pOriginalObj, const AcDbEntity* pClone) override;
public:
    PyDbEntityReactor* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    PyDbEntityReactor* m_backPtr = nullptr;
};

//---------------------------------------------------------------------------------------- -
//PyDbEntityReactor
void makePyDbEntityReactorWrapper();
class PyDbEntityReactor : public PyRxObject, public boost::python::wrapper<PyDbEntityReactor>
{
public:
    PyDbEntityReactor();
    virtual ~PyDbEntityReactor() = default;
    void        cancelled(const PyDbObject& pObj);
    void        copied(const PyDbObject& src, const PyDbObject& newObj);
    void        erased(const PyDbObject& src, bool bErasing);
    void        goodbye(const PyDbObject& ptr);
    void        openedForModify(const PyDbObject& ptr);
    void        modified(const PyDbObject& ptr);
    void        subObjModified(const PyDbObject& ptr, const PyDbObject& subObj);
    void        modifyUndone(const PyDbObject& ptr);
    void        modifiedXData(const PyDbObject& ptr);
    void        unappended(const PyDbObject& ptr);
    void        reappended(const PyDbObject& ptr);
    void        objectClosed(const PyDbObjectId& id);
    void        modifiedGraphics(const PyDbEntity& ent);
    void        dragCloneToBeDeleted(const PyDbEntity& pOriginalObj, const  PyDbEntity& pClone);
public:
    static PyRxClass    desc();
    static std::string  className();

public:
    AcDbEntityReactor* impObj(const std::source_location& src = std::source_location::current()) const;

public://prevent reentry on error
    bool reg_cancelled = true;
    bool reg_copied = true;
    bool reg_erased = true;
    bool reg_goodbye = true;
    bool reg_openedForModify = true;
    bool reg_modified = true;
    bool reg_subObjModified = true;
    bool reg_modifyUndone = true;
    bool reg_modifiedXData = true;
    bool reg_unappended = true;
    bool reg_reappended = true;
    bool reg_objectClosed = true;
    bool reg_modifiedGraphics = true;
    bool reg_dragCloneToBeDeleted = true;
};

#pragma pack (pop)