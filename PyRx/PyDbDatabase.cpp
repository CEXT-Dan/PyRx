#include "stdafx.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//---------------------------------------------------------------------------------------------------
// makeAcDbDatabaseWrapper
void makeAcDbDatabaseWrapper()
{
    static auto wrapper = class_<PyDbDatabase, bases<PyRxObject>>("DbDatabase")
        .def(init<>())
        //.def("abortDeepClone", &PyDbDatabase::dummy)
        //.def("addAcDbObject", &PyDbDatabase::dummy)
        //.def("addReactor", &PyDbDatabase::dummy)
        .def("angbase", &PyDbDatabase::angbase)
        .def("angdir", &PyDbDatabase::angdir)
        .def("annoAllVisible", &PyDbDatabase::annoAllVisible)
        .def("annotativeDwg", &PyDbDatabase::annotativeDwg)
        //.def("applyPartialOpenFilters", &PyDbDatabase::dummy)
        .def("approxNumObjects", &PyDbDatabase::approxNumObjects)
        .def("attmode", &PyDbDatabase::attmode)
        .def("aunits", &PyDbDatabase::aunits)
        .def("auprec", &PyDbDatabase::auprec)
        .def("blipmode", &PyDbDatabase::blipmode)
        .def("byBlockLinetype", &PyDbDatabase::byBlockLinetype)

        .def("className", &PyDbDatabase::className)
        .def("getFilename", &PyDbDatabase::getFilename)
        .def("readDwgFile", &PyDbDatabase::readDwgFile)
        .def("blockTableId", &PyDbDatabase::blockTableId)
        .def("modelspaceId", &PyDbDatabase::modelspaceId)
        ;
}

//---------------------------------------------------------------------------------------------------
// PyDbDatabase
PyDbDatabase::PyDbDatabase()
    :PyRxObject(nullptr, false)
{
}

PyDbDatabase::PyDbDatabase(AcDbDatabase* _pDb)
    : PyRxObject(_pDb, false)
{
}

PyDbDatabase::PyDbDatabase(AcDbDatabase* _pDb, bool autoDelete)
    : PyRxObject(_pDb, false)
{
}

PyDbDatabase::~PyDbDatabase()
{
}

double PyDbDatabase::angbase() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->angbase();
    throw PyNullObject();
}

bool PyDbDatabase::angdir() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->angdir();
    throw PyNullObject();
}

bool PyDbDatabase::annoAllVisible() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->annoAllVisible();
    throw PyNullObject();
}

bool PyDbDatabase::annotativeDwg() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->annotativeDwg();
    throw PyNullObject();
}

int PyDbDatabase::approxNumObjects() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->approxNumObjects();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::attmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->attmode();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::aunits() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->aunits();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::auprec() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->auprec();
    throw PyNullObject();
}

bool PyDbDatabase::blipmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->blipmode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byBlockLinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byBlockLinetype());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byBlockMaterial() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byBlockMaterial());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byLayerLinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byLayerLinetype());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::byLayerMaterial() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->byLayerMaterial());
    throw PyNullObject();
}

bool PyDbDatabase::cameraDisplay() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->cameraDisplay();
    throw PyNullObject();
#endif
}

double PyDbDatabase::cameraHeight() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->cameraHeight();
    throw PyNullObject();
#endif
}

Adesk::Int16 PyDbDatabase::cDynDisplayMode() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->cDynDisplayMode();
    throw PyNullObject();
#endif // BRXAPP
}

double PyDbDatabase::celtscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->celtscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::celtype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->celtype());
    throw PyNullObject();
}

AcDb::LineWeight PyDbDatabase::celweight() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->celweight();
    throw PyNullObject();
}

double PyDbDatabase::chamfera() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamfera();
    throw PyNullObject();
}

double PyDbDatabase::chamferb() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamferb();
    throw PyNullObject();
}

double PyDbDatabase::chamferc() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamferc();
    throw PyNullObject();
}

double PyDbDatabase::chamferd() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->chamferd();
    throw PyNullObject();
}

