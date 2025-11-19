#pragma once

#ifdef BRXAPP

class PyRxObject;

void makePyBrxCoreWrapper();

class PyBrxCore
{
public:
    static bool isLicenseAvailable(BricsCAD::LicensedFeature feature);
    static boost::python::list getOpenObjects();

    //TODO
    //static void getConstraintsGroup1(const PyDbObjectId& blockId);
    //static void getConstraintsGroup2(const PyDbObjectId& blockId, bool createIfNotExist);
    //static void getAllConstraintsGroups(const PyDbDatabase& db);

    static boost::python::list  getBlockParametersNames(const PyDbObjectId& blockRefId);
    static void                 setBlockParameterExpression(const PyDbObjectId& blockRefId, const std::string& name, const std::string& expr);
    static std::string          getBlockParameterExpression(const PyDbObjectId& blockRefId, const std::string& name);
    static double               getBlockParameterValue(const PyDbObjectId& blockRefId, const std::string& name);
    static std::string          getEntityGuiName(const PyDbObjectId& entId);
    static void                 setEntityGuiName(const PyDbObjectId& entId, const std::string& name);
    static bool                 blockParameterHasStringValue(const PyDbObjectId& blockRefId, const std::string& name);
    static std::string          getBlockParameterStringValue(const PyDbObjectId& blockRefId, const std::string& name);
    static std::string          effectiveBlockRefName(const PyDbObjectId& blockRefId);
    static PyDbObjectId         effectiveBlockTableRecord(const PyDbObjectId& blockRefId);
    static bool                 removeConstraints(const PyDbObjectId& id);
    static bool                 removeConstraintsFromDatabase(const PyDbDatabase& db);
};


#endif