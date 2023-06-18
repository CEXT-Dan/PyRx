#pragma once

class PyDbDatabase;
class PyDbLayoutManager;
void makeAcDbHostApplicationServicesWrapper();

class PyDbHostApplicationServices
{
public:
    PyDbDatabase workingDatabase() const;
    void setWorkingDatabase(PyDbDatabase& pDatabase);
    std::string findFile1(const std::string& fileName);
    std::string findFile2(const std::string& fileName, const PyDbDatabase& db);
    std::string findFile3(const std::string& fileName, const PyDbDatabase& db, AcDbHostApplicationServices::FindFileHint hint);
    std::string product() const;
    PyDbLayoutManager dbLayoutManager();



protected:
    AcDbHostApplicationServices* pDbHostApp = acdbHostApplicationServices();
};