std::string PyDbDatabase::classDxfName(const PyRxClass& pClass)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(imp->classDxfName(pClass.impObj()));
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::clayer() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->clayer());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::closeInput(bool bCloseFile)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->closeInput(bCloseFile);
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::cmaterial() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->cmaterial());
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::cmljust() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->cmljust();
    throw PyNullObject();
}

double PyDbDatabase::cmlscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->cmlscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::cmlstyleID() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->cmlstyleID());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::colorDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->colorDictionaryId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::continuousLinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->continuousLinetype());
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::coords() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->coords();
    throw PyNullObject();
}

Adesk::UInt32 PyDbDatabase::countEmptyObjects(const Adesk::UInt32 flags)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->countEmptyObjects(flags);
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::detailViewStyle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->detailViewStyle());
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::detailViewStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->detailViewStyleDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::dimaso() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimaso();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::dimAssoc() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimAssoc();
    throw PyNullObject();
}

int PyDbDatabase::dimfit() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimfit();
    throw PyNullObject();
}

bool PyDbDatabase::dimsho() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimsho();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimstyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimstyle());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimStyleTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimStyleTableId());
    throw PyNullObject();
}

int PyDbDatabase::dimunit() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dimunit();
    throw PyNullObject();
}

void PyDbDatabase::disablePartialOpen()
{
    auto imp = impObj();
    if (imp != nullptr)
        impObj()->disablePartialOpen();
    throw PyNullObject();
}

void PyDbDatabase::disableUndoRecording(bool disable)
{
    auto imp = impObj();
    if (imp != nullptr)
        impObj()->disableUndoRecording(disable);
    throw PyNullObject();
}

bool PyDbDatabase::dispSilh() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dispSilh();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::dragmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dragmode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dragVisStyle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dragVisStyle());
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::drawOrderCtl() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->drawOrderCtl();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::dwfframe() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dwfframe();
    throw PyNullObject();
}

bool PyDbDatabase::dwgFileWasSavedByAutodeskSoftware() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dwgFileWasSavedByAutodeskSoftware();
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::dxfIn(const std::string& dxfFilename)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dxfIn(utf8_to_wstr(dxfFilename).c_str());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::dxfOut(const std::string& dxfFilename)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->dxfOut(utf8_to_wstr(dxfFilename).c_str());
    throw PyNullObject();
}

double PyDbDatabase::elevation() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->elevation();
    throw PyNullObject();
}

Adesk::UInt32 PyDbDatabase::eraseEmptyObjects(const Adesk::UInt32 flags)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->eraseEmptyObjects(flags);
    throw PyNullObject();
#endif
}

AcGePoint3d PyDbDatabase::extmax() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->extmax();
    throw PyNullObject();
}

AcGePoint3d PyDbDatabase::extmin() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->extmin();
    throw PyNullObject();
}

double PyDbDatabase::facetres() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->facetres();
    throw PyNullObject();
}

double PyDbDatabase::filletrad() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->filletrad();
    throw PyNullObject();
}

bool PyDbDatabase::fillmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->fillmode();
    throw PyNullObject();
}

void PyDbDatabase::forceWblockDatabaseCopy()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        impObj()->forceWblockDatabaseCopy();
    throw PyNullObject();
#endif
}

std::string PyDbDatabase::geoCoordinateSystemId() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(impObj()->geoCoordinateSystemId());
    throw PyNullObject();
#endif
}

bool PyDbDatabase::geoMarkerVisibility() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->geoMarkerVisibility();
    throw PyNullObject();
#endif
}

double PyDbDatabase::get3dDwfPrec() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->get3dDwfPrec();
    throw PyNullObject();
#endif
}

AcDb::PlotStyleNameType PyDbDatabase::getCePlotStyleNameId(PyDbObjectId& id) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->getCePlotStyleNameId(id.m_id);
    throw PyNullObject();
}

