#pragma once

class PyDbDatabase;

void makeEdCoreWrapper();

class EdCore
{
public:
  static Acad::ErrorStatus xrefDetach1(const std::string& XrefBlockname);
  static Acad::ErrorStatus xrefDetach2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& db);
};

