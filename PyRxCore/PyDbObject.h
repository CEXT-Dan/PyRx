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
    PyDbObject(const PyDbObjectId&);
    PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    inline virtual ~PyDbObject() override = default;
    void                addContext(const PyDbObjectContext& ctx);
    void                removeContext(const PyDbObjectContext& ctx);
    AnnotativeStates    isAnnotative() const;
    void                setAnnotative(AnnotativeStates status);
    PyDbObjectId        objectId() const;
    PyDbObjectId        ownerId() const;
    void                setOwnerId(const PyDbObjectId& objId);
    PyDbDatabase        database() const;
    void                createExtensionDictionary();
    PyDbObjectId        extensionDictionary() const;
    void                releaseExtensionDictionary();
    void                close();
    void                upgradeOpen();
    void                upgradeFromNotify(Adesk::Boolean& wasWritable);
    void                downgradeOpen();
    void                downgradeToNotify(Adesk::Boolean wasWritable);
    void                cancel();
    void                erase1();
    void                erase2(Adesk::Boolean erasing);
    void                handOverTo(PyDbObject& newObject, Adesk::Boolean keepXData, Adesk::Boolean keepExtDict);
    void                swapIdWith(PyDbObjectId& otherId, Adesk::Boolean swapXdata, Adesk::Boolean swapExtDict);
    bool                hasXData(const std::string& regappName);
    void                setXData(const boost::python::list& xdata);
    virtual boost::python::list xData1() const;
    virtual boost::python::list xData2(const std::string& regappName) const;
    void                xDataTransformBy(const AcGeMatrix3d& xform);
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
    void                assertWriteEnabled();
    void                assertNotifyEnabled() const;
    bool                isUndoRecordingDisabled() const;
    void                disableUndoRecording(Adesk::Boolean disable);
    void                addPersistentReactor(const PyDbObjectId& objId);
    void                removePersistentReactor(const PyDbObjectId& objId);
    bool                hasPersistentReactor(const PyDbObjectId& objId) const;
    bool                hasFields(void) const;
    PyDbObjectId        getField1();
    PyDbObjectId        getField2(const std::string& propName);
    PyDbObjectId        setField1(PyDbField& pField);
    PyDbObjectId        setField2(const std::string& propName, PyDbField& pField);
    PyDbHandle          getHandle() const;
    void                removeField1(const PyDbObjectId& fieldId);
    void                removeField2(const std::string& propName);
    PyDbObjectId        getFieldDictionary(void) const;
    void                addReactor(PyDbObjectReactor& pReactor) const;
    void                removeReactor(PyDbObjectReactor& pReactor) const;
    void                snoop(PyDbSnoopDwgFiler& filer);
    PyDbObject          deepClone1(PyDbObject& pOwnerObject, PyDbIdMapping& idMap);
    PyDbObject          deepClone2(PyDbObject& pOwnerObject, PyDbIdMapping& idMap, Adesk::Boolean isPrimary);
    PyDbObject          wblockClone1(PyRxObject& pOwnerObject, PyDbIdMapping& idMap);
    PyDbObject          wblockClone2(PyRxObject& pOwnerObject, PyDbIdMapping& idMap, Adesk::Boolean isPrimary);
    void                xmitPropagateModify() const;
    void                setAcDbObjectIdsInFlux();
    Adesk::Boolean      isAcDbObjectIdsInFlux() const;

    boost::python::object getBinaryData(const std::string& key);
    void                  setBinaryData(const std::string& key, const boost::python::object& inbuf);

    static PyRxClass    desc();
    static std::string  className();
    static PyDbObject   cloneFrom(const PyRxObject& src);
    static PyDbObject   cast(const PyRxObject& src);
public:
    inline AcDbObject*  impObj(const std::source_location& src = std::source_location::current()) const;
};

template<typename T>
inline T PyDbObjectCast(const PyRxObject& src)
{
    T dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

template<typename T1, typename T2>
inline T1 PyDbObjectCloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(T2::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
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