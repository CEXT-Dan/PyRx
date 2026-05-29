#pragma once
#pragma pack (push, 8)

enum PromptCondition
{
    eNone = 0,
    eNoEmpty = 1,
    eNoZero = 1,
    eNoNegative = 2,
};


class PyDbObjectId;
class PyDbDatabase;
class PyApDocument;
class PyRxClass;

void makePyEditorWrapper();

class PyAcEditor
{

    using bpobject = boost::python::object;
    using bplist = boost::python::list;
    using bpdict = boost::python::dict;
    using bptuple = boost::python::tuple;

public:

    static bptuple getCorner(const AcGePoint3d& basePt, const std::string& prompt);

    static bptuple getInteger1(const std::string& prompt);
    static bptuple getInteger2(const std::string& prompt, PromptCondition condition);

    static bptuple getDouble1(const std::string& prompt);
    static bptuple getDouble2(const std::string& prompt, PromptCondition condition);

    static bptuple getAngle(const AcGePoint3d& basePt, const std::string& prompt);
    static bptuple getPoint1(const std::string& prompt);
    static bptuple getPoint2(const AcGePoint3d& basePt, const std::string& prompt);
    static bptuple getDist1(const std::string& prompt);
    static bptuple getDist2(const AcGePoint3d& basePt, const std::string& prompt);

    static bptuple getString1(const std::string& prompt);
    static bptuple getString2(int cronly, const std::string& prompt);

    static bptuple getString3(const std::string& prompt, PromptCondition condition);
    static bptuple getString4(int cronly, const std::string& prompt, PromptCondition condition);

    static bptuple entSel0();
    static bptuple entSel1(const std::string& prompt);
    static bptuple entSel2(const std::string& prompt, const PyRxClass& desc);
    static bptuple entSel3(const std::string& prompt, const boost::python::list& filter);
    static bptuple entSel4(const boost::python::list& filter);
    static bptuple entSel5(const PyRxClass& desc);

    static bptuple nEntSelP1(const std::string& prompt);
    static bptuple nEntSelP2(const std::string& prompt, const AcGePoint3d& ptres);
    static bptuple nEntSelPEx1(const std::string& prompt, int uTransSpaceFlag);
    static bptuple nEntSelPEx2(const std::string& prompt, const AcGePoint3d& ptres, int uTransSpaceFlag);

    static bptuple select1();
    static bptuple select2(const bpobject& filter);
    static bptuple select3(const bpobject& filter, const bpobject& rm);

    static bptuple selectPrompt1(const std::string& add, const std::string& remove);
    static bptuple selectPrompt2(const std::string& add, const std::string& remove, const bpobject& filter);
    static bptuple selectPrompt3(const std::string& add, const std::string& remove, const bpobject& filter, const bpobject& rm);

    static bptuple selectKeyword1(const bpobject& prompt, const bpobject& kw, const bpobject& filter, const bpobject& cw);
    static bptuple selectKeyword2(const bpobject& prompt, const bpobject& kw, const bpobject& filter, const bpobject& cw, const bpobject& ocw);
    static bptuple selectKeyword3(const bpobject& prompt, const bpobject& kw, const bpobject& filter, const bpobject& cw, const bpobject& ocw, const bpobject& rm);

    static bptuple selectAll1();
    static bptuple selectAll2(const bpobject& filter);
    static bptuple selectAll3(const bpobject& filter, const bpobject& rm);

    static bptuple selectImplied();

    static bptuple selectWindow1(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
    static bptuple selectWindow2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const bpobject& filter);
    static bptuple selectWindow3(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const bpobject& filter, const bpobject& rm);

    static bptuple selectFence1(const bpobject& points);
    static bptuple selectFence2(const bpobject& points, const bpobject& filter);
    static bptuple selectFence3(const bpobject& points, const bpobject& filter, const bpobject& rm);

    static bptuple selectWindowPolygon1(const bpobject& points);
    static bptuple selectWindowPolygon2(const bpobject& points, const bpobject& filter);
    static bptuple selectWindowPolygon3(const bpobject& points, const bpobject& filter, const bpobject& rm);

    static bptuple selectPrevious1();
    static bptuple selectPrevious2(const bpobject& filter);

    static bptuple selectLast1();
    static bptuple selectLast2(const bpobject& filter);

    static bptuple ssget1(const std::string& args, const bpobject& arg1, const bpobject& arg2);
    static bptuple ssget2(const std::string& args, const bpobject& arg1, const bpobject& arg2, const bpobject& filter);
    static bptuple ssget3(const std::string& args, const bpobject& arg1, const bpobject& arg2, const bpobject& filter, const bpobject& rm);

    static bptuple ssgetkw1(const std::string& args, const bpobject& arg1, const bpobject& arg2, const bpobject& filter, const bpobject& cw);
    static bptuple ssgetkw2(const std::string& args, const bpobject& arg1, const bpobject& arg2, const bpobject& filter, const bpobject& cw, const bpobject& ocw);
    static bptuple ssgetkw3(const std::string& args, const bpobject& arg1, const bpobject& arg2, const bpobject& filter, const bpobject& cw, const bpobject& ocw, const bpobject& rm);

    static AcGeMatrix3d         curUCS();
    static void                 setCurUCS(const AcGeMatrix3d& mat);
    static PyDbObjectId         activeViewportId();
    static PyDbObjectId         curViewportObjectId();
    static AcGeVector3d         ucsNormalVector();
    static AcGeVector3d         ucsXDir();
    static AcGeVector3d         ucsYDir();
    static Acad::PromptStatus   initGet(int val, const std::string& skwl);
    static std::string          getInput();
    static bptuple getKword(const std::string& skwl);
    static boost::python::list  traceBoundary(const AcGePoint3d& seedPoint, bool detectIslands);
    static boost::python::list  getCurrentSelectionSet();
    static void                 setAllowDuplicateSelection(PyApDocument& doc, bool flag);
    static bool                 duplicateSelectionsAllowed(PyApDocument& doc);
    static void                 regen();
    static int                  getViewportNumber(int ptx, int pty);
    static std::string          className();
};

#pragma pack (pop)
