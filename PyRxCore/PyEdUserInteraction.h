#pragma once

#pragma pack (push, 8)
class PyRxClass;
class PyApDocument;

//-----------------------------------------------------------------------------------------
// PySysVar
void makePySysVarWrapper();

class PySysVarImpl
{
    std::string m_name;
    boost::python::object m_oldobj;
    bool m_doit = true;
public:
    PySysVarImpl(const std::string& name, const boost::python::object& obj);
    ~PySysVarImpl(void);
    void detach(bool flag);
    void set(const std::string& name, const boost::python::object& obj);
    void clear() const;
};

class PySysVar
{
public:
    PySysVar(const std::string& name, const boost::python::object& obj);
    ~PySysVar(void) = default;
    void detach(bool flag);

private:
    std::shared_ptr<PySysVarImpl> m_impl;
};

//-----------------------------------------------------------------------------------------
// PyEdUserInteraction
void makePyEdUserInteractionWrapper();
class PyEdUserInteraction
{
    HWND m_activeWindow;
    std::vector<HWND> m_wnds;
public:
    PyEdUserInteraction();
    PyEdUserInteraction(PyApDocument& pDocument, bool prompting);
    PyEdUserInteraction(AcApDocument* pDocument, bool prompting);
    ~PyEdUserInteraction(void);
protected:
    void beginUserInteraction(AcApDocument* pDocument, bool prompting);
    void endUserInteraction();
};

//-----------------------------------------------------------------------------------------
// PyEdUIContext
void makePyEdUIContextWrapper();

class PyEdUIContext : AcEdUIContext, public boost::python::wrapper<PyEdUIContext>
{
public:
    AcGePoint3d m_hitPoint;
    HMENU m_hmenu = 0;
    bool m_isAlive = false;
public:
    PyEdUIContext();
    virtual ~PyEdUIContext() override;

    virtual void* getMenuContext(const AcRxClass* pClass, const AcDbObjectIdArray& ids);
    virtual void  onCommand(Adesk::UInt32 cmd);
    virtual void  OnUpdateMenu();
    AcGePoint3d   hitPoint() const;

    boost::python::object getMenuContextWr(const PyRxClass& pyclass, const boost::python::list& pyids);
    void    onCommandWr(Adesk::UInt32);
    void    OnUpdateMenuWr();
    void    calcHitPoint() const;

    static bool addObjectContextMenu(PyRxClass& pClass, PyEdUIContext& pContext);
    static bool removeObjectContextMenu(PyRxClass& pClass, PyEdUIContext& pContext);
    static bool addDefaultContextMenu1(PyEdUIContext& pContext);
    static bool addDefaultContextMenu2(PyEdUIContext& pContext, const std::string& appName);
    static bool removeDefaultContextMenu(PyEdUIContext& pContext);
};


#pragma pack (pop)