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
    static std::string className();
};

