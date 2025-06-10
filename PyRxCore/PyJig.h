#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
class PyDbEntity;
class PyDbObjectId;

class PyGiWorldDraw;
class PyGiViewportDraw;

//--------------------------------------------------------------------------------------------------------
//PyJig
void makePyEdJigWrapper();
class PyJig : public AcEdJig, public boost::python::wrapper<PyJig>
{
public:
    PyJig(const PyDbEntity& ent);
    virtual ~PyJig() override = default;
    AcEdJig::DragStatus         dragwr1();
#if !defined(_BRXTARGET250)
    AcEdJig::DragStatus         dragwr2(const AcEdDragStyle& style);
#endif
    virtual AcEdJig::DragStatus sampler() override;
    virtual Adesk::Boolean      update() override;
    virtual AcDbEntity*/*     */entity() const override;
    PyDbObjectId                appendwr();
    std::string                 keywordListWr();
    void                        setKeywordListWr(const std::string& val);
    std::string                 dispPromptWr();
    void                        setDispPromptWr(const std::string& val);
    boost::python::tuple        acquireStringWr();
    boost::python::tuple        acquireAngleWr1();
    boost::python::tuple        acquireAngleWr2(const AcGePoint3d& basePnt);
    boost::python::tuple        acquireDistWr1();
    boost::python::tuple        acquireDistWr2(const AcGePoint3d& basePnt);
    boost::python::tuple        acquirePointWr1();
    boost::python::tuple        acquirePointWr2(const AcGePoint3d& basePnt);
    AcEdJig::CursorType         specialCursorTypeWr();
    void                        setSpecialCursorTypeWr(AcEdJig::CursorType val);
    AcEdJig::UserInputControls  userInputControlsWr();
    void                        setUserInputControlsWr(AcEdJig::UserInputControls val);
    static std::string          className();
public:
    AcDbEntity* m_pEnt = nullptr;
};

//--------------------------------------------------------------------------------------------------------
//PyDrawJig
void makePyEdDrawJigWrapper();

class PyDrawJig : public AcEdJig, public AcDbEntity, public boost::python::wrapper<PyDrawJig>
{
public:
    PyDrawJig();
    virtual ~PyDrawJig() override = default;
    AcEdJig::DragStatus         dragwr1();

#if !defined(_BRXTARGET250)
    AcEdJig::DragStatus         dragwr2(const AcEdDragStyle& style);
#endif
    virtual AcEdJig::DragStatus sampler() override;
    virtual Adesk::Boolean      update() override;
    std::string                 keywordListWr();
    void                        setKeywordListWr(const std::string& val);
    std::string                 dispPromptWr();
    void                        setDispPromptWr(const std::string& val);
    boost::python::tuple        acquireStringWr();
    boost::python::tuple        acquireAngleWr1();
    boost::python::tuple        acquireAngleWr2(const AcGePoint3d& basePnt);
    boost::python::tuple        acquireDistWr1();
    boost::python::tuple        acquireDistWr2(const AcGePoint3d& basePnt);
    boost::python::tuple        acquirePointWr1();
    boost::python::tuple        acquirePointWr2(const AcGePoint3d& basePnt);
    AcEdJig::CursorType         specialCursorTypeWr();
    void                        setSpecialCursorTypeWr(AcEdJig::CursorType val);
    AcEdJig::UserInputControls  userInputControlsWr();
    void                        setUserInputControlsWr(AcEdJig::UserInputControls val);
    virtual Adesk::Boolean      worldDrawWr(PyGiWorldDraw& wd);
    virtual void                viewportDrawWr(PyGiViewportDraw& vd);
    virtual Adesk::Boolean      subWorldDraw(AcGiWorldDraw* wd) override;
    virtual void                subViewportDraw(AcGiViewportDraw* vd) override;
    virtual AcDbEntity*/*     */entity() const override;
    static std::string          className();
};
#pragma pack (pop)
