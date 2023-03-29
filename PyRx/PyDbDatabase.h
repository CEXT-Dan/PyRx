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
    Adesk::Int16 attmode() const;
    Adesk::Int16 aunits() const;
    Adesk::Int16 auprec() const;
    bool blipmode() const;
    PyDbObjectId byBlockLinetype() const;
    PyDbObjectId byBlockMaterial() const;
    PyDbObjectId byLayerLinetype() const;
    PyDbObjectId byLayerMaterial() const;
    bool cameraDisplay() const;
    double cameraHeight() const;
    Adesk::Int16 cDynDisplayMode() const;
    double celtscale() const;
    PyDbObjectId celtype() const;
    AcDb::LineWeight celweight() const; //TODO:: add  AcDb::LineWeight enum
    double chamfera() const;
    double chamferb() const;
    double chamferc() const;
    double chamferd() const;
    std::string classDxfName(const PyRxClass& pClass);
    PyDbObjectId clayer() const;
    Acad::ErrorStatus closeInput(bool bCloseFile);
    PyDbObjectId cmaterial() const;
    Adesk::Int16 cmljust() const;
    double cmlscale() const;
    PyDbObjectId cmlstyleID() const;
    PyDbObjectId colorDictionaryId() const;
    PyDbObjectId continuousLinetype() const;
    Adesk::Int16 coords() const;
    Adesk::UInt32 countEmptyObjects(const Adesk::UInt32 flags);
    PyDbObjectId detailViewStyle() const;
    PyDbObjectId detailViewStyleDictionaryId() const;
    bool dimaso() const;
    Adesk::UInt8 dimAssoc() const;
    int dimfit() const;
    bool dimsho() const;
    PyDbObjectId dimstyle() const;
    PyDbObjectId dimStyleTableId() const;
    int dimunit() const;
    void disablePartialOpen();
    void disableUndoRecording(bool disable);
    bool dispSilh() const;
    Adesk::Int16 dragmode() const;
    PyDbObjectId dragVisStyle() const;
    Adesk::UInt8 drawOrderCtl() const;
    Adesk::UInt8 dwfframe() const;
    bool dwgFileWasSavedByAutodeskSoftware() const;
    Acad::ErrorStatus dxfIn(const std::string& dxfFilename);
    Acad::ErrorStatus dxfOut(const std::string& dxfFilename);
    double elevation() const;
    Adesk::UInt32 eraseEmptyObjects(const Adesk::UInt32 flags);
    AcGePoint3d extmax() const;
    AcGePoint3d extmin() const;
    double facetres() const;
    double filletrad() const;
    bool fillmode() const;
    void forceWblockDatabaseCopy();
    std::string geoCoordinateSystemId() const;
    bool geoMarkerVisibility() const;
    double get3dDwfPrec() const;

    //TODO: Acad::ErrorStatus getAcDbObjectId
    AcDb::PlotStyleNameType getCePlotStyleNameId(PyDbObjectId& id) const;
    bool isAppRegistered(const std::string& pszAppName) const;
    std::string getDimapost() const;
    std::string getDimblk() const;
    std::string getDimblk1() const;
    std::string getDimblk2() const;
    std::string getDimpost() const;


    Acad::ErrorStatus create(bool buildDefaultDrawing, bool noDocument);
    Acad::ErrorStatus readDwgFile(const char* fileName);
    std::string getFilename();

    PyDbObjectId currentSpaceId() const;
    PyDbObjectId blockTableId() const;
    PyDbObjectId modelspaceId() const;

    static std::string className();
private:
    AcDbDatabase* impObj() const;
};


