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
public:

    static boost::python::tuple getCorner(const AcGePoint3d& basePt, const std::string& prompt);

    static boost::python::tuple getInteger1(const std::string& prompt);
    static boost::python::tuple getInteger2(const std::string& prompt, PromptCondition condition);

    static boost::python::tuple getDouble1(const std::string& prompt);
    static boost::python::tuple getDouble2(const std::string& prompt, PromptCondition condition);

    static boost::python::tuple getAngle(const AcGePoint3d& basePt, const std::string& prompt);
    static boost::python::tuple getPoint1(const std::string& prompt);
    static boost::python::tuple getPoint2(const AcGePoint3d& basePt, const std::string& prompt);
    static boost::python::tuple getDist1(const std::string& prompt);
    static boost::python::tuple getDist2(const AcGePoint3d& basePt, const std::string& prompt);

    static boost::python::tuple getString1(const std::string& prompt);
    static boost::python::tuple getString2(int cronly, const std::string& prompt);

    static boost::python::tuple getString3(const std::string& prompt, PromptCondition condition);
    static boost::python::tuple getString4(int cronly, const std::string& prompt, PromptCondition condition);


    static boost::python::tuple entSel1(const std::string& prompt);
    static boost::python::tuple entSel2(const std::string& prompt, const PyRxClass& desc);
    static boost::python::tuple entSel3(const std::string& prompt, const boost::python::list& filter);
    static boost::python::tuple nEntSelP1(const std::string& prompt);
    static boost::python::tuple nEntSelP2(const std::string& prompt, const AcGePoint3d& ptres);
    static boost::python::tuple nEntSelPEx1(const std::string& prompt, int uTransSpaceFlag);
    static boost::python::tuple nEntSelPEx2(const std::string& prompt, const AcGePoint3d& ptres, int uTransSpaceFlag);
    static boost::python::tuple select1();
    static boost::python::tuple select2(const boost::python::object& filter);
    static boost::python::tuple select3(const std::string& add, const std::string& remove);
    static boost::python::tuple select4(const std::string& add, const std::string& remove, const boost::python::object& filter);
    static boost::python::tuple selectAll1();
    static boost::python::tuple selectAll2(const boost::python::object& filter);
    static boost::python::tuple selectImplied();
    static boost::python::tuple selectWindow1(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
    static boost::python::tuple selectWindow2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::object& filter);
    static boost::python::tuple selectFence1(const boost::python::object& points);
    static boost::python::tuple selectFence2(const boost::python::object& points, const boost::python::object& filter);
    static boost::python::tuple selectWindowPolygon1(const boost::python::object& points);
    static boost::python::tuple selectWindowPolygon2(const boost::python::object& points, const boost::python::object& filter);
    static boost::python::tuple selectPrevious1();
    static boost::python::tuple selectPrevious2(const boost::python::object& filter);
    static boost::python::tuple selectLast1();
    static boost::python::tuple selectLast2(const boost::python::object& filter);
    static boost::python::tuple ssget1(const std::string& args, const boost::python::object& arg1, const boost::python::object& arg2);
    static boost::python::tuple ssget2(const std::string& args, const boost::python::object& arg1, const boost::python::object& arg2, const boost::python::object& filter);
    static AcGeMatrix3d         curUCS();
    static void                 setCurUCS(const AcGeMatrix3d& mat);
    static PyDbObjectId         activeViewportId();
    static PyDbObjectId         curViewportObjectId();
    static AcGeVector3d         ucsNormalVector();
    static AcGeVector3d         ucsXDir();
    static AcGeVector3d         ucsYDir();
    static Acad::PromptStatus   initGet(int val, const std::string& skwl);
    static std::string          getInput();
    static boost::python::tuple getKword(const std::string& skwl);
    static boost::python::list  traceBoundary(const AcGePoint3d& seedPoint, bool detectIslands);
    static boost::python::list  getCurrentSelectionSet();
    static void                 setAllowDuplicateSelection(PyApDocument& doc, bool flag);
    static bool                 duplicateSelectionsAllowed(PyApDocument& doc);
    static void                 regen();
    static int                  getViewportNumber(int ptx, int pty);
    static std::string          className();
};

#pragma pack (pop)
