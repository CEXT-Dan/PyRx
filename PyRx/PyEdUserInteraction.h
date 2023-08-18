#pragma once
class PyRxClass;

class PyApDocument;
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
    virtual ~PyEdUserInteraction(void);
protected:
    void userInteraction(AcApDocument* pDocument, bool prompting);
    void undoUserInteraction();
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
    void    calcHitPoint();

    static bool addObjectContextMenu(PyRxClass& pClass, PyEdUIContext& pContext);
    static bool removeObjectContextMenu(PyRxClass& pClass, PyEdUIContext& pContext);
    static bool addDefaultContextMenu1(PyEdUIContext& pContext);
    static bool addDefaultContextMenu2(PyEdUIContext& pContext, const std::string& appName);
    static bool removeDefaultContextMenu(PyEdUIContext& pContext);
};