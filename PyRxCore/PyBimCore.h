#pragma once
#ifdef BRXAPP

class PyDbDatabase;
class PyDbObjectId;
class PyDbFullSubentPath;

//---------------------------------------------------------------------------------------- -
//PyBimCore
void makePyBimCoreWrapper();

class PyBimCore
{
public:
    static boost::python::list  getAnchoredBlockReferences(const PyDbDatabase& db);
    static bool                 isAnchoredBlockRef(const PyDbObjectId& blockRefId);
    static PyDbFullSubentPath   getAnchorFace(const PyDbObjectId& anchoredBlockRefId);
    static PyDbFullSubentPath   queryValidAnchorPt(const AcGePoint3d& point, const PyDbDatabase& pDb);
    static PyDbObjectId         createAnchoredBlockReference(const PyDbObjectId& blockRefId, const PyDbFullSubentPath& faceSubentPath, const AcGePoint3d& pointOnFace,bool keepOrientation);
    static void                 unAnchorBlockReference(const PyDbObjectId& blockRefId);
    static boost::python::tuple isSimilarGeometry(const boost::python::list& firstSet, const boost::python::list& secondSet);
    static boost::python::tuple findSimilarGeometry(const boost::python::list& matchSet, const boost::python::list& searchSet);
    static boost::python::tuple findSimilar3dSolids(const boost::python::list& entitySet);
    static boost::python::tuple findMatchingBlockDefinition(const boost::python::list& entitySet);
    static boost::python::tuple matchEntitiesToBlockDefinitions(const boost::python::list& entitySet);
    static boost::python::tuple replaceGeometryByBlocks(const boost::python::tuple& similarGroups);
};

#endif
