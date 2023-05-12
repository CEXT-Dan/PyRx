#pragma once
#include "PyRxObject.h"

class PyDbEntity;
class PyDbObjectId;

//--------------------------------------------------------------------------------------------------------
//PyJig
void makeAcEdJigWrapper();

class PyJig : public AcEdJig, public boost::python::wrapper<PyJig>
{
public:
    PyJig(const PyDbEntity& ent);
    virtual ~PyJig() = default;

    AcEdJig::DragStatus dragwr1();
#ifndef BRXAPP
    AcEdJig::DragStatus dragwr2(const AcEdDragStyle& style);
#endif
    virtual AcEdJig::DragStatus sampler() override;
    virtual Adesk::Boolean update() override;
    virtual AcDbEntity* entity() const override;

    PyDbObjectId appendwr();

    std::string keywordListwr();
    void        setKeywordListwr(const std::string& val);

    std::string dispPromptwr();
    void        setDispPromptwr(const std::string& val);

    boost::python::tuple acquireStringwr();

    boost::python::tuple acquireAnglewr1();
    boost::python::tuple acquireAnglewr2(const AcGePoint3d& basePnt);

    boost::python::tuple acquireDistwr1();
    boost::python::tuple acquireDistwr2(const AcGePoint3d& basePnt);

    boost::python::tuple acquirePointwr1();
    boost::python::tuple acquirePointwr2(const AcGePoint3d& basePnt);

    AcEdJig::CursorType specialCursorTypewr();
    void                setSpecialCursorTypewr(AcEdJig::CursorType val);

    AcEdJig::UserInputControls userInputControlswr();
    void                       setUserInputControlswr(AcEdJig::UserInputControls val);

    static std::string className();

public:
    AcDbEntity* m_pEnt = nullptr;
};