bool PyDbDatabase::isAppRegistered(const std::string& pszAppName) const
{
#ifdef ARX2023
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->isAppRegistered(utf8_to_wstr(pszAppName).c_str());
    throw PyNullObject();
#else
    throw PyNotimplementedByHost();
#endif // 
}

std::string PyDbDatabase::dimapost() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(impObj()->dimapost());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimblk() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimblk());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimblk1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimblk1());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::dimblk2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->dimblk2());
    throw PyNullObject();
}

std::string PyDbDatabase::dimpost() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return wstr_to_utf8(impObj()->dimpost());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::getDimstyleParentId(PyDbObjectId& childStyle) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->getDimstyleParentId(childStyle.m_id));
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::groupDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->groupDictionaryId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::insert(PyDbObjectId& blockId, const std::string& pBlockName, PyDbDatabase& db, bool preserveSourceDatabase /*= true*/)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insert(blockId.m_id, utf8_to_wstr(pBlockName).c_str(), db.impObj(), preserveSourceDatabase);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::insert(PyDbObjectId& blockId, const std::string& pSourceBlockName, const std::string& pDestinationBlockName, PyDbDatabase& db, bool preserveSourceDatabase /*= true*/)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insert(blockId.m_id, utf8_to_wstr(pSourceBlockName).c_str(), utf8_to_wstr(pDestinationBlockName).c_str(), db.impObj(), preserveSourceDatabase);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::insert(const AcGeMatrix3d& xform, PyDbDatabase& db, bool preserveSourceDatabase /*= true*/)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insert(xform, db.impObj(), preserveSourceDatabase);
    throw PyNullObject();
}

AcDb::UnitsValue PyDbDatabase::insunits() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->insunits();
    throw PyNullObject();
}

bool PyDbDatabase::isBeingDestroyed() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isBeingDestroyed();
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::layerTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->layerTableId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::layerZero() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->layerZero());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::layoutDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->layoutDictionaryId());
    throw PyNullObject();
}

double PyDbDatabase::lensLength() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->lensLength();
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::linetypeTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->linetypeTableId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::registerApp(const std::string& pszAppName)
{
#ifdef ARX2023
    auto imp = impObj();
    if (imp != nullptr)
        return imp->registerApp(utf8_to_wstr(pszAppName).c_str());
#else
    throw PyNotimplementedByHost();
#endif
}

PyDbObjectId PyDbDatabase::materialDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->materialDictionaryId());
    throw PyNullObject();
}

AcDb::MeasurementValue PyDbDatabase::measurement() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->measurement();
    throw PyNullObject();
}

bool PyDbDatabase::mirrtext() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->mirrtext();
    throw PyNullObject();
}

double PyDbDatabase::mleaderscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->mleaderscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::mleaderstyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->mleaderstyle());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::mleaderStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->mleaderStyleDictionaryId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::mLStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->mLStyleDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::msltscale() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->msltscale();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::namedObjectsDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->namedObjectsDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::needsRecovery() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->needsRecovery();
    throw PyNullObject();
#endif
}

double PyDbDatabase::northDirection() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->northDirection();
    throw PyNullObject();
}

Adesk::Int32 PyDbDatabase::numberOfSaves() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->numberOfSaves();
    throw PyNullObject();
}

bool PyDbDatabase::orthomode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->orthomode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::paperSpaceVportId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->paperSpaceVportId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::plotSettingsDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->plotSettingsDictionaryId());
    throw PyNullObject();
}

bool PyDbDatabase::plotStyleMode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->plotStyleMode();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::plotStyleNameDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->plotStyleNameDictionaryId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::regAppTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->regAppTableId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::restoreOriginalXrefSymbols()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->restoreOriginalXrefSymbols();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::saveAs(const std::string& fileName)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->saveAs(utf8_to_wstr(fileName).c_str());
    throw PyNullObject();
}

void PyDbDatabase::setFullSaveRequired()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        imp->setFullSaveRequired();
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::readDwgFile(const char* fileName)
{
    std::wstring wsfileName{ utf8_to_wstr(fileName) };
    auto imp = impObj();
    if (imp != nullptr)
        return imp->readDwgFile(wsfileName.c_str());
    return eNullPtr;
}

