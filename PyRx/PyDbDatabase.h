#pragma once
#include "PyRxObject.h"

class PyDbObjectId;

void makeAcDbDatabaseWrapper();

class PyDbDatabase : public PyRxObject
{
public:
    PyDbDatabase();
    PyDbDatabase(AcDbDatabase* pDb);
    ~PyDbDatabase();
    double angbase() const;
    bool angdir() const;
    bool annoAllVisible() const;
    bool annotativeDwg() const;
    int approxNumObjects() const;


    Acad::ErrorStatus create(bool buildDefaultDrawing, bool noDocument);
    Acad::ErrorStatus readDwgFile(const char* fileName);
    std::string getFilename();

    PyDbObjectId blockTableId() const;
    PyDbObjectId modelspaceId() const;

    static std::string className();
private:
    AcDbDatabase* impObj() const;
};


