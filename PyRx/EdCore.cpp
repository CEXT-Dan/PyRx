#include "stdafx.h"
#include "EdCore.h"

#include "PyDbDatabase.h"

using namespace boost::python;

void makeEdCoreWrapper()
{
    class_<EdCore>("Core")
        .def("xrefDetach", &EdCore::xrefDetach1)//.staticmethod("xrefDetach")
        .def("xrefDetach", &EdCore::xrefDetach2).staticmethod("xrefDetach")
        ;
}

Acad::ErrorStatus EdCore::xrefDetach1(const std::string& XrefBlockname)
{
    return acedXrefDetach(utf8_to_wstr(XrefBlockname).c_str());
}

Acad::ErrorStatus EdCore::xrefDetach2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& db)
{
    return acedXrefDetach(utf8_to_wstr(XrefBlockname).c_str(), bQuiet, db.impObj());
}
