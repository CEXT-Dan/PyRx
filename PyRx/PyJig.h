#pragma once
#include "PyRxObject.h"

class PyDbEntity;
class PyDbObjectId;

void makeAcEdJigWrapper();

class PyJig : public PyRxObject

{
public:
    PyJig();
    virtual ~PyJig() = default;

    AcEdJig::DragStatus drag1();
#ifdef NEVER //TODO:
    AcEdJig::DragStatus drag2(const AcEdDragStyle& style);
#endif

    virtual AcEdJig::DragStatus sampler();
    virtual Adesk::Boolean update();

    PyDbObjectId append();

    std::string keywordList();
    void        setKeywordList(const std::string& val);

    std::string dispPrompt();
    void        setDispPrompt(const std::string& val);

    boost::python::tuple acquireString();

    boost::python::tuple acquireAngle1();
    boost::python::tuple acquireAngle2(const AcGePoint3d& basePnt);

    boost::python::tuple acquireDist1();
    boost::python::tuple acquireDist2(const AcGePoint3d& basePnt);

    boost::python::tuple acquirePoint1();
    boost::python::tuple acquirePoint2(const AcGePoint3d& basePnt);

    AcEdJig::CursorType specialCursorType();
    void                setSpecialCursorType(AcEdJig::CursorType val);

    AcEdJig::UserInputControls userInputControls();
    void                       setUserInputControls(AcEdJig::UserInputControls val);

    virtual PyDbEntity entity() const;

    static std::string className();
public:
    AcEdJig* impObj() const;
};

