#pragma once

class PyDbObjectId;
class PyDbDatabase;

void makeAcEditorWrapper();

class PyAcEditor
{
public:
    static void                 alert(const std::string& prompt);//
    static bool                 arxLoad(const std::string& path);//
    static bool                 arxUnload(const std::string& app);//
    static Acad::ErrorStatus    audit(const PyDbDatabase& db, bool bFixErrors);//
    static Acad::ErrorStatus    audit2(const PyDbDatabase& db, bool bFixErrors, bool bCmdLnEcho);//
    static bool                 cmdS(const boost::python::list& lst);//
    static std::string          findFile(const std::string& file);//
    static std::string          findTrustedFile(const std::string& file);//
    static boost::python::list  arxLoaded();//
    static boost::python::tuple getInteger(const std::string& prompt);
    static boost::python::tuple getDouble(const std::string& prompt);
    static boost::python::tuple getAngle(const AcGePoint3d& basePt, const std::string& prompt);
    static boost::python::tuple getPoint1(const std::string& prompt);
    static boost::python::tuple getPoint2(const AcGePoint3d& basePt, const std::string& prompt);
    static boost::python::tuple getDist1(const std::string& prompt);
    static boost::python::tuple getDist2(const AcGePoint3d& basePt, const std::string& prompt);
    static boost::python::tuple getString(int cronly, const std::string& prompt);
    static boost::python::tuple entSel(const std::string& prompt);
    static boost::python::tuple select1();
    static boost::python::tuple select2(const boost::python::list& filter);
    static boost::python::tuple select3(const std::string& add, const std::string& remove);
    static boost::python::tuple select4(const std::string& add, const std::string& remove, const boost::python::list& filter);
    static boost::python::tuple selectAll1();
    static boost::python::tuple selectAll2(const boost::python::list& filter);
    static boost::python::tuple selectWindow1(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
    static boost::python::tuple selectWindow2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::list& filter);
    static boost::python::tuple selectFence1(const boost::python::list& points);
    static boost::python::tuple selectFence2(const boost::python::list& points, const boost::python::list& filter);
    static boost::python::tuple selectWindowPolygon1(const boost::python::list& points);
    static boost::python::tuple selectWindowPolygon2(const boost::python::list& points, const boost::python::list& filter);
    static boost::python::tuple selectPrevious1();
    static boost::python::tuple selectPrevious2(const boost::python::list& filter);
    static boost::python::tuple selectLast1();
    static boost::python::tuple selectLast2(const boost::python::list& filter);
    static boost::python::tuple ssget1(std::string args, const boost::python::object& arg1, const boost::python::object& arg2);
    static boost::python::tuple ssget2(std::string args, const boost::python::object& arg1, const boost::python::object& arg2, const boost::python::list& filter);
    static AcGeMatrix3d         curUCS();//
    static Acad::ErrorStatus    setCurUCS(const AcGeMatrix3d& mat);//
    static PyDbObjectId         activeViewportId();//
    static Acad::PromptStatus   initGet(int val, const std::string& skwl);
    static boost::python::tuple getKword(const std::string& skwl);
    static boost::python::object getVar(const std::string& sym);//
    static bool                 setVar(const std::string& sym, const  boost::python::object&);//

    static std::string className();
};