std::string PyDbDatabase::getFilename()
{
    auto imp = impObj();
    if (imp != nullptr)
    {
        const TCHAR* path = nullptr;
        if (imp->getFilename(path) == eOk && path != nullptr)
            return std::string{ wstr_to_utf8(path) };
    }
    return std::string{ };
}

PyDbObjectId PyDbDatabase::currentSpaceId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->currentSpaceId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::blockTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->blockTableId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::modelspaceId() const
{
    return PyDbObjectId(acdbSymUtil()->blockModelSpaceId(impObj()));
}








Acad::ErrorStatus PyDbDatabase::setInsunits(const AcDb::UnitsValue units)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setInsunits(units);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setInterfereObjVisStyle(const PyDbObjectId& id)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setInterfereObjVisStyle(id.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setInterfereVpVisStyle(const PyDbObjectId& id)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setInterfereVpVisStyle(id.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setIntersectColor(Adesk::UInt16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setIntersectColor(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setIntersectDisplay(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setIntersectDisplay(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setIsolines(Adesk::Int16 isolines)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setIsolines(isolines);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setJoinStyle(AcDb::JoinStyle style)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setJoinStyle(style);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLatitude(double lat)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLatitude(lat);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLayerEval(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLayerEval(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLayerNotify(Adesk::Int16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLayerNotify(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLensLength(const double _lensLength)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLensLength(_lensLength);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLightGlyphDisplay(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLightGlyphDisplay(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLightingUnits(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLightingUnits(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLightsInBlocks(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLightsInBlocks(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setLimcheck(bool check)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLimcheck(check);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLimmax(const AcGePoint2d& max)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLimmax(max);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLimmin(const AcGePoint2d& min)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLimmin(min);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLineWeightDisplay(bool display)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLineWeightDisplay(display);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftAng1(double ang1)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftAng1(ang1);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftAng2(double ang2)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftAng2(ang2);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftMag1(double mag1)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftMag1(mag1);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftMag2(double mag2)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftMag2(mag2);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftNormals(Adesk::UInt8 value)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftNormals(value);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLoftParam(Adesk::UInt16 flags)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLoftParam(flags);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLongitude(double lng)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLongitude(lng);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLtscale(double scale)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLtscale(scale);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLunits(Adesk::Int16 lunits)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLunits(lunits);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setLuprec(Adesk::Int16 prec)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setLuprec(prec);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMaxactvp(Adesk::Int16 max)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMaxactvp(max);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMeasurement(AcDb::MeasurementValue type)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMeasurement(type);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMirrtext(bool mirror)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMirrtext(mirror);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMLeaderscale(double scale)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMLeaderscale(scale);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMLeaderstyle(const PyDbObjectId& objId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMLeaderstyle(objId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMsltscale(bool val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMsltscale(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setMsOleScale(double val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setMsOleScale(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setNorthDirection(double northdir)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setNorthDirection(northdir);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setObscuredColor(Adesk::UInt16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setObscuredColor(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setObscuredLineType(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setObscuredLineType(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setOleStartUp(bool val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setOleStartUp(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setOrthomode(bool mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setOrthomode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPdfframe(Adesk::Int8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPdfframe(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setPdmode(Adesk::Int16 mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPdmode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPdsize(double size)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPdsize(size);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPelevation(double elev)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPelevation(elev);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPextmax(const AcGePoint3d& max)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPextmax(max);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPextmin(const AcGePoint3d& min)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPextmin(min);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPickstyle(Adesk::Int16 style)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPickstyle(style);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPinsbase(const AcGePoint3d& base)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPinsbase(base);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlimcheck(bool check)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlimcheck(check);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlimmax(const AcGePoint2d& max)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlimmax(max);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlimmin(const AcGePoint2d& min)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlimmin(min);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlineEllipse(bool pline)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlineEllipse(pline);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlinegen(bool gen)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlinegen(gen);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPlinewid(double width)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPlinewid(width);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPreviewType(Adesk::Int16 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPreviewType(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setProjectName(const std::string& val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setProjectName(utf8_to_wstr(val).c_str());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPsltscale(bool scale)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPsltscale(scale);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPsolHeight(double height)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPsolHeight(height);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setPsolWidth(double width)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPsolWidth(width);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setPucs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPucs(ucsOrigin, ucsXDir, ucsYDir);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPucsBase(const PyDbObjectId& ucsid)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPucsBase(ucsid.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setPucsname(const PyDbObjectId& ucsRecId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setPucsname(ucsRecId.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setQtextmode(bool mode)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setQtextmode(mode);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setRealWorldScale(const bool realWorldScale)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setRealWorldScale(realWorldScale);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setRegenmode(bool mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setRegenmode(mode);
    throw PyNullObject();
}

void PyDbDatabase::setRetainOriginalThumbnailBitmap(bool retain)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setRetainOriginalThumbnailBitmap(retain);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSaveproxygraphics(Adesk::Int16 saveimg)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSaveproxygraphics(saveimg);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSectionViewStyle(const PyDbObjectId& objId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSectionViewStyle(objId.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setShadedge(Adesk::Int16 mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setShadedge(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setShadedif(Adesk::Int16 dif)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setShadedif(dif);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setShadowPlaneLocation(double val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setShadowPlaneLocation(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setShowHist(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setShowHist(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setSketchinc(double inc)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSketchinc(inc);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSkpoly(bool asPoly)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSkpoly(asPoly);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSolidHist(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSolidHist(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setSortEnts(Adesk::UInt8 sortEnts)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSortEnts(sortEnts);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSplframe(bool disp)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSplframe(disp);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSplinesegs(Adesk::Int16 segs)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSplinesegs(segs);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSplinetype(Adesk::Int16 type)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSplinetype(type);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setStepSize(double stepSize)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setStepSize(stepSize);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setStepsPerSec(double stepsPerSec)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setStepsPerSec(stepsPerSec);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setStyleSheet(const std::string& val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setStyleSheet(utf8_to_wstr(val).c_str());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSurftab1(Adesk::Int16 tab1)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSurftab1(tab1);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSurftab2(Adesk::Int16 tab2)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSurftab2(tab2);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSurftype(Adesk::Int16 type)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSurftype(type);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSurfu(Adesk::Int16 v)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSurfu(v);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setSurfv(Adesk::Int16 v)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setSurfv(v);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTablestyle(const PyDbObjectId& objId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTablestyle(objId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTextsize(double size)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTextsize(size);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTextstyle(const PyDbObjectId& objId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTextstyle(objId.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setThickness(double thickness)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setThickness(thickness);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTilemode(bool mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTilemode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTimeZone(AcDb::TimeZone tz)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTimeZone(tz);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTimeZoneAsUtcOffset(double offset)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTimeZoneAsUtcOffset(offset);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setTracewid(double width)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTracewid(width);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTreedepth(Adesk::Int16 depth)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTreedepth(depth);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTStackAlign(int val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTStackAlign(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setTStackSize(int val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setTStackSize(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUcs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUcs(ucsOrigin, ucsXDir, ucsYDir);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUcsBase(const PyDbObjectId& ucsid)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUcsBase(ucsid.m_id);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUcsname(const PyDbObjectId& ucsRecId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUcsname(ucsRecId.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setUnitmode(Adesk::Int16 mode)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUnitmode(mode);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUpdateThumbnail(Adesk::UInt8 val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUpdateThumbnail(val);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setUseri1(Adesk::Int16 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUseri1(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUseri2(Adesk::Int16 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUseri2(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUseri3(Adesk::Int16 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUseri3(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUseri4(Adesk::Int16 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUseri4(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUseri5(Adesk::Int16 val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUseri5(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUserr1(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUserr1(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUserr2(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUserr2(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUserr3(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUserr3(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUserr4(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUserr4(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUserr5(double val)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUserr5(val);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setUsrtimer(bool timer)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setUsrtimer(timer);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setVersionGuid(const std::string& pNewGuid)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setVersionGuid(utf8_to_wstr(pNewGuid).c_str());
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setViewportScaleDefault(double newDefaultVPScale)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setVisretain(newDefaultVPScale);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setVisretain(bool retain)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setVisretain(retain);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setWorldPucsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setWorldPucsBaseOrigin(origin, orthoView);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setWorldUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setWorldUcsBaseOrigin(origin, orthoView);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setWorldview(bool view)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setWorldview(view);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::setXclipFrame(Adesk::UInt8 disp)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setXclipFrame(disp);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbDatabase::setXrefEditEnabled(bool enable)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->setXrefEditEnabled(enable);
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::shadedge() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->shadedge();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::shadedif() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->shadedif();
    throw PyNullObject();
}

double PyDbDatabase::shadowPlaneLocation() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->shadowPlaneLocation();
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::showHist() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->showHist();
    throw PyNullObject();
#endif
}

double PyDbDatabase::sketchinc() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->sketchinc();
    throw PyNullObject();
}

bool PyDbDatabase::skpoly() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->skpoly();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::solidHist() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->solidHist();
    throw PyNullObject();
#endif
}

Adesk::UInt8 PyDbDatabase::sortEnts() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->splframe();
    throw PyNullObject();
}

bool PyDbDatabase::splframe() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->splframe();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::splinesegs() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->splinesegs();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::splinetype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->splinetype();
    throw PyNullObject();
}

double PyDbDatabase::stepSize() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->stepSize();
    throw PyNullObject();
#endif
}

double PyDbDatabase::stepsPerSec() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->stepsPerSec();
    throw PyNullObject();
#endif
}

Adesk::Int16 PyDbDatabase::surftab1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->surftab1();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::surftab2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->surftab2();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::surftype() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->surftype();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::surfu() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->surfu();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::surfv() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->surfv();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::tablestyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->tablestyle());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::tableStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->tableStyleDictionaryId());
    throw PyNullObject();
}

double PyDbDatabase::textsize() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->textsize();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::textstyle() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->textstyle());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::textStyleTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->textStyleTableId());
    throw PyNullObject();
}

double PyDbDatabase::thickness() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->thickness();
    throw PyNullObject();
}

bool PyDbDatabase::tilemode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->tilemode();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::tileModeLightSynch() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->tileModeLightSynch();
    throw PyNullObject();
#endif
}

AcDb::TimeZone PyDbDatabase::timeZone() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->timeZone();
    throw PyNullObject();
}

double PyDbDatabase::tracewid() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->tracewid();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::treedepth() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->treedepth();
    throw PyNullObject();
}

int PyDbDatabase::tstackalign() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->tstackalign();
    throw PyNullObject();
}

int PyDbDatabase::tstacksize() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->tstacksize();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::ucsBase() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->ucsBase());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::ucsname() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->ucsname());
    throw PyNullObject();
}

AcGePoint3d PyDbDatabase::ucsorg() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->ucsorg();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::UCSTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->UCSTableId());
    throw PyNullObject();
}

AcGeVector3d PyDbDatabase::ucsxdir() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->ucsxdir();
    throw PyNullObject();
}

AcGeVector3d PyDbDatabase::ucsydir() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->ucsydir();
    throw PyNullObject();
}

bool PyDbDatabase::undoRecording() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->undoRecording();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::unitmode() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->unitmode();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::updateDataLink(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->updateDataLink(nDir, nOption);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::updateExt(bool doBestFit)
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->updateExt(doBestFit);
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::updateThumbnail() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->updateThumbnail();
    throw PyNullObject();
#endif
}

Adesk::Int16 PyDbDatabase::useri1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->useri1();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::useri2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->useri2();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::useri3() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->useri3();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::useri4() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr4();
    throw PyNullObject();
}

Adesk::Int16 PyDbDatabase::useri5() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr5();
    throw PyNullObject();
}

double PyDbDatabase::userr1() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr1();
    throw PyNullObject();
}

double PyDbDatabase::userr2() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr2();
    throw PyNullObject();
}

double PyDbDatabase::userr3() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr3();
    throw PyNullObject();
}

double PyDbDatabase::userr4() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr4();
    throw PyNullObject();
}

double PyDbDatabase::userr5() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->userr5();
    throw PyNullObject();
}

bool PyDbDatabase::usrtimer() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->usrtimer();
    throw PyNullObject();
}

double PyDbDatabase::viewportScaleDefault() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->viewportScaleDefault();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::viewportTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->viewportTableId());
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::viewTableId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->viewTableId());
    throw PyNullObject();
}

bool PyDbDatabase::visretain() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->visretain();
    throw PyNullObject();
}

PyDbObjectId PyDbDatabase::visualStyleDictionaryId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->visualStyleDictionaryId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb)
{
    auto imp = impObj();
    if (imp != nullptr)
    {
        AcDbDatabase* _pOutputDb = nullptr;
        auto stat = impObj()->wblock(_pOutputDb);
        if (stat == eOk && _pOutputDb != nullptr)
            pOutputDb = PyDbDatabase(_pOutputDb, true);
        return stat;
    }
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb, const PyDbObjectId& blockId)
{
    auto imp = impObj();
    if (imp != nullptr)
    {
        AcDbDatabase* _pOutputDb = nullptr;
        auto stat = impObj()->wblock(_pOutputDb, blockId.m_id);
        if (stat == eOk && _pOutputDb != nullptr)
            pOutputDb = PyDbDatabase(_pOutputDb, true);
        return stat;
    }
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint)
{
    auto imp = impObj();
    if (imp != nullptr)
    {
        //TODO: maybe we can do better
        const auto PyDbObjectIds = py_list_to_std_vector<PyDbObjectId>(outObjIds);
        AcDbObjectIdArray ids;
        for (const auto& pyId : PyDbObjectIds)
            ids.append(pyId.m_id);

        AcDbDatabase* _pOutputDb = nullptr;
        auto stat = impObj()->wblock(_pOutputDb, ids, basePoint);
        if (stat == eOk && _pOutputDb != nullptr)
            pOutputDb = PyDbDatabase(_pOutputDb, true);
        return stat;
    }
    throw PyNullObject();
}

Acad::ErrorStatus PyDbDatabase::wblock(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint, AcDb::DuplicateRecordCloning drc)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
    {
        //TODO: maybe we can do better
        const auto PyDbObjectIds = py_list_to_std_vector<PyDbObjectId>(outObjIds);
        AcDbObjectIdArray ids;
        for (const auto& pyId : PyDbObjectIds)
            ids.append(pyId.m_id);

        AcDbDatabase* pDb = pOutputDb.impObj();
        return impObj()->wblock(pDb, ids, basePoint, drc);
    }
    throw PyNullObject();
#endif
}

AcGePoint3d PyDbDatabase::worldPucsBaseOrigin(AcDb::OrthographicView orthoView) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->worldPucsBaseOrigin(orthoView);
    throw PyNullObject();
#endif
}

AcGePoint3d PyDbDatabase::worldUcsBaseOrigin(AcDb::OrthographicView orthoView) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->worldUcsBaseOrigin(orthoView);
    throw PyNullObject();
#endif
}

bool PyDbDatabase::worldview() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->worldview();
    throw PyNullObject();
}

Adesk::UInt8 PyDbDatabase::xclipFrame() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->xclipFrame();
    throw PyNullObject();
#endif
}

PyDbObjectId PyDbDatabase::xrefBlockId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(impObj()->xrefBlockId());
    throw PyNullObject();
}

bool PyDbDatabase::xrefEditEnabled() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return impObj()->xrefEditEnabled();
    throw PyNullObject();
}

std::string PyDbDatabase::className()
{
    return "AcDbDatabase";
}

AcDbDatabase* PyDbDatabase::impObj() const
{
    return static_cast<AcDbDatabase*>(m_pImp);
}

