#pragma once

void makeAcEditorWrapper();

class PyAcEditor
{
public:
    boost::python::tuple getInteger(const std::string& prompt);
    boost::python::tuple getDouble(const std::string& prompt);
    boost::python::tuple getString(int cronly, const std::string& prompt);
    boost::python::tuple entsel(const std::string& prompt);
    boost::python::tuple selectAll();
    boost::python::tuple selectAllf(const boost::python::list& filter);
    static std::string className();
};

