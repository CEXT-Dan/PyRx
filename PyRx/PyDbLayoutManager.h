#pragma once
#include "PyRxObject.h"

class PyDbObjectId;
class PyDbDatabase;
class PyDbLayout;
//-----------------------------------------------------------------------------------------
//PyDbLayoutManager
void makePyDbLayoutManagerWrapper();

class PyDbLayoutManager : public PyRxObject
{
public:
    PyDbLayoutManager();
    PyDbLayoutManager(AcDbLayoutManager* ptr, bool autoDelete);
    virtual ~PyDbLayoutManager() override = default;
    Acad::ErrorStatus   setCurrentLayout1(const std::string& newname);
    Acad::ErrorStatus   setCurrentLayout2(const std::string& newname, PyDbDatabase& pDb);
    Acad::ErrorStatus   setCurrentLayoutId(const PyDbObjectId& layoutId);
    std::string         getActiveLayoutName1(bool allowModel);
    std::string         getActiveLayoutName2(bool allowModel, PyDbDatabase& pDb);
    PyDbObjectId        getActiveLayoutBTRId1();
    PyDbObjectId        getActiveLayoutBTRId2(const PyDbDatabase& pDb);
    PyDbObjectId        findLayoutNamed1(const std::string& name);
    PyDbObjectId        findLayoutNamed2(const std::string& name, const PyDbDatabase& pDb);
    bool                layoutExists1(const std::string& name);
    bool                layoutExists2(const std::string& name, const PyDbDatabase& pDb);
    Acad::ErrorStatus   copyLayout1(const std::string& copyname, const std::string& newname);
    Acad::ErrorStatus   copyLayout2(const std::string& copyname, const std::string& newname, const PyDbDatabase& pDb);
    Acad::ErrorStatus   deleteLayout1(const std::string& delname);
    Acad::ErrorStatus   deleteLayout2(const std::string& delname, PyDbDatabase& pDb);
    Acad::ErrorStatus   createLayout1(const std::string& newname, PyDbObjectId& layoutId, PyDbObjectId& blockTableRecId);
    Acad::ErrorStatus   createLayout2(const std::string& newname, PyDbObjectId& layoutId, PyDbObjectId& blockTableRecId, PyDbDatabase& pDb);
    Acad::ErrorStatus   renameLayout1(const std::string& oldname, const std::string& newname);
    Acad::ErrorStatus   renameLayout2(const std::string& oldname, const std::string& newname, PyDbDatabase& pDb);
    Acad::ErrorStatus   cloneLayout1(PyDbLayout& pLBTR, const std::string& newname);
    Acad::ErrorStatus   cloneLayout2(PyDbLayout& pLBTR, const std::string& newname, int newTabOrder, PyDbDatabase& pDb);
    PyDbObjectId        getNonRectVPIdFromClipId(PyDbObjectId& clipId);
    bool                isVpnumClipped1(int index);
    bool                isVpnumClipped2(int index, const PyDbDatabase& pDb);
    int                 countLayouts1();
    int                 countLayouts2(PyDbDatabase& pDb);

    //void              addReactor(AcDbLayoutManagerReactor* newObj);
    //void              removeReactor(AcDbLayoutManagerReactor* delObj)

    static Adesk::ULongPtr      setupForLayouts(PyDbDatabase& pDb);
    static Acad::ErrorStatus    clearSetupForLayouts(Adesk::ULongPtr contextHandle);
    static PyRxClass            desc();
    static std::string          className();
public:
    AcDbLayoutManager* impObj(const std::source_location& src = std::source_location::current()) const;
};


