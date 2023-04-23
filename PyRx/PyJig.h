#pragma once
#include "PyRxObject.h"

class PyDbEntity;
class PyDbObjectId;

class PyJigBase : public AcEdJig
{
public:
    PyJigBase();
    virtual ~PyJigBase() override = default;
    virtual AcDbEntity* entity() const;
    virtual AcEdJig::DragStatus sampler();
    virtual Adesk::Boolean update();
};


void makeAcEdJigWrapper();

class PyJig : public PyJigBase, public boost::python::wrapper<PyJig>

{
public:
    PyJig(const PyDbEntity& ent);
    virtual ~PyJig() = default;

    AcEdJig::DragStatus drag1();
#ifdef NEVER //TODO:
    AcEdJig::DragStatus drag2(const AcEdDragStyle& style);
#endif

    virtual AcEdJig::DragStatus sampler();
    virtual Adesk::Boolean update();

    PyDbObjectId append1();

    std::string keywordList1();
    void        setKeywordList1(const std::string& val);

    std::string dispPrompt1();
    void        setDispPrompt1(const std::string& val);

    boost::python::tuple acquireString1();

    boost::python::tuple acquireAngle1();
    boost::python::tuple acquireAngle2(const AcGePoint3d& basePnt);

    boost::python::tuple acquireDist1();
    boost::python::tuple acquireDist2(const AcGePoint3d& basePnt);

    boost::python::tuple acquirePoint1();
    boost::python::tuple acquirePoint2(const AcGePoint3d& basePnt);

    AcEdJig::CursorType specialCursorType1();
    void                setSpecialCursorType1(AcEdJig::CursorType val);

    AcEdJig::UserInputControls userInputControls1();
    void                       setUserInputControls1(AcEdJig::UserInputControls val);

    virtual AcDbEntity* entity() const override;

    static std::string className();

    AcDbEntity* m_pEnt = nullptr;

};

