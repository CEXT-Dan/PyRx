#pragma once

class PyDbObjectId;
class PyDbDatabase;

void makeAcEditorWrapper();

class PyAcEditor
{
public:
    void alert(const std::string& prompt);
    bool arxLoad(const std::string& path);
    bool arxUnload(const std::string& app);
    Acad::ErrorStatus audit(const PyDbDatabase& db, bool bFixErrors, bool bCmdLnEcho);
    bool cmdS(const boost::python::list& lst);

    std::string findFile(const std::string& file);
    std::string findTrustedFile(const std::string& file);

    boost::python::list  arxLoaded();
    boost::python::tuple getInteger(const std::string& prompt);
    boost::python::tuple getDouble(const std::string& prompt);
    boost::python::tuple getAngle(const AcGePoint3d& basePt,const std::string& prompt);

    boost::python::tuple getPoint(const std::string& prompt);
    boost::python::tuple getPoint(const AcGePoint3d& basePt,  const std::string& prompt);

    boost::python::tuple getDist(const std::string& prompt);
    boost::python::tuple getDist(const AcGePoint3d& basePt, const std::string& prompt);

    boost::python::tuple getString(int cronly, const std::string& prompt);
    boost::python::tuple entsel(const std::string& prompt);

    boost::python::tuple select1();
    boost::python::tuple select2(const boost::python::list& filter);
    boost::python::tuple select3(const std::string& add, const std::string& remove);
    boost::python::tuple select4(const std::string& add, const std::string& remove, const boost::python::list& filter);


    boost::python::tuple selectAll();
    boost::python::tuple selectAll(const boost::python::list& filter);

    boost::python::tuple selectCrossingWindow1(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
    boost::python::tuple selectCrossingWindow2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::list& filter);




    AcGeMatrix3d curUCS();
    Acad::ErrorStatus setCurUCS(const AcGeMatrix3d& mat);

    PyDbObjectId activeViewportId();


    static std::string className();
};

